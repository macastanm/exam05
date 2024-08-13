#include "SpellBook.hpp"

SpellBook::SpellBook() { }

SpellBook::SpellBook(SpellBook const &copy) {
    *this = copy;
}

SpellBook &SpellBook::operator=(SpellBook const &src) {
    if (this != &src)
    {
        this->_mySpells = src._mySpells;
    }
    return (*this);
}

SpellBook::~SpellBook() {
    for (std::map<std::string, ASpell *>::iterator it = _mySpells.begin(); it != _mySpells.end(); it++) {
        delete it->second;
    }
    _mySpells.clear();
}

void    SpellBook::learnSpell(ASpell *spellToLearn) {
    if (spellToLearn)
    {
		_mySpells.insert(std::pair<std::string, ASpell *>(spellToLearn->getName(), spellToLearn->clone()));
    }
}

void   SpellBook::forgetSpell(std::string const &spellName) {
    std::map<std::string, ASpell *>::iterator   it = _mySpells.find(spellName);
    if (it != _mySpells.end())
    {
        delete it->second;
        _mySpells.erase(it);
    }
}

ASpell   *SpellBook::creatSpell(std::string const &spellName) {
    std::map<std::string, ASpell *>::iterator   it = _mySpells.find(spellName);
    if (it != _mySpells.end())
    {
        return it->second->clone();
    }
    return NULL;
}