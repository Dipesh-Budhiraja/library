#include <bits/stdc++.h>
using namespace std;

//PROTOTYPES OF ALL FUNCTIONS
void optionSubmitted(int choice);
void create_student();
void display_all_students();
void display_specific_student(char rollNo[]);
void create_book();
void display_all_books();
void display_specific_book(char isbnNo[]);
//PROTOTYPES END HERE

//DECLARATION OF CLASSES
class student{
public:
	char rollNo[20];
	char sname[20];
	char phonenum[11];
	student(char rollNo[], char sname[], char phonenum[]){
		strcpy(this->rollNo, rollNo);
		strcpy(this->sname, sname);
		strcpy(this->phonenum, phonenum);
	}
};

class book{
public:
	char isbnNo[20];
	char bname[20];
	char authorName[20];
	book(char isbnNo[], char bname[], char authorName[]){
		strcpy(this->isbnNo, isbnNo);
		strcpy(this->bname, bname);
		strcpy(this->authorName, authorName);	
	}
};
//DECLARATION OF CLASSES ENDS

//MAIN FUNCTION
int main(){
	int choice;
	do{
		cout << "\n1. CREATE STUDENT RECORD" << endl;
		cout << "2. DISPLAY ALL STUDENTS RECORD" << endl;
		cout << "3. DISPLAY SPECIFIC STUDENT RECORD" << endl;
		cout << "4. CREATE BOOK" << endl;
		cout << "5. DISPLAY ALL BOOKS" << endl;
		cout << "6. DISPLAY SPECIFIC BOOK" << endl;
		cout << "7. EXIT\n" << endl;

		cin >> choice;

		optionSubmitted(choice);
	}while(choice != 7);

	return 0;
}

//OPTION SUBMITTED
void optionSubmitted(int choice){
	switch(choice){
		case 1: create_student(); break;
		case 2: display_all_students(); break;
		case 3: char rollNo[20];
				getchar();
				cout << "Enter rollNo of student: " << endl;
				cin.getline(rollNo, 19);
				display_specific_student(rollNo);
				break;
		case 4: create_book(); break;
		case 5: display_all_books(); break;
		case 6: char isbnNo[20];
				getchar();
				cout << "Enter isbnNo of student: " << endl;
				cin.getline(isbnNo, 19);
				display_specific_book(isbnNo); break;
		default: "No Choice Matches"; break;
	}
}

//CREATE STUDENT
void create_student(){
	char rollNo[20];
	char sname[20];
	char phonenum[20];
	getchar();
	cin.getline(rollNo, 19);
	cin.getline(sname, 19);
	cin.getline(phonenum, 19);

	student obj(rollNo, sname, phonenum);

	ofstream studentWrite("students.txt", ios :: app);
	if(studentWrite.is_open()){
		cout << "Student successfully written" << endl;
		studentWrite << obj.rollNo << " " << obj.sname << " " << obj.phonenum << endl;
		studentWrite.close();
	}
	else{
		cout << "file not opening" << endl;
	}
}

void display_all_students(){
	char rollNo[20];
	char sname[20];
	char phonenum[20];
	getchar();
	ifstream studentRead("students.txt");

	if(studentRead.is_open()){
		cout << "file opened successfully \n";
		while(studentRead >> rollNo >> sname >> phonenum){
			cout << rollNo << " " << sname << " " << phonenum << endl;
		}
		studentRead.close();
	}
	else{
		cout << "file not opened \n";
	}	
}

void display_specific_student(char rollNo[]){
	char rollNoCheck[20];
	char sname[20];
	char phonenum[20];
	ifstream studentRead("students.txt");

	if(studentRead.is_open()){
		cout << "file opened successfully \n";
		// cout << strcmp(rollNo, rollNoCheck);
		while(studentRead >> rollNoCheck >> sname >> phonenum){
			if(strcmp(rollNo, rollNoCheck) == 0){
				cout << rollNo << " " << sname << " " << phonenum << endl;
				break;
			}
		}
		studentRead.close();
	}
	else{
		cout << "file not opened \n";
	}
}

void create_book(){
	char isbnNo[20];
	char bname[20];
	char authorName[20];
	getchar();
	cin.getline(isbnNo, 19);
	cin.getline(bname, 19);
	cin.getline(authorName, 19);

	book obj(isbnNo, bname, authorName);//redundant lines honestly

	ofstream bookWrite("books.txt", ios :: app);
	if(bookWrite.is_open()){
		cout << "Book successfully written" << endl;
		bookWrite << obj.isbnNo << " " << obj.bname << " " << obj.authorName << endl;
		bookWrite.close();
	}
	else{
		cout << "file not opening" << endl;
	}
}

void display_all_books(){
	char isbnNo[20];
	char bname[20];
	char authorName[20];
	getchar();
	ifstream bookRead("books.txt");

	if(bookRead.is_open()){
		cout << "file opened successfully \n";
		while(bookRead >> isbnNo >> bname >> authorName){
			cout << isbnNo << " " << bname << " " << authorName << endl;
		}
		bookRead.close();
	}
	else{
		cout << "file not opened \n";
	}
}

void display_specific_book(char isbnNo[]){
	char isbnNoCheck[20];
	char bname[20];
	char authorName[20];
	ifstream bookRead("books.txt");

	if(bookRead.is_open()){
		cout << "file opened successfully \n";
		// cout << strcmp(rollNo, rollNoCheck);
		while(bookRead >> isbnNoCheck >> bname >> authorName){
			if(strcmp(isbnNo, isbnNoCheck) == 0){
				cout << isbnNo << " " << bname << " " << authorName << endl;
				break;
			}
		}
		bookRead.close();
	}
	else{
		cout << "file not opened \n";
	}
}