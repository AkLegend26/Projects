# Name: Ayush Pathak
# VUnetID: pathaa3
# Email: ayush.pathak@vanderbilt.edu
# Class: CS 1104 - Vanderbilt University
# Section: 2
# Date: 10/30/2021
# Honor statement: I attest that I understand the honor code for this class and have
#                  neither given nor received any unauthorized aid on this assignment.

# Program Description: This program decodes the encrypted message entered by the user
#                      based on the dictionary.

# Constant variable.
DECODE = {'aaaaa': 'A', 'aaaab': 'B', 'aaaba': 'C', 'aaabb': 'D',
          'aabaa': 'E', 'aabab': 'F', 'aabba': 'G', 'aabbb': 'H',
          'abaaa': 'I', 'abaab': 'J', 'ababa': 'K', 'ababb': 'L',
          'abbaa': 'M', 'abbab': 'N', 'abbba': 'O', 'abbbb': 'P',
          'baaaa': 'Q', 'baaab': 'R', 'baaba': 'S', 'baabb': 'T',
          'babaa': 'U', 'babab': 'V', 'babba': 'W', 'babbb': 'X',
          'bbaaa': 'Y', 'bbaab': 'Z'}


def decode_one(string):
    """
    This function takes the user input string and converts it into a list, then removes blanks and numbers
    to make sure it's only alphabets.

    Parameters:
        string:
            The message that will be decoded, entered by the user.
    Returns:
        Returns the decoded string and calls another function, decoded_two, to finish decoding.
    """
    string_as_list = []
    upper_case = []
    for char in string: # Converting string into a list so it's mutable.
        string_as_list.append(char)

    for char in string_as_list:  # From the ist appending a new list by removing special characters and numbers.
        if char.isupper() > 0 and char.isalpha():
            upper_case.append('a')
        elif char.isupper() == 0 and char.isalpha():
            upper_case.append('b')

    l =len(upper_case)
    five_letter_list = []
    n = 0
    return decode_two(upper_case,n,five_letter_list,l)

def decode_two(upper_case,n,five_letter_list,l):
    """
    This function groups characters into five letter word and then compares them to the dictionary
    and adds the value from the dictionary into the answer string.

    Parameters:
        upper_case:
            List of only a's and b's translated from the decoded_one function.
        n:
            Number that defines where to start and end the string concatenation.
        five_letter_list:
            Empty list that will take the values of grouped five letter words of a's and b's.
        l:
            Length of the upper_case list.

    Return:
        This function returns the decoded message in a string.
    """
    while n <= l:
        for char in upper_case:  # Grouping 5 characters into a word of a's and b's.
            a = ''.join(upper_case[n:n+5])
            five_letter_list.append(a)
            n += 5
    coded_list= []
    for x in five_letter_list: # This condition removes blank spaces from five letter list and
                               # adds  it to the coded list.
        if x.isalpha() > 0:
            coded_list.append(x)
    ans_string = ''
    for element in coded_list:
        if element in DECODE: # Checks the dictionary for encrypted message.
            ans_string += DECODE[element]
    return ans_string


def user_input():
    """
    This function asks the user for the input.

    Returns:
         Returns the string entered by the user.
    """
    string = input('Enter encoded text: ')
    while len(string) == 0:
        print('No text entered, try again:',end = ' ')
        string = input()

    return string


def main():
    string = user_input()
    encrypted = decode_one(string)
    print(f'The decoded word is {encrypted}.')
    print()
    b = input('Run again? ')
    if b == 'y':
        main()
    else:
        return

# DO NOT CHANGE ANYTHING BELOW THIS COMMENT.
if __name__ == '__main__':
    main()