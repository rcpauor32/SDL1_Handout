#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"
#include "Module.h"
#include "Dummy.h"
#include "EscModule.h"
#include <stdio.h>
#include "conio.h"

#define NUM_MODULES 1

class Application
{
public:

	Module* modules[NUM_MODULES];
	EscModule* esc_module;

public:

	Application()
	{
		modules[0] = new ModuleDummy();
		esc_module = new EscModule();
		// TODO 4: Create your new module
		// it should check if player it ESC key
		// use kbhit()
		// http://www.cprogramming.com/fod/kbhit.html
		
	}

	// INIT all modules

	bool Init() 
	{
		for(int i = 0; i < NUM_MODULES; ++i)
			modules[i]->Init();
		
		return true; 
	}

	// UPDATE all modules
	// TODO 2: Make sure all modules receive its update
	int Update() { 
		LOG("\nModules Updating -------------------");

		for (int i = 0; i < NUM_MODULES; ++i) {
			if (!modules[i]->Update()) 
				return false;
			else LOG("\nSuccess Updating -------------------");
		}

		if (esc_module.EscPress())
			return UPDATE_STOP; 
	}

	// EXIT Update 
	// TODO 3: Make sure all modules have a chance to cleanup
	bool CleanUp()
	{
		for (int i = NUM_MODULES - 1; i >= 0; --i) {
			modules[i]->CleanUp();
		}

		return true;
	}

};

#endif // __APPLICATION_H__