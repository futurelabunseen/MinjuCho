// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "GameplayTags.h"
#include "CMProjectileActor.generated.h"

UCLASS()
class COLORMONSTER_1_API ACMProjectileActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACMProjectileActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile")
	TObjectPtr<class USphereComponent> CollisionComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = "StaticMesh")
	TObjectPtr<class UStaticMeshComponent> StaticMesh;

	UPROPERTY(VisibleAnywhere, Category = "Movement")
	TObjectPtr<class UProjectileMovementComponent> ProjectileMovementComponent;

	UFUNCTION()
	void FireInDirection(const FVector& ShootDirection);

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	FORCEINLINE void SetCurrentColor(const FGameplayTag& InColor) {CurrentColor = InColor;}

	UFUNCTION()
	void ChangeColor(const FGameplayTag& InColor);

	UFUNCTION()
	void AttachDecalToMonster(AActor* HitMonster, const FLinearColor& InColor);
	UPROPERTY(EditAnywhere, Category = Effect, meta = (AllowPrivateAccess = "true"))
	FVector DecalSize;
protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Color, meta = (AllowPrivateAccess = "true"))
	FGameplayTag CurrentColor;

	// Decal Effect For Actor
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Effect, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class ADecalActor> EffectClass;

	// Decal Material For Component
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Effect, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UMaterialInstance> DecalMaterial;
};

