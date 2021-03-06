#include "stdafx.h"
#include "../include/ui/Canvas.h"

using namespace MPF;
using namespace MPF::Visual;
using namespace MPF::UI;

DEFINE_TYPE(Canvas, MPF::UI::Canvas)
DEFINE_UI_VALUES(Canvas)
DEFINE_UI_FUNCS(Canvas, Panel)

DependencyProperty<float> Canvas::LeftProperty(L"Left");
DependencyProperty<float> Canvas::TopProperty(L"Top");

Canvas::Canvas()
{

}

Canvas::~Canvas()
{

}

MPF::Visual::Point Canvas::MakeChildOffset(UIElement& elem)
{
	auto left = elem.GetValue(LeftProperty);
	auto top = elem.GetValue(TopProperty);

	return{ left, top };
}

float Canvas::GetLeft(const UIElement& elem)
{
	return elem.GetValue(LeftProperty);
}

void Canvas::SetLeft(UIElement& elem, float value)
{
	elem.SetValue(LeftProperty, value);
}

float Canvas::GetTop(const UIElement& elem)
{
	return elem.GetValue(TopProperty);
}

void Canvas::SetTop(UIElement& elem, float value)
{
	elem.SetValue(TopProperty, value);
}

std::pair<float, float> Canvas::GetPosition(const UIElement& elem)
{
	return std::make_pair(GetLeft(elem), GetTop(elem));
}

void Canvas::SetPosition(UIElement& elem, const std::pair<float, float>& position)
{
	SetLeft(elem, position.first);
	SetTop(elem, position.second);
}