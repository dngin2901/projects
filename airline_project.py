# Name:        Danny Ngin
# Program Title: Airline Flight Scheduling after providing txt file

# Function that will open the file
def openFile():
    goodFile = False
    while goodFile == False:
        fname = input("Enter name of data file: ")
        try:
            flightFile = open(fname, 'r')
            goodFile = True
        # excepting handling is raised when wrong file name is entered 
        except IOError:
            print("Invalid file name, please try again...")

    return flightFile

# function to store the data retrieved from the text file into the appropriate list
def getData():
    scheduleFile = openFile()
    airlineNameList = []
    flightNumList = []
    departureTimeList = []
    arrivalTimeList = []
    priceList = []
    for line in scheduleFile:
        line = line.strip()
        airline,flightNumber,departureTime,arrivalTime,price = line.split(',')
        airlineNameList.append(airline)
        flightNumList.append(flightNumber)
        departureTimeList.append(departureTime)
        arrivalTimeList.append(arrivalTime)
        # the airline prices have the $ removed before it is appended
        priceList.append(int(price[1:]))
    scheduleFile.close()

    return airlineNameList, flightNumList, departureTimeList, arrivalTimeList, priceList 

# function to convert the departure time and arrival time into minutes
def getFlightMinutes(departureTimeList, arrivalTimeList):
    departureMinuteList = []
    arrivalMinuteList = []
    # the hours and minutes is split from departureTimeList at the colon 
    for line in departureTimeList:
        departureHour, departureMin = line.split(':')
        departureHour = int(departureHour)
        departureMin = int(departureMin)
        # the total departure is calculated by multiplying the hours
        # by 60 than adding the minutes
        departureTotal = (departureHour * 60) + departureMin
        departureMinuteList.append(departureTotal)
    # the hours and minutes is split from arrivalTimeList at the colon
    for line in arrivalTimeList:
        line = line.strip()
        arrivalHour, arrivalMin = line.split(':')
        arrivalHour = int(arrivalHour)
        arrivalMin = int(arrivalMin)
        # the total arrival minutes is calculated by multiplying the hours
        # by 60 than adding the minutes
        arrivalTotal = (arrivalHour * 60) + arrivalMin
        arrivalMinuteList.append(arrivalTotal)
        
    return departureMinuteList, arrivalMinuteList

# function to subtract the arrivalMinuteList and departureMinuteList to get total flight
# time in minutes
def getFlightDuration(departureMinuteList, arrivalMinuteList):
    flightDurationList = []
    for i in range(len(departureMinuteList)):
        flightDurationList.append(arrivalMinuteList[i] - departureMinuteList[i])

    return flightDurationList
    
# function that prints the menu options 
def getChoice():
    menuChoice = 7
    choice = 0
    done = False
    while (done == False):
        try:
            print("\nPlease choose one of the following options: ")
            print("1 -- Find all flights on a particular airline")
            print("2 -- Find the cheapest flight")
            print("3 -- Find all flights less than a specified price")
            print("4 -- Find the shortest flight")
            print("5 -- Find all flights that depart within a specifed range")
            print("6 -- Find the average price for a specified airline")
            print("7 -- Quit")
            choice = int(input("choice ==> "))
            # if choice is not between 1 and 7 the error message is printed
            if choice < 1 or choice > menuChoice:
                print("\nInvalid option -- try again\n")
            else:
                done = True
        # exception handling is raised if choice entered is not an integer
        except ValueError:
            print("\nInvalid option -- try again\n")                           
        
    return choice

