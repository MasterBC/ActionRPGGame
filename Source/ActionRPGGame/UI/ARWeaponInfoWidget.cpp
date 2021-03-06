// Fill out your copyright notice in the Description page of Project Settings.

#include "ARWeaponInfoWidget.h"
#include "ARPlayerController.h"
#include "ARUIWeaponEquipment.h"
#include "ARAbilityBase.h"
#include "ARGunAttributes.h"
void UARWeaponInfoWidget::NativePreConstruct()
{
	if (AARPlayerController* MyPC = Cast<AARPlayerController>(GetOwningPlayer()))
	{
		WeaponEquipement = MyPC->UIWeaponEquipment;
	}
	Super::NativePreConstruct();
}
void UARWeaponInfoWidget::NativeConstruct()
{
	if (AARPlayerController* MyPC = Cast<AARPlayerController>(GetOwningPlayer()))
	{
		WeaponEquipement = MyPC->UIWeaponEquipment;
	}
	Super::NativeConstruct();
}

float UARWeaponInfoWidget::GetMagazineAmmo()
{
	UARAbilityBase* Ability = WeaponEquipement->Weapons[SlotIndex].Get();
	if (!Ability)
		return 0;

	if (UARGunAttributes* Attributes = Cast<UARGunAttributes>(Ability->Attributes))
	{
		return Attributes->Magazine.GetCurrentValue();
	}
	return 0;
}
float UARWeaponInfoWidget::GetMagazineAmmoNormalized()
{
	UARAbilityBase* Ability = WeaponEquipement->Weapons[SlotIndex].Get();
	if (!Ability)
		return 0;

	if (UARGunAttributes* Attributes = Cast<UARGunAttributes>(Ability->Attributes))
	{
		float CurrentValue = Attributes->Magazine.GetCurrentValue();
		FVector2D Input(0, Attributes->Magazine.GetFinalValue());
		return FMath::GetMappedRangeValueClamped(Input, FVector2D(0, 1), CurrentValue);
	}
	return 0;
}