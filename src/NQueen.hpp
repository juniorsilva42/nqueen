#ifndef IA_SOLVE_PROBLEMS_H
#define IA_SOLVE_PROBLEMS_H

#define BOARD_LENGTH 8

class NQueen {

private:
  int board[BOARD_LENGTH][BOARD_LENGTH];

  bool isSafePlace(int row, int col);
  bool solve(int board[BOARD_LENGTH][BOARD_LENGTH], int col);
  void startBoard();
  void printBoard();

public:  
  NQueen();
  ~NQueen() = default;
  
  void getSolution();
};

#endif
