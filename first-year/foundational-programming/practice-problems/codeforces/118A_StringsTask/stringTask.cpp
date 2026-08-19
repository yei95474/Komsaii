#include <bits/stdc++.h>
using namespace std;

int main() {
    string x, dest;
    cin>>x;
    transform(x.begin(),x.end(),x.begin(), [](char x){return tolower(x);});
    for(int i=0; i<x.length(); i++){
        char temp;
        if (x[i] !='a' && x[i]!='e' && x[i] !='i' && x[i]!='o' && x[i] !='u' && x[i]!='y') {
            temp=x[i];
            dest.push_back('.');
            dest.push_back(temp);
        }
    }
    cout<<dest;
}