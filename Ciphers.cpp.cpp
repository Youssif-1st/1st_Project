//This C++ program serves as a menu-driven interface for implementing two classical ciphers: the Vigenere Cipher and the Route Cipher. 
//For the Vigenere Cipher, users can encrypt or decrypt messages using a keyword,
//with input text and keywords processed to ensure only alphabetical characters are considered. 
//The keyword length is capped at 8 characters, and both encryption and decryption are case-insensitive, yielding output in uppercase. 
//As for the Route Cipher, users can encrypt or decrypt messages using a specified key. Input messages are padded with 'X' to form a rectangular matrix, 
//and the encryption process reads the grid clockwise, starting from the top right corner, while decryption follows a spiral path from the same corner. 
//The program ensures input validation and error handling for both ciphers, 
//providing an intuitive experience for users to interact with classical encryption techniques.



#include <iostream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

// we use this  function to print a 2D matrix
void printMatrix(const vector<vector<char>>& matrix) {
    for (const auto& row : matrix) {
        for (char ch : row) {
            cout << ch << ' ';
        }
        cout << endl;
    }
}

// we use this function to encrypt using Route Cipher
string encryptRouteCipher(const string& plaintext, int key) {
    string result;

    // we use this to remove non-letter characters and convert to uppercase
    string processedText;
    for (char ch : plaintext) {
        if (isalpha(ch)) {
            processedText += toupper(ch);
        }
    }

    // we use this to calculate number of rows needed
    int rows = (processedText.length() + key - 1) / key;

    // we use this to pad with 'X' to make a rectangular matrix
    while (processedText.length() % key != 0) {
        processedText += 'X';
    }

    // we use this to create matrix and fill it with 'X'
    vector<vector<char>> matrix(rows, vector<char>(key, 'X'));

    // we use this to fill matrix row by row
    int index = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < key; ++j) {
            if (index < processedText.length()) {
                matrix[i][j] = processedText[index++];
            }
        }
    }

    // we use this to read the grid clockwise, going inwards, starting from the top right corner
    for (int j = key - 1; j >= 0; --j) {
        for (int i = 0; i < rows; ++i) {
            result += matrix[i][j];
        }
    }

    return result;
}

string decryptRouteCipher(const string& ciphertext, int key) {
    string result;

    // we use this to calculate number of rows needed
    int rows = (ciphertext.length() + key - 1) / key;

    // we use this to create matrix and fill it with 'X'
    vector<vector<char>> matrix(rows, vector<char>(key, 'X'));

    // we use this to fill matrix by going in a spiral path starting from the top right corner
    int index = 0;
    for (int j = key - 1; j >= 0; --j) {
        for (int i = 0; i < rows; ++i) {
            if (index < ciphertext.length()) {
                matrix[i][j] = ciphertext[index++];
            }
        }
    }

    // we use this to read the grid clockwise, going inwards, starting from the top right corner
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < key; ++j) {
            result += matrix[i][j];
        }
    }

    return result;
}
// we use this to function to encrypt using Vigenere Cipher
string encryptVigenere(const string& message, const string& keyword) {
    string encryptedText = "";
    size_t keyword_length = keyword.length();

    size_t i = 0;
    while (i < message.length()) {
        char char_to_encrypt = message[i];
        if (isalpha(char_to_encrypt)) {
            char base = islower(char_to_encrypt) ? 'a' : 'A';
            int shift = keyword[i % keyword_length] - 'A';
            char encrypted_char = (char_to_encrypt - base + shift) % 26 + base;
            encryptedText += toupper(encrypted_char);  // we use this to convert to uppercase
        }
        else {
            encryptedText += char_to_encrypt;
        }
        ++i;
    }

    return encryptedText;
}
// we use this to function to decrypt using Vigenere Cipher
string decryptVigenere(const string& message, const string& keyword) {
    string decryptedText = "";
    size_t keyword_length = keyword.length();

    size_t i = 0;
    do {
        char char_to_decrypt = message[i];
        if (isalpha(char_to_decrypt)) {
            char base = islower(char_to_decrypt) ? 'a' : 'A';
            int shift = keyword[i % keyword_length] - 'A';
            char decrypted_char = (char_to_decrypt - base - shift + 26) % 26 + base;
            decryptedText += toupper(decrypted_char);  // we use this to convert to uppercase
        }
        else {
            decryptedText += char_to_decrypt;
        }
        ++i;
    } while (i < message.length());

    return decryptedText;
}

