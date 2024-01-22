#include <conio.h>
#include <iomanip.h>
#include <iostream.h>
#include <string.h>

class Item {
   public:
    char name[100];
    double price;
    int quantity;
};
 // name, price
Item meats[] = {{"Beef", 5.0},   {"Chicken", 3.5}, {"Pork", 4.2},
                {"Lamb", 6.0},   {"Turkey", 4.8},  {"Salmon", 7.5},
                {"Shrimp", 6.2}, {"Bacon", 5.3},   {"Sausage", 4.5},
                {"Ham", 5.8}};

Item fruits[] = {{"Apple", 2.0},     {"Orange", 1.5},     {"Banana", 1.2},
                 {"Grape", 2.5},     {"Kiwi", 3.0},       {"Mango", 2.8},
                 {"Pineapple", 4.0}, {"Strawberry", 2.2}, {"Watermelon", 5.5},
                 {"Pear", 2.3}};

void mainUI(int ctr), itemSection(int ctr), itemSectionFruits(int ctr),
    itemSectionMeats(int ctr);    //displays something

int main() {
    clrscr();

    mainUI(0);
    
    clrscr();
    cout<<":)";

    getch();
    return 0;
}

void mainUI(int ctr) {
    clrscr();
    cout<<"arrow up, arrow down, space\n";
    char *options[] = {"Menu", "See Items", "Log in", "Exit"};
    int optionsSize = sizeof(options) / sizeof(options[0]);
    for (int x = 0; x < optionsSize; x++) {
        if (ctr == x) cout << ">";  // ----*
        cout << options[x] << "\n";
    }
    //----------KEYS conditional

    char key = getch();
    if (key == 80 && ctr == optionsSize - 1)
        ctr = 0;  // Arrow Up pressed when pointing at last option, it returns
                  // to first option
    else if (key == 72 && ctr == 0)
        ctr = optionsSize - 1;  // Arrow Down pressed when pointing at first
                                // option, it returns to last option
    else if (key == 80)
        ctr = ctr + 1;  // Arrow Up, points at next option
    else if (key == 72)
        ctr = ctr - 1;  // Arrow Down, points at next option
    else if (key == 'q')
        return;
    else if (key == 32 && ctr == 1) {
        itemSection(0);
        return;
    }
    mainUI(ctr);  // Call mainUI, and arrow pointing at (ctr) index of options;
}

void itemSection(int ctr) {
    clrscr();
    cout<<"arrow up, arrow down, space\n";
    char *options[] = {"Fruits", "Meats"};  //!!!
    int optionsSize = sizeof(options) / sizeof(options[0]);
    for (int x = 0; x < optionsSize; x++) {
        if (ctr == x) cout << ">";
        cout << options[x] << "\n";
    }
    //---------KEYS conditional

    char key = getch();
    if (key == 80 && ctr == optionsSize - 1)
        ctr = 0;  // Arrow Up pressed when pointing at last option, it returns
                  // to first option
    else if (key == 72 && ctr == 0)
        ctr = optionsSize - 1;  // Arrow Down pressed when pointing at first
                                // option, it returns to last option
    else if (key == 80)
        ctr = ctr + 1;  // Arrow Up, points at next option
    else if (key == 72)
        ctr = ctr - 1;  // Arrow Down, points at next option
    else if (key == 'q')
        return;
    else if (key == 32) {
        switch (ctr) {
            case 0:
                itemSectionFruits(0);
                break;
            case 1:
                itemSectionMeats(0);
                break;
        }
        return;
    }
    itemSection(ctr);
}

void itemSectionFruits(int ctr) {
    clrscr();
    cout<<"arrow up, arrow down, space\n";
    cout<<" q = quit\n";
    int numOfFruits = sizeof(fruits) / sizeof(fruits[0]);
    for (int x = 0; x < numOfFruits; x++) {
        if (ctr == x) cout << ">";
        cout << fruits[x].name << endl;
    }

    // KEYS conditional
    char key = getch();
    if (key == 80 && ctr == numOfFruits - 1)
        ctr = 0;  // Arrow Up pressed when pointing at last option, it returns
                  // to first option
    else if (key == 72 && ctr == 0)
        ctr = numOfFruits - 1;  // Arrow Down pressed when pointing at first
                                // option, it returns to last option
    else if (key == 80)
        ctr = ctr + 1;  // Arrow Up, points at next option
    else if (key == 72)
        ctr = ctr - 1;  // Arrow Down, points at next option
    else if (key == 'q')
        return;  // quit
    itemSectionFruits(ctr);
}
void itemSectionMeats(int ctr) {
    clrscr();
    cout<<" q = quit\n";
    int numOfMeats = sizeof(meats) / sizeof(meats[0]);
    for (int x = 0; x < numOfMeats; x++) {
        if (ctr == x) cout << ">";
        cout << meats[x].name << endl;
    }

    // KEYS conditional
    char key = getch();
    if (key == 80 && ctr == numOfMeats - 1)
        ctr = 0;  // Arrow Up pressed when pointing at last option, it returns
                  // to first option
    else if (key == 72 && ctr == 0)
        ctr = numOfMeats - 1;  // Arrow Down pressed when pointing at first
                               // option, it returns to last option
    else if (key == 80)
        ctr = ctr + 1;  // Arrow Up, points at next option
    else if (key == 72)
        ctr = ctr - 1;  // Arrow Down, points at next option
    else if (key == 'q')
        return;  // quit
    itemSectionMeats(ctr);
}
