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

    void get_surname() {
        std::cout <<surname << " " << name << " "<< group<<std::endl;
    }
    void get_name(){}

    void get_avrg(){
        std::cout<<"Average is "<< average<<std::endl;
    }
    ~Student()= default;
private:
    void Sum(){
        for (int i = 0; i<5; i++)
            sum+=marks[i];
    }
    char name[10];
    char surname[20];
    char group[20];
    int marks[5];
    int sum = 0;
    float average = sum/5;
};

int main() {
    int sCount = 0;
    auto* bomonka = new Student[20];
    string info;
    std::ifstream F ("studentsList.txt");
    if(F){
        while(std::getline(F, info)){
            bomonka[sCount].set_info(info);
             sCount++;
         }
        F.close();
        std::cout<<std::endl;
        system("cls");
        std::cout<<"Number of students is " <<  sCount<< std::endl;

        for(int i = 0; i<sCount; i++)
        bomonka[i].get_surname();
     }
    else std::cout<<"File is not found";
    return 0;
}
