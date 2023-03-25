#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
int main(){
    ll t ;
    cin >>t;
    while (t > 0){
            ll r;
            cin >> r;
            ll c ;
            cin >> c;

            ll w = max(r,c)-1;
            ull n = w*(w-1) + w;
            ull ans;
            if ( w % 2 == 0){
                if (w+1 == r){
                    ans = n + c;
                }
                else ans = n + w + 1 + w - r+1;
            }
            else {
                if (w + 1 == c){
                    ans = n + r;
                }
                else ans = n + 2*(w+1) -c;
            }
            cout << ans << "\n";

        t--;
    }
    }
