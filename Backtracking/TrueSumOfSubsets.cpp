/*
Bài tập 4: Tìm tất cả các cách chọn số từ mảng sao cho tổng bằng một giá trị cho trước
Mô tả: Cho một mảng các số nguyên và một giá trị mục tiêu.
Bạn cần tìm tất cả các cách chọn các số trong mảng sao cho tổng của chúng bằng giá trị mục tiêu.

Input: Một mảng số nguyên và một giá trị mục tiêu.
Output:  In ra tất cả các tập hợp con có tổng bằng giá trị mục tiêu.

Test case 1: Mảng [2, 3, 5] và mục tiêu 8
Output: [[3, 5]]
Test case 2: Mảng [1, 2, 3, 4, 5] và mục tiêu 5
Output: [[1, 4], [2, 3], [5]]
*/

#if 0

#include <bits/stdc++.h>
#include "../Headers/MVector.h"

using namespace std;

int sum, target = 5;
vector<int> input = {1, 2, 3, 4, 5};
vector<vector<int>> result;
vector<int> subset;

void Backtracking(int i)
{
    if (i >= input.size())
    {
        if (sum == target) result.push_back(subset);
        return;
    }

    Backtracking(i + 1);
    subset.push_back(input[i]);
    sum += input[i];
    Backtracking(i + 1);
    subset.pop_back();
    sum -= input[i];
}

int main()
{
    Backtracking(0);

    sort(result.begin(), result.end());

    for (auto i : result)
    {
        for (auto j : i) cout << j << " ";
        cout << "\n";

    }

    return 0;
}
#endif
