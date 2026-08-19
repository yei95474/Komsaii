#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long sum=0;
    cin>>n;
    int mat[n][3];
    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++) {
            cin>>mat[i][j];
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++) {
            sum+=mat[i][j];
        }
    }
    cout<<((sum==0)?"YES":"NO");

}