#include <iostream>
#include <memory>
#include <vector>

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


//Functions prototypes
//std::unique_ptr<std::vector<std::shared_ptr<Test>>> Make()
auto Make()
{
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void Fill(std::vector<std::shared_ptr<Test>> &vec, int num)
{
    for(unsigned int i = 0; i < num; ++i)
    {
        std::cout << "Enter data point [" << i << "]: ";
        int data_point;
        std::cin >> data_point;
        vec.push_back(std::make_shared<Test>(data_point));
    }        
}

void Display(const std::vector<std::shared_ptr<Test>> &vec)
{
    std::cout << "\nDisplaing vector data" << std::endl;
    std::cout << "=========================" << std::endl;
    for (const auto &vec_item: vec)
        std::cout << vec_item->GetData() << std::endl;
    std::cout << "=========================" << std::endl;
}

int main()
{
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> pVec;
    pVec = Make();
    std::cout << "How many data points do you want to enter? ";
    int num;
    std::cin >> num;
    Fill(*pVec, num);
    Display(*pVec);
	
    std::cout << "pVec.get()=" << pVec.get() << std::endl;
    
    return 0;
}
