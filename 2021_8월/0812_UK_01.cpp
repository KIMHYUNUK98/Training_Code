#include <iostream>
#include <vector>
#include <deque>

using namespace std;
#define MAX 102

// ��, ��, ��, ��
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

// �ʱ� ��ġ�� (1,1)
void MOVE(int y, int x) {
    while(true) {
        count++;
        direction = 3; // ó�� ������ ���� �̵�
        arr[y][x] = 1;

        if(visited[y + dy[direction]][x + dx[direction]] || arr[y + dy[direction]][x + dx[direction]] == -1)
            cout << count << endl;

        snake.push_back({y + dy[direction], x + dx[direction]});
        visited[y + dy[direction]][x + dx[direction]] = true;

        // ����� �߰��ϸ� ����� �Դ´�
        if(arr[y + dy[direction]][x + dx[direction]] == 1) {
            arr[y + dy[direction]][x + dx[direction]] = 0;
        }

        // ����� ������ ������ �� �� �����ش�.
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

    // ���� 1�� ä���.
    for(int i = 0  ; i <= num + 1 ; i++) {
        for(int j = 0 ; j <= num + 1 ; j++) {
            if(i == 0 || j == 0 || j == num + 1 || i == num + 1) {
                arr[i][j] = -1;
                visited[i][j] = true;
            }
        }
    }

    // ��� ��ġ�� 1 ����
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