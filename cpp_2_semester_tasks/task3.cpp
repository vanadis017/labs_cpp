#include <iostream>
#include <stdexcept>

using namespace std;


class Cargo{
    public:
    virtual ~Cargo() = default;
    virtual double getWeight() const = 0;
};

class HeavyContainer : public Cargo{
    private:
        double weight;
    public:
        HeavyContainer(double w){
            if (w<=0.0){
                throw invalid_argument("Weight must be positive");  
            }
            weight = w;
        }
        double getWeight() const override {
            return weight;
        }
};


int main(){
    try{
        HeavyContainer c1(100.0);
        cout<<"Weight of c1: "<<c1.getWeight()<<endl;

        HeavyContainer c2(0.0);
        cout<<"Weight of c2: "<<c2.getWeight()<<endl;
    }
    catch(const invalid_argument& e){
        cerr<<"Error: "<<e.what()<<endl;
    }
}