# MediaInfo Viewer

[Čeština](README.cs-CZ.md) | [English (US)](../README.md) | [English (UK)](README.en-GB.md) | [English (Australia)](README.en-AU.md) | [Deutsch](README.de-DE.md) | [Français](README.fr-FR.md) | [Español](README.es-ES.md) | [Italiano](README.it-IT.md) | [Português](README.pt-PT.md) | [Polski](README.pl-PL.md) | [Slovenčina](README.sk-SK.md) | [Dansk](README.da-DK.md) | [Suomi](README.fi-FI.md) | [Íslenska](README.is-IS.md) | [Norsk (bokmål)](README.nb-NO.md) | [Svenska](README.sv-SE.md) | [Türkçe](README.tr-TR.md) | [Eesti](README.et-EE.md) | [Gaeilge](README.ga-IE.md) | [Lietuvių](README.lt-LT.md) | [Latviešu](README.lv-LV.md) | **Magyar** | [Malti](README.mt-MT.md) | [Nederlands](README.nl-NL.md) | [Română](README.ro-RO.md) | [Ελληνικά](README.el-GR.md) | [Bosanski](README.bs-Latn-BA.md) | [Hrvatski](README.hr-HR.md) | [Slovenščina](README.sl-SI.md) | [Crnogorski](README.cnr-Latn-ME.md) | [Беларуская](README.be-BY.md) | [Български](README.bg-BG.md) | [Македонски](README.mk-MK.md) | [Српски](README.sr-Cyrl-RS.md) | [Українська](README.uk-UA.md) | [Русский](README.ru-RU.md)

Natív Windows x86 megjelenítő a MediaInfo.dll jelentéseihez. Minden fájlnak saját, csak olvasható lapja van.

