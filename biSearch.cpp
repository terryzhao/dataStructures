/*
 * =====================================================================================
 *
 *  Filename:  biSearch.cpp
 *
 *  Description:
 *
 *  Created:  2017年11月13日 16时47分43秒
 *  Revision:  none
 *
 *  Author:  Terry Zhao
 *  Organization:
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

int biSearch(char *arr, int len, char ch)
{
    int min, mid, max;
    min = 0;
    max = len;

    while(min < max)
    {
        mid = min + (max - min)/2;
        if(*(arr+mid) == ch)
            return mid;
        else if(*(arr+mid) > ch)
            max = mid;
        else
            min = mid+1;
    }

    return -1;
}

int main(void)
{
    char arr[6] = {'a', 'b', 'c', 'd', 'e', 'f'};

    int ret = biSearch(arr, 6, 'a');

    cout<<"result: "<<ret<<endl;

    return 0;
}
