#include<iostream>
#define UFN 1e9
using namespace std;
#include<vector>
#include<map>
int n,m;
map<char,vector<pair<char,int>>> List;
void Inp()
{
    cin>>n;
    for(int i=0;i<n;i++)
    
    {
        char x;
        char y;
        int w;
        cin>>x;        cin>>y;
        cin>>w;
        List[x].push_back(make_pair(y,w));

    }

}
void Duyet()
{
    for (auto x:List)
    {
        vector<pair<char,int>> s=x.second;
        cout <<x.first<<": ";
        for (auto u:s)
        {
            cout <<u.first<<" "<<u.second<<" ; ";
        }
        cout <<endl;
    }
}
int main()
{
    Inp();
    Duyet();
}