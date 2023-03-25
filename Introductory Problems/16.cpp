#include <bits/stdc++.h>

#define ll long long

using namespace std;

void print(vector<int> v){
    cout << endl;
    for (int i : v){
        cout << i << " " ;
    }
    cout << endl;
}

ll diff = INT_MAX;
ll sum = 0;

void solve(vector<ll> & v , int i, ll s){
    if (i == v.size()){
        if (diff > abs((sum - 2 * s))) diff = abs(sum - 2*s);
        return;
    }
    solve(v , i+1 , s);
    solve(v , i+1 , s + v[i]);
}

int main(){
    int n;
    cin >> n;
    vector<ll> w;
    for (int i = 0 ; i < n ;i++){
        ll t;
        cin >> t;
        sum += t;
        w.push_back(t);
    }
    solve(w , 0 , 0);
    cout << diff << endl;

}
