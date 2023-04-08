#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <unordered_map>
#include <chrono>
#include <math.h>
#include <queue>
#include <random>

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

void solve(){
    int n,m;
    cin >> n >> m;
    vvi adj(n+1);
    while(m--){
        int a,b;
        cin >>a>>b;
        adj[a].pb(b);
    }
    vi dist(n+1,0);
    priority_queue<pii, vector<pii>, greater<pii>> q; // weight - node 
    q.push({0,1});

    vb visited(n+1,0);
    vi parent(n+1);
    while(!q.empty()){  
        int top =q.top().second;
        q.pop();
        for(int child : adj[top]){
            if (dist[child] > dist[top]- 1){
                dist[child] =dist[top]-1;
                q.push({dist[child],child});
                parent[child] = top;
            }
        }
    }

    if (dist[n]==0){
        cout << "IMPOSSIBLE"<<endl;
        return;
    }
    int x=n;
    vi ans;
    ans.pb(x);
    while(x!=1){
        x=parent[x];
        ans.pb(x);
    }
    reverse(ans.begin(),ans.end());
    cout <<ans.size() <<endl;
    for(int i :ans){
        cout << i << " ";
    }
    cout << endl;
}


int main(){
    ios::sync_with_stdio(false);
    solve();
}

//thielldld 