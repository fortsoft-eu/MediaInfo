# MediaInfo Viewer

[Čeština](README.cs-CZ.md) | [English (US)](../README.md) | [English (UK)](README.en-GB.md) | [English (Australia)](README.en-AU.md) | [Deutsch](README.de-DE.md) | [Français](README.fr-FR.md) | [Español](README.es-ES.md) | [Italiano](README.it-IT.md) | [Português](README.pt-PT.md) | [Polski](README.pl-PL.md) | [Slovenčina](README.sk-SK.md) | [Dansk](README.da-DK.md) | [Suomi](README.fi-FI.md) | [Íslenska](README.is-IS.md) | [Norsk (bokmål)](README.nb-NO.md) | [Svenska](README.sv-SE.md) | [Türkçe](README.tr-TR.md) | [Eesti](README.et-EE.md) | [Gaeilge](README.ga-IE.md) | [Lietuvių](README.lt-LT.md) | **Latviešu** | [Magyar](README.hu-HU.md) | [Malti](README.mt-MT.md) | [Nederlands](README.nl-NL.md) | [Română](README.ro-RO.md) | [Ελληνικά](README.el-GR.md) | [Bosanski](README.bs-Latn-BA.md) | [Hrvatski](README.hr-HR.md) | [Slovenščina](README.sl-SI.md) | [Crnogorski](README.cnr-Latn-ME.md) | [Беларуская](README.be-BY.md) | [Български](README.bg-BG.md) | [Македонски](README.mk-MK.md) | [Српски](README.sr-Cyrl-RS.md) | [Українська](README.uk-UA.md) | [Русский](README.ru-RU.md)

Vietējais Windows x86 skatītājs MediaInfo.dll pārskatiem. Katram failam ir sava tikai lasāma cilne.

