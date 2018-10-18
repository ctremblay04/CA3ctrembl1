#ifndef LLC_H
#define LLC_H

#include <string>
#include <iostream>

using namespace std;

struct Node {
	string data;
	Node *next;
	Node();
	Node(string s);
};

class LLC {
	public:
		LLC();
		LLC(const LLC &obj);
		~LLC();
		bool contains(const string &str);
		bool insert(const string &str);
		void remove(const string &str);
		void shuffle();
		LLC& operator+(const LLC &obj);
		void operator+=(int p);
		void operator=(const LLC &obj);
		void join(LLC *obj);
		void head(int n) const;
		string tail() const;
		int len();
		friend ostream& operator<<(ostream& os, const LLC &obj);
	private:
		Node *_head = NULL;
		Node *_tail = NULL;
		int num = 0;
		void cp(const LLC &obj);
};
#endif
