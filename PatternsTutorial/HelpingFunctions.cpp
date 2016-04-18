#include "HelpingFunctions.h"

int firstModifier(int x) {return x*2 + 1;}
int secondModifier(int x) {return 2*(x + 1);}
int (*modifiers[2])(int) = {&firstModifier, &secondModifier};
