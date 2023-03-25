#include <bits/stdc++.h>

#define ll long long

using namespace std;





int main(){
    int n;
    cin >> n;

    vector<vector<int>> v(pow(2,n) ,vector<int>(n,0) );
    v[1][0] = 1;


    for (int i = 1 ; i < n ;i++){
        int w = i;
        ll h = pow(2, i);
        for (ll j = h ; j < 2*h ; j++){
            v[j][w] = 1;
            for (int c = 0 ; c <  w ;c++){
                v[j][c] = v[2*h - j-1][c];
            }
        }
    }

    for (int i = 0 ; i < v.size() ; i++){
        for (int  j  = v[0].size()-1; j >= 0 ; j--){
            cout << v[i][j];
        }
        cout << endl;
    }


}
