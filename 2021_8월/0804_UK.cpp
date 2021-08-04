// dp������ �ʱⰪ�� �����ϰ� �� ������ ��� �̾���� ����
// ��κ��� �ּڰ�, �ִ��� ã�� ����
// ������ �պ��� �󸶳� Ŀ���� �� ���� �������� ū �Ͱ� ���� ���� �ϳ��� ���ϴ� ������ �Ͱ�

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