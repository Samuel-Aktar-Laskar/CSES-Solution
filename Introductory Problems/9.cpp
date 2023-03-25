
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long



int main(){
    ll n;
    cin >> n;
    ll ans = 1;
    for (int i = 1 ; i <= n ;i++){
        ans *= 2;
        if (ans > pow(10, 9)+7){
            ans = ans % (ll)(pow(10,9)+7);
        }
    }
    cout << ans;

}
