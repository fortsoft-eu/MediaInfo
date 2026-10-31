# MediaInfo Viewer

[Čeština](README.cs-CZ.md) | [English (US)](../README.md) | [English (UK)](README.en-GB.md) | [English (Australia)](README.en-AU.md) | [Deutsch](README.de-DE.md) | [Français](README.fr-FR.md) | [Español](README.es-ES.md) | [Italiano](README.it-IT.md) | [Português](README.pt-PT.md) | [Polski](README.pl-PL.md) | **Slovenčina** | [Dansk](README.da-DK.md) | [Suomi](README.fi-FI.md) | [Íslenska](README.is-IS.md) | [Norsk (bokmål)](README.nb-NO.md) | [Svenska](README.sv-SE.md) | [Türkçe](README.tr-TR.md) | [Eesti](README.et-EE.md) | [Gaeilge](README.ga-IE.md) | [Lietuvių](README.lt-LT.md) | [Latviešu](README.lv-LV.md) | [Magyar](README.hu-HU.md) | [Malti](README.mt-MT.md) | [Nederlands](README.nl-NL.md) | [Română](README.ro-RO.md) | [Ελληνικά](README.el-GR.md) | [Bosanski](README.bs-Latn-BA.md) | [Hrvatski](README.hr-HR.md) | [Slovenščina](README.sl-SI.md) | [Crnogorski](README.cnr-Latn-ME.md) | [Беларуская](README.be-BY.md) | [Български](README.bg-BG.md) | [Македонски](README.mk-MK.md) | [Српски](README.sr-Cyrl-RS.md) | [Українська](README.uk-UA.md) | [Русский](README.ru-RU.md)

Natívny prehliadač reportov MediaInfo.dll pre Windows x86. Každý súbor má vlastnú kartu iba na čítanie.

