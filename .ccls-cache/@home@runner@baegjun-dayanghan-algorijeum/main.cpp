/*
아이디어 :

어렵지 않게 풀었던 문제.
그래프를 다 채우고 마지막에 계산했는데, 더 좋은 방법이 있지 않을까 생각한다..

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
#include <climits>
#define INF 1e9
#define endl '\n'

using namespace std;

int N;
int graph[401][401];
vector<int> student[401];
vector<pair<pair<int, int>, pair<int, int>>> v;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool compare(pair<pair<int, int>, pair<int, int>> p1, pair<pair<int, int>, pair<int, int>> p2) {
    if (p1.first.first == p2.first.first) { // 좋아하는 사람 수가 같다면
        if (p1.first.second == p2.first.second) { // 빈 칸 개수가 같다면 
            if (p1.second.first == p2.second.first) { // x좌표가 같다면 
                return p1.second.second < p2.second.second; // y좌표 기준으로 오름차순
            }
            return p1.second.first < p2.second.first; // x좌표 기준으로 오름차순
        }
        return p1.first.second > p2.first.second; // 빈 칸 개수를 기준으로 내림차순
    }
    return p1.first.first > p2.first.first; // 좋아하는 사람 수를 기준으로 내림차순
}

void Fill(int n, int a, int b, int c, int d) {
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            if (graph[i][j] == 0) {
                int like = 0;
                int blank = 0;
                for (int k = 0; k < 4; k ++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx < 1 || ny < 1 || nx > N || ny > N) continue;

                    if (graph[nx][ny] == a || graph[nx][ny] == b || graph[nx][ny] == c || graph[nx][ny] == d) like ++;
                    
                    if (graph[nx][ny] == 0) blank ++;
                }

                v.push_back({{like,blank},{i,j}});
            } 
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N*N; i ++) {
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        student[i].push_back(n);
        student[i].push_back(a);
        student[i].push_back(b);
        student[i].push_back(c);
        student[i].push_back(d);
        
        Fill(n, a, b, c, d);
        sort(v.begin(), v.end(), compare);
        
        int x = v[0].second.first;
        int y = v[0].second.second;
        student[i].push_back(x);
        student[i].push_back(y);
        
        graph[x][y] = n;

        v.clear();
    }

    // for (int i = 1; i <= N; i ++) {
    //     for (int j = 1; j <= N; j ++) {
    //         cout << graph[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    int result = 0;
    for (int i = 0; i < N*N; i ++) {    
        int cnt = 0;

        int x = student[i][5];
        int y = student[i][6];

        for (int j = 0; j < 4; j ++) {
            int nx = x + dx[j];
            int ny = y + dy[j];

            if (nx < 1 || ny < 1 || nx > N || ny > N) continue;

            if (graph[nx][ny] == student[i][1] || graph[nx][ny] == student[i][2] || graph[nx][ny] == student[i][3] || graph[nx][ny] == student[i][4]) cnt ++;
        }

        if (cnt) result += pow(10, cnt-1);
    }

    cout << result << endl;
    return 0;
}
