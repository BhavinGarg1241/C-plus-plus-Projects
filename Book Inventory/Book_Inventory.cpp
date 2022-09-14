#include <bits/stdc++.h>
using namespace std;

class Book_Inventory{
	string book_name,author_name;
	int cost,stock;
	public:
		void menu();
		void add_book();
		void show_book();
		void search_book();
		void edit_book();
		void delete_book();
		void buy_book();	
};

//Menu
void Book_Inventory::menu(){
	cout<<setiosflags(ios::right)<<setw(20)<<"Menu"<<endl<<endl;
	cout<<"Enter 1 to add book."<<endl;
	cout<<"Enter 2 to show books."<<endl;
	cout<<"Enter 3 to search book."<<endl;
	cout<<"Enter 4 to edit book details."<<endl;
	cout<<"Enter 5 to delete book."<<endl;
	cout<<"Enter 6 to buy book."<<endl;
	cout<<"Enter 7 to exit."<<endl<<endl;
	
	cout<<"Note: "<<"Use underscore instead of space"<<endl<<"      where ever reqiured in names of books and auhtors"<<endl;
}

//Add Book
void Book_Inventory::add_book(){
	system("cls");
	fstream file;
		
	cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"Add Books"<<endl<<endl;
	cout<<"Enter Book Name  : ";
	cin>>book_name;
	cout<<"Enter Author Name : ";
	cin>>author_name;
	cout<<"Enter cost per copy of book : ";
	cin>>cost;
	cout<<"Enter number of copies available : ";
	cin>>stock;
	
	file.open("book.txt", ios::out | ios::app);
	file<<" "<<book_name<<" "<<author_name<<" "<<cost<<" "<<stock<<"\n\n";
	file.close();
}

//Display Books
void Book_Inventory::show_book(){
	system("cls");
	fstream file;
	
	cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"Books"<<endl<<endl;
	file.open("book.txt", ios::in);
	if (!file){
		cout<<endl<<endl<<"File not opening."<<"\n"<<"Please try again."<<endl;
	}else{
		cout<<left<<setw(20)<<"Book"<<left<<setw(20)<<"Author"<<left<<setw(15)<<"Cost"<<left<<setw(15)<<"No. of Copies"<<endl<<endl;
		file >> book_name >> author_name >> cost >> stock;
		
		while(!file.eof()){
			cout<<left<<setw(20)<<book_name<<left<<setw(20)<<author_name<<left<<setw(15)<<cost<<endl<<endl;
			file >> book_name >> author_name >> cost >> stock;
		}
		system("pause");
		file.close();
	}	
}

//Search Book
void Book_Inventory::search_book(){
	system("cls");
	fstream file;
	int count = 0;
	string book, author;
	cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"Search Books"<<endl<<endl;
	file.open("book.txt", ios::in);
	
	if (!file){
		cout<<endl<<endl<<"File not opening."<<"\n"<<"Please try again."<<endl;
	}else{
		cout<<"Enter Book name to be searched : ";
		cin>>book;
//		cout<<"Enter author name to be searched : ";
//		cin>>author;
		file >> book_name >> author_name >> cost >>stock;
		system("cls");
		cout<<setiosflags(ios::right)<<setw(20)<<"Search Books"<<endl<<endl;
		cout<<left<<setw(20)<<"Book"<<left<<setw(20)<<"Author"<<left<<setw(15)<<"Cost"<<left<<setw(15)<<"No. of Copies"<<endl<<endl;
		while(!file.eof()){
			if(book==book_name){
				cout<<left<<setw(20)<<book_name<<left<<setw(20)<<author_name<<left<<setw(15)<<cost<<left<<setw(15)<<stock<<endl<<endl;
				count++;
//				break;
			}
			file >> book_name >> author_name >> cost >> stock;
		}
		
		file.close();
		if (count == 0){
			cout<<"Book Not Found"<<endl<<endl;
		}
		system("pause");
	}
}

//Edit Book Details
void Book_Inventory::edit_book(){
	system("cls");
	fstream file, file1;
	string book,author;
	int new_cost,new_stock,count = 0;
	
	cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"Edit Book Details"<<endl<<endl;
	
	file1.open("book1.txt", ios::app | ios::out);
	file.open("book.txt", ios::in);

	if (!file){
		cout<<endl<<endl<<"File not opening."<<"\n"<<"Please try again."<<endl;
	}else{
		cout<<"Enter Book name to be edited : ";
		cin>>book;
		cout<<"Enter author name of book to be edited : ";
		cin>>author;
		file >> book_name >> author_name >> cost >>stock;
		
		while(!file.eof()){
			if(book==book_name && author==author_name){
				system("cls");
				cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"Edit Book Details"<<endl<<endl;
				cout<<"Enter new book name  : ";
				cin>>book;
				cout<<"Enter Author name of new book : ";
				cin>>author;
				cout<<"Enter cost per copy of new book : ";
				cin>>new_cost;
				cout<<"Enter number of copies available of new book : ";
				cin>>new_stock;
				
				file1<<" "<<book<<" "<<author<<" "<<new_cost<<" "<<new_stock<<"\n\n";
				count++;
			}else{
				file1<<" "<<book_name<<" "<<author_name<<" "<<cost<<" "<<stock<<"\n\n";
			}
			file >> book_name >> author_name >> cost >> stock;
		}
		if (count == 0){
			cout<<"Book Not Found"<<endl<<endl;
		}
	}
	cout << endl;
	system("pause");
	file.close();
	file1.close();
	remove("book.txt");
	rename("book1.txt","book.txt");
}

