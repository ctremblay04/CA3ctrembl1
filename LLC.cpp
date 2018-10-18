#include "LLC.h"

Node :: Node(){this->data = '\0'; this->next = NULL;}

Node :: Node(string s) {this->data = s; this->next = NULL;}

LLC :: LLC() {
	this->_head = new Node();
	this->_tail = new Node();
	this->_head->next = this->_tail;
}

LLC :: LLC(const LLC &obj) {
	this->cp(obj);
}

void LLC :: cp(const LLC &obj) {
	Node *curr = new Node();
	this->_head = curr;
	Node *temp = obj._head->next;
	while (temp != NULL) {
		Node *n = new Node(temp->data);
		curr->next = n;
		curr = curr->next;
		temp = temp->next;
	}
	this->_tail = curr;
	this->num = obj.num;	
}

void LLC :: operator=(const LLC &obj) {
	this->~LLC();
	this->cp(obj);
}

LLC :: ~LLC() {
	Node *a = this->_head;
	Node *b = this->_head->next;
	int i = 0;
	while (b) {
		delete a;
		a = b;
		b = b->next;
		i++;
	}
}

bool LLC :: contains(const string &str) {
	Node *temp = this->_head->next;
	while (temp != this->_tail) {
		if (str.compare(temp->data) == 0)
			return true;
		temp = temp->next;
	}
	return false;
}

bool LLC :: insert(const string &str) {
	Node *temp = this->_head;
	while (temp->next != this->_tail) {
		temp = temp->next;
	}
	Node *n = new Node(str);
	n->next = this->_tail;
	temp->next = n;
	this->num++;
	return true;
}

void LLC :: remove(const string &str) {
	Node *temp = this->_head;
	while (temp->next != this->_tail) {
		if (str.compare(temp->next->data) == 0) {
			Node *n = temp->next;
			temp->next = temp->next->next;
			delete n;
			this->num--;
		}
		else {
			temp = temp->next;
		}
	}
}

void LLC :: shuffle() {
	Node *nodes [this->num];
	Node *temp = this->_head->next;
	int i = 0;
	while (temp != this->_tail) {
		nodes[i] = temp;
		temp = temp->next;
		i++;
	}
	for (i = 0; i < this->num-1; i++) {
		int j = rand()%this->num;
		temp = nodes[i];
		nodes[i] = nodes[j];
		nodes[j] = temp;
	}
	for (i = 0; i < this->num-1; i++) {
		nodes[i]->next = nodes[i+1];
	}
	this->_head->next = nodes[0];
	nodes[this->num-1]->next = this->_tail;
	temp = this->_head;
}

LLC& LLC :: operator+(const LLC &obj) {
	LLC *retObj = new LLC(*this);
	Node *temp = retObj->_head;
	while (temp->next != retObj->_tail) {
		temp = temp->next;
	}
	Node *n = obj._head->next;
	while (n != obj._tail) {
		temp->next = new Node(n->data);
		temp = temp->next;
		n = n->next;
	}
	temp->next = retObj->_tail;
	retObj->num += obj.num;
	temp = retObj->_head;
	return *retObj;
}

void LLC :: head(int n) const{
	if (this->num == 0 or n == 0) {
		cout << "[]" << endl;
		return;
	}
	Node *temp = this->_head->next;
	cout << "[" << temp->data;
	temp = temp->next;
	n--;
	while (n > 0 and temp != this->_tail) {
		cout << ", " << temp->data;
		temp = temp->next;
		n--;		
	}
	cout << "]" << endl;
}

string LLC :: tail() const{
	Node *temp = this->_head->next;
	if (temp == this->_tail) {
		cout << endl;
		return NULL;
	}
	while (temp->next != this->_tail) {
		temp = temp->next;
	}
	cout << temp->data << endl;
	return temp->data;
}

ostream& operator<<(ostream &os, const LLC &obj) {
	obj.head(obj.num);
	return os;
}

void LLC :: operator+=(int p) {
	p %= this->num;
	if (p == 0) {return;}
	Node *temp = this->_head;
	Node *h = this->_head->next;
	int i = 0;
	while (temp->next != this->_tail) {
		if (i == p) {
			Node *n = temp->next;
			temp->next = this->_tail;
			this->_head->next = n;
			temp = n;
			i++;
		}
		else {
			temp = temp->next;
			i++;
		}
	}
	cout << temp->data << endl;
	temp->next = h;
}

void LLC :: join(LLC *obj) {
	if (obj->num == 0 or this->_head == obj->_head) {return;}
	Node *temp = this->_head;
	while (temp->next != this->_tail) {
		temp = temp->next;
	}
	temp->next = obj->_head->next;
	temp = temp->next;
	while (temp->next != obj->_tail) {
		temp = temp->next;
	}
	temp->next = this->_tail;
	obj->_head->next = obj->_tail;
	this->num += obj->num;
	obj->num = 0;
}

int LLC :: len() {
	return this->num;
}




