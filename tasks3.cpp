                                      //LOGIN AND REGISTRATION FORM 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to register a new user
void registerUser() {
    string username, password;
    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    // Open the file in append mode to store user credentials
    ofstream file;
    file.open("credentials.txt", ios::app);
    if (file.is_open()) {
        file << username << " " << password << endl;
        file.close();
        cout << "Registration successful!" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
}

// Function to login an existing user
bool loginUser() {
    string username, password, storedUsername, storedPassword;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    // Open the file in read mode to verify user credentials
    ifstream file;
    file.open("credentials.txt");
    if (file.is_open()) {
        bool loginSuccess = false;
        while (file >> storedUsername >> storedPassword) {
            if (storedUsername == username && storedPassword == password) {
                loginSuccess = true;
                break;
            }
        }
        file.close();

        if (loginSuccess) {
            cout << "Login successful!" << endl;
            return true;
        } else {
            cout << "Invalid username or password!" << endl;
            return false;
        }
    } else {
        cout << "Error opening file!" << endl;
        return false;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "1. Register\n2. Login\n3. Exit\nChoose an option: ";
        cin >> choice;

        if (choice == 1) {
            registerUser();
        } else if (choice == 2) {
            if (loginUser()) {
                break;  // Exit loop if login is successful
            }
        } else if (choice == 3) {
            cout << "Exiting..." << endl;
            break;
        } else {
            cout << "Invalid option! Try again." << endl;
        }
    }

    return 0;
}