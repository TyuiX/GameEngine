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
	// handle out of bound error if user put large depth
	std::cout << "size1: " << gameStates[state].size() << std::endl;

	std::cout << "name: " << actor.getName() << std::endl;
	if (depth > gameStates[state].size()) {
		depth = gameStates[state].size();
	}
	//insert it in that index
	gameStates[state].insert(gameStates[state].begin() + depth, actor);
	std::cout << "size: " << gameStates[state].size() << std::endl;
	return 0;
	

}

void gameHandler::renderState(GLFWwindow* window) {
	//std::cout << "name: " << gameStates[currentState][0].getName() << std::endl;
	for (auto actor : gameStates[currentState]) {
		actor.Render(window);
	}
	

}
void gameHandler::changeCurrentState(int state) {
	currentState = state;
}
