//
// Created by elmae on 19.06.2025.
//
#include <iostream>
#include <string>
#include "UserAccount.h"

UserAccount::UserAccount(std::string name,int accountID, double initialBalance) {

    ownerName = name;
    balance = initialBalance;
    id = accountID;

}

void UserAccount::deposit(double amount) {

    if (amount>0) {
        balance += amount;
    }

}

bool UserAccount::withdraw(double amount) {

    if (balance >= amount) {
        balance -= amount;
    }
    else {
        return false;
    }

}

void UserAccount::transferTo(UserAccount &other, double amount) {
    if (balance >= amount) {

        balance -= amount;
        other.balance += amount;
        std::cout<<"Transfer Successful.\n";

    }
    else {
        std::cout<<"Insufficient Balance.";

    }

}

void UserAccount::printInfo() const {

    std::cout<<"ID: "<<id<<"\n";
    std::cout<<"Name: "<<ownerName<<"\n";
    std::cout<<"Balance: "<<balance<<"\n";

}

int UserAccount::getID() const {
    return id;
}



