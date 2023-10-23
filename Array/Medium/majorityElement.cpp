/******************************************************************************

                    Find majority element count (element count > n/2)
BF:
TC: O(n^2)
SC: O(1)
BS:
TC: O(n logn) + O(n)
SC: O(n)
OS:
TC: O(n)
SC: O(1)
*******************************************************************************/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

/* Brute force */
// int majorityElementCount (vector<int> &arr)
// {
//     cout << arr.size() << endl;
//     int count = 0;
//     for (int i=0; i<arr.size(); i++)
//     {
//         count = 0;
//         for (int j=i; j<arr.size(); j++)
//         {
//             if (arr[i] == arr[j])
//                 count++;
//         }
//         if (count > (arr.size()/2))
//             return arr[i];
//     }
//     return -1;
// }

/* Better solution */
// int majorityElementCount (vector<int> &arr)
// {
//     map<int, int> m;
//     for (int i=0; i<arr.size(); i++)
//     {
//         m[arr[i]]++;
//     }
//     for (auto x : m)
//     {
//         if (x.second > (arr.size()/2))
//             return x.first;
//     }
//     return -1;
// }

/* Optimal solution 
Boyer Moore's voting algorithm
*/
int majorityElementCount (vector<int> &arr)
{
    int count = 1, element = arr[0];
    for (int i=0; i<arr.size(); i++)
    {
        if (count == 0)
        {
            element = arr[i];
            count++;
        }
        else if (element == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    count++;
    for (int i=0; i<arr.size(); i++)
    {
        if (element == arr[i])
            count++;
    }
    if (count > (arr.size()/2))
        return element;
    return -1;
}

int main()
{
    vector<int> arr = {2, 1, 2, 2, 4, 4, 4, 4, 2, 1, 4, 2, 4};
    cout << majorityElementCount(arr) << endl;
    return 0;
}