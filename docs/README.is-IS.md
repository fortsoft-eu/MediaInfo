# MediaInfo Viewer

[Čeština](README.cs-CZ.md) | [English (US)](../README.md) | [English (UK)](README.en-GB.md) | [English (Australia)](README.en-AU.md) | [Deutsch](README.de-DE.md) | [Français](README.fr-FR.md) | [Español](README.es-ES.md) | [Italiano](README.it-IT.md) | [Português](README.pt-PT.md) | [Polski](README.pl-PL.md) | [Slovenčina](README.sk-SK.md) | [Dansk](README.da-DK.md) | [Suomi](README.fi-FI.md) | **Íslenska** | [Norsk (bokmål)](README.nb-NO.md) | [Svenska](README.sv-SE.md) | [Türkçe](README.tr-TR.md) | [Eesti](README.et-EE.md) | [Gaeilge](README.ga-IE.md) | [Lietuvių](README.lt-LT.md) | [Latviešu](README.lv-LV.md) | [Magyar](README.hu-HU.md) | [Malti](README.mt-MT.md) | [Nederlands](README.nl-NL.md) | [Română](README.ro-RO.md) | [Ελληνικά](README.el-GR.md) | [Bosanski](README.bs-Latn-BA.md) | [Hrvatski](README.hr-HR.md) | [Slovenščina](README.sl-SI.md) | [Crnogorski](README.cnr-Latn-ME.md) | [Беларуская](README.be-BY.md) | [Български](README.bg-BG.md) | [Македонски](README.mk-MK.md) | [Српски](README.sr-Cyrl-RS.md) | [Українська](README.uk-UA.md) | [Русский](README.ru-RU.md)

Windows x86-skoðari fyrir MediaInfo.dll-skýrslur. Hver skrá hefur sinn eigin skrifvarða flipa.

