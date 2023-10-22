/******************************************************************************

                    Intersection between 2 sorted arrays
Brute force:
TC: O(n1 * n2)
SC: O(n2)

Optimal:
TC: O(n)
SC: O(n) -> for result
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/* brute force */
vector<int> intersection (int arr1[], int arr2[], int n1, int n2)
{
    vector<int> res;
    int arr[n2] = {};
    for (int i=0; i<n1; i++)
    {
        for (int j=0; j<n2; j++)
        {
            if ((arr1[i] == arr2[j]) && (arr[j] == 0))
            {
                res.push_back(arr1[i]);
                arr[j]++;
                break;
            }
            if (arr2[j] > arr1[i])
                break;
        }
    }
    return res;
}

/* Optimal solution */
vector<int> intersection (int arr1[], int arr2[], int n1, int n2)
{
    vector<int> result;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
		if (arr1[i] < arr2[j])
		{
			i++;
		}
		else if (arr1[i] > arr2[j])
		{
			j++;
		}
        else
        {
            result.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return result;
}

int main()
{
    // int arr1[] = {1, 2, 3, 4, 4, 5, 5, 6};
    // int arr2[] = {2, 3, 4, 5, 5, 6, 6, 7, 7};
    int arr1[] = {1, 1};
    int arr2[] = {1};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    vector<int> v1;
    v1 = intersection (arr1, arr2, n1, n2);
    
    for (auto x : v1)
    {
        cout << x << " ";
    }

    return 0;
}