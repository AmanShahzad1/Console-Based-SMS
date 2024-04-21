#pragma once
# include <iostream>
# include<string>
using namespace std;

class Student {			//Creating a class for Student's data
public:
	string S_id;
	string SFname, SLname, SEmail, SReg_Date, SGender, SB_Group, SContact_No, SFee;
	char SAddress[200];
	Student();
	void setSID(int Sr_No);
	Student setSCredentials();
	void Sdisplay();
};

class StudentList {
	int Ssize, S_Sr_No;
	Student* Sarr;
public:
	StudentList();
	void resizeSList();
	bool SList_isFull();
	void newStudent();
	void displaySList();
	void save_to_Sfile();
	void load_from_Sfile();
	void updateSCredentials();
};
