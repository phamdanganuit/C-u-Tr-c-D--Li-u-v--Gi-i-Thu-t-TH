#include<iostream>
using namespace std;
#define MAX 100
void input(int s[],int &n,int &m){
    cout <<"Nhap so tien can doi ";cin>>n;
    cout<<"Nhap so loai tien ";cin>>m;
    for (int i=0;i<m;i++)
    {
        cout<<"Nhap menh gia to thu "<<i+1<<endl;cin>>s[i];
    }
}
int countChange(int n, int m, int s[]) {
    if (n == 0) {
        return 1; 
    } 
    if (n < 0 || (m <= 0 && n >= 1)) {
        return 0; 
    }
    return countChange(n, m - 1, s) + countChange(n - s[m - 1], m, s);
}
int main() {
    int n ;
    int m ;
    int s[MAX];
    input(s,n,m);
    cout << "So cach doi tien: " << countChange(n, m, s) << endl;
    return 0;
}
