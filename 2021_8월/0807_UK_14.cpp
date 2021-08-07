// Stack�� for���� ���������� �ʱ�ȭ��Ű�� ���ؼ� for�� �ȿ��� Stack<int>�� �������ָ� �ȴ�.

#include <iostream>
#include <stack>

using namespace std;

int main() {
    int num;
    string arr;

    cin >> num;

    for(int i = 0 ; i < num ; i++) {
        stack<char> Q;
        cin >> arr;
        for(int j = 0 ; j < arr.length() ; j++) {

            if( Q.empty() || arr[j] == '(' ) {
                Q.push(arr[j]);
            }

            else if(Q.top() == '(') {
                Q.pop();
            } 

        }
        if(Q.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