# function that will print all the flights for the airline entered
def airlineName(airlineNameList, flightNumList, departureTimeList, arrivalTimeList, priceList, flightDurationList):
    indexList = []
    done = False
    while (done == False):
        airlineName = input("\nEnter name of airline: ")
        # if the airline entered does not exactly match the airline names from the
        # airlineNameList, the error message will be printed
        if airlineName not in airlineNameList:
            print("Invalid input -- try again")
        else:
            done = True
    # if the airline entered matches the airline name list, the index position is
    # stored into indexList 
    for i in range(len(airlineNameList)):
        if airlineName == airlineNameList[i]:
            indexList.append(i)
    
    print("\nThe flights that meet your criteria are:\n")
    # all the flights for the airline and information is printed under the heading
    # which is also spaced using padding
    print("{:10}{:10}{:10}{:10}{:10}".format("AIRLINE", "FLT#", "DEPT", "ARR", "PRICE"))
    print("-------------------------------------------------------------")
    # the data from all the other list corrosponding to the airline entered is
    # printed using the index position from indexList
    for i in range(len(indexList)):
        print("{:10}{:10}{:10}{:10}${}".format(airlineNameList[indexList[i]],
                                                  flightNumList[indexList[i]],
                                                  departureTimeList[indexList[i]],
                                                  arrivalTimeList[indexList[i]],
                                                  priceList[indexList[i]]))
               
    return                 

# function to find the cheapest flight 
def cheapestFlight(priceList, airlineNameList, flightNumList):
    cheapest = 0
    cheapestIndex = 0
    # if the first index position in priceList is less than cheapest that price is
    # stored in cheapest until the lowest price in priceList is stored in cheapest
    for i in range(len(priceList)):
        if (priceList[i]) < (cheapest):
            cheapest = priceList[i]
            cheapestIndex = i
    # cheapestIndex provides the index position to print the corrosponding elements from the
    # other list
    print("\nThe cheapest flight is {} {} at ${}".format(airlineNameList[cheapestIndex],
                                                         flightNumList[cheapestIndex],
                                                         priceList[cheapestIndex]))

    return

# function that finds airlines that are cheaper than price entered
def flightsCheaperThan(airlineNameList, flightNumList, departureTimeList, arrivalTimeList, priceList):
    cheaper = 0
    indexList = []
    done = False
    while (done == False):
        try:
            # price entered from user
            cheaper = int(input("\nEnter your maximum price: $ "))
            done = True
        # exception handling is raised if a string is entered
        except ValueError:
            print("\nInvalid input please try again...") 
    # if any prices in priceList are less than cheaper the index position will be
    # stored in indexList
    for i in range(len(priceList)):
        if priceList[i] < cheaper:
            indexList.append(i)
    # if cheaper is to low or not an integer 
    # the indexList will be empty raising the print statement
    if indexList == []:
        print("No fights meet your criteria")
    # the prices less than user input and the list elements from
    # corrosponding lists are printed using the index position from indexList
    else:
        print("\nThe flights that meet your criteria are:\n")
        print("{:10}{:10}{:10}{:10}{:10}".format("AIRLINE", "FLT#", "DEPT", "ARR", "PRICE"))
        print("-------------------------------------------------------------")
        for i in range(len(indexList)):
            print("{:10}{:10}{:10}{:10}${}".format(airlineNameList[indexList[i]],
                                                  flightNumList[indexList[i]],
                                                  departureTimeList[indexList[i]],
                                                  arrivalTimeList[indexList[i]],
                                                  priceList[indexList[i]]))
        return
    
# function to find the shortest flight from departure to arrival
def shortestFlight(flightDurationList ,airlineNameList, flightNumList):
    shortest = flightDurationList[0]
    shortestIndex = 0
    # if the first index position in flightDurationList is less than shortest that time is
    # stored in shortest until the shortest time in flightDurationList is stored in shortest
    for i in range(len(flightDurationList)):
        if (flightDurationList[i]) < (shortest):
            shortest = flightDurationList[i]
            shortestIndex = i
    # shortestIndex provides the index position to print the corrosponding elements from the
    # other list
    print("\nThe shortest flight is {} {} at {} minutes".format(airlineNameList[shortestIndex],
                                                                flightNumList[shortestIndex],
                                                                flightDurationList[shortestIndex]))

    return

# function to convert user input from specifiedTime function to minutes
# by spliting the hour and minutes at the colon
def inputMinutes(userInput):
    hour, minute = userInput.split(':')
    hour = int(hour)
    minute = int(minute)
    totalMinute = (hour * 60) + minute

    return totalMinute

