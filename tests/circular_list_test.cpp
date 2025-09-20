#include <iostream>
#include "../src/CircularList.hpp"

void testEmptyList() {
    CircularList<int> list;
    std::cout << "Test: Empty list - ";
    if (list.isEmpty() && list.size() == 0) {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "FAIL" << std::endl;
    }
}

void testAppend() {
    CircularList<int> list;
    list.append(10);
    list.append(20);
    list.append(30);
    
    std::cout << "Test: Append - ";
    if (list.size() == 3) {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "FAIL" << std::endl;
    }
}

void testGetCurrent() {
    CircularList<std::string> list;
    list.append("Hello");
    
    std::cout << "Test: Get current - ";
    try {
        if (list.getCurrent() == "Hello") {
            std::cout << "PASS" << std::endl;
        } else {
            std::cout << "FAIL" << std::endl;
        }
    } catch (...) {
        std::cout << "FAIL" << std::endl;
    }
}

void testStep() {
    CircularList<int> list;
    list.append(10);
    list.append(20);
    list.append(30);
    
    list.reset();
    int first = list.getCurrent();
    list.step();
    int second = list.getCurrent();
    list.step();
    int third = list.getCurrent();
    list.step();
    int backToFirst = list.getCurrent();
    
    std::cout << "Test: Step - ";
    if (first == 10 && second == 20 && third == 30 && backToFirst == 10) {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "FAIL" << std::endl;
    }
}

void testCircular() {
    CircularList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    
    list.reset();
    for (int i = 0; i < 3; i++) {
        list.step();
    }
    
    std::cout << "Test: Circular - ";
    if (list.getCurrent() == 1) {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "FAIL" << std::endl;
    }
}

int main() {
    std::cout << "Running Circular List Tests:" << std::endl;
    std::cout << "============================" << std::endl;
    
    testEmptyList();
    testAppend();
    testGetCurrent();
    testStep();
    testCircular();
    
    std::cout << "\nTesting with Monopoly spaces:" << std::endl;
    std::cout << "=============================" << std::endl;
    
    CircularList<std::string> board;
    board.append("Go");
    board.append("Mediterranean Avenue");
    board.append("Community Chest");
    
    board.reset();
    std::cout << "Space 0: " << board.getCurrent() << std::endl;
    board.step();
    std::cout << "Space 1: " << board.getCurrent() << std::endl;
    board.step();
    std::cout << "Space 2: " << board.getCurrent() << std::endl;
    board.step();
    std::cout << "Back to: " << board.getCurrent() << std::endl;
    
    return 0;
}
