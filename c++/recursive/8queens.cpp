//8 queens
#include <iostream>
#include <cmath>
using namespace std;

bool ok(int *q, int c) {
    for(int i = 0; i < c; i++) {
        if(q[c] == q[i]) return false;
    }
    for(int i = 0; i < c; i++) {
        if(c - i == abs(q[c] - q[i])) return false;
    }
    return true;
}

void print(int *q) {
    static int count = 0;
    cout << "Solution number: " << ++count << endl;
    for (int i = 0; i < 8; i++) {
        cout << q[i];
    }
    cout << endl;
}

void move(int *q, int c) {
    if (c == 8) {
        print(q);
        return;
    }
    for(int j = 0; j < 8; j++) {
        q[c] = j;
        if(ok(q, c)) {
            move(q, c + 1);
        }
    }
}


int main() {
    int q[8];
    move(q, 0);
}
