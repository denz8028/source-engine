//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:		Crowbar - an old favorite
//
// $NoKeywords: $
//=============================================================================//

#include "ai_activity.h"
#include "cbase.h"
#include "basehlcombatweapon.h"
#include "player.h"
#include "gamerules.h"
#include "ammodef.h"
#include "mathlib/mathlib.h"
#include "in_buttons.h"
#include "soundent.h"
#include "basebludgeonweapon.h"
#include "vstdlib/random.h"
#include "npcevent.h"
#include "ai_basenpc.h"
//#include "weapon_crowbar.h"

#define	FLASHLIGHT_RANGE	75.0f
#define	FLASHLIGHT_REFIRE	0.4f

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

ConVar    sk_plr_dmg_flashlight		( "sk_plr_dmg_flashlight","0");
ConVar    sk_npc_dmg_flashlight		( "sk_npc_dmg_flashlight","0");

//-----------------------------------------------------------------------------
// CWeaponCrowbar
//-----------------------------------------------------------------------------
class CWeaponFlashlight : public CBaseHLBludgeonWeapon
{
public:
	DECLARE_CLASS( CWeaponFlashlight, CBaseHLBludgeonWeapon );

	DECLARE_SERVERCLASS();
	DECLARE_ACTTABLE();

	CWeaponFlashlight();

	float		GetRange( void )		{	return	FLASHLIGHT_RANGE;	}
	float		GetFireRate( void )		{	return	FLASHLIGHT_REFIRE;	}

	void		AddViewKick( void );
	float		GetDamageForActivity( Activity hitActivity );

	virtual int WeaponMeleeAttack1Condition( float flDot, float flDist );
	void   SecondaryAttack( void );

	// Animation event
	virtual void Operator_HandleAnimEvent( animevent_t *pEvent, CBaseCombatCharacter *pOperator );

private:
	// Animation event handlers
	void HandleAnimEventMeleeHit( animevent_t *pEvent, CBaseCombatCharacter *pOperator );
};

IMPLEMENT_SERVERCLASS_ST(CWeaponFlashlight, DT_WeaponFlashlight)
END_SEND_TABLE()

#ifndef HL2MP
LINK_ENTITY_TO_CLASS( weapon_flashlight, CWeaponFlashlight );
PRECACHE_WEAPON_REGISTER( weapon_flashlight );
#endif

acttable_t CWeaponFlashlight::m_acttable[] =
{
	{ ACT_MELEE_ATTACK1,	ACT_MELEE_ATTACK_SWING, true },
	{ ACT_IDLE,				ACT_IDLE_ANGRY_MELEE,	false },
	{ ACT_IDLE_ANGRY,		ACT_IDLE_ANGRY_MELEE,	false },
};

IMPLEMENT_ACTTABLE(CWeaponFlashlight);

//-----------------------------------------------------------------------------
// Constructor
//-----------------------------------------------------------------------------
CWeaponFlashlight::CWeaponFlashlight( void )
{
}

//-----------------------------------------------------------------------------
// Purpose: Get the damage amount for the animation we're doing
// Input  : hitActivity - currently played activity
// Output : Damage amount
//-----------------------------------------------------------------------------
float CWeaponFlashlight::GetDamageForActivity( Activity hitActivity )
{
	if ( ( GetOwner() != NULL ) && ( GetOwner()->IsPlayer() ) )
		return sk_plr_dmg_flashlight.GetFloat();

	return sk_npc_dmg_flashlight.GetFloat();
}

//-----------------------------------------------------------------------------
// Purpose: Add in a view kick for this weapon
//-----------------------------------------------------------------------------
void CWeaponFlashlight::AddViewKick( void )
{
	CBasePlayer *pPlayer  = ToBasePlayer( GetOwner() );

	if ( pPlayer == NULL )
		return;

	QAngle punchAng;

	punchAng.x = random->RandomFloat( 1.0f, 2.0f );
	punchAng.y = random->RandomFloat( -2.0f, -1.0f );
	punchAng.z = 0.0f;

	pPlayer->ViewPunch( punchAng );
}


//-----------------------------------------------------------------------------
// Attempt to lead the target (needed because citizens can't hit manhacks with the crowbar!)
//-----------------------------------------------------------------------------
ConVar sk_flashlight_lead_time( "sk_flashlight_lead_time", "0.9" );

