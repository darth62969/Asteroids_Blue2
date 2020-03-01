#pragma once

#include <vector>

#include "Renderer.h"
#include "Structures.h"

class object;

class mode
{
public:

	const std::string name = 0;
	const std::string description =0;

	virtual int step() = 0; 			// Increments mode, runs checkes for level clear and moves objects if needed. 
								// returns 1 if mode won 2 if lost;
	virtual void generateLevel() = 0;	// Generates objects and places them onScreen;
	virtual void init() = 0;			// 

	std::vector<std::shared_ptr<object>> getOnScreen();
	void addToOnScreen(std::shared_ptr<object> obj);

	virtual void drawLevel() = 0;
	virtual void drawObjects() = 0;
	virtual void drawScore() = 0;
	virtual void drawAll() = 0;

	virtual void keyboardFunc(char key, int x, int y) = 0;
	virtual void mouseFunc(int button, int state, int x, int y) = 0;
	virtual void passiveMouseFunc(int x, int y) = 0;

private:
	std::vector<std::shared_ptr<object>>* onScreen;	// collection of objects for the mode that are displayed onScreen;
	int level = 1;					// current level, default 1;
	int stp = 0;					// current step, used to keep track of frames;
	int maxLevel;					// Maximum level posible in mode, SET THIS!!;
	int bulletsHit = 0;
};

