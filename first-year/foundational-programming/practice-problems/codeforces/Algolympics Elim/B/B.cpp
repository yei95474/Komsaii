#include <bits/stdc++.h>

using namespace std;


int main () {
    int n;
    cin>>n;
    vector<int> people(n);
    vector<int> nnn(n);
    int k1,k2,k;
    cin>>k1>>k2>>k;

    nnn[0] = k1; 
    nnn[1] = k2;

    int ctr=2;

    for(int i=2; i<n; i++ ) {
        int c;
        cin>>c;
        for (int j=0; j<c; j++) {
            int temp;
            cin>>temp;
            nnn.push_back(temp);
            ctr++;
        }
        
    }

    for (int i=0; i<n; i++){
        cout<<nnn[i];

    }
    cout<<"\n";
}
