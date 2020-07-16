//#include <iostream>
//#include <stdexcept>
//#include <vector>
//#include <string>
//#include <map>
//#include "Sorting.cpp"
////#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//    vector<int> a({1,2,3,4,5});
//    string a('s');
//    a.erase(a.begin(), a.begin()+1);
//    cout<<a.size();
//    return 0;
//}

#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int main() {
    string s;
    s = "qwdqwd//dw/dw";
    std::stringstream dw(s);
    string temp;

    while (getline(dw, temp, '/')) {
        cout<< temp<<endl;
    }

    return 0;
}
