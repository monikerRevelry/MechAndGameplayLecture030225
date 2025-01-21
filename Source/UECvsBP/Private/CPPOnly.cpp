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

	FString LoopCountString = FString::Printf(TEXT("LoopCount: %d"), LoopCount);

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
	double end;

	// start trace
	FScopeCycleCounterUObject ScopeCounter(this);

	UGameplayStatics::GetAccurateRealTime(temp, start);
	UE_LOG(LogTemp, Warning, TEXT("Start time is: %d"), start);
	for (int i = 0; i < LoopCount; i++)
	{
		if (GEngine)
		{
			UE_LOG(LogTemp, Warning, TEXT("CPP loop is: %d"), i);
		}
	}
	UGameplayStatics::GetAccurateRealTime(temp, end);
	UE_LOG(LogTemp, Warning, TEXT("end time is: %d"), start - end);
}

// Called when the CubeMesh overlaps another actor
void ACPPOnly::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("OverlapBegin triggered"));
	// Call LoopTime method when overlap begins
	LoopTime();
}