// Zoe Dauphinee, lab 3, class basics

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// Task 1
// Define an Account struct
struct Account_struct {
    string name;
    int number;
};

// Task 2
// Define an Account class (use a different name than in Task 1)
class Account {
    friend ostream& operator<<(ostream& os, const Account& account);
    public:
        Account(const string& name, int number) : name(name), number(number) {}
        const string& get_name() const { return name; }
        const int get_number() const { return number; }
    private:
        string name;
        int number;
};

// ostream& operator<<(ostream& os, Account& account);


// Task 3
// Define an Account (use a different name than in Task 1&2) and
// Transaction classes
class Transaction {
    friend ostream& operator<<(ostream& os, const Transaction& transaction);
    public:
        Transaction(const string& type, int amount) : type(type), amount(amount) {}
    private:
        string type;
        int amount;
};

class Account2 {
    friend ostream& operator<<(ostream& os, const Account2& account);    
    public:
        Account2(const string& name, int number) : name(name), number(number) {}
        const int get_number() const { return number; }
        void deposit(int amount);
        void withdrawal(int amount);
    private:
        string name;
        int number;
        int balance = 0;
        vector<Transaction> transactions;
};


// Task 4
// Define an Account with a nested public Transaction class
// (use different names than in the previous Tasks)
class Account3 {
    friend ostream& operator<<(ostream& os, const Account3& account);
    public:
        Account3(const string& name, int number) : name(name), number(number) {}
        const int get_number() const { return number; }
        void deposit(int amount);
        void withdrawal(int amount);
        class Nested_transaction {
            friend ostream& operator<<(ostream& os, const Nested_transaction& transaction);
            public:
                Nested_transaction(const string& type, int amount) : type(type), amount(amount) {}
            private:
                string type;
                int amount;
        };
    private:
        string name;
        int number;
        int balance = 0;
        vector<Transaction> transactions;
};


// Task 5
// Define an Account with a nested private Transaction class
// (use different names than in the previous Tasks)
class Account4 {
    private:
        string name;
        int number;
        int balance = 0;
        vector<Transaction> transactions;
        class Private_nested_transaction {
                friend ostream& operator<<(ostream& os, const Private_nested_transaction& transaction);
            public:
                Private_nested_transaction(const string& type, int amount) : type(type), amount(amount) {}
            private:
                string type;
                int amount;
        };
    public:
        Account4(const string& name, int number) : name(name), number(number) {}
        const int get_number() const { return number; }
        void deposit(int amount);
        void withdrawal(int amount);   
    friend ostream& operator<<(ostream& os, const Account4& account);
    friend ostream& operator<<(ostream& os, const Private_nested_transaction& transaction);
};


