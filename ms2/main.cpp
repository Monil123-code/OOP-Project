// Final Project Milestone 2
// 
// Version 1.0
// Date	2023-02-27
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the Error and
// the Date class for submission.
//
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include "Date.h"
#include "POS.h"
#include "Error.h"
using namespace std;
using namespace sdds;

bool equalDates(const Date& A, const Date& B);
void line(char fill);
bool T1();
bool T2();
bool T3();
bool T4();
bool T5();
int main() {
    line('1');
    bool ok = T1();
    line('2');
    ok && (ok = T2());
    line('3');
    ok && (ok = T3());
    line('4');
    ok && (ok = T4());
    line('5');
    ok && (ok = T5());
    return 0;
}


bool T1() {
    bool passed = true;
    Error F;
    Error G("Error G has a message");
    Error X("Error X has a message too");
    Error C = G;
    X = G;
    if (!F) {
        cout << "This is correct >" << F << "<" << endl;
    }
    else {
        cout << "This message should not get printed: " << F << endl;
        passed = false;
    }
    if (G) {
        cout << "This is correct >" << G << "<" << endl;
    }
    else {
        cout << "This message should not get printed: " << G << endl;
        passed = false;
    }
    if (X) {
        cout << "This copy assign is correct >" << X << "<" << endl;
    }
    else {
        cout << "This message should not get printed: " << X << endl;
        passed = false;
    }
    if (C) {
        cout << "This copy is correct >" << C << "<" << endl;
    }
    else {
        cout << "This message should not get printed: " << C << endl;
        passed = false;
    }
    G.clear();
    if (!G) {
        cout << "This is correct >" << G << "<" << endl;
    }
    else {
        cout << "This message should not get printed: " << G << endl;
        passed = false;
    }
    return passed;

}

bool T2() {
    bool ok = true;
    if (ok) {
        cout << "Checking constant values, POS.h: " << endl;
    }
    if (ok && MIN_YEAR != 2000) {
        cout << "MIN_YEAR must be 2000" << endl;
        ok = false;
    }
    if (ok && MAX_YEAR != 2030) {
        cout << "MAX_YEAR must be 2030" << endl;
        ok = false;
    }
    if (ok && (TAX - 0.13 > 0.0001 || TAX - 0.13 < -0.0001)) {
        cout << "TAX must be 0.13" << endl;
        ok = false;
    }
    if (ok && MAX_SKU_LEN != 7) {
        cout << "MAX_SKU_LEN must be 7" << endl;
        ok = false;
    }
    if (ok && MAX_NO_ITEMS != 2000) {
        cout << "MAX_NO_ITMES must be 2000" << endl;
        ok = false;
    }

    if (ok) {
        cout << "Passed!" << endl;
    }
    if (ok) {
        cout << "Checking constant values passed" << endl;
    }
    else {
        cout << "You did not pass all the tests, keep working on your project!" << endl;
    }
    return ok;
}

