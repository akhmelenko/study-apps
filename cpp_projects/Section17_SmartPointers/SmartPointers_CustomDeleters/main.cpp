#include <iostream>
#include <memory>

class Test
{
private:
    int data;
public:
    Test() : data{0} {std::cout << "\tTest constructor(" << data << ")" << std::endl;}
    Test(int data) : data{data} {std::cout << "\tTest constructor(" << data << ")" << std::endl;}
    GetData() {return data;}
    ~Test() {std::cout << "\tTest destructor(" << data << ")" << std::endl;}
};

void MyDeleter(Test* ptr)
{
    std::cout << "\tUsing my custom function deleter" << std::endl;
    delete ptr;
}

int main()
{
    {
        std::cout <<" === Using a function deleter ===" << std::endl;
        std::shared_ptr<Test> pTest1 = {new Test{100}, MyDeleter};
    }

    {
        std::cout <<" === Using a lambda deleter ===" << std::endl;
        std::shared_ptr<Test> pTest2 = {new Test{100},
            [](Test* ptr)
            {
                std::cout << "\tUsing my lambda deleter" << std::endl;
                delete ptr;
            }
        };
	}
    
	return 0;
}
