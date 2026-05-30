#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <cstddef>

using namespace std;


// Структура результата

struct FlaviusResult {
    vector<size_t> eliminatedOrder;
    size_t winner = 0;
};


// Прототипы функций
FlaviusResult flaviusJosephusOrder(size_t warriorsQuantity, size_t killIndex);
FlaviusResult flaviusJosephusMarkedArray(size_t warriorsQuantity, size_t killStep);
FlaviusResult flaviusJosephusIterator(size_t peopleCount, size_t k);
FlaviusResult getDeadMenQueryWithMap(size_t warriorsQuantity, size_t killStep);


// Визуализация

void visualizeFromResult(const FlaviusResult& result) {
    cout << "Eliminated order: ";
    for (auto x : result.eliminatedOrder) {
        cout << x << " ";
    }
    cout << "\nWinner: " << result.winner << "\n";
}


// main
int main() {
    size_t n = 10;
    size_t k = 3;

    cout << "=== flaviusJosephusOrder ===\n";
    visualizeFromResult(flaviusJosephusOrder(n, k));

    cout << "\n=== flaviusJosephusMarkedArray ===\n";
    visualizeFromResult(flaviusJosephusMarkedArray(n, k));

    cout << "\n=== flaviusJosephusIterator ===\n";
    visualizeFromResult(flaviusJosephusIterator(n, k));

    cout << "\n=== getDeadMenQueryWithMap ===\n";
    visualizeFromResult(getDeadMenQueryWithMap(n, k));

    return 0;
}


// 1. Реализация через deque
FlaviusResult flaviusJosephusOrder(size_t warriorsQuantity, size_t killIndex) {
    FlaviusResult result;

    if (warriorsQuantity == 0 || killIndex == 0) {
        return result;
    }

    deque<size_t> q;
    for (size_t i = 1; i <= warriorsQuantity; ++i) {
        q.push_back(i);
    }

    while (q.size() > 1) {
        size_t moves = (killIndex - 1) % q.size();

        for (size_t i = 0; i < moves; ++i) {
            q.push_back(q.front());
            q.pop_front();
        }

        result.eliminatedOrder.push_back(q.front());
        q.pop_front();
    }

    result.winner = q.front();
    return result;
}


// 2. Реализация через массив с пометкой 0

FlaviusResult flaviusJosephusMarkedArray(size_t warriorsQuantity, size_t killStep) {
    FlaviusResult result;

    if (warriorsQuantity == 0 || killStep == 0) {
        return result;
    }

    vector<size_t> circle(warriorsQuantity);
    for (size_t i = 0; i < warriorsQuantity; ++i) {
        circle[i] = i + 1;
    }

    size_t aliveCounter = warriorsQuantity;
    size_t steps = 0;
    size_t i = 0;

    while (aliveCounter > 1) {
        if (circle[i] != 0) {
            steps++;
            if (steps == killStep) {
                result.eliminatedOrder.push_back(circle[i]);
                circle[i] = 0;
                aliveCounter--;
                steps = 0;
            }
        }
        i = (i + 1) % warriorsQuantity;
    }

    for (size_t j = 0; j < warriorsQuantity; ++j) {
        if (circle[j] != 0) {
            result.winner = circle[j];
            break;
        }
    }

    return result;
}


// 3. Реализация через list + итератор
FlaviusResult flaviusJosephusIterator(size_t peopleCount, size_t k) {
    FlaviusResult result;

    if (peopleCount == 0 || k == 0) {
        return result;
    }

    list<size_t> people;
    for (size_t i = 1; i <= peopleCount; ++i) {
        people.push_back(i);
    }

    size_t counter = 0;
    auto it = people.begin();

    while (people.size() > 1) {
        if (it == people.end()) {
            it = people.begin();
        }

        counter++;

        if (counter % k == 0) {
            result.eliminatedOrder.push_back(*it);
            it = people.erase(it);
        } else {
            ++it;
        }
    }

    result.winner = people.front();
    return result;
}


// 4. Реализация через vector<bool>

FlaviusResult getDeadMenQueryWithMap(size_t warriorsQuantity, size_t killStep) {
    FlaviusResult result;

    if (warriorsQuantity == 0 || killStep == 0) {
        return result;
    }

    vector<bool> circle(warriorsQuantity, true);

    size_t aliveCounter = warriorsQuantity;
    size_t steps = 0;
    size_t i = 0;

    while (aliveCounter > 1) {
        if (circle[i]) {
            steps++;
            if (steps == killStep) {
                result.eliminatedOrder.push_back(i + 1);
                circle[i] = false;
                aliveCounter--;
                steps = 0;
            }
        }
        i = (i + 1) % warriorsQuantity;
    }

    for (size_t j = 0; j < warriorsQuantity; ++j) {
        if (circle[j]) {
            result.winner = j + 1;
            break;
        }
    }

    return result;
}
