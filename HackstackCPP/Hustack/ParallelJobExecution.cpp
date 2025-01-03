#if 0

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("ParallelJobExecution.inp", "r", stdin);

    // Input reading
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    // Sort the durations in ascending order
    sort(d.begin(), d.end());

    // Simulate the job execution
    int current_time = 0;  // The current time when the job can start
    int last_finish_time = 0;

    for (int i = 0; i < n; ++i) {
        current_time += d[i];  // Start the job and finish it at current_time + duration
        last_finish_time = current_time;  // Update the last finish time
    }

    // Output the minimal completion time
    cout << last_finish_time << endl;

    return 0;
}

#endif
