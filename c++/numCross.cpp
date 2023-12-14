#include<iostream>
#include<cmath>
using namespace std;

bool test(int cross[], int x) {
	static int checkList[8][5] = {
		{-1},
		{0,-1}, 
		{1,-1}, 
		{0,1,2,-1}, 
		{1,2,3,-1}, 
		{2,4,-1}, 
		{0,3,4,-1}, 
		{3,4,5,6,-1}, 
	};
	for (int i = 0; i < x; i++) { 
	    if(cross[i] == cross[x]) {
	        return false;
	    }
	}
	for (int i = 0; i < 5; i++) {
	    if (abs(cross[x] - checkList[x][i]) == 1) {
	        return false;
        } 
	}
	return true;
}

void print(int cross[]) {
	static int count = 0;
	cout << " Soultion number: " << ++count << endl;
	if (count > 5) exit(0);
	cout << " " << cross[1] << cross[2] << endl;
	cout << cross[0] << cross[3] << cross[4] << cross[5] << endl;
	cout << " " << cross[6] << cross[7] << endl;
	return;
}

int main() {
    int cross[8] = {0};
    int c = 0;
    cross[0] = 0;
    while(c >= 0) {
        c++;
        if (c == 8) {
            print(cross);
            c--;
            cross[c]++;
        } else { cross[c] = -1; }
        while(c >= 0) {
            cross[c]++;
            bool check = test(cross, c);
            if(cross[c] == 8) {
                c--;
                cross[c]++;
            }
            else if (check) {
                break;
            }
        }
	}
	return 0;
}
