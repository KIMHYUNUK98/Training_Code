// tree���� ���� ���̰� �� node�� ã�� ���
// root ��忡�� DFS�� ���ؼ� cost�� ���� ������� node�� �ϳ� ã�´�.
// root ��忡�� ���� �� node���� �� ���� ������� node�� �ϳ� ã�´�.
// DFS�� �ι� �����ؼ� ���̸� ã�� �� �ִ�.

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
            //���� �湮�� node�� ������ cost���� DFS �Լ��� ��� �ѱ��.
            DFS(new_index, cost + tree[index][i].second);
        }
    }
}

int main() {

    cin >> num;

    for(int i = 1 ; i < num ; i++) 
    {
        cin >> node1 >> node2 >> cost;
        //���� ��� �迭�� ������ش�.
        tree[node1].push_back(make_pair(node2, cost));
        tree[node2].push_back(make_pair(node1, cost));
    }

    // root ��忡�� ���� �� farest_node�� ã�´�.
    DFS(1, 0);

    memset(visited, 0, sizeof(visited));
    diameter = 0;
    // farest_node���� ���� �� ��带 ã�´�.
    DFS(farest_node, 0);

    cout << diameter;
    return 0;
}