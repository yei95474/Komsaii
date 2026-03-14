#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    int uc=0, lc=0;
    for (int i=0; i<s.length(); i++) {
        int ui='A', li= 'a';
        for(int j=0; j<26; j++) {
            if (s[i]==(char)ui) {
                uc++;
                break;
            }
            else if (s[i]==(char)li) {
                lc++;
                break;
            }
            else {
                ui++;
                li++;
            }
        }
    }
    if (uc>lc) {
        transform(s.begin(), s.end(), s.begin(), [](char s){return toupper(s);});
    }
    else {
        transform(s.begin(), s.end(), s.begin(), [](char s){return tolower(s);});
    }
    cout<<s;
}