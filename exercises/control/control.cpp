#include <iostream>

const unsigned int numbers[] { 1000001, 1000002, 1000003, 1000004, 1000005, 1000006, 1000007, 1000008, 1000009 };

bool isodd(unsigned int i) { return i % 2 == 1; }

void part1()
{
    unsigned int sum_odd = 0;
    unsigned int sum_even = 0;
    int v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    for (int idx : v) {
        unsigned int num = numbers[idx];
        (isodd(num) ? sum_odd : sum_even) += num;
    }
    std::cout << "Sums: odd = " << sum_odd << ", even = " << sum_even << "\n";
}

void part2()
{
    // print smallest n for which 1 + 2 + ... + n > 10000
    int sum = 0;
    int i = 0;
    while (true) {
        sum += ++i;
        if (sum > 10000) {
            std::cout << i << "\n";
            break;
        }
    }

    sum = 0;
    i = 0;
    do {
        sum += ++i;
    } while (sum <= 10000);
    std::cout << i << "\n";
}

enum class Language {
    English,
    French,
    German,
    Italian,
    Other
};

void part3(Language l)
{
    switch (l) {
    case Language::English:
        std::cout << "Hello\n";
        break;
    case Language::French:
        std::cout << "Salut\n";
        break;
    case Language::German:
        std::cout << "Hallo\n";
        break;
    case Language::Italian:
        std::cout << "Ciao\n";
        break;
    default:
        std::cout << "I don't speak your language\n";
    }
}

int main()
{
    part1();
    part2();
    part3(Language::English);
    return 0;
}
