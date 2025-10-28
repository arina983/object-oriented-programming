#include <iostream>
#include <list>

using namespace std;

class books{
    protected:
        int number_UDK;
        string FIO;
        string title;
        int year;
        int number_copies;

    public:
    books(int _number_UDK, string _FIO, string _title, int _year, int _number_copies){
        number_UDK = _number_UDK;
        FIO = _FIO;
        title = _title;
        year = _year;
        number_copies = _number_copies;
    }
    void set_number_UDK(int _number_UDK){
        number_UDK = _number_UDK;
    }
    void set_FIO(string _FIO){
        FIO = _FIO;
    }
    void set_title(string _title){
        title = _title;
    }
    void set_year(int _year){
        year = _year;
    }
    void set_number_copies(int _number_copies){
        number_copies = _number_copies;
    }
    int get_number_UDK()const{
        return number_UDK;
    }
    string get_FIO()const{
        return FIO;
    }
    string get_title()const{
        return title;
    }
    int get_year()const{
        return year;
    }
    int get_number_copies()const{
        return number_copies;
    }
    void print()const{
        cout << "Номер УДК: " << number_UDK << endl;
        cout << "Фамилия и инициалы автора: " << FIO <<endl;
        cout << "Название книги: " << title <<endl;
        cout << "Год издания: " << year <<endl;
        cout << "Количество экземпляров данной книги в библиотеке: " << number_copies <<endl;
        cout<< "_____________________________________________" << endl;
    }
};
list <books> book_list;

void add_book(int number_UDK, string FIO, string title, int year, int number_copies) {
    books new_book(number_UDK, FIO, title, year, number_copies);
    auto it = book_list.begin();
    while (it != book_list.end() && it-> get_year() < year){
        ++it;
    }
    book_list.insert(it, new_book);
    cout << "Книга с названием " << title << " добавлена" << endl;
}
void search_spisok(const string& title){
    bool found = false;
    for(const auto& book: book_list){
        if(book.get_title() == title){
            book.print();
            found = true;   
        }
    }if(!found){
    cout << "Книга с названием " << title << " не найдена." << endl;
    }
}
void delete_book(int number_UDK){
    bool found = false;
    auto it = book_list.begin();
    while (it != book_list.end()) {
        if (it->get_number_UDK() == number_UDK) {
            it = book_list.erase(it);
            cout << "Удалена книга: " << it->get_title() << endl;
            found = true;
        } else {
            ++it;
        }
    }if(!found){
    cout << "Книга с УДК " << number_UDK << " не найдена." << endl;
    }
}

void print_all_books(){
    if (book_list.empty()) {
        cout << "Библиотека пуста." << endl;
        return;
    }
    cout << "*************ВСЕ КНИГИ В БИБЛИОТЕКЕ***************" << endl;
    for(const auto& book: book_list){
        book.print();
    }
}

int main(){

    add_book(692, "Климов М.А", "Ад Климовна Остапова", 1933, 5);
    add_book(333, "Иванов А.Б", "Джентельмены", 1988, 6);
    add_book(555, "Сидоров И.Д", "Жизнь замечательных людей", 2001, 7);

    print_all_books();
    
    cout << "-------------ПОИСК КНИГИ------------- " << endl;
    search_spisok("Жизнь замечательных людей");
    search_spisok("Несуществующая книга");

    cout << "------------ДОБАВЛЕНИЕ КНИГИ-----------" << endl;
    add_book(999, "Петров В.Г.", "Искусственный интеллект", 2021, 2);

    cout << "------------УДАЛЕНИЕ КНИГИ-------------" << endl;
    delete_book(333);
    delete_book(456);

    print_all_books();

    return 0;
}