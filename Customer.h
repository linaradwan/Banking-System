//
//  Customer.hpp
//  Banking System 3307
//  This class represent the client from the manager's side
//  Created by Lina Radwan 
//  Copyright © 2016 Lina Radwan. All rights reserved.
//

#ifndef Customer_h
#define Customer_h
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "User.h"
using namespace std;


class Customer{
    
private:
    vector <User> clients;
    double fund;
    
public:
    void newClient(User client);
    User findClient( int accNum, string firstName, string lastName);
    void  deleteClient(User client);
    void loadCustomerBase();
    void  updateAccount(User client);
    bool findAccountNum(int accountNum);
    void viewAllAccounts();
    void viewSpecificAccount();
    
    
};

#endif /* Customer_hpp */
