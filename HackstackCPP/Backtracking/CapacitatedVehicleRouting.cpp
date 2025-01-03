#if 1

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n, K, Q;
int d[13];
int c[13][13];

// Precompute chi phí TSP cho mỗi tập hợp khách hàng
int tspCost(int mask, int last, vector<vector<int>>& memo)
{
    if (mask == 0) return c[0][last];
    if (memo[mask][last] != -1) return memo[mask][last];

    int res = INF;
    for(int i = 1; i <= n; i++)
    {
        if(mask & (1 << (i-1)))
        {
            res = min(res, c[i][last] + tspCost(mask ^ (1 << (i-1)), i, memo));
        }
    }
    return memo[mask][last] = res;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("C:\\Users\\yunas\\OneDrive\\Documents\\C Projects\\Trial Algorithm\\Backtracking\\CapacitatedVehicleRouting.inp", "r", stdin);

    cin >> n >> K >> Q;

    for(int i=1;i<=n;i++) cin >> d[i];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cin >> c[i][j];
        }
    }

    // Precompute chi phí TSP cho tất cả các tập hợp khách hàng
    // Sử dụng memoization để lưu trữ kết quả
    // cost[S] là chi phí tối thiểu để phục vụ tập khách hàng S
    vector<int> cost(1 << n, INF);
    vector<vector<int>> memo(1 << n, vector<int>(n+1, -1));

    for(int mask=1; mask<(1<<n); mask++)
    {
        // Tính tổng yêu cầu của tập mask
        int total_demand = 0;
        for(int i=0;i<n;i++)
        {
            if(mask & (1<<i)) total_demand += d[i+1];
        }
        if(total_demand > Q) continue; // Không hợp lệ nếu vượt sức chứa

        // Tìm chi phí TSP tối thiểu cho tập mask
        int min_cost = INF;
        for(int last=1; last<=n; last++)
        {
            if(mask & (1 << (last-1)))
            {
                int current_cost = tspCost(mask ^ (1 << (last-1)), last, memo) + c[last][0];
                min_cost = min(min_cost, current_cost);
            }
        }
        cost[mask] = min_cost;
    }

    // Quy hoạch động để phân chia các tập hợp khách hàng thành K xe tải
    // dp[mask][k] là tổng chi phí nhỏ nhất để phục vụ các khách hàng trong mask bằng k xe tải
    vector<vector<int>> dp((1 << n), vector<int>(K+1, INF));
    dp[0][0] = 0; // Cơ sở: không có khách hàng nào được phục vụ bằng 0 xe tải có chi phí 0

    for(int mask=0; mask<(1<<n); mask++)
    {
        for(int k=0; k<K; k++) // Sử dụng từ 0 đến K-1 xe tải
        {
            if(dp[mask][k] == INF) continue;
            // Tìm tất cả các tập hợp S con của các khách hàng chưa được phục vụ
            int remaining = ((1<<n)-1) ^ mask;
            for(int sub=remaining; sub>0; sub=(sub-1) & remaining)
            {
                // Kiểm tra xem tập hợp sub có hợp lệ không (sum_d[sub] <= Q)
                if(cost[sub] == INF) continue; // Không hợp lệ
                // Cập nhật dp
                int new_mask = mask | sub;
                dp[new_mask][k+1] = min(dp[new_mask][k+1], dp[mask][k] + cost[sub]);
            }
        }
    }

    // Tìm kết quả tối thiểu với tất cả khách hàng được phục vụ và sử dụng <= K xe tải
    int final_mask = (1 << n) - 1;
    int answer = INF;
    for(int k=1; k<=K; k++)
    {
        answer = min(answer, dp[final_mask][k]);
    }

    cout << answer;

    return 0;
}

#endif
