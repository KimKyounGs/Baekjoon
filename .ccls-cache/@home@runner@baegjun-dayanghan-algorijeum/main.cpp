/*
아이디어 :

1. t 가 2억이라서 시뮬레이션으로 하면 시간초가

2. 수학적인 방법으로 다가가면 된다.
-> x, y 각각 생각하면 각각 2*w, 2*h만큼의 주기가 있다.
-> x만 생각해보면 원래 있던 위치(p) + 시간 t했을 때 마지막 위치가 나오게 된다.
-> 이것을 w만큼 나눠주고 그 결과에 따라 값이 달라진다. 
-> ex) w = 6, x = 2, t = 5 이면 x+t = 7이 되고 이것은  

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#include <map>
#define INF 1e9
#define endl '\n'

using namespace std;

int w, h;
int x, y;
int t;

int main()
{
    cin >> w >> h;
    cin >> x >> y;
    cin >> t;

    if (t%(w*2) == 0) {
        cout << x << ' ';
    }
    else {
        int a = (t%(w*2)+x)/w; // (총 이동량 + 원래 있던 자리) / w; 
        int b = (t%(w*2)+x)%w; // (총 이동량 + 원래 있던 자리) % w; 
        if (a % 2 == 0) { // +을 할 것이냐
            cout << 0+b << ' ';
        } 
        else { // -을 할 것이냐.
            cout << w-b << ' ';
        }
    }

    if (t%(h*2) == 0) {
        cout << y << ' ';
    }
    else {
        int a = (t%(h*2)+y)/h;
        int b = (t%(h*2)+y)%h; 
        if (a % 2 == 0) {
            cout << 0+b << ' ';
        } 
        else {
            cout << h-b << ' ';
        }
    }
    
}


