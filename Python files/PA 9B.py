# Name: Ayush Pathak
# VUnetID: pathaa3
# Email: ayush.pathak@vanderbilt.edu
# Class: CS 1104 - Vanderbilt University
# Section: 2
# Date: 11/18/2021
# Honor statement: I attest that I understand the honor code for this class and have
#                  neither given nor received any unauthorized aid on this assignment.

# Program description: Prints the Max, Min and average for days and overall time,
#                      based on the data in the input file.


def print_info(m , l , avg, z):
    print('\n'f'Day {z}:')
    print(f'Max: {m:.2f}')
    print(f'Min: {l:.2f}')
    print(f'Avg: {avg:.2f}')


def numbers(content):
    """
    This function converts the strings into numbers.

    Parameters:
        content:
            List of lines in the file.

    Returns:
        Updated o_avg list and line(all numbers in a line) list.
    """
    days = 0
    o_avg = []
    o_max = []
    o_min = []
    for x in content:
        c = x.split()
        line = []
        for idx in c:
            if idx.isdigit():
                line.append(int(idx))
                o_avg.append(int(idx))
        days+=1
        calculations(line,days,o_max,o_min)
    overall(o_max, o_min, o_avg)


def calculations(line,days,o_max,o_min):
    """
    This function performs the calculations to print.

    Parameters:
        line:
            Lines of the file.
        days:
            days that the temperature corresponds to.
        o_max:
            List containing overall max for each day.
        o_min:
            List containing overall min for each day.

    Returns:
        An updated version of o_max and o_min
    """
    m = max(line)
    o_max.append(m)
    l = min(line)
    o_min.append(l)
    avg = sum(line) / len(line)
    print_info(m, l, avg, days)


def overall(o_max, o_min, o_avg):
    """
    This function prints overall stats to the screen.

    Parameters:
        o_max:
            List containing overall max for each day.
        o_min:
            List containing overall min for each day.
        o_avg:
            List containing all the temperature values in the file.
    """
    print('\n''Overall stats:')
    print(f'Max: {max(o_max):.2f}')
    print(f'Min: {min(o_min):.2f}')
    print(f'Avg: {sum(o_avg) / len(o_avg):.2f}')


def main():
    # Type your code here.
    file = input('Enter file name: ')
    f = open(file)
    content = f.readlines()
    f.close
    numbers(content)


# DO NOT CHANGE ANYTHING BELOW THIS COMMENT.
if __name__ == '__main__':
    main()