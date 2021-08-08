#include <iostream>
#include <vector>

using namespace std;

vector<int> tree;
int count = 0;

int DFS(int cur_node) {
    int ret = 1;
    int child = 0;

    for(int i = 1 ; i < tree[i].size() ; i++) {
        if(i == del_node) continue;
        count++;
        DFS(i);
    }

    if(child != 0) return count;
    else return ret;
}

int main() {
    int num;
    int node;
    int root;
    int del_node;

    cin >> num;

    //num에 해당하는 만큼 Tree를 기본적으로 설정해야 한다.
    for(int i = 0 ; i < num ; i++) {
        cin >> node;
        if(node == -1) {
            tree[i].push_back(node);
            tree[node].push_back(i);
        }
        else root = i;
    }

    cin >> del_node;

    cout << DFS(0);


    return 0;
}