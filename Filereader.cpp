#include "Filereader.hpp"

Filereader::Filereader(std::string &name)
{
    this->name = name;
}

void Filereader::insert_v()
{
    std::ifstream file;
    int line;
    file.open(this->name);
    if(!file.is_open())
        std::cout << "Файл не открыт" << std::endl;
    else
    {
        std::cout << "Файл открыт" << std::endl;
        if(!file.eof())
        {
            file >> line;
            this->v = line;
        }
        else
            std::cout << "Файл пустой" << std::endl;
        for(int i=0;i< this->v;i++)
        {
            file >> line;
            this->graph.insert(std::make_pair(i,line));   
        }
        file.close();
    }
}

void Filereader::printer()
{
    std::cout << "Количество вершин графа = " << this->v << std::endl;
    for(int i=0;i< this->v;i++)
    {
        std::cout <<"================================"<< std::endl;
        std::cout <<"Координата вершины " << i << " по X: " << this->graph[i]/10 << std::endl;
        std::cout <<"Координата вершины " << i << " по Y: " << this->graph[i]%10 << std::endl;
        std::cout <<"================================"<< std::endl;
    }
}

int Filereader::get_v()
{
    return (this->v);
}

std::map<int, int> Filereader::get_map()
{
    return(this->graph);
}

Filereader::~Filereader()
{
    this->graph.clear();
}