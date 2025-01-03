// Listing the set:
// List all the set of numbers from 1 to n, in dictionary order

#if 0

#include <bits/stdc++.h>

using namespace std;

int n = 3;
vector<vector<int>> result;
vector<int> a;

void Backtracking(int i)
{
    if (i > n)
    {
        if (a.size() != 0) result.push_back(a);
        return;
    }

    Backtracking(i + 1);

    a.push_back(i);
    Backtracking(i + 1);
    a.pop_back();
}

int main()
{
    Backtracking(1);
    sort(result.begin(), result.end());

    for (auto i : result)
    {
        for (auto j : i) cout << j << " ";
        cout << "\n";
    }

    return 0;
}
#endif
