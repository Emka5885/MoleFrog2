#include "Data.h"
#include <algorithm>
#include "Render.h"
#include <string>

Data::Data(AssetManager* assets, DataTypes dataType, int minValue, int maxValue, int initialValue, int dataPosX, int dataPosY) : assets(assets), dataType(dataType), minValue(minValue), maxValue(maxValue), dataPosX(dataPosX), dataPosY(dataPosY)
{
	left = new Button({ 32,32 }, { 255,255,255,255 }, { 0,0,0,255 }, { 0,0,0,255 }, "<", assets->GetFont(FONT), 2);
	right = new Button({ 32,32 }, { 255,255,255,255 }, { 0,0,0,255 }, { 0,0,0,255 }, ">", assets->GetFont(FONT), 2);
	SetNewValue(initialValue);
	Init();
}

void Data::Init()
{
	switch (dataType)
	{
	case angle:
		dataText = "Angle";
		optionalText = "in °";
		break;
	case initialSpeed:
		dataText = "Initial Speed";
		optionalText = "in m/s";
		break;
	case gravity:
		dataText = "Gravity";
		optionalText = "in m/s^2";
		break;
	case airDrag:
		dataText = "Air Drag";
		optionalText = "in m/s^2";
		break;
	}
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
		st += " (" + std::string(optionalText) + ") ";
	}
	const char* text = st.c_str();
	DrawText(assets->GetFont(FONT), { 0,0,0,255 }, text, dataPosX, dataPosY, currentDataTextSize);

	DrawLeft();
}

void Data::CheckIfButtonsHover(Vector2 mousePos)
{
	left->CheckIfHovered(mousePos);
	right->CheckIfHovered(mousePos);
}

void Data::CheckToSetNewValue(Vector2 mousePos)
{
	if (left->GetIfClicked(mousePos))
	{
		SetNewValue(--currentValue);
	}
	if (right->GetIfClicked(mousePos))
	{
		SetNewValue(++currentValue);
	}
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
