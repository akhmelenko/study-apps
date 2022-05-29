#include "Movie.h"
#include <string>
#include <iostream>


Movie::Movie()
{
    cout << "Movie raw ctor" << endl;
}

Movie::~Movie()
{
    cout << "Movie detor" << endl;
}

void Movie::SetName(std::string name_)
{
    name = name_;
}

void Movie::SetWatches(int watches_)
{
    watches = watches_;
}

void Movie::IncrementWatches()
{
    watches++;
}

std::string Movie::GetName() const
{
    return name;
}

int Movie::GetWatches() const
{
    return watches;
}
