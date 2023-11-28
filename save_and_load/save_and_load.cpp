// save_and_load.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

void save(std::ofstream& file, character& person)               // сохранение в бинарном файле
{
    int len = person.name.length();
    file.write((char*)&len, sizeof(len));
    file.write(person.name.c_str(), len);
    file.write((char*)&person.health, sizeof(person.health));
    file.write((char*)&person.armor, sizeof(person.armor));

}

void load(std::ifstream& file, character person)                // загрузка из бинарного файла
{
    int len;
    file.read((char*)&len, sizeof(len));
    person.name.resize(len);
    file.read((char*)person.name.c_str(), len);
    file.read((char*)&person.health, sizeof(person.health));
    file.read((char*)&person.armor, sizeof(person.armor));
}

class character                                                // или struct
{
public:
    std::string name;
    int health = 0;
    int armor = 0;
};
int main()
{
    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
