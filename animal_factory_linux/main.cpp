#include <algorithm>
#include <iostream>
#include <list>
#include <map>

class Animal {
    friend std::ostream &operator<<(std::ostream &os, const Animal &obj);
    std::string name;
    unsigned int age;

   public:
    Animal() {}
    virtual void FillAttributes() {
        std::cout << "Enter the name " << std::endl;
        std::getline(std::cin >> std::ws, name);
        std::cout << "Enter the age " << std::endl;
        std::cin >> age;
    }
    std::string GetName() const { return name; }
    unsigned int GetAge() const { return age; }
    virtual std::string GetType() const { return "Animal"; }
    void PrintBase(std::ostream &os) const {
        os << GetName()
           << ", age = " << GetAge();
    }
    virtual void Print(std::ostream &os) const {
        PrintBase(os);
    }
    virtual Animal *Duplicate() = 0;
};

std::ostream &operator<<(std::ostream &os, const Animal &obj) {
    obj.Print(os);
    return os;
}

class Fish : public Animal {
    const std::string type = "fish";
    unsigned int finsQty;

   public:
    Fish() {}
    virtual void FillAttributes() {
        Animal::FillAttributes();
        std::cout << "Enter the fins qty " << std::endl;
        std::cin >> finsQty;
    }
    virtual std::string GetType() const {
        return type;
    }
    unsigned int GetFinsQty() const {
        return finsQty;
    }
    virtual void Print(std::ostream &os) const {
        PrintBase(os);
        os << ", type = " << GetType()
           << ", fins qty = " << GetFinsQty();
    }
    virtual Animal *Duplicate() {
        return new Fish();
    }
};

class Cat : public Animal {
    const std::string type = "cat";
    unsigned int legsQty;

   public:
    Cat() {}
    virtual void FillAttributes() {
        Animal::FillAttributes();
        std::cout << "Enter the legs qty " << std::endl;
        std::cin >> legsQty;
    }
    virtual std::string GetType() const {
        return type;
    }
    unsigned int GetLegsQty() const {
        return legsQty;
    }
    virtual void Print(std::ostream &os) const {
        PrintBase(os);
        os << ", type = " << GetType()
           << ", legs qty = " << GetLegsQty();
    }
    virtual Animal *Duplicate() {
        return new Cat();
    }
};

class Snake : public Animal {
    const std::string type = "snake";
    unsigned int ringsQty;

   public:
    Snake() {}
    virtual void FillAttributes() {
        Animal::FillAttributes();
        std::cout << "Enter the rings qty " << std::endl;
        std::cin >> ringsQty;
    }
    virtual std::string GetType() const {
        return type;
    }
    unsigned int GetRingsQty() const {
        return ringsQty;
    }
    virtual void Print(std::ostream &os) const {
        PrintBase(os);
        os << ", type = " << GetType()
           << ", rings qty = " << GetRingsQty();
    }
    virtual Animal *Duplicate() {
        return new Snake();
    }
};

std::list<Animal *> pAnimalPatterns{new Fish(), new Cat(), new Snake()};

void PrintAllAnimals(const std::list<Animal *> &pAnimals) {
    std::cout << "Animals list:" << std::endl;
    for (const auto &pObj : pAnimals)
        std::cout << *pObj << std::endl;
}

enum CMD {
    CMD_WRONG,
    CMD_ADD,
    CMD_DELETE,
    CMD_QUIT
};

void PrintAnimalTypes(const std::list<Animal *> pAnimalPatterns) {
    std::cout << "[ ";
    for (const auto pAnimalPattern : pAnimalPatterns)
        std::cout << pAnimalPattern->GetType() << " ";
    std::cout << "]" << std::endl;
}

bool DeleteAnimalByName(
    std::list<Animal *> &pAnimals,
    const std::string &nameToDelete) {
    bool result = false;
    for (auto it = pAnimals.begin(); it != pAnimals.end();) {
        if ((*it)->GetName() == nameToDelete) {
            // free allocated memory
            delete (*it);
            // delete PTR from container
            it = pAnimals.erase(it);
            result = true;
        } else {
            it++;
        }
    }
    return result;
}

bool CheckAnimalType(
    const std::list<Animal *> pAnimalPatterns,
    const std::string &animalType) {
    for (const auto pAnimalPattern : pAnimalPatterns) {
        if (pAnimalPattern->GetType() == animalType)
            return true;
    }
    return false;
}

bool CheckCmdType(
    const std::map<std::string, enum CMD> &cmdTypes,
    const std::string &inputCmd) {
    auto it = cmdTypes.find(inputCmd);
    return it != cmdTypes.end() ? true : false;
}

int main() {
    std::list<Animal *> pAnimals;
    std::map<std::string, enum CMD> cmdTypes =
        {{"wrong", CMD_WRONG}, {"add", CMD_ADD}, {"del", CMD_DELETE}, {"q", CMD_QUIT}};
    bool cycle = true;
    while (cycle) {
        printf("\n======================================\n");
        PrintAllAnimals(pAnimals);
        std::cout << "Enter the command:" << std::endl;
        std::cout << "- 'add': add animal" << std::endl;
        std::cout << "- 'del': delete animal" << std::endl;
        std::string cmdString;
        std::cin >> cmdString;
        std::cout << "Entered command: " << cmdString << std::endl;
        // cmd check
        if (!CheckCmdType(cmdTypes, cmdString)) {
            std::cout << "Wrong command! Try again" << std::endl;
            continue;
        }
        switch (cmdTypes[cmdString]) {
            case CMD_WRONG:
                std::cout << "Wrong command! Try again..." << std::endl;
                break;
            case CMD_ADD: {
                std::cout << "Adding the animal:" << std::endl;
                std::cout << "Enter the animal type of:" << std::endl;
                PrintAnimalTypes(pAnimalPatterns);
                std::string newAnimalType;
                std::getline(std::cin >> std::ws, newAnimalType);
                if (!CheckAnimalType(pAnimalPatterns, newAnimalType)) {
                    std::cout << "Wrong animal type! Try again" << std::endl;
                    break;
                }
                // create animal
                Animal *pAnimal;
                for (const auto &anymalPattern : pAnimalPatterns) {
                    if (anymalPattern->GetType() == newAnimalType)
                        pAnimal = anymalPattern->Duplicate();
                }
                pAnimal->FillAttributes();
                pAnimals.push_back(pAnimal);
            } break;
            case CMD_DELETE: {
                std::cout << "Deleting the animal:" << std::endl;
                std::cout << "Enter the animal name to delete:" << std::endl;
                std::string nameToDelete;
                std::getline(std::cin >> std::ws, nameToDelete);
                // delete animal by name
                if (DeleteAnimalByName(pAnimals, nameToDelete))
                    std::cout << "Animal(s) with name " << nameToDelete << "deleted" << std::endl;
                else
                    std::cout << "No animal(s) with name " << nameToDelete << ". Try again..." << std::endl;
            } break;
            case CMD_QUIT:
                cycle = false;
                break;
        }
    }
    // deallocate memory
    for (auto &pAnymalPattern : pAnimalPatterns)
        delete pAnymalPattern;
    for (auto &pAnimal : pAnimals)
        delete pAnimal;

    return 0;
}