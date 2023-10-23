/******************************************************************************

                                Maximum sub array sum indices
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
pair<int, int> maxSubArraySum (vector<int> &arr)
{
    long long sum, max = INT_MIN;
    int ansStart = -1, ansEnd = -1;
    for (int i=0; i<arr.size(); i++)
    {
        for (int j=i; j<arr.size(); j++)
        {
            sum = 0;
            for (int k=i; k<=j; k++)
            {
                sum += arr[k];
            }
            if (sum > max)
            {
                max = sum;
                ansStart = i;
                ansEnd = j;
            }
        }
    }
    
    return make_pair(ansStart, ansEnd);
}

/* Better solution */
// pair<int, int> maxSubArraySum (vector<int> &arr)
// {
//     long long sum = 0, max = INT_MIN;
//     int ansStart = -1, ansEnd = -1;
//     for (int i=0; i<arr.size(); i++)
//     {
//         sum = 0;
//         for (int j=i; j<arr.size(); j++)
//         {
//             sum += arr[j];
//             if (sum > max)
//             {
//                 max = sum;
//                 ansEnd = j;
//                 ansStart = i;
//             }
//         }
//     }
    
//     return make_pair(ansStart, ansEnd);
// }

/* Optimal solution 
Kadane's algorithm */
// pair<int, int> maxSubArraySum (vector<int> &arr)
// {
//     long long sum =0, max = INT_MIN;
//     int start, ansStart = -1, ansEnd = -1;
//     for (int i=0; i<arr.size(); i++)
//     {
//         if (sum == 0)
//             start = i;
//         sum += arr[i];
//         if (sum > max)
//         {
//              max = sum;
//              ansStart = start;
//              ansEnd = i;
//         }
//         if (sum < 0)
//             sum = 0;
//     }
//     return make_pair(ansStart, ansEnd);
// }

int main()
{
        vector<int> arr = {2, -1, 2, -6, 4, -1, -2, 4, 2, -1, 4, 2, -4};
        // vector<int> arr = {-1, -3, -5, -2 , -4};
        pair<int, int> result = maxSubArraySum(arr);
        cout << result.first << " " << result.second << endl;

    return 0;
}