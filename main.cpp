//
//  main.cpp
//  Banking System 3307
//
//  Created by Lina Radwan
//  Copyright © 2016 Lina Radwan. All rights reserved.
//

#include <iostream>
#include "EmployeeAccount.h"
#include "User.h"
#include "Manager.h"
#include "Maintenance.h"
#include "Customer.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    
    Maintenance maintenance;
    Customer client;
    Manager manger;
    User clientToFind,clientFound, newClient,deletedClient;
    EmployeeAccount mangerToFind,maintenanceToFind;
    string firstname,lastname;
    int login, accountNum,managerChoice,clientChoice,chequingChoice,savingsChoice,maintenanceChoice=0;
    
    bool executionTrace=false,back=true,exitChoice=true, loginSuccess=true;
    
    char loan;
    double chequing,savings;
    
    
    if(maintenance.readExecutionTrace()=="ON")
        executionTrace=true;
    
    ofstream outfile;
    outfile.open("trace.txt",ios::app);
    if(executionTrace){
    outfile<<maintenance.printDateTime() + "\n" ;
    }

    client.loadCustomerBase();
    
    
    cout << "Welcome to Radwan's bank \n Please choose an option to begin your process\n";
    cout<< "1. Customer's LOGIN \n2. Manager's LOGIN \n3. System Maintenance's LOGIN \n";
    cin>>login;
    
    switch (login) {
            
            
            
            //==========CUSTOMER==========//
            //==========CUSTOMER==========//
            //==========CUSTOMER==========//
            //==========CUSTOMER==========//
            //==========CUSTOMER==========//
            //==========CUSTOMER==========//
            
            
        case 1:
            
            
            while(1){
                cout << "========== Customer Login ==========  \n \n";
                cout << "Please enter your account number \n";
                cin >>accountNum;
                cout << "Please enter your first name \n";
                cin>>firstname;
                cout << "Please enter your last name \n";
                cin>>lastname;
                
                clientToFind= client.findClient(accountNum, firstname, lastname);
                
                if(clientToFind.getFirstName()==firstname && clientToFind.getLastName()==lastname && clientToFind.getAccountNum()==accountNum){
                    cout<< "Login Successful!\n***WELCOME "+clientToFind.getFirstName() +" " +clientToFind.getLastName()+ "***\n";
                    clientFound=clientToFind;
                    if(executionTrace){
                        outfile<<clientFound.getFirstName() + " " + clientFound.getLastName()+ " Logged In \n" ;
                    }

                    break;
                }
                else{
                    cout <<"Login Failed \n Please enter the correct account number and name \n";
                    
                }
            }
            
            
            
            
            while(back){
            cout<< "Which account would you like to access today?\n";
            cout<< "1. Chequing \n2. Savings \n3. Book an Appointment with the Manager \n4.Exit \n";
                exitChoice=true;
            cin>>clientChoice;
            
            while(exitChoice){
                switch (clientChoice) {
                    case 1:
                        if(executionTrace){
                            outfile<<clientFound.getFirstName() + " " + clientFound.getLastName()+ " Choose Chequing \n" ;
                        }

                        cout<< "=======CHEQUING ACCOUNT======= \n";
                        cout <<"1. Balance\n2. Deposit\n3. Withdraw\n4. Transfer from chequing to savings\n5. Get a Loan \n6. Back\n";
                        cin>>chequingChoice;
                        switch (chequingChoice) {
                            case 1:
                                if(executionTrace){
                                    outfile<<clientFound.getFirstName() + " " + clientFound.getLastName()+ " Choose chequing balance \n" ;
                                }
                                cout<<"Current Chequing Balance: "<<clientFound.getChequingBalance()<<endl;
                                exitChoice=true;
                                break;
                            case 2:
                                if(executionTrace){
                                    outfile<<clientFound.getFirstName() + " " + clientFound.getLastName()+ " Choose to deposit from chequing account \n" ;
                                }
                                cout<< "Please enter the amount you want to deposit in your account \n";
                                cin>>chequing;
                                clientFound.depositChequings(chequing);
                                cout<< chequing << " was deposited in your account. The current balance is: "<<clientFound.getChequingBalance() <<endl;
                                client.updateAccount(clientFound);
                                exitChoice=true;
                                break;
                                
                            case 3:
                                if(executionTrace){
                                    outfile<<clientFound.getFirstName() + " " + clientFound.getLastName()+ " Choose to withdraw from chequing account\n" ;
                                }
                                cout<< "Please enter the amount you want to withdraw from your account \n";
                                cin>>chequing;
                                clientFound.withdrawChequings(chequing);
                                client.updateAccount(clientFound);
                                exitChoice=true;
                                break;
                                
                            case 4:
                                if(executionTrace){
                                    outfile<<clientFound.getFirstName() + " " + clientFound.getLastName()+ " Choose to transfer from chequing to savings \n" ;
                                }
                                cout<< "Please enter the amount you want to transfer from your chequing account to your savings account \n";
                                cin>>chequing;
                                clientFound.transferToSavings(chequing);
                                client.updateAccount(clientFound);
                                exitChoice=true;
                                break;
                                
                            case 5:
                                if(executionTrace){
                                    outfile<<clientFound.getFirstName() + " " + clientFound.getLastName()+ " Choose to get a bank loan \n" ;
                                }
                                cout<< "If given the loan, You will start to repay the amount after 3 month with 10% interest rate/n Do you still want to continue? (Y/N)"<<endl;
                                cin>>loan;
                                if(loan== 'Y'|| loan=='y'){
                                cout<< "Please input the amount you would like to get a loan for:" <<endl;
                                    cin>>chequing;
                                    clientFound.depositChequings(chequing);
                                    cout<< chequing << " loan was added in your account. Your current balance is: "<<clientFound.getChequingBalance()<<endl;
                                    client.updateAccount(clientFound);
                                }
                                else{
                                    cout<<"Process was cancelled"<<endl;
                                    break;
                                }
                                exitChoice=true;
                                break;
                            case 6:
                                exitChoice=false;
                                break;
                                
                            default:
                                cout<< "Invalid Input: Please Try Again \n";
                                exitChoice=false;
                        }
                        
                        
                        
                        break;
                        
                        
                    case 2:
                        if(executionTrace){
                            outfile<<clientFound.getFirstName() + " " + clientFound.getLastName()+ " Choose savings account\n" ;
                        }
                        cout<< "=======Savings ACCOUNT======= \n";
                        cout <<"1. Balance\n2. Deposit\n3. Withdraw\n4. Transfer from savings to chequing\n5.Back\n";
                        cin>>savingsChoice;
                        
                        switch (savingsChoice) {
                            case 1:
                                if(executionTrace){
                                    outfile<<clientFound.getFirstName() + " " + clientFound.getLastName()+ " Choose chequing balance \n" ;
                                }
                                cout<<"Current Chequing Balance: "<<clientFound.getSavingsBalance()<<endl;
                                exitChoice=true;
                                break;
                            case 2:
                                if(executionTrace){
                                outfile<<clientFound.getFirstName() + " " + clientFound.getLastName()+ " Choose to deposit from savings \n" ;
                            }
                                cout<< "Please enter the amount you want to deposit in your account \n";
                                cin>>savings;
                                clientFound.depositSavings(savings);
                                 cout<< savings<< " was deposited in your account. The current balance is: "<<clientFound.getSavingsBalance() <<endl;
                                client.updateAccount(clientFound);
                                exitChoice=true;
                                
                                break;
                                
                            case 3:
                                if(executionTrace){
                                    outfile<<clientFound.getFirstName() + " " + clientFound.getLastName()+ " Choose to withdraw from savings \n" ;
                                }
                                cout<< "Please enter the amount you want to withdraw from your account \n";
                                cin>>savings;
                                clientFound.withdrawSavings(savings);
                                client.updateAccount(clientFound);
                                exitChoice=true;
                                
                                break;
                                
                            case 4:
                                if(executionTrace){
                                    outfile<<clientFound.getFirstName() + " " + clientFound.getLastName()+ " Choose to transfer from savings to chequing \n" ;
                                }
                                cout<< "Please enter the amount you want to transfer from your savings account to your chequing account \n";
                                cin>>savings;
                                clientFound.transferToChequing(savings);
                                client.updateAccount(clientFound);
                                exitChoice=true;
                                
                                break;
                                
                            case 5:
                                exitChoice=false;
                                break;
                                
                            default:
                                cout<< "Invalid Input: Please Try Again \n";
                                exitChoice=false;
                                break;
                        }
                        
                        
                        
                        break;
                        
                        
                        
                    case 3:{
                        if(executionTrace){
                            outfile<<clientFound.getFirstName() + " " + clientFound.getLastName()+ " Choose to book an appointment with a manager \n" ;
                        }
                        string date;
                        long dayofTheMonth;
                        long num;
                        cout<< "Please write which day you would like to book the appointment(Mon,Tues,Wed,thurs,fri"<<endl;
                        cin>> date;
                        cout<< "Please write the day's date you would like to book your appointment (#)"<<endl;
                        cin>> dayofTheMonth;
                        cout<< "Please input your phone number so that we can contact you and book a good time for you \n";
                        cin>>num;
                       cout <<"Thank You, we will contact you soon"<<endl;
                        
                        ofstream appointmentFile;
                        appointmentFile.open("appointment.txt",ios::app);
                        appointmentFile<<"\n"+clientFound.getFirstName()+ clientFound.getLastName()+date +"," << dayofTheMonth<<"," << num;
                        exitChoice=false;
                        break;
                    }
                        
                
                    case 4: {
                        cout<<"Closing the program"<<endl;
                        outfile.close();
                        exit(0);
                        break;
                    }
                        
                        
                        
                    default:{
                        cout<<"Invalid Input: Please Try Again"<<endl;
                        exitChoice=false;
                        break;
                        
                    }
                        
                        
                        
                }
                
            }
            
            
            }
            
            break;
            
            
            
            
            //==========MANAGER==========//
            //==========MANAGER==========//
            //==========MANAGER==========//
            //==========MANAGER==========//
            //==========MANAGER==========//
            //==========MANAGER==========//
            
            
        case 2:
            
            while(loginSuccess){
                cout << "========== Radwan's bank ==========  \n";
                cout << "========== Manager Login ==========  \n \n";
                cout << "Please enter your account number \n";
                cin >>accountNum;
                cout << "Please enter your first name \n";
                cin>>firstname;
                cout << "Please enter your last name \n";
                cin>>lastname;
                
                mangerToFind= manger.findManager(accountNum, firstname, lastname);
                
                if(mangerToFind.getFirstName()==firstname && mangerToFind.getLastName()==lastname && mangerToFind.getAccountNum()==accountNum){
                    cout<< "Login Successful \n***WELCOME "+mangerToFind.getFirstName() +" " +mangerToFind.getLastName()+ "***\n";
                    loginSuccess=false;
                    
                }
                else{
                    cout <<"Login Failed \n Please enter the correct account number and name \n";
                    
                }
            }
            
            exitChoice=true;
            while(1){
            
            cout << "Please choose an option to complete your process\n";
            cout<< "1. View a Customer's Account \n2. View all accounts in the bank \n3.Create a new Customer \n4: Delete a Customer \n5. View the number of clients with $100,000 or more in their account \n6: Exit \n" ;
            
            cin>> managerChoice;
            
            switch (managerChoice) {
                case 1:
                    while(1){
                    cout << "Please enter the customer's account number \n";
                    cin>>accountNum;
                    cout << "Please enter the customer's first name \n";
                    cin>>firstname;
                    cout << "Please enter the customer's last name \n";
                    cin>>lastname;
                    
                    clientToFind= client.findClient(accountNum, firstname, lastname);
                    
                    if(clientToFind.getFirstName()==firstname && clientToFind.getLastName()==lastname && clientToFind.getAccountNum()==accountNum){
                        cout<< "\nCustomer Name: "+clientToFind.getFirstName() +" " +clientToFind.getLastName()+ "\n";
                        cout<< "Balance in Chequing: "<< clientToFind.getChequingBalance()<<"\nBalance in Savings: "<<clientToFind.getSavingsBalance()<<endl;
                        cout<<"========================== \n";
                        break;
                        
                    }
                    else{
                        cout<<"Invalid Input: Please Try Again"<<endl;
                    }
                    }
                    break;
                    
                case 2:
                    client.viewAllAccounts();
                    
                    break;
                    
                case 3:
                    cout << "Please enter the customer's first name \n";
                    cin>>firstname;
                    cout << "Please enter the customer's last name \n";
                    cin>>lastname;
                    cout<<"Please enter the amount to deposit to customer's Chequing Account \n";
                    cin>>chequing;
                    cout<<"Please enter the amount to deposit to customer's Savings Account \n";
                    cin>>savings;
                    
                    
                    newClient.setFirstName(firstname);
                    newClient.setLastName(lastname);
                    newClient.setChequingBalance(chequing);
                    newClient.setSavingsBalance(savings);
                    client.newClient(newClient);
                    
                    
                    break;
                case 4:
                    cout << "Please enter the customer's account number \n";
                    cin >>accountNum;
                    cout << "Please enter the customer's first name \n";
                    cin>>firstname;
                    cout << "Please enter the customer's last name \n";
                    cin>>lastname;
                    deletedClient= client.findClient(accountNum, firstname, lastname);
                    if( deletedClient.getChequingBalance()==0.00 && deletedClient.getSavingsBalance() == 0.00){
                        client.deleteClient(deletedClient);

                    }
                    else{
                        cout<< "Process failed! You can't delete this client because his account balance is not 0"<<endl;
            
                    }
                   // deletedClient.setFirstName(firstname);
                    //deletedClient.setAccountNum(accountNum);
                    //deletedClient.setLastName(lastname);
                   // deletedClient.setChequingBalance(chequing);
                    //deletedClient.setSavingsBalance(savings);
                    break;
                    
                case 5:
                    
                    client.viewSpecificAccount();
                    
                    break;
                    

                    
                    
                    break;
                    
                case 6:
                    cout<<"Closing the program \n";
                    maintenanceChoice=1;
                    exit(9);
                    break;
                    break;
                    
                default:
                    break;
            }
            }
            
            
            
            
            break;
            
            
            
            
            
            
            
            
            
            
            
            
            
            //==========MAINTENANCE==========//
            //==========MAINTENANCE==========//
            //==========MAINTENANCE==========//
            //==========MAINTENANCE==========//
        case 3:
            
            
            
            
            while(loginSuccess){
                cout << "========== Radwan's bank  ==========  \n";
                cout << "========== Maintenance Login ==========  \n";
                cout << "Please enter your account number \n";
                cin >>accountNum;
                cout << "Please enter your first name \n";
                cin>>firstname;
                cout << "Please enter your last name \n";
                cin>>lastname;
                
                maintenanceToFind=maintenance.findMaintenance(accountNum, firstname, lastname);
                
                if(maintenanceToFind.getFirstName()==firstname && maintenanceToFind.getLastName()==lastname && maintenanceToFind.getAccountNum()==accountNum){
                    cout<< "***Login Successful: Welcome "+maintenanceToFind.getFirstName() +" " +maintenanceToFind.getLastName()+ "***\n";
                    loginSuccess=false;
                    
                    
                    
                    
                    while(maintenanceChoice!=1){
                        cout << "Please choose an option to complete your process\n";
                        cout<< "1. Turn ON the system execution Trace \n2. Turn OFF the system execution Trace \n3. Exit \n";
                        cin>>maintenanceChoice;
                        
                        switch (maintenanceChoice) {
                            case 1:
                                cout<<"ExecutionTrace turned On\n";
                                maintenance.writeExecutionTrace("ON");
                                maintenanceChoice=0;
                               
                                break;
                                
                            case 2:
                                cout<<"ExecutionTrace turned OFF\n";
                                maintenance.writeExecutionTrace("OFF");
                                maintenanceChoice=0;
                                break;
                                
                            case 3:
                                cout<<"Closing the program \n";
                                maintenanceChoice=1;
                                exit(9);
                                break;
                                
                            default:
                                cout<< "Please Enter the correct option"<<endl;
                                break;
                        }
                    }
                    
                    
                    
                }
                else{
                    cout <<"Login Failed: Please enter the correct account number and name \n";
                    
                }
            }
            
            break;

    }

    
}










