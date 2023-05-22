#include <cstdlib>
#include <iostream>
#include <raylib-cpp.hpp>

int main(int argc, char **argv)
{
    raylib::InitWindow(640, 480, "UNDERTALE™ Undyne's Target Practice");
    std::cout << "Message to ensure everything works." << std::endl;
    exit(EXIT_SUCCESS);
}