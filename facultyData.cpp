#include "facultyData.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

FacultyData::FacultyData() {

}

FacultyData::~FacultyData() {

}

void FacultyData::setFacultyID(string facultyID) {
    this->facultyID = facultyID;
}

void FacultyData::setFirstName(string firstname) {
    this->firstname = firstname;
}

void FacultyData::setLastName(string lastname) {
    this->lastname = lastname;
}

void FacultyData::setDepartment(string department) {
    this->department = department;
}

void FacultyData::setAddress(string address) {
    this->address = address;
}

void FacultyData::setCity(string city) {
    this->city = city;
}

void FacultyData::setState(string state) {
    this->state = state;
}

void FacultyData::setZip(int zip) {
    this->zip = zip;
}

void FacultyData::setEmail(string email) {
    this->email = email;
}

void FacultyData::setPhone(string phone) {
    this->phone = phone;
}

string FacultyData::getFacultyID() const {
    return this->facultyID;
}

string FacultyData::getFirstName() const {
    return this->firstname;
}

string FacultyData::getLastName() const {
    return this->lastname;
}

string FacultyData::getDepartment() const {
    return this->department;
}

string FacultyData::getAddress() const {
    return this->address;
}

string FacultyData::getCity() const {
    return this->city;
}

int FacultyData::getZip() const {
    return this->zip;
}

string FacultyData::getEmail() const {
    return this->email;
}

string FacultyData::getPhone() const {
    return this->phone;
}

void FacultyData::activate() {
    ifstream file("course-data.csv");
    if (!file.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    string line;
    // Skip the header line
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string facultyID, firstname, lastname, department, 
        address, city, state, email, phone, zipcode;
        getline(ss, facultyID, ',');
        getline(ss, firstname, ',');
        getline(ss, lastname, ',');
        getline(ss, department, ',');
        getline(ss, address, ',');
        getline(ss, city, ',');
        getline(ss, state, ',');
        getline(ss, email, ',');
        getline(ss, phone, ',');
        getline(ss, zipcode, ',');

        // Convert units from string to int
        try {
            int zip = stoi(zipcode);
        } catch (const invalid_argument& e) {
            cerr << "Error: Invalid argument - " << e.what() << endl;
        }

        // Create a new CourseData object and populate it
        FacultyData faculty;
        faculty.setFirstName(firstname);
        faculty.setLastName(lastname);
        faculty.setDepartment(department);
        faculty.setAddress(address);
        faculty.setCity(city);
        faculty.setState(state);
        faculty.setZip(zip);
        faculty.setEmail(email);
        faculty.setPhone(phone);

        // Activate to display the populated data
        faculty.activate();
    }

    file.close();
}