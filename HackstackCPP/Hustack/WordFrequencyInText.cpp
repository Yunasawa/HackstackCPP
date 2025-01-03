#if 0

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("C:\\Users\\yunas\\OneDrive\\Documents\\C Projects\\Trial Algorithm\\Hustack\\WordFrequencyInText.inp", "r", stdin);

    map<string, int> mp;

    size_t pos = 0;
    string input;
    string token;
    while (getline(cin, input))
    {
        if (input.empty()) break;
        input += " ";
        while (true)
        {
            if ((pos = input.find(" ")) != string::npos)
            {
                token = input.substr(0, pos);
                mp[token]++;
                input.erase(0, pos + 1);
            }
            else
            {
                break;
            }
        }
    }

    for (auto it = mp.begin(); it != mp.end() ; it++)
    {
        if (it->first != "")
        {
            cout << it->first << ' ' << it->second << endl;
        }
    }
    return 0;
}

#endif
