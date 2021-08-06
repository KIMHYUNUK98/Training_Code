#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dp(42);

int fibonacci(int n) {
    if (n == 0) {
        return dp[n]++;
    } else if (n == 1) {
        return dp[n]++;
    } else {
        dp[n] = fibonacci(n-1) + fibonacci(n-2);
        return dp[n];
    }
}

int main() {
    int num;
    int fib;
    cin >> num;

    for(int i = 0 ; i < num ; i++) {
        scanf("%d", &fib);
        fibonacci(fib);

        printf("%d %d\n", fibonacci(fib-1), fibonacci(fib));
    }

    return 0;
}

