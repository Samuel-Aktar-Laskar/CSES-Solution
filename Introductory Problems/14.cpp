#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve(int n , int i , int m , int j){
    if (n == 1){
        cout << i << " " << j<<endl;
        return;
    }
    solve(n-1 ,i , j , m );
    solve(1 , i , m , j);
    solve(n-1 , m , i , j);
}

int main(){

    int n;
    cin >> n;
    int ans = 1;

    for (int i = 1 ; i < n ;i++){
        ans = ans * 2 + 1;
    }
    cout << ans << endl;


    solve(n , 1 , 2 ,3);

}
