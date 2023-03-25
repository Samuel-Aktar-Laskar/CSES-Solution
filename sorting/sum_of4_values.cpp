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
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    forn(i,n) cin >> arr[i];
    umap<ll,vector<pair<int,int>>> mp;
    vector<bool> b(2000000001);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ll sum = arr[i] + arr[j];
            b[sum] = 1;
            mp[sum].push_back({i,j});
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ll sum = arr[i]+arr[j];
            ll diff = k - sum;
            if (diff < 0) continue;
            if (diff < b.size() && b[diff]){
                int s = 0;
                auto vec = mp[diff];
                while(s < vec.size() && (vec[s].first == i || vec[s].first == j || vec[s].second == i || vec[s].second == j)) s++;
                if (s == vec.size()) continue;
                cout << i +1<< " " << j +1<< " " << vec[s].first+1 << " " << vec[s].second+1 << endl;
                return ;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}


int main(){
    
        solve();
    
}
