#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct address
{

    int streetNum;
    string town;

};

struct employee
{
   int idNum=123;
   string name;
   double monthlySalary;
   address empAddress;
};


//int f1(employee emp1);


int main()
{
    employee companyAEmp,companyBEmp;

    companyAEmp.idNum = 12343;
    companyAEmp.name = "SampleName";
    companyAEmp.monthlySalary = 14325.212;


    ifstream inRecEmp;
    ofstream outRecEmp;


    outRecEmp.open("CompanyAEmployeeRecord.txt");

    outRecEmp<<companyAEmp.idNum<<",";
    outRecEmp<<companyAEmp.name<<",";
    outRecEmp<<companyAEmp.monthlySalary<<endl;

    outRecEmp<<companyAEmp.idNum<<",";
    outRecEmp<<companyAEmp.name<<",";
    outRecEmp<<companyAEmp.monthlySalary<<endl;

    int x;
    string z;
    char y;
    inRecEmp.open("CompanyAEmployeeRecord.txt");
    if (inRecEmp.is_open())
    {
        inRecEmp>>x;
        inRecEmp>>z;
        //inRecEmp>>y;

        cout<<x<<endl;
        cout<<z;
    }
    else
    {
        cout<<"File does not exist";
    }
}