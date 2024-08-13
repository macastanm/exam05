#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"
#include <iostream>

int main() {
    // Test Warlock creation
    Warlock richard("Richard", "the Titled");

    // Test Dummy target creation
    Dummy bob;

    // Test Fwoosh spell creation
    Fwoosh* fwoosh = new Fwoosh();

    // Warlock learns Fwoosh spell
    richard.learnSpell(fwoosh);

    // Warlock introduces himself
    richard.introduce();

    // Warlock launches Fwoosh spell at Dummy
    richard.launchSpell("Fwoosh", bob);

    // Warlock tries to forget the Fwoosh spell
    richard.forgetSpell("Fwoosh");

    // Warlock tries to launch Fwoosh spell again (should do nothing)
    richard.launchSpell("Fwoosh", bob);

    // Edge case: Forgetting a spell that doesn't exist
    richard.forgetSpell("Fwoosh"); // Should do nothing

    // Edge case: Launching a spell that doesn't exist
    richard.launchSpell("NonExistentSpell", bob); // Should do nothing

    // Edge case: Learning and forgetting a spell multiple times
    richard.learnSpell(fwoosh);
    richard.learnSpell(fwoosh); // Learning the same spell twice
    richard.forgetSpell("Fwoosh");
    richard.forgetSpell("Fwoosh"); // Forgetting the same spell twice

    // Memory management: Delete dynamically allocated spell
    delete fwoosh;

    // Final output when the program ends
    return 0;
}
