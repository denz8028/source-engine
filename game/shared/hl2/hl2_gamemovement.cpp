//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
// $NoKeywords: $
//=============================================================================//

#include "cbase.h"
#include "gamemovement.h"
#include "hl2_gamerules.h"
#include "in_buttons.h"
#include "movevars_shared.h"
//#ifndef CLIENT_DLL
#include "hl2_player_shared.h"
//#else
//#include "c_hl2_playerlocaldata.h"
//#endif
//#include "weapon_base.h"

class CHL2GameMovement : public CGameMovement
{
public:
	DECLARE_CLASS( CHL2GameMovement, CGameMovement );

	virtual void	OnJump( float fImpulse );
	virtual void	OnLand( float fVelocity );
	virtual void Duck( void );
	virtual void FinishUnDuck( void );
	virtual void FinishDuck( void );
	virtual bool CanUnduck();
	virtual void HandleDuckingSpeedCrop();
};

void CHL2GameMovement::OnJump( float fImpulse )
{
    CHL2_Player *pHL2Player;
	pHL2Player->OnJump( fImpulse );
}
