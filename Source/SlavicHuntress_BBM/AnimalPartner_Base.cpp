// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimalPartner_Base.h"

// Sets default values
AAnimalPartner_Base::AAnimalPartner_Base()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAnimalPartner_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAnimalPartner_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAnimalPartner_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

