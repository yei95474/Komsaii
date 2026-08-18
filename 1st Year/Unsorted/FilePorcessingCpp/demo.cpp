#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Student{
    string id;
    string name;
    double grades;
};

int main () {
    vector<Student> lists;

    ifstream inDemo;
    ofstream outDemo;

    outDemo.open("list.txt");

    if (!outDemo.is_open()) {
        cout<<"File not Found!"<<endl;
    }

    string id;
    string name;
    double grades;

    int n;
    cout<<"Enter [N]umber of Students: ";
    cin>>n;

    for(int i=0; i<n; i++) {
        cout<<endl<<endl<<"Student ["<<i+1<<"]: "<<endl;
        cout<<"Enter [ID] Number: ";
        cin>>id;
        cin.ignore();
        cout<<"Enter [Name]: ";
        getline(cin, name);
        cout<<"Enter [Grades]: ";
        cin>>grades;

        outDemo<<"ID: "<<id<<endl
                <<"NAME: "<<name<<endl
                <<"GRADES: "<<grades<<"\n\n";
    }


    cout<<"\n\n";
    inDemo.open("list.txt");
    int i=0;
    while(!inDemo.eof()) {
        string temp;

        getline(inDemo, temp);
        cout<<temp<<" ";
        getline(inDemo, temp);
        cout<<temp<<" ";
        getline(inDemo, temp);
        cout<<temp<<" ";
        getline(inDemo, temp);
        cout<<temp<<" ";
        cout<<"\n\n";

    }
    return 0;
    }
