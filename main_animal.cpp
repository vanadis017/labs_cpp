#include <iostream>
#include <string>

using namespace std;

class Animal {
private:
    string name;
    int age;
public:
    Animal(const string& name, int age) : name(name), age(age) {

    }
    void eat() const {
        cout << name << " is eating." << endl;
    }
    void sleep() const {
        cout << name << " is sleeping." << endl;
    }
    
    string getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }

};

class Dog : public Animal {
protected:
    string breed;
    bool trained;

    bool isTrained() const {
        return trained;
    }
public:
    
    Dog(const string& name, int age, const string& breed, bool trained) : Animal(name, age), breed(breed), trained(trained) {
    }

    void bark() const {
        cout << "[Dog] " << getName() << " лает: Гав-гав!\n";
    }

    void status() const {
        cout << "[Dog Status] Имя: " << getName()
            << ", Возраст: " << getAge()
            << ", Порода: " << breed
            << ", Дрессировка: " << (trained ? "Да" : "Нет") << "\n";
    }
};

class Cat : public Animal {
protected:
    bool isIndoor;

public:
    
    Cat(const string& name, int age, bool isIndoor) : Animal(name, age), isIndoor(isIndoor) {
    }

    void meow() const {
        cout << "[Cat] " << getName() << " мяукает.\n";
    }

    void purr() const {
        cout << "[Cat] " << getName() << " урчит.\n";
    }

    void status() const {
        cout << "[Cat Status] Имя: " << getName()
            << ", Возраст: " << getAge()
            << ", Содержится дома: " << (isIndoor ? "Да" : "Нет") << "\n";
    }

};

class Trainable {
public:
    virtual ~Trainable() = default;
    virtual void performCommand(const string& cmd) {
        cout << "[Trainable] Выполняю базовую команду: " << cmd << "\n";
    }
};

class GuideDog : public Dog, public Trainable {
public: 
    GuideDog(const std::string& name, int age, const std::string& breed, bool trained)
        : Dog(name, age, breed, trained) {
    }

    void guide() const {
        cout << "[GuideDog] Поводырь " << getName() << " осторожно ведёт хозяина.\n";
    }

    
    void performCommand(const string& cmd) override {
        if (!isTrained()) {
            cout << "[GuideDog] " << getName() << " не может выполнить \"" << cmd
                << "\", так как не прошла курс дрессировки!\n";
            return;
        }

        cout << "[GuideDog] Поводырь-профессионал " << getName() << " слушает: ";
        Trainable::performCommand(cmd);
    }
};

void feed(const Animal& a) {
    a.eat();
}

int main() {
    setlocale(LC_ALL, "Russian");

   
    GuideDog tyzic("Тузик", 4, "Дворняга", true);
    tyzic.eat();
    cout << "Адрес начала GuideDog (tyzic): " << &tyzic << "\n";
    tyzic.bark();
    tyzic.status();
    tyzic.guide();
    tyzic.performCommand("Вперёд");

    Trainable& asTrainable = tyzic;
    cout << "Адрес подобъекта Trainable:       " << &asTrainable << "\n";
    Animal& asAnimal = tyzic;
    asAnimal.eat();
    feed(tyzic);

    Dog& asDog = tyzic;
    asDog.bark();

    Trainable* trainPtr = &tyzic;
    GuideDog* castedGuide = dynamic_cast<GuideDog*>(trainPtr);

    if (castedGuide != nullptr) {
        cout << "[Success] dynamic_cast прошёл успешно!\n";
        (*castedGuide).guide(); 
    }
    else {
        cout << "[Failure] dynamic_cast вернул nullptr.\n";
    }

    tyzic.Trainable::performCommand("Лежать");

    GuideDog novice("Новичок", 1, "Овчарка", false);
    novice.performCommand("Ищи");

    Cat barsik("Барсик", 3, true);
    barsik.sleep();
    barsik.meow();
    barsik.status();

    return 0;
}