/*
아이디어 :

주어진 방법은 곱하거나 더하기 두 가지가 있다.


양수면 큰 숫자끼리 곱하기. 
음수면큰 숫자끼리 곱해서 플러스로 만들기. or 0이랑 곱해서 없애기.


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

    
    
    return 0;
}