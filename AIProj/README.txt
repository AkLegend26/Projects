Travel Route Preference Predictor

Description
This Python program predicts an individual's preferred travel routes based on their previous selections. 
It uses machine learning (neural networks) to learn user preferences for different themes at various 
locations and suggests routes accordingly.
I have kept the sample data's style similar to the actual RoadNetwork but it would take too long to import
and train, ie we are utilizing the sample data I have created.

Author
Ayush Pathak

Installation
Prerequisites
Python 3.x
Pip (Python package manager)
Required Libraries
The program requires the following Python libraries:

pandas
scipy
tensorflow
itertools
random
Installing Libraries
To install these libraries, run the following commands in your terminal:
pip install pandas
pip install scipy
pip install tensorflow

After installing the required libraries, you can run the program using a Python interpreter. 
The program will prompt you to enter a starting location and then present a series of travel 
routes with associated themes. After selecting preferred routes, the program uses these 
choices to train a neural network model. Finally, the program allows you to compare two new 
routes and predicts which one the user will prefer based on their learned preferences.