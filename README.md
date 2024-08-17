1. Ezzel a módosítással beállítható időintervallum az újra spawnoláshoz.
2. Eltünés/ megölés utánatól fog elindulni az új respawn event.
3. CHARACTER::Destroy() funkció után fog megtörténni az új idő beállítása a spawn-nak.

Minden pályán a boss.txt, npc.txt ...stb fáljt ki kell egészíteni egy intervallum oszloppal közvetlen a respawn idő után.
Ugyan úgy használható az 's','m','h' a megadott érték után.

Példa a .txt fáljra:
-Régi:m  804  830  1  1  0  0  10s  100  1  591
-Új  :m  804  830  1  1  0  0  10s  10s  100  1  591

Így ha megölésre kerül az 591-es szörny, akkor 10-20 másodperc között fog valamikor újra éledni. 
(Nem közvetlen megöléstől megy az idő hanem CHARACTER::Destroy()-tól (CHARACTER::Destroy() == amikor eltünik a valami (Megölt szörny esetén a holtteste)))
