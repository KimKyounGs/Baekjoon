/*
# 아이디어 

23.02.21

재채점해서 틀린 문제이다.

이 문제에 질문 게시판을 보니깐 오버플로우 문제인거 같았다.
(게시판 링크 : https://www.acmicpc.net/board/view/110762)

오버플로우가 난 지점을 확인해보면 cnt에 mid/v[i]값을 더해줄 때이다.
cnt에 들어갈 최대값을 생각해보자.
v[i]값들이 다 1이라고 하고, mid값은 최대(10^9) * 10^9라고 생각해보면, cnt에 값이 최대 10^9 * 10^9 * 100000(N최대값)이 될 수 있다. long long으로 표현 가능한 정수는 넘어버린다. (이렇게까지는 아니지만...)

그래서 해결법
1. cnt에 unsigend long long 해주기. (그냥 unsigend 붙어서 더 큰 정수 표현가능하게 가능)
2. for문 안에 if (cnt > M) break; 해주기. (미리 차단해주기.)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long> v; // 심사대에서 심사를 하는데 걸리는 시간.
int N, M;

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i ++) {
        int time;
        cin >> time;
        v.push_back(time);
    }

    sort(v.begin(), v.end());
    
    long long start = 1;
    long long end = v[N-1] * M; 
    long long result =v[N-1] * M;
    while(start <= end) {
        long long mid = (start + end) / 2;

        unsigned long long cnt = 0; // 심사받는 사람 수.
        for (int i = 0; i < N; i++) {
            //if (cnt > M) break;
            cnt += mid/v[i];
        }

        // 심사받는 사람 수가 더 많으면, 평균 시간을 단축.
        if (cnt >= M) {
            result = min(result,mid);
            end = mid - 1;
        }
        // 심사받는 사람 수가 더 작다면, 평균 시간을 늘림.
        else {
            start = mid + 1;
        }
    }
    
    cout << result << endl;
}