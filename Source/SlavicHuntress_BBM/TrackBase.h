// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Materials/Material.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrackBase.generated.h"

UCLASS()
class SLAVICHUNTRESS_BBM_API ATrackBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrackBase();

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


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
