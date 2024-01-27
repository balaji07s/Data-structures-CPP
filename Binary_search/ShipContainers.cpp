/*******************************************************************************            
            capacity to ship containers with d days

BF:
TC: O((sum - max)) * N)
SC: O(1)

OS:
TC: O(log (sum - max) * N)
SC: O(1)
*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int isPossible (vector<int> &arr, int capacity, int days)
{
    int sum = 0, day = 1;
    for (int i=0; i<arr.size(); i++)
    {
        if ((sum + arr[i]) > capacity)
        {
            day++;
            sum = arr[i];
        }
        else {
            sum += arr[i];
        }
        if (day > days)
            return false;
    }

    return true;
}

/* Brute force using linear search */
int shipWithinDays(vector<int>& weights, int days) {
    int max_ele = *max_element(weights.begin(), weights.end()),
        sum = accumulate(weights.begin(), weights.end(), 0);
    for (int i=max_ele; i<=accumulate; i++)
    {
        if (isPossible(weights, mid, days))
            return i;
    }
    return -1;
}

/* Optimal solution using binary search */
int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end()), high = accumulate(weights.begin(), weights.end(), 0);
    while (low <= high)
    {
        int mid = low + (high - low)/2;
        // cout << "Day: " << mid << endl;
        if (isPossible (weights, mid, days) == true)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}


int main ()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days;
    cin >> days;
    cout << shipWithinDays(arr, days) << endl;
}