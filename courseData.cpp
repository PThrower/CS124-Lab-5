#include "courseData.h"
#include <iostream>

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