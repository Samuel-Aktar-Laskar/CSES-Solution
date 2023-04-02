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

    

void solve(){
    int n,m,q;
    cin >> n >>  m >> q;
    vvll dist(n+1, vll(n+1,1e18));
    for(int i=1;i<=n;i++){
        dist[i][i]  = 0;
    }

    while(m--){
        ll a,b,c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[a][b], c);
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    while(q--){
        int a,b;
        cin >> a >> b;
        if (dist[a][b] == 1e18) cout << -1 << endl;
        else cout << dist[a][b] << endl;
    }
}


int main(){
    solve();
}
