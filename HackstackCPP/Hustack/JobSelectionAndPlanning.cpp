#if 0

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job
{
    int deadline;
    int profit;
};

bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

int jobScheduling(vector<Job>& jobs, int n)
{
    sort(jobs.begin(), jobs.end(), compare);

    int max_deadline = 0;
    for (int i = 0; i < n; ++i)
    {
        max_deadline = max(max_deadline, jobs[i].deadline);
    }

    vector<bool> slots(max_deadline + 1, false);
    int total_profit = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int t = jobs[i].deadline; t > 0; --t)
        {
            if (!slots[t])
            {
                slots[t] = true;
                total_profit += jobs[i].profit;
                break;
            }
        }
    }

    return total_profit;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    freopen("C:\\Users\\yunas\\OneDrive\\Documents\\C Projects\\Trial Algorithm\\Hustack\\JobSelectionAndPlanning.inp", "r", stdin);

    int n;
    cin >> n;

    vector<Job> jobs(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> jobs[i].deadline >> jobs[i].profit;
    }

    cout << jobScheduling(jobs, n) << endl;

    return 0;
}

#endif
