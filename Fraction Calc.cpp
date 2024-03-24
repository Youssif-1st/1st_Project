//File name : CS112_A2_T3_S1_20230701_20230513_.cpp

//Purpose : In this application create a rational number calculator that is capable of taking two rational numbers and an operation to perform on them.Program should handle cases of - ve numbers and nominator without denominator.It should also use defensive programming to reject bad inputs.

//Author ID1 : Marya Bilal Hassan habash(section 1)

//Author ID2 : Youssif mohamed youssif mohamed(section 1)

//Email ID1 : maryabilal22006@gmail.com

//Email ID2 : offabasha@gmail.com

//ID1: 20230701 - Did the addition and subtraction operation

//ID2 : 20230513 - Did the multiplication and division operation










#include <iostream>
#include <string>
#include <regex>
#include <cmath>
using namespace std;

// function to simplify a rational number
void simplify(long long int& numerator, long long int& denominator) {
    long long int num = numerator;
    long long int den = denominator;

    // If numerator is 0, set denominator to 1 and return
    if (num == 0) {
        den = 1;
        return;
    }

    // Ensure the sign of the fraction is consistent
    if (den < 0) {
        num *= -1;
        den *= -1;
    }
    if (num < 0) {
        num *= -1;
        den *= -1;
    }
    if (num < 0 && den < 0) {
        num *= -1;
    }

    // Simplify the fraction
    for (long long int i = min(abs(num), abs(den)); i > 1; i--) {
        if (num % i == 0 && den % i == 0) {
            num /= i;
            den /= i;
        }
    }

    // Update the numerator and denominator
    numerator = num;
    denominator = den;
}

// Function to check if a string represents a valid operand
bool isValidOperand(const string& operand) {
    for (char c : operand) {
        // Check if each character is a digit or '/'
        if (!isdigit(c) && c != '/') {
            return false;
        }
    }
    return true;
}

// Function to perform arithmetic operations on rational numbers
void mainOperations(long long int num1, long long int denom1, long long int num2, long long int denom2, char op) {
    long long int resNumerator = 0, resDenominator = 1;

    // Handling special cases for zero numerator or zero denominator
    if (num1 == 0) {
        if (op == '-') {
            resNumerator = -num2;
            resDenominator = denom2;
        }
        else if (op == '+') {
            resNumerator = num2;
            resDenominator = denom2;
        }
        else {
            cout << "= 0" << endl;
            return;
        }
    }
    else if (denom1 == 0 || denom2 == 0) {
        cout << "MATH ERROR!! (denominator can't be zero)" << endl;
        return;
    }
    if (denom1 < 0) {
        num1 *= -1;
        denom1 *= -1;
    }
    if (denom2 < 0) {
        num2 *= -1;
        denom2 *= -1;
    }

    // If both numerators are negative, make the whole numbers positive
    if (num1 < 0 && num2 < 0) {
        num1 *= -1;
        num2 *= -1;
    }


    // Check for invalid operators
    if (op != '+' && op != '-' && op != '*' && op != '/') {
        cerr << "Invalid operation. Please enter a valid operator." << endl;
        return;
    }

    // Perform the arithmetic operation based on the operator
    switch (op) {
    case '+':
        resNumerator = num1 * denom2 + num2 * denom1;
        resDenominator = denom1 * denom2;
        break;
    case '-':
        resNumerator = num1 * denom2 - num2 * denom1;
        resDenominator = denom1 * denom2;
        break;
    case '*':
        if (num2 == 0) {
            cout << "= 0" << endl;
            return;
        }
        resNumerator = num1 * num2;
        resDenominator = denom1 * denom2;
        break;
    case '/':
        if (num2 == 0) {
            cerr << "ERROR!! (logical error you can't divide by zero)" << endl;
            return;
        }
        resNumerator = num1 * denom2;
        resDenominator = denom1 * num2;
        break;
    default:
        cerr << "Invalid operation. Please enter a valid operator." << endl;
        return;
    }

    // Simplify the result
    simplify(resDenominator, resNumerator);

    // Output the result
    if (resDenominator == 1) {
        cout << "= " << resNumerator << endl;
    }
    else {
        cout << "= " << resNumerator << "/" << resDenominator << endl;
    }
}

int main() {
    string input;

    // Display welcome message and menu
    cout << "Welcome To The Rational Number Calculator" << endl;
    cout << "____________________" << endl;
    cout << "MENU:" << endl;
    cout << "____________________" << endl;
    cout << "1-Calculate" << endl;
    cout << "2-EXIT" << endl;
    cout << "Please Enter Your Choice" << endl;
    cout << "____________________" << endl;

    // Read user's choice
    getline(cin, input);

    if (input == "1") {
        cout << "Please Enter Your Operation (or 'exit'):" << endl;

        while (true) {
            // Read user input
            getline(cin, input);

            // Check if the user wants to exit
            if (input == "exit") {
                cout << "Thank you for using the calculator." << endl;
                break;
            }

            // Define a regex pattern to match the input format
            regex pattern(R"(([-+]?\d+)(?:\/([-+]?\d+))?\s*([+\-*/])\s*([-+]?\d+)(?:\/([-+]?\d+))?)");

            smatch matches;

            // Check if the input matches the regex pattern and has the correct number of groups
            if (regex_match(input, matches, pattern) && matches.size() == 6) {
                // Extract numerator and denominator of the first number
                long long int num1, num2;
                int den1, den2;

                try {
                    num1 = stoll(matches[1]);
                    den1 = matches[2].length() > 0 ? stoi(matches[2]) : 1;
                    num2 = stoll(matches[4]);
                    den2 = matches[5].length() > 0 ? stoi(matches[5]) : 1;
                }
                catch (const invalid_argument& e) {
                    cerr << "Invalid operand. Please enter a valid operand." << endl;
                    continue;
                }

                // Extract the operator
                char op = matches[3].str()[0];

                // Perform the operation
                mainOperations(num1, den1, num2, den2, op);
            }
            else {
                // Define a regex pattern for invalid operands
                regex operandPattern(R"([^+\-*/%\d\s\!\@\$\#\%\^\<\>\?\:\'\"\'//'\'**'\'++'\'--'\'+g%'])");
                regex operationPattern(R"([\!\@\$\#\%\^\<\>\?\:\'\"\'//'\'**'\'++'\'--'])");

                // Check if the input contains invalid operands
                if (regex_search(input, operandPattern)) {
                    cerr << "Invalid operand. Please enter a valid operand." << endl;

                }

                else if (regex_search(input, operationPattern)) {
                    cerr << "Invalid operation. Please enter a valid operation." << endl;
                }

            }
        }
    }
    else if (input == "2") {
        cout << "Exiting the program. Goodbye!" << endl;
    }
    else {
        cerr << "Invalid choice. Please select a valid option." << endl;
    }

    return 0;
}









