# Name: Ayush Pathak
# VUnetID: pathaa3
# Email: ayush.pathak@vanderbilt.edu
# Class: CS 1104 - Vanderbilt University
# Section: 2
# Date: 12/06/2021
# Honor statement: I attest that I understand the honor code for this class and have
#                  neither given nor received any unauthorized aid on this assignment.

# Program Description: This program prints the asked information
#                      from the broadway.csv file.

import csv


def main():
    choice = print_info()
    if choice == 0:
        return
    film = input('Enter search term: ')
    year = int(input('Enter year: '))
    print()
    if choice == 1:
        stat = 'Attendance'
        print_solution(film,year,7,stat)
    elif choice == 2:
        stat = 'Revenue'
        print_solution(film, year, 9,stat)
    elif choice == 3:
        stat = 'Performances'
        print_solution(film, year, 11,stat)



def print_info():
    """
    This function asks the user for their desired stats from the broadway file.

    Return:
         Returns the user's choice.
    """
    print('1 - Attendance stats')
    print('2 - Revenue stats')
    print('3 - Performance stats')
    choice = int(input('Please select an option (0 to exit): '))
    while not(0 <= choice <= 3):
        choice = int(input('Invalid option. Try again: '))
    return choice


def opener(film,year,index, month):
    """
    This function reads the data from the broadway file.

    Parameters:
        film:
            Desired play name
        year:
            Desired year of the play
        index:
            The stats form the broadway file based on the users choice.
        month:
            desired month for the play

    Return:
        The list of stats desired by the user.
    """
    with open('broadway.csv') as file:  # The CSV file name can be hard-coded.
        shows = csv.reader(file)
        next(shows)
        solution = []

        for show in shows:
            # Code to skip the first line omitted.

            if film.upper() in show[4].upper():
                if int(show[3]) == year:
                    if int(show[2]) == month:
                        solution.append(int(show[index]))
    return solution


def print_solution(film,year,index,name):
    """
    This function prints the information easier to read on the screen.

    Parameters:
        film:
            Name of the play
        year:
            year of the play
        index:
            The stats form the broadway file based on the users choice.
        name:
            Name of the desired stats.

    Returns:
        Prints the information to the screen.
    """

    emp_list = [0,0,0,0,0,0,0,0,0,0,0,0]
    for i in range(12):
        a = opener(film,year,index, (i+1))
        emp_list[i] = sum(a)
    if sum(emp_list) == 0:
        print('No data found.')
    else:
        print(f'Term: {film.upper()}')
        print(f'Year: {year}')
        print(f'Stat: {name}')
        print('----------------------')
        print('| Month |      Total |')
        print('|-------|------------|')
        for j in range(12):
            print(f'|{(j+1):>6} |{emp_list[j]:>11} |')
        print('----------------------')
        print(f'  TOTAL  {sum(emp_list):>11}')


# DO NOT CHANGE ANYTHING BELOW THIS COMMENT.
if __name__ == '__main__':
    main()

