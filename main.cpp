/******************************************
 * This is the main file to start a
 * game with the server and let it execute
 ******************************************/

#include <iostream>

using namespace std;

int main()
{
    bool gameOver = false;
    
    Network network = new Network(/* SERVER, PORT, USER, PASS */);
    
    Game game = new Game();
    
    game.run(network);
    
    return 0;
}