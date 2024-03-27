## Name: Ayush Pathak
# VUnetID: pathaa3
# Email: ayush.pathak@vanderbilt.edu
# Class: CS 1104 - Vanderbilt University
# Section: 2
# Date: 10/06/2021
# Honor statement: I attest that I understand the honor code for this class and have
#                  neither given nor received any unauthorized aid on this assignment.


# Constant variables (do not move, remove, and/or change).
SINGLE_OR_MARRIED_SEPARATELY = 12400
MARRIED_JOINTLY_OR_WIDOWER = 24800
HEAD_OF_HOUSEHOLD = 18650
SALARY_LIMIT = 150000


# Program Description: This program suggests which tax filing method would be better
# for the user.

def print_intro():
    """This function prints the introductory information for the user
    """
    print('This program calculates itemized and standard deductions')
    print('and determines which deduction to claim for a tax return.')
    print()

def gross_income():
    """This function asks for the adjusted gross income of the user.

        Returns:
            This function returns the adjusted gross income of the user.
    """
    adj_gross_income = int(input('Enter adjusted gross income: '))
    return adj_gross_income


def choice_selector(gross_income):
    """This function asks the user to chose which tax deduction method
        to perform first.

        Parameters:
            gross_income:
                This is the adjusted gross income of the user.

        Returns:
            This function calls for two different function depending on the user choice.
    """
    print()
    print('1) Itemized')
    print('2) Standard')
    choice = int(input('Select deduction to calculate first: '))
    if choice == 1:
        choice_is_one(gross_income)
    if choice == 2:
        choice_is_two(gross_income)


def itemized_expenses():
    """This function asks the user for their expenses and calculates their item deduction.

    Returns:
        The item deduction of the user.
    """
    medical_expenses = int(input('Enter total medical expenses: '))
    job_expenses = int(input('Enter total job expenses: '))
    gifts_to_charity = int(input('Enter total gifts to charity: '))
    item_deduction = medical_expenses + job_expenses + gifts_to_charity
    return item_deduction

def itemized_deduction(adj_income):
    """This function calculates the tax cut from the itemized deduction.

    Parameters:
        adj_income:
            This is the adjusted gross income of the user.

    Returns:
        This function returns the itemized tax deduction of the user.
    """
    print()
    print('Determining the itemized deduction ...')
    print()
    item_deduction = itemized_expenses()
    if adj_income <= 150000:
        item_deduction
    else:
        step_1 = item_deduction* 0.8
        step_2 = (adj_income - 150000) * 0.03
        if step_1 == step_2:
            item_deduction = 'The two deductions are equal.'
        item_deduction = min(step_1, step_2)
    return item_deduction

def standard_deduction_text():
    """This function prints the filing status(s) for the user so they can look at
        the options of input.
    """
    print()
    print('Determining the standard deduction ...')
    print()
    print('1) Single')
    print('2) Married filing jointly')
    print('3) Married filing separately')
    print('4) Head of household')
    print('5) Qualifying widow(er)')

def standard_deduction():
    """This function calculates the standard tax deduction of the user, it calls the
        standard_deduction_text to print the options to the screen.
    """
    standard_deduction_text()
    filing_status = int(input('Select filing status: '))
    if filing_status == 1:
        standard_deduction_tax = 12400
    elif filing_status == 2:
        standard_deduction_tax = 24800
    elif filing_status == 3:
        standard_deduction_tax = 12400
    elif filing_status == 4:
        standard_deduction_tax = 18650
    else:
        standard_deduction_tax = 24800
    return standard_deduction_tax

def choice_is_one(gross_income):
    """This function runs the itemized deduction and standard deduction process
        in the users demanded order.

        Parameters:
            gross_income:
                The adjusted gross income of the user.

        Returns:
            This function prints the suggested method based on the calculations done.
    """
    adj_income = (gross_income)
    a = itemized_deduction(adj_income)
    b = standard_deduction()
    print()
    print(f'Itemized deduction = ${a:.2f}')
    print(f'Standard deduction = ${b:.2f}')
    if a > b:
        print('We suggest claiming the itemized deduction.')
    elif b > a:
        print('We suggest claiming the standard deduction.')
    else:
        print('The two deductions are equal.')



def choice_is_two(gross_income):
    """This function runs the itemized deduction and standard deduction process
        in the users demanded order.

        Parameters:
            gross_income:
                The adjusted gross income of the user.

        Returns:
            This function prints the suggested method based on the calculations done.
    """
    adj_income = gross_income
    b = standard_deduction()
    a = itemized_deduction(adj_income)
    print()
    print(f'Itemized deduction = ${a :.2f}')
    print(f'Standard deduction = ${b :.2f}')
    if b > a:
        print('We suggest claiming the standard deduction.')
    elif a > b:
        print('We suggest claiming the itemized deduction.')
    else:
            print('The two deductions are equal.')


def main():
    print_intro()
    choice_selector(gross_income())



# DO NOT CHANGE ANYTHING BELOW THIS COMMENT.
if __name__ == '__main__':
    main()
