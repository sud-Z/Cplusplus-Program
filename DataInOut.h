// CS-210 T3623 22EW3
// Nicholas Ciesla
// 2/4/2022
// DataInOut.h

#ifndef DATA_IN_OUT_H
#define DATA_IN_OUT_H

#include "AccountInfo.h"
#include<iostream>
#include<iomanip>
#include<memory>
using namespace std;

class DataInOut {
	
	public:
		// Constructor
		DataInOut(); 
		// Function to print interface and get input.
		void GetUserInput(shared_ptr<AccountInfo> const& t_account);
		// Function to print output.
		void PrintTables(shared_ptr<AccountInfo> const& t_account, double t_numYears);
	private:
		// Pointer for acessing account.
		shared_ptr<AccountInfo> m_account;
		// Members for temporary use.
		double m_initInvest = 0.0;
		double m_monthlyDeposit = 0.0;
		double m_interestRate = 0.0;
		double m_numYears = 0.0;

};

#endif