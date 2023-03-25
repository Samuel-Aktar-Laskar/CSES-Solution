#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <map>
#include <unordered_map>
#include <time.h>

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


int main(){
    time_t start,end;
    time(&start);
    ios_base::sync_with_stdio(false);
    ll n,x;
    cin >> n >> x;
    vector<int> arr(n);
    int N = 0;
    forn(i,n) {
        cin >> arr[i];
        N = max(N, arr[i]);
        }
    umap<ll,vector<int>> mp;
    vector<bool> m(N+1);
    forn(i,n){
        m[arr[i]] = 1;
        mp[arr[i]].push_back(i);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int f = x - arr[i] - arr[j];
            if (f >= 0 && f <= N && m[f]){
                auto vec = mp[f];
                int k=0;
                while(k < vec.size() && (vec[k] == i || vec[k] == j)) k++;
                if (k == vec.size()) continue;
                cout << i+1 << " " << j+1 << " " << vec[k]+1 << endl;
                // time(&end);
                // cout << "TIME TAKEN :" << double(end-start) << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    // time(&end);
    // cout << "TIME TAKEN :" << double(end-start) << endl;
}
