#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

#define FILE_NAME "studentdata.xls"

class Student
{
private:
    string name, DOB, stream, gmail, contact_number, address;

public:
    void inputdata()
    {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Date of Birth: ";
        getline(cin, DOB);

        cout << "Enter Stream: ";
        getline(cin, stream);

        cout << "Enter Gmail: ";
        getline(cin, gmail);

        cout << "Enter Contact Number: ";
        getline(cin, contact_number);

        cout << "Enter Address: ";
        getline(cin, address);
    }

    void saveDataToFile()
    {
        FILE *file = fopen(FILE_NAME, "a");

        if (file != nullptr)
        {
            fprintf(file, "%s\t%s\t%s\t%s\t%s\t%s\n", getName().c_str(), getDOB().c_str(), getStream().c_str(), getGmail().c_str(), getContactNumber().c_str(), getAddress().c_str());
            cout << "Data saved successfully to " << FILE_NAME << endl;
            fclose(file);
        }
        else
        {
            cout << "Unable to open the file." << endl;
        }
    }

    string getName() const
    {
        return name;
    }

    string getDOB() const
    {
        return DOB;
    }

    string getStream() const
    {
        return stream;
    }

    string getGmail() const
    {
        return gmail;
    }

    string getContactNumber() const
    {
        return contact_number;
    }

    string getAddress() const
    {
        return address;
    }
};

int main()
{
    int ch;
    cout << endl
         << "\t --------------------------------------" << endl
         << "\t| Welcome to Universal 'Data Handler'  |\n"
         << "\t --------------------------------------" << endl;

    do
    {
        cout << "Press \"1\" to Start the program" << endl;
        cout << "Press \"2\" to Exit The program" << endl;
        cin >> ch;
        cout << "\n\t\tMade By Nishchay" << endl;

        if (ch == 1)
        {
            Student student;
            student.inputdata();
            student.saveDataToFile();
        }
        else if (ch != 2)
        {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (ch != 2);

    cout << "Thank you for Running this Program" << endl;

    return 0;
}
