/*
Bài tập 6: Tìm tất cả các phân hoạch của một số
Mô tả: Cho một số nguyên dương n, bạn cần tìm tất cả các phân hoạch
của n (chia n thành các số nguyên dương sao cho tổng các số trong phân hoạch bằng n).

Input: Một số nguyên n.
Output: In ra tất cả các phân hoạch của n.

Test case 1: 4
Output: [[4], [3, 1], [2, 2], [2, 1, 1], [1, 1, 1, 1]]
Test case 2: 5
Output: [[5], [4, 1], [3, 2], [3, 1, 1], [2, 2, 1], [2, 1, 1, 1], [1, 1, 1, 1, 1]]
*/

#if 0

#include <bits/stdc++.h>

using namespace std;

int n = 4;
vector<int> current;
vector<vector<int>> output;

void partitionNumber(int n, int start)
{
    if (n == 0)
    {
        cout << "Accept: " << n << endl;
        output.push_back(current);
        return;
    }

    for (int i = start; i <= n; i++)
    {
        current.push_back(i);
        cout << "Push: " << i << " | " << n << endl;
        partitionNumber(n - i, i);
        current.pop_back();
        cout << "Pop: " << i << " | " << n << endl;
    }
}

int main()
{
    partitionNumber(n, 1);

    /*
    for (const auto& part : output)
    {
        for (const auto& num : part) cout << num << " ";
        cout << endl;
    }
    */

    return 0;
}

#endif
