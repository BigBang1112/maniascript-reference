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
			Boolean PageAlwaysUpdateScript;
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
Local user structure.
*/
	const	CUser LocalUser;
/*!

*/
	const	CTitle LoadedTitle;
/*!

*/
	const	CMlScriptEvent[] PendingEvents;
/*!

*/
			Void Dbg_SetProcessed(CMlScriptEvent Event);
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
			Void EnableMenuNavigation(Boolean EnableInputs,Boolean WithAutoFocus,Boolean WithManualScroll,CMlControl AutoBackControl,Integer InputPriority);
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
	const	CParsingManager Xml;
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
	const	CDataFileMgr DataFileMgr;
/*!

*/
	const	CScoreMgr ScoreMgr;
/*!

*/
	const	CAnimManager AnimMgr;
/*!

*/
	const	CSystemPlatform System;
/*!
Send a custom event to the owner of the layer.
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
			Void SetText(Text NewText,Boolean SendSubmitEvent);
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
Manialink filename entry.
*/
struct CMlFileEntry : public CMlEntry {
/*!

*/
			Boolean OnlyUserFiles;
/*!

*/
			Void ClearFileNames();
/*!

*/
	const	Text FullFileName;
/*!

*/
	const	Text RelativeNameToRoot;
/*!

*/
	const	Text RelativeNameToTypeFolder;
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
/*!

*/
			Void RefreshImages();
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
			Boolean DisableAutoUnderground;
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
	enum EBuddyResult {
		Ok,
		Error,
		NotFinished,
	};
/*!
Will be Null if the script is not runing in a layer of an app.
*/
	const	CManiaAppBrowser ParentApp;
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
API for Maniaplanet client scripts.
*/
struct CManiaApp : public CNod {
	enum ELinkType {
		ExternalBrowser,
		ManialinkBrowser,
	};
/*!

*/
	const	Text ManiaAppUrl;
/*!

*/
	const	Text ManiaAppBaseUrl;
/*!

*/
	const	Integer Now;
/*!

*/
	const	Boolean IsVisible;
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
Explore to given file or folder. Returns False if it does not exist on the filesystem. (may be because it is in a pack)
*/
			Boolean OpenFileInExplorer(Text FileName);
/*!

*/
			Void Dialog_Message(Text Message);
/*!

*/
	const	CParsingManager Xml;
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
	const	CDataFileMgr DataFileMgr;
/*!

*/
	const	CScoreMgr ScoreMgr;
/*!

*/
	const	CUserV2Manager UserMgr;
/*!

*/
	const	CSystemPlatform System;
/*!

*/
			Text Dbg_DumpDeclareForVariables(CNod Nod,Boolean StatsOnly);
};

/*!
Supported declare modes : Local  Persistent 
This is the title menus Manialink interface.
*/
struct CManiaAppTitleLayer : public CMlScript {
/*!
Will be Null if the script is not runing in a layer of an app.
*/
	const	CManiaAppTitle ParentApp;
/*!

*/
	const	CTitleControl TitleControl;
};

/*!
Supported declare modes : Local 
An event
*/
struct CManiaAppEvent : public CBaseConstEvent {
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
		AppMenu,
		Action1,
		Action2,
		ScrollUp,
		ScrollDown,
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
API for a Title main menu.
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
			Boolean LoadingScreenRequireKeyPressed;
/*!

*/
			Boolean DontScaleMainMenuForHMD;
/*!

*/
	const	CTitleControl TitleControl;
/*!
Only available when editing a title.
*/
	const	CTitleEdition TitleEdition;
/*!

*/
	const	CNotificationsConsumer Notifications;
/*!

*/
	const	Text ExternalRequest_Type;
/*!

*/
	const	Text[] ExternalRequest_Data;
/*!
Call as soon as the request has been consumed and is being processed.
*/
			Void ExternalRequest_Clear();
/*!

*/
	const	CAchievementsManager AchievementsManager;
/*!

*/
	const	CBadgeManager BadgeManager;
/*!

*/
	const	CMatchSettingsManager MatchSettingsManager;
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
};

/*!
Supported declare modes : Local  Persistent 
This is the client ManiaApp for game modes.
*/
struct CManiaAppPlayground : public CManiaAppPlaygroundCommon {
/*!
Send a custom event to the CMode script.
*/
			Void SendCustomEvent(Text Type,Text[] Data);
};

/*!
Supported declare modes : Local  Persistent 
Station mania app.
*/
struct CManiaAppStation : public CManiaAppBase {
/*!

*/
	const	CStation Station;
/*!

*/
			Void EnterStation();
/*!

*/
			Void Maker_EditTitle(Text EditedTitleId);
/*!
A new title id will be derived from the EditedTitleName.
*/
			Void Maker_EditNewTitle(Text EditedTitleName);
/*!

*/
	const	CPackCreatorTitleInfo[] Maker_EditedTitles;
};

/*!

*/
struct CModulePlayground : public CNod {
/*!

*/
			Void Hide();
/*!

*/
			Void Hide(CUIConfig UIConfig);
/*!

*/
			Void Show();
/*!

*/
			Void Show(CUIConfig UIConfig);
/*!

*/
			Boolean IsVisible(CUIConfig UIConfig);
};

/*!

*/
struct CModulePlaygroundInventory : public CModulePlayground {
/*!

*/
			Integer AddItem(CPlayer Player,Text Url,Integer Quantity);
/*!

*/
			Boolean AddAction(CPlayer Player,Text Url);
/*!

*/
			Integer RemoveInventoryItem(CPlayer Player,Text Url,Integer Quantity);
/*!

*/
			Integer GetInventoryItemQuantity(CPlayer Player,Text Url);
/*!

*/
			Boolean IsInventoryItemStored(CPlayer Player,Text Url);
/*!

*/
			Text[] GetStoredItemsList(CPlayer Player);
/*!

*/
			Text[] GetStoredActionsList(CPlayer Player);
};

/*!
An playground Store module.
*/
struct CModulePlaygroundStore : public CModulePlayground {
/*!

*/
			Void Reset();
/*!

*/
			Void Reset(CPlayer Player);
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
/*!

*/
			Void SetItemCanBeBought(CPlayer Player,Text ActionUrl,Boolean CanBeBought);
/*!

*/
			Boolean GetItemCanBeBought(CPlayer Player,Text ActionUrl);
};

/*!

*/
struct CModulePlaygroundScoresTable : public CModulePlayground {
	enum EColumnType {
		CustomString,
		CustomNatural,
		CustomInteger,
		CustomReal,
		CustomTime,
		Avatar,
		Name,
		ManiaStars,
		Tools,
		Tags,
		TMBestTime,
		TMPrevTime,
		TMBestLapTime,
		TMStunts,
		TMRespawns,
		TMCheckpoints,
		TMPoints,
		TMPrevRaceDeltaPoints,
		SMPoints,
		SMRoundPoints,
	};
	enum EScoreSortOrder {
		Default,
		Name,
		LadderRanking,
		TMPoints,
		TMBestTime,
		TMStunts,
		TMRespawns,
		TMCheckpoints,
		TMPrevTime,
		SMPoints,
		SMRoundPoints,
	};
/*!

*/
			Void SetFooterText(Text FooterText);
/*!

*/
			Void ResetCustomColumns(CScore Score);
/*!

*/
			Void ResetCustomColumns();
/*!

*/
			Void Scores_Sort(EScoreSortOrder SortOrder);
/*!

*/
			Void SetColumnValue(CScore Score,Text ColumnId,Text ColumnValue);
/*!

*/
			Void SetColumnValue(CScore Score,Text ColumnId,Integer ColumnValue);
/*!

*/
			Void SetColumnValue(CScore Score,Text ColumnId,Real ColumnValue);
/*!

*/
			Void SetColumnVisibility(EColumnType Type,Boolean Visibility);
/*!

*/
			Void SetColumnVisibility(Text ColumnId,Boolean Visibility);
/*!

*/
			Void SetColor(CScore Score,Vec3 Color);
/*!

*/
			Void ResetColor(CScore Score);
};

/*!

*/
struct CModulePlaygroundChrono : public CModulePlayground {
/*!

*/
			Void StopChrono();
/*!

*/
			Void StartChrono();
/*!

*/
			Void Reset();
/*!

*/
			Void Reset(CPlayer Player);
};

/*!

*/
struct CModulePlaygroundSpeedMeter : public CModulePlayground {
/*!

*/
			Void Reset(CPlayer Player);
/*!

*/
			Void SetGlobalScale(Real Scale);
/*!

*/
			Void SetGaugeNumber(Integer Number);
/*!

*/
			Void SetGaugeAngle(Real Angle);
/*!

*/
			Void SetGaugeBGVisible(Boolean Visibility);
/*!

*/
			Void SetSpeedLineVisible(Boolean Visibility);
/*!

*/
			Void SetGaugeSpeedMax(Real Maximum);
/*!

*/
			Void SetSpeedValueScale(Real Scale);
/*!

*/
			Void SetSpeedUnitScale(Real Scale);
/*!

*/
			Void SetFooterUnitVisible(Boolean Visibility);
/*!

*/
			Void SetFooterLineVisible(Boolean Visibility);
/*!

*/
			Void SetDistanceVisible(Boolean Visibility);
/*!

*/
			Void SetDistanceFooterLineVisible(Boolean Visibility);
};

/*!

*/
struct CModulePlaygroundPlayerState : public CModulePlayground {
/*!

*/
			Void Reset(CPlayer Player);
};

/*!

*/
struct CModulePlaygroundTeamState : public CModulePlayground {
/*!

*/
			Void Reset(CPlayer Player);
};

/*!
Supported declare modes : Local  Persistent 

*/
struct CModuleMenu : public CManiaAppTitle {
/*!

*/
			Void Menu_Goto(Text PageId);
/*!

*/
			Void Menu_Back();
/*!

*/
			Void Menu_Previous();
/*!

*/
			Void Menu_Quit();
};

/*!

*/
struct CModuleMenuComponent : public CNod {
/*!

*/
	const	CUILayer ComponentLayer;
/*!

*/
			Void Hide();
/*!

*/
			Void Show();
};

/*!
Supported declare modes : Local  Persistent 
This is the title menus Manialink interface.
*/
struct CModuleMenuLayer : public CManiaAppTitleLayer {
/*!

*/
	const	CModuleMenuComponent[] Components;
/*!

*/
			CModuleMenuComponent GetFirstComponent(Text Name);
};

/*!

*/
struct CModuleMenuFileBrowser : public CModuleMenuComponent {
	enum EFileType {
		Maps,
		Skins,
		Items,
		Blocks,
		Scripts,
		Images,
		Manialinks,
		Packs,
		Actions,
		Modules,
		Meshes,
		Replays,
	};
	enum EFileAction {
		Select,
		Save,
		MultiSelect,
	};
/*!

*/
	const	Boolean HasFinished;
/*!

*/
	const	Text[] Selection;
/*!

*/
			Void SetFileType(EFileType FileType);
/*!

*/
			Void SetFileAction(EFileAction FileAction);
};

/*!
Station info & manipulation.
*/
struct CStation : public CNod {
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
/*!

*/
	const	EEchelon Echelon;
/*!

*/
	const	Integer NextEchelonPercent;
/*!

*/
			Boolean DisableQuickEnter;
/*!

*/
			Boolean IsLogoVisible;
/*!

*/
			Real GhostAlpha;
/*!

*/
			Vec3 FocusLightColor;
/*!

*/
			Vec3 NormalLightColor;
/*!
Is title present in WorkTitles folder?
*/
	const	Boolean IsEditable;
};

/*!
Supported declare modes : Local  Persistent 
This is the stations Manialink interface.
*/
struct CMlStation : public CMlScript {
/*!
Will be Null if the script is not runing in a layer of an app.
*/
	const	CManiaAppStation ParentApp;
/*!

*/
	const	CStation Station;
/*!

*/
			Void EnterStation();
};

/*!
Supported declare modes : Local  Persistent 
API for editor plugins.
*/
struct CEditorMainPlugin : public CAnyEditorPlugin {
	enum EMeshEditorAPI {
		Materials,
		Interactions,
		Display,
		Global,
		Sets,
		Voxel,
		PickInfo,
		UndoRedo,
	};
/*!

*/
			Void Help_Open();
/*!

*/
			Void Help_Close();
/*!

*/
			CEditorPluginHandle GetPluginHandle(Text Name);
/*!

*/
			Void SendPluginEvent(CEditorPluginHandle Handle,Text Type,Text[] Data);
/*!

*/
			Void Context_SetActive(Text ContextName,Boolean IsActive);
/*!

*/
			Boolean Context_IsActive(Text ContextName);
/*!

*/
			Boolean Binding_IsActive(Text BindingName);
/*!

*/
			Boolean Binding_IsActive(Text ContextName,Text BindingName);
/*!

*/
			Void Plugin_SetClearance(CEditorPluginHandle Handle,EMeshEditorAPI API,Boolean IsAllowed);
/*!

*/
	const	CEditorPluginHandle[] Plugins;
};

/*!
Supported declare modes : Local  Persistent 
API for editor plugins.
*/
struct CAnyEditorPlugin : public CManiaApp {
	enum EInteractionStatus {
		Active,
		Closed,
		Aborted,
	};
/*!

*/
	const	CManiaAppEvent[] PendingEvents;
/*!

*/
	const	CEditorModule ModuleEditor;
/*!

*/
	const	CEditorMesh MeshEditor;
/*!

*/
	const	CEditorEditor EditorEditor;
/*!

*/
	const	EInteractionStatus InteractionStatus;
};

/*!
Supported declare modes : Local  Persistent 
API for the plugins of the map editor.
*/
struct CMapEditorPlugin : public CManiaApp {
	enum CardinalDirections {
		North,
		East,
		South,
		West,
	};
	enum CardinalDirections8 {
		North,
		East,
		South,
		West,
		NorthEast,
		SouthEast,
		SouthWest,
		NorthWest,
	};
	enum RelativeDirections {
		Forward,
		RightForward,
		Right,
		RightBackward,
		Backward,
		LeftBackward,
		Left,
		LeftForward,
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
		Light,
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
/*!

*/
	const	CMapEditorPluginEvent[] PendingEvents;
/*!

*/
	const	CMap Map;
/*!

*/
	const	Text MapName;
/*!

*/
	const	Text MapFileName;
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
			Void DisplayDefaultSetObjectivesDialog();
/*!

*/
			Boolean Undo();
/*!

*/
			Boolean Redo();
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

*/
			Void TestMapWithMode(Text RulesModeName);
/*!

*/
			Void TestMapWithMode(Text RulesModeName,Text SettingsXml);
/*!

*/
			Void TestMapWithMode_SplitScreen(Text RulesModeName);
/*!

*/
			Void TestMapWithMode_SplitScreen(Text RulesModeName,Integer ScreenCount);
/*!

*/
			Void TestMapWithMode_SplitScreen(Text RulesModeName,Integer ScreenCount,Integer FakeCount,Text SettingsXml);
/*!

*/
			Boolean EnableMapTypeStartTest;
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
	const	CMapEditorInventory Inventory;
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
			CBlock GetBlock(CBlockModel BlockModel,Int3 Coord,CardinalDirections Dir);
/*!

*/
			Boolean IsBlockModelSkinnable(CBlockModel BlockModel);
/*!

*/
			Integer GetNbBlockModelSkins(CBlockModel BlockModel);
/*!

*/
			Text GetBlockModelSkin(CBlockModel BlockModel,Integer SkinIndex);
/*!

*/
			Text GetSkinDisplayName(Text SkinFileName);
/*!

*/
			Text GetBlockSkin(CBlock Block);
/*!

*/
			Void SetBlockSkin(CBlock Block,Text SkinFileName);
/*!

*/
			Boolean IsMacroblockModelSkinnable(CMacroblockModel BlockModel);
/*!

*/
			Boolean SetMacroblockSkin(CMacroblockInstance Macroblock,Text SkinFileName);
/*!

*/
			Boolean OpenBlockSkinDialog(CBlock Block);
/*!

*/
			Boolean RemoveBlock(Int3 Coord);
/*!

*/
			Boolean RemoveBlock(CBlockModel BlockModel,Int3 Coord,CardinalDirections Dir);
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
			CBlockClipList CreateFrameClipList();
/*!

*/
			CBlockClipList CreateFixedClipList();
/*!

*/
			Void UnvalidateMetadata();
/*!

*/
			Void UnvalidateGameplayInfo();
/*!

*/
			Void UnvalidatePlayfield();
/*!

*/
			Boolean RemoveMacroblock_NoTerrain_NoUnvalidate(CMacroblockModel MacroblockModel,Int3 Coord,CardinalDirections Dir);
/*!

*/
			Boolean PlaceMacroblock_NoTerrain_NoUnvalidate(CMacroblockModel MacroblockModel,Int3 Coord,CardinalDirections Dir);
/*!

*/
			Void GetConnectResults(CBlock ExistingBlock,CBlockModel NewBlock);
/*!

*/
			Void GetConnectResults(CBlock ExistingBlock,CMacroblockModel NewBlock);
/*!

*/
			Void GetConnectResults(CMacroblockInstance ExistingBlock,CBlockModel NewBlock);
/*!

*/
			Void GetConnectResults(CMacroblockInstance ExistingBlock,CMacroblockModel NewBlock);
/*!

*/
			Integer GetStartBlockCount(Boolean IncludeMultilaps);
/*!

*/
			Integer GetFinishBlockCount(Boolean IncludeMultilaps);
/*!

*/
			Integer GetMultilapBlockCount();
/*!

*/
			Integer GetCheckpointBlockCount();
/*!

*/
			CMacroblockInstance CreateMacroblockInstance(CMacroblockModel MacroblockModel,Int3 Coord,CardinalDirections Dir);
/*!

*/
			CMacroblockInstance CreateMacroblockInstance(CMacroblockModel MacroblockModel,Int3 Coord,CardinalDirections Dir,Integer UserData);
/*!

*/
			CMacroblockInstance CreateMacroblockInstance(CMacroblockModel MacroblockModel,Int3 Coord,CardinalDirections Dir,CBlockClipList DefaultClipList);
/*!

*/
			CMacroblockInstance CreateMacroblockInstance(CMacroblockModel MacroblockModel,Int3 Coord,CardinalDirections Dir,CBlockClipList DefaultClipList,Integer UserData);
/*!

*/
			CMacroblockInstance GetMacroblockInstanceFromOrder(Integer Order);
/*!

*/
			CMacroblockInstance GetMacroblockInstanceFromUnitCoord(Int3 Coord);
/*!

*/
			CMacroblockInstance GetLatestMacroblockInstance();
/*!

*/
			CMacroblockInstance GetLatestMacroblockInstance(Integer Offset);
/*!

*/
			CMacroblockInstance GetMacroblockInstanceConnectedToClip(CBlockClip Clip);
/*!

*/
			Boolean RemoveMacroblockInstance(CMacroblockInstance MacroblockInstance);
/*!

*/
			Boolean RemoveMacroblockInstanceFromOrder(Integer Order);
/*!

*/
			Boolean RemoveMacroblockInstanceFromUnitCoord(Integer Order);
/*!

*/
			Boolean RemoveMacroblockInstancesByUserData(Integer UserData);
/*!

*/
			Void ResetAllMacroblockInstances();
/*!

*/
			Integer GetMaxOrder();
/*!

*/
			Boolean SetMapType(Text MapType);
/*!

*/
			Text GetMapType();
/*!

*/
			Void SetMapStyle(Text MapStyle);
/*!

*/
			Text GetMapStyle();
/*!

*/
			Void SetMapIsCreatedWithPartyEditor(Boolean IsCreatedWithPartyEditor);
/*!

*/
			Text GetAvailableMapName();
/*!

*/
			Vec3 GetVec3FromCoord(Int3 Coord);
/*!

*/
	const	CMapEditorCamera Camera;
/*!

*/
	const	CMapEditorCursor Cursor;
/*!

*/
	const	CItemAnchor[] Items;
/*!

*/
	const	Text[] MediatrackIngameClips;
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
	const	CBlock[] ClassicBlocks;
/*!

*/
	const	CBlock[] TerrainBlocks;
/*!

*/
	const	CBlockClipList[] FixedClipLists;
/*!

*/
	const	CBlockClipList[] FrameClipLists;
/*!

*/
	const	CBlockClipList[] MacroblockInstanceClipLists;
/*!

*/
	const	CMacroblockInstance[] MacroblockInstances;
/*!

*/
	const	CMapEditorConnectResults[] ConnectResults;
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

*/
	const	Boolean IsTesting;
/*!

*/
	const	Boolean IsValidating;
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
struct CMapEditorPluginLayer : public CMlScript {
/*!

*/
	const	CMapEditorPlugin Editor;
};

/*!
Supported declare modes : Local  Persistent 
API for Maniaplanet client scripts.
*/
struct CBadgeEditor : public CManiaAppBase {
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
Supported declare modes : Local  Persistent 
Server plugin
*/
struct CServerPlugin : public CNod {
/*!

*/
	const	CTitle LoadedTitle;
/*!

*/
	const	CMapInfo MapInfo;
/*!

*/
			CClient GetClient(Text Login);
/*!

*/
			CClient GetClient(CUIConfig UI);
/*!
Currently connected Users.
*/
	const	CClient[] Clients;
/*!
Users connected as spectators.
*/
	const	CClient[] Spectators;
/*!
Users connected as players.
*/
	const	CClient[] Players;
/*!
Sorted scores.
*/
	const	CScore[] Scores;
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
			Text ForcedClubLinkUrl1;
/*!

*/
			Text ForcedClubLinkUrl2;
/*!

*/
			Void TweakTeamColorsToAvoidHueOverlap();
/*!

*/
	const	Integer Now;
/*!

*/
	const	CServerPluginEvent[] PendingEvents;
/*!

*/
			Void TriggerModeScriptEvent(Text Type,Text[] Data);
/*!

*/
			Void SendModeScriptCommand(Text CommandName,Boolean BoolVal);
/*!

*/
			Void SendModeScriptCommand(Text CommandName,Integer IntVal);
/*!

*/
			Void SendModeScriptCommand(Text CommandName,Real RealVal);
/*!

*/
			Void SendModeScriptCommand(Text CommandName,Text TextVal);
/*!

*/
	const	Boolean MapLoaded;
/*!

*/
	const	Boolean MapUnloadRequested;
/*!

*/
	const	CMapInfo[] MapList;
/*!

*/
	const	Integer CurMapIndex;
/*!

*/
			Integer NextMapIndex;
/*!

*/
			Void RestartMap();
/*!

*/
			Void NextMap();
/*!

*/
			Boolean HoldMapUnloadRequest;
/*!
Enable minimap on the clients, even if the mode does not do it.
*/
			Boolean Client_ComputeMinimap;
/*!

*/
	const	CUIConfigMgr UIManager;
/*!

*/
	const	CServerAdmin ServerAdmin;
/*!

*/
	const	CXmlRpc XmlRpc;
/*!

*/
	const	CParsingManager Xml;
/*!

*/
	const	CHttpManager Http;
/*!

*/
	const	CSystemPlatform System;
/*!

*/
			Text Dbg_DumpDeclareForVariables(CNod Nod,Boolean StatsOnly);
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
		Missile,
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
			Boolean UseMultiClans;
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
			CSmPlayer GetPlayer(CUIConfig UI);
/*!

*/
			CSmPlayer GetPlayer(Text Login);
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
			Void SpawnPlayer(CSmPlayer Player,Integer ClanNum,Integer Armor,CMapSpawn PlayerSpawn,Integer ActivationDate);
/*!

*/
			Void SpawnPlayer(CSmPlayer Player,Integer ClanNum,CModeTurret Turret,Integer ActivationDate);
/*!

*/
			Void SpawnPlayer(CSmPlayer Player,Integer ClanNum,CModeVehicle Vehicle,Integer ActivationDate);
/*!

*/
			Void SpawnPlayer(CSmPlayer Player,Integer ClanNum,CModeVehicle Vehicle,Integer SlotIndex,Integer ActivationDate);
/*!

*/
			Void SpawnBotPlayer(CSmPlayer Player,Integer ClanNum,Integer Armor,CMapSpawn PlayerSpawn,Integer ActivationDate);
/*!

*/
			Void SpawnBotPlayer(CSmPlayer Player,Integer ClanNum,Integer Armor,CMapBotPath BotPath,Integer ActivationDate);
/*!

*/
			Void SpawnBotPlayer(CSmPlayer Player,Integer ClanNum,Integer Armor,CMapBotSpawn BotSpawn,Integer ActivationDate);
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
			Void AddArmor(CEntity Victim,Integer DeltaArmor,CEntity Shooter,Integer ShooterPoints);
/*!

*/
			Void RemoveArmor(CEntity Victim,Integer DeltaArmor,CEntity Shooter,Integer ShooterPoints);
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
			Void RespawnPlayer(CSmPlayer Player,CMapWaypoint Waypoint);
/*!

*/
			CSmPlayer CreateBotPlayer(Ident ModelId,Integer ClanNum);
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
			Void ActionLoad(CModeVehicle Vehicle,Integer VehicleSlotIndex,EActionSlot ActionSlot,Ident ModelId);
/*!

*/
			Void ActionLoad(CModeTurret Turret,EActionSlot ActionSlot,Ident ModelId);
/*!

*/
			Integer Action_GetCooldown(CSmPlayer Player,EActionInput ActionInput);
/*!

*/
			Integer Action_GetRemainingCooldown(CSmPlayer Player,EActionInput ActionInput);
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
			Void RemoveShieldArmor(Integer VictimShieldId,Integer Damage);
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
	const	CModeVehicle[] Vehicles;
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
An action
*/
struct CSmAction : public CAction {
/*!

*/
	const	Integer Now;
/*!

*/
	const	Integer Variant;
/*!

*/
	const	CSmPlayer[] Players;
/*!

*/
	const	CSmPlayer Owner;
/*!

*/
	const	CModeVehicle OwnerVehicle;
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
			Real AmmoGain;
/*!

*/
			Ident State_EntityId1;
/*!

*/
			Integer State_Integer1;
/*!

*/
			Integer State_Integer2;
/*!

*/
			Boolean State_Boolean1;
/*!

*/
	const	CSmActionEvent[] PendingEvents;
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
/*!

*/
			Void SendRulesEvent(Text Param1,Text[] Param2,CEntity Shooter,CEntity Victim);
/*!

*/
			Ident Anim_GetModelId(Text ModelName);
/*!

*/
			Ident Anim_PlayAtLocation(Ident AnimModelId,Vec3 Position,Vec3 Direction);
/*!

*/
			Ident Anim_PlayOnPlayer(Ident AnimModelId,CSmPlayer Player);
/*!

*/
			Void Anim_Stop(Ident AnimId);
/*!

*/
			Ident Projectile_GetModelId(Text ModelName);
/*!

*/
			Ident Projectile_CreateAtLocation(Ident ProjectileModelId,CSmPlayer PlayerToIgnore,Vec3 InitialPosition,Vec3 InitialDirection,Vec3 InitialVelocity);
/*!

*/
			Ident Projectile_CreateOnPlayer(Ident ProjectileModelId,CSmPlayer Shooter);
/*!

*/
			Integer Cooldown;
/*!

*/
			Boolean Cooldown_IsReady();
/*!

*/
			Void Cooldown_Start();
/*!

*/
			Ident Shield_CreateAtLocation(Vec3 Position,Vec3 Direction);
/*!

*/
			Ident Shield_CreateOnPlayer(CSmPlayer ShieldOwner);
/*!

*/
			Void Shield_Destroy(Ident ShieldId);
/*!

*/
			Boolean Shield_Exists(Ident ShieldId);
/*!

*/
			Integer Shield_GetArmor(Ident ShieldId);
/*!

*/
			Void Shield_SetArmor(Ident ShieldId,Integer ShieldArmor);
/*!

*/
			Boolean Shield_GetIsActive(Ident ShieldId);
/*!

*/
			Void Shield_SetIsActive(Ident ShieldId,Boolean ShieldIsActive);
/*!

*/
			Integer Shield_GetArmorMax(Ident ShieldId);
/*!

*/
			Integer Shield_GetTickReload(Ident ShieldId);
/*!

*/
			Integer Shield_GetCooldown(Ident ShieldId);
/*!

*/
			Integer GetPlayerAmmo(CSmPlayer Player);
/*!

*/
			Integer GetPlayerAmmoMax(CSmPlayer Player);
/*!

*/
			Void Vehicle_TriggerTurbo();
/*!

*/
			Void Vehicle_TriggerTurboBrake();
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
			Integer CurPlayerCamera;
/*!
When in spectator mode, show the scene as it was in the past to enable doing 'instant replays'.
*/
			Integer SpectatorTimeshift;
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
/*!

*/
			Boolean ValidationGhost_IsVisible();
/*!

*/
			Vec3 ValidationGhost_GetPosition();
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
			CTmPlayer GetPlayer(CUIConfig UI);
/*!

*/
			CTmPlayer GetPlayer(Text Login);
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
			Boolean PassOn(CTmModeEvent Event);
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
			Boolean ValidationGhost_Use;
/*!

*/
			Boolean ValidationGhost_Visible;
/*!

*/
	const	Ident ValidationGhost_Id;
/*!

*/
			Boolean StuntModel_EnableCustomisation;
/*!

*/
			Boolean StuntModel_MP3Combo;
/*!

*/
			Boolean StuntModel_MP3Points;
/*!

*/
			Boolean StuntModel_UseStricterAngle;
/*!

*/
			Integer StuntModel_MinStuntDuration;
/*!

*/
			Integer StuntModel_RespawnPenalty;
/*!

*/
			Integer StuntModel_InterComboDelay;
/*!

*/
			Integer StuntModel_InterComboDelayExtendPerPoint;
/*!

*/
			Real StuntModel_FigureRepeatMalus;
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
			Vec3 RaceGhost_GetPosition(Ident GhostInstId);
/*!

*/
			Boolean RaceGhost_IsVisible(Ident GhostInstId);
/*!

*/
			Boolean RaceGhost_IsReplayOver(Ident GhostInstId);
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
Supported declare modes : Local  Persistent 
This is the client ManiaApp for Trackmania game modes.
*/
struct CTrackManiaAppPlayground : public CManiaAppPlayground {
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
	const	CMlControl FocusedControl;
/*!

*/
			Boolean LinksInhibited;
/*!

*/
			Void GetClassChildren(Text Class,CMlFrame Frame,Boolean Recursive);
/*!

*/
	const	CMlControl[] GetClassChildren_Result;
/*!

*/
			Void ScrollToControl(CMlControl Control);
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
	const	Real ReferenceScore;
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
	const	EStereoDisplayMode StereoDisplayMode;
/*!

*/
			Boolean HackCamHmdDisabled;
/*!

*/
	const	Text AvatarDisplayName;
/*!

*/
	const	Text HornDisplayName;
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
	const	Text AuthorLogin;
/*!

*/
	const	Text AuthorName;
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
/*!

*/
	const	Text MakerTitleId;
/*!

*/
	const	Text BaseTitleId;
};

/*!
Supported declare modes : Local 
Events for Manialink page scripts.
*/
struct CMlScriptEvent : public CBaseConstEvent {
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
		ScrollUp,
		ScrollDown,
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
Tool for parsing document
*/
struct CParsingManager : public CNod {
/*!

*/
			CParsingDocument Create(Text Contents);
/*!

*/
			CParsingDocument Create(Text Contents,Boolean GenerateText,Boolean GenerateTextRaw,Boolean GenerateTextResursive);
/*!

*/
			Void Destroy(CParsingDocument Document);
/*!
Parses an XML document
*/
			CParsingDocument Parse_Xml(Text Contents);
/*!
Parses an XML document
*/
			CParsingDocument Parse_Xml(Text Contents,Boolean GenerateText,Boolean GenerateTextRaw,Boolean GenerateTextResursive);
/*!

*/
			Void Parse_Destroy(CParsingDocument Document);
/*!

*/
			Integer DocumentsSlotsLimit;
/*!

*/
	const	CParsingDocument[] DocumentsXml;
/*!

*/
			Ident Compose_Start_Xml(Boolean Compact);
/*!

*/
			Ident Compose_Start_Json(Boolean Compact);
/*!

*/
			Void Compose_End(Ident ComposerId);
/*!

*/
			Void Compose_Destroy(Ident ComposerId);
/*!

*/
			Void Compose_Node_Open(Ident ComposerId,Text Name);
/*!

*/
			Void Compose_Node_Close(Ident ComposerId);
/*!

*/
			Void Compose_Array_Open(Ident ComposerId,Text Name);
/*!

*/
			Void Compose_Array_Close(Ident ComposerId);
/*!

*/
			Void Compose_Attribute(Ident ComposerId,Text Name,Text Value);
/*!

*/
			Void Compose_Attribute(Ident ComposerId,Text Name,Integer Value);
/*!

*/
			Void Compose_Attribute(Ident ComposerId,Text Name,Real Value);
/*!

*/
			Void Compose_Attribute(Ident ComposerId,Text Name,Boolean Value);
/*!

*/
			Void Compose_Value(Ident ComposerId,Text Name,Text Value);
/*!

*/
			Text Compose_GetResult(Ident ComposerId);
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
			CHttpRequest CreatePostFile(Text Url,Text FileName,Text AdditionalHeaders);
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
/*!

*/
	const	CHttpEvent[] PendingEvents;
/*!

*/
			Boolean AutomaticHeaders_Timezone;
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
Input devices.
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
	const	Vec2 MouseKineticScrollVel;
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
	const	Vec2[] TouchPoints_Cur;
/*!

*/
	const	Vec2[] TouchPoints_Init;
/*!

*/
			Text GetPadButtonPlaygroundBinding(CInputPad Pad,EButton Button);
/*!

*/
			Text GetPadButtonCurrentBinding(CInputPad Pad,EButton Button);
/*!

*/
			Boolean ExclusiveMode;
/*!

*/
			Boolean IsKeyPressed(Integer KeyCode);
/*!

*/
	const	Integer TimeSinceLatestMouseActivity;
/*!

*/
	const	Integer TimeSinceLatestTouchActivity;
/*!

*/
	const	Integer TimeSinceLatestKeyboardActivity;
/*!

*/
	const	Integer TimeSinceLatestPadActivity;
};

/*!
Script API to manage game data.
*/
struct CDataFileMgr : public CNod {
	enum EMediaType {
		Image,
		Sound,
		Script,
		MatchSettings,
		Module,
		Skins,
	};
/*!
Array of task results.
*/
	const	CTaskResult[] TaskResults;
/*!
Release a task result no more used.
*/
			Void TaskResult_Release(Ident TaskId);
/*!
Array of campaigns.
*/
	const	CCampaign[] Campaigns;
/*!
Get a campaign from its id.
*/
			CCampaign Campaign_Get(Text CampaignId);
/*!

*/
			Void Map_RefreshFromDisk();
/*!
Get the list of map stored in the user slot/dir.
*/
			CTaskResult_MapList Map_GetUserList(Ident UserId);
/*!
Get the list of map stored in the specified path.
*/
			CTaskResult_MapList Map_GetGameList(Text Path,Boolean Flatten);
/*!
Get the list of map stored according to the filters in the specified path.
*/
			CTaskResult_MapList Map_GetGameList(Text Path,Boolean Flatten,Boolean SortByNameElseByDate,Boolean SortOrderAsc);
/*!
Get the list of map stored in the specified path. Scope is used to specify if the list is retrieved from game data (1), title data (2) or user data (4).
*/
			CTaskResult_MapList Map_GetFilteredGameList(Integer Scope,Text Path,Boolean Flatten);
/*!
Array of ghosts.
*/
	const	CGhost[] Ghosts;
/*!
Release a downloaded ghost no longer needed.
*/
			Void Ghost_Release(Ident GhostId);
/*!

*/
			CTaskResult_Ghost Ghost_Download(Text FileName,Text Url);
/*!

*/
			CTaskResult Ghost_Upload(Text Url,CGhost Ghost,Text AdditionalHeaders);
/*!

*/
			Void Replay_RefreshFromDisk();
/*!
Get the list of replay stored in the specified path.
*/
			CTaskResult_ReplayList Replay_GetGameList(Text Path,Boolean Flatten);
/*!
Get the list of replay stored according to the filters in the specified path.
*/
			CTaskResult_ReplayList Replay_GetGameList(Text Path,Boolean Flatten,Boolean SortByNameElseByDate,Boolean SortOrderAsc);
/*!
Get the list of replay stored in the specified path. Scope is used to specify if the list is retrieved from game data (1), title data (2) or user data (4).
*/
			CTaskResult_ReplayList Replay_GetFilteredGameList(Integer Scope,Text Path,Boolean Flatten);
/*!
Get the list of ghosts from the replay stored at the specified file path.
*/
			CTaskResult_GhostList Replay_Load(Text Path);
/*!
Save the map and the ghost into a replay file stored at the specified path.
*/
			CTaskResult Replay_Save(Text Path,CMap Map,CGhost Ghost);
/*!
Get the list of media stored in the specified path.
*/
			CTaskResult_FileList Media_GetGameList(EMediaType Type,Text Path,Boolean Flatten);
/*!
Get the list of media stored according to the filters in the specified path.
*/
			CTaskResult_FileList Media_GetGameList(EMediaType Type,Text Path,Boolean Flatten,Boolean SortByNameElseByDate,Boolean SortOrderAsc);
/*!
Get the list of media stored in the specified path. Scope is used to specify if the list is retrieved from game data (1), title data (2) or user data (4).
*/
			CTaskResult_FileList Media_GetFilteredGameList(EMediaType Type,Integer Scope,Text Path,Boolean Flatten);
/*!

*/
			CTaskResult_GameModeList GameMode_GetGameList(Integer Scope,Text Path,Boolean Flatten);
/*!

*/
			CTaskResult Pack_DownloadOrUpdate(Text DisplayName,Text Url);
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
	const	CTaskResult[] TaskResults;
/*!
Release a task result no more used.
*/
			Void TaskResult_Release(Ident TaskId);
/*!
Returns the local status of user records.
*/
			ELocalScoreStatus ScoreStatus_GetLocalStatus(Ident UserId);
/*!
Returns the masterserver status of user records.
*/
			EMasterServerScoreStatus ScoreStatus_GetMasterServerStatus(Ident UserId);
/*!
Returns the ghost currently being recorded for a player on the current playground. (or the latest ghost if the player is not playing.)
*/
			CGhost Playground_GetPlayerGhost(CPlayer GamePlayer);
/*!
Set a new record for a map.
*/
			CTaskResult Map_SetNewRecord(Ident UserId,Text MapUid,Text Context,CGhost Ghost);
/*!
Returns the user record time for a map.
*/
			Integer Map_GetRecord(Ident UserId,Text MapUid,Text Context);
/*!
Returns the user record ghost for  a map.
*/
			CTaskResult_Ghost Map_GetRecordGhost(Ident UserId,Text MapUid,Text Context);
/*!
Returns the number of medals for a map.
*/
			Integer Map_GetMultiAsyncLevel(Ident UserId,Text MapUid,Text Context);
/*!
Returns the record score of the medal for a map.
*/
			Integer Map_GetMultiAsyncLevelRecord(Text MapUid,Text Context,Integer MultiAsyncLevel);
/*!
Returns the record ghost of the medal for a map.
*/
			CTaskResult_Ghost Map_GetMultiAsyncLevelRecordGhost(Text MapUid,Text Context,Integer MultiAsyncLevel);
/*!
Returns the skillpoints for a map.
*/
			Integer Map_GetSkillPoints(Ident UserId,Text MapUid,Text Context);
/*!
Returns the user ranking on a map.
*/
			Integer MapLeaderBoard_GetPlayerRanking(Ident UserId,Text MapUid,Text Context,Text Zone);
/*!
Returns the number of user ranked on a map.
*/
			Integer MapLeaderBoard_GetPlayerCount(Text MapUid,Text Context,Text Zone);
/*!
Returns a part of the map leaderboard.
*/
			CTaskResult_NaturalLeaderBoardInfoList MapLeaderBoard_GetPlayerList(Ident UserId,Text MapUid,Text Context,Text Zone,Integer FromIndex,Integer Count);
/*!
Returns the number of medals for a campaign.
*/
			Integer Campaign_GetMultiAsyncLevel(Ident UserId,Text CampaignId);
/*!
Returns the number of medals of the specified level for a campaign.
*/
			Integer Campaign_GetMultiAsyncLevelCount(Ident UserId,Text CampaignId,Integer MultiAsyncLevel);
/*!
Returns the skillpoints for a campaign.
*/
			Integer Campaign_GetSkillPoints(Ident UserId,Text CampaignId);
/*!
Returns the all the records of an opponent specified by its login for a campaign.
*/
			CTaskResult_MapRecordList Campaign_GetOpponentRecords(Ident UserId,Text CampaignId,Text OpponentLogin);
/*!
Returns the buddies records for a map of a campaign.
*/
			CTaskResult_BuddiesChallengeRecord Campaign_GetBuddiesMapRecord(Ident UserId,Text CampaignId,Text MapUid);
/*!
Returns if the buddies records for a map of a campaign are dirty.
*/
			Boolean Campaign_IsBuddiesMapRecordDirty(Ident UserId,Text CampaignId,Text MapUid);
/*!
Returns the buddies records comparison for a campaign.
*/
			CTaskResult_BuddiesChallengeRecordsComparison Campaign_GetBuddiesMapRecordsComparison(Ident UserId,Text CampaignId);
/*!
Returns the records comparison with a buddy for a campaign.
*/
			CTaskResult_BuddyChallengeRecordsComparison Campaign_GetBuddyMapRecordsComparison(Ident UserId,Text OpponentLogin,Text CampaignId);
/*!
Returns the user ranking on a campaign.
*/
			Integer CampaignLeaderBoard_GetPlayerRanking(Ident UserId,Text CampaignId,Text Zone,Boolean UseSkillPoints);
/*!
Returns the number of user ranked on a campaign.
*/
			Integer CampaignLeaderBoard_GetPlayerCount(Text CampaignId,Text Zone,Boolean UseSkillPoints);
/*!
Returns a part of the campaign leaderboard.
*/
			CTaskResult_NaturalLeaderBoardInfoList CampaignLeaderBoard_GetPlayerList(Ident UserId,Text CampaignId,Text Zone,Boolean UseSkillPoints,Integer FromIndex,Integer Count);
/*!
Add points to multiplayer score.
*/
			Void Multiplayer_AddToScore(Ident UserId,Real ScoreDiff,Integer Timestamp);
/*!
Returns the multiplayer ranking.
*/
			Integer MultiplayerLeaderBoard_GetPlayerRanking(Ident UserId,Text Zone);
/*!
Returns the number of user ranked in multiplayer leaderboard.
*/
			Integer MultiplayerLeaderBoard_GetPlayerCount(Text Zone);
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
			CTaskResult_RealLeaderBoardInfoList GlobalLeaderBoard_GetPlayerList(Ident UserId,Text Zone,Integer FromIndex,Integer Count);
};

/*!

*/
struct CAnimManager : public CNod {
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
/*!

*/
			Void Add(CMlControl Control,Text XmlTarget,Integer StartTime,Integer Duration,EAnimManagerEasing EasingFunc);
/*!

*/
			Void AddChain(CMlControl Control,Text XmlTarget,Integer Duration,EAnimManagerEasing EasingFunc);
/*!

*/
			Void Add(CMlControl Control,Text XmlTarget,Integer Duration,EAnimManagerEasing EasingFunc);
/*!

*/
			Void Flush(CMlControl Control);
};

/*!
Supported declare modes : Local 

*/
struct CSystemPlatform : public CNod {
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
	const	ESystemPlatform Platform;
/*!

*/
	const	ESystemSkuIdentifier SkuIdentifier;
/*!

*/
	const	Text ExeVersion;
/*!

*/
	const	Integer CurrentLocalDate;
/*!

*/
	const	Text CurrentLocalDateText;
/*!

*/
	const	Text CurrentTimezone;
/*!

*/
	const	Text ExtraTool_Info;
/*!

*/
			Text ExtraTool_Data;
/*!

*/
			Void ClipboardSet(Text ClipboardText);
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
	const	CMlFrame Parent;
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
			Text ToolTip;
/*!

*/
			Void Show();
/*!

*/
			Void Hide();
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
/*!

*/
	const	Boolean HasCustomIntro;
/*!

*/
	const	Boolean HasCustomMusic;
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
/*!

*/
	const	Boolean IsLocalPageScriptRunning;
};

/*!
API for local users/profiles.
*/
struct CUserV2Manager : public CNod {
/*!

*/
	const	CUserV2Profile MainUserProfile;
/*!

*/
	const	CTaskResult[] TaskResults;
/*!

*/
			Void TaskResult_Release(Ident TaskId);
/*!
NullId for the mainuser.
*/
			CTaskResult_StringIntList GetGroups(Ident UserId);
};

/*!
API for titles menus to control the main loop.
*/
struct CTitleControl : public CNod {
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
		Error_Abort,
	};
	enum EEditorType {
		ActionMaker,
		ChallengeEditor,
		ItemEditor,
		InterfaceDesigner,
		MeshModeler,
		ModuleStudio,
		PixelArt,
		EditorEditor,
		VehicleAssembler,
		MaterialEditor,
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
			Void PlayCampaign(CCampaign Campaign,CMapInfo MapInfo,Text Mode,Text SettingsXml);
/*!

*/
			Void PlayMapList(Text[] MapList,Text Mode,Text SettingsXml);
/*!

*/
			Void PlayMatchSettings(CMatchSettings MatchSettings,Text OverrideMode,Text OverrideSettingsXml);
/*!

*/
			Void PlaySplitScreen(ESplitScreenLayout LayoutType,Text[] MapList,Text Mode,Text SettingsXml);
/*!

*/
			Void PlayMultiOnSameScreen(Text[] MapList,Text Mode,Text SettingsXml);
/*!

*/
			Void PlaySplitScreen(ESplitScreenLayout LayoutType,CMatchSettings MatchSettings);
/*!

*/
			Void PlayMultiOnSameScreen(CMatchSettings MatchSettings);
/*!

*/
			Void ViewReplay(Text Replay);
/*!

*/
			Void OpenEditor(Text EditorName,Text MainPluginSettings);
/*!

*/
			Void OpenEditor(EEditorType EditorType);
/*!

*/
			Void EditSkins();
/*!

*/
			Void EditReplay(Text[] ReplayList);
/*!

*/
			Void EditGhosts(Text Map);
/*!

*/
			Void EditAsset(Text EditorName,Text MainPluginSettingsXml,Text RelativeFileName);
/*!

*/
			Void EditMap(Text Map,Text EditorPluginScript,Text EditorPluginArgument);
/*!

*/
			Void EditNewMap(Text Environment,Text Decoration,Text ModNameOrUrl,Text PlayerModel,Text MapType,Text EditorPluginScript,Text EditorPluginArgument);
/*!

*/
			Void EditNewMap(Text Environment,Text Decoration,Text ModNameOrUrl,Text PlayerModel,Text MapType,Boolean UseSimpleEditor,Text EditorPluginScript,Text EditorPluginArgument);
/*!

*/
			Void EditNewMapFromBaseMap(Text BaseMapName,Text ModNameOrUrl,Text PlayerModel,Text MapType,Text EditorPluginScript,Text EditorPluginArgument);
/*!

*/
			Void EditBadges();
/*!

*/
	const	Boolean CanPublishFiles;
/*!
Set FileName='' to open a file select dialog.
*/
			Void PublishFile(Text FileName);
/*!

*/
			Void ProcessManiaCodeXml(Text ManiaCodeXml);
/*!

*/
	const	CServerInfo[] LocalServers;
/*!

*/
	const	CServerInfo[] LocalServers_CurrentTitle;
/*!

*/
			Void DiscoverLocalServers();
/*!

*/
			Void CreateServer(Text ServerName,Text ServerComment,Integer MaxPlayerCount,Text Password,CMatchSettings MatchSettings,Text PasswordSpectators);
/*!

*/
			Void CreateServer(Text ServerName,Text ServerComment,Integer MaxPlayerCount,Text Password,Text PasswordSpectators,CMatchSettings MatchSettings,Boolean LocalOnly);
/*!
Fetch the server info
*/
			Void GetServerInfo(Text ServerLogin);
/*!

*/
			Void GetServerInfo(CServerInfo LocalServer);
/*!

*/
			Void GetServerInfo_Abort();
/*!

*/
	const	CServerInfo GetServerInfo_Result;
/*!

*/
			Void Join_GetServerInfo_Result(Boolean AsSpectator,Text Password);
/*!
Join a server
*/
			Void JoinServer(Text ServerLogin,Boolean AsSpectator,Text Password);
/*!

*/
			Void Quit();
};

/*!
Supported declare modes : Local 
An event
*/
struct CBaseConstEvent : public CNod {
/*!
Use this flag to solve issues where some events are interpreted twice by different script librairies.</br>Discard events if the flag is set. Set the flag after handling the event.
*/
			Boolean HasBeenProcessed;
};

/*!
API for titles in edition mode.
*/
struct CTitleEdition : public CNod {
	enum EDrive {
		TitleReadable,
		Title,
		User,
	};
/*!

*/
	const	CTitle TitleMaker;
/*!
PackCreator - only available when the title author is the current logged user.
*/
	const	CPackCreator PackCreator;
/*!

*/
	const	Text EditedTitleId;
/*!

*/
	const	CPackCreatorTitleInfo EditedTitleInfo;
/*!
Will copy file 'FileName' from the UserDir to the TitleDir, including its dependencies.
*/
			Void File_ImportFromUser(Text FileName);
/*!
Will move or copy file 'OrigName' to 'DestName'. If DestName is a '\' terminated folder path, keeps the orginial short name.
*/
			Void File_Move(Text OrigName,Text DestNameOrFolder,Boolean KeepOriginalCopy);
/*!

*/
			Boolean File_Exists(Text FileName,EDrive InDrive);
/*!

*/
			Void File_Delete(Text Name);
/*!

*/
			Void File_WriteText(Text FileName,Text Text);
/*!

*/
			Text File_ReadText(Text FileName);
/*!

*/
			Void Dialog_ImportFiles();
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
			Void OpenTitleFolderInExplorer();
/*!

*/
			Void ReloadTitleDesc();
/*!

*/
			Void SaveTitleDesc();
/*!
nb: The maps from the campaign are automatically added to the pack, no need to Build_AddFile().
*/
			Void SetTitleCampaign(Integer CampaignNum,Text ScoreContext,Text MapsFolderNameOrPlayListName,Boolean OfficialRecordEnabled);
/*!

*/
			Void SetTitleCampaign(Integer CampaignNum,Text ScoreContext,Text MapsFolderNameOrPlayListName,Boolean OfficialRecordEnabled,Boolean DisableUnlockSystem);
};

/*!
Manager of buddies instant messaging.
*/
struct CNotificationsConsumer : public CNod {
	enum EFilterPriority {
		All,
		MoreThanMemo,
		MoreThanNotice,
	};
/*!
Events
*/
	const	CNotificationsConsumerEvent[] Events;
/*!
List of the Notifications.
*/
	const	CNotificationsConsumerNotification[] Notifications;
/*!

*/
	const	CNotificationsConsumerNotification[] FilteredNotifications;
/*!

*/
			EFilterPriority Filter_Priority;
};

/*!
Manager of achievements.
*/
struct CAchievementsManager : public CNod {
/*!
List of events for current frame.
*/
	const	CAchievementsEvent[] PendingEvents;
/*!
Achievements descriptions.
*/
	const	CAchievementsAchievement[] Achievements;
/*!
Stats descriptions.
*/
	const	CAchievementsStat[] Stats;
/*!
Achievements descriptions.
*/
	const	CAchievementsAchievementDesc[] AchievementDescriptions;
/*!
Stats descriptions.
*/
	const	CAchievementsStatDesc[] StatDescriptions;
/*!

*/
			Void SendEvent(Ident UserId,Text Mnemo,Integer[] Params);
};

/*!

*/
struct CBadgeManager : public CNod {
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
Allows handling of match-settings files
*/
struct CMatchSettingsManager : public CNod {
/*!
Clear all matchsettings and reload them from disk. Be aware that any non-saved changes will be lost.
*/
			Void MatchSettings_Refresh();
/*!
Create a new matchsettings file.
*/
			CMatchSettings MatchSettings_Create(Text FilePath);
/*!
Save a matchsettings file.
*/
			Void MatchSettings_Save(CMatchSettings MatchSettings);
/*!

*/
			CMatchSettings MatchSettings_SaveAs(Text FilePath,CMatchSettings MatchSettings);
/*!

*/
			Void MatchSettings_EditScriptSettings(CMatchSettings MatchSettings);
/*!

*/
	const	Boolean MatchSettings_EditScriptSettings_Ongoing;
/*!
Array of the matchsettings
*/
	const	CMatchSettings[] MatchSettings;
};

/*!
Supported declare modes : Local  Persistent 
API for game interface client scripts
*/
struct CManiaAppPlaygroundCommon : public CManiaApp {
/*!

*/
	const	CManiaAppPlaygroundEvent[] PendingEvents;
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
/*!

*/
	const	Integer SplitScreenCount;
/*!
Set a layer to be displayed on a subscreen. ScreenNum: 0=global, 1,2.... = screen index.  Limitation: a local layer can only be one screen at a time.
*/
			Void SplitScreenAssignLayer(CUILayer UILayer,Integer ScreenNum);
};

/*!
Supported declare modes : Local  Persistent 
API for Maniaplanet client scripts.
*/
struct CManiaAppBase : public CManiaApp {
/*!

*/
	const	CManiaAppEvent[] PendingEvents;
};

/*!
Script API to create Pack files (can be Titlepack or plain ManiaCredited data).
*/
struct CPackCreatorTitleInfo : public CNod {
/*!

*/
	const	Ident TitleId;
/*!

*/
	const	Ident MakerTitleId;
/*!

*/
			Text DisplayName;
/*!

*/
			Text Description;
/*!

*/
			Text InfoUrl;
/*!

*/
			Text DownloadUrl;
/*!

*/
			Text TitleVersion;
/*!

*/
			Text AllowedClientTitleVersion;
/*!

*/
			Text BaseTitleIds;
/*!

*/
			Text ForcedPlayerModel;
/*!

*/
			Text Packaging_ImageFileName;
/*!

*/
			Text Packaging_LogosFileName;
/*!

*/
			Text Packaging_Group;
/*!
Can be an http://url or a ./path/in/title/datas/station.app.txt
*/
			Text Station_ManialinkUrl;
/*!

*/
			Text Menus_BgReplayFileName;
/*!

*/
			Text Menus_ManiaAppFileName;
/*!

*/
			Text Menus_MusicFileName;
/*!
Use  CGameManiaTitleEditionScriptAPI::SetTitleCampaign() to modify
*/
	const	Boolean Solo_HasCampaign;
/*!

*/
			Text Hud3dFontFileName;
/*!

*/
			Text HudDefaultModuleScriptName;
/*!

*/
			Text MusicFolder;
};

/*!
Supported declare modes : Local 

*/
struct CEditorPluginHandle : public CNod {
};

/*!
Supported declare modes : Metadata 

*/
struct CEditorModule : public CEditorBase {
	enum EModuleType {
		Undefined,
		Hud,
		Inventory,
		Store,
		ScoresTable,
		Equipment,
		MenuBase,
		MenuPage,
		Chrono,
		SpeedMeter,
		PlayerState,
		TeamState,
	};
/*!

*/
			Void NewModule(EModuleType ModuleType);
/*!

*/
			Void OpenModule(Text Path);
/*!

*/
			Void Save();
/*!

*/
			Void SaveAs(Text Path);
/*!

*/
			Void SaveCopyAs(Text Path);
/*!

*/
			Void ForceExit();
/*!

*/
	const	CModuleMenuModel EditedMenu;
/*!

*/
	const	CModuleMenuPageModel EditedMenuPage;
/*!

*/
	const	CModulePlaygroundHudModel EditedPlaygroundHud;
/*!

*/
			Void EditedPlaygroundHud_SetPreviewContext(Ident ContextId);
/*!

*/
			Void FileBrowser_Open();
/*!

*/
	const	Boolean FileBrowser_IsRunning;
/*!

*/
	const	Text FileBrowser_FilePath;
/*!

*/
	const	CEditorPluginModuleEvent[] PendingEvents;
/*!

*/
	const	Boolean IsPreviewMode;
};

/*!
Supported declare modes : Metadata 
API for the mesh modeler.
*/
struct CEditorMesh : public CEditorAsset {
	enum EEdgesDisplay {
		Any,
		Borders,
		None,
	};
	enum EEdgesConstraint {
		Any,
		Adjacent,
		Closed,
	};
	enum EElemType {
		Vertex,
		Edge,
		Face,
		Any,
	};
	enum EInteraction {
		Creation,
		Pick,
		PickJoint,
		VoxelPickDrag_Base,
		VoxelPickDrag_Creation,
		VoxelPickDrag_Delete,
		VoxelPickDrag_Select,
		VoxelPickDrag_Pick,
		VoxelPickDrag_SelectTranslation,
		VoxelPickDrag_SelectRotation,
		VoxelPickDrag_Paste,
		Selection,
		Translation,
		PickTranslation,
		ExtrudeTranslation,
		Rotation,
		PickRotation,
		Scale,
		Curve2D,
		Merge,
		Split,
		Mirror,
		Paste,
		PasteMaterial,
		BlocTransformation,
		None,
	};
	enum ETexCoordLayer {
		Lightmap,
	};
	enum EMaterialFilterCriterion {
		IsAutomatic,
		IsBadForHorizontalFaces,
		IsBadForVerticalFaces,
	};
	enum EFilterKind {
		NoFilter,
		PassIfMatches,
		CutIfMatches,
	};
	enum EUVEditorMode {
		UV,
		Atlas_ApplyOnClic,
		Atlas_SelectOnClic,
	};
	enum EUVEditorProjectionType {
		Planar,
		Curve2D,
		Cylindrical2D,
		Cubic,
		Polyedric,
		Cylindrical,
		ApplyOnlyMaterial,
	};
	enum ELayerType {
		AddGeometry,
		SubdivideSmooth,
		Translation,
		Rotation,
		Scale,
		Mirror,
		MoveToGround,
		Extrude,
		Subdivide,
		Chaos,
		Smooth,
		BorderTransition,
		BlocTransfo,
		Voxels,
		TriggerShape,
		RespawnPos,
		Sector,
		None,
	};
	enum ETitleCoreType {
		TrackMania,
		ShootMania,
	};
/*!

*/
			Boolean GoToMaterialEditor;
/*!

*/
			Boolean IsCreateMaterial;
/*!

*/
			Integer Layers_GetCount();
/*!

*/
			Ident Layers_GetLayerIdFromIndex(Integer LayerIndex);
/*!

*/
			Text Layers_GetLayerNameFromIndex(Integer LayerIndex);
/*!

*/
			ELayerType Layers_GetLayerTypeFromIndex(Integer LayerIndex);
/*!

*/
			Boolean Layers_GetLayerGeneratableFromIndex(Integer LayerIndex);
/*!

*/
			Void Layers_SetLayerGeneratableFromIndex(Integer LayerIndex,Boolean LayerGeneratability);
/*!

*/
			Void Layers_AddLayer(ELayerType LayerType);
/*!

*/
			Ident Layers_GetLayerIdSelected();
/*!

*/
			Void Layers_SetLayerIdSelected(Ident LayerId);
/*!

*/
			ELayerType Layers_GetLayerSelectedType();
/*!

*/
			Integer Layers_GetLayerSelectedIndex();
/*!

*/
			ELayerType Layers_GetEditedLayerType();
/*!

*/
			Text Layers_GetLayerSelectedName();
/*!

*/
			Void Layers_EditMask(Integer LayerIndex);
/*!

*/
			Void Layers_EditMaskValidate(Integer LayerIndex);
/*!

*/
			Void Layers_MoveSelectedLayerUp();
/*!

*/
			Void Layers_MoveSelectedLayerDown();
/*!

*/
			Void Layers_EditSelectedLayer(Boolean RegenerateSolid);
/*!

*/
			Void Layers_CloseEditSelectedLayer();
/*!

*/
			Void Layers_DeleteSelectedLayer();
/*!

*/
			Integer Transitions_GetCount();
/*!

*/
			Void Transitions_AddTransition(Text TransitionName,Integer TransitionPosition,Real TransitionSize);
/*!

*/
			Void Transitions_DeleteCurrentTransition();
/*!

*/
			Integer Transitions_GetTransitionSelectedIndex();
/*!

*/
			Void Transitions_SetTransitionSelectedIndex(Integer TransitionIndex);
/*!

*/
			Integer Transitions_GetTransitionCurrentPage();
/*!

*/
			Void Transitions_SetTransitionCurrentPage(Integer TransitionCurrentPage);
/*!

*/
			Text Transitions_GetTransitionNameFromIndex(Integer TransitionIndex);
/*!

*/
			Void Transitions_SetTransitionNameFromIndex(Integer TransitionIndex,Real TransitionName);
/*!

*/
			Boolean Transitions_GetTransitionVisibilityFromIndex(Integer TransitionIndex);
/*!

*/
			Void Transitions_SetTransitionVisibilityFromIndex(Integer TransitionIndex,Boolean TransitionVisibility);
/*!

*/
			Real Transitions_GetTransitionSizeFromIndex(Integer TransitionIndex);
/*!

*/
			Void Transitions_SetTransitionSizeFromIndex(Integer TransitionIndex,Real TransitionSize);
/*!

*/
			Integer Transitions_GetTransitionPositionFromIndex(Integer TransitionIndex);
/*!

*/
			Void Transitions_SetTransitionPositionFromIndex(Integer TransitionIndex,Integer TransitionPosition);
/*!

*/
			Boolean IsEditingLayer;
/*!

*/
			Integer SubdivideSmooth_NbSteps;
/*!

*/
			Real LayerValueAxisX;
/*!

*/
			Real LayerValueAxisY;
/*!

*/
			Real LayerValueAxisZ;
/*!

*/
			Boolean LayerIndep;
/*!

*/
			Real LayerValueParam1;
/*!

*/
			Real LayerValueParam2;
/*!

*/
			Boolean LayerIndexAxisX;
/*!

*/
			Boolean LayerIndexAxisY;
/*!

*/
			Boolean LayerIndexAxisZ;
/*!

*/
			Boolean Layer_IsVisible;
/*!

*/
			Boolean Layer_IsCollidable;
/*!

*/
			Text LayerName;
/*!

*/
			Boolean LayerGeneratable;
/*!

*/
			Boolean AddTransitionInProgress;
/*!

*/
			Text NewTransitionName;
/*!

*/
			Integer NewTransitionPosition;
/*!

*/
			Real NewTransitionSize;
/*!

*/
			Integer RotateAxis;
/*!

*/
	const	Boolean Tmp_UseParts;
/*!

*/
	const	Boolean IsDebug;
/*!

*/
			Boolean CameraEatingInputsScript;
/*!

*/
	const	Integer VertexCount;
/*!

*/
	const	Integer EdgeCount;
/*!

*/
	const	Integer FaceCount;
/*!

*/
			Void EditionBox_SetStep(Real Step);
/*!

*/
	const	Boolean EditionBox_IsPlaneOriented;
/*!

*/
	const	Real Scale;
/*!

*/
	const	Real Step;
/*!

*/
	const	Real Size;
/*!

*/
	const	Integer RotationStep;
/*!

*/
	const	Real RotationValue;
/*!

*/
	const	Real ScalingStep;
/*!

*/
	const	Real ScalingRatio;
/*!

*/
			Boolean DisplayVertices;
/*!

*/
			Boolean DisplayFaces;
/*!

*/
			Boolean DisplayJoints;
/*!

*/
			EEdgesDisplay DisplayEdges;
/*!

*/
			Void EditedMesh_Clear();
/*!

*/
			Void EditedMesh_Simplify();
/*!

*/
			Void EditedMesh_Lod(Real Faces Ratio);
/*!

*/
			Void UVUnwrap(Ident SetHandle,ETexCoordLayer ETexCoordLayer);
/*!

*/
			Void Undo();
/*!

*/
			Void Redo();
/*!

*/
			Void SwitchPlane();
/*!

*/
			Void GridSnap_SetActive(Boolean IsActive);
/*!

*/
	const	Boolean GridSnap_IsActive;
/*!

*/
			Vec3 PickInfo_GetNormal();
/*!

*/
			Vec3 PickInfo_GetPosition();
/*!

*/
			Ident PickInfo_GetAnchorId();
/*!

*/
			Real PickInfo_GetEdgeLength();
/*!

*/
			Vec3 PickInfo_GetNextVertexPosition();
/*!

*/
			Ident PickInfo_GetMaterial();
/*!

*/
			Text PickInfo_GetError();
/*!

*/
			Void Part_SetAnchorPos(Vec3 Position);
/*!

*/
			Void Part_SetIsJoint(Boolean IsJoint);
/*!

*/
			Void Part_ClearAnchor();
/*!

*/
			Void Joint_Add(Vec3 Position);
/*!

*/
			Void Joint_Link(Ident IdChild,Ident IdParent);
/*!

*/
			Void Anchor_Remove(Ident Id);
/*!

*/
			Boolean IsUsingPhysicMatLib;
/*!

*/
	const	Integer MaterialsUpdateId;
/*!

*/
	const	Ident[] MaterialIds;
/*!

*/
	const	Ident[] MaterialPhysicsIds;
/*!

*/
	const	Text[] MaterialNames;
/*!

*/
	const	Text[] MaterialPhysicsNames;
/*!

*/
			Ident Material_GetMaterialIdSelected();
/*!

*/
			Void Material_SetMaterialIdSelected(Ident MaterialEditorId);
/*!

*/
			Integer Material_GetSubTexIndexSelected();
/*!

*/
			Integer Material_MaterialLibGetCount();
/*!

*/
			Void Material_SetDefault(Ident MaterialId);
/*!

*/
			Ident Material_GetDefault();
/*!

*/
			Ident MaterialPhysic_GetDefault();
/*!

*/
			CImage Material_GetBitmapBase(Ident MaterialId);
/*!

*/
			CImage Material_GetBitmap(Ident MaterialId);
/*!

*/
			Boolean Material_MatchesCriterion(Ident MaterialId,EMaterialFilterCriterion ResultSetHandle);
/*!

*/
			Void Material_SetFilter(EMaterialFilterCriterion Criterion,EFilterKind FilterKind);
/*!

*/
			EFilterKind Material_GetFilter(EMaterialFilterCriterion Criterion);
/*!

*/
			Void Material_ClearFilters();
/*!

*/
			Void Material_UVEditor_SetIsRotation(Boolean IsRotation);
/*!

*/
			Void Material_UVEditor_SetIsScale(Boolean IsScale);
/*!

*/
			Void Material_UVEditor_SetIsScale1D(Boolean IsScale);
/*!

*/
			Void Material_UVEditor_Open(Ident MaterialId,CMlQuad LocationQuad);
/*!

*/
			Void Material_UVEditor_Close();
/*!

*/
			Boolean Material_UVEditor_IsRunning();
/*!

*/
			Void Material_UVEditor_SetMode(EUVEditorMode Mode);
/*!

*/
			EUVEditorMode Material_UVEditor_GetMode();
/*!

*/
			Void Material_UVEditor_SetProjectionType(EUVEditorProjectionType ProjectionType);
/*!

*/
			Boolean Material_IsGameMaterial();
/*!

*/
			Boolean Material_IsCustomLinkFull(Ident MaterialId);
/*!

*/
			Void Material_UVEditor_Apply();
/*!

*/
			Void Material_CopyMaterial(Ident SetHandle);
/*!

*/
			Void Material_PasteMaterial(Ident SetHandle);
/*!

*/
	const	Integer Material_Atlas_SelectedSubTexIndex;
/*!

*/
	const	EInteraction CurrentInteraction;
/*!

*/
			Void Interaction_Close();
/*!

*/
			Void Interaction_SetPreview(Ident SetToPreview);
/*!

*/
	const	Integer CreationElemsCount;
/*!

*/
			Boolean Interaction_StartCreation(Ident CreationSetHandle,EElemType ElemType,Ident SetToPickFromHandle);
/*!

*/
			Void Interaction_Creation_GetElems(Ident ResultSetHandle);
/*!

*/
			Void Interaction_Creation_ClearParams();
/*!

*/
			Void Interaction_Creation_SetEdgesConstraint(EEdgesConstraint EdgesConstraint);
/*!

*/
			Void Interaction_Creation_SetAutoMerge(Boolean AutoMerge);
/*!

*/
			Boolean Interaction_StartPaste();
/*!

*/
			Boolean Interaction_StartBlocTransformation(Ident TransformationSetHandle);
/*!

*/
			Boolean Interaction_StartCurve2D(Ident BordersSetHandle);
/*!

*/
			Void Interaction_CloseCurve2D(Boolean CanDoCurve2D);
/*!

*/
			Boolean Interaction_StartPick(EElemType ElemType,Ident SetToPickFrom);
/*!

*/
			Boolean Interaction_StartPickJoint();
/*!

*/
			Boolean Interaction_StartVoxelPickDrag_Base(EElemType ElemType);
/*!

*/
			Boolean Interaction_StartVoxelPickDrag_Creation();
/*!

*/
			Boolean Interaction_StartVoxelPickDrag_Delete();
/*!

*/
			Boolean Interaction_StartVoxelPickDrag_Select(Ident SelectionSetHandle);
/*!

*/
			Void Interaction_CloseVoxelPickDrag_Select();
/*!

*/
			Boolean Interaction_StartVoxelPickDrag_Pick();
/*!

*/
			Void Interaction_CloseVoxelPickDrag_Pick();
/*!

*/
			Boolean Interaction_StartVoxelPickDrag_SelectTranslation();
/*!

*/
			Boolean Interaction_StartVoxelPickDrag_SelectRotation();
/*!

*/
			Boolean Interaction_StartVoxelPickDrag_Paste();
/*!

*/
			Void CutVoxels();
/*!

*/
			Void CopyVoxels();
/*!

*/
			Boolean Interaction_StartMerge(Ident MergeSetHandle);
/*!

*/
			Boolean Interaction_StartMirror(Ident SetHandle);
/*!

*/
			Void Interaction_Selection_ClearParams();
/*!

*/
			Void Interaction_Selection_SetUseParts(Boolean UseParts);
/*!

*/
			Void Interaction_Selection_SetCanEnterLeaf(Boolean CanEnterLeaf);
/*!

*/
			Boolean Interaction_StartSelection(Ident SelectionSetHandle,EElemType ElemType,Ident SelectionSetToPickFrom,Boolean IsFromALayer,Boolean AllowDoubleClick);
/*!

*/
			Void Interaction_CloseSelection();
/*!

*/
			Boolean Interaction_StartTranslation(Ident TranslationSetHandle);
/*!

*/
			Boolean Interaction_StartPickTranslation(Ident TranslationSetHandle);
/*!

*/
			Boolean Interaction_StartRotation(Ident RotationSetHandle);
/*!

*/
			Boolean Interaction_StartPickRotation(Ident RotationSetHandle);
/*!

*/
			Void Interaction_Rotation_SetStep(Real RotationStep);
/*!

*/
			Boolean Interaction_StartPickScale(Ident ScalingSetHandle);
/*!

*/
			Void Interaction_Scale_SetStep(Real ScalingStep);
/*!

*/
			Boolean Interaction_StartSplit();
/*!

*/
			Void Display_HighlightSet(Ident SetHandle);
/*!

*/
			Void Display_ClearHighlighting();
/*!

*/
	const	Boolean Display_HideElemsByDistance_IsActive;
/*!

*/
			Integer Display_HideElemsByDistance_Distance;
/*!

*/
			Real Display_HideElemsByDistance_Opacity;
/*!

*/
			Void Display_HideElemsByDistance_Start(Ident SetHandle);
/*!

*/
			Void Display_HideElemsByDistance_Stop();
/*!

*/
			Void Display_HideMap();
/*!

*/
			Void Display_ShowMap();
/*!

*/
			Void MergeAllSuperposedElements(Ident SetHandle);
/*!

*/
	const	Ident SelectionSet;
/*!

*/
			Void Selection_Undo();
/*!

*/
			Void Selection_Redo();
/*!

*/
			Void Selection_Invert();
/*!

*/
			Void Selection_SelectAllByMaterial();
/*!

*/
			Ident SetOfElements_Create();
/*!

*/
			Void SetOfElements_CopyFrom(Ident DestinationSet,Ident SourceSet);
/*!

*/
			Void SetOfElements_Append(Ident DestinationSet,Ident SourceSet);
/*!

*/
			Void SetOfElements_Destroy(Ident SetHandle);
/*!

*/
			Void SetOfElements_Empty(Ident SetHandle);
/*!

*/
			Void SetOfElements_SetAllElements(Ident SetHandle);
/*!

*/
			Void SetOfElements_SetAllFaces(Ident SetHandle);
/*!

*/
			Void SetOfElements_DeleteElements(Ident SetHandle);
/*!

*/
			Void SetOfElements_DeleteElements(Ident SetHandle,Boolean Spread);
/*!

*/
			Boolean SetOfElements_HasHorizontalFaces(Ident SetHandle);
/*!

*/
			Boolean SetOfElements_HasVerticalFaces(Ident SetHandle);
/*!

*/
			Integer SetOfElements_GetElemsCount(Ident SetHandle);
/*!

*/
			Integer SetOfElements_GetVerticesCount(Ident SetHandle);
/*!

*/
			Integer SetOfElements_GetEdgesCount(Ident SetHandle);
/*!

*/
			Integer SetOfElements_GetFacesCount(Ident SetHandle);
/*!

*/
			Void ExtendSelectedSet(Ident SetHandle);
/*!

*/
			Boolean GetBordersSet(Ident SetHandle,Ident SetBordersHandle);
/*!

*/
			Void GetBordersVertexs(Ident SetHandle,Ident SetVertexHandle);
/*!

*/
			Void SelectionSet_SelectAll();
/*!

*/
			Void Curve2DPolygon(Ident FourVertexSetHandle,Ident Sethandle,Integer SubTexIndex);
/*!

*/
			Void Preview_Clear();
/*!

*/
			Void VoxelSpace_SetVec3(Vec3 Pos);
/*!

*/
			Integer VoxelSpace_GetVoxelsCount();
/*!

*/
			Void VoxelSpace_SelectAll();
/*!

*/
			Void VoxelSpace_DeleteOneVoxel();
/*!

*/
			Void VoxelSpace_DeleteSelection();
/*!

*/
			Void VoxelSpace_ApplyMaterialToVoxel();
/*!

*/
			Void VoxelSpace_GenerateMesh();
/*!

*/
			Vec3 VoxelSpaceCenter;
/*!

*/
			Real VoxelSpaceStep;
/*!

*/
			Boolean VoxelSpaceIsInteractive;
/*!

*/
			Void SetOfElements_ProjectOnPlane(Ident SetHandle);
/*!

*/
			Void SetOfElements_ProjectOnGround(Ident SetHandle,Real Height);
/*!

*/
			Void SetOfElements_SplitEdgeWithVertex(Ident SetHandle);
/*!

*/
			Void SetOfElements_CollapseEdgeWithVertex(Ident SetHandle);
/*!

*/
			Void SetOfElements_Subdivide(Ident SetHandle);
/*!

*/
			Void SetOfElements_Subdivide_Interpolation(Ident SetHandle);
/*!

*/
			Void SetOfVertices_DrawCircle(Ident InputSetHandle,Ident ResultSetHandle);
/*!

*/
			Void SetOfVertices_DrawDisc(Ident InputSetHandle,Ident ResultSetHandle);
/*!

*/
			Void SetOfVertices_DrawCircle(Ident CenterSetHandle,Vec3 PointOnCircle,Ident ResultSetHandle);
/*!

*/
			Void SetOfVertices_DrawIcosahedron(Ident InputSetHandle,Ident ResultSetHandle);
/*!

*/
			Void SetOfVertices_DrawIcosahedron(Ident CenterSetHandle,Vec3 PointOnCircle,Ident ResultSetHandle);
/*!

*/
			Void SetOfVertices_DrawIcosahedricSphere(Ident InputSetHandle,Ident ResultSetHandle);
/*!

*/
			Void SetOfVertices_DrawPoly(Ident InputSetHandle,Ident ResultSetHandle,Integer VerticesCount);
/*!

*/
			Void SetOfVertices_DrawPoly(Ident CenterSetHandle,Vec3 PointOnPoly,Ident ResultSetHandle,Integer VerticesCount);
/*!

*/
			Void SetOfVertices_DrawSpline(Ident ControlSetHandle,Ident ResultSetHandle);
/*!

*/
			Void SetOfVertices_Weld(Ident VerticesSetHandle);
/*!

*/
			Void SetOfVertices_DrawBox(Ident ControlSetHandle,Ident ResultSetHandle);
/*!

*/
			Void SetOfEdges_Fill(Ident SetHandle);
/*!

*/
			Void SetOfEdges_Flip(Ident SetHandle,Ident ResultSetHandle);
/*!

*/
			Void SetOfEdges_BorderExpand(Ident SetHandle);
/*!

*/
			Void SetOfOneEdge_FaceLoopExpand(Ident SetHandle);
/*!

*/
			Void SetOfOneEdge_EdgeLoopExpand(Ident SetHandle);
/*!

*/
			Void SetOfOneFace_CutHole(Ident FaceSetHandle,Ident EdgesSetHandle);
/*!

*/
			Void SetOfFaces_Extrude(Ident SetHandle,Ident ResultSetHandle);
/*!

*/
			Void SetOfFaces_QuadsToTriangles(Ident SetHandle,Ident ResultSetHandle);
/*!

*/
			Void SetOfFaces_ApplyMaterial(Ident SetHandle,Ident MaterialId);
/*!

*/
			Void SetOfFaces_PlanarExpand(Ident FacesSetHandle);
/*!

*/
			Void SetOfFaces_ChangeOrientation(Ident FacesSetHandle);
/*!

*/
	const	Text[] PrefabNames;
/*!

*/
	const	Integer PrefabNamesUpdateId;
/*!

*/
			Integer PrefabListCurrentPage;
/*!

*/
			Integer Prefab_TotalNb;
/*!

*/
			Void Prefabs_Reload();
/*!

*/
			Void Prefab_Export();
/*!

*/
			Void Prefab_Import(Integer PrefabIndex);
/*!

*/
			Boolean Parts_CanMergeParts();
/*!

*/
			Boolean Parts_CanGroupParts();
/*!

*/
			Boolean Parts_CanUngroupParts();
/*!

*/
			Int3 Parts_GetOpsState();
/*!

*/
			Void Parts_MergeSelectedParts();
/*!

*/
			Void Parts_Group();
/*!

*/
			Void Parts_UngroupSelectedParts();
/*!

*/
			Void Cut();
/*!

*/
			Void Copy();
/*!

*/
			Void AddUndoState();
/*!

*/
			Boolean AutoSave(Text FileName);
/*!

*/
	const	CEditorEvent[] PendingEvents;
/*!

*/
			Boolean MustClearLastSaveBuffer;
/*!

*/
	const	Boolean IsExperimental;
/*!

*/
			ETitleCoreType GetTitleCoreType();
};

/*!
Supported declare modes : Metadata 

*/
struct CEditorEditor : public CEditorBase {
/*!

*/
			Void Bindings_AddContext(Text ContextName);
/*!

*/
			Void Bindings_AddBinding(Text ContextName,Text BindingScriptId,Text BindingDisplayName);
/*!

*/
			Void Bindings_RemoveContext(Text ContextName);
/*!

*/
			Void Bindings_RemoveBinding(Text ContextName,Text BindingName);
/*!

*/
			Void Bindings_RequestInput(Text ContextName,Text BindingName);
/*!

*/
	const	Boolean Bindings_RequestInput_Done;
/*!

*/
			Void Bindings_SetBindingScriptId(Text ContextName,Text BindingScriptId,Text NewBindingScriptId);
/*!

*/
			Void Bindings_SetBindingDisplayName(Text ContextName,Text BindingScriptId,Text BindingDisplayName);
/*!

*/
			Void Bindings_SetContextName(Text ContextName,Text NewContextName);
/*!

*/
	const	Text[] BindingContexts;
/*!

*/
			Void Bindings_GetContextBindings(Text ContextName);
/*!

*/
	const	Text[] RequestedContextBindings;
/*!

*/
			Text Bindings_GetBindingActionName(Text ContextName,Text BindingName);
/*!

*/
			Text Bindings_GetBindingDisplayName(Text ContextName,Text BindingName);
/*!

*/
	const	CEditorEvent[] PendingEvents;
};

/*!
Supported declare modes : Local 
An event
*/
struct CMapEditorPluginEvent : public CManiaAppEvent {
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
		MapSavedOrSaveCancelled,
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
/*!

*/
	const	Boolean OnlyScriptMetadataModified;
/*!

*/
	const	Boolean MapSavedOrSaveCancelled;
};

/*!

*/
struct CMapEditorInventory : public CNod {
/*!

*/
	const	CMapEditorInventoryDirectory CurrentRootNode;
/*!

*/
	const	CMapEditorInventoryDirectory CurrentDirectory;
/*!

*/
	const	CMapEditorInventoryNode CurrentSelectedNode;
/*!

*/
			CMapEditorInventoryNode[] RootNodes;
/*!

*/
			Void EnterDirectory();
/*!

*/
			Void LeaveDirectory();
/*!

*/
			Void SelectArticle(CMapEditorInventoryArticle NodeArticle);
/*!

*/
			Void OpenDirectory(CMapEditorInventoryDirectory NodeDirectory);
/*!

*/
			Void SelectNode(CMapEditorInventoryNode Node);
/*!

*/
			Void OpenBrotherDirectory(Boolean NextOrElsePrevious);
/*!

*/
			Void SelectBrotherArticle(Boolean NextOrElsePrevious);
/*!

*/
			Void SelectBrotherNode(Boolean NextOrElsePrevious);
/*!

*/
			CMapEditorInventoryDirectory GetDirectoryAfter(CMapEditorInventoryNode Node);
/*!

*/
			CMapEditorInventoryDirectory GetDirectoryBefore(CMapEditorInventoryNode Node);
/*!

*/
			CMapEditorInventoryArticle GetArticleAfter(CMapEditorInventoryNode Node);
/*!

*/
			CMapEditorInventoryArticle GetArticleBefore(CMapEditorInventoryNode Node);
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
	const	CMapEditorPlugin::CardinalDirections Dir;
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
The model of a map block
*/
struct CBlockModel : public CCollector {
	enum EWayPointType {
		Start,
		Finish,
		Checkpoint,
		None,
		StartFinish,
		Dispenser,
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
	const	Boolean IsClip;
/*!

*/
	const	CBlockModelVariantGround VariantGround;
/*!

*/
	const	CBlockModelVariantAir VariantAir;
};

/*!

*/
struct CBlockClipList : public CNod {
/*!

*/
	const	CBlockClip[] Clips;
/*!

*/
	const	Int3 Size;
/*!

*/
			Boolean SetClipListFromMacroblock(CMacroblockModel MacroblockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			Boolean SetClipListFromMacroblock(CMacroblockModel MacroblockModel);
/*!

*/
			Boolean SetClipListFromBlock(CBlockModel BlockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			Boolean SetClipListFromBlock(CBlockModel BlockModel);
/*!

*/
			Void CreateAndAddClip(Text Name,Int3 Coord,Int3 Offset,CMapEditorPlugin::CardinalDirections Dir,Integer ClipId);
/*!

*/
			Boolean SetFromClipList(CBlockClipList ClipList,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			Void RemoveClip(CBlockClip Clip);
/*!

*/
			Void ClearClips();
/*!

*/
			Void Destroy();
};

/*!

*/
struct CMacroblockInstance : public CNod {
/*!

*/
	const	CMacroblockModel MacroblockModel;
/*!

*/
	const	CBlockClipList ClipList;
/*!

*/
			CMapEditorPlugin::CardinalDirections Dir;
/*!

*/
	const	Int3 Coord;
/*!

*/
			Integer Order;
/*!

*/
			Integer UserData;
/*!

*/
	const	Int3[] UnitCoords;
/*!

*/
			Int3 GetSize();
};

/*!

*/
struct CMapEditorCamera : public CNod {
	enum EZoomLevel {
		Close,
		Medium,
		Far,
	};
	enum ECameraVStep {
		Low,
		MediumLow,
		Medium,
		MediumHigh,
		High,
	};
/*!

*/
			Void ReleaseLock();
/*!

*/
			Void CenterOnCursor();
/*!

*/
			Void WatchStart();
/*!

*/
			Void WatchClosestFinishLine();
/*!

*/
			Void WatchClosestCheckpoint();
/*!

*/
			Void WatchWholeMap();
/*!

*/
			Void WatchCustomSelection();
/*!

*/
			Void MoveToMapCenter();
/*!

*/
			Boolean GetLock();
/*!

*/
			Boolean CanUse();
/*!

*/
			Void TurnH(Boolean Clockwise);
/*!

*/
			Void TurnH(Boolean Clockwise,Boolean HalfSteps);
/*!

*/
			Void TurnH(Boolean Clockwise,Boolean HalfSteps,Boolean Smooth);
/*!

*/
			Void TurnV(Boolean UpOrElseDown);
/*!

*/
			Void TurnV(Boolean UpOrElseDown,Boolean Smooth);
/*!

*/
			Void Move(CMapEditorPlugin::RelativeDirections RelativeDir);
/*!

*/
			Void FollowCursor(Boolean Follow);
/*!

*/
			Void CenterOnCursor(Boolean Smooth);
/*!

*/
			Void MoveToMapCenter(Boolean Smooth);
/*!

*/
			Void Watch(CBlock Block);
/*!

*/
			Void Watch(CBlock Block,Boolean Smooth);
/*!

*/
			Void Watch(CMacroblockInstance Macroblock);
/*!

*/
			Void Watch(CMacroblockInstance Macroblock,Boolean Smooth);
/*!

*/
			Void Watch(CBlockClip Clip);
/*!

*/
			Void Watch(CBlockClip Clip,Boolean Smooth);
/*!

*/
			Void WatchStart(Boolean Smooth);
/*!

*/
			Void WatchClosestFinishLine(Boolean Smooth);
/*!

*/
			Void WatchClosestCheckpoint(Boolean Smooth);
/*!

*/
			Void WatchWholeMap(Boolean Smooth);
/*!

*/
			Void WatchMacroblocks(Integer UserData);
/*!

*/
			Void WatchMacroblocks(Integer UserData,Boolean Smooth);
/*!

*/
			Void ZoomIn(Boolean Loop);
/*!

*/
			Void ZoomIn(Boolean Loop,Boolean Smooth);
/*!

*/
			Void ZoomOut(Boolean Loop);
/*!

*/
			Void ZoomOut(Boolean Loop,Boolean Smooth);
/*!

*/
			Void Zoom(EZoomLevel Level);
/*!

*/
			Void Zoom(EZoomLevel Level,Boolean Smooth);
/*!

*/
			Void Look(CMapEditorPlugin::CardinalDirections8 Direction);
/*!

*/
			Void Look(CMapEditorPlugin::CardinalDirections8 Direction,Boolean Smooth);
/*!

*/
			Void Look(CMapEditorPlugin::CardinalDirections Direction);
/*!

*/
			Void Look(CMapEditorPlugin::CardinalDirections Direction,Boolean Smooth);
/*!

*/
			Void SetVStep(ECameraVStep Step);
/*!

*/
			Void WatchCustomSelection(Boolean WatchCustomSelection);
};

/*!

*/
struct CMapEditorCursor : public CNod {
/*!

*/
			Void ReleaseLock();
/*!

*/
			Int3 Coord;
/*!

*/
			CMapEditorPlugin::CardinalDirections Dir;
/*!

*/
			CBlockModel BlockModel;
/*!

*/
			CBlockModel TerrainBlockModel;
/*!

*/
			CMacroblockModel MacroblockModel;
/*!

*/
			Real Brightness;
/*!

*/
			Boolean HideDirectionalArrow;
/*!

*/
			Void MoveToCameraTarget();
/*!

*/
			Void ResetCustomRGB();
/*!

*/
			Boolean GetLock();
/*!

*/
			Boolean CanUse();
/*!

*/
			Boolean Raise();
/*!

*/
			Boolean Lower();
/*!

*/
			Void FollowCameraTarget(Boolean Follow);
/*!

*/
			Void Rotate(Boolean CWOrCCW);
/*!

*/
			Void Move(CMapEditorPlugin::CardinalDirections CardinalDir);
/*!

*/
			Void Move(CMapEditorPlugin::CardinalDirections8 CardinalDir8);
/*!

*/
			Void Move(CMapEditorPlugin::RelativeDirections RelativeDir);
/*!

*/
			Void DisableMouseDetection(Boolean Disable);
/*!

*/
			Boolean CanPlace();
/*!

*/
			Boolean IsCustomRGBActivated();
/*!

*/
			Void SetCustomRGB(Vec3 Color);
};

/*!

*/
struct CItemAnchor : public CNod {
/*!

*/
	const	Vec3 Position;
};

/*!

*/
struct CMapEditorConnectResults : public CNod {
/*!

*/
			Boolean CanPlace;
/*!

*/
			Int3 Coord;
/*!

*/
			CMapEditorPlugin::CardinalDirections Dir;
};

/*!
Supported declare modes : Metadata 
Landmark of a map.
*/
struct CAnchorData : public CNod {
	enum EWaypointType {
		Start,
		Finish,
		Checkpoint,
		None,
		StartFinish,
		Dispenser,
	};
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
	const	EWaypointType WaypointType;
/*!

*/
	const	Vec3 Position;
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
	const	Text AuthorZoneFlagUrl;
/*!

*/
	const	Text AuthorCountryFlagUrl;
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
	const	Boolean CreatedWithSimpleEditor;
/*!

*/
	const	Boolean CreatedWithPartyEditor;
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
	const	Integer TMObjective_NbLaps;
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
Supported declare modes : Local 
A currently connected CUser
*/
struct CClient : public CNod {
/*!

*/
	const	CUser User;
/*!

*/
	const	CUIConfig UI;
/*!
Otherwise, it's a LAN account not currently authentified with the masterserver.
*/
	const	Boolean IsConnectedToMasterServer;
/*!

*/
	const	Text ClientVersion;
/*!

*/
	const	Text ClientTitleVersion;
/*!

*/
	const	Boolean IsSpectator;
/*!
Duration during which the player is not active while they should be (AFK).
*/
	const	Integer IdleDuration;
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
Supported declare modes : Local 
ServerPlugin Event
*/
struct CServerPluginEvent : public CBaseConstEvent {
	enum EType {
		Unknown,
		ClientConnected,
		ClientDisconnected,
		MapLoaded,
		BeginMatch,
		BeginRound,
		EndRound,
		EndMatch,
		MapUnloadRequested,
		MapUnloaded,
		ChatCommand,
		ChatMessage,
		ModeCallback,
	};
/*!
Event type.
*/
	const	EType Type;
/*!

*/
	const	CClient Client;
/*!

*/
	const	Text ChatText;
/*!

*/
	const	Text ChatCommandType;
/*!

*/
	const	Text[] ChatCommandData;
/*!

*/
	const	Text ModeCallbackType;
/*!

*/
	const	Text[] ModeCallbackData;
/*!

*/
	const	CScore[] EndMatchScores;
/*!

*/
	const	Integer[] EndMatchRanks;
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
			CUIConfig GetUI(CClient Client);
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
/*!

*/
	const	CUIConfigEvent[] PendingEvents;
};

/*!
API for server control when playing online.
*/
struct CServerAdmin : public CNod {
	enum ESpecMode {
		Selectable,
		SpectatorForced,
		PlayerForced,
		SpectatorSelectable,
		PlayerSelectable,
	};
/*!
ServerInfo
*/
	const	CServerInfo ServerInfo;
/*!

*/
			Void AutoTeamBalance();
/*!

*/
			Boolean Kick(CUser User,Text Reason);
/*!

*/
			Boolean Kick(CClient Client,Text Reason);
/*!

*/
			Boolean Ban(CUser User,Text Reason);
/*!

*/
			Boolean Ban(CClient Client,Text Reason);
/*!

*/
			Boolean ForceSpectator(CUser User,ESpecMode SpecMode);
/*!

*/
			Boolean ForceSpectator(CClient Client,ESpecMode SpecMode);
/*!

*/
			Boolean ForcePlayerRequestedTeam(CUser User,Integer Team);
/*!
Team is 1 or 2.
*/
			Boolean ForcePlayerRequestedTeam(CClient Client,Integer Team);
/*!
Disable Team change UI on the clients.
*/
			Boolean IsDisableChangeTeams;
/*!

*/
			Void SetLobbyInfo(Boolean IsLobby,Integer LobbyPlayerCount,Integer LobbyMaxPlayerCount,Real LobbyPlayersLevel);
/*!

*/
			Void SendToServerAfterMatch(Text ServerUrl);
/*!

*/
			Void CustomizeQuitDialog(Text ManialinkPage,Text SendToServerUrl,Boolean ProposeAddToFavorites,Integer ForceDelay);
/*!
Always use NullId as UserId.
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
			Void Hud_Load(Text ModuleName);
/*!

*/
	const	CModulePlaygroundHud Hud;
/*!

*/
			Void PassOn(CUIConfigEvent EventToPassOn);
/*!

*/
			Void Discard(CUIConfigEvent EventToDiscard);
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
	const	CServerAdmin ServerAdmin;
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
	const	CParsingManager Xml;
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
	const	CDataFileMgr DataFileMgr;
/*!

*/
	const	CScoreMgr ScoreMgr;
/*!

*/
	const	CSystemPlatform System;
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
SkinNameOrUrl: can be 'Skins/Model/....', 'http://....', 'Default' (or '') for item default skin, 'Profile' for the user choice for the model. ModelName: 'DefaultPlayerModel' for the default map model, or the item filename.
*/
			Ident ItemList_AddWithSkin(Text ModelName,Text SkinNameOrUrl);
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
	const	CAchievementsManager AchievementsManager;
/*!

*/
	const	CModeTurretManager TurretsManager;
/*!

*/
	const	CModeVehicleManager VehiclesManager;
/*!

*/
	const	CActionManager ActionsManager;
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

*/
	const	Integer StaminaMaxValue;
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

*/
	const	Boolean IsInVehicle;
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
	const	Vec3 Velocity;
/*!

*/
	const	Real Speed;
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
	const	Boolean IsInWater;
/*!

*/
	const	Boolean IsInOffZone;
/*!

*/
	const	Boolean IsOnTech;
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
	const	Boolean IsOnTechNucleus;
/*!

*/
	const	Boolean IsOnTechArmor;
/*!

*/
	const	Boolean IsOnTechSafeZone;
/*!

*/
	const	Boolean IsOnTechTeleport;
/*!

*/
	const	Boolean IsOnTechNoWeapon;
/*!

*/
	const	Boolean IsPowerJumpActivable;
/*!

*/
	const	Boolean IsTeleportActivable;
/*!

*/
	const	Boolean IsAttractorActivable;
/*!

*/
	const	Integer NbActiveAttractors;
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
	const	CModeVehicle Vehicle;
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
Supported declare modes : Local 
Event recieved by ShootMania gamemodes.
*/
struct CSmModeEvent : public CBaseEvent {
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
		OnPlayerThrowsObject,
		OnPlayerTriggersSector,
		OnPlayerTriggersWaypoint,
		OnPlayerRequestActionChange,
		OnVehicleArmorEmpty,
		OnVehicleCollision,
		OnVehicleVsVehicleCollision,
		OnVehicleLanding,
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
	const	Integer VictimShield;
/*!

*/
	const	CEntity VictimEntity;
/*!

*/
			Integer ShooterPoints;
/*!

*/
	const	CEntity ShooterEntity;
/*!

*/
	const	Integer ShooterClan;
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
	const	Integer WaypointTime;
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
struct CSmMapLandmark : public CMapLandmark {
/*!

*/
	const	CSmMapBase Base;
/*!

*/
	const	CSmMapGate Gate;
/*!

*/
	const	CSmMapGauge Gauge;
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
struct CSmObject : public CEntity {
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
			Void SetAnchor(CMapObjectAnchor ObjectAnchor);
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
/*!

*/
	const	Ident ThrowLatestPlayerId;
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
Will be Null if the script is not runing in a layer of an app.
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
	const	Integer SplitScreenNum;
/*!

*/
	const	Integer SplitScreenCount;
/*!

*/
			Void PlayUiSound(EUISound Sound,Integer SoundVariant,Real Volume);
/*!

*/
	const	CAchievementsManager AchievementsManager;
};

/*!
Supported declare modes : Local 

*/
struct CModeVehicle : public CEntity {
/*!

*/
			Integer Armor;
/*!

*/
			Integer ArmorMax;
/*!

*/
	const	Vec3 Position;
/*!

*/
	const	Real Pitch;
/*!

*/
	const	Real Roll;
/*!

*/
	const	Vec3 Left;
/*!

*/
	const	Vec3 Up;
/*!

*/
	const	Vec3 Dir;
/*!

*/
	const	Vec3 Velocity;
/*!

*/
	const	Real Altitude;
/*!

*/
			Integer Clan;
/*!

*/
			Real AccelCoef;
/*!

*/
	const	Real AccelInput;
/*!

*/
			Void SetEngineActivated(Boolean IsActivated);
};

/*!

*/
struct CAction : public CNod {
};

/*!
Supported declare modes : Local 
An action event
*/
struct CSmActionEvent : public CBaseConstEvent {
	enum EType {
		OnHitPlayer,
		OnProjectileEnd,
		OnProjectileDestroyed,
		OnActiveChange,
		OnHitObject,
		OnHitShield,
		OnHitVehicle,
		OnShieldEnd,
		OnHitTurret,
	};
/*!

*/
	const	EType Type;
/*!

*/
	const	Ident ProjectileModelId;
/*!

*/
	const	Integer Damage;
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
/*!

*/
	const	CEntity Victim;
/*!

*/
	const	Integer Shield;
};

/*!
Supported declare modes : Local  Persistent 
API for the plugins of the map editor.
*/
struct CMapType : public CMapEditorPlugin {
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
	const	CTrackManiaScore Score;
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
alias of HandicapNoGasDuration
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
	const	Integer HandicapNoGasDuration;
/*!

*/
	const	Integer HandicapFullGasDuration;
/*!

*/
	const	Integer HandicapNoBrakesDuration;
/*!

*/
	const	Integer HandicapNoSteeringDuration;
/*!

*/
	const	Integer HandicapNoGripDuration;
/*!

*/
	const	Integer StuntLastTime;
/*!

*/
	const	ESceneVehiclePhyStuntFigure StuntLast;
/*!

*/
	const	Integer StuntAngle;
/*!

*/
	const	Integer StuntPoints;
/*!

*/
	const	Integer StuntCombo;
/*!

*/
	const	Real StuntFactor;
/*!

*/
	const	Boolean StuntStraightLanding;
/*!

*/
	const	Boolean StuntReverseLanding;
/*!

*/
	const	Boolean StuntPerfectLanding;
/*!

*/
	const	Boolean StuntMasterJump;
/*!

*/
	const	Boolean StuntMasterLanding;
/*!

*/
	const	Boolean StuntEpicLanding;
/*!

*/
	const	Boolean StuntIsInFigure;
/*!

*/
	const	Boolean StuntCurFigureMasterJump;
/*!
Values in range (0.000000-1.000000)
*/
	const	Real StuntCurFigureMasterGauge;
/*!
Values in range (0.000000-1.000000)
*/
	const	Real StuntCurFigureEpicGauge;
/*!

*/
	const	Boolean StuntCurComboChainCounter;
/*!

*/
	const	Integer TimeLeftForStuntCombo;
/*!

*/
	const	Integer TimeElapsedSinceLastStunt;
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
	const	Integer UniqueCameraRespawnCount;
/*!

*/
	const	Integer UniqueCameraAvailableRespawnLeft;
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
Approximated value, very dependent on network quality.
*/
	const	Vec3 Position;
/*!
Approximated value, very dependent on network quality.
*/
	const	Real AimYaw;
/*!
Approximated value, very dependent on network quality.
*/
	const	Real AimPitch;
/*!
Approximated value, very dependent on network quality.
*/
	const	Vec3 AimDirection;
/*!
Approximated value, very dependent on network quality.
*/
	const	Vec3 Velocity;
/*!
Approximated value, very dependent on network quality.
*/
	const	Real Speed;
/*!

*/
			Ident ForceModelId;
/*!

*/
	const	Integer IdleDuration;
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
	const	Real Factor;
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
	const	Boolean IsPerfectLanding;
/*!

*/
	const	Boolean IsMasterJump;
/*!

*/
	const	Boolean IsMasterLanding;
/*!

*/
	const	Boolean IsEpicLanding;
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

*/
struct CMlFrame : public CMlControl {
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
			Boolean ScrollActive;
/*!

*/
			Vec2 ScrollOffset;
/*!

*/
	const	Vec2 ScrollAnimOffset;
/*!

*/
			Vec2 ScrollMax;
/*!

*/
			Vec2 ScrollMin;
/*!

*/
			Boolean ScrollGridSnap;
/*!

*/
			Vec2 ScrollGrid;
/*!

*/
			Void Scroll(Vec2 DeltaInGridUnits);
/*!

*/
			Void ScrollBumpTop();
/*!

*/
			Void ScrollBumpBottom();
/*!

*/
			Void ScrollBumpLeft();
/*!

*/
			Void ScrollBumpRight();
/*!

*/
			Boolean DisablePreload;
};

/*!

*/
struct CParsingDocument : public CNod {
/*!

*/
	const	Text TextContents;
/*!

*/
	const	CParsingNode Root;
/*!

*/
	const	CParsingNode[] Nodes;
/*!

*/
			CParsingNode GetFirstChild(Text Name);
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
An HTTP event.
*/
struct CHttpEvent : public CNod {
	enum EType {
		RequestComplete,
	};
/*!

*/
	const	EType Type;
/*!
Request triggering the event
*/
	const	CHttpRequest Request;
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
		Mouse,
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
Asynchronous task result.
*/
struct CTaskResult : public CNod {
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
	const	Text ErrorType;
/*!
Returns the code of the error if the task has failed.
*/
	const	Text ErrorCode;
/*!
Returns the description of the error if the task has failed.
*/
	const	Text ErrorDescription;
/*!

*/
			Void Cancel();
};

/*!

*/
struct CCampaign : public CNod {
/*!

*/
	const	Text CampaignId;
/*!

*/
			CMapGroup[] MapGroups;
/*!

*/
			Integer GetMapGroupCount();
/*!

*/
			CMapGroup GetMapGroup(Integer Index);
/*!

*/
			CMapInfo GetNextMap(CMapInfo CurrentMapInfo);
/*!

*/
			Text ScoreContext;
/*!

*/
			Boolean OfficialRecordEnabled;
};

/*!
Results containing a list of map info.
*/
struct CTaskResult_MapList : public CTaskResult {
/*!
Path of the parent zone.
*/
	const	Text ParentPath;
/*!
Path of the current zone.
*/
	const	Text Path;
/*!
List of the map info. Array of CMapInfo objects.
*/
	const	CMapInfo[] MapInfos;
/*!
List of the sub folders. Array of string.
*/
	const	Text[] SubFolders;
};

/*!
Ghost
*/
struct CGhost : public CNod {
/*!

*/
	const	Ident Id;
/*!
Result associated to this ghost (score/time/respawncount).
*/
	const	CTmResult Result;
/*!
Nickname of the player.
*/
			Text Nickname;
};

/*!
Task result containing a ghost.
*/
struct CTaskResult_Ghost : public CTaskResult {
/*!
Ghost contained by this result.
*/
	const	CGhost Ghost;
};

/*!
Results containing a list of replay info.
*/
struct CTaskResult_ReplayList : public CTaskResult {
/*!
Path of the parent zone.
*/
	const	Text ParentPath;
/*!
Path of the current zone.
*/
	const	Text Path;
/*!
List of the replay info. Array of CReplayInfo objects.
*/
	const	CReplayInfo[] ReplayInfos;
/*!
List of the sub folders. Array of string.
*/
	const	Text[] SubFolders;
};

/*!
Results containing a list of ghost.
*/
struct CTaskResult_GhostList : public CTaskResult {
/*!
List of ghost. Array of CGhost.
*/
	const	CGhost[] Ghosts;
};

/*!
Results containing a list of media info.
*/
struct CTaskResult_FileList : public CTaskResult {
/*!
Path of the parent zone.
*/
	const	Text ParentPath;
/*!
Path of the current zone.
*/
	const	Text Path;
/*!
List of files. Array of string.
*/
	const	Text[] Files;
/*!
List of the sub folders. Array of string.
*/
	const	Text[] SubFolders;
};

/*!
Results containing a list of GameMode info.
*/
struct CTaskResult_GameModeList : public CTaskResult {
/*!
Description of the GameMode
*/
	const	CTaskResult_ModeInfo[] GameModes;
};

/*!
Results containing a part of the leaderboard.
*/
struct CTaskResult_NaturalLeaderBoardInfoList : public CTaskResult_NaturalLeaderBoardInfoList {
/*!
Starting index.
*/
	const	Integer FromIndex;
/*!
Number of item contained.
*/
	const	Integer Count;
/*!
List of the ranking info. Array of CNaturalLeaderBoardInfo objects.
*/
	const	CNaturalLeaderBoardInfo[] LeaderBoardInfo;
};

/*!
Results containing a list of map records.
*/
struct CTaskResult_MapRecordList : public CTaskResult_PlayerMapRecords {
/*!
List of the map records. Array of CPlayerMapRecord objects.
*/
	const	CTaskResult_MapRecord[] MapRecordList;
};

/*!
List of all buddies record for a map.
*/
struct CTaskResult_BuddiesChallengeRecord : public CTaskResult {
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
struct CTaskResult_BuddiesChallengeRecordsComparison : public CTaskResult {
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
struct CTaskResult_BuddyChallengeRecordsComparison : public CTaskResult {
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
struct CTaskResult_RealLeaderBoardInfoList : public CTaskResult_RealLeaderBoardInfoList {
/*!
Starting index.
*/
	const	Integer FromIndex;
/*!
Number of item contained.
*/
	const	Integer Count;
/*!
List of the ranking info. Array of CRealLeaderBoardInfo objects.
*/
	const	CRealLeaderBoardInfo[] LeaderBoardInfo;
};

/*!

*/
struct CPlug : public CNod {
};

/*!
Local profile settings.
*/
struct CUserV2Profile : public CNod {
	enum EMapEditorMode {
		Ask,
		Advanced,
	};
	enum ECustomPlayerModels {
		All,
		OnlyTextures,
		None,
	};
	enum EInputMouseReleaseKey {
		LeftAlt,
		RightAlt,
		LeftCtrl,
		RightCtrl,
	};
/*!

*/
	const	Boolean CanChangePassword;
/*!

*/
	const	Boolean CanChangeNickName;
/*!
avatar, horn and podium pose
*/
	const	Boolean CanChangeAvatar;
/*!

*/
	const	Boolean CanChangeSkin;
/*!

*/
	const	Boolean CanChangeZone;
/*!

*/
	const	Boolean CanChangeGroups;
/*!

*/
			Void Account_ResetChanges();
/*!

*/
			Text Account_Name;
/*!

*/
			Text Account_EMail;
/*!

*/
			Boolean Account_AcceptNews;
/*!

*/
			Boolean Account_EnableAutoConnect;
/*!
Values in range (0.000000-1.000000)
*/
			Real User_LightTrailHue;
/*!
Values in range (0.500000-2.000000)
*/
			Real User_HornPitch;
/*!

*/
			Text User_Description;
/*!

*/
			Text User_ClubLinkUrl;
/*!

*/
			Boolean Custom_EnableAvatars;
/*!

*/
			Boolean Custom_EnableChat;
/*!

*/
			ECustomPlayerModels Custom_PlayerModels;
/*!

*/
			Boolean Custom_EnableUnlimitedHorns;
/*!
Favoured way to open the Map Editor
*/
			EMapEditorMode Editors_MapEditorMode;
/*!

*/
			Boolean Online_AutoSaveReplay;
/*!

*/
			Boolean Online_SaveRoundReplaysSeparately;
/*!

*/
			Boolean Title_IsForbiddenWithParentalLock;
/*!

*/
			Boolean Steam_OpenLinksInSteam;
/*!

*/
			Boolean Steam_SynchonizeWorkshopFiles;
/*!
Values in range (-40.000000-0.000000)
*/
			Real Audio_MasterSoundVolume;
/*!
Values in range (-40.000000-0.000000)
*/
			Real Audio_MasterMusicVolume;
/*!

*/
			Boolean Audio_DontMuteWhenAppUnfocused;
/*!

*/
			Boolean Interface_CrosshairEnableCustomColor;
/*!
Values in range (0.000000-1.000000)
*/
			Real Interface_CrosshairSaturation;
/*!
Values in range (0.000000-1.000000)
*/
			Real Interface_CrosshairLinearHue;
/*!
Values in range (0.100000-2.000000)
*/
			Real Interface_CrosshairSize;
/*!
Values in range (0.100000-1.000000)
*/
			Real Interface_CrosshairOpacity;
/*!

*/
			Text Interface_CrosshairName;
/*!
Values in range (0.100000-2.000000)
*/
			Real Interface_PlayerShieldScale;
/*!

*/
			Boolean Interface_AllyEnableCustomColor;
/*!
Values in range (0.000000-1.000000)
*/
			Real Interface_AllyLinearHue;
/*!

*/
			Boolean Interface_OppoEnableCustomColor;
/*!
Values in range (0.000000-1.000000)
*/
			Real Interface_OppoLinearHue;
/*!

*/
			Boolean Interface_BeaconUseProfileColor;
/*!
Values in range (0.000000-1.000000)
*/
			Real Interface_BeaconOpacity;
/*!
Values in range (0.100000-5.000000)
*/
			Real Interface_BeaconSize;
/*!
Values in range (0.500000-15.000000)
*/
			Real Interface_BeaconDuration;
/*!

*/
			Boolean Inputs_MouseLookInvertY;
/*!

*/
			EInputMouseReleaseKey Inputs_MouseReleaseKey;
/*!
Values in range (0.100000-3.000000)
*/
			Real Inputs_MouseScaleY;
/*!
Values in range (0.100000-3.000000)
*/
			Real Inputs_MouseScaleFreeLook;
/*!
Values in range (0.000000-3.000000)
*/
			Real Inputs_MouseAccel;
/*!
Values in range (-1.000000-1.000000)
*/
			Real Inputs_MouseSensitivityDefault;
/*!
Values in range (-1.000000-1.000000)
*/
			Real Inputs_MouseSensitivityLaser;
/*!

*/
			Real Inputs_MouseSensitivityDefault_Raw;
/*!

*/
			Real Inputs_MouseSensitivityLaser_Raw;
/*!

*/
			CVehicleSettings[] Inputs_Vehicles;
};

/*!
Asynchronous task result.
*/
struct CTaskResult_StringIntList : public CTaskResult {
/*!

*/
	const	Text[] Values;
};

/*!

*/
struct CServerInfo : public CNod {
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
/*!

*/
	const	Boolean IsPrivateForSpectator;
/*!

*/
	const	Text SendToServerAfterMatchUrl;
};

/*!
Script API to create Packs (can be Titlepacks or plain ManiaCredited data), and generate new builds of these packs.
*/
struct CPackCreator : public CNod {
/*!
Register (or retreive) a package for the currently edited title.
*/
			Void RegisterPackForEditedTitle();
/*!

*/
	const	Boolean RegisterPack_IsInProgess;
/*!

*/
	const	CPackCreatorPack CurrentPack;
/*!
Start a new build for a pack, optionnaly a titlepack.
*/
			Ident Build_Begin(CPackCreatorPack Pack,CPackCreatorTitleInfo TitleInfo);
/*!

*/
			Void Build_AddFile(Ident BuildId,Text FileName);
/*!

*/
			Void Build_AddFolder(Ident BuildId,Text FolderName);
/*!

*/
			Void Build_AddFile(Ident BuildId,Text FileName,Boolean IsPublic,Boolean IsInternal,Boolean NoAutomaticDeps);
/*!

*/
			Void Build_AddFolder(Ident BuildId,Text FolderName,Boolean IsPublic,Boolean IsInternal,Boolean NoRecursion,Boolean NoAutomaticDeps);
/*!

*/
			Void Build_Generate(Ident BuildId,Boolean Upload);
/*!

*/
			Boolean Build_IsGenerated(Ident BuildId);
/*!

*/
			Text Build_ErrorMessage(Ident BuildId);
/*!

*/
			Void Build_End(Ident BuildId);
};

/*!
An event.
*/
struct CNotificationsConsumerEvent : public CNod {
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
	const	CNotificationsConsumerNotification Notification;
};

/*!
A Notification.
*/
struct CNotificationsConsumerNotification : public CNod {
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
Supported declare modes : Local 
Event concerning achievements.
*/
struct CAchievementsEvent : public CBaseConstEvent {
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
	const	CAchievementsAchievement Achievement;
};

/*!
An achievement earned by a user.
*/
struct CAchievementsAchievement : public CNod {
/*!
User that earned the achievement.
*/
	const	Ident UserId;
/*!
Description of the achievement.
*/
	const	CAchievementsAchievementDesc AchievementDesc;
};

/*!
Achievement stat.
*/
struct CAchievementsStat : public CNod {
/*!
User that owns the stat.
*/
	const	Ident UserId;
/*!
Description of the stat.
*/
	const	CAchievementsStatDesc StatDesc;
/*!
Value of the stat.
*/
	const	Integer Value;
};

/*!
An achievement's description.
*/
struct CAchievementsAchievementDesc : public CNod {
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
struct CAchievementsStatDesc : public CNod {
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
Represents a match-settings file
*/
struct CMatchSettings : public CNod {
/*!
Name of the file
*/
	const	Text Name;
/*!

*/
	const	Text FileName;
/*!

*/
			Text ScriptModeName;
/*!

*/
			Boolean ScriptModeName_Check(Text ScriptModeName);
/*!

*/
			Void ScriptModeName_Set(Text ScriptModeName);
/*!

*/
	const	CMatchSettingsPlaylistItem[] Playlist;
/*!

*/
			Boolean Playlist_FileExists(Text File);
/*!

*/
			Boolean Playlist_FileMatchesMode(Text File);
/*!

*/
			Void Playlist_Add(Text File);
/*!

*/
			Void Playlist_Remove(Integer Index);
/*!

*/
			Void Playlist_SwapUp(Integer Index);
/*!

*/
			Void Playlist_SwapDown(Integer Index);
};

/*!
Supported declare modes : Local 
An event
*/
struct CManiaAppPlaygroundEvent : public CManiaAppEvent {
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

*/
	const	Ident SettingsPlayerModelId;
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
	const	Boolean IsInGameMenuDisplayed;
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
	enum EMessageDisplay {
		Chat,
		Small,
		Status,
		Big,
	};
	enum EObserverMode {
		Default,
		Forced,
		Forbidden,
		Manual,
	};
	enum EHudVisibility {
		Nothing,
		Everything,
		MarkersOnly,
		Default,
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
			EHudVisibility LabelsVisibility;
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
When not in spectator mode, allow/forbid to change the camera to observe other players. (in Trackmania there's no 'Manual' mode.)
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
/*!

*/
			Void QueueMessage(Integer Duration,Integer Priority,EMessageDisplay Level,Text Message,CUser Avatar,EAvatarVariant AvatarVariant,EUISound Sound,Integer SoundVariant);
/*!

*/
			Void QueueMessage(Integer Duration,Integer Priority,EMessageDisplay Level,Text Message,EUISound Sound,Integer SoundVariant);
/*!

*/
			Void QueueMessage(Integer Duration,Integer Priority,EMessageDisplay Level,Text Message);
/*!

*/
			Void ClearMessages();
};

/*!
Supported declare modes : Metadata 

*/
struct CEditorBase : public CNod {
};

/*!

*/
struct CModuleMenuModel : public CNod {
/*!

*/
			CModuleMenuPageModel[] Pages;
/*!

*/
			CModuleMenuPageModel AddPage(Text PageUrl);
/*!

*/
			Void AddLink(CModuleMenuPageModel ParentPage,CModuleMenuPageModel ChildPage);
/*!

*/
			Text MenuScript;
};

/*!

*/
struct CModuleMenuPageModel : public CNod {
/*!

*/
			Text ManialinkText;
};

/*!

*/
struct CModulePlaygroundHudModel : public CNod {
/*!

*/
			Ident SubModuleAdd(Text ModulePath,Text ModuleName);
/*!

*/
			Ident SubModuleSetNameAndId(Ident ModuleId,Text NewModuleName);
/*!

*/
			Void SubModuleRemove(Ident ModuleId);
/*!

*/
			Boolean SubModuleIsContextActive(Ident ModuleId,Ident ContextId);
/*!

*/
			Void SubModuleSetContextIsActive(Ident ModuleId,Ident ContextId,Boolean IsActive);
/*!

*/
			Ident ContextAdd(Text ContextName);
/*!

*/
			Ident ContextSetId(Ident ContextId,Text NewContextName);
/*!

*/
			Void ContextRemove(Ident ContextId);
/*!

*/
	const	Ident[] ContextsIds;
/*!

*/
	const	Ident[] SubModuleIds;
/*!

*/
			Void SubModuleRetrieve(Ident ModuleId);
/*!

*/
			SHudModule SubModule;
/*!

*/
	const	Integer EditorContextIndex;
};

/*!
Supported declare modes : Local 
An event
*/
struct CEditorPluginModuleEvent : public CManiaAppEvent {
	enum Type {
		LayerCustomEvent,
		KeyPress,
		(reserved),
		MenuNavigation,
		Exit,
		FileNew,
		FileOpen,
		FileSave,
		FileSaveAs,
	};
/*!

*/
	const	Type Type;
/*!

*/
			Void Eat();
};

/*!
Supported declare modes : Metadata 

*/
struct CEditorAsset : public CEditorBase {
};

/*!
Supported declare modes : Local 
An event
*/
struct CEditorEvent : public CManiaAppEvent {
	enum Type {
		LayerCustomEvent,
		KeyPress,
		(reserved),
		MenuNavigation,
		FileChanged,
		Exit,
		FileSave,
		OnUndo,
		OnRedo,
		OnSwitchedBack,
		CameraButtonOn,
		CameraButtonOff,
		VoxelUpdateMaterial,
		OpenUVEditor,
		CloseUVEditor,
		EnableUndo,
		DisableUndo,
		EnableRedo,
		DisableRedo,
	};
/*!

*/
	const	Type Type;
};

/*!

*/
struct CMapEditorInventoryDirectory : public CMapEditorInventoryNode {
/*!

*/
	const	CMapEditorInventoryNode[] Children;
/*!

*/
	const	Boolean HasChildDirectory;
/*!

*/
	const	Boolean HasChildArticle;
};

/*!

*/
struct CMapEditorInventoryNode : public CNod {
/*!

*/
	const	Text NodeName;
/*!

*/
	const	Boolean IsDirectory;
/*!

*/
	const	CMapEditorInventoryDirectory ParentNode;
/*!

*/
			CNod GetCollectorNod();
};

/*!

*/
struct CMapEditorInventoryArticle : public CMapEditorInventoryNode {
};

/*!
A 1-square-sized part of a block instance.
*/
struct CBlockUnit : public CNod {
/*!

*/
	const	Int3 AbsoluteOffset;
/*!

*/
	const	CBlockUnitModel BlockUnitModel;
/*!

*/
	const	CBlock Block;
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
/*!

*/
			Integer InterfaceNumber;
/*!

*/
	const	CImage Icon;
/*!

*/
	const	Text SkinDirectory;
};

/*!

*/
struct CBlockModelVariantGround : public CBlockModelVariant {
};

/*!

*/
struct CBlockModelVariantAir : public CBlockModelVariant {
};

/*!

*/
struct CBlockClip : public CNod {
/*!

*/
	const	Text Name;
/*!

*/
			CMapEditorPlugin::CardinalDirections Dir;
/*!

*/
	const	Int3 Coord;
/*!

*/
	const	Int3 Offset;
/*!

*/
			Integer ClipId;
/*!

*/
			Int3 GetConnectableCoord();
};

/*!
Supported declare modes : Local 
UIConfig Event
*/
struct CUIConfigEvent : public CBaseEvent {
	enum EType {
		Unknown,
		OnModuleCustomEvent,
		OnModuleShowRequest,
		OnModuleHideRequest,
		OnModuleStorePurchase,
		OnModuleInventoryDrop,
		OnModuleInventoryEquip,
		OnLayerCustomEvent,
	};
	enum EModuleType {
		Undefined,
		Hud,
		Inventory,
		Store,
		ScoresTable,
		Equipment,
		MenuBase,
		MenuPage,
		Chrono,
		SpeedMeter,
		PlayerState,
		TeamState,
	};
/*!

*/
	const	EType Type;
/*!

*/
	const	CUIConfig UI;
/*!

*/
	const	EModuleType ModuleType;
/*!

*/
	const	Text Param1;
/*!

*/
	const	Text[] Param2;
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
	const	Text ItemUrl;
/*!

*/
	const	Integer Quantity;
};

/*!
Supported declare modes : Local 
An event
*/
struct CXmlRpcEvent : public CBaseConstEvent {
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

*/
struct CModulePlaygroundHud : public CNod {
/*!

*/
			CModulePlaygroundInventory Inventory;
/*!

*/
			CModulePlaygroundStore Store;
/*!

*/
			CModulePlaygroundScoresTable ScoresTable;
/*!

*/
			CModulePlaygroundChrono Chrono;
/*!

*/
			CModulePlaygroundSpeedMeter SpeedMeter;
/*!

*/
			CModulePlaygroundPlayerState PlayerState;
/*!

*/
			CModulePlaygroundTeamState TeamState;
/*!

*/
	const	CModulePlayground[] Modules;
/*!

*/
			Void SwitchContext(CPlayer Player,Text ContextName);
/*!

*/
			Void SetDefaultContext(CPlayer Player);
/*!

*/
			Ident RetrieveModuleId(Text ModuleName);
};

/*!

*/
struct CModeTurretManager : public CNod {
/*!

*/
			Void MapTurrets_Reset();
/*!

*/
			CModeTurret Turret_Create(Ident ModelId,Vec3 Position,Vec3 Direction,Integer Clan,CPlayer OwnerPlayer);
/*!

*/
			CModeTurret Turret_CreateWithOwner(Ident ModelId,Vec3 Position,Vec3 Direction,Vec3 Up,Integer Clan,Ident OwnerId);
/*!

*/
			CModeTurret Turret_CreateWithOwner(Ident ModelId,Vec3 Position,Vec3 Direction,Vec3 Up,Integer Clan,Ident OwnerId,Boolean AutoAimOn,Boolean AutoTriggerOn);
/*!

*/
			Vec3 Turret_GetPosition(CModeTurret Turret);
/*!

*/
			Void Turret_Destroy(CModeTurret Turret);
/*!

*/
			Void Turret_DestroyAll();
/*!

*/
			Void Turret_Activate(CModeTurret Turret);
/*!

*/
			Void Turret_Deactivate(CModeTurret Turret);
/*!

*/
			Void Turret_SetIsAutomatic(CModeTurret Turret,Boolean IsAuto);
/*!

*/
			Void Turret_Auto_SetAimAnticipation(CModeTurret Turret,Real AimAnticipationMs);
/*!

*/
			Void Turret_Auto_SetFirePeriod(CModeTurret Turret,Integer FirePeriodMs);
/*!

*/
			Void Turret_Auto_SetTargetDetectionFov(CModeTurret Turret,Real DectectionFOVDeg);
/*!

*/
			Void Turret_Auto_SetTargetDetectionRadius(CModeTurret Turret,Real DetectionRadius);
/*!

*/
			CEntity Turret_Auto_GetTarget(CModeTurret Turret);
/*!

*/
			Void Turret_Manual_SetTargetPos(CModeTurret Turret,Vec3 TargetPos);
/*!

*/
			Void Turret_Manual_Fire(CModeTurret Turret);
/*!

*/
			CModeTurret[] Turrets;
};

/*!

*/
struct CModeVehicleManager : public CNod {
	enum EArmorUse {
		Self,
		Group,
		Owner,
		Children,
		Mine,
	};
	enum ESlotType {
		Driver,
		Passenger,
	};
/*!

*/
			Void MapVehicles_Reset();
/*!

*/
			Void DestroyAllVehicles();
/*!

*/
			CModeVehicle Vehicle_Create(Ident ModelId,Integer Clan,Integer Armor,EArmorUse ArmorUse,CMapSpawn Spawn);
/*!

*/
			CModeVehicle Vehicle_Create(Ident ModelId,Vec3 Offset,Integer Armor,EArmorUse ArmorUse,CModeVehicle Owner);
/*!

*/
			Void Vehicle_Destroy(CModeVehicle Vehicle);
/*!

*/
			Void Vehicle_Assign_AutoPilot(CModeVehicle Vehicle,Text ModelName);
/*!

*/
			Void Vehicle_Assign_AutoPilot(CModeVehicle Vehicle,Text ModelName,Boolean LoopPath);
/*!

*/
			Void Vehicle_SetTrailVisible(CModeVehicle Vehicle,Boolean IsVisible);
/*!

*/
			Void Vehicle_SetShieldVisible(CModeVehicle Vehicle,Boolean IsVisible);
/*!

*/
			Integer VehicleModel_GetSlotsCount(Ident ModelId,ESlotType SlotType);
/*!

*/
			CModeVehicle[] Vehicles;
};

/*!

*/
struct CActionManager : public CNod {
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
/*!

*/
			CActionInterface Action_GetState(CPlayer Player,EActionSlot Slot);
/*!

*/
			CActionInterface Action_GetState(CModeVehicle Vehicle,Integer VehicleSlotIndex,EActionSlot Slot);
/*!

*/
			CActionInterface Action_GetState(CModeTurret Turret,EActionSlot Slot);
/*!

*/
			CActionInterface[] Actions;
};

/*!
Supported declare modes : Local  NetworkRead  NetworkWrite 
A player is the incarnation of the user in the playground.
*/
struct CPlayer : public CEntity {
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
Supported declare modes : Local 
An event
*/
struct CBaseEvent : public CBaseConstEvent {
/*!

*/
	const	Boolean HasBeenPassed;
/*!

*/
	const	Boolean HasBeenDiscarded;
};

/*!

*/
struct CEntity : public CNod {
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
Supported declare modes : Local  Metadata 

*/
struct CMapLandmark : public CNod {
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
	const	CMapSector Sector;
/*!

*/
	const	CMapWaypoint Waypoint;
/*!

*/
	const	CMapSpawn PlayerSpawn;
/*!

*/
	const	CMapBotPath BotPath;
/*!

*/
	const	CMapBotSpawn BotSpawn;
/*!

*/
	const	CMapObjectAnchor ObjectAnchor;
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
Supported declare modes : Local  NetworkRead  NetworkWrite 

*/
struct CTrackManiaScore : public CTmScore {
};

/*!
Description of a race run.
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
			Integer Score;
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
struct CParsingNode : public CNod {
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
	const	CParsingNode[] Children;
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
			CParsingNode GetFirstChild(Text Name);
};

/*!

*/
struct CMapGroup : public CNod {
/*!

*/
			Void IsUnlocked();
/*!

*/
	const	CMapInfo[] MapInfos;
};

/*!

*/
struct CReplayInfo : public CNod {
/*!

*/
	const	Text MapUid;
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
A GameMode script.
*/
struct CTaskResult_ModeInfo : public CNod {
/*!
Name of the GameMode
*/
	const	Text Name;
/*!

*/
	const	Text Path;
/*!

*/
	const	Text Description;
/*!

*/
	const	Text Version;
/*!

*/
	const	Text[] CompatibleMapTypes;
};

/*!
Asynchronous task result.
*/
struct CTaskResult_NaturalLeaderBoardInfoList : public CTaskResult {
};

/*!
Ranking item of a leaderboard.
*/
struct CNaturalLeaderBoardInfo : public CNod {
/*!
Rank.
*/
	const	Integer Rank;
/*!
UserId.
*/
	const	Ident UserId;
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
	const	Integer Score;
/*!
FileName.
*/
	const	Text FileName;
/*!
ReplayUrl.
*/
	const	Text ReplayUrl;
};

/*!
Asynchronous task result.
*/
struct CTaskResult_PlayerMapRecords : public CTaskResult {
};

/*!
Map record info.
*/
struct CTaskResult_MapRecord : public CNod {
/*!
Context.
*/
	const	Text Context;
/*!
MapUid.
*/
	const	Text MapUid;
/*!
MapName.
*/
	const	Text MapName;
/*!
Score.
*/
	const	Integer Score;
/*!
Time.
*/
	const	Integer Time;
/*!
RespawnCount.
*/
	const	Integer RespawnCount;
/*!
Timestamp.
*/
	const	Integer Timestamp;
/*!
MultiAsyncLevel.
*/
	const	Integer MultiAsyncLevel;
/*!
SkillPoints.
*/
	const	Integer SkillPoints;
/*!
FileName.
*/
	const	Text FileName;
/*!
ReplayUrl.
*/
	const	Text ReplayUrl;
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
	const	Integer RecordScore;
/*!

*/
	const	Integer RecordTime;
/*!

*/
	const	Integer RecordRespawnCount;
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
	const	Integer OpponentRecordScore;
/*!

*/
	const	Integer OpponentRecordTime;
/*!

*/
	const	Integer OpponentRecordRespawnCount;
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
Asynchronous task result.
*/
struct CTaskResult_RealLeaderBoardInfoList : public CTaskResult {
};

/*!
Ranking item of a leaderboard.
*/
struct CRealLeaderBoardInfo : public CNod {
/*!
Rank.
*/
	const	Integer Rank;
/*!
UserId.
*/
	const	Ident UserId;
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
/*!
FileName.
*/
	const	Text FileName;
/*!
ReplayUrl.
*/
	const	Text ReplayUrl;
};

/*!
Vehicle or Character settings.
*/
struct CVehicleSettings : public CNod {
/*!

*/
	const	Text ModelDisplayName;
/*!

*/
	const	Text ModelName;
/*!
....
*/
	const	Text SkinName;
/*!
Values in range (0.100000-10.000000)
*/
			Real AnalogSensitivity;
/*!
Values in range (0.000000-0.250000)
*/
			Real AnalogDeadZone;
/*!

*/
			Boolean AnalogSteerV2;
/*!
Values in range (0.000000-2.000000)
*/
			Real RumbleIntensity;
/*!
Values in range (0.000000-1.000000)
*/
			Real CenterSpringIntensity;
};

/*!
A pack
*/
struct CPackCreatorPack : public CNod {
/*!
PackId is the TitleId if the pack is a TitlePack.
*/
	const	Ident PackId;
/*!

*/
	const	Ident CreatorId;
/*!

*/
	const	Boolean IsTitlePack;
/*!

*/
			Void Recipients_Add(Text Login,Integer UseCost,Integer GetCost);
/*!

*/
			Void Recipients_Remove(Text Login);
/*!

*/
	const	CPackCreatorRecipient[] Recipients;
};

/*!
Represents a map in the playlist of a matchsetting
*/
struct CMatchSettingsPlaylistItem : public CNod {
/*!
Name of the map
*/
	const	Text Name;
/*!
True if the file is found
*/
	const	Boolean FileExists;
};

/*!

*/
struct SHudModule {
/*!

*/
			Text ModuleName;
/*!

*/
			Real PosX;
/*!

*/
			Real PosY;
/*!

*/
			Real ZIndex;
/*!

*/
			Real Scale;
};

/*!
A 1-square-sized part of a block model.
*/
struct CBlockUnitModel : public CNod {
/*!

*/
	const	Int3 RelativeOffset;
/*!

*/
	const	CBlockModelClip[] Clips;
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
	const	CBlockUnitModel[] BlockUnitModels;
};

/*!
Supported declare modes : Local 

*/
struct CModeTurret : public CEntity {
/*!

*/
			Integer Armor;
/*!

*/
			Integer ArmorMax;
/*!

*/
	const	CPlayer Owner;
};

/*!

*/
struct CActionInterface : public CNod {
/*!

*/
	const	Integer Cooldown;
/*!

*/
	const	Integer CooldownStartTime;
/*!

*/
	const	Integer Energy;
/*!

*/
	const	Integer EnergyCost;
/*!

*/
	const	Integer EnergyMax;
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

*/
struct CMapSector : public CNod {
/*!

*/
	const	Ident[] PlayersIds;
/*!

*/
	const	Text Tag;
};

/*!

*/
struct CMapWaypoint : public CNod {
/*!

*/
	const	Boolean IsFinish;
/*!

*/
	const	Boolean IsMultiLap;
};

/*!

*/
struct CMapSpawn : public CNod {
};

/*!

*/
struct CMapBotPath : public CNod {
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
struct CMapBotSpawn : public CNod {
/*!

*/
	const	Boolean IsFlying;
/*!

*/
	const	Ident BotModelId;
};

/*!

*/
struct CMapObjectAnchor : public CNod {
/*!

*/
	const	Text ItemName;
/*!

*/
	const	Ident ItemModelId;
};

/*!
A recipient included in the bill for a Pack.
*/
struct CPackCreatorRecipient : public CNod {
/*!
Login of the recipient.
*/
	const	Text Login;
/*!
Cost to read the data (and see it ingame).
*/
	const	Integer GetCost;
/*!
Cost to use the in other creations.
*/
	const	Integer UseCost;
};

/*!
The model of a map block
*/
struct CBlockModelClip : public CBlockModel {
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

/*!
* \brief (undocumented)
*/
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
	Real DegToRad(Real Argument1);
	/*! 
	*
	*/
	Real RadToDeg(Real Argument1);
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
	Integer TruncInteger(Real Argument1);
	/*! 
	*
	*/
	Integer CeilingInteger(Real Argument1);
	/*! 
	*
	*/
	Real Distance(Real Argument1, Real Argument2);
	/*! 
	*
	*/
	Real Distance(Vec2 Argument1, Vec2 Argument2);
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
	* \brief Returns the smallest angle from A to B
	* 
	*
	*/
	Real Angle(Real _Radian1, Real _Radian2);
	/*! 
	*
	*/
	Real Angle(Vec2 Argument1, Vec2 Argument2);
	/*! 
	*
	*/
	Real OrientedAngle(Vec2 Argument1, Vec2 Argument2);
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

/*!
* \brief (undocumented)
*/
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
	* \brief Return True if the Text ends with the TextToFind
	* 
	* \param _TextToFind : The text you are looking for
	* \param _TextToSearchIn : The text you are searching in
	*
	*/
	Boolean EndsWith(Text _TextToFind, Text _TextToSearchIn);
	/*! 
	* \brief Return True if the Text ends with the TextToFind
	* 
	* \param _TextToFind : The text you are looking for
	* \param _TextToSearchIn : The text you are searching in
	* \param _IsFormatSensitive : True if you want to take Format into account, False elseway
	* \param _IsCaseSensitive : True if you want to take Case into account, False elseway
	*
	*/
	Boolean EndsWith(Text _TextToFind, Text _TextToSearchIn, Boolean _IsFormatSensitive, Boolean _IsCaseSensitive);
	/*! 
	* \brief Return True if the Text starts with the TextToFind
	* 
	* \param _TextToFind : The text you are looking for
	* \param _TextToSearchIn : The text you are searching in
	*
	*/
	Boolean StartsWith(Text _TextToFind, Text _TextToSearchIn);
	/*! 
	* \brief Return True if the Text starts with the TextToFind
	* 
	* \param _TextToFind : The text you are looking for
	* \param _TextToSearchIn : The text you are searching in
	* \param _IsFormatSensitive : True if you want to take Format into account, False elseway
	* \param _IsCaseSensitive : True if you want to take Case into account, False elseway
	*
	*/
	Boolean StartsWith(Text _TextToFind, Text _TextToSearchIn, Boolean _IsFormatSensitive, Boolean _IsCaseSensitive);
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
	* \brief Find occurences of the _Pattern in the _Text.
	* 
	* \param _Pattern : Pattern is a regular expression, similar to javascript syntax.
	* \param _Text : 
	* \param _Flags : Flags can be 'g' to find all occurences, 'i' to ignore case, 'm' for multiline mode.
	*
	*/
	Text[Void] RegexFind(Text _Pattern, Text _Text, Text _Flags);
	/*! 
	* \brief Captures the groups of the _Pattern in the matching _Text. group[0] is the whole pattern match.
	* 
	* \param _Pattern : Pattern is a regular expression, similar to javascript syntax.
	* \param _Text : 
	* \param _Flags : Flags can be 'i' to ignore case, 'm' for multiline mode.
	*
	*/
	Text[Void] RegexMatch(Text _Pattern, Text _Text, Text _Flags);
	/*! 
	* \brief Replace the _Pattern in the matching text with _Replacement.
	* 
	* \param _Pattern : Pattern is a regular expression, similar to javascript syntax.
	* \param _Text : 
	* \param _Flags : Flags can be 'g' to find all occurences, 'i' to ignore case, 'm' for multiline mode.
	* \param _Replacement : 
	*
	*/
	Text RegexReplace(Text _Pattern, Text _Text, Text _Flags, Text _Replacement);
	/*! 
	* \brief Lookup the text in the current translation dictionary.
	* 
	* Lookup the text in the current translation dictionary, and returns the translation, or returns the original text if not found.
	*
	*/
	Text GetTranslatedText(Text _Text);
};

/*!
* \brief (undocumented)
*/
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

/*!
* \brief (undocumented)
*/
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

/*!
* \brief (undocumented)
*/
namespace TimeLib {

	/*!
	
	*/
	enum EDateFormats {
		Full,
		Date,
		DateShort,
		Time,
		TimeShort,
		Relative,
		RelativeShort,
	};
	/*!
	
	*/
	enum EDurationFormats {
		Full,
		Abbreviated,
		Chrono,
	};
	/*! 
	* \brief Returns the date corresponding to a timestamp, formatted according to the locale. Not available on servers.
	* 
	* \param _Timestamp : Timestamp to format
	* \param _Format : Format
	*
	*/
	Text FormatDate(Text _Timestamp, EDateFormats _Format);
	/*! 
	* \brief Returns the duration between 2 timestamps, formatted according to the locale. Not available on servers.
	* 
	* \param _Timestamp1 : Timestamp1
	* \param _Timestamp2 : Timestamp2
	* \param _Format : Format
	*
	*/
	Text FormatDelta(Text _Timestamp1, Text _Timestamp2, EDurationFormats _Format);
	/*! 
	* \brief Returns the duration Delta formatted according to the locale. Not available on servers.
	* 
	* \param _Delta : Delta in seconds
	* \param _Format : Format
	*
	*/
	Text FormatDelta(Text _Delta, EDurationFormats _Format);
	/*! 
	* \brief Compares 2 timestamps
	* 
	* \param _Timestamp1 : Unix timestamp
	* \param _Timestamp2 : Unix timestamp
	*
	*/
	Integer Compare(Text _Timestamp1, Text _Timestamp2);
	/*! 
	* \brief Returns a Real between 0 and 1, given an interval and a timestamp
	* 
	* \param _Boundary1 : Lower boundary defining the time interval
	* \param _Boundary2 : Higher boundary defining the time interval
	* \param _Timestamp : Timestamp to check
	*
	*/
	Real Clamp01(Text _Boundary1, Text _Boundary2, Text _Timestamp);
	/*! 
	* \brief Gets current timestamp
	* 
	*
	*/
	Text GetCurrent();
	/*! 
	* \brief Returns the duration in seconds between 2 timestamps. May be clamped if huge.
	* 
	* \param _Timestamp1 : First timestamp. Result will be positive if this one is bigger/more recent
	* \param _Timestamp2 : Second timestamp
	*
	*/
	Integer GetDelta(Text _Timestamp1, Text _Timestamp2);
};

/*!
* \brief (undocumented)
*/
namespace ColorLib {

	/*! 
	*
	*/
	Vec3 HsvToRgb(Vec3 __Hsv);
	/*! 
	*
	*/
	Vec3 RgbToHsv(Vec3 __Rgb);
	/*! 
	*
	*/
	Text RgbToHex(Vec3 __Rgb);
	/*! 
	* \brief Returns the RGB color corresponding to _Text
	* 
	* Returns an empty Vec3 if an invalid Text is given
	* \param _Text : The text you want to convert into a RGB color
	*
	*/
	Vec3 HexToRgb(Text _Text);
};

