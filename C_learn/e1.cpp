#include<iostream>
using namespace std;
 double getEarning(double salary, int absenceDays)
 {
 	return (salary-absenceDays*salary/22);
 }


double getEarning(double baseSalary, double salesSum, double rate)
{
	return baseSalary+  salesSum*rate;
}


double getEarning(int workPieces, double wagePerPiece)
{
	return workPieces*wagePerPiece;
}


double getEarning(double hours, double wagePerHour)
{
	return hours*wagePerHour;
}


int main()
{
	cout << "Please select..." << endl;

    cout << "1: Manager." << endl;

    cout << "2: Sales Man." << endl;

    cout << "3: Pieces Worker." << endl;

    cout << "4: Hour-Worker." << endl;

    cout << "Others: Quit" << endl;
	int sel=0;

    cin >> sel;


    switch(sel)

    {

    case 1:

        double salary;
		int absenceDays;
        cin >> salary>>absenceDays;

        cout << getEarning(salary, absenceDays);

        break;

    case 2:
    	double baseSalary;
		 double salesSum; 
		 double rate;

        cin >>  baseSalary>>salesSum>> rate;

        cout << getEarning(baseSalary, salesSum,  rate);

        break;

    case 3:
    	int workPieces;
		double wagePerPiece;

        cin >> workPieces>> wagePerPiece;

        cout << getEarning(workPieces, wagePerPiece);

        break;

    case 4:
		double hours;
		double wagePerHour;
        cin >> hours>>wagePerHour;

        cout <<  getEarning(hours,  wagePerHour);

        break;

    default:

        break;

    }

    return 0;

	
}

