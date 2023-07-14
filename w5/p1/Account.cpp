/*/////////////////////////////////////////////////////////////////////////
                       OOP244 Workshop - #5 (PART 1)
Student Name: Julia Alekseev
Student ID#:  051292134
Email      :  jalekseev@myseneca.ca
Section    :  NEE
Date:      :  June 13, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }
   //operator bool returns true if the account is validand otherwise false.This operator can not modify the account object
   //An Account is considered valid if the account number is a 5 digit integer with a zero or positive balance.
   Account::operator bool() const {
       return m_number >= 10000 && m_balance >= 0;
   }

   //operator int returns the account number.This operator can not modify the account object.
   Account::operator int() const {
       return  m_number;
   }
   //operator double returns the balance value.This operator can not modify the account object.
   Account::operator double() const {
       return m_balance;
   }

   //bool operator ~() This operator returns true is the account is new or not set(i.e. if the account number is zero), otherwise it will return false.This operator can not modify the account object.
   bool Account::operator~() const {
       return m_number == 0;
   }

   /*overload the assignment operator so a NEW account can be set to an integer. Doing so should set the account number of the account to the integer value.
    If the integer value is an invalid account number, the object should be set to an invalid empty state instead.
    If the account is not new, then this operator should not perform any action.
    In any case, a reference of the current object (account) should be returned.*/
   Account& Account::operator=(int number) {
       if (operator~()) {
           if (number >= 10000 && number <= 99999) {
               m_number = number;
           }
           else {
               setEmpty();
           }
       }
       return *this;
   }
   /*overload the assignment operator so a NEW account can be set to another Account object. This action should move the balance and the account number from one account to another;
    therefore unlike the usual assignment operator that affects the left operand only, this operator will affect both operands; the balance of the left account will be set to the balance 
    of the right account and then the balance of the right account will be set to zero. The same will happen to the account number
    If the left Account operand is not new or the right account operand is not valid, no action should be taken.
    In any case, a reference of the current object (account) should be returned.*/
   Account& Account::operator=(Account& rhs) {
       if (operator~() && rhs) {
           m_number = rhs.m_number;
           m_balance = rhs.m_balance;
           rhs.m_number = 0;
           rhs.m_balance = 0.0;
       }
       return *this;
   }

   /*overload the += operator to add a double value to an account. This should act like depositing money into an account. (i.e. the value of the double should be added to the balance)
    if the account is in an invalid state or the double value is negative, no action should be taken.
    In any case, a reference of the current object (account) should be returned.*/
   Account& Account::operator+=(double num) {
       if (operator bool() && num > 0) {
           m_balance += num;
       }
       return *this;
   }

   /*overload the -= operator to reduce an account balance by a double value . 
   This should act like withdrawing money from an account. (i.e. the value of the balance should be reduced by the double value)
    if the account is in an invalid state, the double value is negative or there is not enough money in the account no action should be taken.
    In any case, a reference of the current object (account) should be returned.*/
   Account& Account::operator-=(double num) {
       if (operator bool() && num > 0 && m_balance > 0 && m_balance - num >= 0) {
           m_balance -= num;
       }
       return *this;
   }

   /*overload the **<< operator** (left shift operator) to move funds from the right account to the left. After this operation, the balance of the left account will be the sum of both and the balance of the right account will be zero.
    Funds of an account should not be able to be moved to itself and this operation does not affect the account.
    In any case, a reference of the current object (account) should be returned.*/
   Account& Account::operator<<(Account& rhs) {
       if (this != &rhs && operator bool()) {
          m_balance += rhs.m_balance;
           rhs.m_balance = 0.0;
       }
       return *this;
   }

   /*overload the >> operator (right shift operator) to move funds from the left account to the right. After this operation, the balance of the right account will be the sum of both and the balance of the left account will be zero.
    Funds of an account should not be able to be moved to itself and this operation does not affect the account.
    In any case, a reference of the current object (account) should be returned.*/
   Account& Account::operator>>(Account& rhs) {
       if (this != &rhs && operator bool()) {
           rhs.m_balance += m_balance;
           m_balance = 0.0;
       }
       return *this;
   }

   /*-- create a binary stand alone helper + operator that accepts a constant account reference at left and another constant account reference at right and returns a double value.
    The double value should be the sum of the balances of the two accounts.
    If any of the two accounts is invalid, then zero is returned.*/
  double operator+(const Account& lhs, const Account& rhs) {
      double sum = 0;
      if (lhs && rhs) {
          sum = double(lhs) + double(rhs);
       }
       return sum;
   }

   /*-- create a binary stand alone helper += operator that accepts a double reference at left and a constant account reference at right and returns a double value.
    The value of the balance of the right operand (account reference) should be added to the left operand (double reference)
    Then the value of the double reference is returned. */
   double operator+=(double& num, const Account& rhs) {
       if (rhs) {
           num += rhs.operator double();
       }
       return num;
   }


}