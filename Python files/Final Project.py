class Person:
    """
    class person creates a custom person object.
    """
    def __init__(self, name='N/A', birth_date='N/A', death_date=''):
        """
        init initializes the name, birth_date and death_date attributes of the created
        Person object.

        Parameter:
            name:
                Name of the Person object.
            birth_date:
                Birth_date of the Person object.
            death_date:
                Death_date of the Person object.
        """
        self.__name = name
        self.__birth_date = birth_date
        self.__death_date = death_date
        self.__children = []
        self.__parent = None

    def add_child(self, child):
        """
        This method adds a child to the Person object's children list
        and sets the current person as the parent.

        Parameter:
            child:
                Child object that is added as a child to the Person's children list.

        Return:
             An updated list of the current Person's child list.
        """
        child.set_parent(self)
        self.__children.append(child)

    def delete_child(self, child):
        """
        This method deletes a child from the children list.

        Parameter:
            child:
                The child object that will be deleted from the children list.

        Return:
             Updated children list for the Person.
        """
        self.__children = [name for name in self.__children if name.get_name() != child]

    def get_age(self):
        """
        This method calculates the age of the current person.

        Return:
             Age of the Person.
        """
        age = int(self.__death_date[0:4]) - int(self.__birth_date[0:4])
        if int(self.__death_date[5:7]) < int(self.__birth_date[5:7]):
            return age - 1
        elif int(self.__death_date[5:7]) == int(self.__birth_date[5:7]):
            if int(self.__death_date[8: 10]) < int(self.__birth_date[8:10]):
                return age - 1
            else:
                return age
        else:
            return age

    def get_birth_date(self):
        """
        This method accesses the birth_date attribute of the Person.

        Return:
             Printed Person's birth_date.
        """
        return f'{self.__birth_date}'

    def get_child(self, name):
        """
        This method accesses the child from the children list.

        Parameters:
            name:
                Name of the child.

        Returns:
            The children object requested.
        """
        for idx in range(len(self.__children)):
            if self.__children[idx].get_name() == name:
                return self.__children[idx]

    def get_children(self):
        """
        This method accesses the children list attribute.

        Return:
             The children list.
        """
        return self.__children

    def get_death_date(self):
        """
        This method accesses the death_date attribute of the Person.

        Return:
             The death_date for the Person.
        """
        return self.__death_date

    def get_name(self):
        """
        This method accesses the name attribute of the Person.

        Return:
             Name of the Person.
        """
        return self.__name

    def get_parent(self):
        """
        Accesses the Parent attribute of the Person.

        Return:
             Parent object.
        """
        return self.__parent

    def set_birth_date(self, date):
        """
        This method updates the birth_date of the object.

        Parameters:
            date:
                New date_of_birth.

        Return:
             Updated date_of_birth.
        """
        self.__birth_date = date

    def set_death_date(self, date):
        """
        This method updates the death_date of the Person.

        Parameter:
            date:
                new date_of_death.

        Return:
             Updated date-of_birth.
        """
        self.__death_date = date

    def set_name(self, name):
        """
        This method updates the name of the Person.

        Parameter:
            name:
                New name of the object.

        Return:
             Updated name of the Person.
        """
        self.__name = name

    def set_parent(self, parent):
        """
        This method updates the parent.
        Parameter:
            parent:
                New parent.
        Returns:
             Updates the parent of the Person.
        """
        self.__parent = parent

    def __str__(self):
        """
        This method prints out the Persons initial attributes.

        Returns:
             String composed of Person's initial attributes.
        """
        if len(self.__death_date.split()) == 0:
            return f'{self.__name} *{self.__birth_date}'
        else:
            age = self.get_age()
            return f'{self.__name} *{self.__birth_date} ✝{self.__death_date} ({age})'

    def __eq__(self, human):
        """
        This function compares two objects to see if they are equal.

        Parameters:
            human:
                Object being compared to Person.

        Returns:
            If the objects are equal or not in a Boolean value.
        """
        if isinstance(human, Person):
            if human.__name == self.__name:
                if (
                    human.__birth_date[0:4] == self.__birth_date[0:4]
                    and human.__birth_date[5:7] == self.__birth_date[5:7]
                ):
                    if (
                        human.__death_date[0:4] == self.__death_date[0:4]
                        and human.__death_date[5:7] == self.__death_date[5:7]
                    ):
                        return True
                    else:
                        return False
                else:
                    return False
            else:
                return False
        else:
            return False

# from person import Person


def name_check(name):
    """
    This function checks the conditions for a valid name input.

    Parameter:
        name:
            Name that will be checked.

    Returns:
         Valid name input.
    """
    while len(name.split()) == 0:
        name = input('ERROR: No name entered, try again: ')
    return name


