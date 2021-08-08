#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define MAX 100001

int num;
int node1, node2, cost;
vector<pair<int,int>> tree[MAX];
int visited[MAX] = {0, };
int diameter = 0;
int farest_node = 0;

void DFS(int node, int cost) {
    if(visited[node] == 1) return;

    visited[node] = 1;
    if(diameter < cost) {
        diameter = cost;
        farest_node = node;
    }
    for(int i = 0 ; i < tree[node].size(); i++) {
        int new_node = tree[node][i].first;
        int new_cost = tree[node][i].second;
        if(visited[new_node] == 0)
            DFS(new_node, cost + new_cost);
    }
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> num;
    for(int i = 0 ; i < num ; i++) {
        cin >> node1;
        while(true) {
            cin >> node2;
            if(node2 == -1) break;
            
            cin >> cost;
            tree[node1].push_back(make_pair(node2, cost));
            tree[node2].push_back(make_pair(node1, cost));
            }
    }

    DFS(1, 0);

    memset(visited, 0, sizeof(visited));
    diameter = 0;

    DFS(farest_node, 0);

    cout << diameter;

    return 0;
}