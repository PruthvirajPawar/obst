

#include <iostream>
using namespace std;

class OBST {
        int n;
        int P[10], Q[10];
        char identifier[10][7];
        int W[10][10], C[10][10], R[10][10];
    public:
        void input();
        void find_OBST();
        void display();
        void print_tree(int, int);
};

void OBST::input() {
    cout << "Enter value of N: " << endl;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cout << "Enter value of identifier" << endl;
        cin >> identifier[i];
    }
    cout << "Enter probability of successful search:" << endl;
    
    for(int i = 1; i <= n; i++) {
        cout << "Enter probability P " << i << endl;
        cin >> P[i];
    }
    
    for(int i = 0; i <= n; i++) {
        cout << "Enter probability Q " << i << endl;
        cin >> Q[i];
    }
}

void OBST::find_OBST() {
    for(int i = 0; i <= n; i++) {
        W[i][i] = Q[i];
        C[i][i] = R[i][i] = 0;
    }

    for(int x = 1; x <= n; x++) {
        for(int i = 0, j = x; j <= n; i++, j++) {
            W[i][j] = P[j] + Q[j] + W[i][j - 1];

            int min = 999, index;
            for(int k = (i + 1); k <= j; k++) {
                if((C[i][k - 1] + C[k][j]) < min) {
                    min = C[i][k - 1] + C[k][j];
                    index = k;
                }
            }
            C[i][j] = min + W[i][j];
            R[i][j] = index;
        }
    }
}

void OBST::display() {
    for(int x = 0; x <= n; x++) {
        cout << "\t";
        for(int i = 0, j = x; j <= n; i++, j++) {
            cout << "\tW: " << W[i][j];
        }
        cout << endl;

        cout << "\tN: " << x;
        for(int i = 0, j = x; j <= n; i++, j++) {
            cout << "\tC: " << C[i][j];
        }

        cout << endl;
        cout << "\t";
        for(int i = 0, j = x; j <= n; i++, j++) {
            cout << "\tR: " << R[i][j];
        }
        cout << endl;
        cout << endl;
    }
    cout << endl;
    cout << endl << "Cost of the OBST " << C[0][n];
    cout << endl << "Root of the OBST " << R[0][n] << ": " << identifier[R[0][n]];
    print_tree(0, 4);
    cout << endl;
}

void OBST::print_tree(int i, int j) {
    if(i < j) {
        int k = R[i][j];
        cout << endl <<"Identifier : a" << k << ": " << identifier[k];
        print_tree(i, k - 1);
        print_tree(k, j);
    }
}

int main() {
    OBST obj;
    obj.input();
    obj.find_OBST();
    obj.display();
    return 0;
}
