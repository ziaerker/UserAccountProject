//
// Created by elmae on 19.06.2025.
//

#include <iostream>
#include <string>

#ifndef USERACCOUNT_H
#define USERACCOUNT_H

class UserAccount{

  private:
    std::string ownerName;
    int id;
    double balance;

  public:
    UserAccount(std::string name,int accountID, double initialBalance);
    void deposit(double amount);
    bool withdraw(double amount);
    void transferTo(UserAccount &other, double amount);
    void printInfo() const;
    [[nodiscard]] int getID() const;

};

#endif //USERACCOUNT_H
