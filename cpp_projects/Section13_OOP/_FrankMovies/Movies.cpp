#include "Movies.h"
#include "Movie.h"
#include <iostream>


//named ctor
Movies::Movies(std::string name)
    :collectionName{name}
{
    cout << "====" << name << " collection created" << endl;
}
//copy ctor
Movies::Movies(std::string name, const Movies &src)    
    :Movies(name)
{
    this->collection = src.collection;
    cout << "Movies copy ctor  collection COPIED " << collection.size() << " movies to " << collectionName << " collection" << endl;
}
//detor
Movies::~Movies()
{
    cout << "Movies detor" << endl;
}

int Movies::AddMovie(std::string name, int watches)
{
    for (const auto &movieBefore: collection)
    {
        
        if (movieBefore.GetName() == name)
        {
            cout << "ERR: Movie " << name << " already in collection " << endl;
            return -1;
        }
    }
    //Movie tempMovie;
    //tempMovie.SetName(name);
    //tempMovie.SetWatches(watches);
    collection.push_back(Movie{name, watches});
    
    return 0;
}

int Movies::RemoveMovie(std::string name)
{
    //find movie name in collection
    for (unsigned int i = 0; i < collection.size(); ++i)
    {
        if (collection.at(i).GetName() == name)
        {
            collection.erase(collection.begin()+i);
            return 0;
        }        
    }
    cout << "ERR: Movie " << name << " is not in collection " << endl;
    return -1;
}

void Movies::DisplayMovies() const
{
    if (collection.size() > 0)
    {
        for (const auto &movie: collection)
        {
            cout << movie.GetName() 
            << ", " << movie.GetWatches() << endl;
        }
    }
    else
    {
         cout << collectionName << " collection is empty" << endl;
    }
}

std::string Movies::GetCollectionName() const
{
    return collectionName;
}

int Movies::IncrementWatches(std::string name)
{
    for (auto &movie: collection)
    {
        if (movie.GetName() == name)
        {
            movie.IncrementWatches();
            return 0;
        }  
    }
    cout << "ERR: Movie " << name << " is not in collection " << endl;
    return -1;    
}


