#include "Module.h"
#include "SimpleIterator.h"
#include "NewtonIterator.h"

int main()
{
    double x0, e;
    int N, M, choice;
    cout << "select" << endl;
    cout << "0. Exit." << endl;
    cout << "1.Simple Iterator Method." << endl;
    cout << "2.Newtondownhill Iterator Method." << endl;
    cin >> choice;
    switch( choice ){
        case 0:
        {
            exit(0);
        }
        case 1:
        {
            cout << "Simple Iterator Method" << endl;
            cout << "input the x0, e and N" << endl;
            cin >> x0 >> e >> N;
            Sim_iterator(x0, e, N);
            break;
        }
        case 2:
        {
            cout << "Newtondownhill Iterator Method" << endl;
            cout << "input the x0, e, N and M" << endl;
            cin >> x0 >> e >> N >> M;
            Newton_Iterator(x0, e, N, M);
            break;
        }
    }
}