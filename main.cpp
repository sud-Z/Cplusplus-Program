// CS-210 T3623 22EW3
// Nicholas Ciesla
// 2/4/2022
// main.cpp

#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
using namespace std;

#include "AccountInfo.h"
#include "DataInOut.h"

int main()
{
    // Create account pointer to pass to other classes, DataIO object, loop bool, and user input string.
    auto account = make_shared<AccountInfo>(); 
    DataInOut DataIO;
    bool runAgain = true;
    string userInput;

    // Program Function loop
    while (runAgain) {
        // Get Input from user using dataio object.
        DataIO.GetUserInput(account);
        // Print output tables.
        DataIO.PrintTables(account, account->GetNumYears());
        
        cout << endl << endl;
        // Output and get user input for run again message.
        cout << "Would you like to try again? Enter y or n  ";

        cin >> userInput;
        // Check if user responded anything but yes.
        if (userInput != "y") {
            // End program.
            runAgain = false; 
        }
        else {
            // Clear two lines for new input box.
            cout << endl << endl;
        }
    }

    
    

}


