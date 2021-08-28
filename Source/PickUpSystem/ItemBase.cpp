// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"

UItemBase::UItemBase()
{
	ItemDisplayName = FText::FromString("Item");
	ItemDescription = FText::FromString("Item Description");
	ItemID = -1;
}

void UItemBase::Use(UInventoryComponent* Component)
{

}