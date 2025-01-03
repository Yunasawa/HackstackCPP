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
#define m1 11
#define mod 1000000007
#define ll long long
using namespace std;

bool big_small(int a, int b) {
    return a > b;
}

void get_input();
void solve();

int n, T, D;
int a[m3 + 1], t[m3 + 1];
int f[m3 + 1][102];
int res = 0;

void get_input() {
    cin >> n >> T >> D;
    for (int i = 1 ; i <= n ; ++i) {
        cin >> a[i];
    }
    for (int i = 1 ; i <= n ; ++i) {
        cin >> t[i];
    }
}

void solve() {

    for (int i = 1 ; i <= n ; ++i) {
        for (int j = t[i] ; j <= T ; ++j) {
            for (int k = max(0, i - D) ; k <= i - 1 ; ++k) {
                f[i][j] = max(f[i][j], f[k][j - t[i]] + a[i]);
            }
            res = max(res, f[i][j]);
        }
    }

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    get_input();
    solve();

    return 0;
}

#endif
