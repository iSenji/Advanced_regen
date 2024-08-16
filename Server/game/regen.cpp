//Keress rá (EVENTFUNC(regen_event)) belül:
	regen_spawn(regen, false);

	return PASSES_PER_SEC(regen->time);

//Cseréld le:
#ifdef ENABLE_RENEVAL_REGEN
	if(regen->nextRespawn)
	{
		if(regen->nextRespawn <= time(0))
			regen_spawn(regen, false);
	}
	else
		regen_spawn(regen, false);

	return PASSES_PER_SEC(1);
#else
	regen_spawn(regen, false);

	return PASSES_PER_SEC(regen->time);
#endif

//Keress rá:
regen->event = event_create(regen_event, info, PASSES_PER_SEC(number(0, 16)) + PASSES_PER_SEC(regen->time));

//Cseréld le:
#ifdef ENABLE_RENEVAL_REGEN
				regen->event = event_create(regen_event, info, PASSES_PER_SEC(1)); 
#else
				regen->event = event_create(regen_event, info, PASSES_PER_SEC(number(0, 16)) + PASSES_PER_SEC(regen->time)); 
#endif
