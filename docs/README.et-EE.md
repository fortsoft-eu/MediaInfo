# MediaInfo Viewer

[Čeština](README.cs-CZ.md) | [English (US)](../README.md) | [English (UK)](README.en-GB.md) | [English (Australia)](README.en-AU.md) | [Deutsch](README.de-DE.md) | [Français](README.fr-FR.md) | [Español](README.es-ES.md) | [Italiano](README.it-IT.md) | [Português](README.pt-PT.md) | [Polski](README.pl-PL.md) | [Slovenčina](README.sk-SK.md) | [Dansk](README.da-DK.md) | [Suomi](README.fi-FI.md) | [Íslenska](README.is-IS.md) | [Norsk (bokmål)](README.nb-NO.md) | [Svenska](README.sv-SE.md) | [Türkçe](README.tr-TR.md) | **Eesti** | [Gaeilge](README.ga-IE.md) | [Lietuvių](README.lt-LT.md) | [Latviešu](README.lv-LV.md) | [Magyar](README.hu-HU.md) | [Malti](README.mt-MT.md) | [Nederlands](README.nl-NL.md) | [Română](README.ro-RO.md) | [Ελληνικά](README.el-GR.md) | [Bosanski](README.bs-Latn-BA.md) | [Hrvatski](README.hr-HR.md) | [Slovenščina](README.sl-SI.md) | [Crnogorski](README.cnr-Latn-ME.md) | [Беларуская](README.be-BY.md) | [Български](README.bg-BG.md) | [Македонски](README.mk-MK.md) | [Српски](README.sr-Cyrl-RS.md) | [Українська](README.uk-UA.md) | [Русский](README.ru-RU.md)

Windows x86 omarakendus MediaInfo.dll-i aruannete vaatamiseks. Igal failil on oma kirjutuskaitstud vahekaart.

