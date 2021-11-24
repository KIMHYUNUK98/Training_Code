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
    cout << new_id;
    
    
    // 2단계
    int count = 0;
    for(int i = 0 ; i < new_id.length() ; i++) {
        if(new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.'
            || (new_id[i] >= 'a' && new_id[i] <= 'z')) {
                answer[count++] = new_id[i];
        }
    }
    
    cout << answer;
    /*
    // 3단계
    count = 0;
    for(int i = 0 ; i < answer.length() ; i++) {
        if(answer[i] == '.' && answer[i+1] == '.') {
            continue;
        }
        answer[count++] = answer[i];
    }
    answer[count] = '\0';
    
    // 4단계
    count = 0;
    for(int i = 0 ; i < answer.length() ; i++) {
        if(answer[0] == '.' || answer[answer.length() - 1] == '.')
            continue;
        answer[count++] = answer[i];
    }
    answer[count] = '\0';
    
    // 5단계
    if(answer.length() == 0) {
        answer[0] = 'a';
    }
    
    // 6단계
    count = 0;
    if(answer.length() >= 16) {
        for(int i =0 ; i < 16 ; i++) {
            answer[count++] = answer[i];
        }
    }
    answer[count] = '\0';
    if(answer[count-1] == '.')
        answer[count-1] = '\0';
    
    // 7단계
    if(answer.length() <= 2) {
        while(true) {
            answer[answer.length()] = answer[answer.length()-1];
            if(answer.length() == 3)
                break;
        }
    }
    */
    
    return answer;
}