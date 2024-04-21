# include <iostream>
# include <stdlib.h>
# include "windows.h"
# include "teacher.h"
# include "Student.h"
using namespace std;
int main() {
	system("Color 1E");
	TeacherList obj;
	StudentList Sobj;
	obj.load_from_file();
	Sobj.load_from_Sfile();
	bool check = 1;
	bool chk1 = 1;
	int choice1, choice2;

	cout << "------------------Student Management System-----------------" << endl << endl;
	while (check) {
		cout << "-----------Access Record-----------" << endl;
		cout << "1. Teacher" << endl;
		cout << "2. Student" << endl;
		cout << "3. Exit" << endl;
		cout << "Enter choice =  ";
		cin >> choice1;
		chk1 = 1;
		system("cls");
		if (choice1 == 1) {
			cout << "-----------------------Teacher Record-----------------------" << endl;
			while (chk1) {
				cout << "Enter 1: To insert the record of a new teacher" << endl;
				cout << "Enter 2: To display the teachers record" << endl;
				cout << "Enter 3: To updated the credentials" << endl;
				cout << "Enter 9: To exit" << endl;
				cout << "Enter choice = ";
				cin >> choice2;
				switch (choice2) {
				case 1:
					obj.newTeacher();
					obj.load_from_file();
					break;
				case 2:
					obj.displayList();
					break;
				case 3:
					obj.updateCredentials();
					obj.load_from_file();
					break;
				case 9:
					system("cls");
					chk1 = 0;
					break;
				default:
					cout << "Incorrect entry!" << endl;
					break;
				}
			}
		}
		else if (choice1 == 2) {
			cout << "-----------------------Student Record-----------------------" << endl;
			while (chk1) {
				cout << "Enter 1: To insert the record of a new student" << endl;
				cout << "Enter 2: To display the students record" << endl;
				cout << "Enter 3: To updated the student credentials" << endl;
				cout << "Enter 9: To exit" << endl;
				cout << "Enter choice = ";
				cin >> choice2;
				switch (choice2) {
				case 1:
					Sobj.newStudent();
					Sobj.load_from_Sfile();
					break;
				case 2:
					Sobj.displaySList();
					break;
				case 3:
					Sobj.updateSCredentials();
					Sobj.load_from_Sfile();
					break;
				case 9:
					chk1 = 0;
					system("cls");
					break;
				default:
					cout << "Incorrect entry!" << endl;
					break;
				}
			}
		}
		else if (choice1 == 3) {
			check = 0;
			break;
		}
		else {
			cout << "Incorrect entry!" << endl;
			cout << "Try Again!" << endl;
		}
	}

	cout << endl;
	system("pause");
	return 0;
}