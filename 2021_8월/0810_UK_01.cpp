/* 
5를 최대한 많이 빼야하는 문제로 접근해서 5로 뺄 수있으면 먼저 빼는 알고리즘을 생각했는데
9처럼 3으로만 뺄 수 잇는 설탕의 경우 예외사항이 발생한다.
반대로 생각하면 3을 뺄 수 있을 만큼 먼저 빼고 나머지를 모두 5로 처리하면 된다.
5로 나누어 떨어질 때까지 3을 한 번씩 빼주다가 
5로 나눈 나머지가 0이 되면 그 때 5로 나눈 몫을 count 해주면 끝.
*/

#include <iostream>

using namespace std;

int main() {
    int num;
    int count = 0;

    cin >> num;

    while(num >= 0) {
        if(num % 5 == 0) {
            count += num / 5;
            cout << count << endl;
            return 0;
        }
        num -= 3;
        count++;
    }
    cout << -1 << endl;

    return 0;
}