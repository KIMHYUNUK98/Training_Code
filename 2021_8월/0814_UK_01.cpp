#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string arr;
    while(true) {
        stack<char> S;
        getline(cin, arr);
        if(arr == ".") break;

        int len = arr.length();
        for(int i = 0 ; i < len ; i++) {
            if(arr[i] == '.') break;
            if(arr[i] == '(' || arr[i] == '[') {
                S.push(arr[i]);
            }
            else if(!S.empty() && arr[i] == ')') {
                if(S.top() == '(')
                    S.pop();
            }
            else if(!S.empty() && arr[i] == ']') {
                if(S.top() == '[')
                    S.pop();
            }
        }

        if(S.empty()) cout << "yes" << endl;
        else cout << "no" << endl;
    }


    return 0;
}