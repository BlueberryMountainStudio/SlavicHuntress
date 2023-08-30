// Fill out your copyright notice in the Description page of Project Settings.


#include "TrackBase.h"

// Sets default values
ATrackBase::ATrackBase()
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

bool ATrackBase::Highlight(bool shouldHighlight)
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

bool ATrackBase::Hover(bool shouldHover)
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
void ATrackBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrackBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


