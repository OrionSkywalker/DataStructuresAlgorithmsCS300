//============================================================================
// Name        : DataStructuresAlgorithmsProj2.cpp
// Author      : Ryan M
// Version     : 0.1
// Copyright   : None
// Description : Sink or Swim
//============================================================================

#include "BinarySearchTreeProjectTwo.h"

int main() {
	//the variables and assignments that are used are defined here
	BinarySearchTree* bst;
	bst = new BinarySearchTree();
	Course course;
	int choice = 0;
	string searchTerm;
	string tempName;
	string fileName;
	string line;
	ifstream input;
	bool loopRelay = true;
	fileName = "";

	while(loopRelay){//this keeps the menu looping until the loopRelay is set to false
		cout << "\n";
		cout << "Welcome to the course planner.\n\n\n";
		cout << "==============================\n";
		cout << "1. Load Data Structure.\n";
		cout << "2. Print Course List.\n";
		cout << "3. Print Course.\n";
		cout << "4. Exit\n\n\n";
		cout << "What would you like to do?\n";

		try{//try block to make sure the input makes sense. If not, close the program.

			cin >> choice;

			if(cin.fail()){
			throw runtime_error("Input failed.");
			}
		}

		catch(runtime_error& excpt){
			loopRelay = false;
			cout << excpt.what();
		}

		switch (choice){
		case 1:

			cout << "Enter the file exactly as \"courseData.csv\" otherwise you must have your own file.\n";
			cout << "File format should be csv with form: \n";
			cout << "course identifier, course name, prerequisite#1,...,prerequisite#n.\n\n\n";
			cout << "Please enter the name of the file you would like to open:\n";
			cin >> fileName;
			cout << "You entered: " << fileName <<"\n";

			input.open(fileName);

			if(!input.is_open()){
			cout << "File opening failed!\n";
			loopRelay = false;
			}

			while(getline(input,line)){

				//these are input string names, no relation to the actual course values.

				string courseNum;
				string courseName;
				string prerequ;

				//create a stringstream to read the comma separated values

				stringstream ss(line);

				//instantiate a course object to act as a placeholder while the values are read. this course will be populated and pushed into the bst.

				Course course;

				getline(ss,courseNum,',');
				course.courseNum = courseNum;

				getline(ss,courseName,',');
				course.courseName = courseName;

				getline(ss,prerequ);
				course.prerequ=prerequ;

				//store the course structs in a binary search tree

				bst->Insert(course);
			}//end of while loop reading file

			//done using input so close it

			input.close();
			break;//end of case 1

			case 2:
				cout << "Printing courses in order.\n\n";
				cout << "=====================================\n";

				bst->InOrder();

				cout << "=====================================\n";
			break;//end of case 2

			case 3:{

				cout << "What is the course identifier?\n";
				cout << "Please enter a value like: CSCI100\n";
				cout << "Enter your search term: \n";

				cin >> searchTerm;

				//loop through searchTerm and capitalize everything because the file data is capitalized

				for (unsigned int i = 0; i<searchTerm.size(); i++){
					searchTerm[i]=toupper(searchTerm[i]);
				}
				cout << "Search term was: " << searchTerm << "\n";

				//assign a temporary course to hold the search value, had errors while using initially. Using brackets for the case solved the issue.

				Course temp = bst->Search(searchTerm);

				//print out the information requested. If nothing found "void" will print for all values

				cout << temp.courseNum << ", " << temp.courseName << "\n";
				cout << "Prerequisites: " << temp.prerequ << "\n";

				break;//end of case 3
			}

			case 4:
			{
				cout << "Goodbye.\n";

				return 1;//end of case 4, exit program
			}




		}//switch parentheses end

	}//end while loop operating on loopRelay

	return 0;
}
