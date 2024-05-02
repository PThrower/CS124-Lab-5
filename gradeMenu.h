/**
* Author: Parnell Thrower
* Description: Manage Tasks using Map, HashTable, and Try-Catch
* Due Date: 4/20/2024
*/


//
#pragma once
#include <fstream>
#include "menu.h"
#include <unordered_map>
using namespace std;

//const string TASK_DATA = "task_data.csv";
enum COMMAND {LIST='1', VIEW='2', ADD='3', EDIT = '4', REMOVE = '5', CALCULATE = '6', SAVE = '7', EXIT = 'x' };

class GradeMenu :public Menu {
public:
    GradeMenu();
    ~GradeMenu();

    void doList();
    void doView();
    void doAdd();
    void doEdit();
    void doRemove();
    void calculateGrade();
    void doSave();

    void activate();
    
protected:
    void init();
    void showOption(string title);

private:
    fstream inFile;
};