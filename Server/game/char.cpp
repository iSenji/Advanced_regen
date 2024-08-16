//Keress rá:
	if (m_pkRegen)
	{
		if (m_pkDungeon) {
			// Dungeon regen may not be valid at this point
			if (m_pkDungeon->IsValidRegen(m_pkRegen, regen_id_)) {
				--m_pkRegen->count;
			}
		} else {
			// Is this really safe?
			--m_pkRegen->count;
		}
//Utána add hozzá:

#ifdef ENABLE_RENEVAL_REGEN
		DWORD timecalc = (GetMobRank() == MOB_RANK_BOSS) ? number(m_pkRegen->time, m_pkRegen->time+(m_pkRegen->time/2)) : m_pkRegen->time;
		m_pkRegen->nextRespawn = m_pkRegen->time ? time(0) + timecalc : 0;
#endif