int main() {
    
    // Task 1: account as struct
    //      1a
    cout << "Task1a:\n";
    cout << "Filling vector of struct objects, define a local struct instance and set fields explicitly:\n";

    ifstream file("accounts.txt");
    if (!file) {
        cerr << "failed to open accounts.txt" << endl;
        exit(1);
    }

    string acc_name;
    int acc_num;
    vector<Account_struct> struct_accounts;
    while (file >> acc_name >> acc_num) {
        Account_struct account;
        account.name = acc_name;
        account.number = acc_num;
        struct_accounts.push_back(account);
    }

    file.close();

    for (size_t index = 0; index < struct_accounts.size(); ++index) {
        cout << struct_accounts[index].name << ' ' << struct_accounts[index].number << endl;
    }

    //      1b
    cout << "Task1b:\n";
    cout << "Filling vector of struct objects, using {} initialization:\n";

    struct_accounts.clear();
    file.open("accounts.txt");
    if (!file) {
        cerr << "failed to open accounts.txt" << endl;
        exit(1);
    }

    string acc_name2;
    int acc_num2;
    while (file >> acc_name2 >> acc_num2) {
        Account_struct account{acc_name2, acc_num2};
        struct_accounts.push_back(account);
    }

    file.close();

    for (size_t index = 0; index < struct_accounts.size(); ++index) {
        cout << struct_accounts[index].name << ' ' << struct_accounts[index].number << endl;
    }


    //==================================
    // Task 2: account as class

    //      2a
    cout << "==============\n";
    cout << "\nTask2a:";
    cout << "\nFilling vector of class objects, using local class object:\n";

    file.open("accounts.txt");
    if (!file) {
        cerr << "failed to open accounts.txt" << endl;
        exit(1);
    }

    vector<Account> accounts;
    string acc_name3;
    int acc_num3;
    while (file >> acc_name3 >> acc_num3) {
        Account account(acc_name3, acc_num3);
        accounts.push_back(account);
    }

    file.close();

    for (size_t index = 0; index < accounts.size(); ++index) {
        cout << accounts[index].get_name() << ' ' << accounts[index].get_number() << endl;
    }

    //      2b
    cout << "\nTask2b:\n";
    cout << "output using output operator with getters\n";

    for (size_t index = 0; index < accounts.size(); ++index) {
        cout << accounts[index] << endl;
    }

    //      2c
    cout << "\nTask2c:\n";
    cout << "output using output operator as friend without getters\n";

    for (size_t index = 0; index < accounts.size(); ++index) {
        cout << accounts[index] << endl;
    }

    //      2d
    cout << "\nTask2d:\n";
    cout << "Filling vector of class objects, using temporary class object:\n";

    accounts.clear();
    file.open("accounts.txt");

    string acc_name4;
    int acc_num4;
    while (file >> acc_name4 >> acc_num4) {
        accounts.push_back(Account(acc_name4, acc_num4));
    }

    file.close();

    for (size_t index = 0; index < accounts.size(); ++index) {
        cout << accounts[index] << endl;
    }

    //      2e
    cout << "\nTask2e:\n";
    cout << "Filling vector of class objects, using emplace_back:\n";

    accounts.clear();
    file.open("accounts.txt");
    if (!file) {
        cerr << "failed to open accounts.txt" << endl;
        exit(1);
    }

    string acc_name5;
    int acc_num5;
    while (file >> acc_name5 >> acc_num5) {
        accounts.emplace_back(acc_name5, acc_num5);
    }

    file.close();

    for (size_t index = 0; index < accounts.size(); ++index) {
        cout << accounts[index] << endl;
    }
    

    //==================================
    // Task 3: transaction as class

    cout << "==============\n";
    cout << "\nTask 3:\nAccounts and Transaction:\n";

    ifstream transaction_file("transactions.txt");
    if(!transaction_file) {
        cerr << "failed to open transactions.txt\n";
        exit(1);
    }

    vector<Account2> accounts2;
    string command;
    string name;
    int acc_num6;
    int amt;
    while (transaction_file >> command) {
        if (command == "Account") {
            transaction_file >> name >> acc_num6;
            accounts2.emplace_back(name, acc_num6);
        }
        else if (command == "Deposit") {
            transaction_file >> acc_num6 >> amt;
            for (size_t index = 0; index < accounts2.size(); ++index) {
                if (accounts2[index].get_number() == acc_num6) {
                    accounts2[index].deposit(amt);
                    break;
                }
            }
        }
        else if (command == "Withdraw") {
            transaction_file >> acc_num6 >> amt;
            for (size_t index = 0; index < accounts2.size(); ++index) {
                if (accounts2[index].get_number() == acc_num6) {
                    accounts2[index].withdrawal(amt);
                    break;
                }
            }
        }
    }

    transaction_file.close();

    for (size_t index = 0; index < accounts2.size(); ++index) {
        cout << accounts2[index] << endl;
    }


    //==================================
    // Task 4: transaction nested in Account (public)

    cout << "==============\n";
    cout << "\nTask 4:\nTransaction nested in public section of Account:\n";

    transaction_file.open("transactions.txt");
    if(!transaction_file) {
        cerr << "failed to open transactions.txt\n";
        exit(1);
    }

    vector<Account3> accounts3;
    string command2;
    string name2;
    int acc_num7;
    int amt2;
    while (transaction_file >> command2) {
        if (command2 == "Account") {
            transaction_file >> name2 >> acc_num7;
            accounts3.emplace_back(name2, acc_num7);
        }
        else if (command2 == "Deposit") {
            transaction_file >> acc_num7 >> amt2;
            for (size_t index = 0; index < accounts3.size(); ++index) {
                if (accounts3[index].get_number() == acc_num7) {
                    accounts3[index].deposit(amt2);
                    break;
                }
            }
        }
        else if (command2 == "Withdraw") {
            transaction_file >> acc_num7 >> amt2;
            for (size_t index = 0; index < accounts3.size(); ++index) {
                if (accounts3[index].get_number() == acc_num7) {
                    accounts3[index].withdrawal(amt2);
                    break;
                }
            }
        }
    }

    transaction_file.close();
    
    for (size_t index = 0; index < accounts3.size(); ++index) {
        cout << accounts3[index] << endl;
    }


    //==================================
    // Task 5: transaction nested in Account (private)

    cout << "==============\n";
    cout << "\nTask 5:\nTransaction nested in private section of Account:\n";

    transaction_file.open("transactions.txt");
    if(!transaction_file) {
        cerr << "failed to open transactions.txt\n";
        exit(1);
    }

    vector<Account4> accounts4;
    string command3;
    string name3;
    int acc_num8;
    int amt3;
    while (transaction_file >> command3) {
        if (command3 == "Account") {
            transaction_file >> name3 >> acc_num8;
            accounts4.emplace_back(name3, acc_num8);
        }
        else if (command3 == "Deposit") {
            transaction_file >> acc_num8 >> amt3;
            for (size_t index = 0; index < accounts4.size(); ++index) {
                if (accounts4[index].get_number() == acc_num8) {
                    accounts4[index].deposit(amt3);
                    break;
                }
            }
        }
        else if (command3 == "Withdraw") {
            transaction_file >> acc_num8 >> amt3;
            for (size_t index = 0; index < accounts4.size(); ++index) {
                if (accounts4[index].get_number() == acc_num8) {
                    accounts4[index].withdrawal(amt3);
                    break;
                }
            }
        }
    }

    transaction_file.close();
    
    for (size_t index = 0; index < accounts4.size(); ++index) {
        cout << accounts4[index] << endl;
    }
}



