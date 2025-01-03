#if 0

#include <iostream>
#include <vector>
using namespace std;

int W = 5;
vector<int> weight = {1, 2, 3, 4};
vector<int> profit = {1, 2, 3, 5};

int Knapsack(int W, int n)
{
    if (n == 0 || W == 0)  return 0;

    if (weight[n - 1] > W) return Knapsack(W, n - 1);

    return max(Knapsack(W, n - 1), profit[n - 1] + Knapsack(W - weight[n - 1], n - 1));
}

int main()
{
    cout << Knapsack(W, weight.size()) << endl;
    return 0;
}

#endif
