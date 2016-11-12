
//
//  User.cpp
//  Banking System 3307
//
//  Created by Lina Radwan 
//  Copyright © 2016 Lina Radwan. All rights reserved.
//

#include "User.h"

User:: User(){
    firstName="";
    lastName="";


    chequingBalance=0;
    savingsBalance=0;
    
    
}


string User:: getFirstName(){
    return firstName;
}

string User:: getLastName(){
    return lastName;
}

int User:: getAccountNum(){
    return accountNum;
}

void User:: setFirstName(string firstname){
    firstName=firstname;
}

void User:: setLastName(string lastname){
    lastName=lastname;
}
void User:: setAccountNum(int accountnum){
    accountNum=accountnum;
}


double User:: getChequingBalance(){
    return chequingBalance;
}

double User:: getSavingsBalance(){
    return savingsBalance;
}

void User:: setChequingBalance(double chequingAmount){
    chequingBalance=chequingAmount;
    
}

void User:: setSavingsBalance(double savingsAmount){
    savingsBalance=savingsAmount;
}

void User::depositSavings(double savingsAmount){
    savingsBalance+= savingsAmount;
}

void User:: depositChequings(double chequingsAmount){
    chequingBalance+=chequingsAmount;
    
}

void User:: withdrawSavings(double savingsAmount){
    if (savingsAmount>savingsBalance){
        cout<<"Withdraw was unsuccessful because the withdraw amount is bigger than the balance";
    }
    else{
        savingsBalance=savingsBalance-savingsAmount;
        cout<< savingsAmount << "  was deposited in your account. Your current savings balance is: "<< savingsBalance <<" \n";
    }
    
    
}
void User:: withdrawChequings(double chequingsAmount){
    int checkThreshold= chequingBalance-chequingsAmount;
    int answer;

    if(checkThreshold< THRESHOLD && checkThreshold>=0){
        
        cout<< "If you withdraw this amount, your account balance will be lower than 1,000 and you will be charged $2.00. Are you sure you would like withdraw? \n" << "1. Yes   2. No  (1/2)\n ";
        
        cin>>answer;
        if(answer==1){
            chequingBalance=chequingBalance-chequingsAmount-FEE;
     cout<< chequingsAmount << "  was deposited in your account. Your current chequing balance is: "<< chequingBalance <<" \n";
        }
        else
            cout << "The withdraw has been canceled \n";
        
    }
    else{
        if (chequingsAmount<= chequingBalance){
            chequingBalance=checkThreshold;
            cout<< chequingsAmount << "  was deposited in your account. Your current chequing balance is: "<< chequingBalance <<" \n"; }

       else
           cout<<"Withdraw was unsuccessful because the withdraw amount is bigger than the balance"<<endl;
    }
  
    
    
    
}


void User:: transferToChequing(double amount){
    
    if (amount>savingsBalance){
        cout<<"Withdraw was unsuccessful because the transfer amount is bigger than the balance";
    }
    else{
        savingsBalance=savingsBalance-amount;
        chequingBalance+= amount;
        cout<< amount << "  was transfer from your savings account to your chequing Account. Your current chequing balance is: "<< chequingBalance <<" \n";
        cout<< "Your current Savings Balance is: " <<savingsBalance <<endl;

        
    }
    
    
}
void User:: transferToSavings(double amount){
    int checkThreshold= chequingBalance-amount;
    int answer;
    
    if(checkThreshold< THRESHOLD && checkThreshold>=0){
        
        cout<< "If you tranfer this amount, your account balance will be lower than 1,000 and you will be charged $2.00. Are you sure you would like withdraw? \n" << "1. Yes   2. No  (1/2)\n ";
        
        cin>>answer;
        if(answer==1){
            chequingBalance=chequingBalance-amount-FEE;
            savingsBalance+=amount;
            
            cout<< amount << "  was transfer from your chequing account to your savings Account. Your current savings balance is: "<< savingsBalance <<" \n";
            cout<< "Your current Chequing Balance is: " <<chequingBalance <<endl;

        }
        else
            cout << "The transfer has been canceled \n";
        
    }
    else{
        if (amount<= chequingBalance)
            chequingBalance=checkThreshold;
        else
            cout<<"The Transfer was unsuccessful because the transfer amount is bigger than the balance"<<endl;
    }


}




