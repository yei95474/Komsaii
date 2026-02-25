#include <bits/stdc++.h>
using namespace std;
#define ROW 5
#define COL 5

int main() {
    int i1=0, j1=0;
    int arr[ROW][COL];
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            cin>>arr[i][j];
            if (arr[i][j]==1) {
                i1=i;
                j1=j;
            }
        }
    }

    if ((i1==0 && j1==0) || (i1==4 && j1==0) || (i1==0 && j1==4) || (i1==4 && j1==4)) {
        cout<<4;
    }
    else if ((i1==0 && j1==2) || (i1==2 && j1==0) || (i1==4 && j1==2) || (i1==2 && j1==4)) {
        cout<<2;
    }
    else if ((i1==1 && j1==1) || (i1==1 && j1==3) || (i1==3 && j1==1) || (i1==3 && j1==3)) {
        cout<<2;
    }
    else if ((i1==1 && j1==2) || (i1==2 && j1==1) || (i1==2 && j1==3) || (i1==3 && j1==2)) {
        cout<<1;
    }
    else if (i1==2 && j1==2) {
        cout<<0;
    }
    else {
        cout<<3;
    }
    return 0;
}