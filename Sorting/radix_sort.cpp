/* RADIX SORT */
/* Time complexity: O(d * n) */ /* Here d represents number of digits on max number in the given array */
/* Space complexity: O(n) */


#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;

void print (int arr[], int size)
{
    for (int i=0; i<size; i++)
    {
        printf ("%d ", arr[i]);
    }
    printf ("\r\n");
}

int findMax (int arr[], int size)
{
    int maxVal = INT_MIN;
    
    for (int i=0; i<size; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

void radix_sort (int arr[], int size)
{
    int maxVal = findMax(arr, size);
    int i = 0;
    int j = 0;
    node **list = (node **) malloc (sizeof(node*) * 10);
    memset (list, 0, sizeof(node *) * 10);
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
    {
        for (int i = 0; i < size; i++)
        {
            node *temp = malloc (sizeof(node));
            int digit = (arr[i] / exp) % 10;
            printf ("Digit %d\r\n", digit);
            temp->data = arr[i];
            temp->next = NULL;
            if (list[digit] == NULL)
            {
                list[digit] = temp;
            }
            else
            {
                node *itr = list[digit];
                while (itr->next != NULL)
                    itr = itr->next;
                itr->next = temp;
            }
        }
        int k = 0;
        for (int i=0; i<10; i++)
        {
            node *itr = list[i];
            node *itr_tmp = NULL;
            while (itr != NULL)
            {
                arr[k] = itr->data;
                itr_tmp = itr;
                itr = itr->next;
                k++;
                free(itr_tmp);
            }
            list[i] = NULL;
        }
        j++;
    }
    free (list);
    return;
}

int main()
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = 10;
    
    radix_sort (arr, size);
    
    print(arr, size);
    

    return 0;
}