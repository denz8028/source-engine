//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//
//=============================================================================//
//
// Health.cpp
//
// implementation of CHudHealth class
//
#include "cbase.h"
#include "hud.h"
#include "hud_macros.h"
#include "view.h"

#include "iclientmode.h"

#include <KeyValues.h>
#include <vgui/ISurface.h>
#include <vgui/ISystem.h>
#include <vgui_controls/AnimationController.h>

#include <vgui/ILocalize.h>

using namespace vgui;

#include "hudelement.h"
#include "hud_numericdisplay.h"

#include "convar.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

#define INIT_HEALTH -1

//-----------------------------------------------------------------------------
// Purpose: Health panel
//-----------------------------------------------------------------------------
class CHudHealth : public CHudElement, public CHudNumericDisplay
{
	DECLARE_CLASS_SIMPLE( CHudHealth, CHudNumericDisplay );

public:
	CHudHealth( const char *pElementName );
	virtual void Init( void );
	virtual void VidInit( void );
	virtual void Reset( void );
	virtual void OnThink();
			void MsgFunc_Damage( bf_read &msg );

private:
	// old variables
	int		m_iHealth;

	int		m_bitsDamage;
    CPanelAnimationVarAliasType( float, legacy_xpos, "legacy_xpos", "0", "proportional_float" );
    CPanelAnimationVarAliasType( float, legacy_ypos, "legacy_ypos", "0", "proportional_float" );
    CPanelAnimationVarAliasType( float, legacy_wide, "legacy_wide", "0", "proportional_float" );
    CPanelAnimationVarAliasType( float, legacy_tall, "legacy_tall", "0", "proportional_float" );
    CPanelAnimationVarAliasType( float, simple_xpos, "simple_xpos", "0", "proportional_float" );
    CPanelAnimationVarAliasType( float, simple_ypos, "simple_ypos", "0", "proportional_float" );
    CPanelAnimationVarAliasType( float, simple_wide, "simple_wide", "0", "proportional_float" );
    CPanelAnimationVarAliasType( float, simple_tall, "simple_tall", "0", "proportional_float" );
    CPanelAnimationVarAliasType( float, progress_xpos, "progress_xpos", "0", "proportional_float" );
    CPanelAnimationVarAliasType( float, progress_ypos, "progress_ypos", "0", "proportional_float" );
    CPanelAnimationVarAliasType( float, progress_wide, "progress_wide", "0", "proportional_float" );
    CPanelAnimationVarAliasType( float, progress_tall, "progress_tall", "0", "proportional_float" );
    CPanelAnimationVar( Color, m_ProgressFgColor, "ProgressFgColor", "FgColor" );
    CPanelAnimationVar( Color, m_ProgressBgColor, "ProgressBgColor", "BgColor" );

    int m_iStyle;
    int m_iOriginalXPos;
    int m_iOriginalYPos;
    int m_iOriginalWide;
    int m_iOriginalTall;

};	

DECLARE_HUDELEMENT( CHudHealth );
DECLARE_HUD_MESSAGE( CHudHealth, Damage );

//-----------------------------------------------------------------------------
// Purpose: Constructor
//-----------------------------------------------------------------------------
CHudHealth::CHudHealth( const char *pElementName ) : CHudElement( pElementName ), CHudNumericDisplay(NULL, "HudHealth")
{
	SetHiddenBits( HIDEHUD_HEALTH | HIDEHUD_PLAYERDEAD | HIDEHUD_NEEDSUIT );

    m_iStyle = -1;
    m_iOriginalXPos = 0;
    m_iOriginalYPos = 0;
    m_iOriginalWide = 0;
    m_iOriginalTall = 0;
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CHudHealth::Init()
{
	HOOK_HUD_MESSAGE( CHudHealth, Damage );
	Reset();
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CHudHealth::Reset()
{
	m_iHealth		= INIT_HEALTH;
	m_bitsDamage	= 0;

	wchar_t *tempString = g_pVGuiLocalize->Find("#Valve_Hud_HEALTH");

	if (tempString)
	{
		SetLabelText(tempString);
	}
	else
	{
		SetLabelText(L"HEALTH");
	}
	SetDisplayValue(m_iHealth);
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CHudHealth::VidInit()
{
	Reset();
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CHudHealth::OnThink()
{
	int newHealth = 0;
	C_BasePlayer *local = C_BasePlayer::GetLocalPlayer();
	if ( local )
	{
		// Never below zero
		newHealth = MAX( local->GetHealth(), 0 );
	}

	// Only update the fade if we've changed health
	if ( newHealth == m_iHealth )
	{
		return;
	}

	m_iHealth = newHealth;

	if ( m_iHealth >= 20 )
	{
		g_pClientMode->GetViewportAnimationController()->StartAnimationSequence("HealthIncreasedAbove20");
	}
	else if ( m_iHealth > 0 )
	{
		g_pClientMode->GetViewportAnimationController()->StartAnimationSequence("HealthIncreasedBelow20");
		g_pClientMode->GetViewportAnimationController()->StartAnimationSequence("HealthLow");
	}

    // draw the progress bar
    DrawBox( progress_xpos, progress_ypos, progress_wide, progress_tall, m_ProgressBgColor, 1.0f );
    if ( m_iHealth > 0 )
        DrawBox( progress_xpos, progress_ypos, progress_wide * Clamp( m_iHealth / 100.0f, 0.0f, 1.0f ), progress_tall, m_ProgressFgColor, 1.0f );


	SetDisplayValue(m_iHealth);
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CHudHealth::MsgFunc_Damage( bf_read &msg )
{

	int armor = msg.ReadByte();	// armor
	int damageTaken = msg.ReadByte();	// health
	long bitsDamage = msg.ReadLong(); // damage bits
	bitsDamage; // variable still sent but not used

	Vector vecFrom;

	vecFrom.x = msg.ReadBitCoord();
	vecFrom.y = msg.ReadBitCoord();
	vecFrom.z = msg.ReadBitCoord();

	// Actually took damage?
	if ( damageTaken > 0 || armor > 0 )
	{
		if ( damageTaken > 0 )
		{
			// start the animation
			g_pClientMode->GetViewportAnimationController()->StartAnimationSequence("HealthDamageTaken");
		}
	}
}