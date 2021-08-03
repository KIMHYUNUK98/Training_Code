// �켱���� ť�� �����ϰ� Value�� ��������� ������������ �����̵ȴ�.
// pair�� ������ queue�� index���� value���� �־��ְ�
// �켱���� ť�� top���� pair ť�� top�� ������ count�� 1�� ������Ų��.
// < �켱������ ������ �迭�� ��� ������ ����ϴ� �˰����� �̿� ������ ������� Ǯ��>

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int num = 0;
    int count = 0;
    int major_index = 0;
    int arr = 0;
    int order = 0;

    scanf("%d", &num);
    // �ش� test case ��ŭ for���� �ݺ� ����
    for(int i = 0 ; i < num ; i++) {
        // index���� value���� �� q ����
        // �ش� �켱���� ���� �־��� priority_queue ����
        queue<pair<int,int> > q;
        priority_queue<int> pq;
        scanf("%d %d", &count, &major_index);


        // �迭�� ������ŭ for�� �ݺ� ���� < �迭 ���� >
        // �迭�� index���� value�� �־��ش�
        // �켱����_�迭���� value���� �־��ش�
        for(int j = 0 ; j < count ; j++) {
            scanf("%d", &arr);
            q.push({j,arr});
            pq.push(arr);
        }

        while(!q.empty()) {
            int index = q.front().first;
            int value = q.front().second;
            q.pop();

            if(pq.top() == value) {
                pq.pop();
                order++;
                if(index == major_index) {
                    printf("%d\n", order);
                    break;
                }
            }
            else 
                q.push({index, value});
        }
        order = 0;
    }
    return 0;
}