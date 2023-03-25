#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){

    string s;
    cin >> s;
    int m = 1;
    int counter = 1;
    for (int i = 1 ; i < s.size() ;i++){
        if (s[i] == s[i-1]){
            counter ++;
            m = max(m , counter);
        }
        else counter = 1;
    }
    cout << m;
}



