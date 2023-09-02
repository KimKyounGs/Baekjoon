#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> v;

int main() {
    cin >> N >> C;
    for (int i = 0; i < N; i ++) {
        int n;
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());

    int start = 0;
    int end = v[N-1] - v[0];

    int result = 0;
    while(start <= end) {
        int mid = (start + end) / 2;

        int cnt = 1;
        int preHouse = v[0];
        for (int i = 1; i < N; i ++) {
            if (v[i] - preHouse >= mid) {
                cnt ++;
                preHouse = v[i];
            }
        }

        if (cnt >= C) {
            start = mid + 1;
            result = max(result, mid);
        }
        else {
            end = mid - 1;
        }
    }

    cout << result << '\n';
    
    
}