[Kompilēšana un saderība](#kompilēšana) | [Atkarību audits](#atkarības) | [Licence](../license.txt)

## Kompilēšana

Atveriet MediaInfo.sln mapē Visual Studio 2015 ar instalētu rīku kopu Visual C++ v140. Izvēlieties Release | Win32 un izveidojiet risinājumu. Vienīgā lietojumprogrammu platforma ir Win32 (x86).

[PCRE2 10.49](https://github.com/PCRE2Project/pcre2/tree/pcre2-10.49) — UTF-16, statiski saistīts,
BSD-3-Clause. [Pirmkods](../MediaInfo/PCRE2/).
[license.txt](../license.txt).
PCRE2 ir iebūvēta EXE failā, un tai nav nepieciešams atsevišķs DLL fails vai papildu instalēšana.

Izvades:

- Release\MediaInfo.exe
- Debug\MediaInfo.exe

Skatītājs nesaista C vai C++ izpildlaiku, un tam nav nepieciešams atkārtoti izplatāms MSVC. Atlasītajam
MediaInfo.dll var būt savas atkarības.

Ēkai nepieciešams Windows PowerShell un .NET Framework. Šīs ir tikai uzbūves prasības; vietējam izpildāmajam
failam nav nepieciešams ne PowerShell, ne .NET.

### Izplatīšanas pakotne

Pēc Release izveides palaidiet `powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\PackageRelease.ps1`
. Skripts risinājuma direktorijā izveido `MediaInfo-<version>-win32.zip` , izmantojot izpildāmā faila
četrdaļīgo versiju. Arhīvs satur `MediaInfo.exe` un kombinēto `license.txt` tieši tā saknē.

## Saderība

Win32 skatītājs ir paredzēts Windows NT 4.0 APIs lietošanai.

Izpildāmajā failā ir iekļautas trīs x86 MediaInfo bibliotēkas: 26.10 pašreizējai Windows, 21.03 no Windows XP
pakotnes un 0.7.60 no Windows 95–2000 pakotnes. Bibliotēkas arhitektūra pati par sevi nenosaka tās
operētājsistēmas saderību. Skatītājs izmēģina komplektētās bibliotēkas no jaunākās līdz vecākajai un apstājas
pēc pirmās veiksmīgās ielādes un versijas vaicājuma.

Windows 95 pašlaik netiek atbalstīts izpildlaiks.

## Lietošana

- Fails > Atvērt (Ctrl+O) atver Windows faila dialoglodziņu ar vairāku atlasi. Windows Vista un jaunākās
  versijās Atvērt un Saglabāt izmantojiet moderno Common Item Dialog; vecāki Windows izmanto mantotos kopīgos
  dialoglodziņus.
- Velciet vienu vai vairākus failus uz logu, EXE ikonu vai tās saīsni vai norādiet to ceļus komandrindā. Ja
  vairākas instances nav atļautas, faili tiek atvērti jau palaistajā logā.
- Katram atsevišķam normalizētam pilnam ceļam ir viena cilne. Atkārtoti atverot jau atvērtu failu, tiek
  atlasīta tā esošā cilne, nepārlādējot vai nemainot atskaiti, atlasi vai ritināšanas pozīciju. Salīdzinājumos
  netiek ņemts vērā ceļa burtu reģistrs. Vairāku failu atvēršana apstrādā sarakstu secībā un atstāj aktīvu
  pēdējo veiksmīgi apstrādāto failu neatkarīgi no tā, vai tas ir tikko atvērts vai jau atvērts. Virzot kursoru
  virs cilnes galvenes, vietējā rīka padomos tiek parādīts pilns faila ceļš, tostarp tad, ja parādītais faila
  nosaukums ir saīsināts.
- Izvēlnē Fails ir norādīti astoņi pēdējie ielādētie faili tieši virs Exit, starp atdalītājiem. Ieraksti
  parāda tikai numuru un faila nosaukumu. Atlasot ierakstu, tiek atvērts tā saglabātais pilns ceļš vai tiek
  atlasīta esošā cilne; veiksmīga atkārtota atvēršana pārvieto to uz augšu bez dublikātiem. Atlasot nepieejamu
  failu, tiek jautāts, vai noņemt tā pēdējo failu ierakstu. Tiek izmantota vietējā jautājuma ikona un Yes/No
  pogas. Noklusējums ir Yes un noņem ierakstu no izvēlnes un reģistra; Nē to saglabā. Uzvednē ir iekļauts
  pilns ceļš.
- Peles ritenis pārpildītās ciļņu galvenes ritina galvenes joslu par vienu cilni katrā ziņojumā, nemainot
  atlasi vai fokusu.
- Ctrl+Tab un Ctrl+Shift+Tab pārslēgt cilnes; Ctrl+W aizver aktīvo cilni. Vidēji noklikšķinot uz cilnes
  galvenes, šī cilne tiek aizvērta, vienlaikus saglabājot jebkuru citu aktīvo cilni. Fails > Aizvērt visu
  aizver visas cilnes, tostarp rindas pārskatus. Fails > Iziet (Alt+F4) aizver lietojumprogrammu.
- Cilnes galvenes kontekstizvēlnē ir Aizvērt cilni. Iestatījumos ieslēdziet Aizvērt cilnes ar
  dubultklikšķi, lai aizvērtu cilni ar dubultklikšķi uz tās galvenes. Šī opcija pēc noklusējuma ir
  izslēgta un tiek saglabāta.
- Dubultklikšķis pārskata tekstā atlasa vārdu. Trīskāršs klikšķis atlasa loģisku rindu. Vilkšana
  paplašina atlasi pa vārdiem vai rindām.
- Ctrl+A atlasa atskaiti; Ctrl+C to kopē.
- Rediģēt > Atrast (Ctrl+F) meklē aktīvajā pārskata cilnē vai Palīdzības vai Par programmu teksta
  apgabalā atkarībā no tā, kuram logam ir fokuss. Meklēšanas logs saglabā pēdējo izvēlēto avotu, kamēr
  tam ir fokuss. F3 atkārto meklēšanu, bet Shift+F3 maina tās virzienu. Sasniedzot teksta malu,
  meklēšana turpinās no otras malas. Opcijas > Teksta aplaušana attiecas tikai uz aktīvo cilni; atzīme
  mainās atbilstoši atlasītajai cilnei. Meklēšanas logu var minimizēt un mainīt tā platumu; tiek
  atcerēta atrašanās vieta un opcija Vienmēr virspusē. Līdz 30 meklēšanas tekstiem ar opcijām tiek
  saglabāti tikai līdz lietotnes aizvēršanai. Sākuma un beigu opcijas attiecas uz loģiskajām rindām.
  Regulārās izteiksmes izmanto PCRE2 sintaksi. Pārējās izvēlnes Rediģēt komandas attiecas uz aktīvo
  pārskata cilni. Enter sāk meklēšanu; Shift+Enter apgriež izvēlēto virzienu. “Atšķirt lielos un mazos
  burtus” atšķir lielos un mazos burtus; “Meklēt atpakaļ” meklē teksta sākuma virzienā. Vēstures
  ieraksta izvēle atjauno visas piecas meklēšanas opcijas, tostarp regulārās izteiksmes režīma stāvokli;
  “Vienmēr virspusē” ir neatkarīga opcija. “Regulārā izteiksme” atspējo “Rinda sākas ar” un “Rinda
  beidzas ar”. Ja abas rindas malu opcijas ir ieslēgtas, pietiek ar atbilstību vienā malā. “Teksta
  aplaušana” maina tikai attēlojumu.
- Opcijas > Iestatījumi (Ctrl+G) atver vienu preferenču dialoglodziņu MediaInfo un curl ceļiem, atskaites
  fontam, fontu antialiasingam, saskarnes valodai un atskaites valodai. Tukšs DLL ceļš nodrošina automātisku
  atklāšanu.
- Fonta poga parāda saimi, punkta lielumu un stilu un atver standarta Windows fontu dialoglodziņu. Pēc
  noklusējuma tiek atjaunots Consolas vai Courier New, ja Consolas nav pieejams; poga Noklusējums ir
  atspējota, kamēr ir atlasīta noklusējuma vērtība. Lietotāja atlasītie fonti tiek saglabāti bez aizstāšanas
  ar lietojumprogrammas kodu.
- Fontu antialiasing izvēle ir ClearType, kad tiek atbalstīta, GDI un Nav. Sākotnējā izvēle ir
  ClearType, ja tiek atbalstīta, pretējā gadījumā GDI. Fontu iestatījumi attiecas uz pārskatu cilnēm, to
  eksportu attēlos un pārskatu drukāšanu. Palīdzība un Par programmu saglabā savus teksta fontus.
- Palīdzība atver atsevišķu bezmodeļu logu ar savu uzdevumjoslas ierakstu un minimizēšanas pogu. Par ir modāls
  dialogs; tā produkta galvenē ir uzskaitītas visas trīs iegultās DLL versijas.

Fails > Lappuses iestatīšana… atver papīra, orientācijas un piemaļu iestatījumus pašreizējai sesijai.
Drukāt… (Ctrl+P) atver sistēmas drukāšanas dialogu; Windows 11 nodrošina priekšskatījumu, bet Windows 10
un vecākas versijas saglabā klasisko dialogu. Ctrl+P drukā galvenā loga aktīvo cilni vai Palīdzības vai
Par programmu teksta apgabalu atkarībā no tā, kuram logam ir fokuss. Pārskati izmanto izvēlēto pārskata
fontu, Palīdzība sistēmas dialogu fontu, bet Par programmu sava teksta apgabala fontu. Ja nav atvērtu
ciļņu, bet Palīdzība ir atvērta, Lappuses iestatīšana… un Drukāt… paliek pieejamas; Drukāt… drukā
Palīdzību. Palīdzība izmanto galvenā loga drukāšanas dialogu; atkārtots Ctrl+P Palīdzībā izvirza to pašu
dialogu priekšplānā. Garās rindas tiek aplauztas, un teksts sadalīts lappusēs. Drukāšana notiek fonā.

Atvērt mapi… atver failus, kas atrodas tieši atlasītajā mapē, katru savā cilnē. Apakšmapes netiek iekļautas.
Atvērt un Atvērt mapi koplieto pēdējo atlasīto mapi. Eksports atceras atsevišķu mapi, pēc noklusējuma
Dokumenti.

Paplašinātais režīms pārskatā parāda papildu laukus.

Pilna analīze pārbauda visu failu un var aizņemt ilgāku laiku. Šīs pārskata opcijas un Trasēšanas līmenis
pieder katrai cilnei; izmaiņas atsvaidzina tikai aktīvo cilni. Pēdējā manuāli izvēlētā kombinācija tiek
saglabāta jaunām cilnēm un nākamajai palaišanai. Atbilstošs kešatmiņā saglabātais pārskats tiek atkārtoti
izmantots, kamēr fails paliek nemainīgs.

Zināmie formāti, Zināmie kodeki un Zināmie parametri tiek atvērti atsevišķās pārskata cilnēs.

Sākotnējo loga izmēru un atrašanās vietu izvēlas Windows. Iepriekš saglabātais logu izvietojums ignorē šos
noklusējuma iestatījumus vēlākos palaišanas gadījumos.

Statusa joslas kreisajā pusē redzami failu ceļi un ielādes norise, bet labajā – ielādētās MediaInfo.dll
versija. Gari ceļi tiek saīsināti ar daudzpunkti atbilstoši pieejamajai vietai.

## Izveidot galvenes failu

Rīki ir ceturtā izvēlne izvēļņu joslā. Tā komanda Izveidot galvenes failu… atver vienu avota failu neatkarīgi
no pārskatu cilnēm un kopē tā pirmos 524288 baitus (512 KiB). Īsāks fails tiek kopēts pilnībā; tukšs fails
rada tukšu izvadi. Tā ir parasta bināro failu lasīšana bez MediaInfo analīzes vai MediaInfo.dll prasības. Rīks
nemaina pārskatu cilnes vai programmas neseno failu sarakstu.

Pēc izlasīšanas avota faila mapē sākas dialoglodziņš Saglabāt kā un piedāvā video.mp4.header priekš video.mp4:
.header tiek pievienots visam oriģinālajam nosaukumam. Varat mainīt gan nosaukumu, gan mērķa mapi. Atceļot
jebkuru no dialoglodziņiem, izvades fails netiek ierakstīts. Esoša galamērķa aizstāšanai nepieciešams
apstiprinājums. Avots paliek nemainīgs; neveiksmīga saglabāšana saglabā iepriekšējo galamērķi. Atvēršanai un
saglabāšanai tiek izmantoti jaunākie attiecīgajā Windows versijā pieejamie sistēmas dialoglodziņi.

Lietojumprogrammas startēšanas laikā rīks iegūst sākotnējo ievades mapi no Fails > Atvērt. Ja mape nav
saglabāta, sistēma Windows izvēlas sākotnējo atrašanās vietu. Pēc ievades faila atlasīšanas rīks atceras savu
mapi tikai līdz lietojumprogrammas iziešanai, pat ja ir atcelta opcija Saglabāt kā. Tas nemaina mapes, ko
izmanto Atvērt un Eksportēt, un nesaglabā savu mapi lietojumprogrammas iestatījumos. Katrs dialoglodziņš
Saglabāt kā sākas pašlaik atlasītā ievades faila mapē neatkarīgi no iepriekšējā saglabāšanas mērķa.

## Bibliotēku meklēšana

Vispirms tiek izmēģināts saglabāts manuālais ceļš. Ja to nevar ielādēt, automātiskā atklāšana mēģina:

1. MediaInfo.dll blakus izpildāmajam failam, pēc tam katrā vecākdirektorijā līdz diskam vai UNC koplietojiet
   sakni.
2. ProgramFiles, ProgramFiles(x86) un ProgramW6432.
3. LOCALAPPDATA un APPDATA.

Saskaņā ar šīm instalācijas saknēm atklāšanas pārbaudes tiek pārbaudītas MediaInfo, MediaArea\MediaInfo,
MediaArea, MediaArea.net\MediaInfo, Programs\MediaInfo, Programs\MediaArea\MediaInfo. Nelasāmas vietas un
nesaderīgas DLLs tiek izlaistas. Tas rekursīvi neskenē disku.

Ja saderīgs ārējais DLL netiek atrasts, skatītājs izmēģina iegultās versijas šādā secībā: 26.10, 21.03,
0.7.60. Tas vienlaikus izvelk un pārbauda vienu versiju. Kad versija ir veiksmīgi ielādēta, vecākas versijas
netiek ne izvilktas, ne pārbaudītas. Pietiek ar MediaInfo.exe izplatīšanu vien; saderīgam ārējam DLL vienmēr
ir prioritāte, un to var atjaunināt neatkarīgi.

Neveiksmīga manuāla bibliotēkas maiņa saglabā jau ielādēto bibliotēku.

## Atskaišu eksportēšana

Saglabāt kā formāti ir sakārtoti šādi: TXT, BMP, GIF, JPEG, PNG, TIFF un WebP. Neatbalstītie kodētāji tiek
izlaisti gan mūsdienu, gan mantotajos dialoglodziņos.

TXT piedāvā ANSI, UTF-8, UTF-8 ar BOM, UTF-16 BE ar BOM un UTF-16 LE ar BOM. Noklusējums ir otrais ieraksts,
UTF-8 bez BOM. Tiek saglabāts pilns atskaites teksts un tā sākotnējās rindu beigas.

BMP, PNG un TIFF saglabā visas renderētās krāsas; GIF89a saglabā precīzu renderēto paleti, ja attēlam ir ne
vairāk kā 256 krāsas. Eksportēt vienmēr raksta izvēlēto formātu vai ziņo par kļūdu; tas nekad neaizstāj citu
formātu.

## Interfeisa un atskaišu valodas

Iestatījumi (Opcijas > Iestatījumi, Ctrl+G) ietver bibliotēku ceļus, pārskata fontu, fonta nogludināšanu un
valodas. Saskarnei ir 36 varianti, un sākotnēji tā seko Windows valodai. Pārskati vienmēr pēc noklusējuma
izmanto bibliotēkas sākotnējo angļu valodu neatkarīgi no Windows un saskarnes. To maina tikai manuāla izvēle:
angļu valoda, 37 tulkojumi vai sava MediaInfo CSV tabula.

Labi vai Lietot apstiprina izmaiņas; Atcelt atmet gaidošās izmaiņas. Iestatījumos var noteikt cilnes nosaukuma
ierobežojumu (noklusēti 80) un notīrīt neseno failu sarakstu. Gari nosaukumi saglabā sākumu, beigas un
paplašinājumu ar daudzpunkti vidū.

Galvenā loga virsraksts rāda aktīvo failu formā faila nosaukums — MediaInfo. Iestatījumos nosaukuma garumu
virsrakstā var iestatīt atsevišķi no 8 līdz 255 rakstzīmēm (noklusējums 40). Garāki nosaukumi tiek
saīsināti ar to pašu daudzpunkti vidū, saglabājot paplašinājumu. Ja nav atvērtu cilņu, virsraksts ir
MediaInfo.

Pēc noklusējuma ir atļauta tikai viena instance, un turpmākās palaišanas nodod failus atvērtajam logam.
Iestatījumos var atļaut vairākas instances. Ja ir vairāki logi, saglabātā pozīcija tiek atjaunota tikai katras
formas pirmajam logam; pārējiem logiem tiek atjaunots tikai izmērs.

Mainot tikai saskarni, atvērto pārskatu teksts netiek mainīts. Manuāli lietota pārskatu valodas maiņa
atkārtoti ielādē to pārskatus, vienlaikus saglabājot ciļņu secību un MRU secību.

## libcurl

Automātiska curl atklāšanas pārbaude blakus atlasītajam MediaInfo DLL, pēc tam koplietotajam
executable/ancestor, programmu failiem un lietotāja instalēšanas vietām. Ja saderīgs ārējais curl netiek
atrasts, atbilstošā iegultā pašreizējā vai XP versija tiek izvilkta pārbaudītajā katra lietotāja kešatmiņā.
Vecākais MediaInfo 0.7.60 pilnībā apiet curl atklāšanu, ieguvi un ielādi. Tieši atlasīts nederīgs curl noraida
preferences izmaiņas; Trūkst izvēles automātiskās curl, neliedz parasto lokālo failu atskaites.

## Failu nosaukumi un nesenie faili

MRU failu nosaukumi tiek saīsināti tikai tad, ja tie ir garāki par 80 UTF-16 koda vienībām. Vidējā elipsi
saglabā faila nosaukuma sākumu, beigas pirms tā paplašinājuma un pilnu galīgo paplašinājumu; pilni ceļi un
atskaites paliek nemainīgas. Cilņu parakstos tiek izmantots tas pats algoritms ar konfigurējamu noklusējuma
ierobežojumu 80.

Jaunākie faili > Notīrīt nekavējoties notīra gan reāllaika izvēlni MRU, gan tās saglabātos ceļus, vienlaikus
atstājot neskartas visas atvērtās cilnes. Tas nepiemēro vai neapstiprina gaidošās preferences un neiespējo
Lietot. Atcelt vai Escape saglabā notīrīto vēsturi, vienlaikus atmetot neapstiprinātos labojumus. Notīrīt ir
atspējots ikreiz, kad saraksts ir tukšs, un tā statuss tiek atsvaidzināts, kad sarakstu papildina jauni
pārskati. Nekavējoties tiek ziņots par reģistra rakstīšanas kļūmi. Lietojot jaunu cilnes nosaukuma
ierobežojumu, tiek atjaunināta katra atvērtā cilne, atkārtoti neielādējot tās multivides ziņojumu.

## Licence un pārdale

Skatītājs ir licencēts saskaņā ar MIT licenci license.txt.

MediaInfo ir trešās puses komponents. Vienīgais uzturētais izplatīšanas paziņojums ir saknes license.txt, kas
kodēts kā UTF-8 ar CRLF un ietver skatītāju, bibliotēkas, statiski iekļautos komponentus, ikonas un oficiālās
tulkošanas tabulas.

Šis produkts izmanto MediaInfo bibliotēku, autortiesības (c) 2002-2026 MediaArea.net SARL.

- MediaInfo: <https://mediaarea.net/MediaInfo>
- Licence: <https://mediaarea.net/en/MediaInfo/License>
- Windows lejupielādes: <https://mediaarea.net/en/MediaInfo/Download/Windows>

## Atkarības

### Faili

| Resurss | Arhitektūra | Komponenta ziņotā versija | SHA-256 |
| --- | --- | --- | --- |
| Resources/lib/26.10/MediaInfo.dll | x86 | 26.10 | E73027A1577084135425AA013D46C8B2985AD142CCF04F1ADB301B9A9CFB78F8 |
| Resources/lib/21.03/MediaInfo.dll | x86 | 21.03 | EBBF1C371702F3DC39CA23D619C47EDF97E66A95AEABE725284F1402D8F3E58A |
| Resources/lib/0.7.60/MediaInfo.dll | x86 | 0.7.60 | A26C07BCC25FA01A40E6888D02EABD59AA8DB2ABF6F5195481228D3A91D04441 |
| Resources/lib/26.10/libcurl.dll | x86 | 8.11.0-DEV, Schannel, zlib 1.3.1 | DCF136C84F3A4FBEAE2B317FE36D7F11225B56FBA3343AF4BBA8706B3F46F334 |
| Resources/lib/21.03/libcurl.dll | x86 | 7.47.1, WinSSL, zlib 1.2.8 | 21025CAC8089F1E570EE083D8CFD6311C2C51E97094A9FCD8C7A0B544C22CB48 |
| Resources/lib/libwebp.dll | x86 | 1.1.0 | 9986023BB6FF5510A157919F0CD958A94800EC6A1D981F3403A9648BEDFEE575 |

Tabulā norādītie ceļi ir relatīvi pret MediaInfo projekta direktoriju.

Pašreizējā bibliotēka ziņo par izstrādes versiju; tā precīzu avotu commit nevar atgūt no šīs versijas virknes.
Tā pievienotajā paziņojumā ir izmantots augšējais 8.11.0 autortiesību un atļauju teksts, kura licences
noteikumi ir iekļauti arī izstrādes sērijā.

### Iekļautās sastāvdaļas

| Komponents | Pierādījumi un apjoms | Paziņojums |
| --- | --- | --- |
| MediaInfoLib | Faktiskās versijas un nepieciešamie Unikoda eksporti; nemainīti piegādātie binārie faili | Versijai specifiskas oriģinālās autortiesības, tālākizplatīšanas nosacījumi un atruna |
| ZenLib | Statiskas atsauces uz projektu un iegults ZenLib RTTI visos trijos DLLs; precīzas saistītās versijas nav piegādātas | zlib stila ZenLib paziņojums |
| zlib | Iegultās inflate/deflate versiju virknes: 1.3.2 MediaInfo 26.10, 1.2.11 21.03, 1.2.7 0.7.60; curl papildus ziņo 1.3.1 un 1.2.8 | Oriģinālie zlib paziņojumi visām piecām versijām |
| TinyXML-2 | Atbilstoši mūsdienu avota mērķi un binārais RTTI; iekļauts mantotajā projektā, bet nav neatkarīgi identificēts noņemtajā mantotajā binārajā failā | Saglabāts oriģinālais Lee Thomason zlib stila paziņojums |
| Brian Gladman AES | Iekļauts abos modernajos augšupējo bibliotēku mērķos ar atbilstošiem atļaujas avota paziņojumiem | 1998–2013 pārdalīšanas paziņojums un atruna |
| Brian Gladman SHA-1/SHA-2 | Abi mūsdienu mērķi; SHA-256 un SHA-512 konstantes tabulas atrodas abos mūsdienu binārajos failos | 1998–2010 pārdalīšanas paziņojums un atruna |
| Brian Gladman HMAC | Gan mūsdienu mērķi, gan to curl/S3 lasītāja kods | Oriģināls trīs nosacījumu paziņojums, tostarp tā alternatīvās licences punkts |
| MD5 | Mūsdienu avotu mērķi; Colin Plumb ieviešana skaidri norāda uz publisko domēnu | Attiecinājums saglabāts |
| Base64 | Markus Ewald galvene visos trīs atbilstošajos avota kokos, kreditējot Bob Withers | Saglabāts oriģinālais autorības attiecinājums; kvalifikācija zemāk |
| fmt | 26.10 mērķis un fmt v11 format_error RTTI binārā | Sākotnējais MIT paziņojums, tostarp neobligāts izņēmums |
| tfsxml | 26.10 avota mērķis | Sākotnējais MediaArea MIT paziņojums |
| Android JNI saskarne | JNI_OnLoad faktiski eksportē gan mūsdienu DLLs; iekļautā JNI galvene ir no AOSP | AOSP autortiesības un pilnīga Apache licence 2.0 |
| libcurl | Piegādāts x86 binārie faili; faktisko versiju eksports; dinamiski izmanto mūsdienu MediaInfo | Oriģinālie curl paziņojumi par 8.11.0 un 7.47.1 |
| Oficiālie atskaišu tulkojumi | Visi 38 nemodificētie CSV avoti no MediaInfo v26.10 valodu direktorija; 37 ir iegultas tabulas, kas nav angļu valodā, savukārt angļu valodā tiek izmantoti DLL noklusējuma iestatījumi | Apvienotajā paziņojumā saglabāts tas pats projekta BSD-2-Clause paziņojums |
| MediaInfo ikona | Nepārveidota oficiālā vairāku attēlu ikona, avota versija f057dd3649bc8692a83863b67770e22c9b9dd81a | Sākotnējais BSD-2-Clause paziņojums un attiecinājums |
| libwebp | WebPEncodeLosslessBGRA, WebPFree; 1.1.0; x86 | BSD-3-Clause; PATENTS |

Atbilstošie avota mērķi nodrošina iekļaušanu šajās iepriekšējās būvējuma konfigurācijās; tie nepierāda, ka
katra funkcija pārdzīvo optimizāciju piegādātāja binārajos failos. Precīzas versijas pretenzijas netiek
iesniegtas atkarībām, kuru pārskatīšana nav reģistrēta šajos binārajos failos.

### Izvēles komponenti un sistēmas bibliotēkas

- Windows bibliotēkas projekti nodrošina izpildlaika ielādes libcurl MediaInfo 26.10 un 21.03. MediaInfo
  0.7.60 tika izveidots ar MEDIAINFO_LIBCURL_NO; tā binārā versija satur arī atspējošanas atbalsta
  diagnostiku. Skatītājs nekad neatklāj, neizņem vai neielādē curl šai komplektētajai versijai.
- libmms ir atspējots visos trīs piegādātajos Windows DLLs, ko apstiprina to iegultie atspējošanas atbalsta
  ziņojumi. Tas netiek pārdalīts.
- Qt un wxWidgets pieder neobligātām GUI būvēm. Neviens no tiem nav iekļauts šajā skatītājā vai šajās DLL
  atkarībās. Viņu vispārīgie ieraksti tika noņemti no parādītās licences.
- Graphviz ir izvēles izpildlaika āķis modernā augšupējā kodā. Neviens Graphviz DLL netiek izplatīts.
- Neviens spraudnis FFmpeg netiek izplatīts.
- MediaInfo DLLs tieši importē tikai KERNEL32.dll. Tas nenozīmē, ka nav viņu statiski saistītā izpildlaika un
  palīgkoda.
- Pašreizējais curl tieši importē WS2_32.dll, bcrypt.dll, ADVAPI32.dll, CRYPT32.dll un KERNEL32.dll. XP curl
  tieši importē WS2_32.dll, WLDAP32.dll, ADVAPI32.dll un KERNEL32.dll. Tie ir Windows komponenti. To
  pieejamību pārbauda Windows iekrāvējs.
- Curl ziņo Windows Schannel/WinSSL, nevis OpenSSL būvējumu. Tā ziņotā papildu saspiešanas atkarība ir
  statiski iekļauta zlib. Tā tiešā importēšanas tabulā netiek parādīts papildu ārējs, kas nav Windows DLL.
- Pašam skatītājam nav C/C++ izpildlaika atkarības. Piegādātais trešās puses DLLs satur savas kompilētās
  izpildlaika daļas. Windows būvējumos tiek izmantoti Microsoft rīki; nav pierādījumu, kas prasītu vispārīgus
  libstdc++ vai libc++ inventāra ierakstus.
- JPEG izmanto dinamiski ielādētu sistēmu GDI+. C# resursu pakotājs un PowerShell ir veidošanas rīki un nav
  izpildlaika atkarības.

Parastai lokālā faila pārbaudei nav nepieciešams MediaArea serveris vai attāli lejupielādēta formāta datu
bāze. libcurl izmanto MediaInfo URL ievadēm un, iespējams, attālām atsaucēm atbalstītajos multivides formātos.
Sagrupējot to, šim skatītājam netiek pievienota atsevišķa URL atvēršanas komanda.

### Licenču glabāšana un ierobežojumi

Vienīgais uzturētais izplatīšanas paziņojums ir [license.txt](../license.txt) , kas kodēts kā UTF-8 ar CRLF.
Pārbaudītajām BSD, curl, zlib, MIT un Apache tālākizplatīšanas klauzulām nav nepieciešams atsevišķs paziņojuma
fails fiziski blakus katram DLL; apvienotais paziņojums tiem pievienots izpildāmajos un izplatīšanas
materiālos.

Arhivētā MediaInfo 0.7.60 pakotne izmanto savu versijai raksturīgo licenci un ietver veco GNU Library GPL
tekstu. Tās nosacījumi nepārprotami atšķir nemodificētu bināro pārdali no modificētām versijām; šī skatītāja
dinamiskā saistīšana nemaina piegādāto DLL. Tās sākotnējie nosacījumi un pievienotais licences teksts ir
saglabāti. Skatītājam joprojām ir MIT licence.

Vienam augšpus attiecinājumam ir nepieciešama kvalifikācija: galvenē Markus Ewald Base64 nav skaidras atļaujas
vai licences paziņojuma. MediaArea apraksta Bob Withers Base64 ieviešanu kā publisku domēnu saistītajā
MediaConch dokumentācijā, taču tas atsevišķi nenosaka licences piešķiršanu katrai Ewald maiņai. Šai galvenei
licences piešķiršana nav izgudrota. Pilnīgs pārdevēja apstiprinājums par šo izcelsmi, precīzas ZenLib versijas
un curl izstrāde commit nebija pieejams piegādātajos binārajos failos. Šie punkti neļauj uzskatīt šo inventāru
par pilnīgu, neatkarīgi sertificētu SBOM.

### Primārie avoti

- [MediaInfo pārdales noteikumi](https://mediaarea.net/en/MediaInfo/License)
- 
  [MediaInfo 26.10 bibliotēkas mērķis](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Project/MSVC2022/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 21.03 bibliotēkas mērķis](https://github.com/MediaArea/MediaInfoLib/blob/v21.03/Project/MSVC2015/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 0.7.60 bibliotēkas mērķis](https://github.com/MediaArea/MediaInfoLib/blob/v0.7.60/Project/MSVC2005/Library/MediaInfoLib.vcproj)
- 
  [Izpildes laika curl iekrāvējs](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Source/MediaInfo/Reader/Reader_libcurl.cpp)
- 
  [Komplektētie palīgu avoti un to paziņojumi](https://github.com/MediaArea/MediaInfoLib/tree/v26.10/Source/ThirdParty)
- [ZenLib paziņojums](https://github.com/MediaArea/ZenLib/blob/master/License.txt)
- [zlib avota paziņojumi](https://github.com/madler/zlib/blob/v1.3.2/zlib.h)
- [curl 8.11.0 paziņojums](https://github.com/curl/curl/blob/curl-8_11_0/COPYING)
- [curl 7.47.1 paziņojums](https://github.com/curl/curl/blob/curl-7_47_1/COPYING)
- [Apache licence 2.0](https://www.apache.org/licenses/LICENSE-2.0)
- [MediaArea Base64 apraksts](https://github.com/MediaArea/MediaConch/blob/master/README.md)

Pārskatu tabulas nāk no <https://github.com/MediaArea/MediaInfo/tree/v26.10/Source/Resource/Plugin/Language> .
Atbilstošais projekts LICENSE ir <https://github.com/MediaArea/MediaInfo/blob/v26.10/LICENSE> .

- [libwebp 1.1.0 COPYING](https://github.com/webmproject/libwebp/blob/v1.1.0/COPYING)
- [libwebp 1.1.0 PATENTS](https://github.com/webmproject/libwebp/blob/v1.1.0/PATENTS)
