// Fill out your copyright notice in the Description page of Project Settings.


#include "M_InputDeviceSubsystem.h"

UM_InputDeviceSubsystem::UM_InputDeviceSubsystem()
{

}

void UM_InputDeviceSubsystem::ToggleSlateNavigation(bool bInTabNavigation, bool bInKeyNavigation, bool bInAnalogNavigation)
{
		TSharedRef<FNavigationConfig> navigation_config = FSlateApplication::Get().GetNavigationConfig();
		navigation_config->bTabNavigation = bInTabNavigation;
		navigation_config->bKeyNavigation = bInKeyNavigation;
		navigation_config->bAnalogNavigation = bInAnalogNavigation;
		FSlateApplication::Get().SetNavigationConfig(navigation_config);
}
