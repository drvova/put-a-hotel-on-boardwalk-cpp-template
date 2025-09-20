#include <iostream>
#include <fstream>
#include <string>
#include "src/CircularList.hpp"

int main() {
    CircularList<std::string> board;
    
    std::ifstream file("../monopoly_spaces.txt");
    if (!file) {
        std::cout << "Error: Could not open monopoly_spaces.txt" << std::endl;
        return 1;
    }
    
    std::string space;
    while (std::getline(file, space)) {
        if (space != "") {
            board.append(space);
        }
    }
    file.close();
    
    std::cout << "Monopoly Board has " << board.size() << " spaces:" << std::endl;
    std::cout << "=====================================" << std::endl;
    
    board.reset();
    for (int i = 0; i < board.size(); i++) {
        std::cout << i << ": " << board.getCurrent() << std::endl;
        board.step();
    }
    
    std::cout << "\nTesting circular movement:" << std::endl;
    std::cout << "==========================" << std::endl;
    
    board.reset();
    std::cout << "Start: " << board.getCurrent() << std::endl;
    
    for (int i = 1; i <= 5; i++) {
        board.step();
        std::cout << "Step " << i << ": " << board.getCurrent() << std::endl;
    }
    
    std::cout << "\nGoing around the board once:" << std::endl;
    std::cout << "=============================" << std::endl;
    
    board.reset();
    std::cout << "Start at: " << board.getCurrent() << std::endl;
    
    for (int i = 0; i < board.size(); i++) {
        board.step();
    }
    std::cout << "After " << board.size() << " steps: " << board.getCurrent() << std::endl;
    
    return 0;
}
