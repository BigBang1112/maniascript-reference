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
	enum ESystemPlatform {
		None,
		Steam,
		UPlay,
		PS4,
		XBoxOne,
	};
	enum ESystemSkuIdentifier {
		Unknown,
		EU,
		US,
		JP,
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
	const	ESystemPlatform SystemPlatform;
/*!

*/
	const	ESystemSkuIdentifier SystemSkuIdentifier;
/*!

*/
	const	CMlEvent[] PendingEvents;
/*!

*/
			Void Dbg_SetProcessed(CMlEvent Event);
/*!

*/
			Boolean Dbg_WarnOnDroppedEvents;
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
	const	CVideoManager Video;
/*!

*/
	const	CAudioManager Audio;
/*!

*/
	const	CInputManager Input;
/*!

*/
	const	CDataMgr DataMgr;
/*!

*/
	const	CScoreMgr ScoreMgr;
/*!

*/
	const	CPrivilegeMgr PrivilegeMgr;
/*!

*/
	const	CPresenceMgr PresenceMgr;
/*!

*/
	const	CGamePluginInterfacesScript Plugins;
/*!
Send a custom event to the ManiaApp owning the layer, no-op otherwise.
*/
			Void SendCustomEvent(Text Type,Text[] Data);
/*!

*/
			Void PreloadImage(Text ImageUrl);
/*!

*/
			Void PreloadAll();
/*!

*/
			Text Dbg_DumpDeclareForVariables(CNod Nod,Boolean StatsOnly);
};

/*!
Supported declare modes : Local 
Manialink entry.
*/
struct CMlEntry : public CMlControl {
	enum ETextFormat {
		Basic,
		Script,
		Password,
		Newpassword,
	};
/*!

*/
			Text Value;
/*!

*/
			Void StartEdition();
/*!

*/
			ETextFormat TextFormat;
/*!

*/
			Real Opacity;
/*!

*/
			Vec3 TextColor;
/*!

*/
			Real TextSizeReal;
/*!

*/
			Integer MaxLine;
/*!

*/
			Boolean AutoNewLine;
};

/*!
Supported declare modes : Local 
Manialink entry.
*/
struct CMlFileEntry : public CMlEntry {
/*!

*/
	const	Text FullFileName;
};

/*!
Supported declare modes : Local 
Manialink entry.
*/
struct CMlTextEdit : public CMlControl {
	enum EControlScriptEditorTextFormat {
		Basic,
		Script,
		Password,
		Newpassword,
	};
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
/*!

*/
			Boolean ShowLineNumbers;
/*!

*/
			Real LineSpacing;
/*!

*/
	const	Integer ValueLineCount;
/*!

*/
			Real Opacity;
/*!

*/
			Vec3 TextColor;
/*!

*/
			Real TextSizeReal;
/*!

*/
			EControlScriptEditorTextFormat TextFormat;
};

/*!
Supported declare modes : Local 
Manialink entry.
*/
struct CMlLabel : public CMlControl {
	enum EBlendMode {
		Default,
		Add,
	};
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
			Real LineSpacing;
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
			Real TextSizeReal;
/*!

*/
			EBlendMode Blend;
/*!

*/
			Real ComputeWidth(Text Text);
/*!

*/
			Real ComputeWidth(Text Text,Boolean Translated);
/*!

*/
			Real ComputeHeight(Text Text);
};

/*!
Supported declare modes : Local 
Manialink control.
*/
struct CMlMediaPlayer : public CMlControl {
/*!

*/
			Boolean IsInitPlay;
/*!

*/
			Boolean Music;
/*!

*/
			Boolean IsLooping;
/*!

*/
			Real Volume;
/*!

*/
			Text Url;
/*!

*/
			Void Play();
/*!

*/
			Void Stop();
/*!

*/
			Void StopAndRewind();
};

