# MediaInfo Viewer

[Čeština](README.cs-CZ.md) | [English (US)](../README.md) | [English (UK)](README.en-GB.md) | [English (Australia)](README.en-AU.md) | [Deutsch](README.de-DE.md) | [Français](README.fr-FR.md) | [Español](README.es-ES.md) | [Italiano](README.it-IT.md) | [Português](README.pt-PT.md) | [Polski](README.pl-PL.md) | [Slovenčina](README.sk-SK.md) | [Dansk](README.da-DK.md) | [Suomi](README.fi-FI.md) | [Íslenska](README.is-IS.md) | [Norsk (bokmål)](README.nb-NO.md) | [Svenska](README.sv-SE.md) | [Türkçe](README.tr-TR.md) | [Eesti](README.et-EE.md) | [Gaeilge](README.ga-IE.md) | **Lietuvių** | [Latviešu](README.lv-LV.md) | [Magyar](README.hu-HU.md) | [Malti](README.mt-MT.md) | [Nederlands](README.nl-NL.md) | [Română](README.ro-RO.md) | [Ελληνικά](README.el-GR.md) | [Bosanski](README.bs-Latn-BA.md) | [Hrvatski](README.hr-HR.md) | [Slovenščina](README.sl-SI.md) | [Crnogorski](README.cnr-Latn-ME.md) | [Беларуская](README.be-BY.md) | [Български](README.bg-BG.md) | [Македонски](README.mk-MK.md) | [Српски](README.sr-Cyrl-RS.md) | [Українська](README.uk-UA.md) | [Русский](README.ru-RU.md)

Savoji Windows x86 peržiūros programa MediaInfo.dll ataskaitoms. Kiekvienas failas turi atskirą tik skaitomą
kortelę.

