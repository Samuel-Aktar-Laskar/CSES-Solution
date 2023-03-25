#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <unordered_map>
#include <chrono>

using namespace std;

#define ull unsigned long long
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vc vector<char>
#define vi vector<int>
#define vvb vector<vector<bool>> 
#define vb vector<bool>
#define umap unordered_map
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
    int n;cin >> n;
    int x; cin >> x;
    unordered_map<int,vector<int>> mp;
    vector<int> arr(n);
    forn(i,n) cin >> arr[i];
    forn(i,n){
        mp[arr[i]].push_back(i);
    }
    forn(i,n){
        auto vec = mp[x-arr[i]];
        if (vec.size() > 0){
            int j=0;
            while (j < vec.size() && vec[j] == i) j++;
            if (j == vec.size()) continue;
            cout << i+1 << " " << vec[j] +1<< endl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}


int main(){
    solve();
}
