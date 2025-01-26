// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_BP_Hybrid.generated.h"

UCLASS()
class UECVSBP_API ACPP_BP_Hybrid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_BP_Hybrid();
	// create a public variable for us to us
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ExposedVariables)// only change the default value
	int LoopCount = 5000;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = ExposedFunctions)
	void LoopTime();

};
