#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>

using namespace std;

class Movie
{
    friend class Movies;
private:
    std::string name;
    int watches;
public:
    //raw ctor
    Movie();
    //copy ctor
    Movie(const Movie &src);
    //init ctor
    Movie(std::string name, int watches);
    //move constructor
    //Movie(Movie &&src) noexcept;
    //detor
    ~Movie();
    void SetName(std::string name_);
    void SetWatches(int watches_);
    void IncrementWatches();
    std::string GetName() const;
    int GetWatches() const;
};

#endif // _MOVIE_H_
