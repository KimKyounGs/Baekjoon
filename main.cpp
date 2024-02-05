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

int N, C;
vector <int> house;

int main() {
    cin >> N >> C;

    for (int i = 0; i < N; i ++) {
        int h;
        cin >> h;
        house.push_back(h);
    }

    // 좌표 정렬
    sort(house.begin(), house.end());

    int start = 1;
    int end = house[N-1] - house[0];
    int result = 0;
    while (start <= end) {
        int mid = (start + end) / 2; // 평균 거리.

        int cnt = 1; // 공유기 개수
        int preHouse = house[0];
        for (int i = 1; i < N; i ++) {
            if (house[i] - preHouse >= mid) {
                cnt ++;
                preHouse = house[i];
            }
        }
        // 공유기를 필요 이상 설치했으면 mid 값을 늘리기.
        if (cnt >= C) {
            result = max(mid,result);
            start = mid + 1;
        }
        // 공유기를 덜 설치 했으면 mid 값을 줄이기.
        else {
            end = mid - 1;
        }
    }

    cout << result << endl;
}

