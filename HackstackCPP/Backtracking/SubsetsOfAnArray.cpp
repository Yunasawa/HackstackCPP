/*
Bài tập 2: Tìm các tập con của một mảng
Mô tả: Cho một mảng các số nguyên, bạn cần tìm tất cả các tập con của mảng.

Input: Một mảng số nguyên.
Output: In ra tất cả các tập con của mảng.

Test case 1: [1, 2]
Output: [[], [1], [2], [1, 2]]
Test case 2: [1, 2, 3]
Output: [[], [1], [2], [3], [1, 2], [1, 3], [2, 3], [1, 2, 3]]
*/

#if 0

#include <bits/stdc++.h>
#include "../Headers/MVector.h"

using namespace std;

vector<vector<int>> result;
vector<int> a;
vector<int> input = {1, 3, 5};

void Backtracking(int i)
{
    if (i > input.size() - 1)
    {
        result.push_back(a);
        return;
    }

    Backtracking(i + 1);

    a.push_back(input[i]);
    Backtracking(i + 1);
    a.pop_back();
}

int main()
{
    Backtracking(0);

    sort(result.begin(), result.end(), [](const vector<int>& a, const vector<int>& b)
    {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    });

    for (auto i : result)
    {
        for (auto j : i) cout << j << " ";
        cout << "\n";

    }

    return 0;
}
#endif
