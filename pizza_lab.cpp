#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pizza {
private:
    string size = "medium";
    string dough = "thin";
    string sauce = "tomato";
    vector<std::string> toppings;

public:
    Pizza() = default;

    Pizza& setSize(const std::string& newSize) {
        size = newSize;
        return *this;
    }

    Pizza& setDough(const std::string& newDough) {
        dough = newDough;
        return *this;
    }

    Pizza& setSauce(const std::string& newSauce) {
        text_sauce = newSauce;
        return *this;
    }

    Pizza& addTopping(const std::string& topping) {
        toppings.push_back(topping);
        return *this;
    }

    int getPrice() const {
        int basePrice = 0;
        if (size == "small") basePrice = 300;
        else if (size == "medium") basePrice = 500;
        else if (size == "large") basePrice = 700;

        return basePrice + (toppings.size() * 50);
    }

    friend std::ostream& operator<<(std::ostream& os, const Pizza& pizza) {
        os << pizza.size << ", " << pizza.dough << ", " << pizza.sauce << "\n";
        if (pizza.toppings.empty()) {
            os << "(no toppings)\n";
        }
        else {
            for (size_t i = 0; i < pizza.toppings.size(); ++i) {
                os << pizza.toppings[i];
                if (i < pizza.toppings.size() - 1) {
                    os << ", ";
                }
            }
            os << "\n";
        }
        os << "Price: " << pizza.getPrice();
        return os;
    }
private:
    std::string text_sauce = "tomato";
};

class Order {
private:
    int orderNumber;
    std::string clientName;
    std::vector<Pizza> pizzaList;

public:
    Order(int number, const std::string& name) : orderNumber(number), clientName(name) {}

    void addPizza(const Pizza& pizza) {
        pizzaList.push_back(pizza);
    }

    int totalPrice() const {
        int total = 0;
        for (const auto& pizza : pizzaList) {
            total += pizza.getPrice();
        }
        return total;
    }

    size_t count() const {
        return pizzaList.size();
    }

    friend std::ostream& operator<<(std::ostream& os, const Order& order) {
        os << "====== Order #" << order.orderNumber << " ======\n";
        os << "Client: " << order.clientName << "\n\n";
        for (const auto& pizza : order.pizzaList) {
            os << pizza << "\n";
        }
        return os;
    }
};

int main() {
    Order order(1, "Anna");

    Pizza pizza1;
    pizza1.setSize("large")
        .setDough("thick")
        .setSauce("bbq")
        .addTopping("mushrooms")
        .addTopping("olives")
        .addTopping("pepperoni");

    Pizza pizza2;
    pizza2.setSize("small");

    Pizza pizza3;
    pizza3.addTopping("mozzarella");

    order.addPizza(pizza1);
    order.addPizza(pizza2);
    order.addPizza(pizza3);

    std::cout << order;

    return 0;
}