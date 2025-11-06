// Fill out your copyright notice in the Description page of Project Settings.


#include "M_InputDeviceSubsystem.h"

UM_InputDeviceSubsystem::UM_InputDeviceSubsystem()
{

}

void UM_InputDeviceSubsystem::ToggleSlateNavigation(bool bEnable)
{
	if(!bEnable)
	{ 
		TSharedRef<FNavigationConfig> navigation_config = FSlateApplication::Get().GetNavigationConfig();
		navigation_config->bTabNavigation = false;
		navigation_config->bKeyNavigation = false;
		navigation_config->bAnalogNavigation = false;
		FSlateApplication::Get().SetNavigationConfig(navigation_config);
	}
	else
	{
		TSharedRef<FNavigationConfig> navigation_config = FSlateApplication::Get().GetNavigationConfig();
		navigation_config->bTabNavigation = true;
		navigation_config->bKeyNavigation = true;
		navigation_config->bAnalogNavigation = true;
		FSlateApplication::Get().SetNavigationConfig(navigation_config);
	}

}
