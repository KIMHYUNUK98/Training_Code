#include <iostream>
#include <vector>
#include <deque>

using namespace std;
#define MAX 102

// 상, 하, 좌, 우
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int num;
int apple_num, apple_y, apple_x;
int count = 0;
int direction = 0;
int length = 1;
int move_time = 0;

vector<pair<int, char>> movement;
pair<int, int> tail;
deque<pair<int,int>> snake;
int arr[MAX][MAX] = {0,};
bool visited[MAX][MAX] = {false,};

// 초기 위치는 (1,1)
void MOVE(int y, int x) {
    while(true) {
        count++;
        direction = 3; // 처음 방향은 우측 이동
        arr[y][x] = 1;

        if(visited[y + dy[direction]][x + dx[direction]] || arr[y + dy[direction]][x + dx[direction]] == -1)
            cout << count << endl;

        snake.push_back({y + dy[direction], x + dx[direction]});
        visited[y + dy[direction]][x + dx[direction]] = true;

        // 사과를 발견하면 사과를 먹는다
        if(arr[y + dy[direction]][x + dx[direction]] == 1) {
            arr[y + dy[direction]][x + dx[direction]] = 0;
        }

        // 사과가 없으면 꼬리를 한 개 없애준다.
        else if(arr[y + dy[direction]][x + dx[direction]] == 0) {
            tail = snake.front();
            visited[tail.first][tail.second] = false;
            snake.pop_front();
        }

        if(movement[move_time].first == count) {
            if(movement[move_time].second == 'L')
                direction = (direction + 3) % 4;
            else
                direction = (direction + 1) % 4;
            move_time++;
        }
    }
}

int main() {
    cin >> num;

    // 벽을 1로 채운다.
    for(int i = 0  ; i <= num + 1 ; i++) {
        for(int j = 0 ; j <= num + 1 ; j++) {
            if(i == 0 || j == 0 || j == num + 1 || i == num + 1) {
                arr[i][j] = -1;
                visited[i][j] = true;
            }
        }
    }

    // 사과 위치에 1 놓기
    cin >> apple_num;
    for(int i = 0 ; i < apple_num ; i++) {
        cin >> apple_y >> apple_x;
        arr[apple_y][apple_x] = 1;
    }

    int time_num, seconds;
    char turn;
    cin >> time_num;
    for(int i = 0 ; i < time_num ; i++) {
        cin >> seconds >> turn;
        movement[i].first = seconds;
        movement[i].second = turn;
    }

    snake.push_back({1,1});\
    visited[1][1] = true;
    MOVE(1,1);
    return 0;
}