[Fordítás és kompatibilitás](#fordítás) | [Függőségek ellenőrzése](#függőségek) | [Licenc](../license.txt)

## Fordítás

Nyissa meg a MediaInfo.sln-t a Visual Studio 2015-ban a Visual C++ v140 eszközkészlettel. Válassza a Release | lehetőséget Win32 és készítse el a megoldást. Az egyetlen alkalmazásplatform a Win32 (x86).

[PCRE2 10.49](https://github.com/PCRE2Project/pcre2/tree/pcre2-10.49) — UTF-16, statikusan csatolva,
BSD-3-Clause. [Forráskód](../MediaInfo/PCRE2/).
[license.txt](../license.txt).
A PCRE2 az EXE része, ezért nem igényel külön DLL-t vagy további telepítést.

Kimenetek:

- Release\MediaInfo.exe
- Debug\MediaInfo.exe

A megjelenítő nem kapcsolja össze a C vagy C++ futási környezetet, és nincs szüksége MSVC újraterjeszthetőre.
A kiválasztott MediaInfo.dll saját függőséggel rendelkezhet.

Az építéshez Windows PowerShell és .NET Framework szükséges. Ezek csak összeállítási követelmények; a natív
végrehajtható fájl nem igényel sem PowerShell, sem .NET.

### Terjesztési csomag

A Release felépítése után futtassa a
`powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\PackageRelease.ps1` -t. A szkript létrehozza a
`MediaInfo-<version>-win32.zip` fájlt a megoldási könyvtárban, a végrehajtható fájl négy részből álló
fájlverziójával. Az archívum közvetlenül a gyökérben tartalmazza a `MediaInfo.exe` -t és a kombinált
`license.txt` -t.

## Kompatibilitás

A Win32 megjelenítőt a Windows NT 4.0 APIs használatára tervezték.

A végrehajtható fájl három x86 MediaInfo könyvtárat tartalmaz: 26.10 az aktuális Windows, 21.03 a Windows XP
csomagból és 0.7.60 a Windows 95–2000 csomagból. Egy könyvtár architektúrája önmagában nem határozza meg az
operációs rendszer kompatibilitását. A megjelenítő megpróbálja a kötegelt könyvtárakat a legújabbtól a
legrégebbiig, és leáll az első sikeres betöltés és verzió lekérdezés után.

A Windows 95 jelenleg nem támogatott futtatókörnyezet.

## Az alkalmazás használata

- Fájl > Megnyitás (Ctrl+O) megnyitja a Windows fájl párbeszédpanelt többszörös kijelöléssel. Windows Vista és
  újabb verziókon a Megnyitás és a Mentés a modern Common Item párbeszédablakot használja; régebbi Windows a
  régi gyakori párbeszédpaneleket használja.
- Húzzon egy vagy több fájlt az ablakra, az EXE ikonjára vagy parancsikonjára, vagy adja meg az elérési
  útjukat a parancssorban. Ha több példány nem engedélyezett, a fájlok a már futó ablakban nyílnak meg.
- Minden különálló normalizált teljes elérési útnak egy lapja van. Egy már megnyitott fájl újranyitásakor a
  meglévő fület kiválasztja anélkül, hogy újratöltené vagy módosítaná a jelentését, a kijelölését vagy a
  görgetési pozícióját. Az összehasonlítások figyelmen kívül hagyják az elérési utat a kis- és nagybetűket. A
  több fájl megnyitása sorrendben feldolgozza a listát, és az utoljára sikeresen feldolgozott fájlt aktívan
  hagyja, akár újonnan nyitotta meg, akár már megnyitotta. Ha egy lapfejléc fölé viszi az egeret, a natív
  eszköztippben megjelenik a teljes fájl elérési útja, beleértve azt is, ha a megjelenített fájlnév le van
  rövidítve.
- A Fájl menü a nyolc legutóbb betöltött fájlt sorolja fel közvetlenül a Kilépés felett, az elválasztók
  között. A bejegyzések csak egy számot és fájlnevet mutatnak. Egy bejegyzés kiválasztása megnyitja a tárolt
  teljes elérési utat, vagy kiválasztja a meglévő lapot; a sikeres újranyitás ismétlődések nélkül a tetejére
  helyezi. Egy nem elérhető fájl kiválasztásakor megkérdezi, hogy törölje-e a legutóbbi fájlok bejegyzését. A
  natív kérdés ikon és a Yes/No gombok használatosak. Igen az alapértelmezett, és eltávolítja a bejegyzést a
  menüből és a rendszerleíró adatbázisból; Nem tartja meg. A prompt tartalmazza a teljes elérési utat.
- Az egérgörgő túlcsorduló lapfejlécei a kijelölés vagy a fókusz megváltoztatása nélkül görgetik a fejlécsávot
  üzenetenként egy füllel.
- Ctrl+Tab és Ctrl+Shift+Tab lapok váltása; Ctrl+W bezárja az aktív lapot. A lap fejlécére való középső
  kattintás bezárja azt, miközben a többi aktív lap megmarad. A Fájl > Összes bezárása bezár minden lapot,
  beleértve a sorban álló jelentéseket is. A Fájl > Kilépés (Alt+F4) bezárja az alkalmazást.
- Dupla kattintással kiválaszt egy szót. Három kattintással kiválaszt egy logikai sort. Az elhúzás szavakkal
  vagy sorokkal bővíti a kijelölést.
- Ctrl+A kiválasztja a jelentést; Ctrl+C másolja.
- A Szerkesztés > Keresés (Ctrl+F) az aktív lapon keres. Az F3 megismétli a keresést, a Shift+F3 pedig
  megfordítja az irányát. A szöveg végéhez érve a keresés a másik végéről folytatódik. A Beállítások >
  Sortörés csak az aktív lapra érvényes; a jelölés a kiválasztott lapot követi. A keresőablak kis méretre
  állítható és vízszintesen átméretezhető; a helyzete és a Mindig felül beállítás megmarad. Legfeljebb 30
  keresési szöveg és beállításaik csak az alkalmazás bezárásáig maradnak meg. A sor elejére és végére
  vonatkozó beállítások logikai sorokra érvényesek. A reguláris kifejezések PCRE2-szintaxist használnak. A
  Szerkesztés menü összes parancsa csak az aktív lapra érvényes. Az Enter elindítja a keresést; a Shift+Enter
  megfordítja a kiválasztott irányt. A „Kis- és nagybetűk megkülönböztetése” megkülönbözteti a kis- és
  nagybetűket; a „Keresés visszafelé” a szöveg eleje felé keres. Egy előzmény kiválasztása visszaállítja mind
  az öt keresési beállítást, beleértve a reguláris kifejezések módjának állapotát is; a „Mindig felül” ettől
  független. A „Reguláris kifejezés” letiltja a „Sor elején” és „Sor végén” beállításokat. Ha mindkét
  sorhatárra vonatkozó feltétel be van kapcsolva, bármelyik sorhatáron elég az egyezés. A „Sortörés” csak a
  megjelenítést módosítja.
- A Beállítások > Beállítások (Ctrl+G) egyetlen beállítási párbeszédpanelt nyit meg a MediaInfo és curl
  útvonalak, a jelentés betűtípusa, a betűtípus élsimítása, a felület nyelve és a jelentés nyelve számára. Az
  üres DLL elérési út lehetővé teszi az automatikus felderítést.
- A betűtípus gomb megjeleníti a családot, a pontméretet és a stílust, és megnyitja a szabványos Windows
  betűtípus párbeszédpanelt. Az alapértelmezett visszaállítja a Consolas vagy Courier New értéket, ha a
  Consolas nem érhető el; az Alapértelmezett gomb le van tiltva, amíg az alapértelmezett van kiválasztva. A
  felhasználó által kiválasztott betűtípusok alkalmazáskóddal való helyettesítés nélkül megmaradnak.
- A betűtípus élsimítási lehetőségek a következők: ClearType, ha támogatott, GDI és Nincs. A kezdeti választás
  ClearType, ha támogatott, egyébként GDI. A betűtípus-beállítások csak a médiajelentésekre és azok
  képexportálására vonatkoznak.
- A Súgó egy különálló, modell nélküli ablakot nyit meg, saját tálcán lévő bejegyzéssel és kicsinyítés
  gombbal. A About egy modális párbeszédpanel; termékfejlécében mindhárom beágyazott DLL verzió szerepel.

A Nyomtatás… (Ctrl+P) megnyitja a rendszer nyomtatóválasztó párbeszédablakát, és előnézet nélkül kinyomtatja
az aktív lap teljes tartalmát. A jelentés betűtípusát használja; a hosszú sorokat tördeli és a szöveget
oldalakra osztja. A nyomtatás a háttérben fut.

A Mappa megnyitása… a kiválasztott mappában közvetlenül található fájlokat külön-külön lapon nyitja meg. Az
almappák nem szerepelnek benne. A Megnyitás és a Mappa megnyitása közösen használja az utoljára kiválasztott
mappát. Az exportálás külön mappát jegyez meg, alapértelmezésben a Dokumentumokat.

A Haladó mód további mezőket jelenít meg a jelentésben.

Teljes elemzés megvizsgálja a teljes fájlt, és tovább tarthat. Ezek a jelentésbeállítások és a Nyomkövetési
szint az egyes lapokhoz tartoznak; a módosítás csak az aktív lapot frissíti. Az utoljára manuálisan
kiválasztott kombináció mentésre kerül az új lapokhoz és a következő indításhoz. A megfelelő gyorsítótárazott
jelentést a rendszer újra felhasználja, amíg a fájl változatlan marad.

Az Ismert formátumok, Ismert kodekek és Ismert paraméterek külön jelentéslapokon nyílnak meg.

Az ablak kezdeti méretét és helyét a Windows választja ki. A korábban mentett ablakelhelyezés felülírja ezeket
az alapértelmezett értékeket a későbbi indításoknál.

Az állapotsor bal oldala a fájlok elérési útját és a betöltés állapotát, a jobb oldala a betöltött
MediaInfo.dll verzióját mutatja. A hosszú elérési utak a rendelkezésre álló helyhez igazodva három ponttal
rövidülnek.

## Fejlécfájl létrehozása

Az Eszközök a menüsor negyedik menüje. A Fejlécfájl létrehozása… parancsa egy forrásfájlt nyit meg a
jelentéslapoktól függetlenül, és átmásolja annak első 524288 bájtját (512 KiB). A rövidebb fájlt teljes
egészében másolja; egy üres fájl üres kimenetet ad. Ez egy közönséges bináris fájlolvasás, MediaInfo elemzés
vagy MediaInfo.dll követelmény nélkül. Az eszköz változatlanul hagyja a jelentéslapokat és a megtekintő
legutóbbi fájlok listáját.

Az olvasás után a Mentés másként párbeszédablak elindul a forrásfájl mappájában, és a video.mp4.header fájlt
javasolja a video.mp4 számára: a .header hozzá van fűzve a teljes eredeti névhez. Módosíthatja a nevet és a
célmappát is. Bármelyik párbeszédpanel megszakítása nem ír ki kimenetet. Meglévő célhely cseréje megerősítést
igényel. A forrás változatlan marad; a sikertelen mentés megőrzi az előző célt. A megnyitás és a mentés az
adott Windows-verzióban elérhető legkorszerűbb rendszer-párbeszédpaneleket használja.

Az alkalmazás indításakor az eszköz a kezdeti beviteli mappát a Fájl > Megnyitás mappából veszi. Ha még nincs
mentett mappa, a Windows kiválasztja a kezdeti helyet. A bemeneti fájl kiválasztása után az eszköz csak a
saját mappájára emlékszik az alkalmazás kilépéséig, még akkor is, ha megszakítja a Mentés másként
párbeszédpanelt. Nem módosítja az Megnyitás és Exportálás által használt mappákat, és nem menti el saját
mappáját az alkalmazás beállításaihoz. Minden Mentés másként párbeszédablak az aktuálisan kiválasztott
beviteli fájl mappájában kezdődik, függetlenül az előző mentési céltól.

## Könyvtárak keresése

Először egy mentett kézi elérési utat próbál meg. Ha nem tölthető be, az automatikus felderítés megpróbálja:

1. MediaInfo.dll a végrehajtható fájl mellett, majd minden szülőkönyvtárban egészen a meghajtóig vagy UNC
   megosztása gyökérkönyvtárig.
2. ProgramFiles, ProgramFiles(x86) és ProgramW6432.
3. LOCALAPPDATA és APPDATA.

Ezen telepítési gyökerek alatt a felfedezés ellenőrzi a MediaInfo, MediaArea\MediaInfo, MediaArea,
MediaArea.net\MediaInfo, Programs\MediaInfo, Programs\MediaArea\MediaInfo. Az olvashatatlan helyek és az
inkompatibilis DLLs kihagyásra kerülnek. Nem vizsgálja rekurzív módon a lemezt.

Ha nem található kompatibilis külső DLL, a megjelenítő a beágyazott verziókkal próbálkozik a következő
sorrendben: 26.10, 21.03, 0.7.60. Egyszerre egy verziót bont ki és tesztel. Ha egy verzió sikeresen
betöltődik, a régebbi verziók nem kerülnek kibontásra és tesztelésre. A MediaInfo.exe terjesztése önmagában
elegendő; egy kompatibilis külső DLL mindig elsőbbséget élvez, és függetlenül frissíthető.

A sikertelen kézi könyvtármódosítás megtartja a már betöltött könyvtárat.

## Jelentés exportálása

A Mentés másként formátumok sorrendje: TXT, BMP, GIF, JPEG, PNG, TIFF és WebP. A nem támogatott kódolók mind a
modern, mind a régi párbeszédpanelekből kimaradtak.

A TXT az ANSI, UTF-8, UTF-8 BOM-mal, UTF-16 BE BOM-mal és UTF-16 LE BOM-mal lehetőségeket kínálja. Az
alapértelmezett a második elem, az UTF-8 BOM nélkül. A jelentés teljes szövege és eredeti sorvégei
megmaradnak.

BMP, PNG és TIFF megőrzi az összes renderelt színt; A GIF89a megőrzi a pontos renderelt palettát, ha a kép
legfeljebb 256 színnel rendelkezik. Az Export mindig a kiválasztott formátumot írja, vagy hibát jelez; soha
nem helyettesít más formátumot.

## A felület és a jelentések nyelve

A Beállítások (Beállítások > Beállítások, Ctrl+G) tartalmazza a könyvtárak útvonalát, a jelentés betűtípusát,
az élsimítást és a nyelveket. A felületnek 36 változata van, kezdetben a Windowst követi. A jelentések
alapértelmezése mindig a könyvtár eredeti angol nyelve, a Windowstól és a felülettől függetlenül. Csak a kézi
választás változtatja meg: angol, 37 fordítás vagy saját MediaInfo CSV-tábla.

Az OK vagy az Alkalmaz véglegesíti a módosításokat; a Mégse elveti a függő módosításokat. A Beállításokban
korlátozható a lapnév hossza (alapérték 80), és törölhető a legutóbbi fájlok listája. A hosszú nevek eleje,
vége és kiterjesztése megmarad, középen három ponttal.

Alapértelmezés szerint csak egy példány engedélyezett, és a későbbi indítások átadják a fájlokat a nyitott
ablaknak. A beállításokban több példány is engedélyezhető. Több ablak esetén csak az egyes űrlapok első ablaka
állítja vissza a mentett pozíciót; a továbbiak csak a méretet.

Ha csak a felületet módosítja, a nyitott jelentések szövege változatlan marad. A jelentések manuálisan
alkalmazott nyelvének módosítása újratölti a jelentéseket, miközben megőrzi a tabulátorok sorrendjét és a MRU
sorrendet.

## libcurl

Automatikus curl felderítési ellenőrzések a kiválasztott MediaInfo DLL, majd a megosztott executable/ancestor,
Programfájlok és felhasználói telepítési helyek mellett. Ha nem található kompatibilis külső curl, akkor a
megfelelő beágyazott aktuális vagy XP verzió kicsomagolásra kerül az ellenőrzött felhasználónkénti
gyorsítótárba. A legrégebbi MediaInfo 0.7.60 teljesen megkerüli a curl felfedezést, kibontást és betöltést.
Egy kifejezetten kiválasztott érvénytelen curl elutasítja a beállításmódosítást; hiányzik az opcionális
automatikus curl nem akadályozza meg a szokásos helyi fájl jelentéseket.

## Fájlnevek és a legutóbbi fájlok

A MRU fájlnevek csak akkor rövidülnek, ha hosszabbak, mint 80 UTF-16 kódegység. A középső ellipszis megőrzi a
fájlnév elejét, végét a kiterjesztése előtt és a teljes végső kiterjesztést; a teljes útvonalak és a
jelentések változatlanok maradnak. A lapfeliratok ugyanazt az algoritmust használják, 80 konfigurálható
alapértelmezett korláttal.

Legutóbbi fájlok > Törlés azonnal törli az élő MRU menüt és annak mentett elérési útjait, miközben az összes
nyitott lap érintetlenül marad. Nem alkalmazza és nem érvényesíti a függőben lévő beállításokat, és nem
engedélyezi az Alkalmazást. A Mégse vagy Kilépés funkció megőrzi a törölt előzményeket, miközben elveti a
függőben lévő szerkesztéseket. A Clear le van tiltva, ha a lista üres, és az állapota frissül, amikor új
jelentések töltik fel a listát. A rendszerleíró adatbázis írási hibáját azonnal jelenteni kell. Az új
lapnév-korlát alkalmazása minden megnyitott lapot frissít anélkül, hogy újratöltené a médiajelentést.

## Licenc és újraelosztás

A néző a license.txt MIT licence alatt áll.

A MediaInfo harmadik féltől származó összetevő. Az egyetlen karbantartott terjesztési közlemény a root
license.txt, UTF-8 kódolású CRLF-val, és tartalmazza a megjelenítőt, a könyvtárakat, a statikusan beépített
összetevőket, az ikonokat és a hivatalos fordítási táblázatokat.

Ez a termék a MediaInfo könyvtárat használja, Copyright (c) 2002-2026 MediaArea.net SARL.

- MediaInfo: <https://mediaarea.net/MediaInfo>
- Engedély: <https://mediaarea.net/en/MediaInfo/License>
- Windows letöltések: <https://mediaarea.net/en/MediaInfo/Download/Windows>

## Függőségek

### Fájlok

| Forrás | Építészet | Az összetevő által jelentett verzió | SHA-256 |
| --- | --- | --- | --- |
| Resources/lib/26.10/MediaInfo.dll | x86 | 26.10 | E73027A1577084135425AA013D46C8B2985AD142CCF04F1ADB301B9A9CFB78F8 |
| Resources/lib/21.03/MediaInfo.dll | x86 | 21.03 | EBBF1C371702F3DC39CA23D619C47EDF97E66A95AEABE725284F1402D8F3E58A |
| Resources/lib/0.7.60/MediaInfo.dll | x86 | 0.7.60 | A26C07BCC25FA01A40E6888D02EABD59AA8DB2ABF6F5195481228D3A91D04441 |
| Resources/lib/26.10/libcurl.dll | x86 | 8.11.0-DEV, Schannel, zlib 1.3.1 | DCF136C84F3A4FBEAE2B317FE36D7F11225B56FBA3343AF4BBA8706B3F46F334 |
| Resources/lib/21.03/libcurl.dll | x86 | 7.47.1, WinSSL, zlib 1.2.8 | 21025CAC8089F1E570EE083D8CFD6311C2C51E97094A9FCD8C7A0B544C22CB48 |
| Resources/lib/libwebp.dll | x86 | 1.1.0 | 9986023BB6FF5510A157919F0CD958A94800EC6A1D981F3403A9648BEDFEE575 |

A táblázat elérési útjai a MediaInfo projektkönyvtárához viszonyítottak.

A jelenlegi könyvtár fejlesztési verziót közöl; pontos forrása commit nem állítható vissza ebből a
verzió-karakterláncból. A kísérő közlemény az upstream 8.11.0 szerzői jogi és engedélyszöveget használja,
amelynek licencfeltételei szintén jelen vannak a fejlesztési sorozatban.

### Beépített összetevők

| Összetevő | Bizonyítékok és terjedelem | Értesítés |
| --- | --- | --- |
| MediaInfoLib | A tényleges verziók és a szükséges Unicode-exportok; változatlan binárisok | Verzióspecifikus eredeti szerzői jog, továbbterjesztési feltételek és felelősség kizárása |
| ZenLib | Statikus projekthivatkozások és beágyazott ZenLib RTTI mindhárom DLLs-ba; a pontos linkelt változatok nincsenek megadva | zlib-stílusú ZenLib megjegyzés |
| zlib | Beágyazott inflate/deflate verziójú karakterláncok: 1.3.2 in MediaInfo 26.10, 1.2.11 in 21.03, 1.2.7 in 0.7.60; curl emellett 1.3.1 és 1.2.8 jelentéseket is tartalmaz | Eredeti zlib megjegyzések mind az öt verzióhoz |
| TinyXML-2 | Megfelelő modern forráscélok és bináris RTTI; szerepel az örökölt projektben, de nincs önállóan azonosítva a törölt örökölt binárisban | Az eredeti Lee Thomason zlib stílusú megjegyzés megmarad |
| Brian Gladman AES | Mindkét modern upstream könyvtári célban megtalálható, megfelelő megengedő forrásmegjegyzésekkel | 1998–2013 újraterjesztési közlemény és felelősségkizárás |
| Brian Gladman SHA-1/SHA-2 | Mindkét modern célpont; A SHA-256 és a SHA-512 konstans táblák mindkét modern binárisban megtalálhatók | 1998–2010 újraterjesztési közlemény és felelősségkizárás |
| Brian Gladman HMAC | Mind a modern célpontok, mind a curl/S3 olvasókódjuk | Eredeti három feltételre vonatkozó értesítés, beleértve az alternatív licenciát is |
| MD5 | Modern forráscélok; A Colin Plumb megvalósítás kifejezetten közterületet ír elő | A hozzárendelés megtartva |
| Base64 | Markus Ewald fejléc mindhárom megfelelő forrásfában, Bob Withers jóváírással | Az eredeti szerzői megjelölés megtartva; alatti minősítést |
| fmt | 26.10 cél és fmt v11 format_error RTTI a binárisban | Eredeti MIT értesítés, beleértve az opcionális kivételt |
| tfsxml | 26.10 forráscél | Eredeti MediaArea MIT közlemény |
| Android JNI felület | A JNI_OnLoad-t valójában mindkét modern DLLs exportálja; a mellékelt JNI fejléc a AOSP-ból származik | AOSP szerzői jog és teljes Apache licenc 2.0 |
| libcurl | Mellékelt x86 binárisok; tényleges verzióexportok; dinamikusan használja a modern MediaInfo | Eredeti curl közlemények 8.11.0 és 7.47.1 |
| Hivatalos jelentésfordítások | Minden 38 módosítatlan CSV forrás a MediaInfo v26.10 nyelvi könyvtárból; A 37 nem angol nyelvű táblázatok be vannak ágyazva, míg az angol az DLL alapértelmezett értékeket használja | Ugyanaz a projekt BSD-2-Clause közleménye megmaradt a kombinált közleményben |
| MediaInfo ikonra | Módosítatlan hivatalos többképes ikon, forrásverzió f057dd3649bc8692a83863b67770e22c9b9dd81a | Eredeti BSD-2-Clause megjegyzés és forrásmegjelölés |
| libwebp | WebPEncodeLosslessBGRA, WebPFree; 1.1.0; x86 | BSD-3-Clause; PATENTS |

Az egyező forráscélok beépítik azokat az upstream build konfigurációkba; nem bizonyítják, hogy minden függvény
túléli az optimalizálást a szállítói binárisban. Nincs pontos verziókövetelmény olyan függőségekre, amelyek
revíziója nincs rögzítve ezekben a binárisokban.

### Opcionális összetevők és rendszerkönyvtárak

- A Windows könyvtárprojektek lehetővé teszik a futásidejű libcurl-t a MediaInfo 26.10 és az 21.03 számára.
  MediaInfo 0.7.60 MEDIAINFO_LIBCURL_NO-val készült; binárisa a letiltott támogatás diagnosztikát is
  tartalmazza. A megjelenítő soha nem fedezi fel, nem bontja ki vagy tölti be a curl fájlt az adott csomagban
  található verzióhoz.
- A libmms mindhárom mellékelt Windows DLLs-ban le van tiltva, amint azt a beágyazott letiltott támogatási
  üzeneteik is megerősítik. Nincs újraosztva.
- A Qt és a wxWidgets opcionális GUI buildekhez tartoznak. Egyik sem szerepel ebben a megjelenítőben vagy
  ezekben a DLL függőségekben. Általános bejegyzéseiket eltávolították a megjelenített licencből.
- A Graphviz egy opcionális futásidejű hook a modern upstream kódban. Nincs Graphviz DLL újraterjesztve.
- Nincs FFmpeg bővítmény újraterjesztve.
- A MediaInfo DLLs csak közvetlenül importál KERNEL32.dll. Ez nem jelenti azt, hogy a statikusan összekapcsolt
  futási környezet és a segédkód hiányzik.
- Az aktuális curl közvetlenül importálja a következőt: WS2_32.dll, bcrypt.dll, ADVAPI32.dll, CRYPT32.dll és
  KERNEL32.dll. A XP curl közvetlenül importálja a WS2_32.dll, WLDAP32.dll, ADVAPI32.dll és KERNEL32.dll
  fájlokat. Ezek Windows komponensek. Elérhetőségüket a Windows betöltő ellenőrzi.
- Curl jelentések Windows Schannel/WinSSL, nem pedig OpenSSL build. A jelentett további tömörítési függősége
  statikusan szerepel zlib. A közvetlen importálási táblájában nem jelenik meg további külső nem Windows DLL.
- Magának a megjelenítőnek nincs C/C++ futásidejű függősége. A mellékelt, harmadik féltől származó DLLs saját
  lefordított futásidejű részeit tartalmazza. A Windows buildek Microsoft-eszközöket használnak; nincs
  bizonyíték az általános libstdc++ vagy libc++ leltárbejegyzésekre.
- A JPEG dinamikusan betöltött GDI+ rendszert használ. Az C# erőforráscsomagoló és az PowerShell összeállítási
  eszközök, és nem futásidejű függőségek.

A szokásos helyi fájlellenőrzés nem igényel MediaArea szervert vagy távolról letöltött formátumú adatbázist. A
libcurl a MediaInfo által használt URL bemenetekhez és potenciálisan távoli hivatkozásokhoz támogatott
médiaformátumokban. A csomagban nem ad hozzá külön URL-nyitó parancsot ehhez a megjelenítőhöz.

### Licenctárolás és korlátozások

Az egyetlen karbantartott terjesztési értesítés a [license.txt](../license.txt) , kódolva UTF-8 és CRLF. Az
ellenőrzött BSD, curl, zlib, MIT és Apache újraelosztási záradékok nem igényelnek külön értesítési fájlt
fizikailag mindegyik DLL mellett; az összevont közleményt a végrehajtható és terjesztési anyagokban kísérik.

Az archivált MediaInfo 0.7.60 csomag saját verzió-specifikus licencet használ, és tartalmazza a régi GNU
Library GPL szöveget. Feltételei kifejezetten megkülönböztetik a módosítatlan bináris újraelosztást a
módosított változatoktól; a megjelenítő általi dinamikus linkelés nem módosítja a mellékelt DLL-t. Az eredeti
feltételek és a hozzá tartozó licencszöveg megmarad. A néző továbbra is MIT-engedéllyel rendelkezik.

Egy upstream hozzárendelés minősítést igényel: a Markus Ewald Base64 fejlécnek nincs kifejezett engedélye vagy
licencnyilatkozata. A MediaArea a Bob Withers Base64 megvalósítását köztulajdonként írja le a kapcsolódó
MediaConch dokumentációjában, de ez nem határoz meg önállóan minden Ewald-módosításhoz licencet. Ehhez a
fejléchez nem találtak ki engedélyt. A származásról, a pontos ZenLib revíziókról és a curl commit
fejlesztésről szóló teljes gyártói visszaigazolás nem volt elérhető a mellékelt binárisokban. Ezek a pontok
megakadályozzák, hogy ezt a készletet teljes, független tanúsítvánnyal rendelkező SBOMként kezeljék.

### Elsődleges források

- [MediaInfo újraelosztási feltételek](https://mediaarea.net/en/MediaInfo/License)
- 
  [MediaInfo 26.10 könyvtár cél](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Project/MSVC2022/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 21.03 könyvtár cél](https://github.com/MediaArea/MediaInfoLib/blob/v21.03/Project/MSVC2015/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 0.7.60 könyvtár cél](https://github.com/MediaArea/MediaInfoLib/blob/v0.7.60/Project/MSVC2005/Library/MediaInfoLib.vcproj)
- 
  [Futásidejű curl betöltő](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Source/MediaInfo/Reader/Reader_libcurl.cpp)
- 
  [Csatolt segítő források és értesítéseik](https://github.com/MediaArea/MediaInfoLib/tree/v26.10/Source/ThirdParty)
- [ZenLib megjegyzés](https://github.com/MediaArea/ZenLib/blob/master/License.txt)
- [zlib forrás megjegyzései](https://github.com/madler/zlib/blob/v1.3.2/zlib.h)
- [curl 8.11.0 megjegyzés](https://github.com/curl/curl/blob/curl-8_11_0/COPYING)
- [curl 7.47.1 megjegyzés](https://github.com/curl/curl/blob/curl-7_47_1/COPYING)
- [Apache licenc 2.0](https://www.apache.org/licenses/LICENSE-2.0)
- [MediaArea Base64 leírás](https://github.com/MediaArea/MediaConch/blob/master/README.md)

A jelentéstáblázatok innen származnak:
<https://github.com/MediaArea/MediaInfo/tree/v26.10/Source/Resource/Plugin/Language> . A megfelelő LICENSE
projekt a <https://github.com/MediaArea/MediaInfo/blob/v26.10/LICENSE> .

- [libwebp 1.1.0 COPYING](https://github.com/webmproject/libwebp/blob/v1.1.0/COPYING)
- [libwebp 1.1.0 PATENTS](https://github.com/webmproject/libwebp/blob/v1.1.0/PATENTS)
