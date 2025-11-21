// Fill out your copyright notice in the Description page of Project Settings.


#include "M_CharacterBase.h"

// Sets default values
AM_CharacterBase::AM_CharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	m_AbilitySystemComponent->SetIsReplicated(true);
	m_AbilitySystemComponent->SetReplicationMode(m_ReplicationMode);
}

// Called when the game starts or when spawned
void AM_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AM_CharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (m_AbilitySystemComponent)
		m_AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

void AM_CharacterBase::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	if (m_AbilitySystemComponent)
		m_AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

// Called every frame
void AM_CharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AM_CharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* AM_CharacterBase::GetAbilitySystemComponent() const
{
	return m_AbilitySystemComponent;
}

