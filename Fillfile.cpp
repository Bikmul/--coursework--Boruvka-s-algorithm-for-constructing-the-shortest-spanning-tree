#include "Fillfile.hpp"

Fillfile::Fillfile(int **arr, int v)
{
    this->fillfile(arr,v);
}

Fillfile::~Fillfile()
{

}

void Fillfile::fillfile(int **arr, int v)
{
    std::ofstream file;
    file.open("/Users/dtwanda/Desktop/курсач/visual/file.ber");
    if(!file.is_open())
        std::cout << "Ошибка записи в файл" << std::endl;
    else
    {
        for(int i = 0; i <v;i++)
        {
            for(int j = 0;j < v;j++)
                file << arr[i][j];
            if(i != v-1)
                file << std::endl;
        }
        std::cout << "Файл создан " << std::endl; 
    }
    file.close();
}