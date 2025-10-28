#include <iostream>
#include <fstream>
#include <list>

using namespace std;

class HR_Department{
    protected:
        string title;
        int number_employees;
        int number_hours_produced;
        int payment_hour;
        int passing_tax;
        public:
        HR_Department(): title(""), number_employees(0), number_hours_produced(0), payment_hour(0), passing_tax(0) {}
        HR_Department(string _title, int _number_employees, int _number_hours_produced, int _payment_hour, int _passing_tax){
            title = _title;
            number_employees = _number_employees;
            number_hours_produced = _number_hours_produced;
            payment_hour = _payment_hour;
            passing_tax = _passing_tax;
        }
    void set_title(string _title){
        title = _title;
    }
    void set_number_employees(int _number_employees){
        number_employees = _number_employees;
    }
    void set_number_hours_produced(int _number_hours_produced){
        number_hours_produced = _number_hours_produced;
    }
    void set_payment_hour(int _payment_hour){
        payment_hour = _payment_hour;
    }
    void set_passing_tax(int _passing_tax){
         passing_tax = _passing_tax;
    }
    string get_title(){
        return title;
    }
    int get_number_employees(){
        return number_employees;
    }
    int get_number_hours_produced(){
        return number_hours_produced;
    }
    int get_payment_hour(){
        return payment_hour;
    }
    int get_passing_tax(){
        return passing_tax;
    }
    void print()const{
        cout << "Наименование предприятия: " << title << endl;
        cout << "Число работников: " << number_employees <<endl;
        cout << "Норма выработки часов в месяц: " << number_hours_produced <<endl;
        cout << "Оплата за час: " << payment_hour <<endl;
        cout << "Подоходный налог: " << passing_tax << "%" << endl;
        cout<< "*****************************************" << endl;
    }

    int amount_deductions()const{
        int salary = payment_hour * number_hours_produced * number_employees;
        return salary * 0.13;
    }
};

list <HR_Department> department;

int main(){

    ifstream File("ok.txt");
    if (!File){
        cout << "Ошибка открытия файла ok.txt" << endl;
        return 1;
    }
    string title, temp;
    int number_employees, number_hours_produced, payment_hour, passing_tax;

     while (getline(File, title)) {
        getline(File, temp);
        number_employees = stoi(temp);
        
        getline(File, temp);
        number_hours_produced = stoi(temp);
        
        getline(File, temp);
        payment_hour = stoi(temp);
        
        getline(File, temp);
        passing_tax = stoi(temp);

    HR_Department new_dep(title, number_employees, number_hours_produced, payment_hour, passing_tax);

    auto it = department.begin();
    while (it != department.end() && it-> get_number_employees() < number_employees){
        ++it;
    }
    department.insert(it, new_dep);
    }

    File.close();

    cout << "Предприятия, упорядоченные по числу работников:" << endl;
    for (const auto& dep : department) {
        dep.print();
        cout << "Сумма отчислений по налогу: " << dep.amount_deductions() << " руб." << endl;
        cout << "*****************************************" << endl;
    }

    return 0;
}