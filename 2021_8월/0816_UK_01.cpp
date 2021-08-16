#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map <string, int> part_arr;
    for(string name : participant) {
        part_arr[name]++;
    }
    for(string name : completion) {
        part_arr[name]--;
    }
    for(string name : participant) {
        if(part_arr[name] == 1)
            return name;
    }
}