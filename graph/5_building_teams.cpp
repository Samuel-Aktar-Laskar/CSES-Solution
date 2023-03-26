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

    vi dsu(n+1);
    forn(i,n+1) dsu[i]=i;

    bool hasCycle = false;
    forn(i,m){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        


    }


    vi ans(n+1,0);
    

    for(int i=1;i<=n;i++){
        if (ans[i]) continue;

        ans[i]=1;
        queue<int> q;
        q.push(i);

        bool b=1;
        while(!q.empty()){
            int siz = q.size();
            while(siz--){
                int top = q.front();
                q.pop();
                for(auto node : adj[top]){
                    if (ans[node]){
                        if ((b && ans[node]==1) || (!b && ans[node]==2)){
                            cout << "IMPOSSIBLE" << endl;
                            return;
                        }
                        continue;
                    }
                    q.push(node);
                    if(b) ans[node]=2;
                    else ans[node]=1;
                }
            }
            b = !b;
        }
    }

    

    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    


}


int main(){
    solve();
}
