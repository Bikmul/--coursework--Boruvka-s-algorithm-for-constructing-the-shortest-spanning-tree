#pragma once
#include <iostream>
#include <map>
#include <fstream>

class Filereader
{
private:
    std::string name;
    int v;
    std::map<int, int> graph;
public:
    Filereader(std::string &name);
    ~Filereader();

    int get_v();
    std::map<int, int>  get_map();

    void insert_v();
    void printer();
};