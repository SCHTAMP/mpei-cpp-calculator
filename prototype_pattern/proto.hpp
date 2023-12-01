#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <iostream>
#include <fstream>
#include <unordered_map>

// Singleton класс Log для записи действий в файл
class Log {
private:
    std::ofstream file;

    Log() {
        file.open("log.txt");
    }

public:
    static Log& getInstance() {
        static Log instance;
        return instance;
    }

    void writeLog(const std::string& message) {
        file << message << std::endl;
    }
};

// Пример класса, поддерживающего паттерн Prototype
class Prototype {
public:
    virtual Prototype* clone() = 0;
    virtual void performAction() = 0;
};

// Пример конкретного класса, реализующего интерфейс прототипа
class ConcretePrototype1 : public Prototype {
public:
    Prototype* clone() override {
        Log::getInstance().writeLog("Cloning ConcretePrototype1");
        return new ConcretePrototype1(*this);
    }

    void performAction() override {
        Log::getInstance().writeLog("ConcretePrototype1: performAction");
        std::cout << "ConcretePrototype1: performAction" << std::endl;
    }
};

// Пример конкретного класса, реализующего интерфейс прототипа
class ConcretePrototype2 : public Prototype {
public:
    Prototype* clone() override {
        Log::getInstance().writeLog("Cloning ConcretePrototype2");
        return new ConcretePrototype2(*this);
    }

    void performAction() override {
        Log::getInstance().writeLog("ConcretePrototype2: performAction");
        std::cout << "ConcretePrototype2: performAction" << std::endl;
    }
};

// Пример класса, использующего прототипы для создания новых объектов
class PrototypeFactory {
private:
    std::unordered_map<int, Prototype*> prototypes;

public:
    PrototypeFactory() {
        prototypes[1] = new ConcretePrototype1();
        prototypes[2] = new ConcretePrototype2();
    }

    ~PrototypeFactory() {
        for (auto& pair : prototypes) {
            delete pair.second;
        }
    }

    Prototype* createPrototype(int type) {
        if (prototypes.find(type) != prototypes.end()) {
            return prototypes[type]->clone();
        }

        throw std::runtime_error("Invalid prototype type");
    }
};

#endif  // PROTOTYPE_H