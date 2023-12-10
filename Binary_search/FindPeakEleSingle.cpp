/******************************************************************************
 * 
 *                      Find peak element in an array (only single peak element in the array)
 * 
 * Brute force:
 * TC: O(n)
 * SC: O(1)
 * Optimal solution:
 * TC: O(log n)
 * SC: O(1)
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;


/*
Brute force approach
*/
int findPeak (vector<int> &arr)
{
    int h = arr.size()-1;
    if (arr.size() == 1 || arr[0] > arr[1])
    {
        return 0;
    }
    else if (arr[h] > arr[h-1])
    {
        return h;
    }
    else
    {
        for (int i=1; i<arr.size()-1; i++)
        {
            if (arr[i] > arr[i-1] && arr[i] > arr[i+1])
            {
                return i;
            }
        }
    }
    return -1;
}

/*
Optimised force approach
*/
// int findPeak (vector<int> &arr)
// {
//     int l = 0,
//         h = arr.size()-1;
    
//     if (arr.size() == 1 || arr[0] > arr[1])
//     {
//         return 0;
//     }
//     else if (arr[h] > arr[h-1])
//     {
//         return h;
//     }
//     else
//     {
//         l++;
//         h--;
//         while (l <= h)
//         {
//             int m = l + (h - l) / 2;
//             if (arr[m-1] < arr[m] && arr[m] > arr[m+1])
//             {
//                 return m;
//             }
//             else if (arr[m-1] > arr[m])
//             {
//                 h = m - 1;
//             }
//             else
//             {
//                 l = m + 1;
//             }
//         }
//     }

//     return -1;
// }


int main()
{
    
    vector<int> arr = {1, 2, 6, 3, 2, 1, 0};
    // vector<int> arr = {0, 1, 3, 4, 5, 6, 7, 10, 7, 6};
    cout << findPeak(arr) << endl;

    return 0;
}