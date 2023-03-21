#include <iostream>
#include <vector>
#include <random>

int main() {
    std::vector<int> v;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> add_dist(15, 30);
    std::uniform_int_distribution<> remove_dist(4, 9);

    int num_to_add = add_dist(gen);
    for (int i = 0; i < num_to_add; ++i) {
        v.push_back(i);
    }

    int num_to_remove = remove_dist(gen);
    for (int i = 0; i < num_to_remove; ++i) {
        if (!v.empty()) {
            v.pop_back();
        }
    }

    while (v.size() <= 125) {
        num_to_add = add_dist(gen);
        std::cout << "removing " << num_to_remove << "\n";
        for (int i = 0; i < num_to_add; ++i) {
            v.push_back(i);
        }

        num_to_remove = remove_dist(gen);
        std::cout << "remove " << num_to_remove << "\n";
        for (int i = 0; i < num_to_remove; ++i) {
            if (!v.empty()) {
                v.pop_back();
            }
        }
    }

    std::cout << "Vector size: " << v.size() << std::endl;
    std::cout << "\n";
    for (int i : v) {
        std::cout << i << " ";
    }

    return 0;
}