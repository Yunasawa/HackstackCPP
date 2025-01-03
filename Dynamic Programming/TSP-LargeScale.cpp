#if 0

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, dist[1000][1000];
vector<int> path;

int tsp(int mask, int pos, vector<vector<int>>& dp, vector<vector<int>>& parent) {
    if (mask == ((1 << n) - 1)) return dist[pos][0];
    if (dp[mask][pos] != -1) return dp[mask][pos];

    int ans = INF;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city, dp, parent);
            if (newAns < ans) {
                ans = newAns;
                parent[mask][pos] = city;
            }
        }
    }
    return dp[mask][pos] = ans;
}

void findPath(int mask, int pos, vector<vector<int>>& parent) {
    path.push_back(pos);
    if (mask == ((1 << n) - 1)) return;
    int nextCity = parent[mask][pos];
    findPath(mask | (1 << nextCity), nextCity, parent);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("C:\\Users\\yunas\\OneDrive\\Documents\\C Projects\\Trial Algorithm\\Dynamic Programming\\TSP-LargeScale.inp", "r", stdin);

int n;
    cin >> n;

    // Distance matrix
    vector<vector<int>> dist(n, vector<int>(n));

    // Read the distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    // Greedy algorithm to find a tour
    vector<bool> visited(n, false);
    vector<int> tour;

    int currentCity = 0; // start from city 0
    visited[currentCity] = true;
    tour.push_back(currentCity + 1); // store the 1-indexed city

    // Find the nearest neighbor for each step
    for (int i = 1; i < n; i++) {
        int nextCity = -1;
        int minDist = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[currentCity][j] < minDist) {
                nextCity = j;
                minDist = dist[currentCity][j];
            }
        }

        visited[nextCity] = true;
        tour.push_back(nextCity + 1); // store the 1-indexed city
        currentCity = nextCity;
    }

    // Output the result
    cout << n << endl;
    for (int city : tour) {
        cout << city << " ";
    }
    cout << endl;

    return 0;
}

#endif // 1
