/*
 * =====================================================================================
 *
 *  Filename:  sorting.cpp
 *
 *  Description:
 *
 *  Created:  2017年11月13日 13时11分30秒
 *  Revision:  none
 *
 *  Author:  Terry Zhao
 *  Organization:
 *
 * =====================================================================================
 */
#include <iostream>

using namespace std;

void insertion_sort(int *arr, int len)
{
    for(int i=1; i<len; i++)
    {
        int tm = *(arr+i);
        int j = i-1;

        for(; ((j>=0) && *(arr+j)>tm); j--)
        {
            *(arr+j+1) = *(arr+j);
        }
        *(arr+j+1) = tm;
    }
}

void quick_sort(int *arr, int low, int high)
{
    int i = low;
    int j = high;
    int tm = *(arr+low);

    if(i<j)
    {
        while(i < j)
        {
            while((*(arr+j)>tm) && (j>i))
                j--;
            *(arr+i)=*(arr+j);

            while((*(arr+i)<tm) && (i<j))
                i++;
            *(arr+j)=*(arr+i);
        }

        *(arr+i) = tm;

        quick_sort(arr, low, i-1);
        quick_sort(arr, i+1, high);
    }
}

void listArr(int *arr, int len)
{
    for(int i=0; i<len; i++)
    {
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}


int main(void)
{
    int arr[10] = {5, 3, 4, 1, 9, 8, 2, 0, 7, 6};

    cout<<"unsorted arr: "<<endl;
    listArr(arr, 10);
    // insertion_sort(arr, 10);
    quick_sort(arr, 0, 9);
    cout<<"sorted arr: "<<endl;
    listArr(arr, 10);


    return 0;
}
