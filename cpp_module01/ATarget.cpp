#include "ATarget.hpp"

ATarget::ATarget() { }

ATarget::ATarget(ATarget const &copy) {
    *this = copy;
}

ATarget &ATarget::operator=(ATarget const &src) {
    if (this != &src)
    {
        this->_type = src._type;
    }
    return (*this);
}

ATarget::ATarget(std::string const &type) {
    this->_type = type;
}

ATarget::~ATarget() {}

std::string const &ATarget::getType(void) const {
    return(this->_type);
}

void    ATarget::getHitBySpell(ASpell const &spell) const {
    std::cout << _type << " has been " << spell.getEffects() << "!\n";
}