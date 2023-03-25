#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <unordered_map>
#include <queue>

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

void solve(){

}

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    priority_queue<int, vector<int> , greater<int>> desiredSize;
    forn(i,n){
        int temp;
        cin >> temp;
        desiredSize.push(temp);
    }
    priority_queue<int, vector<int> , greater<int> > apartmentSize;
    forn(i,m){
        int temp;
        cin >> temp;
        apartmentSize.push(temp);
    }

    
    
    int ans=0;
    while (!desiredSize.empty() && !apartmentSize.empty()){
        int a = desiredSize.top();
        int b = apartmentSize.top();
        if (abs(a-b) <= k){
            desiredSize.pop();
            apartmentSize.pop();
            ans++;
        }
        else if (a < b){
            desiredSize.pop();
        }
        else apartmentSize.pop();
    }
    cout << ans << endl;
    
    

}
