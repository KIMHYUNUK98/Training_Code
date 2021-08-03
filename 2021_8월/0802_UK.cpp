// 우선순위_큐는 별다른 조건이 없으면 내림차순으로 queue를 구성하게 된다.
// greater<자료형>을 해주면 오름차순으로 queue를 구성할 수 있다 

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int num;
    int number;
    pi count;
    
    priority_queue<pi, vector<pi>, greater<pi>> q;

    scanf("%d", &num);

    for(int i = 0 ; i < num ; i++) {
        scanf("%d", &number);
        if(number == 0) {
            if(q.size() == 0) printf("0\n") 
            else {
                count = q.top();
                printf("%d\n", count.second);
                q.pop();
            }
        }
        else {
            q.push(make_pair(abs(number), number));
        }
    }
    return 0;
}