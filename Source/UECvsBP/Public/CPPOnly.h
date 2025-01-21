// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPOnly.generated.h"

UCLASS()
class UECVSBP_API ACPPOnly : public AActor
{
	GENERATED_BODY()
	// U us used for components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, meta = (AllowPrivateAccess = "true")) // these tell the editor how to work see the scipts for the character
		class UStaticMeshComponent* CubeMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, meta = (AllowPrivateAccess = "true"))
	class UTextRenderComponent* TextRenderComponent; // Add this line

public:
	// Sets default values for this actor's properties
	ACPPOnly();
	// create a public variable for us to us
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = ExposedVariables)// only change the default value
		int LoopCount = 5000;
	double start;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = ExposedFunctions)
	void LoopTime();
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};

