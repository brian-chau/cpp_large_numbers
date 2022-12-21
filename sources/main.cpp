#include <iostream>
#include <memory>

#include "Fibonacci.h"
#include "Menu.h"

int main() {
    std::vector<std::string> choices{"Fibonacci with Algorithm",
                                     "Fibonacci using GMP built-in function",
                                     "Exit"};

    std::unique_ptr<Menu> menu(new Menu(choices));
    int choice = menu->HandleMenu();
    std::unique_ptr<Fibonacci> fib = std::make_unique<Fibonacci>();
    switch (choice) {
        case 0:
            std::cout << fib->FibAlgorithm(30000000) << std::endl;
            break;
        case 1:
            fib->FibBuiltIn(30000000);
            break;
        default:
            std::cout << "Invalid selection!" << std::endl;
            break;
    }
    return 0;
}
