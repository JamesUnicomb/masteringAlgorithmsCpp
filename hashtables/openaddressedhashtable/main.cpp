#include <iostream>
#include "oahtbl.hpp"
#include "../../utils/hashpjw.hpp"
#include "../../utils/djb2.hpp"

using namespace std;

int main()
{
    cout << "open addressed hash table example" << endl;

    string vacated = "vacated";
    OAHTbl<string, HashPJW, DJB2> oahtbl(11, &vacated);

    oahtbl.insert("bat");
    oahtbl.insert("cat");
    oahtbl.insert("dog");
    oahtbl.insert("snake");
    oahtbl.insert("cow");
    oahtbl.insert("chicken");
    oahtbl.insert("duck");
    oahtbl.insert("goat");
    oahtbl.insert("goose");
    oahtbl.insert("donkey");
    oahtbl.insert("owl");

    oahtbl.display();

    cout << "size = " << oahtbl.getSize() << endl;
    cout << "lookup(bat) = " << oahtbl.lookup("bat") << endl;
    cout << "lookup(wolf) = " << oahtbl.lookup("wolf") << endl;

    oahtbl.remove("dog");
    cout << "size = " << oahtbl.getSize() << endl;
    oahtbl.display();

    oahtbl.insert("gofer");
    cout << "size = " << oahtbl.getSize() << endl;
    oahtbl.display();
}