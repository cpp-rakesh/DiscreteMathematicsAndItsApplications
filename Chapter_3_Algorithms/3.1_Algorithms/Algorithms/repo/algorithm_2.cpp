/*
  Implementation of Algorithm 2
  Chapter 3.1 (Algorithms)
  Rakesh Kumar, cpp.rakesh(at)gmail.com
  Date: Jan 18th, 2017
 */

#include <cstdio>
#include <vector>
#include <cstdlib>

int random(int max, int min) {
    return min + rand() % (max - min + 1);
}

int search(const std::vector<int>& list, int x) {
    int pos = 0;
    
    for (std::size_t i = 0; i < list.size(); ++i) {
        if (list[i] == x) {
            pos = i + 1;
            break;
        }
    }
        
    return pos;
}

void print(const std::vector<int>& list) {
    for (std::size_t i = 0; i < list.size(); ++i)
        printf("%d ", list[i]);
    printf("\n");
}

std::vector<int> build_list() {
    const int min = 0;
    const int max = 100;
    std::vector<int> list;
    
    for (int i = 0; i < 50; ++i)
        list.push_back(random(min, max));
    
    return list;
}

void test_max() {
    const int x = 178;
    for (int i = 0; i < 10; ++i) {
        const std::vector<int> list = build_list();
        printf("--------------------------------------------------------------------------------\n");
        print(list);
        printf("Element [%d] found at [%d] location\n", x, search(list, x));
        printf("--------------------------------------------------------------------------------\n");
    }
}

int main() {
    test_max();
    
    return 0;
}
