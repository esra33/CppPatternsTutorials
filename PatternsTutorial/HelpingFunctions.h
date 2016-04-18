#ifndef HelpingFunctions_h
#define HelpingFunctions_h

#ifdef _WIN32
#pragma once
#endif

int firstModifier(int x);
int secondModifier(int x);
extern int (*modifiers[2])(int);

#endif