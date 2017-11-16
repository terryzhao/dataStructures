/*
 * =====================================================================================
 *
 *  Filename:  beibao.cpp
 *
 *  Description:
 *
 *  Created:  2017年11月16日 10时21分04秒
 *  Revision:  none
 *
 *  Author:  Terry Zhao
 *  Organization:
 *
 * =====================================================================================
 */

// example for Dynamic Programming -- beibao

// 输入样例：

// 100 5

// 77 92

// 22 22

// 29 87

// 50 46

// 99 90



// 输出样例：

// 133

#include <iostream>
#include <fstream>

using namespace std;

const int n = 5;
const int peoTotal = 100;
//people needed for each mine.
int peoNeed[5] = {77, 22, 29, 50, 99};
//gold number for each gold mine.
int gold[5] = {92, 22, 87, 46, 90};
//maxGold[i][j]保存了i个人挖前j个金矿能够得到的最大金子数，等于-1时表示未知]
int maxGold[peoTotal][n];


inline int Max(int a, int b)
{
    return (a>b) ? a : b;
}

int initData()
{
    for(int i=0; i<peoTotal; i++)
    {
        for(int j=0; j<n; j++)
            maxGold[i][j] = -1;
    }
}

//获得在仅有people个人和前mineNum个金矿时能够得到的最大金子数，
//注意“前多少个”也是从0开始编号的
int getMaxGold(int people, int mineNum)
{
    int retMaxGold;

    if(mineNum < 0)
        return 0;

    //如果这个问题曾经计算过  [对应动态规划中的“做备忘录”]
    if(maxGold[people][mineNum] != -1){
        //获得保存起来的值
        return maxGold[people][mineNum];
    }

    if(mineNum == 0) {
        //如果仅有一个金矿时 [对应动态规划中的“边界”]
        //当给出的人数足够开采这座金矿
        if(people >= peoNeed[mineNum]){
            //得到最大值就是这座金矿的金字数
            retMaxGold = gold[mineNum];
        }else{
            //得到的最大值为０
            retMaxGold = 0;
        }

        maxGold[people][mineNum] = retMaxGold;
        return retMaxGold;
    }

    //如果给出的人够开采这座金矿 [对应动态规划中的“最优子结构”]
    if(people >= peoNeed[mineNum]){

        //考虑开采与不开采两种情况，取最大值
        retMaxGold = Max(getMaxGold(people - peoNeed[mineNum], mineNum-1)+gold[mineNum],
                getMaxGold(people, mineNum-1));
    }else//否则给出的人不够开采这座金矿 [对应动态规划中的“最优子结构”]
    {
        //仅考虑不开采的情况
        retMaxGold  = getMaxGold(people,mineNum - 1);
    }

    //做备忘录
    maxGold[people][mineNum] = retMaxGold;
    return retMaxGold;
}

int main()
{
    //初始化数据
    initData();
    //输出给定peopleTotal个人和n个金矿能够获得的最大金子数，
    //再次提醒编号从0开始，所以最后一个金矿编号为n-1
    cout<<getMaxGold(peoTotal-1 ,n-1)<<endl;

    return 0;
}



