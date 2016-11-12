//
//  Maintenance.hpp
//  Banking System 3307
//  This class will represent the system mainatenace of the bank
//  Created by Lina Radwan 
//  Copyright © 2016 Lina Radwan. All rights reserved.
//

#ifndef Maintenance_h
#define Maintenance_h

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "EmployeeAccount.h"
using namespace std;


class Maintenance{
    
public:
    string printDateTime();
    EmployeeAccount findMaintenance(int accountNum, string firstName, string lastName);
    string readExecutionTrace();
    void writeExecutionTrace(string executionTraceSwitch);


};


#endif /* Maintenance_hpp */
