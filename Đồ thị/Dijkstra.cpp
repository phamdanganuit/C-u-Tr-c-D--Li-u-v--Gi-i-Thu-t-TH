#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define MAX 1e9
typedef long long ll;
using namespace std;

map<int, set<pair<int, int>>> adj;
vector<string> List;
map<string, int> strtoInt;
map<int, string> Inttostr;
int n, m;
void inp()
{

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        List.push_back(str);
        strtoInt[str] = i;
        Inttostr[i] = str;
    }
    for (int i = 0; i < m; i++)
    {
        string u, v;
        int w;
        cin >> u >> v >> w;
        int x, y;
        x = strtoInt[u];
        y = strtoInt[v];
        adj[x].insert(make_pair(y, w));
        adj[y].insert(make_pair(x, w));
    }
}
void Dijkstra(int s)
{
    vector<ll> d(n + 1, MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    d[s] = 0;
    Q.push(make_pair(0, s));
    while (!Q.empty())
    {
        pair<int, int> top = Q.top();
        Q.pop();
        int u = top.second;
        int kc = top.first;
        if (kc > d[u])
        {
            continue;
        }
        for (auto x : adj[u])
        {
            int v = x.first;
            int w = x.second;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push(make_pair(d[v], v));
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << Inttostr[i] << ": " << d[i] << endl;
    }
}
int main()
{
    inp();
    cout << " Nhap dinh bat dau\n ";
    string u;
    cin >> u;
    int x = strtoInt[u];
    Dijkstra(x);
    return 0;
}