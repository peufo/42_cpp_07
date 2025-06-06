#include <iostream>
#include <string>
#include "Array.hpp"

void displayInt(int &n)
{
    std::cout << "My int: " << n << std::endl;
}

void testInt()
{
    Array<int> arr(2);

    arr[0] = 42;
    arr[1] = -8;
    try
    {
        arr[2] = 5;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    arr.forEach(displayInt);

    std::cout << "Size of my number array: " << arr.size() << std::endl;
}

struct User
{
    std::string name;
    int age;
};

void displayUser(User &user)
{
    std::cout << user.name << " is " << user.age << " years old !" << std::endl;
}

void testUser()
{
    Array<User> arr(3);

    arr[0] = (User){"Jonas", 30};
    arr[1] = (User){"Alice", 105};
    arr[2].name = "Bob";
    arr[2].age = 22;

    Array<User> arr2 = arr;
    arr2[1] = (User){"Robert", 80};

    arr.forEach(displayUser);
    std::cout << "Size of my first users array: " << arr.size() << std::endl;

    std::cout << std::endl;
    arr2.forEach(displayUser);
    std::cout << "Size of my second users array: " << arr2.size() << std::endl;
}

int main()
{
    testInt();
    std::cout << std::endl;
    testUser();
}
