// precision 함수를 사용하면 소수점 몇번째까지 표시할 것인지 정할 수 있다.
// cout << fixed 를 하면 소수점 아래의 개수만 정할 수 있다.

#include <iostream>

using namespace std;

int main() {
    double A, B;

    cin >> A >> B;

    cout.precision(12);
    cout << fixed;
    cout << A /B;

    return 0;
}