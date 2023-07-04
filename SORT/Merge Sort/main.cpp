#include <iostream>
#include <vector>

using namespace std;

void Merge(int arr[], int l, int m, int r)
{
    vector<int> x(arr + l, arr + m + 1);
    vector<int> y(arr + m + 1, arr + r + 1);
    int i = 0, j = 0;
    while (i < x.size() && j < y.size())
    {
        if (x[i] <= y[j])
        {
            arr[l] = x[i];
            l++;
            i++;
        }
        if (x[i] >= y[j])
        {
            arr[l] = y[j];
            l++;
            j++;
        }
    }
    while (i < x.size())
    {
        arr[l] = x[i];
        i++;
        l++;
    }
    while (j < y.size())
    {
        arr[l] = y[j];
        j++;
        l++;
    }
}

void MergeSort(int arr[], int l, int r)
{
    while (l >= r)
    {
        return;
    }
    int m = (l + r) / 2;
    MergeSort(arr, l, m);
    MergeSort(arr, m + 1, r);
    Merge(arr, l, m, r);
}

int main()
{
    int n;
    int *a = new int[n];
    cout << "Nhap so phan tu \n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    MergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}