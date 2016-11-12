//
//  Manager.cpp
//  Banking System 3307
//
//  Created by Lina Radwan
//  Copyright © 2016 Lina Radwan. All rights reserved.
//

#include "Manager.h"

/*
 This method will take the firstname, last name and the account number of the user as its parameter 
 and will look for the manager in the "managersAccount.txt" and return it.
 */

EmployeeAccount Manager:: findManager(int accountNum, string firstName, string lastName){
    vector<EmployeeAccount> managersData;
    EmployeeAccount foundManager;
    //call the readFile function to read the managersAccount.txt file and return a vector with the current managers accounts.
    managersData= foundManager.readFile("managersAccounts.txt");
    
    //loop through the vector to look for a manager with the same account number.
    for(int i = 0; i < managersData.size(); i++){
        if(managersData[i].getAccountNum() == accountNum ){
            foundManager = managersData[i];
            return foundManager;
        }
    }
    
    //if found it will return the the manager's account, if not it will return an empty manager account
    return foundManager;
}
