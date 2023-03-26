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
#define pii pair<int,int>
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

    

void solve(){
    int n,m;
    cin >> n >> m;
    vvi adj(n+1);
    forn(i,m){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    queue<int> q;
    q.push(n);
    vb visited(n+1,0);
    visited[n]=1;

    vi parent(n+1);
    int k=0;
    while(!q.empty()){
        int siz = q.size();
        while(siz--){
            int top = q.front();
            if (top == 1){
                cout << k+1 << endl;
                int node = 1;
                while(node != n){
                    cout << node << " ";
                    node = parent[node];
                }
                cout << n;
                cout << endl;
                return;
            }
            q.pop();
            for(auto node : adj[top]){
                if (visited[node]) continue;
                visited[node] =1;
                q.push(node);
                parent[node] = top;
            }
        }
        k++;
    }
    cout << "IMPOSSIBLE" << endl;

}


int main(){
    solve();
}
