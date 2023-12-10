/******************************************************************************

                            heap sort
TC: O(n logn)
SC: O(1)
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;


void print (vector<int> &arr)
{
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}

/*
TC: O(logn)
SC: O(1)
*/
int deleteFromHeap (vector<int> &arr)
{
    int i=0, j;
    int x = arr.front();
    swap(arr[0], arr[arr.size()-1]);
    arr.pop_back();
    j = 2*i+1;
    while (j < arr.size())
    {
        if (((j+1) < arr.size()) && arr[j+1] < arr[j])
            j = j+1;
        if (arr[j] < arr[i])
        {
            swap(arr[i], arr[j]);
            i = j;
            j = 2*i+1;
        }
        else
            break;
    }
    return x;
}

/*
TC: O(n)
SC: O(1)
*/
void createHeap (vector<int> &arr)
{
    int j=0;
    for (int i=arr.size()-1; i>=0; i--)
    {
        j = 2*i+1;
        int k = i;
        while (j<arr.size())
        {
            if ((j+1) < arr.size() && arr[j+1] < arr[j])
                j = j+1;
            if (arr[j] < arr[k])
            {
                swap(arr[j], arr[k]);
                k = j;
                j = 2*k+1;
            }
            else
                break;
        }
    }
}

int main()
{
    int x;
    vector<int> arr = {20, 4, 8, 6, 1, 22, 15, 10};
    createHeap(arr);
    print(arr);
    cout << deleteFromHeap(arr) << " ";
    cout << deleteFromHeap(arr) << " ";
    cout << deleteFromHeap(arr) << " ";
    cout << deleteFromHeap(arr) << " ";
    cout << deleteFromHeap(arr) << " ";
    cout << deleteFromHeap(arr) << " ";
    cout << deleteFromHeap(arr) << " ";
    cout << deleteFromHeap(arr) << " ";


    return 0;
}