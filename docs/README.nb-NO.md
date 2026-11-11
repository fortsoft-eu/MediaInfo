# MediaInfo Viewer

[Čeština](README.cs-CZ.md) | [English (US)](../README.md) | [English (UK)](README.en-GB.md) | [English (Australia)](README.en-AU.md) | [Deutsch](README.de-DE.md) | [Français](README.fr-FR.md) | [Español](README.es-ES.md) | [Italiano](README.it-IT.md) | [Português](README.pt-PT.md) | [Polski](README.pl-PL.md) | [Slovenčina](README.sk-SK.md) | [Dansk](README.da-DK.md) | [Suomi](README.fi-FI.md) | [Íslenska](README.is-IS.md) | **Norsk (bokmål)** | [Svenska](README.sv-SE.md) | [Türkçe](README.tr-TR.md) | [Eesti](README.et-EE.md) | [Gaeilge](README.ga-IE.md) | [Lietuvių](README.lt-LT.md) | [Latviešu](README.lv-LV.md) | [Magyar](README.hu-HU.md) | [Malti](README.mt-MT.md) | [Nederlands](README.nl-NL.md) | [Română](README.ro-RO.md) | [Ελληνικά](README.el-GR.md) | [Bosanski](README.bs-Latn-BA.md) | [Hrvatski](README.hr-HR.md) | [Slovenščina](README.sl-SI.md) | [Crnogorski](README.cnr-Latn-ME.md) | [Беларуская](README.be-BY.md) | [Български](README.bg-BG.md) | [Македонски](README.mk-MK.md) | [Српски](README.sr-Cyrl-RS.md) | [Українська](README.uk-UA.md) | [Русский](README.ru-RU.md)

Windows x86-viser for MediaInfo.dll-rapporter. Hver fil har sin egen skrivebeskyttede fane.

