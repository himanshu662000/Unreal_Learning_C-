// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "himanshu.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API Uhimanshu : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	Uhimanshu();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;



	UPROPERTY(EditAnywhere)
	float rotating_speed=1.01f;
	UPROPERTY(EditAnywhere)
	float trace_distance=1000.f;
	UPROPERTY(EditAnywhere)
	float speed_ofTrace=1.02f;


	FString& printf(const wchar_t* Str, const TCHAR* Display_Message);
	void ExecuteSweepTrace(float &DeltaTime);

	
		
};
