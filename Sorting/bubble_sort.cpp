/******************************************************************************

                            Bubble sort algorithm
Iterative bubble sort:
Best case:
TC: O(n)
SC: O(1)
Average & Worst case:
TC: O(n^2)
SC: O(1)

Recursive bubble sort:
Best case:
TC: O(n)
SC: O(1)

Average & worst case:
TC: O(n^2)
SC: O(n)

It is Stable, in-place and takes N-1 passes in the worst case
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

/* Iterative bubble sort */
void bubble_sort (vector<int> &arr)
{
    int n = arr.size();
    bool flag;
    for (int i=0; i<n; i++)
    {
        flag = false;
        for (int j=0; j<(n - i - 1); j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
        if (flag == false)
            break;
    }
}

/* Recursive bubble sort */
void recursive_bubble_sort (vector<int> &arr, int i, int flag)
{
    if (flag == false || arr.size() == 1)
        return;
    flag = false;
    for (int j=0; j< (arr.size() - i  - 1); j++)
    {
        if (arr[j] > arr[j+1])
        {
            swap(arr[j], arr[j+1]);
            flag = true;
        }
    }
    print(arr);
    recursive_bubble_sort(arr, i+1, flag);
}

int main()
{
    vector<int> v1 = {20, 6, 10, 5, 1, 14, 2, 3, 2};
    bubble_sort(v1);
    recursive_bubble_sort(v1, 0, true);
    print(v1);
    return 0;
}