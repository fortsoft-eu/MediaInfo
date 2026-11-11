# MediaInfo Viewer

[Čeština](README.cs-CZ.md) | [English (US)](../README.md) | [English (UK)](README.en-GB.md) | [English (Australia)](README.en-AU.md) | [Deutsch](README.de-DE.md) | [Français](README.fr-FR.md) | [Español](README.es-ES.md) | [Italiano](README.it-IT.md) | [Português](README.pt-PT.md) | [Polski](README.pl-PL.md) | [Slovenčina](README.sk-SK.md) | [Dansk](README.da-DK.md) | [Suomi](README.fi-FI.md) | [Íslenska](README.is-IS.md) | [Norsk (bokmål)](README.nb-NO.md) | [Svenska](README.sv-SE.md) | [Türkçe](README.tr-TR.md) | [Eesti](README.et-EE.md) | [Gaeilge](README.ga-IE.md) | [Lietuvių](README.lt-LT.md) | [Latviešu](README.lv-LV.md) | [Magyar](README.hu-HU.md) | [Malti](README.mt-MT.md) | [Nederlands](README.nl-NL.md) | [Română](README.ro-RO.md) | [Ελληνικά](README.el-GR.md) | [Bosanski](README.bs-Latn-BA.md) | [Hrvatski](README.hr-HR.md) | **Slovenščina** | [Crnogorski](README.cnr-Latn-ME.md) | [Беларуская](README.be-BY.md) | [Български](README.bg-BG.md) | [Македонски](README.mk-MK.md) | [Српски](README.sr-Cyrl-RS.md) | [Українська](README.uk-UA.md) | [Русский](README.ru-RU.md)

Izvorni pregledovalnik Windows x86 za poročila MediaInfo.dll. Vsaka datoteka ima svoj zavihek samo za branje.

