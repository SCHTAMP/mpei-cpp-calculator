#ifndef FACADE_H
#define FACADE_H

#include <iostream>
#include <fstream>

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

// Subsystem 1
class Subsystem1 {
public:
    void operation1() {
        Log::getInstance().writeLog("Subsystem1: operation1");
        std::cout << "Subsystem1: operation1" << std::endl;
    }

    void operation2() {
        Log::getInstance().writeLog("Subsystem1: operation2");
        std::cout << "Subsystem1: operation2" << std::endl;
    }
};

// Subsystem 2
class Subsystem2 {
public:
    void operation1() {
        Log::getInstance().writeLog("Subsystem2: operation1");
        std::cout << "Subsystem2: operation1" << std::endl;
    }

    void operation2() {
        Log::getInstance().writeLog("Subsystem2: operation2");
        std::cout << "Subsystem2: operation2" << std::endl;
    }
};

// Facade класс, объединяющий работу с несколькими подсистемами
class Facade {
private:
    Subsystem1 subsystem1;
    Subsystem2 subsystem2;

public:
    void doSomething() {
        try {
            Log::getInstance().writeLog("Facade: doSomething");
            subsystem1.operation1();
            subsystem2.operation1();
            subsystem1.operation2();
            subsystem2.operation2();
            throw std::runtime_error("Something went wrong");
        } catch (const std::exception& e) {
            Log::getInstance().writeLog("Exception caught: " + std::string(e.what()));
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }
};

#endif  // FACADE_H