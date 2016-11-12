//
//  EmployeeAccount.hpp
//  Banking System 3307
//  This class represents the manager and maintenance accounts
//
//  Created by Lina Radwan
//  Copyright © 2016 Lina Radwan. All rights reserved.
//

#ifndef EmployeeAccount_h
#define EmployeeAccount_h


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;



class EmployeeAccount{
    
private:
    string firstName,lastName;
    int accountNum;
    
public:
    EmployeeAccount();
    string getFirstName();
    string getLastName();
    int getAccountNum();
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setAccountNum(int accountNum);
    vector<EmployeeAccount> readFile(string filename);

};

#endif /* EmployeeAccount_hpp */
