#include <bits/stdc++.h>

using namespace std;


int main () {
    int n;
    cin>>n;
    vector<int> people(n);
    int k1,k2,k;
    cin>>k1>>k2>>k;

    for(int i=0; i<n; i++ ) {
        int c;
        cin>>c;
        for (int j=0; j<c; j++) {
            int temp;
            cin>>temp;
            people[j]=temp;
        }

    }

    for (int i=0; i<n; i++){
        cout<<people[i];

    }
    cout<<"\n";
}
