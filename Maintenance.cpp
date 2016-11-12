//
//  Maintenance.cpp
//  Banking System 3307
//
//  Created by Lina Radwan 
//  Copyright © 2016 Lina Radwan. All rights reserved.
//

#include "Maintenance.h"


//This method will return the current date and time which will be then used to print the time for the trace
string Maintenance:: printDateTime(){
    time_t now = time(0);
    char* dt = ctime(&now);
    return dt;
}


//This method will look for the system maintenance in the database( txt file). It will take accountNum, the first name, and the last name of the system maintenance we're looking for and will return the account of the manager if found, if not it will return an empty manager

EmployeeAccount Maintenance:: findMaintenance(int accountNum, string firstName, string lastName){
    
    vector<EmployeeAccount> maintenanceData;
    EmployeeAccount foundMaintenace;
    //call the readFile function to read the maintenanceAccounts.txt file and return a vector with the current system maintenance accounts.
    maintenanceData= foundMaintenace.readFile("maintenanceAccounts.txt");
    
    //loop through the vector to look for a system maintenance person with the same account number.
    for(int i = 0; i < maintenanceData.size(); i++){
        if(maintenanceData[i].getAccountNum() == accountNum ){
            foundMaintenace = maintenanceData[i];
            return foundMaintenace;
        }
    }
    //if found it will return the the maintenance account, if not it will return an empty maintenance account
    return foundMaintenace;
}


//This method will read the excutionTraceSwitch file and will return the string (ON or OFF ) in the file

string Maintenance::readExecutionTrace(){
    
    string str;
    ifstream infile;
    
    infile.open("ExecutionTraceSwitch.txt");
    
    if (infile.fail()){
        cerr << "Error opening the file" << endl;
        exit(1);
    }
    
    getline(infile,str);
    return str;
    
}

//This method will write in the excutionTraceSwitch file the string (ON or OFF ) passed as the parameter
//It will replace the original string in the file with the string passed in the parameter
void Maintenance:: writeExecutionTrace(string executionTraceSwitch){
    
    string token;
    ifstream currentFile;
    
    if(currentFile.fail()){
        cerr<< "Error opening the file";
        exit(1);
    }
    
    ofstream temp;
    temp.open("temp.txt");
    temp<< executionTraceSwitch;

    
    temp.close();
    remove("ExecutionTraceSwitch.txt");
    rename("temp.txt","ExecutionTraceSwitch.txt");
   
}










