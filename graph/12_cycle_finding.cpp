#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <unordered_map>
#include <chrono>
#include <math.h>
#include <stack>

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

template<typename T>
void printVector(vector<T> & v){
    cout << "Priting the vector"<<endl;
    for (auto i: v){
        cout << i << " ";
    }
    cout << endl;
}

bool dfs(vector<vector<pii>> &adj, int node, vb &visited, vi &parent, vll &weights, vb &vis){
    
    visited[node] = 1;

    vis[node] = 1;
    for(auto child : adj[node]){
        ll childWeight = weights[node] + child.second;
        if (!visited[child.first]){
            parent[child.first] = node;
            weights[child.first] = childWeight;

            if (dfs(adj,child.first, visited,parent,weights, vis)){
                return true;
            }
        }
        else {
            //caught a cycle
            if(childWeight < weights[child.first]){
                //caught a negative weight cycle
                stack<int> stk;
                int h = child.first;
                stk.push(h);
                h = node;
                while(h != child.first){
                    stk.push(h);
                    h = parent[h];
                }
                cout << "YES" << endl;
                cout << child.first << " ";
                while(!stk.empty()){
                    int t = stk.top();
                    stk.pop();
                    cout << t << " ";
                }
                return true;

            }

        }
    }
    visited[node] = 0;
    return false;
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<pii>> adj(n+1);
    while(m--){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
    }

    vb visited(n+1,0);
    vi parent(n+1);
    vll weights(n+1);

    vb vis(n+1,0);
    vb visn(n+1,0);
    for(int i=1;i<=n;i++){
        if (vis[i]) continue;
        if (dfs(adj,i,visited,parent,weights,vis)){
            return;
        }
    }
    cout << "NO" << endl;


}


int main(){
    ios::sync_with_stdio(false);
    solve();
}
