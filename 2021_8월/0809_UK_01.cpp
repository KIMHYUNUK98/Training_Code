// 제일 작을 때 빈 공간의 배열 숫자를 통해 논리식을 하나 만들어낸다
// 하나씩 키워보면서 바뀌어지는 일정한 패턴을 찾고 그 논리를 재귀 함수에 if문으로 넣는다.

#include <iostream>

using namespace std;

void draw_star(int y, int x, int num) {
    if((y/num) % 3 == 1 && (x/num) % 3 == 1) {
        cout << " ";
    }
    else {
        if(num / 3 == 0) cout << "*";
        else draw_star(y,x,num/3);
    }
}

int main() {
    int num;
    cin >> num;

    for(int i = 0 ; i < num ; i++) {
        for(int j = 0 ; j < num ; j++) {
            draw_star(i,j, num);
        }
        cout << "\n";
    }

    return 0;
}