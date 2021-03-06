// Fill out your copyright notice in the Description page of Project Settings.

#include "ConsoleGameDevII.h"
#include "RobberCharacterClass.h"
#include "RobberCharacterControllerClass.h"
#include "ConsoleGameDevIIHUD.h"

ARobberCharacterControllerClass::ARobberCharacterControllerClass()
{
	bIsBinocularsOpen = false;
}

void ARobberCharacterControllerClass::BeginPlay()
{
	Super::BeginPlay();
	 
}

void ARobberCharacterControllerClass::HandleInventoryInput()
{
	ARobberCharacterClass* Char = Cast<ARobberCharacterClass>(GetPawn());
	InventoryWidgetRef->ItemsArray = Char->GetInventory();
	InventoryWidgetRef->Show();
}

void ARobberCharacterControllerClass::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);

	if (InventoryWidgetBP)
	{
		InventoryWidgetRef = CreateWidget<UInventoryWidget>(this, InventoryWidgetBP);
		InventoryWidgetRef->Show();
		ARobberCharacterClass* Char = Cast<ARobberCharacterClass>(GetPawn());
		InventoryWidgetRef->ItemsArray = Char->GetInventory();
	}

	if (TooltipWidgetBP)
	{
		TooltipWidgetRef = CreateWidget<UTootlipWidgetClass>(this, TooltipWidgetBP);
		TooltipWidgetRef->AddToViewport();
		TooltipWidgetRef->ToggleOff();
	}

	if (BinocularsWidgetBP)
	{
		BinocularsWidgetRef = CreateWidget<UBinocularsWidgetClass>(this, BinocularsWidgetBP);
		BinocularsWidgetRef->AddToViewport();
		BinocularsWidgetRef->ToggleOff();
	}
	
	if (BoxWidgetBP)
	{
		BoxWidgetRef = CreateWidget<UBoxWidgetClass>(this, BoxWidgetBP);
		BoxWidgetRef->AddToViewport();
		BoxWidgetRef->ToggleOff();
	}

	if (WastedWidgetBP)
	{
		WastedWidgetRef = CreateWidget<UWastedWidgetClass>(this, WastedWidgetBP);
		WastedWidgetRef->AddToViewport();
		WastedWidgetRef->ToggleOff();
	}

	if (WinWidgetBp)
	{
		WinWidgetRef = CreateWidget<UWinWidgetClass>(this, WinWidgetBp);
		WinWidgetRef->AddToViewport();
		WinWidgetRef->ToggleOff();
	}

}

void ARobberCharacterControllerClass::SetNameOfWidget(FString name)
{
	TooltipWidgetRef->SetName(name);
}

void ARobberCharacterControllerClass::SetDescriptionOfWidget(FString desc)
{
	TooltipWidgetRef->SetDescription(desc);
}

void ARobberCharacterControllerClass::SetNameOfInventoryWidget(FString name)
{
	InventoryWidgetRef->SetItemsName(name);
}

AConsoleGameDevIIHUD* ARobberCharacterControllerClass::GetHud() const
{
	return Cast<AConsoleGameDevIIHUD>(GetHUD());
}

void ARobberCharacterControllerClass::ToggleTooltipUIOn()
{
	TooltipWidgetRef->ToggleOn();
}

void ARobberCharacterControllerClass::ToggleTooltipUIOff()
{
	TooltipWidgetRef->ToggleOff();
}

void ARobberCharacterControllerClass::ToggleBinocularsWidgetOn()
{
	if (!bIsBinocularsOpen)
	{
		BinocularsWidgetRef->ToggleOn();
		bIsBinocularsOpen = true;
	}
	else if (bIsBinocularsOpen)
	{
		BinocularsWidgetRef->ToggleOff();
		bIsBinocularsOpen = false;
	}
	
}
void ARobberCharacterControllerClass::ToggleBinocularsWidgetOff()
{
	BinocularsWidgetRef->ToggleOff();
}

void ARobberCharacterControllerClass::ToggleBoxWidgetOn()
{
	BoxWidgetRef->ToggleOn();
}

void ARobberCharacterControllerClass::ToggleBoxWidgetOff()
{
	BoxWidgetRef->ToggleOff();
}

void ARobberCharacterControllerClass::ToggleWastedWidgetOn()
{
	WastedWidgetRef->ToggleOn();
}

void ARobberCharacterControllerClass::ToggleWastedWidgetOff()
{
	WastedWidgetRef->ToggleOff();
}

void ARobberCharacterControllerClass::ToggleWinWidgetOff()
{
	WinWidgetRef->ToggleOff();
}

void ARobberCharacterControllerClass::ToggleWinWidgetOn()
{
	WinWidgetRef->ToggleOn();
}






