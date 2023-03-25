#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int t;
    cin >> t ;

    for (; t > 0 ; t--){
        ll a;
    cin >> a;
    ll b;
    cin >> b;
    ll p = min(a,b) - abs(a-b);
    if (p < 0){
        cout << "NO"<<endl;
    }
    else {
        if (p % 3 == 0){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }


    }


}
