#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    // 1단계
    for(int i= 0 ; i < new_id.length() ;i++) {
        new_id[i] = tolower(new_id[i]);
    }
    
    
    // 2단계
    int count = 0;
    for(int i = 0 ; i < new_id.length() ; i++) {
        if(new_id[i] != '-' && new_id[i] != '_' && new_id[i] != '.'
            && (new_id[i] < 'a' || new_id[i] > 'z') 
            && (new_id[i] - '0' < 0 || new_id[i] - '0' > 9)) {
                new_id.erase(new_id.begin() + i--);
        }
    }
    
    // 3단계
    for(int i = 0 ; i < new_id.length() ; i++) {
        if(new_id[i] == '.' && new_id[i+1] == '.') {
            new_id.erase(new_id.begin() + i--);
        }
    }
    
    // 4단계
    for(int i = 0 ; i < new_id.length() ; i++) {
        if(new_id[0] == '.') {
            new_id.erase(new_id.begin());
        }
        if(new_id[new_id.length() - 1] == '.') {
            new_id.erase(new_id.end() - 1);
        }       
    }
  // cout << new_id;
    

    // 5단계
    if(new_id.length() == 0) {
        new_id.push_back('a');
    }
    
    // 6단계
    if(new_id.length() >= 16) {
        new_id.erase(new_id.begin() + 15, new_id.end());
    }
    if(new_id[new_id.length() -1] == '.')
        new_id.erase(new_id.end()-1);
    //cout << new_id;
    
    // 7단계
    if(new_id.length() <= 2) {
        while(true) {
            new_id.push_back(new_id[new_id.length()-1]);
            if(new_id.length() >= 3)
                break;
        }
    }
    //cout << new_id;
    
    return new_id;
}