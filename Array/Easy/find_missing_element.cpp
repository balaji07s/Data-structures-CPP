/******************************************************************************

                            Find the missing number in a sorted array
BRUTE FORCE:
TC: O(n2)
SC: O(1)
BETTER:
TC: O(2n)
SC: O(n)
OPTIMAL:
TC: O(n)
SC: O(1)
*******************************************************************************/

#include <iostream>

using namespace std;

/* Brute force */
int findMissingNumber (int arr[], int n)
{
    bool flag = false;
    for (int i=1; i<=arr[n-1]; i++)
    {
        flag = false;
        for (int j=0; j<n; j++)
        {
            if (arr[j] == i)
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
            return i;
    }
    return -1;
}


/* better */
// int findMissingNumber (int arr[], int n)
// {
//     int hash[arr[n-1] + 1] = {};
//     for (int i=0; i<n; i++)
//     {
//         hash[arr[i]]++;
//     }
    
//     for (int i=1; i<= arr[n-1]; i++)
//     {
//         if (hash[i] == 0)
//             return i;
//     }
//     return -1;
// }

/* Optimal */
// void findMissingNumber (int arr[], int n)
// {
//     int res = 0,
//         xorsum = 0;
//     for (int i=0; i<=n; i++)
//     {
//         xorsum = xorsum ^ (i + 1);
//         if (i < n)
//         res = res ^ arr[i];
//     }
        // return xorsum * res;
// }


int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 9, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << findMissingNumber (arr, n) << endl;

    return 0;
}