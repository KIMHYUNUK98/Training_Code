#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[55];
vector<int> visited ={0,};
int count = 0;
int num;
int node;
int root;
int del_node;
int next_node;

void DFS(int cur_node) {
    if(visited[cur_node] == 1) return;
    visited[cur_node] = 1;

    //cout << tree[cur_node].size() << "  ";
    if(tree[cur_node].size() == 1) {
        count++;
    }

    for(int i = 0 ; i < tree[i].size() ; i++) {
        next_node = tree[cur_node][i];
        if(next_node == del_node) continue;
        if(visited[next_node] == 0) {
            DFS(next_node);
        }
    }
}

int main() {

    cin >> num;

    //num에 해당하는 만큼 Tree를 기본적으로 설정해야 한다.
    for(int i = 0 ; i < num ; i++) {
        cin >> node;
        if(node == -1) root = i;
        else {
            tree[node].push_back(i);
        }
        tree[i].push_back(-1);
    }

    cin >> del_node;

    DFS(root);

    if(del_node != root) {
        cout << count << "\n";
    }
    else cout << 0 << "\n";

    return 0;
}