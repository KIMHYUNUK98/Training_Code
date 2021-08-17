#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> hash_map;
    for(vector<string> pair : clothes)
        hash_map[pair[1]]++;
    
    unordered_map<string, int>::iterator iter;
    for(iter = hash_map.begin() ; iter != hash_map.end() ; iter++) {
        answer *= iter->second+1;
    }
    
    return answer-1;
}