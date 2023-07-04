#include<iostream>
//
using namespace std;

// Giải thuật : Duyệt tất cả các cặp giá trị trong mảng và nếu gặp nào nghịch thế thì đổi cho nhau

void InterchangeSort(int a[],int n)
{
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (a[i]>a[j])// 1 2 3 5 6 
            {
                swap(a[i],a[j]);
            }
        }
    }
}
int main()
{
    int a[]={1,4,2,5,6};
    int n=5;
    InterchangeSort(a,n);
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
}