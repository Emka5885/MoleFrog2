#pragma once
#include "AssetManager.h"
#include "Button.h"

class Data
{
private:
	AssetManager* assets;

	const char* dataText;
	const char* optionalText;
	int dataPosX, dataPosY;
	int minValue, maxValue;
	int currentValue;
	int currentDataTextSize;
	int currentValueTextSize;

	Button* left;
	Button* right;

	void UpdateLeft();
	void UpdateRight();
	void DrawLeft();
	void DrawValue();
	void DrawRight();

public:
	Data(AssetManager* assets, const char* dataText, int minValue, int maxValue, int dataPosX, int dataPosY, const char* optionalText = "");

	void SetNewValue(int newValue);
	void DrawData();

	void CheckIfButtonsHover(Vector2 mousePos);
	void CheckToSetNewValue(Vector2 mousePos);
};