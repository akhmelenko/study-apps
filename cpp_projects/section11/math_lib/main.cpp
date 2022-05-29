#include <iostream>
//#include <csdtlib>
#include <ctime>

using namespace std;

int main()
{
    size_t size {10}; 
    
	cout << "MAX RANDOM = " << RAND_MAX << "     sizeof(size_t) = " << sizeof(size_t) << endl;
    cout << "time(nullptr) = " << time(nullptr) << endl;
    srand(time(nullptr));
    
    for (unsigned int i; i < 20; ++i)
        cout << "rand() = " << rand() << " rand() % 6 = " << rand() % 6 << endl;
    
	return 0;
}
