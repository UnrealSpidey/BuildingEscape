// Copyright Nick Bullard

#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "OpenDoor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	DoorInitialYaw = GetOwner()->GetActorRotation().Yaw;
	DoorCurrentYaw = DoorInitialYaw;
	DoorTargetYaw += DoorInitialYaw; //DoorTargetYaw = DoorTargetYaw + DoorInitialYaw; The += is known as a compond assignment opperator

	if (!PressurePlate)
	{
		UE_LOG(LogTemp, Error, TEXT("%s has the OpenDoor component but PressurePlate is Null"), *GetOwner()->GetName());
	}
	
	ActorThatOpensDoor = GetWorld()->GetFirstPlayerController()->GetPawn();

}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PressurePlate && PressurePlate->IsOverlappingActor(ActorThatOpensDoor)) // the PressurePlate && is a lazy guard
	{
		OpenDoor(DeltaTime);
		DoorLastOpened = GetWorld()->GetTimeSeconds();
	}
	else
	{
		if ((GetWorld()->GetTimeSeconds() - DoorLastOpened) > DoorClosedDelay)
		{
				CloseDoor(DeltaTime);
		}
	}
}


// Called when Pawn is in Trigger Volume
void UOpenDoor::OpenDoor(float DeltaTime)
{
	DoorCurrentYaw = FMath::Lerp(DoorCurrentYaw, DoorTargetYaw, DeltaTime * DoorOpenSpeed);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = DoorCurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation); 
}

// Called when Pawn leaves the Trigger Volume + DoorClosedDelay
void UOpenDoor::CloseDoor(float DeltaTime)
{
	DoorCurrentYaw = FMath::Lerp(DoorCurrentYaw, DoorInitialYaw, DeltaTime * DoorCloseSpeed);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = DoorCurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);
}
