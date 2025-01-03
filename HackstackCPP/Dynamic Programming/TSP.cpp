# if 0

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
int solve();
bool big_small(int a, int b) {
    return a > b;
}

vector<vector<int>> cost;
vector<vector<int>> dp;
int n;

void get_input() {
    cin >> n;
    cost.assign(n, vector<int>(n, 0));
    dp.assign(1 << n, vector<int>(n, -1));
    for (int i = 0 ; i < n ; ++i) {
        for (int j = 0 ; j < n ; ++j) {
            cin >> cost[i][j];
        }
    }
}

int solve(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        return cost[pos][0];
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;

    for (int i = 0 ; i < n ; ++i) {
        if (!(mask & (1 << i))) {
            int new_ans = cost[pos][i] + solve(mask | (1 << i), i);
            ans = min(new_ans, ans);
        }
    }

    dp[mask][pos] = ans;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    get_input();
    cout << solve(1, 0);

    return 0;
}


# endif // 0
