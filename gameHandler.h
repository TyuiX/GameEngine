#include <vector>
#include <Actor.h>
#include <unordered_map>
#include <memory>
class gameHandler {
private:
	//key = id for map
	std::unordered_map<int, std::shared_ptr<Actor>> ActorMap;
	int highestID;
	std::vector<std::vector<int>> gameStates;
	std::vector<int> freeId;
	
	int currentState;
public:
	gameHandler();
	//increaseState by 1
	void addState();
	//return -1 if no id for it is found
	int getId(Actor& actor);
	
	//remove this state
	void removeState(int state);
	//add an actor into gameHandler and return the id where it was stored
	int addActor(Actor& actor);
	int removeActor(int id);
	int addActorToState(int id, int state, int depth);
	//remove the actor from a game state, return 0 if it found and removed, reutrn 1 if it didn't find it
	int removeActorFromState(Actor actor, int state);
	//render all actor in the game state
	void renderState(GLFWwindow* window);
	//take actor want change and depth is the layer, higher layer mean more in the back when rendering
	void changeActorLayer(Actor actor, int state, int depth);
	//change the state return 0 if success otherwise return -1
	int changeCurrentState(int state);
};
