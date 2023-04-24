#include<iostream>
#include<string>
#include<vector> //���������� ��� ������ � ��������
using namespace std;

class Butterfly //������ �����
{
public: //����������� �������
    int lifedays = 0; //���� ������ - ����� ���� ����� ����������
    string stagelife; //���� ������ - ������ �����

    Butterfly(string s, int d) {
        stagelife = s;
        lifedays = d;
    }

    void newstage() { //����� ������ - ��� �������� �� ����� ������ �����
        int a = 1; //���������� ��� �������� 1 ��� � �������� ����� �����

        //��������� �������� �������, ���� ��� ����� ����������� ��������� [0;7] - ��������
        if (lifedays >= 0 && lifedays <= 7) {
            stagelife = "��������";
            cout << "������ �����: " << stagelife << "\t" << endl;
            cout << "���� �����: " << lifedays + a << endl;

        }
        //��������� �������� �������, ���� ��� ����� ����������� ��������� [7;15] - ��������
        else if (lifedays >= 7 && lifedays <= 15) {
            stagelife = "�������";

            cout << "������ �����: " << stagelife << "\t" << endl;
            cout << "���� �����: " << lifedays + a << endl;

        }
        //��������� �������� �������, ���� ��� ����� ����������� ��������� [15;23] - ��������
        else if (lifedays >= 15 && lifedays <= 23) {
            stagelife = "�������";
            cout << "������ �����: " << stagelife << "\t" << endl;
            cout << "���� �����: " << lifedays + a << endl;

        }
        else if (lifedays == 24) {
            stagelife = "��������";

            lifedays = 0;   //>24 ���� - �������� 
            cout << "������ �����: " << stagelife << "\t" << endl;
            cout << "���� �����: " << lifedays + a << endl;

        }

    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    int b = 0;
    vector<Butterfly*>vec(b); //������� ������ ���������� �� ������� ������
    vec.push_back(new Butterfly("��������", 0));
    for (int i = 0; i < 10; i++) {
        vec.push_back(new Butterfly("��������", 0));
    }
    cout << "�������� ������: " << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << "������� " << i + 1 << ": ������ ����� - " << vec[i]->stagelife << ", ��� ����� - " << vec[i]->lifedays << endl;
    }
    for (int i = 0; i < vec.size(); i++) {
        vec[i]->newstage();
    }
    cout << "������������ ������: " << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << "������� " << i + 1 << ": ������ ����� - " << vec[i]->stagelife << ", ��� ����� - " << vec[i]->lifedays << endl;
    }
    return 0;
}