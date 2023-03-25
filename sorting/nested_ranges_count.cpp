#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <unordered_map>
#include <chrono>
#include <queue>
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
    vvi arr(n, vi(3,0));
    forn(i,n){
        int a,b;
        cin >> a >> b;
        arr[i][0] = a;
        arr[i][1] = b;
        arr[i][2] = i;
    }
    sort(arr.begin(), arr.end(), [](const vi & a, const vi & b) -> bool {
        if (a[0] != b[0]) return a[0] < b[0];
        else return a[1] > b[1];
    });

    vvi ans(n, vi(3,0)); // contained, containes , index
    forn(i,n) ans[i][2] = arr[i][2];
    //contained part
    multiset<int>  mpq;
    forn(i,n){
        if (i==0){
            //can not be contained
            mpq.insert(arr[i][1]);
            ans[i][0] = 0;
        } else {
            int ct =0;
            auto iter = mpq.rbegin();
            while (iter != mpq.rend()){
                int top = *iter;
                if (top < arr[i][1]) break;
                ct++;
                iter++;
            }
            ans[i][0] = ct;
            mpq.insert(arr[i][1]);
        }
    }
    //contains part
    multiset<int> pq;
    for(int i=n-1; i>=0; i--){
        if (i== n-1){
            //can not contain
            pq.insert(arr[i][1]);
            ans[i][1] = 0;
        }
        else {
            int ct=0;
            auto iter = pq.begin();
            while(iter != pq.end()){
                int top = *iter;
                if (top > arr[i][1]) break;
                iter++;
                ct++;
            }
            pq.insert(arr[i][1]);
            ans[i][1] = ct;
        }
    }

    sort(ans.begin(), ans.end(), [](const vi & a, const vi & b) -> bool {
        return a[2] < b[2] ;
    });

    //printMatrix(ans);
    forn(i,n){
        cout << ans[i][1] << " ";
    }
    cout << endl;
    forn(i,n){
        cout << ans[i][0] << " ";
    }
}


int main(){
    solve();
}
