#include <iostream>
#include <cmath>
using namespace std;

struct complex_number {
    double x;
    double y;
};

double module(complex_number z){
    return sqrt(z.x*z.x + z.y*z.y);
}

int main(){
    int N;
    cout << "Введите кол-во комплексных чисел"<<"\n";
    cin >> N;

    complex_number numbers[N];

    for (int i = 0; i < N; i ++) {
        cout <<"Введите дествительную и мнимую части числа: ";
        cin >> numbers[i].x >> numbers[i].y;
    }

    int max_ind;
    int min_ind;
    double max_mod = module(numbers[0]);
    double min_mod = module(numbers[0]);

    for (int i = 0; i < N; i ++){
        double mod = module(numbers[i]);
        if (mod > max_mod) {
            max_mod = mod;
            max_ind = i;
        }
        if (mod < min_mod){
            min_mod = mod; 
            min_ind = i;
        }
    }    

    cout << "Число с наибольшим модулем: " << max_mod << "\n";
    cout << "число с наименьшим модулем: " << min_mod << "\n";
    cout << numbers[min_ind].x << " + " << numbers[min_ind].y << "i" << endl;

    return 0;
}