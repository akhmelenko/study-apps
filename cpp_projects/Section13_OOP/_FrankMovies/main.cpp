#include <iostream>
#include "Movies.h"
//#include "Movie.h"
#include <string>
#include <vector>

using namespace std;

void AddMovie(Movies &collection, std::string name, int watches)
{
    if (!collection.AddMovie(name, watches))
    {
        cout << name << " added with " << watches << " watches to " << collection.DisplayMovies() /*GetCollectionName()*/ << " collecion" << endl;
    }
    else
    {
        cout << name << " is already in " << collection.GetCollectionName() << " collection" << endl;
    }
}

void DisplayCollection(Movies &collection)
{
    cout << "========================" << collection.GetCollectionName() << " collection ======================" << endl;
    collection.DisplayMovies();
    cout << "==============================================================" << endl;
}

void IncrementWatches(Movies &collection, std::string name)
{
    if (!collection.IncrementWatches(name))
        cout << name << " incremented in "<< collection.GetCollectionName() << " collecion" << endl;
    else
        cout << name << " is not in " << collection.GetCollectionName() << " collection" << endl;
}

void RemoveMovie(Movies &collection, std::string name)
{
    if (!collection.RemoveMovie(name))
        cout << name << " removed from "<< collection.GetCollectionName() << " collecion" << endl;
    else
        cout << name << " is not in " << collection.GetCollectionName() << " collection" << endl; 
}


int main()
{

    //vector<Movie> vec;
    
    Movies my0;
    DisplayCollection(my0);
    
    Movies my {"My"};
    DisplayCollection(my);
    
    AddMovie(my, "RAMBO", 5);
    DisplayCollection(my);
    AddMovie(my, "TERMINATOR", 2);
    DisplayCollection(my);
    AddMovie(my, "BLADE RUNNER", 3);
    DisplayCollection(my);
    AddMovie(my, "RAMBO", 3);
    DisplayCollection(my);
    IncrementWatches(my, "RAMBO");
    DisplayCollection(my);
    IncrementWatches(my, "TERMINATOR");
    DisplayCollection(my);
    IncrementWatches(my, "TERMINATOR 2");
    DisplayCollection(my);
    
    Movies my2 {"My2", my};
    AddMovie(my2, "BOND", 56);
    DisplayCollection(my2);
    RemoveMovie(my, "TERMINATOR");
    DisplayCollection(my);
    DisplayCollection(my2);
	return 0;
}
