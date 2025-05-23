#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;
using namespace this_thread;

int playChoice;
int renChoice1;
int renChoice2;
int barChoice1;
int barChoice2;
int classChoice1;
int classChoice2;
int romChoice1;
int romChoice2;
int modChoice1;
int modChoice2;
int Gold;
int Influence;

vector<string> Territory;

int renResult(int renChoice)
{
    switch (renChoice)
    {
    case 1:
        cout << "While the popularity of your new piece, the Cantiones quae ab\n"
             << "argumento sacrae vocantur, is limited, the relationship you\n"
             << "build with the Queen provides benefits lasting into the future!\n";
        cout << "You gain the territories of East Anglia and West Country!\n";
        Territory.push_back("East Anglia");
        Territory.push_back("West Country");
        break;
    case 2:
        cout << "The Anglican Church is very important during this time period.\n"
             << "You gain employment at the Chapel Royal as a result!\n"
             << "You gain 35 Gold!\n";
        Gold += 35;
        break;
    case 3:
        cout << "Due to the wealth of the Petre family, you gain valuable patrons!\n"
             << "You gain 25 Gold!\n";
        Gold += 25;
        break;
    case 4:
        cout << "Unfortunately, unsellable music is uncommon for good reason at this time.\n"
             << "You lose 10 Gold.\n";
        Gold -= 10;
        break;
    }
    return 0;
}

int barResult(int barChoice)
{
    switch (barChoice)
    {
    case 1:
        cout << "You compose many violin concertos, totalling around 500. They gain you some wealth!\n";
        Gold += 25;
        break;
    case 2:
        cout << "The Four Seasons becomes a massive post-humous hit. You influence many people!\n";
        Gold += 55;
        break;
    case 3:
        cout << "You attempt to compose a fugue, however your virtuosic tendencies cause it to fail.\n"
             << "You lose 5 Gold.\n";
        Gold -= 5;
        break;
    case 4:
        cout << "Unfortunately, the emperor died shortly and you gain nothing from this.\n";
        break;
    }
    return 0;
}

int classResult(int classChoice)
{
    switch (classChoice)
    {
    case 1:
        cout << "You compose the \"Farewell\" Symphony, which protests your piling commissions.\n"
             << "It is critically acclaimed\n";
        Gold += 45;
        break;
    case 2:
        cout << "The new prince has no interest in music, and you gain nothing.\n";
        break;
    case 3:
        cout << "You are beloved in England, and enjoy your time!\n";
        break;
    case 4:
        cout << "You gain musical training, but are kicked out after cutting the pigtails of a fellow member.\n";
        break;
    }
    return 0;
}

int romResult(int romChoice)
{
    switch (romChoice)
    {
    case 1:
        cout << "The American Quartet becomes one of your most famous works!\n";
        Gold += 50;
        break;
    case 2:
        cout << "Your cello conertos are know for their beautiful and high melodies!\n";
        Gold += 40;
        break;
    case 3:
        cout << "You get the scholarship, giving you financial independence!\n";
        Gold += 65;
        break;
    case 4:
        cout << "This new contact gives you international attention!\n";
        break;
    }
    return 0;
}

int modResult(int modChoice)
{
    switch (modChoice)
    {
    case 1:
        cout << "Your first major piece is a success, and you are offered a position as assistant conductor!\n";
        Gold += 35;
        break;
    case 2:
        cout << "The Nazis find it unacceptable, and you must flee the country.\n";
        Gold -= 5;
        break;
    case 3:
        cout << "You become famous in America where it is performed!\n";
        break;
    case 4:
        cout << "The concerto passes in obscurity.\n";
        break;
    }
    return 0;
}

void Modern()
{
    cout << "--- the Modern Era ---\n\n";
    cout << "In your final experience, you are Richard Strauss, born to a musical family.\n";
    cout << "1. Experiment with a suite\n"
         << "2. Write an opera\n"
         << "3. Compose a symphony\n"
         << "4. Make a concerto\n";
    cout << "Your Choice: ";
    cin >> modChoice1;
    modResult(modChoice1);
    cout << "Compose one more piece: ";
    cin >> modChoice2;
    if (modChoice1 != modChoice2)
    {
        modResult(modChoice2);
    }
    else
    {
        cout << "You already chose that. Pick a different one: ";
        cin >> modChoice2;
        if (modChoice1 != modChoice2)
        {
            modResult(modChoice2);
        }
        else
        {
            cout << "Same choice again. Restart the game.\n";
        }
    }
    sleep_for(seconds(2));
    Influence += 250000000;
    cout << "Congrats, you're done the Modern Era!\n";
    cout << "Now you can see what you've accomplished with your music!\n\n";
    sleep_for(seconds(2));
}

void Romantic()
{
    cout << "--- the Romantic Era ---\n\n";
    cout << "You are Antonin Dvorak. Born to a small business family, your musical talent is hereditary\n";
    cout << "1. Compose the \"American\" Quartet\n"
         << "2. Write a cello concerto\n"
         << "3. Apply for a state scholarship\n"
         << "4. Contact a German publisher\n";
    cout << "Your Choice: ";
    cin >> romChoice1;
    romResult(romChoice1);
    cout << "Compose one more piece: ";
    cin >> romChoice2;
    if (romChoice1 != romChoice2)
    {
        romResult(romChoice2);
    }
    else
    {
        cout << "You already chose that. Pick a different one: ";
        cin >> romChoice2;
        if (romChoice1 != romChoice2)
        {
            romResult(romChoice2);
        }
        else
        {
            cout << "Same choice again. Restart the game.\n";
        }
    }
    sleep_for(seconds(2));
    Influence += 200000000;
    cout << "Congrats, you're done with the Romantic Era!\n"
         << "Now you will enter the Modern Era!\n\n";
    sleep_for(seconds(2));
    Modern();
}

