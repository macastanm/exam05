#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <string>
# include <iostream>
# include <map>
# include "ASpell.hpp" 

class   SpellBook {
    private:
        std::map<std::string, ASpell *> _mySpells;

        SpellBook(SpellBook const &copy);
        SpellBook &operator=(SpellBook const &src);

    public:
        SpellBook();
        ~SpellBook();

        void    learnSpell(ASpell *spellToLearn);
        void    forgetSpell(std::string const &spellName);
        ASpell  *creatSpell(std::string const &spellName);
};

#endif