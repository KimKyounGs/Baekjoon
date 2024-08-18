#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#define INF 1e9

using namespace std;

int N;
vector<int> outcome[51]; 
int order[10]; // 타순
int result = 0;

void Hits(bool *base, int type, int *sum) {
    if (type == 1) {    
        if (base[2] == true) {
            (*sum) ++;
            base[2] = false;
        }
        if (base[1] == true) {
            base[2] = true;
            base[1] = false;
        }
        if (base[0] == true) {
            base[1] = true;
        }
        base[0] = true;
    }
    else if (type == 2) {
        if (base[2] == true) {
            (*sum) ++;
            base[2] = false;
        }
        if (base[1] == true) {
            (*sum) ++;
            base[2] = false;
        }
        if (base[0] == true) {
            base[2] = true;
            base[0] = false;
        }
        base[1] = true;
    }
    else if (type == 3) {
        if (base[2] == true) {
            (*sum) ++;
            base[2] = false;
        }
        if (base[1] == true) {
            (*sum) ++;
            base[1] = false;
        }
        if (base[0] == true) {
            (*sum) ++;
            base[0] = false;
        }
        base[2] = true;
    }
    else if (type == 4) {
        if (base[2] == true) {
            (*sum) ++;
            base[2] = false;
        }
        if (base[1] == true) {
            (*sum) ++;
            base[1] = false;
        }
        if (base[0] == true) {
            (*sum) ++;
            base[0] = false;
        }
        (*sum) ++;
    }
}

void Play() {
    int sum = 0; // 점수
    int recent = 1; // 주자 순서
    for (int i = 0; i < N; i ++) {
        int out = 0; // 아웃 카운트
        bool base[3] = {0,};
        while(out != 3) {
            if (outcome[i][order[recent]-1] == 0) out ++;
            else if (outcome[i][order[recent]-1] == 1) { // 안타
                Hits(base, 1, &sum);
            }
            else if (outcome[i][order[recent]-1] == 2) { // 2루타
                Hits(base, 2, &sum);
            }
            else if (outcome[i][order[recent]-1] == 3) { // 3루타
                Hits(base, 3, &sum);
            }
            else if (outcome[i][order[recent]-1] == 4) { // 홈런
                Hits(base, 4, &sum);
            } 
            recent ++;
            if (recent == 10) recent = 1;
        }
    }

    result = max(result, sum);
}

void Permutation() {
    vector<int> v;
    for (int i = 2; i <= 9; i ++) {
        v.push_back(i);
    }

    do {
        order[4] = 1;
        int cnt = 1;
        for (int i = 0; i < 8; ++i) {
            order[cnt] = v[i];
            cnt ++;
            if (cnt == 4) cnt ++; // 4번 타자는 1번으로 정해져 있음.
        }
        // for (int i = 1; i <= 9; i ++) {
        //     cout << order[i] << ' ';
        // }
        // cout << endl;
        Play();
    } while (next_permutation(v.begin(), v.end()));
}

void Solution() {
    Permutation();
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < 9; j ++) {
            int n;
            cin >> n;
            outcome[i].push_back({n});
        }
    }

    Solution();
    
    cout << result << '\n';
}