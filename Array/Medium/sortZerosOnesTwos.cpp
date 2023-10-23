/******************************************************************************

                    Sort array of 0s, 1s, and 2s
BF:
TC: O(n logn) 
SC: O(1)
BS:
TC: O(2n) 
SC: O(1)
OS:
TC: O(n)
SC: O(1)
*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Brute force */
// void sortZerosOnesTwos (vector<int> &arr)
// {
//     sort(arr.begin(), arr.end());
//     return;
// }

/* Better solution */
// void sortZerosOnesTwos (vector<int> &arr)
// {
//     int zeros = 0, ones = 0, twos = 0, i;
//     for (i=0; i<arr.size(); i++)
//     {
//         switch(arr[i])
//         {
//             case 0:
//                 zeros++;
//                 break;
//             case 1:
//                 ones++;
//                 break;
//             case 2:
//                 twos++;
//                 break;
//         }
//     }
//     i = 0;
//     while ((zeros > 0) || (ones > 0) || (twos > 0))
//     {
//         if (zeros > 0)
//         {
//             arr[i] = 0;
//             zeros--;
//         }
//         else if (ones > 0)
//         {
//             arr[i] = 1;
//             ones--;
//         }
//         else if (twos > 0)
//         {
//             arr[i] = 2;
//             twos--;
//         }
//         i++;
//     }
// }

/* Optimal approach 
dutch national flag algorithm */
void sortZerosOnesTwos (vector<int> &arr)
{
    int l=0, m=0, h=arr.size()-1;
    
    while (m <= h)
    {
        if (arr[m] == 0)
        {
            swap(arr[l], arr[m]);
            m++; l++;
        }
        else if (arr[m] == 1)
        {
            m++;
        }
        else if (arr[m] == 2)
        {
            swap(arr[m], arr[h]);
            h--;
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 2, 1, 2, 0, 0, 1, 1, 2, 1};
    sortZerosOnesTwos(arr);
    for (auto x : arr)
        cout << x << " ";

    return 0;
}