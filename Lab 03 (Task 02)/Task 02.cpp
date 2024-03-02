#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    
    map<string, string> contacts;

    contacts["Asghar Ali"] = "03123546006";
    contacts["Saeed"] = "03123546005";
    contacts["Mustafa"] = "03123546004";
    contacts["Zohad"] = "03123546000";

    cout << "Initial Contacts:" << endl;
    for (const pair<const string, string>& contact : contacts) {
        cout << contact.first << ": " << contact.second << endl;
    }

    char choice;
    do {
        cout << "\nChoose an option:\n";
        cout << "1. Enter a new contact detail.\n";
        cout << "2. Search the directory.\n";
        cout << "Enter your choice (1/2): ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
        case '1': {
           
            string newContactName, newContactDetails;
            cout << "\nEnter the name of the new contact: ";
            getline(cin, newContactName);
            cout << "Enter the details of the new contact: ";
            getline(cin, newContactDetails);
            contacts[newContactName] = newContactDetails;

            cout << "\nUpdated Contacts:" << endl;
            for (const pair<const string, string>& contact : contacts) {
                cout << contact.first << ": " << contact.second << endl;
            }
            break;
        }
        case '2': {
            string searchName;
            cout << "\nEnter the name of the contact you want to search: ";
            getline(cin, searchName);

            map<string, string>::iterator details = contacts.find(searchName);
            if (details != contacts.end()) {
                cout << "Contact found:\n" << details->first << ": " << details->second << endl;
            }
            else {
                cout << "Contact not found." << endl;
            }
            break;
        }

        default:
            cout << "Invalid choice! Please enter 1 or 2." << endl;
        }

        cout << "Do you want to enter a new contact detail or search the directory? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
