#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int num;
    int dp[1001][3] = {0,};

    cin >> num;
    for(int i = 1  ; i <= num ; i++) {
        cin >> dp[i][0] >> dp[i][1] >> dp[i][2];

        dp[i][0] += min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] += min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] += min(dp[i-1][0], dp[i-1][1]);
    }

    cout << min(dp[num][0], min(dp[num][1], dp[num][2]));
    return 0;
}