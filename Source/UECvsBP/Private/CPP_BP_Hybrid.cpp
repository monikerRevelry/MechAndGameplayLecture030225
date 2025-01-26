// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_BP_Hybrid.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
ACPP_BP_Hybrid::ACPP_BP_Hybrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_BP_Hybrid::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_BP_Hybrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// our loop function
void ACPP_BP_Hybrid::LoopTime()
{
    // temp vars
    int32 temp;
    double start;
    double end;

    // start trace
    FScopeCycleCounterUObject ScopeCounter(this);

    UGameplayStatics::GetAccurateRealTime(temp, start);
    //UE_LOG(LogTemp, Warning, TEXT("Start time is: %f"), start);
    for (int i = 0; i < LoopCount; i++)
    {
        if (GEngine)
        {
            FString LoopText = FString::Printf(TEXT("CPP loop is: %d"), i);
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, LoopText);
        }
    }
    UGameplayStatics::GetAccurateRealTime(temp, end);
    FString EndText = FString::Printf(TEXT("end time is: %f"), end - start);
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, EndText);
}

