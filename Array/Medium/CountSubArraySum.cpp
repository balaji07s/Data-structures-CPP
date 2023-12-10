/******************************************************************************

                Count subarray sum equals k
BF:
TC: O(n^3)
SC: O(1)
BS:
TC: O(n^2)
SC: O(1)
OS:
TC: O(n logn) -> map
TC: O(n) -> unordered map with best or average case
TC: O(n2) -> unordered map with worst case
SC: O(n)
*******************************************************************************/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

/* Brute force */
// int countSubArraySum (vector<int> arr, int k)
// {
//     int count = 0, sum = 0, n = arr.size();
//     for (int i=0; i<n; i++)
//     {
//         for (int j=i; j<n; j++)
//         {
//             sum = 0;
//             for (int k=i; k<=j; k++)
//             {
//                 sum += arr[k];
//             }
//             if (sum == k)
//                 count++;
//         }
//     }
//     return count;
// }



/* Better solution */
// int countSubArraySum (vector<int> arr, int k)
// {
//     int count = 0, sum = 0, n = arr.size();
//     for (int i=0; i<n; i++)
//     {
//         sum = 0;
//         for (int j=i; j<n; j++)
//         {
//             sum += arr[j];
//             if (sum == k)
//                 count++;
//         }
//     }
//     return count;
// }

/* Optimal solution */
int countSubArraySum (vector<int> arr, int k)
{
    unordered_map<long long, int> m;
    int count = 0;
    long long sum = 0;
    int n = arr.size();
    
    m[0] = 1;
    for (int i=0; i<n; i++)
    {
        sum += arr[i];
        if ((m.find((sum - k)) != m.end()))
        {
            count += m[sum-k];
        }
        m[sum]++;
    }
    
    for (auto x : m)
        cout << x.first << " " << x.second << endl;
    return count;
}

int main()
{
    vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int k;
    cin >> k;
    cout << countSubArraySum (arr, k) << endl;

    return 0;
}