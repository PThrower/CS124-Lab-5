#pragma once

#include <iostream>
#include "dateTime.h"

using namespace std;

class AssignmentData : public DateTime{
public:
    AssignmentData();
    ~AssignmentData();
    void setID(int id);
    void setGroupID(int groupID);
    void setDescription(string description);
    void setStartDate(DateTime start);
    void setEndDate(DateTime end);
    void setPossiblePoints(int possiblePoints);
    string setPoints(int points);

    int getID() const;
    int getGroupID() const;
    string getDescription() const;
    DateTime getStartDate() const;
    DateTime getendDate() const;
    int getPossiblePoints() const;
    string getPoints() const;
    
private:
    DateTime start;
    DateTime end;

    int id, groupID;
    string description, possiblePoints, points;
};