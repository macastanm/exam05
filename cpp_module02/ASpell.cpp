#include "ASpell.hpp"

ASpell::ASpell() { }

ASpell::ASpell(ASpell const &copy) {
    *this = copy;
}

ASpell &ASpell::operator=(ASpell const &src) {
    if (this != &src)
    {
        this->_name = src._name;
        this->_effects = src._effects;
    }
    return (*this);
}

ASpell::ASpell(std::string const &name, std::string const &effects) {
    this->_name = name;
    this->_effects = effects;
}

ASpell::~ASpell() {}

std::string const &ASpell::getName(void) const {
    return(this->_name);
}

std::string const &ASpell::getEffects(void) const {
    return(this->_effects);
}

void    ASpell::launch(ATarget const &target) {
    target.getHitBySpell(*this);
}
