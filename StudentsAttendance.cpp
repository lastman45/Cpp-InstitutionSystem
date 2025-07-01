#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;

int AdminView();
int StudentView();
int StudentSignin();
int CheckStudentsCredentials(string Username, string Password);
int GetAllStudentsbyRollNo();
int DeleteAllStudents();
int DeleteStudentbyRollNo();
int ListofStudentsEnrolled();
int CheckPresentCountbyRollNo();
int DisplayStudentsPresent();
int EnrollStudent();
int AdminSignin();
int MarkMyAttendance(string Username);
int CountMyAttendance(string Username);
void Delay();

void Delay() // slight pause
{
    for (int i = 0; i < 3; i++)
    {
        cout << "\nSaving Records...";
        this_thread::sleep_for(chrono::milliseconds(500)); // 500 milliseconds delay simmulating saving process
    }
    cout << "\nExiting Now....";
}

int AdminView()
{
    int GoBack = 0;
    while (1)
    {
        system("cls");
        cout << "\n 1.Enroll a Student";
        cout << "\n 2.Delete all Students Enrolled";
        cout << "\n 3.Delete a Student by Roll No.";
        cout << "\n 4.Check List of Students Enrolled by Username";
        cout << "\n 5.Check Present Count of Students by Roll No.";
        cout << "\n 6.Get List of Students with Attendance count";
        cout << "\n 7.Sign out";
        int choice;

        cout << "\n Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            EnrollStudent();
            break;
        case 2:
            DeleteAllStudents();
            break;
        case 3:
            DeleteStudentbyRollNo();
            break;
        case 4:
            ListofStudentsEnrolled();
            break;
        case 5:
            CheckPresentCountbyRollNo();
            break;
        case 6:
            DisplayStudentsPresent();
            break;
        case 7:
            GoBack = 1;
            break;
        default:
            cout << "\n Invalid choice. Please try again.";
            getchar();
        }
        if (GoBack == 1)
        {
            break;
        }
    }
    return 0;
}

int StudentSignin()
{
    system("cls");
    cout << "\n STUDENT LOGIN PAGE";
    StudentView();
    Delay();
    return 0;
}

int AdminSignin()
{
    system("cls");
    cout << "\n ADMIN LOGIN PAGE";
    string Username;
    string Password;

    cout << "\nEnter Username: ";
    cin >> Username;
    cout << "\nEnter Password: ";
    cin >> Password;

    if (Username == "admin" && Password == "pass")
    {
        AdminView();
        getchar();
        Delay();
    }
    else
    {
        cout << "\n ERROR!!! ";
        cout << "\n Press any key to return to main menu";
        getchar();
        getchar();
    }
    return 0;
}

int CheckStudentsCredentials(string Username, string Password)
{
    ifstream read("StudentDatabase.dat");
    if (read)
    {
        int RecordFound = 0;
        string line;
        string Temp = Username + Password + ".dat";
        while (getline(read, line))
        {
            if (line == Temp)
            {
                RecordFound = 1;
                break;
            }
        }
        return RecordFound;
    }
    return 0;
}

int GetAllStudentsbyRollNo()
{
    cout << "\nAll Students by Roll No: \n";
    cout << "Press any Key to continue";
    getchar();
    getchar();
    return 0;
}

int DeleteAllStudents()
{
    cout << "\nDeleting All Students\n";
    cout << " Press any Key to return to Main Menu";
    getchar();
    getchar();
    return 0;
}

int CheckPresentCountbyRollNo()
{
    cout << "\nCheck Present Count by Roll No: \n";
    cout << "Press any Key to continue";
    getchar();
    getchar();
    return 0;
}

int StudentView()
{
    cout << "\n STUDENT LOGIN \n";
    string Username, Password;
    cout << "\n Enter Username: ";
    cin >> Username;
    cout << "\n  Enter Password: ";
    cin >> Password;

    int Reset = CheckStudentsCredentials(Username, Password);
    if (Reset == 0)
    {
        cout << "\n Invalid Username or Password";
        cout << "\n Press any Key to return to Main Menu";
        getchar();
        getchar();
        return 0;
    }
    int GoBack = 0;
    while (GoBack == 0)
    {
        system("cls");
        cout << "\n 1.Mark Attendance for Today \n";
        cout << "\n 2.Count My Attendance \n";
        cout << "\n 3.Logout \n";
        int choice;

        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            MarkMyAttendance(Username);
            break;
        case 2:
            CountMyAttendance(Username);
            break;
        case 3:
            GoBack = 1;
            break;
        default:
            cout << "\n Invalid Choice.SELECT FROM OPTIONS ABOVE \n";
            getchar();
        }
    }
    return 0;
}

