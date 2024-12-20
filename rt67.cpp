#include <iostream>
#include <string>
#include <vector>
#include <iomanip> 


class BankAccount {
public:
    int accountNumber;
    std::string ownerName;
    double balance;

    BankAccount(int accountNumber, const std::string& ownerName, double balance) 
        : accountNumber(accountNumber), ownerName(ownerName), balance(balance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Внесено " << amount << " на счет " << accountNumber << std::endl;
        } else {
            std::cout << "Сумма пополнения должна быть положительной." << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0) {
          if (balance >= amount) {
              balance -= amount;
              std::cout << "Снято " << amount << " со счета " << accountNumber << std::endl;
          } else {
              std::cout << "Недостаточно средств на счете." << std::endl;
          }
        } else {
            std::cout << "Сумма снятия должна быть положительной." << std::endl;
        }
    }
     void printBalance() const{
        std::cout << "Баланс счета " << accountNumber << ": " <<  std::fixed << std::setprecision(2) << balance << std::endl;


    }
};

class SavingsAccount : public BankAccount {
public:
    double interestRate;

    SavingsAccount(int accountNumber, const std::string& ownerName, double balance, double interestRate)
        : BankAccount(accountNumber, ownerName, balance), interestRate(interestRate) {}

    void accrueInterest() {
        double interest = balance * interestRate;
        balance += interest;
        std::cout << "Начислены проценты в размере " << std::fixed << std::setprecision(2) << interest  << " на счет " << accountNumber << std::endl;
    }
};

int main() {
  setlocale(LC_ALL, "Russian");
    BankAccount account1(12345, "Иван Иванов", 1000.0);
    SavingsAccount account2(67890, "Петр Петров", 2000.0, 0.05);


    account1.printBalance();
    account2.printBalance();
    std::cout << std::endl;

    account1.deposit(500.0);
    account2.withdraw(100.0);
    std::cout << std::endl;


  account1.printBalance();
    account2.printBalance();
    std::cout << std::endl;


    account2.accrueInterest();
    account2.printBalance();


    return 0;
}