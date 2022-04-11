#include <iostream>
#include <vector>
using namespace std;

//int main()
//{
//    vector<int> myvector;
//    myvector.push_back(3);
//    myvector.push_back(4);
//    myvector.push_back(1);
//    myvector.push_back(7);
//    myvector.push_back(2);
//    // Vector becomes 3, 4, 1, 7, 2
//
//    for (auto x : myvector) cout << x << ' ';
//    cout << endl;
//    cout << myvector.front() << endl;
//    cout << myvector.back() << endl;
//    for (auto x : myvector) cout << x << ' ';
//
//    myvector.pop_back();
//    cout << endl;
//
//    for (auto x : myvector) cout << x << ' ';
//
//    myvector.push_back(2);
//    cout << endl;
//
//    for (auto x : myvector) cout << x << ' ';
//
//    cout << endl;
//    cout << myvector[1] << endl;
//    cout << myvector.at(1) << endl;
//    
//
//
//    vector<int> vector1{ 1,2,3,4,5,6,7,8 };
//    
//    //size
//    cout << vector1.size() << endl;
//
//    //clear
//    for (auto x : vector1) cout << x << ',';
//    puts("\n===========clear ==============");
//    vector1.clear();
//    for (auto x : vector1) cout << x << ',';
//    
//
//    puts("\n===========at==============");
//
//    //at
//    vector1 = { 1,2,3,4,5,6,7,8 };
//    for (auto x : vector1) cout << x << ',';
//    cout << endl;
//    cout <<"vector1.at(2) = " <<vector1.at(2) << endl;
//    cout <<"vector1[2] = " <<vector1[2] << endl;
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
//    vector1.insert(vector1.begin(), 100);
//    for (auto x : vector1) cout << x << ',';
//    vector1.insert(vector1.begin(), 3, 123);
//    for (auto x : vector1) cout << x << ',';
//
//    vector<int> vector2;
//    vector2.push_back(111);
//    vector2.push_back(222);
//    vector2.push_back(333);
//    cout << "Vector1: ";
//    for (auto x : vector1) cout << x << ',';
//    vector1.insert(vector1.begin(), vector2.begin(), vector2.end());
//    cout << "insert-> Vector1: ";
//    for (auto x : vector1) cout << x << ',';
//
//    //erase
//    for (auto x : vector1) cout << x << ',';
//    vector1.erase(vector1.begin());
//    cout << "erase -> ";
//    for (auto x : vector1) cout << x << ',';
//
//    vector1.erase(vector1.begin(), vector1.end());
//    for (auto x : vector1) cout << x << ',';
//    
//    puts("\n===========reserve==============");
//    //reserve
//    vector1.reserve(14);
//    for (auto x : vector1) cout << x << ',';
//
//    return 0;
//}