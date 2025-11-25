// Fill out your copyright notice in the Description page of Project Settings.


#include "M_InputDeviceSubsystem.h"

UM_InputDeviceSubsystem::UM_InputDeviceSubsystem()
{

}

void UM_InputDeviceSubsystem::ToggleSlateNavigation(bool bInTabNavigation, bool bInKeyNavigation, bool bInAnalogNavigation, bool bInActionNavigation)
{
    if (FSlateApplication::IsInitialized())
    {
		TSharedRef<FNavigationConfig> navigation_config = FSlateApplication::Get().GetNavigationConfig();
		navigation_config->bTabNavigation = bInTabNavigation;
		navigation_config->bKeyNavigation = bInKeyNavigation;
		navigation_config->bAnalogNavigation = bInAnalogNavigation;

		if (bInActionNavigation)
        {
            // Якщо увімкнено - повертаємо правила назад, якщо їх немає
            if (!navigation_config->KeyActionRules.Contains(EKeys::Enter))
            {
                navigation_config->KeyActionRules.Emplace(EKeys::Enter, EUINavigationAction::Accept);
                navigation_config->KeyActionRules.Emplace(EKeys::SpaceBar, EUINavigationAction::Accept);
                navigation_config->KeyActionRules.Emplace(EKeys::Virtual_Accept, EUINavigationAction::Accept);
            }
        }
        else
        {
            navigation_config->KeyActionRules.Remove(EKeys::Enter);
            navigation_config->KeyActionRules.Remove(EKeys::SpaceBar);
            navigation_config->KeyActionRules.Remove(EKeys::Virtual_Accept); 
        }

		FSlateApplication::Get().SetNavigationConfig(navigation_config);
	}
}
