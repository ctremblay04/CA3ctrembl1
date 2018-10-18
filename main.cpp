#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "LLC.h"
using namespace std;

int main(int argc, char *argv[]) {
	cout << "#1) Testing default constructor by making LLC test0" << endl;
	LLC test0 = LLC();
	cout << "\t#1 Success\n\n#2) Testing insert method by populating test0 with values:" << endl;
	cout << "1) \"poo\"\n2) \"god\"\n3) \"joe\"\n4) \"cait\"\n5) \"john\"\n6) \"connor\"\n7) \"meg\"\n8) \"bridget\"\n9) \"kevin\"" << endl;
	if (
	test0.insert("poo") and
	test0.insert("god") and
	test0.insert("joe") and
	test0.insert("cait") and
	test0.insert("john") and
	test0.insert("connor") and
	test0.insert("meg") and
	test0.insert("bridget") and
	test0.insert("kevin")) {
		cout << "\t#2 Success\n" << endl;
	}
	else {
		cout << "\t#2 Failure\n" << endl;
	}	
	cout << "#3) Testing copy constructor by copying test0 into LLC test1" << endl;
	LLC test1 = LLC(test0);
	cout << "\t#3 Success\n\n#4) Testing assignment operator = to copy test1 into LLC test2" << endl;
	LLC test2 = test1;
	cout << "\t#4 Success\n\nCreating LLC *test3 to test destructor using copy constructor and test0" << endl;
	LLC *test3 = new LLC(test0);
	cout << "#5) Testing destructor ~ to destroy test3" << endl;
	delete test3;
	cout << "\t#5 Success\n\n#6) Testing contains(str) by checking if test0 holds value \"kevin\" and not value \"dog\"" << endl;
	if (test0.contains("kevin") and not test0.contains("dog")) {
		cout << "\t#6 Success\n" << endl;
	}
	else {
		cout << "\t#6 Failure\n" << endl;
	}
	cout << "#7) Testing remove(str) method by removing \"poo\" from test0" << endl;
	test0.remove("poo");
	cout << "\t#7 Success\n\n#8) Testing shuffle() method on test0" << endl;
	test0.shuffle();
	cout << "\t#8 Success\n\n#9) Testing operator + to assign test2 to test0+test1" << endl;
	test2 = test0+test1;
	cout << "\t#9 Success\n\n#10) Testing head() to output the first 10 values of test2" << endl;
	test2.head(10);
	cout << "\t#10 Success\n\n#11) Testing tail() to output the last value of test2" << endl;
	test2.tail();
	cout << "\t#11 Success\n\n#12) Testing << to output test1" << endl;
	cout << test1;
	cout << "\t#12 Success\n\n#13) Testing += to shift test1 5 places" << endl;
	test1 += 5;
	cout << test1;
	cout << "\t#13 Success\n\n#14) Testing len() to find len of test1" << endl;
	cout << test1.len() << endl;
	cout << "\t#14 Success\n\n#15) Testing join() to join test1 to test0" << endl;
	test0.join(&test1);
	cout << "test0: " << test0;
	cout << "test1: " << test1;
	cout << "\t#15 Success" << endl;

	
}
