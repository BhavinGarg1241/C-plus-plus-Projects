#include <bits/stdc++.h>
using namespace std;

//For Employee
class employee{
	public:
		string empusername = "employee1250";
		string emppsswd = "Cool$Emp";
		string firstname, lastname, custpsswd, city;
		int age;
		char acc_type;
		string acc_number;
		float balance;
		//functions for employee	
		void emplogin();
		void empmenu();
		void addacc();
		void showall();
		void searchacc();
		void checkbalance();
		void editacc();
		void deleteacc();	
};

//Employee Driving function defined
int empfunc();

//Employee Login
void employee::emplogin(){
	string empuser;
	string emppass;
	system("cls");
	cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"Login";
	cout<<endl<<endl<<"Enter Username : ";
	cin>>empuser;
	cout<<"Enter Password : ";
	cin>>emppass;
	
	//check credentials
	
	if(empuser==empusername && emppass==emppsswd){
		cout<<endl<<setiosflags(ios::right)<<setw(20)<<"Login Successfull"<<endl<<endl;
		system("pause");
		empfunc();
	}else{
		cout<<endl<<setiosflags(ios::right)<<setw(20)<<"Username or Password does not Match...\nPlease Try Again"<<endl<<endl;
		system("pause");
		system("cls");
	}
}

//Employee Menu
void employee::empmenu(){
	system("cls");
	cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"Menu"<<endl<<endl;
	cout<<"Enter 1 to add account."<<endl;
	cout<<"Enter 2 to display all account holders."<<endl;
	cout<<"Enter 3 to search account."<<endl;
	cout<<"Enter 4 to to check balance of particular account."<<endl;
	cout<<"Enter 5 to edit account details."<<endl;
	cout<<"Enter 6 to delete account."<<endl;
	cout<<"Enter 7 to exit."<<endl<<endl;
}

//Add New Account
void employee::addacc(){
	system("cls");
	fstream file;
	cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"Add Account"<<endl<<endl;
	cout<<"Create account number (10 digits) : ";
	cin>>acc_number;
	try{
		if(acc_number.length()<10 || acc_number.length()>10){
		throw acc_number;
		}else{
			acc_number=acc_number;
		}
	}	
	catch(string acc_number){
		cout<<endl<<"Enter Valid Account Number....\nPlease try again"<<endl<<endl;
		system("pause");
		empfunc();
	}	
	cout<<"Enter first name : ";
	cin>>firstname;
	cout<<"Enter last name : ";
	cin>>lastname;
	cout<<"Enter age : ";
	cin>>age;
	cout<<"Enter City : ";
	cin>>city;
	cout<<"Type of account (S for savings and C for current account : ";
	cin>>acc_type;
	try{
		if(acc_type!='S' && acc_type!='s' && acc_type!='C' && acc_type!='c'){
			throw acc_type;
		}else{
			acc_type=acc_type;
		}
	}
	catch(char){
		cout<<endl<<"Invalid Account Type.\nPlease Try Again."<<endl<<endl;
		system("pause");
		empfunc();
	}
	cout<<"Create Password : ";
	cin>>custpsswd;
	try{
		if(custpsswd.length()<8){
			throw custpsswd;
		}else{
			custpsswd=custpsswd;
		}
	}
	catch(string custpsswd){
		cout<<endl<<"Password length should be 8 or more than 8.\nPlease Try Again."<<endl<<endl;
		system("pause");
		empfunc();
	}
	cout<<endl<<"Deposit some Money to open account (minimum amount : 500) =  ";
	cin>>balance;
	try{
		if(balance<500){
			throw balance;
		}else{
			balance=balance;
		}
	}
	catch(float){
		cout<<endl<<"Deposit Amount should atleast 500 Rs.\nPlease Try Again."<<endl<<endl;
		system("pause");
		empfunc();
	}
	file.open("Accounts.txt",ios::out | ios::app);
	file<<custpsswd<<" "<<acc_number<<" "<<firstname<<" "<<lastname<<" "<<age<<" "<<city<<" "<<acc_type<<" "<<balance<<"\n\n";
	file.close();
}

