#pragma once

#include <iostream>

using namespace std;

class CourseData {
public:
    CourseData();
    ~CourseData();

    void setTerm(string term);
    void setSection(string section);
    void setCourseName(string courseName);
    void setUnits(int units);
    void setFacultyID(string facultyID);

    string getTerm() const;
    string getSection() const;
    string getCourseName() const;
    int getUnits() const;
    string getFacultyID() const;

private:
    string term, section, courseName, facultyID;
    int units;
};