def date_format(dob):
    """
    This function checks the format for the date input.
    parameter:
        dob:
            Date input.
    Returns:
         Valid date input.
    """
    while (len(dob)) != 10:
        print('ERROR: Must follow 1970-01-01 format, try again: ', end='')
        dob = input()
    while not (dob[4] == '-' or dob[7] != '-'):
        print('ERROR: Must follow 1970-01-01 format, try again: ', end='')
        dob = input()
    return dob


def print_info(current_person):
    """
    This function prints the Person object info to the screen with options that user cna choose.

    Parameter:
        current_person:
            Person Object.

    Returns:
         The choice made by the user.
    """
    print('------------------------------------------------------')
    print(current_person.__str__())
    print('------------------------------------------------------')
    print(' 1) Edit name                 6) Print statistics')
    print(' 2) Edit date of birth        7) Print children')
    print(' 3) Edit date of death        8) Print grandchildren')
    print(' 4) Add a child               9) Print aunts/uncles')
    print(' 5) Delete a child           10) Print cousins')
    print()
    print('11) Enter child\'s family     12) Enter parent\'s family')
    print()
    print('Select option (or 0 to exit): ', end='')

    selection = int(input())
    while not (0 <= selection <= 12):
        selection = int(input('Invalid input. Try again. '))
    print()
    if selection == 0:
        print()
    return selection


def edit_name(current_person):
    """
    This function edits the name of the person.

    Parameter:
        current_person:
            Person object.

    Returns:
         Updated name of the Person.
    """
    print('Enter name: ', end='')
    name = input()
    current_person.set_name(name_check(name))
    print()


def edit_date_birth(current_person):
    """
    This function edits the date of birth of the Person.

    Parameter:
        current_person:
            Person object.

    Returns:
         Updated date of birth of the Person.
    """
    print('Enter date of birth: ', end='')
    dob = input()
    dob = date_format(dob)
    current_person.set_birth_date(dob)
    print()


def edit_date_death(current_person):
    """
    This function edits the date of death of the Person.

    Parameter:
        current_person:
            Person object.

    Returns:
         Updated date of death of the Person.
    """
    dod = input('Enter date of death: ')
    dod = date_format(dod)
    current_person.set_death_date(dod)
    print()


def add_child(current_person):
    """
    This function adds a child to the current Person if the child doesn't already exist.

    Parameter:
        current_person:
            Person object.

    Returns:
         An updated list of Children for Person.
    """
    name = input('Enter name: ')
    name = name_check(name)

    dob = input('Enter date of birth: ')
    dob = date_format(dob)

    new_child = Person(name, dob)
    for child in current_person.get_children():
        if child.__eq__(new_child):
            print('ERROR: Child with same name, and year and month of birth already exists.')
            print()
            return
    print()
    current_person.add_child(new_child)


def del_child(current_person):
    """
    This function deletes a child from the Person's Children list.

    Parameter:
        current_person:
            Person object.

    Returns:
         Updated list of the Children for the Person.
    """
    if len(current_person.get_children()) == 0:
        print(f'No children found for {current_person.get_name()}.')
        print()
        return

    for idx, name in enumerate(current_person.get_children()):
        print(f'{idx + 1}) {name.get_name()}')
    selection = int(input('Select a child (or 0 to go back to main menu): '))
    print()

    if selection == 0:
        print('Returning to main menu.')
        print()
        return

    lst = current_person.get_children()
    removed_child = lst[selection - 1].get_name()
    print(f'{removed_child} deleted.')
    print()
    current_person.delete_child(removed_child)


def print_stat(current_person):
    """
    This function prints number of children and grandchildren for the Person.

    Parameters:
        current_person:
            Person object.
    """
    print(f'Number of children: {len(current_person.get_children())}')
    grand_children = 0
    for idx, name in enumerate(current_person.get_children()):
        grand_children += len(name.get_children())
    print(f'Number of grandchildren: {grand_children}')
    print()


def print_children(current_people):
    """
    This function prints the children of the Person.

    parameter:
        current_people:
            Person object.
    """
    child_list = current_people.get_children()
    if len(child_list) == 0:
        print(f'No children found for {current_people.get_name()}.')
        print()
        return
    print(f'Children of {current_people.get_name()}:')
    for idx in child_list:
        print(f'- {idx.__str__()}')
    print()


