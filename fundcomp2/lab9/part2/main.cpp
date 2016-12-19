//David Durkin
//main driver function

#include "Node.h"
#include "BinaryTree.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>

int main(){

	BinaryTree binary;
	binary.makeNodes();
	int j = 0;
	binary.buildTree();
	binary.postOrder(binary.getRoot());

}