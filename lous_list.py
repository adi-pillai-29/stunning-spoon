#Aditya Pillai - arp3np

import urllib.request

def instructors(department):
    """
    This function accesses an online file of snapshots of Lou's List, with the file containing courses given the department parameter.
    It then puts together and returns an alphabetically-sorted list containing each instructor listed in Lou’s List for the given department.
    Instructors are not counted twice and any "+1"s, etc. are not included.

    :param department: the department whose course and instructor information we are trying to access (e.g. CS)
    :return: instructors--an alphabetically sorted list created by accumulator programming that contains all the instructors--non repeated--in a given department
    """
    dept = urllib.request.urlopen("http://cs1110.cs.virginia.edu/files/louslist/"+department) #Access department online file
    instructors = [] #null list to be filled and sorted w/ instructors
    for line in dept: #reading through each line in the file, decoding it, creating an array from it
        decoded = line.decode('utf-8')
        line_list = decoded.split("|")
        if line_list[4].find('+') != -1: #handling extra characters in the instructor element (i.e. +n) where n is a single digit
            index = line_list[4].find('+')
            line_list[4] = line_list[4][0:index]
        if line_list[4] not in instructors:    #appending the instructor element to the null array if not present
            instructors.append(line_list[4])
    instructors.sort() #sort instructors array
    return instructors #return instructors array

def class_search(dept_name, has_seats_available=True, level=None, not_before=None, not_after=None):
    """
    This function searches for classes from an online file within a given department that match the requirements of the parameter inputs.
    These classes/all their info are placed as lists (from the process of reading and splitting each line) into a grand list of compatible classes/info through accumulator programming.

    :param dept_name: name of the department, no default
    :param has_seats_available: boolean parameter. If true, this means current enrollment must be less than the allowable enrollment. If false, no requirement on this. Default = True
    :param level: 4 digit value that is used to find classes whose course number/level first digit match the first digit of the level parameter
    :param not_before: a limit on the time at which a class begins. Expressed as a 4 digit number in the 24 hour system for displaying time. If a value besides None (default) is there, the class cannot happen before this parameter of time.
    :param not_after: a limit on the time at which a class begins. Expressed as a 4 digit number in the 24 hour system for displaying time. If a value besides None (default) is there, the class cannot happen after this parameter of time.
    :return: returns a list containing list versions of all the classes that match the parameter requirements
    """
    dept = urllib.request.urlopen("http://cs1110.cs.virginia.edu/files/louslist/" + dept_name) #opening the file given the dapartment
    classes = [] #null list to be filled with lists of the parameter-matching classes
    for line in dept:  #iterating through the lines in the file object
        decoded = line.decode('utf-8').strip()  #decode the file, remove empty spacees
        line_list = decoded.split("|") #create a list from each line by splitting on "|"
        if has_seats_available == True: #This entire portion onwards is a series of conditionals for each parameter that determines (True/False) if the current line/class from the file matches the parameters-this conditional determines if a class has seats available by...
            if int(line_list[15]) < int(line_list[16]): #...comparing if the enrollment is less than the allowable enrollment
                bool1 = True
            else:
                bool1 = False
        else:
            bool1 = True    #yields True if the has_seats_available parameter was False, meaning the class search won't be limited by the enrollment/allowable enrollment
        if level != None:       #conditional for determining if the level parameter's first digit matches the current class number's first digit
            str_level = str(level)
            if line_list[1][0] == str_level[0]:
                bool2 = True
            else:
                bool2 = False
        else:    #If level = None, then the level of the class is not a consideration/limiting factor in the class search
            bool2 = True
        if not_before != None:  #conditional for determining if the current class's beginning time occurs after and including the not_before parameter
            if int(line_list[12]) >= not_before:
                bool3 = True
            else:
                bool3 = False
        else:    #If not_before  = None, then the time of the class is not a consideration/limiting factor in the class search
            bool3 = True
        if not_after != None:   #conditional for determining if the current class's beginning time occurs before and including the not_after parameter
            if int(line_list[12]) <= not_after:
                bool4 = True
            else:
                bool4 = False
        else:    #If not_after  = None, then the time of the class is not a consideration/limiting factor in the class search
            bool4 = True
        if bool1 and bool2 and bool3 and bool4: #If all the boolean conditions for each parameter are True, then the current class in the search is appended to the growing list of compatible classes
            classes.append(line_list)
    return classes #return the list of each class matching the parameter requirement expressed as a list



