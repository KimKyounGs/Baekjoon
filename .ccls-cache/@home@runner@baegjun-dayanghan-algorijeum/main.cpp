/*
아이디어 : 

0 1 2 3 4 5 6 7 8 9 10 11 12 ... 500000

1. 고장난 번호가 포함된 숫자는 0, 나머지는 1로 초기화 한다.
2. 1으로 시작해서 + - BFS를 시작한다. --> 변수가 생길 것 같은데 일단 진행.


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int N, M;
vector<int> v;
int graph[500001];

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i ++) {
        int n;
        cin >> n;
        v.push_back(n);
    }

    memset(graph, 1, sizeof(graph));
    
    for (int i = 0; i <= 500000; i ++) {
        int temp = i;
        while(i > 0) {
            for (int j = 0; j < M; j ++) {
                if (temp % 10 == v[i]) {
                    graph[i] = 0;
                    break;
                }
            }
        }
    }

    for (int i = 0;)
}
