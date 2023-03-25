#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

void printSet(multiset<int> & mp){
    for(auto i : mp){
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int n, k;
    cin >> n >> k;

    // Read the array
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Multiset to store the current window
    multiset<int> window;

    // Process the first window
    for (int i = 0; i < k; i++)
        window.insert(a[i]);

    // Print the median of the first window
    multiset<int>::iterator it = window.begin();
    advance(it, k / 2);
    if (k % 2 == 0) it--;
    cout << *it << " ";

    // Process the rest of the array
    for (int i = k; i < n; i++)
    {

        //check if the element to be removed is the iter
        if (it == window.find(a[i-k])){
            window.insert(a[i]);
            window.erase(window.find(a[i-k]));
            
            it = window.begin();
            advance(it, k / 2);
            if (k % 2 == 0) it--;
            cout << *it << " ";

        }
        else {
            
            //cout << "i is " << i << endl;
            //printSet(window);
            //check if same side
            bool same_side = (a[i] > *it) == (a[i-k] > *it);
            if (same_side){
                cout << "same side " << endl;
                cout << *it << " ";
                window.insert(a[i]);
                window.erase(window.find(a[i-k]));
            }
            else if (a[i] > *it){
                window.insert(a[i]);
                window.erase(window.find(a[i-k]));
                cout << "right side " << endl;
                it++;
                cout << *it << " ";
            }
            else {
                window.insert(a[i]);
                window.erase(window.find(a[i-k]));
                cout << "left side " << endl;
                it--;
                cout << *it << " ";
            }


        }
        
    }

    cout << endl;
    return 0;
}
