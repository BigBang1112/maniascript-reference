class Void {};
class Integer{};
class Real{};
class Boolean{};
class Text{};
class Vec2{};
class Vec3{};
class Int3{};
class Ident{};

/*!
Supported declare modes : Local  Persistent 
This is the base Manialink page interface.
*/
struct CMlScript : public CNod {
	enum LinkType {
		ExternalBrowser,
		ManialinkBrowser,
		Goto,
		ExternalFromId,
		ManialinkFromId,
		GotoFromId,
	};
/*!

*/
	const	CMlPage Page;
/*!

*/
	const	Boolean PageIsVisible;
/*!

*/
	const	Integer Now;
/*!

*/
	const	Integer Period;
/*!

*/
	const	Integer CurrentTime;
/*!

*/
	const	Text CurrentTimeText;
/*!

*/
	const	Text CurrentLocalDateText;
/*!
Local user structure.
*/
	const	CUser LocalUser;
/*!

*/
	const	CTitle LoadedTitle;
/*!

*/
	const	CMlEvent[] PendingEvents;
/*!

*/
	const	Real MouseX;
/*!

*/
	const	Real MouseY;
/*!

*/
	const	Boolean MouseLeftButton;
/*!

*/
	const	Boolean MouseRightButton;
/*!

*/
	const	Boolean MouseMiddleButton;
/*!

*/
	const	Boolean KeyUp;
/*!

*/
	const	Boolean KeyDown;
/*!

*/
	const	Boolean KeyLeft;
/*!

*/
	const	Boolean KeyRight;
/*!

*/
	const	Boolean KeyReturn;
/*!

*/
	const	Boolean KeySpace;
/*!

*/
	const	Boolean KeyDelete;
/*!

*/
			Boolean IsKeyPressed(Integer KeyCode);
/*!

*/
			Boolean EnableMenuNavigationInputs;
/*!

*/
			Void EnableMenuNavigation(Boolean EnableInputs,Boolean WithAutoFocus,CMlControl AutoBackControl,Integer InputPriority);
/*!

*/
	const	Boolean IsMenuNavigationForeground;
/*!

*/
			Void OpenLink(Text Url,LinkType LinkType);
/*!

*/
			Void TriggerPageAction(Text ActionString);
/*!

*/
	const	CXmlManager Xml;
/*!

*/
	const	CHttpManager Http;
/*!

*/
	const	CAudioManager Audio;
/*!
Send a custom event to the ManiaApp owning the layer, no-op otherwise.
*/
			Void SendCustomEvent(Text Type,Text[] Data);
/*!

*/
			Void PreloadImage(Text ImageUrl);
};

/*!
Supported declare modes : Local 
Manialink control.
*/
struct CMlEntry : public CMlControl {
/*!

*/
			Text Value;
/*!

*/
			Void StartEdition();
/*!

*/
			Integer MaxLine;
/*!

*/
			Boolean AutoNewLine;
};

/*!
Supported declare modes : Local 
Manialink control.
*/
struct CMlFileEntry : public CMlEntry {
/*!

*/
	const	Text FullFileName;
};

/*!
Supported declare modes : Local 
Manialink control.
*/
struct CMlLabel : public CMlControl {
/*!

*/
			Text Style;
/*!

*/
			Text Substyle;
/*!

*/
			Text TextFont;
/*!

*/
			Void SetText(Text NewText);
/*!

*/
			Text Value;
/*!

*/
	const	Integer ValueLineCount;
/*!

*/
			Integer MaxLine;
/*!

*/
			Boolean AppendEllipsis;
/*!

*/
			Boolean AutoNewLine;
/*!

*/
			Real Opacity;
/*!

*/
			Vec3 TextColor;
/*!

*/
			Integer TextSize;
/*!

*/
			Real ComputeWidth(Text Text);
};

/*!
Supported declare modes : Local 
Manialink control.
*/
struct CMlMediaPlayer : public CMlControl {
};

/*!
Supported declare modes : Local 
Manialink control.
*/
struct CMlQuad : public CMlControl {
	enum EKeepRatioMode {
		Inactive,
		Clip,
		Fit,
	};
/*!

*/
			Void ChangeImageUrl(Text fieldName);
/*!

*/
			Text ImageUrl;
/*!

*/
			Text ImageUrlFocus;
/*!

*/
			Text Style;
/*!

*/
			Text Substyle;
/*!

*/
			Boolean StyleSelected;
/*!

*/
	const	Boolean DownloadInProgress;
/*!

*/
			Vec3 Colorize;
/*!

*/
			Vec3 ModulateColor;
/*!

*/
			Vec3 BgColor;
/*!

*/
			Vec3 BgColorFocus;
/*!

*/
			Real Opacity;
/*!

*/
			EKeepRatioMode KeepRatio;
};

/*!
Supported declare modes : Local 
Manialink control.
*/
struct CMlGauge : public CMlControl {
/*!

*/
			Text Style;
/*!

*/
			Void SetRatio(Real NewRatio);
/*!

*/
			Void SetClan(Integer NewClan);
/*!
Values in range (0.000000-1.000000)
*/
			Real Ratio;
/*!
Values in range (0.000000-1.000000)
*/
			Real GradingRatio;
/*!

*/
			Integer Clan;
/*!

*/
			Vec3 Color;
/*!

*/
			Boolean DrawBackground;
/*!

*/
			Boolean DrawBlockBackground;
/*!

*/
			Boolean CenteredBar;
};

/*!
Supported declare modes : Local 
Manialink control.
*/
struct CMlGraph : public CMlControl {
/*!

*/
			Vec2 CoordsMin;
/*!

*/
			Vec2 CoordsMax;
/*!

*/
			CMlGraphCurve AddCurve();
/*!

*/
			Void RemoveCurve(CMlGraphCurve Curve);
/*!

*/
			CMlGraphCurve[] Curves;
};

/*!
Supported declare modes : Local 
Manialink control.
*/
struct CMlMinimap : public CMlControl {
/*!

*/
			Vec3 WorldPosition;
/*!

*/
			Vec2 MapPosition;
/*!

*/
			Real MapYaw;
/*!
Values in range (0.500000-10.000000)
*/
			Real ZoomFactor;
};

/*!
Supported declare modes : Local 
Manialink control.
*/
struct CMlCamera : public CMlControl {
};

/*!
Supported declare modes : Local  Persistent 
This is the Manialink browser interface.
*/
struct CMlBrowser : public CMlScript {
	enum EBuddyAction {
		Add,
		Invite,
		Remove,
	};
	enum EBuddyResult {
		Ok,
		Error,
		NotFinished,
	};
/*!

*/
	const	CMap CurMap;
/*!

*/
			Void ShowCurMapCard();
/*!

*/
	const	EBuddyResult BuddyDoResult;
/*!

*/
	const	Text BuddyDoErrorMessage;
/*!

*/
	const	Boolean IsInBrowser;
/*!

*/
			Void BrowserBack();
/*!

*/
			Void BrowserQuit();
/*!

*/
			Void BrowserHome();
/*!

*/
			Void BrowserReload();
/*!

*/
			Text BrowserFocusedFrameId;
/*!

*/
			Void SetLocalUserClubLink(Text ClubLink);
};

/*!
Supported declare modes : Local  Persistent 

*/
struct CManiaApp : public CNod {
	enum ELinkType {
		ExternalBrowser,
		ManialinkBrowser,
	};
/*!

*/
	const	Integer Now;
/*!

*/
	const	Boolean IsVisible;
/*!

*/
	const	CUser LocalUser;
/*!

*/
	const	CTitle LoadedTitle;
/*!

*/
			Boolean EnableMenuNavigationInputs;
/*!

*/
	const	Real MouseX;
/*!

*/
	const	Real MouseY;
/*!

*/
	const	CUILayer[] UILayers;
/*!

*/
			CUILayer UILayerCreate();
/*!

*/
			Void UILayerDestroy(CUILayer Layer);
/*!

*/
			Void UILayerDestroyAll();
/*!

*/
			Void LayerCustomEvent(CUILayer Layer,Text Type,Text[] Data);
/*!

*/
			Void OpenLink(Text Url,ELinkType LinkType);
/*!

*/
	const	CXmlManager Xml;
/*!

*/
	const	CHttpManager Http;
/*!

*/
	const	CAudioManager Audio;
};

/*!

*/
struct CManiaAppEvent : public CNod {
	enum EType {
		LayerCustomEvent,
		KeyPress,
		ExternalCustomEvent,
		MenuNavigation,
	};
	enum EMenuNavAction {
		Up,
		Right,
		Left,
		Down,
		Select,
		Cancel,
		PageUp,
		PageDown,
	};
/*!

*/
	const	EType Type;
/*!

*/
	const	CUILayer CustomEventLayer;
/*!

*/
	const	Text CustomEventType;
/*!

*/
	const	Text[] CustomEventData;
/*!

*/
	const	Text ExternalEventType;
/*!

*/
	const	Text[] ExternalEventData;
/*!

*/
	const	EMenuNavAction MenuNavAction;
/*!

*/
	const	Integer KeyCode;
/*!

*/
	const	Text KeyName;
};

/*!
Supported declare modes : Local  Persistent 

*/
struct CManiaAppTitle : public CManiaApp {
/*!

*/
	const	CManiaAppEvent[] PendingEvents;
/*!

*/
			Void Menu_Quit();
/*!

*/
			Void Menu_Home();
/*!

*/
			Void Menu_Solo();
/*!

*/
			Void Menu_Competitions();
/*!

*/
			Void Menu_Local();
/*!

*/
			Void Menu_Internet();
/*!

*/
			Void Menu_Editor();
/*!

*/
			Void Menu_Profile();
/*!

*/
			Void PlayMap(Text Map);
/*!

*/
			Boolean LoadingScreenRequireKeyPressed;
/*!

*/
			Boolean DontScaleMainMenuForHMD;
};

/*!

*/
struct CStation : public CNod {
/*!

*/
	const	CTitle Title;
/*!

*/
	const	Integer AudienceRegisteredUsers;
/*!

*/
	const	Integer CampaignMedalsMax;
/*!

*/
	const	Integer CampaignMedalsCurrent;
/*!

*/
	const	Integer CampaignMedalsRanking;
/*!

*/
	const	Real LadderPoints;
/*!

*/
	const	Integer LadderRank;
};

/*!
Supported declare modes : Local  Persistent 
This is the Manialink browser interface.
*/
struct CMlStation : public CMlBrowser {
/*!

*/
	const	CStation Station;
/*!

*/
			Void EnterStation();
};

