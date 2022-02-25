// CS-210 T3623 22EW3
// Nicholas Ciesla
// 2/4/2022
// AccountInfo.cpp

#include "AccountInfo.h"

AccountInfo::AccountInfo() { // Default Constructor

	m_initInvest = 0.0;
	// Setting balance to the initial investment.
	m_balance = m_initInvest; 

	m_monthlyDeposit = 0.0;
	m_interestRate = 0.0;
	m_numYears = 0.0;

}

// Constructor with parameters.
AccountInfo::AccountInfo(double t_initInvest, double t_monthlyDeposit, double t_interestRate, double t_numYears) {

	m_initInvest = t_initInvest;
	// Setting balance to the initial investment.
	m_balance = m_initInvest;

	m_monthlyDeposit = t_monthlyDeposit;
	m_interestRate = t_interestRate;
	m_numYears = t_numYears;

}

void AccountInfo::SetInitInvest(double t_initInvest) { 
	// Setter for Initial Investment automatically also sets balance.
	m_initInvest = t_initInvest;
	SetBalance(t_initInvest);
}
double AccountInfo::GetInitInvest() {
	return m_initInvest;
}

void AccountInfo::SetBalance(double t_balance) {
	m_balance = t_balance;
}
double AccountInfo::GetBalance() {
	return m_balance;
}

void AccountInfo::SetMonthlyDeposit(double t_monthlyDeposit) {
	m_monthlyDeposit = t_monthlyDeposit;
}
double AccountInfo::GetMonthlyDeposit() {
	return m_monthlyDeposit;
}

void AccountInfo::SetInterestRate(double t_interestRate) {
	m_interestRate = t_interestRate;
}
double AccountInfo::GetInterestRate() {
	return m_interestRate;
}

void AccountInfo::SetNumYears(double t_numYears) {
	m_numYears = t_numYears;
}
double AccountInfo::GetNumYears() {
	return m_numYears;
}

void AccountInfo::ReSetBalance() {
	// Function to set balance back to initial investment.
	m_balance = m_initInvest;
}

double AccountInfo::CalculateMoneyEarnedNoDep() {
	// Function to calculate one year of interest earned with no deposits.
	double interest = 0;
	// Converting yearly interest to monthly
	double monthlyInterest = ((m_interestRate / 100.0) / 12.0);

	for (int i = 0; i < 12; i++) {
		// This seemed odd to me, if I added interest to the total before the end of the year with this one,
		// I would get different results than the example, but if I had to do that with the deposit function.
		interest += (m_balance) * monthlyInterest;
	}

	m_balance += interest;
	return interest;
}

double AccountInfo::CalculateMoneyEarnedWDep() {
	// Function to calculate one year of interest earned with deposits.
	double interest = 0;
	double totalInterest = 0;
	// Converting yearly interest to monthly
	double monthlyInterest = ((m_interestRate / 100.0) / 12.0);
	

	for (int i = 0; i < 12; i++) {
		m_balance += m_monthlyDeposit;
		interest = (m_balance) * monthlyInterest;
		// As previously mentioned.
		m_balance += interest;
		totalInterest += interest;
	}
	
	return totalInterest;

}