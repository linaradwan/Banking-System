//
//  Customer.cpp
//  Banking System 3307
//
//  Created by Lina Radwan
//  Copyright © 2016 Lina Radwan. All rights reserved.
//

#include "Customer.h"


//Function the will read the customers accounts from the customerAccount.txt and will saves them into vector
void Customer:: loadCustomerBase(){
    fund=0;
    clients.clear();
    User client;
    string str, data;
    vector<string> list;
    ifstream infile;
    
    infile.open("customerAccounts.txt");
    
    if (infile.fail()){
        cerr << "Error opening the file" << endl;
        exit(1);
    }
    
    while(getline(infile,str)){
        istringstream iss(str);

        while(getline(iss,data,',')){
            list.push_back(data);
        }
        
        client.setFirstName(list[0]);
        client.setLastName(list[1]);
        client.setAccountNum(stoi(list[2]));
        
        fund+=stod(list[3])+stod(list[4]);
        client.setChequingBalance(stod(list[3]));
        client.setSavingsBalance(stod(list[4]));
        
        
        clients.push_back(client);
        list.clear();
    }
    
    infile.close();
    
    
    
}

//A method that will create a new customer and will added it in the customerAccounts.txt
void Customer::newClient(User client){
    
    ofstream outfile;
    outfile.open("customerAccounts.txt",ios::app);
    
    if(outfile.fail()){
        cerr<< "Error opening the file";
        exit(1);
    }
    Customer newUser;
    
    newUser.loadCustomerBase();
    int accountNum = (rand()% 900000)+100000;
    cout<<newUser.findAccountNum(accountNum)<<"\n";
    while(newUser.findAccountNum(accountNum)==true){
        accountNum +=1;}
    client.setAccountNum(accountNum);

    stringstream stream,stream2;
    stream<<fixed<< setprecision(2) << client.getChequingBalance();
    string cheqBalance= stream.str();
    stream2<<fixed<< setprecision(2) << client.getSavingsBalance();
    string savingBalance= stream2.str();

    string cust= "\n" + client.getFirstName()+ "," + client.getLastName()+ ","+ to_string(client.getAccountNum())+ "," + cheqBalance + "," + savingBalance;
    outfile<< cust;
    outfile.close();
    
    cout<< "\n A new client has been added successfully \n";
    loadCustomerBase();
}


//This method will look for the client in the clients vector
User Customer:: findClient( int accountNum, string firstName, string lastName){
    
    User clientFound;
    int i=0;
    clientFound.setFirstName("NOT FOUND");
    clientFound.setLastName("NOT FOUND");
    clientFound.setAccountNum(0);
    
    
    while( i< clients.size()){
        if(clients[i].getAccountNum()==accountNum ){
            clientFound=clients[i];
            return clientFound;
        }
        i++;
    }
    return clientFound;
    
}


void Customer:: viewSpecificAccount(){
    int count=0;
    for (int i=0 ;i<clients.size(); i++){
        if(clients[i].getSavingsBalance()>100000 || clients[i].getChequingBalance()>100000)
        count++;
    }
    cout<< "There are " << count <<" that has more than $100000 in their account"<<endl;
}



//This method will delete the client from the vector and the customerAccounts.txt
void Customer:: deleteClient(User client){
    string line,token;
    ifstream currentFile;
    vector<string> list;
    currentFile.open("customerAccounts.txt");
    
    if(currentFile.fail()){
        cerr<< "Error opening the file";
        exit(1);
    }
    
    ofstream temp;
    temp.open("temp.txt");
    
    
    
    while(getline(currentFile,line)) {
        istringstream iss(line);
        //separate string and put into vector
        while(getline(iss,token,',')){
            list.push_back(token);
        }
        if (list[2] != to_string(client.getAccountNum())){
            temp << line << "\n";
        }
        list.clear();
    }
    
    
    
    temp.close();
    currentFile.close();
    //delete the customerAccounts txt and rename the temp.txt into customerAccounts.txt basically replace them
    remove("customerAccounts.txt");
    rename("temp.txt","customerAccounts.txt");
    
    clients.clear();
    loadCustomerBase();
    
}

//Updates a client and adds it in the txt file
void  Customer:: updateAccount(User client){
    deleteClient(client);
    ofstream clientsDB;
    clientsDB.open("customerAccounts.txt",ios::app);
    
    if(clientsDB.fail()){
        cerr<< "Error opening the file";
        exit(1);
    }
    
    
    string cust= client.getFirstName()+ "," + client.getLastName()+ ","+ to_string(client.getAccountNum())+ "," + to_string(client.getChequingBalance()) + "," + to_string(client.getSavingsBalance());
    clientsDB<< cust;
    clientsDB.close();
    clients.clear();
    loadCustomerBase();
    
}


//looks if an account Number exsit this is used when we are assigning an account number to users as we'll want to generate an account num that is unique
bool Customer:: findAccountNum(int accountNum){
    int i=0;
    while(i<clients.size()){
        if(accountNum==clients[i].getAccountNum())
            return true;
        
        i++;
    }
    return false;
}


//displays all the accounts the bank has
void Customer::viewAllAccounts(){
    int custNum=1;
    for(int i = 0; i < clients.size(); i++){
        cout << "Customer: " << custNum++ << "\n";
        cout << clients[i].getAccountNum() << "\t" << clients[i].getFirstName() << "\t" << clients[i].getLastName() << "\n";
        cout<< "Balance in Chequing: "<< clients[i].getChequingBalance()<<"  Balance in Savings: "<<clients[i].getSavingsBalance()<<endl;
        
        
    }
    cout << "Total Customers: " << clients.size() << "\n";
    cout<<"Bank funds Total: " <<fund<<endl;
}