[Koostamine ja ühilduvus](#kompileerimine) | [Sõltuvuste audit](#sõltuvused) | [Litsents](../license.txt)

## Kompileerimine

Avage MediaInfo.sln kaustas Visual Studio 2015, kui tööriistakomplekt on installitud Visual C++ v140. Valige Release | Win32 ja koostage lahendus. Ainus rakendusplatvorm on Win32 (x86).

[PCRE2 10.49](https://github.com/PCRE2Project/pcre2/tree/pcre2-10.49) — UTF-16, staatiliselt lingitud,
BSD-3-Clause. [Lähtekood](../MediaInfo/PCRE2/).
[license.txt](../license.txt).
PCRE2 on EXE-faili sisse ehitatud ega vaja eraldi DLL-faili või paigaldamist.

Väljundid:

- Release\MediaInfo.exe
- Debug\MediaInfo.exe

Vaataja ei lingi C ega C++ käitusaega ega vaja MSVC edasilevitatavat. Valitud MediaInfo.dll-l võivad olla oma
sõltuvused.

Ehitamiseks on vaja Windows PowerShell ja .NET Framework. Need on ainult ehitusnõuded; algne käivitatav fail
ei nõua ei PowerShell ega .NET.

### Väljalaskepakett

Pärast Release ehitamist käivitage
`powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\PackageRelease.ps1` . Skript loob lahenduse
kataloogis `MediaInfo-<version>-win32.zip` , kasutades käivitatava faili neljaosalist versiooni. Arhiiv
sisaldab `MediaInfo.exe` ja kombineeritud `license.txt` otse selle juurtes.

## Ühilduvus

Win32 vaataja on loodud kasutama Windows NT 4.0 APIs.

Käivitatav fail sisaldab kolme x86 MediaInfo teeki: 26.10 praeguse Windows jaoks, 21.03 paketist Windows XP ja
0.7.60 paketist Windows 95–2000. Ainuüksi raamatukogu arhitektuur ei määra selle operatsioonisüsteemi
ühilduvust. Vaataja proovib komplekteeritud teeke uusimast vanimani ja peatub pärast esimest edukat laadimist
ja versioonipäringut.

Windows 95 ei ole praegu toetatud käitusaeg.

## Kasutamine

- Fail > Ava (Ctrl+O) avab mitme valikuga failidialoogi Windows. Windows Vista ja uuemates versioonides
  kasutage avamiseks ja salvestamiseks kaasaegset ühise üksuse dialoogi; vanemad Windows kasutavad tavalisi
  päranddialooge.
- Lohistage üks või mitu faili aknasse, EXE ikoonile või selle otseteele või andke failiteed käsureal. Kui
  mitu eksemplari pole lubatud, avatakse failid juba töötavas aknas.
- Igal erineval normaliseeritud täisteel on üks vahekaart. Juba avatud faili taasavamisel valitakse selle
  olemasolev vahekaart ilma aruannet, valikut või kerimisasendit uuesti laadimata või muutmata. Võrdlused
  ignoreerivad teetähte. Mitme faili avamine töötleb loendit järjekorras ja jätab aktiivseks viimase edukalt
  töödeldud faili, olenemata sellest, kas see on äsja avatud või juba avatud. Hõljutades kursorit vahelehe
  päise kohal, kuvatakse natiivses kohtspikris faili täielik tee, sealhulgas juhul, kui kuvatavat failinime
  lühendatakse.
- Menüü Fail loetleb kaheksa viimati laaditud faili otse Exit kohal, eraldajate vahel. Kirjed näitavad ainult
  numbrit ja failinime. Kirje valimine avab selle salvestatud täieliku tee või valib olemasoleva vahekaardi;
  edukas taasavamine viib selle üles ilma duplikaatideta. Kättesaamatu faili valimisel küsitakse, kas
  eemaldada selle hiljutiste failide kirje. Kasutatakse natiivse küsimuse ikooni ja Yes/No nuppe. Jah on
  vaikimisi ja eemaldab kirje menüüst ja registrist; No ei säilita seda. Viip sisaldab kogu teed.
- Hiireratas ületäitunud vahelehe päistest kerib päiseribal ühe vahekaardi sõnumi kohta, muutmata valikut või
  fookust.
- Ctrl+Tab ja Ctrl+Shift+Tab vahekaartide vahetamine; Ctrl+W sulgeb aktiivse vahekaardi. Vahekaardi päise
  keskmisel klõpsamisel suletakse see vahekaart, säilitades samal ajal kõik muud aktiivsed vahekaardid. Fail >
  Sule kõik sulgeb kõik vahekaardid, sealhulgas järjekorras olevad aruanded. Fail > Välju (Alt+F4) sulgeb
  rakenduse.
- Topeltklõps valib sõna. Kolmikklõps valib loogilise rea. Lohistamine laiendab valikut sõnade või ridade
  kaupa.
- Ctrl+A valib aruande; Ctrl+C kopeerib selle.
- Redigeeri > Otsi (Ctrl+F) otsib aktiivselt vahekaardilt. F3 kordab otsingut ja Shift+F3 pöörab otsingu suuna
  ümber. Teksti lõppu jõudes jätkub otsing teisest otsast. Suvandid > Reamurdmine kehtib ainult aktiivsel
  vahekaardil; märge vastab valitud vahekaardile. Otsinguakna saab minimeerida ja selle laiust muuta; asukoht
  ning valik Alati pealmine jäetakse meelde. Kuni 30 otsinguteksti koos valikutega säilitatakse ainult
  rakenduse sulgemiseni. Alguse ja lõpu valikud kehtivad loogiliste ridade kohta. Regulaaravaldised kasutavad
  PCRE2 süntaksit. Kõik menüü Redigeeri käsud kehtivad ainult aktiivsel vahekaardil. Enter käivitab otsingu;
  Shift+Enter pöörab valitud suuna ümber. „Tõstutundlik“ eristab suur- ja väiketähti; „Otsi tagasisuunas“
  otsib teksti alguse suunas. Ajalookirje valimine taastab kõik viis otsinguvalikut, sealhulgas
  regulaaravaldise režiimi oleku; „Alati pealmine“ on sõltumatu. „Regulaaravaldis“ keelab valikud „Rida algab“
  ja „Rida lõpeb“. Kui mõlemad reapiiri valikud on lubatud, piisab vastest ühes piiris. „Reamurdmine“ muudab
  ainult kuvamist.
- Seaded > Eelistused (Ctrl+G) avab ühe eelistuste dialoogi MediaInfo ja curl teede, aruande fondi, fondi
  antialiasingu, liidese keele ja aruande keele jaoks. Tühi DLL tee võimaldab automaatset tuvastamist.
- Fondinupp kuvab perekonna, punkti suuruse ja stiili ning avab standardse Windows fondidialoogi. Vaikeseade
  taastab Consolas või Courier New, kui Consolas pole saadaval; nupp Vaikimisi on keelatud, kui vaikeseade on
  valitud. Kasutaja valitud fondid säilitatakse ilma rakenduskoodiga asendamata.
- Fondi antialiase valikud on ClearType, kui seda toetatakse, GDI ja Puudub. Esialgne valik on ClearType, kui
  seda toetatakse, muul juhul GDI. Fondi seaded mõjutavad ainult meediaraporteid ja nende kujutiste eksporti.
- Abi avab eraldi režiimita akna, millel on oma tegumiriba sisestus ja minimeerimisnupp. Teave on modaalne
  dialoog; selle toote päises on loetletud kõik kolm manustatud DLL versiooni.

Prindi… (Ctrl+P) avab süsteemi printerivaliku dialoogi ja prindib kogu aktiivse vahekaardi ilma eelvaateta.
Kasutatakse valitud aruandefonti; pikad read murtakse ja tekst jagatakse lehekülgedeks. Printimine toimub
taustal.

Ava kaust… avab otse valitud kaustas olevad failid, igaüks oma vahekaardil. Alamkaustu ei kaasata. Ava ja Ava
kaust jagavad viimati valitud kausta. Eksport jätab meelde oma kausta, vaikimisi Dokumendid.

Täpsem režiim kuvab aruandes lisavälju.

Täielik analüüs uurib kogu faili ja võib võtta kauem aega. Need aruande valikud ja Jälitustase kuuluvad igale
vahelehele; muudatus värskendab ainult aktiivset vahekaarti. Viimane käsitsi valitud kombinatsioon
salvestatakse uute vahekaartide ja järgmise käivitamise jaoks. Sobivat vahemällu salvestatud aruannet
kasutatakse uuesti, kuni fail jääb muutumatuks.

Teadaolevad vormingud, Teadaolevad koodekid ja Teadaolevad parameetrid avanevad eraldi aruandevahekaartidel.

Akna esialgse suuruse ja asukoha valib Windows. Varem salvestatud aknapaigutus alistab need vaikeseaded
hilisematel käivitamistel.

Olekuriba vasakul pool kuvatakse failiteed ja laadimise edenemine, paremal laaditud MediaInfo.dll versioon.
Pikad teed lühendatakse vastavalt vabale ruumile mõttepunktidega.

## Loo päisefail

Tööriistad on menüüriba neljas menüü. Selle käsk Loo päisefail… avab aruande vahekaartidest sõltumatult ühe
lähtefaili ja kopeerib selle esimesed 524288 baiti (512 KiB). Lühem fail kopeeritakse täielikult; tühi fail
annab tühja väljundi. See on tavaline binaarfailide lugemine, ilma MediaInfo analüüsita või MediaInfo.dll-i
nõudeta. Tööriist jätab aruannete vahelehed ja programmi viimaste failide loendi muutmata.

Pärast lugemist algab lähtefaili kaustas dialoog Salvesta nimega ja pakub video.mp4 jaoks video.mp4.header:
.header lisatakse kogu algsele nimele. Saate muuta nii nime kui ka sihtkausta. Kummagi dialoogi tühistamine ei
kirjuta väljundit. Olemasoleva sihtkoha asendamine nõuab kinnitust. Allikas jääb muutumatuks; ebaõnnestunud
salvestamine säilitab eelmise sihtkoha. Avamiseks ja salvestamiseks kasutatakse uusimaid selles Windowsi
versioonis saadaolevaid süsteemidialooge.

Rakenduse käivitamisel võtab tööriist algse sisendkausta Fail > Ava. Kui ühtegi kausta pole salvestatud, valib
Windows algse asukoha. Pärast sisendfaili valimist jätab tööriist oma kausta meelde ainult kuni rakenduse
sulgemiseni, isegi kui Salvesta nimega on tühistatud. See ei muuda Ava ja Ekspordi kasutatavaid kaustu ega
salvesta oma kausta rakenduse seadetesse. Iga Salvesta nimega dialoog algab parajasti valitud sisendfaili
kaustast, olenemata eelmisest salvestussihtkohast.

## Teekide otsimine

Esmalt proovitakse salvestatud käsitsi teed. Kui seda ei saa laadida, proovib automaatne avastamine:

1. MediaInfo.dll käivitatava faili kõrval, seejärel igas ülemkataloogis kuni draivini või UNC jagage juur.
2. ProgramFiles, ProgramFiles(x86) ja ProgramW6432.
3. LOCALAPPDATA ja APPDATA.

Nende installijuurte all kontrollib avastus MediaInfo, MediaArea\MediaInfo, MediaArea,
MediaArea.net\MediaInfo, Programs\MediaInfo, Programs\MediaArea\MediaInfo. Loetamatud asukohad ja ühildumatud
DLLs jäetakse vahele. See ei skaneeri ketast rekursiivselt.

Kui ühilduvat välist DLL ei leita, proovib vaataja manustatud versioone järgmises järjekorras: 26.10, 21.03,
0.7.60. See ekstraktib ja testib ühe versiooni korraga. Kui versioon on edukalt laaditud, siis vanemaid
versioone ei ekstraheerita ega testita. Ainuüksi MediaInfo.exe levitamisest piisab; ühilduv väline DLL on
alati prioriteetne ja seda saab iseseisvalt värskendada.

Ebaõnnestunud käsitsi teegi muutmine säilitab juba laaditud teegi.

## Aruande eksport

Salvesta nimega vormingud on järjestatud TXT, BMP, GIF, JPEG, PNG, TIFF ja WebP. Toetamata kodeerijad on välja
jäetud nii kaasaegsetest kui ka päranddialoogidest.

TXT pakub vorminguid ANSI, UTF-8, BOM-iga UTF-8, BOM-iga UTF-16 BE ja BOM-iga UTF-16 LE. Vaikimisi on valitud
teine kirje, BOM-ita UTF-8. Aruande kogu tekst ja algsed reavahetused säilivad.

BMP, PNG ja TIFF säilitavad kõik renderdatud värvid; GIF89a säilitab täpse renderdatud paleti, kui pildil on
kuni 256 värvi. Eksport kirjutab alati valitud vormingu või teatab veast; see ei asenda kunagi teist
vormingut.

## Liidese ja aruannete keeled

Eelistused (Suvandid > Eelistused, Ctrl+G) sisaldavad teekide asukohti, aruande fonti, silumist ja keeli.
Liidesel on 36 varianti ning alguses järgib see Windowsi. Aruanded kasutavad vaikimisi alati teegi algset
inglise keelt, sõltumata Windowsist ja liidesest. Seda muudab ainult käsitsi valitud aruande keel: inglise
keel, 37 tõlget või oma MediaInfo CSV-tabel.

OK või Rakenda kinnitab muudatused; Loobu tühistab ootel muudatused. Eelistustes saab määrata vahekaardi nime
piirangu (vaikimisi 80) ja tühjendada hiljutiste failide loendi. Pikad nimed säilitavad alguse, lõpu ja
laiendi, keskel on mõttepunktid.

Vaikimisi on lubatud ainult üks eksemplar ja järgmised käivitused saadavad failid avatud aknasse. Eelistustes
saab lubada mitu eksemplari. Mitme akna korral taastab salvestatud asukoha ainult iga vormi esimene aken;
järgmised aknad taastavad ainult suuruse.

Ainult liidese muutmine jätab avatud aruannete teksti muutmata. Käsitsi rakendatud aruande keele muudatus
laadib nende aruanded uuesti, säilitades samal ajal tabeldusjärjestuse ja MRU järjestuse.

## libcurl

Automaatne curl leidmise kontroll valitud MediaInfo DLL, seejärel jagatud executable/ancestor,
programmifailide ja kasutaja installikohtade kõrval. Kui ühilduvat välist curl ei leita, ekstraheeritakse
sobiv manustatud praegune või XP versioon kontrollitud kasutaja vahemällu. Vanim MediaInfo 0.7.60 möödub
täielikult curl avastamisest, ekstraheerimisest ja laadimisest. Selgelt valitud kehtetu curl lükkab eelistuse
muudatuse tagasi; puudub valikuline automaatne curl, mis ei takista tavalisi kohaliku faili aruandeid.

## Failinimed ja viimati kasutatud failid

MRU failinimesid lühendatakse ainult siis, kui need on pikemad kui 80 UTF-16 koodiühikut. Keskmine ellips
säilitab failinime alguse, lõpu enne selle laiendit ja täieliku lõpliku laiendi; täielikud teed ja aruanded
jäävad muutumatuks. Vahelehtede pealdised kasutavad sama algoritmi konfigureeritava vaikepiiranguga 80.

Hiljutised failid > Kustuta kustutab kohe nii reaalajas MRU menüü kui ka selle salvestatud teed, jättes kõik
avatud vahelehed puutumata. See ei rakenda ega kinnita ootel olevaid eelistusi ega luba rakendust. Tühista või
põgenemine säilitab kustutatud ajaloo, loobudes samal ajal ootel olevatest muudatustest. Kustuta on keelatud,
kui loend on tühi, ja selle olekut värskendatakse, kui loendisse lisatakse uued aruanded. Registri kirjutamise
ebaõnnestumisest teatatakse kohe. Uue vahelehe nimepiirangu rakendamine värskendab iga avatud vahekaarti ilma
selle meediaaruannet uuesti laadimata.

## Litsents ja ümberjagamine

Vaataja on litsentsitud MIT litsentsi alusel license.txt.

MediaInfo on kolmanda osapoole komponent. Ainus hooldatav leviteatis on root license.txt, mis on kodeeritud
kui UTF-8 koos CRLF-ga ja sisaldab vaatajat, teeke, staatiliselt ühendatud komponente, ikooni ja ametlikke
tõlketabeleid.

See toode kasutab MediaInfo teeki, autoriõigus (c) 2002-2026 MediaArea.net SARL.

- MediaInfo: <https://mediaarea.net/MediaInfo>
- Litsents: <https://mediaarea.net/en/MediaInfo/License>
- Windows allalaadimisi: <https://mediaarea.net/en/MediaInfo/Download/Windows>

## Sõltuvused

### Failid

| Ressurss | Arhitektuur | Komponendi teatatud versioon | SHA-256 |
| --- | --- | --- | --- |
| Resources/lib/26.10/MediaInfo.dll | x86 | 26.10 | E73027A1577084135425AA013D46C8B2985AD142CCF04F1ADB301B9A9CFB78F8 |
| Resources/lib/21.03/MediaInfo.dll | x86 | 21.03 | EBBF1C371702F3DC39CA23D619C47EDF97E66A95AEABE725284F1402D8F3E58A |
| Resources/lib/0.7.60/MediaInfo.dll | x86 | 0.7.60 | A26C07BCC25FA01A40E6888D02EABD59AA8DB2ABF6F5195481228D3A91D04441 |
| Resources/lib/26.10/libcurl.dll | x86 | 8.11.0-DEV, Schannel, zlib 1.3.1 | DCF136C84F3A4FBEAE2B317FE36D7F11225B56FBA3343AF4BBA8706B3F46F334 |
| Resources/lib/21.03/libcurl.dll | x86 | 7.47.1, WinSSL, zlib 1.2.8 | 21025CAC8089F1E570EE083D8CFD6311C2C51E97094A9FCD8C7A0B544C22CB48 |
| Resources/lib/libwebp.dll | x86 | 1.1.0 | 9986023BB6FF5510A157919F0CD958A94800EC6A1D981F3403A9648BEDFEE575 |

Tabeli teed on suhtelised MediaInfo projektikataloogi suhtes.

Praegune raamatukogu teatab arendusversioonist; selle täpset allikat commit ei saa sellest versioonistringist
taastada. Sellega kaasnev teatis kasutab ülesvoolu 8.11.0 autoriõiguse ja lubade teksti, mille
litsentsitingimused on samuti arendussarjas olemas.

### Sisseehitatud komponendid

| Komponent | Tõendid ja ulatus | Märkus |
| --- | --- | --- |
| MediaInfoLib | Tegelikud versioonid ja nõutavad Unicode'i ekspordid; muutmata tarnitud kahendfailid | Versioonispetsiifilised originaalautoriõigused, edasilevitamistingimused ja lahtiütlus |
| ZenLib | Staatilised projektiviited ja manustatud ZenLib RTTI kõigis kolmes DLLs; täpseid lingitud versioone pole esitatud | zlib-stiilis ZenLib teade |
| zlib | Manustatud inflate/deflate versiooni stringid: 1.3.2 MediaInfo 26.10, 1.2.11 21.03, 1.2.7 0.7.60; curl teatab lisaks 1.3.1 ja 1.2.8 | Kõigi viie versiooni originaalteatised zlib |
| TinyXML-2 | Sobivad kaasaegsed allika sihtmärgid ja binaarne RTTI; kaasatud pärandprojekti, kuid pole iseseisvalt tuvastatud eemaldatud pärandbinaarfailis | Algne Lee Thomason zlib-stiilis teade on säilinud |
| Brian Gladman AES | Sisaldub mõlemas kaasaegses ülesvoolu teegi sihtmärgis koos vastavate lubavate allikateadetega | 1998–2013 levitamise teatis ja lahtiütlus |
| Brian Gladman SHA-1/SHA-2 | Mõlemad kaasaegsed sihtmärgid; SHA-256 ja SHA-512 konstantsed tabelid esinevad mõlemas kaasaegses kahendfailis | 1998–2010 levitamise teatis ja lahtiütlus |
| Brian Gladman HMAC | Nii kaasaegsed sihtmärgid kui ka nende curl/S3 lugejakood | Algne kolme tingimusega teatis, sealhulgas selle alternatiivse litsentsi lõik |
| MD5 | Kaasaegsed allika sihtmärgid; Colin Plumb teostus sätestab selgesõnaliselt avaliku domeeni | Omistamine säilinud |
| Base64 | Markus Ewald päis kõigis kolmes vastavas lähtepuus, krediteerides Bob Withers | Algne autorsuse omistamine säilinud; kvalifikatsioon allpool |
| fmt | 26.10 sihtmärk ja fmt v11 format_error RTTI kahendkoodis | Algne MIT teatis, sealhulgas valikuline erand |
| tfsxml | 26.10 allika sihtmärk | Algne MediaArea MIT teade |
| Android JNI liides | JNI_OnLoad ekspordivad tegelikult mõlemad kaasaegsed DLLs; kaasasolev JNI päis pärineb AOSP | AOSP autoriõigus ja täielik Apache litsents 2.0 |
| libcurl | Tarnitakse x86 kahendfaile; tegelik versiooni eksport; dünaamiliselt kasutatav kaasaegne MediaInfo | Algsed curl teatised 8.11.0 ja 7.47.1 kohta |
| Ametlikud aruannete tõlked | Kõik 38 muutmata CSV allikad MediaInfo v26.10 keelekataloogist; 37 mitteingliskeelsed tabelid on manustatud, samas kui inglise keeles kasutatakse DLL vaikeväärtusi | Sama projekti BSD-2-Clause teade on säilitatud kombineeritud teatises |
| MediaInfo ikoon | Muutmata ametlik mitme pildi ikoon, allika versioon f057dd3649bc8692a83863b67770e22c9b9dd81a | Algne BSD-2-Clause teade ja omistamine |
| libwebp | WebPEncodeLosslessBGRA, WebPFree; 1.1.0; x86 | BSD-3-Clause; PATENTS |

Sobivad allika sihtmärgid loovad kaasamise nendesse ülesvoolu ehituskonfiguratsioonidesse; need ei tõesta, et
iga funktsioon säilib tarnija binaarfailides optimeerimise korral. Sõltuvustele, mille redaktsiooni pole
nendes kahendkoodides salvestatud, täpset versiooni ei nõuta.

### Valikulised komponendid ja süsteemiteegid

- Windows teegiprojektid võimaldavad käitusaegse laadimise libcurl MediaInfo 26.10 ja 21.03 jaoks. MediaInfo
  0.7.60 ehitati MEDIAINFO_LIBCURL_NO-ga; selle kahendfail sisaldab ka puudega toe diagnostikat. Vaataja ei
  avasta, ei ekstrakti ega laadi kunagi selle komplekteeritud versiooni jaoks curl.
- libmms on keelatud kõigis kolmes tarnitud Windows DLLs, mida kinnitavad nende manustatud keelatud
  tugisõnumid. Seda ümber ei jaotata.
- Qt ja wxWidgets kuuluvad valikulistesse GUI järgudesse. Kumbki ei sisaldu selles vaatajas ega nendes DLL
  sõltuvustes. Nende üldised kirjed eemaldati kuvatud litsentsist.
- Graphviz on valikuline käitusaegne konks kaasaegses ülesvoolu koodis. Ühtegi Graphviz DLL ei levitata edasi.
- Ühtegi pistikprogrammi FFmpeg ei levitata edasi.
- MediaInfo DLLs impordib otse ainult KERNEL32.dll. See ei tähenda, et nende staatiliselt lingitud käitusaeg
  ja abikood puuduvad.
- Praegune curl impordib otse WS2_32.dll, bcrypt.dll, ADVAPI32.dll, CRYPT32.dll ja KERNEL32.dll. XP curl
  impordib otse WS2_32.dll, WLDAP32.dll, ADVAPI32.dll ja KERNEL32.dll. Need on Windows komponendid. Nende
  saadavust kontrollib laadur Windows.
- Curl raporteerib Windows Schannel/WinSSL, mitte OpenSSL järgu. Selle teatatud täiendav tihendussõltuvus on
  staatiliselt kaasatud zlib. Selle otseimpordi tabelis ei kuvata täiendavat välist mitte-Windows DLL.
- Vaatajal endal puudub C/C++ käitusaja sõltuvus. Kaasasolevad kolmanda osapoole DLLs sisaldavad nende enda
  kompileeritud käitusaja osi. Windows järgud kasutavad Microsofti tööriistu; puuduvad tõendid, mis nõuaksid
  üldisi libstdc++ või libc++ varude kandeid.
- JPEG kasutab dünaamiliselt laaditud süsteemi GDI+. C# ressursipakkija ja PowerShell on koostamise tööriistad
  ega ole käitusaegsed sõltuvused.

Tavaliseks kohaliku faili kontrollimiseks ei ole vaja MediaArea serverit ega kauglaaditud vormingu andmebaasi.
libcurl kasutab MediaInfo URL sisendite ja potentsiaalselt kaugviidete jaoks toetatud meediumivormingutes.
Selle komplekteerimine ei lisa sellele vaatajale eraldi URL-avamiskäsku.

### Litsentside säilitamine ja piirangud

Ainus hooldatav levitusteade on [license.txt](../license.txt) , kodeeritud kui UTF-8 koos CRLF-ga.
Kontrollitud BSD, curl, zlib, MIT ja Apache'i edasijaotamisklauslid ei nõua füüsiliselt iga DLL kõrval eraldi
teatisefaili; kombineeritud teade on nendega kaasas täitmis- ja levimaterjalides.

Arhiveeritud pakett MediaInfo 0.7.60 kasutab oma versioonipõhist litsentsi ja sisaldab vana GNU Library GPL
teksti. Selle tingimused eristavad sõnaselgelt muutmata binaarset ümberjaotamist muudetud versioonidest; selle
vaataja dünaamiline linkimine ei muuda kaasasolevat DLL. Selle algtingimused ja sellega kaasnev litsentsi
tekst on säilinud. Vaataja jääb MIT-litsentsiga.

Üks ülesvoolu omistamine vajab kvalifikatsiooni: päisel Markus Ewald Base64 pole selgesõnalist luba ega
litsentsiavaldust. MediaArea kirjeldab Bob Withers Base64 rakendamist avaliku domeenina oma seotud MediaConch
dokumentatsioonis, kuid see ei määra iseseisvalt litsentsi iga Ewaldi muudatuse jaoks. Selle päise jaoks pole
litsentsi välja mõeldud. Tarnija täielik kinnitus selle päritolu kohta, täpsed ZenLib versioonid ja curl
arendus commit ei olnud kaasasolevates kahendfailides saadaval. Need punktid takistavad selle laoseisu
käsitlemist tervikliku, sõltumatult sertifitseeritud SBOM-na.

### Peamised allikad

- [MediaInfo edasijagamise tingimused](https://mediaarea.net/en/MediaInfo/License)
- 
  [MediaInfo 26.10 teegi sihtmärk](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Project/MSVC2022/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 21.03 teegi sihtmärk](https://github.com/MediaArea/MediaInfoLib/blob/v21.03/Project/MSVC2015/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 0.7.60 teegi sihtmärk](https://github.com/MediaArea/MediaInfoLib/blob/v0.7.60/Project/MSVC2005/Library/MediaInfoLib.vcproj)
- 
  [Käitusaegne curl laadur](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Source/MediaInfo/Reader/Reader_libcurl.cpp)
- 
  [Komplekteeritud abiallikad ja nende teated](https://github.com/MediaArea/MediaInfoLib/tree/v26.10/Source/ThirdParty)
- [ZenLib teade](https://github.com/MediaArea/ZenLib/blob/master/License.txt)
- [zlib allika teated](https://github.com/madler/zlib/blob/v1.3.2/zlib.h)
- [curl 8.11.0 teade](https://github.com/curl/curl/blob/curl-8_11_0/COPYING)
- [curl 7.47.1 teade](https://github.com/curl/curl/blob/curl-7_47_1/COPYING)
- [Apache litsents 2.0](https://www.apache.org/licenses/LICENSE-2.0)
- [MediaArea Base64 kirjeldus](https://github.com/MediaArea/MediaConch/blob/master/README.md)

Aruande tabelid pärinevad <https://github.com/MediaArea/MediaInfo/tree/v26.10/Source/Resource/Plugin/Language>
-st. Sobiv projekt LICENSE on <https://github.com/MediaArea/MediaInfo/blob/v26.10/LICENSE> .

- [libwebp 1.1.0 COPYING](https://github.com/webmproject/libwebp/blob/v1.1.0/COPYING)
- [libwebp 1.1.0 PATENTS](https://github.com/webmproject/libwebp/blob/v1.1.0/PATENTS)
