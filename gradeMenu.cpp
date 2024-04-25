/**
* Author: Parnell Thrower
* Description: Manage Tasks using Map, HashTable, and Try-Catch
* Due Date: 4/20/2024
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "menu.h"
//#include "gradeMenu.h"
#include "gradeMenu.h"

using namespace std;

GradeMenu::GradeMenu() {
	addOption("1) List");
	addOption("2) View");
	addOption("3) Add");
	addOption("4) Edit");
	addOption("5) Remove");
	addOption("6) Calculate Grade");
	addOption("7) Save");
	addOption("x) Exit");

	//list = new TaskList();
	init();
}
GradeMenu::~GradeMenu() {	
	//delete list;
	inFile.close();
}

void GradeMenu::init() {

}

/*void GradeMenu::init() {
    inFile.open(TASK_DATA);

    string text;
    string line = "";
    bool firstRow = true;
    while (getline(inFile, line)) {
        // Skip the first row
        if (firstRow) {
            firstRow = false;
            continue;
        }
        stringstream ss(line);
        //Task task;
        getline(ss, text, ',');
        //task.setTerm(text);
        getline(ss, text, ',');
        //task.setName(text);
        getline(ss, text, ',');
        //task.setStartDate(text);
        getline(ss, text, ',');
       // task.setEndDate(text);
        getline(ss, text, ',');
        //task.setStatus(stoi(text));    // value =1 means DONE! and value = 0 is pending

        // Add the task to the map
        //tasks.insert({task.getName(), task});
    }
    inFile.close();
}*/

/*void TaskMenu::init() {
	inFile.open(TASK_DATA);

	string text;
	string line = "";
	bool firstRow = true;
	while (getline(inFile, line)) {
		// Skip the first row
		if (firstRow) {
			firstRow = false;
			continue;
		}
		stringstream ss(line);		
		Task task;
		getline(ss, text, ',');
		task.setTerm(text);
		getline(ss, text, ',');
		task.setName(text);
		getline(ss, text, ',');
		task.setStartDate(text);
		getline(ss, text, ',');
		task.setEndDate(text);
		getline(ss, text, ',');
		task.setStatus(stoi(text));	// value =1 means DONE! and value = 0 is pending
		list->push(task);
	}
	inFile.close();
}*/

void GradeMenu::doList() {
	showOption(getName(3).substr(3));
	//list->printTable(false);
}

void GradeMenu::doView() {
	showOption(getName(4).substr(3));
	//list->printTable(true);
}

void GradeMenu::doAdd() {
	showOption(getName(0).substr(3));
	//list->addNew();
	cout << endl;
}

void GradeMenu::doEdit() {
	showOption(getName(1).substr(3));
	//list->editTask();
	cout << endl;
}

void GradeMenu::doRemove() {
	showOption(getName(2).substr(3));	
	//list->deleteTask();
	cout << endl;
}

void GradeMenu::calculateGrade() {

}

void GradeMenu::doSave() {

}

void GradeMenu::activate() {
	char command = COMMAND::ADD;
	while (command != EXIT) {
		command = doMenuOption();
		switch (command) {		
		case LIST:
			doList();
			break;
		case VIEW:
			doView();
			break;
		case ADD:
			doAdd();
			break;
		case EDIT:
			doEdit();
			break;
		case REMOVE:
			doRemove();
			break;
		case CALCULATE:
			calculateGrade();
			break;
		case SAVE:
			doSave();
			break;
		case EXIT:
			cout << "Bye!" << endl;
			break;
		default:
			cout << "Not a valid command. Please try again." << endl << endl;
			break;
		}
	}	
}

void GradeMenu::showOption(const string title) {
	cout << "***** " << title << " *****" << endl;
}