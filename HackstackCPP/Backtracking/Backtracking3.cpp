// Bài toán biểu thức
// Cho xâu S (chỉ gồm các ký tự ‘0′ đến ‘9′, độ dài nhỏ hơn 10) và số nguyên M.
// Yêu cầu: Không thay đổi thứ tự của các ký tự trong xâu S.
// Hãy đếm số cách lấy ra một số ký tự trong xâu S và chèn vào trước nó các dấu ‘+′ hoặc ‘−‘ để thu được số M cho trước?

#if 0

#include <bits/stdc++.h>

using namespace std;

string s;
int n, m, answer;

void Backtracking(int i, int sum)
{
    if (i == n)
    {
        if (sum == m) ++answer;
        return;
    }

    Backtracking(i + 1, sum + (s[i] - 48));
    Backtracking(i + 1, sum - (s[i] - 48));
    Backtracking(i + 1, sum);
}

int main()
{
    s = "1234";
    m = 6;

    n = s.length();

    Backtracking(0, 0);

    cout << answer;

    return 0;
}
#endif
