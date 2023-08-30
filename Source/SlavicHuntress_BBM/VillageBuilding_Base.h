// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VillageBuilding_Base.generated.h"

UCLASS()
class SLAVICHUNTRESS_BBM_API AVillageBuilding_Base : public AActor
{
	GENERATED_BODY()
	
public:	

	// Art
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Art")
		TObjectPtr<UStaticMeshComponent> mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Art")
		UMaterial* highlightMat = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Art")
		UMaterial* hoverMat = nullptr;

	//CODE
	UPROPERTY(BlueprintReadWrite)
		bool highlighted = false;

	UPROPERTY(BlueprintReadWrite)
		bool hovered = false;

	//UFUNCTIONS
	UFUNCTION(BlueprintCallable)
		bool Highlight(bool shouldHighlight);

	UFUNCTION(BlueprintCallable)
		bool Hover(bool shouldHighlight);

	// Sets default values for this actor's properties
	AVillageBuilding_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
