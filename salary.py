#Aditya Pillai - arp3np

def report(name):
    """
    This function contains multiple nested functions that are responsible for extracting the right salary information using the name.
    These functions utilize searching through files for matching text with regular expressions in order to yield the title, salary, and rank from the database.
    After the sub-function definitions, this main report function reads through the salary web-page of name's url and calls the sub-functions to retrieve the specific data from the html

    :param name: any variation on the identifier for employees in UVA's salary data
    :return: returns values associated with the "name" in the database: title, salary, rank (in terms of salary)
    """
    import re
    import urllib.request

    def name_to_URL(name):
        """
        This function handles various ways of specifying a name to search for in a database by converting name to the form e.g. james-e-ryan

        :param name: any variation on the identifier for employees in UVA's salary data
        :return: returns the formatted version of the name/identifier that is compatible with the format of existing urls in the database
        """
        url_end = ""
        if ("." in name and "," not in name) or (name.count(" ") >= 1 and "," not in name): #Name entries expressed as First Middle Last
            name_list = name.split()
            for item in name_list:
                item = item.strip('.')
                url_end += item.lower() + "-"
            url_end = url_end.strip('-')
        elif "," in name: #Name entries expressed as Last, First Middle
            name_list = name.split()
            for i in range(1, len(name_list)):
                url_end += name_list[i].strip('.').lower() + "-"
            url_end += name_list[0].strip(',').lower()
        else: #Default for both already formatted entries (e.g. james-e-ryan and numerical entries)
            url_end = name
        return url_end

    def job_title_salary(data):
        """
        This function searches through the html for the webpage for a specific line that contains salary and title using a regular expression

        :param data: refers to the decoded string representation of the html file after being read. Matches based on a regular expression will be searched for in this text
        :return: returns a title str value and salary float value from groups in the match object in the text
        """
        title_finder = re.compile(r"<meta property=\"og:description\" content=\"Job title: (.*)<br /> 2018 total gross pay: \$([0-9]+),([0-9]+)\" />") #compiled regex for title and salary
        match_ob = title_finder.search(data) #searching for first instance of regex in data   #.group(1) = title                 #.group(2) + .group(3) = salary
        title = match_ob.group(1)
        if "&amp;" in title:
            title = title.replace("&amp;", "&")
        elif "&#39" in title:
            title = title.replace("&#39;", "'")
        salary = float(match_ob.group(2) + match_ob.group(3))
        return title, salary

    def pay_rank(data):
        """
        This function searches through the html for the webpage for a specific line that contains the rank using a regular expression

        :param data: refers to the decoded string representation of the html file after being read. Matches based on a regular expression will be searched for in this text
        :return: returns the rank from the from a group in the match object in the text
        """
        rank_finder = re.compile(r"<tr><td>University of Virginia rank</td><td>(.*) of 8,582<!--not null --></td></tr>")
        match_ob = rank_finder.search(data)
        if match_ob:
            if "," in match_ob.group(1):
                rank_str = match_ob.group(1)
                rank_str = rank_str.replace(",", "")
                rank = int(rank_str)
            else:
                rank = int(match_ob.group(1))
        else:
            rank = 0
        return rank

    url_end2 = name_to_URL(name)

    full_url = "http://cs1110.cs.virginia.edu/files/uva2018/" + url_end2
    try:
        with urllib.request.urlopen(full_url) as stream:
            data = stream.read().decode('utf-8')
        title, salary = job_title_salary(data)
        rank = pay_rank(data)
        return title, salary, rank
    except:                     #exception handling if the url does not exist, returns values of None, 0, 0 instead of title, salary, and rank
        return None, 0, 0