/*!
Supported declare modes : Local  Persistent 

*/
struct CEditorPlugin : public CManiaApp {
	enum CardinalDirections {
		North,
		East,
		South,
		West,
	};
	enum PlaceMode {
		Unknown,
		Terraform,
		Block,
		Macroblock,
		Skin,
		CopyPaste,
		Test,
		Plugin,
		CustomSelection,
		OffZone,
		BlockProperty,
		Path,
		GhostBlock,
	};
	enum EditMode {
		Unknown,
		Place,
		FreeLook,
		Erase,
		Pick,
		SelectionAdd,
		SelectionRemove,
	};
/*!

*/
	const	CEditorPluginEvent[] PendingEvents;
/*!

*/
	const	CMap Map;
/*!

*/
	const	Text MapName;
/*!

*/
			Void ComputeShadows();
/*!

*/
			Void Undo();
/*!

*/
			Void Redo();
/*!

*/
			Void Quit();
/*!

*/
			Void Help();
/*!

*/
			Void Validate();
/*!

*/
			Void AutoSave();
/*!

*/
			Void SaveMap(Text FileName,Text Path);
/*!

*/
			PlaceMode PlaceMode;
/*!

*/
			EditMode EditMode;
/*!

*/
			Boolean UndergroundMode;
/*!

*/
			Boolean BlockStockMode;
/*!

*/
			Int3 CursorCoord;
/*!

*/
			CardinalDirections CursorDir;
/*!

*/
			CBlockModel CursorBlockModel;
/*!

*/
			CBlockModel CursorTerrainBlockModel;
/*!

*/
			CMacroblockModel CursorMacroblockModel;
/*!

*/
			Real CameraVAngle;
/*!

*/
			Real CameraHAngle;
/*!

*/
			Real CameraToTargetDistance;
/*!

*/
			Vec3 TargetedPosition;
/*!

*/
			Boolean EnableAirMapping;
/*!

*/
			Boolean EnableMixMapping;
/*!

*/
			Void RemoveAllBlocks();
/*!

*/
			Void RemoveAllTerrain();
/*!

*/
			Void RemoveAllOffZone();
/*!

*/
			Void RemoveAllObjects();
/*!

*/
			Void RemoveAll();
/*!

*/
			Void RemoveAllBlocksAndTerrain();
/*!

*/
			Void ShowCustomSelection();
/*!

*/
			Void HideCustomSelection();
/*!

*/
			Void CopyPaste_Copy();
/*!

*/
			Void CopyPaste_Cut();
/*!

*/
			Void CopyPaste_Remove();
/*!

*/
			Void CopyPaste_SelectAll();
/*!

*/
			Void CopyPaste_ResetSelection();
/*!

*/
			Void OpenToolsMenu();
/*!

*/
			Void EditMediatrackIngame();
/*!

*/
			Boolean CanPlaceBlock(CBlockModel BlockModel,Int3 Coord,CardinalDirections Dir,Boolean OnGround,Integer VariantIndex);
/*!

*/
			Boolean PlaceBlock(CBlockModel BlockModel,Int3 Coord,CardinalDirections Dir);
/*!

*/
			Boolean CanPlaceBlock_NoDestruction(CBlockModel BlockModel,Int3 Coord,CardinalDirections Dir,Boolean OnGround,Integer VariantIndex);
/*!

*/
			Boolean PlaceBlock_NoDestruction(CBlockModel BlockModel,Int3 Coord,CardinalDirections Dir);
/*!

*/
			Boolean CanPlaceRoadBlocks(CBlockModel BlockModel,Int3 StartCoord,Int3 EndCoord);
/*!

*/
			Boolean PlaceRoadBlocks(CBlockModel BlockModel,Int3 StartCoord,Int3 EndCoord);
/*!

*/
			Boolean CanPlaceTerrainBlocks(CBlockModel BlockModel,Int3 StartCoord,Int3 EndCoord);
/*!

*/
			Boolean PlaceTerrainBlocks(CBlockModel BlockModel,Int3 StartCoord,Int3 EndCoord);
/*!

*/
			Boolean PlaceTerrainBlocks_NoDestruction(CBlockModel BlockModel,Int3 StartCoord,Int3 EndCoord);
/*!

*/
			Boolean CanPlaceMacroblock(CMacroblockModel BlockModel,Int3 Coord,CardinalDirections Dir);
/*!

*/
			Boolean PlaceMacroblock(CMacroblockModel BlockModel,Int3 Coord,CardinalDirections Dir);
/*!

*/
			Boolean CanPlaceMacroblock_NoDestruction(CMacroblockModel BlockModel,Int3 Coord,CardinalDirections Dir);
/*!

*/
			Boolean PlaceMacroblock_NoDestruction(CMacroblockModel BlockModel,Int3 Coord,CardinalDirections Dir);
/*!

*/
			CBlock GetBlock(Int3 Coord);
/*!

*/
			Boolean RemoveBlock(Int3 Coord);
/*!

*/
			Boolean RemoveTerrainBlocks(Int3 StartCoord,Int3 EndCoord);
/*!

*/
			Integer GetBlockGroundHeight(CBlockModel BlockModel,Integer CoordX,Integer CoordZ,CardinalDirections Dir);
/*!

*/
			CBlock GetStartLineBlock();
/*!

*/
			Void CopyPaste_AddOrSubSelection(Int3 StartCoord,Int3 EndCoord);
/*!

*/
			Boolean CopyPaste_Symmetrize();
/*!

*/
			Void SaveMacroblock(CMacroblockModel MacroblockModel);
/*!

*/
			Integer GetInterfaceNumber(CCollector Collector);
/*!

*/
			Void SetInterfaceNumber(CCollector Collector,Integer NewValue);
/*!

*/
			CMacroblockModel GetMacroblockModelFromName(Text MacroblockModelName);
/*!

*/
			CBlockModel GetTerrainBlockModelFromName(Text TerrainBlockModelName);
/*!

*/
			CBlockModel GetBlockModelFromName(Text BlockModelName);
/*!

*/
	const	CItemAnchor[] Items;
/*!

*/
	const	Text[] MediatrackIngameClips;
/*!

*/
	const	Text[] MediatrackIngameIsScriptClips;
/*!

*/
			Integer MediatrackIngameEditedClipIndex;
/*!

*/
	const	CBlock[] Blocks;
/*!

*/
	const	CBlockModel[] BlockModels;
/*!

*/
	const	CBlockModel[] TerrainBlockModels;
/*!

*/
	const	CMacroblockModel[] MacroblockModels;
/*!

*/
	const	CAnchorData[] AnchorData;
/*!

*/
			Int3[] CustomSelectionCoords;
/*!

*/
			Vec3 CustomSelectionRGB;
/*!

*/
			Boolean EnableEditorInputsCustomProcessing;
/*!

*/
	const	Boolean EditorInputIsDown_Menu;
/*!

*/
	const	Boolean EditorInputIsDown_SwitchToRace;
/*!

*/
	const	Boolean EditorInputIsDown_CursorUp;
/*!

*/
	const	Boolean EditorInputIsDown_CursorRight;
/*!

*/
	const	Boolean EditorInputIsDown_CursorDown;
/*!

*/
	const	Boolean EditorInputIsDown_CursorLeft;
/*!

*/
	const	Boolean EditorInputIsDown_CursorRaise;
/*!

*/
	const	Boolean EditorInputIsDown_CursorLower;
/*!

*/
	const	Boolean EditorInputIsDown_CursorTurn;
/*!

*/
	const	Boolean EditorInputIsDown_CursorPick;
/*!

*/
	const	Boolean EditorInputIsDown_CursorPlace;
/*!

*/
	const	Boolean EditorInputIsDown_CursorDelete;
/*!

*/
	const	Boolean EditorInputIsDown_CameraUp;
/*!

*/
	const	Boolean EditorInputIsDown_CameraRight;
/*!

*/
	const	Boolean EditorInputIsDown_CameraDown;
/*!

*/
	const	Boolean EditorInputIsDown_CameraLeft;
/*!

*/
	const	Boolean EditorInputIsDown_IconUp;
/*!

*/
	const	Boolean EditorInputIsDown_IconRight;
/*!

*/
	const	Boolean EditorInputIsDown_IconDown;
/*!

*/
	const	Boolean EditorInputIsDown_IconLeft;
/*!

*/
	const	Real CollectionSquareSize;
/*!

*/
	const	Real CollectionSquareHeight;
/*!

*/
	const	Integer CollectionGroundY;
/*!

*/
			Text ManialinkText;
/*!

*/
	const	CMlPage ManialinkPage;
};

/*!
Supported declare modes : Local  Persistent 
Rules API for ShootMania gamemodes.
*/
struct CSmMode : public CMode {
	enum EWeapon {
		Laser,
		Rocket,
		Nucleus,
		Arrow,
	};
	enum EActionSlot {
		Slot_A,
		Slot_B,
		Slot_C,
		Slot_D,
		Slot_E,
		Slot_F,
		Slot_G,
		Slot_H,
	};
	enum EActionInput {
		Weapon,
		Movement,
		Activable1,
		Activable2,
		Activable3,
		Activable4,
		Consumable1,
		Consumable2,
		None,
	};
	enum EGameplay {
		Default,
		Mp3Beta0,
	};
/*!

*/
			Integer StartTime;
/*!

*/
			Integer EndTime;
/*!

*/
			Integer SpawnInvulnerabilityDuration;
/*!

*/
			Boolean UseClans;
/*!

*/
			Boolean UseForcedClans;
/*!

*/
			Boolean UsePvPCollisions;
/*!

*/
			Boolean UsePvPWeapons;
/*!

*/
			Boolean UseInterractiveScreensIn3d;
/*!

*/
			Boolean UseLaserVsBullets;
/*!

*/
			Boolean UseLaserSkewering;
/*!

*/
			Boolean UsePlayerTagging;
/*!

*/
			Boolean UseBeaconsWithRecipients;
/*!

*/
			Boolean UseAmmoBonusOnHit;
/*!

*/
			Boolean UseSameWallJump;
/*!

*/
			Boolean UseDefaultActionEvents;
/*!

*/
			Boolean UseAllies;
/*!

*/
			Boolean UseAutoSpawnBots;
/*!

*/
			Boolean ForceNavMapsComputation;
/*!

*/
			Integer GameplayVersion;
/*!

*/
			EGameplay Gameplay;
/*!

*/
			Boolean UseProtectClanmates;
/*!

*/
			Real OffZoneRadius;
/*!

*/
			Real OffZoneRadiusSpeed;
/*!

*/
			Ident OffZoneCenterLandmarkId;
/*!

*/
	const	Integer PlayersNbTotal;
/*!

*/
	const	Integer PlayersNbAlive;
/*!

*/
	const	Integer PlayersNbDead;
/*!

*/
	const	Integer ClansNbTotal;
/*!

*/
	const	Integer ClansNbAlive;
/*!

*/
	const	Integer ClansNbDead;
/*!

*/
	const	Integer[] ClansNbPlayers;
/*!

*/
	const	Integer[] ClansNbPlayersAlive;
/*!

*/
	const	CSmPlayer[] Players;
/*!

*/
	const	CSmPlayer[] BotPlayers;
/*!

*/
	const	CSmPlayer[] Spectators;
/*!

*/
	const	CSmPlayer[] AllPlayers;
/*!

*/
	const	CSmModeEvent[] PendingEvents;
/*!

*/
	const	CSmMapBase[] MapBases;
/*!

*/
	const	CSmMapLandmark[] MapLandmarks;
/*!

*/
	const	CSmMapLandmark[] MapLandmarks_PlayerSpawn;
/*!

*/
	const	CSmMapLandmark[] MapLandmarks_Gauge;
/*!

*/
	const	CSmMapLandmark[] MapLandmarks_Sector;
/*!

*/
	const	CSmMapLandmark[] MapLandmarks_BotPath;
/*!

*/
	const	CSmMapLandmark[] MapLandmarks_ObjectAnchor;
/*!

*/
	const	CSmMapLandmark[] MapLandmarks_Gate;
/*!

*/
	const	CSmScore[] Scores;
/*!

*/
			Integer[] ClanScores;
/*!

*/
			Void PassOn(CSmModeEvent Event);
/*!

*/
			Void Discard(CSmModeEvent Event);
/*!

*/
			Void SpawnPlayer(CSmPlayer Player,Integer ClanNum,Integer Armor,CSmMapPlayerSpawn PlayerSpawn,Integer ActivationDate);
/*!

*/
			Void SpawnBotPlayer(CSmPlayer Player,Integer ClanNum,Integer Armor,CSmMapPlayerSpawn PlayerSpawn,Integer ActivationDate);
/*!

*/
			Void SpawnBotPlayer(CSmPlayer Player,Integer ClanNum,Integer Armor,CSmMapBotPath BotPath,Integer ActivationDate);
/*!

*/
			Void UnspawnPlayer(CSmPlayer Player);
/*!

*/
			Void ClearScores();
/*!

*/
			Void SetPlayerClan(CSmPlayer Player,Integer ClanNum);
/*!

*/
			Void SetPlayerWeapon(CSmPlayer Player,EWeapon DefaultWeapon,Boolean AutoSwitchWeapon);
/*!

*/
			Void SetPlayerReloadAllWeapons(CSmPlayer Player,Boolean ReloadAllWeapons);
/*!

*/
			Void SetPlayerAmmo(CSmPlayer Player,EWeapon Weapon,Integer Count);
/*!

*/
			Integer GetPlayerAmmo(CSmPlayer Player,EWeapon Weapon);
/*!

*/
			Void AddPlayerAmmo(CSmPlayer Player,EWeapon Weapon,Real DeltaCount);
/*!

*/
			Void SetPlayerAmmoMax(CSmPlayer Player,EWeapon Weapon,Integer Count);
/*!

*/
			Integer GetPlayerAmmoMax(CSmPlayer Player,EWeapon Weapon);
/*!

*/
			Void AddPlayerArmor(CSmPlayer Victim,Integer DeltaArmor,CSmPlayer Shooter,Integer ShooterPoints);
/*!

*/
			Void RemovePlayerArmor(CSmPlayer Victim,Integer DeltaArmor,CSmPlayer Shooter,Integer ShooterPoints);
/*!

*/
			Integer GetWeaponNum(EWeapon Weapon);
/*!

*/
			Boolean CanRespawnPlayer(CSmPlayer Player);
/*!

*/
			Void RespawnPlayer(CSmPlayer Player);
/*!

*/
			Void RespawnPlayer(CSmPlayer Player,CSmMapLandmark CheckpointLandmark);
/*!

*/
			CSmPlayer CreateBotPlayer(Ident ModelId,Integer TeamNum);
/*!

*/
			Void DestroyBotPlayer(CSmPlayer BotPlayer);
/*!

*/
			Void DestroyAllBotPlayers();
/*!

*/
			Void ScriptedBot_Move(CSmPlayer BotPlayer,Vec3 Goal);
/*!

*/
			Void ScriptedBot_MoveDelta(CSmPlayer BotPlayer,Vec3 Delta);
/*!

*/
			Void ScriptedBot_MoveAndAim(CSmPlayer BotPlayer,Vec3 Goal);
/*!

*/
			Void ScriptedBot_MoveDeltaAndAim(CSmPlayer BotPlayer,Vec3 Delta);
/*!

*/
			Void ScriptedBot_Aim(CSmPlayer BotPlayer,Vec3 Goal);
/*!

*/
			Void ScriptedBot_AimDelta(CSmPlayer BotPlayer,Real DeltaYaw,Real DeltaPitch);
/*!

*/
			Void ScriptedBot_RequestAction(CSmPlayer BotPlayer);
/*!

*/
			Void ScriptedBot_RequestGunTrigger(CSmPlayer BotPlayer);
/*!

*/
			Void ActionLoad(CSmPlayer Player,EActionSlot ActionSlot,Ident ModelId);
/*!

*/
			Void ActionBind(CSmPlayer Player,EActionSlot ActionSlot,EActionInput ActionInput);
/*!

*/
			Void ActionSetVariant(CSmPlayer Player,EActionSlot ActionSlot,Integer ActionVariant);
/*!

*/
			Void SetNbFakePlayers(Integer NbClan1,Integer NbClan2);
/*!

*/
	const	CSmObject[] Objects;
/*!

*/
			CSmObject ObjectCreate(Ident ModelId);
/*!

*/
			Void ObjectDestroy(CSmObject Object);
/*!

*/
			Void ObjectDestroyAll();
/*!

*/
			Void Replay_SaveAttackScore(CSmPlayer Player,Integer Score);
/*!

*/
			Void Replay_SaveDefenseScore(CSmPlayer Player,Integer Score);
/*!

*/
			Void Replay_SaveTeamScore(Integer Team,Integer Score);
/*!

*/
			Void Replay_SavePlayerOfInterest(CSmPlayer Player);
/*!

*/
			Void Replay_SaveWinner(CSmPlayer Player);
/*!

*/
			Void Replay_SaveInterface();
};

