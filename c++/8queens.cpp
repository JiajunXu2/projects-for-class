#include <iostream>
using namespace std;

int main() {
      int b[8][8] = {};// Initialize the board to 0
      int r = 0, c = 0;// Start in the 1st row, 1st column
      b[r][c] = 1; // Place the first queen on the upper left corner 

nextCol:
      c++; // Move to the next column
      if (c == 8) { // If you passed the last column
            goto print;
      }
      r = -1; // Otherwise start at the "TOP" of the column

nextRow:
      r++; // Move to the next row
      if (r == 8) { // If you have passed the end of the column
            goto backtrack;
      }
      // If there is a queen in the same row (to the left), goto nextRow
      for (int i = 0; i < c; i++) { //for each square to the left of the current square
            if (b[r][i] == 1) { //if there is a queen on that square
                goto nextRow;
            }
      }

      // If there is a queen in the upper-left diagonal, goto nextRow
      for (int i = 0; (r - i) >= 0 && (c - i ) >= 0; i++) { //for (int i = 1; ...; i++) // End the loop when you are above or left of the chessboard
            if (b[r-i][c-i] == 1) { //if there is a queen i spots above and left of the current square
                goto nextRow;
            }
      }

      // If there is a queen in the lower-left diagonal, goto nextRow
      for (int i = 0; (r+i) <= 7 && (c-i) >= 0; i++) { //for (int i = 1; ...; i++) // End the loop when you are below or left of the chessboard
            if(b[r+i][c-i] == 1) {//if (there is a queen i spots below and left of the current square)
                goto nextRow;
            }
      }
      b[r][c] = 1;
      goto nextCol;

backtrack:
      c--; // Move to the previous column

      if (c == -1) { //if (you have moved to the left of the chessboard)
            return 0; //exit the program
      }
      r = 0;
      while (b[r][c] !=1) { // Find the square in the column with a queen in it and set r to the row number of that square
            r++;
      }
      b[r][c] = 0;// Remove the queen from the current square

      goto nextRow;

print:
      static int numSolutions = 0;
      cout << "Solution #" << ++numSolutions << ":\n";
      
      for (int r = 0; r < 8; r++) {
	    for (int c = 0; c < 8; c++) {
	        cout << b[r][c];
	    }
	    cout << endl;
	  }
      goto backtrack;
}
