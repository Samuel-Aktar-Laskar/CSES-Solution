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

    
void fill(vvc &map, int i, int j){
    int n = map.size();
    int m = map[0].size();
    if (i<0 || i >= n || j < 0 || j >= m) return;
    if (map[i][j] == '#') return;
    map[i][j] = '#';
    fill(map, i+1, j);
    fill(map, i, j+1);
    fill(map, i-1,j);
    fill(map,i,j-1);
}

void solve(){
    int n,m;
    cin >> n >>m;
    vvc map(n,vc(m));
    forn(i,n){
        forn(j,m){
            cin >> map[i][j];
        }
    }
    int ans = 0;
    forn(i,n){
        forn(j,m){
            if (map[i][j] == '.'){
                fill(map,i,j);
                ans++;
            }
        }
    }
    cout << ans << endl;




}


int main(){
    solve();
}
