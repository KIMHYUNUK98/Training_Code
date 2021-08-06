// dp문제는 초기값을 설정하고 그 연산을 계속 이어나가는 문제
// 대부분이 최솟값, 최댓값을 찾는 문제
// 이전의 합보다 얼마나 커지며 두 개의 선택지중 큰 것과 작은 것중 하나를 택하는 문제로 귀결

#include <iostream>
#include <vector>

using namespace std;
#define MAX 99999

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;

    vector<int> dp(num+1, MAX);
    dp[3] = 1;
    dp[5] = 1;

    for(int i = 6 ; i <= num ; i++) {
        dp[i] = min(dp[i-5] + 1, dp[i-3] + 1);
    }

    if(dp[num] >= MAX) {
        cout << "-1" << endl;
    } else {
        cout << dp[num] << endl;
    }
    return 0;
}