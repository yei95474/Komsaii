#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    int n;
    vector<string> words;
    cin>>n;
    for(int i=0;i<n;i++) {
        string temp;
        cin>>temp;
        words.push_back(temp);
    }

    for(int i=0;i<n;i++) {
        int temp= words[i].length();
        if(temp>10) {
            cout<< words[i][0] << temp-2 << words[i][temp-1]<<endl;
        }
        else {
            cout<<words[i]<<endl;
        }
    }
    return 0;
}