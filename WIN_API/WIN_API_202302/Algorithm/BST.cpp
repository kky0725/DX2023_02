#include "BST.h"
#include "iostream"

BinarySearchTree::BinarySearchTree()
{
}

BinarySearchTree::~BinarySearchTree()
{
}

void BinarySearchTree::Insert(int key)
{
	Node* newNode = new Node(key);

	if (_root == nullptr)
	{
		_root = newNode;
		return;
	}
	Node* node = _root;
	Node* parent = nullptr;

	while (true)
	{
		if (node == nullptr)
			break;

		parent = node;
		if (key < node->_key)
		{
			node = node->_left;
		}
		else
		{
			node = node->_right;
		}
	}

	newNode->_parent = parent;
	if (key < parent->_key)
		parent->_left = newNode;
	else
		parent->_right = newNode;
}

void BinarySearchTree::Replace(Node* node1, Node* node2)
{
	if (node1->_parent == nullptr)
		_root = node2;
	else if (node1 == node1->_parent->_left)
	{
		node1->_parent->_left = node2;
	}
	else
	{
		node1->_parent->_right = node2;
	}

	if (node2 != nullptr)
	{
		node2->_parent = node1->_parent;
	}

	delete node1;
}

void BinarySearchTree::Delete(Node* node)
{
	if (node == nullptr)
		return;

	if (node->_right == nullptr)
	{
		Replace(node, node->_left);
		return;
	}
	else if (node->_left == nullptr)
	{
		Replace(node, node->_right);
		return;
	}
	else
	{
		node->_key = Next(node)->_key;
		node->_data = Next(node)->_data;
		Delete(Next(node));
		return;
	}
}

void BinarySearchTree::PrintTree(Node* root)
{
	// 전위 순회 : 루트 ~ 왼쪽 ~ 오른쪽
	// 중위 순회 : 왼족 ~ 루트 ~ 오른쪽
	// 후위 순회 : 왼쪽 ~ 오른쪽 ~ 루트

	if (root == nullptr)
		return;
	PrintTree(root->_left);
	std::cout << root->_key << std::endl;
	PrintTree(root->_right);
}

Node* BinarySearchTree::Search(Node* root, int key)
{
	if (root == nullptr)
	{
		std::cout << key << "가 없습니다." << std::endl;
		return nullptr;
	}

	if (key == root->_key)
	{
		std::cout << key << "을/를 찾았습니다." << std::endl;
		return root;
	}

	if (key < root->_key)
		return Search(root->_left, key);
	else
		return Search(root->_right, key);


}

Node* BinarySearchTree::Min(Node* root)
{
	if (root == nullptr)
		return nullptr;

	if (root->_left == nullptr)
		return root;
	return Min(root->_left);
}

Node* BinarySearchTree::Max(Node* root)
{
	if (root == nullptr)
		return nullptr;

	if (root->_right == nullptr)
		return root;
	return Max(root->_right);

}

Node* BinarySearchTree::Previous(Node* root)
{
	if (root == nullptr || root->_left == nullptr)
		return nullptr;
	Node* node = root->_left;
	while (node->_right != nullptr)
	{
		node = node->_right;
	}

	return node;
}

Node* BinarySearchTree::Next(Node* root)
{
	if (root == nullptr || root->_right == nullptr)
		return nullptr;
	Node* node = root->_right;
	while (node->_left != nullptr)
	{
		node = node->_left;
	}

	return node;
}
