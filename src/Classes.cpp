#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <random>

std::mutex vector_mutex;

// Adds a random number of integers (between 15 and 30) to the vector
void add_integers(std::vector<int>& v) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(15, 30);
    std::uniform_int_distribution<> dis2(1, 100);

    while (v.size() < 125) {
        int num_integers_to_add = dis(gen);
        std::cout << "adding " << num_integers_to_add << "\n";
        std::vector<int> ints_to_add(num_integers_to_add);
        for (int i = 0; i < num_integers_to_add; ++i) {
            ints_to_add[i] = dis2(gen);
        }
        {
            std::lock_guard<std::mutex> lock(vector_mutex);
            v.insert(v.end(), ints_to_add.begin(), ints_to_add.end());
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

// Removes a random number of integers (between 4 and 9) from the vector
void remove_integers(std::vector<int>& v) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(4, 9);

    while (v.size() < 125) {
        int num_integers_to_remove = dis(gen);
        {   
            std::cout << "removing " << num_integers_to_remove << "\n";
            std::lock_guard<std::mutex> lock(vector_mutex);
            if (v.size() >= num_integers_to_remove) {
                v.erase(v.begin(), v.begin() + num_integers_to_remove);
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

int main() {
    std::vector<int> v;
    std::thread add_thread(add_integers, std::ref(v));
    std::thread remove_thread(remove_integers, std::ref(v));
    add_thread.join();
    remove_thread.join();
    std::cout << "Final size of the vector: " << v.size() << std::endl;
    std::cout << "\n";
    for (int i : v) {
        std::cout << i << " ";
    }
    return 0;
}