#include "Warlock.hpp"

Warlock::Warlock() { }

Warlock::Warlock(Warlock const &copy) {
    *this = copy;
}

Warlock &Warlock::operator=(Warlock const &src) {
    if (this != &src)
    {
        this->_name = src._name;
        this->_title = src._title;
    }
    return (*this);
}

Warlock::Warlock(std::string const &name, std::string const &title) {
    this->_name = name;
    this->_title = title;
    std::cout << _name << ": This looks like another boring day.\n";
}

Warlock::~Warlock() {
    std::cout << _name << ": My job here is done!\n";
    for (std::map<std::string, ASpell *>::iterator it = _mySpells.begin(); it != _mySpells.end(); it++) {
        delete it->second;
    }
    _mySpells.clear();
}

std::string const &Warlock::getName(void) const {
    return(this->_name);
}
std::string const &Warlock::getTitle(void) const {
    return(this->_title);
}
void    Warlock::setTitle(std::string const &title) {
    this->_title = title;
}

void    Warlock::introduce(void) const {
    std::cout << _name <<": I am " << _name << ", " << _title << "!\n";
}

void    Warlock::learnSpell(ASpell *spellToLearn) {
    if (spellToLearn)
    {
		_mySpells.insert(std::pair<std::string, ASpell *>(spellToLearn->getName(), spellToLearn->clone()));
    }
}

void   Warlock::forgetSpell(std::string spellName) {
    std::map<std::string, ASpell *>::iterator   it = _mySpells.find(spellName);
    if (it != _mySpells.end())
    {
        delete it->second;
        _mySpells.erase(it);
    }
}

void   Warlock::launchSpell(std::string spellName, const ATarget &taget) {
    std::map<std::string, ASpell *>::iterator   it = _mySpells.find(spellName);
    if (it != _mySpells.end())
    {
        it->second->launch(taget);
    }
}