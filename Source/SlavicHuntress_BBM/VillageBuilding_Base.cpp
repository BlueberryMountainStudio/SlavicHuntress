// Fill out your copyright notice in the Description page of Project Settings.


#include "VillageBuilding_Base.h"

// Sets default values
AVillageBuilding_Base::AVillageBuilding_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//initiate mesh
	mesh = CreateOptionalDefaultSubobject<UStaticMeshComponent>("Mesh");
	if (mesh)
	{
		mesh->AlwaysLoadOnClient = true;
		mesh->AlwaysLoadOnServer = true;
		mesh->bOwnerNoSee = false;
		mesh->bCastDynamicShadow = true;
		mesh->bAffectDynamicIndirectLighting = true;
		mesh->PrimaryComponentTick.TickGroup = TG_PrePhysics;
		mesh->SetupAttachment(RootComponent);
		static FName MeshCollisionProfileName(TEXT("FoeMesh"));
		mesh->SetCollisionProfileName(MeshCollisionProfileName);
		mesh->SetGenerateOverlapEvents(true);
		mesh->SetCanEverAffectNavigation(false);
	}

}

bool AVillageBuilding_Base::Highlight(bool shouldHighlight)
{
	if (shouldHighlight == true)
	{
		mesh->SetOverlayMaterial(highlightMat);
		highlighted = true;

	}
	else
	{
		mesh->SetOverlayMaterial(nullptr);
		highlighted = false;
		hovered = false;
	}

	return highlighted;
}

bool AVillageBuilding_Base::Hover(bool shouldHover)
{
	if (shouldHover == true)
	{
		mesh->SetOverlayMaterial(hoverMat);
		hovered = true;
	}
	else
	{
		if (highlighted)
		{
			mesh->SetOverlayMaterial(highlightMat);
		}
		else {
			mesh->SetOverlayMaterial(nullptr);
			hovered = false;
		}
	}
	return hovered;
}

// Called when the game starts or when spawned
void AVillageBuilding_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVillageBuilding_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

