#include "Warlock.hpp"
#include "BrickWall.hpp"
#include "Dummy.hpp"
#include "Fireball.hpp"
#include "Fwoosh.hpp"
#include "Polymorph.hpp"
#include "TargetGenerator.hpp"

int main()
{
    // Warlock and target generator creation
    Warlock richard("Richard", "the Tester");
    TargetGenerator tarGen;

    // Creating spells and targets
    Polymorph* polymorph = new Polymorph();
    Fireball* fireball = new Fireball();
    Fwoosh* fwoosh = new Fwoosh();
    BrickWall model1;
    Dummy dummy;

    // Learn and forget sequence
    richard.learnSpell(polymorph);
    richard.learnSpell(fwoosh);
    richard.learnSpell(fireball);
    richard.learnSpell(fireball);  // Learning the same spell twice

    tarGen.learnTargetType(&model1);
    tarGen.learnTargetType(&dummy);

    // Attempt to launch spells before learning
    ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");
    ATarget* practiceDummy = tarGen.createTarget("Target Practice Dummy");
    ATarget* nonExistentTarget = tarGen.createTarget("Nonexistent Target");

    richard.launchSpell("Polymorph", *wall);
    richard.launchSpell("Fwoosh", *practiceDummy);
    richard.launchSpell("Fireball", *wall);
    richard.launchSpell("Nonexistent Spell", *wall); // Launching a non-existent spell
    richard.launchSpell("Polymorph", *nonExistentTarget); // Launching at a non-existent target

    // Forgetting spells
    richard.forgetSpell("Polymorph");
    richard.forgetSpell("Fwoosh");
    richard.forgetSpell("Fireball");
    richard.forgetSpell("Fireball");  // Forgetting the same spell twice

    // Re-attempt to launch forgotten spells
    richard.launchSpell("Polymorph", *wall);
    richard.launchSpell("Fwoosh", *practiceDummy);
    richard.launchSpell("Fireball", *wall);

    // Cleanup
    delete polymorph;
    delete fireball;
    delete fwoosh;

    return 0;
}
