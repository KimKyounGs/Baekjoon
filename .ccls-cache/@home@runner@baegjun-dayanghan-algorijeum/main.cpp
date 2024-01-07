/*
아이디어 :

주어진 방법은 곱하거나 더하기 두 가지가 있다.


양수면 큰 숫자끼리 곱하기. 
음수면큰 숫자끼리 곱해서 플러스로 만들기. or 0이랑 곱해서 없애기.

ex)
4
-1
2
1
3

-1 1 2 3

-1 

1 2 3

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

int N;
int result;
vector<int> v;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i ++) {
        int n;
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());

    int idx = 0;
    // 음수 처리
    while(true) {
        // 음수
        if (v[idx] < 0) {
            if (v[idx + 1] <= 0) {
                result += v[idx] * v[idx + 1];
                idx ++;
            } 
            else {
                result += v[idx];
                idx ++;
            }
        }
        else {
            break;
        }
    }
    cout << "Debug = " << result << endl;
    // 양수 처리
    for (int i = N-1; i >= idx; i --) {
        if (i-1 >= idx) {
            result += v[i-1] * v[i];
            i--;
        }
        else {
            result += v[i];
        }
    }

    cout << result << endl;
    return 0;
}