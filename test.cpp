
#include <list>
#include <iostream>
#include <stdlib.h>

using namespace std;

int size = 30;
int smooth = 5;

float myavg(std::list<float> l) {
    float sum=0;
    for ( std::list<float>::iterator it = l.begin(); it != l.end(); ++it)
        sum+= *it;
    return sum / l.size();
}

int main() {
    std::list<float> dlist;
    std::list<float> sublist;

    while(1) {
        float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        sublist.push_front(r);
        float mavg = myavg(sublist);
        dlist.push_front(mavg);

        cout << "pushing: " << r << ", ";
        cout << "size: " << sublist.size() << ", ";
        cout << "avg: " << mavg << std::endl;

        cout << "pushing: " << mavg << ", ";
        cout << "dlist size: " << dlist.size() << ", ";
        cout << "dlist begin: " << dlist.front() << ", ";
        cout << "dlist end: " << dlist.back() << ", ";
        cout << std::endl;

        // smooth the first 5 values
        if (sublist.size()>=smooth)
            sublist.pop_back();

        // keep 30 readings
        if (dlist.size()>=size) 
            dlist.pop_back();

    }

    return 0;
}