int main() {
    cout << "Welcome to Cipher Menu!\n";

    int mainmenu;
    int option;  // we use this to declare option outside the do-while loop
    do {
        cout << "Choose Cipher:\n";
        cout << "1) Vigenere Cipher\n2) Route Cipher\n3) Exit\n";
        cout << "Choose your option (1, 2, 3)------->";
        cin >> mainmenu;

        if (mainmenu == 1) {
            do {
                cout << "Vigenere Cipher Menu:\n";
                cout << "1) Encryption\n2) Decryption\n3) Return to Main Menu\n";
                cout << "Choose your option (1, 2, 3)------->";
                cin >> option;

                if (option == 1 || option == 2) {
                    string text, key;

                    if (option == 1) {
                        cout << "ENCRYPTION ACTIVATED" << endl;
                        cout << "Enter the text------->";
                        cin.ignore(); // we use this to clear newline from the buffer
                        getline(cin, text);

                        cout << "Enter the keyword------->";
                        getline(cin, key);

                        if (key.length() > 8) {
                            cout << "Error!! Keyword length exceeds the maximum limit of 8 characters.\n";
                            exit(1);
                        }

                        for (size_t i = 0; i < key.length(); i++) {
                            if (!isalpha(key[i])) {
                                cout << "Error!! Only alphabetic characters are allowed in the keyword.\n";
                                exit(1);
                            }
                            key[i] = toupper(key[i]);
                        }

                        string encryptedText = encryptVigenere(text, key);
                        cout << "Encrypted Text: " << encryptedText << endl;
                    }
                    else if (option == 2) {
                        cout << "DECRYPTION ACTIVATED" << endl;
                        cout << "Enter the text------->";
                        cin.ignore(); // we use this to clear newline from the buffer
                        getline(cin, text);

                        cout << "Enter the keyword: ";
                        getline(cin, key);

                        if (key.length() > 8) {
                            cout << "Error!! Keyword length exceeds the maximum limit of 8 characters.\n";
                            exit(1);
                        }

                        for (size_t i = 0; i < key.length(); i++) {
                            if (!isalpha(key[i])) {
                                cout << "Error!! Only alphabetic characters are allowed in the keyword.\n";
                                exit(1);
                            }
                            key[i] = toupper(key[i]);
                        }

                        string decryptedText = decryptVigenere(text, key);
                        cout << "Decrypted Text: " << decryptedText << endl;
                    }
                }
                else if (option != 3) {
                    cout << "Error: Invalid option. Please choose 1, 2, 3." << endl;
                }
            } while (option != 3);
        }
        else if (mainmenu == 2) {
            do {
                cout << "Route Cipher Menu:\n";
                cout << "1) Encryption\n2) Decryption\n3) Return to Main Menu\n";
                cout << "Choose your option (1, 2, 3)------->";
                cin >> option;

                if (option == 1 || option == 2) {
                    string text;
                    int key;

                    if (option == 1) {
                        cout << "ENCRYPTION ACTIVATED" << endl;
                        cout << "Enter the text------->";
                        cin.ignore(); // we use this to clear newline from the buffer
                        getline(cin, text);

                        cout << "Enter the key------->";
                        cin >> key;

                        string encryptedText = encryptRouteCipher(text, key);
                        cout << "Encrypted Text------->" << encryptedText << endl;
                    }
                    else if (option == 2) {
                        cout << "DECRYPTION ACTIVATED" << endl;
                        cout << "Enter the text-------> ";
                        cin.ignore(); // we use this to clear newline from the buffer
                        getline(cin, text);

                        cout << "Enter the key-------> ";
                        cin >> key;

                        string decryptedText = decryptRouteCipher(text, key);
                        cout << "Decrypted Text-------> " << decryptedText << endl;
                    }
                }
                else if (option != 3) {
                    cout << "Error!! Invalid option. Please choose 1, 2, 3." << endl;
                }
            } while (option != 3);
        }
        else if (mainmenu != 3) {
            cout << "Error!! Invalid option. Please choose 1, 2, 3." << endl;
        }
    } while (mainmenu != 3);

    cout << "Exiting the program\n";

    return 0;
}
