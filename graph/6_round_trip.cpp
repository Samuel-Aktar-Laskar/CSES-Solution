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

template<typename T>
void printVector(vector<T> & v){
    cout << "Priting the vector"<<endl;
    for (auto i: v){
        cout << i << " ";
    }
    cout << endl;
}

int dfs(vvi &adj, int node, vb &vis, vi &parent){
    for(auto child : adj[node]){
        if (child==parent[node]) continue;
        else if (vis[child]){
            //found cycle
            parent[child] = node;
            return child;
        }

        parent[child] = node;
        vis[child]=1;
        int temp = dfs(adj, child,vis, parent);
        if (temp) return temp;
    }
    return 0;
}
    

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

    vi parent(n+1);
    vb vis(n+1,0);
    for(int i=1;i<=n;i++){
        if (vis[i]) continue;
        vis[i]=1;
        int child = dfs(adj,i,vis,parent);

        if (child){
            vi path;
            path.pb(child);
            int node = parent[child];
            while(node != child){
                path.pb(node);
                node = parent[node];
            }
            cout << path.size()+1 << endl;
            for(int i : path){
                cout << i << " ";
            }
            cout << child;
            return;
        }

    }

    cout << "IMPOSSIBLE" << endl;

}


int main(){
    solve();
}
