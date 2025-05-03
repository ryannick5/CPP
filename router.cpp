#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <bitset>
#include <sstream>

using namespace std;

string input;
vector<string> R1 = {
    to_string(rand() % 256),
    to_string(rand() % 256),
    to_string(rand() % 256),
    to_string(rand() % 256)};
vector<string> R8 = {
    to_string(rand() % 256),
    to_string(rand() % 256),
    to_string(rand() % 256),
    to_string(rand() % 256)};

// Animation frames
vector<vector<string>> frames = {
    {"##############",
     "#  R1        #",
     "#       R2   #",
     "#  R3        #",
     "#      R4    #",
     "#         R5 #",
     "#  R6        #",
     "#       R7   #",
     "#    R8      #",
     "##############"},
    {"##############",
     "#  R1        #",
     "#    \\  R2   #",
     "#  R3        #",
     "#      R4    #",
     "#         R5 #",
     "#  R6        #",
     "#       R7   #",
     "#    R8      #",
     "##############"},
    {"##############",
     "#  R1        #",
     "#     \\ R2   #",
     "#  R3   \\    #",
     "#      R4    #",
     "#         R5 #",
     "#  R6        #",
     "#       R7   #",
     "#    R8      #",
     "##############"},
    {"##############",
     "#  R1        #",
     "#     \\ R2   #",
     "#  R3   \\    #",
     "#      R4    #",
     "#      |  R5 #",
     "#  R6        #",
     "#       R7   #",
     "#    R8      #",
     "##############"},
    {"##############",
     "#  R1        #",
     "#     \\ R2   #",
     "#  R3   \\    #",
     "#      R4    #",
     "#      |  R5 #",
     "#  R6–––     #",
     "#       R7   #",
     "#    R8      #",
     "##############"},
    {"##############",
     "#  R1        #",
     "#     \\ R2   #",
     "#  R3   \\    #",
     "#      R4    #",
     "#      |  R5 #",
     "#  R6–––     #",
     "#    \\   R7  #",
     "#    R8      #",
     "##############"}};

// Convert string to binary
string stringToBinary(const string &input)
{
    stringstream binaryStream;
    for (char c : input)
    {
        binaryStream << bitset<8>(c);
    }
    return binaryStream.str();
}

void Draw(int frameIndex)
{
    if (frameIndex >= 0 && frameIndex < frames.size())
    {
        for (const string &line : frames[frameIndex])
        {
            cout << line << endl;
        }
    }
}

void Transmit()
{
    cout << "\nTransmitting from "
         << R1[0] << "." << R1[1] << "." << R1[2] << "." << R1[3]
         << " to "
         << R8[0] << "." << R8[1] << "." << R8[2] << "." << R8[3];
    cout.flush();
    for (int i = 0; i < 10; i++)
    {
        usleep(800000);
        cout << " .";
        cout.flush();
    }

    for (int i = 0; i < frames.size(); i++)
    {
        system("clear");
        Draw(i);
        usleep(500000);
    }

    cout << "Done!";
}

void Packet()
{
    int packetSize = 3; // adjustable packet length
    int len = input.length();
    vector<string> packets;

    for (int i = 0; i < len; i += packetSize)
    {
        packets.push_back(input.substr(i, packetSize));
    }

    cout << "\nPackets:\n";
    for (const string &pkt : packets)
    {
        cout << "[" << pkt << "]" << endl;
    }

    usleep(100000);
    cout << "\n\nBinary Message:\n"
         << stringToBinary(input) << "\n";
}

void End()
{
    usleep(100000); // short delay so user sees last animation frame
    cout << "\nRestored Message:\n"
         << input << "\n";
}

int main()
{
    cout << "Enter message: ";

    getline(cin, input);

    Packet();
    Transmit();
    End();

    return 0;
}
