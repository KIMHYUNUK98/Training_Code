#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int count = 0;
int dx[4] = {-1, 0, 0, 1 };
int dy[4] = { 0,-1, 1, 0};
int miro[102][102];
int visited[102][102] = {0,};
int check[102][102] = {0, };  //미로의 길 개수가 아니라 최소 개수이므로 check이중 배열 필요
int N, M;

void BFS(int start, int end) {
    visited[start][end] = 1;

    queue<pair<int, int>> q;
    q.push(make_pair(start, end));

    while(!q.empty()) {
        int X = q.front().second;
        int Y = q.front().first;
        q.pop();

        for(int i = 0 ; i < 4 ; i++) {
            int newX = X + dx[i];
            int newY = Y + dy[i];
            if(newX >= 0 && newX < M && newY >= 0 && newY < N && miro[newY][newX] == 1 &&
                visited[newY][newX] == 0 && check[newY][newX] == 0) {
                check[newY][newX] = check[Y][X] + 1;
                visited[newY][newX] = 1;
                q.push(make_pair(newY, newX));
            }
        }
    }
}

int main() {
    cin >> N >> M;

    //공백없이 숫자열을 입력받기 (int타입으로 받을 경우 scanf로 하나씩 입력)
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < M ; j++) {
            scanf("%1d", &miro[i][j]);
        }
    }

    BFS(0, 0);
/*
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < M ; j++) {
            cout << check[i][j] << " ";
        }
        cout << '\n';
    }
    */
    cout << check[N-1][M-1] + 1;

    return 0;
}