[Kompiliavimas ir suderinamumas](#kompiliavimas) | [Priklausomybių auditas](#priklausomybės) | [Licencija](../license.txt)

## Kompiliavimas

Atidarykite MediaInfo.sln Visual Studio 2015 su įdiegtu Visual C++ v140 įrankių rinkiniu. Pasirinkite Release | Win32 ir sukurkite sprendimą. Vienintelė taikomųjų programų platforma yra Win32 (x86).

[PCRE2 10.49](https://github.com/PCRE2Project/pcre2/tree/pcre2-10.49) — UTF-16, statiškai susieta,
BSD-3-Clause. [Pirminis kodas](../MediaInfo/PCRE2/).
[license.txt](../license.txt).
PCRE2 yra įtraukta į EXE failą ir jai nereikia atskiro DLL failo ar papildomo diegimo.

Išėjimai:

- Release\MediaInfo.exe
- Debug\MediaInfo.exe

Žiūrovas nesusieja C arba C++ vykdymo laiko ir jai nereikia MSVC, kurį galima perskirstyti. Pasirinktas
MediaInfo.dll gali turėti savo priklausomybes.

Statant reikia Windows PowerShell ir .NET Framework. Tai tik konstrukcijos reikalavimai; vietiniam vykdomajam
failui nereikia nei PowerShell, nei .NET.

### Platinimo paketas

Sukūrę Release, paleiskite `powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\PackageRelease.ps1` .
Scenarijus sukuria `MediaInfo-<version>-win32.zip` sprendimų kataloge, naudodamas keturių dalių vykdomojo
failo versiją. Archyve yra `MediaInfo.exe` ir kombinuotasis `license.txt` tiesiai jo šaknyje.

## Suderinamumas

Win32 peržiūros priemonė skirta naudoti Windows NT 4.0 APIs.

Vykdomajame faile yra trys x86 MediaInfo bibliotekos: 26.10 dabartinei Windows, 21.03 iš Windows XP paketo ir
0.7.60 iš Windows 95–2000 paketo. Vien tik bibliotekos architektūra nenulemia jos suderinamumo su operacine
sistema. Žiūrovas bando sugrupuotas bibliotekas nuo naujausios iki seniausios ir sustoja po pirmosios
sėkmingos įkėlimo ir versijos užklausos.

Windows 95 šiuo metu nepalaikomas vykdymo laikas.

## Naudojimas

- Failas > Atidaryti (Ctrl+O) atidaro Windows failo dialogo langą su keliais pasirinkimais. Windows Vista ir
  naujesnėje versijoje Atidaryti ir Išsaugoti naudokite šiuolaikinį bendro elemento dialogo langą; senesni
  Windows naudoja senus įprastus dialogo langus.
- Vilkite vieną ar kelis failus į langą, ant EXE piktogramos ar jos nuorodos arba perduokite jų kelius
  komandinėje eilutėje. Jei keli egzemplioriai neleidžiami, failai atidaromi jau veikiančiame lange.
- Kiekvienas atskiras normalizuotas visas kelias turi vieną skirtuką. Iš naujo atidarius jau atidarytą failą,
  jo esamas skirtukas pasirenkamas iš naujo neįkeliant ir nekeičiant ataskaitos, pasirinkimo ar slinkties
  padėties. Lyginant nepaisoma kelio raidžių didžiosios ir mažosios raidės. Atidarius kelis failus, sąrašas
  apdorojamas eilės tvarka ir paliekamas aktyvus paskutinis sėkmingai apdorotas failas, nesvarbu, ar jis buvo
  atidarytas naujai, ar jau atidarytas. Užvedus pelės žymeklį virš skirtuko antraštės, vietiniame patarime
  rodomas visas failo kelias, įskaitant tuos atvejus, kai rodomas failo pavadinimas sutrumpinamas.
- Meniu Failas pateikia aštuonių paskutinių įkeltų failų sąrašą tiesiai virš Exit, tarp skyriklių. Įrašai rodo
  tik numerį ir failo pavadinimą. Pasirinkus įrašą, atidaromas visas išsaugotas jo kelias arba pasirenkamas
  esamas skirtukas; sėkmingas pakartotinis atidarymas perkelia jį į viršų be dublikatų. Pasirinkus
  nepasiekiamą failą, klausiama, ar pašalinti naujausių failų įrašą. Naudojama vietinio klausimo piktograma ir
  Yes/No mygtukai. Taip yra numatytasis ir pašalina įrašą iš meniu ir registro; Jo neišlaiko. Raginimas apima
  visą kelią.
- Pelės ratukas perpildytas skirtukų antraštes slenka antraštės juosta po vieną skirtuką kiekviename pranešime
  nekeičiant pasirinkimo ar fokusavimo.
- Ctrl+Tab ir Ctrl+Shift+Tab perjungti skirtukus; Ctrl+W uždaro aktyvų skirtuką. Viduryje spustelėjus skirtuko
  antraštę, tas skirtukas uždaromas ir išsaugomas bet kuris kitas aktyvus skirtukas. Failas > Uždaryti viską
  uždaro kiekvieną skirtuką, įskaitant eilėje esančias ataskaitas. Failas > Išeiti (Alt+F4) uždaro programą.
- Dukart spustelėjus pasirenkamas žodis. Tris kartus spustelėjus pasirenkama loginė eilutė. Vilkimas praplečia
  pasirinkimą žodžiais arba eilutėmis.
- Ctrl+A pasirenka ataskaitą; Ctrl+C jį nukopijuoja.
- Redaguoti > Rasti (Ctrl+F) ieško aktyviame skirtuke. F3 kartoja paiešką, o Shift+F3 pakeičia jos kryptį.
  Pasiekus teksto galą, paieška tęsiama nuo kito galo. Parinktys > Teksto eilučių kėlimas taikomas tik
  aktyviam skirtukui; varnelė atitinka pasirinktą skirtuką. Paieškos langą galima sumažinti ir keisti jo
  plotį; jo vieta ir parinktis Visada viršuje įsimenamos. Iki 30 paieškos tekstų su parinktimis saugoma tik
  iki programos uždarymo. Pradžios ir pabaigos parinktys taikomos loginėms eilutėms. Reguliarieji reiškiniai
  naudoja PCRE2 sintaksę. Visos meniu Redaguoti komandos taikomos tik aktyviam skirtukui. Enter pradeda
  paiešką; Shift+Enter apverčia pasirinktą kryptį. „Skirti didžiąsias ir mažąsias raides“ skiria didžiąsias ir
  mažąsias raides; „Ieškoti atgal“ ieško teksto pradžios link. Pasirinkus istorijos įrašą atkuriamos visos
  penkios paieškos parinktys, įskaitant reguliariųjų reiškinių režimo būseną; „Visada viršuje“ yra
  nepriklausoma. „Reguliarusis reiškinys“ išjungia „Eilutė prasideda“ ir „Eilutė baigiasi“. Įjungus abi
  eilutės kraštų parinktis, pakanka atitikmens viename krašte. „Teksto eilučių kėlimas“ keičia tik rodymą.
- „Nustatymai“ > „Nuostatos“ (Ctrl+G) atidaro vieną nuostatų dialogo langą, skirtą MediaInfo ir curl takams,
  ataskaitos šriftui, šrifto antialiasing, sąsajos kalbai ir ataskaitos kalbai. Tuščias DLL kelias įgalina
  automatinį aptikimą.
- Šrifto mygtukas rodo šeimą, taško dydį ir stilių bei atidaro standartinį Windows šrifto dialogo langą.
  Numatytasis atkuria Consolas arba Courier New, jei Consolas nepasiekiamas; mygtukas Default yra išjungtas,
  kol pasirinktas numatytasis. Vartotojo pasirinkti šriftai išsaugomi nepakeičiant programos kodu.
- Šrifto antialiasing parinktys yra ClearType, kai palaikoma, GDI ir Nėra. Pradinis pasirinkimas yra
  ClearType, kai palaikomas, kitu atveju GDI. Šrifto nustatymai turi įtakos tik žiniasklaidos pranešimams ir
  jų vaizdų eksportavimui.
- Pagalba atidaro atskirą bemodį langą su atskiru užduočių juostos įrašu ir sumažinimo mygtuku. Apie yra
  modalinis dialogas; jo produkto antraštėje pateikiamos visos trys įterptosios DLL versijos.

Spausdinti… (Ctrl+P) atveria sistemos spausdintuvo pasirinkimo dialogą ir išspausdina visą aktyvų skirtuką be
peržiūros. Naudojamas ataskaitos šriftas; ilgos eilutės perkeliamos, o tekstas padalijamas į puslapius.
Spausdinama fone.

Atidaryti aplanką… atveria tiesiogiai pasirinktame aplanke esančius failus, kiekvieną atskirame skirtuke.
Poaplankiai neįtraukiami. Atidaryti ir Atidaryti aplanką naudoja bendrą paskutinį pasirinktą aplanką.
Eksportas įsimena atskirą aplanką, numatytasis yra Dokumentai.

Išplėstinis režimas rodo papildomus ataskaitos laukus.

Išsami analizė patikrina visą failą ir gali užtrukti ilgiau. Šios ataskaitos parinktys ir Sekimo lygis
priklauso kiekvienam skirtukui; pakeitimas atnaujina tik aktyvų skirtuką. Paskutinis rankiniu būdu pasirinktas
derinys išsaugomas naujiems skirtukams ir kitam paleidimui. Atitinkama talpykloje saugoma ataskaita naudojama
pakartotinai, kol failas lieka nepakitęs.

Žinomi formatai, Žinomi kodekai ir Žinomi parametrai atveriami atskiruose ataskaitų skirtukuose.

Pradinį lango dydį ir vietą pasirenka Windows. Anksčiau išsaugota lango vieta pakeičia šiuos numatytuosius
nustatymus vėliau paleidžiant.

Kairėje būsenos juostos pusėje rodomi failų keliai ir įkėlimo eiga, dešinėje – įkeltos MediaInfo.dll versija.
Ilgi keliai trumpinami daugtaškiu pagal turimą vietą.

## Sukurti antraštės failą

Įrankiai yra ketvirtasis meniu juostos meniu. Jo komanda Sukurti antraštės failą… atidaro vieną šaltinio failą
nepriklausomai nuo ataskaitos skirtukų ir nukopijuoja pirmuosius 524288 baitus (512 KiB). Trumpesnis failas
nukopijuojamas visas; tuščias failas sukuria tuščią išvestį. Tai įprastas dvejetainių failų skaitymas be
MediaInfo analizės arba MediaInfo.dll reikalavimo. Įrankis nepakeičia ataskaitų skirtukų ir peržiūros
priemonės naujausių failų sąrašo.

Perskaičius, šaltinio failo aplanke prasideda dialogo langas Įrašyti kaip ir siūlomas video.mp4.header,
skirtas video.mp4: .header pridedamas prie viso pradinio pavadinimo. Galite pakeisti pavadinimą ir paskirties
aplanką. Atšaukus bet kurį dialogo langą, išvestis nebus rašoma. Norint pakeisti esamą paskirties vietą,
reikia patvirtinimo. Šaltinis lieka nepakitęs; nepavykęs išsaugojimas išsaugo ankstesnę paskirties vietą.
Atidarant ir įrašant naudojami naujausi toje Windows versijoje prieinami sistemos dialogo langai.

Paleidus programą, įrankis paima pradinį įvesties aplanką iš Failas > Atidaryti. Jei nebuvo išsaugotas joks
aplankas, Windows pasirenka pradinę vietą. Pasirinkus įvesties failą, įrankis atsimena savo aplanką tik tol,
kol programa išjungiama, net jei atšaukta Įrašyti kaip. Jis nekeičia Atidaryti ir Eksportuoti naudojamų
aplankų ir neišsaugo savo aplanko programos nustatymuose. Kiekvienas dialogo langas Įrašyti kaip prasideda
šiuo metu pasirinkto įvesties failo aplanke, neatsižvelgiant į ankstesnę įrašymo vietą.

## Bibliotekų paieška

Pirmiausia bandomas išsaugotas rankinis kelias. Jei jo negalima įkelti, automatinis aptikimas bando:

1. MediaInfo.dll šalia vykdomojo failo, tada kiekviename pirminiame kataloge iki disko arba UNC bendrinti
   šaknį.
2. ProgramFiles, ProgramFiles(x86) ir ProgramW6432.
3. LOCALAPPDATA ir APPDATA.

Pagal šias diegimo šaknis aptikimas tikrina MediaInfo, MediaArea\MediaInfo, MediaArea,
MediaArea.net\MediaInfo, Programs\MediaInfo, Programs\MediaArea\MediaInfo. Neįskaitomos vietos ir nesuderinami
DLLs praleidžiami. Jis rekursyviai nenuskaito disko.

Jei nerandama suderinamo išorinio DLL, žiūryklė bando įterptąsias versijas tokia tvarka: 26.10, 21.03, 0.7.60.
Jis vienu metu ištraukia ir išbando vieną versiją. Kai versija sėkmingai įkeliama, senesnės versijos nėra nei
išgaunamos, nei išbandomos. Užtenka vien platinti MediaInfo.exe; suderinamas išorinis DLL visada turi
pirmenybę ir gali būti atnaujintas atskirai.

Nepavykus rankiniu būdu pakeitus biblioteką, išlaikoma jau įkelta biblioteka.

## Ataskaitų eksportavimas

Išsaugoti kaip formatai yra išdėstyti TXT, BMP, GIF, JPEG, PNG, TIFF ir WebP. Šiuolaikiniuose ir senuosiuose
dialogo languose nepalaikomi koduotuvai neįtraukiami.

TXT siūlo ANSI, UTF-8, UTF-8 su BOM, UTF-16 BE su BOM ir UTF-16 LE su BOM. Numatytasis yra antrasis įrašas,
UTF-8 be BOM. Išsaugomas visas ataskaitos tekstas ir originalios eilučių pabaigos.

BMP, PNG ir TIFF išsaugo visas pateiktas spalvas; GIF89a išsaugo tikslią pateiktą paletę, kai vaizdas turi
daugiausiai 256 spalvų. Eksportas visada rašo pasirinktą formatą arba praneša apie klaidą; jis niekada
nepakeičia kito formato.

## Sąsajos ir ataskaitų kalbos

Nuostatose (Parinktys > Nuostatos, Ctrl+G) yra bibliotekų keliai, ataskaitos šriftas, glodinimas ir kalbos.
Sąsaja turi 36 variantus ir iš pradžių laikosi Windows kalbos. Ataskaitoms visada numatyta originali
bibliotekos anglų kalba, nepriklausomai nuo Windows ir sąsajos. Tai pakeičia tik rankinis pasirinkimas: anglų
kalba, 37 vertimai arba savas MediaInfo CSV žodynas.

Gerai arba Taikyti patvirtina pakeitimus; Atšaukti atmeta laukiančius pakeitimus. Nuostatose galima riboti
kortelių pavadinimus (numatyta 80) ir išvalyti paskutinių failų sąrašą. Ilgi pavadinimai išlaiko pradžią,
pabaigą ir plėtinį, o viduryje įterpiamas daugtaškis.

Pagal numatytąsias nuostatas leidžiamas tik vienas egzempliorius, o vėlesni paleidimai perduoda failus
atvertam langui. Nuostatose galima leisti kelis egzempliorius. Kai langų yra keli, išsaugota vieta atkuriama
tik pirmajam kiekvienos formos langui; kiti langai atkuria tik dydį.

Pakeitus tik sąsają, atvirų ataskaitų tekstas lieka nepakitęs. Rankiniu būdu pritaikytas ataskaitų kalbos
pakeitimas iš naujo įkelia jų ataskaitas, išsaugant skirtukų tvarką ir MRU tvarką.

## libcurl

Automatinės curl aptikimo patikros šalia pasirinktų MediaInfo DLL, tada bendrinamų executable/ancestor,
programos failų ir vartotojo diegimo vietų. Jei nerandama suderinamo išorinio curl, atitinkama įterptoji
dabartinė arba XP versija ištraukiama į patikrintą kiekvieno vartotojo talpyklą. Seniausias MediaInfo 0.7.60
visiškai apeina curl atradimą, ištraukimą ir įkėlimą. Aiškiai pasirinktas netinkamas curl atmeta nuostatos
pakeitimą; trūksta pasirenkamo automatinio curl, netrukdo įprastoms vietinių failų ataskaitoms.

## Failų pavadinimai ir naujausi failai

MRU failų pavadinimai trumpinami tik tada, kai yra ilgesni nei 80 UTF-16 kodo vienetai. Vidurinė elipsė
išsaugo failo pavadinimo pradžią, pabaigą prieš plėtinį ir visą galutinį plėtinį; visi keliai ir ataskaitos
nesikeičia. Skirtukų subtitrai naudoja tą patį algoritmą su konfigūruojama numatyta 80 riba.

Naujausi failai > Išvalyti iš karto išvalo ir tiesioginį MRU meniu, ir jo išsaugotus kelius, nepažeidžiant
visų atidarytų skirtukų. Ji netaiko ir nepatvirtina laukiančių nuostatų ir neįgalina Taikyti. Atšaukti arba
Pabėgti išsaugo išvalytą istoriją ir atmeta laukiančius pakeitimus. Išvalyti išjungiama, kai sąrašas tuščias,
o jo būsena atnaujinama, kai sąrašą užpildo naujos ataskaitos. Nedelsiant pranešama apie registro įrašymo
gedimą. Pritaikius naują skirtuko pavadinimo apribojimą, kiekvienas atidarytas skirtukas atnaujinamas iš naujo
neįkeliant žiniasklaidos ataskaitos.

## Licencija ir perskirstymas

Žiūrovas yra licencijuotas pagal MIT licenciją license.txt.

MediaInfo yra trečiosios šalies komponentas. Vienintelis palaikomas platinimo pranešimas yra root license.txt,
užkoduotas kaip UTF-8 su CRLF ir apimantis peržiūros priemonę, bibliotekas, statiškai integruotus komponentus,
piktogramą ir oficialias vertimo lenteles.

Šiam gaminiui naudojama MediaInfo biblioteka, autorių teisės (c) 2002-2026 MediaArea.net SARL.

- MediaInfo: <https://mediaarea.net/MediaInfo>
- Licencija: <https://mediaarea.net/en/MediaInfo/License>
- Windows atsisiuntimai: <https://mediaarea.net/en/MediaInfo/Download/Windows>

## Priklausomybės

### Failai

| Išteklius | Architektūra | Komponento pranešta versija | SHA-256 |
| --- | --- | --- | --- |
| Resources/lib/26.10/MediaInfo.dll | x86 | 26.10 | E73027A1577084135425AA013D46C8B2985AD142CCF04F1ADB301B9A9CFB78F8 |
| Resources/lib/21.03/MediaInfo.dll | x86 | 21.03 | EBBF1C371702F3DC39CA23D619C47EDF97E66A95AEABE725284F1402D8F3E58A |
| Resources/lib/0.7.60/MediaInfo.dll | x86 | 0.7.60 | A26C07BCC25FA01A40E6888D02EABD59AA8DB2ABF6F5195481228D3A91D04441 |
| Resources/lib/26.10/libcurl.dll | x86 | 8.11.0-DEV, Schannel, zlib 1.3.1 | DCF136C84F3A4FBEAE2B317FE36D7F11225B56FBA3343AF4BBA8706B3F46F334 |
| Resources/lib/21.03/libcurl.dll | x86 | 7.47.1, WinSSL, zlib 1.2.8 | 21025CAC8089F1E570EE083D8CFD6311C2C51E97094A9FCD8C7A0B544C22CB48 |
| Resources/lib/libwebp.dll | x86 | 1.1.0 | 9986023BB6FF5510A157919F0CD958A94800EC6A1D981F3403A9648BEDFEE575 |

Lentelėje pateikti keliai yra santykiniai MediaInfo projekto katalogo atžvilgiu.

Dabartinė biblioteka praneša apie kūrimo versiją; tikslaus šaltinio commit negalima atkurti iš tos versijos
eilutės. Prie jo pridedamame pranešime naudojamas 8.11.0 autorių teisių ir leidimo tekstas, kurio licencijos
sąlygos taip pat pateikiamos kūrimo serijoje.

### Įtraukti komponentai

| Komponentas | Įrodymai ir apimtis | Pastaba |
| --- | --- | --- |
| MediaInfoLib | Faktinės versijos ir būtini Unicode eksportai; nepakeistas pateiktas dvejetainis failas | Konkrečiai versijai būdingos originalios autorių teisės, platinimo sąlygos ir atsakomybės atsisakymas |
| ZenLib | Statinės projekto nuorodos ir įterptos ZenLib RTTI visose trijose DLLs; tikslios susietos versijos nepateiktos | zlib stiliaus ZenLib pranešimas |
| zlib | Įterptosios inflate/deflate versijos eilutės: 1.3.2 MediaInfo 26.10, 1.2.11 21.03, 1.2.7 0.7.60; curl papildomai praneša 1.3.1 ir 1.2.8 | Originalūs zlib pranešimai visoms penkioms versijoms |
| TinyXML-2 | Atitinka šiuolaikinius šaltinio tikslus ir dvejetainį RTTI; įtrauktas į palikimo projektą, bet nėra atskirai identifikuotas pašalintoje palikimo dvejetainėje programoje | Išsaugotas originalus Lee Thomason zlib stiliaus pranešimas |
| Brian Gladman AES | Įtraukta į abu modernius ankstesnius bibliotekos tikslus su atitinkamais leistinųjų šaltinių pranešimais | 1998–2013 perskirstymo pranešimas ir atsakomybės atsisakymas |
| Brian Gladman SHA-1/SHA-2 | Abu modernūs taikiniai; SHA-256 ir SHA-512 pastovios lentelės yra abiejuose šiuolaikiniuose dvejetainiuose failuose | 1998–2010 perskirstymo pranešimas ir atsakomybės atsisakymas |
| Brian Gladman HMAC | Tiek šiuolaikiniai taikiniai, tiek jų curl/S3 skaitytuvo kodas | Originalus trijų sąlygų pranešimas, įskaitant jo alternatyvios licencijos pastraipą |
| MD5 | Šiuolaikiniai šaltinio taikiniai; Colin Plumb įgyvendinimas aiškiai nurodo viešąjį domeną | Priskyrimas išsaugotas |
| Base64 | Markus Ewald antraštė visuose trijuose atitinkamuose šaltinio medžiuose, pridedant Bob Withers | Išsaugotas originalus autorystės priskyrimas; kvalifikacija žemiau |
| fmt | 26.10 tikslas ir fmt v11 format_error RTTI dvejetainėje | Originalus MIT pranešimas, įskaitant neprivalomą išimtį |
| tfsxml | 26.10 šaltinio tikslas | Originalus MediaArea MIT pranešimas |
| Android JNI sąsaja | JNI_OnLoad iš tikrųjų eksportuoja tiek šiuolaikinės DLLs; įtraukta JNI antraštė yra iš AOSP | AOSP autorių teisės ir visa Apache licencija 2.0 |
| libcurl | Pateikiami x86 dvejetainiai failai; faktinės versijos eksportas; dinamiškai naudojamas šiuolaikinių MediaInfo | Originalūs curl pranešimai apie 8.11.0 ir 7.47.1 |
| Oficialūs ataskaitų vertimai | Visi 38 nepakeisti CSV šaltiniai iš MediaInfo v26.10 kalbų katalogo; 37 ne anglų kalbos lentelės yra įdėtos, o anglų kalba naudoja DLL numatytuosius nustatymus | Tas pats projekto BSD-2-Clause pranešimas išliko bendrame pranešime |
| MediaInfo piktogramą | Nepakeista oficiali kelių vaizdų piktograma, šaltinio versija f057dd3649bc8692a83863b67770e22c9b9dd81a | Originalus BSD-2-Clause pranešimas ir priskyrimas |
| libwebp | WebPEncodeLosslessBGRA, WebPFree; 1.1.0; x86 | BSD-3-Clause; PATENTS |

Atitinkami šaltinio tikslai nustato įtraukimą į tas ankstesnių kūrimo konfigūracijas; jie neįrodo, kad
kiekviena funkcija išlieka optimizuota tiekėjo dvejetainiuose failuose. Priklausomybėms, kurių peržiūra
neįrašyta tuose dvejetainiuose failuose, tikslios versijos reikalavimas neteikiamas.

### Pasirenkami komponentai ir sistemos bibliotekos

- Windows bibliotekos projektai įgalina vykdymo laiką įkeltą libcurl, skirtą MediaInfo 26.10 ir 21.03.
  MediaInfo 0.7.60 buvo sukurtas naudojant MEDIAINFO_LIBCURL_NO; jo dvejetainėje programoje taip pat yra
  neįgaliojo palaikymo diagnostika. Žiūrovas niekada neranda, neištraukia ir neįkelia tos komplektuotos
  versijos curl.
- libmms yra išjungtas visuose trijuose pateiktuose Windows DLLs, kaip patvirtina jų įterptieji išjungto
  palaikymo pranešimai. Jis neperskirstomas.
- Qt ir wxWidgets priklauso pasirenkamoms GUI versijoms. Nė vienas nėra įtrauktas į šią peržiūros priemonę
  arba į šias DLL priklausomybes. Jų bendrieji įrašai buvo pašalinti iš rodomos licencijos.
- Graphviz yra pasirenkamas vykdymo laiko kabliukas šiuolaikiniame aukštesnio srauto kode. Graphviz DLL nėra
  perskirstytas.
- Joks FFmpeg papildinys nėra perskirstytas.
- MediaInfo DLLs tiesiogiai importuoja tik KERNEL32.dll. Tai nereiškia, kad nėra jų statiškai susieto vykdymo
  laiko ir pagalbinio kodo.
- Dabartinis curl tiesiogiai importuoja WS2_32.dll, bcrypt.dll, ADVAPI32.dll, CRYPT32.dll ir KERNEL32.dll. XP
  curl tiesiogiai importuoja WS2_32.dll, WLDAP32.dll, ADVAPI32.dll ir KERNEL32.dll. Tai yra Windows
  komponentai. Jų prieinamumą tikrina Windows krautuvas.
- Curl praneša Windows Schannel/WinSSL, o ne OpenSSL statymą. Jo pranešta papildoma glaudinimo priklausomybė
  yra statiškai įtraukta zlib. Jokių papildomų išorinių ne Windows DLL tiesioginio importavimo lentelėje nėra.
- Pati peržiūros priemonė neturi C/C++ vykdymo laiko priklausomybės. Pateiktose trečiosios šalies DLLs yra jų
  pačių sudarytos vykdymo laiko dalys. Windows versijose naudojami Microsoft įrankiai; nėra jokių įrodymų, kad
  būtų reikalingi bendrieji libstdc++ arba libc++ inventoriaus įrašai.
- JPEG naudoja dinamiškai įkeliamą sistemą GDI+. C# išteklių pakuotojas ir PowerShell yra kūrimo įrankiai ir
  nėra vykdymo laiko priklausomybės.

Įprastam vietinio failo patikrinimui nereikia MediaArea serverio arba nuotoliniu būdu atsisiųstos formato
duomenų bazės. libcurl naudoja MediaInfo URL įvestims ir galimai nuotolinėms nuorodoms palaikomuose medijos
formatuose. Ją sujungus, šiai peržiūros programai nepridedama atskira URL atidarymo komanda.

### Licencijos saugojimas ir apribojimai

Vienintelis palaikomas platinimo pranešimas yra [license.txt](../license.txt) , užkoduotas kaip UTF-8 su CRLF.
Patikrintos BSD, curl, zlib, MIT ir Apache perskirstymo sąlygos nereikalauja atskiro pranešimo failo fiziškai
šalia kiekvieno DLL; bendras pranešimas pridedamas prie jų vykdomojoje ir platinimo medžiagoje.

Archyvuotas MediaInfo 0.7.60 paketas naudoja savo versijos licenciją ir apima seną GNU Library GPL tekstą. Jo
sąlygos aiškiai atskiria nemodifikuotą dvejetainį perskirstymą nuo modifikuotų versijų; Šios peržiūros
priemonės dinaminis susiejimas nekeičia pateikto DLL. Išsaugomos originalios sąlygos ir pridedamas licencijos
tekstas. Žiūrovas lieka MIT licencijuotas.

Vienam ankstesniam priskyrimui reikalinga kvalifikacija: Markus Ewald Base64 antraštė neturi aiškaus leidimo
ar licencijos pareiškimo. MediaArea aprašo Bob Withers Base64 įgyvendinimą kaip viešąjį domeną susijusioje
MediaConch dokumentacijoje, tačiau tai atskirai nenustato licencijos suteikimo kiekvienam Ewald pakeitimui.
Šiai antraštei nebuvo sugalvota licencija. Pateiktuose dvejetainiuose failuose nebuvo išsamaus pardavėjo
patvirtinimo apie šią kilmę, tikslius ZenLib pakeitimus ir curl plėtrą commit. Šie punktai neleidžia šio
inventoriaus laikyti užbaigtu, nepriklausomai sertifikuotu SBOM.

### Pirminiai šaltiniai

- [MediaInfo perskirstymo sąlygos](https://mediaarea.net/en/MediaInfo/License)
- 
  [MediaInfo 26.10 bibliotekos tikslas](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Project/MSVC2022/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 21.03 bibliotekos tikslas](https://github.com/MediaArea/MediaInfoLib/blob/v21.03/Project/MSVC2015/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 0.7.60 bibliotekos tikslas](https://github.com/MediaArea/MediaInfoLib/blob/v0.7.60/Project/MSVC2005/Library/MediaInfoLib.vcproj)
- 
  [Vykdymo laikas curl krautuvas](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Source/MediaInfo/Reader/Reader_libcurl.cpp)
- 
  [Sugrupuoti pagalbiniai šaltiniai ir jų pranešimai](https://github.com/MediaArea/MediaInfoLib/tree/v26.10/Source/ThirdParty)
- [ZenLib pranešimas](https://github.com/MediaArea/ZenLib/blob/master/License.txt)
- [zlib šaltinio pranešimai](https://github.com/madler/zlib/blob/v1.3.2/zlib.h)
- [curl 8.11.0 pranešimas](https://github.com/curl/curl/blob/curl-8_11_0/COPYING)
- [curl 7.47.1 pranešimas](https://github.com/curl/curl/blob/curl-7_47_1/COPYING)
- [Apache licencija 2.0](https://www.apache.org/licenses/LICENSE-2.0)
- [MediaArea Base64 aprašymas](https://github.com/MediaArea/MediaConch/blob/master/README.md)

Ataskaitų lentelės gaunamos iš
<https://github.com/MediaArea/MediaInfo/tree/v26.10/Source/Resource/Plugin/Language> . Atitinkamas projektas
LICENSE yra <https://github.com/MediaArea/MediaInfo/blob/v26.10/LICENSE> .

- [libwebp 1.1.0 COPYING](https://github.com/webmproject/libwebp/blob/v1.1.0/COPYING)
- [libwebp 1.1.0 PATENTS](https://github.com/webmproject/libwebp/blob/v1.1.0/PATENTS)
