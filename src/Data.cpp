#include "Data.h"
#include <algorithm>
#include "Definitions.h"
#include "Render.h"
#include <string>

Data::Data(const char* dataText, int minValue, int maxValue, int dataPosX, int dataPosY, const char* unitText) : dataText(dataText), minValue(minValue), maxValue(maxValue), dataPosX(dataPosX), dataPosY(dataPosY), unitText(unitText)
{
	SetNewValue(1);
}

void Data::SetNewValue(int newValue)
{
	currentValue = std::clamp(newValue, minValue, maxValue);
}

void Data::Draw(AssetManager* assets)
{
	std::string st = std::string(dataText);
	if (unitText != "")
	{
		st += " (in " + std::string(unitText) + ")";
	}
	
	const char* text = st.c_str();
	DrawText(assets->GetFont(FONT), { 0,0,0,255 }, text, dataPosX, dataPosY);
}
