#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

//PROTOTYPES OF ALL FUNCTIONS
void optionSubmitted(int choice);
void create_student();
void display_all_students();
void display_specific_student(char rollNo[]);
void create_book();
void display_all_books();
void display_specific_book(char isbnNo[]);
bool issuedbook(char rollNoCheck[],char isbnNoCheck[]);
// function to link archive to book
//function to link book to students
//

//PROTOTYPES END HERE

//DECLARATION OF CLASSES
struct student{
	char rollNo[20];
	char sname[20];
	char phonenum[11];
	int bookcount;
	student(){
		strcpy(rollNo, "");
		strcpy(sname, "");
		strcpy(phonenum, "");
		bookcount = 0;
	}
};

struct book{
	char isbnNo[20];
	char bname[20];
	char authorName[20];
	book(){
		strcpy(isbnNo, "");
		strcpy(bname, "");
		strcpy(authorName, "");
	}
};
struct issued{
	char rollNo[20];
	char isbnNo[20];
	issued(){
		strcpy(rollNo, "");
		strcpy(isbnNo, "");
	}
};

struct archive{
    char isbnNo[20];
    int ctr;
    archive(){
		strcpy(isbnNo, "");
    	ctr = 0;
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
	student obj;

	cin.getline(rollNo, 19);
	cin.getline(sname, 19);
	cin.getline(phonenum, 19);

	

	ofstream studentWrite;
	studentWrite.open("students.dat", ios :: app | ios :: binary);
	if(studentWrite.is_open()){
		cout << "Student successfully written" << endl;
		studentWrite.write((char*)&obj,sizeof(student));
		studentWrite.close();
	}
	else{
		cout << "file not opening" << endl;
	}
}

void display_all_students(){
//	char rollNo[20];
//	char sname[20];
//	char phonenum[20];
    student temp;
	getchar();
	ifstream studentRead("students.dat",ios :: binary);

	if(studentRead.is_open()){
		cout << "file opened successfully \n";
		while(studentRead.read((char*)&temp,sizeof(student))){
			cout << temp.rollNo << " " << temp.sname << " " << temp.phonenum << " " << temp.bookcount << endl;
		}
		studentRead.close();
	}
	else{
		cout << "file not opened \n";
	}
}

void display_specific_student(char rollNoCheck[]){
//	char rollNoCheck[20];
//	char sname[20];
//	char phonenum[20];
	student temp;
	ifstream studentRead("students.dat",ios :: binary);
	if(studentRead.is_open()){
		cout << "file opened successfully \n";
		// cout << strcmp(rollNo, rollNoCheck);
		while(studentRead.read((char*)&temp,sizeof(student))){
			if(strcmp(temp.rollNo, rollNoCheck) == 0){
				cout << temp.rollNo << " " << temp.sname << " " << temp.phonenum << endl;
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
//	char isbnNo[20];
//	char bname[20];
//	char authorName[20];
    book obj;	//redundant lines honestly
	getchar();
	cin.getline(obj.isbnNo, 19);
	cin.getline(obj.bname, 19);
	cin.getline(obj.authorName, 19);

	ofstream bookWrite("books.dat", ios :: app|ios ::binary);
	if(bookWrite.is_open()){
		cout << "Book successfully written" << endl;
		bookWrite.write((char*)&obj,sizeof(student));
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
	ifstream bookRead("books.dat",ios::binary);

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

void display_specific_book(char isbnNoCheck[]){
	book temp;
	ifstream bookRead("books.dat",ios ::binary);

	if(bookRead.is_open()){
		cout << "file opened successfully \n";
		// cout << strcmp(rollNo, rollNoCheck);
		while(bookRead.read((char*)&temp,sizeof(student))){
			if(strcmp(temp.isbnNo, isbnNoCheck) == 0){
				cout << temp.isbnNo << " " << temp.bname << " " << temp.authorName << endl;
				break;
			}
		}
		bookRead.close();
	}
	else{
		cout << "file not opened \n";
	}
}

bool issuedbook(char rollNoCheck[],char isbnNoCheck[20]){
student temp;
ifstream studentRead("students.dat",ios :: binary);
int pos = studentRead.tellg();
while(studentRead.read((char*)&temp,sizeof(student))){
 if(strcmp(rollNoCheck,temp.rollNo)==0){
    if(temp.bookcount<3){
        archive archtemp;
        ifstream archiveRead("archive.txt",ios :: binary);
        int archpos = archiveRead.tellg();
        while(archiveRead.read((char*)&archtemp,sizeof(archive))){
              if(strcmp(archtemp.isbnNo,isbnNoCheck)==0){
                if(archtemp.ctr>0){ /// if count of copies is more than '0'
                    studentRead.close(); /// only case of successful issue
                    archiveRead.close();
                    issued issuetemp;
                    strcpy(issuetemp.rollNo,rollNoCheck);
                    strcpy(issuetemp.isbnNo,isbnNoCheck);
                    temp.bookcount++;
                    archtemp.ctr--;
                    ofstream studentWrite("students.dat",ios :: binary | ios::ate); /// added book count to student
                        studentWrite.seekp(pos,ios :: beg);
                        studentWrite.write((char*)&temp,sizeof(student));
                    ofstream issuedWrite("issued.dat",ios :: binary); /// added book issued to issued file
                        issuedWrite.write((char*)&issuetemp,sizeof(issued));
                    ofstream archiveWrite("archive.dat",ios :: binary); /// removed book from archive
                        archiveWrite.seekp(archpos,ios :: beg);
                        archiveWrite.write((char*)&archtemp,sizeof(archive));
                return true;
                }
                else{
                    cout<<"All the copies of this book have been issued\n"; /// all copies issued
                    return false;
                }
                archpos = archiveRead.tellg();
              }
              else{
                cout<<"This book doesn't exist\n"; /// book doesn't exist
                return false;
              }
            }

    }
    else{
        cout<<"Maximum number of books issued for this student\n"; /// student has issued max number of books
        return false;
    }
    pos = studentRead.tellg();
 }
 else{
    cout<<"Student doesn't exist\n"; /// student doesn't exist in database
    return false;
 }
}
}
