#include <bits/stdc++.h>
using namespace std;

int main () {
    int x,y,c=0;
    cin>>x>>y;

    if (x==1 && y==1) {
        cout<<1;
        return 0;
    }
    while (x<=y) {
        c++;
        y*=2;
        x*=3;
    }
    cout<<c;
}