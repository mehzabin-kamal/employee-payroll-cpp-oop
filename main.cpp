#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;
    double salary;

public:
    Employee(string n, int i, double s) {
        name = n;
        id = i;
        salary = s;
    }

    virtual double calculateSalary() {
        return salary;
    }

    virtual void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << calculateSalary() << endl;
    }
};

class Manager : public Employee {
    double bonus;

public:
    Manager(string n, int i, double s, double b) : Employee(n, i, s) {
        bonus = b;
    }

    double calculateSalary() {
        return salary + bonus;
    }

    void display() {
        cout << "\nManager Details" << endl;
        Employee::display();
        cout << "Bonus: " << bonus << endl;
    }
};

class Developer : public Employee {
    double allowance;

public:
    Developer(string n, int i, double s, double a) : Employee(n, i, s) {
        allowance = a;
    }

    double calculateSalary() {
        return salary + allowance;
    }

    void display() {
        cout << "\nDeveloper Details" << endl;
        Employee::display();
        cout << "Allowance: " << allowance << endl;
    }
};

class Intern : public Employee {
public:
    Intern(string n, int i, double s) : Employee(n, i, s) {}

    void display() {
        cout << "\nIntern Details" << endl;
        Employee::display();
    }
};

int main() {
    Manager m("Mehzabin Kamal", 101, 50000, 10000);
    Developer d("Ayesha Rahman", 102, 40000, 5000);
    Intern i("Nadia Islam", 103, 15000);

    m.display();
    d.display();
    i.display();

    return 0;
}
