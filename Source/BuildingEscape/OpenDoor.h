// Copyright Nick Bullard

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h" // Always needs to be at bottom

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);

private:

	float DoorInitialYaw;
	float DoorCurrentYaw;

	UPROPERTY(EditAnywhere, meta=(DisplayName = "Door Open Angle"))
	float DoorTargetYaw = 90.f;

	float DoorLastOpened = 0.f;

	UPROPERTY(EditAnywhere)
	float DoorClosedDelay = 0.5f;

	UPROPERTY(EditAnywhere)
	float DoorOpenSpeed = .8f;

	UPROPERTY(EditAnywhere)
	float DoorCloseSpeed = 2.f;
	UPROPERTY(EditAnywhere)
	
	ATriggerVolume* PressurePlate; // Look at moving this up, as it's important to set

	//UPROPERTY(EditAnywhere)
	AActor* ActorThatOpensDoor;


};
