// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "ItemBase.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...

	Capacity = 10;
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	for (auto& Item : DefaultItems)
	{
		AddItem(Item);
	}
}


// Called every frame
/*void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
*/

bool UInventoryComponent::AddItem(UItemBase* Item)
{
	if (Items.Num() >= Capacity || !Item)
	{
		return false;
	}
	Item->OwnersInventory = this;
	Item->World = GetWorld();
	Items.Add(Item);

	//Update UI
	OnInventoryUpdated.Broadcast();
	return true;
}

bool UInventoryComponent::RemoveItem(UItemBase* Item)
{
	if (Item)
	{
		Item->OwnersInventory = nullptr;
		Item->World = nullptr;
		Items.RemoveSingle(Item);

		//Update UI
		OnInventoryUpdated.Broadcast();
		return true;
	}
	return false;
}

void UInventoryComponent::UseItem(class UItemBase* Item)
{
	if (Item)
	{
		Item->Use(this);
		Item->OnUse(this); // Blueprint Event.
	}
}
