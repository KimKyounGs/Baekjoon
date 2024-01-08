/*
아이디어 :



회의실 배정 -> 끝나는 시간을 기준으로 정렬하고 최적의 해를 도출했다.

희의실 배정 -> 한 강의실에 대해서 얼마나 많이 배정을 할 수 있다. -> 한 강의실에서 최대한 많이 넣으면, 결국 최소한으로 강의실을 구할 수 있다.

한 강의실에 최대한 많은 강의를 배정하면 (끝나는 시간을 기준으로 정렬했을 때) -> 최소한의 강의실을 구할 수 있다.(x)



강의실 배정 -> 시작 시간을 기준으로 정렬하고 최적의 해를 도출한다.



3
1 3
2 4
3 5

1 3 -> 3 5
2 4

2개의 강의실. -> 이중포문 -> 

시간복잡도 -> O(N^2) -> 1초 넘어간다.
시간복잡도 -> O(NlogN) -> 1초 안넘김.

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
vector<pair<int, int>> v;
priority_queue<int> pq;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i ++) {
        int s,e;
        cin >> s >> e;
        v.push_back({s,e});
    }

    sort(v.begin(), v.end());

    int start = v[0].first;
    int end = v[0].second;
    int cnt = 1;
    
    while(cnt == N) {
        
    }
    
    return 0;
}