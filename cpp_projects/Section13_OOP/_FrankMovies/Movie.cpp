#include "Movie.h"
#include <string>
#include <iostream>

//ctor
Movie::Movie()
{
    cout << "Movie raw ctor" << endl;
}
//copy ctor
Movie::Movie(const Movie &src)
{
    name = src.name;
    watches = src.watches;
    cout << "Copy ctor for " << name << endl;
}
//init ctor
Movie::Movie(std::string name_, int watches_)
{
    this->name = name_;
    this->watches = watches_;
    cout << "Init ctor for " << name << endl;
}
/*//move constructor
Movie::Movie(Movie &&src) noexcept
    :Movie(src.name, src.watches)
{
    
}*/
//detor
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
