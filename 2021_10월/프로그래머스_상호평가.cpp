#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    int max = -1;
    int sum = 0;
    int count = 0;
    int my_score = 0;
    int min = 101;
    float average = 0.F;
    int only = 0;
    
    for(int i = 0 ; i < scores.size() ; i++) 
    {
        my_score = scores[i][i];
        
        for(int j = 0 ; j < scores[i].size(); j++) 
        {
            sum += scores[j][i];
            count++;
            if(max == scores[j][i] || min == scores[j][i]) {only++;}
            if(max < scores[j][j]) {max = scores[j][i];}
            if(min > scores[j][i]) {min = scores[j][i];}
            
            cout << "max = " << max << endl;
            cout << "min = " << min << endl;
        }
        
        if(only == 0 && (my_score == max || my_score == min)) {
            sum -= my_score;
            count--;
        }
        average = (float)sum / count;
    
        
        if(average >= 90) {
            answer.append("A");
        } else if(average >= 80) {
            answer.append("B");
        } else if(average >= 70) {
            answer.append("C");
        } else if(average >= 50) {
            answer.append("D");
        } else {
            answer.append("F");
        }
        count = 0;
        sum = 0;
        max = -1;
        min = 101;
        only = 0;
    }
    
    return answer;
}
