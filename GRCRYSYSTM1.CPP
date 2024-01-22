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

Item vegetables[] = {{"Carrot", 1.0},   {"Broccoli", 1.2}, {"Spinach", 1.5},
                     {"Tomato", 2.0},   {"Cucumber", 1.8}, {"Bell Pepper", 1.3},
                     {"Zucchini", 1.7}, {"Lettuce", 1.0},  {"Onion", 1.2},
                     {"Potato", 1.5}};


// Function prototypes
void handleArrowKeys(char key, int& ctr, int size);

// Menu section functions
void mainUI(int ctr);
void itemSection(int ctr);

// automatic display
void displayItems(Item items[], int size, int ctr),
    displayOptions(char*options[], int size, int ctr);

// item section
void itemSectionFruits(int ctr), itemSectionMeats(int ctr),
    itemSectionVegetables(int ctr), menuSection(), loginSection();

int main() {
    clrscr();
    mainUI(0);
    clrscr();
    cout << ":)";

    getch();
    return 0;
}

void handleArrowKeys(char key, int& ctr, int size) {
    if (key == 80 && ctr == size - 1)
        ctr = 0;
    else if (key == 72 && ctr == 0)
        ctr = size - 1;
    else if (key == 80)
        ctr = ctr + 1;
    else if (key == 72)
        ctr = ctr - 1;
}

void displayItems(Item items[], int size, int ctr) {
    for (int x = 0; x < size; x++) {
        if (ctr == x) cout << ">";
        cout << items[x].name << endl;
    }
}

void displayOptions(char* options[], int size, int ctr) {
    for (int x = 0; x < size; x++) {
        if (ctr == x) cout << ">";
        cout << options[x] << endl;
    }
}

void mainUI(int ctr) {
    clrscr();
    cout << "arrow up, arrow down, space\n";
    char* options[] = {"Menu", "See Items", "Log in", "Exit"};
    int optionsSize = sizeof(options) / sizeof(options[0]);

    displayOptions(options, optionsSize, ctr);

    //----------KEYS conditional
    char key = getch();
    switch(key){
	case 'q': return;
	case 32: 
	if(ctr==1) itemSection(0);
	else if(ctr==0) menuSection();
	else if(ctr==3) return;
	else if(ctr==2) loginSection(); 
	return;
	
    }
    if (key == 'q')
	return;
    else if (key == 32 && ctr == 1) {
	itemSection(0);
	return;
    }
    handleArrowKeys(key, ctr, optionsSize);

    mainUI(ctr);  // Call mainUI, and arrow pointing at (ctr) index of options;
}

void itemSection(int ctr) {
    clrscr();
    cout << "arrow up, arrow down, space\n";
    char* options[] = {"Fruits", "Meats", "Vegetables"};  //!!!
    int optionsSize = sizeof(options) / sizeof(options[0]);

    displayOptions(options, optionsSize, ctr);

    //---------KEYS conditional
    char key = getch();
    handleArrowKeys(key, ctr, optionsSize);
    if (key == 'q')
        return;
    else if (key == 32) {
        switch (ctr) {
            case 0:itemSectionFruits(0);break;
            case 1:itemSectionMeats(0);break;
            case 2:itemSectionVegetables(0);break;
        }
	return;
    }
    itemSection(ctr);
}

void itemSectionVegetables(int ctr) {
    clrscr();
    cout << "arrow up, arrow down, space\n";
    cout << " q = quit\n";

    int numOfVegetables = sizeof(vegetables) / sizeof(vegetables[0]);
    displayItems(vegetables, numOfVegetables, ctr);

    char key = getch();
    if (key == 'q') return;  // quit
    handleArrowKeys(key, ctr, numOfVegetables);

    itemSectionVegetables(ctr);
}

void itemSectionFruits(int ctr) {
    clrscr();

    int numOfFruits = sizeof(fruits) / sizeof(fruits[0]);
    displayItems(fruits, numOfFruits, ctr);

    char key = getch();
    if (key == 'q') return;
    handleArrowKeys(key, ctr, numOfFruits);

    itemSectionFruits(ctr);
}

void itemSectionMeats(int ctr) {
    clrscr();

    int numOfMeats = sizeof(meats) / sizeof(meats[0]);
    displayItems(meats, numOfMeats, ctr);

    char key = getch();
    if (key == 'q') return;
    handleArrowKeys(key, ctr, numOfMeats);

    itemSectionMeats(ctr);
}
void menuSection(){
cout<<"MENU!";
getch();
}
void loginSection(){
cout<<"LOGIN!";
getch();
}
