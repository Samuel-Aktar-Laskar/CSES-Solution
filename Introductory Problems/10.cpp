
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long

int main(){
    int n;
    cin >> n;

    int f = 0;
    int t = 0;

    int i = n;

    while (i > 4){
        f += i / 5;
        i = i / 5;
    }

    i = n;
    while (i > 1){
        t += i / 2;
        i = i/2;
    }
    cout << min(f,t);


}
