#include <iostream>
#include <fstream>
#include <string>

using std::string;

class Student {
public:
    Student() {
        name = new char[20];
        surname = new char[20];
        group = new char[10];
        marks = new int [5];
        average = 0;
    };  // конструктор по умолчанию
    void set_info(string info) {
        int i = 0;
        int k = 0;
        while (info[i] != ' ') {
            surname[k++] = info[i++];
        }
        surname[k]='\0';
        i++;
        k = 0;
        while (info[i] != ' ') {
            name[k++] = info[i++];
        }
        name[k]='\0';
        i++;
        k = 0;
        while (info[i] != ' ') {
            group[k++] = info[i++];
        }
        group[k]='\0';
        i++;
        for (k = 0; k < 5; k++) {
            marks[k] = info[i] - '0';
            i += 2;
        }
    }

    void get_info() {
        std::cout << surname << " " << name << " " << group;
        for (int i = 0; i < 5; i++)
            std::cout << " "<< marks[i] << " ";
        std::cout << std::endl;
    }

    void get_avrg() {
        int sum = 0;
        for (int i = 0; i < 5; i++)
            sum += marks[i];
        average = sum / 5.0;
        std::cout << "Average is " << average << std::endl;

    }

    ~Student() {
        delete[] name;
        delete[] surname;
        delete[] group;
        delete[] marks;
    };

private:
    char *name;
    char *surname;
    char *group;
    int *marks;
    float average;
};

int main() {
    int sCount = 0;
    Student *bomonka = new Student[20];
    string info;
    std::ifstream F("studentsList.txt");
    if (F) {
        while (std::getline(F, info)) {
            bomonka[sCount].set_info(info);
            sCount++;
        }
        F.close();

        std::cout << "Number of students is " << sCount << std::endl;

        for (int i = 0; i < sCount; i++) {
            bomonka[i].get_info();
            bomonka[i].get_avrg();
        }
    } else std::cout << "File is not found";
    return 0;
}