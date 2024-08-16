//Keress rá:
	DWORD	time;

//Add hozzá utána:
#ifdef ENABLE_RENEVAL_REGEN
	time_t	nextRespawn;
#endif

//Keress rá:
		time(0),

//Add hozzá utána:
#ifdef ENABLE_RENEVAL_REGEN
		nextRespawn(0),
#endif
