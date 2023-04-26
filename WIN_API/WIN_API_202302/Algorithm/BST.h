#pragma once

struct Node
{
	Node() {}
	Node(int key) : _key(key) {}

	Node* _left = nullptr;
	Node* _right = nullptr;
	Node* _parent = nullptr;

	int _key = -1;
	int _data = 0;
};

class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();

	void Insert(int key);
	
	void Delete(Node* Node); // 해당노드 삭제
	void PrintTree(Node* root);

	Node* Search(Node* root, int key);
	Node* Min(Node* root);
	Node* Max(Node* Root);

	Node* Previous(Node* root);
	Node* Next(Node* root);

public:
	Node* _root = nullptr;

private:
	void Replace(Node* node1, Node* node2); // node1은 교체 후 삭제

};