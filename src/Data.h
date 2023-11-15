#pragma once
#include "AssetManager.h"

class Data
{
private:
	const char* dataText;
	const char* unitText;
	int dataPosX, dataPosY;
	int minValue, maxValue;
	int currentValue;

public:
	Data(const char* dataText, int minValue, int maxValue, int dataPosX, int dataPosY, const char* unitText = "");

	void SetNewValue(int newValue);
	void Draw(AssetManager* assets);
};