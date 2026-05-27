#include <iostream>
#include <fstream>
#include<cctype>
#include<string>
using namespace std;

// Register
void registerUser() {

    string username, password;

    cout << "CREATE YOUR USERNAME: ";
    cin >> username;

    cout << "CREATE PASSWORD: ";
    cin >> password;


    if (username.empty() || password.empty()) {
        cout << "FIELDS CANNOT BE EMPTY!\n";
        return;
    }

 // Check duplicate username

    ifstream checkFile(username + ".txt");
   
        if (checkFile) {
            cout << "USERNAME ALREADY EXISTS! TRY A DIFFERENT ONE.\n";
            checkFile.close();
            return;

        }
   checkFile.close(); 
    
    
    // Strong Password Validation
    if (password.length() < 6) {
        cout << "PASSWORD MUST BE AT LEAST 6 CHARACTERS LONG!\n";
        return;
    }

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;

    for (char ch : password)
    {
        if (isupper(ch))
            hasUpper = true;
        else if (islower(ch))
            hasLower = true;
        else if (isdigit(ch)) 
            hasDigit = true;
    }

    if (!hasUpper || !hasLower || !hasDigit)
    {
        cout << "\nPASSWORD IS TOO WEAK! IT MUST CONTAIN :\n";

        if (!hasUpper) 
            cout << "\t --AT LEAST ONE UPPERCASE LETTER (A-Z)\n";
        if (!hasLower)
            cout << "\t --AT LEAST ONE LOWERCASE LETTER (a-z)\n";
        if (!hasDigit) 
            cout << "\t --AT LEAST ONE NUMBER (0-9)\n";

        return; // Stop registration if requirements are missing
    }

    // Create personal file for this user
    ofstream userFile(username + ".txt");

    if (!userFile) {
        cout << "ERROR CREATING USERS FILE!\n";
        return;
    }
    userFile << username << " " << password << endl;
    userFile.close();

   cout << "\nREGISTRATION SUCCESSFUL!\n";
   
}

// Login
bool loginUser(string u, string p) {
    ifstream file(u + ".txt");
    if (!file) {
        cout << "USER NOT FOUND!\n";
        return false;
    }

    string fileUser, filePass;

    while (file >> fileUser >> filePass) {
        if (fileUser == u && filePass == p) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}
int main() 
{
    int choice;
    do {
        cout << "\n\t\t\t\t============================================" << endl;
        cout << "\t\t\t\t||     USER REGISTRATION & LOGIN SYSTEM   ||" << endl;
        cout << "\t\t\t\t============================================" << endl;

        cout << "\t\t\t\t|      1. REGISTER                         |" << endl;
        cout << "\t\t\t\t|      2. LOGIN                            |" << endl;
        cout << "\t\t\t\t|      3. EXIT                             |" << endl;

        cout << "\t\t\t\t============================================" << endl;

        cout << "\n\nENTER YOUR CHOICE : ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "INVALID INPUT!\n";
            continue;
        }
        switch (choice)
        {
        case 1:
            registerUser();
            break;

        case 2:
        {
            string username, password;

            cout << "ENTER USERNAME: ";
            cin >> username;

            cout << "ENTER PASSWORD: ";
            cin >> password;
            
            if (loginUser(username, password))
                cout << "\nLOGIN SUCCESSFUL!\n";
            else
                cout << "\nINVALID USERNAME OR PASSWORD!\n";
            break;
        }

        case 3:
            cout << "\nPROGRAM EXITED.\n";
            break;

        default:
            cout << "\nINVALID CHOICE.\n";
        }
    } while (choice != 3);
   
    return 0;
    
} 

