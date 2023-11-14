#include <iostream>
#include <vector>

class Account {
public:
    Account(int accountNumber, double balance = 0.0) : accountNumber(accountNumber), balance(balance) {}

    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposit successful. New balance: " << balance << "\n";
        } else {
            std::cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawal successful. New balance: " << balance << "\n";
        } else {
            std::cout << "Invalid withdrawal amount or insufficient funds.\n";
        }
    }

private:
    int accountNumber;
    double balance;
};

class Customer {
public:
    Customer(std::string name, int customerId) : name(name), customerId(customerId) {}

    std::string getName() const {
        return name;
    }

    int getCustomerId() const {
        return customerId;
    }

    void addAccount(Account account) {
        accounts.push_back(account);
        std::cout << "Account added successfully.\n";
    }

    void displayAccounts() const {
        std::cout << "Accounts for " << name << " (Customer ID: " << customerId << ")\n";
        for (size_t i = 0; i < accounts.size(); ++i) {
            std::cout << i + 1 << ". Account Number: " << accounts[i].getAccountNumber()
                      << ", Balance: " << accounts[i].getBalance() << "\n";
        }
    }

    std::vector<Account>& getAccounts() {
        return accounts;
    }

private:
    std::string name;
    int customerId;
    std::vector<Account> accounts;
};

class Bank {
public:
    void addCustomer(Customer customer) {
        customers.push_back(customer);
        std::cout << "Customer added successfully.\n";
    }

    void displayCustomers() const {
        std::cout << "List of Customers:\n";
        for (const auto& customer : customers) {
            std::cout << "Customer ID: " << customer.getCustomerId()
                      << ", Name: " << customer.getName() << "\n";
        }
    }

private:
    std::vector<Customer> customers;
};

int main() {
    Bank bank;

    std::string customerName;
    int customerId;

    std::cout << "Enter customer name: ";
    std::getline(std::cin, customerName);

    std::cout << "Enter customer ID: ";
    std::cin >> customerId;

    Customer customer(customerName, customerId);
    bank.addCustomer(customer);

    int numAccounts;
    std::cout << "Enter the number of accounts to create: ";
    std::cin >> numAccounts;

    for (int i = 0; i < numAccounts; ++i) {
        int accountNumber;
        std::cout << "Enter account number for Account " << i + 1 << ": ";
        std::cin >> accountNumber;

        double initialBalance;
        std::cout << "Enter initial balance for Account " << i + 1 << ": ";
        std::cin >> initialBalance;

        customer.addAccount(Account(accountNumber, initialBalance));
    }

    // Display customers and their accounts
    bank.displayCustomers();
    customer.displayAccounts();

    // Example: Deposit and Withdrawal
    int accountIndex;
    std::cout << "Enter the account index for deposit/withdrawal: ";
    std::cin >> accountIndex;

    double depositAmount;
    std::cout << "Enter the deposit amount: ";
    std::cin >> depositAmount;

    customer.getAccounts()[accountIndex - 1].deposit(depositAmount);

    double withdrawalAmount;
    std::cout << "Enter the withdrawal amount: ";
    std::cin >> withdrawalAmount;

    customer.getAccounts()[accountIndex - 1].withdraw(withdrawalAmount);

    return 0;
}
