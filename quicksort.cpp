#include<iostream>
using namespace std;

void swap(int arr[],int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l;
    int j = h;
    while(i < j)
    {
        while(arr[i] <= pivot) i++;
        while(arr[j] > pivot) j--;
        if(i < j) swap(arr,i,j);
    }
    swap(arr,j,l);
    return j;
}

void quickSort(int arr[], int l, int h)
{
    if(l < h)
    {
        int pi = partition(arr,l,h);
        quickSort(arr,l,pi-1);
        quickSort(arr, pi+1, h);
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0 ; i < n; i++) cout<<arr[i]<<"\t";
    cout<<endl;
}

int main()
{
    int arr[] = {10,7,8,9,1,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr,0,n-1);
    cout<<"Display sorted array : "<<endl;
    printArray(arr,n);

    return 0;
}