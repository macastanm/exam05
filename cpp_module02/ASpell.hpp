#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <string>
# include <iostream>
# include "ATarget.hpp"

class ATarget;

class ASpell {
    private:
        std::string _name;
        std::string _effects;
    
    public:
        ASpell();
        ASpell(ASpell const &copy);
        ASpell &operator=(ASpell const &src);
    
        ASpell(std::string const &name, std::string const &effects);
        virtual ~ASpell();

        std::string const &getName(void) const;
        std::string const &getEffects(void) const;

        virtual ASpell *clone() const = 0;

        void    launch(ATarget const &target);
};

#endif