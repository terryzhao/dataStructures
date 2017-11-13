/*
 * =====================================================================================
 *
 *  Filename:  finabocci.cpp
 *
 *  Description:
 *
 *  Created:  2017年11月13日 14时40分42秒
 *  Revision:  none
 *
 *  Author:  Terry Zhao
 *  Organization:
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;


int f(int n)
{
    if(n<1)
        return 0;

    if(n==1 || n==2)
        return 1;

    return f(n-1) + f(n-2);
}

int main()
{
   cout<<"Finabocci: "<<endl;
   for(int i=1; i<6; i++)
   {
       printf("f(%d) = %d\n", i, f(i));
   }

    return 0;
}

