#include "Set.h"
#include <sstream>

Set::Set(int size) :
	size{ size },
	//Inicializamos el vector, del tamaño especificado, de punteros bool a 'false'
	elements{ std::vector<std::shared_ptr<bool>>(size, std::make_shared<bool>(false)) }
{
	
}

Set::Set(int size, bool belongs) :
	size{ size },
	//Inicializamos el vector, del tamaño especificado, de punteros bool a el valor del parametro 
	//especificado en el constructor 'belongs'
	elements{ std::vector<std::shared_ptr<bool>>(size, std::make_shared<bool>(belongs)) }
{
	
}

Set::~Set()
{
	
}


bool Set::isEmpty() const
{
	//std::vector::empty comprueba si el vector esta vacio (std::vector::size = 0)
	if (elements.empty()) return true;
	else return false;
}

bool Set::isPart(int val) const
{
	if (val >= 1 && val <= Size()) return *elements.at(val - 1);
	else return false;
}

bool Set::isEqual(Set actualSet) const
{
	if (size == actualSet.Size()) {
		for (int i{ 0 }; i < size; i++) 
			if (elements.at(i) != actualSet.Elements().at(i)) return false;
		return true;
	}
	return false;
}

void Set::insert(int val)
{
	if (val >= 1 && val <= size && elements.at(val-1) == false ) elements.at(val - 1) = std::make_shared<bool>(true);
}

void Set::erase(int val)
{
	if (val >= 1 && val <= size && elements.at(val - 1) != false) elements.at(val - 1) = std::make_shared<bool>(false);
}

Set Set::add(Set addeSet)
{
	if (size == addeSet.Size()) {
		Set resultSet{ size };
		resultSet.Elements(elements);
		for (int i{ 1 }; i < size; i++)
			resultSet.insert(i);
		return resultSet;
	}
	else throw std::string("Los tamaños de los sets han de ser iguales");
}

Set Set::substract(Set subsSet)
{
	if (size == subsSet.Size()) {
		Set resultSet{ size };

		for (int i{ 1 }; i < size; i++)
			if (isPart(i) && !subsSet.isPart(i)) resultSet.insert(i);

		return resultSet;
	}
	else throw std::string("Los tamaños de los sets han de ser iguales");
}

Set Set::intersect(Set secondSet)
{
	if (size == secondSet.Size()) {
		Set resultSet{ size };

		for (int i{ 1 }; i <= size; i++)
			if (isPart(i) && secondSet.isPart(i)) resultSet.insert(i);
		
		return resultSet;
	}
	else throw std::string("Los tamaños de los sets han de ser iguales");
}

std::string Set::print(std::string s)
{
	std::stringstream ss;

	ss << s << "{";

	for (int i{ 0 }; i < size; i++) {
		if (elements.at(i)) ss << " " << (i + 1);
	}

	ss << "} \n";

	return ss.str();
}

