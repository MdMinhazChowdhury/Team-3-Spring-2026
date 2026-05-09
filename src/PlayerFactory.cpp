// created by Javani
#include "Human.cpp"
#include <string>
// Factory class for creating players
class PlayerFactory {
public:

    // Create and returns a human player
    //player name, and player unique id
    static Human createHumanPlayer(std::string name, std::string id) {
        return Human(name, id);// return the player created
    }

};