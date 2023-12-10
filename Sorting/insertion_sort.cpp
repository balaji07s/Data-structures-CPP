/******************************************************************************

                        Insertion sort algorithm
Best case
TC: O(n)
SC: O(1)
Average and worst case
TC: O(n^2)
SC: O(1)
Recursive:
Best case
TC: O(n)
SC: O(n)
Average and worst case
TC: O(n^2)
SC: O(n)
*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print (vector<int> &arr)
{
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}

/* Iterative insertion sort */
// void insertion_sort (vector<int> &arr)
// {
//     for (int i=1; i<arr.size(); i++)
//     {
//         int j = i;
//         int temp = arr[i];
//         while (j > 0 && arr[j-1] > temp)
//         {
//             arr[j] = arr[j-1];
//             j--;
//         }
//         arr[j] = temp;
//     }
// }

/* Recursive insertion sort */
void recursive_insertion_sort (vector<int> &arr, int i)
{
    if (i == arr.size() || arr.size() == 1)
    {
        return;
    }
    int j=i;
    int temp = arr[j];
    while (j>0 && arr[j-1] > temp)
    {
        arr[j] = arr[j-1];
        j--;
    }
    arr[j] = temp;
    recursive_insertion_sort(arr, i+1);
}

int main()
{
    vector<int> arr = {20, 6, 10, 5, 1, 14, 2, 3, 2};
    recursive_insertion_sort (arr, 0);

    print (arr);

    return 0;
}