#Ayush Pathak
#AI PA 4
#Choosing the best trip for user and then predicting given two routes the user would prefer

import pandas as pd
from scipy.spatial.distance import pdist, squareform
from itertools import permutations
import tensorflow as tf
import itertools
import random
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense

# Loading data
# Sorry Kyle, but just input the data files location here based on your directory
locations_df = pd.read_csv('/Users/legend/Documents/AI/PA_4/locations_main.csv')
#print(locations_df.head())
edges_df = pd.read_csv('/Users/legend/Documents/AI/PA_4/edges_main.csv')
#print(edges_df.head())
attractions_df = pd.read_csv('/Users/legend/Documents/AI/PA_4/attractions_main.tsv', sep='\t')
#print(attractions_df.head())

# ----- Function Definitions -----
def convert_input_to_route(input_str):
    """
    Converts user input into a a route
    """
    return input_str.split(',')

def prepare_training_data(themes_per_route, theme_locations):
    """
    Prepares training data by converting themes into a binary vector.
    """
    X_train = []
    for themes in themes_per_route:
        route_vector = [1 if theme in themes else 0 for theme in theme_locations.keys()]
        X_train.append(route_vector)
    return X_train

def generate_multiple_route_sets(start_location, theme_locations, locations_df, sets=3, max_stops_range=(3, 5)):
    """
    Generates multiple routes for users to choose from
    """
    route_sets = []
    for max_stops in range(max_stops_range[0], max_stops_range[1] + 1):
        routes = generate_themed_routes(start_location, theme_locations, locations_df, num_routes=3, max_stops=max_stops)
        route_sets.append(routes)
    return route_sets

def group_locations_by_theme(attractions_df):
    """
    Groups locations by their associated themes.
    """
    theme_locations = {}
    for _, row in attractions_df.iterrows():
        themes = row['Themes'].split(', ')
        for theme in themes:
            if theme not in theme_locations:
                theme_locations[theme] = set()
            theme_locations[theme].add(row['Loc or Edge Label'])
    return theme_locations

def generate_themed_routes(start_location, theme_locations, locations_df, num_routes=3, max_stops=5):
    """
    Generates routes based on themes starting from a specified location with a limit on the number of stops.
    """
    if start_location not in locations_df['Location Label'].values:
        print("Invalid starting location.")
        return []

    routes = []
    themes_list = list(theme_locations.keys())

    for _ in range(num_routes):
        route = [start_location]
        random.shuffle(themes_list)
        selected_themes = themes_list[:max_stops]  # Select a random subset of themes
        
        for theme in selected_themes:
            possible_locations = list(theme_locations[theme] - set(route))
            if possible_locations:
                next_location = random.choice(possible_locations)
                route.append(next_location)
        
        if route[-1] != start_location:  # Ensure the route ends at the start location
            route.append(start_location)
        
        if route not in routes:  # Add route to the list if it's not already present
            routes.append(route)
    
    return routes

def extract_themes_for_routes(routes, attractions_df):
    """
    Extracts themes for each given route.
    """
    themes_per_route = []
    for route in routes:
        themes = set()
        for location in route:
            location_themes = attractions_df[attractions_df['Loc or Edge Label'] == location]['Themes']
            for theme in location_themes:
                themes.update(theme.split(', '))
        themes_per_route.append(themes)
    return themes_per_route

    
# ----- Main Logic -----


# User input for starting location
start_location = input("Please enter your starting location: ")

# Group locations by theme
theme_locations = group_locations_by_theme(attractions_df)

# Generate multiple sets of routes with varying lengths
route_sets = generate_multiple_route_sets(start_location, theme_locations, locations_df, sets=3, max_stops_range=(3, 8))


user_choices = []
for set_num in range(3):
    print(f"\nGenerating set {set_num + 1} of routes...")

    # Generate themed routes with varying lengths
    themed_routes = generate_themed_routes(start_location, theme_locations, locations_df, num_routes=3, max_stops=set_num + 3)

    # Extract themes for each route
    themes_per_route = extract_themes_for_routes(themed_routes, attractions_df)

    # Present routes and themes to the user
    for i, route in enumerate(themed_routes):
        print(f"Route {i+1}: {' -> '.join(route)}")
        print(f"Themes: {', '.join(themes_per_route[i])}\n")

    # Ask the user to choose their preferred route
    print("Please choose your preferred route by entering the route number.")
    user_choice = int(input("Enter your choice): ")) - 1

    if user_choice < 0 or user_choice >= len(themed_routes):
        print("Invalid choice. Please enter a valid route number.")
    else:
        user_choices.append((set_num, user_choice))
        preferred_route = themed_routes[user_choice]
        print(f"You have chosen: {' -> '.join(preferred_route)}\n")

