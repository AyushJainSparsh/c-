#include<iostream>
using namespace std;

class stu
{
    private : int id , mark ;

    public : void input()
    {
        cout << "Enter id and marks" << endl;
        cin >> id >> mark;
    }

    public : void display()
    {
        cout << "id = " << id << endl;
        cout << "Marks = " << mark << endl;
    }
};

int main()
{
    stu t;
    t.input();
    t.display();
    return 0;
}