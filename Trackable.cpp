#include "Trackable.h"

Trackable::~Trackable() = default;

long Trackable::getModCount() const
{
    return modCount;
}

void Trackable::bumpModCount()
{
    ++modCount;
}