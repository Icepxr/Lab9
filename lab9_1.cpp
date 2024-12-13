#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){	
	int i=1;
	double vat,interest,payment,PrevBalance,Total=0,NewBalance=0;
	cout << "Enter initial loan: ";
	cin >> PrevBalance;
	cout << "Enter interest rate per year (%): ";
	cin >> vat;

	cout << "Enter amount you can pay per year: ";
	cin >> payment;

	
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	
	//newBalance = total -payment
	// if total < payment -> payment = total end!
	// Prev = newbalance
	
	
	
	do{
		interest = (vat*PrevBalance)/100;
		Total = PrevBalance+interest;
		NewBalance = Total - payment;

		cout << fixed << setprecision(2); 
		cout << setw(13) << left << i; 
		cout << setw(13) << left << PrevBalance;

		cout << setw(13) << left << interest;
		cout << setw(13) << left << Total;
		
		if(payment>Total){
			cout << setw(13) << left << Total;
			NewBalance=0;
		}else{
		cout << setw(13) << left << payment;
			
		}
		cout << setw(13) << left <<NewBalance;
		cout << "\n";	
		i++;
		PrevBalance = NewBalance;
	}while(PrevBalance>payment);
		
	while(NewBalance!=0){
		interest = (vat*PrevBalance)/100;
		cout << fixed << setprecision(2); 
		cout << setw(13) << left << i; 
		cout << setw(13) << left << PrevBalance;

		cout << setw(13) << left << interest;
		Total = PrevBalance+interest;
		cout << setw(13) << left << Total;
		if(Total<payment){
			payment=Total;
		}
		cout << setw(13) << left << payment;
		NewBalance = Total-payment;
		cout << setw(13) << left <<NewBalance;
		cout << "\n";	
		PrevBalance = NewBalance;
		i++;
	}
		
	
		
		
	
	return 0;
}
