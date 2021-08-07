// Stack을 for문을 돌릴때마다 초기화시키기 위해서 for문 안에서 Stack<int>를 선언해주면 된다.

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
