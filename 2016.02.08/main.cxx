// ************************************************************************* //
// * Daily Programmer 2016-02-08 Easy: Unconditional Loan Income           * //
// * https://www.reddit.com/r/dailyprogrammer/comments/44qzj5/             * //
// ************************************************************************* //

#include <iomanip>
using std::setprecision;
using std::setw;
using std::setfill;
#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
using std::right;
#include <numeric>
using std::accumulate;
#include <list>
using std::list;

int main()
{
    float interestRate = 1.02;
    float annualLoan = 15000;
    float clawbackTrigger = 100000;
    float clawback = 0;
    float royaltyYoung = 0.2;
    float royaltyOld = 0.4;
    float royalty = royaltyYoung;
    float repayment = 0;
    int   age = 18;
    float outstandingDebt = 0;
    float totalLoans = 0;
    float totalIncomeRepayments = 0;
    float totalClawbackRepayments = 0;
    bool  useInterestCap = true;
    float interestCap = 0;
    list<float> loans;
    list<float> incomeStream1({ 0, 0, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
    list<float> incomeStream2({ 0, 0, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 100, 120, 140, 160, 200, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 });
    list<float> incomeStream = incomeStream2;

    while (!incomeStream.empty())
    {
        for (float& loan : loans)
        {
            loan *= interestRate;
            
            if (useInterestCap && (loan > 2 * annualLoan))
            {
                interestCap += loan - (2 * annualLoan);
                loan = 2 * annualLoan;
            }
        }

        // Calculate age based royalties
        if (age < 65) royalty = royaltyYoung;
        else royalty = royaltyOld;
        repayment = royalty * 1000 * incomeStream.front();
        totalIncomeRepayments += repayment;
        incomeStream.pop_front();

        // Loans dispersed at the beginning of the year
        loans.emplace_back(annualLoan);
        totalLoans += annualLoan;

        // Check the clawback condition
        outstandingDebt = accumulate(loans.begin(), loans.end(), 0);
        if (outstandingDebt > clawbackTrigger) clawback = royalty * annualLoan;
        else clawback = 0;
        totalClawbackRepayments += clawback;
        repayment += clawback;

        // cout << "Age: " << age;
        // cout << " Loans: " << loans.size();
        // cout << " Outstanding Debt: " << fixed << setprecision(2) << outstandingDebt;

        // Pay off some of these loans
        while ((repayment > 0) && !loans.empty())
        {
            if (loans.front() > repayment) 
            {
                loans.front() -= repayment;
                repayment = 0;
            }
            else
            {
                repayment -= loans.front();
                loans.pop_front();
                // cout << " Loan Repaid";
            }
        }

        // cout << endl;

        ++age;
    }
    outstandingDebt = accumulate(loans.begin(), loans.end(), 0);

    // cout << endl;
    cout << "Overall loans taken:";
    cout << setw(25) << setfill(' ');
    cout << right << fixed << setprecision(2) << totalLoans << endl;

    cout << "Repayments from income:";
    cout << setw(22) << setfill(' ');
    cout << right << fixed << setprecision(2) << totalIncomeRepayments << endl;

    cout << "Repayments from benefit clawbacks:";
    cout << setw(11) << setfill(' ');
    cout << right << fixed << setprecision(2) << totalClawbackRepayments << endl;

    cout << "Savings from interest cap:";
    cout << setw(19) << setfill(' ');
    cout << right << fixed << setprecision(2) << interestCap << endl;

    cout << "Ending balance with interest:";
    cout << setw(16) << setfill(' ');
    cout << right << fixed << setprecision(2) << outstandingDebt << endl;

    cout << "Reclaimed:";
    cout << setw(34) << setfill(' ');
    cout << right << fixed << setprecision(1) << 100 * (totalClawbackRepayments + totalIncomeRepayments)/totalLoans << "%" << endl;
    return 0;
}
