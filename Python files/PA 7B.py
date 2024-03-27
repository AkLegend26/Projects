# Name: Ayush Pathak
# VUnetID: pathaa3
# Email: ayush.pathak@vanderbilt.edu
# Class: CS 1104 - Vanderbilt University
# Section: 2
# Date: 10/30/2021
# Honor statement: I attest that I understand the honor code for this class and have
#                  neither given nor received any unauthorized aid on this assignment.

# Program Description: This program rolls desired number of dice, desired number of times,
#                      and reports how many of the rolls, the dice had same values.


import random  # This line should be after your comment header.

def user_input():
    """
    This function asks user for the desired number of dice and number of rolls.

    Returns:
         This function calls a function to roll the dice and count matching digits.
    """
    number = int(input('Enter number of dice: '))
    while not(2 <= number <= 5):
        number = int(input('Only two to five dice, try again: '))
    rolls = int(input('Enter number of rolls: '))
    while rolls < 0:
        rolls = int(input('Not a positive number, try again: '))
    dice_rolls(number,rolls)
    again = input('Run experiment again? ')
    if again == 'y':
        user_input()

def dice_rolls(number, rolls):
    """
    This function rolls the dice and checks how many rolls the dices had same value.

    Parameter:
        number:
            number of dices being rolled.
        rolls:
            number of rolls for each dice.

    Returns:
         This function calls a print_to_screen function to print information to the screen.
    """
    loop_counter = 0
    for element in range(rolls): # rolling for range of rolls.
        ind_rolls = []
        for i in range(number):
            dice_roll = random.randint(1,6)  #appending the number generated.
            ind_rolls.append(dice_roll) # creating a list inside of loops with
                                        # rows for rolls and columns for dice.
        match = 0
        for i in ind_rolls:
            if i == ind_rolls[0]:
                match += 1
        if match == len(ind_rolls):# number of elements in 1 roll matched is equal to dice.
            loop_counter += 1
    print_to_screen(number,rolls, loop_counter)

def print_to_screen(number, rolls, loop_counter):
    """
    This function prints information to the screen.
    Parameters:
        number:
            Number of Dices.
        rolls:
            Number of rolls.
        loop_counter:
            number of rolls when dices had the same value.
    """
    print()
    print(f'When {number} dice were rolled {rolls} times, the number of rolls')
    print(f'where all numbers matched was {loop_counter} out of {rolls} rolls.')
    print()


def main():
    ##### DO NOT EDIT THE CODE BELOW #####

    # Get seed from user.
    seed = int(input('Enter a seed: '))

    # Set seed for random number generator.
    random.seed(seed)

    ##### DO NOT EDIT THE CODE ABOVE #####

    # Start your code here.
    user_input()





# DO NOT CHANGE ANYTHING BELOW THIS COMMENT.
if __name__ == '__main__':
    main()