/*!
Supported declare modes : Local  Persistent 
Ingame Manialink API for ShootMania.
*/
struct CSmMlScriptIngame : public CMlScriptIngame {
/*!

*/
	const	Integer ArenaNow;
/*!

*/
	const	CSmPlayer InputPlayer;
/*!

*/
	const	CSmPlayer GUIPlayer;
/*!

*/
	const	CSmPlayer[] Players;
/*!

*/
	const	CSmScore[] Scores;
/*!

*/
	const	Integer[] ClanScores;
/*!

*/
			Boolean HideResumePlayingButton;
/*!

*/
	const	CSmMapBase[] MapBases;
/*!

*/
	const	CSmMapLandmark[] MapLandmarks;
/*!

*/
	const	CSmMapLandmark[] MapLandmarks_PlayerSpawn;
/*!

*/
	const	CSmMapLandmark[] MapLandmarks_Gauge;
/*!

*/
	const	CSmMapLandmark[] MapLandmarks_Sector;
/*!

*/
	const	CSmMapLandmark[] MapLandmarks_BotPath;
/*!

*/
	const	CSmMapLandmark[] MapLandmarks_ObjectAnchor;
/*!

*/
	const	CSmMapLandmark[] MapLandmarks_Gate;
};

/*!
Supported declare modes : Local 

*/
struct CSmAction : public CNod {
/*!

*/
	const	Integer Now;
/*!

*/
	const	Integer Variant;
/*!

*/
			CSmPlayer[] Players;
/*!

*/
			CSmPlayer Owner;
/*!

*/
	const	Boolean IsActive;
/*!

*/
			Integer Energy;
/*!

*/
			Integer EnergyMax;
/*!

*/
			Integer EnergyCost;
/*!

*/
			Boolean EnergyReload;
/*!

*/
	const	CSmActionEvent[] PendingEvents;
/*!

*/
			Void SendRulesEvent(Text Param1,Text[] Param2,CSmPlayer Shooter,CSmPlayer Victim);
/*!

*/
			Ident GetAnimModelId(Text ModelName);
/*!

*/
			Void PlayAnimOnPlayer(Ident AnimModelId,CSmPlayer Player);
/*!

*/
			Void PlayAnimAtPosition(Ident AnimModelId,Vec3 Position,Vec3 Direction);
/*!

*/
			Ident GetProjectileModelId(Text ModelName);
/*!

*/
			Void CreateProjectile(CSmPlayer PlayerToIgnore,Ident ProjectileModelId,Vec3 InitialPosition,Vec3 InitialDirection,Vec3 InitialVelocity);
/*!

*/
			Void CreateProjectile(CSmPlayer PlayerToIgnore,Ident ProjectileModelId,Vec3 InitialPosition,Vec3 InitialDirection,Vec3 InitialVelocity,Integer ContextId);
/*!

*/
			Void CreateShoot(CSmPlayer Shooter,Ident ProjectileModelId);
/*!

*/
			Void CreateShoot(CSmPlayer Shooter,Ident ProjectileModelId,Integer ContextId);
/*!

*/
			Integer Cooldown;
/*!

*/
			Boolean Cooldown_IsReady(Integer Now);
/*!

*/
			Void Cooldown_Start();
};

/*!
Supported declare modes : Local  Persistent 

*/
struct CSmMapType : public CMapType {
/*!

*/
	const	CSmMode Mode;
/*!

*/
	const	CSmPlayer[] AllPlayers;
/*!

*/
	const	CSmPlayer[] Players;
};

/*!
Supported declare modes : Local  Persistent 
Trackmania race API for Manialink scripts
*/
struct CTmMlScriptIngame : public CMlScriptIngame {
/*!

*/
	const	CTmMlPlayer InputPlayer;
/*!

*/
	const	CTmMlPlayer GUIPlayer;
/*!

*/
	const	Integer NbLaps;
/*!

*/
	const	Boolean IndependantLaps;
/*!

*/
	const	CTmMlPlayer[] Players;
/*!

*/
	const	CTmScore[] Scores;
/*!

*/
	const	Integer[] ClanScores;
/*!

*/
	const	Vec3 MapStartLinePos;
/*!
You can use MapCheckpointPos.count to get the number of checkpoints.
*/
	const	Vec3[] MapCheckpointPos;
/*!

*/
	const	Vec3[] MapFinishLinePos;
/*!

*/
	const	Boolean MapIsLapRace;
/*!

*/
	const	Integer MapNbLaps;
};

/*!
Supported declare modes : Local  Persistent 
Rules API for TrackMania gamemodes.
*/
struct CTmMode : public CMode {
	enum ETmScoreSortOrder {
		TotalPoints,
		BestRace_Time,
		BestRace_Stunts,
		BestRace_NbRespawns,
		BestRace_CheckpointsProgress,
		PrevRace_Time,
		Name,
		LadderRankSortValue,
	};
	enum ETMRespawnBehaviour {
		Normal,
		DoNothing,
		GiveUpBeforeFirstCheckPoint,
		AlwaysGiveUp,
	};
	enum ETmRaceChronoBehaviour {
		Auto,
		Hidden,
		CountDown,
		Normal,
	};
	enum EPersonalGhost {
		Disabled,
		Latest,
		FastestRace,
	};
/*!

*/
	const	CTmPlayer[] AllPlayers;
/*!

*/
	const	CTmPlayer[] Spectators;
/*!

*/
	const	CTmPlayer[] Players;
/*!

*/
	const	CTmPlayer[] PlayersRacing;
/*!

*/
	const	CTmPlayer[] PlayersWaiting;
/*!

*/
	const	CTmScore[] Scores;
/*!

*/
			Integer Clan1Score;
/*!

*/
			Integer Clan2Score;
/*!

*/
			Integer[] ClanScores;
/*!

*/
	const	Integer ClansNbTotal;
/*!

*/
	const	Integer[] ClansNbPlayers;
/*!

*/
	const	CTmModeEvent[] PendingEvents;
/*!

*/
			Void PassOn(CTmModeEvent Event);
/*!

*/
			Void Discard(CTmModeEvent Event);
/*!

*/
			Void SpawnPlayer(CTmPlayer Player,Integer ClanNum,Integer RaceStartTime);
/*!

*/
			Void UnspawnPlayer(CTmPlayer Player);
/*!

*/
			Void SetPlayerClan(CTmPlayer Player,Integer ClanNum);
/*!

*/
			Void Scores_Sort(ETmScoreSortOrder SortOrder);
/*!

*/
			Void Scores_Clear();
/*!

*/
			Void Ladder_ComputeRank(ETmScoreSortOrder SortOrder);
/*!

*/
			Integer CutOffTimeLimit;
/*!

*/
			Integer NbLaps;
/*!

*/
			Boolean IndependantLaps;
/*!

*/
			Boolean UseClans;
/*!

*/
			Boolean UseForcedClans;
/*!

*/
			ETMRespawnBehaviour RespawnBehaviour;
/*!

*/
			Boolean UiRounds;
/*!

*/
			Boolean UiLaps;
/*!

*/
			Boolean UiStuntsMode;
/*!

*/
			Boolean UiDisplayStuntsNames;
/*!

*/
			Boolean UiDisableHelpMessage;
/*!

*/
			Integer UiScoresPointsLimit;
/*!

*/
			ETmRaceChronoBehaviour UiRaceChrono;
/*!

*/
			Boolean HideOpponents;
/*!

*/
			Integer ForceMaxOpponents;
/*!

*/
			Boolean EnableLegacyXmlRpcCallbacks;
/*!

*/
			Boolean MedalGhost_ShowGold;
/*!

*/
			Boolean MedalGhost_ShowSilver;
/*!

*/
			Boolean MedalGhost_ShowBronze;
/*!

*/
			EPersonalGhost PersonalGhost;
/*!

*/
	const	Vec3 MapStartLinePos;
/*!
You can use MapCheckpointPos.count to get the number of checkpoints.
*/
	const	Vec3[] MapCheckpointPos;
/*!

*/
	const	Vec3[] MapFinishLinePos;
/*!

*/
	const	Boolean MapIsLapRace;
/*!

*/
	const	Integer MapNbLaps;
};

/*!
Supported declare modes : Local  Persistent 

*/
struct CTmMapType : public CMapType {
/*!

*/
	const	CTmMode Mode;
/*!

*/
	const	CTmPlayer[] AllPlayers;
/*!

*/
	const	CTmPlayer[] Players;
};

/*!

*/
struct CNod {
/*!

*/
	const	Ident Id;
};

/*!
Supported declare modes : Local  Persistent 

*/
struct CMlPage : public CNod {
/*!

*/
	const	CMlFrame MainFrame;
/*!

*/
			CMlControl GetFirstChild(Text ControlId);
/*!

*/
			Boolean LinksInhibited;
/*!

*/
			Void GetClassChildren(Text Class,CMlFrame Frame,Boolean Recursive);
/*!

*/
	const	CMlControl[] GetClassChildren_Result;
};

/*!
Supported declare modes : Local  Persistent  Cloud 

*/
struct CUser : public CNod {
	enum EEchelon {
		None,
		Bronze1,
		Bronze2,
		Bronze3,
		Silver1,
		Silver2,
		Silver3,
		Gold1,
		Gold2,
		Gold3,
	};
	enum ETagType {
		Bronze,
		Silver,
		Gold,
		Nadeo,
	};
	enum EStereoDisplayMode {
		None,
		Stereo,
		HMD,
	};
/*!

*/
	const	Text Login;
/*!

*/
	const	Text Name;
/*!

*/
	const	Text AvatarUrl;
/*!

*/
	const	Text ZonePath;
/*!

*/
	const	Text ZoneFlagUrl;
/*!

*/
	const	Text CountryFlagUrl;
/*!

*/
	const	Text Language;
/*!

*/
	const	Text Description;
/*!

*/
	const	Vec3 Color;
/*!

*/
	const	Text ClubLink;
/*!

*/
	const	Text BroadcastTVLogin;
/*!

*/
	const	Text SteamUserId;
/*!

*/
	const	Integer FameStars;
/*!

*/
	const	EEchelon Echelon;
/*!

*/
	const	Boolean IsBeginner;
/*!

*/
	const	Integer LadderRank;
/*!

*/
	const	Integer LadderTotal;
/*!

*/
	const	Real LadderPoints;
/*!

*/
	const	Text LadderZoneName;
/*!

*/
	const	Text LadderZoneFlagUrl;
/*!

*/
	const	Integer RequestedClan;
/*!

*/
	const	Boolean RequestsSpectate;
/*!

*/
	const	Boolean IsFakeUser;
/*!

*/
	const	Integer[] Tags_Favored_Indices;
/*!

*/
	const	Text[] Tags_Id;
/*!

*/
	const	ETagType[] Tags_Type;
/*!

*/
	const	Text[] Tags_Comments;
/*!

*/
	const	Text[] Tags_Deliverer;
/*!

*/
	const	Text[] AlliesConnected;
/*!

*/
	const	EStereoDisplayMode StereoDisplayMode;
	enum PlayerType {
		Human,
		Fake (not net),
		Net,
		Replay,
	};
	enum SpectatorMode {
		Void,
		Watcher,
		LocalWatcher,
		Target,
	};
};

/*!
Supported declare modes : Local  Persistent 

*/
struct CTitle : public CNod {
/*!

*/
	const	Text TitleId;
/*!

*/
	const	Text BaseTitleId;
/*!

*/
	const	Text Name;
/*!

*/
	const	Text Desc;
/*!

*/
	const	Text InfoUrl;
/*!

*/
	const	Text DownloadUrl;
/*!

*/
	const	Text TitleVersion;
};

/*!
Events for Manialink page scripts.
*/
struct CMlEvent : public CNod {
	enum Type {
		KeyPress,
		MouseClick,
		MouseOver,
		MouseOut,
		EntrySubmit,
		MenuNavigation,
		PluginCustomEvent,
	};
	enum EMenuNavAction {
		Up,
		Right,
		Left,
		Down,
		Select,
		Cancel,
		PageUp,
		PageDown,
	};
/*!

*/
	const	Type Type;
/*!

*/
	const	Integer KeyCode;
/*!

*/
	const	Text KeyName;
/*!

*/
	const	Text CharPressed;
/*!

*/
	const	Text ControlId;
/*!

*/
	const	CMlControl Control;
/*!

*/
	const	EMenuNavAction MenuNavAction;
/*!

*/
	const	Text CustomEventType;
/*!

*/
	const	Text[] CustomEventData;
};

/*!

*/
struct CXmlManager : public CNod {
/*!

*/
			CXmlDocument Create(Text Contents);
/*!

*/
			CXmlDocument Create(Text Contents,Boolean GenerateText,Boolean GenerateTextRaw,Boolean GenerateTextResursive);
/*!

*/
			Void Destroy(CXmlDocument Document);
/*!

*/
	const	CXmlDocument[] Documents;
};

