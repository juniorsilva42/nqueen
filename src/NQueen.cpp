#include <iostream>
#include "NQueen.hpp"

using namespace std;

NQueen::NQueen() {
  this->startBoard();
}

void NQueen::startBoard() {
  for (int i = 0; i < BOARD_LENGTH; i++) {
    for (int j = 0; j < BOARD_LENGTH; j++) {
      this->board[i][j] = 0;
    }
  }
}

bool NQueen::isSafePlace(int row, int col) {
  int i, j;
  
  for (i = 0; i < col; i++) {
    if (this->board[row][i]) {
      return false;
    }    
  }
  
  for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (this->board[i][j]) {
      return false;
    }    
  } 

  for (i = row, j = col; j >= 0 && i < BOARD_LENGTH; i++, j--) {
    if (this->board[i][j]) {
      return false;
    }    
  }

  return true; 
}

bool NQueen::solve(int board[BOARD_LENGTH][BOARD_LENGTH], int col) {
  if (col >= BOARD_LENGTH) {
    return true;
  }

  for (int i = 0; i < BOARD_LENGTH; i++) { 
    if (this->isSafePlace(i, col)) { 
      this->board[i][col] = 1; 

      if (this->solve(this->board, col + 1)) {
        return true;
      }

      this->board[i][col] = 0; 
    } 
  } 
  
  return false; 
}

void NQueen::printBoard() {
  for (int i = 0; i < BOARD_LENGTH; i++) {
    for (int j = 0; j < BOARD_LENGTH; j++) {
      if ((i % BOARD_LENGTH) && (j % BOARD_LENGTH) == 0) {
        cout << endl;
      }

      printf("%d ", this->board[i][j]);
    }
  }

  cout << endl;
}

void NQueen::getSolution() {
  int startColNumber = 0;

  if (this->solve(this->board, startColNumber)) {
    this->printBoard();
  } else {
    cout << "Sem solução";
  }
}