int MarkMyAttendance(string Username)
{
    cout << "\n Marking Attendance for Today!! \n";
    cout << " Press any Key to return to Main Menu";
    getchar();
    getchar();
    return 0;
}

int ListofStudentsEnrolled()
{
    cout << "\n List of Students Enrolled \n";

    ifstream read("StudentDatabase.dat");
    if (read)
    {
        string line;
        while (getline(read, line))
        {
            char name[100];
            strcpy(name, line.c_str());
            char onlyname[100];
            strncpy(onlyname, name, (strlen(name) - 4));
            onlyname[strlen(name) - 4] = '\0'; // Null-terminate the string
            cout << "\n"
                 << onlyname;
        }
        read.close();
    }
    else
    {
        cout << "\n No Students Enrolled  \n";
    }
    cout << " Press any Key to return to Main Menu";
    getchar();
    getchar();
    return 0;
}

int EnrollStudent()
{
    cout << "\n STUDENT ENROLLMENT FORM \n";
    string Name, Username, Password, RollNo, Address, FatherName, MotherName;
    cout << "\n Enter Student Name: ";
    cin >> Name;
    cout << "\n Enter Student Username: ";
    cin >> Username;
    cout << "\n Enter Student Password: ";
    cin >> Password;
    cout << "\n Enter Student Roll No: ";
    cin >> RollNo;
    getchar();

    char add[100];
    cout << "\n Enter Student Address: ";
    cin.getline(add, 100);
    cout << "\n Enter Father Name: ";
    cin >> FatherName;
    cout << "\n Enter Mother Name: ";
    cin >> MotherName;

    ifstream read("StudentDatabase.dat");
    if (read)
    {
        int RecordFound = 0;
        string line;
        while (getline(read, line))
        {
            if (line == Username + ".dat")
            {
                RecordFound = 1;
                break;
            }
        }
        if (RecordFound == 1)
        {
            cout << "\n Student Already Enrolled \n";
            getchar();
            getchar();
            Delay();
            read.close();
            return 0;
        }
    }
    read.close();

    ofstream out("StudentDatabase.dat", ios::app);
    out << Username + ".dat" << "\n";
    out.close();

    string Temp = Username + ".dat";
    ofstream out1(Temp.c_str());
    out1 << Name << "\n";
    out1 << Username << "\n";
    out1 << Password << "\n";
    out1 << RollNo << "\n";
    out1 << Address << "\n";
    out1 << FatherName << "\n";
    out1 << MotherName << "\n";
    out1.close();

    cout << "\n Student Enrolled Successfully \n";
    cout << " Press any Key to return to Main Menu";
    getchar();
    getchar();
    return 0;
}

int DeleteStudentbyRollNo()
{
    cout << "\nDelete Student by Roll No: (Function not yet implemented)\n";
    cout << "Press any key to continue";
    getchar();
    getchar();
    return 0;
}

int DisplayStudentsPresent()
{
    cout << "\nDisplay Students Present: (Function not yet implemented)\n";
    cout << "Press any key to continue";
    getchar();
    getchar();
    return 0;
}

int CountMyAttendance(string Username)
{
    cout << "\nCount My Attendance for " << Username << ": (Function not yet implemented)\n";
    cout << "Press any key to continue";
    getchar();
    getchar();
    return 0;
}

int main(int argc, char **argv)
{
    while (1)
    {
        system("cls");
        cout << "\n STUDENTS ATTENDANCE \n";
        cout << "1.Student Login\n";
        cout << "2.Admin Login\n";
        cout << "3.Exit\n";
        int choice;
        cout << "\n Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            StudentSignin();
            break;
        case 2:
            AdminSignin();
            break;
        case 3:
            while (1)
            {
                system("cls");
                cout << "Exiting..Are you sure?(y/n) \n";
                char Exitchoice;
                cin >> Exitchoice;
                if (Exitchoice == 'y' || Exitchoice == 'Y')
                    exit(0);
                else if (Exitchoice == 'n' || Exitchoice == 'N')
                {
                    break;
                }
                else
                {
                    cout << "\nSelect a valid option";
                    getchar();
                }
            }
            break;
        default:
            cout << "\n Invalid Option.Enter Again";
            getchar();
        }
    }
    return 0;
}
