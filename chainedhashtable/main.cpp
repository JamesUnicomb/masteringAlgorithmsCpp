#include <iostream>
#include "chtbl.hpp"

using namespace std;

int main()
{
    cout << "chained hash table example" << endl;

    CHTbl<string, HashPJW> chtbl(11);
    chtbl.insert("bat");
    chtbl.insert("cat");
    chtbl.insert("dog");
    chtbl.insert("snake");
    chtbl.insert("cow");
    chtbl.insert("chicken");
    chtbl.insert("duck");
    chtbl.insert("goat");

    cout << "size = " << chtbl.getSize() << endl;
    cout << "lookup(bat) = " << chtbl.lookup("bat") << endl;
    cout << "lookup(rat) = " << chtbl.lookup("rat") << endl;

    cout << "size = " << chtbl.getSize() << endl;
    cout << "lookup(dog) = " << chtbl.lookup("dog") << endl;
    chtbl.remove("dog");
    cout << "size = " << chtbl.getSize() << endl;
    cout << "lookup(dog) = " << chtbl.lookup("dog") << endl;

    cout << "display:" << endl;
    chtbl.display();
}