#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class rhomb {
    private:

    int diagonal1;
    int diagonal2;

    public:

    rhomb(){
        diagonal1 = 1;
        diagonal2 = 2;
    }

    rhomb(int d1, int d2){
        diagonal1 = d1;
        diagonal2 = d2;
    }

    double square() const {
        return (diagonal1 * diagonal2) / 2.0;
    }

    bool isSquare() const {
        return diagonal1 == diagonal2;
    }
    int getDiagonal1() const { 
        return diagonal1; 
    }
    int getDiagonal2() const { 
        return diagonal2; 
    }

    void print() const {
        cout << "Ромб с диагоналями: " << diagonal1 << " и " << diagonal2;
        cout << ", Площадь: " << square();
        if (isSquare()) {
            cout << " (квадрат)";
        }
        cout << endl;
    }
};

int main(){
    int K;
    cout << "Введите количество ромбов: ";
    cin >> K;

    rhomb* rhombuses = new rhomb[K];

    for (int i = 0; i < K; i++) {
        int d1, d2;
        cout << "Введите диагонали для ромба " << i + 1 << " (d1 d2): ";
        cin >> d1 >> d2;
        rhombuses[i] = rhomb(d1, d2);
    }

    int k1 = 0;
    for (int i = 0; i < K; i++) {
        if (rhombuses[i].isSquare()) {
            k1++;
        }
    }

    if (K > 0) {
        int minIndex = 0;
        double minArea = rhombuses[0].square();

        for (int i = 1; i < K; i++) {
            if (rhombuses[i].square() < minArea) {
                minArea = rhombuses[i].square();
                minIndex = i;
            }
        }

        cout << "\nРезультаты:" << endl;
        cout << "Количество квадратов (k1): " << k1 << endl;
        cout << "Ромб с минимальной площадью:" << endl;
        rhombuses[minIndex].print();
        cout << "Минимальная площадь: " << minArea << endl;
    } else {
        cout << "Не создано ни одного ромба!" << endl;
    }

    delete[] rhombuses;

    return 0;
}