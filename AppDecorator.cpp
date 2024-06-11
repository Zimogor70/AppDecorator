//На основе примера
//Создайте декоратор для расчёта стоимости напитка с лимоном, с корицей, с мороженым
#include <iostream>
#include <string>

using namespace std;

class Beverage {
public:
	virtual ~Beverage() = default;
	virtual double cost() = 0;
	virtual string getDescription() = 0;
};

class Tea : public Beverage {
public:
	double cost() { return 1.99; }
	string getDescription() { return "Tea"; }
};

class Coffee : public Beverage {
public:
	double cost() { return 1.49; }
	string getDescription() { return "Coffee"; }
};

class BeverageDecorator : public Beverage {
protected:
	Beverage* beverage;
public:
	BeverageDecorator(Beverage* b) : beverage(b) {};
	double cost() { return beverage->cost(); }
	string getDescription() { return beverage->getDescription(); }
};

class WithMilk : public BeverageDecorator {
public:
	WithMilk(Beverage* b) : BeverageDecorator(b) {};
	double cost() { return BeverageDecorator::cost() + 0.50; }
	string getDescription() { return BeverageDecorator::getDescription() + ", Milk"; }
};

class WithSugar : public BeverageDecorator {
public:
	WithSugar(Beverage* b) : BeverageDecorator(b) {};
	double cost() { return BeverageDecorator::cost() + 0.20; }
	string getDescription() { return BeverageDecorator::getDescription() + ", Sugar"; }
};

class WithLemon : public BeverageDecorator {
public:
	WithLemon(Beverage* b) : BeverageDecorator(b) {};
	double cost() { return BeverageDecorator::cost() + 0.30; }
	string getDescription() { return BeverageDecorator::getDescription() + ", Lemon"; }
};

class WithCinnamon : public BeverageDecorator {
public:
	WithCinnamon(Beverage* b) : BeverageDecorator(b) {};
	double cost() { return BeverageDecorator::cost() + 0.35; }
	string getDescription() { return BeverageDecorator::getDescription() + ", Cinnamon"; }
};

class WithIceCream : public BeverageDecorator {
public:
	WithIceCream(Beverage* b) : BeverageDecorator(b) {};
	double cost() { return BeverageDecorator::cost() + 0.55; }
	string getDescription() { return BeverageDecorator::getDescription() + ", Ice Cream"; }
};

int main() {
	Beverage* beverage = new Coffee();
	beverage = new WithMilk(beverage);
	beverage = new WithSugar(beverage);

	std::cout << beverage->getDescription() << ": $" << beverage->cost() << std::endl;
	delete beverage;

	Beverage* tea = new Tea();
	tea = new WithSugar(tea);
	tea = new WithLemon(tea);
	tea = new WithCinnamon(tea);

	std::cout << tea->getDescription() << ": $" << tea->cost() << std::endl;

	delete tea;
}

