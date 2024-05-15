#include "courseData.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


CourseData::CourseData() {

}

CourseData::~CourseData() {

}

void CourseData::setTerm(string term) {
    this->term = term;
}

void CourseData::setSection(string section) {
    this->section = section;
}

void CourseData::setCourseName(string courseName) {
    this->courseName = courseName;
}

void CourseData::setUnits(int units) {
    this->units = units;
}

void CourseData::setFacultyID(string facultyID) {
    this->facultyID = facultyID;
}

string CourseData::getTerm() const {
    return this->term;
}

string CourseData::getSection() const {
    return this->section;
}

string CourseData::getCourseName() const {
    return this->courseName;
}

int CourseData::getUnits() const {
    return this->units;
}

string CourseData::getFacultyID() const {
    return this->facultyID;
}

void CourseData::activate() {
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
        string term, section, courseName, facultyID, unitsStr;
        getline(ss, term, ',');
        getline(ss, section, ',');
        getline(ss, courseName, ',');
        getline(ss, unitsStr, ',');
        getline(ss, facultyID, ',');

        // Convert units from string to int
        try {
            int units = stoi(unitsStr);
        } catch (const invalid_argument& e) {
            cerr << "Error: Invalid argument - " << e.what() << endl;
        }

        // Create a new CourseData object and populate it
        CourseData course;
        course.setTerm(term);
        course.setSection(section);
        course.setCourseName(courseName);
        course.setUnits(units);
        course.setFacultyID(facultyID);

        // Activate to display the populated data
        course.activate();
    }

    file.close();
}