[Bygging og kompatibilitet](#kompilering) | [Kontroll av avhengigheter](#avhengigheter) | [Lisens](../license.txt)

## Kompilering

Åpne MediaInfo.sln i Visual Studio 2015 med Visual C++ v140 verktøysettet installert. Velg Release | Win32 og bygg løsningen. Den eneste applikasjonsplattformen er Win32 (x86).

[PCRE2 10.49](https://github.com/PCRE2Project/pcre2/tree/pcre2-10.49) — UTF-16, statisk lenket, BSD-3-Clause.
[license.txt](../license.txt). [Kildekode](../MediaInfo/PCRE2/).
PCRE2 er innebygd i EXE-filen og krever ingen separat DLL eller installasjon.

Utganger:

- Release\MediaInfo.exe
- Debug\MediaInfo.exe

Seeren kobler ikke til C- eller C++-kjøretiden og trenger ikke en MSVC-redistribuerbar. Den valgte
MediaInfo.dll kan ha sine egne avhengigheter.

Bygg krever Windows PowerShell og .NET Framework. Dette er kun byggekrav; den opprinnelige kjørbare krever
verken PowerShell eller .NET.

### Distribusjonspakke

Etter å ha bygget Release, kjør `powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\PackageRelease.ps1`
. Skriptet oppretter `MediaInfo-<version>-win32.zip` i løsningskatalogen ved å bruke den kjørbare filens
firedelte filversjon. Arkivet inneholder `MediaInfo.exe` og den kombinerte `license.txt` direkte ved roten.

## Kompatibilitet

Win32-visningsprogrammet er designet for å bruke Windows NT 4.0 APIs.

Den kjørbare inkluderer tre x86 MediaInfo-biblioteker: 26.10 for gjeldende Windows, 21.03 fra Windows
XP-pakken og 0.7.60 fra Windows 95–2000-pakken. Et biblioteks arkitektur alene bestemmer ikke dets
operativsystemkompatibilitet. Seeren prøver de medfølgende bibliotekene fra nyeste til eldste og stopper etter
den første vellykkede innlastingen og versjonsspørringen.

Windows 95 er for øyeblikket ikke en støttet kjøretid.

## Bruk

- Fil > Åpne (Ctrl+O) åpner Windows-fildialogen med flere valg. På Windows Vista og senere, åpne og lagre bruk
  den moderne dialogboksen Common Item; eldre Windows bruker de eldre vanlige dialogene.
- Dra én eller flere filer til vinduet, EXE-ikonet eller snarveien, eller oppgi banene på kommandolinjen. Hvis
  flere forekomster ikke er tillatt, åpnes filene i vinduet som allerede kjører.
- Hver distinkte normaliserte fulle bane har én fane. Åpne en allerede åpen fil på nytt velger den
  eksisterende fanen uten å laste inn på nytt eller endre rapporten, utvalget eller rulleposisjonen.
  Sammenligninger ignorerer banebokstaver. Åpninger med flere filer behandler listen i rekkefølge og lar den
  sist behandlede filen være aktiv, enten den er nylig åpnet eller allerede åpen. Holder du musepekeren over
  en faneoverskrift, vises hele filbanen i et innebygd verktøytips, inkludert når det viste filnavnet er
  forkortet.
- Fil-menyen viser de åtte sist lastede filene rett over Avslutt, mellom skilletegn. Oppføringer viser bare et
  nummer og filnavn. Hvis du velger en oppføring, åpnes dens lagrede fulle bane eller den eksisterende fanen
  velges; vellykket gjenåpning flytter den til toppen uten duplikater. Hvis du velger en utilgjengelig fil,
  blir du spurt om du vil fjerne oppføringen for nylige filer. Det opprinnelige spørsmålsikonet og
  Yes/No-knappene brukes. Ja er standard og fjerner oppføringen fra menyen og registret; Nei beholder den.
  Spørringen inkluderer hele banen.
- Musehjulet over overfylte faneoverskrifter ruller overskriften én fane per melding uten å endre valg eller
  fokus.
- Ctrl+Tab og Ctrl+Skift+Tab bryterfaner; Ctrl+W lukker den aktive fanen. Midtklikk på en faneoverskrift
  lukker den fanen mens andre aktive faner bevares. Fil > Lukk alle lukker hver fane, inkludert rapporter i
  kø. Fil > Avslutt (Alt+F4) lukker programmet.
- Kontekstmenyen til en faneoverskrift inneholder Lukk fane. Slå på Lukk faner med dobbeltklikk i
  Preferanser for å lukke en fane ved å dobbeltklikke på overskriften. Valget er som standard av og
  lagres.
- Dobbeltklikk i rapportteksten velger et ord. Trippelklikk velger en logisk linje. Dra for å utvide
  utvalget med ord eller linjer.
- Ctrl+A velger rapporten; Ctrl+C kopierer den.
- Rediger > Søk (Ctrl+F) søker i den aktive rapportfanen eller tekstfeltet i Hjelp eller Om, avhengig av
  hvilket vindu som har fokus. Søkevinduet beholder den sist valgte kilden mens det selv har fokus. F3
  gjentar søket; Skift+F3 snur retningen. Ved tekstens ender fortsetter søket fra motsatt ende.
  Alternativer > Tekstbryting gjelder bare den aktive fanen; haken følger den valgte fanen. Søkevinduet
  kan minimeres og endres i bredden; plasseringen og innstillingen Alltid øverst huskes. Opptil 30
  søketekster med innstillingene deres beholdes bare til programmet avsluttes. Valgene for begynnelse og
  slutt gjelder logiske linjer. Regulære uttrykk bruker PCRE2-syntaks. De øvrige kommandoene i
  Rediger-menyen gjelder den aktive rapportfanen. Enter starter søket; Skift+Enter snur den valgte
  retningen. «Skill mellom store og små bokstaver» skiller mellom store og små bokstaver; «Søk bakover»
  søker mot begynnelsen av teksten. Valg av en historikkoppføring gjenoppretter alle fem søkevalg,
  inkludert innstillingen for regulære uttrykk; «Alltid øverst» er uavhengig. «Regulært uttrykk»
  deaktiverer «Linjen starter med» og «Linjen slutter med». Når begge valgene for linjens ender er
  aktivert, holder det med et treff ved én ende. «Tekstbryting» endrer bare visningen.
- Alternativer > Innstillinger (Ctrl+G) åpner en enkelt preferansedialog for MediaInfo og curl baner,
  rapportfont, skriftkantutjevnelse, grensesnittspråk og rapportspråk. En tom DLL-bane muliggjør automatisk
  oppdagelse.
- Font-knappen viser familie, punktstørrelse og stil og åpner standard Windows skriftdialog. Standard
  gjenoppretter Consolas, eller Courier New hvis Consolas er utilgjengelig; Standard-knappen er deaktivert
  mens standard er valgt. Brukervalgte fonter beholdes uten erstatning med applikasjonskode.
- Valg for skriftkantutjevning er ClearType når de støttes, GDI og Ingen. Det første valget er ClearType
  når det støttes, ellers GDI. Skriftinnstillinger gjelder rapportfaner, bildeeksport av dem og utskrift
  av rapporter. Hjelp og Om beholder sine egne tekstskrifter.
- Hjelp åpner et eget modellløst vindu med egen oppgavelinjeoppføring og minimeringsknapp. Om er en modal
  dialog; produktoverskriften viser alle tre innebygde DLL-versjoner.

Fil > Utskriftsformat… åpner innstillinger for papir, retning og marger for denne økten. Skriv ut…
(Ctrl+P) åpner systemets utskriftsdialog; Windows 11 viser en forhåndsvisning, mens Windows 10 og eldre
beholder den klassiske dialogen. Ctrl+P skriver ut den aktive fanen i hovedvinduet eller tekstfeltet i
Hjelp eller Om, avhengig av hvilket vindu som har fokus. Rapporter bruker den valgte rapportskriften,
Hjelp bruker systemets dialogskrift, og Om bruker skriften i sitt tekstfelt. Hvis ingen faner er åpne,
men Hjelp er åpen, er Utskriftsformat… og Skriv ut… fortsatt tilgjengelige; Skriv ut… skriver ut Hjelp.
Hjelp bruker hovedvinduets utskriftsdialog; Ctrl+P på nytt i Hjelp henter den samme dialogen frem. Lange
linjer brytes og teksten deles i sider. Utskrift foregår i bakgrunnen.

Åpne mappe… åpner filene direkte i den valgte mappen, hver i sin egen fane. Undermapper tas ikke med. Åpne og
Åpne mappe deler den sist valgte mappen. Eksport husker sin egen mappe, som standard Dokumenter.

Avansert modus viser flere felt i rapporten.

Full analyse undersøker hele filen og kan ta lengre tid. Disse rapportalternativene og Sporingsnivå tilhører
hver fane; en endring oppdaterer bare den aktive fanen. Den siste manuelt valgte kombinasjonen lagres for nye
faner og neste oppstart. En samsvarende bufret rapport gjenbrukes så lenge filen forblir uendret.

Kjente formater, Kjente kodeker og Kjente parametere åpnes i egne rapportfaner.

Den opprinnelige vindusstørrelsen og plasseringen velges av Windows. Tidligere lagret vindusplassering
overstyrer disse standardinnstillingene ved senere lanseringer.

Venstre side av statuslinjen viser filbaner og innlastingsfremdrift; høyre side viser versjonen av den
innlastede MediaInfo.dll. Lange baner forkortes med utelatelsesprikker etter tilgjengelig plass.

## Opprett en headerfil

Menyen Verktøy er den fjerde på menylinjen. Dens Opprett en headerfil…-kommando åpner én kildefil uavhengig av
rapportfanene og kopierer de første 524288 byte (512 KiB). En kortere fil kopieres i sin helhet; en tom fil
produserer en tom utdatafil. Dette er vanlig binær fillesing, uten MediaInfo-analyse eller krav om
MediaInfo.dll. Verktøyet lar rapportfaner og programmets liste over siste filer være uendret.

Etter lesing starter dialogboksen Lagre som i kildefilens mappe og foreslår video.mp4.header for video.mp4:
.header legges til hele originalnavnet. Du kan endre både navnet og målmappen. Hvis du avbryter en av
dialogboksene, skrives ingen utdata. Å erstatte en eksisterende destinasjon krever bekreftelse. Kilden forblir
uendret; en mislykket lagring bevarer den forrige destinasjonen. Åpning og lagring bruker de nyeste
systemdialogboksene som er tilgjengelige i denne Windows-versjonen.

Ved oppstart av applikasjonen henter verktøyet den første inndatamappen fra Fil > Åpne. Hvis ingen mappe er
lagret, velger Windows den opprinnelige plasseringen. Etter at en inndatafil er valgt, husker verktøyet sin
egen mappe bare til programmet avsluttes, selv om Lagre som avbrytes. Det endrer verken mappene som brukes av
Åpne og Eksporter eller lagrer sin egen mappe i applikasjonsinnstillingene. Hver Lagre som-dialog starter i
mappen til den valgte inndatafilen, uavhengig av forrige lagringsmål.

## Søk etter biblioteker

En lagret manuell bane prøves først. Hvis den ikke kan lastes, prøver automatisk oppdagelse:

1. MediaInfo.dll ved siden av den kjørbare filen, deretter i hver overordnet katalog opp til stasjonen eller
   UNC deleroten.
2. ProgramFiles, ProgramFiles(x86) og ProgramW6432.
3. LOCALAPPDATA og APPDATA.

Under disse installasjonsrøttene sjekker oppdagelse MediaInfo, MediaArea\MediaInfo, MediaArea,
MediaArea.net\MediaInfo, Programs\MediaInfo, Programs\MediaArea\MediaInfo. Uleselige plasseringer og
inkompatible DLLs hoppes over. Den skanner ikke disken rekursivt.

Hvis ingen kompatibel ekstern DLL blir funnet, prøver seeren de innebygde versjonene i denne rekkefølgen:
26.10, 21.03, 0.7.60. Den trekker ut og tester én versjon om gangen. Når en versjon er lastet inn, blir eldre
versjoner verken pakket ut eller testet. Distribuering av MediaInfo.exe alene er tilstrekkelig; en kompatibel
ekstern DLL har alltid prioritet og kan oppdateres uavhengig.

En mislykket manuell bibliotekendring beholder biblioteket som allerede var lastet.

## Eksport av rapporter

Lagre som-formatene er sortert TXT, BMP, GIF, JPEG, PNG, TIFF og WebP. Kodere som ikke støttes, er utelatt fra
både moderne og eldre dialogbokser.

TXT tilbyr ANSI, UTF-8, UTF-8 med BOM, UTF-16 BE med BOM og UTF-16 LE med BOM. Det andre alternativet, UTF-8
uten BOM, er standard. Hele rapportteksten og de opprinnelige linjeskiftene bevares.

BMP, PNG og TIFF bevarer alle gjengitte farger; GIF89a bevarer den eksakte gjengitte paletten når bildet har
maksimalt 256 farger. Eksport skriver alltid det valgte formatet eller rapporterer en feil; det erstatter
aldri et annet format.

## Grensesnitt og rapportspråk

Preferanser (Alternativer > Preferanser, Ctrl+G) inneholder bibliotekstier, rapportskrift, utjevning og språk.
Grensesnittet har 36 varianter og følger først Windows. Rapporter bruker alltid bibliotekets opprinnelige
engelsk som standard, uavhengig av Windows og grensesnittet. Bare et manuelt valg endrer rapportspråket:
engelsk, 37 oversettelser eller en egen MediaInfo-CSV-tabell.

OK eller Bruk bekrefter endringer; Avbryt forkaster ventende endringer. Preferanser angir grensen for fanenavn
(80 som standard) og tømmer listen over nylige filer. Lange navn beholder begynnelsen, slutten og filtypen med
utelatelsesprikker i midten.

Hovedvinduets tittel viser den aktive filen som filnavn — MediaInfo. I innstillingene kan navnets lengde i
tittelen angis separat til 8–255 tegn (40 som standard). Lengre navn forkortes med de samme
utelatelsesprikkene i midten, og filtypen beholdes. Uten åpne faner er tittelen MediaInfo.

Som standard tillates bare én forekomst, og senere oppstarter sender filer til det åpne vinduet. Flere
forekomster kan tillates i preferansene. Ved flere vinduer gjenopprettes lagret plassering bare for det første
vinduet i hvert skjema; senere vinduer gjenoppretter bare størrelsen.

Hvis du bare endrer grensesnittet, blir teksten i åpne rapporter uendret. En manuelt påført
rapportspråkendring laster inn rapportene på nytt samtidig som tabulatorrekkefølgen og MRU-rekkefølgen
bevares.

## libcurl

Automatiske curl oppdagelseskontroller ved siden av den valgte MediaInfo DLL, deretter de delte
executable/ancestor, programfiler og brukerinstallasjonsplasseringer. Hvis ingen kompatibel ekstern curl blir
funnet, trekkes den samsvarende innebygde gjeldende eller XP-versjonen ut i den sjekkede hurtigbufferen per
bruker. Den eldste MediaInfo 0.7.60 omgår curl oppdagelse, utvinning og lasting fullstendig. En eksplisitt
valgt ugyldig curl avviser preferanseendringen; manglende valgfri automatisk curl forhindrer ikke vanlige
lokale filrapporter.

## Filnavn og nylig brukte filer

MRU filnavn forkortes bare når de er lengre enn 80 UTF-16 kodeenheter. En midterste ellipse bevarer
begynnelsen, slutten av filnavnet før utvidelsen og den komplette siste utvidelsen; fullstendige baner og
rapporter forblir uendret. Fanetekster bruker den samme algoritmen med en konfigurerbar standardgrense på 80.

Nylige filer > Slett sletter umiddelbart både den aktive MRU-menyen og dens lagrede stier mens alle åpne faner
er intakte. Det gjelder eller validerer ikke ventende preferanser og aktiverer ikke Bruk. Cancel or Escape
bevarer den slettede loggen mens den forkaster ventende redigeringer. Slett er deaktivert når listen er tom,
og statusen oppdateres når nye rapporter fyller ut listen. En register-skrivefeil rapporteres umiddelbart. Ved
å bruke en ny fanenavngrense oppdateres hver åpne fane uten å laste inn medierapporten på nytt.

## Lisens og redistribusjon

Seeren er lisensiert under MIT-lisensen i license.txt.

MediaInfo er en tredjepartskomponent. Den eneste vedlikeholdte distribusjonsmeldingen er root license.txt,
kodet som UTF-8 med CRLF og inkluderer visningsprogrammet, biblioteker, statisk integrerte komponenter, ikon
og offisielle oversettelsestabeller.

Dette produktet bruker MediaInfo-biblioteket, Copyright (c) 2002-2026 MediaArea.net SARL.

- MediaInfo: <https://mediaarea.net/MediaInfo>
- Lisens: <https://mediaarea.net/en/MediaInfo/License>
- Windows nedlastinger: <https://mediaarea.net/en/MediaInfo/Download/Windows>

## Avhengigheter

### Filer

| Ressurs | Arkitektur | Versjon rapportert av komponenten | SHA-256 |
| --- | --- | --- | --- |
| Resources/lib/26.10/MediaInfo.dll | x86 | 26.10 | E73027A1577084135425AA013D46C8B2985AD142CCF04F1ADB301B9A9CFB78F8 |
| Resources/lib/21.03/MediaInfo.dll | x86 | 21.03 | EBBF1C371702F3DC39CA23D619C47EDF97E66A95AEABE725284F1402D8F3E58A |
| Resources/lib/0.7.60/MediaInfo.dll | x86 | 0.7.60 | A26C07BCC25FA01A40E6888D02EABD59AA8DB2ABF6F5195481228D3A91D04441 |
| Resources/lib/26.10/libcurl.dll | x86 | 8.11.0-DEV, Schannel, zlib 1.3.1 | DCF136C84F3A4FBEAE2B317FE36D7F11225B56FBA3343AF4BBA8706B3F46F334 |
| Resources/lib/21.03/libcurl.dll | x86 | 7.47.1, WinSSL, zlib 1.2.8 | 21025CAC8089F1E570EE083D8CFD6311C2C51E97094A9FCD8C7A0B544C22CB48 |
| Resources/lib/libwebp.dll | x86 | 1.1.0 | 9986023BB6FF5510A157919F0CD958A94800EC6A1D981F3403A9648BEDFEE575 |

Banene i tabellen er relative til prosjektmappen MediaInfo.

Det nåværende biblioteket rapporterer en utviklingsversjon; dens eksakte kilde commit kan ikke gjenopprettes
fra den versjonsstrengen. Den medfølgende merknaden bruker oppstrøms 8.11.0 copyright- og tillatelsesteksten,
hvis lisensvilkår også finnes i utviklingsserien.

### Innebygde komponenter

| Komponent | Bevis og omfang | Legg merke til |
| --- | --- | --- |
| MediaInfoLib | Faktiske versjoner og nødvendig Unicode-eksport; uendret tilførte binærfiler | Versjonsspesifikk original opphavsrett, redistribusjonsbetingelser og ansvarsfraskrivelse |
| ZenLib | Statiske prosjektreferanser og innebygd ZenLib RTTI i alle tre DLLs; eksakt koblede revisjoner leveres ikke | zlib-stil ZenLib merknad |
| zlib | Innebygde inflate/deflate versjonsstrenger: 1.3.2 i MediaInfo 26.10, 1.2.11 i 21.03, 1.2.7 i 0.7.60; curl rapporterer i tillegg 1.3.1 og 1.2.8 | Originale zlib merknader for alle fem versjonene |
| TinyXML-2 | Matchende moderne kildemål og binær RTTI; inkludert i det gamle prosjektet, men ikke uavhengig identifisert i den fjernede eldre binære filen | Original Lee Thomason zlib-stil varsel beholdt |
| Brian Gladman AES | Inkludert i begge moderne oppstrøms bibliotekmål, med samsvarende tillatte kildemerknader | 1998–2013 omfordelingsvarsel og ansvarsfraskrivelse |
| Brian Gladman SHA-1/SHA-2 | Både moderne mål; SHA-256 og SHA-512 konstanttabeller til stede i begge moderne binærfiler | 1998–2010 omfordelingsvarsel og ansvarsfraskrivelse |
| Brian Gladman HMAC | Både moderne mål og deres curl/S3-leserkode | Opprinnelig varsel om tre tilstander, inkludert avsnittet om alternative lisenser |
| MD5 | Moderne kildemål; Colin Plumb implementering angir eksplisitt offentlig domene | Attribusjon beholdt |
| Base64 | Markus Ewald overskrift i alle tre tilsvarende kildetrær, krediterer Bob Withers | Opprinnelig forfatterattribusjon beholdt; kvalifikasjonen nedenfor |
| fmt | 26.10 mål og fmt v11 format_error RTTI i binæren | Original MIT varsel, inkludert valgfritt unntak |
| tfsxml | 26.10 kildemål | Original MediaArea MIT varsel |
| Android JNI grensesnitt | JNI_OnLoad er faktisk eksportert av både moderne DLLs; den inkluderte JNI-overskriften er fra AOSP | AOSP opphavsrett og fullstendig Apache-lisens 2.0 |
| libcurl | Levert x86 binærfiler; faktiske versjon eksport; dynamisk brukt av moderne MediaInfo | Originale curl merknader for 8.11.0 og 7.47.1 |
| Offisielle rapportoversettelser | Alle 38 umodifiserte CSV kilder fra MediaInfo v26.10 språkkatalogen; 37 ikke-engelske tabeller er innebygd, mens engelsk bruker DLL standardinnstillinger | Samme prosjekt BSD-2-Clause varsel beholdt i den kombinerte kunngjøringen |
| MediaInfo ikon | Uendret offisielt flerbildeikon, kilderevisjon f057dd3649bc8692a83863b67770e22c9b9dd81a | Opprinnelig BSD-2-Clause varsel og attribusjon |
| libwebp | WebPEncodeLosslessBGRA, WebPFree; 1.1.0; x86 | BSD-3-Clause; PATENTS |

De samsvarende kildemålene etablerer inkludering i de oppstrøms byggekonfigurasjonene; de beviser ikke at hver
funksjon overlever optimalisering i leverandørens binære filer. Ingen eksakt versjonskrav er gjort for
avhengigheter hvis revisjon ikke er registrert i disse binære filene.

### Valgfrie komponenter og systembiblioteker

- Windows-biblioteksprosjektene muliggjør kjøretidslastet libcurl for MediaInfo 26.10 og 21.03. MediaInfo
  0.7.60 ble bygget med MEDIAINFO_LIBCURL_NO; dens binære inneholder også diagnostikken for deaktivert støtte.
  Seeren oppdager, trekker ut eller laster aldri inn curl for den medfølgende versjonen.
- libmms er deaktivert i alle tre medfølgende Windows DLLs, som bekreftet av deres innebygde
  deaktiverte-støttemeldinger. Det er ikke omfordelt.
- Qt og wxWidgets tilhører valgfrie GUI-bygg. Verken er inkludert i denne fremviseren eller i disse
  DLL-avhengighetene. Deres generiske oppføringer ble fjernet fra den viste lisensen.
- Graphviz er en valgfri kjøretidskrok i moderne oppstrømskode. Ingen Graphviz DLL er omfordelt.
- Ingen FFmpeg-plugin er omdistribuert.
- MediaInfo DLLs importerer bare KERNEL32.dll direkte. Dette betyr ikke at deres statisk koblede kjøretid og
  hjelpekode er fraværende.
- Gjeldende curl importerer direkte WS2_32.dll, bcrypt.dll, ADVAPI32.dll, CRYPT32.dll og KERNEL32.dll. XP curl
  importerer direkte WS2_32.dll, WLDAP32.dll, ADVAPI32.dll og KERNEL32.dll. Dette er Windows komponenter.
  Tilgjengeligheten deres kontrolleres av Windows-lasteren.
- Curl rapporterer Windows Schannel/WinSSL, ikke en OpenSSL build. Dens rapporterte ekstra
  kompresjonsavhengighet er statisk inkludert zlib. Ingen ekstra ekstern ikke-Windows DLL vises i dens direkte
  importtabell.
- Selve seeren har ingen C/C++ kjøretidsavhengighet. Den medfølgende tredjeparts DLLs inneholder sine egne
  kompilerte kjøretidsdeler. Windows-byggene bruker Microsoft-verktøy; det er ingen bevis som krever generiske
  libstdc++ eller libc++ inventaroppføringer.
- JPEG bruker dynamisk lastet system GDI+. C# ressurspakkeren og PowerShell er byggeverktøy og er ikke
  kjøretidsavhengigheter.

Vanlig lokal filinspeksjon krever ikke en MediaArea-server eller en eksternt nedlastet formatdatabase. libcurl
brukes av MediaInfo for URL innganger og potensielt eksterne referanser i støttede medieformater. Å pakke den
legger ikke til en separat URL-åpningskommando til denne fremviseren.

### Lisenslagring og begrensninger

Den eneste vedlikeholdte distribusjonsmeldingen er [license.txt](../license.txt) , kodet som UTF-8 med CRLF.
De sjekkede BSD, curl, zlib, MIT og Apache redistribusjonsklausulene krever ikke en separat meldingsfil fysisk
ved siden av hver DLL; det kombinerte varselet følger dem i kjørbare og distribusjonsmaterialer.

Den arkiverte MediaInfo 0.7.60-pakken bruker sin egen versjonsspesifikke lisens og inkluderer den gamle GNU
Library GPL-teksten. Dens vilkår skiller uttrykkelig umodifisert binær omfordeling fra modifiserte versjoner;
dynamisk kobling av denne fremviseren endrer ikke den medfølgende DLL. De originale betingelsene og den
tilhørende lisensteksten beholdes. Seeren forblir MIT-lisensiert.

Én oppstrømsattribusjon trenger kvalifisering: Markus Ewald Base64-overskriften har ingen eksplisitt
tillatelse eller lisenserklæring. MediaArea beskriver Bob Withers Base64 implementeringen som offentlig domene
i den relaterte MediaConch dokumentasjonen, men det etablerer ikke uavhengig en lisensbevilgning for hver
Ewald endring. Ingen lisensbevilgning er oppfunnet for den overskriften. En fullstendig leverandørbekreftelse
av den herkomsten, de eksakte ZenLib-revisjonene og curl-utviklingen commit var ikke tilgjengelig i de
medfølgende binærfilene. Disse punktene forhindrer å behandle denne beholdningen som en komplett, uavhengig
sertifisert SBOM.

### Primærkilder

- [MediaInfo omfordelingsvilkår](https://mediaarea.net/en/MediaInfo/License)
- 
  [MediaInfo 26.10 bibliotekmål](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Project/MSVC2022/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 21.03 bibliotekmål](https://github.com/MediaArea/MediaInfoLib/blob/v21.03/Project/MSVC2015/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 0.7.60 bibliotekmål](https://github.com/MediaArea/MediaInfoLib/blob/v0.7.60/Project/MSVC2005/Library/MediaInfoLib.vcproj)
- 
  [Kjøretid curl laster](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Source/MediaInfo/Reader/Reader_libcurl.cpp)
- 
  [Medfølgende hjelpekilder og deres merknader](https://github.com/MediaArea/MediaInfoLib/tree/v26.10/Source/ThirdParty)
- [ZenLib varsel](https://github.com/MediaArea/ZenLib/blob/master/License.txt)
- [zlib kildemerknader](https://github.com/madler/zlib/blob/v1.3.2/zlib.h)
- [curl 8.11.0 varsel](https://github.com/curl/curl/blob/curl-8_11_0/COPYING)
- [curl 7.47.1 varsel](https://github.com/curl/curl/blob/curl-7_47_1/COPYING)
- [Apache-lisens 2.0](https://www.apache.org/licenses/LICENSE-2.0)
- [MediaArea Base64 beskrivelse](https://github.com/MediaArea/MediaConch/blob/master/README.md)

Rapporttabellene kommer fra
<https://github.com/MediaArea/MediaInfo/tree/v26.10/Source/Resource/Plugin/Language> . Samsvarsprosjektet
LICENSE er <https://github.com/MediaArea/MediaInfo/blob/v26.10/LICENSE> .

- [libwebp 1.1.0 COPYING](https://github.com/webmproject/libwebp/blob/v1.1.0/COPYING)
- [libwebp 1.1.0 PATENTS](https://github.com/webmproject/libwebp/blob/v1.1.0/PATENTS)
