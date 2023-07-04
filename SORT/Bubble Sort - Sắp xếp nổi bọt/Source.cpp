#include<iostream>

using namespace std;

void BubbleSort(int n,int a[])
{
    for (int i=0;i<n;i++)
    {
        for (int j=n-1;j>i;j--) //j=i+1
        {
            if (a[j]>a[j-1])
                swap(a[j],a[j-1]);
        }
    }
}
int main()
{
    int a[]={1,4,2,5,6};
    int n=5;
    BubbleSort(5,a);
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
}