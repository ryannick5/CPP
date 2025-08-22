
#include <iostream>
#include <string>

using namespace std;

    int Exp = 1;
    int Health = 10;
    int OppHealth = 2;
    string Opp = "";
    string Name = "";
    int AttckMag = 1;
	int AttckPhys = 1;
	string Item1 = "";
	string Item2 = "";
	string Item3 = "";

int Pickup (string Item, int ItemNum) {
    if (ItemNum == 1) {
        Item1 = Item;
    } else if (ItemNum == 2) {
        Item2 = Item;
    } else if (ItemNum ==3) {
        Item3 = Item;
    }
}

int Drop (string Item, int DropNum) {
    if (DropNum == 1) {
        Item1 = "";
    } else if (DropNum == 2) {
        Item2 = "";
    } else if (DropNum ==3) {
        Item3 = "";
    }
}

void Encounter () {
    switch (Exp) {
        case 1:
            Opp = "Slime";
            OppHealth = 2;
        break;
        case 2:
            Opp = "Goblin";
            OppHealth = 9;
        break;
        case 3:
            Opp = "Golem";
            OppHealth = 38;
        break;
        case 4:
            Opp = "Dragon";
            OppHealth = 176;
        break;
    }
}

int main()
{
    cout << "-=<Hello! Welcome to Dungeron Explorer>=-\n" 
         << "Created By: Ryan Nickelman\n\n";
    cout << "What is your name? "
    cin >> Name;
    cout << "Welcome " << Name << "!\n\n"
         << "You can now choose your starter item: ";
    
    
	return 0;
}


