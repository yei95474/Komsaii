#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, c=0, div=5;
    cin>>x;
    while (x>0) {
        if (x>=div) {
            x-=div;
            c++;
        }
        else {
            div--;
        }
    }
    cout<<c;
}