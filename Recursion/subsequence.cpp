/******************************************************************************

                                SUBSEQUENCE in an array/list

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

/* Main solution */
void printF (int ind, vector<int> &ds, int arr[], int n)
{
    if (ind == n)
    {
        for (auto x : ds)
            cout << x  << " ";
        if (ds.size() == 0)
            cout << "{}" << " ";
        cout << endl;
        return;
    }
    ds.push_back(arr[ind]);
    printF (ind+1, ds, arr, n);
    ds.pop_back();
    printF (ind+1, ds, arr, n);
}

/* Alternate solution */
void printF (int ind, vector<int> &ds, int arr[], int n)
{
    if (ind == n)
    {
        for (auto x : ds)
            cout << x  << " ";
        if (ds.size() == 0)
            cout << "{}" << " ";
        cout << endl;
        return;
    }
    
    printF (ind+1, ds, arr, n);
    ds.push_back(arr[ind]);
    printF (ind+1, ds, arr, n);
    ds.pop_back();
}

int main ()
{

    int arr[] = {3, 1, 2};
    int n = 3;
    vector<int> ds;
    printF (0, ds, arr, n);

  return 0;
}
