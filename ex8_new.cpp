#include <iostream>
#include <functional>
#include <unordered_map>
#include <vector>
#include <chrono>
#include <thread>

// #define DEBUG_PRINT_2 1


/// EX1
std::unordered_map<int, int> generateAssociativeMap(const std::vector<int>& inputList) {
    std::unordered_map<int, int> resultMap;

    for (const auto& item : inputList) {
        int key = item;
        resultMap[key]++;
    }

    return resultMap;
}
/// EX1


/// EX2
template<typename F>
long long timeMe(F func) {
    auto start = std::chrono::high_resolution_clock::now();

    func();

    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

void exampleFunction() {
    using namespace std::this_thread;
    using namespace std::chrono;
    for (int i = 0; i < 10000; ++i) {
        #ifdef DEBUG_PRINT_2
            std::cout << " " << i * i << " ";
        #else
            sleep_for(nanoseconds(5));
        #endif
    }
    #ifdef DEBUG_PRINT_2
        std::cout << std::endl;
    #endif
}
/// EX2


/// EX3
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

void deleteBinaryTree(TreeNode* &root)
{
    if (root == nullptr) {
        return;
    }
 
    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);
 
    delete root;
 
    root = nullptr;
}

void recursiveTreeGet(TreeNode* node, std::function<void(int)> func) {
    if (node != nullptr) {
        func(node->value);
        recursiveTreeGet(node->left, func);
        recursiveTreeGet(node->right, func);
    }
}
/// EX3

void ex1() {
    std::vector<int> inputList = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 7, 5, 3, 1};

    std::unordered_map<int, int> result = generateAssociativeMap(inputList);

    std::cout << "EX 1 Start:" << std::endl;
    for (const auto& pair : result) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    std::cout << "EX 1 End" << std::endl << std::endl;
};

void ex2() {
    long long executionTime = timeMe(exampleFunction);
    std::cout << "EX 2 Start:" << std::endl;
    std::cout << "Время выполнения exampleFunction: " << executionTime << " мс" << std::endl;
    std::cout << "EX 2 End" << std::endl << std::endl;
};

void ex3() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    
    auto printValue = [](int val) {
        std::cout << val << " ";
    };

    std::cout << "EX 3 Start:" << std::endl;
    recursiveTreeGet(root, printValue);
    std::cout << std::endl << "EX 3 End" << std::endl;
    
    deleteBinaryTree(root);
};

int main() {
    ex1();
    ex2();
    ex3();
    return 0;
}

