#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int a[20][1000000]; // Mảng Sparse Table
int n, m, ans = 0, ik, jk;

void init();
void getInput();
int solve(int ik, int jk);

void init() {
    int max_heigh = log2(n);
    for (int i = 1; i <= max_heigh; ++i) {
        for (int j = 0; j + (1 << i) - 1 < n; ++j) {
            a[i][j] = min(a[i-1][j], a[i-1][j + (1 << (i-1))]);
        }
    }
}
void print() {
    int max_heigh = log2(n);
    for (int i = 1; i <= max_heigh; ++i) {
        for (int j = 0; j + (1 << i) - 1 < n; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}
void getInput() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[0][i];
    }
    init();
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> ik >> jk;
        ans += solve(ik, jk);
    }
    cout << ans << endl;
}

int solve(int ik, int jk) {
    int heigh = int(log2(jk - ik + 1));
    int min_ik = a[heigh][ik];
    int min_jk = a[heigh][jk - (1 << heigh) + 1];
    return min(min_ik, min_jk);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    getInput();
    return 0;
}
