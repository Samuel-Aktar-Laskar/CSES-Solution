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

    
    template <typename T>
    void printMatrix(vector<vector<T>> & mat){
        cout << "Printing matrix" << endl;
        for (auto v : mat){
            for (auto e : v){
                cout << e << " ";
            }
            cout<< endl;
        }
        cout << endl;
    }

void solve(){
    int n;
    
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3,0));
    
    forn(i,n){
        cin >> arr[i][0];
        cin >> arr[i][1];
    }
    forn(i,n) arr[i][2] = i;
    sort(arr.begin(), arr.end(), [](const vi & a, const vi & b) -> bool {
        if (a[0] != b[0]) return a[0] < b[0];
        else return a[1] > b[1];
        return a[2] < b[2];
    });
    //printMatrix(arr);
    vector<int> mx(n);
    forn(i,n){
        if (i==0) mx[i] = arr[i][1];
        else mx[i] = max(mx[i-1], arr[i][1]);
    }
    vector<int> mn(n);
    for(int i=n-1;i>=0;i--){
        if (i==n-1) mn[i] = arr[i][1];
        else mn[i] = min(mn[i+1],arr[i][1]);
    }
    vector<vector<int>> ans(n,vector<int>(3,0));
    
    forn(i,n){
        //contained
        if (i==0){
            ans[i][1] = 0;
        }
        else {
            if (mx[i-1] >= arr[i][1]) ans[i][1] = 1;
        }

        // contains
        if (i== n-1){
            ans[i][0] = 0;
        }
        else {
            if (mn[i+1] <= arr[i][1]) ans[i][0] = 1;
        }
        ans[i][2]=arr[i][2];
    }
    //printMatrix(ans);
    sort(ans.begin(), ans.end(), [](const vi & a, const vi & b) -> bool {
        return a[2] < b[2];
    });
    //printMatrix(ans);
    forn(i,n){
        cout << ans[i][0] << " ";
    }
    cout << endl;
    forn(i,n){
        cout << ans[i][1] << " ";
    }


}


int main(){
   solve();
}