//Display all Account Holders
void employee::showall(){
	system("cls");
	fstream file;
	cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"All Accounts"<<endl<<endl;
	file.open("Accounts.txt",ios::in);
	if(!file){
		cout<<endl<<endl<<"Server Error."<<"\n"<<"Please try again."<<endl;
	}else{
		cout<<left<<setw(20)<<"Account Number"<<left<<setw(13)<<"First Name"<<setw(12)<<"Last Name"<<left<<setw(16)<<"City"<<left<<setw(8)<<"Acc Type"<<endl<<endl;
		file>>custpsswd>>acc_number>>firstname>>lastname>>age>>city>>acc_type>>balance;
		while(!file.eof()){
			cout<<left<<setw(20)<<acc_number<<left<<setw(13)<<firstname<<left<<setw(12)<<lastname<<left<<setw(18)<<city<<left<<setw(8)<<acc_type<<endl<<endl;
			file>>custpsswd>>acc_number>>firstname>>lastname>>age>>city>>acc_type>>balance;
		}
	}
	system("pause");
	file.close();
}


//Search Account
void employee::searchacc(){
	system("cls");
	fstream file;
	string accnum;
	int count=0;
	file.open("Accounts.txt",ios::in);
	if (!file){
		cout<<endl<<endl<<"Server Error."<<"\n"<<"Please try again."<<endl;
	}else{
		cout<<endl<<endl<<"Enter Account Number to be searched : ";
		cin>>accnum;
		file>>custpsswd>>acc_number>>firstname>>lastname>>age>>city>>acc_type>>balance;
		while(!file.eof()){
			if(accnum==acc_number){
				system("cls");
				cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"Search Accounts"<<endl<<endl;
				cout<<"Account Number : "<<acc_number<<"\n"
					<<"Account Holder's Name : "<<firstname<<" "<<lastname<<"\n"
					<<"Age : "<<age<<"\n"					
					<<"City : "<<city<<"\n"
					<<"Account Type : "<<acc_type
					<<endl<<endl;
				count++;
				break;
			}
			file>>custpsswd>>acc_number>>firstname>>lastname>>age>>city>>acc_type>>balance;
		}
		if(count==0){
			cout<<"Account Not Found!"<<endl<<endl;
		}
	}
	file.close();
	system("pause");	
}



//Search Account to check balance
void employee::checkbalance(){
	system("cls");
	fstream file;
	int count = 0;
	string accnum;
	cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"Check Balance"<<endl<<endl;
	file.open("Accounts.txt",ios::in);
	if (!file){
		cout<<endl<<endl<<"Server Error."<<"\n"<<"Please try again."<<endl;
	}else{
		cout<<"Enter Account Number whose balance you want to check : ";
		cin>>accnum;
		system("cls");
		file>>custpsswd>>acc_number>>firstname>>lastname>>age>>city>>acc_type>>balance;
		while(!file.eof()){
			if(accnum==acc_number){
				cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"Search Accounts"<<endl<<endl;
				cout<<"Account Number : "<<acc_number<<"\n"
					<<"Account Holder's Name : "<<firstname<<" "<<lastname<<"\n"
					<<"Balance : "<<balance<<"\n"					
					<<endl<<endl;
				count++;
				break;
			}
			file>>custpsswd>>acc_number>>firstname>>lastname>>age>>city>>acc_type>>balance;
		}
		if(count==0){
			cout<<"Account Not Found!"<<endl<<endl;
		}
	}
	file.close();
	system("pause");
}


