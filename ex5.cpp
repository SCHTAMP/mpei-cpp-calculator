/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

struct Heap {
    private:
        // std::vector<int> A;
        const int max = 100;
        int A[100];
        int last_index = -1, first_index = -1;
        
        
        int PARENT(int i) {
            return (i - 1) / 2;
        }
        
        int LEFT(int i) {
            return (2*i + 1);
        };
        
        int RIGHT(int i) {
            return (2*i + 2);
        };
        
        void heapify_down(int i) {
            int left = LEFT(i);
            int right = RIGHT(i);
            
            int smallest = i;
            
            if (left < size() && A[left] < A[i]) {
                smallest = left;
            };
            
            if (right < size() && A[right] < A[smallest]) {
                smallest = right;
            };
            
            if (smallest != i) {
                swap(A[i], A[smallest]);
                heapify_down(smallest);
            };
        };
        
        void heapify_up(int i) {
            if (i && A[PARENT(i)] > A[i]) {
                swap(A[i], A[PARENT(i)]);
                heapify_up(PARENT(i));
            };
        };
        
    public:
        unsigned int size() {
            // return A.size();
            return end(A)-begin(A);
        };
        
        bool empty() {
            return size() == 0;
        };
        
        void push(int key) {
            // A.push_back(key);
            
            last_index++;
            A[last_index] = key;
            
            int index = size() - 1;
            
            heapify_up(index);
        };
        
        void pop() {
            try {
                if (size() == 0) {
                    throw out_of_range("Index out of Vector(Heap) range");
                };
                
                // A[0] = A.back();
                // A.pop_back();
                
                first_index++;
                
                heapify_down(0);
            } 
            catch (const out_of_range &e) {
                cout << endl << "Error (out of range):" << endl << e.what() << endl;
            };
        };
        
        int top() {
            try {
                if (size() == 0) {
                    throw out_of_range("Index out of Vector(Heap) range");
                };
                
                // return A.at(0);
                return A[first_index];
            } 
            catch (const out_of_range &e) {
                cout << endl << "Error (out of range):" << endl << e.what() << endl;
            };
        };
};

int main()
{
    Heap h;
    
    h.push(3);
    h.push(2);
    h.push(15);
    
    cout << "Size: " << h.size() << endl;
    
    cout << "Top value: " << h.top() << endl;
    h.pop();
    cout << "Size after pop: " << h.size() << endl;
    
    h.push(5);
    h.push(6);
    h.push(45);
    
    cout << "Size after push: " << h.size() << endl;
    
    cout << h.top() << " ";
    h.pop();
    cout << h.top() << " ";
    h.pop();
    cout << h.top() << " ";
    h.pop();
    cout << h.top() << " ";
    h.pop();
    
    cout << endl << "Is empty: " << h.empty() << endl;
    
    cout << endl << "Last value: " << h.top();
    h.pop();
    
    cout << endl << "Is empty: " << h.empty() << endl;
    
    h.top();
    h.pop();
    

    return 0;
}
