#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    string n;
    cin >> n;
    vector<int> v(26 , 0);
    for (char c : n){
        v[c - 'A']++;
    }

    int index = -1;
    int odd = 0;

    for (int i = 0; i < v.size() ; i++){
        if (v[i] % 2 == 1){
            index = i;
            odd++;
        }
    }

    if (odd > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    char c;
    if (odd == 1){
        c = (char)(index + 'A');
        v[index]--;
    }

    string ans = "";
    for (int i = 0 ; i < v.size() ; i++){
        char ci = 'A' + i;
        int num = v[i]/2;
        while (num > 0){
            ans += ci ;
            num--;
        }
    }

    if (odd == 1){
        ans += c;
    }

    for (int i = v.size()-1 ; i >= 0  ; i--){
        char ci = 'A' + i;
        int num = v[i]/2;
        while (num > 0){
            ans += ci ;
            num--;
        }
    }

    cout << ans << endl;


}
