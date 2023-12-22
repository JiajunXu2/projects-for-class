// Towers Recursive
#include <iostream>
#include <string>
using namespace std;

void move(int f, int t, int e, int n) {
    if(n == 1){
        cout << "Transfer ring from " << f << " to " << t << endl;
        return;
    }
    move(f, e, t, n - 1);
    cout << "Transfer ring from " << f << " to " << t << endl;
    move(e, t, f, n - 1);
}
int main() {
    int n;
    cout << "Enter number of rings: ";
    cin >> n;
    move(1, 2, 3, n);
    return 0;
}
