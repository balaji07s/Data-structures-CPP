/******************************************************************************

                            Two SUM yes (or) no
BF:
TC: O(n^2)
SC: O(1)
BS: 
TC: O(n log n)
SC: O(n)
OS:
TC: O(n log n)
SC: O(1) -> if sorting is quick sort
*******************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/* Brute force */
// bool twoSumYesOrNo (vector<int> &arr, int k)
// {
//     for (int i=0; i<arr.size(); i++)
//     {
//         for (int j=i+1; j<arr.size(); j++)
//         {
//             if ((arr[i] + arr[j]) == k)
//                 return true;
//         }
//     }
//     return false;
// }

/* Better solution */
// bool twoSumYesOrNo (vector<int> &arr, int k)
// {
//     int rem;
//     map<int, int> result;
//     for (int i=0; i<arr.size(); i++)
//     {
//         rem = k - arr[i];
//         if (result.find(rem) != result.end())
//         {
//             return true;
//         }
//         result[arr[i]] = i;
//     }
//     return false;
// }

/* Optimal */
bool twoSumYesOrNo (vector<int> &arr, int k)
{
    int i = 0, j = arr.size()-1;
    sort(arr.begin(), arr.end());
    while (i < j)
    {
        if ((arr[i] + arr[j]) < k)
        {
            i++;
        }
        else if ((arr[i] + arr[j]) > k)
        {
            j--;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {1, 2, 1, 0, 1, 1, 1, 4, 2, 3};
    int k;
    cin >> k;
    cout << twoSumYesOrNo (arr, k) << endl;

    return 0;
}