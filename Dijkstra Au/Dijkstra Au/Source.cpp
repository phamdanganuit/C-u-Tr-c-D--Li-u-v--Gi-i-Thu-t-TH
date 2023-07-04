#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

#define INF 1e9
#define M 10001

using namespace std;

int stringToInt(const string &str, unordered_map<string, int> &strToInt, unordered_map<int, string> &intToStr, int &counter)
{
    if (strToInt.find(str) != strToInt.end())
    {
        return strToInt[str];
    }
    else
    {
        strToInt[str] = counter;
        intToStr[counter] = str;
        return counter++;
    }
}

void inp(vector<pair<int, int>> adj[M], unordered_map<int, string> &intToStr, int &n, int &m)
{
    cin >> n >> m;
    unordered_map<string, int> strToInt;
    int counter = 1;
    for (int i = 0; i < m; i++)
    {
        string sx, sy;
        int x, y, w;
        cin >> sx >> sy >> w;
        x = stringToInt(sx, strToInt, intToStr, counter);
        y = stringToInt(sy, strToInt, intToStr, counter);
        adj[x].push_back({y, w});
    }
}

void Dijkstra(vector<pair<int, int>> adj[M], unordered_map<int, string> &intToStr, int s, int n)
{
    vector<long long> d(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    d[s] = 0;
    Q.push({0, s});
    while (!Q.empty())
    {
        pair<int, int> top = Q.top();
        Q.pop();
        int kc = top.first;
        int u = top.second;
        if (kc > d[u])
        {
            continue;
        }
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (d[v] > (d[u] + w))
            {
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << intToStr[i] << ": " << d[i] << endl;
    }
}

int main()
{
    vector<pair<int, int>> adj[M];
    unordered_map<int, string> intToStr;
    int n, m;
    inp(adj, intToStr, n, m);
    Dijkstra(adj, intToStr, 1, n);
    return 0;
}
