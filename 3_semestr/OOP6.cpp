#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class books{
    public:
        int number_UDK;
        string FIO;
        string title;
        int year;
        int number_requests;

    books(int _number_UDK, string _FIO, string _title, int _year, int _number_requests){
        number_UDK = _number_UDK;
        FIO = _FIO;
        title = _title;
        year = _year;
        number_requests = _number_requests;
    }

    int get_year()const{
        return year;
    }

    void print()const{
        cout << "Номер УДК: " << number_UDK << endl;
        cout << "Фамилия и инициалы автора: " << FIO <<endl;
        cout << "Название книги: " << title <<endl;
        cout << "Год издания: " << year <<endl;
        cout << "Количество обращений к книге: " << number_requests <<endl;
        cout<< "__________________________________________" << endl;
    }
};

void sort_year(queue <books> & q){
    if (q.empty()) return;
    
    vector<books> books_vec;
    while (!q.empty()) {
        books_vec.push_back(q.front());
        q.pop();
    }
    
    for (int i = 0; i < books_vec.size() - 1; i++) {
        for (int j = 0; j < books_vec.size() - 1 - i; j++) {
            if (books_vec[j].get_year() > books_vec[j + 1].get_year()) {
                swap(books_vec[j], books_vec[j + 1]);
            }
        }
    }
    for (const auto& book : books_vec) {
        q.push(book);
    }
    cout << "Очередь отсортирована" << endl;
}
void remove_books(queue <books> & q, int min_requests){
    queue <books> temp;
    while(!q.empty()){
        books current = q.front();
        q.pop();
        if (current.number_requests >= min_requests){
            temp.push(current);
        }
    }
    while(!temp.empty()){
        q.push(temp.front());
        temp.pop();
    }
    cout << "Удалены книги с количеством обращений меньше " << min_requests<<endl;
}

void print_queue(queue<books> &q){
    cout << "**********************************************" << endl;
    cout << "Список книг:" << endl;
    cout << "**********************************************" << endl;
    queue <books> temp = q;
    while(!temp.empty()){
        temp.front().print();
        temp.pop();
    }
}

int main(){

    queue<books> book_queue;
    book_queue.push(books(692, "Климов М.А", "Ад Климовна Остапова", 1933, 5));
    book_queue.push(books(123, "Пушкин А.С", "Евгений Онегин", 1833, 15));
    book_queue.push(books(456, "Толстой Л.Н", "Война и мир", 1869, 8));
    book_queue.push(books(789, "Достоевский Ф.М", "Преступление и наказание", 1866, 3));
    print_queue(book_queue);

    sort_year(book_queue);
    print_queue(book_queue);

    remove_books(book_queue, 4);
    print_queue(book_queue);
    
    return 0;
}