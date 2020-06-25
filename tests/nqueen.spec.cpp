#include "../src/NQueen.cpp"
#include <gtest/gtest.h>

TEST(NQueenSolve, SixPlaceBoard) {
  int sixPlacesBoard[6][6] =
    { { 0, 0, 0, 0, 0, 0 }, 
    { 0, 0, 0, 0, 0, 0 }, 
    { 0, 0, 0, 0, 0, 0 }, 
    { 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0 }};

  NQueen nqueen(sixPlacesBoard);    

  ASSERT_EQ(6, nqueen.getSolution());
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}
