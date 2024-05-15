/**
* Author: Parnell Thrower
* Description: GradeBook mimic Program
* Due Date: 4/20/2024
*/

#include <iostream>
#include <iomanip>
//#include "gradeMenu.h"
#include "gradeMenu.h"
#include "binarySearchTree.h"
#include "assignment.h"

using namespace std;

void showBanner();

int main() {
	BinarySearchTree<AssignmentData> bst;
    bst.populateTree();
	showBanner();
	GradeMenu menu;
	menu.activate();
	return 0;
}

/**
 * showBanner - print me first
 **/
void showBanner() {
	const char originalFill = cout.fill();
	cout << setfill('*') << setw(50) << "*" << endl << endl;
	cout << "\tApplication to Mimic Grade Book using B-Trees" << endl;
	cout << "\t===========================" << endl;
	cout << "\tProgram written by: Parnell Thrower"<< endl;
	cout << "\tCourse info: CS-124-03" << endl;
	cout << "\tDue date: 4/20/2024"<< endl << endl;
	cout << setfill('*') << setw(50) << "*" << endl << endl;
	cout.fill(originalFill);
}