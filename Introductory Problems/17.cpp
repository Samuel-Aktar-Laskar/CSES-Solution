#include <bits/stdc++.h>

#define ll long long

using namespace std;

void attack(char grid[8][8]  , int i, int j){

    for (int r = 0 ; r < 8 ; r++){
        grid[r][j] = '*';
    }
    int r = i;
    int c = j;
    while (c < 8 && c >= 0 && r >= 0){
        grid[r][c] = '*' ;
        r--;
        c++;
    }
    r = i;
    c = j;
    while (c < 8 && c >= 0 && r >= 0){
        grid[r][c] = '*' ;
        r--;
        c--;
    }
}

void print(char  grid[8][8]){
    cout << "Printing " << endl;
      for (int i = 0 ;i < 8 ;i++){
        for (int j = 0; j < 8 ; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int ans = 0;

void solve(char  grid[8][8]  , int r){
    //cout << "r is " << r << endl;
    //print(grid);
    for (int c = 0 ; c < 8 ; c++){
            if (grid[r][c] == '*') continue;

        if (r == 0){
            ans ++;
            continue;
        }
        char  _grid[8][8];
        copy(&grid[0][0] , &grid[0][0] + 8*8, &_grid[0][0]);
        attack(_grid , r, c);
        solve(_grid , r-1);
    }
}

int main(){
    char grid[8][8] ;

    for (int i = 0 ;i < 8 ;i++){
        for (int j = 0; j < 8 ; j++){
            cin >> grid[i][j];
        }
    }
    solve(grid, 7);
    cout <<ans << endl;



}
