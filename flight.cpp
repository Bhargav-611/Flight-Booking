#include<iostream>
#include<conio.h>
#include<iomanip>
#include<graphics.h>
#include <chrono>
#include <ctime>
using namespace std;

class date;

auto now = std::chrono::system_clock::now();
    
// Convert it to time_t
std::time_t time_now = std::chrono::system_clock::to_time_t(now);
    
// Convert it to struct tm
std::tm *local_time = std::localtime(&time_now);
    
// Extract date components
int year = local_time->tm_year + 1900; // Years since 1900
int month = local_time->tm_mon + 1;    // Months start from 0
int day = local_time->tm_mday;         // Day of the month



class date
{
    int day;
    int month;
    int year;

    public:

    void setday(int a)
    {
        day = a;
    }

    void setmonth(int a)
    {
        month = a;
    }

    void setyear(int a)
    {
        year = a;
    }

    int getday() const
    {
        return day;
    }

    int getmonth() const
    {
        return month;
    }

    int getyear() const
    {
        return year;
    }

    void incday()
    {
        day++;
    }

    void incmonth()
    {
        month++;
    }

    void incyear()
    {
        year++;
    }    

    void print() const
    {
        cout << day << '-' << month << '-' << year;
    }
};


date nextDate(date currdate)
{
    date nextdate;
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(currdate.getmonth() == 2 && (currdate.getyear() % 4 == 0 && (currdate.getyear() % 100 != 0 || currdate.getyear() % 400 == 0)))
    {
        if(currdate.getday() == 29)
        {
            currdate.incmonth();
            currdate.setday(1);
        }
        else
            currdate.incday();
    }
    else if(days[currdate.getmonth()]==31)
    {
        if( currdate.getday() == 31)
        {
            if( currdate.getmonth()==12)
            {
                year++;
                currdate.setmonth(1);
                currdate.setday(1);
            }
            else
            {
                currdate.incmonth();
                currdate.setday(1);   
            }
        }
        else
        {
            currdate.incday();
        }
    }
    else if(currdate.getmonth()==2)
    {
        if(currdate.getday()==28)
        {
            currdate.setday(1);
            currdate.incmonth();
        }
        else
        {
            currdate.incday();
        }
    }
    else
    {
        if(currdate.getday()==30)
        {
            if(currdate.getmonth()==12)
            {
                year++;
                currdate.setmonth(1);
                currdate.setday(1);
            }
            else
            {
                currdate.incmonth();
                currdate.setday(1);   
            }
        }
        else
        {
            currdate.incday();
        }       
    }

    nextdate.setday(currdate.getday());
    nextdate.setmonth(currdate.getmonth());
    nextdate.setyear(currdate.getyear());
    return nextdate;
    
}

    
    
    
    
        
    



class flight1
{
    static int count;
    float FlightNo;
    string firstName;
    string lastName;
    string mobileNo;
    string From;
    string email;
    string passportNo;
    string location;
    date flightDate;
    string time;
    int numPersons;
    string ticketClass;
    float totalPrice;

    public:
        void SetData();
        
        static int countshow()
        {
            return count;
        }
        
        void Class();

        void Date();

        void Time();
        
        void Where();

        void printall();

        flight1()
        {
            From = "Surat";
        }
        

};

int flight1::count = 0;

void flight1::SetData()
{
    system("cls");
    cout << endl <<  endl << "Enter First Name: ";
    cin >> firstName;
    cout << endl << "Enter Last Name: ";
    cin >> lastName;
    cout << endl << "Enter Mobile No.: ";
    cin >> mobileNo;
    cout << endl << "Enter Email ID: ";
    cin >> email;
    cout << endl << "Enter Passport No.: ";
    cin >> passportNo;
    cout << endl << "Enter Number Of Person: ";
    cin >> numPersons;

    totalPrice = totalPrice * numPersons;

    FlightNo = count+123456;
    cout << endl << endl << "Your E-Ticket Number Is  " << FlightNo << endl << "(Please Save This Number)" << endl;

    count++;
    cout << endl << endl << "(Enter any key)" << endl;
    cin >> ws;
}

