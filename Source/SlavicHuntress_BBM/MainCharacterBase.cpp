// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacterBase.h"

// Sets default values
AMainCharacterBase::AMainCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	interactionRange = CreateOptionalDefaultSubobject<USphereComponent>("InteractionRange");
	if (interactionRange)
	{
		interactionRange->AlwaysLoadOnClient = true;
		interactionRange->AlwaysLoadOnServer = true;
		interactionRange->bOwnerNoSee = false;
		interactionRange->SetSphereRadius(600);
		interactionRange->bCastDynamicShadow = true;
		interactionRange->bAffectDynamicIndirectLighting = true;
		interactionRange->PrimaryComponentTick.TickGroup = TG_PrePhysics;
		interactionRange->SetupAttachment(RootComponent);
		static FName SphereCollisionProfileName(TEXT("InteractionRange"));
		interactionRange->SetCollisionProfileName(SphereCollisionProfileName);
		interactionRange->SetGenerateOverlapEvents(true);
		interactionRange->SetCanEverAffectNavigation(false);
	}
}

// Called when the game starts or when spawned
void AMainCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

