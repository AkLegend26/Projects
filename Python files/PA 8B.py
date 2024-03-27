# Name: Ayush Pathak
# VUnetID: pathaa3
# Email: ayush.pathak@vanderbilt.edu
# Class: CS 1104 - Vanderbilt University
# Section: 2
# Date: 11/09/2021
# Honor statement: I attest that I understand the honor code for this class and have
#                  neither given nor received any unauthorized aid on this assignment.

# Program Description: This program runs an interactive hangman game with the user.


def print_intro():
    """
    This function prints the game setup lines to the screen.
    """

    print('Game setup')
    print('==========')


def trial_number(string):
    """
    This function asks user for the number of trials and ensures that the input
    fits the desired criteria.
    Parameters:
        string:
            the string input by the user.

    Returns:
        Returns the number of trials.
    """
    trial = input('Enter maximum number of tries: ')

    while True:
        if trial.isdigit():
            if len(range(int(trial))) < len("".join(string.split())):
                print(f'Must be at least {len("".join(string.split()))}, try again: ', end = '')
                trial = input()
            else:
                return trial
        else:
            trial = input(f'Must be a number, try again: ')



def game():
    """
    This function asks the user for string and calls a function that asks for trial number.

    Returns:
        Returns the string and trial number.
    """
    string = input('Enter secret string: ')
    while string == '':
        string = input('No string entered, try again: ')
    string = string.upper()
    trial = trial_number(string)

    return string, trial

def empty_string(string):
    """
    This function creates the baseline for the dashed string (base for hangman with dashes).

    Parameters:
        string: The string input by the user.

    Returns:
         Returns the dashed string(list) based on the user input.
    """
    emp_string = ''
    for char in string:
        if char.isupper() == 1:
            emp_string += '-'
        else:
            emp_string += ' '
    emp_string_list = list(emp_string)
    return emp_string_list

def guess_condition(guess, correct_guess):
    """
    This function ensures that the guess input by the user is appropriate.
    Parameters:
        guess:
            The guess input by the user.
        correct_guess:
            list of guesses that were in the secret string.

    Returns:
         This function returns the guess.
    """
    while guess.isalnum() != 1 or guess.isdigit() == 1:
        guess = input('Not a letter, try again: ')

    if guess.upper() in correct_guess:
        guess = input('Correct letter already guessed, try again: ')
        return guess_condition(guess, correct_guess)
    else:
        return guess


def guess_print(trial, emp_string_list, correct_guess):
    """
    This function prints guess information to the screen.

    Parameters:
        trial:
            Number of times user wants to guess.
        emp_string_list:
            Dashed list with correct guesses substituted.
        correct_guess:
            list of correct guesses by the user.

    Returns:
         Returns the user's guess.
    """
    print(f'You have {trial} tries left.')
    print(f'Your guesses so far: {"".join(emp_string_list)}')
    guess = input('Enter your guess: ')
    guess = guess_condition(guess, correct_guess)
    print()
    return guess


def print_lost(string, emp_string_list):
    """
    This function prints the ending screen if user loses.

    Parameters:
        string:
            string input by the user.
        emp_string_list:
            dashed out string with the the correct guesses substituted in.
    """
    if ("".join(emp_string_list)) != string:
        print('Sorry, you lost.')
        print(f'The secret string is {string}')

def main_game(string, trial, emp_string_list):
    """
    This function asks the user to guess, checks if the guess is right and substitutes
    the dashed string accordingly.

    Parameters:
        string:
            String input by the user.
        trial:
            number of trials.
        emp_string_list:
            dashed out string with the correct guess substituted.

    """
    correct_guess = []
    while int(trial) > 0:
        guess = guess_print(trial, emp_string_list, correct_guess)

        for idx in range(len(string)):
            for char in string[idx]:

                if char == guess.upper():
                    emp_string_list[idx] = string[idx]
                    correct_guess.append(char)
        if ("".join(emp_string_list)) == string:
            print('Congratulations, you won!''\n'f'The secret string is: {string}')
            return
        trial = int(trial) - 1

    print_lost(string, emp_string_list)



def main():
    print_intro()
    [string, trial] = game()
    emp_string = empty_string(string)
    print()
    print('Play game')
    print('=========')
    main_game(string, trial, emp_string)


# DO NOT CHANGE ANYTHING BELOW THIS COMMENT.
if __name__ == '__main__':
    main()