#include "cs50.h"
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define ARRAY_SIZE 20000

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = 0;
    int temp[right - left + 1];
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    } 
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for(i = left, k = 0; i <= right; i++, k++)
    {
        arr[i] = temp[k];
    }
}

void merge_sort(int arr[], int left, int right)
{
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    merge_sort( arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
int main(void)
{
    int *arr1 = malloc(ARRAY_SIZE * sizeof(int));
    int *arr2 = malloc(ARRAY_SIZE * sizeof(int));

    srand(time(NULL));
    for (int i =0; i < ARRAY_SIZE; i++)
    {
        int random_num = rand() % 100000;
        arr1[i] = random_num;
        arr2[i] = random_num;
    }

    printf("Sorting %d random numbers...\n\n", ARRAY_SIZE);

    clock_t start_bubble = clock();
    bubble_sort(arr1, ARRAY_SIZE);
    clock_t end_bubble = clock();
    double time_bubble = ((double) (end_bubble - start_bubble)) / CLOCKS_PER_SEC;
    printf("Bubble Sort Time: %f seconds\n", time_bubble);

    clock_t start_merge = clock();
    merge_sort(arr2, 0, ARRAY_SIZE - 1);
    clock_t end_merge = clock();
    double time_merge = ((double)(end_merge - start_merge)) / CLOCKS_PER_SEC;
    printf("Merge Sort Time: %f seconds\n", time_merge);

    free(arr1);
    free(arr2);

    return 0;
}
