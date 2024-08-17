//Keress rá:
	MODE_Z_SECTION,
	MODE_DIRECTION,
	MODE_REGEN_TIME,

//Add hozzá utána:
#ifdef ENABLE_RENEVAL_REGEN
	MODE_REGEN_TIME_RANGE,
#endif

//Keress rá:
	int mode = MODE_TYPE;
	int tmpTime;

Add hozzá utána:
#ifdef ENABLE_RENEVAL_REGEN
	int tmpTimeRange;
#endif

//Keress rá:
			case MODE_REGEN_TIME:
			[...]
			break;

Add hozzá utána:
#ifdef ENABLE_RENEVAL_REGEN
			case MODE_REGEN_TIME_RANGE:
				regen->timeRange = 0;
				tmpTimeRange = 0;

				for (i = 0; i < strlen(szTmp); ++i)
				{
					switch (szTmp[i])
					{
						case 'h':
							regen->timeRange += tmpTimeRange * 3600;
							tmpTimeRange = 0;
							break;

						case 'm':
							regen->timeRange += tmpTimeRange * 60;
							tmpTimeRange = 0;
							break;

						case 's':
							regen->timeRange += tmpTimeRange;
							tmpTimeRange = 0;
							break;

						default:
							if (szTmp[i] >= '0' && szTmp[i] <= '9')
							{
								tmpTimeRange *= 10;
								tmpTimeRange += (szTmp[i] - '0');
							}
					}
				}

				++mode;
				break;
#endif



//Keress rá (EVENTFUNC(regen_event)) belül:
	regen_spawn(regen, false);
	return PASSES_PER_SEC(regen->time);

//Add hozzá előtte:
#ifdef ENABLE_RENEVAL_REGEN
	if(regen->nextRespawn > 0)
	{
		if(regen->nextRespawn <= time(0))
		{
			regen_spawn(regen, false);
			regen->nextRespawn = 0;
			return PASSES_PER_SEC(number(regen->time, regen->timeRange));
		}
		else
		{
			//fix
			DWORD nextSpawn = static_cast<DWORD>(regen->nextRespawn - time(0));
			return PASSES_PER_SEC(nextSpawn);
		}
	}
#endif
