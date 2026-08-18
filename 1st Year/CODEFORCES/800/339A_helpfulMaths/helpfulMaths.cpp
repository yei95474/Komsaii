#include <bits/stdc++.h>
using namespace std;

int main () {
    string x;
    cin>>x;

    sort(x.begin(), x.end(), std::greater<int>());

    for (int i=x.length()-1; x[i]=='+'; i--) {
        x.pop_back();
    }
    
    sort(x.begin(), x.end());
    string dest;
    for (int i=0; i<x.length()-1; i++) {
        dest.push_back(x[i]);
        dest.push_back('+');
    }
    dest.push_back(x[x.length()-1]);
    cout<<dest<<endl;
}