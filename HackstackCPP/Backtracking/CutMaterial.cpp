#if 0

#include <bits/stdc++.h>

using namespace std;

int H, W, n;
vector<pair<int, int>> subs;
vector<vector<bool>> grid;

bool canPlace(int h, int w, int x, int y)
{
    if (x + h > H || y + w > W) return false;

    for (int i = x; i < x + h; i++)
    {
        for (int j = y; j < y + w; j++)
        {
            if (grid[i][j]) return false;
        }
    }
    return true;
}

void place(int h, int w, int x, int y, bool value)
{
    for (int i = x; i < x + h; i++)
    {
        for (int j = y; j < y + w; j++)
        {
            grid[i][j] = value;
        }
    }
}

bool canCut(int index)
{
    if (index == subs.size()) return true;

    int h = subs[index].first;
    int w = subs[index].second;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (canPlace(h, w, i, j))
            {
                place(h, w, i, j, true);
                if (canCut(index + 1)) return true;
                place(h, w, i, j, false);
            }
            if (canPlace(w, h, i, j))
            {
                place(w, h, i, j, true);
                if (canCut(index + 1)) return true;
                place(w, h, i, j, false);
            }
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("C:\\Users\\yunas\\OneDrive\\Documents\\C Projects\\Trial Algorithm\\Backtracking\\CutMaterial.inp", "r", stdin);

    cin >> H >> W >> n;

    subs.resize(n);
    for (int i = 0; i < n; i++) cin >> subs[i].first >> subs[i].second;

    grid.assign(H, vector<bool>(W, false));

    cout << (canCut(0) ? 1 : 0) << endl;

    return 0;
}

#endif
