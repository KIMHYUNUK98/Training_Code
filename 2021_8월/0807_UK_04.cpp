#include <iostream>
#include <vector>

using namespace std;

int main() {
    int A, B;
    vector<int> C;

    cin >> A >> B;

    C.push_back(A+B);
    C.push_back(A-B);
    C.push_back(A*B);
    C.push_back(A/B);
    C.push_back(A%B);

    for(int i = 0 ; i < C.size() ; i++) {
        cout << C[i] << endl;
    }
    return 0;
}