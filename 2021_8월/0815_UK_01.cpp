#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    if(a.second == b.second)
        return a.first < b.first;
    
    return a.second < b.second;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    int one, two;
    vector<pair<int, int>> arr;
    
    cin >> num;
    for(int i = 0 ; i < num ; i++) {
        cin >> one >> two;
        arr.push_back(make_pair(one, two));
    }

    sort(arr.begin(), arr.end(), compare);

    for(int i = 0 ; i < num ; i++) {
        cout << arr[i].first << " " << arr[i].second << "\n";
    }

    return 0;
}