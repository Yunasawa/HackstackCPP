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
#include <unordered_map>
#define m6 1000001
#define m5 100001
#define m4 10001
#define m3 1001
#define m2 101
#define m1 11
#define m42 20002
#define mod 1000000007
#define ll long long
#define INF INT_MAX
using namespace std;

bool big_small(int a, int b) {
    return a > b;
}
typedef pair<int, int> ii;


void get_input();
void solve();
void makeSet(int n);
int findSet(int x);
long long kruskal(int n);


int n, m;
typedef pair<int, ii> Edge;
int parent[m5], rank_[m5]; // Mảng lưu cha và bậc trong Union-Find
vector<Edge> edges; // Danh sách các cạnh (trọng số, (u, v))

// Hàm khởi tạo Union-Find
void makeSet(int n) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rank_[i] = 0;
    }
}

// Tìm gốc của tập chứa x
int findSet(int x) {
    if (x != parent[x]) {
        parent[x] = findSet(parent[x]); // Path compression
    }
    return parent[x];
}

// Hợp nhất hai tập chứa x và y
bool unionSet(int x, int y) {
    int rootX = findSet(x);
    int rootY = findSet(y);
    if (rootX != rootY) {
        if (rank_[rootX] > rank_[rootY]) {
            parent[rootY] = rootX;
        } else if (rank_[rootX] < rank_[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank_[rootX]++;
        }
        return true;
    }
    return false;
}

// Thuật toán Kruskal
long long kruskal(int n) {
    sort(edges.begin(), edges.end()); // Sắp xếp các cạnh theo trọng số
    makeSet(n); // Khởi tạo Union-Find
    long long mstWeight = 0; // Trọng số của cây khung nhỏ nhất
    int countEdges = 0;

    for (const auto& edge : edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (unionSet(u, v)) { // Nếu hợp nhất được u và v (không tạo chu trình)
            mstWeight += weight;
            countEdges++;
            if (countEdges == n - 1) break; // Đủ \( N-1 \) cạnh thì dừng
        }
    }
    return mstWeight;
}
void get_input() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
}


void solve() {
    cout << kruskal(n) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    get_input();
    solve();

    return 0;
}


#endif // 0
