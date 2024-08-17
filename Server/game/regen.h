//Keress rá:
	DWORD	time;

//Add hozzá utána:
#ifdef ENABLE_RENEVAL_REGEN
	DWORD	timeRange;
	time_t	nextRespawn;
#endif

//Keress rá:
		time(0),

//Add hozzá utána:
#ifdef ENABLE_RENEVAL_REGEN
		timeRange(0),
		nextRespawn(0),
#endif
