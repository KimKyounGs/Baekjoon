/*
아이디어 :


*/
#include <iostream>
#include <stack>

using namespace std;

string str;
stack<char> num;
int result;

bool check = false;
bool subCheck = false;

void calculate() {
    int mul = 1;
    if (!check) {
        while(!num.empty()) {
            result += (num.top() - '0') * mul;
            num.pop();
            mul *= 10;
        }
    }

    else {
        while(!num.empty()) {
            result -= (num.top() - '0') * mul;
            num.pop();
            mul *= 10;
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> str;
    int len = str.length();   
    
    for (int i = 0; i < len; i ++) {
        // 부호인경우
        if (str[i] == '-' || str[i] == '+') {
            calculate();
            if(str[i] == '-' && !subCheck) {
                subCheck = true;
                check = !check;
            }
        }
        // 숫자인 경우
        else {
            num.push(str[i]);
        }
    }
    calculate();

    cout << result << '\n';
}