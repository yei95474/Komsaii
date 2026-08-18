#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    int n;
    int sure=0, c=0, temp;
    cin>>n;

    for(int i=0;i<n;i++) {
        for (int i=0; i<3; i++) {
            cin>>temp;
            if(temp==1) {
                c++;
            }
        }
        if (c>=2) {
            sure++;
        }
        c=0;
    }
    cout<<sure;
    return 0;
}