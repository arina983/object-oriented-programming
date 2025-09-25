#include <iostream>
#include <limits>
using namespace std;


class beauty_shops{
    protected: 
    string title_shops;
    int telephone;
    string address_shops;
    int working_hours;

    public: 
    beauty_shops():title_shops(""), telephone(0), address_shops(""), working_hours(0) {}

    beauty_shops(string title, int phone, string address, int w_h){
        title_shops = title;
        telephone = phone;
        address_shops = address;
        working_hours = w_h;
    }

    string get_title_shops(){
        return title_shops;
    }

    int get_telephone(){
        return telephone;
    }

    string get_address_shops(){
        return address_shops;
    }

    int get_working_hours(){
        return working_hours;
    }

    void set_title_shops(string title){
        title_shops = title;
    }

    void set_telephone(int phone){
        telephone = phone;
    }

    void set_address_shops(string address){
        address_shops = address;
    }

    void set_working_hours(int w_h){
        working_hours = w_h;
    }

    void print(){
        cout << "Название магазина: " << title_shops << endl;
        cout << "Номер телефона: " << telephone << endl;
        cout << "Адрес: " << address_shops << endl;
        cout << "Время работы: " << working_hours << endl;
    }
};

class professional: public beauty_shops {
    protected: 
    string type_cosmetics;

    public: 
    professional() : beauty_shops(), type_cosmetics("") {}

    professional(int phone, string address, int w_h, string type) : beauty_shops("", phone, address, w_h), type_cosmetics(type){}

    string get_Type_cosmetics() {
        return type_cosmetics;
    }

    void set_Type_cosmetics(string type) {
        type_cosmetics = type;
    }

    void print(){
        cout << "Номер телефона: " << telephone << endl;
        cout << "Адрес: " << address_shops << endl;
        cout << "Время работы: " << working_hours << endl;
        cout << "Тип косметики: " << type_cosmetics << endl;
    }
};

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main(){
    int N;
    cout << "Введите количество магазинов: " << endl;
    cin >> N;
    clearInputBuffer();

    beauty_shops* shops = new beauty_shops[N];

    for (int i = 0; i < N; i++){
        string title;
        int phone;
        string address;
        int w_h;

        cout << "Введите название магазина " << i + 1 << ": " << endl;
        getline(cin, title);

        cout << "Введите номер телефона " << i + 1 << ": " << endl;
        cin >> phone;
        clearInputBuffer();

        cout << "Введите адрес " << i + 1 << ": " << endl;
        getline(cin, address);
        
        cout << "Введите время работы " << i + 1 << ": " << endl;
        cin >> w_h;
        clearInputBuffer();

        shops[i] = beauty_shops(title, phone, address, w_h);
        cout << "Магазин " << i + 1 << ": " << endl;
        shops[i].print();
        cout << endl;

    }
    
    int K;
    cout << "Введите количество профессионалов: " << endl;
    cin >> K;
    clearInputBuffer();

    professional* professionals = new professional[K];
     for (int i = 0; i < K; i++){
        int phone;
        string address;
        int w_h;
        string type;
        
        cout << "Введите номер телефона "  << i + 1 << ": " << endl;
        cin >> phone;
        clearInputBuffer();

        cout << "Введите часы работы "  << i + 1 << endl;
        cin >> w_h;
        clearInputBuffer();

        cout << "Введите адрес: "  << i + 1 << ": "<< endl;
        getline(cin, address);

        cout << "Введите тип косметики "  << i + 1 << ": " << endl;
        getline(cin, type);

        professionals[i] = professional(phone, address, w_h, type);
        cout << "Профессионал " << i + 1 << ": " << endl;
        professionals[i].print();
        cout << endl;

     }
    delete[] shops;
    delete[] professionals;

    return 0;
}
