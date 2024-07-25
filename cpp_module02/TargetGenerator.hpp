#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <string>
# include <iostream>
# include <map>
# include <vector>
# include "ATarget.hpp" 

class   TargetGenerator {
    private:
        std::map<std::string, ATarget *> _myTargets;

        TargetGenerator(TargetGenerator const &copy);
        TargetGenerator &operator=(TargetGenerator const &src);

    public:
        TargetGenerator();
        ~TargetGenerator();

        void    learnTargetType(ATarget *targetToLear);
        void    forgetTargetType(std::string const &targetName);
        ATarget  *createTarget(std::string const &targetName);
};

#endif