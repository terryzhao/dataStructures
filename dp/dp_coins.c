/*
 * =====================================================================================
 *
 *  Filename:  dp_coins.c
 *
 *  Description:
 *
 *  Created:  2017年11月20日 09时40分59秒
 *  Revision:  none
 *
 *  Author:  Terry Zhao
 *  Organization:
 *
 * =====================================================================================
 */

/* 假设有几种硬币，如1、3、5，并且数量无限。
 * 请找出能够组成某个数目的找零所使用最少的硬币数。  */

/* 解法： */
/* 　　用待找零的数值k描述子结构/状态，记作sum[k]，
 * 其值为所需的最小硬币数。对于不同的硬币面值coin[0...n]，
 * 有sum[k] = min(sum[k-coin[0]] , sum[k-coin[1]], ...)+1。
 * 对应于给定数目的找零total，需要求解sum[total]的值。 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

const int INF = 1e9 + 10;


typedef struct {
    int nCoin; //使用硬币数量
    int lastSum;//上一个状态
    int addCoin;//从上一个状态达到当前状态所用的硬币种类
} state;


int makeChange(int totalMoney, int* coins, int coinNum)
{
    int total = totalMoney;

    state* sum = (state *)malloc(sizeof(state)*(total+1));

    //init
    for(int i=0; i<=total; i++)
        sum[i].nCoin = INF;

    sum[0].nCoin = 0;
    sum[0].lastSum = 0;

    for(int i=1; i<=total; i++)
    {
        for(int j=0; j<coinNum; j++)
        {
            if(i-coins[j] >= 0)
            {
                if((sum[i-coins[j]].nCoin+1)<sum[i].nCoin){
                    sum[i].nCoin = sum[i-coins[j]].nCoin+1;
                    sum[i].lastSum = j;
                    sum[i].addCoin = coins[j];
                }
            }

        }
    }

    if(sum[total].nCoin == INF){
        printf("can not make changes!\n");
        return -1;
    }else
        return sum[total].nCoin;
}

int main()
{
    int totalMoney = 100;
    int coins[3] = {1, 3, 5};

    int num = makeChange(totalMoney, coins, 3);
    printf("min number of coins: %d\n", num);


    return 0;
}