/*!

*/
struct CHttpManager : public CNod {
/*!

*/
			CHttpRequest CreateGet(Text Url);
/*!

*/
			CHttpRequest CreateGet(Text Url,Boolean UseCache);
/*!

*/
			CHttpRequest CreatePost(Text Url,Text Resource);
/*!

*/
			Void Destroy(CHttpRequest Request);
/*!

*/
			Boolean IsValidUrl(Text Url);
/*!

*/
	const	CHttpRequest[] Requests;
/*!

*/
	const	Integer SlotsAvailable;
};

/*!

*/
struct CAudioManager : public CNod {
	enum ELibSound {
		Alert,
		ShowDialog,
		HideDialog,
		ShowMenu,
		HideMenu,
		Focus,
		Valid,
		Start,
		Countdown,
		Victory,
		ScoreIncrease,
		Checkpoint,
	};
/*!

*/
			CAudioSound CreateSound(Text Url);
/*!

*/
			CAudioSound CreateSound(Text Url,Real VolumedB,Boolean IsMusic,Boolean IsLooping,Boolean IsSpatialized);
/*!

*/
			Void DestroySound(CAudioSound Sound);
/*!

*/
	const	CAudioSound[] Sounds;
/*!

*/
			Void PlaySoundEvent(CAudioSound Sound,Real VolumedB);
/*!

*/
			Void PlaySoundEvent(Text Url,Real VolumedB);
/*!

*/
			Void PlaySoundEvent(ELibSound Sound,Integer SoundVariant,Real VolumedB);
/*!

*/
			Void PlaySoundEvent(CAudioSound Sound,Real VolumedB,Integer Delay);
/*!

*/
			Void PlaySoundEvent(Text Url,Real VolumedB,Integer Delay);
/*!

*/
			Void PlaySoundEvent(ELibSound Sound,Integer SoundVariant,Real VolumedB,Integer Delay);
/*!

*/
			Void ClearAllDelayedSoundsEvents();
/*!

*/
			Boolean ForceEnableMusic;
/*!

*/
			Real LimitMusicVolumedB;
};

/*!
Supported declare modes : Local 
Manialink control.
*/
struct CMlControl : public CNod {
	enum AlignHorizontal {
		Left,
		HCenter,
		Right,
		None,
	};
	enum AlignVertical {
		Top,
		VCenter,
		Bottom,
		None,
		VCenter2,
	};
/*!

*/
	const	Text ControlId;
/*!

*/
	const	Text[] ControlClasses;
/*!

*/
			Boolean HasClass(Text Class);
/*!

*/
			Vec2 Size;
/*!

*/
			AlignHorizontal HorizontalAlign;
/*!

*/
			AlignVertical VerticalAlign;
/*!

*/
			Boolean Visible;
/*!

*/
			Vec3 RelativePosition;
/*!

*/
			Real RelativeScale;
/*!

*/
			Real RelativeRotation;
/*!

*/
	const	Vec3 AbsolutePosition;
/*!

*/
	const	Real AbsoluteScale;
/*!

*/
	const	Real AbsoluteRotation;
/*!

*/
			Boolean DataAttributeExists(Text DataName);
/*!

*/
			Text DataAttributeGet(Text DataName);
/*!

*/
			Void DataAttributeSet(Text DataName,Text DataValue);
/*!

*/
			Void Show();
/*!

*/
			Void Hide();
/*!

*/
			Void Unload();
/*!

*/
			Void Focus();
};

/*!

*/
struct CMlGraphCurve : public CNod {
/*!

*/
			Vec2[] Points;
/*!

*/
			Vec3 Color;
/*!

*/
			Void SortPoints();
/*!

*/
			Text Style;
/*!
Values in range (0.000000-50.000000)
*/
			Real Width;
};

/*!
Supported declare modes : Local  Metadata  Persistent 

*/
struct CMap : public CNod {
/*!

*/
	const	CMapInfo MapInfo;
/*!

*/
			Text MapName;
/*!

*/
			Text Comments;
/*!

*/
	const	Text AuthorZoneIconUrl;
/*!

*/
	const	Text CollectionName;
/*!

*/
	const	Text DecorationName;
/*!

*/
	const	Text AuthorLogin;
/*!

*/
	const	Text AuthorNickName;
/*!

*/
	const	Text AuthorZonePath;
/*!

*/
	const	Text MapType;
/*!

*/
	const	Text MapStyle;
/*!

*/
			Integer TMObjective_AuthorTime;
/*!

*/
			Integer TMObjective_GoldTime;
/*!

*/
			Integer TMObjective_SilverTime;
/*!

*/
			Integer TMObjective_BronzeTime;
/*!

*/
			Integer TMObjective_NbLaps;
/*!

*/
			Boolean TMObjective_IsLapRace;
/*!

*/
			Text ObjectiveTextAuthor;
/*!

*/
			Text ObjectiveTextGold;
/*!

*/
			Text ObjectiveTextSilver;
/*!

*/
			Text ObjectiveTextBronze;
/*!

*/
	const	Integer CopperPrice;
/*!

*/
	const	Int3 Size;
};

/*!

*/
struct CUILayer : public CNod {
	enum EUILayerType {
		Normal,
		ScoresTable,
		ScreenIn3d,
		AltMenu,
		Markers,
		CutScene,
		InGameMenu,
		EditorPlugin,
		ManiaplanetPlugin,
		ManiaplanetMenu,
		LoadingScreen,
	};
/*!

*/
			Boolean IsVisible;
/*!

*/
			EUILayerType Type;
/*!

*/
			Text AttachId;
/*!

*/
			Text ManialinkPage;
/*!

*/
	const	CMlPage LocalPage;
};

/*!

*/
struct CEditorPluginEvent : public CManiaAppEvent {
	enum Type {
		LayerCustomEvent,
		KeyPress,
		(reserved),
		MenuNavigation,
		CursorSelectionBegin,
		CursorSelectionEnd,
		CursorChange,
		MapModified,
		EditorInput,
		EditAnchor,
		EditObjectives,
		StartValidation,
	};
	enum EInput {
		Unknown,
		Menu,
		SwitchToRace,
		CursorUp,
		CursorRight,
		CursorDown,
		CursorLeft,
		CursorRaise,
		CursorLower,
		CursorTurn,
		CursorPick,
		CursorPlace,
		CursorDelete,
		CameraUp,
		CameraRight,
		CameraDown,
		CameraLeft,
		IconUp,
		IconRight,
		IconDown,
		IconLeft,
	};
/*!

*/
	const	Type Type;
/*!

*/
	const	EInput Input;
/*!

*/
	const	Ident EditedAnchorDataId;
};

/*!
The model of a map block
*/
struct CBlockModel : public CCollector {
	enum EBaseType {
		None,
		Conductor,
		Generator,
		Collector,
	};
	enum EWayPointType {
		Start,
		Finish,
		Checkpoint,
		None,
		StartFinish,
	};
	enum EProdState {
		Obsolete,
		GameBox,
		DevBuild,
		Release,
	};
/*!

*/
	const	Text Name;
/*!

*/
	const	Boolean IsRoad;
/*!

*/
	const	Boolean IsTerrain;
/*!

*/
	const	EWayPointType WaypointType;
/*!

*/
	const	Boolean NoRespawn;
/*!

*/
	const	CBlockModelVariantGround VariantGround;
/*!

*/
	const	CBlockModelVariantAir VariantAir;
};

/*!
Supported declare modes : Local  Metadata 

*/
struct CMacroblockModel : public CCollector {
/*!

*/
	const	Boolean IsGround;
/*!

*/
	const	Boolean HasStart;
/*!

*/
	const	Boolean HasFinish;
/*!

*/
	const	Boolean HasCheckpoint;
/*!

*/
	const	CBlockModel GeneratedBlockModel;
/*!

*/
	const	Text Name;
};

/*!

*/
struct CItemAnchor : public CNod {
	enum CardinalDirections {
		North,
		East,
		South,
		West,
	};
/*!

*/
	const	Vec3 Position;
};

/*!

*/
struct CBlock : public CNod {
	enum CardinalDirections {
		North,
		East,
		South,
		West,
	};
/*!

*/
	const	Integer BlockScriptId;
/*!

*/
	const	Boolean CanHaveAnchor;
/*!

*/
			Void UseDefaultAnchor();
/*!

*/
			Void UseCustomAnchor();
/*!

*/
	const	Int3 Coord;
/*!

*/
	const	CardinalDirections Direction;
/*!

*/
	const	CBlockUnit[] BlockUnits;
/*!

*/
	const	CBlockModel BlockModel;
};

/*!
Supported declare modes : Metadata 

*/
struct CAnchorData : public CNod {
/*!

*/
	const	Text DefaultTag;
/*!

*/
	const	Integer DefaultOrder;
/*!

*/
			Text Tag;
/*!

*/
			Integer Order;
};

/*!
Supported declare modes : Local  Persistent 

*/
struct CMode : public CNod {
	enum EMedal {
		None,
		Finished,
		Bronze,
		Silver,
		Gold,
		Author,
	};
/*!

*/
			Text ModeStatusMessage;
/*!

*/
	const	CTitle LoadedTitle;
/*!

*/
	const	Text ServerLogin;
/*!

*/
	const	Text ServerName;
/*!

*/
	const	Text ServerModeName;
/*!

*/
	const	Text MapName;
/*!

*/
	const	CMap Map;
/*!

*/
	const	Text MapPlayerModelName;
/*!

*/
	const	CUser[] Users;
/*!

*/
	const	CTeam[] Teams;
/*!

*/
			Text NeutralEmblemUrl;
/*!

*/
	const	Text ForcedClubLinkUrl1;
/*!

*/
	const	Text ForcedClubLinkUrl2;
/*!

*/
			Void TweakTeamColorsToAvoidHueOverlap();
/*!

*/
	const	Integer Now;
/*!

*/
	const	Integer Period;
/*!

*/
			Boolean MatchEndRequested;
/*!

*/
	const	Boolean ServerShutdownRequested;
/*!

*/
	const	Boolean MapLoaded;
/*!

*/
			Void RequestLoadMap();
/*!

*/
			Void RequestUnloadMap();
/*!

*/
	const	CMapInfo[] MapList;
/*!

*/
			Integer NextMapIndex;
/*!

*/
	const	CUIConfigMgr UIManager;
/*!

*/
			Void Ladder_OpenMatch_Request();
/*!

*/
			Void Ladder_AddPlayer(CScore PlayerScore);
/*!

*/
			Void Ladder_OpenMatch_BeginRequest();
/*!

*/
			Void Ladder_OpenMatch_AddPlayer(CScore PlayerScore);
/*!

*/
			Void Ladder_OpenMatch_EndRequest();
/*!

*/
			Void Ladder_CloseMatchRequest();
/*!

*/
			Void Ladder_CancelMatchRequest();
/*!

*/
	const	Boolean Ladder_RequestInProgress;
/*!

*/
			Void Ladder_SetResultsVersion(Integer Version);
/*!

*/
			Void Ladder_SetMatchMakingMatchId(Integer MatchId);
/*!

*/
			Void Ladder_EnableChallengeMode(Boolean Enable);
/*!

*/
			Boolean Admin_KickUser(CUser User,Text Reason);
/*!

*/
			Void Admin_SetLobbyInfo(Boolean IsLobby,Integer LobbyPlayerCount,Integer LobbyMaxPlayerCount,Real LobbyPlayersLevel);
/*!

*/
			Void AutoTeamBalance();
/*!

*/
			Void Solo_SetNewRecord(CScore PlayerScore,EMedal PlayerScore);
/*!

*/
	const	Boolean Solo_NewRecordSequenceInProgress;
/*!

*/
	const	CXmlRpc XmlRpc;
/*!

*/
	const	CXmlManager Xml;
/*!

*/
	const	CHttpManager Http;
/*!

*/
			Integer Synchro_AddBarrier();
/*!

*/
			Boolean Synchro_BarrierReached(Integer Barrier);
/*!

*/
			Boolean Users_AreAllies(CUser User1,CUser User2);
/*!

*/
			Void Users_RequestSwitchToSpectator(CUser User);
/*!

*/
			CUser Users_CreateFake(Text NickName,Integer RequestedTeam);
/*!

*/
			Void Users_DestroyFake(CUser User);
/*!

*/
			Void Users_SetNbFakeUsers(Integer NbTeam1,Integer NbTeam2);
/*!

*/
			Void Users_DestroyAllFakes();
/*!

*/
			Void ItemList_Begin();
/*!

*/
			Ident ItemList_Add(Text ModelName);
/*!

*/
			Ident ItemList_AddWithSkin(Text ModelName,Text SkinName);
/*!

*/
			Void ItemList_End();
/*!

*/
			Void DemoToken_StartUsingToken();
/*!

*/
			Void DemoToken_StopUsingToken();
/*!

*/
			Void DemoToken_GetAndUseToken(CUser User);
/*!

*/
			Void ActionList_Begin();
/*!

*/
			Ident ActionList_Add(Text ActionName);
/*!

*/
			Void ActionList_End();
/*!

*/
			Boolean UseMinimap;
/*!

*/
			Boolean Replay_AutoStart;
/*!

*/
			Void Replay_Start();
/*!

*/
			Void Replay_Stop();
};

