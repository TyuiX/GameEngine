#include <gameHandler.h>
#include <iostream>
gameHandler::gameHandler() {
	currentState = 0;
	highestID = -1;
}
void gameHandler::addState() {
	std::vector<int> newList;
	gameStates.push_back(newList);
}


int gameHandler::addActor(Actor& actor) {
	if (freeId.size() > 0) {
		int id = freeId.back();
		freeId.pop_back();
		ActorMap[id] = std::make_shared<Actor>(actor);
		return id;
	}
	int l = ActorMap.size();
	ActorMap[l] = std::make_shared<Actor>(actor);
	highestID = l;
	return l;
	
}
int gameHandler::getId(Actor& actor) {
	for (int i = 0; i < highestID + 1; i++) {
		// check for null
		if (ActorMap[i]) {
			//compare the memory address
			if (ActorMap[i].get() == &actor) {
				return i;
			}

		}
	}
	return -1;
}
//reminder may have change this to different way in future if were making sure element not in the list
int gameHandler::addActorToState(int id, int state, int depth) {
	if (depth < 0) {
		return -1;
	}
	int size = gameStates[state].size();
	if (depth > size) {
		depth = size;
	}
	//check if it already in the list
	bool exists = std::find(gameStates[state].begin(), gameStates[state].end(), id) != gameStates[state].end();
	if (!exists) {
		gameStates[state].insert(gameStates[state].begin() + depth, id);
	}
	return 0;
}

void gameHandler::renderState(GLFWwindow* window) {
	for (int id : gameStates[currentState]) {
		ActorMap[id]->Render(window);
	}

}
int gameHandler::changeCurrentState(int state) {
	if (state < 0 || state >= gameStates.size()) {
		return -1;
	}
	currentState = state;
	return 0;
}
