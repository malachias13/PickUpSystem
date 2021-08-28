// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

// Blueprints will bind to this to Update UI.
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInventoryUpdated);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PICKUPSYSTEM_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Item [Player]")
		void UseItem(class UItemBase* Item);

public:	
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Inventory
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		bool AddItem(class UItemBase* Item);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		bool RemoveItem(class UItemBase* Item);

	UPROPERTY(EditDefaultsOnly, Instanced)
		TArray<class UItemBase*> DefaultItems;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
		TArray<class UItemBase*> Items;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
		int32 Capacity;

	// Event
	UPROPERTY(BlueprintAssignable, Category = "Inventory")
		FInventoryUpdated OnInventoryUpdated;
		
};