def print_grand_children(current_person):
    """
    This function prints the grandchildren of the Person, if they exist.

    Parameters:
        current_person:
            Person object.
    """
    if len(current_person.get_children()) == 0:
        print(f'No grandchildren found for {current_person.get_name()}.' '\n')
        return

    print(f'Grandchildren of {current_person.get_name()}:')
    for idx, name in enumerate(current_person.get_children()):
        for index, grand_child in enumerate(name.get_children()):
            print(f'- {grand_child.__str__()}')
    print()


def print_aunt_uncles(current_person):
    """
    This function prints aunts and uncles of the Person, if they exist.

    Parameters:
        current_person:
            Person object.
    """
    if not current_person.get_parent():
        print(f'No aunts and uncles found for {current_person.get_name()}.''\n')
        return
    if current_person.get_parent() == 1:
        print(f'No aunts and uncles found for {current_person.get_name()}.''\n')
        return

    parents = current_person.get_parent()

    if not parents.get_parent():
        print(f'No aunts and uncles found for {current_person.get_name()}.''\n')
        return
    if parents.get_parent() == 1:
        print(f'No aunts and uncles found for {current_person.get_name()}.''\n')
        return

    grand_parents = parents.get_parent()

    if len(grand_parents.get_children()) <= 1:
        print(f'No aunts and uncles found for {current_person.get_name()}.''\n')
        return
    print(f'Aunts and uncles of {current_person.get_name()}:')
    for idx, name in enumerate(grand_parents.get_children()):
        if name.get_name() != parents.get_name():
            print(f'- {name.__str__()}')
    print()


def print_cousins(current_person):
    """
    This function prints the cousins of the current person, if they exist.

    Parameter:
        current_person:
            Person object.
    """
    if current_person.get_parent() == None:
        print(f'No aunt and uncles found for {current_person.get_name()}' '\n')
        return
    parents = current_person.get_parent()
    if parents.get_parent() == None:
        print(f'No aunt and uncles found for {current_person.get_name()}' '\n')
        return
    grand_parents = parents.get_parent()
    if len(grand_parents.get_children()) <= 1:
        print(f'No aunt and uncles found for {current_person.get_name()}' '\n')
        return
    print(f'Cousins of {current_person.get_name()}:')
    for name in grand_parents.get_children():
        if name.get_name() != parents.get_name():
            for child in name.get_children():
                print(f'- {child.__str__()}')
    print()


def child_family(current_person):
    """
    This function accesses into the children's object.

    parameter:
        current_person:
            Person object.

    Returns:
         Updated current person depending on who user wants to access.
    """
    if len(current_person.get_children()) == 0:
        print(f'No children found for {current_person.get_name()}.')
        print()
        return current_person

    for idx, name in enumerate(current_person.get_children()):
        print(f'{idx + 1}) {name.get_name()}')

    selection = int(input('Select a child (or 0 to go back to main menu): '))
    print()
    if selection == 0:
        print('Returning to main menu.')
        print()
        return current_person

    lst = current_person.get_children()
    name = lst[selection - 1]
    print(f'Entering family of {name.get_name()}.')
    print()
    return name


def parent_family(current_person):
    """
    This function accesses the parent's family.

    parameter:
        current_person:
            Person object.

    Returns:
         Updated current person depending on users choice.
    """
    if current_person.get_parent() == None:
        print(f'No parent found for {current_person.get_name()}.')
        print()
        return current_person

    parent = current_person.get_parent()
    print(f'Entering family of {parent.get_name()}.' '\n')
    return parent


def action(selection, current_person):
    """
    This function calls for action depending on users selection.

    Parameters:
        selection:
            The choice made by the user.
        current_person:
            Person object.

    Returns:
         updated current person from the user's choice.
    """
    if selection == 1:
        edit_name(current_person)
        return current_person

    if selection == 2:
        edit_date_birth(current_person)
        return current_person

    if selection == 3:
        edit_date_death(current_person)
        return current_person

    if selection == 4:
        add_child(current_person)
        return current_person

    if selection == 5:
        del_child(current_person)
        return current_person

    if selection == 6:
        print_stat(current_person)
        return current_person

    if selection == 7:
        print_children(current_person)
        return current_person

    if selection == 8:
        print_grand_children(current_person)
        return current_person

    if selection == 9:
        print_aunt_uncles(current_person)
        return current_person

    if selection == 10:
        print_cousins(current_person)
        return current_person

    if selection == 11:
        return child_family(current_person)

    if selection == 12:
        return parent_family(current_person)


def main():
    current_person = Person('John Doe', '1960-01-15', '2020-01-15')
    selection = print_info(current_person)
    while selection != 0:
        current_person = action(selection, current_person)
        selection = print_info(current_person)


# DO NOT CHANGE ANYTHING BELOW THIS COMMENT.
if __name__ == '__main__':
    main()

