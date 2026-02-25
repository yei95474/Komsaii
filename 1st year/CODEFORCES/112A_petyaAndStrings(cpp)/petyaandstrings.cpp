#include <bits/stdc++.h>
using namespace std;

int main() {
    string a;
    string b;
    cin>>a;
    cin>>b;
    int len=a.length(), flag=0;
    transform(a.begin(),a.end(),a.begin(), ::toupper);
    transform(b.begin(),b.end(),b.begin(), ::toupper);
    for(int i=0; i<len; i++) {
        if ((a.at(i)-'A')<(b.at(i)-'A')) {
            flag--;
        }
        if ((a.at(i)-'A')>(b.at(i)-'A')) {
            flag++;
        }
        if(flag>0 || flag<0) {
            cout<<flag;
            return 0;
        }
    }

    cout<<0;
    return 0;
}