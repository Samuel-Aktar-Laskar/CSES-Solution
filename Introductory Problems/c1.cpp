#include <bits/stdc++.h>


using namespace std;
#define ll long long

int main(){
    int l;
    cin >> l;
    ll p;
    cin >> p;
    ll ans= 0;
    for (int i = 1; i < l ;i++){
        ll h;
        cin >> h;
        if (h < p){
            ans += p - h;
            continue;
        }
        p = h;
    }
    cout << ans;
}
