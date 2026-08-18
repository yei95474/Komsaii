#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k,temp,c=0,largest=0;
    cin>>n;
    cin>>k;
    if(n<k) {
        return 0;
    }
    vector<int> scores;
    for(int i=0;i<n;i++) {
        cin>>temp;
        if (temp>largest) {
            largest=temp;
        }
        scores.push_back(temp);     
    }

    if(largest<1) {
        cout<<0;
        return 0;
    }
    sort(scores.begin(), scores.end(), greater<int>());
    for(int i=0; i<n; i++) {
        if (scores[i]<scores[k-1] || scores[i]==0) {
            break;
        }
        c++;
    }
    cout<<c;
    return 0;
}