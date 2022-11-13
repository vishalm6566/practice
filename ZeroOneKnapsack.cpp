#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    if(a > b) return a;
    return b;
}

int knapSack(int W, int weight[], int value[], int n)
{
    vector<vector<int>> K(n+1, vector<int>(W+1));
    int i, j;

    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= W; j++)
        {
            if(i == 0 || j == 0) K[i][j] = 0;
            else if(weight[i-1] <= j)
            {
                K[i][j] = max(value[i - 1] + K[i - 1][j - weight[i - 1]], K[i - 1][j]);
            }
            else K[i][j] = K[i-1][j];
        }
    }
    return K[n][W];
}

int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    cout << knapSack(W, wt, val, n);

    return 0;
}