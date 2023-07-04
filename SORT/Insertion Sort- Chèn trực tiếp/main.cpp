#include <iostream>
using namespace std;

void InSertionSort(int a[], int n)
{
    int pos, i, x;       // pos la vi tri can tim, x la bien de luu phan tu can chen
    for (i = 1; i < n; i++) // Doan a[0] da sap xep
    {
        // x=a[i];
        // pos=i-1;
        // while(pos>=0&& a[pos]>x)
        // {
            // a[pos+1]=a[pos];
            // pos--;
        // }
        // a[pos+1]=x;

        x=a[i];// Lay gia tri can so sanh ra
        pos =i-1;
        while (pos>=0&&a[pos]>x) //Xep tu lon den be
        {
            a[pos+1]=a[pos];//dich gia tri a[pos] sang phai 1 don vi
            pos--; // so sanh voi gia tri truoc do
        }
        a[pos+1]=x; // Gan gia tri cuoi cung vao neu dung dieu kien
        
    }
}
int main()
{
    int a[] = {1, 4, 2, 5, 6};
    int n = 5;
    InSertionSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}
void InSertionSort(int arr[],int N)
{
    for (int i=1;i<N;i++)
    {
        int pos =i-1;
        int x=arr[i];
        while(pos>=0&&arr[pos]<x)
        {
            arr[pos]=arr[pos+1];
            pos--;
        }
        arr[pos+1]=x;
    }
}