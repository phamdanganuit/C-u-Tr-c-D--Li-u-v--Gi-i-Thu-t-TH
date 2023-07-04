#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

map<char, set<pair<char, int>>> List;
int n;
int m;
void inp()
{
    cin >> n >> m;

    char *a = new char[n];

    for (int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        char x, y;
        int w;
        cin >> x >> y;
        cin >> w;
        List[x].insert(make_pair(y, w));
    }
}
void outp()
{
    for (auto x : List)
    {
        set<pair<char, int>> tmp = x.second;
        cout <<x.first<<" ";
        for (auto s:tmp)
        {
            cout<< s.first<<" "<<s.second;
        }
        cout<<endl;
    }
}
int main()
{
    inp();
    outp();
}