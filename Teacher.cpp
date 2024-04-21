# include <iostream>
# include <fstream>
# include<string>
# include "Teacher.h"
using namespace std;

// Constructor for TeacherNode class
Teacher::Teacher() {
	T_id = "\0";
	Fname = "\0";
	Lname = "\0";
	User_name = "\0";
	Email = "\0";
	Reg_Date = "\0";
	Gender = "\0";
	B_Group = "\0";
	Contact_No = "\0";
	for (int i = 0; i < 200; i++) {
		Address[i] = '\0';
	}
}

// Setter function to set ID in increasing order
void Teacher::setID(int Sr_No) {
	string temp = to_string(Sr_No);		// Converting integer to string value
	this->T_id = temp;
}

// Function to input data of credentials
Teacher Teacher ::setCredentials() {
	Teacher obj;
	string temp;
	int day = 0, month = 0, year = 0;
	bool chk = 0, tempchk;
	cout << "Enter the first name of new teacher = ";
	cin >> obj.Fname;
	cout << "Enter the last name of new teacher = ";
	cin >> obj.Lname;
	cout << "Enter the username of new teacher = ";
	cin >> obj.User_name;
	cout << "Enter the email of new teacher = ";
	cin >> obj.Email;

	cout << "Enter day of registration = ";
	cin >> day;
	while (chk == 0) {			
		if (day > 0 && day <= 31) {
			temp = to_string(day);
			chk = 1;
			break;
		}
		else {
			cout << "Invalid day entered!" << endl;
			cout << "Please enter day again = ";
			cin >> day;
		}
	}
	obj.Reg_Date = temp;
	obj.Reg_Date.append("/");

	chk = 0;
	cout << "Enter month of registration = ";
	cin >> month;
	while (chk == 0) {
		if (month > 0 && month < 13) {
			temp = to_string(month);
			chk = 1;
			break;
		}
		else {
			cout << "Invalid month entered!" << endl;
			cout << "Please enter month again = ";
			cin >> month;
		}
	}
	obj.Reg_Date.append(temp);
	obj.Reg_Date.append("/");
	chk = 0;
	cout << "Enter year of registration = ";
	cin >> year;
	while (chk == 0) {
		if (year > 0 && year < 9999) {
			temp = to_string(year);
			chk = 1;
			break;
		}
		else {
			cout << "Invalid year entered!" << endl;
			cout << "Please enter year again = ";
			cin >> year;
		}
	}
	temp = to_string(year);
	obj.Reg_Date.append(temp);

	chk = 0;
	cout << "Enter the Gender of new teacher (For male (Enter = M), For (Enter = F),For other(Enter = O)) = ";
	cin >> obj.Gender;
	while (chk == 0) {
		if (obj.Gender == "M" || obj.Gender == "F" || obj.Gender == "O") {
			chk = 1;
			break;
			
		}
		else {
			cout << "Invalid entry!" << endl;
			cout << "Please enter gender again (For male (Enter = M), For (Enter = F),For other(Enter = O)) = ";
			cin >> obj.Gender;
		}
	}

	chk = 0;
	cout << "Enter the blood group of new teacher = ";
	cin >> obj.B_Group;
	while (chk == 0) {
		if (obj.B_Group[1] == '+' || obj.B_Group[1] == '-') {
			chk = 1;
			break;
		}
		else {
			cout << "Invalid entry!" << endl;
			cout << "Please enter gender again (Eg., B+)) = ";
			cin >> obj.B_Group;
		}
	}

	cout << "Enter the contact number of new teacher = ";
	cin >> obj.Contact_No;
	chk = 0;
	while (chk == 0) {		// Checking if the entered Contact number is  correct or not
		tempchk = 0;
		if (obj.Contact_No.length() < 10 || obj.Contact_No.length() >11) {
			cout << "Incorrect entry!" << endl;
			cout << "Please insert number without any special character (eg., '-') = ";
			cin >> obj.Contact_No;
		}
		else if (obj.Contact_No.length() == 11) {
			for (int i = 0; i < 11; i++) {
				if (obj.Contact_No[i] > 'A') {
					tempchk = 1;
				}
			}
			if (tempchk == 1) {
				cout << "Incorrect entry!" << endl;
				cout << "Please insert number having 11 digits and without any special character (eg.'-') = ";
				cin >> obj.Contact_No;
			}

			else {
				chk = 1;
				break;
			}
		}
		else if (obj.Contact_No.length() == 10) {
			for (int i = 0; i < 10; i++) {
				if (obj.Contact_No[i] > 'A') {
					tempchk = 1;
				}
			}
			if (tempchk == 1) {
				cout << "Incorrect entry!" << endl;
				cout << "Please insert number having 11 digits and without any special character (eg.'-') = ";
				cin >> obj.Contact_No;
			}

			else {
				chk = 1;
				break;
			}
		}

	}

	cout << "Enter the address of new teacher = ";

	cin.ignore();
	cin.getline(obj.Address, 200);

	return obj;
}

