# MediaInfo Viewer

[Čeština](README.cs-CZ.md) | [English (US)](../README.md) | [English (UK)](README.en-GB.md) | [English (Australia)](README.en-AU.md) | [Deutsch](README.de-DE.md) | [Français](README.fr-FR.md) | [Español](README.es-ES.md) | [Italiano](README.it-IT.md) | [Português](README.pt-PT.md) | [Polski](README.pl-PL.md) | [Slovenčina](README.sk-SK.md) | [Dansk](README.da-DK.md) | [Suomi](README.fi-FI.md) | [Íslenska](README.is-IS.md) | [Norsk (bokmål)](README.nb-NO.md) | [Svenska](README.sv-SE.md) | [Türkçe](README.tr-TR.md) | [Eesti](README.et-EE.md) | [Gaeilge](README.ga-IE.md) | [Lietuvių](README.lt-LT.md) | [Latviešu](README.lv-LV.md) | [Magyar](README.hu-HU.md) | [Malti](README.mt-MT.md) | **Nederlands** | [Română](README.ro-RO.md) | [Ελληνικά](README.el-GR.md) | [Bosanski](README.bs-Latn-BA.md) | [Hrvatski](README.hr-HR.md) | [Slovenščina](README.sl-SI.md) | [Crnogorski](README.cnr-Latn-ME.md) | [Беларуская](README.be-BY.md) | [Български](README.bg-BG.md) | [Македонски](README.mk-MK.md) | [Српски](README.sr-Cyrl-RS.md) | [Українська](README.uk-UA.md) | [Русский](README.ru-RU.md)

Native Windows x86-viewer voor MediaInfo.dll-rapporten. Elk bestand krijgt een eigen tabblad dat alleen kan
worden gelezen.