/*!
Supported declare modes : Local 

*/
struct CMlQuad : public CMlControl {
	enum EKeepRatioMode {
		Inactive,
		Clip,
		Fit,
	};
	enum EBlendMode {
		Default,
		Add,
	};
/*!

*/
			Void ChangeImageUrl(Text fieldName);
/*!

*/
			CImage Image;
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
/*!

*/
			EBlendMode Blend;
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
/*!

*/
			Boolean Underground;
/*!

*/
			Void Fog_SetAll(Real Value);
/*!

*/
			Void Fog_ClearDisk(Vec3 WorldCenter,Real Radius,Real FadeSize);
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
	const	CManiaAppBrowser ParentApp;
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
API for Maniaplanet client scripts.
*/
struct CManiaApp : public CNod {
	enum ELinkType {
		ExternalBrowser,
		ManialinkBrowser,
	};
	enum EAnimManagerEasing {
		Linear,
		QuadIn,
		QuadOut,
		QuadInOut,
		CubicIn,
		CubicOut,
		CubicInOut,
		QuartIn,
		QuartOut,
		QuartInOut,
		QuintIn,
		QuintOut,
		QuintInOut,
		SineIn,
		SineOut,
		SineInOut,
		ExpIn,
		ExpOut,
		ExpInOut,
		CircIn,
		CircOut,
		CircInOut,
		BackIn,
		BackOut,
		BackInOut,
		ElasticIn,
		ElasticOut,
		ElasticInOut,
		ElasticIn2,
		ElasticOut2,
		ElasticInOut2,
		BounceIn,
		BounceOut,
		BounceInOut,
	};
	enum ESystemPlatform {
		None,
		Steam,
		UPlay,
		PS4,
		XBoxOne,
	};
	enum ESystemSkuIdentifier {
		Unknown,
		EU,
		US,
		JP,
	};
/*!

*/
	const	Integer Now;
/*!

*/
	const	Boolean IsVisible;
/*!

*/
	const	Integer CurrentDate;
/*!

*/
	const	Text CurrentLocalDateText;
/*!

*/
			Integer LayersDefaultManialinkVersion;
/*!

*/
	const	CUser LocalUser;
/*!

*/
	const	CTitle LoadedTitle;
/*!

*/
	const	ESystemPlatform SystemPlatform;
/*!

*/
	const	ESystemSkuIdentifier SystemSkuIdentifier;
/*!

*/
			Boolean EnableMenuNavigationInputs;
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
	const	CVideoManager Video;
/*!

*/
	const	CAudioManager Audio;
/*!

*/
	const	CInputManager Input;
/*!

*/
	const	CDataMgr DataMgr;
/*!

*/
	const	CScoreMgr ScoreMgr;
/*!

*/
	const	CPrivilegeMgr PrivilegeMgr;
/*!

*/
	const	CPresenceMgr PresenceMgr;
/*!

*/
	const	CGameUserManagerScript UserMgr;
/*!

*/
	const	CManiaPlanet ManiaPlanet;
/*!

*/
	const	CGamePluginInterfacesScript Plugins;
/*!

*/
			Text Dbg_DumpDeclareForVariables(CNod Nod,Boolean StatsOnly);
};

/*!
Supported declare modes : Local  Persistent 
This is the base Manialink page interface.
*/
struct CManiaAppTitleLayer : public CMlScript {
/*!

*/
			CManiaAppTitle ParentApp;
/*!

*/
	const	CTitleFlow TitleFlow;
};

/*!

*/
struct CManiaAppEvent : public CNod {
	enum EType {
		LayerCustomEvent,
		KeyPress,
		ExternalCustomEvent,
		MenuNavigation,
		ChildModuleEvent,
		ParentModuleEvent,
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
		AppMenu,
		Action1,
		Action2,
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
	const	CManiaApp ChildModuleEventModule;
/*!

*/
	const	Text ChildModuleEventType;
/*!

*/
	const	Text[] ChildModuleEventData;
/*!

*/
	const	Text ParentModuleEventType;
/*!

*/
	const	Text[] ParentModuleEventData;
/*!

*/
	const	EMenuNavAction MenuNavAction;
/*!

*/
	const	Boolean IsActionAutoRepeat;
/*!

*/
	const	Integer KeyCode;
/*!

*/
	const	Text KeyName;
};

/*!
Supported declare modes : Local  Persistent 
API for Maniaplanet client scripts.
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
/*!

*/
	const	CTitleFlow TitleFlow;
/*!

*/
	const	CGameScriptNotificationsConsumer Notifications;
/*!

*/
	const	Text ExternalRequest_Type;
/*!

*/
	const	Text[] ExternalRequest_Data;
/*!

*/
			Void ExternalRequest_Clear();
/*!

*/
	const	CGameAchievementScriptManager AchievementsManager;
/*!

*/
			CGameManagerBadgeScript BadgeManager;
};

/*!
Supported declare modes : Local  Persistent 
API for game interface client scripts
*/
struct CManiaAppPlayground : public CManiaAppPlaygroundCommon {
};

/*!

*/
struct CGamePlaygroundModuleServer : public CNod {
/*!

*/
			Void Hide();
/*!

*/
			Void Hide(CPlayer Player);
/*!

*/
			Void Show();
/*!

*/
			Void Show(CPlayer Player);
/*!

*/
			Boolean IsVisible(CPlayer Player);
};

/*!

*/
struct CGamePlaygroundModuleServerInventory : public CGamePlaygroundModuleServer {
/*!

*/
			Integer AddItem(CPlayer Player,Text ItemModelUrl,Integer Quantity);
/*!

*/
			Integer RemoveItem(CPlayer Player,Text ItemModelUrl,Integer Quantity);
/*!

*/
			Integer GetItemQuantity(CPlayer Player,Text ItemModelUrl);
/*!

*/
			Boolean AddAction(CPlayer Player,Text ActionModelUrl);
/*!

*/
			Boolean RemoveAction(CPlayer Player,Text ActionModelUrl);
/*!

*/
			Boolean IsActionStored(CPlayer Player,Text ActionModelUrl);
};

/*!

*/
struct CGamePlaygroundModuleServerStore : public CGamePlaygroundModuleServer {
/*!

*/
			Void Reset();
/*!

*/
			Void SetMoney(CPlayer Player,Integer Amount);
/*!

*/
			Integer GetMoney(CPlayer Player);
/*!

*/
			Boolean AddMoney(CPlayer Player,Integer Amount);
/*!

*/
			Boolean SubMoney(CPlayer Player,Integer Amount);
/*!

*/
			Void SetActionLevel(CPlayer Player,Text ActionUrl,Integer ActionLevel);
/*!

*/
			Integer GetActionLevel(CPlayer Player,Text ActionUrl);
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
API for the plugins of the map editor.
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
		Item,
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
	enum ShadowsQuality {
		NotComputed,
		VeryFast,
		Fast,
		Default,
		High,
		Ultra,
	};
	enum ValidationStatus {
		NotValidable,
		Validable,
		Validated,
	};
	enum EditorStatus {
		Running,
		ChallengeType,
		Objectives,
		ToPlayground,
		ChangeEditor,
		Save,
		SaveSameId,
		ToPlaygroundRecordPath,
		QuickSave,
		QuickLoad,
		EditToolsMenu,
		Quit,
		QuickQuit,
		ReplayRemoveAllKeys,
		ReplaySave,
		ReplayQuit,
		ToAnim,
		ToItem,
		ToEditor,
		ToLayer,
		EditSequences,
		QuickEditInGameClipGroup,
		ComputeShadows,
		ComputeShadowsFromScript,
		ShootVideo,
		ShootScreen,
		Preview,
		EditBlock,
		EditBlockQuit,
		AdditionalToolsMenu,
		RecordGhost,
		SaveMacroblock,
		EditCameraEffectScript,
		SaveFromScript,
		CreatePluginScript,
		EditPluginScript,
		EditMapTypeScript,
		ReloadMapTypeScript,
		EditClipConfigScript,
		ChooseMapType,
		ClipExport,
		ChooseBlockSkin,
		Count,
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
	const	Boolean IsEditorReadyForRequest;
/*!

*/
			Boolean HoldLoadingScreen;
/*!

*/
			Void ComputeShadows();
/*!

*/
			Void ComputeShadows(ShadowsQuality ShadowsQuality);
/*!

*/
	const	ShadowsQuality CurrentShadowsQuality;
/*!

*/
	const	Boolean IsUltraShadowsQualityAvailable;
/*!

*/
			Void Undo();
/*!

*/
			Void Redo();
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
			Void Quit();
/*!

*/
			Void QuickQuit();
/*!

*/
			Void QuitAndSetResult(Text Type,Text[] Data);
/*!

*/
			Void QuickQuitAndSetResult(Text Type,Text[] Data);
/*!

*/
			Void TestMapFromStart();
/*!

*/
			Void TestMapFromCoord(Int3 Coord,CardinalDirections Dir);
/*!
CAUTION: only in Turbo or developer build
*/
			Void TestMapFromCoordWithMapTypeScript(Int3 Coord,CardinalDirections Dir);
/*!

*/
			Void TestMapWithMode(Text RulesModeName);
/*!

*/
			Void SaveMap(Text FileName);
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
			Vec3 CameraTargetPosition;
/*!

*/
	const	Vec3 CameraPosition;
/*!

*/
			Real ThumbnailCameraVAngle;
/*!

*/
			Real ThumbnailCameraHAngle;
/*!

*/
			Real ThumbnailCameraRoll;
/*!

*/
			Real ThumbnailCameraFovY;
/*!

*/
			Vec3 ThumbnailCameraPosition;
/*!

*/
			Boolean GetRaceCamera(Vec3 Position,Real Yaw,Real Pitch,Real Roll,Real FovY);
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
			Void PreloadAllBlocks();
/*!

*/
			Void PreloadAllItems();
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
			Boolean CanPlaceMacroblock(CMacroblockModel MacroblockModel,Int3 Coord,CardinalDirections Dir);
/*!

*/
			Boolean PlaceMacroblock(CMacroblockModel MacroblockModel,Int3 Coord,CardinalDirections Dir);
/*!

*/
			Boolean CanPlaceMacroblock_NoDestruction(CMacroblockModel MacroblockModel,Int3 Coord,CardinalDirections Dir);
/*!

*/
			Boolean PlaceMacroblock_NoDestruction(CMacroblockModel MacroblockModel,Int3 Coord,CardinalDirections Dir);
/*!

*/
			Boolean CanPlaceMacroblock_NoTerrain(CMacroblockModel MacroblockModel,Int3 Coord,CardinalDirections Dir);
/*!

*/
			Boolean PlaceMacroblock_NoTerrain(CMacroblockModel MacroblockModel,Int3 Coord,CardinalDirections Dir);
/*!

*/
			Boolean RemoveMacroblock(CMacroblockModel MacroblockModel,Int3 Coord,CardinalDirections Dir);
/*!

*/
			Boolean RemoveMacroblock_NoTerrain(CMacroblockModel MacroblockModel,Int3 Coord,CardinalDirections Dir);
/*!

*/
			CBlock GetBlock(Int3 Coord);
/*!

*/
			Boolean IsBlockModelSkinnable(CBlockModel BlockModel);
/*!

*/
			Integer GetNbBlockModelSkins(CBlockModel BlockModel);
/*!

*/
			Text GetBlockModelSkinName(CBlockModel BlockModel,Integer SkinIndex);
/*!

*/
			Integer GetBlockSkinIndex(CBlock Block);
/*!

*/
			Void SetBlockSkinIndex(CBlock Block,Integer SkinIndex);
/*!

*/
			Boolean OpenBlockSkinDialog(CBlock Block);
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
			Integer GetGroundHeight(Integer CoordX,Integer CoordZ);
/*!

*/
			Int3 GetMouseCoordOnGround();
/*!

*/
			Int3 GetMouseCoordAtHeight(Integer CoordY);
/*!

*/
			CBlock GetStartLineBlock();
/*!

*/
			Boolean RemoveItem(CAnchorData Item);
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
			CMacroblockModel GetMacroblockModelFromFilePath(Text MacroblockModelFilePath);
/*!

*/
			CBlockModel GetTerrainBlockModelFromName(Text TerrainBlockModelName);
/*!

*/
			CBlockModel GetBlockModelFromName(Text BlockModelName);
/*!

*/
			Text GetMapStyle();
/*!

*/
			Void SetMapStyle(Text MapStyle);
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
			Boolean EnableCursorShowingWhenInterfaceIsFocused;
/*!

*/
			Boolean HideEditorInterface;
/*!

*/
			Boolean HideBlockHelpers;
/*!

*/
			Boolean ShowPlacementGrid;
/*!
CAUTION: only in Turbo or developer build
*/
			Boolean IsTrustedPlugin_DevBuild;
/*!
CAUTION: only in Turbo or developer build
*/
	const	EditorStatus EditorStatus;
/*!
CAUTION: only in Turbo or developer build
*/
			Boolean HideAlwaysCursorDirectionalArrow;
/*!
CAUTION: only in Turbo or developer build
*/
			Real CursorBrightnessFactor;
/*!
CAUTION: only in Turbo or developer build
*/
			Boolean EnableUnlimitedUndoHistory;
/*!
CAUTION: only in Turbo or developer build
*/
			Integer UndoHistorySize;
/*!
CAUTION: only in Turbo or developer build
*/
			Integer CoppersLimit;
/*!
CAUTION: only in Turbo or developer build
*/
			Boolean TurboClassicMapEditorMode;
/*!

*/
	const	Boolean EditorInputIsDown_Menu;
/*!

*/
	const	Boolean EditorInputIsDown_SwitchToRace;
/*!

*/
	const	Boolean EditorInputIsDown_Undo;
/*!

*/
	const	Boolean EditorInputIsDown_Redo;
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
	const	Boolean EditorInputIsDown_CameraZoomNext;
/*!

*/
	const	Boolean EditorInputIsDown_Camera0;
/*!

*/
	const	Boolean EditorInputIsDown_Camera1;
/*!

*/
	const	Boolean EditorInputIsDown_Camera3;
/*!

*/
	const	Boolean EditorInputIsDown_Camera7;
/*!

*/
	const	Boolean EditorInputIsDown_Camera9;
/*!

*/
	const	Boolean EditorInputIsDown_PivotChange;
/*!

*/
	const	Boolean EditorInputIsDown_CursorTurnSlightly;
/*!

*/
	const	Boolean EditorInputIsDown_CursorTurnSlightlyAntiClockwise;
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
	const	Boolean EditorInputIsDown_RemoveAll;
/*!

*/
	const	Boolean EditorInputIsDown_Save;
/*!

*/
	const	Boolean EditorInputIsDown_SaveAs;
/*!

*/
	const	Boolean EditorInputIsDown_MapStyle;
/*!

*/
	const	Boolean EditorInputIsDown_ClassicMapEditor;
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
	const	ValidationStatus ValidationStatus;
/*!

*/
			Text ManialinkText;
/*!

*/
	const	CMlPage ManialinkPage;
};

/*!
Supported declare modes : Local  Persistent 
This is the base Manialink page interface.
*/
struct CEditorPluginLayer : public CMlScript {
/*!

*/
	const	CEditorPlugin Editor;
};

/*!
Supported declare modes : Local  Persistent 
API for Maniaplanet client scripts.
*/
struct CBadgeEditor : public CGameManiaAppMinimal {
/*!

*/
			Void Leave();
/*!

*/
			CBadge DisplayCurrentBadge;
/*!

*/
			Vec2 DisplayPosN;
/*!

*/
			Vec2 DisplaySize;
/*!

*/
			Real DisplayFoV;
/*!
Values in range (0.100000-10.000000)
*/
			Real CameraTransitionDuration;
/*!
Values in range (-10.000000-10.000000)
*/
			Real MeshRotation_MaxSpeed;
/*!
Values in range (0.100000-10.000000)
*/
			Real MeshRotation_Acceleration;
/*!

*/
			Ident DisplayCurrentMeshId;
/*!

*/
	const	Ident[] MeshIds;
/*!

*/
			Void MeshId_Next();
/*!

*/
			Void MeshId_Previous();
/*!

*/
	const	CBadge[] Badges;
/*!

*/
			CBadge BadgeCreate();
/*!

*/
			Void BadgeDestroy(CBadge Badge);
/*!

*/
			Void BadgeCopy(CBadge Source,CBadge Destination);
/*!

*/
			Void BadgeReadFromProfile(CBadge Badge,Ident UserId);
/*!

*/
			Void BadgeWriteToProfile(CBadge Badge,Ident UserId);
};

/*!

*/
struct CGameMasterServerOnlineSignal_RecordBeaten : public CGameMasterServerOnlineSignal {
/*!

*/
	const	Text BeatenLogin;
/*!

*/
	const	Text BeatenDisplayName;
/*!

*/
	const	Text ChallengeUid;
/*!

*/
	const	Text ChallengeName;
/*!

*/
	const	Integer RecordScore;
/*!

*/
	const	Integer RecordScoreBeaten;
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
			Boolean UseAutoRespawnBots;
/*!

*/
			Boolean WalkOnWall;
/*!

*/
			Boolean UseAutoDiscardBotEvents;
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
	const	CSmMapLandmark[] MapLandmarks_BotSpawn;
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
			Void SpawnBotPlayer(CSmPlayer Player,Integer ClanNum,Integer Armor,CSmMapBotSpawn BotSpawn,Integer ActivationDate);
/*!

*/
			Void SpawnBotPlayer(CSmPlayer Player,CSmPlayer Owner,Integer Armor,Vec3 Offset,Integer ActivationDate);
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
	const	CSmMapLandmark[] MapLandmarks_BotSpawn;
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
	const	Boolean IsBound;
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
			Void SendRulesEvent(Text Param1,Text[] Param2,CSmPlayer Shooter,CSmPlayer Victim,CSmObject Object);
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
/*!

*/
			Boolean IsJumping;
/*!

*/
			Boolean IsGliding;
/*!

*/
			Boolean IsAttractor;
/*!

*/
			Boolean IsFlying;
/*!

*/
			Boolean IsSliding;
/*!

*/
			Boolean IsRunning;
/*!

*/
			Boolean IsFrozen;
/*!

*/
			Boolean IsSneaking;
/*!

*/
			Boolean IsFreeLooking;
/*!

*/
			Boolean HasNoPlayerCollision;
};

/*!
Supported declare modes : Local  Persistent 
API for the plugins of the map editor.
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
	const	CTmRaceClientEvent[] RaceEvents;
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
	const	Integer SplitScreenNum;
/*!

*/
	const	Integer SplitScreenCount;
/*!

*/
			Integer CurPlayerCamera;
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
			Void Cheats_Reset();
/*!

*/
			Boolean EnableCollisions;
/*!

*/
			Boolean EnableScaleCar;
/*!

*/
			Boolean EnableCheckpointBonus;
/*!

*/
			Boolean EnableUniqueCamera;
/*!

*/
			Boolean EnableBonusEvents;
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
			Ident RaceGhost_Add(CGhost Ghost,Boolean DisplayAsPlayerBest);
/*!

*/
			Ident RaceGhost_AddWithOffset(CGhost Ghost,Integer OffsetMs);
/*!

*/
			Ident RaceGhost_Add(CGhost Ghost,Boolean DisplayAsPlayerBest,Ident ModelId);
/*!

*/
			Void RaceGhost_Remove(Ident GhostInstId);
/*!

*/
			Void RaceGhost_RemoveAll();
/*!

*/
			Integer RaceGhost_GetStartTime(Ident GhostInstId);
/*!

*/
			Integer RaceGhost_GetCurCheckpoint(Ident GhostInstId);
/*!

*/
			Integer RaceGhost_GetCheckpointTime(Ident GhostInstId,Integer Checkpoint);
/*!

*/
			Boolean RaceGhost_IsReplayOver(Ident GhostInstId);
/*!

*/
			Boolean OnlineRecordEnabled;
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
API for the plugins of the map editor.
*/
struct CTmMapType : public CMapType {
/*!

*/
	const	CTmMode Mode;
/*!

*/
			Void TMObjective_SetFromBestRace(CTmScore Score);
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
User profile.
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
	enum EMuteSetting {
		Auto,
		Muted,
		NotMuted,
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
	const	Integer NextEchelonPercent;
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
	const	Boolean VoiceChat_Supported;
/*!

*/
			EMuteSetting VoiceChat_MuteSetting;
/*!

*/
	const	Boolean VoiceChat_IsSpeaking;
/*!

*/
	const	Boolean VoiceChat_IsMuted;
/*!

*/
	const	Boolean IsConnectedToMasterServer;
/*!

*/
	const	Text[] AlliesConnected;
/*!

*/
	const	EStereoDisplayMode StereoDisplayMode;
/*!

*/
			Boolean HackCamHmdDisabled;
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
		AppMenu,
		Action1,
		Action2,
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
	const	Boolean IsActionAutoRepeat;
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
/*!

*/
			Integer DocumentsSlotsLimit;
};

/*!
Manager for HTTP requests
*/
struct CHttpManager : public CNod {
/*!
Create a get request, AdditionnalHeaders format is : "Header-name: Value\nOther-name: OtherValue"
*/
			CHttpRequest CreateGet(Text Url);
/*!

*/
			CHttpRequest CreateGet(Text Url,Boolean UseCache);
/*!

*/
			CHttpRequest CreateGet(Text Url,Boolean UseCache,Text AdditionalHeaders);
/*!

*/
			CHttpRequest CreatePost(Text Url,Text Resource);
/*!

*/
			CHttpRequest CreatePost(Text Url,Text Resource,Text AdditionalHeaders);
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
struct CVideoManager : public CNod {
/*!

*/
			CVideo CreateVideo(Text Url,Boolean IsLooping,Boolean AutoProcessing);
/*!

*/
			Void DestroyVideo(CVideo Video);
/*!

*/
	const	CVideo[] Videos;
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
			CAudioSource CreateSound(Text Url);
/*!

*/
			CAudioSource CreateSound(Text Url,Real VolumedB,Boolean IsMusic,Boolean IsLooping,Boolean IsSpatialized);
/*!

*/
			Void DestroySound(CAudioSource Sound);
/*!

*/
	const	CAudioSource[] Sounds;
/*!

*/
			CAudioSourceMusic CreateMusic(Text Url);
/*!

*/
			Void DestroyMusic(CAudioSourceMusic Music);
/*!

*/
			Void PlaySoundEvent(CAudioSource Sound,Real VolumedB);
/*!

*/
			Void PlaySoundEvent(Text Url,Real VolumedB);
/*!

*/
			Void PlaySoundEvent(ELibSound Sound,Integer SoundVariant,Real VolumedB);
/*!

*/
			Void PlaySoundEvent(CAudioSource Sound,Real VolumedB,Integer Delay);
/*!

*/
			Void PlaySoundEvent(Text Url,Real VolumedB,Integer Delay);
/*!

*/
			Void PlaySoundEvent(ELibSound Sound,Integer SoundVariant,Real VolumedB,Integer Delay);
/*!

*/
			Void PlaySoundEvent(CAudioSource Sound,Real VolumedB,Vec3 PanRadiusLfe);
/*!

*/
			Void PlaySoundEvent(Text Url,Real VolumedB,Vec3 PanRadiusLfe);
/*!

*/
			Void PlaySoundEvent(CAudioSource Sound,Real VolumedB,Vec3 PanRadiusLfe,Integer Delay);
/*!

*/
			Void PlaySoundEvent(Text Url,Real VolumedB,Vec3 PanRadiusLfe,Integer Delay);
/*!

*/
			Void ClearAllDelayedSoundsEvents();
/*!

*/
			Boolean ForceEnableMusic;
/*!

*/
			Real LimitMusicVolumedB;
/*!

*/
			Real LimitSceneSoundVolumedB;
/*!

*/
			Real LimitUiSoundVolumedB;
};

/*!

*/
struct CInputManager : public CNod {
	enum EButton {
		Left,
		Right,
		Up,
		Down,
		A,
		B,
		X,
		Y,
		L1,
		R1,
		LeftStick,
		RightStick,
		Menu,
		View,
		LeftStick_Left,
		LeftStick_Right,
		LeftStick_Up,
		LeftStick_Down,
		RightStick_Left,
		RightStick_Right,
		RightStick_Up,
		RightStick_Down,
		L2,
		R2,
		None,
	};
/*!

*/
	const	CInputEvent[] PendingEvents;
/*!

*/
	const	Integer Now;
/*!

*/
	const	Integer Period;
/*!

*/
	const	CInputPad[] Pads;
/*!

*/
	const	Vec2 MousePos;
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
			Text GetPadButtonPlaygroundBinding(CInputPad Pad,EButton Button);
/*!

*/
			Text GetPadButtonCurrentBinding(CInputPad Pad,EButton Button);
/*!

*/
			Text GetPadButtonBinding(CInputPad Pad,EButton Button);
/*!

*/
			Boolean ExclusiveMode;
/*!

*/
			Boolean IsKeyPressed(Integer KeyCode);
/*!

*/
			Integer Dbg_AutoRepeat_InitialDelay;
/*!

*/
			Integer Dbg_AutoRepeat_Period;
};

/*!
Script API to manage user data.
*/
struct CDataMgr : public CNod {
	enum EFileType {
		Map,
		Ghost,
	};
	enum EResult {
		NotStarted,
		Running,
		Cancelled,
		Finished_Ok,
		Error_MountRead,
		Error_MountWrite,
		Error_Delete,
		Error_NoUserRecords,
		Error_NoUserDataCache,
		Error_MasterServer,
		Error_FindOrAddFid,
		Error_DownloadPackDesc,
		Error_LoadFromFid,
		Error_FidNotLoadable,
		Error_BadFileType,
		Error_MedalGhostReplayFidNotFound,
		Error_MedalGhostNotFoundOnReplay,
		Error_SaveUserRecordsToFid,
		Error_FindFid,
		Error_SaveToFid,
		Error_UrlNotReachable,
		Error_EmptyUrl,
		Error_Internal,
		Error_NotEnoughSpace,
	};
/*!

*/
	const	CMapInfo[] Maps;
/*!

*/
	const	CHighScore[] Records;
/*!

*/
	const	CGhost[] Ghosts;
/*!

*/
	const	Boolean HasFreeSpaceForNewMap;
/*!

*/
	const	CImage MapThumbnail;
/*!

*/
			Void MapFilterClear();
/*!

*/
			Text MapFilterStartWithPath;
/*!

*/
			Void DeleteFile(Text FileName);
/*!

*/
			Void RetrieveNewFileName(Ident UserId,Text SlotName,EFileType FileType);
/*!

*/
			Void GetNewMapEditionId(Ident UserId,Integer MinEditionId);
/*!

*/
			Void RetrieveMapFileNameFromEditionId(Ident UserId,Text FileName);
/*!

*/
			Void RetrieveUserFiles(Ident UserId,Text SlotName,EFileType FileType);
/*!

*/
			Void RetrieveGameFiles(EFileType FileType);
/*!

*/
			Void RetrieveOrderedCampaignMaps();
/*!

*/
			Void ClearFileList();
/*!

*/
			Void LoadMapThumbnail(Integer MapIndex);
/*!

*/
			Void UploadUserFile(Text PostUrl,Text MapName,Text Metadata);
/*!

*/
			Void UploadUserFile(Text PostUrl,Text MapName,Text Metadata,Text AdditionalHeaders);
/*!

*/
			Void QueryHasFreeSpaceForNewMap(Ident UserId);
/*!

*/
			Void RetrieveRecords(CMapInfo MapInfo,Ident UserId);
/*!

*/
			Void RetrieveRecordsNoMedals(Text MapUid,Ident UserId);
/*!

*/
			Void StoreRecord(Text MapUid,Ident UserId,CGhost Ghost);
/*!

*/
			Void StoreRecord(Text MapUid,Ident UserId,CGhost Ghost,Text GhostName);
/*!

*/
			CGhost GhostRetrieve(Text GhostUrl);
/*!

*/
			CGhost GhostRetrieveFromPlayer(CPlayer GamePlayer);
/*!

*/
			CGhost GhostRetrieveFromTaskResult(CWebServicesTaskResult_GhostHandle TaskResult);
/*!

*/
			Void GhostDestroy(CGhost Ghost);
/*!

*/
	const	Boolean Ready;
/*!

*/
	const	Boolean DoNotSwitchOff;
/*!

*/
	const	EResult LatestResult;
/*!

*/
	const	Ident MenuUserId;
/*!

*/
	const	Text NewFileName;
/*!

*/
	const	Integer MinEditionId;
/*!

*/
	const	Text MapFileNameFromEditionId;
};

/*!
Score and leaderboard manager.
*/
struct CScoreMgr : public CNod {
	enum ELocalScoreStatus {
		None,
		Loading,
		NotLoaded,
		Loaded,
	};
	enum EMasterServerScoreStatus {
		None,
		Synchronizing,
		NotSynchronized,
		Synchronized,
	};
/*!
Array of task results.
*/
	const	CWebServicesTaskResult[] TaskResults;
/*!
Release a task result no more used.
*/
			Void ReleaseTaskResult(Ident TaskId);
/*!
Returns the local status of user records.
*/
			ELocalScoreStatus ScoreStatus_GetLocalStatus(Ident UserId);
/*!
Returns the masterserver status of user records.
*/
			EMasterServerScoreStatus ScoreStatus_GetMasterServerStatus(Ident UserId);
/*!
Set a new record for a campaign map.
*/
			CWebServicesTaskResult Campaign_SetNewMapRecord(Ident UserId,Text MapUid,CGhost Ghost);
/*!
Returns the user record time for a campaign map.
*/
			Integer Campaign_GetMapRecord(Ident UserId,Text MapUid);
/*!
Returns the user record ghost for  a campaign map.
*/
			CWebServicesTaskResult_GhostHandle Campaign_GetMapRecordGhost(Ident UserId,Text MapUid);
/*!
Returns the number of medals for campaign map.
*/
			Integer Campaign_GetMapMultiAsyncLevel(Ident UserId,Text MapUid);
/*!

*/
			CWebServicesTaskResult_BuddiesChallengeRecord Campaign_GetBuddiesMapRecord(Ident UserId,Text MapUid);
/*!

*/
			Boolean Campaign_IsBuddiesMapRecordDirty(Ident UserId,Text MapUid);
/*!

*/
			CWebServicesTaskResult_BuddiesChallengeRecordsComparison Campaign_GetBuddiesMapRecordsComparison(Ident UserId);
/*!

*/
			CWebServicesTaskResult_BuddyChallengeRecordsComparison Campaign_GetBuddyMapRecordsComparison(Ident UserId,Text OpponentLogin);
/*!

*/
			Void Multiplayer_AddToScore(Ident UserId,Real ScoreDiff,Integer Timestamp);
/*!
Returns the user ranking on a campaign.
*/
			Integer CampaignLeaderBoard_GetPlayerRanking(Ident UserId,Text CampaignId,Text Zone);
/*!
Returns the number of user ranked on a campaign.
*/
			Integer CampaignLeaderBoard_GetPlayerCount(Text CampaignId,Text Zone);
/*!
Returns the user ranking on a map.
*/
			Integer MapLeaderBoard_GetPlayerRanking(Ident UserId,Text MapUid,Text Zone);
/*!
Returns the number of user ranked on a map.
*/
			Integer MapLeaderBoard_GetPlayerCount(Text MapUid,Text Zone);
/*!
Returns the user global ranking.
*/
			Integer GlobalLeaderBoard_GetPlayerRanking(Ident UserId,Text Zone);
/*!
Returns the number of user ranked in global leaderboard.
*/
			Integer GlobalLeaderBoard_GetPlayerCount(Text Zone);
/*!
Returns a part of the global leaderboard.
*/
			CWebServicesTaskResult_RealLeaderBoard GlobalLeaderBoard_GetPlayerList(Ident UserId,Text Zone,Integer FromIndex,Integer Count);
};

/*!
User privileges manager.
*/
struct CPrivilegeMgr : public CNod {
	enum EPrivilege {
		PlayMultiplayerMode,
		PlayMultiplayerSession,
		UploadUserCreatedContent,
		ViewOnlinePresence,
		ViewUserCreatedContent,
		ViewUserCreatedContentRequired,
		ViewUserGameHistory,
		VoiceChat,
		PlayMultiplayerAsync,
		DownloadUserCreatedContent,
	};
/*!
Array of task results.
*/
	const	CWebServicesTaskResult[] TaskResults;
/*!
Release a task result no more used.
*/
			Void ReleaseTaskResult(Ident TaskId);
/*!
Check if the user has the specified privilege.
*/
			CWebServicesTaskResult CheckPrivilege(Ident UserId,EPrivilege Privilege);
/*!

*/
			CWebServicesTaskResult CheckPrivilegeForAllUsers(EPrivilege Privilege);
/*!
Check if the user has the specified privilege related to each target user.
*/
			CWebServicesTaskResult_CheckTargetedPrivilegeResultScript CheckTargetedPrivilege(Ident UserId,EPrivilege Privilege);
/*!

*/
			CWebServicesTaskResult_CheckTargetedPrivilegeResultScript CheckTargetedPrivilegeForAllUsers(EPrivilege Privilege);
};

/*!

*/
struct CPresenceMgr : public CNod {
	enum ERichPresence {
		Undefined,
		MainMenu,
		Solo,
		Multi,
		Party,
		Create,
	};
/*!

*/
	const	CWebServicesTaskResult[] TaskResults;
/*!

*/
			Void ReleaseTaskResult(Ident TaskId);
/*!

*/
			Void SetPresence(Ident UserId,ERichPresence UplayFlow);
/*!

*/
			CGameMasterServerRichPresenceTaskResult_GetOnlinePresenceForPlayersScript GetOnlinePresenceForPlayers(Ident UserId);
};

/*!
Script API to communicate with plugins.
*/
struct CGamePluginInterfacesScript : public CNod {
/*!
Fetch a specific plugin API.
*/
			CManiaplanetPluginInterface GetInterface(Text Name);
/*!
List of all the Plugins' APIs.
*/
	const	CManiaplanetPluginInterface[] Interfaces;
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
			Vec2 RelativePosition_V3;
/*!

*/
			Real ZIndex;
/*!

*/
			Real RelativeScale;
/*!

*/
			Real RelativeRotation;
/*!

*/
	const	Vec2 AbsolutePosition_V3;
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
/*!

*/
	const	Boolean IsFocused;
};

/*!

*/
struct CImage : public CPlug {
	enum ERenderTech {
		Unknown,
		Tech3,
	};
	enum ETexFilter {
		Point,
		Bilinear,
		Trilinear,
		Anisotropic,
		AnisoPoint,
	};
	enum ETexAddress {
		Wrap,
		Mirror,
		Clamp,
		BorderSM3,
	};
	enum EColorSpace {
		Linear,
		sRGB,
	};
	enum EVideoTimer {
		Game,
		Human,
		(External),
		Scene,
		Default,
	};
	enum EGenerateUV {
		NoGenerate,
		CameraVertex,
		WorldVertex,
		WorldVertexXY,
		WorldVertexXZ,
		WorldVertexYZ,
		CameraNormal,
		WorldNormal,
		CameraReflectionVector,
		WorldReflectionVector,
		WorldNormalNeg,
		WaterReflectionVector,
		Hack1Vertex,
		MapTexel DEPRECATED,
		FogPlane0,
		Vsk3SeaFoam,
		ImageSpace,
		LightDir0Reflect,
		EyeNormal,
		ShadowB1Pw01,
		Tex3AsPosPrCamera,
		FlatWaterReflect,
		FlatWaterRefract,
		FlatWaterFresnel,
		WorldPosXYblendZY,
		DisableVshOutput,
	};
	enum EUsage {
		Color,
		Light,
		Height->DuDv,
		Render,
		H->DuDvLumi,
		H->NormXYZ,
		H->NormXY,
		DepthCmp,
		DispH01,
		H->NormPal8b,
		NormXYZ,
		NormXY,
		NormPal8b,
		NormPal16b,
		ColorFloat,
		RenderFloat,
		H->DuDv1,
		Alpha,
		LightAlpha,
		H->NormX0ZY,
		NormX0ZY,
		TexCoord,
		Render16b,
		Vertex,
		H->BumpTxTy,
		BumpTxTy,
		H->Norm0YZX,
		Norm0YZX,
		Norm:XYZ->0YZX,
		Depth,
		SrgbL8->LinearL16,
		NormATI2N,
		NormXYZ->ATI2N,
		Color16b,
		SpecFIE->FI0E,
		SpecFI0E,
	};
	enum EColorDepth {
		DefaultColorDepth,
		Color16b,
		Color32b,
	};
	enum ECubeMapFace {
		None,
		XPos,
		XNeg,
		YPos,
		YNeg,
		ZPos,
		ZNeg,
	};
	enum EBumpCompressMode {
		None(32b),
		Pal8b,
		DXT1(4b),
		Pal16b,
	};
	enum EPixelUpdate {
		None,
		Render,
		Shader,
		DynaSpecular,
		Clear,
		RenderVideo,
	};
	enum EDynamic {
		Off,
		On,
		On 2 Buffers,
	};
	enum ENormalRotate {
		None,
		+x +z -y,
	};
	enum EEdCustomSaveOp {
		None,
		Conv.Diffuse,
		ShootCubeHdrScaleA2 DXT5,
	};
	enum ECompressor {
		NVidia,
		DirectX,
	};
	enum EForceBorderSize {
		1 texel,
		2 texels,
		3 texels,
		4 texels,
	};
	enum EMipMapAlpha01 {
		HalfBinary,
		ForceBinary,
		ShadeOfGray,
	};
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
Supported declare modes : Local  Persistent 
API for Maniaplanet client scripts.
*/
struct CManiaAppBrowser : public CManiaApp {
/*!

*/
	const	CManiaAppEvent[] PendingEvents;
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
	enum EUILayerAnimation {
		None,
		DownFast,
		DownSlow,
		LeftFast,
		LeftSlow,
		RightFast,
		RightSlow,
		ScaleFast,
		ScaleSlow,
		UpFast,
		UpSlow,
	};
/*!

*/
			Boolean IsVisible;
/*!

*/
	const	Boolean AnimInProgress;
/*!

*/
			EUILayerType Type;
/*!

*/
			EUILayerAnimation InAnimation;
/*!

*/
			EUILayerAnimation OutAnimation;
/*!

*/
			EUILayerAnimation InOutAnimation;
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
API for users.
*/
struct CGameUserManagerScript : public CNod {
/*!

*/
	const	Boolean Intro;
/*!

*/
			Boolean CanSkipIntro;
/*!

*/
			Void SetSkipIntro();
/*!

*/
	const	Boolean MainUserLogged;
/*!

*/
	const	CGameUserScript MainUser;
/*!

*/
	const	Boolean MainUser_CanUseVoiceChat;
/*!

*/
			Boolean VoiceChat_MuteAll;
/*!

*/
			Void RequestMainUserChange();
/*!

*/
	const	CGameUserScript[] Users;
/*!

*/
	const	CInputPad MainUserPad;
/*!

*/
			Text GetBuddiesLogins(Ident UserId);
/*!

*/
			Boolean AreBuddiesLoginsReady(Ident UserId);
/*!

*/
			Void InviteBuddyToServer(Ident UserId,Text Login);
/*!

*/
			Void ShowInviteUI(Ident UserId);
/*!

*/
			Void ShowProfile(Ident UserId,Text ProfileLogin);
};

/*!
Supported declare modes : Local  Persistent 
Internal API for Maniaplanet.
*/
struct CManiaPlanet : public CNod {
	enum EContext {
		MenuStartUp,
		MenuManiaPlanet,
		MenuManiaTitleMain,
		MenuProfile,
		MenuSolo,
		MenuLocal,
		MenuMulti,
		MenuCompetitions,
		MenuEditors,
		EditorPainter,
		EditorTrack,
		EditorMediaTracker,
		Solo,
		SoloLoadScreen,
		Multi,
		MultiLoadScreen,
		MenuCustom,
		Unknown,
	};
	enum ELinkType {
		ExternalBrowser,
		ManialinkBrowser,
	};
	enum EBuyTitleMode {
		OpenStore,
		BuyIfNeeded,
		Ask,
	};
	enum EMenuStationsPage {
		Home,
		Play,
		Store,
		Options,
		Help,
	};
	enum EUplayFlow {
		OverView,
		Auth,
		Reward,
		Rewards,
		Actions,
	};
	enum ESystemPlatform {
		None,
		Steam,
		UPlay,
		PS4,
		XBoxOne,
	};
	enum ESystemSkuIdentifier {
		Unknown,
		EU,
		US,
		JP,
	};
	enum EHmdWearingState {
		Dismount,
		Mount,
		Unknown,
	};
	enum EHmdTrackingState {
		NotStarted,
		Calibrating,
		NotTracking,
		Tracking,
	};
/*!

*/
	const	Integer Now;
/*!

*/
	const	Text CurrentLocalDateText;
/*!

*/
	const	CUser LocalUser;
/*!

*/
	const	CTitle LoadedTitle;
/*!

*/
	const	CTitle[] TitlesAvailable;
/*!

*/
	const	CTitle[] TitlesBases;
/*!

*/
	const	Text[] TitleIdsInstalled;
/*!

*/
	const	Text[] TitleIdsPayed;
/*!

*/
	const	Integer EmptyStationsCount;
/*!

*/
	const	ESystemPlatform SystemPlatform;
/*!

*/
	const	ESystemSkuIdentifier SystemSkuIdentifier;
/*!

*/
	const	Text ExeVersion;
/*!

*/
	const	CMap CurrentMap;
/*!

*/
	const	EContext ActiveContext;
/*!

*/
	const	Text ActiveContext_MenuFrame;
/*!

*/
	const	Text ActiveContext_InGameDialogFrame;
/*!

*/
	const	Text ActiveContext_DialogFrame;
/*!

*/
	const	Text ActiveContext_SystemDialogFrame;
/*!

*/
	const	Boolean ActiveContext_ClassicDialogDisplayed;
/*!

*/
	const	Integer ActiveContext_GameWill;
/*!

*/
	const	Boolean ActiveContext_ManialinkBrowserDisplayed;
/*!

*/
	const	Boolean ActiveContext_MenuStationsDisplayed;
/*!

*/
	const	Boolean ActiveContext_InGameMenuDisplayed;
/*!

*/
	const	EMenuStationsPage ActiveContext_MenuStationsPage;
/*!

*/
	const	EMenuStationsPage ActiveContext_MenuStationsClickedPage;
/*!

*/
	const	Text CurrentServerLogin;
/*!

*/
	const	Text CurrentServerName;
/*!

*/
	const	Text CurrentServerModeName;
/*!

*/
	const	Text CurrentServerJoinLink;
/*!

*/
	const	CUser[] CurrentServerPlayers;
/*!

*/
	const	Integer CurrentAppId;
/*!

*/
			Boolean IsPrivateSession;
/*!

*/
	const	Boolean IsKioskMode;
/*!

*/
	const	Boolean ParentalLock_IsLocked;
/*!

*/
	const	Integer TotalTimePlay;
/*!

*/
	const	Integer Messenger_MessagesCount;
/*!

*/
	const	Integer AccountPlanets;
/*!

*/
	const	Boolean IsTitleTimeLimited;
/*!

*/
	const	Boolean IsTitleTimeLimitActivated;
/*!

*/
	const	Boolean CanUnlockTitleTimeLimitOnStore;
/*!

*/
	const	Integer TitleTimeLeft;
/*!

*/
	const	Integer CurConnectionDate;
/*!

*/
	const	Integer PrevConnectionDate;
/*!
Values in range (-40.000000-0.000000)
*/
			Real MasterSoundVolume;
/*!
Values in range (-40.000000-0.000000)
*/
			Real MasterMusicVolume;
/*!

*/
	const	Boolean TmTurbo_IsDemo;
/*!

*/
	const	Boolean TmTurbo_IsPartialInstall;
/*!

*/
	const	Boolean TmTurbo_IsBeta;
/*!

*/
	const	Boolean TmTurbo_IsBetaDeactivated;
/*!

*/
	const	Boolean TmTurbo_IsOpenBeta;
/*!

*/
	const	Boolean TmTurbo_IsSlowInstall;
/*!

*/
			Boolean Settings_StationsManualLayout;
/*!
Overwrite the user's system clipboard.
*/
			Void ClipboardSet(Text ClipboardText);
/*!

*/
			Void OpenLink(Text Url,ELinkType LinkType);
/*!

*/
			Void QuitGameAndOpenLink(Text Url);
/*!

*/
			Void InstallTitle(Text TitleId);
/*!

*/
			Void InstallTitleFromUrl(Text Url,Text DisplayName);
/*!

*/
			Void InstallTitleFromUrl(Text Url,Text DisplayName,Boolean EnterAfterInstall);
/*!

*/
			Void ShowTitle(Text TitleId,Boolean ShowStation);
/*!

*/
			Void SelectTitle(Text TitleId);
/*!

*/
			Void EnterTitle(Text TitleId);
/*!

*/
			Void ShowCurMapCard();
/*!

*/
			Void SetMenuStationsActive(Boolean Activate);
/*!

*/
			Void Dialog_EnterGameKey();
/*!

*/
			Void Dialog_BuyTitleDialog(Text TitleId,Text OverrideBuyUrl,Integer OverrideActionAfterBuy);
/*!

*/
			Void Dialog_BuyTitleEx(Text TitleId,EBuyTitleMode Mode,Text OverrideBuyUrl,Integer OverrideActionAfterBuy);
/*!

*/
			Void Dialog_GenerateGameKeys(Text TitleId,Integer FeaturesLevel,Integer NbToGenerate,Boolean AddBuddyOnRegistration);
/*!

*/
			Void Dialog_BuyStations();
/*!

*/
			Void Dialog_SetServerFavourite(Text ServerLogin,Boolean Favorite,Boolean Silent);
/*!

*/
	const	Boolean Dialog_IsFinished;
/*!

*/
	const	Boolean Dialog_Success;
/*!

*/
	const	Boolean Dialog_Aborted;
/*!

*/
			Void CustomMenu_Request(Text Type,Text[] Data);
/*!

*/
			Void SetLocalUserClubLink(Text ClubLink);
/*!

*/
			Void SetLocalUserNickName(Text NickName);
/*!

*/
			Void FlashWindow();
/*!

*/
			Void CreateShortcut(Text ShortcutName,Text Url);
/*!

*/
			Void HideSystemLoadingScreen();
/*!

*/
			Boolean IsLiveStreamingEnabled;
/*!

*/
			Boolean IsRemotePlayEnabled;
/*!

*/
			Void TmTurbo_LoadingOpportunity();
/*!

*/
	const	CGameAchievementScriptManager AchievementsManager;
/*!

*/
	const	CGameUserManagerScript UserMgr;
/*!

*/
			Void Authentication_GetToken(Ident UserId,Text AppLogin);
/*!

*/
	const	Boolean Authentication_GetTokenResponseReceived;
/*!

*/
	const	Integer Authentication_ErrorCode;
/*!

*/
	const	Text Authentication_Token;
/*!

*/
	const	CWebServicesTaskResult[] MasterServer_MSTaskResults;
/*!

*/
			Void MasterServer_ReleaseMSTaskResult(Ident TaskId);
/*!

*/
			Text MasterServer_GetURL(Text ShortCutId);
/*!

*/
	const	CMasterServerUser MasterServer_MainMSUser;
/*!

*/
	const	CMasterServerUser[] MasterServer_MSUsers;
/*!

*/
			CMasterServerUser MasterServer_GetMSUserFromId(Ident UserId);
/*!

*/
			Void MasterServer_Connect(Ident UserId);
/*!

*/
			CWebServicesTaskResult_GetDisplayNameScriptResult MasterServer_GetDisplayName(Ident UserId);
/*!

*/
			CWebServicesTaskResult MasterServer_CheckNetworkAvailability(Ident UserId);
/*!

*/
			CWebServicesTaskResult_Session_Get MasterServer_GetSessionInfo(Ident UserId,Text SessionId);
/*!

*/
			Void MasterServer_Zone_GetPathAndName(Text ZoneFullPath,Text ZonePath,Text ZoneName);
/*!

*/
			CWebServicesTaskResult_ZoneList MasterServer_Zone_GetChilds(Text ZoneFullPath);
/*!

*/
			CWebServicesTaskResult MasterServer_Zone_ChangeZone(Ident UserId,Text ZoneFullPath);
/*!

*/
			CWebServicesTaskResult_LaunchUplayScriptResult MasterServer_UplayLaunch(Ident UserId,EUplayFlow UplayFlow,Integer RewardCode);
/*!

*/
			CWebServicesTaskResult_LaunchUplayScriptResult MasterServer_UplayLaunch_v2(Ident UserId,EUplayFlow UplayFlow,Text RewardId);
/*!

*/
			CWebServicesTaskResult_LaunchUplayScriptResult MasterServer_UplayLaunchAndCompleteActions(Ident UserId,EUplayFlow UplayFlow,Text RewardId);
/*!

*/
			Void MasterServer_Tracking_ContextMenuStart(Ident UserId,Text MenuName);
/*!

*/
			Void MasterServer_Tracking_ContextMenuStop(Ident UserId,Text MenuName);
/*!

*/
			Void MasterServer_Tracking_ContextGameModeStart(Ident UserId,Text GameMode);
/*!

*/
			Void MasterServer_Tracking_ContextGameModeStop(Ident UserId,Text GameMode);
/*!

*/
			Void MasterServer_Tracking_ContextMapStart(Ident UserId,Text MapUid,Text Environment);
/*!

*/
			Void MasterServer_Tracking_ContextMapStop(Ident UserId,Text MapUid);
/*!

*/
			Void MasterServer_Tracking_ContextPlayStart(Ident UserId,Text Type);
/*!

*/
			Void MasterServer_Tracking_ContextPlayStop(Ident UserId,Text Type,Text Reason,Integer NbRespawns);
/*!

*/
			Void MasterServer_Tracking_MedalUnlock(Ident UserId,Integer Medal);
/*!

*/
			Void MasterServer_Tracking_MedalUnlock_v2(Ident UserId,Integer PreviousMedal,Integer Medal);
/*!

*/
			Void MasterServer_Tracking_NewMapCreated(Ident UserId,Text Environment,Boolean IsRandomlyGenerated);
/*!

*/
			Void MasterServer_Tracking_NewsImpression(Ident UserId,Text NewsId);
/*!

*/
			Void MasterServer_Tracking_NewsClick(Ident UserId,Text NewsId);
/*!

*/
			Void MasterServer_Tracking_PlayerAchievement(Ident UserId,Integer AchievementId);
/*!

*/
			Void MasterServer_Tracking_PlayerProgressionMap(Ident UserId,Text Value);
/*!

*/
			Void MasterServer_Tracking_PlayerRespawn(Ident UserId,Integer RaceTime);
/*!

*/
			Void MasterServer_Tracking_StatCampaign(Ident UserId,Integer PlayedMapCount,Integer BronzeMedalCount,Integer SilverMedalCount,Integer GoldMedalCount,Integer AuthorMedalCount,Integer MaxDifficultyLevel);
/*!

*/
			Void MasterServer_Tracking_StatCampaign_v2(Ident UserId,Integer PlayedMapCount,Integer PlayedEnvCount,Integer BronzeMedalCount,Integer SilverMedalCount,Integer GoldMedalCount,Integer AuthorMedalCount,Integer MaxDifficultyLevel);
/*!

*/
			Void MasterServer_Tracking_StatChallenge(Ident UserId,Integer PendingChallengeCount);
/*!

*/
			Void MasterServer_Tracking_StatGlobalRanking(Ident UserId,Integer GlobalRanking);
/*!

*/
			Void MasterServer_Tracking_StatOnline(Ident UserId,Integer Echelon);
/*!

*/
			Void MasterServer_Tracking_StatRecordCenter(Ident UserId,Integer BestCount,Integer EqualCount,Integer WorstCount);
/*!

*/
			CWebServicesTaskResult MasterServer_Beta_RetrieveUserInfo(Ident UserId);
/*!

*/
			CWebServicesTaskResult MasterServer_Beta_AcceptNDA(Ident UserId);
/*!

*/
			CWebServicesTaskResult BuyFullGame(Ident UserId);
/*!

*/
			CWebServicesTaskResult ShowSystemError(Ident UserId,Integer ErrorCode);
/*!

*/
			Void HMD_Activate(Boolean Enable);
/*!

*/
	const	Boolean HMD_IsActive;
/*!

*/
	const	Vec3 HMD_HeadTranslation;
/*!

*/
	const	Real HMD_HeadYaw;
/*!

*/
	const	Real HMD_HeadPitch;
/*!

*/
	const	Real HMD_HeadRoll;
/*!

*/
			Void HMD_ResetTracking();
/*!

*/
			Void HMD_SelectUser();
/*!

*/
	const	CGameUserScript HMD_CurrentUser;
/*!

*/
			Real HMD_WorldScale;
/*!
Be careful, when this value is not 1, the behavior is non-physic. May induce motion sicknessValues in range (0.000010-10000.000000)
*/
			Real HMD_MoveScale;
/*!
Values in range (0.200000-100.000000)
*/
			Real HMD_HUD_Distance;
/*!

*/
	const	EHmdWearingState HMD_WearingState;
/*!

*/
	const	EHmdTrackingState HMD_TrackingState;
/*!

*/
	const	Boolean HMD_IsUserWarnBySystem_OutOfPlayArea;
/*!

*/
			Boolean Cameras_BlackOut;
};

/*!
API for titles menus to control the main loop.
*/
struct CTitleFlow : public CNod {
	enum ESplitScreenLayout {
		Horizontal,
		Vertical,
		Four,
	};
	enum EResult {
		Success,
		Error_Internal,
		Error_DataMgr,
		Error_Net_ServerNotFound,
		Error_Net_ServerUnreachable,
		Error_Net_Disconnected,
		Error_Net_WrongPassword,
		Error_Network_OnlineExpired,
		Error_Network_ServerFull,
	};
/*!
Can a command be issued.
*/
	const	Boolean IsReady;
/*!
Result of the latest command issued.
*/
	const	EResult LatestResult;
/*!

*/
	const	Text CustomResultType;
/*!

*/
	const	Text[] CustomResultData;
/*!

*/
			Void PlayMap(Text Map,Text Mode,Text SettingsXml);
/*!

*/
			Void PlayMapList(Text[] MapList,Text Mode,Text SettingsXml);
/*!

*/
			Void PlayPlaylist(Text Playlist,Text OverrideMode,Text OverrideSettingsXml);
/*!

*/
			Void PlaySplitScreen(ESplitScreenLayout LayoutType,Text[] MapList,Text Mode,Text SettingsXml);
/*!

*/
			Void PlayMultiOnSameScreen(ESplitScreenLayout LayoutType,Text[] MapList,Text Mode,Text SettingsXml);
/*!

*/
			Void ViewReplay(Text Replay);
/*!

*/
			Void EditMap(Text Map,Text EditorPluginScript,Text EditorPluginArgument);
/*!

*/
			Void EditNewMap(Text Environment,Text Decoration,Text ModUrl,Text PlayerModel,Text MapType,Text EditorPluginScript,Text EditorPluginArgument);
/*!

*/
			Void EditBadges();
/*!

*/
	const	CServerInfo JoinServer_ServerInfo;
/*!

*/
			Void JoinServer_GetInfo(Text ServerLogin);
/*!

*/
			Void JoinServer_GetInfo(Text ServerLogin,Text ServerPassword);
/*!

*/
			Void JoinServer_Join(Boolean AsSpectator);
/*!

*/
			Void JoinServer_Abort();
/*!

*/
			Void Quit();
};

/*!
Manager of buddies instant messaging.
*/
struct CGameScriptNotificationsConsumer : public CNod {
	enum EFilterPriority {
		All,
		MoreThanMemo,
		MoreThanNotice,
	};
/*!
Events
*/
	const	CGameScriptNotificationsConsumerEvent[] Events;
/*!
List of the Notifications.
*/
	const	CGameScriptNotificationsConsumerNotification[] Notifications;
/*!

*/
	const	CGameScriptNotificationsConsumerNotification[] FilteredNotifications;
/*!

*/
			EFilterPriority Filter_Priority;
};

/*!
Manager of achievements.
*/
struct CGameAchievementScriptManager : public CNod {
/*!
List of events for current frame.
*/
	const	CGameAchievementScriptEvent[] PendingEvents;
/*!
Achievements descriptions.
*/
	const	CGameAchievementScriptAchievement[] Achievements;
/*!
Stats descriptions.
*/
	const	CGameAchievementScriptStat[] Stats;
/*!
Achievements descriptions.
*/
	const	CGameAchievementScriptAchievementDesc[] AchievementDescriptions;
/*!
Stats descriptions.
*/
	const	CGameAchievementScriptStatDesc[] StatDescriptions;
/*!

*/
			Void SendEvent(Ident UserId,Text Mnemo,Integer[] Params);
/*!

*/
			CWebServicesTaskResult MasterServer_UplayCompleteAction(Ident UserId,Text ActionId);
/*!

*/
			CWebServicesTaskResult MasterServer_UplayCompleteActions(Ident UserId,Text[] ActionIds);
/*!

*/
			CGameAchievementScriptUplayAction MasterServer_GetUplayAction(Ident UserId,Text ActionId);
/*!

*/
			Boolean MasterServer_IsUplayActionCompleted(Ident UserId,Text ActionId);
/*!

*/
			CWebServicesTaskResult MasterServer_UplayPurchaseReward(Ident UserId,Text RewardId);
/*!

*/
			Boolean MasterServer_IsUplayRewardPurchased(Ident UserId,Text RewardId);
/*!

*/
	const	CWebServicesTaskResult[] MasterServer_MSTaskResults;
/*!

*/
			Void MasterServer_ReleaseMSTaskResult(Ident TaskId);
/*!

*/
	const	CGameAchievementScriptUplayAction[] MasterServer_UplayActions;
};

/*!

*/
struct CGameManagerBadgeScript : public CNod {
/*!

*/
	const	CBadge[] Badges;
/*!

*/
			CBadge BadgeCreate();
/*!

*/
			Void BadgeDestroy(CBadge Badge);
/*!

*/
			Void BadgeCopy(CBadge Source,CBadge Destination);
/*!

*/
			Void BadgeReadFromProfile(CBadge Badge,Ident UserId);
/*!

*/
			Void BadgeWriteToProfile(CBadge Badge,Ident UserId);
/*!

*/
			Boolean ProfileIsReady(Ident UserId);
};

/*!
Supported declare modes : Local  Persistent 
API for game interface client scripts
*/
struct CManiaAppPlaygroundCommon : public CManiaApp {
/*!

*/
	const	CGameManiaAppPlaygroundScriptEvent[] PendingEvents;
/*!

*/
	const	CPlaygroundClient Playground;
/*!

*/
	const	CMap Map;
/*!
(read-only) UI actually displayed, as defined by the server.
*/
			CUIConfig UI;
/*!
Locally accessible by the client script to locally override settings from the server.
*/
			CUIConfig ClientUI;
};

/*!

*/
struct CEditorPluginEvent : public CManiaAppEvent {
	enum Type {
		LayerCustomEvent,
		KeyPress,
		(reserved),
		MenuNavigation,
		ChildModuleEvent,
		ParentModuleEvent,
		CursorSelectionBegin,
		CursorSelectionEnd,
		CursorChange,
		MapModified,
		EditorInput,
		EditAnchor,
		EditObjectives,
		StartValidation,
		StartTest,
	};
	enum EInput {
		Unknown,
		Menu,
		SwitchToRace,
		Undo,
		Redo,
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
		CameraZoomNext,
		Camera0,
		Camera1,
		Camera3,
		Camera7,
		Camera9,
		PivotChange,
		CursorTurnSlightly,
		CursorTurnSlightlyAntiClockwise,
		IconUp,
		IconRight,
		IconDown,
		IconLeft,
		RemoveAll,
		Save,
		SaveAs,
		MapStyle,
		ClassicMapEditor,
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
/*!

*/
	const	Boolean IsFromPad;
/*!

*/
	const	Boolean IsFromMouse;
/*!

*/
	const	Boolean IsFromKeyboard;
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
	const	Boolean IsPodium;
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
	const	Boolean HasMultilap;
/*!

*/
	const	CBlockModel GeneratedBlockModel;
/*!

*/
			Void ClearScriptMetadata();
/*!

*/
	const	Text Name;
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
/*!

*/
	const	CBlock Block;
/*!

*/
	const	CItemAnchor Item;
};

/*!
Supported declare modes : Local  Persistent 
API for Maniaplanet client scripts.
*/
struct CGameManiaAppMinimal : public CManiaApp {
/*!

*/
	const	CManiaAppEvent[] PendingEvents;
};

/*!

*/
struct CBadge : public CNod {
/*!

*/
			Vec3 PrimaryColor;
/*!

*/
			Text SkinName;
/*!

*/
			Text StickerSlot_Get(Text Slot);
/*!

*/
			Void StickerSlot_Set(Text Slot,Text Sticker);
/*!

*/
			Void StickerSlot_Clear();
/*!

*/
			Text[] Layers;
};

/*!

*/
struct CGameMasterServerOnlineSignal : public CNod {
/*!

*/
	const	Integer OnlineSignalId;
/*!

*/
	const	Text SenderLogin;
/*!

*/
	const	Text SenderDisplayName;
/*!

*/
	const	Integer TimeStamp;
};

/*!
Supported declare modes : Local  Persistent 
Rules API for gamemodes.
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
	enum ESystemPlatform {
		None,
		Steam,
		UPlay,
		PS4,
		XBoxOne,
	};
	enum ESystemSkuIdentifier {
		Unknown,
		EU,
		US,
		JP,
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
			Text ClientManiaAppUrl;
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
			Void Hud_Load(Text ModuleUrl);
/*!

*/
	const	CGamePlaygroundModuleServerHud Hud;
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
Only available for local solo modes.
*/
	const	CInputManager Input;
/*!
Only available for local solo modes.
*/
	const	CDataMgr DataMgr;
/*!

*/
	const	CScoreMgr ScoreMgr;
/*!
Only available for local solo modes.
*/
	const	ESystemPlatform SystemPlatform;
/*!
Only available for local solo modes.
*/
	const	ESystemSkuIdentifier SystemSkuIdentifier;
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
			Boolean ItemList_Begin();
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
			Boolean ActionList_Begin();
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
/*!

*/
	const	CGameAchievementScriptManager AchievementsManager;
/*!

*/
			CManiaplanetPluginInterface GetPluginInterface(Text Name);
/*!

*/
	const	CManiaplanetPluginInterface[] PluginInterfaces;
/*!

*/
	const	CGamePluginInterfacesScript Plugins;
/*!

*/
			Text Dbg_DumpDeclareForVariables(CNod Nod,Boolean StatsOnly);
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
Values in range (0.000000-1.000000)
*/
	const	Real GetLinearHue;
/*!

*/
			Real ForceLinearHue;
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
		OnModuleCustomEvent,
		OnModuleShowRequest,
		OnModuleHideRequest,
		OnModuleStorePurchase,
		OnModuleInventoryDrop,
		OnModuleInventoryEquip,
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
	enum EModuleType {
		Undefined,
		Hud,
		Inventory,
		Minimap,
		Store,
		ScoresTable,
		MenuBase,
		MenuBrowser,
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
/*!

*/
	const	Text ItemUrl;
/*!

*/
	const	Integer Quantity;
/*!

*/
	const	EModuleType ModuleType;
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
	const	CSmMapBotSpawn BotSpawn;
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
	const	CSmMapLandmark AnchorLandmark;
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

*/
	const	CPlaygroundClient Playground;
/*!
(read-only) UI actually displayed, as defined by the server.
*/
			CUIConfig UI;
/*!
Locally accessible by the client script to locally override settings from the server.
*/
			CUIConfig ClientUI;
/*!
Is in spectator mode - may be only for a short time between rounds.
*/
	const	Boolean IsSpectator;
/*!
Client actually desires to spectate instead of playing.
*/
	const	Boolean IsSpectatorClient;
/*!

*/
	const	Boolean UseClans;
/*!

*/
	const	Boolean UseForcedClans;
/*!

*/
	const	CManiaAppPlaygroundCommon ParentApp;
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
Request change of IsSpectatorClient (not immediate, and it may be refused).
*/
			Void RequestSpectatorClient(Boolean Spectator);
/*!
Set the spectated player, but do not switch to spectator mode automatically. Equivalent to numpad1/2/3/4
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
			Void CloseInGameMenu(EInGameMenuResult Result);
/*!

*/
			Void CloseScoresTable();
/*!

*/
	const	Boolean IsInGameMenuDisplayed;
/*!

*/
	const	Text CurrentServerLogin;
/*!

*/
	const	Text CurrentServerName;
/*!

*/
	const	Text CurrentServerDesc;
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
	const	CGameAchievementScriptManager AchievementsManager;
};

/*!

*/
struct CSmActionEvent : public CNod {
	enum EType {
		OnHitPlayer,
		OnProjectileStart,
		OnProjectileEnd,
		OnActiveChange,
		OnHitObject,
	};
/*!

*/
	const	EType Type;
/*!

*/
	const	CSmPlayer Player;
/*!

*/
	const	CSmObject Object;
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
API for the plugins of the map editor.
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
			Boolean ValidationEndRequested;
/*!

*/
			Boolean ValidationEndNoConfirm;
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
Player for CTmMlScriptIngame.
*/
struct CTmMlPlayer : public CPlayer {
	enum ERaceState {
		BeforeStart,
		Running,
		Finished,
		Eliminated,
	};
	enum ETmRacePlayerCoopMode {
		None,
		Symbiosys,
		Checkpoint,
	};
	enum ETmJumpMode {
		Disabled,
		Simple,
		Double,
		Infinite,
	};
	enum ETmBonusModeEventType {
		None,
		Bumps,
		LowGravity,
		FreeWheeling,
		LockedDirections,
	};
	enum ESceneVehiclePhyStuntFigure {
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
	const	Integer CoopSymbiosysPercentTotal;
/*!

*/
	const	Integer CoopCheckpointCurController;
/*!

*/
	const	ETmRacePlayerCoopMode CoopMode;
/*!

*/
	const	Integer ControllerCount;
/*!

*/
	const	Integer ControllerId0;
/*!

*/
	const	Integer ControllerId1;
/*!

*/
	const	Integer ControllerId2;
/*!

*/
	const	Integer ControllerId3;
/*!

*/
	const	Boolean ForcedAerialCamera;
/*!

*/
	const	Boolean ButtonSmashFrenzy;
/*!

*/
	const	Boolean EnableTurboButton;
/*!

*/
	const	Boolean MaxiAirControl;
/*!

*/
	const	Boolean EnableEmptyCars;
/*!

*/
	const	ETmJumpMode JumpMode;
/*!

*/
	const	Boolean TinyCar;
/*!

*/
	const	Boolean EnableCatchUpSpeed;
/*!

*/
	const	Boolean EnableStuntMode;
/*!

*/
	const	Boolean EnableOnlineMode;
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
	const	Vec3 AimDirection;
/*!

*/
	const	Real AimYaw;
/*!

*/
	const	Real AimPitch;
/*!

*/
	const	Real Upwardness;
/*!

*/
	const	Integer CurRaceContinuousRank;
/*!

*/
	const	Real Distance;
/*!

*/
	const	Real Speed;
/*!

*/
	const	Integer DisplaySpeed;
/*!

*/
	const	Real InputSteer;
/*!

*/
	const	Real InputGasPedal;
/*!

*/
	const	Boolean InputIsBraking;
/*!

*/
	const	Real EngineRpm;
/*!

*/
	const	Integer EngineCurGear;
/*!

*/
	const	Real EngineTurboRatio;
/*!

*/
	const	Integer WheelsContactCount;
/*!

*/
	const	Integer WheelsSkiddingCount;
/*!

*/
	const	Real DamageHullRatio;
/*!

*/
	const	Real DamageWindowRatio;
/*!

*/
	const	Integer InWaterDuration;
/*!

*/
	const	Integer FreeWheelingDuration;
/*!

*/
	const	Integer FlyingDuration;
/*!

*/
	const	Integer SparklingDuration;
/*!

*/
	const	Integer LightTrailsDuration;
/*!

*/
	const	Integer SkiddingDuration;
/*!

*/
	const	Real SkiddingDistance;
/*!

*/
	const	Real FlyingDistance;
/*!

*/
	const	Boolean BonusModeIsJump;
/*!

*/
	const	Boolean BonusModeIsTurbo;
/*!

*/
	const	Boolean BonusModeIsMiniCar;
/*!

*/
	const	Boolean BonusModeIsBigCar;
/*!

*/
	const	Boolean BonusModeIsEmptyCars;
/*!

*/
	const	Boolean BonusModeIsSpeedyCars;
/*!

*/
	const	Boolean BonusModeIsGold;
/*!

*/
	const	Integer BonusModeEmptyCarsStock;
/*!

*/
	const	Integer BonusModeTurboStock;
/*!

*/
	const	Integer BonusModeJumpStock;
/*!

*/
	const	Integer BonusBumpCooldown;
/*!

*/
	const	Boolean BonusIsPossible;
/*!

*/
	const	Integer BonusModeTimeTillEvent;
/*!

*/
	const	Integer BonusModeTimeTillEndEvent;
/*!

*/
	const	Integer BonusModeTimeTillEventWarning;
/*!

*/
	const	ETmBonusModeEventType BonusModeEventType;
/*!

*/
	const	Boolean BonusModeEventIsGold;
/*!

*/
	const	Integer StuntLastTime;
/*!

*/
	const	Integer StuntPoints;
/*!

*/
	const	Integer StuntCombo;
/*!

*/
	const	Boolean StuntPerfectLanding;
/*!

*/
	const	Boolean StuntMasterLanding;
/*!

*/
	const	Boolean StuntEpicLanding;
/*!

*/
	const	ESceneVehiclePhyStuntFigure StuntLast;
/*!

*/
	const	Integer StuntTurboGauge;
/*!

*/
	const	Integer StuntTurboGaugeMax;
/*!

*/
	const	Integer TimeElapsedSinceLastStunt;
/*!

*/
	const	Integer StuntAngle;
/*!

*/
	const	Integer UniqueCameraRespawnCount;
/*!

*/
	const	Integer UniqueCameraAvailableRespawnLeft;
/*!

*/
	const	Integer TimeLeftForStuntCombo;
/*!

*/
	const	Integer TimeTillSmashRespawn;
/*!

*/
	const	Integer TimeTillSmashGiveUp;
/*!

*/
	const	Boolean SmashNeedHelp;
/*!

*/
	const	Boolean StuntStickNeedHelp;
/*!

*/
	const	Boolean StuntJumpNeedHelp;
/*!

*/
	const	Real StuntJumpCharge;
/*!

*/
	const	Real StuntMasterCharge;
/*!

*/
	const	Real StuntEpicCharge;
/*!

*/
			Void StuntStateReset();
/*!

*/
	const	Integer TimeBeforeDeadlyZone;
/*!

*/
	const	Boolean IsDeadlyZoneActive;
};

/*!

*/
struct CTmRaceClientEvent : public CNod {
	enum EType {
		Unknown,
		WayPoint,
		Respawn,
		Turbo,
		Horn,
		Impact,
		WaterSplash,
		GlassSmash,
		PartDetached,
		StopEngine,
		StartEngine,
		AirSpawnRelease,
	};
/*!

*/
	const	EType Type;
/*!

*/
	const	CTmMlPlayer Player;
/*!

*/
	const	Integer CheckpointInRace;
/*!

*/
	const	Integer CheckpointInLap;
/*!

*/
	const	Boolean IsEndRace;
/*!

*/
	const	Boolean IsEndLap;
/*!

*/
	const	Integer RaceTime;
/*!

*/
	const	Integer LapTime;
/*!

*/
	const	Integer StuntsScore;
/*!

*/
	const	Integer NbRespawns;
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
Player for CTmMode.
*/
struct CTmPlayer : public CPlayer {
	enum ETmRacePlayerCoopMode {
		None,
		Symbiosys,
		Checkpoint,
	};
	enum ETmJumpMode {
		Disabled,
		Simple,
		Double,
		Infinite,
	};
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
			Ident ForceModelId;
/*!

*/
			Real AccelCoef;
/*!

*/
			Real ControlCoef;
/*!

*/
			Real GravityCoef;
/*!

*/
			ETmRacePlayerCoopMode CoopMode;
/*!

*/
			Integer ControllerCount;
/*!

*/
			Integer ControllerId0;
/*!

*/
			Integer ControllerId1;
/*!

*/
			Integer ControllerId2;
/*!

*/
			Integer ControllerId3;
/*!

*/
			Boolean ForcedAerialCamera;
/*!

*/
			Boolean ButtonSmashFrenzy;
/*!

*/
			Boolean EnableTurboButton;
/*!

*/
			Boolean MaxiAirControl;
/*!

*/
			Boolean EnableEmptyCars;
/*!

*/
			ETmJumpMode JumpMode;
/*!

*/
			Boolean TinyCar;
/*!

*/
			Boolean EnableCatchUpSpeed;
/*!

*/
			Boolean EnableStuntMode;
/*!

*/
			Boolean EnableOnlineMode;
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
/*!

*/
			Boolean DisablePreload;
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
This is a video playback handle.
*/
struct CVideo : public CNod {
	enum ETextureFilter {
		Default,
		Point,
	};
/*!

*/
	const	CImage Image;
/*!

*/
			Boolean IsLooping;
/*!

*/
	const	Boolean DownloadInProgress;
/*!

*/
	const	Real PlayLength;
/*!

*/
			Void BeginProcessing();
/*!

*/
			Void EndProcessing();
/*!

*/
	const	Boolean IsProcessing;
/*!
Automatically begin processing when the layer becomes visible and end when hidden.
*/
			Boolean AutoProcessing;
/*!

*/
			Void Play();
/*!

*/
			Void Pause();
/*!

*/
			Void Stop();
/*!

*/
	const	Boolean IsPlaying;
/*!

*/
			Real PlayCursor;
/*!

*/
			ETextureFilter TextureFilter;
};

/*!

*/
struct CAudioSource : public CNod {
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
			Real FadeDuration;
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
			Vec3 PanRadiusLfe;
/*!

*/
			Real PlayCursor;
/*!

*/
	const	Real PlayLength;
};

/*!

*/
struct CAudioSourceMusic : public CAudioSource {
	enum EUpdateMode {
		Cut,
		OnNextBar,
		OnNextHalfBar,
		OnNextBeat,
	};
/*!

*/
			Real[] Tracks_Volume;
/*!

*/
			Real[] Tracks_VolumedB;
/*!

*/
	const	Text[] Tracks_Name;
/*!

*/
	const	Real[] Tracks_Length;
/*!

*/
	const	Integer Tracks_Count;
/*!

*/
	const	Real BeatsPerMinute;
/*!

*/
	const	Real BeatDuration;
/*!

*/
	const	Integer BeatsPerBar;
/*!

*/
			EUpdateMode UpdateMode;
/*!

*/
			Boolean Dbg_ForceIntensity;
/*!

*/
			Boolean Dbg_ForceSequential;
/*!

*/
			Boolean Dbg_ForceRandom;
/*!
Values in range (0.000000-1.000000)
*/
			Real LPF_CutoffRatio;
/*!
Values in range (0.100000-20.000000)
*/
			Real LPF_Q;
/*!
Values in range (0.000000-1.000000)
*/
			Real HPF_CutoffRatio;
/*!
Values in range (0.100000-20.000000)
*/
			Real HPF_Q;
/*!

*/
			Real FadeTracksDuration;
/*!

*/
			Real FadeFiltersDuration;
/*!

*/
			Void MuteAllTracks();
/*!

*/
			Void UnmuteAllTracks();
/*!

*/
			Void NextVariant();
/*!

*/
			Void NextVariant(Boolean IsIntensityDecreasing);
/*!

*/
			Void EnableSegment(Text SegmentName);
/*!

*/
			Boolean UseNewImplem;
};

/*!

*/
struct CInputEvent : public CNod {
	enum EType {
		PadButtonPress,
	};
	enum EButton {
		Left,
		Right,
		Up,
		Down,
		A,
		B,
		X,
		Y,
		L1,
		R1,
		LeftStick,
		RightStick,
		Menu,
		View,
		LeftStick_Left,
		LeftStick_Right,
		LeftStick_Up,
		LeftStick_Down,
		RightStick_Left,
		RightStick_Right,
		RightStick_Up,
		RightStick_Down,
		L2,
		R2,
		None,
	};
/*!

*/
	const	EType Type;
/*!

*/
	const	CInputPad Pad;
/*!

*/
	const	EButton Button;
/*!

*/
	const	Boolean IsAutoRepeat;
/*!

*/
	const	Integer KeyCode;
/*!

*/
	const	Text KeyName;
};

/*!
game controller.
*/
struct CInputPad : public CNod {
	enum EButton {
		Left,
		Right,
		Up,
		Down,
		A,
		B,
		X,
		Y,
		L1,
		R1,
		LeftStick,
		RightStick,
		Menu,
		View,
		LeftStick_Left,
		LeftStick_Right,
		LeftStick_Up,
		LeftStick_Down,
		RightStick_Left,
		RightStick_Right,
		RightStick_Up,
		RightStick_Down,
		L2,
		R2,
		None,
	};
	enum EPadType {
		Keyboard,
		Generic,
		XBox,
		PlayStation,
		Vive,
	};
/*!

*/
	const	Integer ControllerId;
/*!

*/
	const	Ident UserId;
/*!

*/
	const	EPadType Type;
/*!

*/
	const	Text ModelName;
/*!

*/
	const	Integer IdleDuration;
/*!

*/
	const	Integer Left;
/*!

*/
	const	Integer Right;
/*!

*/
	const	Integer Up;
/*!

*/
	const	Integer Down;
/*!

*/
	const	Integer A;
/*!

*/
	const	Integer B;
/*!

*/
	const	Integer X;
/*!

*/
	const	Integer Y;
/*!

*/
	const	Integer L1;
/*!

*/
	const	Integer R1;
/*!

*/
	const	Integer LeftStickBut;
/*!

*/
	const	Integer RightStickBut;
/*!

*/
	const	Integer Menu;
/*!

*/
	const	Integer View;
/*!
Values in range (-1.000000-1.000000)
*/
	const	Real LeftStickX;
/*!
Values in range (-1.000000-1.000000)
*/
	const	Real LeftStickY;
/*!
Values in range (-1.000000-1.000000)
*/
	const	Real RightStickX;
/*!
Values in range (-1.000000-1.000000)
*/
	const	Real RightStickY;
/*!
Values in range (0.000000-1.000000)
*/
	const	Real L2;
/*!
Values in range (0.000000-1.000000)
*/
	const	Real R2;
/*!

*/
	const	EButton[] ButtonEvents;
/*!

*/
			Void ClearRumble();
/*!
Duration = 0 --> forever.
*/
			Void AddRumble(Integer Duration,Real LargeMotor,Real SmallMotor);
/*!
(only works on PS4.)  set to (0,0,0) to reset back to default color.
*/
			Void SetColor(Vec3 Color);
};

/*!

*/
struct CMapInfo : public CNod {
/*!

*/
	const	Text MapUid;
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
	const	Boolean IsPlayable;
/*!

*/
	const	Integer TMObjective_AuthorTime;
/*!

*/
	const	Integer TMObjective_GoldTime;
/*!

*/
	const	Integer TMObjective_SilverTime;
/*!

*/
	const	Integer TMObjective_BronzeTime;
/*!

*/
	const	Boolean TMObjective_IsLapRace;
/*!

*/
	const	Text Name;
/*!

*/
	const	Text Path;
/*!

*/
	const	Text FileName;
};

/*!

*/
struct CHighScore : public CNod {
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
	const	Text Name;
/*!

*/
	const	Integer Time;
/*!

*/
	const	Text Score;
/*!

*/
	const	Integer Rank;
/*!

*/
	const	Integer Count;
/*!

*/
	const	Text GhostUrl;
/*!

*/
	const	EMedal Medal;
/*!

*/
	const	Text GhostName;
};

/*!

*/
struct CGhost : public CNod {
	enum EDataState {
		Ready,
		InProgress,
		Error,
	};
/*!

*/
	const	EDataState DataState;
/*!

*/
	const	CTmResult RaceResult;
/*!

*/
			Text Nickname;
};

/*!
Asynchronous task result.
*/
struct CWebServicesTaskResult : public CNod {
	enum ETaskErrorType {
		Success,
		Canceled,
		Unexpected,
		Internal,
		DataManager,
		PrivilegeManager,
		MasterServer,
		UbiServices,
		UplayPC,
		PS4,
		XboxOne,
	};
/*!

*/
	const	Ident Id;
/*!
Returns a boolean indicating if the task is still processing.
*/
	const	Boolean IsProcessing;
/*!
Returns a boolean indicating if the task has succeeded.
*/
	const	Boolean HasSucceeded;
/*!
Returns a boolean indicating if the task has failed or has been canceled.
*/
	const	Boolean HasFailed;
/*!
Returns a boolean indicating if the task has been canceled.
*/
	const	Boolean IsCanceled;
/*!
Returns the type of the error if the task has failed.
*/
	const	ETaskErrorType ErrorType;
/*!
Returns the code of the error if the task has failed.
*/
	const	Integer ErrorCode;
/*!
Returns the description of the error if the task has failed.
*/
	const	Text ErrorDescription;
/*!

*/
			Void Cancel();
};

/*!
Asynchronous task result.
*/
struct CWebServicesTaskResult_GhostHandle : public CWebServicesTaskResult {
};

/*!
List of all buddies record for a map.
*/
struct CWebServicesTaskResult_BuddiesChallengeRecord : public CWebServicesTaskResult {
/*!
Login of the user who has launched the task.
*/
	const	Text Login;
/*!

*/
	const	CHighScoreComparison[] BuddiesChallengeRecord;
/*!
Sort the results by opponent record count.
*/
			Void SortByOpponentCount();
/*!
Sort the results by opponent display name.
*/
			Void SortByOpponentDisplayName();
/*!
Sort the results by opponent login.
*/
			Void SortByOpponentLogin();
/*!
Sort the results by opponent record date.
*/
			Void SortByOpponentRecordDate();
/*!
Sort the results by opponent record time.
*/
			Void SortByOpponentRecordTime();
};

/*!
Results for comparison of challenge records with all the buddies.
*/
struct CWebServicesTaskResult_BuddiesChallengeRecordsComparison : public CWebServicesTaskResult {
/*!
Login of the user who has launched the task.
*/
	const	Text Login;
/*!
List of comparison summary between user records and buddy records. Array of CHighScoreComparisonSummary objects.
*/
	const	CHighScoreComparisonSummary[] BuddiesComparison;
/*!
Sort the results by user best record count.
*/
			Void SortByPlayerCount();
/*!
Sort the results by opponent login.
*/
			Void SortByOpponentLogin();
/*!
Sort the results by opponent best record count.
*/
			Void SortByOpponentCount();
/*!
Sort the results by opponent last record date.
*/
			Void SortByOpponentDate();
/*!
Sort the results by opponent display name.
*/
			Void SortByOpponentDisplayName();
};

/*!
Results for comparison of challenge records between a user and one of its buddy.
*/
struct CWebServicesTaskResult_BuddyChallengeRecordsComparison : public CWebServicesTaskResult {
/*!
Login of the user who has launched the task.
*/
	const	Text Login;
/*!
Buddy login.
*/
	const	Text BuddyLogin;
/*!
List of best challenge records for user. Array of CHighScoreComparison objects.
*/
	const	CHighScoreComparison[] PlayerBestRecordsComparison;
/*!
List of best challenge records for buddy. Array of CHighScoreComparison objects.
*/
	const	CHighScoreComparison[] BuddyBestRecordsComparison;
/*!
Sort the results by map name.
*/
			Void SortByMapName();
/*!
Sort the results by record time.
*/
			Void SortByRecordTime();
/*!
Sort the results by record time diff.
*/
			Void SortByRecordTimeDiff();
/*!
Sort the results by record date.
*/
			Void SortByRecordDate();
};

/*!
Results containing a part of the leaderboard.
*/
struct CWebServicesTaskResult_RealLeaderBoard : public CWebServicesTaskResult {
/*!
Starting index.
*/
	const	Integer FromIndex;
/*!
Number of item contained.
*/
	const	Integer Count;
/*!
List of the ranking info. Array of CGameRealLeaderBoardInfo objects.
*/
	const	CGameRealLeaderBoardInfo[] LeaderBoardInfo;
};

/*!
Results of task requesting if the registered login have a privilege.
*/
struct CWebServicesTaskResult_CheckTargetedPrivilegeResultScript : public CWebServicesTaskResult_CheckTargetedPrivilegeResult {
/*!
Add a login to the request. Must be called before starting the task.
*/
			Void AddLogin(Text Login);
/*!
Start the request of privilege.
*/
			Void StartTask();
/*!
Returns true if the player has the privilege.
*/
			Boolean HasPrivilege(Text Login);
/*!
Returns the reason why the user does not have the privilege.
*/
			Text GetDenyReason(Text Login);
};

/*!
Results of task requesting the list of servers where the logins are playing.
*/
struct CGameMasterServerRichPresenceTaskResult_GetOnlinePresenceForPlayersScript : public CGameMasterServerRichPresenceTaskResult_PlayerOnlinePresenceList {
/*!
List of the online presence. Array of CGameMasterServerPlayerOnlinePresenceScript objects.
*/
	const	CGameMasterServerPlayerOnlinePresence[] OnlinePresences;
/*!
Add a login to the request. Must be called before starting the task.
*/
			Void AddLogin(Text Login);
/*!
Start the request for getting the list of servers.
*/
			Void StartTask();
};

/*!
Supported declare modes : Local 

*/
struct CManiaplanetPluginInterface : public CNod {
/*!

*/
	const	Text Name;
/*!

*/
			Void CustomEvent(Text Type,Text[] Data);
/*!

*/
	const	CManiaplanetPluginInterfaceEvent[] PendingEvents;
};

/*!

*/
struct CPlug : public CNod {
};

/*!
Supported declare modes : Local  Persistent 
User playing the game.
*/
struct CGameUserScript : public CNod {
/*!

*/
	const	Text SystemName;
/*!

*/
	const	Text DisplayName;
/*!

*/
	const	Vec3 Color;
/*!

*/
	const	Boolean PersistentIsReady;
/*!

*/
			Void PersistentSave();
/*!

*/
	const	CGameUserProfile Config;
};

/*!
Masterserver user info.
*/
struct CMasterServerUser : public CNetMasterServerUserInfo {
/*!

*/
	const	Boolean NeedToChangeZone;
/*!
Number of level in the full path of the user zone.
*/
	const	Integer ZoneLevelCount;
/*!
Returns the zone path of the indicated level.
*/
			Text GetZone(Integer ZoneLevel);
/*!
Sets the subscription zone.
*/
			Void SetSubscriptionZone(Text Zone);
/*!

*/
	const	Integer MultiInternetPlayTimeLeft;
};

/*!
Results of task requesting the display name of registered login.
*/
struct CWebServicesTaskResult_GetDisplayNameScriptResult : public CWebServicesTaskResult {
/*!
Add a login to the request. Must be called before starting the task.
*/
			Void AddLogin(Text Login);
/*!
Start the request of display name.
*/
			Void StartTask();
/*!
Get a display name for a login. Must be called after the task has succeeded.
*/
			Text GetDisplayName(Text Login);
};

/*!
Asynchronous task result.
*/
struct CWebServicesTaskResult_Session_Get : public CWebServicesTaskResult {
/*!

*/
	const	Text SessionId;
/*!

*/
	const	Text ServerLogin;
/*!

*/
	const	Text ServerPassword;
};

/*!
Results containing a list of child zones of a specified zone.
*/
struct CWebServicesTaskResult_ZoneList : public CWebServicesTaskResult {
/*!
Path of the parent zone.
*/
	const	Text Path;
/*!
Number of child zones.
*/
	const	Integer ZoneCount;
/*!
List of the child zones. Array of CZone objects.
*/
	const	CZone[] Zones;
};

/*!
Results of task launching Uplay and completing action at registration.
*/
struct CWebServicesTaskResult_LaunchUplayScriptResult : public CWebServicesTaskResult {
/*!
Add an action to complete at registration. Must be called before starting the task.
*/
			Void AddActionToComplete(Text ActionId);
/*!
Start the launch of uplay.
*/
			Void StartTask();
};

/*!

*/
struct CServerInfo : public CGameNetServerInfo {
/*!

*/
	const	Text ServerName;
/*!

*/
	const	Text ServerLogin;
/*!

*/
	const	Text JoinLink;
/*!

*/
	const	Text Comment;
/*!

*/
	const	Text ServerVersionBuild;
/*!

*/
	const	Integer PlayerCount;
/*!

*/
	const	Integer MaxPlayerCount;
/*!

*/
	const	Integer SpectatorCount;
/*!

*/
	const	Integer MaxSpectatorCount;
/*!

*/
	const	Real PlayersLevelMin;
/*!

*/
	const	Real PlayersLevelAvg;
/*!

*/
	const	Real PlayersLevelMax;
/*!

*/
	const	Integer ServerLevel;
/*!

*/
	const	Text ServerLevelText;
/*!

*/
	const	Text ModeName;
/*!

*/
	const	Real LadderServerLimitMax;
/*!

*/
	const	Real LadderServerLimitMin;
/*!

*/
	const	Text[] PlayerNames;
/*!

*/
	const	Text[] ChallengeNames;
/*!

*/
	const	Integer NbChallenges;
/*!

*/
	const	Boolean HasBuddies;
/*!

*/
	const	Boolean IsFavourite;
/*!

*/
	const	Boolean IsLobbyServer;
/*!

*/
	const	Boolean IsPrivate;
};

/*!
An event.
*/
struct CGameScriptNotificationsConsumerEvent : public CNod {
	enum EType {
		NewNotification,
		NotificationChanged,
	};
/*!
Type of the event.
*/
	const	EType Type;
/*!
Notification concerned by the event.
*/
	const	CGameScriptNotificationsConsumerNotification Notification;
};

/*!
A Notification.
*/
struct CGameScriptNotificationsConsumerNotification : public CNod {
	enum ENotificationPriority {
		Memo,
		Notice,
		Alarm,
	};
/*!

*/
	const	Text Title;
/*!

*/
	const	Text Description;
/*!

*/
	const	Text ImageUrl;
/*!

*/
	const	ENotificationPriority Priority;
/*!

*/
	const	Boolean HasBeenRead;
/*!

*/
	const	Boolean HasBeenActivated;
/*!
The user has been displayed the Notification for a sufficient time.
*/
			Void SetRead();
/*!
The user has clicked on the Notification.
*/
			Void SetActivated();
};

/*!
Event concerning achievements.
*/
struct CGameAchievementScriptEvent : public CNod {
	enum EType {
		NewAchievement,
	};
/*!
Type of the event.
*/
	const	EType Type;
/*!
When Type==::NewAchievement, this will be the new achievement
*/
	const	CGameAchievementScriptAchievement Achievement;
};

/*!
An achievement earned by a user.
*/
struct CGameAchievementScriptAchievement : public CNod {
/*!
User that earned the achievement.
*/
	const	Ident UserId;
/*!
Description of the achievement.
*/
	const	CGameAchievementScriptAchievementDesc AchievementDesc;
};

/*!
Achievement stat.
*/
struct CGameAchievementScriptStat : public CNod {
/*!
User that owns the stat.
*/
	const	Ident UserId;
/*!
Description of the stat.
*/
	const	CGameAchievementScriptStatDesc StatDesc;
/*!
Value of the stat.
*/
	const	Integer Value;
};

/*!
An achievement's description.
*/
struct CGameAchievementScriptAchievementDesc : public CNod {
/*!

*/
	const	Text TitleId;
/*!
Name of the achievement.
*/
	const	Text DisplayName;
/*!

*/
	const	Text Description;
/*!

*/
	const	Text IconUrl;
};

/*!
Achievement stat.
*/
struct CGameAchievementScriptStatDesc : public CNod {
/*!

*/
	const	Text TitleId;
/*!
Name of the stat.
*/
	const	Text DisplayName;
/*!

*/
	const	Text Description;
};

/*!
Uplay action.
*/
struct CGameAchievementScriptUplayAction : public CNod {
/*!
The identification code of the ActionInfo.
*/
	const	Text ActionId;
/*!
Localized name.
*/
	const	Text Name;
/*!
Localized description.
*/
	const	Text Description;
/*!
Value in Uplay virtual currency.
*/
	const	Integer Value;
};

/*!

*/
struct CGameManiaAppPlaygroundScriptEvent : public CManiaAppEvent {
	enum Type {
		LayerCustomEvent,
		KeyPress,
		(reserved),
		MenuNavigation,
		ChildModuleEvent,
		ParentModuleEvent,
		PlaygroundScriptEvent,
	};
/*!

*/
	const	Text PlaygroundScriptEventType;
/*!

*/
	const	Text[] PlaygroundScriptEventData;
};

/*!
Supported declare modes : Local  Persistent 
API for plugins to get playground info.
*/
struct CPlaygroundClient : public CNod {
/*!
Null when no map loaded.
*/
	const	CMap Map;
/*!

*/
	const	Integer GameTime;
/*!

*/
	const	CUser LocalUser;
/*!

*/
	const	CUIConfig UI;
/*!

*/
	const	CServerInfo ServerInfo;
/*!
Is in spectator mode - may be only for a short time between rounds.
*/
	const	Boolean IsSpectator;
/*!
Client actually desires to spectate instead of playing.
*/
	const	Boolean IsSpectatorClient;
/*!

*/
	const	Boolean UseClans;
/*!

*/
	const	Boolean UseForcedClans;
/*!

*/
	const	Boolean IsLoadingScreen;
/*!

*/
			Void QuitServer(Boolean Silent);
/*!

*/
			Void QuitServerAndSetResult(Boolean Silent,Text Type,Text[] Data);
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
Request change of IsSpectatorClient (not immediate, and it may be refused).
*/
			Void RequestSpectatorClient(Boolean Spectator);
/*!

*/
			Void SetSpectateTarget(Text Player);
/*!

*/
			Void ShowProfile(Text Player);
/*!

*/
			Boolean DisablePlayingStateTracking;
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

*/
struct CCollector : public CNod {
	enum EProdState {
		Aborted,
		GameBox,
		DevBuild,
		Release,
	};
/*!

*/
	const	Text Name;
/*!

*/
			Text PageName;
/*!

*/
			Integer InterfaceNumber;
/*!

*/
	const	CImage Icon;
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
/*!

*/
			Boolean HoldLoadingScreen;
};

/*!

*/
struct CGamePlaygroundModuleServerHud : public CNod {
/*!

*/
			CGamePlaygroundModuleServerInventory Inventory;
/*!

*/
			CGamePlaygroundModuleServerStore Store;
/*!

*/
			CGamePlaygroundModuleServerScoresTable ScoresTable;
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
A player is the incarnation of the user in the playground.
*/
struct CPlayer : public CNod {
/*!

*/
	const	CUser User;
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
			Real ShootRadius;
/*!

*/
			Real TargetMinDistance;
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
	const	CSmPlayer Owner;
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
struct CSmMapBotSpawn : public CNod {
/*!

*/
	const	Boolean IsFlying;
/*!

*/
	const	Ident BotModelId;
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
struct CHighScoreComparison : public CNod {
/*!

*/
	const	CMapInfo MapInfo;
/*!

*/
	const	Text Login;
/*!

*/
	const	Integer RecordTime;
/*!

*/
	const	Integer RecordDate;
/*!

*/
	const	Text RecordDateString;
/*!

*/
	const	Integer RecordElapsedTime;
/*!

*/
	const	Integer RecordCount;
/*!

*/
	const	Text OpponentLogin;
/*!

*/
	const	Text OpponentDisplayName;
/*!

*/
	const	Text OpponentRecordUrl;
/*!

*/
	const	Integer OpponentRecordTime;
/*!

*/
	const	Integer OpponentRecordDate;
/*!

*/
	const	Text OpponentRecordDateString;
/*!

*/
	const	Integer OpponentRecordElapsedTime;
/*!

*/
	const	Integer OpponentRecordCount;
};

/*!

*/
struct CHighScoreComparisonSummary : public CNod {
/*!

*/
	const	Text Login;
/*!

*/
	const	Integer BestRecordCount;
/*!

*/
	const	Integer BestRecordLastDate;
/*!

*/
	const	Text BestRecordLastDateString;
/*!

*/
	const	Integer BestRecordElapsedTime;
/*!

*/
	const	Text OpponentLogin;
/*!

*/
	const	Text OpponentDisplayName;
/*!

*/
	const	Integer OpponentBestRecordCount;
/*!

*/
	const	Integer OpponentBestRecordLastDate;
/*!

*/
	const	Text OpponentBestRecordLastDateString;
/*!

*/
	const	Integer OpponentBestRecordElapsedTime;
};

/*!
Ranking item of a leaderboard.
*/
struct CGameRealLeaderBoardInfo : public CNod {
/*!
Rank.
*/
	const	Integer Rank;
/*!
Login.
*/
	const	Text Login;
/*!
Display name.
*/
	const	Text DisplayName;
/*!
Score.
*/
	const	Real Score;
};

/*!
Asynchronous task result.
*/
struct CWebServicesTaskResult_CheckTargetedPrivilegeResult : public CWebServicesTaskResult {
};

/*!
Asynchronous task result.
*/
struct CGameMasterServerRichPresenceTaskResult_PlayerOnlinePresenceList : public CWebServicesTaskResult {
};

/*!
Online presence
*/
struct CGameMasterServerPlayerOnlinePresence : public CNod {
/*!
Player login.
*/
	const	Text Login;
/*!
Player dsiplay name.
*/
	const	Text DisplayName;
/*!
Login of the server on which the player is.
*/
	const	Text ServerLogin;
/*!
Boolean indicating if the player is online
*/
	const	Boolean IsOnline;
};

/*!

*/
struct CManiaplanetPluginInterfaceEvent : public CNod {
	enum EType {
		PluginCustomEvent,
	};
/*!

*/
	const	EType Type;
/*!

*/
	const	Text EventType;
/*!

*/
	const	Text[] EventData;
};

/*!

*/
struct CGameUserProfile : public CNod {
/*!

*/
			Text SkinName;
/*!

*/
			Vec3 PrimaryColor;
};

/*!
Masterserver user info.
*/
struct CNetMasterServerUserInfo : public CNod {
	enum EFirstPartySignInState {
		Unknown,
		NotSignedUp,
		SignedOut,
		SignedIn,
	};
	enum EMasterServerConnectionStatus {
		NotConnected,
		Connecting,
		Connected,
		Disconnecting,
	};
	enum EMasterServerConnectionDetailedStatus {
		NotConnected,
		CheckingNetworkAvailability,
		CheckingMasterServerConnexion,
		WaitingCredentials,
		CheckingMasterServerWaitingQueue,
		WaitingOnMasterServerQueue,
		WaitingSubscriptionCredentials,
		CheckingSubscriptionCredentials,
		WaitingSubscriptionInfo,
		Subscribe,
		OpeningSession,
		Identifying,
		GettingZones,
		WaitingNewZone,
		ChangingZone,
		GettingOnlineProfile,
		SynchronizingProfileChunks,
		AssociatingKey,
		UpdatingProfile,
		GettingBannedCryptedChecksumsList,
		GettingTitleInfo,
		ConnectingToUbiServices,
		FinalizingConnection,
		Connected,
		Disconnecting,
	};
	enum EMasterServerConnectionError {
		None,
		NetworkNotAvailable,
		FirstPartySignedOut,
		NoUbiServicesSession,
		MasterServerDisabled,
		MasterServerInSafeMode,
		KillSwitchEnabled,
		BetaBanned,
		BetaNotApproved,
		NoUplayPC,
	};
	enum ETaskErrorType {
		Success,
		Canceled,
		Unexpected,
		Internal,
		DataManager,
		PrivilegeManager,
		MasterServer,
		UbiServices,
		UplayPC,
		PS4,
		XboxOne,
	};
/*!

*/
	const	Ident Id;
/*!
Login.
*/
	const	Text Login;
/*!
Display name.
*/
	const	Text DisplayName;
/*!
Connection status: NotConnected, Connecting, Connected or Disconnecting.
*/
	const	EMasterServerConnectionStatus ConnectionStatus;
/*!

*/
	const	ETaskErrorType LastConnectionErrorType;
/*!

*/
	const	Integer LastConnectionErrorCode;
/*!

*/
	const	Text LastConnectionErrorDescription;
/*!
Return if the user has a Uplay profile.
*/
	const	Boolean HasUplayProfile;
/*!
Return if the user has a accepted DNA.
*/
	const	Boolean HasAcceptedNDA;
/*!

*/
	const	CNetUbiServicesNews[] UbiServicesSpaceNews;
/*!

*/
	const	CNetUbiServicesNews[] UbiServicesProfileNews;
};

/*!

*/
struct CZone : public CNod {
/*!

*/
	const	Text Name;
/*!

*/
	const	Text Path;
/*!

*/
	const	Text FullPath;
/*!

*/
	const	Text FlagUrl;
};

/*!

*/
struct CGameNetServerInfo : public CNetMasterHost {
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
struct CGamePlaygroundModuleServerScoresTable : public CGamePlaygroundModuleServer {
/*!

*/
			Void SetFooterText(Text FooterText);
/*!

*/
			Void SetColumnValue(CPlayer Player,Text ColumnName,Text ColumnValue);
/*!

*/
			Void SetColumnValue(CPlayer Player,Text ColumnName,Integer ColumnValue);
/*!

*/
			Void SetColumnValue(CPlayer Player,Text ColumnName,Real ColumnValue);
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
UbiServices news.
*/
struct CNetUbiServicesNews : public CNod {
/*!

*/
	const	Ident Id;
/*!
A globally unique ID for the news item.
*/
	const	Text NewsId;
/*!
There is no predefined value, it is a contract between the producer and the consumer to define game specific.
*/
	const	Text Type;
/*!
Specifies where the news should be placed in-game.
*/
	const	Text Placement;
/*!
Localization string of the news, e.g. "en-US"
*/
	const	Text Locale;
/*!
Localized title of the news
*/
	const	Text Title;
/*!
Localized body of the news
*/
	const	Text Body;
/*!
Link to an image or video to be displayed with the news. Format of the media is placement specific.
*/
	const	Text MediaUrl;
/*!
MIME type of the media object to display.  e.g. "image/png" or "video/mp4"
*/
	const	Text MediaType;
/*!
The priority that should be given to that news.
*/
	const	Integer Priority;
/*!
The minimum time in seconds at which this news item should be displayed.
*/
	const	Integer DisplayTime;
/*!
Returns the date and (UTC) time at which the news was published.
*/
			Integer GetPublicationDate(Integer Month,Integer Day,Integer Hour,Integer Minute,Integer Second);
/*!
The number of links attached to this news. Links are mandatory for given types. For example, DLCOffer should have a mandatory storelink type link.
*/
	const	Integer LinksCount;
/*!
Returns Type, Param, ActionName and ActionDescription of the link. Type allows the game to correctly interpret param. The value may be game-specific but there are the following predefined types: "pstore" means that the param field contains the DLC ID related to the news content, "sstore" means that the param field contains an Offer ID related to an offer being available on the secondary store. "weblink" means that the param field should be an URL to a web page. Param defines the parameter value of the action. For a "pstore" type, value must be the DLC ID of the 1st party store (platform specific). For example, PS3 would look like "UP0001-NPUB90687_00-ACEMBERSVIDEO001", while on Xbox, it would look like: "0x555308796ea1e800". For a "sstore" type, value must be an Offer ID of the secondary store. This depends on the Secondary Store implementation of the game. For a "weblink" type, value must be a valid HTTP address. ActionName is The name of the action for tracking purposes. ActionDescription is the description of the action the game should display. The game must support default descriptions such as "Buy" for a store link.
*/
			Void GetLinkInfo(Integer LinkIndex,Text Type,Text Param,Text ActionName,Text ActionDescription);
};

/*!

*/
struct CNetMasterHost : public CNod {
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
	Real Rand(Real Argument1, Real Argument2, Integer Argument3);
	/*! 
	*
	*/
	Integer Rand(Integer Argument1, Integer Argument2);
	/*! 
	*
	*/
	Integer Rand(Integer Argument1, Integer Argument2, Integer Argument3);
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
	/*! 
	* \brief Returns the modulus of X in the range Min..Max
	* 
	*
	*/
	Real Mod(Real _X, Real _Min, Real _Max);
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
	* \brief Return a string where the previously unclosed $< tags have their $> counterpart
	* 
	*
	*/
	Text CloseStyleTags(Text _String);
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
	* \brief Splits a given text based on a given separators set.
	* 
	* \param _Separators : The separators to use
	* \param _Text : The text to split.
	*
	*/
	Text[Void] Split(Text _Separators, Text _Text);
	/*! 
	* \brief Joins a set of texts with the given separator
	* 
	* \param _Separator : The separator to use
	* \param _Texts : The texts to join.
	*
	*/
	Text Join(Text _Separator, Text[Void] _Texts);
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

