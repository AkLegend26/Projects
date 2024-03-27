# Name: Ayush Pathak
# VUnetID: pathaa3
# Email: ayush.pathak@vanderbilt.edu
# Class: CS 1104 - Vanderbilt University
# Section: 2
# Date: 11/09/2021
# Honor statement: I attest that I understand the honor code for this class and have
#                  neither given nor received any unauthorized aid on this assignment.

# Program Description: This program prints number of payment with amounts, interest and
#                      remaining balance based on the loan amount.

def main():
    # Type your code here.
    string = input('Enter information: ')
    print()

    unit_s = string.split()  # seperate the elements from the input.
    # converting all the elements into floats.
    p = float(unit_s[0])
    r = float((float(unit_s[1])) / 12)
    n = float(unit_s[2])
    lines_to_print = float(unit_s[3])

    print('----------------------------------------------------------')
    print('| Payment | Amount | Interest | Principal | Loan Balance |')
    print('----------------------------------------------------------')

    pay = 0
    a = p * (r * ((1.0 + r) ** n)) / (((1 + r) ** n) - 1.0)  # calculating monthly amount.

    while pay != lines_to_print:
        int = p * r
        prin = a - int
        bal = p - prin
        p = bal
        pay += 1
        print(f'|{pay:8.0f} |{a:7.2f} |{int:9.2f} |{prin:10.2f} |{bal:13.2f} |')

    print('----------------------------------------------------------')


# DO NOT CHANGE ANYTHING BELOW THIS COMMENT.
if __name__ == '__main__':
    main()