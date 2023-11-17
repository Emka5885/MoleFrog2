#pragma once
#include "AssetManager.h"
#include "Button.h"
#include "Definitions.h"

class Data
{
private:
	AssetManager* assets;
	DataTypes dataType;

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
	Data(AssetManager* assets, DataTypes dataType, int minValue, int maxValue, int initialValue, int dataPosX, int dataPosY);

	void Init();
	void SetNewValue(int newValue);
	void DrawData();

	void CheckIfButtonsHover(Vector2 mousePos);
	void CheckToSetNewValue(Vector2 mousePos);
};