/*
 * BinarySearchTreeProjectTwo.cpp
 *
 *  Created on: Aug 10, 2021
 *      Author: RyanM
 */

#include "BinarySearchTreeProjectTwo.h"




BinarySearchTree::BinarySearchTree(){
	root = nullptr;
}
BinarySearchTree::~BinarySearchTree(){

}
void BinarySearchTree::InOrder(){
	this->inOrder(root);
}
void BinarySearchTree::Insert(Course course){
	if(root == nullptr){
		root = new Node(course);
	}
	else{
		addNode(root,course);
	}
}
Course BinarySearchTree::Search(string courseNum) {

    // set current node equal to root
	Node* current = root;
    // keep looping downwards until bottom reached or matching bidId found
	while(current != nullptr){
        // if match found, return current bid
		if(current->course.courseNum.compare(courseNum) == 0){
			return current->course;
		}
		// if bid is smaller than current node then traverse left
		if(courseNum.compare(current->course.courseNum) < 0){
			current = current->left;
		}
		else{        // else larger so traverse right

			current = current->right;
		}
	}

	//a Course named course is created. This course is returned.
    Course course;
    return course;
}

void BinarySearchTree::addNode(Node* node, Course course) {
    // FIXME (8) Implement inserting a bid into the tree
    // if node is larger then add to left
	if(node->course.courseNum.compare(course.courseNum) > 0){ //string.compare(string) returns 0 if both strings match, <0 if first string smaller than second string, >0 if second string is greater
		 // if no left node
		if(node->left == nullptr){
            // this node becomes left
			node->left = new Node(course);
		}// else recurse down the left node
		else{
			addNode(node->left, course);
		}
	}//else node bid is larger
	else{
		if(node->right == nullptr){
		            // this node becomes right
					node->right = new Node(course);
				}// else recurse down the left node
				else{
					addNode(node->right, course);
				}
	}



}

void BinarySearchTree::inOrder(Node* node) {

      //if node is not equal to null ptr, begin traversing the tree
	if(root != nullptr){

		//if node to the left is populated
		if(node->left != nullptr){

			/*call inOrder recursively with the left value as the node,
			this keeps happening until the left node is empty and we have
			arrived at the lowest value in the tree.
			 */

			inOrder(node->left);
		}

		//we have arrived at the lowest value in the tree, print it
		cout << node->course.courseNum << ", " << node->course.courseName << endl;

		//if node to the right isn't empty go right
		if(node->right!=nullptr){
			/*Have visited the lowest values. Need to get the values on the right with this.
			  This recursive call happens after each value is printed. Once no more values
			  to the right, done traversing the tree.
			*/
			inOrder(node->right);
		}
	}
}

