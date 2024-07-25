#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <string>
# include <iostream>
# include <map>
# include "ASpell.hpp"
# include "ATarget.hpp"

class   ATarget;
class   ASpell;

class   Warlock {
    private:
        std::string _name;
        std::string _title;
    
        std::map<std::string, ASpell*>  _mySpells;

        Warlock();
        Warlock(Warlock const &copy);
        Warlock &operator=(Warlock const &src);

    public:
        Warlock(std::string const &name, std::string const &title);
        ~Warlock();

        std::string const &getName(void) const;
        std::string const &getTitle(void) const;
        void    setTitle(std::string const &title);
        void    introduce(void) const;
        
        void    learnSpell(ASpell *spellToLearn);
        void    forgetSpell(std::string spellName);
        void    launchSpell(std::string spellName, const ATarget &taget);
};

#endif