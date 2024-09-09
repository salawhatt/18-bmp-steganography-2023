#pragma once
#include "macros.h"


class TUIBase
{
	friend class InputProc;
public:
	void cursorMovementXY(SHORT x, SHORT y);
	void drawTUI(int height, char type);
	void drawTUI(int height, char type, char* key);
	int arrowMovement(int maximum_position_y);
};

class OtherMessages : public TUIBase
{
public:
	void instruction();
	void warnings(int mod);
};