bool T3() {
    bool ok = true;
    if (ok) {
        cout << "Testing Date constructors and operator<< overload; " << endl;
        time_t t = time(NULL);
        Date Cur;
        tm lt = *localtime(&t);
        Date tCur(lt.tm_year + 1900, lt.tm_mon + 1, lt.tm_mday, lt.tm_hour, lt.tm_min);
        cout << tCur << (equalDates(tCur, Cur) ? " is the same as " : " is not the same as ") << Cur << endl;

        if (equalDates(tCur, Cur)) {
            cout << "Passed!" << endl;
        }
        else {
            cout << "One or more of the Date constructors or operator<< are not implemented correctly." << endl;
            ok = false;
        }
    }
    if (ok) {
        Date A(2023, 10, 18);
        Date B = A;
        cout << "Testing Date(int, int, int) constructor and operator>> overload; " << endl;
        cout << "enter the following date: 2023/10/18" << endl << "> ";
        cin >> B;

        if (!equalDates(A, B)) {
            cout << "Either the constructor or operator>> is not implemented correctly." << endl;
            ok = false;
        }
        else {
            cout << "Passed!" << endl;
        }
    }
    if (ok) {
        Date A(2023, 9, 7, 14, 30);
        Date B = A;
        B.dateOnly(false);
        cout << "Testing Date(int, int, int,int,int) constructor and operator>> overload; " << endl;
        cout << "enter the following date and time: 2023/9/7, 14:30" << endl << "> ";
        cin >> B;

        if (!equalDates(A, B)) {
            cout << "Either the constructor or operator>> is not implemented correctly." << endl;
            ok = false;
        }
        else {
            cout << "Passed!" << endl;
        }
    }
    if (ok) {
        Date A(2023, 9, 7, 15);
        Date B = A;
        B.dateOnly(false);
        cout << "Testing Date(int, int, int,int,int=0) constructor and operator>> overload; " << endl;
        cout << "enter the following date and time: 2023/9/7, 15:0" << endl << "> ";
        cin >> B;

        if (!equalDates(A, B)) {
            cout << "Either the constructor or operator>> is not implemented correctly." << endl;
            ok = false;
        }
        else {
            cout << "Passed!" << endl;
        }
    }
    if (ok) {
        cout << "You passed all Constructor tests!" << endl;
    }
    else {
        cout << "You did not pass all the tests, keep working on your project!" << endl;

    }
    return ok;
}

bool T4() {
    bool ok = true;
    if (ok) {
        cout << "Testing the logical operators: " << endl;
    }
    if (ok) {
        Date A(2023, 10, 18, 15);
        Date B(2023, 10, 18, 15);
        cout << "testing operator==" << endl;
        if (A == B) {
            cout << "passed!" << endl;
        }
        else {
            cout << A << " is equal to " << B << " but operator== returns otherwise!" << endl;
            ok = false;
        }
    }

    if (ok) {
        Date A(2023, 10, 18, 15);
        Date B(2023, 10, 18, 15);
        cout << "testing operator>=" << endl;
        if (A >= B) {
            cout << "passed!" << endl;
        }
        else {
            cout << A << " is equal to " << B << endl << "but operator>= returns otherwise!" << endl;
            ok = false;
        }
    }

    if (ok) {
        Date A(2023, 10, 18, 15);
        Date B(2023, 10, 18, 15);
        cout << "testing operator<=" << endl;
        if (A <= B) {
            cout << "passed!" << endl;
        }
        else {
            cout << A << " is equal to " << B << endl << "but operator<= returns otherwise!" << endl;
            ok = false;
        }
    }

    if (ok) {
        Date A(2023, 10, 17);
        Date B(2023, 10, 18, 15);
        cout << "testing operator!=" << endl;
        if (A != B) {
            cout << "passed!" << endl;
        }
        else {
            cout << A << " is not equal to " << B << " but operator!= returns otherwise!" << endl;
            ok = false;
        }
    }
    if (ok) {
        Date A(2023, 10, 17);
        Date B(2023, 10, 18, 15);
        cout << "testing operator<" << endl;
        if (A < B) {
            cout << "passed!" << endl;
        }
        else {
            cout << A << " is less than " << B << " but operator< returns otherwise!" << endl;
            ok = false;
        }
    }
    if (ok) {
        Date A(2023, 10, 17);
        Date B(2023, 10, 18, 15);
        cout << "testing operator>" << endl;
        if (B > A) {
            cout << "passed!" << endl;
        }
        else {
            cout << B << " is greater than " << B << " but operator> returns otherwise!" << endl;
            ok = false;
        }
    }
    if (ok) {
        Date A(2023, 10, 17);
        Date B(2023, 10, 18, 15);
        cout << "testing operator<=" << endl;
        if (A < B) {
            cout << "passed!" << endl;
        }
        else {
            cout << A << " is less than " << B << " but operator<= returns otherwise!" << endl;
            ok = false;
        }
    }
    if (ok) {
        Date A(2023, 10, 17);
        Date B(2023, 10, 18, 15);
        cout << "testing operator>=" << endl;
        if (B >= A) {
            cout << "passed!" << endl;
        }
        else {
            cout << B << " is greater than " << B << " but operator>= returns otherwise!" << endl;
            ok = false;
        }
    }
    if (ok) {
        cout << "You passed logical operator tests" << endl;
    }
    else {
        cout << "You did not pass all the tests, keep working on your project!" << endl;
    }

    return ok;
}

