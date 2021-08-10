/*
문제의도만 파악하면 알고리즘으로 구현하는게 어렵지 않다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int num;
    int time;
    int sum = 0;
    vector<pair<int,int>> arr;
    vector<int> pin;

    cin >> num;
    for(int i = 1 ; i <= num ; i++) {
        cin >> time;
        arr.push_back(make_pair(time, i));
    }

    sort(arr.begin(), arr.end());

    for(int i = 0 ; i < num ; i++) {
        for(int j = 0 ; j <= i ; j++) {
            sum += arr[j].first;
        }
    }

    cout << sum;
    return 0;
}