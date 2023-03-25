#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <unordered_map>
#include <chrono>
#include <math.h>
#include <queue>
#include <stack>
#include <map>

using namespace std;

#define ull unsigned long long
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vc vector<char>
#define vi vector<int>
#define vvb vector<vector<bool>> 
#define vb vector<bool>
#define pb push_back
#define umap unordered_map
#define pii pair<int,int>
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

bool check(vvc &grid, int i, int j){
    int n=grid.size();
    int m=grid[0].size();
    if (i<0 || j <0 || i>=n || j>=m || grid[i][j] == '#') return false;
    else {
        grid[i][j]='#';
        return true;
        }
}


void printPath(map<pii,pii> &parent, pii &A, pii &B){
    stack<pii> stk;
    pii node = B;
    while(node != A){
        stk.push(node);
        node = parent[node];
    }
    pii prev = A;
    while(!stk.empty()){
        auto node = stk.top();
        stk.pop();
        int i1 = prev.first;
        int j1 = prev.second;
        int i2 = node.first;
        int j2 = node.second;
        prev=node;

        if (j2>j1)cout << "R";
        else if (j2<j1) cout << "L";
        else if (i2>i1) cout << "D";
        else if (i2<i1) cout << "U";
    }
}

void solve(){
    int n,m;
    cin >> n >> m;
    vvc grid(n,vc(m));
    pii A,B;
    forn(i,n){
        forn(j,m){
            char c;
            cin >> c;
            grid[i][j]=c;
            if (c=='A') A = pii(i,j);
            else if (c=='B') B = pii(i,j);
        }
    }
    //BFS
    map<pii,pii> parent;

    queue<pii> q;
    q.push(A);
    grid[A.first][A.second] = '#';
    int len =0;
    while(!q.empty()){
        int siz = q.size();
        while(siz--){
            auto top = q.front();
            int i=top.first;
            int j=top.second;
            if (top==B){
                cout << "YES" << endl;
                cout << len << endl;
                printPath(parent,A,B);
                return;
            }
            q.pop();
            if (check(grid,i+1,j)){
                q.push(pii(i+1,j));
                parent[pii(i+1,j)] = top;
            }
            if (check(grid,i,j+1)){
                q.push(pii(i,j+1));
                parent[pii(i,j+1)]=top;
            }
            if (check(grid,i-1,j)){
                q.push(pii(i-1,j));
                parent[pii(i-1,j)]=top;
            }
            if (check(grid,i,j-1)){
                q.push(pii(i,j-1));
                parent[pii(i,j-1)]=top;
            }

        }
        len++;

    }
    cout << "NO" << endl;



}


int main(){
    solve();
}
