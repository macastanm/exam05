#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <string>
# include <iostream>
# include "ASpell.hpp"

class   ASpell;

class ATarget {
    private: 
        std::string _type;
    
    public:
        ATarget();
        ATarget(ATarget const &copy);
        ATarget &operator=(ATarget const &src);
    
        ATarget(std::string const &type);
        virtual ~ATarget();

        std::string const &getType(void) const;

        virtual ATarget *clone() const = 0;

        void    getHitBySpell(ASpell const &spell) const;
};

#endif