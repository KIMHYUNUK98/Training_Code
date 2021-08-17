/*
string���� ���ڸ� �޾����Ƿ� ���� �ϳ��ϳ��� 1byte�� �� ������ �����ϸ鼭 �Ҵ�Ǿ���.
���� for���� ���ؼ� �ϳ��� ���ڰ� �ٸ� ������ �պκп� ��� ������ Ȯ���� �ϸ� false.
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