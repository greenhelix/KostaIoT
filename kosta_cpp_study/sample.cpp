#include <iostream>
#include <vector>
using namespace std;

//int main() {
//    vector<int> vector1{ 1,2,3,4,5,6,7,8 };
//   
//    cout << "vector1 : ";
//    for (auto x : vector1) cout << x << ',';
//    cout << endl;
//
//    //size
//    cout << "vector size: " << vector1.size() << endl;
//
//    //clear
//    puts("\n===========clear ==============");
//    vector1.clear();
//    cout << "vector1 : ";
//    for (auto x : vector1) cout << x << ',';
//    cout << endl;
//
//
//    puts("\n===========at==============");
//
//    //at
//    vector1 = { 1,2,3,4,5,6,7,8 };
//    for (auto x : vector1) cout << x << ',';
//    cout << endl;
//    cout << "vector1.at(2) = " << vector1.at(2) << endl;
//    cout << "vector1[2] = " << vector1[2] << endl;
//
//
//    //empty
//    puts("\n===========empty==============");
//    for (auto x : vector1) cout << x << ',';
//    bool vEmpty = vector1.empty();
//    string check = vEmpty ? "True" : "False";
//
//    cout << endl;
//    cout << "Is it Empty? " << endl;
//    cout << check << endl;
//
//    //swap
//    puts("\n===========swap==============");
//    vector<char> test1{ 'a', 'b','c','d' };
//    vector<char> test2{ 'A', 'B', 'C', 'D' };
//
//    cout << "test1 = ";
//    for (char c : test1) cout << c << ',';
//    cout << endl;
//    cout << "test2 = ";
//    for (char c : test2) cout << c << ',';
//    cout << endl;
//
//    puts("\n swap!!!! \n");
//    test1.swap(test2);
//
//    cout << "test1 = ";
//    for (char c : test1) cout << c << ',';
//    cout << endl;
//    cout << "test2 = ";
//    for (char c : test2) cout << c << ',';
//    cout << endl;
//
//    //insert
//    puts("\n===========insert==============");
//
//    vector1.insert(vector1.begin(), 100);
//
//    cout << "vector1 : ";
//    for (auto x : vector1) cout << x << ',';
//    cout << endl;
//
//    vector1.insert(vector1.begin()+1, 3, 123);
//
//    cout << "vector1 : ";
//    for (auto x : vector1) cout << x << ',';
//    cout << endl;
//
//    //push
//    puts("\n===========push_back==============");
//    
//    vector1 = { 1,2,3,4,5,6,7,8 };
//
//    cout << "vector1 : ";
//    for (auto x : vector1) cout << x << ',';
//    cout << endl;
//
//    vector1.push_back(111);
//    vector1.push_back(222);
//    vector1.push_back(333);
//
//    cout << "vector1 : ";
//    for (auto x : vector1) cout << x << ',';
//    cout << endl;
//
//    //pop_back
//    puts("\n===========pop_back==============");
//
//    vector1.pop_back();
//    vector1.pop_back();
//    vector1.pop_back();
//
//    cout << "vector1 : ";
//    for (auto x : vector1) cout << x << ',';
//    cout << endl;
//
//    //erase
//    puts("\n===========erase==============");
//
//    vector1.clear();
//    vector1 = { 1,2,3,4,5,6,7,8 };
//    cout << "vector1 : ";
//    for (auto x : vector1) cout << x << ',';
//    cout << endl;
//
//    vector1.erase(vector1.begin());
//    cout << "erase -> ";
//    for (auto x : vector1) cout << x << ',';
//    cout << endl;
//
//    cout << "index = 2~4 erase -> ";
//    vector1.erase(vector1.begin()+2, vector1.end()-2);
//    for (auto x : vector1) cout << x << ',';
//
//    puts("\n===========reserve/capacity==============");
//    //reserve
//
//    vector1 = { 1,2,3,4,5,6,7,8 };
//    cout << "vector size: " << vector1.size() << endl;
//    cout << "vector capacity: " << vector1.capacity() << endl;
//
//    vector1.push_back(9);
//    cout << "vector size: " << vector1.size() << endl;
//    cout << "vector capacity: " << vector1.capacity() << endl;
//
//    vector1.reserve(13);
//    cout << "reserve -> ";
//    for (auto x : vector1) cout << x << ',';
//    cout << endl;
//    cout << "vector size: " << vector1.size() << endl;
//    cout << "vector capacity: " << vector1.capacity() << endl;
//
//    return 0;
//}