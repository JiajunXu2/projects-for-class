//Non Recursive
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int NUM_ROWS = 5, NUM_COLS = 6;
string path[NUM_ROWS][NUM_COLS];

// Calculates the cost of every square and fills in the cost matrix.
void calculateCosts() {
   static int weight[NUM_ROWS][NUM_COLS] = {{3,4,1,2,8,6},
                                            {6,1,8,2,7,4},
                                            {5,9,3,9,9,5},
                                            {8,4,1,3,2,6},
                                            {3,7,2,8,6,4}};
   // Declare the cost matrix.
   int cost[NUM_ROWS][NUM_COLS] =       {   {3},
                                            {6},
                                            {5},
                                            {8},
                                            {3}};
   // Copy the leftmost column of the weight matrix to the cost matrix, and initialize the leftmost column of the path matrix.
   string path[NUM_ROWS][NUM_COLS] =    {   {"0"},
                                            {"1"},
                                            {"2"},
                                            {"3"},
                                            {"4"}};
   for(int i = 1; i < NUM_COLS; i++) {
       for(int j = 0; j < NUM_ROWS; j++) {
           int up = weight[(j + 4) % 5][i - 1];
           int left = weight[j][i - 1];
           int down = weight[(j + 1) % 5][i - 1];
           cost[j][i] = weight[j][i] + min(min(up, left), down);
           path[j][i] += to_string(i);
       }
   }// Calculate the cost of each square in the column (non-recursively),and store the correct number in the cost matrix and the correct string in the path matrix.

   int minRow = 0;
   // Check which square in the rightmost column has the lowest cost.  Store the row number of that square in minRow.
   int placeHolder = cost[0][5];
   for(int i = 1; i < 5; i++){
       if(placeHolder > cost[i][5]) {
           minRow = placeHolder;
       }
   }
   
   cout << "The length of the shortest path is " << cost[minRow][NUM_COLS-1];
   cout << ".\nThe rows of the path from left to right are " << path[minRow][NUM_COLS-1] << ".";
}

int main() {
   calculateCosts();

   return 0;