void flight1::Time()
{
    int n;
    bool fleg = false;
    do
    {
        system("cls");
        if(fleg)
        {
            cout << endl << "Enter Valid Number.";
            fleg = false;
        }
        cout << endl << "Select A Time...";
        cout << endl << endl << "1: 08:00" ; 
        cout << endl << "2: 12:00";
        cout << endl << "3: 16:00";
        cout << endl << "4: 20:00";
        cout << endl << "5: 23:00";

        cout << endl << "6: Back";
        cout << endl << endl << "Select One Option: ";
        cin >> n;


        if (cin.fail()) {
            cin.clear(); // Clear the error state
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            continue;
        }

        switch(n)
        {
        case 1 ... 5:
            if(n==1) time = "08:00";
            else if(n==2) time = "12:00";
            else if(n==3) time = "16:00";
            else if(n==4) time = "20:00";
            else if(n==5) time = "23:00";

            SetData();

            break;
        case 6:
            break;
        default:
            fleg = true;
            break;
        }
    }while(n>6 || n<1);
}

void flight1::Date()
{
    int n;
    date dates[5];
    dates[0].setday(::day);
    dates[0].setmonth(::month);
    dates[0].setyear(::year);

    bool fleg = false;
    do
    {
        system("cls");
        if(fleg)
        {
            cout << endl << "Enter Valid Number.";
            fleg = false;
        }
        cout << endl << "Select A Date...";
        cout << endl << endl << "1: " ; dates[0].print();
        dates[1] = nextDate(dates[0]);
        cout << endl << "2: "; dates[1].print();
        dates[2] = nextDate(dates[1]);
        cout << endl << "3: "; dates[2].print();
        dates[3] = nextDate(dates[2]);
        cout << endl << "4: "; dates[3].print();
        dates[4] = nextDate(dates[3]);
        cout << endl << "5: "; dates[4].print();

        cout << endl << "6: Back";
        cout << endl << endl << "Select One Option: ";
        cin >> n;


        if (cin.fail()) {
            cin.clear(); // Clear the error state
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            continue;
        }

        switch(n)
        {
        case 1 ... 5:
            if(n==1) flightDate = dates[0];
            else if(n==2) flightDate = dates[1];
            else if(n==3) flightDate = dates[2];
            else if(n==4) flightDate = dates[3];
            else if(n==5) flightDate = dates[4];

            Time();

            break;
        case 6:
            break;
        default:
            fleg = true;
            break;
        }
    }while(n>6 || n<1);

}

void flight1::Class()
{
    int n;
    bool fleg = false;
    do
    {
        system("cls");
        if(fleg)
        {
            cout << endl << "Enter Valid Number.";
            fleg = false;
        }
        cout << endl << endl << "1: First Class           (Extra 1500 Rs.)";
        cout << endl << "2: Business Class        (Extra 1000 Rs.)";
        cout << endl << "3: Economy Class         (No Extra Cost)";
        cout << endl << "4: Back";
        cout << endl << endl << "Select One Option: ";
        cin >> n;

        if (cin.fail()) {
            cin.clear(); // Clear the error state
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            continue;
        }
    
        switch (n)
        {
        case 1 ... 3:
            if(n==1) { ticketClass = "First Class"; totalPrice += 1500; }
            else if(n==2) { ticketClass = "Business Class"; totalPrice += 500; }
            else { ticketClass = "Economy Class"; }

            Date();
            break;
        
        case 4:
            break;
        
        default:
            fleg = true;
            break;
        }
    }while(n>4 || n<1);
}

