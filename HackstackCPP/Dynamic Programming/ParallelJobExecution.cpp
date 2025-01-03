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
bool compare(int a, int b) {
    return a > b;
}

int n;
int arr[m6];

void get_input() {
   cin >> n;
   for (int i = 0 ; i < n ; ++i) {
        cin >> arr[i];
   }
   sort(arr, arr + n, compare);
}

void solve() {
    int end_time = 0, work_time = 0;
    for (int i = 0 ; i < n ; ++i) {
        if (end_time < arr[i] + work_time) {
            end_time = work_time + arr[i];
        }
    ++ work_time;
    }
    cout << end_time;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    get_input();
    solve();

    return 0;
}

#endif // 0
