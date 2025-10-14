#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class mobile_device {
    private:
    string device_name;
    int connection_type;
    string operating_system;
    
    public:

    mobile_device(): device_name(""), connection_type(0), operating_system("") {}
    mobile_device(string name, string o_s){
        device_name = name;
        operating_system = o_s;
    }

    mobile_device (string name, int c_t, string o_s){
        device_name = name;
        connection_type = c_t;
        operating_system = o_s;
    }
     int get_connection_type() const {
        return connection_type;
    }
    string get_operating_system() const {
        return operating_system;
    }
    string get_device_name() const {
        return device_name;
    }

    void set_connection_type(int c_t) {
        connection_type = c_t;
    }
    
    void set_operating_system(string o_s) {
        operating_system = o_s;
    }

    void set_device_name(string name) {
        device_name = name;
    }
};

int main(){

    cout<<"Введите размерность вектора 1: "<<endl;
    int N;
    cin>> N;
    cin.ignore();

    vector<mobile_device> device;
    device.reserve(N);

    for (int i = 0; i < N; i ++){
        string device_name, operating_system;
        int connection_type;

        cout << "Запись " << i + 1 << ":" << endl;
        cout<<"Введите название устройства:"<<endl;
        getline(cin, device_name);

        cout<<"Введите тип соединения: "<<endl;
        cin>>connection_type;
        cin.ignore();

        cout<<"Введите операционную систему устройства:"<<endl;
        getline(cin, operating_system);

        device.push_back(mobile_device(device_name, connection_type, operating_system));
        
        cout << "-------------------" << endl;
    }
 
    vector<mobile_device> tablet;

    string target_os = "android";
    for (const auto& dev : device) {
        if (dev.get_operating_system() == target_os) {
            tablet.push_back(dev);
        }
    }

    if (tablet.empty()){
        cout<<"Вектор пуст!"<<endl;
    } else {
        cout <<"Вектор не пуст: размер вектора "<<size(tablet) << endl;
    }

    sort(tablet.begin(), tablet.end(), [](const mobile_device& a, const mobile_device& b){
        return a.get_operating_system() < b.get_operating_system();
    });
    cout << "После сортировки:" << endl;
    for (const auto& tab : tablet) {
        cout << tab.get_device_name() << " - " << tab.get_operating_system() << endl;
}
    
 cout << "\nВставка нового устройства:" << endl;
    string new_name, new_os;
    int new_connection_type;

    cout << "Введите название нового устройства: " << endl;
    getline(cin, new_name);
    
    cout << "Введите тип соединения: " << endl;
    cin >> new_connection_type;
    cin.ignore();
    
    cout << "Введите операционную систему: " << endl;
    getline(cin, new_os);

    if (new_os == target_os) {
        mobile_device new_device(new_name, new_connection_type, new_os);
        
        // Находим позицию для вставки с сохранением сортировки
        auto it = lower_bound(tablet.begin(), tablet.end(), 
                             new_device, 
                             [](const mobile_device& a, const mobile_device& b) {
                                 return a.get_operating_system() < b.get_operating_system();
                             });
        
        tablet.insert(it, new_device);
        cout << "Устройство успешно добавлено!" << endl;
    } else {
        cout << "Ошибка: тип соединения не соответствует критерию фильтрации!" << endl;
    }

    cout << "\nФинальный вектор:" << endl;
    for (const auto& dev : tablet) {
         cout << dev.get_device_name() << " - " << dev.get_operating_system() << " - " << dev.get_connection_type() << endl;
    }

    return 0;
}
