#include <iostream>
class Human
{
protected:
    std::string name;
    int age;
public:
    Human(std::string name_, int age_ = 0) : name(name_), age(age_)
    {
    }
    ~Human()
    {
    }
    std::string getName() const { return name; }
    int getAge() const { return age; }
};

class Sportmen : virtual public Human
{
protected:
    double gameAverage;
public:
    Sportmen(std::string name_, int age_, double gameAverage_) :
        Human(name_, age_), gameAverage(gameAverage_)
    {
    }
    ~Sportmen()
    {
    }
};

class BasketballPlayer : public Sportmen
{
protected:
    std::string club;
public:
    BasketballPlayer(std::string name_, int age_, double gameAverage_, std::string club_) :
        Human(name_, age_), Sportmen(name_, age_, gameAverage_), club(club_)
    {
    }
    ~BasketballPlayer()
    {
    }
};

class Student : virtual public Human
{
protected:
    int mark;
public:
    Student(int mark_, std::string name_, int age_) :
        Human(name_, age_), mark(mark_)
    {
    }
};

class Employee : public Student
{
protected:
    int salary;
public:
    Employee(int mark_, std::string name_, int age_, int salary_) :
        Human(name_, age_), Student(mark_, name_, age_), salary(salary_)
    {
    }
};

class Person : public Employee, public BasketballPlayer
{

public:
    Person(std::string name, int age, double gameAverage, std::string club, int mark, int salary) :
        Human(name, age), BasketballPlayer(name, age, gameAverage, club), Employee(mark, name, age, salary)
    {

    }
    void GetPerson() {
        std::cout << "Name : " << name << "\nage : " << age << "\ngameAverage: "
            << gameAverage << "\nclub: " << club << "\nmark: " << mark << "\nsalary: " << salary;
    }
};

int main()
{
    Person chel("Valera", 19, 20, "chb", 9, 500);
    chel.GetPerson();
    return 0;
}