#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int num, number;
    int count = 0;
    vector<int> arr;
    vector<char> answer;
    stack<int> Stack;

    cin >> num;

    //원하는 수열 순서를 가진 배열 arr을 만들어 놓은다.
    for(int i = 1 ; i <= num ; i++) {
        cin >> number;
        arr.push_back(number);
    }

    for(int i = 1 ; i <= num ; i++) {
        Stack.push(i);
        answer.push_back('+');
        while(!Stack.empty() && arr[count] == Stack.top()) {
            Stack.pop();
            answer.push_back('-');
            count++;
        }
    }

    if(Stack.empty()) {
        for(int i = 0 ; i < answer.size() ; i++) {
            cout << answer[i] << endl;
        }
    }
    else {
        cout << "NO";
    }

    return 0;
}