#pragma once
#ifndef _MISERE_TICTACTOE_H
#define _MISERE_TICTACTOE_H

#include "BoardGame_Classes.h"

template <typename T>
class Misere_TicTacToe_Board : public Board<T> {
public:
    Misere_TicTacToe_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
};

template <typename T>
class Misere_TicTacToe_Player : public Player<T> {
public:
    Misere_TicTacToe_Player(string name, T symbol);
    void getmove(int& x, int& y);
};

template <typename T>
class Misere_TicTacToe_Random_Player : public RandomPlayer<T> {
public:
    Misere_TicTacToe_Random_Player(T symbol);
    void getmove(int& x, int& y);
};

//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

using namespace std;

// Constructor for Misere_TicTacToe_Board
template <typename T>
Misere_TicTacToe_Board<T>::Misere_TicTacToe_Board() {
    this->rows = this->columns = 3;
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
bool Misere_TicTacToe_Board<T>::update_board(int x, int y, T mark) {
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && this->board[x][y] == 0) {
        this->n_moves++;
        this->board[x][y] = toupper(mark);
        return true;
    }
    return false;
}

// Display the board and the pieces on it
template <typename T>
void Misere_TicTacToe_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

// Returns true if there is any loser (three in a row)
template <typename T>
bool Misere_TicTacToe_Board<T>::is_win() {
    // Check rows and columns
    for (int i = 0; i < this->rows; i++) {
        if ((this->board[i][0] != 0 && this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2]) ||
            (this->board[0][i] != 0 && this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i])) {
            return true;
        }
    }
    // Check diagonals
    if ((this->board[0][0] != 0 && this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2]) ||
        (this->board[0][2] != 0 && this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0])) {
        return true;
    }
    return false;
}

// Return true if all moves are done and no loser
template <typename T>
bool Misere_TicTacToe_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool Misere_TicTacToe_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//--------------------------------------

// Constructor for Misere_TicTacToe_Player
template <typename T>
Misere_TicTacToe_Player<T>::Misere_TicTacToe_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void Misere_TicTacToe_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;
}

// Constructor for Misere_TicTacToe_Random_Player
template <typename T>
Misere_TicTacToe_Random_Player<T>::Misere_TicTacToe_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void Misere_TicTacToe_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;  // Random number between 0 and 2
    y = rand() % this->dimension;  // Random number between 0 and 2
}

#endif //_MISERE_TICTACTOE_H
