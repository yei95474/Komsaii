#include <bits/stdc++.h>
using namespace std;

struct Student
{
    string name;
    vector<int> scores;
    double average;
};

void calculateAverages(vector<Student> &classroom)
{
    for(int i=0; i<classroom.size(); i++) {
        int sum = 0;
        double average;
        for(int j=0; j<classroom[i].scores.size(); j++) {
            sum += classroom[i].scores[j];
        }
        average = (double) sum / classroom[i].scores.size();
        classroom[i].average = average;
    }
}

void addStudent(vector<Student> &classroom)
{
Student s;
   string name;
   cout<< "Name: ";
   getline(cin, name);
   s.name = name;
   int n;
   cout<<"Number of scores: ";
   cin>>n;
   
   for (int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        s.scores.push_back(temp);
   }
   cin.ignore();
   classroom.push_back(s);
}

vector<string> getHonorRoll(const vector<Student> &classroom, double treshold)
{
    vector <string> namesOnly;
    for (int i=0; i<classroom.size(); i++) {
        if (classroom[i].average > treshold) {
            namesOnly.push_back(classroom[i].name);
        }
    }

    return namesOnly;
}

int main()
{
    vector<Student> classroom;

    int numStudents;
    cout << "How many students? ";
    cin >> numStudents;
    cin.ignore();

    for (int i = 0; i < numStudents; i++) {
        cout << "\n--- Student " << i + 1 << " ---\n";
        addStudent(classroom);
    }

    calculateAverages(classroom);

    cout << "\n--- All Students ---\n";
    for (int i = 0; i < (int)classroom.size(); i++) {
        cout << classroom[i].name << ": " << classroom[i].average << "\n";
    }

    double threshold;
    cout << "\nEnter honor roll threshold: ";
    cin >> threshold;

    vector<string> honorRoll = getHonorRoll(classroom, threshold);

    cout << "\n--- Honor Roll (above " << threshold << ") ---\n";
    if (honorRoll.empty()) {
        cout << "No students made the honor roll.\n";
    } else {
        for (int i = 0; i < (int)honorRoll.size(); i++) {
            cout << honorRoll[i] << "\n";
        }
    }
}