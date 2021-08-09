#include <iostream>

using namespace std;
string video[64];

void compress (int x, int y, int num) {
    char ch = video[y][x];

    for(int i = y ; i < y + num ; i++) {
        for(int j = x ; j < x + num ; j++) {
            if(ch != video[i][j]) {
                cout << '(';
                compress(x, y, num/2);
                compress(x + num/2, y, num/2);
                compress(x, y + num/2, num/2);
                compress(x + num/2, y + num/2, num/2);
                cout << ')';
                return;
            }
        }
    }
    cout << ch;
}

int main() {
    
    int num;
    cin >> num;

    for(int i = 0 ; i < num ; i++) {
        cin >> video[i];
    }

    compress(0, 0, num);
    return 0;
}
