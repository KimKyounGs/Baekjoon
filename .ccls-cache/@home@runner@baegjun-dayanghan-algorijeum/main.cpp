/*
아이디어 :

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
vector<int> v;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i ++) 
    {
        int n;
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());
    int a = 0;
    int b = 0;
    int maxs = 0;

    for (int i = 0; i < N-1; i ++) 
    {
        if (maxs < v[i+1] - v[i])
        {
            a = i+1;
            b = i;
            maxs = v[i+1] - v[i];
        }
    }

    if (maxs == 1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << (v[a] + v[b])/2;
    }
    
}