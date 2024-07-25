#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() { }

TargetGenerator::TargetGenerator(TargetGenerator const &copy) {
    *this = copy;
}

TargetGenerator &TargetGenerator::operator=(TargetGenerator const &src) {
    if (this != &src)
    {
        this->_myTargets = src._myTargets;
    }
    return (*this);
}

TargetGenerator::~TargetGenerator() {
    _myTargets.clear();
}

void    TargetGenerator::learnTargetType(ATarget *targetToLear) {
    if (targetToLear)
    {
        _myTargets[targetToLear->getType()] = targetToLear;
    }
}

void   TargetGenerator::forgetTargetType(std::string const &targetName) {
    std::map<std::string, ATarget *>::iterator   it = _myTargets.find(targetName);
    if (it != _myTargets.end())
    {
        delete it->second;
        _myTargets.erase(it);
    }
}

ATarget   *TargetGenerator::createTarget(std::string const &targetName) {
    std::map<std::string, ATarget *>::iterator   it = _myTargets.find(targetName);
    if (it != _myTargets.end())
    {
        return it->second->clone();
    }
    return NULL;
}