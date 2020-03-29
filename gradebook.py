#Aditya Pillai - arp3np

dict1 = {}
dict2 = {}

def assignment(kind, grade, weight = 1):
    """
    This function computes a running total for the weighted average of a assignment type given assignments in the type.
    One assignment per method call. The function keeps track of stats such as the cumulative values of the weight parameter,
    the running total for the weighted average, and a triple nested dictionary that keeps track of grade:weight pairs so
    they can be recalculated each function execution
    :param kind: the type of the assignment that serves as the primary key for the series of dictionaries
    :param grade: the grade value for the assignment
    :param weight: the weight of the assignment relative to other assignments
    :return:
    """
    global dict1 #global dictionaries
    global dict2
    grade = str(grade)
    if kind not in dict1: #process when kind is not a key in the comprehensive dictionary dict1
        dict1[kind] = {'cum_weight':0, 'running_total':0, 'prior':{}} #key - kind, value - dictionary
        dict1_entry = dict1.get(kind)
        dict1_entry['cum_weight'] += weight
        dict1_entry['prior'].update({grade:weight}) #revising the cumulative weight and the dictionary at the end intended to hold all grade:weight pairs
        prior2 = {}
        for keys in dict1_entry['prior']: #creating a dictionary of grades and their decimal weights
            prior2[keys] = dict1_entry['prior'][keys] / (dict1_entry['cum_weight'])
        array_weights = list(range(len(prior2)))
        i = 0
        for keys, values in prior2.items(): #populating an array with values of grade * decimal weights
            array_weights[i] = float(keys) * values
            i += 1
        sum_weights = sum(array_weights) #summing the elements of the array to form the current grade type average
        dict1_entry['running_total'] = sum_weights  #revising the value for running total key
        dict1[kind] = dict1_entry   #assigning the completely updated dictionary w/ cumulative weights, running total, and dictionary of grade:weight pairs
        dict2[kind] = sum_weights #dict2 - streamlined dictionary with just kind and the overall weighted average from assignments
    else:                               #process for when kind is already in the primary dictionary dict1
        dict1_entry = dict1.get(kind)
        dict1_entry['cum_weight'] += weight
        if grade in dict1_entry['prior']: #segment of code for handling events of "identical keys" when grade is already in a sub-dictionary
            if grade.find('.') == -1:
                grade += ".0"
                while grade in dict1_entry['prior']:
                    grade += "0"
            else:
                while grade in dict1_entry['prior']:
                    grade += "0"
        dict1_entry['prior'].update({grade: weight}) #adding the present grade/weight to the growing dictionary of assignment values per kind
        prior2 = {}
        for keys in dict1_entry['prior']:  #creating a dictionary of grades and their decimal weights
            prior2[keys] = dict1_entry['prior'][keys] / (dict1_entry['cum_weight'])
        array_weights = list(range(len(prior2)))
        i = 0
        for keys, values in prior2.items(): #populating an array with values of grade * decimal weights
            array_weights[i] = float(keys) * values
            i += 1
        sum_weights = sum(array_weights)  #summing the elements of the array to form the current grade type average
        dict1_entry['running_total'] = sum_weights #revising the value for running total key
        dict1[kind] = dict1_entry  #assigning the completely updated dictionary w/ cumulative weights, running total, and dictionary of grade:weight pairs
        dict2[kind] = sum_weights  #dict2 - streamlined dictionary with just kind and the overall weighted average from assignments

def total(proportions):
    """
    This function takes a dictionary that has keys of assignment types and values of ratios of the overall grade
    that the type applies to, and returns the cumulative grade based on proportions. From the assignment function,
    it is utilizing the global dictionary variable dict2, which contains assignment types and their overall weighted average/grade
    :param proportions: dictionary with assignment type keys and ratios of overall grade as values
    :return: returns the cumulative grade based on proportions
    """
    overall_grade = [] #empty array to hold the overall weighted averages for each assignment type
    for keys in proportions: #iterating through the keys in the parameter dictionary
        if keys in dict2: #checking if parameter keys are in dict2
            type_grade = proportions[keys] * dict2[keys] #if so, calculating the overall weighted average for assignment types
            overall_grade.append(type_grade) #adding this value to an empty array
        else:
            overall_grade.append(0) #if key not in dict2, the score on all assignments in that type are assumed to be 0, adding 0 to the array
    return "The overall course grade is " + str(sum(overall_grade)) #summing the elements of the array to yield the cumulative grade

#Sample run code examples:
syllabus = {
    'exam': 0.5,
    'hw': 0.4,
    'lab': 0.1,
}
print(total(syllabus))
assignment('exam', 83)
assignment('exam', 88)
assignment('exam', 91, 2)
print(total(syllabus))
assignment('hw', 100)
assignment('hw', 100)
assignment('hw', 70)
assignment('hw', 0)
assignment('hw', 100, 4)
assignment('hw', 50)
assignment('lab', 90)
print(total(syllabus))
assignment('extra', 300)
print(total(syllabus))