[Gradnja in združljivost](#prevajanje) | [Pregled odvisnosti](#odvisnosti) | [Licenca](../license.txt)

## Prevajanje

Odprite MediaInfo.sln v Visual Studio 2015 z nameščenim naborom orodij Visual C++ v140. Izberite Release | Win32 in zgradite rešitev. Edina aplikacijska platforma je Win32 (x86).

[PCRE2 10.49](https://github.com/PCRE2Project/pcre2/tree/pcre2-10.49) — UTF-16, statično povezano,
BSD-3-Clause. [Izvorna koda](../MediaInfo/PCRE2/).
[license.txt](../license.txt).
PCRE2 je vgrajena v EXE in ne zahteva ločene datoteke DLL ali dodatne namestitve.

Izhodi:

- Release\MediaInfo.exe
- Debug\MediaInfo.exe

Pregledovalnik ne povezuje izvajalnega okolja C ali C++ in ne potrebuje možnosti redistribucije MSVC. Izbrani
MediaInfo.dll ima lahko lastne odvisnosti.

Zgradba zahteva Windows PowerShell in .NET Framework. To so samo gradbene zahteve; izvirna izvršljiva datoteka
ne zahteva niti PowerShell niti .NET.

### Distribucijski paket

Po izgradnji Release zaženite `powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\PackageRelease.ps1` .
Skript ustvari `MediaInfo-<version>-win32.zip` v imeniku rešitve z uporabo različice štiridelne datoteke
izvedljive datoteke. Arhiv vsebuje `MediaInfo.exe` in kombinirani `license.txt` neposredno v svojem korenu.

## Združljivost

Pregledovalnik Win32 je zasnovan za uporabo Windows NT 4.0 APIs.

Izvršljiva datoteka vključuje tri knjižnice x86 MediaInfo: 26.10 za trenutni Windows, 21.03 iz paketa Windows
XP in 0.7.60 iz paketa Windows 95–2000. Sama arhitektura knjižnice ne določa njene združljivosti z
operacijskim sistemom. Pregledovalnik preizkusi združene knjižnice od najnovejše do najstarejše in se ustavi
po prvem uspešnem nalaganju in poizvedbi za različico.

Windows 95 trenutno ni podprto izvajalno okolje.

## Uporaba

- Datoteka > Odpri (Ctrl+O) odpre pogovorno okno datoteke Windows z več izbirami. V Windows Vista in novejših
  različicah Odpri in Shrani uporabi sodobno pogovorno okno skupnih elementov; starejši Windows uporabljajo
  podedovana običajna pogovorna okna.
- Povlecite eno ali več datotek v okno, na ikono EXE ali njeno bližnjico ali pa podajte njihove poti v ukazni
  vrstici. Če več primerkov ni dovoljenih, se datoteke odprejo v že delujočem oknu.
- Vsaka ločena normalizirana polna pot ima en zavihek. Ponovno odpiranje že odprte datoteke izbere njen
  obstoječi zavihek brez ponovnega nalaganja ali spreminjanja poročila, izbire ali položaja drsenja.
  Primerjave ne upoštevajo velikih in malih črk poti. Odpiranje več datotek obdeluje seznam po vrstnem redu in
  pusti zadnjo uspešno obdelano datoteko aktivno, ne glede na to, ali je bila na novo odprta ali je že odprta.
  Če miškin kazalec premaknete nad glavo zavihka, se prikaže celotna pot do datoteke v izvornem opisu orodja,
  tudi ko je prikazano ime datoteke skrajšano.
- V meniju Datoteka je neposredno nad Izhod med ločili prikazanih osem nazadnje naloženih datotek. Vnosi
  prikazujejo samo številko in ime datoteke. Izbira vnosa odpre njegovo shranjeno celotno pot ali izbere
  njegov obstoječi zavihek; uspešno ponovno odpiranje ga premakne na vrh brez dvojnikov. Če izberete
  nedosegljivo datoteko, se prikaže vprašanje, ali želite odstraniti njen vnos nedavnih datotek. Uporabljena
  sta izvorna ikona vprašanja in gumbi Yes/No. Da je privzeto in odstrani vnos iz menija in registra; Ne
  obdrži. Poziv vključuje celotno pot.
- Kolešček miške nad prepolnimi glavami zavihkov se premika po traku z glavo za en zavihek na sporočilo brez
  spreminjanja izbire ali fokusa.
- Ctrl+Tab in Ctrl+Shift+Tab preklop zavihkov; Ctrl+W zapre aktivni zavihek. Srednji klik glave zavihka zapre
  ta zavihek in ohrani vse druge aktivne zavihke. Datoteka > Zapri vse zapre vse zavihke, vključno s poročili
  v čakalni vrsti. Datoteka > Izhod (Alt+F4) zapre aplikacijo.
- Priročni meni glave zavihka vsebuje Zapri zavihek. V Nastavitvah omogočite Zapri zavihke z dvoklikom,
  da zavihek zaprete z dvoklikom na njegovo glavo. Možnost je privzeto izklopljena in se shrani.
- Dvoklik v besedilu poročila izbere besedo. Trojni klik izbere logično vrstico. Vlečenje razširi izbor
  po besedah ali vrsticah.
- Ctrl+A izbere poročilo; Ctrl+C ga kopira.
- Uredi > Najdi (Ctrl+F) išče po aktivnem zavihku poročila ali besedilnem polju okna Pomoč ali O
  programu, odvisno od tega, katero okno ima fokus. Iskalno okno ohrani nazadnje izbrani vir, dokler ima
  fokus. F3 ponovi iskanje, Shift+F3 pa obrne njegovo smer. Na koncu besedila se iskanje nadaljuje z
  drugega konca. Možnosti > Prelom vrstic velja le za aktivni zavihek; kljukica sledi izbranemu zavihku.
  Iskalno okno je mogoče minimizirati in mu spreminjati širino; položaj in možnost Vedno na vrhu se
  shranita. Do 30 iskalnih besedil z možnostmi se hrani le do zaprtja programa. Možnosti začetka in
  konca veljata za logične vrstice. Regularni izrazi uporabljajo sintakso PCRE2. Drugi ukazi menija
  Uredi veljajo za aktivni zavihek poročila. Enter začne iskanje, Shift+Enter pa obrne izbrano smer.
  »Razlikuj velike in male črke« razlikuje velike in male črke; »Išči nazaj« išče proti začetku
  besedila. Izbira vnosa iz zgodovine obnovi vseh pet možnosti iskanja, vključno s stanjem regularnih
  izrazov; »Vedno na vrhu« je neodvisna možnost. »Regularni izraz« onemogoči »Vrstica se začne z« in
  »Vrstica se konča z«. Če sta vključeni obe možnosti robov vrstice, zadostuje ujemanje na enem robu.
  »Prelom vrstic« spremeni samo prikaz.
- Možnosti > Nastavitve (Ctrl+G) odpre eno samo pogovorno okno z nastavitvami za poti MediaInfo in curl,
  pisavo poročila, izravnavo pisave, jezik vmesnika in jezik poročila. Prazna pot DLL omogoča samodejno
  odkrivanje.
- Gumb pisave prikaže družino, velikost in slog pisave ter odpre standardno pogovorno okno pisave Windows.
  Privzeto obnovi Consolas ali Courier New, če Consolas ni na voljo; gumb Privzeto je onemogočen, ko je
  izbrana privzeta vrednost. Pisave, ki jih izbere uporabnik, se ohranijo brez zamenjave s kodo aplikacije.
- Možnosti izravnave pisave so ClearType, če je podprto, GDI in Brez. Začetna izbira je ClearType, če je
  podprto, sicer GDI. Nastavitve pisave veljajo za zavihke poročil, njihov izvoz v slike in tiskanje
  poročil. Pomoč in O programu ohranita lastni pisavi besedila.
- Pomoč odpre ločeno brezmodno okno z lastnim vnosom v opravilni vrstici in gumbom za pomanjšanje. About je
  modalno pogovorno okno; njegova glava izdelka navaja vse tri vdelane različice DLL.

Datoteka > Priprava strani… odpre nastavitve papirja, usmerjenosti in robov za trenutno sejo. Natisni…
(Ctrl+P) odpre sistemsko pogovorno okno za tiskanje; Windows 11 ponuja predogled, Windows 10 in starejši
pa ohranijo klasično okno. Ctrl+P natisne aktivni zavihek glavnega okna ali besedilno polje okna Pomoč
ali O programu, odvisno od tega, katero okno ima fokus. Poročila uporabljajo izbrano pisavo poročila,
Pomoč sistemsko pisavo pogovornih oken, O programu pa pisavo svojega besedilnega polja. Če ni odprtih
zavihkov, Pomoč pa je odprta, Priprava strani… in Natisni… ostaneta na voljo; Natisni… natisne pomoč.
Pomoč uporablja pogovorno okno za tiskanje glavnega okna; ponovni Ctrl+P v Pomoči postavi isto okno v
ospredje. Dolge vrstice se prelomijo, besedilo pa razdeli na strani. Tiskanje poteka v ozadju.

Odpri mapo… odpre datoteke neposredno v izbrani mapi, vsako na svojem zavihku. Podmape niso vključene. Odpri
in Odpri mapo si delita nazadnje izbrano mapo. Izvoz si zapomni ločeno mapo, privzeto Dokumenti.

Napredni način prikaže dodatna polja poročila.

Popolna analiza pregleda celotno datoteko in lahko traja dlje. Te možnosti poročila in Raven sledenja
pripadajo vsakemu zavihku; sprememba osveži samo aktivni zavihek. Zadnja ročno izbrana kombinacija se shrani
za nove zavihke in naslednji zagon. Ujemajoče se predpomnjeno poročilo se ponovno uporabi, dokler datoteka
ostane nespremenjena.

Znani formati, Znani kodeki in Znani parametri se odprejo na svojih zavihkih poročila.

Začetno velikost in lokacijo okna izbere Windows. Prej shranjena postavitev oken preglasi te privzete
nastavitve pri poznejših zagonih.

Levi del vrstice stanja prikazuje poti datotek in potek nalaganja, desni pa različico naložene knjižnice
MediaInfo.dll. Dolge poti se skrajšajo s tripičjem glede na razpoložljivi prostor.

## Ustvari datoteko glave

Meni Orodja je četrti v menijski vrstici. Njegov ukaz Ustvari datoteko glave… odpre eno izvorno datoteko
neodvisno od zavihkov poročila in kopira njenih prvih 524288 bajtov (512 KiB). Krajša datoteka se kopira v
celoti; prazna datoteka ustvari prazen rezultat. To je običajno branje binarne datoteke, brez analize
MediaInfo ali zahteve za MediaInfo.dll. Orodje pusti nespremenjene zavihke poročila in pregledovalnikov seznam
nedavnih datotek.

Po branju se v mapi izvorne datoteke odpre pogovorno okno Shrani kot in predlaga video.mp4.header za
video.mp4: .header se doda celotnemu izvirnemu imenu. Spremenite lahko ime in ciljno mapo. Preklic katerega
koli pogovornega okna ne zapiše nobenega rezultata. Zamenjava obstoječe destinacije zahteva potrditev. Vir
ostane nespremenjen; neuspelo shranjevanje ohrani prejšnji cilj. Odpiranje in shranjevanje uporabljata
najnovejša sistemska pogovorna okna, ki so na voljo v tej različici sistema Windows.

Ob zagonu aplikacije orodje vzame prvotno vnosno mapo iz Datoteka > Odpri. Če ni shranjena nobena mapa,
Windows izbere začetno lokacijo. Ko je vhodna datoteka izbrana, si orodje zapomni lastno mapo samo, dokler se
aplikacija ne zapre, tudi če je možnost Shrani kot preklicana. Ne spremeni niti map, ki jih uporabljata Odpri
in Izvozi, niti ne shrani lastne mape v nastavitve aplikacije. Vsako pogovorno okno Shrani kot se začne v mapi
trenutno izbrane vhodne datoteke, ne glede na prejšnji cilj shranjevanja.

## Iskanje knjižnic

Najprej se preizkusi shranjena ročna pot. Če ga ni mogoče naložiti, samodejno odkrivanje poskusi:

1. MediaInfo.dll poleg izvršljive datoteke, nato pa v vsakem nadrejenem imeniku do pogona ali UNC korena
   skupne rabe.
2. ProgramFiles, ProgramFiles(x86) in ProgramW6432.
3. LOCALAPPDATA in APPDATA.

Pod temi namestitvenimi koreni odkrivanje preveri MediaInfo, MediaArea\MediaInfo, MediaArea,
MediaArea.net\MediaInfo, Programs\MediaInfo, Programs\MediaArea\MediaInfo. Neberljive lokacije in nezdružljivi
DLLs so preskočeni. Diska ne pregleduje rekurzivno.

Če združljivega zunanjega DLL ni mogoče najti, pregledovalnik preizkusi vdelane različice v tem vrstnem redu:
26.10, 21.03, 0.7.60. Ekstrahira in preizkuša eno različico naenkrat. Ko se različica uspešno naloži, se
starejše različice ne izvlečejo in ne preizkusijo. Zadostuje samo distribucija MediaInfo.exe; združljiv
zunanji DLL ima vedno prednost in ga je mogoče posodobiti neodvisno.

Neuspešna ročna sprememba knjižnice ohrani knjižnico, ki je bila že naložena.

## Izvoz poročil

Oblike zapisa Shrani kot so razvrščene TXT, BMP, GIF, JPEG, PNG, TIFF in WebP. Nepodprti kodirniki so
izpuščeni v sodobnih in starih pogovornih oknih.

TXT ponuja ANSI, UTF-8, UTF-8 z BOM, UTF-16 BE z BOM in UTF-16 LE z BOM. Privzeta je druga možnost, UTF-8 brez
BOM. Ohranijo se celotno besedilo poročila in izvirni konci vrstic.

BMP, PNG in TIFF ohranijo vse upodobljene barve; GIF89a ohrani natančno upodobljeno paleto, ko ima slika
največ 256 barv. Izvoz vedno zapiše izbrano obliko ali javi napako; nikoli ne nadomesti drugega formata.

## Jeziki vmesnika in poročil

Nastavitve (Možnosti > Nastavitve, Ctrl+G) vsebujejo poti knjižnic, pisavo poročila, glajenje in jezike.
Vmesnik ima 36 različic in sprva sledi Windowsu. Poročila vedno privzeto uporabljajo izvirno angleščino
knjižnice, neodvisno od Windowsa in vmesnika. To spremeni samo ročna izbira jezika: angleščina, 37 prevodov
ali lastna tabela MediaInfo CSV.

V redu ali Uporabi potrdi spremembe; Prekliči zavrže čakajoče spremembe. Nastavitve določijo omejitev imena
zavihka (privzeto 80) in počistijo seznam nedavnih datotek. Dolga imena ohranijo začetek, konec in pripono s
tropičjem na sredini.

Naslov glavnega okna prikazuje dejavno datoteko v obliki ime datoteke — MediaInfo. V nastavitvah lahko
dolžino imena v naslovu ločeno nastavite na 8–255 znakov (privzeto 40). Daljša imena se skrajšajo z istim
tropičjem na sredini, končnica pa se ohrani. Brez odprtih zavihkov je naslov MediaInfo.

Privzeto je dovoljen samo en primerek, poznejši zagoni pa pošljejo datoteke odprtemu oknu. V nastavitvah lahko
dovolite več primerkov. Pri več oknih le prvo okno vsakega obrazca obnovi shranjeni položaj; poznejša okna
obnovijo samo velikost.

Če spremenite le vmesnik, ostane besedilo odprtih poročil nespremenjeno. Ročno uporabljena sprememba jezika
poročila znova naloži njihova poročila, pri tem pa ohrani vrstni red zavihkov in vrstni red MRU.

## libcurl

Samodejna preverjanja odkrivanja curl poleg izbranih MediaInfo DLL, nato deljenih executable/ancestor,
programskih datotek in lokacij za uporabniško namestitev. Če združljivega zunanjega curl ni mogoče najti, se
ustrezna vdelana trenutna različica ali različica XP ekstrahira v preverjeni predpomnilnik za posameznega
uporabnika. Najstarejši MediaInfo 0.7.60 v celoti zaobide odkrivanje, ekstrakcijo in nalaganje curl. Izrecno
izbran neveljaven curl zavrne spremembo preference; manjkajoči izbirni samodejni curl ne prepreči običajnih
poročil lokalnih datotek.

## Imena datotek in nedavne datoteke

Imena datotek MRU se skrajšajo samo, če so daljša od 80 UTF-16 kodnih enot. Srednja elipsa ohrani začetek,
konec imena datoteke pred njeno končnico in celotno končno končnico; celotne poti in poročila ostanejo
nespremenjeni. Podnapisi zavihkov uporabljajo isti algoritem z nastavljivo privzeto omejitvijo 80.

Nedavne datoteke > Počisti takoj počisti meni MRU v živo in njegove shranjene poti, medtem ko ostanejo vsi
odprti zavihki nedotaknjeni. Ne uporablja ali preverja čakajočih nastavitev in ne omogoča Uporabi. Prekliči
ali Escape ohrani počiščeno zgodovino, medtem ko zavrže urejanja v teku. Počisti je onemogočen, kadar koli je
seznam prazen, njegovo stanje pa se osveži, ko se seznam zapolni z novimi poročili. Napaka pri pisanju v
register je sporočena takoj. Uporaba nove omejitve imena zavihka posodobi vsak odprt zavihek brez ponovnega
nalaganja njegovega medijskega poročila.

## Licenca in redistribucija

Pregledovalnik je licenciran pod licenco MIT v license.txt.

MediaInfo je komponenta tretje osebe. Edino vzdrževano obvestilo o distribuciji je korenski license.txt,
kodiran kot UTF-8 z CRLF in vključuje pregledovalnik, knjižnice, statično vključene komponente, ikono in
uradne prevajalske tabele.

Ta izdelek uporablja knjižnico MediaInfo, Copyright (c) 2002-2026 MediaArea.net SARL.

- MediaInfo: <https://mediaarea.net/MediaInfo>
- Licenca: <https://mediaarea.net/en/MediaInfo/License>
- Windows prenosi: <https://mediaarea.net/en/MediaInfo/Download/Windows>

## Odvisnosti

### Datoteke

| Vir | Arhitektura | Različica, ki jo je sporočila komponenta | SHA-256 |
| --- | --- | --- | --- |
| Resources/lib/26.10/MediaInfo.dll | x86 | 26.10 | E73027A1577084135425AA013D46C8B2985AD142CCF04F1ADB301B9A9CFB78F8 |
| Resources/lib/21.03/MediaInfo.dll | x86 | 21.03 | EBBF1C371702F3DC39CA23D619C47EDF97E66A95AEABE725284F1402D8F3E58A |
| Resources/lib/0.7.60/MediaInfo.dll | x86 | 0.7.60 | A26C07BCC25FA01A40E6888D02EABD59AA8DB2ABF6F5195481228D3A91D04441 |
| Resources/lib/26.10/libcurl.dll | x86 | 8.11.0-DEV, Schannel, zlib 1.3.1 | DCF136C84F3A4FBEAE2B317FE36D7F11225B56FBA3343AF4BBA8706B3F46F334 |
| Resources/lib/21.03/libcurl.dll | x86 | 7.47.1, WinSSL, zlib 1.2.8 | 21025CAC8089F1E570EE083D8CFD6311C2C51E97094A9FCD8C7A0B544C22CB48 |
| Resources/lib/libwebp.dll | x86 | 1.1.0 | 9986023BB6FF5510A157919F0CD958A94800EC6A1D981F3403A9648BEDFEE575 |

Poti v tabeli so relativne glede na imenik projekta MediaInfo.

Trenutna knjižnica poroča o razvojni različici; njegovega točnega vira commit ni mogoče obnoviti iz tega niza
različice. Spremno obvestilo uporablja zgornje besedilo avtorskih pravic in dovoljenj 8.11.0, katerega
licenčni pogoji so prisotni tudi v razvojni seriji.

### Vgrajene komponente

| Komponenta | Dokazi in obseg | Obvestilo |
| --- | --- | --- |
| MediaInfoLib | Dejanske različice in zahtevani izvozi Unicode; nespremenjene dobavljene binarne datoteke | Izvirne avtorske pravice, pogoji redistribucije in zavrnitev odgovornosti, specifične za različico |
| ZenLib | Statične reference projekta in vdelan ZenLib RTTI v vseh treh DLLs; natančne povezane revizije niso na voljo | Obvestilo v slogu zlib ZenLib |
| zlib | Vdelani nizi različice inflate/deflate: 1.3.2 v MediaInfo 26.10, 1.2.11 v 21.03, 1.2.7 v 0.7.60; curl dodatno poroča 1.3.1 in 1.2.8 | Izvirna obvestila zlib za vseh pet različic |
| TinyXML-2 | Ujemanje sodobnih izvornih ciljev in dvojiškega RTTI; vključen v podedovani projekt, vendar ni neodvisno identificiran v odstranjeni podedovani dvojiški datoteki | Izvirno obvestilo v slogu Lee Thomason zlib je ohranjeno |
| Brian Gladman AES | Vključeno v oba tarča sodobne knjižnice navzgor z ustreznimi dovoljenimi obvestili o izvoru | 1998–2013 obvestilo o prerazporeditvi in zavrnitev odgovornosti |
| Brian Gladman SHA-1/SHA-2 | Oba moderna cilja; Konstantni tabeli SHA-256 in SHA-512 sta prisotni v obeh sodobnih binarnih datotekah | 1998–2010 obvestilo o prerazporeditvi in zavrnitev odgovornosti |
| Brian Gladman HMAC | Obe sodobni tarči in njihova bralna koda curl/S3 | Prvotno obvestilo s tremi pogoji, vključno z odstavkom o alternativni licenci |
| MD5 | Sodobni izvorni cilji; Implementacija Colin Plumb izrecno navaja javno domeno | Pripis ohranjen |
| Base64 | Markus Ewald glava v vseh treh ustreznih izvornih drevesih, pripisovanje Bob Withers | Pripis izvirnega avtorstva ohranjen; kvalifikacije spodaj |
| fmt | 26.10 cilj in fmt v11 format_error RTTI v binarni obliki | Prvotno obvestilo MIT, vključno z neobvezno izjemo |
| tfsxml | 26.10 vir cilj | Izvirno obvestilo MediaArea MIT |
| Vmesnik Android JNI | JNI_OnLoad dejansko izvozita tako sodobna DLLs; vključena glava JNI je iz AOSP | AOSP avtorske pravice in popolna licenca Apache 2.0 |
| libcurl | Dobavljene binarne datoteke x86; izvoz dejanske različice; dinamično uporablja sodobni MediaInfo | Izvirna obvestila curl za 8.11.0 in 7.47.1 |
| Uradni prevodi poročil | Vsi 38 nespremenjeni CSV viri iz jezikovnega imenika MediaInfo v26.10; 37 ne-angleških tabel je vdelanih, medtem ko angleščina uporablja privzete DLL | Isto obvestilo o projektu BSD-2-Clause je ohranjeno v združenem obvestilu |
| ikona MediaInfo | Nespremenjena uradna ikona z več slikami, izvorna različica f057dd3649bc8692a83863b67770e22c9b9dd81a | Izvirno obvestilo in pripis BSD-2-Clause |
| libwebp | WebPEncodeLosslessBGRA, WebPFree; 1.1.0; x86 | BSD-3-Clause; PATENTS |

Ujemajoči izvorni cilji vzpostavijo vključitev v te konfiguracije gradnje navzgor; ne dokazujejo, da vsaka
funkcija preživi optimizacijo v binarnih datotekah prodajalca. Za odvisnosti, katerih revizija ni zabeležena v
teh dvojiških datotekah, ni podana nobena zahteva glede natančne različice.

### Izbirne komponente in sistemske knjižnice

- Projekti knjižnice Windows omogočajo libcurl, naložen med izvajanjem, za MediaInfo 26.10 in 21.03. MediaInfo
  0.7.60 je bil izdelan z MEDIAINFO_LIBCURL_NO; njegova dvojiška datoteka vsebuje tudi diagnostiko onemogočene
  podpore. Pregledovalnik nikoli ne odkrije, ekstrahira ali naloži curl za to različico v paketu.
- libmms je onemogočen v vseh treh priloženih Windows DLLs, kar potrjujejo njihova vdelana sporočila o
  onemogočeni podpori. Ni prerazporejeno.
- Qt in wxWidgets pripadata neobveznim zgradbam GUI. Nobeden ni vključen v ta pregledovalnik ali v te
  odvisnosti DLL. Njihovi generični vnosi so bili odstranjeni iz prikazane licence.
- Graphviz je izbirna kljuka med izvajanjem v sodobni kodi navzgor. Noben Graphviz DLL ni prerazporejen.
- Noben vtičnik FFmpeg ni redistribuiran.
- MediaInfo DLLs neposredno uvozi samo KERNEL32.dll. To ne pomeni, da njihovo statično povezano izvajalno
  okolje in pomožna koda manjkata.
- Trenutni curl neposredno uvozi WS2_32.dll, bcrypt.dll, ADVAPI32.dll, CRYPT32.dll in KERNEL32.dll. XP curl
  neposredno uvozi WS2_32.dll, WLDAP32.dll, ADVAPI32.dll in KERNEL32.dll. To so komponente Windows. Njihovo
  razpoložljivost preverja nalagalnik Windows.
- Curl poroča Windows Schannel/WinSSL, ne zgradba OpenSSL. Njegova prijavljena dodatna odvisnost stiskanja je
  statično vključena zlib. V njegovi tabeli neposrednega uvoza se ne pojavi noben dodatni zunanji ne-Windows
  DLL.
- Sam pregledovalnik nima nobene odvisnosti od izvajalnega okolja C/C++. Priloženi DLLs tretje osebe vsebuje
  lastne prevedene dele izvajalnega okolja. Zgradbe Windows uporabljajo Microsoftova orodja; ni dokazov, ki bi
  zahtevali generične vnose v popis libstdc++ ali libc++.
- JPEG uporablja dinamično naložen sistem GDI+. Pakirnik virov C# in PowerShell sta orodji za gradnjo in nista
  odvisnosti med izvajanjem.

Običajni pregled lokalnih datotek ne zahteva strežnika MediaArea ali oddaljeno prenesene baze podatkov v
formatu. libcurl uporablja MediaInfo za vnose URL in morebitne oddaljene reference v podprtih medijskih
formatih. Združevanje tega pregledovalnika ne doda ločenega ukaza za odpiranje URL.

### Shranjevanje licence in omejitve

Edino vzdrževano obvestilo o distribuciji je [license.txt](../license.txt) , kodirano kot UTF-8 z CRLF.
Preverjene klavzule o prerazporeditvi BSD, curl, zlib, MIT in Apache ne zahtevajo ločene datoteke z obvestilom
fizično poleg vsakega DLL; združeno obvestilo jih spremlja v izvedljivem in distribucijskem gradivu.

Arhivirani paket MediaInfo 0.7.60 uporablja lastno licenco, specifično za različico, in vključuje staro
besedilo GNU Library GPL. Njegovi pogoji izrecno razlikujejo nespremenjeno binarno redistribucijo od
spremenjenih različic; dinamično povezovanje tega pregledovalnika ne spremeni priloženega DLL. Njeni izvirni
pogoji in spremno besedilo licence so ohranjeni. Pregledovalnik ostane z licenco MIT.

Eno pripisovanje navzgor potrebuje kvalifikacijo: glava Markus Ewald Base64 nima izrecnega dovoljenja ali
izjave o licenci. MediaArea opisuje implementacijo Bob Withers Base64 kot javno domeno v svoji povezani
dokumentaciji MediaConch, vendar to ne določa samostojne dodelitve licence za vsako spremembo Ewald. Za to
glavo ni bila izumljena nobena licenca. Popolna potrditev tega porekla, natančnih revizij ZenLib in razvoja
curl commit ni bila na voljo v priloženih dvojiških datotekah. Te točke preprečujejo obravnavanje tega popisa
kot popolnega, neodvisno potrjenega SBOM.

### Primarni viri

- [MediaInfo pogoji prerazporeditve](https://mediaarea.net/en/MediaInfo/License)
- 
  [MediaInfo 26.10 cilj knjižnice](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Project/MSVC2022/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 21.03 cilj knjižnice](https://github.com/MediaArea/MediaInfoLib/blob/v21.03/Project/MSVC2015/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 0.7.60 cilj knjižnice](https://github.com/MediaArea/MediaInfoLib/blob/v0.7.60/Project/MSVC2005/Library/MediaInfoLib.vcproj)
- 
  [Runtime curl nalagalnik](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Source/MediaInfo/Reader/Reader_libcurl.cpp)
- 
  [Skupni viri pomoči in njihova obvestila](https://github.com/MediaArea/MediaInfoLib/tree/v26.10/Source/ThirdParty)
- [ZenLib obvestilo](https://github.com/MediaArea/ZenLib/blob/master/License.txt)
- [zlib vir obvestila](https://github.com/madler/zlib/blob/v1.3.2/zlib.h)
- [curl 8.11.0 obvestilo](https://github.com/curl/curl/blob/curl-8_11_0/COPYING)
- [curl 7.47.1 obvestilo](https://github.com/curl/curl/blob/curl-7_47_1/COPYING)
- [Licenca Apache 2.0](https://www.apache.org/licenses/LICENSE-2.0)
- [MediaArea Base64 opis](https://github.com/MediaArea/MediaConch/blob/master/README.md)

Tabele poročil prihajajo iz
<https://github.com/MediaArea/MediaInfo/tree/v26.10/Source/Resource/Plugin/Language> . Ustrezni projekt
LICENSE je <https://github.com/MediaArea/MediaInfo/blob/v26.10/LICENSE> .

- [libwebp 1.1.0 COPYING](https://github.com/webmproject/libwebp/blob/v1.1.0/COPYING)
- [libwebp 1.1.0 PATENTS](https://github.com/webmproject/libwebp/blob/v1.1.0/PATENTS)
