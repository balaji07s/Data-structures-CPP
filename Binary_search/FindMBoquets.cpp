/*******************************************************************************            
            Find the min no.of.days to make m bouquets

BF:
TC: O(min - max) * N + N
SC: O(1);

OS:
TC: O(log N) * N + N
SC: O(1);
*******************************************************************************/

#include <iostream>
#include <vector>
#include <climits>
#include <utility>
using namespace std;

int findNoOfBouquets (int days, int k, vector<int> &arr)
{
    int count =0, ans = 0;
    for (int i=0; i<arr.size(); i++)
    {
        if (arr[i] <= days)
        {
            count++;
        }
        else
        {
            ans += count/k;
            count = 0;
        }
    }
    ans += count/k;
    return ans;
}

pair<int, int> findMinMax (vector<int> &arr)
{
    pair<int, int> minMax = {INT_MAX, INT_MIN};
    for (auto x : arr)
    {
        minMax.first = min(x, minMax.first);
        minMax.second = max(x, minMax.second);
    }
    return minMax;
}

/* Brute force using linear search */
#if 0
int minDaysToMakeMBouquets (vector<int> &arr, int m, int k)
{
    pair<int, int> minMax = findMinMax (arr);
    int min = minMax.first, max = minMax.second;
    for (int i=min; i<=max; i++)
    {
        int res = findNoOfBouquets(i, k, arr);
        if (res >= m)
        {
            return i;
        }
    }
}
#endif

/* Optimal solution using binary search */
int minDaysToMakeMBouquets (vector<int> &arr, int m, int k)
{
    pair<int, int> minMax = findMinMax(arr);
    int low = minMax.first, high = minMax.second;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if (findNoOfBouquets(mid, k, arr) >= m)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    cout << minDaysToMakeMBouquets(arr, 2, 3);


    return 0;
}
