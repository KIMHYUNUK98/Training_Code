#include <iostream>
#include <queue>

using namespace std;

int main() {
    int num, index, temp;
    queue<int> Q;
    vector<int> arr;

    cin >> num >> index;

    // 순열 생성
    for(int i = 1 ; i <= num ; i++) {
        Q.push(i);  
    }

    while(!Q.empty()) {
        for(int k = 0 ; k < index ; k++) {
            temp = Q.front();
            Q.pop();
            if(k != index-1)
                Q.push(temp);
        }
        arr.push_back(temp);
    }

    cout << "<";   
    for(int i = 0 ; i < arr.size(); i++) {
        if(i == arr.size()-1) 
            cout << arr[i] << ">";
        else
            cout << arr[i] << ", " ;
    }
    return 0;
}