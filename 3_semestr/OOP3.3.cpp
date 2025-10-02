#include <iostream>
#include <fstream>
#include <climits>
#include <cstring>

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

    const char* get_name(){
        return disease_name;
    }
    int get_month(int i){
        return month[i];
    }
    int get_min(){
        return minimal_morbidity;
    }

};

int main(){
    ifstream in("OOP.dat", ios::binary);
    if (!in) {
        cout << "Ошибка открытия файла OOP.dat!" << endl;
        return 1;
    }
    
    int n;
    in.read((char*)&n, sizeof(n));
    cout << "Количество болезней: " << n << endl;

    disease t;
    int global_min = INT_MAX;
    char min_disease_name[30] = "";
    
    while(!in.eof()){
        in.read((char*)&t, sizeof(t));
        cout << t.get_name() << "\nКоличество заболевших по месяцам: "<< endl;
        for (int i = 0; i < 6; i++){
            cout << t.get_month(i) << " ";
        } 
        cout << "\nМин. заболеваемость: " << t.get_min() << endl;
        if (t.get_min() < global_min) {
            global_min = t.get_min();
            strcpy(min_disease_name, t.get_name());
        }
    }
    cout << "Минимальная заболеваемость за полугодие: " << min_disease_name << endl;
    
    in.close();
    return 0;
}