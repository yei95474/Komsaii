#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

struct wordRecord {
    string word;
    int length;
    int vowelCount;
};

int countVowels (string w) {
    int c=0;
    for (int i=0; i<w.length(); i++) {
        char temp = toupper(w[i]);
        if (temp=='A' || temp=='E' || temp=='I' || temp=='O' || temp=='U') {
            c++;
        }
    }
    return c;
}

bool isPalindrome(string w) {
    int l= w.length();
    transform(w.begin(), w.end(), w.begin(), ::toupper);
    for (int i=0, j=l-1; i<j; i++, j--) {
        if (w[i] != w[j]) {
            return false;
        }
    }
    return true;
}

wordRecord analyzeWord(string w) {
    wordRecord temp;
    temp.word = w;
    temp.length = w.length();
    temp.vowelCount= countVowels(w);
    return temp;
}

vector<wordRecord> analyzeList(vector<string> words) {
    vector<wordRecord> list;
    
    for (int i=0; i<words.size(); i++) {
        wordRecord temp = analyzeWord(words[i]);
        list.push_back(temp);
    }
    return list;
}

double averageLength(vector<wordRecord> records) {
    int sum=0;
    double average;
    for (int i=0; i<records.size(); i++) {
        sum+= records[i].length;
    }
    average = sum/ records.size();
    return average;
}

int main() {
    int n;
    vector<string> words;
    cout<< "Enter size: ";
    cin>>n;
    for (int i=0; i<n; i++) {
        string temp;
        cout << "\nWord " << i + 1 << " : ";
        cin>>temp;
        words.push_back(temp);
    }
    vector<wordRecord> results = analyzeList(words);

    cout << "\n\nWord Analysis Report\n\n";
    for (int i = 0; i < results.size(); i++) {
        cout << "Word: "       << results[i].word       << "\n";
        cout << "Length: "     << results[i].length     << "\n";
        cout << "Vowels: "     << results[i].vowelCount << "\n";
        cout << "Palindrome: " << (isPalindrome(results[i].word) ? "Yes" : "No") << "\n\n";
    }

    cout << "Average Length: " << fixed << setprecision(2) << (double) averageLength(results) << "\n";
    return 0;
}