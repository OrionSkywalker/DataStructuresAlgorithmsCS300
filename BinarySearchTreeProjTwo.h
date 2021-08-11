/*
 * BinarySearchTreeProjectTwo.h
 *
 *  Created on: Aug 10, 2021
 *      Author: RyanM
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstring>
using namespace std;
#ifndef BINARYSEARCHTREEPROJECTTWO_H_
#define BINARYSEARCHTREEPROJECTTWO_H_

//structures composed of courses. each course has a courseNum, courseName, and may or may not have prerequisites

struct Course{

	//variables for courses

	string courseNum;
	string courseName;
	string prerequ;

	//a default Course constructor sets each variable to the string "Void"

	Course(){
		courseNum = "Void";
		courseName = "Void";
		prerequ = "Void";
	}
};


//a structure that holds nodes. each node has a left and right pointer and holds a course structure as described above

struct Node{
	Course course;
	Node* left;
	Node* right;

	//default Node constructor, sets the right and left pointers to null

	Node(){
		left = nullptr;
		right = nullptr;
	}

	//overloaded constructor, if a Node is created with a course then its course will point to the course passed instead of the course initialized with void in all fields

	Node(Course aCourse) : Node(){
		this->course = aCourse;
	}
};

class BinarySearchTree{
private:
	Node* root;

	void addNode(Node* node, Course course);
	void inOrder(Node* node);

public:
	BinarySearchTree();
	virtual ~BinarySearchTree();
	void InOrder();
	void Insert(Course course);
	Course Search(string courseNum);
};

#endif

/* BINARYSEARCHTREEPROJECTTWO_H_ */
