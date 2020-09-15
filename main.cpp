#include <iostream>
#include <fstream>
#include <Windows.h>
using  std::string;

class Student{
public:

    Student()= default;  // конструктор по умолчанию
    void set_info(string info){
        int i = 0;
        int k=0;
        while(info[i] != ' '){
            std::cout<<info[i];
            surname[k++]=info[i++];
        }
        i++;
        k=0;
        while(info[i]!=' '){
            name[k++]=info[i++];
        }
        i++;
        k=0;
        while(info[i]!=' '){
            group[k++]=info[i++];
        }
    }
    ~Student()= default;
    void get_name(){
        std::cout<<name;
    }
    void get_surname(){
        std::cout<<surname;
    }
    void get_group(){
        std::cout<<group;
    }
private:
    string name;
    string surname;
    string group;
    int marks[5];
    float average;
};

int main() {
    int sCount = 0;
    auto* bomonka = new Student[20];
    SetConsoleOutputCP(CP_UTF8);
    string info;
    std::ifstream F ("studentsList.txt");
    if(F){
        while(std::getline(F, info)){
             std::cout<<info<<std::endl;
             bomonka[sCount].set_info(info);
             sCount++;
         }
        F.close();

        
        std::cout<<std::endl<<"Number of students is " << sCount << std::endl;
     }
    else std::cout<<"File is not found";
    return 0;
}