# function that prints all the airlines within a specified departure and arrival time 
def specifiedTime(airlineNameList, flightNumList, departureTimeList, arrivalTimeList, departureMinuteList, priceList):    
    indexList = []
    earliestDone = False
    latestDone = False
    while (earliestDone == False):
        try:
            # the user enters a 24 hour time for earliest departure time
            # which is then split by the colon
            earliestInp = input("\nEnter the earliest allowable departure time: ") 
            hour, minute = earliestInp.split(":")
            hour = int(hour)
            minute = int(minute)
            earliestDone = True
        # if user input does not contain a colon exception handling is raised
        except ValueError:
            print("Invalid time please try again...")
    while (latestDone == False):    
        try:
            # the user enters a 24 hour time for latest departure
            # which is then split by the colon
            latestInp = input("Enter the latest allowable departure time: ") 
            hour, minute = latestInp.split(":")
            hour = int(hour)
            minute = int(minute)
            latestDone = True
        # if user input does not contain a colon exception handling is raised
        except ValueError:
            print("Invalid time please try again...")
    # the inputs is converted to minutes by using the inputMinutes function
    latestInpMinute = inputMinutes(latestInp)
    earliestInpMinute = inputMinutes(earliestInp)
    # if departure time in minutes [i] is >= the earliest departure time in minutes
    # and if departure time in minutes [i] is <= latest departure time in minutes
    # the index position will be stored in indexList
    for i in range(len(departureTimeList)):
        if (departureMinuteList[i]) >= earliestInpMinute and (departureMinuteList[i]) <= latestInpMinute:
           indexList.append(i)            
    # the indexList is checked if its empty is so the message is printed
    if indexList == []:
        print("No fights meet your criteria")
    # the airlines and elements from the other list is printed using the
    # indexList as the index position
    else:
        print("\nThe flights that meet your criteria are:\n")
        print("{:10}{:10}{:10}{:10}{:10}".format("AIRLINE", "FLT#", "DEPT", "ARR", "PRICE"))
        print("-------------------------------------------------------------")
        for i in range(len(indexList)):
            print("{:10}{:10}{:10}{:10}${}".format(airlineNameList[indexList[i]],
                                                  flightNumList[indexList[i]],
                                                  departureTimeList[indexList[i]],
                                                  arrivalTimeList[indexList[i]],
                                                  priceList[indexList[i]]))

    return

# function to get average price for an airline
def averagePrice(airlineNameList, priceList):
    counter = 0
    total = 0
    done = False
    while (done == False):
        findAirline = input("\nEnter the name of the airline: ")
        # if the user input is spelled incorrectly an error message
        # will print
        if findAirline not in airlineNameList:
            print("invalid input please try again...")
        else:
            done = True
    for i in range(len(priceList)):
        # if user input matches airlineNameList all of
        # prices for the airline are added together and divided by the
        # total number prices
        if findAirline == airlineNameList[i]:
            total += priceList[i]
            counter += 1
    avgPrice = total / counter
    print("The average price is {}".format(avgPrice))

    return 
        
# main function calls on all option function, getData and getFlightDuration function                 
def main ():
    airlineNameList, flightNumList, departureTimeList, arrivalTimeList, priceList = getData()
    departureMinuteList, arrivalMinuteList, = getFlightMinutes(departureTimeList, arrivalTimeList)
    flightDurationList = getFlightDuration(departureMinuteList, arrivalMinuteList)
    choice = 0
    # loop to continue the getChoice function until the user enters 7
    # to exit program
    while choice != 7:
        choice = getChoice()
        if choice == 1:
            airlineName (airlineNameList, flightNumList, departureTimeList, arrivalTimeList, priceList, flightDurationList)
        elif choice == 2:
            cheapestFlight(priceList, airlineNameList, flightNumList)
        elif choice == 3:
            flightsCheaperThan(airlineNameList, flightNumList, departureTimeList, arrivalTimeList, priceList)
        elif choice == 4:
            shortestFlight(flightDurationList ,airlineNameList, flightNumList)
        elif choice == 5:
            specifiedTime(airlineNameList, flightNumList, departureTimeList, arrivalTimeList, departureMinuteList, priceList)
        elif choice == 6:
            averagePrice(airlineNameList, priceList)
main()
