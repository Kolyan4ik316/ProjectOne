// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Framework/Application/SlateUser.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/Application/NavigationConfig.h"
#include "M_InputDeviceSubsystem.generated.h"
/**
 * 
 */
UCLASS(BlueprintType)
class PROJECTONE_API UM_InputDeviceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UM_InputDeviceSubsystem();

protected:
	//UPROPERTY()
	//TSharedRef<FNavigationConfig> OriginalNavigationConfig;

	//UPROPERTY()
	//TSharedRef<FNavigationConfig> DisabledNavigationConfig = MakeShared<FNavigationConfig>();
public:
	UFUNCTION(BlueprintCallable, Category = "Input|Navigation")
	void ToggleSlateNavigation(bool bInTabNavigation = true, bool bInKeyNavigation = true, bool bInAnalogNavigation = true, bool bInActionNavigation = true);
	
};
