# include <iostream>
# include <fstream>
# include<string>
# include "Student.h"
using namespace std;

// Constructor for TeacherNode class
Student::Student() {
	S_id = "\0";
	SFname = "\0";
	SLname = "\0";
	SEmail = "\0";
	SReg_Date = "\0";
	SGender = "\0";
	SB_Group = "\0";
	SContact_No = "\0";
	for (int i = 0; i < 200; i++) {
		SAddress[i] = '\0';
	}
}

// Setter function to set ID in increasing order
void Student::setSID(int Sr_No) {
	string temp = to_string(Sr_No);		// Converting integer to string value
	this->S_id = temp;
}

// Function to input data of credentials
Student Student::setSCredentials() {
	Student obj;
	string temp;
	int day = 0, month = 0, year = 0;
	bool chk = 0, tempchk;
	cout << "Enter the first name of new student = ";
	cin >> obj.SFname;
	cout << "Enter the last name of new student = ";
	cin >> obj.SLname;
	cout << "Enter the email of new student = ";
	cin >> obj.SEmail;

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
	obj.SReg_Date = temp;
	obj.SReg_Date.append("/");

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
	obj.SReg_Date.append(temp);
	obj.SReg_Date.append("/");
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
	obj.SReg_Date.append(temp);

	chk = 0;
	cout << "Enter the Gender of new student (For male (Enter = M), For (Enter = F),For other(Enter = O)) = ";
	cin >> obj.SGender;
	while (chk == 0) {
		if (obj.SGender == "M" || obj.SGender == "F" || obj.SGender == "O") {
			chk = 1;
			break;

		}
		else {
			cout << "Invalid entry!" << endl;
			cout << "Please enter gender again (For male (Enter = M), For (Enter = F),For other(Enter = O)) = ";
			cin >> obj.SGender;
		}
	}

	chk = 0;
	cout << "Enter the blood group of new student = ";
	cin >> obj.SB_Group;
	while (chk == 0) {
		if (obj.SB_Group[1] == '+' || obj.SB_Group[1] == '-') {
			chk = 1;
			break;
		}
		else {
			cout << "Invalid entry!" << endl;
			cout << "Please enter gender again (Eg., B+)) = ";
			cin >> obj.SB_Group;
		}
	}

	cout << "Enter the contact number of new student = ";
	cin >> obj.SContact_No;
	chk = 0;
	while (chk == 0) {		// Checking if the entered Contact number is  correct or not
		tempchk = 0;
		if (obj.SContact_No.length() < 10 || obj.SContact_No.length() > 11) {
			cout << "Incorrect entry!" << endl;
			cout << "Please insert number without any special character (eg., '-') = ";
			cin >> obj.SContact_No;
		}
		else if (obj.SContact_No.length() == 11) {
			for (int i = 0; i < 11; i++) {
				if (obj.SContact_No[i] > 'A') {
					tempchk = 1;
				}
			}
			if (tempchk == 1) {
				cout << "Incorrect entry!" << endl;
				cout << "Please insert number having 11 digits and without any special character (eg.'-') = ";
				cin >> obj.SContact_No;
			}

			else {
				chk = 1;
				break;
			}
		}
		else if (obj.SContact_No.length() == 10) {
			for (int i = 0; i < 10; i++) {
				if (obj.SContact_No[i] > 'A') {
					tempchk = 1;
				}
			}
			if (tempchk == 1) {
				cout << "Incorrect entry!" << endl;
				cout << "Please insert number having 11 digits and without any special character (eg.'-') = ";
				cin >> obj.SContact_No;
			}

			else {
				chk = 1;
				break;
			}
		}

	}

	cout << "Enter the address of new student = ";

	cin.ignore();
	cin.getline(obj.SAddress, 200);

	chk = 0;
	cout << "Enter the fee status(Paid/Unpaid) = ";
	cin >> temp;
	while (chk == 0) {
		if (temp == "Paid" || temp == "Unpaid") {
			obj.SFee = temp;
			chk = 1;
			break;
		}
		else {
			cout << "Invalid entry!" << endl;
			cout << "Enter fee status again (eg., Paid) = ";
			cin >> temp;
		}
	}
	return obj;
}

void Student:: Sdisplay() {
	cout << S_id << "\t" << SFname << "\t" << SLname << "\t" << SEmail << "\t" << SReg_Date << "\t" << SB_Group << "\t" << SContact_No << "\t" << SAddress << "\t" << SFee << endl;
}

//--------------------------------------------------------------------------------//


// Constructor for Student class
StudentList::StudentList() {
	this->Ssize = 100;
	this->S_Sr_No = 0;
	Sarr = new Student[this->Ssize];
}

// Function to check if the list of Students is full or not
bool StudentList::SList_isFull() {
	if (S_Sr_No == this->Ssize - 1) {
		return 1;
	}
	return 0;
}

// Function to resize the list of students
void StudentList::resizeSList() {
	Student* temp = new Student[this->Ssize];
	for (int i = 0; i < S_Sr_No; i++) {
		temp[i] = Sarr[i];
	}
	delete Sarr;
	this->Ssize = (this->Ssize * 2);
	Sarr = new Student[this->Ssize];
	for (int i = 1; i <= S_Sr_No; i++) {
		Sarr[i] = temp[i];
	}
}

void StudentList::newStudent() {
	Student temp;
	if (SList_isFull()) {
		resizeSList();
	}
	S_Sr_No++;
	Sarr[S_Sr_No] = temp.setSCredentials();
	Sarr[S_Sr_No].setSID(S_Sr_No);
	save_to_Sfile();
}

