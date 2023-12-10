/******************************************************************************

                            Selection sort algorithm
Iterative selection sort:
Best case:
TC: O(n)
SC: O(1)
Average & Worst case:
TC: O(n^2)
SC: O(1)

Recursive selection sort:
Best case:
TC: O(n)
SC: O(1)

Average & worst case:
TC: O(n^2)
SC: O(n)

It is an unstable, in-place and takes N-1 passes in the worst case
***********************************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(vector<int> &v1)
{
    for (auto x : v1)
    {
        cout << x << " ";
    }
    cout << endl;
}

/* Iterative selection sort using minIndex */
// void selection_sort (vector<int> &arr)
// {
//     int minIndex;
//     for (int i=0; i<arr.size(); i++)
//     {
//         minIndex = i;
//         for (int j=i; j<arr.size(); j++)
//         {
//             if (arr[j] < arr[minIndex])
//             {
//                 minIndex = j;
//             }
//         }
//         print(arr);
//         swap(arr[minIndex], arr[i]);
//     }
// }

/* Recursive selection sort using minIndex */
// void recursive_selection_sort (vector<int> &arr, int i)
// {
//     int minIndex = i;
//     if (i == arr.size() || arr.size() == 1)
//         return;
//     for (int j=i+1; j<arr.size(); j++)
//     {
//         if (arr[j] < arr[minIndex])
//         {
//             minIndex = j;
//         }
//     }
//     print(arr);
//     swap(arr[minIndex], arr[i]);
//     recursive_selection_sort(arr, i+1);
// }

/* Iterative selection sort using maxIndex */
void selection_sort (vector<int> &arr)
{
    int maxIndex;
    for (int i=0; i<arr.size(); i++)
    {
        maxIndex = 0;
        for (int j=0; j< (arr.size() - i - 1); j++)
        {
            if (arr[j] > arr[maxIndex])
            {
                maxIndex = j;
            }
        }
        swap(arr[maxIndex], arr[(arr.size() - i - 1)]);
    }
}

/* Recursive selection sort using maxIndex */
void recursive_selection_sort (vector<int> &arr, int i)
{
    int maxIndex = 0;
    if (i == arr.size() || arr.size() == 1)
        return;
    for (int j=0; j < (arr.size() - i); j++)
    {
        if (arr[j] > arr[maxIndex])
        {
            maxIndex = j;
        }
    }
    print(arr);
    swap(arr[maxIndex], arr[(arr.size()-i-1)]);
    recursive_selection_sort(arr, i+1);
}

/* Stable selection sort algorithm */
/* 
Best case:
TC: O(N)
SC: O(1)
Average and worst case:
TC: O(N^2)
SC: O(1)
*/
void stable_selection_sort (vector<int> &arr)
{
    for (int i=0; i<arr.size(); i++)
    {
        bool flag = false;
        for (int j=i+1; j<arr.size(); j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
                flag = true;
            }
        }
        if (flag == false)
            break;
    }
}

int main()
{
    vector<int> v1 = {20, 6, 10, 5, 1, 14, 2, 3, 2};
    selection_sort(v1);
    // // selection_sort(v1);
    // cout << "First time sort: " << endl;
    // recursive_selection_sort(v1, 0);
    // cout << "Second time sort: " << endl;
    // recursive_selection_sort(v1, 0);
    print(v1);
    return 0;
}