#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <unordered_map>

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
    int n;
    cin >> n;
    umap<int,int> mp;
    forn(i,n) {
        int temp;
        cin >> temp;
        mp[temp]++;
    }
    cout << mp.size() << endl;
}
