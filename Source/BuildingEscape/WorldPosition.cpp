// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldPosition.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UWorldPosition::UWorldPosition()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWorldPosition::BeginPlay()
{
	Super::BeginPlay();

	FString ObjectName = GetOwner()->GetName();
	//UE_LOG(LogTemp, Log, TEXT("Object name is: %s"), *ObjectName);
	//UE_LOG(LogTemp, Log, TEXT("Object name is: %s"), *GetOwner()->GetName());

	FString ObjectPosition = GetOwner()->GetActorLocation().ToString();
	//FString ObjectPosition = GetOwner()->GetActorTransform().GetLocation().ToString();
	//UE_LOG(LogTemp, Log, TEXT("Object Position is: %s"), *ObjectPosition);
	//UE_LOG(LogTemp, Log, TEXT("Object Position is: %s"), *GetOwner()->GetActorLocation().ToString());

	UE_LOG(LogTemp, Log, TEXT("%s Location is %s"), *ObjectName, *ObjectPosition);
}


// Called every frame
void UWorldPosition::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

