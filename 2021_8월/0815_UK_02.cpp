#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int num;
    int step;
    int dp[303];
    int arr[301] = {0};

    cin >> num;

    for(int i = 1 ; i <= num ; i++) {
        cin >> arr[i];
    }

    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];

    for(int i = 3 ; i <= num ; i++) {
        dp[i] = max(arr[i] + dp[i-2], arr[i] + arr[i-1] + dp[i-3]);
    }

    cout << dp[num];
    return 0;
}