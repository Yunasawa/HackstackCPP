#if 0

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestCommonSubsequence(string X, string Y, string &lcs)
{
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxLength = 0;

    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= m; i++)
        {
            if (X[i - 1] == Y[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

            if (maxLength < dp[i][j])
            {
                maxLength = dp[i][j];
                lcs += X[i - 1];
            }
        }
    }

    return dp[m][n];
}

int main()
{
    string X2 = "ABCBDAB";
    string Y2 = "BDCABB";
    string lcs2;
    cout << "LCS length of X2 and Y2: " << longestCommonSubsequence(X2, Y2, lcs2) << endl;
    cout << "LCS: " << lcs2 << endl;

    return 0;
}

#endif
