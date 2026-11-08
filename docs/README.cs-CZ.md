# MediaInfo Viewer

**Čeština** | [English (US)](../README.md) | [English (UK)](README.en-GB.md) | [English (Australia)](README.en-AU.md) | [Deutsch](README.de-DE.md) | [Français](README.fr-FR.md) | [Español](README.es-ES.md) | [Italiano](README.it-IT.md) | [Português](README.pt-PT.md) | [Polski](README.pl-PL.md) | [Slovenčina](README.sk-SK.md) | [Dansk](README.da-DK.md) | [Suomi](README.fi-FI.md) | [Íslenska](README.is-IS.md) | [Norsk (bokmål)](README.nb-NO.md) | [Svenska](README.sv-SE.md) | [Türkçe](README.tr-TR.md) | [Eesti](README.et-EE.md) | [Gaeilge](README.ga-IE.md) | [Lietuvių](README.lt-LT.md) | [Latviešu](README.lv-LV.md) | [Magyar](README.hu-HU.md) | [Malti](README.mt-MT.md) | [Nederlands](README.nl-NL.md) | [Română](README.ro-RO.md) | [Ελληνικά](README.el-GR.md) | [Bosanski](README.bs-Latn-BA.md) | [Hrvatski](README.hr-HR.md) | [Slovenščina](README.sl-SI.md) | [Crnogorski](README.cnr-Latn-ME.md) | [Беларуская](README.be-BY.md) | [Български](README.bg-BG.md) | [Македонски](README.mk-MK.md) | [Српски](README.sr-Cyrl-RS.md) | [Українська](README.uk-UA.md) | [Русский](README.ru-RU.md)

Nativní prohlížeč reportů MediaInfo.dll pro Windows x86. Každý soubor má vlastní kartu pouze pro čtení.

