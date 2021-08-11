#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int main() {
    string arr;
    int count  = 0;
    //gets, gets_s
    getline(cin, arr);
    

    for(int i = 0 ; i < arr.length() ; i++){
        if(isspace(arr[i])) count++;
    }
    int answer = count + 1;

    if(isspace(arr[arr.length()-1])) answer -= 1;
    if(isspace(arr[0])) answer -= 1;

    cout << answer;
    return 0;
}