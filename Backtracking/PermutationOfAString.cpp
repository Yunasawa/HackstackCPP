/*
Tìm tất cả các hoán vị của một chuỗi
Mô tả: Cho một chuỗi ký tự, bạn cần tìm tất cả các hoán vị của chuỗi đó.

Input: Một chuỗi ký tự gồm các ký tự chữ cái (có thể có ký tự trùng lặp).
Output: In ra tất cả các hoán vị của chuỗi đó.

Test case 1: "AB"
Output: ["AB", "BA"]
Test case 2: "AAB"
Output: ["AAB", "ABA", "BAA"]
*/

#if 0

#include <bits/stdc++.h>
#include "../Headers/MVector.h"

using namespace std;

vector<string> result;

void Backtracking(string& s, int i)
{
    if (i == s.length() - 1)
    {
        //cout << s << "\n";
        if (!VectorContains(result, s)) result.push_back(s);
        return;
    }

    for (int j = i; j < s.length(); j++)
    {
        swap(s[i], s[j]);
        Backtracking(s, i + 1);
        swap(s[i], s[j]);
    }
}

int main()
{
    string s = "ABCD";

    Backtracking(s, 0);

    sort(result.begin(), result.end());

    PrintVector(result);

    return 0;
}

#endif
