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
    _mySpellBook.learnSpell(spellToLearn);
}

void   Warlock::forgetSpell(std::string spellName) {
    _mySpellBook.forgetSpell(spellName);
}

void   Warlock::launchSpell(std::string spellName, const ATarget &taget) {
    ATarget const *test = 0;
    if (test == &taget)
        return;

    ASpell *temp = _mySpellBook.creatSpell(spellName);
    if (temp)
        temp->launch(taget);
}