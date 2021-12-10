#include "BSTree.h"
#include "BSTNode.h"

BSTree::BSTree()
{
	rootNode = nullptr;
}

BSTree::~BSTree()
{
	//implement destructor
	if (rootNode) {
		delete rootNode->getLeftChild();
		delete rootNode->getRightChild();
		delete rootNode;
	}
}

int countHeight(BSTNode *start)
{
	if (nullptr == start)
	{
		return -1;
	}
	else
	{
		int ld = countHeight(start->getLeftChild());
		int rd = countHeight(start->getRightChild());
		
		return max(ld, rd) + 1;
	}
}

int BSTree::getHeight() const
{
	return countHeight(rootNode);
}

int countNodes(BSTNode* start)
{
	if (nullptr == start)
	{
		return 0;
	}
	else
	{
		return 1 + countNodes(start->getLeftChild()) + countNodes(start->getRightChild());
	}
}

int BSTree::getNumNodes() const

{
	return countNodes(rootNode);
}

void preorder(BSTNode* node, string& line, string& result) {
	for (int i = 0; i < line.size(); i++) {
		if (i != 0) {
			result += ">";
		}
		result += line[i];
	}
	if (node == nullptr) {
		result += ">[NULL]\n";
		line = line.substr(0, line.size() - 1);
		return;
	}
	result += ">" + node->getKey() + '\n';

	line += "l";
	preorder(node->getLeftChild(), line, result);

	line += "r";
	preorder(node->getRightChild(), line, result);

	line = line.substr(0, line.size() - 1);
}

string BSTree::getRepresentation()
{
	//implement function
	string line = "";
	string result = "";
	preorder(rootNode, line, result);
	result = result.substr(0, result.size() - 1);
	return result;
}

BSTNode* BSTree::getNode(string key)
{
	//implement function
	BSTNode* currNode = rootNode;
	while (currNode != nullptr) {
		if (currNode->getKey().compare(key) > 0)
			currNode = currNode->getLeftChild();
		else if (currNode->getKey().compare(key) < 0)
			currNode = currNode->getRightChild();	
		else
			return currNode;
	}
	return nullptr;
}


bool BSTree::addNode(string key)
{
	BSTNode* newNode = new BSTNode(key);
	addNode(newNode);
	return true;
}

bool BSTree::addNode(BSTNode* item)
{
	//implement function
	if (rootNode == nullptr) {
		rootNode = item;
		return true;
	} else {
		BSTNode* currNode = rootNode;
		while (currNode != nullptr) {
			if (currNode->getKey().compare(item->getKey()) > 0) {
				if (currNode->getLeftChild() == nullptr) {
					currNode->setLeftChild(item);
				} else {
					currNode = currNode->getLeftChild();
				}
			} else if (currNode->getKey().compare(item->getKey()) < 0) {
				if (currNode->getRightChild() == nullptr) {
					currNode->setRightChild(item);
				} else {
					currNode = currNode->getRightChild();
				}
			} else {
				return false;
			}
		}
		return true;
	}
}
