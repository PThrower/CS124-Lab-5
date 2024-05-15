/*
This takes in data from grade-scale.csv for further processing.
*/
#include "gradeScale.h"
#include "binarySearchTree.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

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


void GradeScale::activate() {
    ifstream file("grade-scale.csv");
    if (!file.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    string line;
    // Skip the header line
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string section, description, idNumber, weightLBS;
        getline(ss, section, ',');
        getline(ss, description, ',');
        getline(ss, idNumber, ',');
        getline(ss, weightLBS, ',');

        // Convert units from string to int
        try {
            int id = stoi(idNumber);
        } catch (const invalid_argument& e) {
            cerr << "Error: Invalid argument - " << e.what() << endl;
        }

        try {
            int weight = stoi(weightLBS);
        } catch (const invalid_argument& e) {
            cerr << "Error: Invalid argument - " << e.what() << endl;
        }

        // Create a new CourseData object and populate it
        GradeScale scale;
        scale.setGroupID(id);
        scale.setSection(section);
        scale.setDescription(description);
        scale.setWeight(description, weight);


        // Activate to display the populated data
        scale.activate();
    }

    file.close();
}