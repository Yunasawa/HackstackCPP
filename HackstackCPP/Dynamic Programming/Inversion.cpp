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


void getInput();
void solve();

int n;
int arr[m6];
int temp[m6];

void getInput() {
    cin >> n;
    for (int i = 0 ; i < n ; ++i) {
        cin >> arr[i];
    }
}

int _merge(int left, int mid, int right) {
    int temp_it = left, it_left = left, it_right = mid + 1, ans = 0;
    while (it_left <= mid && it_right <= right) {
        if (arr[it_left] <= arr[it_right]) {
            temp[temp_it++] = arr[it_left++];
        } else {
            temp[temp_it++] = arr[it_right++];
            ans = (ans + (mid - it_left + 1)) % mod;
        }
    }

    while (it_left <= mid) temp[temp_it++] = arr[it_left++];
    while (it_right <= right) temp[temp_it++] = arr[it_right++];

    for (int i = left ; i <= right; ++i) {
        arr[i] = temp[i];
    }
    return ans;
}
int merge_sort(int left, int right) {
    int mid, ans = 0;

    if (right > left) {
        mid = (left + right) / 2;

        ans = (ans + merge_sort(left, mid) % mod) % mod;
        ans = (ans + merge_sort(mid + 1, right) % mod) % mod;
        ans = (ans + _merge(left, mid, right) % mod) % mod;
    }

    return ans;
}
void solve() {
    cout << merge_sort(0, n-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    getInput();
    solve();

    return 0;
}



#endif // 0
