#include <iostream>
using namespace std;
//Thuat toan xam lon
void SelectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if ( a[j]<a[min])
            {
                min=j;
            }  
        }
        swap(a[i],a[min]);
    }
}
int main()
{
    int a[] = {1, 4, 5, 6, 2,3};
    SelectionSort(a, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << endl;
    }
}