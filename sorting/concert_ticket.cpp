#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <unordered_map>
#include <chrono>
#include <set>

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
    int n,m;
    cin >> n >> m;
    multiset<int> ticketPrice;
    forn(i,n){
        int temp;
        cin >> temp;
        ticketPrice.insert(temp);
    }
    forn(i,m){
        int price;
        cin >> price;
        auto iter = ticketPrice.upper_bound(price);
        if (iter == ticketPrice.begin()){
            cout << -1 << endl;
            continue;
        }
        iter--;
        cout << *iter << endl;
        ticketPrice.erase(iter);
    }

}


int main(){
    solve();
}
