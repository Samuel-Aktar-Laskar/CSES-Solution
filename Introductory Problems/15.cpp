#include <bits/stdc++.h>

#define ll long long

using namespace std;

int fact(int n){
    int ans = 1;
    for (int i = 1 ; i <= n ;i++){
        ans *= i;
    }
    return ans;
}

int main(){
    string n;
    cin >> n;
    sort(n.begin() , n.end());


    vector<int> v(26 , 0);
    for (char c : n){
        v[c - 'a']++;
    }
    int l = fact(n.size());
    for (int i : v){
        l /= fact(i);
    }
    cout << l << endl;

     cout << n << endl;

    while(true){
        int prev = n.back();
        int m = -1;
        for (int i = n.size() - 2 ;i >= 0 ; i--){
            if (n[i] < prev){
                m = i;
                break;
            }
            else {
                prev = n[i];
            }
        }
        if (m == -1) break;

        int p = -1;
        for (int i = n.size() -1 ; i >= 0 ; i--){
            if (n[i] > n[m]){
                p = i;
                break;
            }
        }

        char mc = n[m];
        n[m]= n[p];
        n[p] = mc;
        reverse(n.begin()+m+1,n.end());

        cout << n << endl;



    }


}
