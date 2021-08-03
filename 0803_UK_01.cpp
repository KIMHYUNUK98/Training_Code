// 우선순위 큐를 선언하고 Value를 집어넣으면 오름차순으로 정렬이된다.
// pair로 형성된 queue에 index값과 value값을 넣어주고
// 우선순위 큐의 top값과 pair 큐의 top이 같으면 count를 1씩 증가시킨다.
// < 우선순위가 지정된 배열의 출력 순서를 계산하는 알고리즘은 이와 동일한 방법으로 풀자>

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
    // 해당 test case 만큼 for문을 반복 실행
    for(int i = 0 ; i < num ; i++) {
        // index값과 value값이 들어갈 q 선언
        // 해당 우선순위 값을 넣어줄 priority_queue 선언
        queue<pair<int,int> > q;
        priority_queue<int> pq;
        scanf("%d %d", &count, &major_index);


        // 배열의 개수만큼 for문 반복 실행 < 배열 생성 >
        // 배열에 index값과 value를 넣어준다
        // 우선순위_배열에는 value값만 넣어준다
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