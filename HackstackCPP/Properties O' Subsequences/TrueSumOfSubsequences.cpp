// 1. Đếm số dãy con liên tiếp có tổng bằng một giá trị cho trước.
// Đề bài: Cho một dãy số nguyên và một số nguyên S. Hãy đếm số dãy con liên tiếp có tổng bằng S.
// Input: {1, 2, 3, 4, 5}, S = 5
// Output: 2 (Dãy con có tổng bằng 5: [2, 3], [5])

#if 0

#include <iostream>
#include <vector>
using namespace std;

int CountSubarraysWithSum(const vector<int>& arr, int S)
{
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; ++i)
    {
        int sum = 0;
        for (int j = i; j < n; ++j)
        {
            sum += arr[j];
            if (sum == S) count++;
        }
    }
    return count;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int S = 9;

    int result = CountSubarraysWithSum(arr, S);
    cout << result << endl;

    return 0;
}

#endif
