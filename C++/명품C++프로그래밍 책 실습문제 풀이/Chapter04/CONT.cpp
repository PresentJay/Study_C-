#include "CONT.h"

Container::Container() { fill(); }
void Container::fill() { size = 10; }
void Container::consume() { size--; }
int Container::getSize() { return size; }