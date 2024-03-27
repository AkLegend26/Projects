# Name: Ayush Pathak
# VUnetID: pathaa3
# Email: ayush.pathak@vanderbilt.edu
# Class: CS 1104 - Vanderbilt University
# Section: 2
# Date: 10/06/2021
# Honor statement: I attest that I understand the honor code for this class and have
#                  neither given nor recieved any unauthorized aid on this assignment.

# Program description:  This program asks questions about 2 credit cards and recommends
# the one that provides more annual rewards.


def print_intro():
    """Prints the introduction statement to the user."""

    print('This program compares two credit card offers to determine')
    print('the best credit card in terms of award dollars.')


def get_award_dollars(monthly_expenses, annual_fee, points_per_dollar):
    """Returns the award value in dollars of the credit card .

    Parameters:
        monthly_expenses:
            Input by the user that states their monthly expenses.
        annual_fee:
            Annual fee of the credit card.
        points_per_dollar:
            The points credit card company provides for every dollar spent.

    Returns:
        The award money by the use of credit card in a year."""
    award_dollar = ((((monthly_expenses * 12) * points_per_dollar) / 100) - annual_fee)
    if award_dollar > 0:
        return award_dollar
    else:
        return int(0)


def process_card(num, monthly_expenses):
    """Prints information on the screen and asks for credit card information than calls
    get_award_dollar function to get the award dollar value in a year.

    Parameters:
        num:
            Credit Card number for comparison with the other Credit Card.
        monthly_expenses:
            The monthly expenses of the user.

    Returns:
        Calls get_award_dollars function with defined parameters."""
    print('=== Credit Card', num, 'Offer ===')
    annual_fee = float(input('Enter annual fee: '))
    points_per_dollar = float(input('Enter points per dollar spent: '))
    print()
    return get_award_dollars(monthly_expenses, annual_fee, points_per_dollar)


def print_recommendation(award_dollars_1, award_dollars_2):
    """Compares the award value form the first credit card to the second one
    and prints the recommendation depending on which one is greater.

    Parameters:
        award_dollars_1:
            Award in dollars tha t are provided by the first Credit Card.
        award_dollars_2:
            Award in dollars that are provided by the second Credit Card.

    Returns:
        Prints the award value of both credit card and the recommendation."""
    print(f'Credit Card 1 annual award dollars = ${award_dollars_1 :.2f}')
    print(f'Credit Card 2 annual award dollars = ${award_dollars_2 :.2f}')
    print()
    if award_dollars_1 > award_dollars_2:
        print('We recommend applying for Credit Card 1.')
    elif award_dollars_2 > award_dollars_1:
        print('We recommend applying for Credit Card 2.')
    elif award_dollars_2 == award_dollars_1:
        print('Both cards result in the same total award dollars.')


def main():
    print_intro()
    print()
    monthly_expenses = float(input('Enter estimated monthly expenses: '))
    print()
    print_recommendation(process_card(1, monthly_expenses), process_card(2, monthly_expenses))


# DO NOT CHANGE ANYTHING BELOW THIS COMMENT.
if __name__ == '__main__':
    main()