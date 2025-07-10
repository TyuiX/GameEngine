#include <gameHandler.h>
#include <iostream>
gameHandler::gameHandler() {
	currentState = 0;
	counter = 0;
}
void gameHandler::addState() {
	std::vector<Actor> newActorList;
	gameStates.push_back(newActorList);
}

int gameHandler::addActor(Actor actor, int state, int depth) {
	std::cout << "size1: " << gameStates[state].size() << std::endl;

	std::cout << "name: " << actor.getName() << std::endl;
	if (depth > gameStates[state].size()) {
		depth = gameStates[state].size();
	}
	gameStates[state].insert(gameStates[state].begin() + depth, actor);
	std::cout << "size: " << gameStates[state].size() << std::endl;
	return 0;
	

}

void gameHandler::renderState(GLFWwindow* window) {
	for (Actor& actor : gameStates[currentState]) {
		actor.Render(window);
	}
	

}
void gameHandler::changeCurrentState(int state) {
	currentState = state;
}
