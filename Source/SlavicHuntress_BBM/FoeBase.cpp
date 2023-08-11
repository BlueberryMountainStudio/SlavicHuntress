// Fill out your copyright notice in the Description page of Project Settings.


#include "FoeBase.h"

// Sets default values
AFoeBase::AFoeBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateOptionalDefaultSubobject<USkeletalMeshComponent>("Mesh");
	if (mesh)
	{
		mesh->AlwaysLoadOnClient = true;
		mesh->AlwaysLoadOnServer = true;
		mesh->bOwnerNoSee = false;
		mesh->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPose;
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

void AFoeBase::Highlight(bool shouldHighlight)
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
	
}

void AFoeBase::Hover(bool shouldHover)
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

}

// Called when the game starts or when spawned
void AFoeBase::BeginPlay()
{
	Super::BeginPlay();
	currentHealth = maxHealth;
	
}

// Called every frame
void AFoeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

