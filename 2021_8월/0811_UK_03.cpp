#include <iostream>
#include <string>

using namespace std;

int main() {

    string arr;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    cin >> arr;

    for(int i = 0 ; i < alphabet.length() ; i++) {
        cout << (int)arr.find(alphabet[i]) << " ";
    }
    return 0;
}