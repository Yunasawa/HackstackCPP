#if 0

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#include <math.h>
#include <limits.h>
#include <map>
#define m6 1000001
#define m5 100001
#define m3 1001
#define mod 1000000007
#define ll long long
using namespace std;

void get_input();
void solve();
bool check_dis(int dis);

int n, c, t;
int arr[m5];

void get_input() {
    cin >> n >> c;
    for (int i = 0 ; i < n ; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
}

bool check_dis(int dis) {
    int _count = 1;
    int i = 0, j = 1;
    while (i < n) {
        while (j < n && (arr[j] - arr[i]) < dis) ++j;
        if (j < n) ++ _count;
        i = j;
        if (_count >= c) return true;
        ++ j;
    }
    return false;
}
void solve() {
    int mid, left = 0, right = arr[n-1] - arr[0], ans = 0;
    while (left <= right) {
        mid = (right + left) / 2;
        if (check_dis(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for (int i = 0 ; i < t ; ++i) {
        get_input();
        solve();
    }

    return 0;
}


#endif // 0
