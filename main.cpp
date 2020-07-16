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
    vector<int> a({2,3,4,5,1});

    sort(a.begin(), a.end());
    for (int s:a) {
        cout<<s;
    }

    return 0;
}
