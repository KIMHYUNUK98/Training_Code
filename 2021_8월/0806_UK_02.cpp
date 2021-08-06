#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num;
int house;
int arr[25][25] = {0,};
int visited[25][25] = {0,};
vector<int> count_num;
int counting;

void DFS(int start, int end) {
    visited[start][end] = 1;
    counting++;
    //cout << arr[start][end] << " ";

    int i = start;
    int j = end;

    if(arr[i-1][j] == 1 && visited[i-1][j] == 0) DFS(i-1, j);
    if(arr[i+1][j] == 1 && visited[i+1][j] == 0) DFS(i+1, j);
    if(arr[i][j-1] == 1 && visited[i][j-1] == 0) DFS(i, j-1);
    if(arr[i][j+1] == 1 && visited[i][j+1] == 0) DFS(i, j+1);



}

int main() {
    cin >> num;

    // visited 함수 초기화 및 arr 집 유무 확인
    for(int i = 1 ; i <= num ; i++) {
        for(int j = 1 ; j <= num ; j++) {
            scanf("%1d", &arr[i][j]); // 숫자를 하나씩 입력받는 문법
            visited[i][j] = 0;
        }
    }

    for(int i = 1 ; i <= num ; i++) {
        for(int j = 1 ; j <= num ; j++) {
            if(arr[i][j] == 1 && visited[i][j] == 0) {
                counting = 0;
                DFS(i,j);
                count_num.push_back(counting);
            }
        }
    }

    sort(count_num.begin(), count_num.end());
    cout << count_num.size() << '\n';
    for(int i = 0 ; i < count_num.size() ; i++) {
        cout << count_num[i] << '\n';
    }
    
    return 0;
}