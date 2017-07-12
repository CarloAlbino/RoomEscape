// Fill out your copyright notice in the Description page of Project Settings.

#include "PositionReport.h"
#include "Gameframework/Actor.h"

// Sets default values for this component's properties
UPositionReport::UPositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UPositionReport::BeginPlay()
{
	Super::BeginPlay();

	FString stringBreak = "_";
	FString prefix;
	FString name;
	
	FVector location = GetOwner()->GetActorLocation();

	if (GetOwner()->GetName().Split(stringBreak, &prefix, &name)) {
		UE_LOG(LogTemp, Warning, TEXT("Position report reporting for duty!! Currently on %s, at %s"), *name, *location.ToString());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Position report reporting for duty!! Currently on %s, at %s"), *GetOwner()->GetName(), *location.ToString());
	}
}


// Called every frame
void UPositionReport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

