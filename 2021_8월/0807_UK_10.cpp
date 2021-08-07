#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int num, larger;
    int intro;

    cin >> num >> larger;
    vector<int> arr;

    for(int i = 0 ; i < num ; i++) {
        cin >> intro;
        arr.push_back(intro);
    }

    for(int i = 0 ; i < num ; i++) {
        if(arr[i] < larger) {
            cout << arr[i] << " ";
        }
    }
    return 0;
}