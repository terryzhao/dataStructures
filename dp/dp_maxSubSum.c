/*
 * =====================================================================================
 *
 *  Filename:  dp_maxSubSum.c
 *
 *  Description:
 *
 *  Created:  2017年11月20日 09时09分00秒
 *  Revision:  none
 *
 *  Author:  Terry Zhao
 *  Organization:
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int maxSum(int* arr, int n)
{
    int i;
    int *start = (int *)malloc(sizeof(int)*n);
    int *all = (int *)malloc(sizeof(int)*n);
    int final;


    if(!start || !all)
        return -1;

    memset(start, 0, sizeof(int)*n);
    memset(all, 0, sizeof(int)*n);

    start[n-1] = arr[n-1];
    all[n-1]   = arr[n-1];

    for(i=n-2; i>=0; i--)
    {
        start[i] = max(arr[i], arr[i]+start[i+1]);

        all[i] = max(start[i], all[i+1]);

        printf("start[%d] = %d,  all[%d] = %d\n", i, start[i], i, all[i]);
    }

    final = all[0];

    free(start);
    free(all);

    return final;
}

int main()
{
    /* int arr[6] = {0, -2, 3, 5, -1, 2}; //9 */
    int arr[6] = {1, -2, 3, 5, -3, 2}; // 8

    printf("max sum of sub arr: %d\n", maxSum(arr, sizeof(arr)/sizeof(arr[0])));

    return 0;
}
