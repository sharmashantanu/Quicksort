#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;
int size;
int partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=(low-1);
    for(int j=low;j<high;j++)
    {
        if(pivot>=arr[j])
        {
            i++;
            int temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    int var=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=var;
    return (i+1);
}

void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int num=partition(arr,low,high);
        for(int i=0;i<size;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        quicksort(arr,low,num-1);
        quicksort(arr,num+1,high);
    }
}

int main()
{
    int k,choice;
    cout<<"\n\n\n\t\t\t\tQUICKSORT";
    cout<<"\n\n\n\n How many numbers you want to be sorted : ";
    cin>>k;
    int arr[k-1],l,h,n;
    l=0;
    h=k-1;
    size=k;
    cout<<"\n\n\n 1.Enter numbers manually";
    cout<<"\n\n 2.Generate random numbers";
    cout<<"\n\n\n Please select an option from the given choices : ";
    cin>>choice;
    switch(choice)
    {
        case 1: cout<<"\n\n Enter the elements to be sorted : ";
                for(n=0;n<k;n++)
                {
                    cin>>arr[n];
                    cout<<"\t\t\t\t   ";
                }
                cout<<endl;
                quicksort(arr,l,h);
                break;

        case 2: cout<<"\n\n Random numbers generated are : ";
                srand(time(NULL));
                for(n=0;n<k;n++)
                {
                    arr[n]=rand()%1000;
                }
                for(n=0;n<k;n++)
                {
                    cout<<arr[n]<<"\n\t\t\t\t";
                }
                cout<<endl;
                quicksort(arr,l,h);
    }
    cout<<"\n\n Sorted Array is : ";
    for(n=0;n<k;n++)
    {
        if(n<k-1)
            cout<<arr[n]<<" <  ";
        else
            cout<<arr[n]<<"\n\n\n";
    }
    return 0;
}
