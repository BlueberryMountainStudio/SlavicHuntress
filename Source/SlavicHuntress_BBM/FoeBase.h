// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FoeBase.generated.h"

UCLASS()
class SLAVICHUNTRESS_BBM_API AFoeBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFoeBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameDesign")
		float maxHealth = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameDesign|HitZoneMultiplier")
		float defaultMultiplier = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameDesign|HitZoneMultiplier")
		float weakMultiplier = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameDesign|HitZoneMultiplier")
		float lungMultiplier = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameDesign|HitZoneMultiplier")
		float heartMultiplier = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameDesign|HitZoneMultiplier")
		float headMultiplier = 0;

	UPROPERTY(BlueprintReadWrite)
		float currentHealth = 0;

	UPROPERTY(BlueprintReadWrite)
		bool hovered? = 0;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
