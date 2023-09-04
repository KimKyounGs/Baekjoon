#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string N;

int main() {
    while(1) {
        cin >> N;

        if (N == "0") {
            break;
        }

        int start = 0;
        int end = N.length() - 1;
        bool check = false;
        
        while(start < end) {
            if (N[start] != N[end]) check = true;
            start ++;
            end --;
        }

        if (check) cout << "no" << '\n';
        else cout << "yes" << '\n';
    }
    
    return 0;
}