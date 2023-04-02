#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <unordered_map>
#include <chrono>
#include <math.h>
#include <queue>

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
    int m = grid[0].size();
    if (i<0 || j <0 || i >=n || j>=m) return false;
    if (grid[i][j] == '#' || grid[i][j] == 'M' || grid[i][j] == 'A') return false;
    return true;
}

bool check2(vvc &grid, int i, int j){
    int n=grid.size();
    int m = grid[0].size();
    if (i<0 || j <0 || i >=n || j>=m) return false;
    if (grid[i][j] == '#' || grid[i][j] == 'M') return false;
    return true;
}

    
bool dfs(vvc &grid, int i,int j, vc &path){
    if (i==0 || j==0 || i==grid.size()-1 || j== grid[0].size()-1) return true;
    bool b = 0;
    if (check2(grid,i+1,j)){
        grid[i+1][j] = '#';
        b = dfs(grid,i+1,j,path);
        if (b){
            path.pb('D');
            return true;
        }
    }

    if (check2(grid,i,j+1)){
        grid[i][j+1] = '#';
        b = dfs(grid,i,j+1,path);
        if (b){
            path.pb('R');
            return true;
        }
    }

    if (check2(grid,i-1,j)){
        grid[i-1][j] = '#';
        b = dfs(grid,i-1,j,path);
        if (b){
            path.pb('U');
            return true;
        }
    }

    if (check2(grid,i,j-1)){
        grid[i][j-1] = '#';
        b = dfs(grid,i,j-1,path);
        if (b){
            path.pb('L');
            return true;
        }
    }

    return false;



}


void solve(){
    int n,m;
    cin >> n >> m;
    vvc grid(n, vc(m));

    int ia,ja;
    deque<tuple<int,int,char>> q;
    forn(i,n){
        forn(j,m){
            cin >> grid[i][j];
            if (grid[i][j] == 'A'){
                q.push_back({i,j,'A'});
                ia =i;
                ja=j;
            }
            else if (grid[i][j] == 'M'){
                q.push_front({i,j,'M'});
            }
        }
    }

    while(!q.empty()){
        auto top = q.front();
        int i=get<0>(top);
        int j=get<1>(top);
        char c = get<2>(top);

        q.pop_front();
        
        if (check(grid,i,j+1)){
            if (c=='M') {
                grid[i][j+1] = 'M';
                q.push_back({i,j+1,'M'});
            }
            else {
                grid[i][j+1] = 'A';
                q.push_back({i,j+1,'A'});
            }
        }
        if (check(grid,i+1,j)){
            if (c=='M') {
                grid[i+1][j] = 'M';
                q.push_back({i+1,j,'M'});
            }
            else {
                grid[i+1][j] = 'A';
                q.push_back({i+1,j,'A'});
            }
        }
        if (check(grid,i,j-1)){
            if (c=='M') {
                grid[i][j-1] = 'M';
                q.push_back({i,j-1,'M'});
            }
            else {
                grid[i][j-1] = 'A';
                q.push_back({i,j-1,'A'});
            }
        }

        if (check(grid,i-1,j)){
            if (c=='M') {
                grid[i-1][j] = 'M';
                q.push_back({i-1,j,'M'});
            }
            else {
                grid[i-1][j] = 'A';
                q.push_back({i-1,j,'A'});
            }
        }


    }
    vc path;
    bool b = dfs(grid,ia,ja,path);
    if (b){
        cout << "YES" << endl;
        cout << path.size() << endl;
        reverse(path.begin(), path.end());
        for(char c : path){
            cout << c;
        }
        cout << endl;
    }
    else cout << "NO" << endl;

}


int main(){
    solve();
}
