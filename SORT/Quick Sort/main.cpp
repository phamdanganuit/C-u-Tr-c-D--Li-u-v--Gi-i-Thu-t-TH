// #include <iostream>
// using namespace std;

// // Phan Hoach Lomuto

// int patition(int arr[], int left, int right)
// {
//     int pivot = arr[right]; // Đặt chôt là phần tử cuối
//     int i = left - 1;
//     for (int j = left; j < right - 1; j++)
//     {
//         if (arr[j] <= pivot)
//         {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[right]);
//     return i + 1;
// }
// void QuickSort(int arr[], int l, int r)
// {
//     if (l < r)
//     {
//         int p = patition(arr, l, r);
//         QuickSort(arr, l, p - 1);
//         QuickSort(arr, p + 1, r);
//     }
// }
// // Phan Hoach Hoare

// int Patition(int arr[], int l, int r)
// {
//     int pivot = arr[l];
//     int i = l - 1, j = r + 1;
//     while (i < j)
//     {
//         while (arr[i] < pivot)
//             i++;
//         while (arr[j] > pivot)
//         {
//             j--;
//         }
//         swap(arr[i], arr[j]);
//     }
//     return j;
// }
// void quicksort(int arr[], int l, int r)
// {
//     if (l < r)
//     {
//         int p = Patition(arr, l, r);
//         quicksort(arr, l, p - 1);
//         quicksort(arr, p + 1, r);
//     }
// }

// int main()
// {
//     int n;
//     int *a = new int[n];
//     cout << "Nhap so phan tu \n";
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     quicksort(a, 0, n - 1);

//     for (int i = 0; i < n; i++)
//     {
//         cout << a[i] << " ";
//     }
// }
#include <iostream>
#include<ctime>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int HoarePartition(int a[], int l, int r)
{
    int pivot = (l + r) / 2;
    int i = l - 1;
    int j = r + 1;
    while (i <= j)
    {
        while (a[i] > a[pivot])
            i++;
        while (a[j] < a[pivot])
            j--;
        swap(a[i], a[j]);
    }
    return j;
}
void Quicksort(int a[], int l, int r)
{
    if (l < r)
    {
        int p = HoarePartition(a, l, r);
        Quicksort(a, l, p - 1);
        Quicksort(a, p + 1, r);
    }
}
int main()
{
    int n;
    cin>>n;
    int *a=new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand();

    }
    Quicksort(a, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}