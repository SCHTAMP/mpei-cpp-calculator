#include <iostream>

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
    };

    Node* head;
    int size;

public:
    DoublyLinkedList() {
        head = nullptr;
        size = 0;
    }

    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addElement(const T& value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }

        size++;
    }

    void removeElementByIndex(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Invalid index!" << std::endl;
            return;
        }

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
        } else {
            Node* current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            Node* prevNode = current->prev;
            Node* nextNode = current->next;
            prevNode->next = nextNode;
            if (nextNode != nullptr) {
                nextNode->prev = prevNode;
            }
            delete current;
        }

        size--;
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    int findElement(const T& value) {
        Node* current = head;
        int index = 0;
        while (current != nullptr) {
            if (current->data == value) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }
};

int main() {
    DoublyLinkedList<int> list;

    list.addElement(1);
    list.addElement(2);
    list.addElement(3);
    list.addElement(4);
    list.addElement(5);
    
    
    std::cout << "List:" << std::endl; 
    list.printList();

    int tofind = 3;
    int index = list.findElement(tofind);

    std::cout << "Element " << tofind << " found at index: " << index << std::endl;
    int toRemove = 2;
    list.removeElementByIndex(toRemove);
    std::cout << "Removing element ad index: " << toRemove << std::endl; 
    
    std::cout << "List:" << std::endl; 
    list.printList();

    return 0;
}
