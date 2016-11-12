//
//  Manager.hpp
//  Banking System 3307
//  This class will represent the manager of the bank
//  The class will only implement a function that will look for the manager and return the manager account. This will check whether the manager account we are looking actually exist.   
//  Created by Lina Radwan on 2016-10-19.
//  Copyright © 2016 Lina Radwan. All rights reserved.
//

#ifndef Manager_h
#define Manager_h



#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "EmployeeAccount.h"

using namespace std;


class Manager{
    
public:
    EmployeeAccount findManager(int accountNum, string firstName, string lastName);
    
};

#endif /* Manager_hpp */
