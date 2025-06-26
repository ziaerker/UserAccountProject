#include <iostream>
#include "UserAccount.h"
#include <vector>


int main() {
    std::vector<UserAccount> accounts;

    while (true) {
        int choice;
        std::cout << "====== Main Menu ======\n";
        std::cout << "1. I have an ID\n";
        std::cout << "2. I have not an ID\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            int id;
            std::cout << "Enter your ID: ";
            std::cin >> id;

            UserAccount* currentUser = nullptr;
            for (auto& acc : accounts) {
                if (acc.getID() == id) {
                    currentUser = &acc;
                    break;
                }
            }

            if (!currentUser) {
                std::cout << "No account found with ID " << id << ".\n";
                continue;
            }


            while (true) {
                int action;
                std::cout << "\n== Account Menu ==\n";
                std::cout << "1. Deposit\n";
                std::cout << "2. Withdraw\n";
                std::cout << "3. Print Info\n";
                std::cout << "4. Transfer\n";
                std::cout << "5. Back to Main Menu\n";
                std::cout << "Your choice: ";
                std::cin >> action;

                if (action == 1) {
                    double amount;
                    std::cout << "Enter amount to deposit: ";
                    std::cin >> amount;
                    currentUser->deposit(amount);
                }
                else if (action == 2) {
                    double amount;
                    std::cout << "Enter amount to withdraw: ";
                    std::cin >> amount;
                    if (!currentUser->withdraw(amount)) {
                        std::cout << "Insufficient funds.\n";
                    }
                }
                else if (action == 3) {
                    currentUser->printInfo();
                }
                else if (action == 4) {
                    int recipientID;
                    std::cout<<"Enter ID to transfer to:\n";
                    std::cin>> recipientID;
                    UserAccount* other = nullptr;
                    for (auto& acc: accounts) {
                        if (acc.getID() == recipientID) {
                            other = &acc;
                            break;
                        }
                    }
                    if (other == nullptr) {
                        std::cout<<"Invalid ID.\n";
                    }
                    else {
                        double amount;
                        std::cout<<"Enter amount to transfer:\n";
                        std::cin >> amount;
                        currentUser ->transferTo(*other, amount);
                    }
                }
                else if (action == 5) {
                    break;
                }
                else {
                    std::cout << "Invalid selection.\n";
                }
            }
        }
        else if (choice == 2) {
            std::string name;
            int accountID;
            double initialBalance;
            std::cout<<"Name:\n";
            std::cin>>name;
            std::cout<<"ID:\n";
            std::cin>> accountID;
            std::cout<<"Balance:\n";
            std::cin>> initialBalance;

            UserAccount acc(name, accountID, initialBalance);
            accounts.push_back(acc);
        }
        else {
            std::cout<<"Invalid Selection";
            break;
        }
    }

    return 0;
}