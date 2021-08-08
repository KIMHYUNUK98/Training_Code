// tree에서 가장 길이가 긴 node를 찾는 방법
// root 노드에서 DFS를 통해서 cost가 가장 길어지는 node를 하나 찾는다.
// root 노드에서 가장 먼 node에서 또 가장 길어지는 node를 하나 찾는다.
// DFS를 두번 실행해서 길이를 찾을 수 있다.

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define MAX 10001

vector<pair<int, int>> tree[MAX];
int visited[MAX] = {0,};
int diameter = 0;
int farest_node = 0;
int num;
int node1, node2, cost;

void DFS(int index, int cost) {
    if(visited[index] == 1) return;
    
    visited[index] = 1;
    if(diameter < cost) {
        diameter = cost;
        farest_node = index;
    }
    
    for(int i = 0 ; i < tree[index].size(); i++) {
        int new_index = tree[index][i].first;
        if(visited[new_index] == 0) {
            //다음 방문할 node와 축적된 cost값을 DFS 함수로 계속 넘긴다.
            DFS(new_index, cost + tree[index][i].second);
        }
    }
}

int main() {

    cin >> num;

    for(int i = 1 ; i < num ; i++) 
    {
        cin >> node1 >> node2 >> cost;
        //인접 노드 배열을 만들어준다.
        tree[node1].push_back(make_pair(node2, cost));
        tree[node2].push_back(make_pair(node1, cost));
    }

    // root 노드에서 가장 먼 farest_node를 찾는다.
    DFS(1, 0);

    memset(visited, 0, sizeof(visited));
    diameter = 0;
    // farest_node에서 가장 먼 노드를 찾는다.
    DFS(farest_node, 0);

    cout << diameter;
    return 0;
}