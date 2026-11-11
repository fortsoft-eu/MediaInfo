# MediaInfo Viewer

[Čeština](README.cs-CZ.md) | [English (US)](../README.md) | [English (UK)](README.en-GB.md) | [English (Australia)](README.en-AU.md) | [Deutsch](README.de-DE.md) | [Français](README.fr-FR.md) | [Español](README.es-ES.md) | [Italiano](README.it-IT.md) | [Português](README.pt-PT.md) | [Polski](README.pl-PL.md) | [Slovenčina](README.sk-SK.md) | **Dansk** | [Suomi](README.fi-FI.md) | [Íslenska](README.is-IS.md) | [Norsk (bokmål)](README.nb-NO.md) | [Svenska](README.sv-SE.md) | [Türkçe](README.tr-TR.md) | [Eesti](README.et-EE.md) | [Gaeilge](README.ga-IE.md) | [Lietuvių](README.lt-LT.md) | [Latviešu](README.lv-LV.md) | [Magyar](README.hu-HU.md) | [Malti](README.mt-MT.md) | [Nederlands](README.nl-NL.md) | [Română](README.ro-RO.md) | [Ελληνικά](README.el-GR.md) | [Bosanski](README.bs-Latn-BA.md) | [Hrvatski](README.hr-HR.md) | [Slovenščina](README.sl-SI.md) | [Crnogorski](README.cnr-Latn-ME.md) | [Беларуская](README.be-BY.md) | [Български](README.bg-BG.md) | [Македонски](README.mk-MK.md) | [Српски](README.sr-Cyrl-RS.md) | [Українська](README.uk-UA.md) | [Русский](README.ru-RU.md)

Windows x86-fremviser til MediaInfo.dll-rapporter. Hver fil har sin egen skrivebeskyttede fane.

