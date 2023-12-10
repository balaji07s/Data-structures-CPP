/******************************************************************************

                    Merge overlapping intervals

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Brute force */
// vector<vector<int>> mergeOverlapIntervals (vector<vector<int>> &arr)
// {
//     int start, end;
//     vector<vector<int>> res;
//     cout << "Array size " << arr.size() << endl;
//     sort(arr.begin(), arr.end());
//     for (int i=0; i<arr.size(); i++)
//     {
//         start = arr[i][0];
//         end = arr[i][1];
//                         cout << "Happy" << endl;
//         if (!res.empty() && start < res.back()[1])
//             continue;
//         for (int j=i+1; j<arr.size(); j++)
//         {
//             if (arr[j][0] <= end)
//             {
//                 cout << "Happy" << endl;
//                 end = max(arr[j][1], end);
//             }
//             else
//             {
//                 break;
//             }
//         }
//         res.push_back({start, end});
//     }
//     return res;
// }

/* Optimal solution */
// vector<vector<int>> mergeOverlapIntervals (vector<vector<int>> &arr)
// {
//     int start, end;
//     vector<vector<int>> res;
//     sort (arr.begin(), arr.end());
//     start = arr[0][0];
//     end = arr[0][1];
//     for (int i=1; i<arr.size(); i++)
//     {
//         if (arr[i][0] <= end)
//         {
//             end = max(arr[i][1], end);
//         }
//         else
//         {
//             res.push_back({start, end});
//             start = arr[i][0];
//             end = arr[i][1];
//         }
//     }
//     res.push_back({start, end});
//     return res;
// }

/* without additional variables */
vector<vector<int>> mergeOverlapIntervals (vector<vector<int>> &arr)
{
    vector<vector<int>> res;
    sort (arr.begin(), arr.end());
    
    for (int i=0; i<arr.size(); i++)
    {
        if (res.empty() || arr[i][0] > res.back()[1])
        {
            res.push_back(arr[i]);
        }
        else
        {
            res.back()[1] = max (arr[i][1], res.back()[1]);
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> arr = {{1, 3},
                                {2, 4},
                                {3, 5},
                                {6, 7},
                                {11, 13},
                                {12, 15},
                                {14, 17}};
    
    vector<vector<int>> res = mergeOverlapIntervals(arr);
    for (auto v1 : res)
    {
        for (auto x : v1)
        {
            cout << x << ", ";
        }
        cout << endl;
    }

    return 0;
}