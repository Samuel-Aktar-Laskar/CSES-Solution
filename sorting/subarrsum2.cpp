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


int bSearch(vector<int> & vec, int k){
    if (vec.size()>0 && vec[0] > k) return 0;
    else if (k > vec.back()) return -1;
    //we have to find element just greater than k and return its index
    int min = 0;
    int max = vec.size()-1;
    while(min < max){
        if (vec[min] == k) return min+1;
        if (vec[max] == k) return max+1;
        int mid = (min+max)/2;
        if (vec[mid] == k) return mid+1;
        if (min + 1 == max) return max;

        if (vec[mid] > k) max  = mid;
        else min = mid;
    }
    return -1;

}
    

void solve(){
    int n,x;
    cin >> n >> x;
    vector<int> arr(n);
    forn(i,n) cin >> arr[i];
    ll S = 0;
    forn(i,n) S += arr[i];
 
    umap<ll,vector<int>> mp;
    ll sum =0;
    for(int i=n-1;i>0;i--){
        sum += arr[i];
        mp[sum].push_back(i);
    }
    mp[0].push_back(n);

    auto iter = mp.begin();
    while(iter != mp.end()){
        sort(iter->second.begin(), iter->second.end());
        iter++;
    }

    int ans=0;

    sum =0;
    for(int i=-1; i<n-1; i++){
        if (i != -1) 
            sum += arr[i];
        ll wanted = S - x - sum;
        if ( mp.find(wanted) == mp.end()) continue;
        auto vec = mp[wanted];




        
        int j = bSearch(vec, i+1);
        if (j==-1) continue;
        ans += vec.size() - j;
    }
    cout << ans << endl;
}


int main(){
    solve();
    // vector<int> arr = {1,2,5,5,6,8,9};
    // int b = bSearch(arr, 80);
    // cout << b << endl;
}