//Edit Account Holder's Name or Address
void employee::editacc(){
	system("cls");
	fstream file,file1;
	string accnum,fname,lname,city_new;
	char ed;
	int count=0;
	cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"Edit Account Details"<<endl<<endl;
	file1.open("Accounts1.txt",ios::out | ios::app);
	file.open("Accounts.txt",ios::in);
	if(!file){
		cout<<endl<<endl<<"Server Error."<<"\n"<<"Please try again."<<endl;
	}else{
		cout<<"Enter Account Number you want edit : ";
		cin>>accnum;
		file>>custpsswd>>acc_number>>firstname>>lastname>>age>>city>>acc_type>>balance;
		while(!file.eof()){
			if(accnum==acc_number){
				system("cls");
				cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"Edit Account Details"<<endl<<endl;
				cout<<"Account Holder's Name : "<<firstname<<" "<<lastname<<"\n"
					<<"Account Number : "<<acc_number<<"\n"
					<<"City : "<<city<<"\n"
					<<"Account Type : "<<acc_type
					<<endl<<endl;
				cout<<"What do you want to edit ? (n for name and c for city) : ";
				cin>>ed;
				try{
					if(ed!='C' && ed!='c' && ed!='n' && ed!='N'){
						throw ed;
					}else{
						ed=ed;
					}
				}
				catch(char){
					cout<<"Invalid Choice.\nPlease Try Again."<<endl<<endl;
					file1<<custpsswd<<" "<<acc_number<<" "<<firstname<<" "<<lastname<<" "<<age<<" "<<city<<" "<<acc_type<<" "<<balance<<"\n\n";
					system("pause");
					empmenu();
				}
				if(ed=='n' || ed=='N'){
					cout<<"Enter new First Name : ";
					cin>>fname;
					cout<<"Enter new Last Name : ";
					cin>>lname;
					cout<<"Account Updated"<<endl;
					file1<<custpsswd<<" "<<acc_number<<" "<<fname<<" "<<lname<<" "<<age<<" "<<city<<" "<<acc_type<<" "<<balance<<"\n\n";
					count++;
				}else if(ed=='c' || ed=='C'){
					cout<<"Enter new City : ";
					cin>>city_new;
					cout<<"Account Updated"<<endl;
					file1<<custpsswd<<" "<<acc_number<<" "<<firstname<<" "<<lastname<<" "<<age<<" "<<city_new<<" "<<acc_type<<" "<<balance<<"\n\n";
					count++;
				}
			}else{
				file1<<custpsswd<<" "<<acc_number<<" "<<firstname<<" "<<lastname<<" "<<age<<" "<<city<<" "<<acc_type<<" "<<balance<<"\n\n";
			}
			file>>custpsswd>>acc_number>>firstname>>lastname>>age>>city>>acc_type>>balance;
		}
		if(count==0){
			cout<<"Account Not Found!"<<endl<<endl;
		}
	}
	file.close();
	file1.close();
	remove("Accounts.txt");
	rename("Accounts1.txt","Accounts.txt");
	system("pause");
}


//Delete Account
void employee::deleteacc(){
	system("cls");
	fstream file,file1;
	string accnum;
	char sure;
	int count=0;	
	cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"Delete Account"<<endl<<endl;
	file1.open("Accounts1.txt",ios::out | ios::app);
	file.open("Accounts.txt",ios::in);
	if (!file){
		cout<<endl<<endl<<"Server Error."<<"\n"<<"Please try again."<<endl;
	}else{
		cout<<"Enter Account Number you want to delete : ";
		cin>>accnum;
		file>>custpsswd>>acc_number>>firstname>>lastname>>age>>city>>acc_type>>balance;
		while(!file.eof()){
			if(accnum==acc_number){
				system("cls");
				cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"Delete Account"<<endl<<endl;
				cout<<"Account Holder's Name : "<<firstname<<" "<<lastname<<"\n"
					<<"Account Number : "<<acc_number<<"\n"
					<<"City : "<<city<<"\n"
					<<"Account Type : "<<acc_type
					<<endl<<endl;
				cout<<"Are you sure you wnat to delete this account (Y/N) : ";
				cin>>sure;
				cout<<endl;
				if(sure=='Y' || sure=='y'){
					cout<<"Account is Deleted Successfully..."<<endl<<endl;
				}else{
					cout<<"OK No Problem\nNavigating to menu."<<endl<<endl;
					file1<<custpsswd<<" "<<acc_number<<" "<<firstname<<" "<<lastname<<" "<<age<<" "<<city<<" "<<acc_type<<" "<<balance<<"\n\n";
				}
				count++;
			}else{
				file1<<custpsswd<<" "<<acc_number<<" "<<firstname<<" "<<lastname<<" "<<age<<" "<<city<<" "<<acc_type<<" "<<balance<<"\n\n";
			}
			file>>custpsswd>>acc_number>>firstname>>lastname>>age>>city>>acc_type>>balance;
		}
		if (count == 0){
			cout<<"Account Not Found"<<endl<<endl;
		}
	}
	file.close();
	file1.close();
	remove("Accounts.txt");
	rename("Accounts1.txt","Accounts.txt");
	system("pause");
}


//For Customer
class customer{
	public:
		string firstname, lastname, custpsswd, city;
		int age;
		char acc_type;
		string acc_number;
		float balance;
		//functions for customer	
		void login();
		void custmenu();
		void deposit();
		void withdraw();
		void custcheckbalance();
};

//Customer Driving function defined
int custfunc();

