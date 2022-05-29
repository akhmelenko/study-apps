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
    /*for (unsigned int i = 0; i < src.collection.size(); ++i)
    {
        collection.push_back(new Movie);
        collection.at(i)->name = src.collection.at(i)->name;
        collection.at(i)->watches = src.collection.at(i)->watches;
    }*/
    for (auto pMovie: src.collection)
    {
        collection.push_back(new Movie);
        collection.back()->SetName(pMovie->GetName());
        collection.back()->SetWatches(pMovie->GetWatches());
    }
    cout << "Movies copy ctor  collection COPIED " << collection.size() << " movies to " << collectionName << " collection" << endl;
}
//detor
Movies::~Movies()
{
    for (unsigned int i = 0; i < collection.size(); ++i)
    {
        delete collection.at(i);
    }
    cout << "Movies detor" << endl;
}

int Movies::AddMovie(std::string name, int watches)
{
    //check for dublicate
    /*for (unsigned int i = 0; i < collection.size(); ++i)
    {
        if (collection.at(i)->GetName() == name)
        {
            cout << "ERR: Movie " << name << " already in collection " << endl;
            return -1;
        }
    }*/
    for (auto pMovieBefore: collection)
    {
        
        if (pMovieBefore->GetName() == name)
        {
            cout << "ERR: Movie " << name << " already in collection " << endl;
            return -1;
        }
    }
    Movie* pMovie = new Movie;
    pMovie->SetName(name);
    pMovie->SetWatches(watches);
    collection.push_back(pMovie);
    
    return 0;
}

int Movies::RemoveMovie(std::string name)
{
    //find movie name in collection
    for (unsigned int i = 0; i < collection.size(); ++i)
    {
        if (collection.at(i)->GetName() == name)
        {
            delete collection.at(i);
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
        /*for (unsigned int i = 0; i < collection.size(); ++i)
        {
            cout << "Movie name = " << collection.at(i)->GetName() 
            << ", movie watches = " << collection.at(i)->GetWatches() 
            << " moviePtr = " << collection.at(i) << endl;
        }*/
        for (const auto pMovie: collection)
        {
            cout << pMovie->GetName() 
            << ", " << pMovie->GetWatches() 
            << ", moviePtr = " << pMovie << endl;
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
    //find movie name in collection
    /*for (unsigned int i = 0; i < collection.size(); ++i)
    {
        if (collection.at(i)->GetName() == name)
        {
            collection.at(i)->IncrementWatches();
            return 0;
        }        
    }*/
    for (const auto pMovie: collection)
    {
        if (pMovie->GetName() == name)
        {
            pMovie->IncrementWatches();
            return 0;
        }  
    }
    cout << "ERR: Movie " << name << " is not in collection " << endl;
    return -1;    
}


