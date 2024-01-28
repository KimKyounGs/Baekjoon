/*
아이디어 :

벡터에서 erase을 사용해서 충분한 양분을 흡수 못한 나무를 없애려고 했지만 out of bound 떴다.
이유는 v.size()로 나무를 저장해둔 인덱스를 접근하는데 도중에 사이즈를 줄여버리면 문제가 발생한다.
쫌 복잡하다.
그래서 temp벡터로 충분한 양분을 얻은 나무를 넣어주고 다시 v벡터로 넣어줌.

시간은 N이 10이여서 아무리 lenㅇ

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

int N, M, K;
int graph[11][11]; // 현재 양분
int food[11][11]; // 겨울 때 주어지는 양분
vector<int> v[11][11]; // 나무 나이
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// 여름이랑 합침.
void Spring() {
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            int sum = 0;
            int len = v[i][j].size();
            vector<int> temp;
            
            sort(v[i][j].begin(), v[i][j].end());
            for (int k = 0; k < len; k ++) {
                if (v[i][j][k] <= graph[i][j]) {
                    graph[i][j] -= v[i][j][k];
                    temp.push_back(v[i][j][k] + 1);
                }
                else {
                    sum += v[i][j][k] / 2;
                }
            }
            v[i][j].clear();
            for (int k = 0; k < temp.size(); k ++) {
                v[i][j].push_back(temp[k]);
            }
            if (sum) {
                graph[i][j] += sum;
            }
        }
    }
}

void Autumn() {
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            int len = v[i][j].size();
            for (int k = 0; k < len; k ++) {
                if (v[i][j][k] % 5 == 0) {
                    for (int z = 0; z < 8; z ++) {
                        int nx = i + dx[z];
                        int ny = j + dy[z];

                        if (nx < 1 || nx > N || ny < 1 || ny > N) continue;

                        v[nx][ny].push_back(1);
                    }
                }
            }
        }
    }
}

void Winter() {
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            graph[i][j] += food[i][j];
        }
    }
}


int main()
{
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            cin >> food[i][j];
            graph[i][j] = 5;
        }
    }

    for (int i = 0; i < M; i ++) {
        int x, y, z;
        cin >> x >> y >> z;

        v[x][y].push_back(z);
    }

    while(K--) {
        Spring();
        Autumn();
        Winter();
    }
    
    int result = 0;
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {    
            result += v[i][j].size();
        }
    }

    cout << result << endl;
}


