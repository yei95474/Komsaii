#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Employee{
    string name;
    int salary;
};

void addEmployee (vector<Employee>& nEmployee) {
    Employee temp;
    cout<<"Name: ";
    getline(cin, temp.name);
    cout<<"Salary: ";
    cin>>temp.salary;
    cin.ignore();
    nEmployee.push_back(temp);
}

bool isless (int a, int b) {
    return(a<b)? true: false;
}


int main() {
    int numEmp;
    cout<<"Number of employees: ";
    cin>>numEmp;
    cin.ignore();

    vector<Employee> nEmployee;
    for (int i=0; i<numEmp; i++) {
       addEmployee(nEmployee);
    }

    for (int i=0; i<numEmp-1; i++) {
        Employee temp;
        for (int j=i+1; j<numEmp; j++) {
            if(isless(nEmployee[i].salary, nEmployee[j].salary)) {
                temp = nEmployee[i];
                nEmployee[i] = nEmployee[j];
                nEmployee[j]= temp;
            }
        }
    }

    for (const auto& x : nEmployee) {
        cout<<x.name<<", ";
    }
    

    
    return 0;
}