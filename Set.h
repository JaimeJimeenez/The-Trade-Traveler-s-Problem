#pragma once
#include <iostream>

class Set
{
public:

	Set(int);
	Set(int, bool);
	~Set();

	bool isEmpty() const;
	bool belongs(int);
	bool isEqual(Set);

	void inserts(int);
	void deleted(int);

	static Set add(Set, Set);
	static Set substract(Set, Set);
	static Set intersect(Set, Set);

	std::string print(std::string);

private:

	int cardinality;
	bool* elements;

};

