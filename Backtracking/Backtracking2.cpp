// Phân tích một số tổng các số
// Cho số nguyên dương n (n≤50). Liệt kê tất cả các cách phân tích n thành tổng các số nguyên nhỏ hơn n, theo thứ tự từ điển.

#if 0

#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> result;
vector<int> a;

void Backtracking(int s)
{
    if (s == n)
    {
        result.push_back(a);
        return;
    }

    int i;
    if (a.size() == 0) i = 1;
    else i = a.back();

    for (int j = i; j <= min(n - s, n - 1); j++)
    {
        a.push_back(j);
        Backtracking(s + j);
        a.pop_back();
    }
}

int main()
{
    n = 5;

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
