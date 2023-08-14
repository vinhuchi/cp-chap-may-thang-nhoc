#include <iostream>
#include <queue>
#include <set>

int main() {
    std::priority_queue<int> max_heap;
    std::set<int> unique_values;

    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            break;
        }

        if (line[0] == '+') {
            int value = std::stoi(line.substr(1));
            if (max_heap.size() < 15000) {
                max_heap.push(value);
                unique_values.insert(value);
            }
        } else if (line[0] == '-') {
            if (!max_heap.empty()) {
                int max_value = max_heap.top();
                max_heap.pop();
                unique_values.erase(max_value);
            }
        }
    }

    std::cout << unique_values.size() << std::endl;
    for (auto it = unique_values.rbegin(); it != unique_values.rend(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}