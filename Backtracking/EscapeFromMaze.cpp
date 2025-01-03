/*
Bài tập 3: Tìm đường đi trong ma trận (Maze Solver)
Mô tả: Cho một ma trận 2D biểu thị một mê cung.
Bạn cần tìm một đường đi từ ô (0, 0) đến ô (m-1, n-1), nơi m là số dòng và n là số cột của ma trận.
Các ô có giá trị "1" là tường, các ô có giá trị "0" là đường đi. Bạn có thể di chuyển lên, xuống, trái, phải.

Input: Một ma trận 2D chứa các giá trị 0 và 1.
Output: In ra "Yes" nếu có thể tìm được đường đi từ (0, 0) đến (m-1, n-1), ngược lại in "No".

Test case 1:
1 0 1
0 0 1
1 0 0
Output: "Yes"
Test case 2:
1 1 1
1 1 1
1 1 1
Output: "No"
*/

#if 0

#include <bits/stdc++.h>
#include "../Headers/MVector.h"

using namespace std;

int rowDirs[] = {-1, 1, 0, 0};
int colDirs[] = {0, 0, -1, 1};

bool IsValid(int x, int y, int m, int n, vector<vector<int>>& maze, vector<vector<bool>>& visited)
{
    return (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0 && !visited[x][y]);
}

bool SolveMaze(int x, int y, int m, int n, vector<vector<int>>& maze, vector<vector<bool>>& visited)
{
    if (x == m - 1 && y == n - 1) return true;

    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int newX = x + rowDirs[i];
        int newY = y + colDirs[i];

        if (IsValid(newX, newY, m, n, maze, visited))
        {
            if (SolveMaze(newX, newY, m, n, maze, visited)) return true;
        }
    }

    visited[x][y] = false;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("C:\\Users\\yunas\\OneDrive\\Documents\\C Projects\\Trial Algorithm\\Backtracking\\EscapeFromMaze.inp", "r", stdin);

    int m, n;
    cin >> m >> n;
    vector<vector<int>> maze(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++) cin >> maze[i][j];
    }

    vector<vector<bool>> visited(m, vector<bool>(n, false));

    if (SolveMaze(0, 0, m, n, maze, visited)) cout << "Yes";
    else cout << "No";

    return 0;
}
#endif
