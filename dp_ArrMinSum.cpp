/*
 * =====================================================================================
 *
 *  Filename:  dp_ArrMinSum.cpp
 *
 *  Description:
 *
 *  Created:  2017年11月21日 09时42分16秒
 *  Revision:  none
 *
 *  Author:  Terry Zhao
 *  Organization:
 *
 * =====================================================================================
 */

/*
 * Get Min Sum for (0, 0) to (m, n);
        1 3 5 9
        8 1 3 4
        5 0 6 1
        8 8 4 0
*
*/

#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b)
{
    if(a<b)
        return a;
    else
        return b;
}

vector<vector<int>> initArray()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(5);
    a.push_back(9);

    vector<int> b;
    b.push_back(8);
    b.push_back(1);
    b.push_back(3);
    b.push_back(4);

    vector<int> c;
    c.push_back(5);
    c.push_back(0);
    c.push_back(6);
    c.push_back(1);

    vector<int> d;
    d.push_back(8);
    d.push_back(8);
    d.push_back(4);
    d.push_back(0);

    vector<vector<int>> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);
    vec.push_back(d);

    return vec;
}

int minSum(vector<vector<int>> vec, int i, int j, int sum)
{
    if((i+1)>=vec.size() && (j+1)>=vec[0].size())
        return sum;

    int rowValue;
    int colValue;
    if(i < (vec.size() - 1))
        rowValue = vec[i+1][j];
    else
        rowValue = vec[i][j];

    if(j < (vec.size() - 1))
        colValue = vec[i][j+1];
    else
        colValue = vec[i][j];

    sum += min(rowValue, colValue);

    if(rowValue < colValue)
        return minSum(vec, i+1, j, sum);
    else
        return minSum(vec, i, j+1, sum);
}

int main()
{
    vector<vector<int>> vec;

    vec = initArray();

    for(int i=0; i<vec.size(); i++)
    {
        for(int j=0; j<vec[0].size(); j++)
            cout<<vec[i][j]<<" ";
        cout<<endl;
    }

    int result = minSum(vec, 0, 0, vec[0][0]);
    cout<<"minSum: "<<result<<endl;

    return 0;
}
