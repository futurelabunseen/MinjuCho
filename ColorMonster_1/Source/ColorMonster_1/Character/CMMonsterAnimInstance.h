// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Engine/DamageEvents.h"
#include "CMMonsterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class COLORMONSTER_1_API UCMMonsterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UCMMonsterAnimInstance();
	
	void SetMonster(class ACMMonster* const InMonster);
protected:
	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Character)
	TObjectPtr<class ACharacter> Owner;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Character)
	TObjectPtr<class UCharacterMovementComponent> Movement;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	FVector Velocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	float GroundSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	uint8 bIsIdle : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	float MovingThreshould;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	uint8 bIsFalling : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	uint8 bIsJumping : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	float JumpingThreshould;
public:
	UFUNCTION()
	void PlayAttackMontage();

	UFUNCTION()
	void PlayDamageMontage();

	UFUNCTION()
	void PlayDeadMontage();

	UFUNCTION()
	void AnimNotify_EndedAttack();

	UFUNCTION()
	void AnimNotify_CheckHit();

private:
	// Monster
	TObjectPtr<class ACMMonster> Monster;
	// Attack Montage
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	TObjectPtr<class UAnimMontage> AttackMontage;
	// Death Montage
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Death, Meta = (AllowPrivateAccess = true))
	TObjectPtr<class UAnimMontage> DeathMontage;
	// Damage Montage
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Death, Meta = (AllowPrivateAccess = true))
	TObjectPtr<class UAnimMontage> DamageMontage;
	
};
