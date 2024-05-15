#include "gradeScale.h"
#include <iostream>

using namespace std;

GradeScale::GradeScale() {
    this->description = "";
    this->weight = 0;
}

GradeScale::~GradeScale() {

}

void GradeScale::setGroupID(int id) {
    this->id = id;
}

void GradeScale::setSection(string section) {
    this->section = section;
}

void GradeScale::setDescription(string description) {
    this->description = description;
}

void GradeScale::setWeight(string description, int weight) {
    this->weight = weight;
    if (description == "Assignments") {
        this->weight = (weight * 10) / 100;
    }
    else if(description ==  "Quizzes") {
        this->weight = (weight * 10) / 100;
    }
    else if(description == "Labs") {
        this->weight = (weight * 30) / 100;
    }
    else if(description == "Midterm") {
        this->weight = (weight * 20) / 100;
    }
    else if(description == "Final Exam") {
        this->weight = (weight * 30) / 100;
    }
}

int GradeScale::getGroupID() const {
    return this->id;
}

string GradeScale::getSection() const {
    return this->section;
}

string GradeScale::getDescription() const {
    return this->description;
}

int GradeScale::getWeight() const {
    return this->weight;
}