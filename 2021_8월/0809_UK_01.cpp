// ���� ���� �� �� ������ �迭 ���ڸ� ���� ������ �ϳ� ������
// �ϳ��� Ű�����鼭 �ٲ������ ������ ������ ã�� �� ���� ��� �Լ��� if������ �ִ´�.

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