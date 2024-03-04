#Introduction

#This Python script serves as a versatile Numbering System Converter,allowing users to seamlessly convert numeric values between different
#bases, including Decimal, Binary, Octal, and Hexadecimal.The program employs a series of functions dedicated to each conversion,
# with careful attention to detail in handling various numeral systems. The user interface is structured through a menu system, guiding users
#through the selection of the input and output bases. Whether you're working with everyday decimal numbers or diving into the intricacies of
#binary and hexadecimal systems, this converter provides a user-friendly platform for effortless numeric transitions. The code is well-commented
#to enhance readability and understanding, making it accessible for those seeking to explore or implement similar conversion functionalities in their projects.




# this function used to convert binary to octal
def binary_to_octal(binary_num):
    octal_numbers = {0: 0, 1: 1, 10: 2, 11: 3, 100: 4, 101: 5, 110: 6, 111: 7}
    output = []
    while binary_num != 0:
        rem = binary_num % 1000
        output.append(octal_numbers[rem])
        binary_num = binary_num // 1000
    output.reverse()
    return output

# Function to convert binary to hexadecimal
def binary_to_hexadecimal(binary_input):
    binary_num = int(binary_input, 2)
    hexadecimal_numbers = {0: '0', 1: '1', 2: '2', 3: '3', 4: '4', 5: '5', 6: '6', 7: '7', 8: '8', 9: '9', 10: 'A',
                           11: 'B', 12: 'C', 13: 'D', 14: 'E', 15: 'F'}
    output = []
    while binary_num != 0:
        rem = binary_num % 16
        output.append(hexadecimal_numbers[rem])
        binary_num = binary_num // 16
    output.reverse()
    return ''.join(output)

# Function to convert decimal to binary
def decimal_to_binary(decimal_num):
    binary_digits = []
    while decimal_num > 0:
        remainder = decimal_num % 2
        binary_digits.append(remainder)
        decimal_num = decimal_num // 2

    if not binary_digits:
        return [0]

    binary_digits.reverse()
    return binary_digits

# Function to convert decimal to octal
def decimal_to_octal(decimal_num):
    octal_digits = []
    while decimal_num > 0:
        remainder = decimal_num % 8
        octal_digits.append(remainder)
        decimal_num = decimal_num // 8
    if not octal_digits:
        return [0]

    octal_digits.reverse()
    return octal_digits

# Function to convert decimal to hexadecimal
def decimal_to_hexadecimal(decimal_num):
    hex_digits = []
    hex_map = {10: 'A', 11: 'B', 12: 'C', 13: 'D', 14: 'E', 15: 'F'}

    while decimal_num > 0:
        remainder = decimal_num % 16

        if remainder >= 10:
            hex_digits.append(hex_map[remainder])
        else:
            hex_digits.append(remainder)

        decimal_num = decimal_num // 16

    if not hex_digits:
        return [0]

    hex_digits.reverse()
    return hex_digits

# Function to convert octal to binary
def octal_to_binary(octal_num):
        binary_digits = []
        for digit in str(octal_num):

            binary_digits.append(format(int(digit), '03b'))

        return ''.join(binary_digits)

# Function to convert octal to hexadecimal

def octal_to_hexadecimal(octal_num):
    binary_num = format(int(octal_num, 8), 'b')
    hex_num = decimal_to_hexadecimal(int(binary_num, 2))
    return hex_num

# Function to convert hexadecimal to decimal

def hexadecimal_to_decimal(hexadecimal_num):
    return int(str(hexadecimal_num), 16)

# Function to convert hexadecimal to binary

def hexadecimal_to_binary(hexadecimal_num):
    decimal_num = int(str(hexadecimal_num), 16)
    return decimal_to_binary(decimal_num)

# Function to convert binary to binary (identity function)

def binary_to_binary(binary_input):
    return binary_input


# Function to convert octal to decimal

def octal_to_decimal(octal_num):
    return int(str(octal_num), 8)

# Function to convert hexadecimal to octal

def hexadecimal_to_octal(hexadecimal_num):
    hex_map = {'0': '0000', '1': '0001', '2': '0010', '3': '0011',
               '4': '0100', '5': '0101', '6': '0110', '7': '0111',
               '8': '1000', '9': '1001', 'A': '1010', 'B': '1011',
               'C': '1100', 'D': '1101', 'E': '1110', 'F': '1111'}

    binary_num = ''
    for digit in hexadecimal_num:
        binary_num += hex_map[digit]

    padding = 3 - len(binary_num) % 3
    binary_num = '0' * padding + binary_num

    octal_num = ''
    for i in range(0, len(binary_num), 3):
        octal_digit = binary_num[i:i + 3]
        octal_num += str(int(octal_digit, 2))

    return octal_num

# Function to convert binary to decimal

def binary_to_decimal(binary_input):
    return int(binary_input, 2)

# Function to convert decimal to decimal (identity function)

def decimal_to_decimal(decimal_num):
    return decimal_num

# Function to convert octal to octal (identity function)

def octal_to_octal(octal_num):
    octal_digits = '01234567'
    for digit in octal_num:
        if digit not in octal_digits:
            raise ValueError("Invalid octal number")


    return octal_num

# Function to convert hexadecimal to hexadecimal (identity function)

def hexadecimal_to_hexadecimal(hexadecimal_num):
    return str(hexadecimal_num).upper()

# Function to display the main menu

def display_menu1():
    print("** Numbering System Converter **")
    print("A) Insert a new number")
    print("B) Exit program")

# Function to display the base selection menu for input

def display_menu2():
    print("** Please select the base you want to convert a number from **")
    print("A) Decimal")
    print("B) Binary")
    print("C) Octal")
    print("D) Hexadecimal")

# Function to display the base selection menu for output

def display_menu3():
    print("** Please select the base you want to convert a number to **")
    print("A) Decimal")
    print("B) Binary")
    print("C) Octal")
    print("D) Hexadecimal")

# Main function to control the program flow

def main():
    while True:
        display_menu1()
        choice1 = input("Enter your choice (A/B): ").upper()

        if choice1 == 'B':
            print("Exiting the program. Goodbye!")
            break
        elif choice1 == 'A':
            number = input("Please insert a number: ")

            while True:
                display_menu2()
                from_base = input("Enter your choice (A/B/C/D): ").upper()

                if from_base not in {'A', 'B', 'C', 'D'}:
                    print("Please select a valid choice.")
                    continue

                while True:
                    display_menu3()
                    to_base = input("Enter your choice (A/B/C/D): ").upper()

                    if to_base not in {'A', 'B', 'C', 'D'}:
                        print("Please select a valid choice.")
                        continue

                    # Conversion logic

                    if from_base == 'A':
                        number_in_decimal = int(number, 10)
                    elif from_base == 'B':
                        number_in_decimal = int(number, 2)
                    elif from_base == 'C':
                        number_in_decimal = int(number, 8)
                    else:
                        number_in_decimal = int(number, 16)

                    if to_base == 'A':
                        result = decimal_to_decimal(number_in_decimal)
                    elif to_base == 'B':
                        result = decimal_to_binary(number_in_decimal)
                    elif to_base == 'C':
                        result = decimal_to_octal(number_in_decimal)
                    else:
                        result = decimal_to_hexadecimal(number_in_decimal)

                    print(f"Result: {result}")
                    break

                break


if __name__ == "__main__":
    main()



