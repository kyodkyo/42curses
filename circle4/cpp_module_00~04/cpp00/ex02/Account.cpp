#include "Account.hpp"

int Account::getNbAccounts(void){return 0;}
int Account::getTotalAmount(void){return 0;}
int Account::getNbDeposits(void){return 0;}
int Account::getNbWithdrawals(void){return 0;}
void Account::displayAccountsInfos(void){}

Account::Account(int initial_deposit){
    initial_deposit = 0;
} 
Account::~Account(void){}

void Account::makeDeposit(int deposit){
    deposit = 0;
}
bool Account::makeWithdrawal(int withdrawal){
    withdrawal = 0;
    return 0;
}
int Account::checkAmount(void) const {return 0;}
void Account::displayStatus(void) const {}
