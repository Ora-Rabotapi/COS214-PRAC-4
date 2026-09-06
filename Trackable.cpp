#include "Trackable.h"

Trackable::~Trackable() = default;

long Trackable::getModCount() const
{
    return modCount_;
}

void Trackable::bumpModCount()
{
    ++modCount_;
}