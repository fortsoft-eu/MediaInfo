# MediaInfo Viewer

[Čeština](README.cs-CZ.md) | [English (US)](../README.md) | [English (UK)](README.en-GB.md) | [English (Australia)](README.en-AU.md) | [Deutsch](README.de-DE.md) | [Français](README.fr-FR.md) | [Español](README.es-ES.md) | [Italiano](README.it-IT.md) | [Português](README.pt-PT.md) | [Polski](README.pl-PL.md) | [Slovenčina](README.sk-SK.md) | [Dansk](README.da-DK.md) | [Suomi](README.fi-FI.md) | [Íslenska](README.is-IS.md) | [Norsk (bokmål)](README.nb-NO.md) | **Svenska** | [Türkçe](README.tr-TR.md) | [Eesti](README.et-EE.md) | [Gaeilge](README.ga-IE.md) | [Lietuvių](README.lt-LT.md) | [Latviešu](README.lv-LV.md) | [Magyar](README.hu-HU.md) | [Malti](README.mt-MT.md) | [Nederlands](README.nl-NL.md) | [Română](README.ro-RO.md) | [Ελληνικά](README.el-GR.md) | [Bosanski](README.bs-Latn-BA.md) | [Hrvatski](README.hr-HR.md) | [Slovenščina](README.sl-SI.md) | [Crnogorski](README.cnr-Latn-ME.md) | [Беларуская](README.be-BY.md) | [Български](README.bg-BG.md) | [Македонски](README.mk-MK.md) | [Српски](README.sr-Cyrl-RS.md) | [Українська](README.uk-UA.md) | [Русский](README.ru-RU.md)

Windows x86-visare för rapporter från MediaInfo.dll. Varje fil har en egen skrivskyddad flik.

