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
    int n;
    cin >> n;
    vector<pair<int,int>> interval(n);
    forn(i,n){
        cin >> interval[i].first;
        cin >> interval[i].second;
    }
    sort(interval.begin(), interval.end());



    int ans=0;


    int i=0;

    while(i < n){
        int end = interval[i].second;
        while (i<n && interval[i].first < end){
            i++;
            end = min(end, interval[i].second);
        }
        ans++;
    }

    cout << ans << endl;

 

}


int main(){
solve();
}
