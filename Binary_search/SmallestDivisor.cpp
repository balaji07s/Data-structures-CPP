/*******************************************************************************            
            Find the smallest divisor

BF:
TC: O(N^2) + N
SC: O(1);

OS:
TC: O(log N * N) + N
SC: O(1);
*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible (vector<int> &arr, int divisor, int T)
{
    int sum = 0;
    for (int i=0; i<arr.size(); i++)
    {
        sum += ceil(((float)arr[i]/(float)divisor));
        if (sum > T)
            return false;
    }
    return true;
}

/* Brute force solution using linear search */
int smallestDivisor (vector<int> &arr, int T)
{
    int max_ele = *max_element(arr.begin(), arr.end());
    for (int i=1; i<arr.size(); i++)
    {
        if (isPossible(arr, i, T) == true)
            return i;
    }
    return false;
}


/* Optimal solution using binary search */
int smallestDivisor(vector<int>& arr, int T) {
    int low = 1, high = *max_element(arr.begin(), arr.end());

    while (low <= high)
    {
        int mid = low + (high - low)/2;
        if (isPossible(arr, mid, T) == true)
        {
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return low;     
}

int main ()
{
    vector<int> arr = {1,2 ,3 ,4 ,5};
    int threshold;
    cin >> threshold;
    cout << smallestDivisor(arr, threshold);

    return 0;
}