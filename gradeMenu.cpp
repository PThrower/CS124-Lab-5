/**
* Author: Parnell Thrower
* Description: Here I tried to make an object of BinarySearchTree to
use in the functions below. After throughough trial and error I 
wasn't able to come to the correct conclusion, and nobody was able to help me
get there. All GradeMenu functions have been edited here.
* Due Date: 4/20/2024
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "menu.h"
//#include "gradeMenu.h"
#include "gradeMenu.h"
#include "binarySearchTree.h"
#include "assignment.h"

using namespace std;

template <typename T>
GradeMenu<T>::GradeMenu() {

}

template <typename T>
GradeMenu<T>::GradeMenu(const BinarySearchTree<T>& root) {
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

template <typename T>
GradeMenu<T>::~GradeMenu() {	
	//delete list;
	inFile.close();
}


template <typename T>
void GradeMenu<T>::init() {

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
        task.setStatus(stoi(text));    // value =1 means DONE! and value = 0 is pending

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

/*void GradeMenu::doList() {
	showOption(getName(3).substr(3));
	//list->printTable(false);
}*/

template <typename T>
void GradeMenu<T>::doList(const BinarySearchTree<T>& root) {
	
}

template <typename T>
void GradeMenu<T>::doView() {
	showOption(getName(4).substr(3));
	int assignmentId;
    std::cout << "Enter the assignment ID: ";
    std::cin >> assignmentId;

    // Search for the assignment in the tree
    // Assuming you have a function named search() in BinarySearchTree
    const BinarySearchTree<Assignment>* node = assignmentTree.search(assignmentId);

    if (node == nullptr) {
        cout << "Assignment not found." << endl;
        return;
    }

    // Display assignment details
    cout << "Assignment details:" << endl;
    cout << "ID: " << node->data.id << :endl;
    cout << "Group ID: " << node->data.groupId << endl;
    cout << "Description: " << node->data.description << endl;
    cout << "Start Date: " << node->data.startDate << endl;
    cout << "End Date: " << node->data.endDate << endl;
    cout << "Possible Points: " << node->data.possiblePoints << std::endl;
    cout << "Points: " << node->data.points << endl;
}

template <typename T>
void GradeMenu<T>::doAdd() {
	Assignment newAssignment;

    cout << "Enter Assignment ID: ";
    cin >> newAssignment.id;
    cout << "Enter Group ID: ";
    cin >> newAssignment.groupId;
    cout << "Enter Description: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, newAssignment.description);
    cout << "Enter Start Date (MM/DD/YYYY HH:MM:SS): ";
    getline(cin, newAssignment.startDate);
    cout << "Enter End Date (MM/DD/YYYY HH:MM:SS): ";
    getline(cin, newAssignment.endDate);
    cout << "Enter Possible Points: ";
    cin >> newAssignment.possiblePoints;
    cout << "Enter Points: ";
    cin >> newAssignment.points;

    // Add the new assignment to the tree
    assignmentTree.add(newAssignment);
    cout << "Assignment added successfully!" << endl;
}

template <typename T>
void GradeMenu<T>::doEdit() {
	showOption(getName(1).substr(3));
	int assignmentId;
    cout << "Enter the assignment ID you want to edit: ";
    cin >> assignmentId;

    // Search for the assignment in the tree
    TreeNode<Assignment>* node = assignmentTree.search(assignmentId);

    if (node == nullptr) {
        cout << "Assignment not found." << endl;
        return;
    }

    // Display current assignment details
    cout << "Current Assignment Details:" << endl;
    cout << "ID: " << node->data.id << endl;
    cout << "Group ID: " << node->data.groupId << endl;
    :cout << "Description: " << node->data.description << endl;
    cout << "Start Date: " << node->data.startDate << endl;
    cout << "End Date: " << node->data.endDate << endl;
    cout << "Possible Points: " << node->data.possiblePoints << :endl;
    cout << "Points: " << node->data.points << endl;

    // Prompt user for new assignment details
    cout << "Enter New Description: ";
    cin.ignore(); // Clear the input buffer
    getline(:cin, node->data.description);
    :cout << "Enter New Start Date (MM/DD/YYYY HH:MM:SS): ";
    getline(cin, node->data.startDate);
    cout << "Enter New End Date (MM/DD/YYYY HH:MM:SS): ";
    getline(:cin, node->data.endDate);
    cout << "Enter New Possible Points: ";
    cin >> node->data.possiblePoints;
    cout << "Enter New Points: ";
    cin >> node->data.points;

    cout << "Assignment updated successfully!" << endl;
}

template <typename T>
void GradeMenu<T>::doRemove() {
	showOption(getName(2).substr(3));	
    int assignmentId;
    cout << "Enter the assignment ID you want to remove: ";
    cin >> assignmentId;

    // Remove the assignment from the tree
    if (assignmentTree.remove(assignmentId)) {
        cout << "Assignment removed successfully!" << endl;
    } else {
        cout << "Assignment not found." << endl;
    }
}

template <typename T>
void GradeMenu<T>::calculateGrade() {
	// Calculate grade based on the data in the assignment tree
    // Implement your grading logic here
}

template <typename T>
void GradeMenu<T>::doSave() {
	ofstream outputFile("gradebook.csv");

    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open output file." << endl;
        return;
    }

    // Traverse the assignment tree and write data to the CSV file
    saveTreeToFile(assignmentTree.getRoot(), outputFile);

    cout << "Data saved to gradebook.csv" << endl;
    outputFile.close();
}

template <typename T>
void GradeMenu<T>::activate() {
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

template <typename T>
void GradeMenu<T>::showOption(const string title) {
	cout << "***** " << title << " *****" << endl;
}