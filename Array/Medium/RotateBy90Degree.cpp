/******************************************************************************

                        Rotate the image 90 degree
BF 1:
TC: O(n^2)
SC: O(n^2)
BF 2:
TC: O(n^2)
SC: O(n^2)
OS:
TC: O(2n^2)
SC: O(1)
*******************************************************************************/

#include <iostream>

using namespace std;

/* Brute force  Method - 1 */
// void rotateMatrix (int arr[][4], int n)
// {
//     int result[n][n] = {};
//     int j = n-1;
//     cout << n << endl;
//     for (int i=0; i<n; i++)
//     {
//         for (int k=0; k<n; k++)
//         {
//             result[k][j] = arr[i][k];
//         }
//         j--;
//     }
    
//     for (int i=0; i<n; i++)
//     {
//         for (int j=0; j<n; j++)
//         {
//             cout << result[i][j] << " ";
//         }
//         cout << endl;
//     } 
// }

/* Brute force  Method - 2 */
// void rotateMatrix (int arr[][4], int n)
// {
//     int result[n][n] = {};
//     for (int i=0; i<n; i++)
//     {
//         for (int j=0; j<n; j++)
//         {
//             result[i][j] = arr[n-j-1][i];
//         }
//     }
    
//     for (int i=0; i<n; i++)
//     {
//         for (int j=0; j<n; j++)
//         {
//             cout << result[i][j] << " ";
//         }
//         cout << endl;
//     } 
// }

/* Optimal solution 
Using transpose of matrix and reversing the array */
void rotateMatrix (int arr[][4], int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (i<j)
            {
                swap(arr[i][j], arr[j][i]);
            }
        }
    }
    
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n/2; j++)
        {
            swap(arr[i][j], arr[i][n-j-1]);
        }
    }
    
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    } 
}

int main()
{
    // int arr[3][3] = {{5, 14, 13},
    //                 {6, 1, 4},
    //                 {7, 2, 9}};
    int arr[4][4] = {{1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 10, 11, 12},
                    {13, 14,15, 16}};
    int n = sizeof(arr[0])/sizeof(arr[0][0]);
    rotateMatrix (arr, n);

    return 0;
}