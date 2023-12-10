/******************************************************************************

            Find the longest consecutive sequence
BF:
TC: 
SC: 
BS:
TC: 
SC: 
OS:
TC: 
SC: 
*******************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

/* brute force */
// bool linearSearch(vector<int> &arr, int temp)
// {
//     for (int i=0; i<arr.size(); i++)
//     {
//         if (arr[i] == temp)
//         {
//             return true;
//         }
//     }
//     return false;
// }

// int longestConsecutiveSeq (vector<int> &arr)
// {
//     int longestCnt = 1, currCnt = 1, temp;
//     for (int i=0; i<arr.size(); i++)
//     {
//         currCnt = 1;
//         temp = arr[i]+1;
//         while (linearSearch(arr, temp))
//         {
//             currCnt++;
//             temp = temp+1;
//         }
//         if (currCnt > longestCnt)
//             longestCnt = currCnt;
//     }
//     return longestCnt;
// }

/* Better solution */
// int longestConsecutiveSeq (vector<int> &arr)
// {
//     int longestCnt = 1, currCnt = 1, minVal;
//     sort (arr.begin(), arr.end());
//     minVal = arr[0];
//     for (int i=1; i<arr.size(); i++)
//     {
//         if (arr[i]-1 == minVal)
//         {
//             currCnt++;
//         }
//         else if (arr[i] != minVal)
//         {
//             currCnt = 1;
//         }
//         if(currCnt > longestCnt)
//         {
//             longestCnt = currCnt;
//         }
//         minVal = arr[i];
//     }
//     return longestCnt;
// }

/* Optimal solution */
int longestConsecutiveSeq (vector<int> &arr)
{
    if (arr.size() == 0)
        return 0;
    unordered_set<int> s;
    int currCnt = 1, longestCnt = 1, temp;
    
    for (auto x : arr)
    {
        s.insert(x);
    }
    
    for (auto x : s)
    {
        if (s.find(x-1) == s.end())
        {
            currCnt = 1;
            temp = x + 1;
            while (s.find(temp) != s.end())
            {
                temp = temp + 1;
                currCnt++;
            }
            longestCnt = max(currCnt, longestCnt);
        }
    }
    return longestCnt;
}

int main()
{
    vector<int> arr = {102, 4, 100, 1, 2, 101, 101, 5, 3, 2, 2, 1, 1};
                    /* 1, 1, 1, 2, 2, 2, 3, 3, 4, 100, 101, 101, 102 */
    cout << longestConsecutiveSeq(arr) << endl;
    
    return 0;
}