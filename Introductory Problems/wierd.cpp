#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve(ll n){

    if ( n == 1){
        cout << n;
        return;
    }
    cout << n << " ";
    if (n%2 == 0){
        solve(n/2);
    }
    else solve(n*3 + 1);
}

int main(){
    int n;
    cin >> n;
    solve(n);

}
