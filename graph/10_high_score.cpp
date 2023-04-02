#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <unordered_map>
#include <chrono>
#include <math.h>

using namespace std;

#define ull unsigned long long
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vc vector<char>
#define vi vector<int>
#define vvb vector<vector<bool>> 
#define vb vector<bool>
#define pb push_back
#define umap unordered_map
#define pii pair<int,int>
#define ll long long
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define INF 1e9
#define fora(i, a, b) for(ll i = a; i <= b; i++)
#define rofa(i, a, b) for(ll i = a; i >= b; i--)
#define forb(i, a, b) for(ll i = a; i < b; i++)
#define forn(i,n) for(ll i=0;i<n;i++)
#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )

int _n;

bool dfs(vvi &adj, int node, vb &visited){
    if (visited[node]) return false;
    visited[node] = 1;
    if (node == _n) return true;
    bool r=false;
    for(int child : adj[node]){
        r = r || dfs(adj,child,visited);
    }
    return r;
}

    

void solve(){
    int n,m;
    cin >> n >> m;
    _n=n;
    vvll edges;
    vvi adj(n+1);
    while(m--){
        int a,b,x;
        cin >> a >> b>>x;
        edges.push_back({a,b,x});
        adj[a].pb(b);
    }
    vll dist(n+1,-1e18);
    dist[1] = 0;

    int V = n-1;
    while(V--){
        for(auto edge : edges){
            int a=edge[0];
            int b=edge[1];
            int x=edge[2];
            if (dist[a] + x>dist[b]) dist[b] = dist[a]+x;
        }
    }


    for(auto edge : edges){
        int a=edge[0];
        int b=edge[1];
        int x=edge[2];
        if (dist[a] + x>dist[b]){
            vb visited(n,0);
            if (dfs(adj,b,visited) && dist[b] != -1e18){
                cout << -1 << endl;
                return;
            }
        }
    }


    cout << dist[n] << endl;

}


int main(){
    solve();
}
