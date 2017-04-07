#include <iostream>		
#include <cmath>		
#include <iomanip>
#include <string>
using namespace std;



void amortizationDetails(char proceed, string name)
{
	double loanAmount;
	double annualInterestRate;
	int numberOfYears;

	double monthlyPayment;
	int numberOfPayments;
	double totalInterest = 0;
	double totalCostOfLoan = 0;

	cout << "Loan Amount: ";
	cin >> loanAmount;

	cout << "Annual Interest Rate: ";
	cin >> annualInterestRate;

	cout << "Number of years to pay off the loan: ";
	cin >> numberOfYears;
	cout << endl;

	double r = annualInterestRate / (12 * 100);
	int n = numberOfYears * 12;
	monthlyPayment = loanAmount * (r / (1 - pow(1 + r, -n)));

	numberOfPayments = numberOfYears * 12;
	totalCostOfLoan = loanAmount + totalInterest;

	int paymentNumber = 0;

	double endingBalance = 0;
	double monthlyInterestRate = 0;
	double principal = 0;

	cout << "Loan Payment Information for " << name << endl;
	cout << "Loan amount $" << fixed << showpoint << setprecision(2) << loanAmount << endl;
	cout << "Annual interest rate " << fixed << showpoint << setprecision(3) << annualInterestRate << "%" << endl;
    cout << "Loan period in years " << numberOfYears << endl;	cout << endl;
	cout << "Monthly payment     " << fixed << showpoint << setprecision(2) << monthlyPayment << endl;
	cout << "Number of payments  " << numberOfPayments << endl;
	cout << "Total interest      " << totalInterest << endl;
	cout << "Total cost of loan  " << totalCostOfLoan << endl;

	cout << "Payment No. \t Payment Amount \t Principal \t Interest \t Ending Balance" << endl;
	cout << endl;

	do {
		monthlyInterestRate = loanAmount * ((annualInterestRate / 12) / 100);
		principal = monthlyPayment - monthlyInterestRate;
		endingBalance = loanAmount - principal;
		loanAmount -= principal;
		totalInterest += monthlyInterestRate;
		paymentNumber += 1;

		cout << paymentNumber;
		cout << " \t\t ";
		cout << fixed << showpoint;
		cout << setprecision(2);
		cout << " \t ";
		cout << monthlyPayment;
		cout << " \t ";
		cout << principal;
		cout << " \t ";
		cout << monthlyInterestRate;
		cout << " \t ";
		cout << endingBalance <<endl;
	} while (paymentNumber != numberOfPayments);

	cout << endl << "Do you like to create another amortization schedule [y/n]?" << endl;
	cin >> proceed;

	if (proceed == 'y' || proceed == 'Y'){
		amortizationDetails(proceed, name);
	}
	else {
		exit;
	}
}

int main()
{
	string name;
	char proceed;

	cout << "What is your name? ";
	getline(cin, name);

	cout << "Do you like to create an amortization schedule [y/n]? ";
	cin >> proceed;

	if (proceed == 'y' || proceed == 'Y'){
		amortizationDetails(proceed, name);
	}
	else {
		exit;
	}
	return 0;
}
