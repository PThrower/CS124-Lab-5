#include "facultyData.h"
#include <iostream>

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