// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPOnly.h"
#include <Containers/UnrealString.h>
#include "Engine/StaticMesh.h"
#include "Engine/Engine.h"
#include "Components/StaticMeshComponent.h" 
#include "Components/TextRenderComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACPPOnly::ACPPOnly()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// create our mesh
	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	//CubeMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndProbe); // notice we use -> as it's a pointer, QueryAndProbe is a trigger based collision

	SetRootComponent(CubeMesh);

	// Set up overlap events
	CubeMesh->SetGenerateOverlapEvents(true);
	CubeMesh->OnComponentBeginOverlap.AddDynamic(this, &ACPPOnly::OnOverlapBegin);

	FString LoopCountString = FString::Printf(TEXT("Loop %d"), LoopCount);

	TextRenderComponent = CreateDefaultSubobject<UTextRenderComponent>(TEXT("LoopCountTextext"));
	TextRenderComponent->SetupAttachment(RootComponent);
	TextRenderComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f)); // Set the relative location
	TextRenderComponent->SetText(FText::FromString(LoopCountString)); // Set the initial text
}

// Called when the game starts or when spawned
void ACPPOnly::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Hello i am alive v1.0"));
	FString LoopCountString = FString::Printf(TEXT("Loop %d"), LoopCount);
	TextRenderComponent->SetText(FText::FromString(LoopCountString));
}

// Called every frame
void ACPPOnly::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Create and attach the TextRenderComponent
}


// our loop function
void ACPPOnly::LoopTime()
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
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, EndText);
}

// Called when the CubeMesh overlaps another actor
void ACPPOnly::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("OverlapBegin triggered"));
	// Call LoopTime method when overlap begins
	LoopTime();
}