void Classical()
{
    cout << "--- the Classical Era ---\n\n";
    cout << "Your new identity is of Joseph Haydn, born to a middle class Austrian family.\n";
    cout << "1. Write a symphony\n"
         << "2. Compose for Prince Anton of Esterháza\n"
         << "3. Visit England\n"
         << "4. Attend the Choir School of St. Stephen's Cathedral\n";
    cout << "Your Choice: ";
    cin >> classChoice1;
    classResult(classChoice1);
    cout << "Compose one more piece: ";
    cin >> classChoice2;
    if (classChoice1 != classChoice2)
    {
        classResult(classChoice2);
    }
    else
    {
        cout << "You already chose that. Pick a different one: ";
        cin >> classChoice2;
        if (classChoice1 != classChoice2)
        {
            classResult(classChoice2);
        }
        else
        {
            cout << "Same choice again. Restart the game.\n";
        }
    }
    sleep_for(seconds(2));
    Influence += 200000000;
    cout << "Congrats, you're done with the Classical Era!\n"
         << "Now you will enter the Romantic Era!\n\n";
    sleep_for(seconds(2));
    Romantic();
}

void Baroque()
{
    cout << "--- the Baroque Era ---\n\n";
    cout << "You enter this new age as Antonio Vivaldi, son to a wealthy Italian family. You are a pronounced violinist.\n";
    cout << "1. Compose a violin concerto\n"
         << "2. Experiment with the Four Seasons\n"
         << "3. Write a fugue\n"
         << "4. Compose for the Emperor\n";
    cout << "Your Choice: ";
    cin >> barChoice1;
    barResult(barChoice1);
    cout << "Compose one more piece: ";
    cin >> barChoice2;
    if (barChoice1 != barChoice2)
    {
        barResult(barChoice2);
    }
    else
    {
        cout << "You already chose that. Pick a different one: ";
        cin >> barChoice2;
        if (barChoice1 != barChoice2)
        {
            barResult(barChoice2);
        }
        else
        {
            cout << "Same choice again. Restart the game.\n";
        }
    }
    sleep_for(seconds(2));
    Influence += 100000000;
    cout << "Congrats, you're done with the Baroque Era!\n"
         << "Now you will enter the Classical Era!\n\n";
    sleep_for(seconds(2));
    Classical();
}

void Renaissance()
{
    cout << "--- the Renaissance Era ---\n\n";
    cout << "Your name is William Byrd, you are from a higher class family\n"
         << "in London, as only those select wealthy familes are able to be\n"
         << "surrounded by music at this point.\n"
         << "Choose who to compose for:\n";
    cout << "1. The Royal Court of Queen Elizabeth\n"
         << "2. The Anglican Church\n"
         << "3. The wealthy Petre family\n"
         << "4. Your wife, Juliana Byrd\n";
    cout << "Your Choice: ";
    cin >> renChoice1;
    renResult(renChoice1);
    cout << "You can compose 1 more piece!\n";
    cout << "Please select another option: ";
    cin >> renChoice2;
    if (renChoice1 != renChoice2)
    {
        renResult(renChoice2);
    }
    else
    {
        cout << "You have chosen the same piece, please make another selection: ";
        cin >> renChoice2;
        if (renChoice1 != renChoice2)
        {
            renResult(renChoice2);
        }
        else
        {
            cout << "Ok, now you've broken it. Restart the game.\n";
        }
    }
    sleep_for(seconds(2));
    cout << "Congrats, you're done with the Renaissance Era!\n"
         << "Now you will enter the Baroque Era!\n\n";
    sleep_for(seconds(2));
    Influence += 3000000;
    Baroque();
}

void func()
{
    cout << "=== Welcome to Orchestral Music Throughout the Ages ===\n\n";
    cout << "You are a new composer hoping to make a name for yourself,\nthese are the ages you will travel through:\n";
    cout << "1. Renaissance (c. 1300 - 1600)\n"
         << "2. Baroque (c. 1600 - 1750)\n"
         << "3. Classical (c. 1750 - 1820)\n"
         << "4. Romantic (c. 1820 - 1850)\n"
         << "5. Modern (c. 1850 - Present)\n"
         << endl;
    sleep_for(seconds(2));
    cout << "You will now enter the Renaissance!\n\n";
    sleep_for(seconds(2));
    Renaissance();
}

int main()
{
    func();
    sleep_for(seconds(2));
    cout << "Through the compositions of:\n"
         << "- William Byrd\n"
         << "- Antonio Vivaldi\n"
         << "- Joseph Haydn\n"
         << "- Antonin Dvorak\n"
         << "- Richard Strauss\n"
         << "You now have: \n";
    sleep_for(seconds(2));
    cout << "The territories of: \n";
    for (const string &region : Territory)
    {
        cout << "- " << region << endl;
    }
    cout << Gold << " Gold\n";
    cout << "And have influenced " << Influence << " People" << endl;
    sleep_for(seconds(2));
    cout << "Resources: \n";
    cout << "1. https://encyclopediavirginia.org/entries/byrd-william-1674-1744/\n"
         << "2. https://www.classical-music.com/features/composers/antonio-vivaldi\n"
         << "3. https://www.classicfm.com/composers/haydn/\n"
         << "4. https://www.antonin-dvorak.cz/en/life/biography/\n"
         << "5. https://www.britannica.com/biography/Richard-Strauss\n";
    return 0;
}