bool T5() {
    bool ok = true;
    ifstream fin;
    if (ok) {
        ofstream fout("date.txt");
        Date A;
        Date B;
        A.dateOnly(false);
        B.dateOnly(false);
        cout << "Testing operator<< and >> overload for iostream, " << endl;
        cout << "Please enter the following data and time:  2023/2/27, 1:35\n> ";
        cin >> A;
        cout << "Read From file:  " << A << endl;
        fout << A;
        fout.close();
        fin.open("date.txt");
        fin >> B;
        if (A != B) {
            cout << "Most likely you did not use istream and/or ostream refrences in your\n"
                "operator<< and operator>> overloads and used cin and cout instead" << endl;
            ok = false;
        }
        else {
            cout << "Passed" << endl;
        }
        cin.ignore(2000, '\n');
        fin.close();
    }

    if (ok) {
        cout << "Opening \"dataEntries.txt\" file for data entry..." << endl;
        fin.open("dateEntries.txt");
        if (!fin) {
            cout << "Failed to open the file!" << endl;
            ok = false;
        }
    }
    if (ok) {
        Date A;
        A.dateOnly(true);
        cout << "Year validation, " << endl;
        cout << "Data in file:  10/1/1\n> ";
        fin >> A;
        cout << "Read From file:  " << A << endl;
        if (!A) {
            cout << "Correctly detected " << A.error() << endl;
        }
        else {
            cout << "Your read function does not check the year entry limits after entry" << endl;
            ok = false;
        }
        fin.ignore(2000, '\n');
    }
    if (ok) {
        Date A;
        A.dateOnly(true);
        cout << "Month validation, " << endl;
        cout << "Data in file:  2000/13/1\n> ";
        fin >> A;
        cout << "Read From file:  " << A << endl;
        if (!A) {
            cout << "Correctly detected " << A.error() << endl;
        }
        else {
            cout << "Your read function does not check the month entry limits after entry" << endl;
            ok = false;
        }
        fin.ignore(2000, '\n');
    }
    if (ok) {
        Date A;
        A.dateOnly(true);
        cout << "Day validation, " << endl;
        cout << "Data in file:  2000/1/50\n> ";
        fin >> A;
        cout << "Read From file:  " << A << endl;
        if (!A) {
            cout << "Correctly detected " << A.error() << endl;
        }
        else {
            cout << "Your read function does not check the day entry limits after entry" << endl;
            ok = false;
        }
        fin.ignore(2000, '\n');
    }
    if (ok) {
        Date A;
        A.dateOnly(true);
        cout << "Day validation, leap year:" << endl;
        cout << "Data in file:  2020/2/29\n> ";
        fin >> A;
        cout << "Read From file:  " << A << endl;
        if (!A) {
            cout << "Possibly your read function does not check the day entry limits using mday()" << endl;
            ok = false;
        }
        else {
            cout << "passed!" << endl;
        }
        fin.ignore(2000, '\n');
    }
    if (ok) {
        Date A;
        A.dateOnly(false);
        cout << "Hour validation, " << endl;
        cout << "Data in file:  2000/1/1, 25:10\n> ";
        fin >> A;
        cout << "Read From file:  " << A << endl;
        if (!A) {
            cout << "Correctly detected " << A.error() << endl;
        }
        else {
            cout << "Your read function does not check the hour entry limit after entry" << endl;
            ok = false;
        }
        fin.ignore(2000, '\n');
    }
    if (ok) {
        Date A;
        A.dateOnly(false);
        cout << "Minute validation, " << endl;
        cout << "Data in file:  2000/1/1, 23:60\n> ";
        fin >> A;
        cout << "Read From file:  " << A << endl;
        if (!A) {
            cout << "Correctly detected " << A.error() << endl;
        }
        else {
            cout << "Your read function does not check the minute entry limit after entry" << endl;
            ok = false;
        }
        fin.ignore(2000, '\n');
    }

    if (ok) {
        cout << "Testing istream read failure detection..." << endl;
        Date A;
        A.dateOnly(false);
        cout << "Invalid year entry" << endl;
        cout << "Data In file: abcd\n> ";
        fin >> A;
        cout << "Read From file:  " << A << endl;
        if (!A) {
            cout << "Passed!" << endl;
        }
        else {
            cout << "Your read function does not check istream::fail() after each entry" << endl;
            ok = false;
        }
        fin.clear();
        fin.ignore(2000, '\n');
    }

    if (ok) {
        Date A;
        A.dateOnly(false);
        cout << "Invalid month entry" << endl;
        cout << "Data In file: 2023abcd\n> ";
        fin >> A;
        cout << "Read From file:  " << A << endl;
        if (!A) {
            cout << "Passed!" << endl;
        }
        else {
            cout << "Your read function does not check istream::fail() after each entry" << endl;
            ok = false;
        }
        fin.clear();
        fin.ignore(2000, '\n');
    }
    if (ok) {
        cout << "Testing istream read failure detection..." << endl;
        Date A;
        A.dateOnly(false);
        cout << "Invalid day entry" << endl;
        cout << "Data In file: 2023/10abcd\n> ";
        fin >> A;
        cout << "Read From file:  " << A << endl;
        if (!A) {
            cout << "Passed!" << endl;
        }
        else {
            cout << "Your read function does not check istream::fail() after each entry" << endl;
            ok = false;
        }
        fin.clear();
        fin.ignore(2000, '\n');
    }
    if (ok) {
        cout << "Testing istream read failure detection..." << endl;
        Date A;
        A.dateOnly(false);
        cout << "Invalid hour entry" << endl;
        cout << "Data In file: 2020/10/11abcd\n";
        fin >> A;
        cout << "Read From file:  " << A << endl;
        if (!A) {
            cout << "Passed!" << endl;
        }
        else {
            cout << "Your read function does not check istream::fail() after each entry" << endl;
            ok = false;
        }
        fin.clear();
        fin.ignore(2000, '\n');
    }
    if (ok) {
        cout << "Testing istream read failure detection..." << endl;
        Date A;
        A.dateOnly(false);
        cout << "Invalid minute entry" << endl;
        cout << "Data In file: 2020/10/11, 8abcd\n";
        fin >> A;
        cout << "Read From file:  " << A << endl;
        if (!A) {
            cout << "Passed!" << endl;
        }
        else {
            cout << "Your read function does not check istream::fail() after each entry" << endl;
            ok = false;
        }
        fin.clear();
        fin.ignore(2000, '\n');
    }
    if (ok) {
        cout << "Testing istream read failure detection..." << endl;
        Date A;
        A.dateOnly(false);
        cout << "Correct entry" << endl;
        cout << "Data In file: 2023/03/01, 20:43\n> ";
        fin >> A;
        if (!A) {
            cout << "incorrectly detected " << A.error() << endl;
            ok = false;
        }
        else {
            cout << "Passed! Read From file:  " << A << endl;
        }
        fin.ignore(2000, '\n');
    }
    if (ok) {
        cout << "You passed all error handling tests." << endl << endl
            << " If your output matches the required output, you can submit your" << endl
            << " Milestone 2" << endl;
    }
    else {
        cout << "You did not pass all the tests, keep working on your project!" << endl;
    }
    return ok;
}


bool equalDates(const Date& A, const Date& B) {
    ostringstream Astr, Bstr;
    Astr << A;
    Bstr << B;
    return (Astr.str() == Bstr.str());
}

void line(char fill) {
    for (size_t i = 0; i < 35; i++) cout << fill << "-";
    cout << "<" << endl;
}