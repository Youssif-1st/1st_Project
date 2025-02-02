#include <iostream>
#include <limits>
#include "Game(6).h"  
#include "Game(3).h"  

using namespace std;

// Function to clear the input buffer
void clear_input_buffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void play_game6() {
    // Create the game board
    Misere_TicTacToe_Board<char> board;

    // Create two players: one human, one random
    Misere_TicTacToe_Player<char> player1("Player 1", 'X');
    Misere_TicTacToe_Random_Player<char> player2('O');

    int x, y;
    bool gameOver = false;

    // Start the game loop
    while (!gameOver) {
        // Display the board
        board.display_board();

        // Player 1's turn
        cout << "\nPlayer 1's turn (X): ";
        player1.getmove(x, y);
        if (!board.update_board(x, y, 'X')) {
            cout << "Invalid move, try again." << endl;
            continue;
        }

        // Check if game is over
        if (board.game_is_over()) {
            board.display_board();
            if (board.is_win()) {
                cout << "Player 2 (O) wins (as Misere rules)!" << endl;
            }
            else {
                cout << "The game is a draw!" << endl;
            }
            break;
        }

        // Player 2's turn (Random Player)
        cout << "\nPlayer 2's turn (O): ";
        player2.getmove(x, y);
        if (!board.update_board(x, y, 'O')) {
            cout << "Invalid move, try again." << endl;
            continue;
        }

        // Check if game is over
        if (board.game_is_over()) {
            board.display_board();
            if (board.is_win()) {
                cout << "Player 1 (X) wins (as Misere rules)!" << endl;
            }
            else {
                cout << "The game is a draw!" << endl;
            }
            break;
        }
    }
}

void play_game3() {
    // Create the game board
    X_O_5x5_Board<char> board;

    // Create two players: one human, one random
    X_O_5x5_Player<char> player1("Player 1", 'X');
    X_O_5x5_Random_Player<char> player2('O');

    int x, y;
    bool gameOver = false;

    // Start the game loop
    while (!gameOver) {
        // Display the board
        board.display_board();

        // Player 1's turn
        cout << "\nPlayer 1's turn (X): ";
        player1.getmove(x, y);
        if (!board.update_board(x, y, 'X')) {
            cout << "Invalid move, try again." << endl;
            continue;
        }

        // Check if game is over
        if (board.game_is_over()) {
            board.display_board();
            if (board.is_win()) {
                cout << "Player 2 (O) wins!" << endl;
            }
            else {
                cout << "The game is a draw!" << endl;
            }
            break;
        }

        // Player 2's turn (Random Player)
        cout << "\nPlayer 2's turn (O): ";
        player2.getmove(x, y);
        if (!board.update_board(x, y, 'O')) {
            cout << "Invalid move, try again." << endl;
            continue;
        }

        // Check if game is over
        if (board.game_is_over()) {
            board.display_board();
            if (board.is_win()) {
                cout << "Player 1 (X) wins!" << endl;
            }
            else {
                cout << "The game is a draw!" << endl;
            }
            break;
        }
    }
}

int main() {
    int choice;

    do {
        // Display the menu
        cout << "\nWelcome to the Game Menu!" << endl;
        cout << "1. Play Game 6 (Misere Tic Tac Toe)" << endl;
        cout << "2. Play Game 3 (5x5 X-O)" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1-3): ";

        // Input validation for menu choice
        while (true) {
            cin >> choice;
            if (cin.fail() || choice < 1 || choice > 3) {
                clear_input_buffer();
                cout << "Invalid choice! Please enter a number between 1 and 3: ";
            }
            else {
                break;
            }
        }

        switch (choice) {
        case 1:
            play_game6();
            break;
        case 2:
            play_game3();
            break;
        case 3:
            cout << "Thank you for playing! Exiting..." << endl;
            break;
        default:
            cout << "Invalid option!" << endl;
            break;
        }
    } while (choice != 3);

    return 0;
}
