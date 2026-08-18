#include <bits/stdc++.h>
using namespace std;

int main() {
    int k,w,n,total=0;
    cin>>k>>w>>n;
    for(int i=1; i<=n; i++) {
        total += (k*i);
    }
    int borrow=total-w;
    if (borrow < 0) {
        borrow = 0;
    }
    cout<<borrow;
}