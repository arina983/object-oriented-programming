#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class cofien{
    private:
    string title;
    string address;
    string working_hours;
    int average_daily_income;

    public:
    cofien(): title(""), address(""), working_hours(""), average_daily_income(0) {} 

    cofien(string _title, string _address, string w_h, int a_d_i){
        title = _title;
        address = _address;
        working_hours = w_h;
        average_daily_income = a_d_i;
    }
    string get_title(){
        return title;
    }
    string get_address(){
        return address;
    }
    string get_working_hours(){
        return working_hours;
    }
    int get_average_daily_income(){
        return average_daily_income;
    }
    void set_title(string _title){
        title = _title;
    }
    void set_address(string _address){
        address = _address;
    }
    void set_working_hours(string w_k){
        working_hours = w_k;
    }
    void set_average_daily_income(int a_d_i ){
        average_daily_income = a_d_i;
    }
    void print(){
        cout<<"Название кофейни: "<< title << endl;
        cout<<"Адрес: "<< address << endl;
        cout<<"Часы работы: "<< working_hours << endl;
        cout<<"Среднесуточный доход: "<< average_daily_income << endl;
    }
};
bool compareByIncome(cofien &a, cofien &b) {
    return a.get_average_daily_income() < b.get_average_daily_income();
}

int main(){
    ifstream F_kofe("kofe.txt");
    if (!F_kofe){
        cout << "Ошибка открытия файла Kino.txt" << endl;
        return 1;
    }

    cout << "Введите количество объектов класса: " << endl;
    int N;
    cin >> N;   
    cin.ignore();

    cofien* cofiens = new cofien[N];
     for(int i = 0; i < N; i++){
        cout << "Запись " << i+1 << endl;

        string title, address, working_hours, income_str;
        int average_daily_income;

        getline(F_kofe, title);
        getline(F_kofe, address);
        getline(F_kofe, working_hours); 
        getline(F_kofe, income_str);
        average_daily_income = stoi(income_str);
        
        cofiens[i].set_title(title);
        cofiens[i].set_address(address);
        cofiens[i].set_working_hours(working_hours);
        cofiens[i].set_average_daily_income(average_daily_income);

        cofiens[i].print();

    }
    F_kofe.close();

    vector<cofien> cofe;
    cofe.reserve(N);
    for (int i = 0; i < N; i++) {
    if (cofiens[i].get_average_daily_income() > 500000) {
        cofe.push_back(cofiens[i]);
        }
    }
    cout << "\nКофейни с доходом > 500000 (отсортированы):" << endl;
    for(auto &c : cofe) {
        c.print();
        cout << "---" << endl;
    }

    cout << "\nВведите данные новой кофейни:" << endl;
    string new_title, new_address, new_hours, new_income_str;
    int new_income;

    cout << "Название: ";
    getline(cin, new_title);
    cout << "Адрес: ";
    getline(cin, new_address);
    cout << "Часы работы: ";
    getline(cin, new_hours);
    cout << "Среднесуточный доход: ";
    getline(cin, new_income_str);
    new_income = stoi(new_income_str);

    cofien new_cofien(new_title, new_address, new_hours, new_income);
    if(new_income > 500000) {
        cofe.push_back(new_cofien);
        sort(cofe.begin(), cofe.end(), compareByIncome);
    }
    // Дозапись в файл
    ofstream outfile("kofe.txt", ios::app);
    if(outfile) {
        outfile << new_title << "\n" << new_address << "\n" 
                << new_hours << "\n" << new_income << "\n";
        outfile.close();
        cout << "Данные успешно добавлены в файл!" << endl;
    } else {
        cout << "Ошибка записи в файл!" << endl;
    }

    delete[] cofiens;
    return 0;
}