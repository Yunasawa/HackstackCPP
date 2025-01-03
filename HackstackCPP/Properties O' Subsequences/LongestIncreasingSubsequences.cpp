// 2. Kiểm tra dãy con liên tiếp tăng dần dài nhất.
// Đề bài: Cho một dãy số nguyên. Hãy tìm độ dài của dãy con liên tiếp tăng dần dài nhất.
// Input: {1, 2, 3, 1, 2, 3, 4, 5, 6}
// Output: 6 (Dãy con tăng dần dài nhất: [1, 2, 3, 4, 5, 6])

#if 0

#include <iostream>
#include <vector>
using namespace std;

int countSubarraysWithSum(const vector<int>& arr)
{
    int n = arr.size();
    int count = 0;
    int maxCount = 0;

    for (int i = 0; i < n; i++)
    {
        count++;
        if (maxCount < count) maxCount = count;

        if (i == n - 1) return maxCount;
        else if (arr[i + 1] < arr[i]) count = 0;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 1, 3, 5, 7, 5, 6};

    int result = countSubarraysWithSum(arr);
    cout << result << endl;

    return 0;
}

#endif
