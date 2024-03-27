# Name: Ayush Pathak
# VUnetID: pathaa3
# Email: ayush.pathak@vanderbilt.edu
# Class: CS 1104 - Vanderbilt University
# Section: 2
# Date: 10/25/2021
# Honor statement: I attest that I understand the honor code for this class and have
#                  neither given nor received any unauthorized aid on this assignment.

# Program Description: This program prints information about the flight details based
#                      on its departure time, such as, if it is late or on_time. It
#                      prints information in multiple ways to make it easier for the
#                      user to understand the details about the flights time and schedule.

def on_time_sequence(difference):
    """
    This function prints the on time sequence wiht letters to the screen.

    Parameters:
        difference:
            list of difference in actual - estimated time of departure.

    Returns:
        Prints the 'O' and 'L' sequence on screen depending on if flight
        is on time or late.
    """
    print('On-time/delayed sequence')
    print('========================')
    o_string = ''

    for time in range(0, len(difference)):
        if -15 <= difference[time] <= 15:
            o_string = o_string + 'O'
        else:
            o_string = o_string + 'L'
    if len(o_string) > 5:
        print(o_string[0:5])
        print(o_string[5:])
    else:
        print(o_string)


def on_time_delayed(difference):
    """
    This function indexes the list difference into sections. Sections are
    if flight is early, if it is on_time, if it is delayed by 30min, if it is
    delayed by 60min or if it delayed by more than 60min.

    Parameters:
        difference:
            list of difference in actual - estimated time of departure.

    Returns:
        This function calls the function print_time_delay with the calculated
        details about the flight.
    """
    early_depart = 0
    ontime = 0
    delayed_30 = 0
    delayed_60 = 0
    delayed_more = 0
    for time in range(0, len(difference)):
        if difference[time] < 0:
            early_depart += 1
        elif difference[time] <= 15:
            ontime += 1
        elif difference[time] <= 30:
            delayed_30 += 1
        elif difference[time] <= 60:
            delayed_60 += 1
        else:
            delayed_more += 1

    print_time_delay(early_depart, ontime, delayed_30, delayed_60, delayed_more, difference)


def print_time_delay(early_depart, ontime, delayed_30, delayed_60, delayed_more, difference):
    """
    This function prints the detailed information about the flight on the screen.

    Parameters:
        early_depart:
            number of flights that departed early.
        ontime:
            number of flights that departed on time.
        delayed_30:
            number of flights that departed up to 30 mins late.
        delayed_60:
            number of flights that departed up to 60 mins late.
        delayed_more:
            number of flights that departed more than 60 mins late.
        difference:
            list of difference in actual - estimated time of departure.

    Returns:
        This function prints the detailed information on the screen.
    """

    print('On-time/delayed departures')
    print('==========================')

    early_percent = round((early_depart / len(difference)) * 100)
    ontime_percent = round((ontime / len(difference)) * 100)
    delayed_30_percent = round((delayed_30 / len(difference)) * 100)
    delayed_60_percent = round((delayed_60 / len(difference)) * 100)
    delayed_more_percent = round((delayed_more / len(difference)) * 100)
    print(f'Early departures: {early_depart} ({early_percent}%)')
    print(f'On-time departures: {ontime} ({ontime_percent}%)')
    print(f'Delayed departures (30 minutes): {delayed_30} ({delayed_30_percent}%)')
    print(f'Delayed departures (one hour): {delayed_60} ({delayed_60_percent}%)')
    print(f'Delayed departures (more than an hour): {delayed_more} ({delayed_more_percent}%)')


def overview(difference):
    """
    This function prints the overview section of the flight and calculates
    if flights are on time or not and their average delay.

    Parameters:
        difference:
            list of difference in actual - estimated time of departure.

    Returns:
        This function prints the average delay and number of on time flights
        on the screen.
    """

    print('Overview')
    print('========')
    print(f'Total departures: {len(difference)}')
    on_time = 0
    avg_delay = []
    for time in range(0, len(difference)):
        if -15 <= difference[time] <= 15:
            on_time += 1
        else:
            avg_delay.append(difference[time])

    print(f'On-time departures: {round((on_time / len(difference)) * 100)}%')
    if len(avg_delay) > 0:
        print(f'Average delay of departure (minutes): {round((sum(avg_delay)) / len(avg_delay))}')
    else:  # To make sure it is not dividing by 0.
        print(f'Average delay of departure (minutes): 0')


def con_to_min(departure_list):
    """
    This function converts time entered by user to only minutes.

    Parameters:
        departure_list:
            List entered by the user in military format.

    Returns:
        This function returns the updated list that is in minutes.
    """

    conv_list = []
    for time in departure_list:
        h = (time // 100) * 60
        m = time % 100
        time = h + m
        conv_list.append(time)
    return conv_list


def user_input():
    """
    This function asks the user for input and calculates the difference between
    actual and expected departure times.

    Returns:
        This function returns the expected departure list, actual departure list
        and the difference between them in a list.
    """

    expected_departure = []
    actual_departure = []
    time = input('Enter expected departure time (or "done" to continue): ')
    while time != 'done':
        actual_time = int(input('Enter actual departure time: '))
        actual_departure.append(actual_time)
        time = int(time)
        expected_departure.append(time)
        time = input('Enter expected departure time (or "done" to continue): ')
    expected_departure = con_to_min(expected_departure)
    actual_departure = con_to_min(actual_departure)
    diff = []
    for time in range(0, len(actual_departure)):
        time2 = actual_departure[time]
        time1 = expected_departure[time]
        difference = time2 - time1
        diff.append(difference)
    return expected_departure, actual_departure, diff


def main():
    [expected_departure, actual_departure, difference] = user_input()
    if len(actual_departure) == 0:
        print('No information entered.')
    else:
        print()
        overview(difference)
        print()
        on_time_delayed(difference)
        print()
        on_time_sequence(difference)


# DO NOT CHANGE ANYTHING BELOW THIS COMMENT.
if __name__ == '__main__':
    main()