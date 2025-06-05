#include "iter.hpp"

void testInt()
{
    int numbers[] = {42, 56, 3, 1, 6};

    std::cout << "Elements:" << std::endl;
    iter(numbers, 5, printElement);
    iter(numbers, 5, doubleElement);
    std::cout << "\nElements (doubled):" << std::endl;
    iter(numbers, 5, printElement);
    std::cout << "\n"
              << std::endl;
}

void testDouble()
{
    double numbers[] = {1.2, 12.3, 5.4, 1.0, 0.0006};

    std::cout << "Elements:" << std::endl;
    iter(numbers, 5, printElement);
    iter(numbers, 5, doubleElement);
    std::cout << "\nElements (doubled):" << std::endl;
    iter(numbers, 5, printElement);
    std::cout << "\n"
              << std::endl;
}

struct User
{
    std::string name;
    int age;
};

void printUser(const User &user)
{
    std::cout << "user: " << user.name << ", age: " << user.age << std::endl;
}

void testUsers()
{
    User users[] = {
        {"Jonas", 30},
        {"Pierre", 42},
        {"Paul", 55},
        {"Jaque", 15}};
    std::cout << "Users:" << std::endl;
    iter(users, 4, printUser);

    std::cout << "\n"
              << std::endl;
}

int main()
{
    testInt();
    testDouble();
    testUsers();
}