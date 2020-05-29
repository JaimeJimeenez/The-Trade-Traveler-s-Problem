#pragma once
#include <iostream>
#include <memory>
#include <vector>

class Set
{
public:

	Set(int size);
	Set(int set, bool belongs);
	~Set();

	bool isEmpty() const;
	bool isPart(int val) const;
	bool isEqual(const Set& actualSet) const;

	void insert(int val);
	void erase(int val);

	Set add(const Set& addeSet);
	Set substract(const Set& subsSet);
	Set intersect(const Set& secondSet);

	std::string print(const std::string& s);

	int Size() const { return size; };
	std::vector<std::shared_ptr<bool>> Elements() const { return elements; };
	void Elements(const std::vector<std::shared_ptr<bool>>& val) { elements = val; };

private:

	int size;
	std::vector<std::shared_ptr<bool>> elements;
};

