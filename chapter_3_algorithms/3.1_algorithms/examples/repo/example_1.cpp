#include <cstdio>
#include <vector>
#include <cstdlib>

int random(int max, int min) {
    return min + rand() % (max - min + 1);
}

int max(const std::vector<int>& list) {
    int max = list[0];
    int i = 1;
    int j = list.size() - 1;

    while (i < j) {
        if (list[i] > max)
            max = list[i];
        if (list[j] > max)
            max = list[j];
        ++i;
        --j;
    }

    if (i == j && list[i] > max)
        max = list[i];

    return max;
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
    for (int i = 0; i < 10; ++i) {
        const std::vector<int> list = build_list();
        printf("--------------------------------------------------------------------------------\n");
        print(list);
        printf("Maximum from the above list is == [%d]\n", max(list));
        printf("--------------------------------------------------------------------------------\n");
    }
}

int main() {
    test_max();
    
    return 0;
}