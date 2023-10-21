/******************************************************************************

                    UNION OF ARRAYS
Brute force:
TC: O(n + n^2)
SC: O(n)
Better:
TC: O(2n + nlogn)
SC: O(n)
Optimal:
TC: O(n + m)
SC: O(n)
*******************************************************************************/


#include <iostream>
#include <vector>
#include <set>

using namespace std;


/* Brute force */
// vector<int> unionOfArrays (int arr1[], int arr2[], int n1, int n2)
// {
//     vector<int> resarr;
//     int n;
//     bool flag;
//     resarr.push_back(arr1[0]);
//     for (int i=1; i<n1; i++)
//     {
//         if (resarr[i-1] != arr1[i])
//             resarr.push_back(arr1[i]);
//     }
//     n = resarr.size();
//     for (int i=0; i<n2; i++)
//     {
//         flag = false;
//         for (int j=0; j<n; j++)
//         {
//             if (resarr[j] == arr2[i])
//             {
//                 flag = true;
//                 break;
//             }
//         }
//         if (flag == false)
//             resarr.push_back(arr2[i]);
//     }
//     return resarr;
// }

/* better */
// set<int> unionOfArrays (int arr1[], int arr2[], int n1, int n2)
// {
//     set<int> result;
    
//     for (int i=0; i<n1; i++)
//     {
//         result.insert(arr1[i]);
//     }
//     for (int i=0; i<n2; i++)
//     {
//         result.insert(arr2[i]);
//     }
//     return result;
// }

/* Optimal */
vector<int> unionOfArrays (int arr1[], int arr2[], int n1, int n2)
{
    int i = 0, j =0, k=0;
    vector<int> result;
    result.push_back(arr1[k++]);
    while ((i < n1) && (j < n2))
    {
        if (arr1[i] < arr2[j])
        {
            if (arr1[i] != result[k-1])
            {
                result.push_back(arr1[i]);
                k++;
            }
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            if (arr2[j] != result[k-1])
            {
                result.push_back(arr2[j]);
                k++;
            }
            j++;
        }
        else
        {
            if (arr2[j] != result[k-1])
            {
                result.push_back(arr2[j]);
                k++;
            }
            i++; j++;
        }
    }
    while (i < n1)
    {
        if (arr1[i] != result[k-1])
        {
            result.push_back(arr1[i]);
            k++;
        }
        i++;
    }
    while (j < n2)
    {
        if (arr2[j] != result[k-1])
        {
            result.push_back(arr2[j]);
            k++;
        }
        j++;
    }
    return result;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 6, 9};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    vector<int> v1;
    set<int> s1;

    v1 = unionOfArrays(arr1, arr2, n1, n2);
    
    for (auto x : v1)
    {
        cout << x << " ";
    }

    return 0;
}
