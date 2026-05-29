#include <iostream>
using namespace std;

class RobotPath{
    private:
        int N;
        double** coords;
    public:
        RobotPath(int n) : N(n), coords(nullptr) {
            if (N > 0) {
                coords = new double*[N];
                for (int i = 0; i < N; ++i) {
                    coords[i] = new double[2];
                    coords[i][0] = 0.0;
                    coords[i][1] = 0.0;
                }
            }
        }

        RobotPath(const RobotPath& other) : N(other.N), coords(nullptr){
            if (N > 0) {
                coords = new double*[N];
                for (int i = 0; i < N; ++i) {
                    coords[i] = new double[2];
                    coords[i][0] = other.coords[i][0];
                    coords[i][1] = other.coords[i][1];
                }
            }
        }

        ~RobotPath() {
            if (coords!=nullptr){
                for(int i=1; i<N,++i){
                    delete[] coords[i];
                }
                delete[] coords;
            }
        }


        void setPoint(int index, double x, double y) {
            if (index >= 0 && index < N) {
                coords[index][0] = x;
                coords[index][1] = y;
            }
        }


        void print() const{
            for (int i = 0; i < N; ++i) {
                cout << "Point " << i << ": (" << coords[i][0] << ", " << coords[i][1] << ")" << endl;
            }
        }

        
};

void ProcessPath(RobotPath path){
            cout<<"Copy of the route: \n";
            path.print();
        }


int main(){
    RobotPath path(3);
    path.setPoint(0, 1.0, 2.0);
    path.setPoint(1, 3.0, 4.0);
    path.setPoint(2, 5.0, 6.0);

    cout << "Original route: \n";
    path.print();

    ProcessPath(path);

    return 0;
}