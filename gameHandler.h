#include <vector>
#include <Actor.h>
class gameHandler {
private:
	std::vector<std::vector<Actor>> gameStates;
	int currentState;
	int counter;
public:
	gameHandler();
	//increaseState by 1
	void addState();
	//remove this state
	void removeState(int state);
	//add an actor into a game state
	int addActor(Actor actor, int state, int depth);
	//remove the actor from a game state, return 0 if it found and removed, reutrn 1 if it didn't find it
	int removeActor(Actor actor, int state);
	//render all actor in the game state
	void renderState(GLFWwindow* window);
	//take actor want change and depth is the layer, higher layer mean more in the back when rendering
	void changeActorLayer(Actor actor, int state, int depth);
	void changeCurrentState(int state);
};
