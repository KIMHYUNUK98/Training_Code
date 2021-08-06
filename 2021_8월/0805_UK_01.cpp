#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num;
    int number;
    scanf("%d" , &num);

    vector<int> dp(num+4, 12);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int j = 0 ; j < num ; j++) {
        scanf("%d", &number);
        for(int i = 4 ; i <=number ; i++) {
            dp[i] = dp [i-3] + dp[i-2] + dp[i-1];
        }
        printf("%d\n", dp[number]);
    }

    return 0;
}