# Prepare data for training
X_train = []
y_train = []

for set_index, routes in enumerate(route_sets):
    themes_per_set = extract_themes_for_routes(routes, attractions_df)
    for route_index, themes in enumerate(themes_per_set):
        route_vector = [1 if theme in themes else 0 for theme in theme_locations.keys()]
        X_train.append(route_vector)
        y_train.append(1 if (set_index, route_index) in user_choices else 0)


# Neural network setup
model = Sequential()
model.add(Dense(64, input_dim=len(theme_locations), activation='relu'))
model.add(Dense(32, activation='relu'))
model.add(Dense(1, activation='sigmoid'))  # Output layer for binary classification

model.compile(loss='binary_crossentropy', optimizer='adam', metrics=['accuracy'])

# Training the model
model.fit(X_train, y_train, epochs=10, batch_size=1)

# Example of predicting user preferences for new routes
# You would need to generate new routes and convert them to the same format as X_train
new_routes = generate_themed_routes(start_location, theme_locations, locations_df, num_routes=5, max_stops=4)
new_themes_per_route = extract_themes_for_routes(new_routes, attractions_df)
X_new = prepare_training_data(new_themes_per_route, theme_locations)

predicted_preferences = model.predict(X_new)

# Sort new routes based on predicted preferences
sorted_routes = sorted(zip(new_routes, predicted_preferences), key=lambda x: x[1], reverse=True)
    
# Number of top routes to consider
top_n = 3

# Extracting top routes based on preference scores
top_routes = sorted_routes[:top_n]

# Initializing a dictionary to count theme frequencies
theme_frequencies = {}

# Extract themes from the top routes and count their frequencies
for route, _ in top_routes:
    for location in route:
        location_themes = attractions_df[attractions_df['Loc or Edge Label'] == location]['Themes']
        for theme in location_themes:
            themes_list = theme.split(', ')
            for single_theme in themes_list:
                if single_theme in theme_frequencies:
                    theme_frequencies[single_theme] += 1
                else:
                    theme_frequencies[single_theme] = 1

# Sort themes by their frequency
sorted_themes = sorted(theme_frequencies.items(), key=lambda x: x[1], reverse=True)

# Output the sorted themes
print("Themes valued by the individual, ordered by preference:")
for theme, frequency in sorted_themes:
    print(f"{theme}: {frequency}")

# Present sorted routes to the user
for route, preference in sorted_routes:
    print(f"Route: {' -> '.join(route)}, Preference Score: {preference[0]}")
    
# Identifying the route with the highest preference
highest_preference_route, highest_preference_score = sorted_routes[0]

highest_route_themes = set()
for location in highest_preference_route:
    location_themes = attractions_df[attractions_df['Loc or Edge Label'] == location]['Themes']
    for theme in location_themes:
        highest_route_themes.update(theme.split(', '))

# Print the suggested route
print("\nSuggested Route for the Individual:")
print("=====================================")
print("Route:", " -> ".join(highest_preference_route))
print("=====================================")
print("Preference Score:", highest_preference_score[0])
print("Themes on this route:", ", ".join(highest_route_themes))
print()

# Ask the user for two routes
print()#these print statements are just to make the terminal output look pretty
print("Please enter two routes for preference prediction.")
route_input_1 = input("Enter Route 1 (e.g., LocationA,LocationB,LocationC,LocationA): ")
route_input_2 = input("Enter Route 2 (e.g., LocationD,LocationE,LocationF,LocationD): ")

# Convert inputs to route format
route_1 = convert_input_to_route(route_input_1)
route_2 = convert_input_to_route(route_input_2)

# Extract themes for the input routes
themes_route_1 = extract_themes_for_routes([route_1], attractions_df)
themes_route_2 = extract_themes_for_routes([route_2], attractions_df)

# Prepare the data for prediction
X_route_1 = prepare_training_data(themes_route_1, theme_locations)
X_route_2 = prepare_training_data(themes_route_2, theme_locations)

# Predict preferences for both routes
preference_route_1 = model.predict(X_route_1)[0][0]
preference_route_2 = model.predict(X_route_2)[0][0]

# Print the preferences for each route
print("\nRoute Preferences:")
print(f"Preference Score for Route 1 ({route_input_1}): {preference_route_1}")
print(f"Preference Score for Route 2 ({route_input_2}): {preference_route_2}")

# Determine and print the preferred route
if preference_route_1 > preference_route_2:
    print("\nPredicted Preferred Route: Route 1")
    print("Route:", " -> ".join(route_1))
    print("Preference Score:", preference_route_1)
else:
    print("\nPredicted Preferred Route: Route 2")
    print("Route:", " -> ".join(route_2))
    print("Preference Score:", preference_route_2)