void flight1 :: Where()
{
    int n;
    bool fleg = false;
    do
    {
        system("cls");
        if(fleg)
        {
            cout << endl << "Enter Valid Number.";
            fleg = false;
        }
        cout << endl << "Travel Surat To...";
        cout << endl << endl << setw(20) << left << "1: Ahmedabad" << setw(7) << "5000 Rs.";
        cout << endl << setw(20) << left << "2: Mumbai" << setw(7) << "6000 Rs.";
        cout << endl << setw(20) << left << "3: Dilhi" << setw(7) << "5100 Rs.";
        cout << endl << setw(20) << left << "4: Chennai" << setw(7) << "7000 Rs.";
        cout << endl << setw(20) << left << "5: Rajasthan" << setw(7) << "1000 Rs.";
        cout << endl << setw(20) << left << "6: Maharastra" << setw(7) << "4000 Rs.";
        cout << endl << setw(20) << left << "7: Goa" << setw(7) << "5600 Rs.";
        cout << endl << setw(20) << left << "8: Kerala" << setw(7) << "5840 Rs.";
        cout << endl << setw(20) << left << "9: Back";
        cout << endl << endl << "Select One Option: ";
        cin >> n;

        if (cin.fail()) {
            cin.clear(); // Clear the error state
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            continue;
        }
    
        switch (n)
        {
        case 1 ... 8:
            if(n==1) { location = "Ahmedabad"; totalPrice += 5000; }
            else if(n==2) { location = "Mumbai"; totalPrice += 6000; }
            else if(n==3) { location = "Dilhi"; totalPrice += 5100; }
            else if(n==4) { location = "Chennai"; totalPrice += 7000; }
            else if(n==5) { location = "Rajasthan"; totalPrice += 1000; }
            else if(n==6) { location = "Maharastra"; totalPrice += 4000; }
            else if(n==7) { location = "Goa"; totalPrice += 5600; }
            else { location = "Kerala"; totalPrice += 5840; }
            
            Class();

            break;
        
        case 9:
            break;
        
        default:
            fleg = true;
            break;
        }
    }while(n>9 || n<1);
}

void flight1::printall()
{
    cout << endl << "Full Name           : " << setw(20) << right << firstName + ' ' + lastName;
    cout << endl << "Mobile No           : " << setw(20) << right << mobileNo;
    cout << endl << "Email Id            : " << setw(20) << right << email;
    cout << endl << "From                : " << setw(20) << right << From;
    cout << endl << "To                  : " << setw(20) << right << location;
    cout << endl << "Passport No         : " << setw(20) << right << passportNo;
    cout << endl << "Flight Date         : " << setw(13) << right; flightDate.print();
    cout << endl << "Time                : " << setw(20) << right << time;
    cout << endl << "Number of Passenger : " << setw(20) << right << numPersons;
    cout << endl << "Ticket Class        : " << setw(20) << right << ticketClass;
    cout << endl << "Flight No           : " << setw(20) << right << FlightNo;
    cout << endl << "Total Price         : " << setw(20) << right << totalPrice << endl;


}



int main()
{
    int n;
    flight1 flight[50];
    cout << endl;
    int temp;
    bool fleg = false;

    do
    {
        system("cls");
        if(fleg)
        {
            cout << endl << "Enter Valid Number.";
            fleg = false;
        }
        cout << endl << endl << "1: Flight Ticket Book";
        cout << endl << "2: Flight Ticket Cancel";
        cout << endl << "3: Flight Ticket Details";
        cout << endl << "4: Quit";
        cout << endl << endl << "Select One Option: ";
        cin >> n;

        if (cin.fail()) {
            cin.clear(); // Clear the error state
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            continue;
        }

        switch (n)
        {
        case 1:
            temp = flight1 :: countshow();
            flight[temp].Where();
            break;

        case 2:
            temp = flight1 :: countshow();

        case 3:
            break;

        case 4:
            break;
        default:
            fleg=true;
            break;
        }
    }while(n!=4);

    int count;
    count = flight1::countshow();
    long int sum = 0;

    system("cls");
    for(int i=0; i<count; i++)
    {
        flight[i].printall();
    }

    cout << endl << endl << "(Enter any key)" << endl;
    cin >> ws;
    return 0;
}