[Podrobnosti sestavení a kompatibility](#sestavení) | [Prověření závislostí](#závislosti) | [Licence](../license.txt)

## Sestavení

Otevřete MediaInfo.sln ve Visual Studio 2015 s nainstalovanou sadou nástrojů Visual C++ v140. Vyberte Release | Win32 a sestavte řešení. Jedinou platformou aplikace je Win32 (x86).

[PCRE2 10.49](https://github.com/PCRE2Project/pcre2/tree/pcre2-10.49) — UTF-16, staticky připojeno,
BSD-3-Clause. [Zdrojové kódy](../MediaInfo/PCRE2/).
[license.txt](../license.txt).
PCRE2 je vestavěna do EXE a nevyžaduje samostatnou DLL ani instalaci.

Výstupní soubory:

- Release\MediaInfo.exe
- Debug\MediaInfo.exe

Prohlížeč se nelinkuje s běhovými knihovnami C ani C++ a nepotřebuje redistribuovatelný balíček MSVC. Vybraná
knihovna MediaInfo.dll může mít vlastní závislosti.

Sestavení vyžaduje Windows PowerShell a .NET Framework. Jde pouze o požadavky na sestavení; nativní
spustitelný soubor nevyžaduje PowerShell ani .NET.

### Distribuční balíček

Po sestavení Release spusťte `powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\PackageRelease.ps1` .
Skript vytvoří v adresáři řešení `MediaInfo-<version>-win32.zip` podle čtyřdílného čísla verze spustitelného
souboru. Archiv obsahuje `MediaInfo.exe` a souhrnný `license.txt` přímo v kořeni.

## Kompatibilita

Prohlížeč Win32 je navržen pro API Windows NT 4.0.

Spustitelný soubor obsahuje tři knihovny MediaInfo pro x86: 26.10 pro současná Windows, 21.03 z balíčku pro
Windows XP a 0.7.60 z balíčku pro Windows 95–2000. Samotná architektura knihovny neurčuje její kompatibilitu s
operačním systémem. Prohlížeč zkouší přibalené knihovny od nejnovější po nejstarší a skončí po prvním úspěšném
načtení a zjištění verze.

Windows 95 v současnosti nejsou podporovaným prostředím pro spuštění.

## Použití

- Soubor > Otevřít (Ctrl+O) otevře dialog Windows pro výběr více souborů. Ve Windows Vista a novějších
  používají Otevřít a Uložit moderní Common Item Dialog; starší Windows používají klasické systémové dialogy.
- Přetáhněte jeden nebo více souborů do okna, na ikonu EXE nebo jeho zástupce, případně předejte jejich cesty
  na příkazovém řádku. Pokud nejsou povolené další instance, soubory se otevřou v již běžícím okně.
- Každá odlišná normalizovaná úplná cesta má jednu kartu. Opětovné otevření již otevřeného souboru vybere
  existující kartu bez nového načítání či změny reportu, výběru nebo pozice posunutí. Při porovnávání cest se
  nerozlišuje velikost písmen. Otevírání více souborů zpracuje seznam postupně a ponechá aktivní poslední
  úspěšně zpracovaný soubor, ať byl nově otevřen, nebo již otevřený. Po najetí nad záhlaví karty se v nativní
  bublinové nápovědě zobrazí úplná cesta, i když je název na kartě zkrácen.
- Nabídka Soubor uvádí osm naposledy načtených souborů v oddělené oblasti přímo nad Konec. Položky obsahují
  jen číslo a název souboru. Výběr položky otevře uloženou úplnou cestu nebo přepne na existující kartu;
  úspěšné opětovné otevření přesune položku na začátek bez duplicit. Při výběru nedostupného souboru se
  zobrazí dotaz na odebrání položky ze seznamu posledních souborů. Používá nativní ikonu otázky a tlačítka
  Ano/Ne. Výchozí Ano odebere položku z nabídky i registru; Ne ji ponechá. Dotaz obsahuje úplnou cestu.
- Kolečko myši nad záhlavími karet, která se nevejdou do šířky, posune pás o jednu kartu na zprávu bez změny
  výběru či fokusu.
- Ctrl+Tab a Ctrl+Shift+Tab přepínají karty; Ctrl+W zavře aktivní kartu. Prostřední tlačítko myši nad záhlavím
  zavře danou kartu a ponechá jinou aktivní kartu vybranou. Soubor > Zavřít vše zavře všechny karty včetně
  reportů ve frontě. Soubor > Konec (Alt+F4) ukončí aplikaci.
- Kontextová nabídka záhlaví karty obsahuje příkaz Zavřít kartu. Volba Zavírat karty dvojklikem v
  Předvolbách umožní zavírání dvojklikem na záhlaví. Ve výchozím stavu je vypnutá a její nastavení se
  ukládá.
- Dvojklik v textu reportu vybere slovo. Trojklik vybere logický řádek. Tažení rozšiřuje výběr po
  slovech nebo řádcích.
- Ctrl+A vybere report; Ctrl+C jej zkopíruje.
- Úpravy > Najít (Ctrl+F) hledá podle fokusu okna v aktivní kartě hlavního okna, v textové oblasti
  Nápovědy nebo v textové oblasti O programu. Okno hledání si po dobu vlastního fokusu ponechá naposledy
  zvolený zdroj. F3 hledání opakuje, Shift+F3 obrátí jeho směr. Po dosažení okraje textu pokračuje
  hledání na opačném konci. Možnosti > Zalamování řádků ovlivňuje jen aktivní kartu; zatržení se mění
  podle vybrané karty. Formulář hledání lze minimalizovat a měnit jeho šířku; pamatuje si polohu a volbu
  Vždy navrchu. Historie uchovává až 30 hledaných textů s jejich volbami pouze do ukončení aplikace.
  Začíná na a Končí na hledají na okrajích logických řádků. Regulární výrazy používají syntaxi PCRE2.
  Ostatní příkazy nabídky Úpravy pracují s aktivní kartou reportu. Enter spustí hledání, Shift+Enter
  obrátí zvolený směr. Volba „Rozlišovat velikost písmen“ rozlišuje velká a malá písmena; „Hledat
  pozpátku“ hledá směrem k začátku textu. Výběr z historie obnoví všech pět voleb hledání, včetně
  uloženého stavu regulárního výrazu; „Vždy navrchu“ je nezávislá volba. „Regulární výraz“ vypne volby
  „Začíná na“ a „Končí na“. Jsou-li obě volby okrajů zapnuté, stačí shoda na jednom z nich. „Zalamování
  řádků“ mění pouze zobrazení.
- Možnosti > Předvolby (Ctrl+G) otevře jediný dialog pro cesty MediaInfo a curl, písmo reportu, vyhlazování
  písma, jazyk rozhraní a jazyk reportu. Prázdná cesta DLL zapíná automatické vyhledávání.
- Tlačítko písma ukazuje rodinu, bodovou velikost a řez a otevírá standardní dialog písma Windows. Výchozí
  obnoví Consolas, případně Courier New, pokud Consolas není dostupné; při výchozím nastavení je tlačítko
  Výchozí zakázáno. Uživatelem zvolené písmo se zachovává bez nahrazování kódem aplikace.
- Vyhlazování písma nabízí ClearType, je-li podporováno, GDI a Žádné. Výchozí je podporované ClearType,
  jinak GDI. Nastavení písma ovlivňuje karty reportů, jejich obrazové exporty i tisk reportů. Nápověda a
  O programu si ponechávají vlastní písma textu.
- Nápověda otevírá samostatné nemodální okno s vlastní položkou na hlavním panelu a možností minimalizace. O
  programu je modální dialog; v záhlaví produktu uvádí všechny tři vložené verze DLL.

Soubor > Vzhled stránky… otevře nastavení papíru, orientace a okrajů pro aktuální spuštění aplikace.
Tisk… (Ctrl+P) otevře systémový tiskový dialog; Windows 11 poskytují náhled, Windows 10 a starší
zachovávají klasický dialog. Ctrl+P vytiskne aktivní kartu hlavního okna, nebo textovou oblast Nápovědy
či O programu podle toho, které okno má fokus. Reporty používají zvolené písmo reportu, Nápověda
systémové dialogové písmo a O programu písmo svého textu. Pokud nejsou otevřené žádné karty a Nápověda
je otevřená, zůstávají Vzhled stránky… i Tisk… dostupné a tiskne se Nápověda. Tisk z Nápovědy používá
dialog hlavního okna; další Ctrl+P v Nápovědě jej přenese do popředí. Dlouhé řádky se zalomí a text se
rozdělí na stránky. Tisk probíhá na pozadí.

Otevřít složku… otevře soubory přímo ve vybrané složce, každý ve vlastní kartě. Podsložky se neprocházejí.
Otevřít a Otevřít složku sdílejí naposledy zvolenou složku. Export si pamatuje vlastní složku, výchozí jsou
Dokumenty.

Pokročilý režim zobrazí další údaje v reportu.

Úplná analýza prozkoumá celý soubor a může trvat déle. Tyto volby reportu a Úroveň trasování patří jednotlivým
kartám; změna obnoví pouze aktivní kartu. Poslední ručně zvolená kombinace se uloží pro nové karty a další
spuštění. Již získaný report pro stejnou kombinaci se použije znovu, pokud se soubor nezměnil.

Známé formáty, Známé kodeky a Známé parametry se otevírají ve vlastních kartách reportu.

Výchozí velikost a umístění okna určuje Windows. Při dalších spuštěních má přednost uložené umístění.

Vlevo ve stavovém řádku se zobrazuje cesta k souboru a průběh načítání, vpravo verze načtené MediaInfo.dll.
Dlouhé cesty se podle dostupného místa zkracují výpustkou.

## Vytvořit hlavičkový soubor

Nabídka Nástroje je čtvrtou hlavní nabídkou. Příkaz Vytvořit hlavičkový soubor… otevře jeden vstupní soubor
nezávisle na kartách reportů a zkopíruje jeho prvních 524288 bajtů (512 KiB). Kratší soubor se zkopíruje celý;
prázdný soubor vytvoří prázdný výstup. Jde o běžné binární čtení souboru bez analýzy MediaInfo; knihovna
MediaInfo.dll není potřeba. Karty reportů ani seznam posledních souborů se tím nemění.

Po přečtení se otevře dialog Uložit jako ve složce vstupního souboru. Pro video.mp4 nabídne název
video.mp4.header: .header se připojí za celý původní název včetně přípony. Název i cílovou složku můžete
změnit. Zrušení kteréhokoli dialogu nic neuloží. Přepsání existujícího cílového souboru vyžaduje potvrzení.
Vstupní soubor zůstane nezměněný a chyba ukládání zachová původní cílový soubor. Pro otevírání i ukládání se
používají nejmodernější systémové dialogy dostupné v dané verzi Windows.

Při spuštění aplikace převezme nástroj stejnou počáteční složku jako příkaz Soubor > Otevřít. Pokud žádná
složka není uložená, počáteční umístění určí Windows. Po výběru vstupního souboru si nástroj svou složku
pamatuje pouze do ukončení aplikace, i když dialog Uložit jako zrušíte. Nemění složky příkazů Otevřít a
Exportovat a aplikace jeho vlastní cestu neukládá do registru. Každý dialog Uložit jako začne ve složce právě
vybraného vstupního souboru bez ohledu na předchozí cíl ukládání.

## Vyhledávání knihoven

Nejprve se zkouší uložená ruční cesta. Pokud se knihovnu nepodaří načíst, automatické vyhledávání zkouší
následující umístění:

1. MediaInfo.dll vedle spustitelného souboru, potom v každém nadřazeném adresáři až po kořen jednotky nebo
   sdíleného prostředku UNC.
2. ProgramFiles, ProgramFiles(x86) a ProgramW6432.
3. LOCALAPPDATA a APPDATA.

V těchto instalačních umístěních se kontrolují MediaInfo, MediaArea\MediaInfo, MediaArea,
MediaArea.net\MediaInfo, Programs\MediaInfo a Programs\MediaArea\MediaInfo. Nečitelná umístění a
nekompatibilní DLL se přeskakují. Disk se neprohledává rekurzivně.

Pokud se nenajde kompatibilní externí DLL, prohlížeč zkusí vložené verze v pořadí 26.10, 21.03, 0.7.60.
Rozbaluje a zkouší vždy jednu verzi. Po úspěšném načtení se starší verze již nerozbalují ani netestují. Stačí
distribuovat samotné MediaInfo.exe; kompatibilní externí DLL má vždy přednost a může být aktualizována
nezávisle.

Neúspěšná ruční změna ponechá dosud načtenou knihovnu.

## Export reportu

Formáty dialogu Uložit jako mají pořadí TXT, BMP, GIF, JPEG, PNG, TIFF a WebP. Nedostupné kodéry se
nezobrazují v moderních ani klasických dialozích.

TXT nabízí ANSI, UTF-8, UTF-8 s BOM, UTF-16 BE s BOM a UTF-16 LE s BOM. Výchozí je druhá položka, UTF-8 bez
BOM. Zachovává se celý text reportu i jeho původní konce řádků.

BMP, PNG a TIFF zachovávají všechny vykreslené barvy; GIF89a zachovává vykreslenou paletu přesně, má-li
obrázek nejvýše 256 barev. Export vždy zapíše vybraný formát, nebo ohlásí chybu; nikdy jej nenahradí jiným.

## Jazyky rozhraní a reportů

Předvolby (Možnosti > Předvolby, Ctrl+G) obsahují cesty ke knihovnám, písmo reportu, vyhlazování a jazyky.
Rozhraní má 36 variant a zpočátku se řídí Windows. Výchozí report je vždy v původní angličtině knihovny,
nezávisle na Windows i rozhraní. Změní jej pouze ruční volba jazyka reportu: angličtina, 37 překladů nebo
vlastní tabulka MediaInfo CSV.

OK nebo Použít potvrdí změny; Zrušit zahodí rozpracované úpravy. V předvolbách lze změnit limit délky názvu
karty (výchozí 80 znaků) a vymazat seznam posledních souborů. Dlouhé názvy zachovají začátek, konec i příponu
s výpustkou uprostřed.

Ve výchozím stavu je povolena pouze jedna instance a další spuštění předá soubory otevřenému oknu. V
předvolbách lze povolit více instancí. Při více oknech se uložená pozice obnoví jen prvnímu oknu daného
formuláře; další převezmou pouze uloženou velikost.

Změna samotného rozhraní ponechává text otevřených reportů beze změny. Ručně potvrzená změna jazyka reportů je
načte znovu se zachováním pořadí karet a MRU.

## libcurl

Automatické vyhledávání curl kontroluje nejprve okolí vybrané MediaInfo DLL, potom společná umístění u EXE a
jeho nadřazených adresářů, Program Files a uživatelských instalací. Pokud nenajde kompatibilní externí curl,
rozbalí odpovídající vloženou současnou nebo XP verzi do ověřené uživatelské mezipaměti. Nejstarší MediaInfo
0.7.60 zcela vynechává vyhledávání, rozbalování i načítání curl. Výslovně zvolená neplatná knihovna curl
zabrání potvrzení předvoleb; chybějící volitelná automaticky hledaná curl nebrání běžným reportům místních
souborů.

## Názvy souborů a historie posledních souborů

Názvy v MRU se zkracují pouze při překročení 80 kódových jednotek UTF-16. Výpustka uprostřed zachovává začátek
názvu, konec názvu před příponou i celou poslední příponu; úplné cesty a reporty se nemění. Názvy karet
používají stejný algoritmus s nastavitelným výchozím limitem 80.

Poslední soubory > Vymazat okamžitě vyprázdní nabídku MRU i uložené cesty; otevřené karty ponechá beze změny.
Nepotvrzuje ani neověřuje rozpracované předvolby a neaktivuje Použít. Zrušit nebo Escape ponechává historii
vymazanou a zahodí nepotvrzené změny. Vymazat je při prázdném seznamu zakázáno a jeho stav se obnoví, když
seznam doplní nové reporty. Selhání zápisu do registru se oznámí okamžitě. Potvrzení nového limitu názvů
upraví všechny otevřené karty bez nového načítání reportů.

## Licence a další šíření

Prohlížeč používá licenci MIT uvedenou v license.txt.

MediaInfo je komponenta třetí strany. Jediný udržovaný distribuční licenční soubor je kořenový license.txt v
UTF-8 s CRLF; zahrnuje prohlížeč, knihovny, staticky začleněné komponenty, ikonu a oficiální překladové
tabulky.

Tento produkt používá knihovnu MediaInfo, Copyright (c) 2002-2026 MediaArea.net SARL.

- MediaInfo: <https://mediaarea.net/MediaInfo>
- Licence: <https://mediaarea.net/en/MediaInfo/License>
- Stažení pro Windows: <https://mediaarea.net/en/MediaInfo/Download/Windows>

## Závislosti

### Soubory

| Zdroj | Architektura | Verze nahlášená komponentou | SHA-256 |
| --- | --- | --- | --- |
| Resources/lib/26.10/MediaInfo.dll | x86 | 26.10 | E73027A1577084135425AA013D46C8B2985AD142CCF04F1ADB301B9A9CFB78F8 |
| Resources/lib/21.03/MediaInfo.dll | x86 | 21.03 | EBBF1C371702F3DC39CA23D619C47EDF97E66A95AEABE725284F1402D8F3E58A |
| Resources/lib/0.7.60/MediaInfo.dll | x86 | 0.7.60 | A26C07BCC25FA01A40E6888D02EABD59AA8DB2ABF6F5195481228D3A91D04441 |
| Resources/lib/26.10/libcurl.dll | x86 | 8.11.0-DEV, Schannel, zlib 1.3.1 | DCF136C84F3A4FBEAE2B317FE36D7F11225B56FBA3343AF4BBA8706B3F46F334 |
| Resources/lib/21.03/libcurl.dll | x86 | 7.47.1, WinSSL, zlib 1.2.8 | 21025CAC8089F1E570EE083D8CFD6311C2C51E97094A9FCD8C7A0B544C22CB48 |
| Resources/lib/libwebp.dll | x86 | 1.1.0 | 9986023BB6FF5510A157919F0CD958A94800EC6A1D981F3403A9648BEDFEE575 |

Cesty v tabulce jsou relativní k adresáři projektu MediaInfo.

Současná knihovna hlásí vývojovou verzi; z jejího řetězce verze nelze zjistit přesný commit zdrojového kódu.
Doprovodné oznámení používá původní text autorských práv a oprávnění z 8.11.0, jehož licenční podmínky platí
také ve vývojové řadě.

### Začleněné komponenty

| Komponenta | Doklady a rozsah | Licenční oznámení |
| --- | --- | --- |
| MediaInfoLib | Skutečné verze a požadované exporty Unicode; nezměněné dodané binární soubory | Původní autorská práva, podmínky dalšího šíření a vyloučení odpovědnosti pro danou verzi |
| ZenLib | Statické projektové odkazy a vložené RTTI ZenLib ve všech třech DLL; přesné přilinkované revize nebyly dodány | Oznámení ZenLib ve stylu zlib |
| zlib | Vložené řetězce verzí inflate/deflate: 1.3.2 v MediaInfo 26.10, 1.2.11 v 21.03, 1.2.7 v 0.7.60; curl navíc hlásí 1.3.1 a 1.2.8 | Původní oznámení zlib pro všech pět verzí |
| TinyXML-2 | Odpovídající cíle sestavení novějších verzí a binární RTTI; součást starého projektu, ale samostatně neidentifikováno ve staré binárce zbavené symbolů | Zachováno původní oznámení Lee Thomason ve stylu zlib |
| Brian Gladman AES | Součást obou novějších původních cílů knihovny, s odpovídajícími permisivními oznámeními ve zdrojích | Oznámení o dalším šíření z 1998–2013 a vyloučení odpovědnosti |
| Brian Gladman SHA-1/SHA-2 | Oba novější cíle; tabulky konstant SHA-256 a SHA-512 přítomné v obou novějších binárních souborech | Oznámení o dalším šíření z 1998–2010 a vyloučení odpovědnosti |
| Brian Gladman HMAC | Oba novější cíle a jejich kód čtečky curl/S3 | Původní oznámení se třemi podmínkami včetně odstavce o alternativní licenci |
| MD5 | Novější cíle sestavení; implementace Colin Plumb výslovně uvádí public domain | Uvedení autora zachováno |
| Base64 | Hlavička Markus Ewald ve všech třech odpovídajících zdrojových stromech, s uvedením Bob Withers | Původní autorství zachováno; upřesnění níže |
| fmt | Cíl 26.10 a RTTI fmt v11 format_error v binárním souboru | Původní oznámení MIT včetně volitelné výjimky |
| tfsxml | Cíl sestavení 26.10 | Původní oznámení MIT společnosti MediaArea |
| Rozhraní Android JNI | JNI_OnLoad skutečně exportují obě novější DLL; vložená hlavička JNI pochází z AOSP | Autorská práva AOSP a úplná licence Apache 2.0 |
| libcurl | Dodané binární soubory x86; skutečné exporty verzí; dynamicky používáno novějšími MediaInfo | Původní oznámení curl pro 8.11.0 a 7.47.1 |
| Oficiální překlady reportů | Všech 38 nezměněných zdrojových CSV z jazykového adresáře MediaInfo v26.10; vkládá se 37 neanglických tabulek, angličtina používá výchozí nastavení DLL | Stejné projektové oznámení BSD-2-Clause zachováno v souhrnném licenčním souboru |
| Ikona MediaInfo | Nezměněná oficiální vícesnímková ikona, zdrojová revize f057dd3649bc8692a83863b67770e22c9b9dd81a | Původní oznámení BSD-2-Clause a uvedení zdroje |
| libwebp | WebPEncodeLosslessBGRA, WebPFree; 1.1.0; x86 | BSD-3-Clause; PATENTS |

Odpovídající cíle sestavení dokládají zahrnutí do těchto původních konfigurací; nedokazují, že každá funkce
přežila optimalizaci v binárních souborech dodavatele. U závislostí, jejichž revize není v binárkách
zaznamenána, se přesná verze netvrdí.

### Volitelné komponenty a systémové knihovny

- Projekty knihoven Windows zapínají načítání libcurl za běhu pro MediaInfo 26.10 a 21.03. MediaInfo 0.7.60
  bylo sestaveno s MEDIAINFO_LIBCURL_NO; jeho binárka obsahuje také hlášku o vypnuté podpoře. Pro tuto
  přibalenou verzi prohlížeč curl nikdy nehledá, nerozbaluje ani nenačítá.
- libmms je ve všech třech dodaných DLL pro Windows vypnuto, což potvrzují vložené hlášky o vypnuté podpoře.
  Není distribuováno.
- Qt a wxWidgets patří k volitelným sestavením GUI. Ani jedna knihovna není součástí prohlížeče ani těchto
  závislostí DLL. Jejich obecné položky byly ze zobrazené licence odstraněny.
- Novější původní kód nabízí volitelné napojení Graphviz za běhu. Žádná Graphviz DLL se nedistribuuje.
- Žádný plugin FFmpeg se nedistribuuje.
- MediaInfo DLL přímo importují pouze KERNEL32.dll. To neznamená, že neobsahují staticky přilinkované běhové
  knihovny a pomocný kód.
- Aktuální curl přímo importuje WS2_32.dll, bcrypt.dll, ADVAPI32.dll, CRYPT32.dll a KERNEL32.dll. XP curl
  přímo importuje WS2_32.dll, WLDAP32.dll, ADVAPI32.dll a KERNEL32.dll. Toto jsou komponenty Windows. Jejich
  dostupnost je kontrolována zavaděčem Windows.
- Curl hlásí Windows Schannel/WinSSL, nikoli sestavení s OpenSSL. Další hlášená kompresní závislost je
  staticky začleněná zlib. V tabulce přímých importů není další externí DLL mimo součásti Windows.
- Prohlížeč sám nemá závislost na běhových knihovnách C/C++. Dodané DLL třetích stran obsahují vlastní
  zkompilované části běhových knihoven. Sestavení pro Windows používají nástroje Microsoftu; nic nedokládá
  potřebu obecných položek libstdc++ nebo libc++ v přehledu.
- JPEG používá dynamicky načítané systémové GDI+. Kompresní nástroj prostředků v C# a PowerShell slouží
  sestavení a nejsou závislostmi pro spuštění.

Běžné zkoumání místních souborů nevyžaduje server MediaArea ani vzdálené stahování databáze formátů. MediaInfo
používá libcurl pro vstupní URL a případné vzdálené odkazy v podporovaných formátech médií. Jeho přibalení
nepřidává do prohlížeče samostatný příkaz k otevírání URL.

### Uložení licencí a omezení

Jediným udržovaným distribučním licenčním souborem je [license.txt](../license.txt) v UTF-8 s CRLF. Prověřené
podmínky dalšího šíření BSD, curl, zlib, MIT a Apache nevyžadují samostatný licenční soubor fyzicky vedle
každé DLL; souhrnný soubor je doprovází v EXE a distribučních materiálech.

Archivovaný balíček MediaInfo 0.7.60 používá vlastní licenci pro danou verzi a obsahuje starý text GNU Library
GPL. Jeho podmínky výslovně rozlišují šíření nezměněných binárních souborů od upravených verzí; dynamické
linkování prohlížeče dodanou DLL nemění. Původní podmínky a doprovodný licenční text zůstávají zachovány.
Prohlížeč nadále používá licenci MIT.

Jedno původní uvedení autorství vyžaduje upřesnění: hlavička Base64 od Markus Ewald neobsahuje výslovné
oprávnění ani licenční prohlášení. MediaArea v související dokumentaci MediaConch označuje implementaci Base64
od Bob Withers za public domain, což však samo nedokládá udělení licence pro každou Ewaldovu změnu. Žádné
licenční oprávnění pro tuto hlavičku nebylo domyšleno. Úplné potvrzení dodavatele o jejím původu, přesné
revize ZenLib a vývojový commit curl nebyly z dodaných binárek dostupné. Proto nelze tento přehled považovat
za úplný, nezávisle certifikovaný SBOM.

### Primární zdroje

- [Podmínky dalšího šíření MediaInfo](https://mediaarea.net/en/MediaInfo/License)
- 
  [Cíl knihovny MediaInfo 26.10](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Project/MSVC2022/Library/MediaInfoLib.vcxproj)
- 
  [Cíl knihovny MediaInfo 21.03](https://github.com/MediaArea/MediaInfoLib/blob/v21.03/Project/MSVC2015/Library/MediaInfoLib.vcxproj)
- 
  [Cíl knihovny MediaInfo 0.7.60](https://github.com/MediaArea/MediaInfoLib/blob/v0.7.60/Project/MSVC2005/Library/MediaInfoLib.vcproj)
- 
  [Načítání curl za běhu](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Source/MediaInfo/Reader/Reader_libcurl.cpp)
- 
  [Přibalené pomocné zdroje a jejich licenční oznámení](https://github.com/MediaArea/MediaInfoLib/tree/v26.10/Source/ThirdParty)
- [Licenční oznámení ZenLib](https://github.com/MediaArea/ZenLib/blob/master/License.txt)
- [Licenční oznámení ve zdroji zlib](https://github.com/madler/zlib/blob/v1.3.2/zlib.h)
- [Licenční oznámení curl 8.11.0](https://github.com/curl/curl/blob/curl-8_11_0/COPYING)
- [Licenční oznámení curl 7.47.1](https://github.com/curl/curl/blob/curl-7_47_1/COPYING)
- [Licence Apache 2.0](https://www.apache.org/licenses/LICENSE-2.0)
- [Popis Base64 od MediaArea](https://github.com/MediaArea/MediaConch/blob/master/README.md)

Tabulky reportů pocházejí z
<https://github.com/MediaArea/MediaInfo/tree/v26.10/Source/Resource/Plugin/Language> . Odpovídající projektová
licence LICENSE je <https://github.com/MediaArea/MediaInfo/blob/v26.10/LICENSE> .

- [libwebp 1.1.0 COPYING](https://github.com/webmproject/libwebp/blob/v1.1.0/COPYING)
- [libwebp 1.1.0 PATENTS](https://github.com/webmproject/libwebp/blob/v1.1.0/PATENTS)
