#include <gameHandler.h>
#include <iostream>
gameHandler::gameHandler() {
	currentState = 0;
	highestID = -1;
}
void gameHandler::addState() {
	std::vector<std::unordered_set<int>> newList;
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
	if (state < 0 || state >= gameStates.size()) {
		return -1;
	}
	else if (depth < 0) {
		return -1;
	}
	int size = gameStates[state].size();
	if (depth > size) {
		depth = size;
		std::unordered_set<int> set;
		gameStates[state].push_back(set);
		gameStates[state][depth].insert(id);
	}
	//check if it already in the list
	for (int depth = 0; depth < gameStates[state].size(); depth++) {
		if (gameStates[state][depth].find(id) != gameStates[state][depth].end()) {
			return -1;

		}

	}
	gameStates[state][depth].insert(id);
	return 0;
}

void gameHandler::renderState(GLFWwindow* window) {
	for (int depth = 0; depth < gameStates[currentState].size(); depth++) {
		for (int id : gameStates[currentState][depth]) {
			ActorMap[id]->Render(window);
		}
	}

}
int gameHandler::changeCurrentState(int state) {
	if (state < 0 || state >= gameStates.size()) {
		return -1;
	}
	currentState = state;
	return 0;
}

int gameHandler::changeActorLayer(int id, int state, int fromDepth, int toDepth) {
	if (gameStates[state][fromDepth].find(id) != gameStates[state][fromDepth].end()) {
		gameStates[state][toDepth].insert(id);
		gameStates[state][fromDepth].erase(id);
		return 0;
	}
	return -1;
}
void gameHandler::removeActorFromState(int id, int state) {
	for (int depth = 0; depth < gameStates[state].size(); depth++) {
		gameStates[state][depth].erase(id);


	}
}
int gameHandler::removeActor(int id) {
	if (ActorMap.find(id) != ActorMap.end()) {
		ActorMap.erase(id);
		freeId.push_back(id);
	}
	return -1;
}

int gameHandler::removeState(int state) {
	if (state < 0 || state >= gameStates.size()) {
		return -1;
	}
	gameStates.erase(gameStates.begin() + state);
	return 0;
}