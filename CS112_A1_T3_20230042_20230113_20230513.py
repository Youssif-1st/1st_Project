# Program: This program(TASK 3) works on solving different types of problems asking only from user input

# Author_1 (HAZEM AHMED MOHAMED) AND ID(20230113): PROBLEM ONE AND PROBLEM SIX

# Author-2 (ADHAM AYMAN MOHAMED) AND ID(20230042): PROBLEM TWO AND PROBLEM FIVE

# Author_3 (YOUSSIF MOHAMED YOUSSIF MOHAMED) AND ID(20230513): PROBLEM THREE AND PROBLEM FOUR

# VERSION: PROGRAM VERSION 1.0

# Date:  25/2/2024


def calculate_grade(mark):
    if 0 <= mark <= 100:
        if mark >= 90:
            return 'A+'
        elif 85 <= mark < 90:
            return 'A'
        elif 80 <= mark < 85:
            return 'B+'
        elif 75 <= mark < 80:
            return 'B'
        elif 70 <= mark < 75:
            return 'C+'
        elif 65 <= mark < 70:
            return 'C'
        elif 60 <= mark < 65:
            return 'D+'
        elif 50 <= mark < 60:
            return 'D'
        elif mark < 50:
            return 'F'
    else:
        return 'Invalid mark. Please enter a mark between 0 and 100.'
def grade_calculator_menu():
    while True:
        try:
            mark = float(input("Enter the mark: "))
            grade = calculate_grade(mark)
            print(f"The grade is: {grade}")
            print("_"*50)
            print("\nGrade calculator menu:")
            print("1. Calculate grade  using another mark")
            print("2. Exit to main menu")
            choice = input("Enter your choice: ")
            print("_"*50)
            if choice == "1":
                continue
            elif choice == "2":
                print("Exiting to main menu ")
                main_menu()
            else:
                print("Please select a valid choice :")

        except ValueError:
            print("Invalid input. Please enter a valid numerical value.")
def is_armstrong_number():
    # first, define the input as a list
    number = list(input("ENTER THE NUMBER YOU WANT TO CHECK:"))

    # then, convert this list to an integer number
    num_int = int(''.join(number))

    # this is a loop that calculates: every number in the list to the power of the length of it
    the_sum = sum(int(i) ** len(number) for i in number)

    # This is a check if the number = the sum that we already calculated
    if the_sum == num_int:
        print("The number is an armstrong number")
    else:
        print("The number is not an armstrong number")
def armstrong_menu():
    is_armstrong_number()
    while True:
        print("_" * 50)
        print("\nArmstrong Number Checker Menu:")
        print("1. Check if another number is an Armstrong number")
        print("2. Exit to main menu ")
        print("_" * 50)

        choice = input("Enter your choice: ")

        if choice == "1":
            is_armstrong_number()
        elif choice == "2":
            print("Exiting Armstrong Number Checker to main menu ...")
            main_menu()
        else:
            print("Invalid choice please enter a valid choice ")
def piapprox(n):
    # the denominator increases by 2 and starts with 1.
    # the numerator is constant =1
    p = 0
    for i in range(0, n):
        p = p + 1 / (-1) ** i / (2 * i + 1)
    return p * 4
def Pi_calculator():
    # Taking input from the user for the number of terms (n)
    n = int(input("Enter the number of terms (n): "))

    # Calculating Pi using the provided algorithm
    piapproximation = piapprox(n)

    # the result
    print(f"Approximation of Pi using {n} terms: {piapproximation}")
def pi_menu():
    Pi_calculator()
    while True:
        print("_" * 50)
        print("\nPi Approximation Menu:")
        print("1. Calculate Pi using another specific number of terms")
        print("2. Exit to main menu")
        choice = input("Enter your choice: ")
        print("_"*50)

        if choice == "1":
            Pi_calculator()
        elif choice == "2":
            print("Exiting pi calculator to main menu..... ")
            main_menu()

        else:
            print("Invalid choice please enter a valid choice")
def encrypt_text(text, shift):   #Define the encrypt_text function, which accepts a shift value and a text as input
    small_alpha = "abcdefghijklmnopqrstuvwxyz" # Define the  characters to be encrypted
    capital_alpha = small_alpha.upper()   # Define uppercase letters
    numbers = "0123456789" # we use this to define the numbers
    before = small_alpha + capital_alpha + numbers    #  Create the 'after' string by shifting each character in 'before' by the specified shift value
    after =(
        small_alpha[shift:] + small_alpha[:shift] + \
        capital_alpha[shift:] + capital_alpha[:shift] + \
        numbers[shift:] + numbers[:shift]
    )
    translation = str.maketrans(before, after)   # Create a translation table using str.maketrans to map characters from 'before' to 'after'
    cipherText = text.translate(translation)     # Use translate method to encrypt the text using the translation table
    return cipherText
