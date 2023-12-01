#include "proto.hpp"

int main() {
    try {
        PrototypeFactory factory;

        Prototype* prototype1 = factory.createPrototype(1);
        prototype1->performAction();  // ConcretePrototype1: performAction

        Prototype* prototype2 = factory.createPrototype(2);
        prototype2->performAction();  // ConcretePrototype2: performAction

        Prototype* invalidPrototype = factory.createPrototype(3);  // Генерация исключения для проверки
    } catch (const std::exception& e) {
        Log::getInstance().writeLog("Exception caught: " + std::string(e.what()));
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}