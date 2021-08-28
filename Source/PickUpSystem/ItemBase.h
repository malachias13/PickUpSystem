// (C) Malachias.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemBase.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable, BlueprintType, EditInlineNew, DefaultToInstanced)
class PICKUPSYSTEM_API UItemBase : public UObject
{
	GENERATED_BODY()
public:

	UItemBase();

	virtual class UWorld* GetWorld() const { return World; }

	UPROPERTY(Transient)
		class UWorld* World;

	// Item pickup mesh
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		class UStaticMesh* MeshPickup;

	// Item thumbnail
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		class UTexture2D* Thumbnail;

	// Item display name in the inventory
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		FText ItemDisplayName;

	// Item description
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		FText ItemDescription;

	// Item ID
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		int32 ItemID;

	// The inventory that the owns this item
	UPROPERTY()
		class UInventoryComponent* OwnersInventory;

	virtual void Use(class UInventoryComponent* Component);

	// OnUse Event --> Can be use in blueprints
	UFUNCTION(BlueprintImplementableEvent)
		void OnUse(class UInventoryComponent* Component);
};
