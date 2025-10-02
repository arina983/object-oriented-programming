#include <iostream>
#include <string>

using namespace std;

class mobile_device {
    private:
    int connection_type;
    string operating_system;
    string device_name;

    public:

    mobile_device (string name, int c_t, string o_s){
        device_name = name;
        connection_type = c_t;
        operating_system = o_s;
    }

    void output(){
        cout<<"Устройство: "<< device_name <<endl;
        cout<<"Тип устройства: "<< connection_type << "G" <<endl;
        cout<<"Операционная системa: "<< operating_system <<"\n\n";
    }
    int get_connection_type(){
        return connection_type;
    }
    string get_operating_system(){
        return operating_system;
    }
    string get_device_name() {
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

    mobile_device honor("Honor", 4, "android");
    mobile_device *iphone = new mobile_device("iphone", 5, "iOS");

    honor.output();
    iphone->output();
 
    honor.set_connection_type(5);
    honor.set_operating_system("HarmonyOS");
    
    iphone->set_device_name("iPhone 15 Pro");
    
    cout << "После изменений:" << "\n\n";
    honor.output();
    iphone->output();
    
    cout << "Информация через геттеры:" << "\n\n";
    cout << "Устройство: " << honor.get_device_name() << endl;
    cout << "Тип соединения: " << honor.get_connection_type() << "G" << endl;
    cout << "Операционная система: " << honor.get_operating_system() << "\n\n";

    cout << "Устройство: " << iphone->get_device_name() << endl;
    cout << "Тип соединения: " << iphone->get_connection_type() << "G" << endl;
    cout << "Операционная система: " << iphone->get_operating_system() << "\n\n";

    delete iphone;

    return 0;
}


