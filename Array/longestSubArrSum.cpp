/******************************************************************************

                    Longest subarray with sum k

*******************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/* Brute force 1 */
// int longestSubArrSum (vector<int> v1, int k)
// {
//     long long sum =0;
//     int maxlen = 0;
//     for (int i=0; i<n; i++)
//     {
//         for (int j=i; j<v1.size(); j++)
//         {
//             sum = 0;
//             for (int k=i; k<=j; k++)
//             {
//                 sum += v1[k];
//             }
//             if ((sum == k) && ((j - i +1) > maxlen))
//             {
//                 maxlen = j-i+1;
//             }
//         }
//     }
//     return maxlen;
// }

/* Brute force 2 */
// int longestSubArrSum (vector<int> v1, int k)
// {
//     long long sum =0;
//     int maxlen = 0;
//     for (int i=0; i<n; i++)
//     {
//         sum = 0;
//         for (int j=i; j<v1.size(); j++)
//         {
//             sum += v1[j];
//             if ((sum == k) && ((j - i +1) > maxlen))
//             {
//                 maxlen = j-i+1;
//             }
//         }
//     }
//     return maxlen;
// }

/* Better */
// int longestSubArrSum (vector<int> v1, int k)
// {
//     long long sum = 0, rem;
//     int len = 0, maxlen = 0;
//     map<long long, int> preSumMap;
//     for (int i=0; i<v1.size(); i++) {
//         sum += v1[i];
//         if (sum == k)
//         {
//             maxlen = max(maxlen, i+1);
//         }
//         rem = sum - k;
//         if (preSumMap.find(rem) != preSumMap.end())
//         {
//             len = i - preSumMap[rem];
//             maxlen = max(maxlen, len);
//         }
//         if (preSumMap.find(sum) == preSumMap.end())
//         {
//             preSumMap[sum] = i;
//         }
//     }
//     return maxlen;
// }

/* Optimal solution */
int longestSubArrSum (vector<int> v1, int k)
{
    long long sum = 0;
    int maxLen = 0, i=0, j=0;
    
    while (i < v1.size() && i >= j)
    {
        sum += v1[i];
        while (sum > k)
        {
            sum -= v1[j];
            j++;
        }
        if (sum == k)
        {
            maxLen = i - j + 1;
        }
        i++;
    }
    return maxLen;
}

int main()
{
    vector<int> v1 = {1, 2, -1, 1, 0, 1, 1, 4, 2, 3};

    int res = longestSubArrSum(v1, 3);
    
    cout << res << endl;

    return 0;
}