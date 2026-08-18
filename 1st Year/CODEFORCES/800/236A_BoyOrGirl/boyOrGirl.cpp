#include <bits/stdc++.h>

using namespace std;

int main () {
    char map[26]={0};
    string x;
    cin>>x;

    for (int i=0; i<x.length(); i++) {
        for (int j=0; j<26; j++) {
            int temp= static_cast<int>(x[i])-'a';
            if (temp==j && map[j]==0) {
                map[j]=1;
            }
            else {
                continue;
            }
        }
    }

    int sum=0;
    for (int i=0; i<26; i++) {
        sum+= map[i];
    }

    if (sum%2==0) {
        cout<<"CHAT WITH HER!";
    }
    else {
        cout<<"IGNORE HIM!";
    }
}