/*!
Supported declare modes : Local  NetworkRead  NetworkWrite 
A Shootmania player.
*/
struct CSmPlayer : public CPlayer {
	enum ESpawnStatus {
		NotSpawned,
		Spawning,
		Spawned,
	};
/*!

*/
	const	CSmScore Score;
/*!

*/
	const	ESpawnStatus SpawnStatus;
/*!

*/
	const	Integer StartTime;
/*!

*/
			Integer EndTime;
/*!
Values in range (0.000000-10.000000)
*/
			Real AmmoGain;
/*!
Values in range (0.100000-10.000000)
*/
			Real AmmoPower;
/*!

*/
	const	Boolean AutoSwitchWeapon;
/*!

*/
	const	Integer CurWeapon;
/*!

*/
	const	Integer CurAmmo;
/*!

*/
	const	Integer CurAmmoMax;
/*!

*/
	const	Integer CurAmmoUnit;
/*!

*/
			Integer Armor;
/*!

*/
			Integer ArmorMax;
/*!

*/
			Integer ArmorGain;
/*!

*/
			Integer ArmorReplenishGain;
/*!
Values in range (0.100000-10.000000)
*/
			Real ArmorPower;
/*!

*/
			Integer Stamina;
/*!
Values in range (0.100000-3.000000)
*/
			Real StaminaMax;
/*!
Values in range (0.000000-1.000000)
*/
			Real StaminaGain;
/*!
Values in range (0.100000-1.000000)
*/
			Real StaminaPower;
/*!
Values in range (0.100000-1.000000)
*/
			Real SpeedPower;
/*!
Values in range (0.100000-1.000000)
*/
			Real JumpPower;
/*!

*/
			Boolean AllowWallJump;
/*!

*/
			Boolean AllowProgressiveJump;
/*!

*/
			Boolean UseAlternateWeaponVisual;
/*!

*/
			Boolean IsHighlighted;
/*!
Values in range (0.000000-1.000000)
*/
			Real EnergyLevel;
/*!

*/
			Vec3 ForceColor;
/*!

*/
			Ident ForceModelId;
/*!

*/
			Boolean HasShield;
/*!
Values in range (0.000000-500.000000)
*/
			Real ThrowSpeed;
/*!

*/
	const	Integer CurrentClan;
/*!

*/
	const	Integer IdleDuration;
/*!

*/
	const	Vec3 Position;
/*!

*/
	const	Real AimYaw;
/*!

*/
	const	Real AimPitch;
/*!

*/
	const	Vec3 AimDirection;
/*!

*/
	const	Boolean IsUnderground;
/*!

*/
	const	Boolean IsTouchingGround;
/*!

*/
	const	Boolean IsInAir;
/*!

*/
	const	Boolean IsOnTechGround;
/*!

*/
	const	Boolean IsOnTechLaser;
/*!

*/
	const	Boolean IsOnTechArrow;
/*!

*/
	const	Boolean IsOnTechArmor;
/*!

*/
	const	Boolean IsOnTechSafeZone;
/*!

*/
	const	Boolean IsOnTech;
/*!

*/
	const	Boolean IsOnTechNoWeapon;
/*!

*/
	const	Boolean IsInWater;
/*!

*/
	const	Vec3 Velocity;
/*!

*/
	const	Real Speed;
/*!

*/
	const	Boolean IsInOffZone;
/*!

*/
	const	Boolean IsCapturing;
/*!

*/
	const	CSmMapLandmark CapturedLandmark;
/*!

*/
	const	CSmObject[] Objects;
/*!

*/
	const	Boolean IsFakePlayer;
/*!

*/
	const	Boolean IsBot;
/*!

*/
	const	CSmPlayerDriver Driver;
};

/*!
Event recieved by ShootMania gamemodes.
*/
struct CSmModeEvent : public CNod {
	enum EType {
		Unknown,
		OnShoot,
		OnHit,
		OnNearMiss,
		OnArmorEmpty,
		OnCapture,
		OnShotDeny,
		OnFallDamage,
		OnCommand,
		OnPlayerAdded,
		OnPlayerRemoved,
		OnPlayerRequestRespawn,
		OnActionCustomEvent,
		OnActionEvent,
		OnPlayerTouchesObject,
		OnPlayerTriggersSector,
		OnPlayerThrowsObject,
		OnPlayerRequestActionChange,
	};
	enum EActionSlot {
		Slot_A,
		Slot_B,
		Slot_C,
		Slot_D,
		Slot_E,
		Slot_F,
		Slot_G,
		Slot_H,
	};
	enum EActionInput {
		Weapon,
		Movement,
		Activable1,
		Activable2,
		Activable3,
		Activable4,
		Consumable1,
		Consumable2,
		None,
	};
	enum EActionSlots {
		Weapon,
		Movement,
		Activable1,
		Activable2,
		Activable3,
		Activable4,
		None,
	};
/*!

*/
	const	EType Type;
/*!

*/
	const	CSmPlayer Player;
/*!

*/
			Integer Damage;
/*!

*/
	const	CSmObject VictimObject;
/*!

*/
			Integer ShooterPoints;
/*!

*/
	const	CSmPlayer Shooter;
/*!

*/
	const	CSmPlayer Victim;
/*!

*/
	const	Real Height;
/*!

*/
	const	Real MissDist;
/*!

*/
	const	Integer WeaponNum;
/*!

*/
	const	Boolean ShooterUsedAction;
/*!

*/
	const	Integer ShooterWeaponNum;
/*!

*/
	const	EActionSlot ShooterActionSlot;
/*!

*/
	const	Text ShooterActionId;
/*!

*/
	const	Boolean VictimUsedAction;
/*!

*/
	const	Integer VictimWeaponNum;
/*!

*/
	const	EActionSlot VictimActionSlot;
/*!

*/
	const	Text VictimActionId;
/*!

*/
	const	EActionSlot Action_Slot;
/*!

*/
	const	EActionInput ActionInput;
/*!

*/
	const	Text ActionId;
/*!

*/
	const	Text Param1;
/*!

*/
	const	Text[] Param2;
/*!

*/
	const	CSmObject Object;
/*!

*/
	const	CSmMapSector Sector;
/*!

*/
	const	CSmBlockPole BlockPole;
/*!

*/
	const	CSmMapLandmark Landmark;
/*!

*/
	const	Ident PlayerId;
/*!

*/
	const	CUser User;
/*!

*/
	const	Boolean PlayerWasSpawned;
/*!

*/
	const	Boolean PlayerWasInLadderMatch;
/*!

*/
	const	Vec3 PlayerLastPosition;
/*!

*/
	const	Vec3 PlayerLastAimDirection;
/*!

*/
	const	Boolean GiveUp;
/*!

*/
	const	Text CommandName;
/*!

*/
	const	Boolean CommandValueBoolean;
/*!

*/
	const	Integer CommandValueInteger;
/*!

*/
	const	Real CommandValueReal;
/*!

*/
	const	Text CommandValueText;
/*!

*/
	const	Integer ActionChange;
};

/*!

*/
struct CSmMapBase : public CNod {
/*!

*/
			Integer Clan;
/*!

*/
			Boolean IsActive;
/*!

*/
	const	Integer NumberOfCollectors;
};

/*!
Supported declare modes : Local  Metadata 

*/
struct CSmMapLandmark : public CNod {
/*!

*/
	const	Text Tag;
/*!

*/
	const	Integer Order;
/*!

*/
	const	Vec3 Position;
/*!

*/
	const	CSmMapBase Base;
/*!

*/
	const	CSmMapGate Gate;
/*!

*/
	const	CSmMapGauge Gauge;
/*!

*/
	const	CSmMapSector Sector;
/*!

*/
	const	CSmMapPlayerSpawn PlayerSpawn;
/*!

*/
	const	CSmMapBotPath BotPath;
/*!

*/
	const	CSmMapObjectAnchor ObjectAnchor;
};

/*!
Supported declare modes : Local  NetworkRead  NetworkWrite 
Scoring info for ShootMania players.
*/
struct CSmScore : public CScore {
/*!

*/
	const	Integer TeamNum;
/*!

*/
			Integer Points;
/*!

*/
			Integer RoundPoints;
/*!

*/
	const	Integer NbEliminationsInflicted;
/*!

*/
	const	Integer NbEliminationsTaken;
/*!

*/
	const	Integer NbRespawnsRequested;
/*!

*/
	const	Integer DamageInflicted;
/*!

*/
	const	Integer DamageTaken;
/*!

*/
			Void Clear();
};

/*!
Supported declare modes : Local 
An instance of an object.
*/
struct CSmObject : public CNod {
	enum EStatus {
		OnPlayer,
		OnAnchor,
		InWorld,
		Unspawned,
	};
/*!

*/
	const	EStatus Status;
/*!

*/
	const	Ident ModelId;
/*!

*/
			Void SetAnchor(CSmMapObjectAnchor ObjectAnchor);
/*!

*/
			Void SetPlayer(CSmPlayer Player);
/*!

*/
			Void SetPosition(Vec3 Position);
/*!

*/
			Void SetPositionAndVel(Vec3 Position,Vec3 Vel);
/*!

*/
			Void SetUnspawned();
/*!
Player holding the object, or Null if the object isn't held by a player.
*/
	const	CSmPlayer Player;
/*!

*/
	const	Vec3 Position;
/*!

*/
	const	Vec3 Vel;
/*!

*/
			Integer MachineState;
/*!

*/
			Boolean Throwable;
};

/*!
Supported declare modes : Local  Persistent 
API for GameModes Manialinks
*/
struct CMlScriptIngame : public CMlScript {
	enum EUISound {
		Default,
		Silence,
		StartMatch,
		EndMatch,
		StartRound,
		EndRound,
		PhaseChange,
		TieBreakPoint,
		TiePoint,
		VictoryPoint,
		Capture,
		TimeOut,
		Notice,
		Warning,
		PlayerEliminated,
		PlayerHit,
		Checkpoint,
		Finish,
		Record,
		ScoreProgress,
		RankChange,
		Bonus,
		FirstHit,
		Combo,
		PlayersRemaining,
		Custom1,
		Custom2,
		Custom3,
		Custom4,
	};
	enum EInGameMenuResult {
		Resume,
		Quit,
		NormalMenu,
		AdvancedMenu,
		ServerSettings,
	};
/*!

*/
	const	Integer GameTime;
/*!
(read-only) UI actually displayed, as defined by the server.
*/
			CUIConfig UI;
/*!
Locally accessible by the client script to locally override settings from the server.
*/
			CUIConfig ClientUI;
/*!
Switch the player to spectator or back into playing
*/
			Boolean IsSpectatorMode;
/*!

*/
	const	Boolean UseClans;
/*!

*/
	const	Boolean UseForcedClans;
/*!

*/
	const	CMap Map;
/*!

*/
			Void ShowCurChallengeCard();
/*!

*/
			Void ShowModeHelp();
/*!

*/
			Void CopyServerLinkToClipBoard();
/*!

*/
			Void JoinTeam1();
/*!

*/
			Void JoinTeam2();
/*!

*/
	const	CTeam[] Teams;
/*!
Set the spectated player, but do not switch to spectator mode automatically. Equivalent to pavnum1/2/3/4
*/
			Void SetSpectateTarget(Text Player);
/*!

*/
			Void ShowProfile(Text Player);
/*!

*/
			Void ShowInGameMenu();
/*!

*/
	const	Text CurrentServerLogin;
/*!

*/
	const	Text CurrentServerName;
/*!

*/
	const	Text CurrentServerJoinLink;
/*!

*/
	const	Text CurrentServerModeName;
/*!

*/
			Void PlayUiSound(EUISound Sound,Integer SoundVariant,Real Volume);
/*!

*/
			Void CloseInGameMenu(EInGameMenuResult Result);
};

/*!

*/
struct CSmActionEvent : public CNod {
	enum EType {
		OnHitPlayer,
		OnProjectileStart,
		OnProjectileEnd,
		OnActiveChange,
	};
/*!

*/
	const	EType Type;
/*!

*/
	const	CSmPlayer Player;
/*!

*/
	const	Integer Damage;
/*!

*/
	const	Ident ProjectileModelId;
/*!

*/
	const	Integer ContextId;
/*!

*/
	const	Vec3 Position;
/*!

*/
	const	Vec3 Direction;
/*!

*/
	const	Vec3 Normal;
};

/*!
Supported declare modes : Local  Persistent 

*/
struct CMapType : public CEditorPlugin {
	enum ValidationStatus {
		NotValidable,
		Validable,
		Validated,
	};
/*!

*/
			Boolean CustomEditAnchorData;
/*!

*/
			Void ClearMapMetadata();
/*!

*/
			ValidationStatus ValidationStatus;
/*!

*/
			Text ValidabilityRequirementsMessage;
/*!

*/
	const	Boolean ValidationEndRequested;
/*!

*/
			Void StartTestMapWithMode(Text RulesModeName);
/*!

*/
			Void RequestEnterPlayground();
/*!

*/
			Void RequestLeavePlayground();
/*!

*/
	const	Boolean IsSwitchedToPlayground;
/*!

*/
	const	CUIConfigMgr UIManager;
/*!

*/
	const	CUser[] Users;
};

