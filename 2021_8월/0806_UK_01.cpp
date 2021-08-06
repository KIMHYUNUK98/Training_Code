#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int max_num;
int count_num;
int start_num;
int starting;
int ending;
queue<int> q;

//vector<vector<int>> arr(1001);
//vector<bool> visited(1001);
int arr[1001][1001];
bool visited[1001];


void reset() {
    for(int i = 0 ; i < max_num ; i++) visited[i] = false;
}

void DFS(int start_num) {
    visited[start_num] = true;
    cout << start_num << " ";

    for(int i = 1 ; i <= max_num ; i++) {
        if(arr[start_num][i] == 1 && visited[i] == false)
            DFS(i);
    }
}

void BFS(int start_num) {
    q.push(start_num);
    visited[start_num] = true;

    while(!q.empty()) {
        start_num = q.front();
        cout << start_num << " ";
        q.pop();

        for(int i = 1 ; i <= max_num ; i++) {
            if(arr[start_num][i] == 1 && visited[i] == false) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main () {

    cin >> max_num >> count_num >> start_num;

    for(int i = 0 ; i < count_num ; i++) {
        cin >> starting >> ending;
        arr[starting][ending] = 1;
        arr[ending][starting] = 1;
    }

    visited[start_num] = true;
    reset();
    DFS(start_num);

    cout << '\n';

    reset();
    BFS(start_num);

    return 0;
}