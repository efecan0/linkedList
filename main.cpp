#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;

	Node()
	{
		data = 0;
		next = NULL;
	}

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

class Linkedlist {
	Node* head;

public:
	Linkedlist() { head = NULL; }

	void insertNode(int);

	void printList();

	void deleteNode(int);
};

void Linkedlist::deleteNode(int node)
{
	Node* p = head;
	Node* last = new Node();

	if ( head -> data == node) 
	{
		head = head->next;
		cout << p->data << " deleted" << '\n';

		delete p;
		return;
	}

	while (p != NULL)
	{
		if (node == p->data)
			break;
		last = p;
		p = p->next;
	}
	
	if (p != NULL)
	{
		if (last == NULL)
		{
			head = head->next;
		}
		else
		{
			last->next = p->next;
		}

		cout << p ->data  << " deleted" << '\n';
		delete p;
	}
	else
		cout << "p null";
}

void Linkedlist::insertNode(int data)
{
	Node* newNode = new Node(data);

	if (head == NULL) {
		head = newNode;
		return;
	}

	Node* temp = head;
	while (temp->next != NULL) {

		temp = temp->next;
	}

	temp->next = newNode;
}

void Linkedlist::printList()
{
	Node* temp = head;

	if (head == NULL) {
		cout << "List empty" << endl;
		return;
	}

	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int main()
{
	Linkedlist list;

	list.insertNode(1);
	list.insertNode(2);
	list.insertNode(45);
	list.insertNode(22);
	list.insertNode(55);
	list.insertNode(3);
	list.insertNode(4);

	cout << "Elements of the list are: ";

	list.printList();
	cout << endl;

	list.deleteNode(55);
	list.deleteNode(1);
	cout << "Elements of the list are: ";
	list.printList();
	cout << endl;
	
	return 0;
}
