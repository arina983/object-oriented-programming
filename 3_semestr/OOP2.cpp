#include <iostream>
#include <cmath>
using namespace std;

class triangle {
    protected: 
        int side_1;
        int side_2;
        int side_3;
    public: 
    triangle() : side_1(1), side_2(1), side_3(1) {}

    triangle(int s_1, int s_2, int s_3){
        side_1 = s_1; 
        side_2 = s_2; 
        side_3 = s_3;
         if (s_1 <= 0 || s_2 <= 0 || s_3 <= 0) {
            cout << "Стороны треугольника должны быть положительными" << endl;
        }
    }

     bool isTriangle() const {
        return (side_1 > 0 && side_2 > 0 && side_3 > 0 && side_1 + side_2 > side_3 && side_1 + side_3 > side_2 && side_2 + side_3 > side_1);
    }

    int perimeter_triangle() const {
        if (!isTriangle()) {
            cout<<"невозможно вычислить периметр"<< endl;
            return 0;
        }
        return side_1 + side_2 + side_3;
    } 

    double Square_triangle() const {
        if (!isTriangle()) {
            cout<<"невозможно вычислить площадь"<< endl;
            return 0;
        }
        double poluperimeter = perimeter_triangle() / 2.0;
        double square = sqrt(poluperimeter * (poluperimeter - side_1) * (poluperimeter - side_2) * (poluperimeter - side_3));
        return square;
    } 

    void print() const {
        cout<< "Длина стороны 1: " << side_1 << "\n";
        cout<< "Длина стороны 2: " << side_2 << "\n";
        cout<< "Длина стороны 3: " << side_3 << "\n";
        cout<< "Периметр треугольника: " << perimeter_triangle() << "\n";
        cout<< "Площадь треугольника: " << Square_triangle() << "\n";
    }
};
    class equilateral_triangle : public triangle {
    public:
    equilateral_triangle() : triangle(1, 1, 1) {}
        equilateral_triangle(int es_1) : triangle(es_1, es_1, es_1) {
            if (es_1 <= 0) {
                cout<<"Все стороны равностороннего треугольника должны быть положительными "<< endl;
            }
        }

        bool isTriangle() const {
            return triangle::isTriangle();
        }
       
    void print() const {
        cout<< "Длина стороны 1: " << side_1 << endl;
        cout<< "Длина стороны 2: " << side_2 << "\n";
        cout<< "Длина стороны 3: " << side_3 << "\n";
        cout<< "Периметр равностороннего треугольника: " << perimeter_triangle() << endl;
        cout<< "Площадь равностороннего треугольника: " << Square_triangle() << endl;
        }
    };

int main(){
    int K, L;
    cout<< "Введите количество треугольников: "<< endl;
    cin >> K;
    triangle* triangles = new triangle[K];
    int valid_triangles = 0;
    for (int i = 0; i < K; i++) {
        int s_1, s_2, s_3;
        cout << "Введите стороны треугольника " << i + 1 << ": " << endl;
        cin >> s_1 >> s_2 >> s_3;
        triangles[i] = triangle(s_1, s_2, s_3);
    }

    cout<< "Введите количество равносторонних треугольников: "<< endl;
    cin >> L;
    equilateral_triangle* equil_triangles = new equilateral_triangle[L];
    for (int i = 0; i < L; i++) {
        int es_1;
        cout << "Введите сторону равностороннего треугольника " << i + 1 << ": " << endl;
        cin >> es_1;
        equil_triangles[i] = equilateral_triangle(es_1);
    }

    double total_area = 0.0;
    for (int i = 0; i < K; i++) {
        total_area += triangles[i].Square_triangle();
    }
    double avg_area = (K > 0) ? total_area / K : 0.0;
    cout << "Средняя площадь треугольников: " << avg_area << endl;

    double max_area = 0.0;
    int max_index = -1;
    for (int i = 0; i < L; i++) {
        double area = equil_triangles[i].Square_triangle();
        if (area > max_area) {
            max_area = area;
            max_index = i;
        }
    }

    if (max_index != -1) {
        cout << "Наибольший равносторонний треугольник: " << endl;
        equil_triangles[max_index].print();
    } else {
        cout << "Нет равносторонних треугольников" << endl;
    }

    delete[] triangles;
    delete[] equil_triangles;

    return 0;
}