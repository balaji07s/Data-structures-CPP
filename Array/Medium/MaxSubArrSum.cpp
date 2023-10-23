/******************************************************************************

                                Maximum sub array sum
BF:
TC: O(n^3)
SC: O(1)
BS:
TC: O(n^2)
SC: O(1)
OS:
TC: O(n)
SC: O(1)
*******************************************************************************/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/* Brute force */
// long long maxSubArraySum (vector<int> &arr)
// {
//     long long sum, max = INT_MIN;
//     for (int i=0; i<arr.size(); i++)
//     {
//         for (int j=i; j<arr.size(); j++)
//         {
//             sum = 0;
//             for (int k=i; k<=j; k++)
//             {
//                 sum += arr[k];
//             }
//             if (sum > max)
//                 max = sum;
//         }
//     }
//     if (max < 0)
//         return 0;
    
//     return max;
// }

// /* Better solution */
// long long maxSubArraySum (vector<int> &arr)
// {
//     long long sum = 0, max = INT_MIN;
//     for (int i=0; i<arr.size(); i++)
//     {
//         sum = 0;
//         for (int j=i; j<arr.size(); j++)
//         {
//             sum += arr[j];
//             if (sum > max)
//                 max = sum;
//         }
//     }
//     if (max < 0)
//         return 0;
    
//     return max;
// }

/* Optimal solution 
Kadane's algorithm */
long long maxSubArraySum (vector<int> &arr)
{
    long long sum =0, max = INT_MIN;
    for (int i=0; i<arr.size(); i++)
    {
        sum += arr[i];
        if (sum > max)
             max = sum;
        if (sum < 0)
            sum = 0;
    }
    if (sum == 0)
        return 0;
    return max;
}

int main()
{
        // vector<int> arr = {2, -1, 2, -6, 4, -1, -2, 4, 2, -1, 4, 2, -4};
        vector<int> arr = {-1, -3, -5, -2 , -4};
        cout << maxSubArraySum(arr) << endl;

    return 0;
}