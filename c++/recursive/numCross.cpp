//8 num cross
#include <iostream>
#include <cmath>
using namespace std;

bool ok(int *cross, int c) {
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
	
    for(int i = 0; i < c; i++) {
        if(cross[c] == cross[i]) return false;
    }
    for(int i = 0; i < 5; i++) {
        if(checkList[c][i] == -1) break;
        if((abs(cross[c] - cross[checkList[c][i]])) == 1) return false;
    }
    return true;
}

void print(int cross[]) {
	static int count = 0;
	if(count > 4) exit(0);
	cout << " Soultion number: " << ++count << endl;
	cout << " " << cross[1] << cross[2] << endl;
	cout << cross[0] << cross[3] << cross[4] << cross[5] << endl;
	cout << " " << cross[6] << cross[7] << endl;
	return;
}

void move(int *cross, int c) {
    if (c == 8) {
        print(cross);
        return;
    }
    for(int j = 0; j < 8; j++) {
        cross[c] = j;
        if(ok(cross, c)) {
            move(cross, c + 1);
        }
    }
    return;
}


int main() {
    int cross[8];
    move(cross, 0);
}
