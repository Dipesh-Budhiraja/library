#include <iostream>
#include <unordered_map>
#include <cstring>
#include <fstream>
using namespace std;

//fn for book issue
void bookIssue(char isbn[], char rollno[], issued item[], archive data[]){
	//loop data
	//data[i].isbn = isbn //book exist otherwise not
	//now check bok id  //data.couter !=0 book with this isbn available
	//issue counter--  archive bookId delete and add inn issued
	//bookId = isbn + / + hidden	
} 

int returnFun(char bookId, issued item[], archive data[]){

}

//fn for checking 

struct student {
	char rollno[6];
	long int phonenum;
	char name[25], email[25];//email not necessary
	student(char rollno[], long int phonenum , char name[], char email[]){
		strcpy(this->rollno, rollno);
		this->phonenum = phonenum;
		strcpy(this->name, name);
		strcpy(this->email, email); 
	}

};

struct book {
	char title[25], author[25];
	int idarr[100];
	char isbn[11];
	book(char title[], char ){

	}
};

struct issued {
	char rollno[6];
	char bookId[15];
	int date;

};

struct archive {
	char isbn[11];
	char bookId[15];
	int counter;
	int hidden;
};

int main(){
	// unordered_map <long int, student> students;
	// unordered_map <long int, book> books;

	// student s1(1, 9999999999, "dipesh", "abc");
	// students.insert(make_pair(s1.rollno, s1));

	// auto got = students.begin();
	// cout << (got->second).name;
	// cout << students[100];
}