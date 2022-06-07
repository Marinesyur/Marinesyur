#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node {
	int info;
	Node* left = nullptr;
	Node* right = nullptr;
};

//1 version

void add(Node*& node, int value) {
	if (node == nullptr) {
		node = new Node{ value, nullptr, nullptr };
		return;
	}

	if (value <= node->info)
		add(node->left, value);
	else
		add(node->right, value);
}

void print_by_ascending(const Node* node) {
	if (node == nullptr)
		return;

	print_by_ascending(node->left);
	cout << node->info << ' ';
	print_by_ascending(node->right);
}

void print_by_descending(const Node* node) {
	if (node == nullptr)
		return;

	print_by_descending(node->right);
	cout << node->info << ' ';
	print_by_descending(node->left);
}

void read(Node*& root) {
	while (true) {
		cout << "Do you wanna add new node? [y/n]" << endl;
		char symbol;
		cin >> symbol;

		if (symbol == 'y') {
			int value;

			cout << "Enter value: ";
			cin >> value;

			add(root, value);
		}
		else if (symbol == 'n')
			break;
		else
			cout << "Incorrect symbol, try again!" << endl;

		cout << endl;
	}

}

void clear(Node*& node) {
	if (node == nullptr)
		return;

	clear(node->left);
	clear(node->right); 

	delete node;

	node = nullptr;
}

int main() {
	Node* root = nullptr;
	read(root);
	cout << endl;

	cout << "Print by ascending: " << endl;
	print_by_ascending(root);
	cout << endl;

	cout << "Print by descending: " << endl;
	print_by_descending(root);
	cout << endl;

	clear(root);

	return 0;
}


//2 version
/*
Node* add(Node* node, int value) {
	if (node == nullptr) 
		return new Node{ value, nullptr, nullptr };

	if (value <= node->info)
		node->left = add(node->left, value);
	else
		node->right = add(node->right, value);

	return node;
}

void print_by_ascending(const Node* node) {
	if (node == nullptr)
		return;

	print_by_ascending(node->left);
	cout << node->info << ' ';
	print_by_ascending(node->right);
}

void print_by_descending(const Node* node) {
	if (node == nullptr)
		return;

	print_by_descending(node->right);
	cout << node->info << ' ';
	print_by_descending(node->left);
}

Node* read() {
	Node* root = nullptr;

	while (true) {
		cout << "Do you wanna add new node? [y/n]" << endl;
		char symbol;
		cin >> symbol;

		if (symbol == 'y') {
			int value;

			cout << "Enter value: ";
			cin >> value;

			root = add(root, value);
		}
		else if (symbol == 'n')
			break;
		else
			cout << "Incorrect symbol, try again!" << endl;

		cout << endl;
	}

	return root;
}

Node* clear(Node* node) {
	if (node == nullptr)
		return;

	clear(node->left); // node->left = clear(node->left);
	clear(node->right); // node->right = clear(node->right);

	delete node;

	return nullptr;
}

int main() {
	Node* root = read();
	cout << endl;

	cout << "Print by ascending: " << endl;
	print_by_ascending(root);
	cout << endl;

	cout << "Print by descending: " << endl;
	print_by_descending(root);
	cout << endl;

	root = clear(root);

	return 0;
}
*/