void Teacher::display() {
	cout << T_id << "\t" << Fname << "\t" << Lname << "\t" << User_name << "\t\t" << Email << "\t" << Reg_Date << "\t" << B_Group << "\t" << Contact_No << "\t" << Address;
}

//--------------------------------------------------------------------------------//

// Constructor for Teacher class
TeacherList::TeacherList() {
	this->size = 100;
	this->Sr_No = 0;
	arr = new Teacher[this->size];
}

int TeacherList::getSR() {
	return Sr_No;
}
// Function to check if the list of teachers is full or not
bool TeacherList :: isFull() {
	if (Sr_No == this->size - 1) {
		return 1;
	}
	return 0;
}

// Function to resize the list of teachers
void TeacherList::resizeList() {
	Teacher* temp = new Teacher[this->size];
	for (int i = 0; i < Sr_No; i++) {
		temp[i] = arr[i];
	}
	delete arr;
	this->size = (this->size * 2);
	arr = new Teacher[this->size];
	for (int i = 1; i <= Sr_No; i++) {
		arr[i] = temp[i];
	}
}

void TeacherList::newTeacher() {
	Teacher temp;
	if (isFull()) {
		resizeList();
	}
	Sr_No++;
	arr[Sr_No] = temp.setCredentials();
	arr[Sr_No].setID(Sr_No);
	save_to_file();
}

void TeacherList::displayList() {
	if(Sr_No == 0) {
		cout << "Teacher List is Empty!" << endl;
	}
	else {
		cout << "T_ID" << "\tF_name" << "\tL_name" << "\tUsername" << "\tEmail" << "\t\t\tReg_Date" << "\tB.Group" << "\t Contact #" << "\t Address" << endl;
		for (int i = 1; i <= Sr_No; i++) {
			arr[i].display();
		}
		cout << endl << endl; 
	}
}

//-----------------------Updating Credentionals---------------------//

void TeacherList::updateCredentials() {
	int temp, temp2;
	string tempstr;
	char st, st1[200];
	bool chk1, chk2;
	displayList();
	cout << "Enter the T-id of the teacher = ";
	cin >> temp;
	while (temp < 0 && temp > Sr_No) {
		cout << "Incorrect Entry!" << endl;
		cout << "Enter the T-id of the teacher = ";
		cin >> temp;
	}
	cout << "T_ID" << "\tF_name" << "\tL_name" << "\tUsername" << "\tEmail" << "\t\tReg_Date" << "\tB.Group" << "\t Contact #" << "Address" << endl;
	arr[temp].display();
	cout << endl;
	chk1 = 0, chk2 = 0;
	while (chk1 == 0) {
		while (chk2 == 0) {
			cout << "1. F_name" << endl;
			cout << "2. L_name" << endl;
			cout << "3. Username" << endl;
			cout << "4. Email" << endl;
			cout << "5. Contact" << endl;
			cout << "6. Address" << endl;

			cout << "Enter the number of credential you want to change = ";
			cin >> temp2;
			cout << endl;
			if (temp2 == 1) {
				cout << "Enter new first name = ";
				cin >> tempstr;
				arr[temp].Fname = tempstr;
				cout << "Updated successfully! \n\n";
				chk2 = 1;
				break;
			}
			else if (temp2 == 2) {
				cout << "Enter new last name = ";
				cin >> tempstr;
				arr[temp].Lname = tempstr;
				cout << "Updated successfully! \n\n";
				chk2 = 1;
				break;
			}
			else if (temp2 == 3) {
				cout << "Enter new username = ";
				cin >> tempstr;
				arr[temp].User_name = tempstr;
				cout << "Updated successfully! \n\n";
				chk2 = 1;
				break;
			}
			else if (temp2 == 4) {
				cout << "Enter new email = ";
				cin >> tempstr;
				arr[temp].Email = tempstr;
				cout << "Updated successfully! \n\n";
				chk2 = 1;
				break;
			}
			else if (temp2 == 5) {
				cout << "Enter new contact number = ";
				cin >> tempstr;
				arr[temp].Contact_No = tempstr;
				cout << "Updated successfully! \n\n";
				chk2 = 1;
				break;
			}
			else if (temp2 == 6) {
				int stemp = 0;
				cout << "Enter new address = ";
				cin.ignore();
				cin.getline(st1, 200);
				for (int i = 0; st1[i] != '\0';i++) {
					arr[temp].Address[i] = st1[i];
					stemp = i;
				}
				stemp++;
				arr[temp].Address[stemp] = '/';
				for (int k = stemp + 1; k < 200; k++) {
					arr[temp].Address[stemp] = '\0';
				}

				cout << "Updated successfully! \n\n";
				chk2 = 1;
				break;
			}
			else {
				cout << "Invalid entry!" << endl;
			}
		}
		cout << "\nDo you want to update anything else? (Y/N) = ";
		cin >> st;
		while (st != 'Y' && st != 'N') {
			cout << "Incorrect entry! " << endl;
			cout << "\nDo you want to update anything else? (Y/N) = ";
			cin >> st;
		}
		if (st == 'N') {
			chk1 = 1;
			break;
		}
		else if(st == 'Y') {
			chk2 = 0;
		}
		
	}
	Updatesave_to_file();
	cout << endl;
}

