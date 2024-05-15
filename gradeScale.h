#pragma once

#include <iostream>

using namespace std;

class GradeScale {
public:
    GradeScale();
    ~GradeScale();

    void setGroupID(int id);
    void setSection(string section);
    void setDescription(string description);
    void setWeight(string description, int weight);

    int getGroupID() const;
    string getSection() const;
    string getDescription() const;
    int getWeight() const;

private:
    int id, weight;
    string section, description;
};