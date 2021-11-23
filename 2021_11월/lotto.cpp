#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int count = 0;
    int zero_count =0 ;
    
    for(int i = 0 ; i < lottos.size() ; i++) {
        for(int j = 0 ; j < win_nums.size() ; j++) {
            if(lottos[i] == win_nums[j])
                count++;
        }
        if(lottos[i] == 0)
            zero_count++;
    }

    if(zero_count != 0)
        answer.push_back(7 - count - zero_count);
    else if(count == 0)
        answer.push_back(6);
    else
        answer.push_back(7 - count);
    
    if(count != 0)
        answer.push_back(7 - count);
    else 
        answer.push_back(6);
        
    return answer;
}