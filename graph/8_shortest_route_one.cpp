#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <unordered_map>
#include <chrono>
#include <math.h>
#include <queue>

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
#define pii pair<long long,int>
#define ll long long
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



struct ComparePii {
    bool operator()(const pii& a, const pii& b) {
        return a.first > b.first;
    }
};


void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<pii>> adj(n+1);
    forn(i,m){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }

    vector<ll> dist(n+1,1e18);
    dist[1] = 0;

    vb visited(n+1,0);

    priority_queue<pii, vector<pii>,ComparePii> pq;
    pq.push({0,1});
    for(int i=2;i<=n;i++){
        pq.push({1e18,i});
    }


    while(!pq.empty()){
        //extract min
        while(!pq.empty() && visited[pq.top().second]){
            pq.pop();
        }
        if (pq.empty()) break;

        int minNode = pq.top().second;
        pq.pop();
        
        visited[minNode] = 1;

        //check neighbours
        for(auto node : adj[minNode]){
            int v = node.first;
            ll w = node.second;
            if (visited[v]) continue;
            if (dist[minNode] + w < dist[v]) {
                dist[v] = dist[minNode] + w;
                pq.push({dist[v],v});
                }
        }

    }

    //print dist array
    for(int i=1;i<=n;i++){
        cout << dist[i] << " ";
    }
    cout << endl;


}


int main(){
    solve();
}
