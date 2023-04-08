#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <unordered_map>
#include <chrono>
#include <math.h>
#include <queue>
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


bool dfs(vvi &adj, int i, vb &visited, vb &vis, stack<int> &touch, vi &parent){

    vis[i] = 1;
    touch.push(i);

    for(int child : adj[i]){
        if (visited[child]) continue;
        parent[child]=i;
        if (vis[child]){
            //foud a cycle
            vi ans;
            int u=i;
            ans.pb(child);
            while(u!=child){
                ans.pb(u);
                u = parent[u];
            }
            ans.pb(child);
            reverse(ans.begin(), ans.end());
            cout << ans.size() << endl;
            for(int x : ans){
                cout << x << " ";
            }

            cout << endl;
            return true;
        }

        if (dfs(adj, child, visited, vis, touch, parent)) return true;

    }

    vis[i] = 0;

    return false;
}

void solve(){
    int n,m;
    cin >> n >>m;
    vvi adj(n+1);
    while(m--){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
    }

    vb visited(n+1,0);
    vb vis(n+1,0);
    vi parent(n+1);


    for(int s=1;s<=n;s++){
        if (visited[s]) continue;
        
        stack<int> touch;
        if (dfs(adj,s,visited,vis,touch,parent)){
            return;
        }
        
        while(!touch.empty()){
            visited[touch.top()] = 1;
            touch.pop();
        }

    }
    cout << "IMPOSSIBLE" << endl;


}


int main(){
    solve();
}
