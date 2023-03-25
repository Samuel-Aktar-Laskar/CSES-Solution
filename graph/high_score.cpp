#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <unordered_map>
#include <chrono>
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
#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )

    

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    forn(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    vector<bool> visited(n+1,0);
    vector<ll> score(n+1,0);
    vector<int> parents(n+1);
    parents[1]= 1;

    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(auto edge : adj[f]){
            int node = edge.first;
            int weight = edge.second;

            parents[node] = f;
            if (!visited[node]){
                //simple
            }
            else {
                //visited
                ll newWeight = score[f] + weight;
                if (newWeight <= score[node]){
                    //simple
                }
                else {
                    //check for cycle
                    int curNode = f;
                    while(curNode != 1){
                        if (curNode == node){
                            cout << -1 << endl;
                            return;
                        }
                        curNode = parents[curNode];
                    }

                    //no cycle 
                    


                }
            }
        }
    }
}


int main(){
    solve();
}
