#include "Data.h"
#include <algorithm>
#include "Definitions.h"
#include "Render.h"
#include <string>

Data::Data(AssetManager* assets, const char* dataText, int minValue, int maxValue, int dataPosX, int dataPosY, const char* optionalText) : assets(assets), dataText(dataText), minValue(minValue), maxValue(maxValue), dataPosX(dataPosX), dataPosY(dataPosY), optionalText(optionalText)
{
	left = new Button({ 32,32 }, { 255,255,255,255 }, { 0,0,0,255 }, { 0,0,0,255 }, "<", assets->GetFont(FONT), 0);
	right = new Button({ 32,32 }, { 255,255,255,255 }, { 0,0,0,255 }, { 0,0,0,255 }, ">", assets->GetFont(FONT), 0);
	SetNewValue(1);
}

void Data::SetNewValue(int newValue)
{
	currentValue = std::clamp(newValue, minValue, maxValue);
}

void Data::UpdateLeft()
{
	left->SetNewPosition({ dataPosX + currentDataTextSize + 21, dataPosY + 16 });
}

void Data::UpdateRight()
{
	right->SetNewPosition({ dataPosX + currentDataTextSize + 42 + currentValueTextSize + 21, dataPosY + 16 });
}

void Data::DrawData()
{
	std::string st = std::string(dataText);
	if (optionalText != "")
	{
		st += " (" + std::string(optionalText) + "):";
	}
	const char* text = st.c_str();
	DrawText(assets->GetFont(FONT), { 0,0,0,255 }, text, dataPosX, dataPosY, currentDataTextSize);

	DrawLeft();
}

void Data::DrawLeft()
{
	UpdateLeft();
	left->Draw();

	DrawValue();
}

void Data::DrawValue()
{
	std::string st = std::to_string(currentValue);
	const char* text = st.c_str();
	DrawText(assets->GetFont(FONT), { 0,0,0,255 }, text, dataPosX + currentDataTextSize + 42, dataPosY, currentValueTextSize);

	DrawRight();
}

void Data::DrawRight()
{
	UpdateRight();
	right->Draw();
}
