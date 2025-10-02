#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

class disease{
    char disease_name[20];
    int month[6];
    int minimal_morbidity;

public:
    disease() : minimal_morbidity(0) {
        disease_name[0] = '\0';
        for(int i = 0; i < 6; i++) {
            month[i] = 0;
        }
    }
    int calculate_min(){
        int min = month[0];
        for(int i = 1; i < 6; i++){
            if (month[i] < min){ 
                min = month[i];
            }
        }
        minimal_morbidity = min;
        cout << "Минимальное значение: " << min << endl;
        return min;
    }

    void set_name(string& name) { 
        strncpy(disease_name, name.c_str(), 19);
        disease_name[19] = '\0';
    }
    
    void set_months(int m[6]) { 
        for(int i = 0; i < 6; i++) {
            month[i] = m[i];
        }
    }

    void write_to_binary(ofstream& file) {
        file.write((char*)this, sizeof(disease));
    }
};

int main(){

    ifstream F("OOP.txt");
    if (!F) {
        cout << "Ошибка открытия файла OOP.txt!" << endl;
        return 1;
    }
    
    int n;
    F >> n;
    cout << "Количество записей: " << n << endl;
    
    disease* diseases = new disease[n];
    
    for(int i = 0; i < n; i++){
        cout << " Запись " << i+1 << endl;
        string name;
        int months[6];
        F >> name;
        cout << "Название болезни: " << name << endl;

        for(int j = 0; j < 6; j++){
            F >> months[j];
            cout << "Месяц " << j+1 << ": " << months[j] << endl;
        }

        diseases[i].set_name(name);
        diseases[i].set_months(months);
        diseases[i].calculate_min();
    }
    F.close();

    ofstream bin_F("OOP.dat", ios::binary);
    if (!bin_F) {
        cout << "Ошибка создания бинарного файла!" << endl;
        delete[] diseases;
        return 1;
    }

    bin_F.write((char*)&n, sizeof(n));

    for (int i = 0; i < n; i++){
        diseases[i].write_to_binary(bin_F);
    }

    bin_F.close();
    delete[] diseases;
    return 0;
}