int CWeaponFlashlight::WeaponMeleeAttack1Condition( float flDot, float flDist )
{
	// Attempt to lead the target (needed because citizens can't hit manhacks with the crowbar!)
	CAI_BaseNPC *pNPC	= GetOwner()->MyNPCPointer();
	CBaseEntity *pEnemy = pNPC->GetEnemy();
	if (!pEnemy)
		return COND_NONE;

	Vector vecVelocity;
	vecVelocity = pEnemy->GetSmoothedVelocity( );

	// Project where the enemy will be in a little while
	float dt = sk_flashlight_lead_time.GetFloat();
	dt += random->RandomFloat( -0.3f, 0.2f );
	if ( dt < 0.0f )
		dt = 0.0f;

	Vector vecExtrapolatedPos;
	VectorMA( pEnemy->WorldSpaceCenter(), dt, vecVelocity, vecExtrapolatedPos );

	Vector vecDelta;
	VectorSubtract( vecExtrapolatedPos, pNPC->WorldSpaceCenter(), vecDelta );

	if ( fabs( vecDelta.z ) > 70 )
	{
		return COND_TOO_FAR_TO_ATTACK;
	}

	Vector vecForward = pNPC->BodyDirection2D( );
	vecDelta.z = 0.0f;
	float flExtrapolatedDist = Vector2DNormalize( vecDelta.AsVector2D() );
	if ((flDist > 64) && (flExtrapolatedDist > 64))
	{
		return COND_TOO_FAR_TO_ATTACK;
	}

	float flExtrapolatedDot = DotProduct2D( vecDelta.AsVector2D(), vecForward.AsVector2D() );
	if ((flDot < 0.7) && (flExtrapolatedDot < 0.7))
	{
		return COND_NOT_FACING_ATTACK;
	}

	return COND_CAN_MELEE_ATTACK1;
}


//-----------------------------------------------------------------------------
// Animation event handlers
//-----------------------------------------------------------------------------
void CWeaponFlashlight::HandleAnimEventMeleeHit( animevent_t *pEvent, CBaseCombatCharacter *pOperator )
{
	// Trace up or down based on where the enemy is...
	// But only if we're basically facing that direction
	Vector vecDirection;
	AngleVectors( GetAbsAngles(), &vecDirection );

	CBaseEntity *pEnemy = pOperator->MyNPCPointer() ? pOperator->MyNPCPointer()->GetEnemy() : NULL;
	if ( pEnemy )
	{
		Vector vecDelta;
		VectorSubtract( pEnemy->WorldSpaceCenter(), pOperator->Weapon_ShootPosition(), vecDelta );
		VectorNormalize( vecDelta );

		Vector2D vecDelta2D = vecDelta.AsVector2D();
		Vector2DNormalize( vecDelta2D );
		if ( DotProduct2D( vecDelta2D, vecDirection.AsVector2D() ) > 0.8f )
		{
			vecDirection = vecDelta;
		}
	}

	Vector vecEnd;
	VectorMA( pOperator->Weapon_ShootPosition(), 50, vecDirection, vecEnd );
	CBaseEntity *pHurt = pOperator->CheckTraceHullAttack( pOperator->Weapon_ShootPosition(), vecEnd,
		Vector(-16,-16,-16), Vector(36,36,36), sk_npc_dmg_flashlight.GetFloat(), DMG_CLUB, 0.75 );

	// did I hit someone?
	if ( pHurt )
	{
		// play sound
		WeaponSound( MELEE_HIT );

		// Fake a trace impact, so the effects work out like a player's crowbaw
		trace_t traceHit;
		UTIL_TraceLine( pOperator->Weapon_ShootPosition(), pHurt->GetAbsOrigin(), MASK_SHOT_HULL, pOperator, COLLISION_GROUP_NONE, &traceHit );
		ImpactEffect( traceHit );
	}
	else
	{
		WeaponSound( MELEE_MISS );
	}
}

void CWeaponFlashlight::SecondaryAttack ( void ) {
	CBasePlayer *pPlayer = ToBasePlayer( GetOwner() );
	if ( pPlayer->FlashlightIsOn() )
	{
		pPlayer->FlashlightTurnOff();
	}
	else
	{
		pPlayer->FlashlightTurnOn();
	}
	m_flNextSecondaryAttack = gpGlobals->curtime + 0.75;
}

//-----------------------------------------------------------------------------
// Animation event
//-----------------------------------------------------------------------------
void CWeaponFlashlight::Operator_HandleAnimEvent( animevent_t *pEvent, CBaseCombatCharacter *pOperator )
{
	CBasePlayer *pPlayer = ToBasePlayer( GetOwner() );
	CBaseCombatWeapon *pWeapon = pPlayer->GetActiveWeapon();
	switch( pEvent->event )
	{
	case EVENT_WEAPON_MELEE_HIT:
		HandleAnimEventMeleeHit( pEvent, pOperator );
		break;

	default:
		BaseClass::Operator_HandleAnimEvent( pEvent, pOperator );
		break;
	}
	switch ( pWeapon->GetActivity() ) {
		case ACT_VM_HOLSTER:
			if ( pPlayer->FlashlightIsOn() ) {
				pPlayer->FlashlightTurnOff();
			}
			break;
	}
}