[Bygging og samhæfi](#þýðing-forritsins) | [Úttekt á háðum söfnum](#hæði) | [Leyfi](../license.txt)

## Þýðing forritsins

Opnaðu MediaInfo.sln í Visual Studio 2015 með Visual C++ v140 verkfærasettinu uppsett. Veldu Release | Win32 og byggðu lausnina. Eini umsóknarvettvangurinn er Win32 (x86).

[PCRE2 10.49](https://github.com/PCRE2Project/pcre2/tree/pcre2-10.49) — UTF-16, tengt statískt, BSD-3-Clause.
[license.txt](../license.txt). [Frumkóði](../MediaInfo/PCRE2/).
PCRE2 er innbyggt í EXE-skrána og þarf hvorki sérstaka DLL-skrá né viðbótaruppsetningu.

Úttak:

- Release\MediaInfo.exe
- Debug\MediaInfo.exe

Áhorfandinn tengir ekki C eða C++ keyrslutímann og þarf ekki endurdreifanlegan MSVC. Valin MediaInfo.dll getur
haft sín eigin ósjálfstæði.

Bygging þarf Windows PowerShell og .NET Framework. Þetta eru eingöngu byggingarkröfur; innfædda keyrslan
krefst hvorki PowerShell né .NET.

### Dreifingarpakki

Eftir að hafa byggt Release, keyrðu
`powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\PackageRelease.ps1` . Handritið býr til
`MediaInfo-<version>-win32.zip` í lausnaskránni, með því að nota fjögurra hluta skráarútgáfu executable.
Skjalasafnið inniheldur `MediaInfo.exe` og sameinaða `license.txt` beint við rót þess.

## Samhæfni

Win32 áhorfandinn er hannaður til að nota Windows NT 4.0 APIs.

Keyrslan inniheldur þrjú x86 MediaInfo söfn: 26.10 fyrir núverandi Windows, 21.03 úr Windows XP pakkanum og
0.7.60 úr Windows 95–2000 pakkanum. Arkitektúr bókasafns einn og sér ákvarðar ekki samhæfni stýrikerfisins.
Áhorfandinn prófar búntsöfnin frá nýjustu til elstu og hættir eftir fyrstu hleðsluna og útgáfufyrirspurnina.

Windows 95 er ekki studdur keyrslutími.

## Notkun

- Skrá > Opna (Ctrl+O) opnar Windows skráargluggann með margvali. Á Windows Vista og síðar, Opna og vista nota
  nútíma Common Item Dialog; eldri Windows nota eldri algengu gluggana.
- Dragðu eina eða fleiri skrár í gluggann, á EXE-táknið eða flýtileið þess, eða gefðu slóðirnar upp á
  skipanalínunni. Ef mörg tilvik eru ekki leyfð opnast skrárnar í glugganum sem er þegar í gangi.
- Hver aðskilin eðlileg full leið hefur einn flipa. Þegar þegar opin skrá er opnuð aftur velur núverandi flipa
  án þess að endurhlaða eða breyta skýrslu, vali eða flettustöðu. Samanburður hunsar slóðstafi. Margar
  skráaropnanir vinna listann í röð og skilja síðustu skrána sem tókst að vinna eftir virka, hvort sem hún er
  nýopnuð eða þegar opin. Með því að sveima yfir flipahaus sýnir alla skráarslóðina í innfæddri tólavísun, þar
  með talið þegar birta skráarnafnið er stytt.
- Skráarvalmyndin sýnir átta skrárnar sem síðast voru hlaðnar beint fyrir ofan Hætta, á milli skilgreina.
  Færslur sýna aðeins númer og skráarheiti. Með því að velja færslu opnast geymda fulla slóð hennar eða velur
  núverandi flipa; Vel heppnuð enduropnun færir það á toppinn án afrita. Með því að velja ótiltæka skrá er
  spurt hvort fjarlægja eigi nýlegar skrár. Innfæddur spurningartákn og Yes/No hnappar eru notaðir. Já er
  sjálfgefið og fjarlægir færsluna úr valmyndinni og skránni; Nei heldur því. Tilkynningin inniheldur alla
  leiðina.
- Músarhjólið yfir yfirfullum flipahausum flettir hausstrimlinum einn flipa fyrir hvern skilaboð án þess að
  breyta vali eða fókus.
- Ctrl+Tab og Ctrl+Shift+Tab skipta um flipa; Ctrl+W lokar virka flipanum. Ef miðsmellt er á flipahaus lokar
  þeim flipa á meðan öðrum virkum flipa er varðveittur. Skrá > Loka öllu lokar öllum flipa, þar á meðal
  skýrslum í biðröð. Skrá > Hætta (Alt+F4) lokar forritinu.
- Samhengisvalmynd flipaheitis inniheldur Loka flipa. Virkjaðu Loka flipum með tvísmelli í
  Kjörstillingum til að loka flipa með því að tvísmella á heiti hans. Valið er sjálfgefið óvirkt og er
  vistað.
- Tvísmellur í skýrslutexta velur orð. Þrír smellir velja röklega línu. Dráttur stækkar valið eftir
  orðum eða línum.
- Ctrl+A velur skýrsluna; Ctrl+C afritar það.
- Breyta > Finna (Ctrl+F) leitar í virka skýrsluflipanum eða textasvæðinu í Hjálp eða Um, eftir því
  hvaða gluggi hefur fókus. Leitarglugginn heldur síðast valda upprunanum meðan hann hefur fókus. F3
  endurtekur leitina og Shift+F3 snýr leitarstefnunni við. Við enda textans heldur leitin áfram frá
  hinum endanum. Valkostir > Línuskipting gildir aðeins fyrir virkan flipa; gátmerkið fylgir völdum
  flipa. Hægt er að lágmarka leitargluggann og breyta breidd hans; staðsetning og stillingin Alltaf efst
  eru vistaðar. Allt að 30 leitartextar og stillingar þeirra eru aðeins geymd þar til forritinu er
  lokað. Upphafs- og endaskilyrði eiga við röklegar línur. Reglulegar segðir nota PCRE2-málskipan. Aðrar
  skipanir í valmyndinni Breyta eiga við virka skýrsluflipann. Enter ræsir leit; Shift+Enter snýr
  valinni stefnu við. „Greina á milli há- og lágstafa“ greinir á milli há- og lágstafa; „Leita
  afturábak“ leitar að upphafi textans. Val á færslu úr leitarsögunni endurheimtir alla fimm
  leitarvalkostina, þar á meðal stillingu reglulegra segða; „Alltaf efst“ er óháður valkostur. „Regluleg
  segð“ gerir „Lína byrjar á“ og „Lína endar á“ óvirka. Ef báðir valkostir fyrir enda línu eru virkir
  nægir samsvörun við annan endann. „Línuskipting“ breytir aðeins birtingunni.
- Valkostir > Kjörstillingar (Ctrl+G) opnar stakan valglugga fyrir MediaInfo og curl slóðir, skýrsluleturgerð,
  hliðrun leturs, viðmótstungumál og skýrslumál. Tóm DLL slóð gerir sjálfvirka uppgötvun kleift.
- Leturhnappurinn sýnir fjölskyldu, punktastærð og stíl og opnar venjulega Windows leturgluggann. Sjálfgefið
  endurheimtir Consolas, eða Courier New ef Consolas er ekki tiltækt; Sjálfgefin hnappur er óvirkur meðan
  sjálfgefið er valið. Notandavalið letur er haldið án þess að skipta út með forritakóða.
- Valkostir fyrir hliðrun leturs eru ClearType þegar þeir eru studdir, GDI og None. Upphafsvalið er
  ClearType þegar það er stutt, annars GDI. Leturstillingar hafa áhrif á skýrsluflipa, myndútflutning
  þeirra og prentun skýrslna. Hjálp og Um halda eigin textaletri.
- Hjálp opnar sérstakan fyrirsætulausan glugga með eigin verkstikufærslu og lágmarkshnappi. Um er valmynd;
  vöruhaus þess sýnir allar þrjár innbyggðu DLL útgáfurnar.

Skrá > Síðuuppsetning… opnar stillingar fyrir pappír, stefnu og spássíur fyrir núverandi keyrslu.
Prenta… (Ctrl+P) opnar prentglugga kerfisins; Windows 11 sýnir forskoðun en Windows 10 og eldri útgáfur
nota hefðbundna gluggann. Ctrl+P prentar virka flipann í aðalglugganum eða textasvæðið í Hjálp eða Um,
eftir því hvaða gluggi hefur fókus. Skýrslur nota valið skýrsluletur, Hjálp notar letur kerfisglugga og
Um notar letur eigin textasvæðis. Ef engir flipar eru opnir en Hjálp er opin eru Síðuuppsetning… og
Prenta… áfram tiltæk; Prenta… prentar hjálpina. Hjálp notar prentglugga aðalgluggans; Ctrl+P aftur í
Hjálp færir sama glugga fremst. Langar línur brotna og textanum er skipt á síður. Prentun fer fram í
bakgrunni.

Opna möppu… opnar skrár sem eru beint í valinni möppu, hverja á sínum flipa. Undirmöppur eru ekki teknar með.
Opna og Opna möppu nota sömu möppuna og síðast var valin. Útflutningur man sína eigin möppu, sjálfgefið Skjöl.

Ítarleg stilling sýnir fleiri reiti í skýrslunni.

Full greining skoðar alla skrána og getur tekið lengri tíma. Þessir skýrsluvalkostir og Rakningarstig tilheyra
hverjum flipa; breyting endurnýjar aðeins virka flipann. Síðasta handvirkt valin samsetning er vistuð fyrir
nýja flipa og næstu ræsingu. Samsvarandi skýrsla í skyndiminni er endurnotuð á meðan skráin er óbreytt.

Þekkt snið, Þekktir kóðarar og Þekktir stikar opnast á eigin skýrsluflipum.

Upphafleg gluggastærð og staðsetning eru valin af Windows. Áður vistuð gluggastaða hnekkir þessum sjálfgefnum
stillingum við síðari opnun.

Vinstra megin á stöðustikunni birtast skráarslóðir og framvinda hleðslu; hægra megin birtist útgáfa þess
MediaInfo.dll sem er hlaðið. Langar slóðir eru styttar með úrfellingarpunktum eftir því plássi sem er tiltækt.

## Búa til hausaskrá

Valmyndin Verkfæri er fjórða valmyndin á valmyndastikunni. Búa til hausaskrá… skipunin hennar opnar eina
frumskrá óháð skýrsluflipa og afritar fyrstu 524288 bæti (512 KiB). Styttri skrá er afrituð í heild; tóm skrá
framleiðir tómt úttak. Þetta er venjulegur lestur tvíundargagna úr skrá, án MediaInfo greiningar eða kröfu um
MediaInfo.dll. Tólið breytir hvorki skýrsluflipum né lista forritsins yfir nýlegar skrár.

Eftir lestur hefst Vista sem valmyndin í upprunaskrármöppunni og stingur upp á video.mp4.header fyrir
video.mp4: .header er bætt við allt upprunalega nafnið. Þú getur breytt bæði nafninu og áfangamöppunni. Ef
hætt er við annan hvorn gluggann skrifar ekkert úttak. Til að skipta út núverandi áfangastað þarf
staðfestingu. Upprunaskráin helst óbreytt; misheppnuð vistun varðveitir fyrri áfangastað. Við opnun og vistun
eru notaðir nýjustu kerfisgluggar sem eru tiltækir í viðkomandi útgáfu Windows.

Við ræsingu forritsins tekur tólið upphaflega inntaksmöppuna frá Skrá > Opna. Ef engin mappa hefur verið
vistuð velur Windows upphafsstaðsetninguna. Eftir að inntaksskrá er valin man tólið aðeins sína eigin möppu
þar til forritið hættir, jafnvel þó að hætt sé við Vista sem. Það breytir hvorki möppunum sem Opna og Flytja
út eru notaðar né vistar sína eigin möppu í forritastillingunum. Sérhver vista sem gluggi byrjar í möppunni í
inntaksskránni sem nú er valin, óháð fyrri vistunarstaðnum.

## Leit að forritasöfnum

Vistað handvirk leið er fyrst prófuð. Ef ekki er hægt að hlaða það reynir sjálfvirk uppgötvun:

1. MediaInfo.dll við hlið keyrslunnar, síðan í hverri yfirmöppu upp að drifinu eða UNC deilirót.
2. ProgramFiles, ProgramFiles(x86) og ProgramW6432.
3. LOCALAPPDATA og APPDATA.

Undir þessum uppsetningarrótum athugar uppgötvun MediaInfo, MediaArea\MediaInfo, MediaArea,
MediaArea.net\MediaInfo, Programs\MediaInfo, Programs\MediaArea\MediaInfo. Ólæsilegum staðsetningum og
ósamrýmanlegum DLLs er sleppt. Það skannar ekki afturkvæmt diskinn.

Ef enginn samhæfur ytri DLL finnst, reynir áhorfandinn innbyggðu útgáfurnar í þessari röð: 26.10, 21.03,
0.7.60. Það dregur út og prófar eina útgáfu í einu. Þegar útgáfa hefur verið hlaðið inn eru eldri útgáfur
hvorki teknar út né prófaðar. Það er nóg að dreifa MediaInfo.exe einum sér; samhæfður ytri DLL hefur alltaf
forgang og hægt er að uppfæra hann sjálfstætt.

Misheppnuð handvirk breyting á bókasafni heldur safninu sem þegar var hlaðið.

## Útflutningur skýrslna

Vista sem sniðin eru í röð TXT, BMP, GIF, JPEG, PNG, TIFF og WebP. Óstuddum kóðara er sleppt úr bæði nútíma og
eldri gluggum.

TXT býður ANSI, UTF-8, UTF-8 með BOM, UTF-16 BE með BOM og UTF-16 LE með BOM. Annar valkosturinn, UTF-8 án
BOM, er sjálfgefinn. Allur texti skýrslunnar og upprunaleg línuskipti varðveitast.

BMP, PNG og TIFF varðveita alla gerðir liti; GIF89a varðveitir nákvæmlega birtu litatöfluna þegar myndin hefur
í mesta lagi 256 liti. Export skrifar alltaf valið snið eða tilkynnir um villu; það kemur aldrei í stað annars
sniðs.

## Viðmót og skýrslutungumál

Kjörstillingar (Valkostir > Kjörstillingar, Ctrl+G) innihalda slóðir safna, letur skýrslu, leturjöfnun og
tungumál. Viðmótið hefur 36 útgáfur og fylgir Windows í upphafi. Skýrslur nota alltaf upprunalega ensku
safnsins sjálfgefið, óháð Windows og viðmóti. Aðeins handvirkt val breytir því: enska, 37 þýðingar eða eigin
MediaInfo CSV-tafla.

Í lagi eða Nota staðfestir breytingar; Hætta við hendir óstaðfestum breytingum. Kjörstillingar leyfa
hámarkslengd flipaheita (sjálfgefið 80) og hreinsun listans yfir nýlegar skrár. Löng heiti halda upphafi, enda
og skráarendingu með úrfellingarmerki í miðju.

Sjálfgefið er aðeins eitt tilvik leyft og síðari ræsingar senda skrár til opna gluggans. Í stillingum má leyfa
mörg tilvik. Ef fleiri gluggar eru leyfðir endurheimtir aðeins fyrsti gluggi hvers eyðublaðs vistaða
staðsetningu; síðari gluggar endurheimta aðeins stærðina.

Ef aðeins viðmótinu er breytt verður texti opinna skýrslna óbreyttur. Breyting á skýrslutungumáli sem er beitt
handvirkt endurhleður skýrslur sínar á meðan fliparöð og MRU röð eru varðveitt.

## libcurl

Sjálfvirk curl uppgötvunarathugun við hliðina á völdum MediaInfo DLL, síðan sameiginlegu executable/ancestor,
forritaskrár og notendauppsetningarstaðsetningar. Ef enginn samhæfur ytri curl finnst, er samsvarandi
innbyggða núverandi eða XP útgáfan dregin út í skyndiminni fyrir hvern notanda. Elsta MediaInfo 0.7.60 framhjá
curl uppgötvun, útdrátt og hleðslu algjörlega. Sérstaklega valinn ógildur curl hafnar kjörbreytingunni; vantar
valfrjálsan sjálfvirkan curl kemur ekki í veg fyrir venjulegar staðbundnar skráarskýrslur.

## Skráarheiti og nýlegar skrár

MRU skráarnöfn eru aðeins stytt þegar þau eru lengri en 80 UTF-16 kóðaeiningar. Miðspor varðveitir upphafið,
lok skráarnafnsins á undan endingunni og endanlega endingu hennar; heildar slóðir og skýrslur haldast
óbreyttar. Skjátextar flipa nota sama reiknirit með stillanlegum sjálfgefnum takmörkunum 80.

Nýlegar skrár > Hreinsa hreinsar strax bæði lifandi MRU valmyndina og vistaðar slóðir hennar á meðan allir
opnir flipar eru óbreyttir. Það á ekki við eða staðfestir óskir í bið og gerir ekki kleift að sækja um. Hætta
við eða flýja varðveitir hreinsaða feril á meðan breytingum sem bíða er fleygt. Hreinsa er óvirkt þegar
listinn er tómur og ástand hans endurnýjast þegar nýjar skýrslur fylla listann. Tilkynnt er um
skráningar-skrifa bilun strax. Með því að nota nýtt flipaheitatakmörk uppfærist hvern opinn flipa án þess að
endurhlaða fjölmiðlaskýrslu hans.

## Leyfi og endurdreifing

Áhorfandinn hefur leyfi samkvæmt MIT leyfinu í license.txt.

MediaInfo er þriðja aðila hluti. Eina dreifingartilkynningin sem er viðhaldið er rót license.txt, kóðuð sem
UTF-8 með CRLF og inniheldur áhorfanda, bókasöfn, kyrrstætt innbyggða íhluti, táknmynd og opinberar
þýðingartöflur.

Þessi vara notar MediaInfo bókasafnið, höfundarrétt (c) 2002-2026 MediaArea.net SARL.

- MediaInfo: <https://mediaarea.net/MediaInfo>
- Leyfi: <https://mediaarea.net/en/MediaInfo/License>
- Windows niðurhal: <https://mediaarea.net/en/MediaInfo/Download/Windows>

## Hæði

### Skrár

| Auðlind | Arkitektúr | Útgáfa tilkynnt af íhlutnum | SHA-256 |
| --- | --- | --- | --- |
| Resources/lib/26.10/MediaInfo.dll | x86 | 26.10 | E73027A1577084135425AA013D46C8B2985AD142CCF04F1ADB301B9A9CFB78F8 |
| Resources/lib/21.03/MediaInfo.dll | x86 | 21.03 | EBBF1C371702F3DC39CA23D619C47EDF97E66A95AEABE725284F1402D8F3E58A |
| Resources/lib/0.7.60/MediaInfo.dll | x86 | 0.7.60 | A26C07BCC25FA01A40E6888D02EABD59AA8DB2ABF6F5195481228D3A91D04441 |
| Resources/lib/26.10/libcurl.dll | x86 | 8.11.0-DEV, Schannel, zlib 1.3.1 | DCF136C84F3A4FBEAE2B317FE36D7F11225B56FBA3343AF4BBA8706B3F46F334 |
| Resources/lib/21.03/libcurl.dll | x86 | 7.47.1, WinSSL, zlib 1.2.8 | 21025CAC8089F1E570EE083D8CFD6311C2C51E97094A9FCD8C7A0B544C22CB48 |
| Resources/lib/libwebp.dll | x86 | 1.1.0 | 9986023BB6FF5510A157919F0CD958A94800EC6A1D981F3403A9648BEDFEE575 |

Slóðirnar í töflunni eru afstæðar við verkefnismöppuna MediaInfo.

Núverandi bókasafn tilkynnir um þróunarútgáfu; Ekki er hægt að endurheimta nákvæmlega uppruna þess commit úr
þeim útgáfustreng. Meðfylgjandi tilkynningu þess notar andstreymis 8.11.0 höfundarréttar- og leyfistextann, en
leyfisskilmálar hans eru einnig til staðar í þróunaröðinni.

### Innbyggðir íhlutir

| Hluti | Sönnunargögn og umfang | Takið eftir |
| --- | --- | --- |
| MediaInfoLib | Raunverulegar útgáfur og nauðsynlegur Unicode útflutningur; óbreytt útgefin tvöfaldur | Útgáfusértækur upprunalegur höfundarréttur, endurdreifingarskilyrði og fyrirvari |
| ZenLib | Statískar verkefnatilvísanir og innbyggð ZenLib RTTI í öllum þremur DLLs; nákvæmlega tengdar endurskoðanir eru ekki til staðar | zlib-stíl ZenLib tilkynning |
| zlib | Innbyggðir inflate/deflate útgáfustrengir: 1.3.2 í MediaInfo 26.10, 1.2.11 í 21.03, 1.2.7 í 0.7.60; curl tilkynnir að auki 1.3.1 og 1.2.8 | Upprunalegar zlib tilkynningar fyrir allar fimm útgáfurnar |
| TinyXML-2 | Samsvörun nútíma upprunamarkmiða og tvöfaldur RTTI; innifalinn í arfleifðarverkefninu, en ekki sjálfstætt auðkenndur í afleita arfleifðartvíundinni | Upprunalegri tilkynningu í Lee Thomason zlib stíl haldið |
| Brian Gladman AES | Innifalið í bæði nútíma andstreymis bókasafnsmiðum, með samsvarandi heimildartilkynningum | 1998–2013 tilkynning um endurdreifingu og fyrirvari |
| Brian Gladman SHA-1/SHA-2 | Bæði nútíma skotmörk; SHA-256 og SHA-512 stöðugar töflur til staðar í báðum nútíma tvítölum | 1998–2010 tilkynning um endurdreifingu og fyrirvari |
| Brian Gladman HMAC | Bæði nútíma skotmörk og curl/S3 lesendakóði þeirra | Upprunaleg þriggja skilyrða tilkynning, þar á meðal málsgrein um varaleyfi |
| MD5 | Nútíma uppspretta skotmörk; Colin Plumb framkvæmd tilgreinir beinlínis almenningseign | Eigninni haldið |
| Base64 | Markus Ewald haus í öllum þremur samsvarandi upprunatré, sem gefur Bob Withers | Upprunalega höfundarrétting haldið; hæfi hér að neðan |
| fmt | 26.10 markmið og fmt v11 format_error RTTI í tvöfalda | Upprunaleg MIT tilkynning, þar á meðal valfrjáls undantekning |
| tfsxml | 26.10 upprunamarkmið | Upprunaleg MediaArea MIT tilkynning |
| Android JNI tengi | JNI_OnLoad er í raun flutt út af bæði nútíma DLLs; meðfylgjandi JNI haus er frá AOSP | AOSP höfundarréttur og fullkomið Apache leyfi 2.0 |
| libcurl | Meðfylgjandi x86 tvöfaldur; raunverulegur útflutningur á útgáfu; virkt notað af nútíma MediaInfo | Upprunalegar curl tilkynningar fyrir 8.11.0 og 7.47.1 |
| Opinberar þýðingar skýrslna | Allar 38 óbreyttar CSV heimildir úr MediaInfo v26.10 tungumálaskránni; 37 töflur sem eru ekki enskar eru innfelldar, en enska notar DLL sjálfgefnar stillingar | Sama verkefni BSD-2-Clause tilkynning varðveitt í sameinuðu tilkynningunni |
| MediaInfo táknmynd | Óbreytt opinbert fjölmyndatákn, endurskoðun uppruna f057dd3649bc8692a83863b67770e22c9b9dd81a | Upprunaleg BSD-2-Clause tilkynning og úthlutun |
| libwebp | WebPEncodeLosslessBGRA, WebPFree; 1.1.0; x86 | BSD-3-Clause; PATENTS |

Samsvörun upprunamarkmiða koma á innlimun í þessar uppstreymisbyggingarstillingar; þau sanna ekki að sérhver
aðgerð lifir af hagræðingu í tvítölvum seljanda. Ekki er gerð krafa um nákvæma útgáfu fyrir ósjálfstæði þar
sem endurskoðun þeirra er ekki skráð í þessum tvöfalda skrám.

### Valfrjálsir íhlutir og kerfissöfn

- Windows bókasafnsverkefnin gera libcurl sem hlaðið er keyrslutíma fyrir MediaInfo 26.10 og 21.03. MediaInfo
  0.7.60 var smíðaður með MEDIAINFO_LIBCURL_NO; tvöfaldur þess inniheldur einnig greiningu fyrir fatlaða
  stuðning. Áhorfandinn uppgötvar aldrei, dregur út eða hleður curl fyrir þá búntútgáfu.
- libmms er óvirkt í öllum þremur meðfylgjandi Windows DLLs, eins og staðfest er af innbyggðum óvirkum
  stuðningsskilaboðum þeirra. Það er ekki endurúthlutað.
- Qt og wxWidgets tilheyra valfrjálsum GUI byggingum. Hvorugt er innifalið í þessum áhorfanda eða í þessum DLL
  ósjálfstæðum. Almennar færslur þeirra voru fjarlægðar úr birtu leyfinu.
- Graphviz er valfrjáls keyrslukrókur í nútíma uppstreymiskóða. Enginn Graphviz DLL er endurdreifður.
- Engin FFmpeg viðbót er endurdreifð.
- MediaInfo DLLs flytur aðeins inn KERNEL32.dll beint. Þetta þýðir ekki að kyrrstöðutengdur keyrslutími þeirra
  og hjálparkóði séu ekki til.
- Núverandi curl flytur beint inn WS2_32.dll, bcrypt.dll, ADVAPI32.dll, CRYPT32.dll og KERNEL32.dll. XP curl
  flytur beint inn WS2_32.dll, WLDAP32.dll, ADVAPI32.dll og KERNEL32.dll. Þetta eru Windows íhlutir. Aðgengi
  þeirra er athugað af Windows hleðslutæki.
- Curl tilkynnir Windows Schannel/WinSSL, ekki OpenSSL byggingu. Tilkynnt viðbótarþjöppunarháð þess er
  statískt með zlib. Engin auka ytri utan Windows DLL birtist í beinum innflutningstöflu þess.
- Áhorfandinn sjálfur er ekki háður C/C++ keyrslutíma. Meðfylgjandi þriðji aðili DLLs inniheldur sína eigin
  samanteknu keyrslutímahluta. Windows smíðin nota Microsoft verkfæri; það eru engar sannanir sem krefjast
  almennra libstdc++ eða libc++ birgðafærslur.
- JPEG notar kraftmikið hlaðið kerfi GDI+. C# auðlindapakkarinn og PowerShell eru byggingarverkfæri og eru
  ekki keyrsluháð.

Venjuleg skoðun á staðbundnum skrám krefst ekki MediaArea netþjóns eða gagnagrunns sem er fjarskammt
niðurhalað. libcurl er notað af MediaInfo fyrir URL inntak og hugsanlega fjartilvísanir á studdum
miðlunarsniðum. Með því að sameina það bætir ekki sérstakri URL-opnunarskipun við þennan áhorfanda.

### Varðveisla leyfa og takmarkanir

Eina dreifingartilkynningin sem er viðhaldið er [license.txt](../license.txt) , kóðað sem UTF-8 með CRLF.
Athuguð BSD, curl, zlib, MIT og Apache endurdreifingarákvæði krefjast ekki sérstakrar tilkynningarskrár
líkamlega við hlið hvers DLL; samanlögð tilkynning fylgir þeim í executable og dreifingarefni.

MediaInfo 0.7.60 pakkinn í geymslu notar sitt eigið útgáfusértæka leyfi og inniheldur gamla GNU Library GPL
textann. Skilmálar þess greina beinlínis óbreytta tvíundirdreifingu frá breyttum útgáfum; Kviktenging hjá
þessum áhorfanda breytir ekki meðfylgjandi DLL. Upprunaleg skilyrði þess og meðfylgjandi leyfistexta eru
geymdir. Áhorfandinn er áfram með MIT leyfi.

Ein uppstreymisúthlutun þarfnast hæfis: Markus Ewald Base64 hausinn hefur enga skýra heimild eða
leyfisyfirlýsingu. MediaArea lýsir Bob Withers Base64 framkvæmdinni sem almenningseign í tengdum MediaConch
skjölum, en það kemur ekki sjálfstætt á leyfisveitingu fyrir hverja Ewald breytingu. Enginn leyfisstyrkur
hefur verið fundinn upp fyrir þann haus. Fullkomin staðfesting söluaðila á upprunanum, nákvæmar ZenLib
endurskoðanir og curl þróun commit voru ekki tiltækar í meðfylgjandi tvöfaldur. Þessir punktar koma í veg
fyrir að meðhöndla þessa birgða sem fullkomið, sjálfstætt vottað SBOM.

### Frumheimildir

- [MediaInfo endurdreifingarskilmálar](https://mediaarea.net/en/MediaInfo/License)
- 
  [MediaInfo 26.10 bókasafnsmarkmið](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Project/MSVC2022/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 21.03 bókasafnsmarkmið](https://github.com/MediaArea/MediaInfoLib/blob/v21.03/Project/MSVC2015/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 0.7.60 bókasafnsmarkmið](https://github.com/MediaArea/MediaInfoLib/blob/v0.7.60/Project/MSVC2005/Library/MediaInfoLib.vcproj)
- 
  [Runtime curl hleðslutæki](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Source/MediaInfo/Reader/Reader_libcurl.cpp)
- 
  [Búnaðaraðstoðarheimildir og tilkynningar þeirra](https://github.com/MediaArea/MediaInfoLib/tree/v26.10/Source/ThirdParty)
- [ZenLib tilkynning](https://github.com/MediaArea/ZenLib/blob/master/License.txt)
- [zlib heimildartilkynningar](https://github.com/madler/zlib/blob/v1.3.2/zlib.h)
- [curl 8.11.0 tilkynning](https://github.com/curl/curl/blob/curl-8_11_0/COPYING)
- [curl 7.47.1 tilkynning](https://github.com/curl/curl/blob/curl-7_47_1/COPYING)
- [Apache leyfi 2.0](https://www.apache.org/licenses/LICENSE-2.0)
- [MediaArea Base64 lýsing](https://github.com/MediaArea/MediaConch/blob/master/README.md)

Skýrslutöflurnar koma frá <https://github.com/MediaArea/MediaInfo/tree/v26.10/Source/Resource/Plugin/Language>
. Samsvörunarverkefnið LICENSE er <https://github.com/MediaArea/MediaInfo/blob/v26.10/LICENSE> .

- [libwebp 1.1.0 COPYING](https://github.com/webmproject/libwebp/blob/v1.1.0/COPYING)
- [libwebp 1.1.0 PATENTS](https://github.com/webmproject/libwebp/blob/v1.1.0/PATENTS)
