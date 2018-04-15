#include "UIView.h"

CheatBase* cheatBase;
UILabel* TriggerbotDelayLbl;
UISlider* TriggerbotDelaySlider;

// Glow ESP Event
void GlowESPCbx_OnStateChanged(UIElement* sender)
{
	UICheckbox* cbx = static_cast<UICheckbox*>(sender);
	if (cbx->GetChecked())
	{
		// Enable Glow ESP
		cheatBase->SetESPGlow(true);
	}
	else
	{
		// Disable Glow ESP
		cheatBase->SetESPGlow(false);
	}
}

// Triggerbot Event
void TriggerbotCbx_OnStateChanged(UIElement* sender)
{
	UICheckbox* cbx = static_cast<UICheckbox*>(sender);
	if (cbx->GetChecked())
	{
		// Enable Triggerbot
		cheatBase->SetTriggerbot(true);
		TriggerbotDelaySlider->SetEnabled(true);
	}
	else
	{
		// Disable Triggerbot
		cheatBase->SetTriggerbot(false);
		TriggerbotDelaySlider->SetEnabled(false);
	}
}

// Change Triggerbot Delay
void TriggerbotDelaySlider_OnValueChanged(UIElement* sender)
{
	UISlider* slider = static_cast<UISlider*>(sender);
	int Value = (int)(slider->GetValue());
	std::wstring text = L"Delay: ";
	text.append(std::to_wstring(Value));
	text.append(L" ms");
	TriggerbotDelayLbl->SetText(text);
	cheatBase->SetTriggerbotDelay(Value);
}

// Triggerbot Event
void BunnyhopCbx_OnStateChanged(UIElement* sender)
{
	UICheckbox* cbx = static_cast<UICheckbox*>(sender);
	if (cbx->GetChecked())
	{
		// Enable Auto Bunnyhopping
		cheatBase->SetBhop(true);
	}
	else
	{
		// Disable Auto Bunnyhopping
		cheatBase->SetBhop(false);
	}
}

void RcsCbx_OnStateChanged(UIElement* sender)
{
	UICheckbox* cbx = static_cast<UICheckbox*>(sender);
	if (cbx->GetChecked())
	{
		// Enable RCS
		cheatBase->SetRCS(true);
	}
	else
	{
		// Disable RCS
		cheatBase->SetRCS(false);
	}
}

void UIView::Init()
{
	cheatBase = new CheatBase();
	
	// Labels
	UILabel* TitleLbl = new UILabel(graphics, L"Entr0py External", L"Arial", 26, 360, 20, 200, 20);
	gui.push_back(TitleLbl);

	UILabel* VisualsLbl = new UILabel(graphics, L"Visuals", L"Verdana", 23, 40, 80, 140, 20);
	gui.push_back(VisualsLbl);

	UILabel* AimLbl = new UILabel(graphics, L"Aim Assist", L"Verdana", 23, 360, 80, 160, 20);
	gui.push_back(AimLbl);

	UILabel* MiscLbl = new UILabel(graphics, L"MISC", L"Verdana", 23, 680, 80, 160, 20);
	gui.push_back(MiscLbl);

	TriggerbotDelayLbl = new UILabel(graphics, L"Delay: 0 ms", L"Arial", 14, 342, 170, 200, 10);
	gui.push_back(TriggerbotDelayLbl);


	// Checkboxes
	UICheckbox* GlowESPCbx = new UICheckbox(graphics, L"Glow ESP", L"Arial", 16, 54, 140, 20, 100, 40);
	GlowESPCbx->SetStateChangedEventHandler(GlowESPCbx_OnStateChanged);
	gui.push_back(GlowESPCbx);

	UICheckbox* TriggerbotCbx = new UICheckbox(graphics, L"Triggerbot", L"Arial", 16, 370, 140, 20, 100, 40);
	TriggerbotCbx->SetStateChangedEventHandler(TriggerbotCbx_OnStateChanged);
	gui.push_back(TriggerbotCbx);

	UICheckbox* RcsCbx = new UICheckbox(graphics, L"Recoil Control", L"Arial", 16, 370, 240, 20, 120, 40);
	RcsCbx->SetStateChangedEventHandler(RcsCbx_OnStateChanged);
	gui.push_back(RcsCbx);

	UICheckbox* BunnyhopCbx = new UICheckbox(graphics, L"Auto Bunnyhops", L"Arial", 16, 700, 144, 20, 140, 40);
	BunnyhopCbx->SetStateChangedEventHandler(BunnyhopCbx_OnStateChanged);
	gui.push_back(BunnyhopCbx);


	// Sliders
	TriggerbotDelaySlider = new UISlider(graphics, 380, 190, 100);
	TriggerbotDelaySlider->SetEnabled(false);
	TriggerbotDelaySlider->SetValueChangedEventHandler(TriggerbotDelaySlider_OnValueChanged);
	TriggerbotDelaySlider->SetMinValue(0);
	TriggerbotDelaySlider->SetMaxValue(360);
	TriggerbotDelaySlider->SetIntervals(1);
	TriggerbotDelaySlider->SetKnobRadius(6);
	gui.push_back(TriggerbotDelaySlider);
}