//Customer Login
void customer::login(){
	system("cls");
	string custuser;
	string custpass;
	bool log = false;
	int count=0;
	fstream file;
	
	file.open("Accounts.txt",ios::in);
	if(!file){
		cout<<endl<<endl<<"Server Error."<<"\n"<<"Please try again."<<endl;
	}else{
		cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"Login";
		cout<<endl<<endl<<"Enter Username (Your Account Number) : ";
		cin>>custuser;
		cout<<"Enter Password : ";
		cin>>custpass;
		file>>custpsswd>>acc_number>>firstname>>lastname>>age>>city>>acc_type>>balance;
		while(!file.eof()){
			if(custuser==acc_number && custpass==custpsswd){
				cout<<endl<<setiosflags(ios::right)<<setw(20)<<"Login Successfull"<<endl<<endl;
				count++;
				log = true;
				system("pause");				
			}
			file>>custpsswd>>acc_number>>firstname>>lastname>>age>>city>>acc_type>>balance;
		}
		if(count==0){
			cout<<endl<<setiosflags(ios::right)<<setw(20)<<"Username or Password does not Match...\nPlease Try Again"<<endl<<endl;
		}	
	}
	file.close();
	if(log==true){
		custfunc();
	}
	system("pause");
	system("cls");
}


//Cutomer Menu
void customer::custmenu(){
	system("cls");
	cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"Menu"<<endl<<endl;
	cout<<"Enter 1 to Deposit Money."<<endl;
	cout<<"Enter 2 to Withdraw Money."<<endl;
	cout<<"Enter 3 to Check Balance."<<endl;
	cout<<"Enter 4 to exit."<<endl;
}


//To Deposit Money
void customer::deposit(){
	system("cls");
	fstream file,file1;
	string accnum;
	int count = 0;
	float newbalance, depomoney;
	cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"Deposit Money"<<endl<<endl;
	file1.open("Accounts1.txt",ios::out | ios::app);
	file.open("Accounts.txt",ios::in);
	if(!file){
		cout<<endl<<endl<<"Server Error."<<"\n"<<"Please try again."<<endl;
	}else{
		cout<<"Enter Account Number to deposit money : ";
		cin>>accnum;
		file>>custpsswd>>acc_number>>firstname>>lastname>>age>>city>>acc_type>>balance;
		while(!file.eof()){
			if(accnum==acc_number){
				system("cls");
				cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"Deposit Money"<<endl<<endl;
				cout<<"Account Holder's Name : "<<firstname<<" "<<lastname<<"\n"
					<<"Account Number : "<<acc_number<<endl;
				cout<<"Enter amount you want to deposit : ";
				cin>>depomoney;
				newbalance=balance+depomoney;
				cout<<"Balance Updated"<<endl;
				file1<<custpsswd<<" "<<acc_number<<" "<<firstname<<" "<<lastname<<" "<<age<<" "<<city<<" "<<acc_type<<" "<<newbalance<<"\n\n";
				count++;
			}else{
				file1<<custpsswd<<" "<<acc_number<<" "<<firstname<<" "<<lastname<<" "<<age<<" "<<city<<" "<<acc_type<<" "<<balance<<"\n\n";
			}
			file>>custpsswd>>acc_number>>firstname>>lastname>>age>>city>>acc_type>>balance;
		}
		if (count == 0){
			cout<<"Account Not Found"<<endl<<endl;
		}
	}
	file.close();
	file1.close();
	remove("Accounts.txt");
	rename("Accounts1.txt","Accounts.txt");
	system("pause");
}

//Withdraw Money
void customer::withdraw(){
	system("cls");
	fstream file,file1;
	string custpass;
	int count = 0;
	float newbalance, drawmoney;
	cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"Withdraw Money"<<endl<<endl;
	file1.open("Accounts1.txt",ios::out | ios::app);
	file.open("Accounts.txt",ios::in);
	if(!file){
		cout<<endl<<endl<<"Server Error."<<"\n"<<"Please try again."<<endl;
	}else{
		cout<<"Enter Password to verify for money withdrawal : ";
		cin>>custpass;
		file>>custpsswd>>acc_number>>firstname>>lastname>>age>>city>>acc_type>>balance;
		while(!file.eof()){
			if(custpass==custpsswd){
				system("cls");
				cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"Withdraw Money"<<endl<<endl;
				cout<<"Account Holder's Name : "<<firstname<<" "<<lastname<<"\n"
					<<"Account Number : "<<acc_number<<endl;
				cout<<"Enter amount you want to withdraw : ";
				cin>>drawmoney;
				newbalance=balance-drawmoney;
				cout<<"Balance Updated"<<endl;
				file1<<custpsswd<<" "<<acc_number<<" "<<firstname<<" "<<lastname<<" "<<age<<" "<<city<<" "<<acc_type<<" "<<balance<<"\n\n";
				count++;
			}else{
				file1<<custpsswd<<" "<<acc_number<<" "<<firstname<<" "<<lastname<<" "<<age<<" "<<city<<" "<<acc_type<<" "<<balance<<"\n\n";
			}
			file>>custpsswd>>acc_number>>firstname>>lastname>>age>>city>>acc_type>>balance;
		}
		if (count == 0){
			cout<<"Password does not match"<<endl<<endl;
		}
	}
	file.close();
	file1.close();
	remove("Accounts.txt");
	rename("Accounts1.txt","Accounts.txt");
	system("pause");
}


