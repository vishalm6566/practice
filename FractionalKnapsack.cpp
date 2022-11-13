#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//1
typedef struct item
{
    int value;
    int weight;
}ITEM;

//3
bool cmp(ITEM a, ITEM b)
{
    double r1 = (double)a.value/(double)a.weight;
    double r2 = (double)b.value/(double)b.weight;
    return r1 > r2;
}

//2
double Knapsack(int w, ITEM arr[], int n)
{
    sort(arr,arr+n,cmp);

    double finalValue = 0.0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i].weight <= w)
        {
            w -= arr[i].weight;
            finalValue += arr[i].value;
        }
        else
        {
            finalValue += arr[i].value * ((double) w / (double)arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main()
{
    int w = 50;
    ITEM arr[] = {{60,10},{100,20},{120,30}};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<Knapsack(w,arr,n);

    return 0;
}
//
// Follow the given steps to solve the problem using the above approach:
//
// Calculate the ratio(value/weight) for each item. (for this we build cmp function)
// Sort all the items in decreasing order of the ratio. (use inbuilt sort function)
// Initialize res =0, curr_cap = given_cap.
// Do the following for every item “i” in the sorted order:
// If the weight of the current item is less than or equal to the remaining capacity then add the value of that item into the result
// Else add the current item as much as we can and break out of the loop.
// Return res.