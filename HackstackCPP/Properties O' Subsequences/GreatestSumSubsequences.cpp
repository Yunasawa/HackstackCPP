// 5. Kiểm tra dãy con liên tiếp có giá trị lớn nhất.
// Đề bài: Cho một dãy số nguyên, hãy kiểm tra dãy con liên tiếp có giá trị lớn nhất và trả về dãy con đó.
// Input: {1, 2, 3, 4, 5, 6, 3, 2, 1}
// Output: [1, 2, 3, 4, 5, 6] (Dãy con có giá trị lớn nhất là [1, 2, 3, 4, 5, 6])


#if 1

#include <iostream>
#include <vector>

using namespace std;


int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 3, 2, 1};

    int sum = 0;
    vector<int> set;
    vector<int> result;
    int value = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        cout << sum << endl;
        set.push_back(arr[i]);
        if (i = arr.size() - 1) break;
        else if (arr[i + 1] < arr[i])
        {
            if (sum > value)
            {
                result = set;
                value = sum;
            }
            sum = 0;
            set.clear();
        }
    }

    for (int i : result) cout << i << " ";

    return 0;
}

#endif
