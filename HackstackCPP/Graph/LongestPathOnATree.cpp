#if 0

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#include <stack>
#include <math.h>
#include <limits.h>
#include <cstring>
#include <map>
#define m6 1000001
#define m5 100001
#define m4 10001
#define m3 1001
#define m2 101
#define m1 11
#define mod 1000000007
#define ll long long
#define INF INT_MAX
using namespace std;

bool big_small(int a, int b) {
    return a > b;
}

typedef pair<int, int> ii;
void get_input();
void solve(int city);
ii bfs(int u);

int n;
vector<ii> tree[m5];    // {node, distance}

void get_input() {
    cin >> n;
    int u, v , w;
    for (int i = 0 ; i < n - 1; ++i) {
        cin >> u >> v >> w;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }
}

ii bfs (int u) {
    int max_dis = INT_MIN, farthest_node = u;

    vector<bool> visited(n + 1, false);
    vector<int> distance(n + 1, 0);

    queue<int> q;

    q.push(u);
    visited[u] = true;

    while(!q.empty()) {
        int current = q.front();
        q.pop();
        for (auto node: tree[current]) {
            if (!visited[node.first]) {
                q.push(node.first);
                visited[node.first] = true;
                distance[node.first] = distance[current] + node.second;

                if (max_dis < distance[node.first]) {
                    max_dis = distance[node.first];
                    farthest_node = node.first;
                }
            }
        }
    }
    return {max_dis, farthest_node};
}

void solve() {
    ii bfs1 = bfs(1);

    ii bfs2 = bfs(bfs1.second);

    cout << bfs2.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    get_input();
    solve();

    return 0;
}

/*
6
1 3 3
1 6 2
2 6 5
4 5 2
4 6 1
*/

#endif // 0