/*!
Supported declare modes : Local  NetworkRead  NetworkWrite 

*/
struct CTmMlPlayer : public CPlayer {
	enum ERaceState {
		BeforeStart,
		Running,
		Finished,
		Eliminated,
	};
/*!

*/
	const	Integer CurrentClan;
/*!

*/
	const	ERaceState RaceState;
/*!

*/
	const	Boolean IsSpawned;
/*!

*/
			CTrackManiaScore Score;
/*!

*/
	const	Integer RaceStartTime;
/*!

*/
	const	Integer LapStartTime;
/*!

*/
			CTmResult CurRace;
/*!

*/
			CTmResult CurLap;
/*!

*/
	const	Integer CurrentNbLaps;
/*!

*/
	const	Integer CurTriggerIndex;
/*!

*/
	const	Integer CurCheckpointRaceTime;
/*!

*/
	const	Integer CurCheckpointLapTime;
/*!

*/
	const	Real AccelCoef;
/*!

*/
	const	Real ControlCoef;
/*!

*/
	const	Real GravityCoef;
/*!

*/
	const	Vec3 Position;
/*!

*/
	const	Real AimYaw;
/*!

*/
	const	Real AimPitch;
/*!

*/
	const	Vec3 AimDirection;
/*!

*/
	const	Real Distance;
/*!

*/
	const	Real Speed;
/*!

*/
	const	Integer DisplaySpeed;
};

/*!
Supported declare modes : Local  NetworkRead  NetworkWrite 

*/
struct CTmScore : public CScore {
/*!

*/
	const	Integer TeamNum;
/*!

*/
			Integer Points;
/*!

*/
			CTmResult BestRace;
/*!

*/
			CTmResult BestLap;
/*!

*/
			Integer PrevRaceDeltaPoints;
/*!

*/
			CTmResult PrevRace;
/*!

*/
			CTmResult TempResult;
/*!

*/
			Void Clear();
};

/*!
Supported declare modes : Local  NetworkRead  NetworkWrite 

*/
struct CTmPlayer : public CPlayer {
/*!

*/
	const	Integer CurrentClan;
/*!

*/
	const	CTmScore Score;
/*!

*/
			Integer RaceStartTime;
/*!

*/
			Boolean IsSpawned;
/*!

*/
			CTmResult CurRace;
/*!

*/
			CTmResult CurLap;
/*!

*/
			Integer CurrentNbLaps;
/*!

*/
	const	Integer CurTriggerIndex;
/*!

*/
	const	Vec3 Position;
/*!

*/
	const	Real AimYaw;
/*!

*/
	const	Real AimPitch;
/*!

*/
	const	Vec3 AimDirection;
/*!

*/
			Real AccelCoef;
/*!

*/
			Real ControlCoef;
/*!

*/
			Real GravityCoef;
};

/*!

*/
struct CTmModeEvent : public CNod {
	enum EType {
		Unknown,
		StartLine,
		WayPoint,
		GiveUp,
		Respawn,
		Stunt,
		OnPlayerAdded,
		OnPlayerRemoved,
		OnCommand,
	};
	enum EStuntFigure {
		None,
		StraightJump,
		Flip,
		BackFlip,
		Spin,
		Aerial,
		AlleyOop,
		Roll,
		Corkscrew,
		SpinOff,
		Rodeo,
		FlipFlap,
		Twister,
		FreeStyle,
		SpinningMix,
		FlippingChaos,
		RollingMadness,
		WreckNone,
		WreckStraightJump,
		WreckFlip,
		WreckBackFlip,
		WreckSpin,
		WreckAerial,
		WreckAlleyOop,
		WreckRoll,
		WreckCorkscrew,
		WreckSpinOff,
		WreckRodeo,
		WreckFlipFlap,
		WreckTwister,
		WreckFreeStyle,
		WreckSpinningMix,
		WreckFlippingChaos,
		WreckRollingMadness,
		TimePenalty,
		RespawnPenalty,
		Grind,
		Reset,
	};
/*!

*/
	const	EType Type;
/*!

*/
	const	CTmPlayer Player;
/*!

*/
			Integer RaceTime;
/*!

*/
	const	Integer CheckpointInRace;
/*!

*/
	const	Integer CheckpointInLap;
/*!

*/
	const	Boolean IsEndLap;
/*!

*/
	const	Boolean IsEndRace;
/*!

*/
			Integer LapTime;
/*!

*/
			Integer StuntsScore;
/*!

*/
			Integer NbRespawns;
/*!

*/
	const	Ident BlockId;
/*!

*/
			Real Speed;
/*!

*/
			Real Distance;
/*!

*/
			Real Damages;
/*!

*/
	const	EStuntFigure StuntFigure;
/*!

*/
	const	Integer Angle;
/*!

*/
	const	Integer Points;
/*!

*/
	const	Integer Combo;
/*!

*/
	const	Boolean IsStraight;
/*!

*/
	const	Boolean IsReverse;
/*!

*/
	const	Boolean IsMasterJump;
/*!

*/
	const	Real Factor;
/*!

*/
	const	CUser User;
/*!

*/
	const	Boolean PlayerWasSpawned;
/*!

*/
	const	Boolean PlayerWasInLadderMatch;
/*!

*/
	const	Text CommandName;
/*!

*/
	const	Boolean CommandValueBoolean;
/*!

*/
	const	Integer CommandValueInteger;
/*!

*/
	const	Real CommandValueReal;
/*!

*/
	const	Text CommandValueText;
};

/*!
Supported declare modes : Local 
Manialink control.
*/
struct CMlFrame : public CMlControl {
	enum EControlType {
		Audio,
		Entry,
		FileEntry,
		Frame,
		Label,
		Quad,
		Video,
	};
/*!

*/
	const	CMlControl[] Controls;
/*!

*/
			CMlControl GetFirstChild(Text ControlId);
/*!

*/
			Boolean ClipWindowActive;
/*!

*/
			Vec2 ClipWindowRelativePosition;
/*!

*/
			Vec2 ClipWindowSize;
};

/*!

*/
struct CXmlDocument : public CNod {
/*!

*/
	const	Text TextContents;
/*!

*/
	const	CXmlNode Root;
/*!

*/
	const	CXmlNode[] Nodes;
/*!

*/
			CXmlNode GetFirstChild(Text Name);
};

/*!
Supported declare modes : Local 
An HTTP request.
*/
struct CHttpRequest : public CNod {
/*!
Url of the request
*/
	const	Text Url;
/*!
Result available once IsCompleted and StatusCode = 200
*/
	const	Text Result;
/*!
HTTP status code
*/
	const	Integer StatusCode;
/*!

*/
	const	Boolean IsCompleted;
};

/*!

*/
struct CAudioSound : public CNod {
/*!

*/
			Void Play();
/*!

*/
			Void Stop();
/*!

*/
	const	Boolean IsPlaying;
/*!

*/
	const	Boolean DownloadInProgress;
/*!

*/
			Real Volume;
/*!

*/
			Real VolumedB;
/*!

*/
			Real Pitch;
/*!

*/
			Vec3 RelativePosition;
/*!

*/
			Real PlayCursor;
/*!

*/
	const	Real PlayLength;
};

/*!

*/
struct CMapInfo : public CNod {
/*!

*/
	const	Ident MapUid;
/*!

*/
	const	Text Comments;
/*!

*/
	const	Integer CopperPrice;
/*!

*/
	const	Text CollectionName;
/*!

*/
	const	Text AuthorLogin;
/*!

*/
	const	Text AuthorNickName;
/*!

*/
	const	Text AuthorZonePath;
/*!

*/
	const	Text MapType;
/*!

*/
	const	Text MapStyle;
/*!

*/
	const	Boolean Unlocked;
/*!

*/
	const	Text Name;
/*!

*/
	const	Text Path;
};

/*!

*/
struct CCollector : public CNod {
/*!

*/
	const	Text Name;
/*!

*/
			Text PageName;
};

/*!

*/
struct CBlockModelVariantGround : public CBlockModelVariant {
	enum EnumAutoTerrainPlaceType {
		Auto,
		Force,
		DoNotPlace,
		DoNotDestroy,
	};
};

/*!

*/
struct CBlockModelVariantAir : public CBlockModelVariant {
};

/*!

*/
struct CBlockUnit : public CNod {
/*!

*/
	const	Int3 Offset;
/*!

*/
	const	CBlockUnitModel BlockUnitModel;
/*!

*/
	const	CBlock Block;
};

/*!
Supported declare modes : Local  NetworkRead  NetworkWrite 

*/
struct CTeam : public CNod {
/*!

*/
			Text Name;
/*!

*/
			Text ZonePath;
/*!

*/
			Text City;
/*!

*/
			Text EmblemUrl;
/*!

*/
			Text PresentationManialinkUrl;
/*!

*/
			Text ClubLinkUrl;
/*!

*/
			Vec3 ColorPrimary;
/*!

*/
			Vec3 ColorSecondary;
/*!

*/
	const	Text ColorText;
/*!

*/
	const	Text ColorizedName;
};

/*!

*/
struct CUIConfigMgr : public CNod {
/*!

*/
			Void ResetAll();
/*!

*/
	const	CUIConfig UIAll;
/*!

*/
	const	CUIConfig[] UI;
/*!

*/
			CUIConfig GetUI(CPlayer Player);
/*!

*/
			CUIConfig GetUI(CUser User);
/*!

*/
	const	CUILayer[] UILayers;
/*!

*/
			CUILayer UILayerCreate();
/*!

*/
			Void UILayerDestroy(CUILayer Layer);
/*!

*/
			Void UILayerDestroyAll();
/*!

*/
	const	CUILayer[] UIReplayLayers;
/*!

*/
			Integer UISequenceMaxDuration;
};

/*!
Supported declare modes : Local  NetworkRead  NetworkWrite 

*/
struct CXmlRpc : public CNod {
/*!

*/
	const	CXmlRpcEvent[] PendingEvents;
/*!

*/
			Void SendCallback(Text Param1,Text Param2);
/*!

*/
			Void SendCallbackArray(Text Type,Text[] Data);
/*!

*/
			Void SendCallback_BeginRound();
/*!

*/
			Void SendCallback_EndRound();
};

/*!
Supported declare modes : Local  NetworkRead  NetworkWrite 

*/
struct CPlayer : public CNod {
/*!

*/
	const	CUser User;
/*!

*/
	const	Text Login;
/*!

*/
	const	Text Name;
/*!

*/
	const	Integer RequestedClan;
/*!

*/
	const	Boolean RequestsSpectate;
};

/*!

*/
struct CSmPlayerDriver : public CNod {
	enum ESmDriverBehaviour {
		Static,
		Turret,
		Scripted,
		IA,
		Patrol,
		Escape,
		Saunter,
	};
	enum ESmDriverPatrolMode {
		OneTrip,
		BackAndForth,
		Loop,
	};
	enum ESmAttackFilter {
		All,
		AllPlayers,
		AllBots,
		AllOpposite,
		OppositePlayers,
		OppositeBots,
		Nobody,
	};
/*!

*/
			ESmDriverBehaviour Behaviour;
/*!

*/
			Real AggroRadius;
/*!

*/
			Real DisengageDistance;
/*!

*/
			Real PathSpeedCoef;
/*!

*/
			Real Accuracy;
/*!

*/
			Integer ReactionTime;
/*!

*/
			Integer ShootPeriodMin;
/*!

*/
			Integer ShootPeriodMax;
/*!

*/
			Boolean RocketAnticipation;
/*!

*/
			Real Fov;
/*!

*/
			ESmAttackFilter AttackFilter;
/*!

*/
	const	CSmPlayer Target;
/*!

*/
	const	Boolean IsStuck;
/*!

*/
			Boolean IsFlying;
/*!

*/
			Integer PathOffset;
/*!

*/
			Real Agressivity;
/*!

*/
			Boolean UseOldShootingSystem;
/*!

*/
			ESmDriverPatrolMode Patrol_Mode;
/*!

*/
			Vec3 Escape_AnchorPoint;
/*!

*/
			Real Escape_DistanceSafe;
/*!

*/
			Real Escape_DistanceMinEscape;
/*!

*/
			Real Escape_DistanceMaxEscape;
/*!

*/
			Vec3 Saunter_AnchorPoint;
/*!

*/
			Integer Saunter_BaseChillingTime;
/*!

*/
			Integer Saunter_ChillingTimeDelta;
/*!

*/
			Real Saunter_Radius;
/*!

*/
			Boolean Scripted_ForceAimInMoveDir;
/*!

*/
			CSmPlayer ForcedTarget;
/*!

*/
			CSmPlayer[] TargetsToAvoid;
};

/*!

*/
struct CSmMapSector : public CNod {
/*!

*/
	const	Ident[] PlayersIds;
};

/*!
Supported declare modes : Local  Metadata 

*/
struct CSmBlockPole : public CSmBlock {
/*!

*/
			Boolean Captured;
/*!

*/
	const	CSmSector Sector;
/*!

*/
	const	CSmGauge Gauge;
};

/*!

*/
struct CSmMapGate : public CNod {
/*!

*/
			Integer Clan;
/*!

*/
			Boolean Automatic;
/*!

*/
			Boolean ManualClosed;
/*!

*/
	const	Boolean AutoClosed;
/*!

*/
			Boolean AutoIsActive;
/*!

*/
			Integer AutoCloseDelay;
/*!

*/
			Integer AutoOpenSpeed;
};

/*!

*/
struct CSmMapGauge : public CNod {
/*!

*/
			Integer Clan;
/*!
Values in range (0.000000-1.000000)
*/
			Real ValueReal;
/*!

*/
			Integer Value;
/*!

*/
			Integer Max;
/*!

*/
			Integer Speed;
/*!

*/
			Boolean Captured;
};

/*!

*/
struct CSmMapPlayerSpawn : public CNod {
};

