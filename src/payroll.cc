/*
Create a Payroll Application for an Organization. This Application takes the
employee_name, emp_id, email_id, hourly_rate and number of hours worked from the
user and calculates the gross pay (hourly_rate * number of hours) and stores it
in a file.

a) Define appropriate constructors to get the input from the user.
b) Define exceptions
  i) when an empty string is given for employee name.
  ii) When an invalid number is given for emp_id, number_of_hours,hourly_rate
  iii) when an invalid email_id is given.

Store it in the appropriate text file. Generate a report of the employees whose
gross_salary is higher than Rs.20000.
*/

#include <iostream>
using namespace std;

class Payroll {
  string name;
  int emp_id;
  string email_id;
  float hourly_rate;
  int hours_worked;

  float gross_pay;  // calculated in calculate_pay() method

 public:
  Payroll() {}  // default constructor

  Payroll(string name, int emp_id, string email_id, float hourly_rate,
          int hours_worked) {
    this->name = name;
    this->emp_id = emp_id;
    this->email_id = email_id;
    this->hourly_rate = hourly_rate;
    this->hours_worked = hours_worked;
  }

  void get_input() {}  // using cin statements
  void calculate_pay() {
    gross_pay = hourly_rate * hours_worked;
  }                        // will throw exceptions
  void write_to_file();    // using stream class fstream
  void generate_report();  // read from file and generate
};

#include <fstream>

void Payroll::write_to_file() {
  string filename = "data.txt";

  ofstream outfile;
  outfile.open(filename.c_str(), ios::binary);
  outfile.write((char*)this, sizeof(Payroll));
  outfile.close();
}

void Payroll::generate_report() {
  string filename = "data.txt";
  ifstream infile;
  infile.open(filename.c_str(), ios::binary);
  Payroll temp;
  infile.read((char*)&temp, sizeof(temp));

  if (temp.gross_pay > 20000)
    cout << "Name: " << temp.name << endl
         << "Emp ID: " << temp.emp_id << endl
         << "Gross Pay: " << temp.gross_pay << endl;

  infile.close();
}

int main() {
  Payroll pay1("Joe Smith", 10001, "junk", 400, 10);
  Payroll pay2("John Doe", 10002, "john", 400, 100);
  pay1.get_input();

  try {
    pay1.calculate_pay();
    pay2.calculate_pay();
  } catch (const char* msg) {
    cout << msg;
    exit(-1);
  }

  pay1.write_to_file();
  pay1.generate_report();

  pay2.write_to_file();
  pay2.generate_report();

  return 0;
}