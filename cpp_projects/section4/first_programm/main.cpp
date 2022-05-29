#include <iostream>

int main()
{
    int favoriteNumber;
	std::cout << "Enter your favorite number between 1 and 100: ";
    std::cin >> favoriteNumber;
    std::cout << "Very good! " << favoriteNumber << " is my favorite number too!" << std::endl;
	return 0;
}
