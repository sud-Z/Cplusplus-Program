// CS-210 T3623 22EW3
// Nicholas Ciesla
// 2/4/2022
// AccountInfo.h

#ifndef ACCOUNT_INFO_H
#define ACCOUNT_INFO_H

class AccountInfo {
	public:
		// Construtors
		AccountInfo();
		AccountInfo(double t_initInvest, double t_monthlyDeposit, double t_interestRate, double t_numYears);
		// Setters and getters for members.
		void SetInitInvest(double t_initInvest);
		double GetInitInvest();

		void SetBalance(double t_balance);
		void ReSetBalance(); // Reset function for Balance.
		double GetBalance();

		void SetMonthlyDeposit(double t_monthlyDeposit);
		double GetMonthlyDeposit();

		void SetInterestRate(double t_interestRate);
		double GetInterestRate();

		void SetNumYears(double t_numYears);
		double GetNumYears();

		double CalculateMoneyEarnedNoDep();
		double CalculateMoneyEarnedWDep();

	private:
		// Class Members
		double m_initInvest;
		double m_balance;
		double m_monthlyDeposit;
		double m_interestRate;
		double m_numYears;
};

#endif
