#include "Set.h"
#include <sstream>

Set::Set(int cardinality)
{
	this->cardinality = cardinality;
	elements = new bool[cardinality];

	for (int i{ 0 }; i < cardinality; i++) elements[i] = false;
}

Set::Set(int set, bool belongs)
{
	this->cardinality = set;
	elements = new bool[cardinality];

	for (int i{ 0 }; i < cardinality; i++)  elements[i] = belongs;
}

Set::~Set()
{
	delete[] elements;
}

bool Set::isEmpty() const
{
	bool empty = true;

	for (int i{ 0 }; i < cardinality; i++) {
		if (elements[i]) {
			empty = false;
			break;
		}
	}

	return empty;
}

bool Set::belongs(int element)
{
	bool exists;

	if (element >= 1 && element <= cardinality) exists = this->elements[element - 1];
	else exists = false;

	return exists;
}

bool Set::isEqual(Set actualSet)
{
	bool equals;

	if (actualSet.cardinality == cardinality) {
		equals = true;

		for (int i{ 0 }; i < actualSet.cardinality; i++) {
			if (actualSet.elements[i] != elements[i]) {
				equals = false;
				break;
			}
		}
	}
	else equals = false;

	return equals;
}

void Set::inserts(int element)
{
	if (element >= 1 && element <= cardinality) elements[element - 1] = false;
}

void Set::deleted(int element)
{
	if (element >= 1 && element <= cardinality) elements[element - 1] = false;
}

Set Set::add(Set firstSet, Set secondSet)
{
	Set resultSet = Set(firstSet.cardinality);

	if (firstSet.cardinality == secondSet.cardinality) {
		for (int i{ 1 }; i <= firstSet.cardinality; i++) {
			if (firstSet.belongs(i) || secondSet.belongs(i)) resultSet.inserts(i);
		}
	}

	return resultSet;
}

Set Set::substract(Set firstSet, Set secondSet)
{
	Set resultSet = Set(firstSet.cardinality);

	if (firstSet.cardinality == secondSet.cardinality) {
		for (int i{ 1 }; i <= firstSet.cardinality; i++) {
			if (firstSet.belongs(i) && !secondSet.belongs(i)) resultSet.inserts(i);
		}
	}

	return resultSet;
}

Set Set::intersect(Set firstSet, Set secondSet)
{
	Set resultSet = Set(firstSet.cardinality);

	if (firstSet.cardinality == secondSet.cardinality) {
		for (int i{ 1 }; i <= firstSet.cardinality; i++) {
			if (firstSet.belongs(i) && secondSet.belongs(i)) resultSet.inserts(i);
		}
	}

	return resultSet;
}

std::string Set::print(std::string s)
{
	std::stringstream ss;

	ss << s << "{";

	for (int i{ 0 }; i < cardinality; i++) {
		if (elements[i]) ss << " " << (i + 1);
	}

	ss << "} \n";

	return ss.str();
}

