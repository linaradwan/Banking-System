//
//  EmployeeAccount.cpp
//  Banking System 3307
//
//  Created by Lina Radwan
//  Copyright © 2016 Lina Radwan. All rights reserved.
//

#include "EmployeeAccount.h"

//The constructor
EmployeeAccount:: EmployeeAccount(){
    firstName="";
    lastName="";
}


string EmployeeAccount:: getFirstName(){
    return firstName;
}

string EmployeeAccount:: getLastName(){
    return lastName;
}

int EmployeeAccount:: getAccountNum(){
    return accountNum;
}

void EmployeeAccount:: setFirstName(string firstname){
    firstName=firstname;
}

void EmployeeAccount:: setLastName(string lastname){
    lastName=lastname;
}
void EmployeeAccount:: setAccountNum(int accountnum){
    accountNum=accountnum;
}

//This method will read the file passed in the parameter and saves each line (employee Account) in a vector and after it reads all the file it return the vector containing all the employee account
vector<EmployeeAccount> EmployeeAccount::readFile(string filename){
    
    vector <EmployeeAccount> dataFileRead;

    EmployeeAccount employee;
    string str, data;
    vector<string> list;
    ifstream infile;
    
    infile.open(filename);
    
    if (infile.fail()){
        cerr << "Error opening the file" << endl;
        exit(1);
    }
    
    //read line by line until there are no lines to be read
    while(getline(infile,str)){
        
        istringstream iss(str);
        while(getline(iss,data,',')){
            list.push_back(data);
        }
        
        employee.setFirstName(list[0]);
        employee.setLastName(list[1]);
        employee.setAccountNum(stoi(list[2]));
        
        
        dataFileRead.push_back(employee);
        list.clear();
    }
    
    infile.close();
    return dataFileRead;
    
}



