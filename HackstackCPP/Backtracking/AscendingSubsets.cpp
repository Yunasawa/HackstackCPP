/*
Bài tập 5: Tìm tất cả các chuỗi con tăng dần
Mô tả: Cho một chuỗi các số nguyên, bạn cần tìm tất cả các chuỗi con tăng dần.

Input: Một mảng số nguyên.
Output: In ra tất cả các chuỗi con tăng dần.

Test case 1: [1, 2, 3]
Output: [[1], [2], [3], [1, 2], [1, 2, 3], [2, 3]]
Test case 2: [3, 2, 1]
Output: [[3], [2], [1]]
*/

#if 0

#include <bits/stdc++.h>

using namespace std;

vector<int> input = {1, 2, 3};
vector<vector<int>> output;
vector<int> subset;

void Backtracking(int i)
{
    if (subset.size() > 0)
    {
        output.push_back(subset);
    }

    if (subset.empty() || input[i] > subset.back())
        {
            subset.push_back(input[i]);
            if (i < input.size()) Backtracking(i + 1);
            subset.pop_back();
        }
}

int main()
{
    for (int i = 0; i < input.size(); i++)
    {
        Backtracking(i);
    }

    sort(output.begin(), output.end(), [](const vector<int>& a, const vector<int>& b)
    {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    });

    for (auto i : output)
    {
        for (auto j : i) cout << j << " ";
        cout << "\n";
    }

    return 0;
}

#endif