[Byggning och kompatibilitet](#kompilering) | [Granskning av beroenden](#beroenden) | [Licens](../license.txt)

## Kompilering

Öppna MediaInfo.sln i Visual Studio 2015 med verktygsuppsättningen Visual C++ v140 installerad. Välj Release | Win32 och bygg lösningen. Den enda applikationsplattformen är Win32 (x86).

[PCRE2 10.49](https://github.com/PCRE2Project/pcre2/tree/pcre2-10.49) — UTF-16, statiskt länkat, BSD-3-Clause.
[license.txt](../license.txt). [Källkod](../MediaInfo/PCRE2/).
PCRE2 är inbyggt i EXE-filen och kräver ingen separat DLL eller installation.

Utgångar:

- Release\MediaInfo.exe
- Debug\MediaInfo.exe

Viewern länkar inte C- eller C++-körtiden och behöver inte en MSVC-omfördelningsbar. Den valda MediaInfo.dll
kan ha sina egna beroenden.

Byggnad kräver Windows PowerShell och .NET Framework. Dessa är endast byggkrav; den ursprungliga körbara filen
kräver varken PowerShell eller .NET.

### Distributionspaket

Efter att ha byggt Release, kör `powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\PackageRelease.ps1`
. Skriptet skapar `MediaInfo-<version>-win32.zip` i lösningskatalogen, med hjälp av den körbara filversionen i
fyra delar. Arkivet innehåller `MediaInfo.exe` och den kombinerade `license.txt` direkt vid dess rot.

## Kompatibilitet

Win32-visaren är utformad för att använda Windows NT 4.0 APIs.

Den körbara filen innehåller tre x86 MediaInfo-bibliotek: 26.10 för nuvarande Windows, 21.03 från paketet
Windows XP och 0.7.60 från paketet Windows 95–2000. Ett biblioteks arkitektur ensam avgör inte dess
operativsystemkompatibilitet. Tittaren provar de medföljande biblioteken från nyaste till äldsta och stoppar
efter den första lyckade laddningen och versionsfrågan.

Windows 95 stöds för närvarande inte.

## Användning

- Arkiv > Öppna (Ctrl+O) öppnar Windows-fildialogrutan med flera val. På Windows Vista och senare, Öppna och
  spara använd den moderna dialogrutan Common Item; äldre Windows använder de äldre vanliga dialogrutorna.
- Dra en eller flera filer till fönstret, EXE-ikonen eller dess genväg, eller ange sökvägarna på
  kommandoraden. Om flera instanser inte är tillåtna öppnas filerna i det fönster som redan körs.
- Varje distinkt normaliserad fullständig bana har en flik. Återöppning av en redan öppen fil väljer dess
  befintliga flik utan att ladda om eller ändra dess rapport, urval eller rullningsposition. Jämförelser
  ignorerar banbokstav. Öppningar av flera filer behandlar listan i ordning och lämnar den senast bearbetade
  filen aktiv, oavsett om den är nyöppnad eller redan öppen. Håller du muspekaren över en flikrubrik visas
  hela filsökvägen i ett inbyggt verktygstips, inklusive när det visade filnamnet förkortas.
- Menyn Arkiv listar de åtta senast laddade filerna direkt ovanför Exit, mellan separatorer. Poster visar
  endast ett nummer och filnamn. Om du väljer en post öppnas dess lagrade fullständiga sökväg eller väljer
  dess befintliga flik; lyckad återöppning flyttar den till toppen utan dubbletter. Att välja en otillgänglig
  fil frågar om man vill ta bort posten för de senaste filerna. Den ursprungliga frågeikonen och
  Yes/No-knapparna används. Ja är standard och tar bort posten från menyn och registret; Nej behåller det.
  Uppmaningen inkluderar hela sökvägen.
- Mushjulet över svämmande flikrubriker rullar rubrikremsan en flik per meddelande utan att ändra val eller
  fokus.
- Ctrl+Tab och Ctrl+Skift+Tab växla flikar; Ctrl+W stänger den aktiva fliken. Genom att mittklicka på en
  flikrubrik stängs den fliken samtidigt som alla andra aktiva flikar bevaras. Arkiv > Stäng alla stänger alla
  flikar, inklusive köade rapporter. Arkiv > Avsluta (Alt+F4) stänger programmet.
- Dubbelklicka väljer ett ord. Trippelklick väljer en logisk linje. Genom att dra utökas markeringen med ord
  eller rader.
- Ctrl+A väljer rapporten; Ctrl+C kopierar det.
- Redigera > Sök (Ctrl+F) söker i den aktiva fliken. F3 upprepar sökningen; Skift+F3 vänder riktningen. Vid
  textens ändar fortsätter sökningen från motsatt ände. Alternativ > Automatiskt radbyte gäller bara den
  aktiva fliken; bocken följer den valda fliken. Sökfönstret kan minimeras och ändras i bredd; positionen och
  inställningen Alltid överst sparas. Upp till 30 söktexter med sina alternativ behålls bara tills programmet
  avslutas. Alternativen för början och slutet gäller logiska rader. Reguljära uttryck använder PCRE2-syntax.
  Alla kommandon i Redigera gäller bara den aktiva fliken. Enter startar sökningen; Skift+Enter vänder den
  valda riktningen. ”Matcha gemener och versaler” skiljer mellan gemener och versaler; ”Sök bakåt” söker mot
  textens början. Ett val i historiken återställer alla fem sökalternativen, inklusive inställningen för
  reguljära uttryck; ”Alltid överst” är oberoende. ”Reguljärt uttryck” inaktiverar ”Raden börjar med” och
  ”Raden slutar med”. Om båda alternativen för radens ändar är aktiverade räcker en träff vid endera änden.
  ”Automatiskt radbyte” ändrar bara visningen.
- Alternativ > Inställningar (Ctrl+G) öppnar en enskild inställningsdialog för MediaInfo och curl sökvägar,
  rapportteckensnitt, teckensnittskantutjämning, gränssnittsspråk och rapportspråk. En tom DLL-sökväg
  möjliggör automatisk upptäckt.
- Teckensnittsknappen visar familjen, punktstorleken och stilen och öppnar standarddialogen Windows
  teckensnitt. Standard återställer Consolas, eller Courier New om Consolas inte är tillgänglig; knappen
  Standard är inaktiverad när standard är valt. Användarvalda teckensnitt behålls utan att ersättas med
  programkod.
- Val av teckensnittskantutjämning är ClearType när de stöds, GDI och Ingen. Det initiala valet är ClearType
  när det stöds, annars GDI. Teckensnittsinställningar påverkar endast mediarapporter och deras bildexporter.
- Arkiv > Exportera (Ctrl+E) öppnar dialogrutan Windows Spara som och exporterar hela den aktiva rapporten
  till TXT, BMP, GIF, JPEG, PNG, TIFF eller WebP, inklusive text utanför det synliga området.
- Hjälp öppnar ett separat modelllöst fönster med en egen post i aktivitetsfältet och minimeringsknapp. Om är
  en modal dialog; dess produktrubrik listar alla tre inbäddade DLL-versioner.

Skriv ut… (Ctrl+P) öppnar systemets skrivardialog och skriver ut hela den aktiva fliken utan
förhandsgranskning. Rapportens teckensnitt används; långa rader radbryts och texten delas upp på sidor.
Utskriften sker i bakgrunden.

Öppna mapp… öppnar filerna direkt i den valda mappen, var och en på en egen flik. Undermappar tas inte med.
Öppna och Öppna mapp delar den senast valda mappen. Export kommer ihåg en egen mapp, som standard Dokument.

Avancerat läge visar fler fält i rapporten.

Fullständig analys undersöker hela filen och kan ta längre tid. Dessa rapportalternativ och Spårningsnivå
tillhör varje flik; en ändring uppdaterar endast den aktiva fliken. Den senast manuellt valda kombinationen
sparas för nya flikar och nästa start. En matchande cachad rapport återanvänds så länge filen förblir
oförändrad.

Kända format, Kända kodekar och Kända parametrar öppnas på egna rapportflikar.

Den ursprungliga fönsterstorleken och platsen väljs av Windows. Tidigare sparad fönsterplacering åsidosätter
dessa standardinställningar vid senare lanseringar.

Vänster del av statusfältet visar filsökvägar och inläsningsförlopp; höger del visar versionen av den inlästa
MediaInfo.dll. Långa sökvägar förkortas med uteslutningstecken efter det tillgängliga utrymmet.

## Skapa en header-fil

Menyn Verktyg är den fjärde på menyraden. Dess Skapa en header-fil…-kommando öppnar en källfil oberoende av
rapportflikarna och kopierar dess första 524288 byte (512 KiB). En kortare fil kopieras i sin helhet; en tom
fil ger en tom utdatafil. Detta är vanlig binär filläsning, utan MediaInfo-analys eller krav på MediaInfo.dll.
Verktyget lämnar rapportflikar och programmets lista över senaste filer oförändrade.

Efter läsning startar dialogrutan Spara som i källfilens mapp och föreslår video.mp4.header för video.mp4:
.header läggs till det fullständiga originalnamnet. Du kan ändra både namnet och målmappen. Om du avbryter
någon av dialogrutorna skrivs ingen utdata. Att ersätta en befintlig destination kräver bekräftelse. Källan
förblir oförändrad; en misslyckad lagring bevarar den tidigare destinationen. Öppning och sparande använder de
senaste systemdialogrutorna som finns i den aktuella Windows-versionen.

Vid programstart hämtar verktyget sin initiala inmatningsmapp från Arkiv > Öppna. Om ingen mapp har sparats
väljer Windows den ursprungliga platsen. När en indatafil har valts kommer verktyget bara ihåg sin egen mapp
tills programmet avslutas, även om Spara som avbryts. Det ändrar varken mapparna som används av Öppna och
Exportera eller sparar sin egen mapp i programinställningarna. Varje Spara som-dialogruta startar i mappen för
den för närvarande valda indatafilen, oavsett den tidigare sparade destinationen.

## Sökning efter bibliotek

En sparad manuell sökväg prövas först. Om den inte kan laddas, försöker automatisk upptäckt:

1. MediaInfo.dll bredvid den körbara filen, sedan i varje överordnad katalog upp till enheten eller UNC dela
   roten.
2. ProgramFiles, ProgramFiles(x86) och ProgramW6432.
3. LOCALAPPDATA och APPDATA.

Under dessa installationsrötter kontrollerar upptäckten MediaInfo, MediaArea\MediaInfo, MediaArea,
MediaArea.net\MediaInfo, Programs\MediaInfo, Programs\MediaArea\MediaInfo. Oläsbara platser och inkompatibla
DLLs hoppas över. Den skannar inte disken rekursivt.

Om ingen kompatibel extern DLL hittas, försöker tittaren de inbäddade versionerna i denna ordning: 26.10,
21.03, 0.7.60. Den extraherar och testar en version i taget. När en version väl har laddats, extraheras eller
testas inte äldre versioner. Att enbart distribuera MediaInfo.exe är tillräckligt; en kompatibel extern DLL
har alltid prioritet och kan uppdateras oberoende.

En misslyckad manuell biblioteksändring behåller biblioteket som redan laddades.

## Export av rapporter

Spara som-formaten är ordnade TXT, BMP, GIF, JPEG, PNG, TIFF och WebP. Kodare som inte stöds utelämnas från
både moderna och äldre dialogrutor.

TXT erbjuder ANSI, UTF-8, UTF-8 med BOM, UTF-16 BE med BOM och UTF-16 LE med BOM. Det andra alternativet,
UTF-8 utan BOM, är standard. Hela rapporttexten och dess ursprungliga radslut bevaras.

BMP, PNG och TIFF bevarar alla renderade färger; GIF89a bevarar den exakta renderade paletten när bilden har
högst 256 färger. Export skriver alltid det valda formatet eller rapporterar ett fel; det ersätter aldrig ett
annat format.

Bilder innehåller hela rapporten i valt rapporttypsnitt, med svart text på vit bakgrund. De innehåller inte
applikationsmenyn, flikrubriker, statusfält, urval eller fält. Återgivningen är oberoende av textrutans
rullningsposition.

För att undvika tysta avkortningar av rapporter eller uttömmande adressutrymmet på äldre datorer är en enda
bild begränsad till 16 384 pixlar bred, 32 767 pixlar hög och 256 MiB okomprimerat bitmappsminne. Välj ett
mindre teckensnitt om en rapport överskrider dessa gränser.

`Google WebP (*.webp)` är det sista formatet och sparar rapporten förlustfritt.

WebP: 16383 × 16383 px.

## Gränssnitt och rapportspråk

Preferenser (Alternativ > Preferenser, Ctrl+G) innehåller bibliotekssökvägar, rapportteckensnitt, utjämning
och språk. Gränssnittet har 36 varianter och följer först Windows. Rapporter använder alltid bibliotekets
ursprungliga engelska som standard, oberoende av Windows och gränssnittet. Endast ett manuellt val ändrar
rapportspråket: engelska, 37 översättningar eller en egen MediaInfo-CSV-tabell.

OK eller Verkställ bekräftar ändringar; Avbryt förkastar väntande ändringar. Preferenser anger gränsen för
fliknamn (80 som standard) och rensar listan över senaste filer. Långa namn behåller början, slutet och
filändelsen med uteslutningstecken i mitten.

Som standard tillåts bara en instans och senare starter skickar filer till det öppna fönstret. Flera instanser
kan tillåtas i preferenserna. Med flera fönster återställs den sparade positionen bara för det första fönstret
av varje formulär; senare fönster återställer bara storleken.

Om du bara ändrar gränssnittet lämnas texten i öppna rapporter oförändrad. En manuellt tillämpad
rapportspråksändring laddar om deras rapporter samtidigt som tabulatorordningen och MRU-ordningen bevaras.

## libcurl

Automatisk curl upptäcktskontroll bredvid den valda MediaInfo DLL, sedan de delade executable/ancestor,
programfiler och användarinstallationsplatser. Om ingen kompatibel extern curl hittas, extraheras den
matchande inbäddade nuvarande eller XP-versionen till den kontrollerade cachen per användare. Den äldsta
MediaInfo 0.7.60 kringgår curl upptäckt, extrahering och laddning helt. En uttryckligen vald ogiltig curl
avvisar inställningsändringen; saknad valfri automatisk curl förhindrar inte vanliga lokala filrapporter.

## Filnamn och senast använda filer

MRU filnamn förkortas endast när de är längre än 80 UTF-16 kodenheter. En ellips i mitten bevarar början,
slutet av filnamnet före dess förlängning och den fullständiga slutliga förlängningen; fullständiga sökvägar
och rapporter förblir oförändrade. Tabtexter använder samma algoritm med en konfigurerbar standardgräns på 80.

Senaste filer > Rensa rensar omedelbart både live-menyn MRU och dess sparade sökvägar samtidigt som alla öppna
flikar lämnas intakta. Den tillämpar eller validerar inte väntande inställningar och aktiverar inte Apply.
Avbryt eller Escape bevarar den rensade historiken samtidigt som väntande redigeringar ignoreras. Rensa är
inaktiverat när listan är tom, och dess tillstånd uppdateras när nya rapporter fylls i listan. Ett
register-skrivfel rapporteras omedelbart. Genom att tillämpa en ny fliknamnsgräns uppdateras varje öppen flik
utan att ladda om dess medierapport.

## Licens och vidaredistribution

Tittaren är licensierad under MIT-licensen i license.txt.

MediaInfo är en tredjepartskomponent. Det enda distributionsmeddelandet som underhålls är root license.txt,
kodad som UTF-8 med CRLF och inkluderar visningsprogram, bibliotek, statiskt inbyggda komponenter, ikon och
officiella översättningstabeller.

Den här produkten använder MediaInfo-biblioteket, Copyright (c) 2002-2026 MediaArea.net SARL.

- MediaInfo: <https://mediaarea.net/MediaInfo>
- Licens: <https://mediaarea.net/en/MediaInfo/License>
- Windows nedladdningar: <https://mediaarea.net/en/MediaInfo/Download/Windows>

## Beroenden

### Filer

| Resurs | Arkitektur | Version rapporterad av komponenten | SHA-256 |
| --- | --- | --- | --- |
| Resources/lib/26.10/MediaInfo.dll | x86 | 26.10 | E73027A1577084135425AA013D46C8B2985AD142CCF04F1ADB301B9A9CFB78F8 |
| Resources/lib/21.03/MediaInfo.dll | x86 | 21.03 | EBBF1C371702F3DC39CA23D619C47EDF97E66A95AEABE725284F1402D8F3E58A |
| Resources/lib/0.7.60/MediaInfo.dll | x86 | 0.7.60 | A26C07BCC25FA01A40E6888D02EABD59AA8DB2ABF6F5195481228D3A91D04441 |
| Resources/lib/26.10/libcurl.dll | x86 | 8.11.0-DEV, Schannel, zlib 1.3.1 | DCF136C84F3A4FBEAE2B317FE36D7F11225B56FBA3343AF4BBA8706B3F46F334 |
| Resources/lib/21.03/libcurl.dll | x86 | 7.47.1, WinSSL, zlib 1.2.8 | 21025CAC8089F1E570EE083D8CFD6311C2C51E97094A9FCD8C7A0B544C22CB48 |
| Resources/lib/libwebp.dll | x86 | 1.1.0 | 9986023BB6FF5510A157919F0CD958A94800EC6A1D981F3403A9648BEDFEE575 |

Sökvägarna i tabellen är relativa till projektmappen MediaInfo.

Det aktuella biblioteket rapporterar en utvecklingsversion; dess exakta källa commit kan inte återställas från
den versionssträngen. Dess medföljande meddelande använder uppströmstexten 8.11.0 copyright och tillstånd,
vars licensvillkor också finns i utvecklingsserien.

### Inbyggda komponenter

| Komponent | Bevis och omfattning | Varsel |
| --- | --- | --- |
| MediaInfoLib | Faktiska versioner och obligatoriska Unicode-exporter; oförändrade tillförda binärfiler | Versionsspecifik originalupphovsrätt, vidaredistributionsvillkor och ansvarsfriskrivning |
| ZenLib | Statiska projektreferenser och inbäddade ZenLib RTTI i alla tre DLLs; exakt länkade versioner tillhandahålls inte | zlib-stil ZenLib meddelande |
| zlib | Inbäddade versionssträngar för inflate/deflate: 1.3.2 i MediaInfo 26.10, 1.2.11 i 21.03, 1.2.7 i 0.7.60; curl rapporterar dessutom 1.3.1 och 1.2.8 | Original zlib meddelanden för alla fem versioner |
| TinyXML-2 | Matcha moderna källmål och binära RTTI; ingår i det äldre projektet, men inte oberoende identifierat i den avskalade äldre binära filen | Originalanslag Lee Thomason zlib-stil behålls |
| Brian Gladman AES | Ingår i båda moderna uppströms biblioteksmål, med matchande tillåtande källmeddelanden | 1998–2013 meddelande om omfördelning och ansvarsfriskrivning |
| Brian Gladman SHA-1/SHA-2 | Både moderna mål; SHA-256 och SHA-512 konstanttabeller som finns i båda moderna binärer | 1998–2010 meddelande om omfördelning och ansvarsfriskrivning |
| Brian Gladman HMAC | Både moderna mål och deras curl/S3 läsarkod | Originalmeddelande med tre villkor, inklusive dess alternativa licensparagraf |
| MD5 | Moderna källmål; Colin Plumb-implementering anger uttryckligen allmän egendom | Tillskrivning bibehålls |
| Base64 | Markus Ewald header i alla tre motsvarande källträd, krediterar Bob Withers | Ursprunglig författarskapstillskrivning bibehålls; kvalifikation nedan |
| fmt | 26.10 mål och fmt v11 format_error RTTI i binären | Original MIT meddelande, inklusive valfritt undantag |
| tfsxml | 26.10 källmål | Original MediaArea MIT meddelande |
| Android JNI gränssnitt | JNI_OnLoad exporteras faktiskt av både moderna DLLs; den medföljande JNI-huvudet är från AOSP | AOSP upphovsrätt och fullständig Apache-licens 2.0 |
| libcurl | Levererade x86 binärer; faktiska versionsexporter; används dynamiskt av modern MediaInfo | Original curl meddelanden för 8.11.0 och 7.47.1 |
| Officiella rapportöversättningar | Alla 38 omodifierade CSV källor från språkkatalogen MediaInfo v26.10; 37 icke-engelska tabeller är inbäddade, medan engelska använder DLL standardvärden | Samma projekt BSD-2-Clause meddelande bibehålls i det kombinerade meddelandet |
| MediaInfo ikon | Oförändrad officiell flerbildsikon, källversion f057dd3649bc8692a83863b67770e22c9b9dd81a | Original BSD-2-Clause meddelande och tillskrivning |
| libwebp | WebPEncodeLosslessBGRA, WebPFree; 1.1.0; x86 | BSD-3-Clause; PATENTS |

De matchande källmålen etablerar inkludering i dessa uppströmsbyggnadskonfigurationer; de bevisar inte att
varje funktion överlever optimering i leverantörens binärer. Inga anspråk på exakt version görs för beroenden
vars revision inte registreras i dessa binärer.

### Valfria komponenter och systembibliotek

- Biblioteksprojekten Windows möjliggör runtime-loaded libcurl för MediaInfo 26.10 och 21.03. MediaInfo 0.7.60
  byggdes med MEDIAINFO_LIBCURL_NO; dess binär innehåller också diagnostiken för inaktiverat stöd. Tittaren
  upptäcker, extraherar eller laddar aldrig curl för den medföljande versionen.
- libmms är inaktiverad i alla tre medföljande Windows DLLs, vilket bekräftas av deras inbäddade
  inaktiverade-supportmeddelanden. Det omfördelas inte.
- Qt och wxWidgets tillhör valfria GUI builds. Varken ingår i den här visningsprogrammet eller i dessa
  DLL-beroenden. Deras generiska poster togs bort från den visade licensen.
- Graphviz är en valfri runtime-hook i modern uppströmskod. Ingen Graphviz DLL omfördelas.
- Inget plugin FFmpeg omdistribueras.
- MediaInfo DLLs importerar endast KERNEL32.dll direkt. Detta betyder inte att deras statiskt länkade körtid
  och hjälpkod saknas.
- Aktuell curl importerar direkt WS2_32.dll, bcrypt.dll, ADVAPI32.dll, CRYPT32.dll och KERNEL32.dll. XP curl
  importerar direkt WS2_32.dll, WLDAP32.dll, ADVAPI32.dll och KERNEL32.dll. Dessa är Windows komponenter.
  Deras tillgänglighet kontrolleras av Windows-lastaren.
- Curl rapporterar Windows Schannel/WinSSL, inte en OpenSSL build. Dess rapporterade ytterligare
  komprimeringsberoende är statiskt inkluderat zlib. Inga ytterligare externa icke-Windows DLL visas i dess
  direktimporttabell.
- Viewern själv har inget C/C++ körtidsberoende. Den medföljande tredje parten DLLs innehåller sina egna
  kompilerade körtidsdelar. Windows-byggena använder Microsoft-verktyg; det finns inga bevis som kräver
  generiska libstdc++ eller libc++ inventeringsposter.
- JPEG använder dynamiskt laddat system GDI+. Resurspaketeraren C# och PowerShell är byggverktyg och är inte
  körtidsberoenden.

Vanlig lokal filinspektion kräver inte en MediaArea-server eller en fjärrnedladdad databas i formatet. libcurl
används av MediaInfo för URL-ingångar och potentiellt fjärrreferenser i medieformat som stöds. Att bunta det
lägger inte till ett separat URL-öppningskommando till den här visningsprogrammet.

### Licenslagring och begränsningar

Det enda distributionsmeddelandet som underhålls är [license.txt](../license.txt) , kodat som UTF-8 med CRLF.
De markerade BSD, curl, zlib, MIT och Apache-omfördelningsklausulerna kräver inte en separat meddelandefil
fysiskt bredvid varje DLL; det kombinerade meddelandet medföljer dem i det körbara och
distributionsmaterialet.

Det arkiverade paketet MediaInfo 0.7.60 använder sin egen versionsspecifika licens och inkluderar den gamla
GNU Library GPL-texten. Dess villkor skiljer uttryckligen omodifierad binär omdistribution från modifierade
versioner; dynamisk länkning av den här tittaren ändrar inte den medföljande DLL. Dess ursprungliga villkor
och tillhörande licenstext behålls. Tittaren förblir MIT-licensierad.

En tillskrivning uppströms kräver kvalificering: Markus Ewald Base64-huvudet har ingen uttrycklig behörighet
eller licensförklaring. MediaArea beskriver Bob Withers Base64-implementeringen som allmän egendom i dess
relaterade MediaConch-dokumentation, men det etablerar inte självständigt ett licensbeviljande för varje
Ewald-ändring. Inget licensbeviljande har uppfunnits för den rubriken. En fullständig leverantörsbekräftelse
av den härkomsten, de exakta ZenLib-revisionerna och curl-utvecklingen commit var inte tillgängliga i de
medföljande binärfilerna. Dessa punkter förhindrar att denna inventering behandlas som en komplett, oberoende
certifierad SBOM.

### Primära källor

- [MediaInfo omfördelningsvillkor](https://mediaarea.net/en/MediaInfo/License)
- 
  [MediaInfo 26.10 biblioteksmål](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Project/MSVC2022/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 21.03 biblioteksmål](https://github.com/MediaArea/MediaInfoLib/blob/v21.03/Project/MSVC2015/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 0.7.60 biblioteksmål](https://github.com/MediaArea/MediaInfoLib/blob/v0.7.60/Project/MSVC2005/Library/MediaInfoLib.vcproj)
- 
  [Körtid curl laddare](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Source/MediaInfo/Reader/Reader_libcurl.cpp)
- 
  [Medföljande hjälpkällor och deras meddelanden](https://github.com/MediaArea/MediaInfoLib/tree/v26.10/Source/ThirdParty)
- [ZenLib meddelande](https://github.com/MediaArea/ZenLib/blob/master/License.txt)
- [zlib källmeddelanden](https://github.com/madler/zlib/blob/v1.3.2/zlib.h)
- [curl 8.11.0 meddelande](https://github.com/curl/curl/blob/curl-8_11_0/COPYING)
- [curl 7.47.1 meddelande](https://github.com/curl/curl/blob/curl-7_47_1/COPYING)
- [Apache-licens 2.0](https://www.apache.org/licenses/LICENSE-2.0)
- [MediaArea Base64 beskrivning](https://github.com/MediaArea/MediaConch/blob/master/README.md)

Rapporttabellerna kommer från
<https://github.com/MediaArea/MediaInfo/tree/v26.10/Source/Resource/Plugin/Language> . Matchningsprojektet
LICENSE är <https://github.com/MediaArea/MediaInfo/blob/v26.10/LICENSE> .

- [libwebp 1.1.0 COPYING](https://github.com/webmproject/libwebp/blob/v1.1.0/COPYING)
- [libwebp 1.1.0 PATENTS](https://github.com/webmproject/libwebp/blob/v1.1.0/PATENTS)
