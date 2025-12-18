#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ll INF = 1e12;
const ll MOD = 1e9 + 7;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll n, m;
    cin >> n >> m;
    vector<ll> adj[n + 1], new_adj[n + 1];
    vector<pair<ll, ll>> edge;
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge.push_back({u, v});
    }
    vector<pair<ll, ll>> new_edge = edge;
    while (new_edge.size() > 1)
    {
        for (ll i = 1; i <= n; i++)
            adj[i].clear(), adj[i] = new_adj[i], new_adj[i].clear();
        queue<ll> q;
        edge.clear();
        edge = new_edge;
        new_edge.clear();
        q.push(edge[0].first);
        ll notun = edge[0].first;
        ll bad_dibo = edge[0].second;
        vector<bool> vis(n + 1, false);
        vis[edge[0].first] = true;
        while (!q.empty())
        {
            ll u = q.front();
            q.pop();
            for (auto v : adj[u])
            {
                if (v == bad_dibo)
                    v = notun;
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                    new_edge.push_back({u, v});
                    new_adj[u].push_back(v);
                    new_adj[v].push_back(u);
                }
            }
        }
        for(ll i=0;i<new_edge.size();i++)
    {
        ll u=new_edge[i].first;
        ll v=new_edge[i].second;
        if(u==v)
            u=v=-1;
    }
        sort(new_edge.rbegin(), new_edge.rbegin());
        while(new_edge.back().first==-1)
            new_edge.pop_back();
    }
    
    for(ll i=0;i<new_edge.size();i++)
    {
        ll u=new_edge[i].first;
        ll v=new_edge[i].second;
        cout<<u<<" "<<v<<"\n";
    }
}