// =========== Task 2 implementations ===========

// output operator in 2b
//ostream& operator<<(ostream& os, Account& account) {
//    os << account.get_name() << ' ' << account.get_number();
//    return os;
//}

// output operator in 2c
ostream& operator<<(ostream& os, const Account& account) {
    os << account.name << ' ' << account.number;
    return os;
}


// =========== Task 3 implementations ===========

// output operator for Account2 class
ostream& operator<<(ostream& os, const Account2& account) {
    os << account.name << ' ' << account.number << ":\n";
    for (size_t index = 0; index < account.transactions.size(); ++index) {
        os << "    " << account.transactions[index] << endl;
    }
    return os;
}

void Account2::deposit(int amount) {
    Transaction new_transaction("Deposit", amount);
    transactions.push_back(new_transaction);
    balance += amount;
}
void Account2::withdrawal(int amount) {
    if (balance < amount) {
        cout << "Account# " << number << " has only " << balance 
        << ". Insufficient for withdrawal of " << amount << ".\n";
    }
    else { 
        balance -= amount;     
        Transaction new_transaction("Withdrawal", amount);
        transactions.push_back(new_transaction);
    }
}

// output operator for Transaction class
ostream& operator<<(ostream& os, const Transaction& transaction) {
    os << transaction.type << ' ' << transaction.amount;
    return os;
}


// =========== Task 4 implementations ===========

void Account3::deposit(int amount) {
    Transaction new_transaction("Deposit", amount);
    transactions.push_back(new_transaction);
    balance += amount;
}
void Account3::withdrawal(int amount) {
    if (balance < amount) {
        cout << "Account# " << number << " has only " << balance 
        << ". Insufficient for withdrawal of " << amount << ".\n";
    }
    else { 
        balance -= amount;     
        Transaction new_transaction("Withdrawal", amount);
        transactions.push_back(new_transaction);
    }
}

ostream& operator<<(ostream& os, const Account3& account) {
    os << account.name << ' ' << account.number << ":\n";
    for (size_t index = 0; index < account.transactions.size(); ++index) {
        os << "    " << account.transactions[index] << endl;
    }
    return os;
}
ostream& operator<<(ostream& os, const Account3::Nested_transaction& transaction) {
    os << transaction.type << ' ' << transaction.amount;
    return os;
}

// =========== Task 5 implementations ===========

void Account4::deposit(int amount) {
    Transaction new_transaction("Deposit", amount);
    transactions.push_back(new_transaction);
    balance += amount;
}
void Account4::withdrawal(int amount) {
    if (balance < amount) {
        cout << "Account# " << number << " has only " << balance 
        << ". Insufficient for withdrawal of " << amount << ".\n";
    }
    else { 
        balance -= amount;     
        Transaction new_transaction("Withdrawal", amount);
        transactions.push_back(new_transaction);
    }
}

ostream& operator<<(ostream& os, const Account4& account) {
    os << account.name << ' ' << account.number << ":\n";
    for (size_t index = 0; index < account.transactions.size(); ++index) {
        os << "    " << account.transactions[index] << endl;
    }
    return os;
}
ostream& operator<<(ostream& os, const Account4::Private_nested_transaction& transaction) {
    os << transaction.type << ' ' << transaction.amount;
    return os;
}