//-------------------------
//the pesudo-code
//-------------------------






// function to simplify a rational number
// Function simplify(numerator, denominator):
    // num = numerator
    // den = denominator

    // If numerator is 0, set denominator to 1 and return
    // If num is 0:
        // Set den to 1
        // Return

    // Ensure the sign of the fraction is consistent
    // If den < 0:
        // Multiply num by -1
        // Multiply den by -1
    // If num < 0:
        // Multiply num by -1
        // Multiply den by -1
    // If num < 0 and den < 0:
        // Multiply num by -1

    // Simplify the fraction
    // For i from min(|num|, |den|) down to 2:
        // If num % i is 0 and den % i is 0:
            // Divide num by i
            // Divide den by i

    // Update the numerator and denominator
    // Set numerator to num
    // Set denominator to den

// Function to check if a string represents a valid operand
// Function isValidOperand(operand):
    // For each character c in operand:
        // Check if each character is a digit or '/'
        // If c is not a digit or '/', return false
    // Return true

// Function to perform arithmetic operations on rational numbers
// Function mainOperations(num1, denom1, num2, denom2, op):
    // resNumerator = 0
    // resDenominator = 1

    // Handling special cases for zero numerator or zero denominator
    // If num1 is 0:
        // If op is '-':
            // Set resNumerator to -num2
            // Set resDenominator to denom2
        // Else if op is '+':
            // Set resNumerator to num2
            // Set resDenominator to denom2
        // Else:
            // Print "= 0"
            // Return
    // Else if denom1 is 0 or denom2 is 0:
        // Print "MATH ERROR!! (denominator can't be zero)"
        // Return

    // If denom1 is less than 0:
        // Multiply num1 by -1
        // Multiply denom1 by -1
    // If denom2 is less than 0:
        // Multiply num2 by -1
        // Multiply denom2 by -1

    // If both numerators are negative:
        // Multiply num1 by -1
        // Multiply num2 by -1

    // Check for invalid operators
    // If op is not one of '+', '-', '*', '/':
        // Print "Invalid operation. Please enter a valid operator."
        // Return

    // Perform the arithmetic operation based on the operator
    // Switch on op:
        // Case '+':
            // Set resNumerator to num1 * denom2 + num2 * denom1
            // Set resDenominator to denom1 * denom2
            // Break
        // Case '-':
            // Set resNumerator to num1 * denom2 - num2 * denom1
            // Set resDenominator to denom1 * denom2
            // Break
        // Case '*':
            // If num2 is 0:
                // Print "= 0"
                // Return
            // Set resNumerator to num1 * num2
            // Set resDenominator to denom1 * denom2
            // Break
        // Case '/':
            // If num2 is 0:
                // Print "ERROR!! (logical error you can't divide by zero)"
                // Return
            // Set resNumerator to num1 * denom2
            // Set resDenominator to denom1 * num2
            // Break
        // Default:
            // Print "Invalid operation. Please enter a valid operator."
            // Return

    // Simplify the result
    // Call simplify with resDenominator and resNumerator

    // Output the result
    // If resNumerator is 0:
        // Print "= 0"
    // Else if resDenominator is 1:
        // Print "= " followed by resNumerator
    // Else:
        // Print "= " followed by resNumerator, "/", and resDenominator

// Main function
// Function main():
    // input = ""

    // Display welcome message and menu
    // Print "Welcome To The Rational Number Calculator"
    // Print "____________________"
    // Print "MENU:"
    // Print "____________________"
    // Print "1-Calculate"
    // Print "2-EXIT"
    // Print "Please Enter Your Choice"
    // Print "____________________"

    // Read user's choice
    // Read input from user

    // If input is "1":
        // Print "Please Enter Your Operation (or 'exit'):"

        // Loop to handle multiple operations
        // Loop:
            // Read user input
            // Read input from user

            // Check if the user wants to exit
            // If input is "exit":
                // Print "Thank you for using the calculator."
                // Break from loop

            // Define a regex pattern to match the input format
            // Define regex pattern to match rational number operations

            // Match the input against the regex pattern
            // If input matches the pattern:
                // Extract num1, denom1, num2, denom2, and op from input
                // Perform mainOperations with num1, denom1, num2, denom2, and op
            // Else:
                // Check for invalid




