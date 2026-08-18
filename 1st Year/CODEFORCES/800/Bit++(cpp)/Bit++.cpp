#include <bits/stdc++.h>
#include <cctype>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int x=0;
    cin>>n;
    string input;
    
    for(int i=0;i<n;i++) {
        cin>>input;
        transform(input.begin(), input.end(), input.begin(), ::toupper);
        if(input=="++X" || input=="X++") {
            x++;
        }
        if(input=="--X" || input=="X--") {
            x--;
        }
    }
    cout<<x;
    return 0;
}