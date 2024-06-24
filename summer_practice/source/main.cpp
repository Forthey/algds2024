#include <iostream>
#include <vector>

#include "FibonacciHeap.hpp"


std::vector<FibonacciHeap> heaps;

class CommandLineInterface {
    static void print(std::string const& what) {
        std::cout << what << std::endl;
    }

    static void printCommands() {
        print("0 - вывести это меню");
        print("1 <n> - отобразить n-ю кучу");
        print("2 <n> <x> - добавить элемент x в n-ю кучу");
        print("3 <n> <m> - объединить кучи n и m");
        print("4 <n> - удалить минимальный элемент из n-й кучи");
        print("5 - добавить еще одну кучу");
        print("6 - выход");
    }

    static void startInteraction() {
        char code;
        int n, m, x;
        do {
            std::cin >> code;
            if (code >= '1' && code <= '4') {
                std::cin >> n;
                if (code == '3') {
                    std::cin >> m;
                }
                else if (code == '2') {
                    std::cin >> x;
                }
            }
            switch (code) {
                case '0':
                    printCommands();
                    break;
                case '1':
                    if (n >= heaps.size()) {
                        print("Кучи с таким номером не существует");
                        break;
                    }
                    heaps[n].display();
                    break;
                case '2':
                    if (n >= heaps.size()) {
                        print("Кучи с таким номером не существует");
                        break;
                    }
                    heaps[n].insert(x);
                    break;
                case '3':
                    if (n >= heaps.size() || m >= heaps.size()) {
                        print("Кучи с таким номером не существует");
                        break;
                    }

                    heaps[n].merge(heaps[m]);
                    break;
                case '4':
                    if (n >= heaps.size()) {
                        print("Кучи с таким номером не существует");
                        break;
                    }

                    try {
                        x = heaps[n].removeMin();
                    }
                    catch (std::exception &e) {
                        print("Куча пустая");
                        break;
                    }
                    print("Удален элемент " + std::to_string(x));
                    break;
                case '5':
                    heaps.emplace_back();
                    break;
                case '6':
                    return;
                default:
                    print("Неизвестная команда");
                    break;
            }
        }
        while (true);
    }
public:
    static void begin() {
        print("Летняя практика, Дрекалов Никита, 5030102/20001");
        print("Фибоначчиева куча");
        printCommands();

        startInteraction();
    }
};



int main() {
    CommandLineInterface::begin();
    return 0;
}