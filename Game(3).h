#pragma once
#ifndef _5X5X_O_H
#define _5X5X_O_H

#include "BoardGame_Classes.h"

template <typename T>
class X_O_5x5_Board : public Board<T> {
public:
    X_O_5x5_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
    int count_three_in_a_row(T symbol);
};

template <typename T>
class X_O_5x5_Player : public Player<T> {
public:
    X_O_5x5_Player(string name, T symbol);
    void getmove(int& x, int& y);
};

template <typename T>
class X_O_5x5_Random_Player : public RandomPlayer<T> {
public:
    X_O_5x5_Random_Player(T symbol);
    void getmove(int& x, int& y);
};

//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

using namespace std;

// Constructor for X_O_5x5_Board
template <typename T>
X_O_5x5_Board<T>::X_O_5x5_Board() {
    this->rows = this->columns = 5;
    this->board = new T * [this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool X_O_5x5_Board<T>::update_board(int x, int y, T mark) {
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0 || mark == 0)) {
        if (mark == 0) {
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }
        return true;
    }
    return false;
}

// Display the board and the pieces on it
template <typename T>
void X_O_5x5_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
template <typename T>
bool X_O_5x5_Board<T>::is_win() {
    // Check rows, columns, and diagonals for three-in-a-row
    return count_three_in_a_row('X') > count_three_in_a_row('O');
}

// Return true if 24 moves are done and no winner
template <typename T>
bool X_O_5x5_Board<T>::is_draw() {
    return (this->n_moves == 24 && !is_win());
}

template <typename T>
bool X_O_5x5_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

// Count the number of three-in-a-rows for a given symbol
template <typename T>
int X_O_5x5_Board<T>::count_three_in_a_row(T symbol) {
    int count = 0;

    // Check rows
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns - 2; j++) {
            if (this->board[i][j] == symbol && this->board[i][j + 1] == symbol && this->board[i][j + 2] == symbol) {
                count++;
            }
        }
    }

    // Check columns
    for (int i = 0; i < this->columns; i++) {
        for (int j = 0; j < this->rows - 2; j++) {
            if (this->board[j][i] == symbol && this->board[j + 1][i] == symbol && this->board[j + 2][i] == symbol) {
                count++;
            }
        }
    }

    // Check diagonals
    for (int i = 0; i < this->rows - 2; i++) {
        for (int j = 0; j < this->columns - 2; j++) {
            if (this->board[i][j] == symbol && this->board[i + 1][j + 1] == symbol && this->board[i + 2][j + 2] == symbol) {
                count++;
            }
            if (this->board[i][j + 2] == symbol && this->board[i + 1][j + 1] == symbol && this->board[i + 2][j] == symbol) {
                count++;
            }
        }
    }

    return count;
}

//--------------------------------------

// Constructor for X_O_5x5_Player
template <typename T>
X_O_5x5_Player<T>::X_O_5x5_Player(std::string name, T symbol) : Player<T>(name, symbol) {}
template <typename T>
X_O_5x5_Player<T>::X_O_5x5_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void X_O_5x5_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: ";
    cin >> x >> y;
}

// Constructor for X_O_5x5_Random_Player
template <typename T>
X_O_5x5_Random_Player<T>::X_O_5x5_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 5;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void X_O_5x5_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;  // Random number between 0 and 4
    y = rand() % this->dimension;
}

#endif //_5X5X_O_H