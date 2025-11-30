// Fill out your copyright notice in the Description page of Project Settings.


#include "M_PawnBase.h"
#include "ProjectOne/M_BasicAttributeSets/M_BasicAttributeSet.h"

// Sets default values
AM_PawnBase::AM_PawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	m_AbilitySystemComponent->SetIsReplicated(true);
	m_AbilitySystemComponent->SetReplicationMode(m_ReplicationMode);


	m_BasicAttributeSet = CreateDefaultSubobject<UM_BasicAttributeSet>(TEXT("BasicAttributeSet"));
}

// Called when the game starts or when spawned
void AM_PawnBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AM_PawnBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (m_AbilitySystemComponent)
		m_AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

void AM_PawnBase::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	if (m_AbilitySystemComponent)
		m_AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

// Called every frame
void AM_PawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AM_PawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* AM_PawnBase::GetAbilitySystemComponent() const
{
	return m_AbilitySystemComponent;
}

