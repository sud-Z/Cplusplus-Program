// CS-210 T3623 22EW3
// Nicholas Ciesla
// 2/4/2022
// DataInOut.cpp

#include "DataInOut.h"
#include<vector>
#include <conio.h>
#include <string>
using namespace std;

DataInOut::DataInOut() {
	shared_ptr<AccountInfo> m_account = nullptr;
	double m_initInvest = 0.0;
	double m_monthlyDeposit = 0.0;
	double m_interestRate = 0.0;
	double m_numYears = 0.0;
}

void DataInOut::GetUserInput(shared_ptr<AccountInfo> const& t_account) {
	// Function to print interface and get user input.
	// Setting pointer to parameter given.
	m_account = t_account;
	bool inputLoop = true;

	// Loop for input validation functionality.
	while (inputLoop == true) {

		try {
			// Output header
			cout << "**********************************" << endl;
			cout << "*********** Data Input ***********" << endl;
			// Output Initial Investment and get input.
			cout << "Initial Ivestment Ammount: $";
			cin >> m_initInvest;
			// Check for bad input
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				throw invalid_argument("Ivalid Initial assesment, must be numerical.");
			}
			// Output Monthly deposit and get input.
			cout << "Monthly Deposit: $";
			cin >> m_monthlyDeposit;
			// Check for bad input
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				throw invalid_argument("Ivalid Monthly Deposit, must be numerical.");
			}
			// Output Annual Interest and get input.
			cout << "Annual Interest: %";
			cin >> m_interestRate;
			// Check for bad input
			if (cin.fail() || m_interestRate < 0.01) {
				cin.clear();
				cin.ignore();
				throw invalid_argument("Ivalid Input, must be numerical and 0.01 or greater");
			}
			// Output Num years and get input.
			cout << "Number of Years: ";
			cin >> m_numYears;
			// Check for bad input
			if (cin.fail() || m_numYears < 1) {
				cin.clear();
				cin.ignore();
				throw invalid_argument("Ivalid Input, must be 1 or greater");
			}
			// If the program makes it throug all input validation, the loop variable can be set to false.
			system("pause"); 
			inputLoop = false;
			
		} // Catch any bad input and output message specified.
		catch (exception e) {
			cout << endl << endl << e.what() << endl << endl;
		}
		
	}
	// Set all account variables to fresh input.
	m_account->SetInitInvest(m_initInvest);
	m_account->SetInterestRate(m_interestRate);
	m_account->SetMonthlyDeposit(m_monthlyDeposit);
	m_account->SetNumYears(m_numYears);
	
}

void DataInOut::PrintTables(shared_ptr<AccountInfo> const& t_account, double t_numYears) {
	// Function to print output.
	// Setting account pointer and creating temp interest variable.
	m_account = t_account;
	double interest;
	// Print no deposit header.
	cout << endl;
	cout << "     Balance and Interest Without Additional Monthly Deposits     " << endl;
	cout << "==================================================================" << endl;
	cout << left << setw(10) << "Year";
	cout << left << setw(28) << "Year End Balance";
	cout << left << setw(28) << "Year End Earned Interest";
	cout << endl;

	// Loop to calculate and print yearly earnings.
	for (int i = 1; i <= m_numYears; i++) {
		interest = m_account->CalculateMoneyEarnedNoDep();
		cout << left << setw(10) << i;
		cout << left << setw(28) << fixed << setprecision(2) << m_account->GetBalance();
		cout << left << setw(28) << fixed << setprecision(2) << interest;
		cout << endl;
	}
	// Reset balance for next round of calculation.
	m_account->ReSetBalance();
	// Print deposit header.
	cout << endl;
	cout << "      Balance and Interest With Additional Monthly Deposits       " << endl;
	cout << "==================================================================" << endl;
	cout << left << setw(10) << "Year";
	cout << left << setw(28) << "Year End Balance";
	cout << left << setw(28) << "Year End Earned Interest";
	cout << endl;
	// Loop to calculate and print yearly earnings.
	for (int i = 1; i <= m_numYears; i++) {
		interest = m_account->CalculateMoneyEarnedWDep();
		cout << left << setw(10) << i;
		cout << left << setw(28) << fixed << setprecision(2) << m_account->GetBalance();
		cout << left << setw(28) << fixed << setprecision(2) << interest;
		cout << endl;
	}
	// Reset balance
	m_account->ReSetBalance();


}
