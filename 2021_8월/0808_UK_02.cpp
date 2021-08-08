#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[100001];
int parent[100001];
int visited[100001];


void findparent(int path) {
    visited[path] = 1;

    for(int i = 0 ; i < tree[path].size(); i++) {
        int next = tree[path][i];

        if(visited[next] == 0) {
            parent[next] = path;
            findparent(next);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int num;
    int left, right;
    cin >> num;

    for(int i = 0 ; i < num-1 ; i++){
        cin >> left >> right;
        tree[left].push_back(right);
        tree[right].push_back(left);
    }

    findparent(1);
    for(int i = 2 ; i <= num ; i++) {
        cout << parent[i] << "\n";
    }
    return 0;
}