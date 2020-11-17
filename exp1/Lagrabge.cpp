#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

float get_y(float);
void get_message(float&, int&, float&, float&);
float get_basicFunc(int, float, float *, float *);

int main()
{
    float length = 0.0, point1, point2;
    int n = 0;
    //get the necessary information
    get_message(length, n, point1, point2);
    //get the original data
    float x[11] = {0.0}, y[11] = {0.0};
    int i = 0;
    for(int x0 = -5; x0 <= 5; x0++) {
        x[i] = (float)x0;
        y[i] = get_y( (float)x0 );
        i++;
    }
    //main process
    /*******************/
    vector<float> basic_func(11, 1.0);
    vector<float>::iterator it = basic_func.begin();
    int count = 0;
    float result = 0.0;
    while( it != basic_func.end() ) {
        *it = get_basicFunc(count, point1, x, y);
        it++;
        count++;
    }
    it = basic_func.begin();
    for(int i = 0; i < 11; i++) {
        result += *it * y[i];
        it++;
    }
    cout << "the result of " << point1 << " is " << result << endl;
    float exact_y = 1.0 / (1 + point1 * point1);
    cout << "the exact value of the point is " << exact_y << endl;
    cout << "the error is " << ( exact_y - result ) << endl; 
    count = 0;
    it = basic_func.begin();
    while( it != basic_func.end() ) {
        *it = get_basicFunc(count, point2, x, y);
        it++;
        count++;
    }
    result = 0.0;
    it = basic_func.begin();
    for(int i = 0; i < 11; i++) {
        result += basic_func[i] * y[i];
    }
    cout << "the result of " << point2 << " is " << result << endl;
    exact_y = 1.0 / (1 + point2 * point2);
    cout << "the exact value of the point is " << exact_y << endl;
    cout << "the error is " << ( exact_y - result )  << endl; 
    /******************/
}

float get_y(float x)
{
    return 1.0 / (1 + pow(x, 2.0));
}

void get_message(float &length, int &n, float &point1, float &point2)
{
    cout << "input the length" << endl;
    cin >> length;
    cout << "input the number of points" << endl;
    cin >> n;
    cout << "input the expected points" << endl;
    cin >> point1 >> point2;
}

float get_basicFunc(int count, float target_point, float* x, float* y)
{
    float high = 1.0, low = 1.0;
    for(int i = 0; i < 11; i++) {
        if( i != count ) {
            high *= ( target_point - x[i] );
            low *= ( x[count] - x[i] );
        } else {
            high = high;
            low = low;
        }
    }
    return (high / low);
}