[Bygning og kompatibilitet](#kompilering) | [Kontrol af afhængigheder](#afhængigheder) | [Licens](../license.txt)

## Kompilering

Åbn MediaInfo.sln i Visual Studio 2015 med Visual C++ v140 værktøjssættet installeret. Vælg Release | Win32 og byg løsningen. Den eneste applikationsplatform er Win32 (x86).

[PCRE2 10.49](https://github.com/PCRE2Project/pcre2/tree/pcre2-10.49) — UTF-16, statisk linket, BSD-3-Clause.
[license.txt](../license.txt). [Kildekode](../MediaInfo/PCRE2/).
PCRE2 er indbygget i EXE-filen og kræver ingen separat DLL eller installation.

Udgange:

- Release\MediaInfo.exe
- Debug\MediaInfo.exe

Fremviseren forbinder ikke C- eller C++-runtiden og har ikke brug for en MSVC-redistribuerbar. Den valgte
MediaInfo.dll kan have sine egne afhængigheder.

Bygning kræver Windows PowerShell og .NET Framework. Disse er kun byggekrav; den oprindelige eksekverbare
kræver hverken PowerShell eller .NET.

### Udgivelsespakke

Efter at have bygget Release, kør
`powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\PackageRelease.ps1` . Scriptet opretter
`MediaInfo-<version>-win32.zip` i løsningsbiblioteket ved at bruge den eksekverbare filversion i fire dele.
Arkivet indeholder `MediaInfo.exe` og den kombinerede `license.txt` direkte ved dets rod.

## Kompatibilitet

Win32 fremviseren er designet til at bruge Windows NT 4.0 APIs.

Den eksekverbare indeholder tre x86 MediaInfo biblioteker: 26.10 for nuværende Windows, 21.03 fra Windows XP
pakken og 0.7.60 fra Windows 95–2000 pakken. Et biblioteks arkitektur alene bestemmer ikke dets
operativsystemkompatibilitet. Seeren prøver de medfølgende biblioteker fra nyeste til ældste og stopper efter
den første succesfulde indlæsning og versionsforespørgsel.

Windows 95 er i øjeblikket ikke en understøttet runtime.

## Brug

- Fil > Åbn (Ctrl+O) åbner Windows-fildialogen med flere valg. På Windows Vista og senere, Åbn og Gem brug den
  moderne dialogboks med almindeligt emne; ældre Windows bruger de ældre almindelige dialoger.
- Træk en eller flere filer til vinduet, EXE-ikonet eller dets genvej, eller angiv stierne på kommandolinjen.
  Hvis flere instanser ikke er tilladt, åbnes filerne i det vindue, der allerede kører.
- Hver distinkt normaliseret fuld sti har en fane. Genåbning af en allerede åben fil vælger dens eksisterende
  fane uden at genindlæse eller ændre dens rapport, valg eller rulleposition. Sammenligninger ignorerer
  sti-bogstaver. Åbninger af flere filer behandler listen i rækkefølge og lader den sidst behandlede fil være
  aktiv, uanset om den er nyåbnet eller allerede åben. Ved at holde markøren over en faneoverskrift vises den
  fulde filsti i et indbygget værktøjstip, inklusive når det viste filnavn forkortes.
- Menuen Filer viser de otte senest indlæste filer direkte over Afslut, mellem separatorer. Indgange viser kun
  et nummer og et filnavn. Valg af en post åbner dens gemte fulde sti eller vælger dens eksisterende fane;
  vellykket genåbning flytter den til toppen uden dubletter. Hvis du vælger en utilgængelig fil, bliver du
  spurgt, om du vil fjerne dens seneste-filer. Det oprindelige spørgsmålsikon og Yes/No-knapperne bruges. Ja
  er standard og fjerner posten fra menuen og registreringsdatabasen; Nej beholder den. Prompten inkluderer
  den fulde sti.
- Musehjulet over overfyldte faneoverskrifter ruller overskriftstrimlen én fane pr. besked uden at ændre valg
  eller fokus.
- Ctrl+Tab og Ctrl+Skift+Tab skifte faner; Ctrl+W lukker den aktive fane. Midtklik på en faneoverskrift lukker
  denne fane, mens enhver anden aktiv fane bevares. Filer > Luk alle lukker alle faner, inklusive rapporter i
  kø. Fil > Afslut (Alt+F4) lukker programmet.
- Fanens kontekstmenu indeholder Luk fane. Aktivér Luk faner ved dobbeltklik i Præferencer for at lukke
  en fane ved at dobbeltklikke på dens overskrift. Indstillingen er som standard slået fra og gemmes.
- Dobbeltklik i rapportteksten markerer et ord. Tredobbeltklik markerer en logisk linje. Træk udvider
  markeringen med ord eller linjer.
- Ctrl+A vælger rapporten; Ctrl+C kopierer det.
- Rediger > Søg (Ctrl+F) søger i den aktive rapportfane eller i tekstfeltet i Hjælp eller Om, alt efter
  hvilket vindue der har fokus. Søgevinduet beholder den senest valgte kilde, mens det selv har fokus.
  F3 gentager søgningen; Skift+F3 vender retningen. Ved tekstens ender fortsætter søgningen fra den
  modsatte ende. Indstillinger > Tekstombrydning gælder kun den aktive fane; markeringen følger den
  valgte fane. Søgevinduet kan minimeres og ændres i bredden; placeringen og indstillingen Altid øverst
  huskes. Op til 30 søgetekster med deres indstillinger gemmes kun, indtil programmet lukkes.
  Indstillingerne for start og slutning gælder logiske linjer. Regulære udtryk bruger PCRE2-syntaks. De
  øvrige kommandoer i menuen Rediger gælder den aktive rapportfane. Enter starter søgningen; Skift+Enter
  vender den valgte retning. „Forskel på store og små bogstaver“ skelner mellem store og små bogstaver;
  „Søg bagud“ søger mod tekstens begyndelse. Valg af en historikpost gendanner alle fem
  søgeindstillinger, herunder tilstanden for regulære udtryk; „Altid øverst“ er uafhængig. „Regulært
  udtryk“ deaktiverer „Linjen starter med“ og „Linjen slutter med“. Er begge indstillinger for linjens
  ender slået til, er et match ved én ende nok. „Tekstombrydning“ ændrer kun visningen.
- Indstillinger > Præferencer (Ctrl+G) åbner en enkelt præferencedialog for MediaInfo og curl stier,
  rapportskrifttype, skrifttypeudligning, grænsefladesprog og rapportsprog. En tom DLL-sti muliggør automatisk
  opdagelse.
- Skrifttypeknappen viser familien, punktstørrelsen og stilen og åbner standard Windows skrifttypedialogen.
  Standard gendanner Consolas eller Courier New hvis Consolas er utilgængelig; knappen Standard er
  deaktiveret, mens standard er valgt. Brugervalgte skrifttyper bibeholdes uden erstatning med
  applikationskode.
- Valg af skrifttypeudligning er ClearType, når de understøttes, GDI og Ingen. Det første valg er
  ClearType, når det understøttes, ellers GDI. Skrifttypeindstillinger gælder rapportfaner, deres
  billedeksport og udskrivning af rapporter. Hjælp og Om beholder deres egne tekstskrifttyper.
- Hjælp åbner et separat modelløst vindue med sin egen proceslinjeindgang og minimeringsknap. Om er en modal
  dialog; dens produktoverskrift viser alle tre indlejrede DLL-versioner.

Filer > Sideopsætning… åbner indstillinger for papir, retning og margener for den aktuelle session.
Udskriv… (Ctrl+P) åbner systemets udskriftsdialog; Windows 11 viser en forhåndsvisning, mens Windows 10
og ældre beholder den klassiske dialog. Ctrl+P udskriver den aktive fane i hovedvinduet eller
tekstfeltet i Hjælp eller Om, alt efter hvilket vindue der har fokus. Rapporter bruger den valgte
rapportskrifttype, Hjælp bruger systemets dialogskrifttype, og Om bruger skrifttypen i sit tekstfelt.
Hvis ingen faner er åbne, men Hjælp er åben, er Sideopsætning… og Udskriv… stadig tilgængelige; Udskriv…
udskriver Hjælp. Hjælp bruger hovedvinduets udskriftsdialog; endnu et Ctrl+P i Hjælp bringer den frem.
Lange linjer ombrydes, og teksten opdeles i sider. Udskrivning foregår i baggrunden.

Åbn mappe… åbner filerne direkte i den valgte mappe, hver på sin egen fane. Undermapper medtages ikke. Åbn og
Åbn mappe deler den sidst valgte mappe. Eksport husker sin egen mappe, som standard Dokumenter.

Avanceret tilstand viser flere felter i rapporten.

Fuld analyse undersøger hele filen og kan tage længere tid. Disse rapportmuligheder og Sporingsniveau hører
til hver fane; en ændring opdaterer kun den aktive fane. Den sidst manuelt valgte kombination gemmes til nye
faner og næste start. En matchende cachelagret rapport genbruges, så længe filen forbliver uændret.

Kendte formater, Kendte codecs og Kendte parametre åbnes på deres egne rapportfaner.

Den oprindelige vinduesstørrelse og placering vælges af Windows. Tidligere gemt vinduesplacering tilsidesætter
disse standardindstillinger ved senere lanceringer.

Venstre side af statuslinjen viser filstier og indlæsningsforløb; højre side viser versionen af den indlæste
MediaInfo.dll. Lange stier forkortes med udeladelsesprikker, så de passer til den tilgængelige plads.

## Opret en header-fil

Menuen Værktøjer er den fjerde på menulinjen. Dens Opret en header-fil…-kommando åbner én kildefil uafhængigt
af rapportfanerne og kopierer dens første 524288 bytes (512 KiB). En kortere fil kopieres i sin helhed; en tom
fil producerer et tomt output. Dette er almindelig binær fillæsning uden MediaInfo-analyse eller et krav om
MediaInfo.dll. Værktøjet efterlader rapportfaner og programmets liste over seneste filer uændret.

Efter læsning starter Gem som-dialogen i kildefilens mappe og foreslår video.mp4.header for video.mp4: .header
føjes til det komplette originalnavn. Du kan ændre både navnet og destinationsmappen. Annullering af en af
dialogboksene skriver ikke noget output. Udskiftning af en eksisterende destination kræver bekræftelse. Kilden
forbliver uændret; en mislykket lagring bevarer den forrige destination. Åbning og lagring bruger de nyeste
systemdialogbokse, der er tilgængelige i denne version af Windows.

Ved applikationsstart tager værktøjet sin indledende inputmappe fra Filer > Åbn. Hvis ingen mappe er blevet
gemt, vælger Windows den oprindelige placering. Når en inputfil er valgt, husker værktøjet kun sin egen mappe,
indtil programmet afsluttes, selvom Gem som annulleres. Det ændrer hverken mapperne brugt af Åbn og Eksportér
eller gemmer sin egen mappe i applikationsindstillingerne. Hver Gem som-dialog starter i mappen med den
aktuelt valgte inputfil, uanset den tidligere gemte destination.

## Søgning efter biblioteker

En gemt manuel sti prøves først. Hvis det ikke kan indlæses, forsøger automatisk registrering:

1. MediaInfo.dll ved siden af den eksekverbare, derefter i hver overordnet mappe op til drevet eller UNC dele
   rod.
2. ProgramFiles, ProgramFiles(x86) og ProgramW6432.
3. LOCALAPPDATA og APPDATA.

Under disse installationsrødder kontrollerer opdagelse MediaInfo, MediaArea\MediaInfo, MediaArea,
MediaArea.net\MediaInfo, Programs\MediaInfo, Programs\MediaArea\MediaInfo. Ulæselige placeringer og
inkompatible DLLs springes over. Det scanner ikke disken rekursivt.

Hvis der ikke findes nogen kompatibel ekstern DLL, prøver fremviseren de indlejrede versioner i denne
rækkefølge: 26.10, 21.03, 0.7.60. Den udtrækker og tester én version ad gangen. Når først en version er
indlæst, bliver ældre versioner hverken udtrukket eller testet. At distribuere MediaInfo.exe alene er
tilstrækkeligt; en kompatibel ekstern DLL har altid prioritet og kan opdateres uafhængigt.

En mislykket manuel biblioteksændring bevarer det bibliotek, der allerede var indlæst.

## Eksport af rapporter

Gem som-formaterne er bestilt TXT, BMP, GIF, JPEG, PNG, TIFF og WebP. Ikke-understøttede indkodere er udeladt
fra både moderne og ældre dialogbokse.

TXT tilbyder ANSI, UTF-8, UTF-8 med BOM, UTF-16 BE med BOM og UTF-16 LE med BOM. Den anden mulighed, UTF-8
uden BOM, er standard. Hele rapportteksten og dens oprindelige linjeskift bevares.

BMP, PNG og TIFF bevarer alle gengivne farver; GIF89a bevarer den nøjagtige gengivne palet, når billedet højst
har 256 farver. Eksport skriver altid det valgte format eller rapporterer en fejl; det erstatter aldrig et
andet format.

## Interface- og rapportsprog

Præferencer (Indstillinger > Præferencer, Ctrl+G) indeholder biblioteksstier, rapportskrifttype, udjævning og
sprog. Grænsefladen har 36 varianter og følger først Windows. Rapporter bruger altid bibliotekets oprindelige
engelsk som standard, uafhængigt af Windows og grænsefladen. Kun et manuelt valg ændrer rapportsproget:
engelsk, 37 oversættelser eller en egen MediaInfo-CSV-tabel.

OK eller Anvend bekræfter ændringer; Annuller forkaster ventende ændringer. Præferencer angiver grænsen for
fanenavne (80 som standard) og rydder listen over seneste filer. Lange navne bevarer begyndelsen, slutningen
og filtypen med udeladelsesprikker i midten.

Hovedvinduets titel viser den aktive fil som filnavn — MediaInfo. I indstillingerne kan navnets længde i
titlen indstilles særskilt til 8–255 tegn (40 som standard). Længere navne forkortes med de samme
udeladelsesprikker i midten, og filtypen bevares. Uden åbne faner er titlen MediaInfo.

Som standard tillades kun én instans, og senere starter sender filer til det åbne vindue. Flere instanser kan
tillades i præferencerne. Ved flere vinduer gendannes den gemte placering kun for det første vindue af hver
formular; senere vinduer gendanner kun størrelsen.

Ændring af kun grænsefladen efterlader teksten i åbne rapporter uændret. En manuelt anvendt
rapportsprogændring genindlæser deres rapporter, mens tabulatorrækkefølgen og MRU rækkefølgen bevares.

## libcurl

Automatisk curl opdagelseskontrol ved siden af den valgte MediaInfo DLL, derefter de delte
executable/ancestor, programfiler og brugerinstallationsplaceringer. Hvis der ikke findes nogen kompatibel
ekstern curl, udtrækkes den matchende indlejrede aktuelle eller XP-version i den kontrollerede
per-bruger-cache. Den ældste MediaInfo 0.7.60 omgår curl opdagelse, udtrækning og indlæsning fuldstændigt. En
eksplicit valgt ugyldig curl afviser præferenceændringen; manglende valgfri automatisk curl forhindrer ikke
almindelige lokale filrapporter.

## Filnavne og seneste filer

MRU filnavne forkortes kun, når de er længere end 80 UTF-16 kodeenheder. En midterste ellipse bevarer
begyndelsen, slutningen af filnavnet før dens udvidelse og den komplette sidste udvidelse; fulde stier og
rapporter forbliver uændrede. Fanetekster bruger den samme algoritme med en konfigurerbar standardgrænse på
80.

Seneste filer > Ryd rydder øjeblikkeligt både live-menuen MRU og dens gemte stier, mens alle åbne faner
forbliver intakte. Den anvender eller validerer ikke afventende præferencer og aktiverer ikke Anvend. Annuller
eller Escape bevarer den ryddede historie, mens afventende redigeringer kasseres. Ryd er deaktiveret, når
listen er tom, og dens tilstand opdateres, når nye rapporter udfylder listen. En registreringsfejl rapporteres
med det samme. Anvendelse af en ny grænse for fanenavne opdaterer alle åbne faner uden at genindlæse dens
medierapport.

## Licens og omfordeling

Seeren er licenseret under MIT-licensen i license.txt.

MediaInfo er en tredjepartskomponent. Den eneste vedligeholdte distributionsmeddelelse er root license.txt,
kodet som UTF-8 med CRLF og inkluderer fremviseren, biblioteker, statisk indbyggede komponenter, ikon og
officielle oversættelsestabeller.

Dette produkt bruger MediaInfo-biblioteket, Copyright (c) 2002-2026 MediaArea.net SARL.

- MediaInfo: <https://mediaarea.net/MediaInfo>
- Licens: <https://mediaarea.net/en/MediaInfo/License>
- Windows downloads: <https://mediaarea.net/en/MediaInfo/Download/Windows>

## Afhængigheder

### Filer

| Ressource | Arkitektur | Version rapporteret af komponenten | SHA-256 |
| --- | --- | --- | --- |
| Resources/lib/26.10/MediaInfo.dll | x86 | 26.10 | E73027A1577084135425AA013D46C8B2985AD142CCF04F1ADB301B9A9CFB78F8 |
| Resources/lib/21.03/MediaInfo.dll | x86 | 21.03 | EBBF1C371702F3DC39CA23D619C47EDF97E66A95AEABE725284F1402D8F3E58A |
| Resources/lib/0.7.60/MediaInfo.dll | x86 | 0.7.60 | A26C07BCC25FA01A40E6888D02EABD59AA8DB2ABF6F5195481228D3A91D04441 |
| Resources/lib/26.10/libcurl.dll | x86 | 8.11.0-DEV, Schannel, zlib 1.3.1 | DCF136C84F3A4FBEAE2B317FE36D7F11225B56FBA3343AF4BBA8706B3F46F334 |
| Resources/lib/21.03/libcurl.dll | x86 | 7.47.1, WinSSL, zlib 1.2.8 | 21025CAC8089F1E570EE083D8CFD6311C2C51E97094A9FCD8C7A0B544C22CB48 |
| Resources/lib/libwebp.dll | x86 | 1.1.0 | 9986023BB6FF5510A157919F0CD958A94800EC6A1D981F3403A9648BEDFEE575 |

Stierne i tabellen er relative til projektmappen MediaInfo.

Det aktuelle bibliotek rapporterer en udviklingsversion; dens nøjagtige kilde commit kan ikke gendannes fra
den versionsstreng. Dens medfølgende meddelelse bruger upstream 8.11.0 copyright- og tilladelsesteksten, hvis
licensbetingelser også er til stede i udviklingsserien.

### Indbyggede komponenter

| Komponent | Bevis og omfang | Meddelelse |
| --- | --- | --- |
| MediaInfoLib | Faktiske versioner og påkrævet Unicode-eksport; uændret leverede binære filer | Versionsspecifik original ophavsret, videredistributionsbetingelser og ansvarsfraskrivelse |
| ZenLib | Statiske projektreferencer og indlejret ZenLib RTTI i alle tre DLLs; eksakt linkede revisioner leveres ikke | zlib-stil ZenLib meddelelse |
| zlib | Indlejrede inflate/deflate versionsstrenge: 1.3.2 i MediaInfo 26.10, 1.2.11 i 21.03, 1.2.7 i 0.7.60; curl rapporterer desuden 1.3.1 og 1.2.8 | Originale zlib meddelelser for alle fem versioner |
| TinyXML-2 | Matchende moderne kildemål og binære RTTI; inkluderet i legacy-projektet, men ikke uafhængigt identificeret i den strippede legacy-binære | Original Lee Thomason zlib-stil meddelelse bevaret |
| Brian Gladman AES | Inkluderet i begge moderne upstream-biblioteksmål, med matchende tilladelige kildemeddelelser | 1998–2013 omfordelingsmeddelelse og ansvarsfraskrivelse |
| Brian Gladman SHA-1/SHA-2 | Både moderne mål; SHA-256 og SHA-512 konstanttabeller til stede i begge moderne binære filer | 1998–2010 omfordelingsmeddelelse og ansvarsfraskrivelse |
| Brian Gladman HMAC | Både moderne mål og deres curl/S3 læsekode | Oprindelig meddelelse med tre betingelser, herunder dens alternative licensparagraf |
| MD5 | Moderne kildemål; Colin Plumb implementering angiver eksplicit offentligt domæne | Tilskrivning bibeholdt |
| Base64 | Markus Ewald header i alle tre tilsvarende kildetræer, kreditering Bob Withers | Den oprindelige forfatterskabstilskrivning bevares; kvalifikation nedenfor |
| fmt | 26.10 mål og fmt v11 format_error RTTI i binær | Original MIT meddelelse, inklusive valgfri undtagelse |
| tfsxml | 26.10 kildemål | Original MediaArea MIT meddelelse |
| Android JNI interface | JNI_OnLoad eksporteres faktisk af både moderne DLLs; den medfølgende JNI header er fra AOSP | AOSP copyright og komplet Apache-licens 2.0 |
| libcurl | Leveret x86 binære filer; faktiske version eksport; dynamisk brugt af moderne MediaInfo | Originale curl meddelelser for 8.11.0 og 7.47.1 |
| Officielle rapportoversættelser | Alle 38 umodificerede CSV kilder fra sprogbiblioteket MediaInfo v26.10; 37 ikke-engelske tabeller er indlejret, mens engelsk bruger DLL standardindstillinger | Samme projekt BSD-2-Clause meddelelse bevaret i den kombinerede meddelelse |
| MediaInfo ikon | Uændret officielt multibillede-ikon, kilderevision f057dd3649bc8692a83863b67770e22c9b9dd81a | Original BSD-2-Clause meddelelse og tilskrivning |
| libwebp | WebPEncodeLosslessBGRA, WebPFree; 1.1.0; x86 | BSD-3-Clause; PATENTS |

De matchende kildemål etablerer inklusion i disse opstrøms build-konfigurationer; de beviser ikke, at hver
funktion overlever optimering i leverandørens binære filer. Der stilles ikke krav om nøjagtig version for
afhængigheder, hvis revision ikke er registreret i disse binære filer.

### Valgfrie komponenter og systembiblioteker

- Windows biblioteksprojekterne muliggør runtime-loaded libcurl for MediaInfo 26.10 og 21.03. MediaInfo 0.7.60
  blev bygget med MEDIAINFO_LIBCURL_NO; dens binære indhold indeholder også diagnosticeringen af deaktiveret
  understøttelse. Seeren opdager, udtrækker eller indlæser aldrig curl for den medfølgende version.
- libmms er deaktiveret i alle tre medfølgende Windows DLLs, som bekræftet af deres indlejrede
  deaktiverede-supportmeddelelser. Det omfordeles ikke.
- Qt og wxWidgets tilhører valgfri GUI builds. Hverken er inkluderet i denne fremviser eller i disse DLL
  afhængigheder. Deres generiske poster blev fjernet fra den viste licens.
- Graphviz er en valgfri runtime-hook i moderne upstream-kode. Ingen Graphviz DLL er omfordelt.
- Intet FFmpeg-plugin er omdistribueret.
- MediaInfo DLLs importerer kun direkte KERNEL32.dll. Dette betyder ikke, at deres statisk forbundne runtime
  og hjælpekode mangler.
- Nuværende curl importerer direkte WS2_32.dll, bcrypt.dll, ADVAPI32.dll, CRYPT32.dll og KERNEL32.dll. XP curl
  importerer direkte WS2_32.dll, WLDAP32.dll, ADVAPI32.dll og KERNEL32.dll. Disse er Windows komponenter.
  Deres tilgængelighed kontrolleres af Windows loaderen.
- Curl rapporterer Windows Schannel/WinSSL, ikke en OpenSSL build. Dens rapporterede yderligere
  kompressionsafhængighed er statisk inkluderet zlib. Ingen yderligere ekstern ikke-Windows DLL vises i dens
  direkte importtabel.
- Selve fremviseren har ingen C/C++ runtime-afhængighed. Den medfølgende tredjeparts DLLs indeholder deres
  egne kompilerede runtime-dele. Windows-bygningerne bruger Microsoft-værktøjer; der er ingen beviser, der
  kræver generiske libstdc++ eller libc++ beholdningsposter.
- JPEG bruger dynamisk indlæst system GDI+. C# ressourcepakkeren og PowerShell er byggeværktøjer og er ikke
  runtime-afhængigheder.

Almindelig lokal filinspektion kræver ikke en MediaArea-server eller en eksternt downloadet formatdatabase.
libcurl bruges af MediaInfo til URL input og potentielt fjernreferencer i understøttede medieformater.
Bundling tilføjer ikke en separat URL-åbningskommando til denne fremviser.

### Licenslagring og begrænsninger

Den eneste vedligeholdte distributionsmeddelelse er [license.txt](../license.txt) , kodet som UTF-8 med CRLF.
De afkrydsede BSD, curl, zlib, MIT og Apache omfordelingsklausuler kræver ikke en separat meddelelsesfil
fysisk ved siden af hver DLL; den kombinerede meddelelse ledsager dem i det eksekverbare og
distributionsmateriale.

Den arkiverede MediaInfo 0.7.60-pakke bruger sin egen versionsspecifikke licens og inkluderer den gamle GNU
Library GPL-tekst. Dens vilkår adskiller udtrykkeligt umodificeret binær omfordeling fra modificerede
versioner; dynamiske links fra denne fremviser ændrer ikke den medfølgende DLL. Dens originale betingelser og
medfølgende licenstekst bibeholdes. Seeren forbliver MIT-licenseret.

Én upstream-tilskrivning kræver kvalifikation: Markus Ewald Base64-headeren har ingen eksplicit tilladelse
eller licenserklæring. MediaArea beskriver Bob Withers Base64 implementeringen som offentligt domæne i dens
relaterede MediaConch dokumentation, men det etablerer ikke selvstændigt en licenstildeling for hver
Ewald-ændring. Der er ikke opfundet nogen licensbevilling til den overskrift. En komplet leverandørbekræftelse
af denne herkomst, de nøjagtige ZenLib-revisioner og curl-udviklingen commit var ikke tilgængelig i de
medfølgende binære filer. Disse punkter forhindrer at behandle denne beholdning som en komplet, uafhængigt
certificeret SBOM.

### Primære kilder

- [MediaInfo omfordelingsbetingelser](https://mediaarea.net/en/MediaInfo/License)
- 
  [MediaInfo 26.10 biblioteksmål](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Project/MSVC2022/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 21.03 biblioteksmål](https://github.com/MediaArea/MediaInfoLib/blob/v21.03/Project/MSVC2015/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 0.7.60 biblioteksmål](https://github.com/MediaArea/MediaInfoLib/blob/v0.7.60/Project/MSVC2005/Library/MediaInfoLib.vcproj)
- 
  [Runtime curl loader](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Source/MediaInfo/Reader/Reader_libcurl.cpp)
- 
  [Medfølgende hjælpekilder og deres meddelelser](https://github.com/MediaArea/MediaInfoLib/tree/v26.10/Source/ThirdParty)
- [ZenLib meddelelse](https://github.com/MediaArea/ZenLib/blob/master/License.txt)
- [zlib kildebemærkninger](https://github.com/madler/zlib/blob/v1.3.2/zlib.h)
- [curl 8.11.0 meddelelse](https://github.com/curl/curl/blob/curl-8_11_0/COPYING)
- [curl 7.47.1 meddelelse](https://github.com/curl/curl/blob/curl-7_47_1/COPYING)
- [Apache-licens 2.0](https://www.apache.org/licenses/LICENSE-2.0)
- [MediaArea Base64 beskrivelse](https://github.com/MediaArea/MediaConch/blob/master/README.md)

Rapporttabellerne kommer fra
<https://github.com/MediaArea/MediaInfo/tree/v26.10/Source/Resource/Plugin/Language> . Det matchende projekt
LICENSE er <https://github.com/MediaArea/MediaInfo/blob/v26.10/LICENSE> .

- [libwebp 1.1.0 COPYING](https://github.com/webmproject/libwebp/blob/v1.1.0/COPYING)
- [libwebp 1.1.0 PATENTS](https://github.com/webmproject/libwebp/blob/v1.1.0/PATENTS)
