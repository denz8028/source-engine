////////////////////////////////////////////////////////////////////
//
// hl2orange.spa.h
//
// Auto-generated on Thursday, 13 September 2007 at 16:59:17
// XLAST project version 1.0.402.0
// SPA Compiler version 2.0.6274.0
//
////////////////////////////////////////////////////////////////////

#ifndef __THE_ORANGE_BOX_SPA_H__
#define __THE_ORANGE_BOX_SPA_H__

#ifdef __cplusplus
extern "C" {
#endif

//
// Title info
//

#define TITLEID_THE_ORANGE_BOX                      0x4541080F

//
// Context ids
//
// These values are passed as the dwContextId to XUserSetContext.
//

#define CONTEXT_CHAPTER_HL2                         0
#define CONTEXT_SCENARIO                            1
#define CONTEXT_GAME                                2
#define CONTEXT_CHAPTER_EP1                         3
#define CONTEXT_CHAPTER_EP2                         4
#define CONTEXT_CHAPTER_PORTAL                      5

//
// Context values
//
// These values are passed as the dwContextValue to XUserSetContext.
//

// Values for CONTEXT_CHAPTER_HL2

#define CONTEXT_CHAPTER_HL2_POINT_INSERTION         0
#define CONTEXT_CHAPTER_HL2_A_RED_LETTER_DAY        1
#define CONTEXT_CHAPTER_HL2_ROUTE_KANAL             2
#define CONTEXT_CHAPTER_HL2_WATER_HAZARD            3
#define CONTEXT_CHAPTER_HL2_BLACK_MESA_EAST         4
#define CONTEXT_CHAPTER_HL2_RAVENHOLM               5
#define CONTEXT_CHAPTER_HL2_HIGHWAY_17              6
#define CONTEXT_CHAPTER_HL2_SANDTRAPS               7
#define CONTEXT_CHAPTER_HL2_NOVA_PROSPEKT           8
#define CONTEXT_CHAPTER_HL2_ENTANGLEMENT            9
#define CONTEXT_CHAPTER_HL2_ANTICITIZEN_ONE         10
#define CONTEXT_CHAPTER_HL2_FOLLOW_FREEMAN          11
#define CONTEXT_CHAPTER_HL2_OUR_BENEFACTORS         12
#define CONTEXT_CHAPTER_HL2_DARK_ENERGY             13

// Values for CONTEXT_SCENARIO

#define CONTEXT_SCENARIO_CTF_2FORT                  0
#define CONTEXT_SCENARIO_CP_DUSTBOWL                1
#define CONTEXT_SCENARIO_CP_GRANARY                 2
#define CONTEXT_SCENARIO_CP_WELL                    3
#define CONTEXT_SCENARIO_CP_GRAVELPIT               4
#define CONTEXT_SCENARIO_TC_HYDRO                   5
#define CONTEXT_SCENARIO_CTF_CLOAK                  6
#define CONTEXT_SCENARIO_CP_CLOAK                   7

// Values for CONTEXT_GAME

#define CONTEXT_GAME_GAME_HALF_LIFE_2               0
#define CONTEXT_GAME_GAME_EPISODE_ONE               1
#define CONTEXT_GAME_GAME_EPISODE_TWO               2
#define CONTEXT_GAME_GAME_PORTAL                    3
#define CONTEXT_GAME_GAME_TEAM_FORTRESS             4

// Values for CONTEXT_CHAPTER_EP1

#define CONTEXT_CHAPTER_EP1_UNDUE_ALARM             0
#define CONTEXT_CHAPTER_EP1_DIRECT_INTERVENTION     1
#define CONTEXT_CHAPTER_EP1_LOWLIFE                 2
#define CONTEXT_CHAPTER_EP1_URBAN_FLIGHT            3
#define CONTEXT_CHAPTER_EP1_EXIT_17                 4

// Values for CONTEXT_CHAPTER_EP2

#define CONTEXT_CHAPTER_EP2_TO_THE_WHITE_FOREST     0
#define CONTEXT_CHAPTER_EP2_THIS_VORTAL_COIL        1
#define CONTEXT_CHAPTER_EP2_FREEMAN_PONTIFEX        2
#define CONTEXT_CHAPTER_EP2_RIDING_SHOTGUN          3
#define CONTEXT_CHAPTER_EP2_UNDER_THE_RADAR         4
#define CONTEXT_CHAPTER_EP2_OUR_MUTUAL_FIEND        5
#define CONTEXT_CHAPTER_EP2_T_MINUS_ONE             6

// Values for CONTEXT_CHAPTER_PORTAL

#define CONTEXT_CHAPTER_PORTAL_TESTCHAMBER_00       0
#define CONTEXT_CHAPTER_PORTAL_TESTCHAMBER_04       1
#define CONTEXT_CHAPTER_PORTAL_TESTCHAMBER_08       2
#define CONTEXT_CHAPTER_PORTAL_TESTCHAMBER_10       3
#define CONTEXT_CHAPTER_PORTAL_TESTCHAMBER_13       4
#define CONTEXT_CHAPTER_PORTAL_TESTCHAMBER_14       5
#define CONTEXT_CHAPTER_PORTAL_TESTCHAMBER_15       6
#define CONTEXT_CHAPTER_PORTAL_TESTCHAMBER_16       7
#define CONTEXT_CHAPTER_PORTAL_TESTCHAMBER_17       8
#define CONTEXT_CHAPTER_PORTAL_TESTCHAMBER_18       9
#define CONTEXT_CHAPTER_PORTAL_TESTCHAMBER_19       10

// Values for X_CONTEXT_PRESENCE

#define CONTEXT_PRESENCE_TF_CP                      0
#define CONTEXT_PRESENCE_TF_CTF_LOSING              1
#define CONTEXT_PRESENCE_TF_CTF_TIED                2
#define CONTEXT_PRESENCE_TF_CTF_WINNING             3
#define CONTEXT_PRESENCE_APPCHOOSER                 4
#define CONTEXT_PRESENCE_MENU                       5
#define CONTEXT_PRESENCE_EP1_INGAME                 6
#define CONTEXT_PRESENCE_HL2_INGAME                 7
#define CONTEXT_PRESENCE_EP2_INGAME                 8
#define CONTEXT_PRESENCE_PORTAL_INGAME              9
#define CONTEXT_PRESENCE_COMMENTARY                 10
#define CONTEXT_PRESENCE_IDLE                       11

// Values for X_CONTEXT_GAME_MODE

#define CONTEXT_GAME_MODE_MULTIPLAYER               0
#define CONTEXT_GAME_MODE_SINGLEPLAYER              1

//
// Property ids
//
// These values are passed as the dwPropertyId value to XUserSetProperty
// and as the dwPropertyId value in the XUSER_PROPERTY structure.
//

#define PROPERTY_CAPS_OWNED                         0x10000000
#define PROPERTY_CAPS_TOTAL                         0x10000001
#define PROPERTY_PLAYER_TEAM_SCORE                  0x10000002
#define PROPERTY_OPPONENT_TEAM_SCORE                0x10000003
#define PROPERTY_FLAG_CAPTURE_LIMIT                 0x1000000B
#define PROPERTY_NUMBER_OF_ROUNDS                   0x1000000C
#define PROPERTY_GAME_SIZE                          0x1000000D
#define PROPERTY_AUTOBALANCE                        0x1000000E
#define PROPERTY_PRIVATE_SLOTS                      0x1000000F
#define PROPERTY_MAX_GAME_TIME                      0x10000010
#define PROPERTY_NUMBER_OF_KILLS                    0x10000011
#define PROPERTY_DAMAGE_DEALT                       0x10000012
#define PROPERTY_PLAY_TIME                          0x10000013
#define PROPERTY_POINT_CAPTURES                     0x10000014
#define PROPERTY_POINT_DEFENSES                     0x10000015
#define PROPERTY_DOMINATIONS                        0x10000016
#define PROPERTY_REVENGE                            0x10000017
#define PROPERTY_BUILDINGS_DESTROYED                0x10000019
#define PROPERTY_HEADSHOTS                          0x1000001A
#define PROPERTY_HEALTH_POINTS_HEALED               0x1000001B
#define PROPERTY_INVULNS                            0x1000001C
#define PROPERTY_KILL_ASSISTS                       0x1000001D
#define PROPERTY_BACKSTABS                          0x1000001E
#define PROPERTY_HEALTH_POINTS_LEACHED              0x1000001F
#define PROPERTY_BUILDINGS_BUILT                    0x10000020
#define PROPERTY_SENTRY_KILLS                       0x10000021
#define PROPERTY_TELEPORTS                          0x10000022
#define PROPERTY_KILLS                              0x10000023
#define PROPERTY_NUMBER_OF_TEAMS                    0x10000025
#define PROPERTY_TEAM_RED                           0x10000026
#define PROPERTY_TEAM_BLUE                          0x10000027
#define PROPERTY_TEAM_SPECTATOR                     0x10000028
#define PROPERTY_TEAM                               0x10000029
#define PROPERTY_WIN_LIMIT                          0x1000002A
#define PROPERTY_RANKING_TEST                       0x2000000A
#define PROPERTY_POINTS_SCORED                      0x20000018

//
// Achievement ids
//
// These values are used in the dwAchievementId member of the
// XUSER_ACHIEVEMENT structure that is used with
// XUserWriteAchievements and XUserCreateAchievementEnumerator.
//

#define ACHIEVEMENT_HLX_KILL_ENEMIES_WITHPHYSICS    43
#define ACHIEVEMENT_HLX_KILL_ENEMY_WITHHOPPERMINE   44
#define ACHIEVEMENT_HLX_KILL_ENEMIES_WITHMANHACK    45
#define ACHIEVEMENT_HLX_KILL_SOLDIER_WITHHISGRENADE 46
#define ACHIEVEMENT_HLX_KILL_ENEMIES_WITHONEENERGYBALL 47
#define ACHIEVEMENT_HLX_KILL_ELITESOLDIER_WITHHISENERGYBALL 48
#define ACHIEVEMENT_EPX_GET_ZOMBINEGRENADE          50
#define ACHIEVEMENT_EPX_KILL_ZOMBIES_WITHFLARES     51
#define ACHIEVEMENT_HL2_HIT_CANCOP_WITHCAN          52
#define ACHIEVEMENT_HL2_PUT_CANINTRASH              53
#define ACHIEVEMENT_HL2_ESCAPE_APARTMENTRAID        54
#define ACHIEVEMENT_HL2_BREAK_MINITELEPORTER        55
#define ACHIEVEMENT_HL2_GET_CROWBAR                 56
#define ACHIEVEMENT_HL2_KILL_BARNACLESWITHBARREL    57
#define ACHIEVEMENT_HL2_GET_AIRBOAT                 58
#define ACHIEVEMENT_HL2_GET_AIRBOATGUN              60
#define ACHIEVEMENT_HL2_FIND_VORTIGAUNTCAVE         61
#define ACHIEVEMENT_HL2_KILL_CHOPPER                62
#define ACHIEVEMENT_HL2_FIND_HEVFACEPLATE           63
#define ACHIEVEMENT_HL2_GET_GRAVITYGUN              64
#define ACHIEVEMENT_HL2_MAKEABASKET                 65
#define ACHIEVEMENT_HL2_BEAT_RAVENHOLM_NOWEAPONS    66
#define ACHIEVEMENT_HL2_BEAT_CEMETERY               67
#define ACHIEVEMENT_HL2_KILL_ENEMIES_WITHCRANE      68
#define ACHIEVEMENT_HL2_PIN_SOLDIER_TOBILLBOARD     69
#define ACHIEVEMENT_HL2_KILL_ODESSAGUNSHIP          70
#define ACHIEVEMENT_HL2_KILL_THREEGUNSHIPS          71
#define ACHIEVEMENT_HL2_BEAT_DONTTOUCHSAND          72
#define ACHIEVEMENT_HL2_KILL_ENEMIES_WITHANTLIONS   74
#define ACHIEVEMENT_HL2_KILL_ENEMY_WITHTOILET       75
#define ACHIEVEMENT_HL2_BEAT_TURRETSTANDOFF2        76
#define ACHIEVEMENT_HL2_BEAT_TOXICTUNNEL            78
#define ACHIEVEMENT_HL2_BEAT_PLAZASTANDOFF          79
#define ACHIEVEMENT_HL2_KILL_ALLC1709SNIPERS        80
#define ACHIEVEMENT_HL2_BEAT_SUPRESSIONDEVICE       81
#define ACHIEVEMENT_HL2_BEAT_C1713STRIDERSTANDOFF   82
#define ACHIEVEMENT_HL2_BEAT_GAME                   84
#define ACHIEVEMENT_HL2_FIND_ALLLAMBDAS             86
#define ACHIEVEMENT_EP1_BEAT_MAINELEVATOR           87
#define ACHIEVEMENT_EP1_BEAT_CITADELCORE            88
#define ACHIEVEMENT_EP1_BEAT_CITADELCORE_NOSTALKERKILLS 89
#define ACHIEVEMENT_EP1_KILL_ANTLIONS_WITHCARS      90
#define ACHIEVEMENT_EP1_BEAT_GARAGEELEVATORSTANDOFF 91
#define ACHIEVEMENT_EP1_KILL_ENEMIES_WITHSNIPERALYX 92
#define ACHIEVEMENT_EP1_BEAT_HOSPITALATTICGUNSHIP   93
#define ACHIEVEMENT_EP1_BEAT_CITIZENESCORT_NOCITIZENDEATHS 94
#define ACHIEVEMENT_EP1_BEAT_GAME                   95
#define ACHIEVEMENT_EP1_BEAT_GAME_ONEBULLET         96
#define ACHIEVEMENT_EP2_KILL_POISONANTLION          97
#define ACHIEVEMENT_EP2_KILL_ALLGRUBS               98
#define ACHIEVEMENT_EP2_BREAK_ALLWEBS               99
#define ACHIEVEMENT_EP2_BEAT_ANTLIONINVASION        100
#define ACHIEVEMENT_EP2_BEAT_ANTLIONGUARDS          101
#define ACHIEVEMENT_EP2_KILL_ENEMIES_WITHCAR        102
#define ACHIEVEMENT_EP2_BEAT_HUNTERAMBUSH           103
#define ACHIEVEMENT_EP2_KILL_CHOPPER_NOMISSES       104
#define ACHIEVEMENT_EP2_KILL_COMBINECANNON          105
#define ACHIEVEMENT_EP2_FIND_ALLRADARCACHES         106
#define ACHIEVEMENT_EP2_BEAT_ROCKETCACHEPUZZLE      107
#define ACHIEVEMENT_EP2_BEAT_RACEWITHDOG            108
#define ACHIEVEMENT_EP2_BEAT_WHITEFORESTINN         109
#define ACHIEVEMENT_EP2_PUT_ITEMINROCKET            110
#define ACHIEVEMENT_EP2_BEAT_MISSILESILO2           111
#define ACHIEVEMENT_EP2_BEAT_OUTLAND12_NOBUILDINGSDESTROYED 112
#define ACHIEVEMENT_EP2_BEAT_GAME                   113
#define ACHIEVEMENT_EP2_KILL_HUNTER_WITHFLECHETTES  114
#define ACHIEVEMENT_PORTAL_GET_PORTALGUNS           115
#define ACHIEVEMENT_PORTAL_KILL_COMPANIONCUBE       116
#define ACHIEVEMENT_PORTAL_ESCAPE_TESTCHAMBERS      117
#define ACHIEVEMENT_PORTAL_BEAT_GAME                118
#define ACHIEVEMENT_PORTAL_INFINITEFALL             119
#define ACHIEVEMENT_PORTAL_LONGJUMP                 120
#define ACHIEVEMENT_PORTAL_BEAT_2ADVANCEDMAPS       121
#define ACHIEVEMENT_PORTAL_BEAT_4ADVANCEDMAPS       122
#define ACHIEVEMENT_PORTAL_BEAT_6ADVANCEDMAPS       123
#define ACHIEVEMENT_PORTAL_GET_ALLBRONZE            124
#define ACHIEVEMENT_PORTAL_GET_ALLSILVER            125
#define ACHIEVEMENT_PORTAL_GET_ALLGOLD              126
#define ACHIEVEMENT_TF_GET_TURRETKILLS              127
#define ACHIEVEMENT_TF_KILL_NEMESIS                 128
#define ACHIEVEMENT_TF_GET_CONSECUTIVEKILLS_NODEATHS 129
#define ACHIEVEMENT_TF_GET_HEALED_BYENEMY           130
#define ACHIEVEMENT_TF_PLAY_GAME_FRIENDSONLY        131
#define ACHIEVEMENT_TF_WIN_MULTIPLEGAMES            132
#define ACHIEVEMENT_TF_GET_MULTIPLEKILLS            133
#define ACHIEVEMENT_TF_WIN_2FORT_NOENEMYCAPS        134
#define ACHIEVEMENT_TF_WIN_WELL_MINIMUMTIME         135
#define ACHIEVEMENT_TF_WIN_HYDRO_NOENEMYCAPS        136
#define ACHIEVEMENT_TF_WIN_DUSTBOWL_NOENEMYCAPS     137
#define ACHIEVEMENT_TF_WIN_GRAVELPIT_NOENEMYCAPS    138
#define ACHIEVEMENT_TF_PLAY_GAME_EVERYCLASS         139
#define ACHIEVEMENT_TF_PLAY_GAME_EVERYMAP           140
#define ACHIEVEMENT_TF_GET_HEALPOINTS               141
#define ACHIEVEMENT_TF_BURN_PLAYERSINMINIMIMTIME    142
#define ACHIEVEMENT_HL2_DISINTEGRATE_SOLDIERSINFIELD 143
#define ACHIEVEMENT_HL2_FOLLOW_FREEMAN              144
#define ACHIEVEMENT_TF_GET_HEADSHOTS                145
#define ACHIEVEMENT_PORTAL_DETACH_ALL_CAMERAS       146
#define ACHIEVEMENT_PORTAL_HIT_TURRET_WITH_TURRET   148

#ifndef _XBOX
#define ACHIEVEMENT_PORTAL_TRANSMISSION_RECEIVED	149
#define ACHIEVEMENT_TF_GENERAL_KILL_ENEMIES_AFTER_TELEPORTING	150
#endif // _XBOX

#define ACHIEVEMENT_TF_LAST_ORANGEBOX				150

//TE120--
//
// TE120 Achievement ids
//
#define ACHIEVEMENT_E120_REUNITED	0
#define ACHIEVEMENT_E120_MY_FIRST_GRAVITY_JUMP 1
#define ACHIEVEMENT_E120_CATCH_EM_ALL 2
#define ACHIEVEMENT_E120_SCHOLAR 3
#define ACHIEVEMENT_E120_METROIDVANIA 4
#define ACHIEVEMENT_E120_SLICER 5
#define ACHIEVEMENT_E120_CHAPTER_1 6
#define ACHIEVEMENT_E120_CHAPTER_2 7
#define ACHIEVEMENT_E120_CHAPTER_3 8
#define ACHIEVEMENT_E120_CHAPTER_4 9
#define ACHIEVEMENT_E120_STRIDER_SMASHER 10
//TE120--

//
// Stats view ids
//
// These are used in the dwViewId member of the XUSER_STATS_SPEC structure
// passed to the XUserReadStats* and XUserCreateStatsEnumerator* functions.
//

// Skill leaderboards for ranked game modes

#define STATS_VIEW_SKILL_RANKED_MULTIPLAYER         0xFFFF0000
#define STATS_VIEW_SKILL_RANKED_SINGLEPLAYER        0xFFFF0001

// Skill leaderboards for unranked (standard) game modes

#define STATS_VIEW_SKILL_STANDARD_MULTIPLAYER       0xFFFE0000
#define STATS_VIEW_SKILL_STANDARD_SINGLEPLAYER      0xFFFE0001

// Title defined leaderboards

#define STATS_VIEW_PLAYER_MAX_UNRANKED              1
#define STATS_VIEW_PLAYER_MAX_RANKED                2

//
// Stats view column ids
//
// These ids are used to read columns of stats views.  They are specified in
// the rgwColumnIds array of the XUSER_STATS_SPEC structure.  Rank, rating
// and gamertag are not retrieved as custom columns and so are not included
// in the following definitions.  They can be retrieved from each row's
// header (e.g., pStatsResults->pViews[x].pRows[y].dwRank, etc.).
//

// Column ids for PLAYER_MAX_UNRANKED

#define STATS_COLUMN_PLAYER_MAX_UNRANKED_POINTS_SCORED 2
#define STATS_COLUMN_PLAYER_MAX_UNRANKED_KILLS      3
#define STATS_COLUMN_PLAYER_MAX_UNRANKED_POINTS_CAPPED 1
#define STATS_COLUMN_PLAYER_MAX_UNRANKED_DAMAGE_DEALT 4
#define STATS_COLUMN_PLAYER_MAX_UNRANKED_PLAY_TIME  5
#define STATS_COLUMN_PLAYER_MAX_UNRANKED_POINT_DEFENSES 6
#define STATS_COLUMN_PLAYER_MAX_UNRANKED_DOMINATIONS 7
#define STATS_COLUMN_PLAYER_MAX_UNRANKED_REVENGE    8
#define STATS_COLUMN_PLAYER_MAX_UNRANKED_BUILDINGS_DESTROYED 9
#define STATS_COLUMN_PLAYER_MAX_UNRANKED_HEADSHOTS  10
#define STATS_COLUMN_PLAYER_MAX_UNRANKED_HEALTH_POINTS_HEALED 11
#define STATS_COLUMN_PLAYER_MAX_UNRANKED_INVULNS    12
#define STATS_COLUMN_PLAYER_MAX_UNRANKED_KILL_ASSISTS 13
#define STATS_COLUMN_PLAYER_MAX_UNRANKED_BACKSTABS  14
#define STATS_COLUMN_PLAYER_MAX_UNRANKED_HEALTH_POINTS_LEACHED 15
#define STATS_COLUMN_PLAYER_MAX_UNRANKED_BUILDINGS_BUILT 16
#define STATS_COLUMN_PLAYER_MAX_UNRANKED_SENTRY_KILLS 17
#define STATS_COLUMN_PLAYER_MAX_UNRANKED_TELEPORTS  18

// Column ids for PLAYER_MAX_RANKED

#define STATS_COLUMN_PLAYER_MAX_RANKED_POINTS_SCORED 2

//
// Matchmaking queries
//
// These values are passed as the dwProcedureIndex parameter to
// XSessionSearch to indicate which matchmaking query to run.
//

#define SESSION_MATCH_QUERY_PLAYER_MATCH            0

//
// Gamer pictures
//
// These ids are passed as the dwPictureId parameter to XUserAwardGamerTile.
//



#ifdef __cplusplus
}
#endif

#endif // __THE_ORANGE_BOX_SPA_H__


