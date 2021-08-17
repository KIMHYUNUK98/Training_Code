/*
string으로 숫자를 받았으므로 숫자 하나하나가 1byte로 한 공간을 차지하면서 할당되었다.
이중 for문을 통해서 하나의 숫자가 다른 숫자의 앞부분에 모두 들어가는지 확인을 하면 false.
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    if(phone_book.size() <= 1) return true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 1 ; i < phone_book.size() ; i++) {
        if(phone_book[i].find(phone_book[i-1]) == 0)
            answer = false;
    }
    return answer;
}