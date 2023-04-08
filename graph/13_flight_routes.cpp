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

    
typedef pair<ll,int> pll;

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<pii>> adj(n+1);
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].pb({b,c});
    }
    vi visited(n+1,0);
    vector<priority_queue<ll>> dist(n+1);

    dist[1].push(0);



    priority_queue<pll, vector<pll>, greater<pll>> q; //weight-node
    q.push({0,1});



    while(!q.empty()){

        auto top = q.top();

        q.pop();
        if (top.first > dist[top.second].top()) continue;

        for(auto child : adj[top.second]){
            int v = child.first;
            
            ll w = child.second;

            ll tmp = top.first+ w;

            if (dist[v].size() < k){
                dist[v].push(top.first + w);
                q.push({tmp, v});
            }
            else if (top.first + w < dist[v].top()){
                dist[v].pop();
                dist[v].push(top.first + w);
                q.push({tmp, v});
            }
            
            
            



        }
        
    }
    vll ans;

    while(k--){
        ll top = dist[n].top();
        dist[n].pop();
        ans.pb(top);
    }
    reverse(ans.begin(), ans.end());
    for(ll a : ans) cout << a << " ";
    cout << endl;

}


int main(){
    solve();
}