/*!

*/
struct CSmMapBotPath : public CNod {
/*!

*/
	const	Integer Clan;
/*!

*/
	const	Vec3[] Path;
/*!

*/
	const	Boolean IsFlying;
};

/*!

*/
struct CSmMapObjectAnchor : public CNod {
/*!

*/
	const	Text ItemName;
/*!

*/
	const	Ident ItemModelId;
};

/*!
Supported declare modes : Local  NetworkRead  NetworkWrite 

*/
struct CScore : public CNod {
/*!

*/
	const	CUser User;
/*!

*/
	const	Boolean IsRegisteredForLadderMatch;
/*!

*/
	const	Real LadderScore;
/*!

*/
			Integer LadderRankSortValue;
/*!

*/
			Real LadderMatchScoreValue;
/*!

*/
			Integer LadderClan;
};

/*!
Supported declare modes : Local  NetworkRead  NetworkWrite 
This object handles the interface.
*/
struct CUIConfig : public CNod {
	enum EUISequence {
		None,
		Playing,
		Intro,
		Outro,
		Podium,
		CustomMTClip,
		EndRound,
		PlayersPresentation,
		UIInteraction,
		RollingBackgroundIntro,
		CustomMTClip_WithUIInteraction,
	};
	enum EUIStatus {
		None,
		Normal,
		Warning,
		Error,
		Official,
	};
	enum EVisibility {
		None,
		Normal,
		Manual,
		ForcedHidden,
		ForcedVisible,
	};
	enum ELabelsVisibility {
		None,
		Never,
		Always,
		WhenInFrustum,
		WhenVisible,
		WhenInMiddleOfScreen,
	};
	enum EAvatarVariant {
		Default,
		Sad,
		Happy,
	};
	enum EUISound {
		Default,
		Silence,
		StartMatch,
		EndMatch,
		StartRound,
		EndRound,
		PhaseChange,
		TieBreakPoint,
		TiePoint,
		VictoryPoint,
		Capture,
		TimeOut,
		Notice,
		Warning,
		PlayerEliminated,
		PlayerHit,
		Checkpoint,
		Finish,
		Record,
		ScoreProgress,
		RankChange,
		Bonus,
		FirstHit,
		Combo,
		PlayersRemaining,
		Custom1,
		Custom2,
		Custom3,
		Custom4,
	};
	enum ENoticeLevel {
		Default,
		PlayerInfo,
		PlayerWarning,
		MapInfo,
		MapWarning,
		MatchInfo,
		MatchWarning,
	};
	enum EObserverMode {
		Default,
		Forced,
		Forbidden,
		Manual,
	};
/*!

*/
			EUISequence UISequence;
/*!

*/
	const	Boolean UISequenceIsCompleted;
/*!

*/
			Text UISequence_CustomMTClip;
/*!

*/
			Integer UISequence_CustomMTRefTime;
/*!

*/
			Boolean UISequence_CanSkipIntroMT;
/*!

*/
			Text UISequence_PodiumPlayersWin;
/*!

*/
			Text UISequence_PodiumPlayersLose;
/*!

*/
			Text ManialinkPage;
/*!

*/
			Text BigMessage;
/*!

*/
			Text BigMessageAvatarLogin;
/*!

*/
			EAvatarVariant BigMessageAvatarVariant;
/*!

*/
			EUISound BigMessageSound;
/*!

*/
			Integer BigMessageSoundVariant;
/*!

*/
			Text StatusMessage;
/*!

*/
			Text GaugeMessage;
/*!

*/
			Real GaugeRatio;
/*!

*/
			Integer GaugeClan;
/*!
An XML text describing the map tooltips appearing in the HUD.<br/>It's a set of &lt;marker/&gt; elements which can have the following attributes : <ol><li>label : a text to display</li><li>pos : a vector of 3 world coordinates desribing the position of the marker</li><li>playerlogin : alternatively, instead of using pos, you can use a player login. The marker will smoothly follow the player</li><li>playerid : similar to playerlogin. Fill it with Player.Id. The marker will smoothly follow the player</li><li>box : a vector of 3 dimensions describing the size of the marked object (allows a better placement of the marker on the screen)</li><li>gauge : a Real. If between 0. and 1. a gauge will be shown undeneath the text</li><li>imageurl : a string. URL of an image to use</li><li>distmax : a real. The marker will disappear if the dist to it is greater than distmax</li><li>isturning : a bool. Only for markers attached to players. If the marker appear on a minimap, it will turn around to reflect the player orientation.</li></ol>
*/
			Text MarkersXML;
/*!

*/
	const	CUILayer[] UILayers;
/*!

*/
			Boolean OverlayHideNotices;
/*!

*/
			Boolean OverlayHideMapInfo;
/*!

*/
			Boolean OverlayHideOpponentsInfo;
/*!

*/
			Boolean OverlayHideChat;
/*!

*/
			Boolean OverlayHideCheckPointList;
/*!

*/
			Boolean OverlayHideRoundScores;
/*!

*/
			Boolean OverlayHideCountdown;
/*!

*/
			Boolean OverlayHideCrosshair;
/*!

*/
			Boolean OverlayHideGauges;
/*!

*/
			Boolean OverlayHideConsumables;
/*!

*/
			Boolean OverlayHide321Go;
/*!

*/
			Boolean OverlayHideBackground;
/*!

*/
			Boolean OverlayHideChrono;
/*!

*/
			Boolean OverlayHideSpeedAndDist;
/*!

*/
			Boolean OverlayHidePersonnalBestAndRank;
/*!

*/
			Boolean OverlayHidePosition;
/*!

*/
			Boolean OverlayHideCheckPointTime;
/*!

*/
			Boolean OverlayHideEndMapLadderRecap;
/*!

*/
			Boolean OverlayHideMultilapInfos;
/*!

*/
			Boolean OverlayHideSpectatorControllers;
/*!

*/
			Boolean OverlayHideSpectatorInfos;
/*!

*/
			Boolean OverlayChatHideAvatar;
/*!
Values in range (0 - 40)
*/
			Integer OverlayChatLineCount;
/*!

*/
			Vec2 OverlayChatOffset;
/*!

*/
			Vec2 CountdownCoord;
/*!

*/
			Boolean NoticesFilter_HidePlayerInfo;
/*!

*/
			Boolean NoticesFilter_HidePlayerWarning;
/*!

*/
			Boolean NoticesFilter_HidePlayerInfoIfNotMe;
/*!

*/
			Boolean NoticesFilter_HidePlayerWarningIfNotMe;
/*!

*/
			Boolean NoticesFilter_HideMapInfo;
/*!

*/
			Boolean NoticesFilter_HideMapWarning;
/*!

*/
			Boolean NoticesFilter_HideMatchInfo;
/*!

*/
			Boolean NoticesFilter_HideMatchWarning;
/*!

*/
			ENoticeLevel NoticesFilter_LevelToShowAsBigMessage;
/*!

*/
			Text ScoreTable;
/*!

*/
			EVisibility ScoreTableVisibility;
/*!

*/
			Text SmallScoreTable;
/*!

*/
			EVisibility SmallScoreTableVisibility;
/*!

*/
			Boolean ScoreTableOnlyManialink;
/*!

*/
			Boolean AltMenuNoDefaultScores;
/*!

*/
			Boolean AltMenuNoCustomScores;
/*!

*/
			Boolean OverlayScoreSummary;
/*!

*/
			Ident ScoreSummary_Player1;
/*!

*/
			Integer ScoreSummary_Points1;
/*!

*/
			Integer ScoreSummary_RoundPoints1;
/*!

*/
			Integer ScoreSummary_MatchPoints1;
/*!

*/
			Real ScoreSummary_Gauge1;
/*!

*/
			Ident ScoreSummary_Player2;
/*!

*/
			Integer ScoreSummary_Points2;
/*!

*/
			Integer ScoreSummary_RoundPoints2;
/*!

*/
			Integer ScoreSummary_MatchPoints2;
/*!

*/
			Real ScoreSummary_Gauge2;
/*!

*/
			Boolean ScreenIn3dHideScoreSummary;
/*!

*/
			Boolean ScreenIn3dHideVersus;
/*!

*/
			Integer CountdownEndTime;
/*!

*/
			EUIStatus UIStatus;
/*!

*/
			ELabelsVisibility AlliesLabelsVisibility;
/*!

*/
			EVisibility AlliesLabelsShowGauges;
/*!

*/
			EVisibility AlliesLabelsShowNames;
/*!
Values in range (0 - 250)
*/
			Integer AlliesLabelsMaxCount;
/*!

*/
			ELabelsVisibility TeamLabelsVisibility;
/*!

*/
			EVisibility TeamLabelsShowGauges;
/*!

*/
			EVisibility TeamLabelsShowNames;
/*!

*/
			ELabelsVisibility OpposingTeamLabelsVisibility;
/*!

*/
			EVisibility OpposingTeamLabelsShowGauges;
/*!

*/
			EVisibility OpposingTeamLabelsShowNames;
/*!

*/
			Boolean ForceSpectator;
/*!

*/
			Integer SpectatorForceCameraType;
/*!

*/
			Ident SpectatorAutoTarget;
/*!

*/
			Ident SpectatorForcedTarget;
/*!

*/
			Integer SpectatorForcedClan;
/*!

*/
			Real SpectatorCamAutoLatitude;
/*!

*/
			Real SpectatorCamAutoLongitude;
/*!

*/
			Real SpectatorCamAutoRadius;
/*!

*/
			EObserverMode SpectatorObserverMode;
/*!

*/
			Void SendChat(Text Text);
/*!

*/
			Void SendNotice(Text Text,ENoticeLevel Level,CUser Avatar,EAvatarVariant AvatarVariant,EUISound Sound,Integer SoundVariant);
/*!

*/
			Text GetLayerManialinkAction(CUILayer Layer);
/*!

*/
			Void ClearLayerManialinkAction(CUILayer Layer);
};

/*!
Supported declare modes : Local  NetworkRead  NetworkWrite 

*/
struct CTrackManiaScore : public CTmScore {
};

/*!

*/
struct CTmResult : public CNod {
	enum ETmRaceResultCriteria {
		Time,
		Stunts,
		NbRespawns,
		CheckpointsProgress,
		None,
	};
/*!

*/
			Integer Time;
/*!

*/
			Integer StuntsScore;
/*!

*/
			Integer NbRespawns;
/*!

*/
			Integer[] Checkpoints;
/*!

*/
			Integer Compare(CTmResult Other,ETmRaceResultCriteria Criteria);
};

/*!

*/
struct CXmlNode : public CNod {
/*!

*/
	const	Text Name;
/*!

*/
	const	Text TextContents;
/*!

*/
	const	Text TextRawContents;
/*!

*/
	const	Text TextRecursiveContents;
/*!

*/
	const	CXmlNode[] Children;
/*!

*/
			Text GetAttributeText(Text Name,Text DefaultValue);
/*!

*/
			Integer GetAttributeInteger(Text Name,Integer DefaultValue);
/*!

*/
			Real GetAttributeReal(Text Name,Real DefaultValue);
/*!

*/
			Boolean GetAttributeBoolean(Text Name,Boolean DefaultValue);
/*!

*/
			CXmlNode GetFirstChild(Text Name);
};

/*!

*/
struct CBlockModelVariant : public CNod {
/*!

*/
			Text Name;
/*!

*/
	const	Boolean IsAllUnderground;
/*!

*/
	const	Boolean IsPartUnderground;
/*!

*/
	const	Int3 Size;
/*!

*/
	const	Int3 OffsetBoundingBoxMin;
/*!

*/
	const	Int3 OffsetBoundingBoxMax;
/*!

*/
			CBlockUnitModel[] BlockUnitModels;
};

/*!

*/
struct CBlockUnitModel : public CNod {
	enum CardinalDirEnum {
		North,
		East,
		South,
		West,
	};
	enum MultiDirEnum {
		SameDir,
		SymmetricalDirs,
		AllDir,
		OpposedDirOnly,
		PerpendicularDirsOnly,
		NextDirOnly,
		PreviousDirOnly,
	};
/*!

*/
	const	Int3 Offset;
/*!

*/
	const	CBlockModelClip[] Clips;
};

/*!

*/
struct CXmlRpcEvent : public CNod {
	enum EType {
		Unknown,
		Callback,
		CallbackArray,
	};
/*!

*/
	const	EType Type;
/*!

*/
	const	Text Param1;
/*!

*/
	const	Text Param2;
/*!

*/
	const	Text ParamArray1;
/*!

*/
	const	Text[] ParamArray2;
};

/*!
Supported declare modes : Local  Metadata 

*/
struct CSmBlock : public CSmLandmark {
/*!

*/
	const	CSmBase Base;
};

/*!

*/
struct CSmSector : public CNod {
/*!

*/
	const	Ident[] PlayersIds;
};

/*!

*/
struct CSmGauge : public CNod {
/*!

*/
			Integer Clan;
/*!
Values in range (0.000000-1.000000)
*/
			Real ValueReal;
/*!

*/
			Integer Value;
/*!

*/
			Integer Max;
/*!

*/
			Integer Speed;
};

/*!
The model of a map block
*/
struct CBlockModelClip : public CBlockModel {
	enum EnumClipType {
		ClassicClip,
		FreeClipSide,
		FreeClipTop,
		FreeClipBottom,
	};
	enum MultiDirEnum {
		SameDir,
		SymmetricalDirs,
		AllDir,
		OpposedDirOnly,
		PerpendicularDirsOnly,
		NextDirOnly,
		PreviousDirOnly,
	};
};

