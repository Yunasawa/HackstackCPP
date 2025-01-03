// Bài toán biểu diễn số ở hệ nhị phân
// Một số tự nhiên khi biểu diễn trong hệ đếm nhị phân thì chỉ có 2 chữ số 0 và 1.
// Yêu cầu: Cho trước số n và số k .
// Hãy cho biết trong các số từ 1 đến n có bao nhiêu số mà khi biểu diễn trong hệ đếm 2 có đúng k chữ số 1.

#if 0

#include <bits/stdc++.h>

using namespace std;

int n, k, m, answer;

int countBits(int n)
{
    if (n == 0) return 1;
    return static_cast<int>(log2(n)) + 1;
}

void Backtracking(int i, int cnt1, int dec, string bitString)
{
    if (cnt1 > k) return;
    if (dec > n) return;

    if (i > m)
    {
        if (cnt1 == k && dec <= n)
        {
            cout << bitString << endl;
            answer++;
        }
        return;
    }

    Backtracking(i + 1, cnt1, dec * 2, bitString + "0");
    Backtracking(i + 1, cnt1 + 1, dec * 2 + 1, bitString + "1");
}

int main()
{
    n = 38;
    k = 2;

    m = countBits(n);

    Backtracking(1, 0, 0, "");

    cout << answer;

    return 0;
}
#endif
