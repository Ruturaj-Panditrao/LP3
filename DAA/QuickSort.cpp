// QuickSort Sorting Algorithm :
// With Deterministic Partition
// As Well as Randomized Partition 
// For choosing the Pivot

#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int deterministic_partition(int arr[],int low, int high)
{   
    int i = low;
    int j = high;
    int pivot = arr[low];

    while(i<j)
    {
        while(arr[i]<=pivot && i<high)
        {
            i++;
        }

        while(arr[j]>pivot && j>low)
        {
            j--;
        }

        if(i<j) swap(arr[i],arr[j]);
    }

    swap(arr[low],arr[j]);
    return j;
}

int randomized_partition(int arr[], int low, int high)
{
    int i = low;
    int j = high;
    // Choose the Pivot Element Randomly
    int pivotIndex = rand() % (high-low) + low;
    swap(arr[low], arr[pivotIndex]);
    int pivot = arr[low];

    while(i<j)
    {
        while(arr[i]<=pivot && i<high)
        {
            i++;
        }
        while(arr[j]>pivot && j>low)
        {
            j--;
        }

        if(i<j) swap(arr[i],arr[j]);
    }

    swap(arr[low],arr[j]);
    return j;
}

void deterministicQuickSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int p = deterministic_partition(arr,low,high);
        deterministicQuickSort(arr,low,p-1);
        deterministicQuickSort(arr,p+1,high);
    }
}

void randomizedQuickSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int p = randomized_partition(arr,low,high);
        randomizedQuickSort(arr,low,p-1);
        randomizedQuickSort(arr,p+1,high);
    }
}


int main()
{
    int arr1[] = {10,14,2,7,9,100,20};
    int arr2[] = {10,14,2,7,9,100,20};
    cout<<"Given Array : "<<endl;
    printArray(arr1,7);
    cout<<"Deterministic Quick Sort : "<<endl;
    deterministicQuickSort(arr1,0,6);
    printArray(arr1,7);
    cout<<"Randomized Quick Sort : "<<endl;
    randomizedQuickSort(arr2,0,6);
    printArray(arr2,7);
}

// Time Complexity : O(NlogN)
// Space Complexity : O(1)
