#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)  {
	return ;
};

Weapon::~Weapon(){};

const	std::string& Weapon::getType() {
	return this->type;
}

void	Weapon::setType(std::string new_type) {
	this->type = new_type;
}