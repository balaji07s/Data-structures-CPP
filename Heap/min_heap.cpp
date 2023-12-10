/******************************************************************************

                            min Heap

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
void insertIntoHeap (vector<int> &arr, int index)
{
    int i = index;
    while ((i > 0) && (arr[((i-1)/2)] > arr[i]))
    {
        swap(arr[((i-1)/2)], arr[i]);
        i = ((i-1)/2);
    }
}

/*
TC: O(logn)
SC: O(1)
*/
void deleteFromHeap (vector<int> &arr)
{
    int i=0, j;
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
    return;
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
    vector<int> arr = {20, 4, 8, 6, 1, 22, 15, 10};
    // for (int i=0; i<arr.size(); i++)
        // insertIntoHeap (arr, i);
    
    // print(arr);
    // deleteFromHeap(arr);
    // print(arr);
    // deleteFromHeap(arr);
    // print(arr);
    // deleteFromHeap(arr);
    // print(arr);
    // deleteFromHeap(arr);
    // print(arr);
    // deleteFromHeap(arr);
    // print(arr);
    // deleteFromHeap(arr);
    // print(arr);
    // deleteFromHeap(arr);
    // print(arr);

    createHeap(arr);
    print(arr);

    return 0;
}