#include <gameHandler.h>
#include <iostream>
gameHandler::gameHandler() {
	currentState = 0;
}
void gameHandler::addState() {
	std::vector<Actor> newActorList;
	gameStates.push_back(newActorList);
}


int gameHandler::addActor(Actor actor, int state, int depth) {

	//std::cout << "name: " << actor.getName() << std::endl;
	if (depth < 0) {
		return -1;
	}
	int size = gameStates[state].size();
	if (depth > size) {
		depth = size;
	}
	gameStates[state].insert(gameStates[state].begin() + depth, actor);
	return 0;
	

}

void gameHandler::renderState(GLFWwindow* window) {
	for (Actor& actor : gameStates[currentState]) {
		actor.Render(window);
	}
	

}
int gameHandler::changeCurrentState(int state) {
	if (state < 0 || state >= gameStates.size()) {
		return -1;
	}
	currentState = state;
	return 0;
}
