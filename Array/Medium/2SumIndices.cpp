/******************************************************************************

                            Two SUM indices
BF:
TC: O(n^2)
SC: O(1)
OS:
TC: O(n log n)
SC: O(n)
*******************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/* Brute force */
// pair<int, int> twoSumYesOrNo (vector<int> &arr, int k)
// {
//     pair<int, int> output;
//     for (int i=0; i<arr.size(); i++)
//     {
//         for (int j=i+1; j<arr.size(); j++)
//         {
//             if ((arr[i] + arr[j]) == k)
//                 return make_pair(i, j);
//         }
//     }
//     return make_pair(-1, -1);
// }

/* Optimal */
pair<int, int> twoSumYesOrNo (vector<int> &arr, int k)
{
    int rem;
    map<int, int> result;
    pair<int, int> output = {-1, -1};
    for (int i=0; i<arr.size(); i++)
    {
        rem = k - arr[i];
        if (result.find(rem) != result.end())
        {
            output.first = result[rem];
            output.second = i;
            return output;
        }
        result[arr[i]] = i;
    }
    return output;
}

int main()
{
    vector<int> arr = {1, 2, 1, 0, 1, 1, 1, 4, 2, 3};
    int k;
    cin >> k;
    pair<int, int> result;
    result = twoSumYesOrNo (arr, k);
    cout << result.first << " " << result.second << endl;

    return 0;
}