#include <iostream>
#include <algorithm>


using namespace std;

int main() {
    int arr[] = {5, 2, 9, 1, 7, 6, 3};

    // 내림차순 정렬 (이거 에러남!)
    sort(arr, arr + 7, greater<int>());

    for (int i = 0; i < 7; i ++)
        {
            cout << ""
        }

    return 0;
}