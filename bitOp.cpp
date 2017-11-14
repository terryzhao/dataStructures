/*
 * =====================================================================================
 *
 *  Filename:  bitOp.cpp
 *
 *  Description:
 *
 *  Created:  2017年11月13日 18时41分18秒
 *  Revision:  none
 *
 *  Author:  Terry Zhao
 *  Organization:
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

int countBit1(int n)
{
    int num = 0;

    while(n)
    {
        n &= (n-1);

        num++;
    }

    return num;
}

int main(int argc, char *argv[])
{
    if(argc > 1) {
        cout<<atoi(argv[1])<<endl;
        cout<<countBit1(atoi(argv[1]))<<endl;
    }

    return 0;
}