//Delete Book
void Book_Inventory::delete_book(){
	system("cls");
	fstream file, file1;
	int count = 0;
	string book,author;
	cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"Delete Book"<<endl<<endl;
	
	file1.open("book1.txt",	ios::app | ios::out);
	file.open("book.txt", ios::in);
	
	if (!file){
		cout<<endl<<endl<<"File not opening."<<"\n"<<"Please try again."<<endl;
	}else{
		cout<<"Enter Book name to be deleted : ";
		cin>>book;
		cout<<"Enter author name of book to be deleted : ";
		cin>>author;
		file >> book_name >> author_name >> cost >>stock;
		
		while(!file.eof()){
			if(book==book_name && author==author_name){
				system("cls");
				cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"Delete Book"<<endl<<endl;
				cout << "Book is Deleted Successfully..."<<endl<<endl;
				count++;
			}else{
				file1<<" "<<book_name<<" "<<author_name<<" "<<cost<<" "<<stock<<"\n\n";
			}
			file >> book_name >> author_name >> cost >> stock;
		}
		if (count == 0){
			cout<<"Book Not Found"<<endl<<endl;
		}
	}
	system("pause");

	file.close();
	file1.close();
	remove("book.txt");
	rename("book1.txt","book.txt");	
}

//Buy Book
void Book_Inventory::buy_book(){
	system("cls");
	string book,author;
	int newstock,copies,count=0;
	cout<<endl<<endl<<setiosflags(ios::right)<<setw(20)<<"Buying Books"<<endl<<endl;
	fstream file,file1;
	file1.open("book1.txt",	ios::app | ios::out);
	file.open("book.txt", ios::in);
	
	if (!file){
		cout<<endl<<endl<<"File not opening."<<"\n"<<"Please try again."<<endl;
	}else{
		cout<<"Enter Book name you want to buy : ";
		cin>>book;
		cout<<"Enter author name of book you want to buy : ";
		cin>>author;
		cout<<"Enter number of copies you want to buy : ";
		cin>>copies;
		file >> book_name >> author_name >> cost >>stock;
		
		while(!file.eof()){
			if(book==book_name && author==author_name){
				system("cls");
				cout<<setiosflags(ios::right)<<setw(20)<<"Buying Books"<<endl<<endl;
				if(copies<=stock){
					newstock=stock-copies;
					cout<<"Books bought successfully"<<endl;
					cout<<"Amount : Rs "<<cost*copies<<endl<<endl;
				}else{
					cout<<"Required number of copies not available"<<endl<<"Copies available : "<<stock<<endl<<endl;
				}
				
				file1<<" "<<book<<" "<<author<<" "<<cost<<" "<<newstock<<"\n\n";
				count++;
			}else{
				file1<<" "<<book_name<<" "<<author_name<<" "<<cost<<" "<<stock<<"\n\n";
			}
			file >> book_name >> author_name >> cost >> stock;
		}
		if (count == 0){
			cout<<"Book Not Found"<<endl<<endl;
		}
	}
	system("pause");

	file.close();
	file1.close();
	remove("book.txt");
	rename("book1.txt","book.txt");	
}

//Driver Code
int main(){
	int choice;
	char x;
	Book_Inventory book;
	
	cout<<"...Welcome to our Book Shop..."<<endl<<endl<<"Press Enter to check our menu."<<endl;
	if(cin.get()=='\n'){
		while(1){
			book.menu();
			cout<<endl;
			cout<<"Enter your choice : ";
			cin>>choice;
			cout<<endl<<endl;
			switch(choice){
				case 1:
					do{
						book.add_book();
					cout<<endl<<"Do you want to add another book (y/n) : ";
					cin>>x;
					cout<<endl;
					}while(x=='y');
					break;
				case 2:
					book.show_book();
					break;
				case 3:
					book.search_book();
					break;
				case 4:
					book.edit_book();
					break;
				case 5:
					book.delete_book();
					break;
				case 6:
					book.buy_book();
					break;
				case 7:
					for(int i=0;i<28;i++){
        				cout<<"*";
    				}
    				cout<<"\n";
    				cout<<"Thankyou and visit again...\n";
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


//Credits - Bhavin Garg
