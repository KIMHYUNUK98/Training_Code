// �켱����_ť�� ���ٸ� ������ ������ ������������ queue�� �����ϰ� �ȴ�.
// greater<�ڷ���>�� ���ָ� ������������ queue�� ������ �� �ִ� 

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