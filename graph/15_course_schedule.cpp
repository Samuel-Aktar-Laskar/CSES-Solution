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



bool visit(int i,vvi &adj, vi &color, vi &ans){
    if (color[i] == 2) return false;
    if (color[i] == 1) return true;

    color[i] = 1;
    for(int child : adj[i]){
        if (visit(child,adj,color,ans)) return true;
    }

    color[i] = 2;
    ans.pb(i);
    return false;
}
    

void solve(){
    int n,m;
    cin >> n >> m;
    vvi adj(n+1);
    while(m--){
        int  a,b;
        cin >>a>>b;
        adj[a].pb(b);
    }


    vi ans;
    vi color(n+1,0);
    for(int i=1;i<=n;i++){
        if (color[i] == 0){
            if (visit(i,adj,color,ans)){
                cout <<"IMPOSSIBLE" << endl;
                return;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    for(int i : ans) cout << i <<  ' ';
    cout << endl;




}


int main(){
    solve();
}