//Check Balance
void customer::custcheckbalance(){
	system("cls");
	fstream file;
	int count = 0;
	string custpass;
	cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"Check Balance"<<endl<<endl;
	file.open("Accounts.txt",ios::in);
	if (!file){
		cout<<endl<<endl<<"Server Error."<<"\n"<<"Please try again."<<endl;
	}else{
		cout<<"Enter password to check balance : ";
		cin>>custpass;
		file>>custpsswd>>acc_number>>firstname>>lastname>>age>>city>>acc_type>>balance;
		while(!file.eof()){
			if(custpass==custpsswd){
				system("cls");
				cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"Search Accounts"<<endl<<endl;
				cout<<"Account Number : "<<acc_number<<"\n"
					<<"Account Holder's Name : "<<firstname<<" "<<lastname<<"\n"
					<<"Balance : "<<balance<<"\n"					
					<<endl<<endl;
				count++;
				break;
			}
			file>>custpsswd>>acc_number>>firstname>>lastname>>age>>city>>acc_type>>balance;
		}
		if(count==0){
			cout<<"Account Not Found!"<<endl<<endl;
		}
	}
	file.close();
	system("pause");
}


//Driver Code
int main(){
	int option;
	employee emp;
	customer cust;
	
	cout<<endl<<endl<<"...Welcome to our Bank of C++"<<endl<<endl<<"Press Enter to check our menu."<<endl;
	if(cin.get()=='\n'){
		system("cls");
		while(1){
			cout<<endl<<setiosflags(ios::right)<<setw(30)<<"Login Portal"<<endl<<endl;
			cout<<right<<setw(10)<<"1. Employee"<<right<<setw(20)<<"2. Customer"<<right<<setw(20)<<"3. Exit"<<endl<<endl;
			cout<<"Enter your choice : ";
			cin>>option;
			switch(option){
				case 1:
					emp.emplogin(); //Login for employees
					break;
				case 2:
					cust.login(); //Login for Customers
					break;
				case 3:
					system("cls");
					cout<<endl<<endl;
					for(int i=0;i<28;i++){
        				cout<<"*";
    				}
    				cout<<"\n";
    				cout<<"Thankyou and visit again...\n";
    				cout<<"...Bank of C++..."<<endl;
    				for(int i=0;i<28;i++){
        				cout<<"*";
    				}    				
					exit(0);	
    				break;
    			default:
    				cout<<endl<<endl<<"Invalid Choice..."<<endl<<endl;
			}
		}
	}
}


//Function for call class functions of employee
int empfunc(){
	int choice;
	char x;
	employee e;
	while(1){
		e.empmenu();
		cout<<endl;
		cout<<"Enter your choice : ";
		cin>>choice;
		cout<<endl<<endl;
		switch(choice){
			case 1:
				do{
					e.addacc();
					cout<<endl<<"Do you want to add another accout (Y/N) : ";
					cin>>x;
					cout<<endl;
				}while(x=='y' || x=='Y');
				break;
			case 2:
				e.showall();
				break;
			case 3:
				e.searchacc();
				break;
			case 4:
				e.checkbalance();
				break;
			case 5:
				e.editacc();
				break;
			case 6:
				e.deleteacc();
				break;
			case 7:
				cout<<"Navigating to Main Menu....."<<endl<<endl;
				system("pause");
				main();	
    			break;
    		default:
    			cout<<endl<<endl<<"Invalid Choice..."<<endl<<endl;
		}
	}
}

//Function for call class functions of customer
int custfunc(){
	int choice;
	char x;
	customer c;
	while(1){
		c.custmenu();
		cout<<endl;
		cout<<"Enter your choice : ";
		cin>>choice;
		cout<<endl<<endl;
		switch(choice){
			case 1:
				c.deposit();
				break;
			case 2:
				c.withdraw();
				break;
			case 3:
				c.custcheckbalance();
				break;
			case 4:
				cout<<"Navigating to Main Menu....."<<endl<<endl;
				system("pause");
				main();	
    			break;
    		default:
    			cout<<endl<<endl<<"Invalid Choice..."<<endl<<endl;
		}
	}
}







