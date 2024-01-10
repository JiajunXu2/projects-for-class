#include<iostream>
using namespace std;

int main() {
   while (true) {
      string runners;
      cout << "Enter the race outcome: ";
      cin >> runners;
      if (runners == "done") return 0;
      int numTeams = 0;       
      int scores[26] = {0}; //scores[i] keeps track of the total score of team i
      int counts[26] = {0}; 
      for (unsigned int i = 0; i < runners.length(); i++) {     //For each runner in the race,
        char currentChar = runners[i];     
        counts['currentChar' - 65]++;     //counts[i] keeps track of the number of runners on team i
        
        bool isUnique = true;
        for (int m = i - 1; m >= 0 ; m--) {
	        if (runners[i] == runners[m]) {
	           isUnique = false;
	           break;
	        }
        }
        if (isUnique) {
	           numTeams++; // If it's the first runner of that particular team, update the total number of teams
	        }
      }
      // If the teams do not all have the same number of runners,
         // Print an error message and ask for input again (go back to the beginning of the loop)
      cout << "There are " << numTeams << " teams." << endl;
      for (int n = 0; n < 26; n++) { // For each letter from A-Z,
          if(counts[n] > 0) { // If that team participated,
              cout << counts[n] << ": " << scores << endl; // Print the name of the team and its average score
          }
      }
      // Print the name of the winning team and its average score (if it's a tie, you may either pick one arbitrarily or print all of the winners)
   }
   return 0;
}
