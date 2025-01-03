#ifndef REMOVE_DUPLICATES_H
#define REMOVE_DUPLICATES_H

#include <vector>
#include <unordered_set>

using namespace std;

// Template function to remove duplicates from a vector
template <typename T>
vector<T> RemoveDuplicates(const vector<T>& input)
{
    unordered_set<T> seen;
    vector<T> result;

    for (const auto& item : input)
    {
        if (seen.insert(item).second) result.push_back(item);
    }

    return result;
}

// Template function to print a vector
template <typename T>
void PrintVector(const vector<T>& vec)
{
    for (const auto& item : vec)
    {
        cout << item << endl;
    }
}

template <typename T>
bool VectorContains(const vector<T>& vec, const T& value)
{
    return find(vec.begin(), vec.end(), value) != vec.end();
}

#endif // REMOVE_DUPLICATES_H

