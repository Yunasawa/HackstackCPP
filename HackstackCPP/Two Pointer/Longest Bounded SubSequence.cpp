#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#define M 1000000
#define ll long long
using namespace std;

vector<int> arr_sum;
int n, q, ans = -1;

void getInput();
void solve();

void getInput() {
    cin >> n >> q;
    int num;
    for (int i = 0 ; i < n ; ++i) {
        cin >> num;
        if (i == 0) {
            arr_sum.push_back(num);
        } else {
            arr_sum.push_back(arr_sum[i-1] + num);
        }
    }
}

void solve() {
    int left = 0, right = 1;
    while (right < n) {
        if (arr_sum[right] - arr_sum[left] <= q) {
            ++ right;
        } else {
            ans = max(ans, right - left - 1);
            ++ left;
        }
    }
    cout << ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    getInput();
    solve();

    return 0;
}
