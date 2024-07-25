#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <string>
# include <iostream>

class   Warlock {
    private:
        std::string _name;
        std::string _title;
    
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
};

#endif