[Zostavenie a kompatibilita](#zostavenie) | [Preverenie závislostí](#závislosti) | [Licencia](../license.txt)

## Zostavenie

Otvorte MediaInfo.sln vo Visual Studio 2015 s nainštalovanou súpravou nástrojov Visual C++ v140. Vyberte Release | Win32 a zostavte riešenie. Jedinou platformou aplikácie je Win32 (x86).

Výstupy:

- Release\MediaInfo.exe
- Debug\MediaInfo.exe

Prehliadač sa nelinkuje s behovými knižnicami C ani C++ a nepotrebuje redistribuovateľný balík MSVC. Vybraná
knižnica MediaInfo.dll môže mať vlastné závislosti.

Budovanie vyžaduje Windows PowerShell a .NET Framework. Toto sú len požiadavky na zostavenie; natívny
spustiteľný súbor nevyžaduje ani PowerShell ani .NET.

### Distribučný balík

Po vytvorení Release spustite `powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\PackageRelease.ps1` .
Skript vytvorí `MediaInfo-<version>-win32.zip` v adresári riešenia pomocou štvordielnej verzie spustiteľného
súboru. Archív obsahuje `MediaInfo.exe` a kombinovaný `license.txt` priamo v koreňovom adresári.

## Kompatibilita

Prehliadač Win32 je navrhnutý pre API Windows NT 4.0.

Spustiteľný súbor obsahuje tri knižnice x86 MediaInfo: 26.10 pre aktuálny Windows, 21.03 z balíka Windows XP a
0.7.60 z balíka Windows 95–2000. Samotná architektúra knižnice neurčuje jej kompatibilitu s operačným
systémom. Prehliadač vyskúša pribalené knižnice od najnovších po najstaršie a zastaví sa po prvom úspešnom
načítaní a dotaze na verziu.

Windows 95 momentálne nie je podporované prostredie runtime.

## Použitie

- Súbor > Otvoriť (Ctrl+O) otvorí dialógové okno súboru Windows s viacnásobným výberom. Na Windows Vista a
  novších verziách Otvoriť a Uložiť používa moderné dialógové okno Common Item Dialog; staršie Windows
  používajú staré bežné dialógové okná.
- Presuňte jeden alebo viac súborov do okna, na ikonu EXE alebo jeho zástupcu, prípadne odovzdajte ich cesty v
  príkazovom riadku. Ak nie je povolených viac inštancií, súbory sa otvoria v už spustenom okne.
- Každá odlišná normalizovaná úplná cesta má jednu kartu. Opätovným otvorením už otvoreného súboru sa vyberie
  jeho existujúca karta bez opätovného načítania alebo zmeny jeho zostavy, výberu alebo pozície posúvania.
  Porovnania ignorujú veľkosť písmen cesty. Viacnásobné otvorenia súborov spracujú zoznam v poradí a ponechajú
  aktívny posledný úspešne spracovaný súbor, či už novootvorený alebo už otvorený. Umiestnením kurzora myši na
  hlavičku karty sa v natívnom popise zobrazí úplná cesta k súboru, a to aj vtedy, keď je zobrazený názov
  súboru skrátený.
- Ponuka Súbor uvádza osem naposledy načítaných súborov priamo nad Ukončením medzi oddeľovačmi. Záznamy
  zobrazujú iba číslo a názov súboru. Výberom položky sa otvorí jej uložená úplná cesta alebo sa vyberie
  existujúca karta; úspešné opätovné otvorenie ho posúva na vrchol bez duplikátov. Pri výbere nedostupného
  súboru sa zobrazí otázka, či chcete odstrániť jeho položku posledných súborov. Používa sa natívna ikona
  otázky a tlačidlá Yes/No. Áno je predvolená hodnota a odstráni položku z ponuky a registra; Nie si to
  zachováva. Výzva obsahuje úplnú cestu.
- Koliesko myši nad preplnenými hlavičkami kariet posúva pás hlavičky o jednu kartu na správu bez zmeny výberu
  alebo zamerania.
- Ctrl+Tab a Ctrl+Shift+Tab prepínacie karty; Ctrl+W zatvorí aktívnu kartu. Kliknutím stredným tlačidlom myši
  na hlavičku karty sa táto karta zatvorí, pričom sa zachová akákoľvek iná aktívna karta. Súbor > Zavrieť
  všetko zatvorí všetky karty vrátane prehľadov vo fronte. Súbor > Ukončiť (Alt+F4) zatvorí aplikáciu.
- Dvojklik vyberie slovo. Trojklik vyberie logický riadok. Ťahanie rozširuje výber po slovách alebo riadkoch.
- Ctrl+A vyberie zostavu; Ctrl+C ho skopíruje.
- Nastavenia > Predvoľby (Ctrl+G) otvorí jediný dialóg pre cesty MediaInfo a curl, písmo reportu,
  vyhladzovanie písma, jazyk rozhrania a jazyk reportu. Prázdna cesta DLL zapína automatické vyhľadávanie.
- Tlačidlo písma zobrazuje rodinu, veľkosť bodu a štýl a otvára štandardné dialógové okno písma Windows.
  Predvolene obnoví Consolas alebo Courier New, ak Consolas nie je k dispozícii; tlačidlo Predvolené je
  vypnuté, kým je vybraté predvolené. Používateľom zvolené písma sa zachovajú bez nahradenia kódom aplikácie.
- Možnosti vyhladzovania písma sú ClearType, ak je podporované, GDI a Žiadne. Počiatočná voľba je ClearType,
  ak je podporovaná, inak GDI. Nastavenia písma ovplyvňujú iba mediálne správy a ich exporty obrázkov.
- Súbor > Exportovať (Ctrl+E) otvorí dialógové okno Windows Uložiť ako a exportuje celý aktívny prehľad do
  TXT, BMP, GIF, JPEG, PNG, TIFF alebo WebP vrátane textu mimo viditeľnej oblasti.
- Pomocník otvorí samostatné nemodálne okno s vlastnou položkou na paneli úloh a možnosťou minimalizácie. O
  aplikácii je modálny dialóg; záhlavie produktu uvádza všetky tri vložené verzie DLL.

Tlačiť… (Ctrl+P) otvorí systémový dialóg výberu tlačiarne a vytlačí celý obsah aktívnej karty bez náhľadu.
Použije sa zvolené písmo reportu, dlhé riadky sa zalomia a text sa rozdelí na stránky. Tlač prebieha na
pozadí.

Otvoriť priečinok… otvorí súbory priamo vo vybranom priečinku, každý na vlastnej karte. Podpriečinky sa
neprechádzajú. Otvoriť a Otvoriť priečinok zdieľajú naposledy vybraný priečinok. Export si pamätá vlastný
priečinok, predvolené sú Dokumenty.

Pokročilý režim zobrazí ďalšie údaje v reporte.

Úplná analýza preskúma celý súbor a môže trvať dlhšie. Tieto voľby reportu a Úroveň trasovania patria
jednotlivým kartám; zmena obnoví iba aktívnu kartu. Posledná ručne zvolená kombinácia sa uloží pre nové karty
a ďalšie spustenie. Už získaný report pre rovnakú kombináciu sa použije znova, ak sa súbor nezmenil.

Známe formáty, Známe kodeky a Známe parametre sa otvárajú na vlastných kartách reportu.

Počiatočnú veľkosť a umiestnenie okna vyberá Windows. Predtým uložené umiestnenie okna prepíše tieto
predvolené hodnoty pri neskorších spustení.

Vľavo v stavovom riadku sa zobrazuje cesta k súboru a priebeh načítavania, vpravo verzia načítanej
MediaInfo.dll. Dlhé cesty sa podľa dostupného miesta skracujú výpustkou.

## Vytvoriť súbor hlavičky

Ponuka Nástroje je treťou hlavnou ponukou. Príkaz Vytvoriť súbor hlavičky… otvorí jeden vstupný súbor
nezávisle od kariet reportov a skopíruje jeho prvých 524288 bajtov (512 KiB). Kratší súbor sa skopíruje celý;
prázdny súbor vytvorí prázdny výstup. Ide o bežné binárne čítanie súboru bez analýzy MediaInfo; knižnica
MediaInfo.dll nie je potrebná. Karty reportov ani zoznam posledných súborov sa tým nemenia.

Po prečítaní sa otvorí dialógové okno Uložiť ako v priečinku vstupného súboru. Pre video.mp4 ponúkne názov
video.mp4.header: .header sa pripojí za celý pôvodný názov vrátane prípony. Názov aj cieľový priečinok môžete
zmeniť. Zrušenie ktoréhokoľvek dialógového okna nič neuloží. Prepísanie existujúceho cieľového súboru vyžaduje
potvrdenie. Vstupný súbor zostane nezmenený a chyba ukladania zachová pôvodný cieľový súbor. Na otváranie aj
ukladanie sa používajú najmodernejšie systémové dialógové okná dostupné v danej verzii Windows.

Pri spustení aplikácie prevezme nástroj rovnaký počiatočný priečinok ako príkaz Súbor > Otvoriť. Ak žiadny
priečinok nie je uložený, počiatočné umiestnenie určí Windows. Po výbere vstupného súboru si nástroj svoj
priečinok pamätá iba do ukončenia aplikácie, aj keď dialógové okno Uložiť ako zrušíte. Nemení priečinky
príkazov Otvoriť a Exportovať a aplikácia jeho vlastnú cestu neukladá do registra. Každé dialógové okno Uložiť
ako začne v priečinku práve vybraného vstupného súboru bez ohľadu na predchádzajúci cieľ ukladania.

## Vyhľadávanie knižníc

Najprv sa vyskúša uložená manuálna cesta. Ak sa nedá načítať, automatické zisťovanie sa pokúsi:

1. MediaInfo.dll vedľa spustiteľného súboru, potom v každom nadradenom adresári až po jednotku alebo UNC
   koreňový adresár.
2. ProgramFiles, ProgramFiles(x86) a ProgramW6432.
3. LOCALAPPDATA a APPDATA.

Pod týmito koreňovými adresármi inštalácie skontroluje vyhľadávanie MediaInfo, MediaArea\MediaInfo, MediaArea,
MediaArea.net\MediaInfo, Programs\MediaInfo, Programs\MediaArea\MediaInfo. Nečitateľné miesta a nekompatibilné
DLL sa preskočia. Nekontroluje rekurzívne disk.

Ak sa nenájde žiadny kompatibilný externý DLL, prehliadač vyskúša vložené verzie v tomto poradí: 26.10, 21.03,
0.7.60. Extrahuje a testuje jednu verziu naraz. Po úspešnom načítaní verzie nie sú staršie verzie extrahované
ani testované. Samostatná distribúcia MediaInfo.exe je postačujúca; kompatibilný externý DLL má vždy prednosť
a možno ho aktualizovať nezávisle.

Neúspešná ručná zmena ponechá už načítanú knižnicu.

## Export reportu

Formáty Uložiť ako sú zoradené TXT, BMP, GIF, JPEG, PNG, TIFF a WebP. Nepodporované kódovače sú vynechané z
moderných aj starších dialógových okien.

TXT ponúka ANSI, UTF-8, UTF-8 s BOM, UTF-16 BE s BOM a UTF-16 LE s BOM. Predvolená je druhá položka, UTF-8 bez
BOM. Zachováva sa celý text reportu aj jeho pôvodné konce riadkov.

BMP, PNG a TIFF zachovajú všetky vykreslené farby; GIF89a zachová presnú vykreslenú paletu, keď má obrázok
najviac 256 farieb. Export vždy zapíše zvolený formát alebo ohlási chybu; nikdy nenahrádza iný formát.

Obrázky obsahujú celú správu vo vybratom písme správy s čiernym textom na bielom pozadí. Neobsahujú menu
aplikácie, hlavičky kariet, stavový riadok, výber ani vsuvku. Vykresľovanie je nezávislé od polohy rolovania
textového poľa.

Aby sa predišlo tichému skracovaniu správ alebo vyčerpaniu priestoru adries na starších počítačoch, jeden
obrázok je obmedzený na 16 384 pixelov na šírku, 32 767 pixelov na výšku a 256 MiB nekomprimovanej bitmapovej
pamäte. Ak prehľad prekračuje tieto limity, vyberte menšie písmo.

`Google WebP (*.webp)` je posledný formát a ukladá report bezstratovo.

WebP: 16383 × 16383 px.

## Jazyky rozhrania a reportov

Predvoľby (Nastavenia > Predvoľby, Ctrl+G) obsahujú cesty ku knižniciam, písmo reportu, vyhladzovanie a
jazyky. Rozhranie má 36 variantov a spočiatku sa riadi Windows. Reporty sú vždy predvolene v pôvodnej
angličtine knižnice, nezávisle od Windows a rozhrania. Zmení to iba ručná voľba: angličtina, 37 prekladov
alebo vlastná tabuľka MediaInfo CSV.

OK alebo Použiť potvrdí zmeny; Zrušiť zahodí rozpracované úpravy. Predvoľby umožňujú zmeniť limit dĺžky názvu
karty (predvolene 80 znakov) a vymazať zoznam posledných súborov. Dlhé názvy zachovajú začiatok, koniec aj
príponu s výpustkou uprostred.

Predvolene je povolená iba jedna inštancia a ďalšie spustenie odovzdá súbory otvorenému oknu. V Predvoľbách
možno povoliť viac inštancií. Pri viacerých oknách sa uložená poloha obnoví len prvému oknu daného formulára;
ďalšie prevezmú iba uloženú veľkosť.

Ak zmeníte iba rozhranie, text otvorených správ zostane nezmenený. Manuálne aplikovaná zmena jazyka zostavy
znova načíta ich zostavy, pričom sa zachová poradie kariet a poradie MRU.

## libcurl

Automatické vyhľadávanie curl kontroluje najprv okolie vybranej MediaInfo DLL, potom spoločné umiestnenia pri
EXE a jeho nadradených adresároch, Program Files a používateľských inštaláciách. Ak nenájde kompatibilný
externý curl, rozbalí zodpovedajúcu vloženú súčasnú alebo XP verziu do overenej používateľskej vyrovnávacej
pamäte. Najstaršia MediaInfo 0.7.60 úplne vynecháva vyhľadávanie, rozbaľovanie aj načítanie curl. Výslovne
zvolená neplatná curl zabráni potvrdeniu predvolieb; chýbajúca voliteľná automaticky hľadaná curl nebráni
bežným reportom miestnych súborov.

## Názvy súborov a história posledných súborov

Názvy v MRU sa skracujú iba pri prekročení 80 kódových jednotiek UTF-16. Výpustka uprostred zachováva začiatok
názvu, koniec názvu pred príponou aj celú poslednú príponu; úplné cesty a reporty sa nemenia. Názvy kariet
používajú rovnaký algoritmus s nastaviteľným predvoleným limitom 80.

Nedávne súbory > Vymazať okamžite vymaže živú ponuku MRU aj jej uložené cesty, pričom všetky otvorené karty
zostanú nedotknuté. Neaplikuje ani neoveruje čakajúce preferencie a nepovoľuje Použiť. Zrušiť alebo Escape
zachová vymazanú históriu a zahodí čakajúce úpravy. Vymazať je zakázané vždy, keď je zoznam prázdny, a jeho
stav sa obnoví, keď zoznam zaplnia nové prehľady. Zlyhanie zápisu do registra je okamžite hlásené. Použitie
nového limitu názvov kariet aktualizuje každú otvorenú kartu bez opätovného načítania jej mediálnej správy.

## Licencia a ďalšie šírenie

Prehliadač je licencovaný na základe licencie MIT v license.txt.

MediaInfo je komponent tretej strany. Jediný udržiavaný distribučný licenčný súbor je koreňový license.txt v
UTF-8 s CRLF; zahŕňa prehliadač, knižnice, staticky začlenené komponenty, ikonu a oficiálne prekladové
tabuľky.

Tento produkt používa knižnicu MediaInfo, Copyright (c) 2002-2026 MediaArea.net SARL.

- MediaInfo: <https://mediaarea.net/MediaInfo>
- Licencia: <https://mediaarea.net/en/MediaInfo/License>
- Windows stiahnutí: <https://mediaarea.net/en/MediaInfo/Download/Windows>

## Závislosti

### Súbory

| Zdroj | Architektúra | Verzia nahlásená komponentom | SHA-256 |
| --- | --- | --- | --- |
| Resources/lib/26.10/MediaInfo.dll | x86 | 26.10 | E73027A1577084135425AA013D46C8B2985AD142CCF04F1ADB301B9A9CFB78F8 |
| Resources/lib/21.03/MediaInfo.dll | x86 | 21.03 | EBBF1C371702F3DC39CA23D619C47EDF97E66A95AEABE725284F1402D8F3E58A |
| Resources/lib/0.7.60/MediaInfo.dll | x86 | 0.7.60 | A26C07BCC25FA01A40E6888D02EABD59AA8DB2ABF6F5195481228D3A91D04441 |
| Resources/lib/26.10/libcurl.dll | x86 | 8.11.0-DEV, Schannel, zlib 1.3.1 | DCF136C84F3A4FBEAE2B317FE36D7F11225B56FBA3343AF4BBA8706B3F46F334 |
| Resources/lib/21.03/libcurl.dll | x86 | 7.47.1, WinSSL, zlib 1.2.8 | 21025CAC8089F1E570EE083D8CFD6311C2C51E97094A9FCD8C7A0B544C22CB48 |
| Resources/lib/libwebp.dll | x86 | 1.1.0 | 9986023BB6FF5510A157919F0CD958A94800EC6A1D981F3403A9648BEDFEE575 |

Cesty v tabuľke sú relatívne k adresáru projektu MediaInfo.

Súčasná knižnica hlási vývojovú verziu; z jej reťazca verzie nemožno zistiť presný commit zdrojového kódu.
Sprievodné oznámenie používa pôvodný text autorských práv a oprávnení z 8.11.0, ktorého licenčné podmienky
platia aj vo vývojovej vetve.

### Začlenené komponenty

| Komponent | Dôkazy a rozsah | Všimnite si |
| --- | --- | --- |
| MediaInfoLib | Aktuálne verzie a požadované exporty Unicode; nezmenené dodané binárne súbory | Pôvodné autorské práva špecifické pre danú verziu, podmienky redistribúcie a vylúčenie zodpovednosti |
| ZenLib | Statické projektové referencie a vložené ZenLib RTTI vo všetkých troch DLL; presné prepojené revízie nie sú dodané | Upozornenie v štýle zlib ZenLib |
| zlib | Vložené reťazce verzie inflate/deflate: 1.3.2 v MediaInfo 26.10, 1.2.11 v 21.03, 1.2.7 v 0.7.60; curl navyše uvádza 1.3.1 a 1.2.8 | Pôvodné upozornenia zlib pre všetkých päť verzií |
| TinyXML-2 | Zhoda moderných zdrojových cieľov a binárnych RTTI; zahrnuté v starom projekte, ale nie sú nezávisle identifikované v stiahnutom starom binárnom súbore | Pôvodné upozornenie v štýle Lee Thomason zlib bolo zachované |
| Brian Gladman AES | Zahrnuté v oboch moderných upstreamových knižničných cieľoch so zodpovedajúcimi tolerantnými zdrojmi | 1998–2013 oznámenie o redistribúcii a vylúčenie zodpovednosti |
| Brian Gladman SHA-1/SHA-2 | Oba moderné ciele; SHA-256 a SHA-512 konštantné tabuľky prítomné v oboch moderných binárnych súboroch | 1998–2010 oznámenie o redistribúcii a vylúčenie zodpovednosti |
| Brian Gladman HMAC | Moderné terče aj ich curl/S3 kód čítačky | Pôvodné oznámenie o troch podmienkach vrátane odseku s alternatívnou licenciou |
| MD5 | Moderné zdrojové ciele; Implementácia Colin Plumb výslovne uvádza verejnú doménu | Atribúcia bola zachovaná |
| Base64 | Markus Ewald hlavička vo všetkých troch zodpovedajúcich zdrojových stromoch s pripísaním Bob Withers | Pôvodné označenie autorstva sa zachová; kvalifikácia nižšie |
| fmt | 26.10 cieľ a fmt v11 format_error RTTI v binárnom | Pôvodné oznámenie MIT vrátane voliteľnej výnimky |
| tfsxml | 26.10 zdrojový cieľ | Pôvodné oznámenie MediaArea MIT |
| Rozhranie Android JNI | JNI_OnLoad v skutočnosti exportujú moderné DLL; zahrnutá hlavička JNI pochádza z AOSP | AOSP autorské práva a úplná licencia Apache 2.0 |
| libcurl | Dodávané x86 binárne súbory; exporty skutočnej verzie; dynamicky používané modernými MediaInfo | Pôvodné oznámenia curl pre 8.11.0 a 7.47.1 |
| Oficiálne preklady reportov | Všetkých 38 nezmenených zdrojových CSV z jazykového adresára MediaInfo v26.10; vkladá sa 37 neanglických tabuliek, angličtina používa predvolené nastavenie DLL | Rovnaké projektové oznámenie BSD-2-Clause zachované v súhrnnom licenčnom súbore |
| ikona MediaInfo | Neupravená oficiálna ikona viacerých obrázkov, zdrojová revízia f057dd3649bc8692a83863b67770e22c9b9dd81a | Pôvodné BSD-2-Clause oznámenie a uvedenie zdroja |
| libwebp | WebPEncodeLosslessBGRA, WebPFree; 1.1.0; x86 | BSD-3-Clause; PATENTS |

Zodpovedajúce zdrojové ciele vytvárajú zahrnutie do týchto upstream zostavovacích konfigurácií; nedokazujú, že
každá funkcia prežije optimalizáciu v binárnych súboroch dodávateľa. Pre závislosti, ktorých revízia nie je
zaznamenaná v týchto binárnych súboroch, sa neuplatňuje žiadny nárok na presnú verziu.

### Voliteľné komponenty a systémové knižnice

- Projekty knižníc Windows umožňujú runtime načítané libcurl pre MediaInfo 26.10 a 21.03. MediaInfo 0.7.60 bol
  vytvorený pomocou MEDIAINFO_LIBCURL_NO; jeho binárny súbor obsahuje aj diagnostiku zakázanej podpory. Divák
  nikdy neobjaví, nerozbalí ani nenačíta curl pre túto pribalenú verziu.
- libmms je zakázaná vo všetkých troch dodávaných Windows DLL, čo potvrdzujú aj ich vložené správy o zakázaní
  podpory. Neprerozdeľuje sa.
- Qt a wxWidgets patria k voliteľným zostavám GUI. Ani jedno nie je zahrnuté v tomto prehliadači ani v týchto
  DLL závislostiach. Ich všeobecné záznamy boli zo zobrazenej licencie odstránené.
- Graphviz je voliteľný runtime háčik v modernom upstream kóde. Nie je redistribuovaný žiadny Graphviz DLL.
- Nie je redistribuovaný žiadny doplnok FFmpeg.
- MediaInfo DLL priamo importuje iba KERNEL32.dll. To neznamená, že chýba ich staticky prepojený runtime a
  pomocný kód.
- Aktuálna curl priamo importuje WS2_32.dll, bcrypt.dll, ADVAPI32.dll, CRYPT32.dll a KERNEL32.dll. XP curl
  priamo importuje WS2_32.dll, WLDAP32.dll, ADVAPI32.dll a KERNEL32.dll. Toto sú komponenty Windows. Ich
  dostupnosť kontroluje zavádzač Windows.
- Curl hlási Windows Schannel/WinSSL, nie zostavu OpenSSL. Jeho hlásená ďalšia závislosť od kompresie je
  staticky zahrnutá zlib. V jeho tabuľke priameho importu sa nezobrazia žiadne ďalšie externé non-Windows DLL.
- Samotný prehliadač nemá žiadnu závislosť od C/C++ runtime. Dodané DLL tretej strany obsahujú ich vlastné
  kompilované časti runtime. Zostavy Windows používajú nástroje spoločnosti Microsoft; neexistuje žiadny dôkaz
  vyžadujúci generické libstdc++ alebo libc++ položky inventára.
- JPEG používa dynamicky načítané systémové GDI+. Kompresný nástroj prostriedkov v C# a PowerShell slúžia
  zostaveniu a nie sú závislosťami pri spustení.

Bežná kontrola lokálnych súborov nevyžaduje server MediaArea ani vzdialene stiahnutú databázu formátu. libcurl
používa MediaInfo pre vstupy URL a potenciálne vzdialené odkazy v podporovaných formátoch médií. Zbalenie
nepridá do tohto prehliadača samostatný príkaz URL-opening.

### Uloženie licencií a obmedzenia

Jediné udržiavané oznámenie o distribúcii je [license.txt](../license.txt) , zakódované ako UTF-8 s CRLF.
Kontrolované BSD, curl, zlib, MIT a doložky o redistribúcii Apache nevyžadujú samostatný súbor s upozornením
fyzicky vedľa každého DLL; kombinované oznámenie ich sprevádza v spustiteľných a distribučných materiáloch.

Archivovaný balík MediaInfo 0.7.60 používa vlastnú licenciu špecifickú pre verziu a obsahuje starý text GNU
Library GPL. Jeho podmienky výslovne odlišujú nemodifikovanú binárnu redistribúciu od modifikovaných verzií;
dynamické prepojenie týmto prehliadačom nemení dodaný DLL. Jeho pôvodné podmienky a sprievodný text licencie
sa zachovávajú. Prehliadač zostáva licencovaný MIT.

Jedno pôvodné uvedenie autorstva si vyžaduje spresnenie: hlavička Base64 od Markus Ewald neobsahuje výslovné
oprávnenie ani licenčné vyhlásenie. MediaArea v súvisiacej dokumentácii MediaConch označuje implementáciu
Base64 od Bob Withers za public domain, čo však samo nedokladá udelenie licencie pre každú Ewaldovu zmenu.
Žiadne licenčné oprávnenie pre túto hlavičku nebolo domyslené. Úplné potvrdenie dodávateľa o jej pôvode,
presné revízie ZenLib a vývojový commit curl neboli z dodaných binárnych súborov dostupné. Preto nemožno tento
prehľad považovať za úplný, nezávisle certifikovaný SBOM.

### Primárne zdroje

- [MediaInfo podmienky redistribúcie](https://mediaarea.net/en/MediaInfo/License)
- 
  [Cieľ knižnice MediaInfo 26.10](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Project/MSVC2022/Library/MediaInfoLib.vcxproj)
- 
  [Cieľ knižnice MediaInfo 21.03](https://github.com/MediaArea/MediaInfoLib/blob/v21.03/Project/MSVC2015/Library/MediaInfoLib.vcxproj)
- 
  [Cieľ knižnice MediaInfo 0.7.60](https://github.com/MediaArea/MediaInfoLib/blob/v0.7.60/Project/MSVC2005/Library/MediaInfoLib.vcproj)
- 
  [Runtime curl zavádzač](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Source/MediaInfo/Reader/Reader_libcurl.cpp)
- 
  [Pribalené pomocné zdroje a ich upozornenia](https://github.com/MediaArea/MediaInfoLib/tree/v26.10/Source/ThirdParty)
- [ZenLib upozornenie](https://github.com/MediaArea/ZenLib/blob/master/License.txt)
- [zlib zdrojové upozornenia](https://github.com/madler/zlib/blob/v1.3.2/zlib.h)
- [curl 8.11.0 upozornenie](https://github.com/curl/curl/blob/curl-8_11_0/COPYING)
- [curl 7.47.1 upozornenie](https://github.com/curl/curl/blob/curl-7_47_1/COPYING)
- [Licencia Apache 2.0](https://www.apache.org/licenses/LICENSE-2.0)
- [MediaArea Base64 popis](https://github.com/MediaArea/MediaConch/blob/master/README.md)

Tabuľky prehľadov pochádzajú z
<https://github.com/MediaArea/MediaInfo/tree/v26.10/Source/Resource/Plugin/Language> . Zodpovedajúci projekt
LICENSE je <https://github.com/MediaArea/MediaInfo/blob/v26.10/LICENSE> .

- [libwebp 1.1.0 COPYING](https://github.com/webmproject/libwebp/blob/v1.1.0/COPYING)
- [libwebp 1.1.0 PATENTS](https://github.com/webmproject/libwebp/blob/v1.1.0/PATENTS)
