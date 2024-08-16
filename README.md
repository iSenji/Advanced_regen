Ezzel a módosítással a CHARACTER::Destroy() után fog csak újra spawnolni Szörny/NPC .. stb
Ha ez egy Szörny és MOB_RANK_BOSS akkor az újra spawnolás megölés utántól a regen.txt-ben, boss.txt-ben... stb megadott idő
és az idő 1,5*-ös intervallum között fog megtörténni valamikor.

//Példa: Boss-nak 1 óra respawn van beállítva 21:00-kor megölik akkor random fog újraéledni 22:00 és 22:30 között.

//Hamarosan ki fogom egészíteni egy kisebb módosítással, ahol a txt-ben megadható lesz egy 'x-ig' érték ami erre fog szolgálni, hogy mi magunk állítsuk be
ezt az intervallumot.