def pro_4():
    text = input("\nEnter the text you want to encrypt: ")
    shift = int(input("Enter the shift number: "))

    encrypted_text = encrypt_text(text, shift)

    print("\nCoded Message:  {}".format(encrypted_text))
def encrypt_menu():
    pro_4()
    while True:
        print("_"*50)
        print("\nText Encryption Menu:")
        print("1. Encrypt another text")
        print("2. Exit to main menu")
        print("_"*50)

        choice = input("Enter your choice: ")

        if choice == "1":
            pro_4()
        elif choice == "2":
            print("Exiting to main menu")
            main_menu()
        else:
            print("Invalid choice please enter a valid choice.")
def lists_equality_checker():
    # Get  inputs for list1
    list1_input = input("Enter elements of list 1 separatly by using space: ")
    list1 = [int(x) for x in list1_input.split()]  # to modify the shape of list and take each charectar separatly

    # Get inputs for list2
    list2_input = input("Enter elements of list 2 separatly by using space: ")
    list2 = [int(x) for x in list2_input.split()]  # to modify the shape of list and take each charectar separatly

    # the first probabilty for non equal lists
    # first we have to check if both lists have the same length or not
    if len(list1) != len(list2):
        print("the two lists are not equal{ Both lists do not  have the same length}\nOR")
    counts_of_list_1 = {}  # a variable to store counts of first list to compare it later
    # Counts of elements in first list and store them also
    # and use increment method to save all element of lists by keys
    for element in list1:
        if element in counts_of_list_1:
            counts_of_list_1[element] += 1  # as if this element was saved before move to other index by value 1
        else:
            counts_of_list_1[element] = 1
    # we start to compare elements from lists one by elements from list two using (counts_of_list_1)
    # and use decrement method to get all element of list and compare them
    for element in list2:
        if element in counts_of_list_1:
            counts_of_list_1[element] -= 1  # as this element was compared before move to other one
        else:
            # the second posiblites of both lists are not equal
            # If an element in list1 is not in list2, lists are not equal
            print("the two lists are not equal(there are different elements)")
            return False
    # as counts of list1 subtracted by that of list2 so there most by zeros counts otherwise they willnot be equal
    # If any count is not zero, lists are not equal
    for count in counts_of_list_1.values():
        if count != 0:
            print("the two lists are not equal(there are different elements)")
            return False

    # If all counts are zero, lists are equal
    print("BOTH LISTS ARE EQUAL")
    return True
def list_checker_menu():
    while True:
        lists_equality_checker()
        print("_"*50)
        print("\nList Equality Checker Menu:")
        print("1. Check if another two lists are equal")
        print("2. Exit the main menu")
        print("_"*50)

        choice = input("Enter your choice : ")

        if choice == "1":
            lists_equality_checker()
        elif choice == "2":
            print("Exiting List Equality Checker...")
            main_menu()
        else:
            print("Invalid choice please enter a valid choice.")


# this program finds all the factors of any positive integer
def find_factors():
    # Starting with a loop to check that the user will not input a negative number
    while True:
        try:
            number = int(input("Enter a positive integer: "))
            # This is an empty list to store the factors
            factors = []
            # check if the user will not input 0
            if number == 0:
                print("0 (zero) has no factors")
            elif number > 0:
                # this is a for loop in range all the numbers from 1 to the number that the user entered
                for factor in range(1, number + 1):
                    # check if the number is a factor or not
                    if number % factor == 0:
                        # here ( append ) add all the factors to the empty list (factors)
                        factors.append(factor)
                print(f"The factors of {number} are: {factors}")
                break
            else:
                print("Please enter a valid positive integer")
        except ValueError:
            print("Invalid input. Please enter a valid integer.")
def factors_menu():
    find_factors()
    while True:
        print("_"*50)
        print("\nFactors Finder Menu:")
        print("1. Find another factors of a number")
        print("2. Exit to the main menu")
        print("_"*50)
        choice = input("Enter your choice please : ")
        if choice == "1":
            find_factors()
        elif choice == "2":
            print("Exiting Factors Finder...")
            main_menu()
        else:
            print("Invalid choice. Please enter 1 or 2.")
def main_menu():
 if __name__ == "__main__":
    while True:
        print("\n# Main Menu  #")
        print("_"*25)
        print("1) GRADE CALCULATOR ")
        print("2) ARMSTRONG NUMBER CHECKER ")
        print("3) PI CALCULATOR ")
        print("4) ENCRYPTION OF TEXT")
        print("5) LISTS EQUALITY CHECKER")
        print("6) FIND FACTORS OF POSITIVE NUMBER")
        choice = input("\nplease select your problem solver: ").lower()
        if choice == "1":
            grade_calculator_menu()
        elif choice == "2":
            armstrong_menu()
        elif choice == "3":
            pi_menu()
        elif choice == "4":
            encrypt_menu()
        elif choice == "5":
           list_checker_menu()
        elif choice == "6":
            factors_menu()
        else:
            print("please enter a valid choice from above")
main_menu()

















































