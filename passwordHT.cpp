#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to check if the password meets all security criteria
// Returns true only if all rules pass
bool checkSecurity(string password) {
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool lengthValid = false;

    // Check length
    if (password.length() >= 10) {
        lengthValid = true;
    }

    // Loop through each character to check for letter types and digits
    for (int i = 0; i < password.length(); i++) {
        if (isupper(password[i])) {
            hasUpper = true;
        }
        if (islower(password[i])) {
            hasLower = true;
        }
        if (isdigit(password[i])) {
            hasDigit = true;
        }
    }

    if (lengthValid && hasUpper && hasLower && hasDigit) {
        return true;
    }
    else {
        return false;
    }


}

// Function to print specific failure reasons if the password is invalid
void displayErrors(string password) {
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;

    if (password.length() < 10) {
        cout << " - Must be at least 10 characters" << endl;
    }

    for (int i = 0; i < password.length(); i++) {
        if (isupper(password[i])) {
            hasUpper = true;
        }
        if (islower(password[i])) {
            hasLower = true;
        }
        if (isdigit(password[i])) {
            hasDigit = true;
        }
    }

    if (!hasUpper) {
        cout << " - Must include at least one uppercase letter" << endl;
    }
    if (!hasLower) {
        cout << " - Must include at least one lowercase letter" << endl;
    }
    if (!hasDigit) {
        cout << " - Must include at least one digit" << endl;
    }
}

int main() {
    // Initialize Variables
    string userPassword;
    int attemptCount;
    bool passwordValid;
    char userResponse;
    bool choice = false;
    bool validUserResponse;
    bool securityResult;

    // Do while loop to loop as long as the user wants to test new passwords
    do {
        // Reset counters and flags for a new session
        attemptCount = 0;
        passwordValid = false;
        securityResult = false;

        cout << "-------- Password Validator --------" << endl;
        cout << "Your password must be 10+ characters and include uppercase, lowercase, and a digit." << endl;

        // Loop until the specific password entered is valid
        while (!passwordValid) {
            attemptCount++;

            cout << "Please enter password: ";
            // Using cin.ignore if needed or getline to handle potential spaces
            if (attemptCount == 1) {
                cin.ignore();
            }
            getline(cin, userPassword);

            // Call the security check function
            securityResult = checkSecurity(userPassword);
            if (securityResult) {
                passwordValid = true;
                cout << "Password valid!" << endl;
                cout << "Total attempts: " << attemptCount << endl;
            }
            else {
                cout << "Password is invalid due to the following reasons:" << endl;
                displayErrors(userPassword);
                cout << "Please try again." << endl << endl;
            }
        }

        // Check the user response to see if they want to run the program again
        validUserResponse = false;
        while (!validUserResponse) {
            cout << "Do you want to test another password? (y/n): ";
            cin >> userResponse;

            if (userResponse == 'y' || userResponse == 'Y') {
                choice = true;
                validUserResponse = true;
                // Making space for new validator
                cout << endl << endl;
            }
            else if (userResponse == 'n' || userResponse == 'N') {
                choice = false;
                validUserResponse = true;
            }
            else {
                cout << "Invalid response. Please enter 'y' or 'n'" << endl;
            }
        }

    } while (choice == true);

    cout << "Program now exiting." << endl;

    return 0;
}