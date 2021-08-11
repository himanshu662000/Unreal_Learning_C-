// Fill out your copyright notice in the Description page of Project Settings.


#include "himanshu.h"

#include <string>

// Sets default values for this component's properties
Uhimanshu::Uhimanshu()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void Uhimanshu::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void Uhimanshu::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	FString message=TEXT("jad");
	
	Uhimanshu::ExecuteSweepTrace(DeltaTime);
	FRotator FinalRotation=GetOwner()->GetActorRotation();
	FinalRotation.Yaw=rotating_speed+(FinalRotation.Yaw);
	GetOwner()->SetActorRotation(FinalRotation);
	UE_LOG(LogTemp,Display,TEXT("Final Rotation is %s"),*FinalRotation.ToString());
}

void Uhimanshu::ExecuteSweepTrace(float &DeltaTime)
{
	TArray <struct FHitResult> HitResults;
	FVector Actor_loc = GetOwner()->GetActorLocation();
	FVector Start_loc = Actor_loc;
	FVector End_loc = Actor_loc +trace_distance*(GetForwardVector());

	// const FCollisionShape CollisionShape = FCollisionShape::MakeSphere(sweep_radius);
	//bool Hit = GetWorld()->SweepMultiByChannel(HitResults, Start_loc, End_loc, FQuat::Identity, ECC_Camera, CollisionShape);
	DrawDebugLine(GetWorld(), Start_loc, End_loc, FColor::Green, false, -0.1f, 0, 2.5f);
	bool Line_Hit = GetWorld()->LineTraceMultiByChannel(HitResults, Start_loc, End_loc, ECC_Visibility);
	if (Line_Hit)
	{
		for (FHitResult const HitResult : HitResults)
		{
			float pos_x=HitResult.GetActor()->GetActorLocation().X;
			FString Display_message=TEXT("Himanshu");
			
			
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red,Display_message);

			FVector Actor_Newlocation { HitResult.GetActor()->GetActorLocation() };
			Actor_Newlocation.X = speed_ofTrace * (HitResult.GetActor()->GetActorLocation().X);

			HitResult.GetActor()->SetActorLocation(Actor_Newlocation);

		}
	}

}