// -------------File Handling Functions---------------------//

void TeacherList::save_to_file() {
	ofstream out;
	int temp = 0;
	out.open("teacher.txt");
	if (!out.is_open()) {
		cout << "File does not exsist!" << endl;
	}
	else {
		out << Sr_No << endl;
		for (int i = 1; i <= Sr_No; i++) {
			if (i == Sr_No) {
				out << endl;
			}
			out << arr[i].T_id << ',' << arr[i].Fname << ',' << arr[i].Lname << ',';
			out << arr[i].User_name << ',' << arr[i].Email << ',' << arr[i].Reg_Date << ',';
			out << arr[i].Gender << ',' << arr[i].B_Group << ',' << arr[i].Contact_No << ',';
			for (int j = 0; arr[i].Address[j] != '\0'; j++) {
				out << arr[i].Address[j];
				temp = j;
			}
			if (arr[i].Address[temp] != '/') {
				out << '/' ;
			}
			
		}

		out.close();
	}

}

void TeacherList::Updatesave_to_file() {
	ofstream out;
	int temp = 0;
	out.open("teacher.txt");
	if (!out.is_open()) {
		cout << "File does not exsist!" << endl;
	}
	else {
		out << Sr_No << endl;
		for (int i = 1; i <= Sr_No; i++) {
			out << arr[i].T_id << ',' << arr[i].Fname << ',' << arr[i].Lname << ',';
			out << arr[i].User_name << ',' << arr[i].Email << ',' << arr[i].Reg_Date << ',';
			out << arr[i].Gender << ',' << arr[i].B_Group << ',' << arr[i].Contact_No << ',';
			for (int j = 0; arr[i].Address[j] != '\0'; j++) {
				out << arr[i].Address[j];
				temp = j;
			}
			if (arr[i].Address[temp] != '/') {
				out << '/';
			}

		}

		out.close();
	}

}
void TeacherList::load_from_file() {
	char temp[200];
	ifstream in;  
	in.open("teacher.txt");
	if (!in.is_open()) {
		cout << "File does not exsist!" << endl;
	}
	else {
		in >> Sr_No;
		if (Sr_No != 0) {
			for (int i = 1; i <= Sr_No; i++) {
				getline(in, arr[i].T_id, ',');
				getline(in, arr[i].Fname, ',');
				getline(in, arr[i].Lname, ',');
				getline(in, arr[i].User_name, ',');
				getline(in, arr[i].Email, ',');
				getline(in, arr[i].Reg_Date, ',');
				getline(in, arr[i].Gender, ',');
				getline(in, arr[i].B_Group, ',');
				getline(in, arr[i].Contact_No, ',');
				for (int j = 0;j < 200; j++) {
					in.get(temp[j]);
					if (temp[j] == '/') {
						arr[i].Address[j] = temp[j];
						break;
					}
					else {
						arr[i].Address[j] = temp[j];
					}
				}
			}
		}
		in.close();
		
	}
}
