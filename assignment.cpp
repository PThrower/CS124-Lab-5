#include <iostream>
#include "assignment.h"

using namespace std;

AssignmentData::AssignmentData() {

}

AssignmentData::~AssignmentData() {

}

void AssignmentData::setID(int id) {
    this->id = id;
}

void AssignmentData::setGroupID(int groupID) {
    this->groupID = groupID;
}

void AssignmentData::setDescription(string description) {
    this->description = description;
}

void AssignmentData::setStartDate(DateTime start) {
    
}

void AssignmentData::setEndDate(DateTime end) {
    
}

void AssignmentData::setPossiblePoints(int possiblePoints) {
    this->possiblePoints = possiblePoints;
}

void AssignmentData::setPoints(int points) {
    this->points = points;
}

int AssignmentData::getID() const {
    return this->id;
}

int AssignmentData::getGroupID() const {
    return this->groupID;
}

string AssignmentData::getDescription() const {
    return this->description;
}

DateTime AssignmentData::getStartDate() const {
    return this->start;
}

DateTime AssignmentData::getendDate() const {
    return this->end;
}

int AssignmentData::getPossiblePoints() const {
    return this->possiblePoints;
}

int AssignmentData::getPoints() const {
    return this->points;
}