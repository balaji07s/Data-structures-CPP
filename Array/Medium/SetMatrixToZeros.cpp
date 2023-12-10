/******************************************************************************

                    Set matrix to zeros
BF:
TC: O
SC:

*******************************************************************************/

#include <iostream>
#include <vector>


using namespace std;

/* Brute force */
void setRowsToZeros (int row, vector<vector<int>> &arr)
{
    for (int i=0; i<arr[0].size(); i++)
    {
        if (arr[row][i] != 0)
            arr[row][i] = -1;
    }
}

void setColumnsToZeros (int col, vector<vector<int>> &arr)
{
    for (int i=0; i<arr.size(); i++)
    {
        if (arr[i][col] != 0)
            arr[i][col] = -1;
    }
}

void setMatrixToZeros (vector<vector<int>> &arr)
{
    int row = arr.size();
    int col = arr[0].size();
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            if (arr[i][j] == 0)
            {
                setRowsToZeros(i, arr);
                setColumnsToZeros(j, arr);
            }
        }
    }
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            if (arr[i][j] == -1)
                arr[i][j] = 0;
        }
    }
}



int main()
{
    // vector<vector<int>> matrix = {{1, 1, 1, 1},
    //                                 {1, 0, 0, 1},
    //                                 {1, 0, 0, 1},
    //                                 {1, 1, 1, 1}};
    
    // vector<vector<int>> matrix = {{1, 1, 1},
    //                                 {1, 0, 1},
    //                                 {1, 0, 1},
    //                                 {1, 1, 1}};

    vector<vector<int>> matrix = {{1, 1, 1, 1},
                                    {1, 0, 0, 1},
                                    {1, 1, 1, 1}};

    setMatrixToZeros (matrix);

    for (int i=0; i<matrix.size(); i++)
    {
        for (int j=0; j<matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}