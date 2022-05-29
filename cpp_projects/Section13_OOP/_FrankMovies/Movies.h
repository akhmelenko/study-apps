#ifndef _MOVIES_H_
#define _MOVIES_H_

#include <vector>
#include "Movie.h"

class Movies
{
private:
    std::string collectionName;
    vector<Movie> collection;
public:
    //named ctor
    Movies(std::string name = "Collection");
    //copy ctor
    Movies(std::string name, const Movies &src);
    //detor
    ~Movies();
    int AddMovie(std::string name = "Movie Name", int watches = 0);
    int RemoveMovie(std::string name);
    std::string GetCollectionName() const;
    void DisplayMovies() const;
    int IncrementWatches(std::string name);    
};

#endif // _MOVIES_H_