/*!
Supported declare modes : Local  Metadata 

*/
struct CSmLandmark : public CNod {
/*!

*/
	const	Text Tag;
/*!

*/
	const	Integer Order;
/*!

*/
	const	Vec3 Position;
/*!

*/
	const	Vec3 DirFront;
};

/*!

*/
struct CSmBase : public CNod {
/*!

*/
			Integer Clan;
/*!

*/
			Boolean IsActive;
/*!

*/
	const	Integer NumberOfCollectors;
};

namespace MathLib {

	/*! 
	*
	*/
	Integer Abs(Integer Argument1);
	/*! 
	*
	*/
	Real Abs(Real Argument1);
	/*! 
	*
	*/
	Real ToReal(Integer Argument1);
	/*! 
	*
	*/
	Real Sin(Real Argument1);
	/*! 
	*
	*/
	Real Cos(Real Argument1);
	/*! 
	*
	*/
	Real Tan(Real Argument1);
	/*! 
	*
	*/
	Real Atan2(Real Argument1, Real Argument2);
	/*! 
	*
	*/
	Real Exp(Real Argument1);
	/*! 
	*
	*/
	Real Rand(Real Argument1, Real Argument2);
	/*! 
	*
	*/
	Integer Rand(Integer Argument1, Integer Argument2);
	/*! 
	*
	*/
	Real NearestReal(Integer Argument1);
	/*! 
	*
	*/
	Integer NearestInteger(Real Argument1);
	/*! 
	*
	*/
	Integer FloorInteger(Real Argument1);
	/*! 
	*
	*/
	Integer CeilingInteger(Real Argument1);
	/*! 
	*
	*/
	Real Distance(Vec3 Argument1, Vec3 Argument2);
	/*! 
	*
	*/
	Real DotProduct(Vec3 Argument1, Vec3 Argument2);
	/*! 
	*
	*/
	Vec3 CrossProduct(Vec3 Argument1, Vec3 Argument2);
	/*! 
	*
	*/
	Real Angle(Vec3 Argument1, Vec3 Argument2);
	/*! 
	*
	*/
	Real OrientedAngle(Vec3 Argument1, Vec3 Argument2);
	/*! 
	*
	*/
	Real PI();
	/*! 
	*
	*/
	Real Asin(Real Argument1);
	/*! 
	*
	*/
	Real Acos(Real Argument1);
	/*! 
	*
	*/
	Real Pow(Real Argument1, Real Argument2);
	/*! 
	*
	*/
	Real Ln(Real Argument1);
	/*! 
	*
	*/
	Real Sqrt(Real Argument1);
	/*! 
	* \brief Returns the maximum between A and B
	* 
	*
	*/
	Integer Max(Integer _A, Integer _B);
	/*! 
	* \brief Returns the minimum between A and B
	* 
	*
	*/
	Integer Min(Integer _A, Integer _B);
	/*! 
	* \brief Returns the value X clamped to the range Min..Max
	* 
	*
	*/
	Integer Clamp(Integer _X, Integer _Min, Integer _Max);
	/*! 
	* \brief Returns the maximum between A and B
	* 
	*
	*/
	Real Max(Real _A, Real _B);
	/*! 
	* \brief Returns the minimum between A and B
	* 
	*
	*/
	Real Min(Real _A, Real _B);
	/*! 
	* \brief Returns the value X clamped to the range Min..Max
	* 
	*
	*/
	Real Clamp(Real _X, Real _Min, Real _Max);
};

namespace TextLib {

	/*! 
	* \brief Returns the Real corresponding to _Text
	* 
	* Returns -1 if an invalid Text is given
	* \param _Text : The text you want to convert into a Real
	*
	*/
	Real ToReal(Text _Text);
	/*! 
	* \brief Returns the Integer corresponding to _Text
	* 
	* Returns -1 if an invalid Text is given
	* \param _Text : The text you want to convert into an Integer
	*
	*/
	Integer ToInteger(Text _Text);
	/*! 
	* \brief Returns the RGB color corresponding to _Text
	* 
	* Returns an empty Vec3 if an invalid Text is given
	* \param _Text : The text you want to convert into a RGB color
	*
	*/
	Vec3 ToColor(Text _Text);
	/*! 
	* \brief Returns a substring of _Text
	* 
	* Returns the substring of _Text beginning at the _Start index, with a length of _Length chars 
	* Returns an empty Text if _Start > Text.Length or _Length == 0
	* \param _Text : The text in which we look for the substring
	* \param _Start : The beginning index of the substring
	* \param _Length : The length of the substring
	*
	*/
	Text SubString(Text _Text, Integer _Start, Integer _Length);
	/*! 
	* \brief Returns a substring of _Text
	* 
	* Returns the substring of _Text beginning at the _Start index, with a length of _Length chars 
	* Returns an empty Text if _Start > Text.Length or _Length == 0
	* \param _Text : The text in which we look for the substring
	* \param _Start : The beginning index of the substring
	* \param _Length : The length of the substring
	*
	*/
	Text SubText(Text _Text, Integer _Start, Integer _Length);
	/*! 
	* \brief Returns the length of _Text
	* 
	* \param _Text : The text you want the length
	*
	*/
	Integer Length(Text _Text);
	/*! 
	* \brief Returns the Text corresponding to _Integer
	* 
	* \param _Integer : The Integer you want to convert
	*
	*/
	Text ToText(Integer _Integer);
	/*! 
	* \brief Returns the Text corresponding to _Real
	* 
	* \param _Real : The Real you want to convert
	*
	*/
	Text ToText(Real _Real);
	/*! 
	* \brief Returns the Text corresponding to _Boolean
	* 
	* \param _Boolean : The Boolean you want to convert
	*
	*/
	Text ToText(Boolean _Boolean);
	/*! 
	* \brief Returns the Text corresponding to _Int3
	* 
	* \param _Int3 : The Int3 you want to convert
	*
	*/
	Text ToText(Int3 _Int3);
	/*! 
	* \brief Returns the Text corresponding to _Vec3
	* 
	* \param _Vec3 : The Vec3 you want to convert
	*
	*/
	Text ToText(Vec3 _Vec3);
	/*! 
	* \brief Returns the Text corresponding to _Time
	* 
	* Converts a _Time Integer to a Text with the following format : 
	*  - MmSsCc if IncludeCentiSeconds is set to true 
	* - MmSs if IncludeCentiSeconds is set to false
	* \param _Time : The time you want to convert into a Text
	* \param _IncludeCentiSeconds : Set IncludeCentiSeconds to True if you wants the CentiSeconds to be displayed in the returned Text
	*
	*/
	Text TimeToText(Integer _Time, Boolean _IncludeCentiSeconds);
	/*! 
	* \brief Returns the Text corresponding to _Time
	* 
	* Converts the _Time Integer to a Text with the following format : MmSs
	* \param _Time : The time you want to convert into a Text
	*
	*/
	Text TimeToText(Integer _Time);
	/*! 
	* \brief Returns the Text corresponding to _Color
	* 
	* \param _Color : The color you want to convert into a text
	*
	*/
	Text ColorToText(Vec3 _Color);
	/*! 
	*
	*/
	Text FormatInteger(Integer Argument1, Integer Argument2);
	/*! 
	* \brief Returns the Text corresponding to a Real. With formatting
	* 
	* \param _Value : The Real value you want to convert
	* \param _FPartLength : The number of digits you want for the FPart
	* \param _HideZeroes : Hide trailing zeroes
	* \param _HideDot : Hide trailing dot if there is nothing after it
	*
	*/
	Text FormatReal(Real _Value, Integer _FPartLength, Boolean _HideZeroes, Boolean _HideDot);
	/*! 
	* \brief Changes lower case characters to upper case characters
	* 
	*
	*/
	Text ToUpperCase(Text _TextToChange);
	/*! 
	* \brief Changes upper case characters to lower case characters
	* 
	*
	*/
	Text ToLowerCase(Text _TextToChange);
	/*! 
	* \brief Compares texts without taking format characters in account.
	* 
	* Returns True if Text1 and Text2 are equal. 
	* Format differences are not taken into account. 
	* Case differences are taken into account if IsCaseSensitive is set to True.
	*
	*/
	Boolean CompareWithoutFormat(Text _Text1, Text _Text2, Boolean _IsCaseSensitive);
	/*! 
	* \brief Returns True if the searched text is found in the text to search in.
	* 
	* Format is not taken into account if IsFormatSensitive is set to False. 
	* Case is not taken into account if IsCaseSensitive is set to False.
	* \param _TextToFind : The text you are looking for
	* \param _TextToSearchIn : The text you are searching in
	* \param _IsFormatSensitive : True if you want to take Format into account, False elseway
	* \param _IsCaseSensitive : True if you want to take Case into account, False elseway
	*
	*/
	Boolean Find(Text _TextToFind, Text _TextToSearchIn, Boolean _IsFormatSensitive, Boolean _IsCaseSensitive);
	/*! 
	*
	*/
	Text Compose(Text Argument1);
	/*! 
	*
	*/
	Text Compose(Text Argument1, Text Argument2);
	/*! 
	*
	*/
	Text Compose(Text Argument1, Text Argument2, Text Argument3);
	/*! 
	*
	*/
	Text Compose(Text Argument1, Text Argument2, Text Argument3, Text Argument4);
	/*! 
	*
	*/
	Text Compose(Text Argument1, Text Argument2, Text Argument3, Text Argument4, Text Argument5);
	/*! 
	*
	*/
	Text Compose(Text Argument1, Text Argument2, Text Argument3, Text Argument4, Text Argument5, Text Argument6);
	/*! 
	*
	*/
	Text MLEncode(Text Argument1);
	/*! 
	*
	*/
	Text URLEncode(Text Argument1);
	/*! 
	*
	*/
	Text StripFormatting(Text Argument1);
	/*! 
	*
	*/
	Text[Void] Split(Text Argument1, Text Argument2);
	/*! 
	*
	*/
	Text Join(Text Argument1, Text[Void] Argument2);
	/*! 
	*
	*/
	Text SmartSplit(Text Argument1, Integer Argument2, Integer Argument3, Integer Argument4);
	/*! 
	*
	*/
	Text Trim(Text Argument1);
	/*! 
	*
	*/
	Text ReplaceChars(Text Argument1, Text Argument2, Text Argument3);
	/*! 
	* \brief Replaces occurences of _ToReplace in _Text with _Replacement
	* 
	* \param _Text : The text you search in
	* \param _ToReplace : The text you want to replace
	* \param _Replacement : The text you want to insert
	*
	*/
	Text Replace(Text _Text, Text _ToReplace, Text _Replacement);
	/*! 
	* \brief Lookup the text in the current translation dictionary.
	* 
	* Lookup the text in the current translation dictionary, and returns the translation, or returns the original text if not found.
	*
	*/
	Text GetTranslatedText(Text _Text);
};

namespace MapUnits {

	/*! 
	*
	*/
	CardinalDirections GetNextDir(CardinalDirections Argument1);
	/*! 
	*
	*/
	CardinalDirections GetPreviousDir(CardinalDirections Argument1);
	/*! 
	*
	*/
	CardinalDirections GetOpposedDir(CardinalDirections Argument1);
	/*! 
	*
	*/
	CardinalDirections AddDirs(CardinalDirections Argument1, CardinalDirections Argument2);
	/*! 
	*
	*/
	CardinalDirections SubDirs(CardinalDirections Argument1, CardinalDirections Argument2);
	/*! 
	*
	*/
	Int3 GetNeighbourCoord(Int3 Argument1, CardinalDirections Argument2);
	/*! 
	*
	*/
	Int3 GetRotatedOffset(Int3 Argument1, CardinalDirections Argument2);
	/*! 
	*
	*/
	Int3 GetRotatedOffsetPositive(Int3 Argument1, CardinalDirections Argument2, Int3 Argument3);
};

namespace AnimLib {

	/*! 
	* \brief Returns the value smoothly transitionning from 0 to 1
	* 
	*
	*/
	Real SmoothStep(Real _X);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using Robert Penner easing functions. Function must be one of:  "Linear", "QuadIn", "QuadOut", "QuadInOut", "CubicIn", "CubicOut", "CubicInOut", "QuartIn", "QuartOut", "QuartInOut", "QuintIn", "QuintOut", "QuintInOut", "SineIn", "SineOut", "SineInOut", "ExpIn", "ExpOut", "ExpInOut", "CircIn", "CircOut", "CircInOut", "BackIn", "BackOut", "BackInOut", "ElasticIn", "ElasticOut", "ElasticInOut", "ElasticIn2", "ElasticOut2", "ElasticInOut2", "BounceIn", "BounceOut", "BounceInOut"
	* 
	*
	*/
	Real Ease(Text _Function, Real _T, Real _Base, Real _Change, Real _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseLinear(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInQuad(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseOutQuad(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInOutQuad(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInCubic(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseOutCubic(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInOutCubic(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInQuart(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseOutQuart(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInOutQuart(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInQuint(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseOutQuint(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInOutQuint(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInSine(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseOutSine(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInOutSine(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInExp(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseOutExp(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInOutExp(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInCirc(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseOutCirc(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInOutCirc(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInBack(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseOutBack(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInOutBack(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInElastic(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseOutElastic(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInOutElastic(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInElastic2(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseOutElastic2(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInOutElastic2(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInBounce(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseOutBounce(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInOutBounce(Integer _T, Real _Base, Real _Change, Integer _Duration);
};

