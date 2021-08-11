#include <iostream>
#include <string>

using namespace std;

int main() {
    int num;
    int sum = 0;
    string arr;

    cin >> num;

    cin >> arr;
    for(int i = 0 ; i < num ; i++) {
        sum += arr[i] - '0';
    }

    cout << sum;
    return 0;
}