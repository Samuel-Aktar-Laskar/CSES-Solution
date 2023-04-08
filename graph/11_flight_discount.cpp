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
#define vll vector<ll>
#define vvll vector<vector<ll>>
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

    
template<typename T>
void printVector(vector<T> & v){
    cout << "Priting the vector"<<endl;
    for (auto i: v){
        cout << i << " ";
    }
    cout << endl;
}

void solve(){
    int n,m;

   cin >> n >> m;
    vector<vector<pii>> adj(n+1);
    vector<vector<pii>> adjr(n+1);
    while(m--){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adjr[v].pb({u,w});
    }


    //finding dist from 1
    vector<ll> dist1(n+1,1e18);
    dist1[1] = 0;
    {    
        priority_queue<pair<ll,int>> q;
        q.push({0,1});
        vb visited(n+1,0);
        while(!q.empty()){
            while(!q.empty() && visited[q.top().second]) q.pop();
            if (q.empty()) break;

            int top = q.top().second;
            q.pop();

            for(auto child : adj[top]){
                if (visited[child.first]) continue;
                if (dist1[top] + child.second < dist1[child.first]){
                    dist1[child.first] = dist1[top] + child.second;
                    q.push({-dist1[child.first], child.first});
                }
            }

            visited[top] =1;
        }
    }
    vector<ll> dist2(n+1, 1e18);
    dist2[n]= 0;
    {    
        priority_queue<pair<ll,int>> q;
        q.push({0,n});
        vb visited(n+1,0);
        while(!q.empty()){
            while(!q.empty() && visited[q.top().second]) q.pop();
            if (q.empty()) break;

            int top = q.top().second;
            q.pop();

            for(auto child : adjr[top]){
                if (visited[child.first]) continue;
                if (dist2[top] + child.second < dist2[child.first]){
                    dist2[child.first] = dist2[top] + child.second;
                    q.push({-dist2[child.first], child.first});
                }
            }

            visited[top] =1;
        }
    }
    
    ll ans = 1e18;
    for(int i=1;i<=n;i++){
        for(auto child : adj[i]){
            int j = child.first;
            int w = child.second;
            ans = min(ans, dist1[i] + dist2[j] + w/2);
        }
    }
    
    cout << ans << endl;


}


int main(){
    solve();
}
