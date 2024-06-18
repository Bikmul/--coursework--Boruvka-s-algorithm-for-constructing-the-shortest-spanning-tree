#include <iostream>
#include "Filereader.hpp"
#include "Shteiner.hpp"
#include "Fillfile.hpp"

int main()
{
    std::string path;

    std::cout << "Введите название файла: ";
    std::cin >> path;
    Filereader file(path);
    file.insert_v();
    // file.printer();
    Shteiner tree(file.get_v(), file.get_map());
    tree.printer();
    tree.algoritm();
    tree.dop_print();
    Fillfile write(tree.getFlag(), tree.get_v());

    std::cout << "Название файла: " << path << std::endl;
}