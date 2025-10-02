#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

class cinema{
protected:
    string name;
    string number;
    string address;
    string working_hours;
    int number_of_cinemas;

public:
    cinema() : name(""), number(""), address(""), working_hours(""), number_of_cinemas(0){}

    cinema(string _name, string _num, string _address, string w_k, int num_of_cinema){
        name = _name;
        number = _num;
        address = _address;
        working_hours = w_k;
        number_of_cinemas = num_of_cinema;
    }

    string get_name(){
        return name;
    }
    string get_number(){
        return number;
    }
    string get_address(){
        return address;
    }
    string get_working_hours(){
        return working_hours;
    }
    int get_number_of_cinemas(){
        return number_of_cinemas;
    }
    void set_name(string _name){
        name = _name;
    }
    void set_number(string _num){
        number = _num;
    }
    void set_address(string _address){
        address = _address;
    }
    void set_working_hours(string w_k){
        working_hours = w_k;
    }
    void set_number_of_cinemas(int num_of_cinema){
        number_of_cinemas = num_of_cinema;
    }

    void print(){
        cout << "Название кинотеатра: " << name << endl;
        cout << "Телефон: " << number << endl;
        cout << "Адрес: " << address << endl;
        cout << "Время работы: " << working_hours << endl;
        cout << "Количество кинозалов: " << number_of_cinemas << endl;
    }
};

class cinemas : public cinema {
protected:
    int capacity;
public:
    cinemas() : cinema(), capacity(0) {}
    cinemas(string _name, string _address, string w_k, int _cap ) : cinema(_name, "", _address, w_k, 0), capacity(_cap){}

    int get_capacity(){
        return capacity;
    }

    void set_capacity(int _cap){
        capacity = _cap;
    }

    void print(){
        cout << "Название кинозала: " << name << endl;
        cout << "Адрес: " << address << endl;
        cout << "Время работы: " << working_hours << endl;
        cout << "Вместимость: " << capacity << endl;
    }
};

int main(){

    ifstream F_Kino("Kino.txt");
    if (!F_Kino){
        cout << "Ошибка открытия файла Kino.txt" << endl;
        return 1;
    }
    
    int n;
    cout << "Введите количество кинотеатров: ";
    cin >> n;
    cin.ignore();
    
    cinema* cinemase = new cinema[n];
    
    for(int i = 0; i < n; i++){
        cout << "Запись " << i+1 << endl;
        
        string name, number, address, working_hours, num_cinemas_str;
        int number_of_cinemas;
        
        getline(F_Kino, name);
        getline(F_Kino, number);
        getline(F_Kino, address);
        getline(F_Kino, working_hours);
        getline(F_Kino, num_cinemas_str);
        number_of_cinemas = stoi(num_cinemas_str);

        cinemase[i].set_name(name);
        cinemase[i].set_number(number);
        cinemase[i].set_address(address);
        cinemase[i].set_working_hours(working_hours);
        cinemase[i].set_number_of_cinemas(number_of_cinemas);

        cinemase[i].print();
        cout << "******************" << endl;
    }
    F_Kino.close();

    ifstream F_Zal("Zal.txt");
    if (!F_Zal){
        cout << "Ошибка открытия файла Zal.txt" << endl;
        delete[] cinemase;
        return 1;
    }
    
    int k;
    cout << "Введите количество залов: ";
    cin >> k;
    cin.ignore();
    
    cinemas* cinemases = new cinemas[k];
    
    for (int j = 0; j < k; j++){
        cout << "Запись " << j+1 << endl;
        
        string name, address, working_hours, capacity_str;
        int capacity;
        
        getline(F_Zal, name);
        getline(F_Zal, address);
        getline(F_Zal, working_hours);
        getline(F_Zal, capacity_str);
        capacity = stoi(capacity_str);
        
        cinemases[j].set_name(name);
        cinemases[j].set_address(address);
        cinemases[j].set_working_hours(working_hours);
        cinemases[j].set_capacity(capacity);

        cinemases[j].print();
        cout << "******************" << endl;
    }
    F_Zal.close();

    delete[] cinemase;
    delete[] cinemases;

    return 0;
}