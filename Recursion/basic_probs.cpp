/************************************************************************************************************************

                                            BASIC RECURSION CODES

************************************************************************************************************************/
#include <iostream>
#include <algorithm>

using namespace std;

void print_1_n (int n)
{
    if (n == 0)
        return;
    print_1_n(n-1);
    cout << n << endl;
}

void print_n_1 (int n)
{
    if (n == 0)
        return;
    cout << n << endl;
    print_n_1(n -1);
}

void print_sum (int n, int sum)
{
    if (n == 0)
    {
        cout << sum << endl;
        return;
    }
    print_sum(n-1, sum+n);
}

int return_sum (int n)
{
    if (n == 0)
        return 0;
    return n + return_sum(n - 1);
}

void reverse_array1 (int arr[], int l, int h)
{
    if (l >= h)
        return;
    swap(arr[l], arr[h]);
    reverse_array1(arr, l+1, h-1);
}

void reverse_array2 (int arr[], int i, int n)
{
    if (i >= n/2)
        return;
    swap (arr[i], arr[n-i]);
    reverse_array2(arr, i+1, n);
}

bool is_palindrome_using_2_ptrs (string s, int l, int h)
{
    if (l >= h)
        return true;
    else if (s[l] != s[h])
        return false;
    return is_palindrome_using_2_ptrs(s, l+1, h-1);
}

int main ()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    // string s;
    // cin >> n;
    // cin >> s;
    // print_1_n(n);
    // print_n_1(n);
    // print_sum(n, 0);
    // reverse_array1(arr, 0, n-1); /* Two pointers approach */
    reverse_array2(arr, 0, n-1); /* single pointer approach */
    // cout << return_sum (n) << endl;
    // cout << is_palindrome_using_2_ptrs (s, 0, s.size()-1) << endl;
    
    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}