// HW 4 Задача 2. Сортируем адреса.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

class Address {
private:
    std::string city;
    std::string street;
    int home;
    int flat;

public:
    Address() {}

    void set_private_field(std::string city, std::string street, int home, int flat) {
        this->city = city;
        this->street = street;
        this->home = home;
        this->flat = flat;
    }

    std::string get_private_field_name_city() {
        return city;
    }

    std::string get_output_address() {
        return city + ", " + street + ", " + std::to_string(home) + ", " + std::to_string(flat);
    }
};

void sorting(Address* address, int size) {
    Address temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < (size - 1) - i; j++) {
            if (address[j].get_private_field_name_city() > address[j + 1].get_private_field_name_city()) {
                temp = address[j];
                address[j] = address[j + 1];
                address[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int size;
    std::ifstream In("in.txt");
    if (!(In.is_open())) {
        std::cout << "Не удалось открыть файл";
    }

    In >> size;

    Address* arr = new Address[size];

    int num = 0;
    std::string city;
    std::string street;
    int home;
    int flat;

    while (!(In.eof())) {
        In >> city;
        In >> street;
        In >> home;
        In >> flat;
        arr[num].set_private_field(city, street, home, flat);
        num++;
    }

    In.close();

    std::ofstream Out("out.txt");

    sorting(arr, size);

    Out << size << std::endl;
    for (int i = 0; i < size; i++) {
        Out << arr[i].get_output_address() << std::endl;
    }

    delete[] arr;

    Out.close();
  
}

