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

struct Job {
    int deadline;
    int profit;
};

// Hàm sắp xếp công việc theo lợi nhuận giảm dần
bool job_compare(Job a, Job b) {
    return a.profit > b.profit;
}

int n;
vector<Job> jobs;

void getInput() {
    cin >> n;
    int a, b;
    Job input;
    for (int i = 0 ; i < n ; ++i) {
        cin >> a >> b; // Nhập deadline và profit
        input.deadline = a;
        input.profit = b;
        jobs.push_back(input);
    }
}

void solve() {
    sort(jobs.begin(), jobs.end(), job_compare);

    int max_deadline = 0;
    for (int i = 0; i < n; ++i) {
        max_deadline = max(max_deadline, jobs[i].deadline);
    }

    vector<int> time_slots(max_deadline + 1, -1);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = jobs[i].deadline; j > 0; --j) {
            if (time_slots[j] == -1) {
                time_slots[j] = i;
                ans += jobs[i].profit;
                break;
            }
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


#endif
