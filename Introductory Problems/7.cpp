#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long

int main(){
    int n;
    cin >> n ;
    for (ull k = 1 ; k <= n ; k++){
        if (k <= 2){
            cout << k*k*(k*k-1)/2 << endl;
        }
        else cout << k*k * (k*k -1) / 2 - 4*(k-1)*(k-2)<<endl;
    }
}

