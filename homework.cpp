#include<iostream>
#include<string>
#include<vector> //библиотека дл€ работы с вектором
using namespace std;

class Butterfly //задаем класс
{
public: //модификатор доступа
    int lifedays = 0; //поле класса - число дней жизни насекомого
    string stagelife; //поле класса - стади€ жизни

    Butterfly(string s, int d) {
        stagelife = s;
        lifedays = d;
    }

    void newstage() { //метод класса - дл€ перевода на новую стадию жизни
        int a = 1; //переменна€ дл€ прибавки 1 дн€ к текущему сроку жизни

        //выполн€ем проверку условий, если дни жизни принадлежат диапазону [0;7] - гусеница
        if (lifedays >= 0 && lifedays <= 7) {
            stagelife = "√усеница";
            cout << "—тади€ жизни: " << stagelife << "\t" << endl;
            cout << "ƒень жизни: " << lifedays + a << endl;

        }
        //выполн€ем проверку условий, если дни жизни принадлежат диапазону [7;15] - гусеница
        else if (lifedays >= 7 && lifedays <= 15) {
            stagelife = " уколка";

            cout << "—тади€ жизни: " << stagelife << "\t" << endl;
            cout << "ƒень жизни: " << lifedays + a << endl;

        }
        //выполн€ем проверку условий, если дни жизни принадлежат диапазону [15;23] - гусеница
        else if (lifedays >= 15 && lifedays <= 23) {
            stagelife = "Ѕабочка";
            cout << "—тади€ жизни: " << stagelife << "\t" << endl;
            cout << "ƒень жизни: " << lifedays + a << endl;

        }
        else if (lifedays == 24) {
            stagelife = "√усеница";

            lifedays = 0;   //>24 дней - гусеница 
            cout << "—тади€ жизни: " << stagelife << "\t" << endl;
            cout << "ƒень жизни: " << lifedays + a << endl;

        }

    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    int b = 0;
    vector<Butterfly*>vec(b); //создаем вектор указателей на объекты класса
    vec.push_back(new Butterfly("гусеница", 0));
    for (int i = 0; i < 10; i++) {
        vec.push_back(new Butterfly("гусеница", 0));
    }
    cout << "»сходный вектор: " << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << "Ѕабочка " << i + 1 << ": стади€ жизни - " << vec[i]->stagelife << ", дни жизни - " << vec[i]->lifedays << endl;
    }
    for (int i = 0; i < vec.size(); i++) {
        vec[i]->newstage();
    }
    cout << "ѕолучившийс€ вектор: " << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << "Ѕабочка " << i + 1 << ": стади€ жизни - " << vec[i]->stagelife << ", дни жизни - " << vec[i]->lifedays << endl;
    }
    return 0;
}