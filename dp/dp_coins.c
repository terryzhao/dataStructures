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
