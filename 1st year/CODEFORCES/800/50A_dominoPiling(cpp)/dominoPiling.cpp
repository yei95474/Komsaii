#include <bits/stdc++.h>
using namespace std;

int main() {
    int m,n;
    cin>>m>>n;

    if(n%2==0) {
        cout<<m*(n/2);
    }
    if(n%2!=0) {
        if(m%2==0) {
            cout<<(m*(n/2))+(m/2);
        }
        if(m%2!=0) {
            cout<<(m*(n/2))+(m/2);
        }
    }
    return 0;
}