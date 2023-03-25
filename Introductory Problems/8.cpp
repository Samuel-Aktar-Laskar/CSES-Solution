#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long

int main(){
    int n ;
    cin >> n;
    if ((n-3)%4 == 0){
            cout << "YES" << endl;
        int i = 3;
        cout << n/2 << endl;
        while( i <= n){
            cout << i << " ";
            if (i+1 > n) break;
            cout << i+1 << " ";
            i += 4;
        }
        cout << endl;
        cout << n/2 + 1 << endl;

        i = 1;
        while (i <= n-1){
            cout << i << " ";
            if (i+1 > n-1) break;
            cout << i+1 << " ";
            i += 4;
        }
    }
    else if (n % 4 == 0){
        cout << "YES" << endl;
        cout << n /2 << endl;
        int i = 1 ;
        int j = n;
        while (i < j){
            cout << i << " " <<  j << " ";
            i +=2;
            j -=2;
        }
        cout << endl;
        cout << n /2;
        cout << endl;
        i = 2;
        j = n-1;
        while (i < j){
            cout << i << " " <<  j << " ";
            i +=2;
            j -=2;
        }
        cout << endl;
    }
    else cout << "NO";
}
