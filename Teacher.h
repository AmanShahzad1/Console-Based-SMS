#pragma once
# include <iostream>
# include<string>
using namespace std;

class Teacher {			//Creating a class for Teacher's data
public:
	string T_id;
	string Fname, Lname, User_name, Email, Reg_Date, Gender, B_Group, Contact_No;
	char Address[200];
	Teacher();
	void setID(int Sr_No);
	Teacher setCredentials();
	void display();
};

class TeacherList {
	int size, Sr_No;
	Teacher* arr;
public:
	TeacherList();
	int getSR();
	void resizeList();
	bool isFull();
	void newTeacher();
	void displayList();
	void save_to_file();
	void Updatesave_to_file();
	void load_from_file();
	void updateCredentials();
};
