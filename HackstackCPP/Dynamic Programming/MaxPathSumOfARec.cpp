/*
Cho một bảng hình chữ nhật có kích thước n \times m với ô bắt đầu là ô góc trên bên trái có toạ độ (1, 1),
ô kết thúc là ô góc dưới bên phải có toạ độ (n, m). Trên mỗi ô của bảng có ghi một số nguyên dương là số điểm được
cộng thêm khi người chơi đi vào ô đó. Ban đầu, người chơi ở ô bắt đầu với số điểm là 0. Biết rằng, người chơi chỉ
có thể di chuyển sang phải hoặc đi xuống dưới. Hỏi số điểm tối đa mà người chơi có thể đạt được khi di chuyển từ
ô bắt đầu đến ô kết thúc là bao nhiêu?

Input:
Dòng 1: Hai số nguyên dương n, m thể hiện cho kích thước của bảng (n, m ≤ 103)
Dòng 2…n+1: Mỗi dòng gồm m số nguyên dương thể hiện cho giá trị các ô trong bảng. Giá trị một ô không vượt quá 109.

Output:
Một số nguyên duy nhất là kết quả của bài toán
*/

#if 0

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MaxN = 1 + 1e3;
int n, m, a[MaxN][MaxN];
ll dp[MaxN][MaxN];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("C:\\Users\\yunas\\OneDrive\\Documents\\C Projects\\Trial Algorithm\\Dynamic Programming\\MaxPathSumOfARec.inp", "r", stdin);

    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= m ; ++j) cin >> a[i][j];

    for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= m ; ++j) dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
    cout << dp[n][m] << endl;

    return 0;
}

#endif
