//
//  User.hpp
//  Banking System 3307
//  This class represents the client
//  Created by Lina Radwan
//  Copyright © 2016 Lina Radwan. All rights reserved.
//

#ifndef User_h
#define User_h

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User{
    
private:
    string firstName,lastName;
    int accountNum;
    double chequingBalance,savingsBalance;
    static const int FEE=2;
    static const int THRESHOLD= 1000;
    
public:
    User();
    string getFirstName();
    string getLastName();
    int getAccountNum();
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setAccountNum(int accountNum);
    
    double getChequingBalance();
    double getSavingsBalance();
    void setChequingBalance(double chequingAmount);
    void setSavingsBalance(double savingsAmount);
    void depositSavings(double savingsAmount);
    void depositChequings(double chequingsAmount);
    void withdrawSavings(double savingsAmount);
    void withdrawChequings(double chequingsAmount);
    void transferToChequing(double amount);
    void transferToSavings(double amount);
    
    
    
};

#endif /* User_hpp */



    
    