[Bouwen en compatibiliteit](#compileren) | [Controle van afhankelijkheden](#afhankelijkheden) | [Licentie](../license.txt)

## Compileren

Open MediaInfo.sln in Visual Studio 2015 met de Visual C++ v140 toolset geïnstalleerd. Kies Release | Win32 en bouw de oplossing. Het enige applicatieplatform is Win32 (x86).

[PCRE2 10.49](https://github.com/PCRE2Project/pcre2/tree/pcre2-10.49) — UTF-16, statisch gekoppeld,
BSD-3-Clause. [Broncode](../MediaInfo/PCRE2/).
[license.txt](../license.txt).
PCRE2 is in het EXE-bestand ingebouwd en vereist geen afzonderlijke DLL of extra installatie.

Uitgangen:

- Release\MediaInfo.exe
- Debug\MediaInfo.exe

De viewer koppelt de C- of C++-runtime niet en heeft geen MSVC-herdistribueerbare versie nodig. De
geselecteerde MediaInfo.dll kan zijn eigen afhankelijkheden hebben.

Voor het bouwen zijn Windows PowerShell en .NET Framework vereist. Dit zijn alleen bouwvereisten; het native
uitvoerbare bestand vereist noch PowerShell, noch .NET.

### Distributiepakket

Nadat je Release hebt gebouwd, voer je
`powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\PackageRelease.ps1` uit. Het script maakt
`MediaInfo-<version>-win32.zip` in de oplossingsmap, met behulp van de vierdelige bestandsversie van het
uitvoerbare bestand. Het archief bevat `MediaInfo.exe` en de gecombineerde `license.txt` direct in de root.

## Compatibiliteit

De Win32-viewer is ontworpen voor het gebruik van Windows NT 4.0 APIs.

Het uitvoerbare bestand bevat drie x86 MediaInfo bibliotheken: 26.10 voor de huidige Windows, 21.03 uit het
Windows XP pakket en 0.7.60 uit het Windows 95–2000 pakket. De architectuur van een bibliotheek alleen bepaalt
niet de compatibiliteit met het besturingssysteem. De viewer probeert de gebundelde bibliotheken van nieuw
naar oud en stopt na de eerste succesvolle laad- en versiequery.

Windows 95 is momenteel geen ondersteunde runtime.

## Gebruik

- Bestand > Openen (Ctrl+O) opent het Windows bestandsdialoogvenster met meervoudige selectie. Op Windows
  Vista en later gebruiken Openen en Opslaan het moderne Common Item Dialog; oudere Windows gebruiken de oude
  algemene dialoogvensters.
- Sleep een of meer bestanden naar het venster, het EXE-pictogram of de snelkoppeling, of geef de paden op via
  de opdrachtregel. Als meerdere exemplaren niet zijn toegestaan, worden de bestanden in het al geopende
  venster geopend.
- Elk afzonderlijk genormaliseerd volledig pad heeft één tabblad. Als u een reeds geopend bestand opnieuw
  opent, wordt het bestaande tabblad geselecteerd zonder het rapport, de selectie of de schuifpositie opnieuw
  te laden of te wijzigen. Bij vergelijkingen wordt geen rekening gehouden met hoofdletters en kleine letters.
  Bij het openen van meerdere bestanden wordt de lijst op volgorde verwerkt en blijft het laatste succesvol
  verwerkte bestand actief, ongeacht of het nieuw is geopend of al is geopend. Als u de muisaanwijzer op een
  tabbladkop plaatst, wordt het volledige bestandspad weergegeven in een eigen knopinfo, ook wanneer de
  weergegeven bestandsnaam is ingekort.
- Het menu Bestand toont de acht meest recent geladen bestanden direct boven Afsluiten, tussen
  scheidingstekens. Invoer toont alleen een nummer en bestandsnaam. Als u een item selecteert, wordt het
  opgeslagen volledige pad geopend of wordt het bestaande tabblad geselecteerd; succesvol heropenen verplaatst
  het naar de top zonder duplicaten. Als u een niet-beschikbaar bestand selecteert, wordt u gevraagd of de
  vermelding met recente bestanden moet worden verwijderd. Er wordt gebruik gemaakt van het eigen
  vraagpictogram en de Yes/No-knoppen. Ja is de standaardinstelling en verwijdert de vermelding uit het menu
  en het register; Nee behoudt het. De prompt bevat het volledige pad.
- Met het muiswiel over overlopende tabbladkoppen schuift u één tabblad per bericht door de koptekststrook
  zonder de selectie of focus te wijzigen.
- Ctrl+Tab en Ctrl+Shift+Tab schakellipjes; Ctrl+W sluit het actieve tabblad. Als u met de middelste muisknop
  op een tabbladkop klikt, wordt dat tabblad gesloten terwijl alle andere actieve tabbladen behouden blijven.
  Bestand > Alles sluiten sluit elk tabblad, inclusief rapporten in de wachtrij. Bestand > Afsluiten (Alt+F4)
  sluit de toepassing.
- Het snelmenu van een tabbladkop bevat Tabblad sluiten. Schakel Tabbladen sluiten met dubbelklikken in
  bij Voorkeuren om een tabblad te sluiten door op de kop te dubbelklikken. Deze optie staat standaard
  uit en wordt opgeslagen.
- Dubbelklikken in de rapporttekst selecteert een woord. Driemaal klikken selecteert een logische regel.
  Slepen breidt de selectie uit met woorden of regels.
- Ctrl+A selecteert het rapport; Ctrl+C kopieert het.
- Bewerken > Zoeken (Ctrl+F) zoekt in het actieve rapporttabblad of het tekstvak in Help of Info,
  afhankelijk van welk venster de focus heeft. Het zoekvenster behoudt de laatst gekozen bron zolang het
  zelf de focus heeft. F3 herhaalt de zoekopdracht; Shift+F3 keert de richting om. Aan het einde van de
  tekst gaat het zoeken verder vanaf het andere uiteinde. Opties > Automatische terugloop geldt alleen
  voor het actieve tabblad; het vinkje volgt het geselecteerde tabblad. Het zoekvenster kan worden
  geminimaliseerd en in de breedte worden aangepast; de positie en de instelling Altijd bovenop worden
  onthouden. Maximaal 30 zoekteksten met hun opties blijven alleen bewaard totdat de toepassing wordt
  afgesloten. De begin- en eindopties gelden voor logische regels. Reguliere expressies gebruiken
  PCRE2-syntaxis. De overige opdrachten in het menu Bewerken gelden voor het actieve rapporttabblad.
  Enter start het zoeken; Shift+Enter keert de gekozen richting om. "Hoofdlettergevoelig" maakt
  onderscheid tussen hoofdletters en kleine letters; "Achteruit zoeken" zoekt naar het begin van de
  tekst. Een keuze uit de geschiedenis herstelt alle vijf zoekopties, ook de stand van de modus voor
  reguliere expressies; "Altijd bovenop" staat hier los van. "Reguliere expressie" schakelt "Regel
  begint met" en "Regel eindigt op" uit. Als beide opties voor de regeluiteinden aanstaan, volstaat een
  overeenkomst aan één uiteinde. "Automatische terugloop" verandert alleen de weergave.
- Opties > Voorkeuren (Ctrl+G) opent één dialoogvenster met voorkeuren voor MediaInfo en curl paden,
  rapportlettertype, lettertype-anti-aliasing, interfacetaal en rapporttaal. Een leeg DLL pad maakt
  automatische detectie mogelijk.
- De lettertypeknop geeft de familie, puntgrootte en stijl weer en opent het standaard Windows
  lettertypedialoogvenster. Standaard wordt Consolas hersteld, of Courier New als Consolas niet beschikbaar
  is; de knop Standaard is uitgeschakeld terwijl de standaard is geselecteerd. Door de gebruiker geselecteerde
  lettertypen blijven behouden zonder vervanging door toepassingscode.
- Keuzes voor lettertype-anti-aliasing zijn ClearType indien ondersteund, GDI en Geen. De initiële keuze
  is ClearType indien ondersteund, anders GDI. Lettertype-instellingen gelden voor rapporttabbladen, hun
  afbeeldingsuitvoer en het afdrukken van rapporten. Help en Info behouden hun eigen tekstlettertypen.
- Help opent een apart modelloos venster met een eigen taakbalkinvoer en minimaliseerknop. Over is een modale
  dialoog; de productkop vermeldt alle drie de ingebedde DLL-versies.

Bestand > Pagina-instelling… opent de instellingen voor papier, afdrukstand en marges voor de huidige
sessie. Afdrukken… (Ctrl+P) opent het afdrukvenster van het systeem; Windows 11 toont een
afdrukvoorbeeld, terwijl Windows 10 en ouder het klassieke venster behouden. Ctrl+P drukt het actieve
tabblad van het hoofdvenster of het tekstvak in Help of Info af, afhankelijk van welk venster de focus
heeft. Rapporten gebruiken het gekozen rapportlettertype, Help het systeemlettertype voor
dialoogvensters en Info het lettertype van het eigen tekstvak. Als er geen tabbladen open zijn maar Help
wel open is, blijven Pagina-instelling… en Afdrukken… beschikbaar; Afdrukken… drukt Help af. Help
gebruikt het afdrukvenster van het hoofdvenster; opnieuw Ctrl+P in Help brengt hetzelfde venster naar de
voorgrond. Lange regels worden afgebroken en de tekst wordt over pagina’s verdeeld. Afdrukken gebeurt op
de achtergrond.

Map openen… opent de bestanden die zich direct in de geselecteerde map bevinden, elk op een eigen tabblad.
Submappen worden niet meegenomen. Openen en Map openen delen de laatst geselecteerde map. Export onthoudt een
eigen map, standaard Documenten.

De geavanceerde modus toont extra velden in het rapport.

Volledige analyse onderzoekt het hele bestand en kan langer duren. Deze rapportopties en Traceringsniveau
horen bij elk tabblad; een wijziging vernieuwt alleen het actieve tabblad. De laatste handmatig gekozen
combinatie wordt bewaard voor nieuwe tabbladen en de volgende start. Een overeenkomend in de cache opgeslagen
rapport wordt hergebruikt zolang het bestand ongewijzigd blijft.

Bekende bestandsindelingen, Bekende codecs en Bekende parameters worden op eigen rapporttabbladen geopend.

De initiële venstergrootte en -locatie worden geselecteerd met Windows. Eerder opgeslagen vensterplaatsing
overschrijft deze standaardwaarden bij latere lanceringen.

Links op de statusbalk staan bestandspaden en de voortgang van het laden; rechts staat de versie van de
geladen MediaInfo.dll. Lange paden worden met een weglatingsteken ingekort tot de beschikbare ruimte.

## Headerbestand maken

Het menu Extra is het vierde menu op de menubalk. De opdracht Headerbestand maken… opent één bronbestand,
onafhankelijk van de rapporttabbladen, en kopieert de eerste 524288 bytes (512 KiB). Een korter bestand wordt
volledig gekopieerd; een leeg bestand produceert een lege uitvoer. Dit is het gewone lezen van binaire
bestanden, zonder MediaInfo-analyse of een vereiste voor MediaInfo.dll. De tool laat rapporttabbladen en de
lijst met recente bestanden van het programma ongewijzigd.

Na het lezen start het dialoogvenster Opslaan als in de map van het bronbestand en wordt video.mp4.header voor
video.mp4 voorgesteld: .header wordt toegevoegd aan de volledige originele naam. U kunt zowel de naam als de
doelmap wijzigen. Als u een van beide dialoogvensters annuleert, wordt er geen uitvoer geschreven. Voor het
vervangen van een bestaande bestemming is bevestiging vereist. De bron blijft ongewijzigd; bij een mislukte
opslag blijft de vorige bestemming behouden. Voor openen en opslaan worden de modernste systeemdialoogvensters
gebruikt die in die Windows-versie beschikbaar zijn.

Bij het opstarten van de toepassing haalt het hulpprogramma de oorspronkelijke invoermap van Bestand > Openen.
Als er geen map is opgeslagen, kiest Windows de oorspronkelijke locatie. Nadat een invoerbestand is
geselecteerd, onthoudt het hulpprogramma zijn eigen map alleen totdat de toepassing wordt afgesloten, zelfs
als Opslaan als wordt geannuleerd. Het verandert noch de mappen die worden gebruikt door Openen en Exporteren,
noch slaat het zijn eigen map op in de applicatie-instellingen. Elk dialoogvenster Opslaan als begint in de
map van het momenteel geselecteerde invoerbestand, ongeacht de vorige opslagbestemming.

## Bibliotheken zoeken

Er wordt eerst geprobeerd een opgeslagen handmatig pad te gebruiken. Als het niet kan worden geladen, probeert
de automatische detectie het volgende:

1. MediaInfo.dll naast het uitvoerbare bestand en vervolgens in elke bovenliggende map tot aan de schijf of
   UNC gedeelde root.
2. ProgramFiles, ProgramFiles(x86) en ProgramW6432.
3. LOCALAPPDATA en APPDATA.

Onder deze installatiewortels controleert de detectie MediaInfo, MediaArea\MediaInfo, MediaArea,
MediaArea.net\MediaInfo, Programs\MediaInfo, Programs\MediaArea\MediaInfo. Onleesbare locaties en
incompatibele DLLs worden overgeslagen. De schijf wordt niet recursief gescand.

Als er geen compatibele externe DLL wordt gevonden, probeert de kijker de ingebedde versies in deze volgorde:
26.10, 21.03, 0.7.60. Het extraheert en test één versie tegelijk. Zodra een versie succesvol is geladen,
worden oudere versies niet meer uitgepakt of getest. Alleen het verspreiden van MediaInfo.exe is voldoende;
een compatibele externe DLL heeft altijd voorrang en kan onafhankelijk worden bijgewerkt.

Bij een mislukte handmatige bibliotheekwijziging blijft de bibliotheek behouden die al was geladen.

## Rapport exporteren

De formaten Opslaan als zijn gerangschikt in de volgorde TXT, BMP, GIF, JPEG, PNG, TIFF en WebP.
Niet-ondersteunde encoders worden weggelaten uit zowel moderne als oudere dialoogvensters.

TXT biedt ANSI, UTF-8, UTF-8 met BOM, UTF-16 BE met BOM en UTF-16 LE met BOM. De tweede optie, UTF-8 zonder
BOM, is de standaard. De volledige rapporttekst en de oorspronkelijke regeleinden blijven behouden.

BMP, PNG en TIFF behouden alle weergegeven kleuren; GIF89a behoudt het exacte gerenderde palet wanneer de
afbeelding maximaal 256 kleuren heeft. Export schrijft altijd het geselecteerde formaat of rapporteert een
fout; het vervangt nooit een ander formaat.

## Interface- en rapporttalen

Voorkeuren (Opties > Voorkeuren, Ctrl+G) bevatten bibliotheekpaden, rapportlettertype, anti-aliasing en talen.
De interface heeft 36 varianten en volgt aanvankelijk Windows. Rapporten gebruiken standaard altijd het
oorspronkelijke Engels van de bibliotheek, onafhankelijk van Windows en de interface. Alleen een handmatige
keuze wijzigt de rapporttaal: Engels, 37 vertalingen of een eigen MediaInfo-CSV-tabel.

OK of Toepassen bevestigt wijzigingen; Annuleren verwerpt openstaande wijzigingen. Voorkeuren stellen de
limiet voor tabnamen in (standaard 80) en wissen de lijst met recente bestanden. Lange namen behouden begin,
einde en extensie met een weglatingsteken in het midden.

Standaard is slechts één exemplaar toegestaan en worden bestanden bij opnieuw starten naar het open venster
gestuurd. In de voorkeuren kunnen meerdere exemplaren worden toegestaan. Bij meerdere vensters herstelt alleen
het eerste venster van elk formulier de opgeslagen positie; latere vensters herstellen alleen de grootte.

Als u alleen de interface wijzigt, blijft de tekst van geopende rapporten ongewijzigd. Door een handmatig
aangebrachte wijziging in de rapporttaal worden de rapporten opnieuw geladen, terwijl de tabvolgorde en de
MRU-volgorde behouden blijven.

## libcurl

Automatische curl-detectiecontroles naast de geselecteerde MediaInfo DLL, vervolgens de gedeelde
executable/ancestor, programmabestanden en gebruikersinstallatielocaties. Als er geen compatibele externe curl
wordt gevonden, wordt de overeenkomende ingebedde huidige of XP-versie geëxtraheerd naar de gecontroleerde
cache per gebruiker. De oudste MediaInfo 0.7.60 omzeilt het ontdekken, extraheren en laden van curl volledig.
Een expliciet geselecteerde ongeldige curl wijst de voorkeurswijziging af; Het ontbreken van de optionele
automatische curl verhindert gewone rapporten over lokale bestanden niet.

## Bestandsnamen en recente bestanden

MRU bestandsnamen worden alleen ingekort als ze langer zijn dan 80 UTF-16 code-eenheden. Een middelste ellips
behoudt het begin, het einde van de bestandsnaam vóór de extensie en de volledige uiteindelijke extensie;
volledige paden en rapporten blijven ongewijzigd. Tabbijschriften gebruiken hetzelfde algoritme met een
configureerbare standaardlimiet van 80.

Recente bestanden > Wissen wist onmiddellijk zowel het live MRU-menu als de opgeslagen paden, terwijl alle
geopende tabbladen intact blijven. Er worden geen voorkeuren toegepast of gevalideerd, en Toepassen is niet
ingeschakeld. Annuleren of Ontsnappen bewaart de gewiste geschiedenis terwijl openstaande bewerkingen worden
genegeerd. Wissen wordt uitgeschakeld wanneer de lijst leeg is, en de status wordt vernieuwd wanneer nieuwe
rapporten de lijst vullen. Een schrijffout in het register wordt onmiddellijk gemeld. Door een nieuwe
tabnaamlimiet toe te passen, wordt elk geopend tabblad bijgewerkt zonder het mediarapport opnieuw te laden.

## Licentie en herdistributie

De kijker heeft een licentie onder de MIT-licentie in license.txt.

MediaInfo is een component van derden. De enige onderhouden distributiekennisgeving is root license.txt,
gecodeerd als UTF-8 met CRLF en inclusief de viewer, bibliotheken, statisch ingebouwde componenten, iconen en
officiële vertaaltabellen.

Dit product maakt gebruik van de MediaInfo-bibliotheek, Copyright (c) 2002-2026 MediaArea.net SARL.

- MediaInfo: <https://mediaarea.net/MediaInfo>
- Licentie: <https://mediaarea.net/en/MediaInfo/License>
- Windows downloads: <https://mediaarea.net/en/MediaInfo/Download/Windows>

## Afhankelijkheden

### Bestanden

| Bron | Architectuur | Versie gerapporteerd door de component | SHA-256 |
| --- | --- | --- | --- |
| Resources/lib/26.10/MediaInfo.dll | x86 | 26.10 | E73027A1577084135425AA013D46C8B2985AD142CCF04F1ADB301B9A9CFB78F8 |
| Resources/lib/21.03/MediaInfo.dll | x86 | 21.03 | EBBF1C371702F3DC39CA23D619C47EDF97E66A95AEABE725284F1402D8F3E58A |
| Resources/lib/0.7.60/MediaInfo.dll | x86 | 0.7.60 | A26C07BCC25FA01A40E6888D02EABD59AA8DB2ABF6F5195481228D3A91D04441 |
| Resources/lib/26.10/libcurl.dll | x86 | 8.11.0-DEV, Schannel, zlib 1.3.1 | DCF136C84F3A4FBEAE2B317FE36D7F11225B56FBA3343AF4BBA8706B3F46F334 |
| Resources/lib/21.03/libcurl.dll | x86 | 7.47.1, WinSSL, zlib 1.2.8 | 21025CAC8089F1E570EE083D8CFD6311C2C51E97094A9FCD8C7A0B544C22CB48 |
| Resources/lib/libwebp.dll | x86 | 1.1.0 | 9986023BB6FF5510A157919F0CD958A94800EC6A1D981F3403A9648BEDFEE575 |

De paden in de tabel zijn relatief ten opzichte van de projectmap MediaInfo.

De huidige bibliotheek rapporteert een ontwikkelingsversie; de exacte bron commit kan niet worden hersteld uit
die versiereeks. De begeleidende kennisgeving maakt gebruik van de upstream 8.11.0 copyright- en
toestemmingstekst, waarvan de licentievoorwaarden ook aanwezig zijn in de ontwikkelingsserie.

### Ingebouwde componenten

| Onderdeel | Bewijs en reikwijdte | Kennisgeving |
| --- | --- | --- |
| MediaInfoLib | Werkelijke versies en vereiste Unicode-exports; onveranderd geleverde binaire bestanden | Versiespecifiek origineel copyright, herdistributievoorwaarden en disclaimer |
| ZenLib | Statische projectreferenties en ingebedde ZenLib RTTI in alle drie DLLs; exacte gekoppelde revisies niet meegeleverd | zlib-stijl ZenLib kennisgeving |
| zlib | Ingebedde inflate/deflate versiereeksen: 1.3.2 in MediaInfo 26.10, 1.2.11 in 21.03, 1.2.7 in 0.7.60; curl rapporteert bovendien 1.3.1 en 1.2.8 | Originele zlib-kennisgevingen voor alle vijf versies |
| TinyXML-2 | Matchen van moderne brondoelen en binaire RTTI; opgenomen in het oude project, maar niet onafhankelijk geïdentificeerd in het gestripte oude binaire bestand | Originele kennisgeving in Lee Thomason zlib-stijl behouden |
| Brian Gladman AES | Opgenomen in beide moderne upstream-bibliotheekdoelen, met bijpassende tolerante bronvermeldingen | 1998–2013 herdistributiekennisgeving en disclaimer |
| Brian Gladman SHA-1/SHA-2 | Beide moderne doelen; SHA-256 en SHA-512 constante tabellen aanwezig in beide moderne binaire bestanden | 1998–2010 herdistributiekennisgeving en disclaimer |
| Brian Gladman HMAC | Zowel moderne doelen als hun curl/S3-lezercode | Originele kennisgeving met drie voorwaarden, inclusief de paragraaf over alternatieve licenties |
| MD5 | Moderne brondoelen; In de Colin Plumb-implementatie wordt expliciet het publieke domein vermeld | Naamsvermelding behouden |
| Base64 | Markus Ewald header in alle drie de corresponderende bronbomen, met vermelding van Bob Withers | Oorspronkelijke auteurstoeschrijving behouden; kwalificatie hieronder |
| fmt | 26.10 doel en fmt v11 format_error RTTI in het binaire getal | Oorspronkelijke MIT kennisgeving, inclusief optionele uitzondering |
| tfsxml | 26.10 brondoel | Originele MediaArea MIT kennisgeving |
| Android JNI-interface | JNI_OnLoad wordt feitelijk geëxporteerd door zowel moderne DLLs; de meegeleverde JNI header is van AOSP | AOSP copyright en volledige Apache-licentie 2.0 |
| libcurl | Meegeleverde x86 binaire bestanden; daadwerkelijke versie-export; dynamisch gebruikt door moderne MediaInfo | Originele curl kennisgevingen voor 8.11.0 en 7.47.1 |
| Officiële rapportvertalingen | Alle 38 ongewijzigde CSV bronnen uit de taaldirectory MediaInfo v26.10; 37 niet-Engelse tabellen zijn ingesloten, terwijl Engels de standaardwaarden DLL gebruikt | Zelfde projectBSD-2-Clause-aankondiging behouden in de gecombineerde kennisgeving |
| MediaInfo-pictogram | Ongewijzigd officieel pictogram met meerdere afbeeldingen, bronrevisie f057dd3649bc8692a83863b67770e22c9b9dd81a | Oorspronkelijke BSD-2-Clause kennisgeving en toeschrijving |
| libwebp | WebPEncodeLosslessBGRA, WebPFree; 1.1.0; x86 | BSD-3-Clause; PATENTS |

De overeenkomende brondoelen zorgen voor opname in die upstream-buildconfiguraties; ze bewijzen niet dat elke
functie de optimalisatie in de binaire bestanden van de leverancier overleeft. Er wordt geen exacte
versieclaim gedaan voor afhankelijkheden waarvan de revisie niet in die binaire bestanden is vastgelegd.

### Optionele componenten en systeembibliotheken

- De Windows bibliotheekprojecten maken runtime-geladen libcurl mogelijk voor MediaInfo 26.10 en 21.03.
  MediaInfo 0.7.60 is gebouwd met MEDIAINFO_LIBCURL_NO; het binaire bestand bevat ook de diagnose voor
  gehandicaptenondersteuning. De kijker ontdekt, extraheert of laadt nooit curl voor die gebundelde versie.
- libmms is uitgeschakeld in alle drie de meegeleverde Windows DLLs, zoals bevestigd door de ingebouwde
  ondersteuningsberichten voor uitgeschakelde bestanden. Het wordt niet herverdeeld.
- Qt en wxWidgets behoren tot optionele GUI-builds. Geen van beide is opgenomen in deze viewer of in deze DLL
  afhankelijkheden. Hun algemene vermeldingen zijn verwijderd uit de weergegeven licentie.
- Graphviz is een optionele runtime-hook in moderne upstream-code. Er wordt geen Graphviz DLL herverdeeld.
- Er wordt geen FFmpeg-plug-in opnieuw gedistribueerd.
- De MediaInfo DLLs importeert rechtstreeks alleen KERNEL32.dll. Dit betekent niet dat hun statisch gekoppelde
  runtime- en helpercode ontbreken.
- De huidige curl importeert rechtstreeks WS2_32.dll, bcrypt.dll, ADVAPI32.dll, CRYPT32.dll en KERNEL32.dll.
  XP curl importeert rechtstreeks WS2_32.dll, WLDAP32.dll, ADVAPI32.dll en KERNEL32.dll. Dit zijn Windows
  componenten. Hun beschikbaarheid wordt gecontroleerd door de Windows-lader.
- Curl rapporteert Windows Schannel/WinSSL, geen OpenSSL build. De gerapporteerde extra
  compressieafhankelijkheid is statisch opgenomen zlib. Er verschijnt geen aanvullende externe niet-Windows
  DLL in de directe importtabel.
- De viewer zelf is niet afhankelijk van de runtime van C/C++. De meegeleverde DLLs van derden bevatten hun
  eigen gecompileerde runtime-gedeelten. De Windows-builds maken gebruik van Microsoft-tools; er is geen
  bewijs dat de generieke inventarisgegevens libstdc++ of libc++ vereist zijn.
- JPEG gebruikt dynamisch geladen systeem GDI+. De C# resource packer en PowerShell zijn buildtools en zijn
  geen runtime-afhankelijkheden.

Voor gewone inspectie van lokale bestanden is geen MediaArea-server of een op afstand gedownloade
formaatdatabase vereist. libcurl wordt gebruikt door MediaInfo voor URL invoer en mogelijk externe referenties
in ondersteunde mediaformaten. Door het te bundelen wordt er geen afzonderlijk URL-openingscommando aan deze
viewer toegevoegd.

### Licentieopslag en beperkingen

De enige onderhouden distributiekennisgeving is [license.txt](../license.txt) , gecodeerd als UTF-8 met CRLF.
De gecontroleerde BSD, curl, zlib, MIT en Apache-herverdelingsclausules vereisen geen afzonderlijk
kennisgevingsbestand fysiek naast elke DLL; de gecombineerde kennisgeving vergezelt hen in het uitvoerbare en
distributiemateriaal.

Het gearchiveerde pakket MediaInfo 0.7.60 gebruikt zijn eigen versiespecifieke licentie en bevat de oude GNU
Library GPL-tekst. De voorwaarden ervan maken uitdrukkelijk onderscheid tussen ongewijzigde binaire
herverdeling en gewijzigde versies; dynamisch koppelen door deze viewer wijzigt de opgegeven DLL niet. De
originele voorwaarden en bijbehorende licentietekst blijven behouden. De kijker blijft een MIT-licentie
behouden.

Voor één toeschrijving stroomopwaarts is kwalificatie vereist: de header Markus Ewald Base64 heeft geen
expliciete toestemming of licentieverklaring. MediaArea beschrijft de Bob Withers Base64-implementatie als
publiek domein in de bijbehorende MediaConch-documentatie, maar dat bepaalt niet onafhankelijk een
licentieverlening voor elke Ewald-wijziging. Voor die header is geen licentieverlening uitgevonden. Een
volledige leveranciersbevestiging van die herkomst, de exacte ZenLib revisies en de curl ontwikkeling commit
was niet beschikbaar in de meegeleverde binaire bestanden. Deze punten verhinderen dat deze inventaris wordt
behandeld als een volledige, onafhankelijk gecertificeerde SBOM.

### Primaire bronnen

- [MediaInfo herverdelingsvoorwaarden](https://mediaarea.net/en/MediaInfo/License)
- 
  [MediaInfo 26.10 bibliotheekdoel](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Project/MSVC2022/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 21.03 bibliotheekdoel](https://github.com/MediaArea/MediaInfoLib/blob/v21.03/Project/MSVC2015/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 0.7.60 bibliotheekdoel](https://github.com/MediaArea/MediaInfoLib/blob/v0.7.60/Project/MSVC2005/Library/MediaInfoLib.vcproj)
- 
  [Runtime curl-lader](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Source/MediaInfo/Reader/Reader_libcurl.cpp)
- 
  [Gebundelde hulpbronnen en hun mededelingen](https://github.com/MediaArea/MediaInfoLib/tree/v26.10/Source/ThirdParty)
- [ZenLib kennisgeving](https://github.com/MediaArea/ZenLib/blob/master/License.txt)
- [zlib bronmeldingen](https://github.com/madler/zlib/blob/v1.3.2/zlib.h)
- [curl 8.11.0 kennisgeving](https://github.com/curl/curl/blob/curl-8_11_0/COPYING)
- [curl 7.47.1 kennisgeving](https://github.com/curl/curl/blob/curl-7_47_1/COPYING)
- [Apache-licentie 2.0](https://www.apache.org/licenses/LICENSE-2.0)
- [MediaArea Base64 beschrijving](https://github.com/MediaArea/MediaConch/blob/master/README.md)

De rapporttabellen zijn afkomstig van
<https://github.com/MediaArea/MediaInfo/tree/v26.10/Source/Resource/Plugin/Language> . Het bijbehorende
project LICENSE is <https://github.com/MediaArea/MediaInfo/blob/v26.10/LICENSE> .

- [libwebp 1.1.0 COPYING](https://github.com/webmproject/libwebp/blob/v1.1.0/COPYING)
- [libwebp 1.1.0 PATENTS](https://github.com/webmproject/libwebp/blob/v1.1.0/PATENTS)