void StudentList::displaySList() {
	if (S_Sr_No == 0) {
		cout << "Student List is Empty!" << endl;
	}
	else {
		cout << "S_ID" << "\tF_name" << "\tL_name" << "\tEmail" << "\t\t\tReg_Date" << "\tB.Group" << "\t Contact #" << "\t Address" << "\tFee St." << endl;
		for (int i = 1; i <= S_Sr_No; i++) {
			Sarr[i].Sdisplay();
		}
		cout << endl << endl;
	}
}

//-----------------------Updating Credentionals---------------------//

void StudentList::updateSCredentials() {
	int temp, temp2;
	string tempstr;
	char st, st1[200];
	bool chk1, chk2;
	displaySList();
	cout << "Enter the S-id of the student = ";
	cin >> temp;
	cout << "S_ID" << "\tF_name" << "\tL_name" << "\tEmail" << "\t\tSReg_Date" << "\tB.Group" << "\t Contact #" << "\tAddress" << "\tFee St." << endl;
	Sarr[temp].Sdisplay();
	cout << endl;
	chk1 = 0, chk2 = 0;
	while (chk1 == 0) {
		while (chk2 == 0) {
			cout << "1. F_name" << endl;
			cout << "2. L_name" << endl;
			cout << "3. Email" << endl;
			cout << "4. Contact" << endl;
			cout << "5. Address" << endl;
			cout << "6. Fee Status" << endl;

			cout << "Enter the number of credential you want to change = ";
			cin >> temp2;
			cout << endl;
			if (temp2 == 1) {
				cout << "Enter new first name = ";
				cin >> tempstr;
				Sarr[temp].SFname = tempstr;
				cout << "Updated successfully! \n\n";
				chk2 = 1;
				break;
			}
			else if (temp2 == 2) {
				cout << "Enter new last name = ";
				cin >> tempstr;
				Sarr[temp].SLname = tempstr;
				cout << "Updated successfully! \n\n";
				chk2 = 1;
				break;
			}

			else if (temp2 == 3) {
				cout << "Enter new email = ";
				cin >> tempstr;
				Sarr[temp].SEmail = tempstr;
				cout << "Updated successfully! \n\n";
				chk2 = 1;
				break;
			}
			else if (temp2 == 4) {
				cout << "Enter new contact number = ";
				cin >> tempstr;
				Sarr[temp].SContact_No = tempstr;
				cout << "Updated successfully! \n\n";
				chk2 = 1;
				break;
			}
			else if (temp2 == 5) {
				int stemp = 0;
				cout << "Enter new address = ";
				cin.ignore();
				cin.getline(st1, 200);
				for (int i = 0; st1[i] != '\0';i++) {
					Sarr[temp].SAddress[i] = st1[i];
					stemp = i;
				}
				stemp++;
				Sarr[temp].SAddress[stemp] = '/';
				for (int k = stemp + 1; k < 200; k++) {
					Sarr[temp].SAddress[stemp] = '\0';
				}

				cout << "Updated successfully! \n\n";
				chk2 = 1;
				break;
			}
			else if (temp2 == 6) {
				bool chk = 0;
				cout << "Enter the fee status(Paid/Unpaid) = ";
				cin >> tempstr;
				while (chk == 0) {
					if (tempstr == "Paid" || tempstr == "Unpaid") {
						Sarr[temp].SFee = tempstr;
						chk = 1;
						chk2 = 1;
						break;
					}
					else {
						cout << "Invalid entry!" << endl;
						cout << "Enter fee status again (eg., Paid) = ";
						cin >> tempstr;
					}
				}
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
		else if (st == 'Y') {
			chk2 = 0;
		}
	}
	save_to_Sfile();
	cout << endl;
}

// -------------File Handling Functions---------------------//

void StudentList::save_to_Sfile() {
	ofstream out;
	int temp = 0;
	out.open("student.txt");
	if (!out.is_open()) {
		cout << "File does not exsist!" << endl;
	}
	else {
		out << S_Sr_No << endl;
		for (int i = 1; i <= S_Sr_No; i++) {
			out << Sarr[i].S_id << ',' << Sarr[i].SFname << ',' << Sarr[i].SLname << ',';
			out << Sarr[i].SEmail << ',' << Sarr[i].SReg_Date << ',';
			out << Sarr[i].SGender << ',' << Sarr[i].SB_Group << ',' << Sarr[i].SContact_No << ',';
			for (int j = 0; Sarr[i].SAddress[j] != '\0'; j++) {
				out << Sarr[i].SAddress[j];
				temp = j;
			}
			if (Sarr[i].SAddress[temp] != '/') {
				out << '/';
			}
			out << ',' << Sarr[i].SFee << endl;
		}

		out.close();
	}

}

void StudentList::load_from_Sfile() {
	char temp[200];
	ifstream in;
	in.open("student.txt");
	if (!in.is_open()) {
		cout << "File does not exsist!" << endl;
	}
	else {
		in >> S_Sr_No;
		if (S_Sr_No != 0) {
			for (int i = 1; i <= S_Sr_No; i++) {
				getline(in, Sarr[i].S_id, ',');
				getline(in, Sarr[i].SFname, ',');
				getline(in, Sarr[i].SLname, ',');
				getline(in, Sarr[i].SEmail, ',');
				getline(in, Sarr[i].SReg_Date, ',');
				getline(in, Sarr[i].SGender, ',');
				getline(in, Sarr[i].SB_Group, ',');
				getline(in, Sarr[i].SContact_No, ',');
				for (int j = 0;j < 200; j++) {
					in.get(temp[j]);
					if (temp[j] == ',') {
						break;
					}
					else {
						Sarr[i].SAddress[j] = temp[j];
					}
				}
				getline(in, Sarr[i].SFee, '\n');
			}
		}
		in.close();
	}

}
