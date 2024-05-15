#pragma once

#include <iostream>

using namespace std;

class FacultyData {
public:
    FacultyData();
    ~FacultyData();

    void setFacultyID(string facultyID);
    void setFirstName(string firstname);
    void setLastName(string lastname);
    void setDepartment(string department);
    void setAddress(string address);
    void setCity(string city);
    void setState(string state);
    void setZip(int zip);
    void setEmail(string email);
    void setPhone(string phone);

    string getFacultyID() const;
    string getFirstName() const;
    string getLastName() const;
    string getDepartment() const;
    string getAddress() const;
    string getCity() const;
    int getZip() const;
    string getEmail() const;
    string getPhone() const;

private:
    string facultyID, firstname, lastname, department, address, city, state, email, phone;
    int zip;
};