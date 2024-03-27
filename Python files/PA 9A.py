import random  # This line should be after your header comments.

# Constant variable.
CHOICE = ['Rock', 'Paper', 'Scissors']


def game(name_players):
    """
    This function rolls rock,paper for all the players.

    Parameters:
        name_players:
            Name of players

    Return:
        This function calls other functions to keep track of winner.
    """
    shows = [] #list that has values of rocks paper and scissors or an X for each player.

    for names in range(len(name_players.split())):
        shows.append(CHOICE[random.randint(0,1)])

    loop(name_players,shows)
    loop2(name_players,shows)
    print()
    result(name_players, shows)


def loop2(name_players,shows):
    """
    This function checks for the winner based on rolls when 2 people remain.

    Parameters:
        name_players:
            List containing name of players.
        shows:
            List containing rolls of players.

    """
    while shows.count('X') != len(name_players.split())- 1:

        for i, show in enumerate(shows):
            if shows.count('Rock') > shows.count('Paper'):
                if show == 'Paper':
                    shows[i] = 'X'
            elif shows.count('Paper') > shows.count('Rock'):
                if show == 'Rock':
                    shows[i] = 'X'
        for idx, show in enumerate(shows):
            if show != 'X':
                shows[idx] = CHOICE[random.randint(0, 2)]
        print_info(shows)
        replace(shows)


def replace(shows):
    """
    This function checks to see which player roll wins.

    Parameters:
        shows:
            List of rolls of players in the game.

    Returns:
        Updated shows list with people still in the game.
    """
    for idx, show in enumerate(shows):
        if 'Scissors' in shows:
            if show == 'Paper':
                shows[idx] = 'X'
        if 'Rock' in shows:
            if show == 'Scissors':
                shows[idx] = 'X'
        if 'Paper' in shows:
            if show == 'Rock':
                shows[idx] = 'X'


def result(name_players, shows):
    """
    This function prints the result of the game.

    Parameters:
        name_players:
            List containing name of all players.
        shows:
            List containing rolls of people still in the game.
    """
    name = name_players.split()
    for idx, show in enumerate(shows):
        if show != 'X':
            print(f'{name[idx]} won.')


def loop(name_players,shows):
    """
    This function checks to see who wins rolls when all players are remaining.

    Parameters:
        name_players:
            List containing name of players.
        shows:
            List containing names of remaining players rolls.

    Returns:
        Updated shows list with remaining players.
    """
    while shows.count('X') != (len(name_players.split()) - 3):
        print_info(shows)
        for i, show in enumerate(shows):
            if shows.count('Rock') > shows.count('Paper'):
                if show == 'Paper':
                    shows[i] = 'X'
            elif shows.count('Paper') > shows.count('Rock'):
                if show == 'Rock':
                    shows[i] = 'X'
        for idx, show in enumerate(shows):
            if show != 'X':
                shows[idx] = CHOICE[random.randint(0,1)]
    print_info(shows)


def print_info(shows):
    """
    This function prints roll of the players to the screen.

    Parameters:
        shows:
            List containing remaining players rolls.
    """
    for idx in shows:
        print(f'{idx:^10}',end='')
    print()


def name_input(num_players):
    """
    This function asks for number of players.

    Parameters:
        num_players:
            Number of players.

    Returns:
         List of name of players in the game.
    """
    name = input('Enter names of players: ')
    while len(name.split()) != num_players:
        name = input(f'Must enter {num_players} names, try again: ')
    return name


def num_input():
    """
    This function asks for number of players.

    Returns:
         Number of players.
    """
    num_players = input('Enter number of players: ')
    while True:
        if num_players.isdigit():
            if int(num_players) < 3:
                num_players = input('Must be at least 3, try again: ')
            else:
                return num_players
        else:
            num_players = input('Must be a number, try again: ')


def main():

    ##### DO NOT EDIT THE CODE BELOW #####

    # Get seed from user.
    seed = int(input('Enter a seed: '))

    # Set seed for random number generator.
    random.seed(seed)

    ##### DO NOT EDIT THE CODE ABOVE #####

    num_players = int(num_input())
    name_players = name_input(num_players)
    print()

    for idx in name_players.split():
        print (f'{idx:^10}', end='')
    print()
    print('-'* (int(num_players) * 10))

    game(name_players)

# DO NOT CHANGE ANYTHING BELOW THIS COMMENT.
if __name__ == '__main__':
    main()