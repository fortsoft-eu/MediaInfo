# MediaInfo Viewer

[Čeština](README.cs-CZ.md) | [English (US)](../README.md) | [English (UK)](README.en-GB.md) | [English (Australia)](README.en-AU.md) | [Deutsch](README.de-DE.md) | [Français](README.fr-FR.md) | [Español](README.es-ES.md) | [Italiano](README.it-IT.md) | [Português](README.pt-PT.md) | [Polski](README.pl-PL.md) | [Slovenčina](README.sk-SK.md) | [Dansk](README.da-DK.md) | [Suomi](README.fi-FI.md) | [Íslenska](README.is-IS.md) | [Norsk (bokmål)](README.nb-NO.md) | [Svenska](README.sv-SE.md) | [Türkçe](README.tr-TR.md) | [Eesti](README.et-EE.md) | [Gaeilge](README.ga-IE.md) | [Lietuvių](README.lt-LT.md) | [Latviešu](README.lv-LV.md) | [Magyar](README.hu-HU.md) | **Malti** | [Nederlands](README.nl-NL.md) | [Română](README.ro-RO.md) | [Ελληνικά](README.el-GR.md) | [Bosanski](README.bs-Latn-BA.md) | [Hrvatski](README.hr-HR.md) | [Slovenščina](README.sl-SI.md) | [Crnogorski](README.cnr-Latn-ME.md) | [Беларуская](README.be-BY.md) | [Български](README.bg-BG.md) | [Македонски](README.mk-MK.md) | [Српски](README.sr-Cyrl-RS.md) | [Українська](README.uk-UA.md) | [Русский](README.ru-RU.md)

Werrej nattiv ta’ Windows x86 għar-rapporti ta’ MediaInfo.dll. Kull fajl għandu tab tiegħu għall-qari biss.

[Bini u kompatibbiltà](#kumpilazzjoni) | [Verifika tad-dipendenzi](#dipendenzi) | [Liċenzja](../license.txt)

## Kumpilazzjoni

Iftaħ MediaInfo.sln f'Visual Studio 2015 bis-sett ta' għodda Visual C++ v140 installat. Agħżel Release | Win32 u ibni s-soluzzjoni. L-unika pjattaforma tal-applikazzjoni hija Win32 (x86).

[PCRE2 10.49](https://github.com/PCRE2Project/pcre2/tree/pcre2-10.49) — UTF-16, marbut statikament,
BSD-3-Clause. [Kodiċi tas-sors](../MediaInfo/PCRE2/).
[license.txt](../license.txt).
PCRE2 hija integrata fil-fajl EXE u ma teħtieġx DLL separata jew installazzjoni addizzjonali.

Outputs:

- Release\MediaInfo.exe
- Debug\MediaInfo.exe

It-telespettatur ma jgħaqqadx ir-runtime C jew C++ u m'għandux bżonn MSVC redistributable. Il-MediaInfo.dll
magħżul jista' jkollu d-dipendenzi tiegħu stess.

Il-bini jeħtieġ Windows PowerShell u .NET Framework. Dawn huma rekwiżiti tal-bini biss; l-eżekutibbli nattiv
ma jeħtieġ la PowerShell u lanqas .NET.

### Pakkett tad-distribuzzjoni

Wara li tibni Release, mexxi `powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\PackageRelease.ps1` .
L-iskrittura toħloq `MediaInfo-<version>-win32.zip` fid-direttorju tas-soluzzjoni, billi tuża l-verżjoni
tal-fajl b'erba' partijiet tal-eżekutibbli. L-arkivju fih `MediaInfo.exe` u l-`license.txt` magħquda
direttament fl-għerq tiegħu.

## Kompatibilità

It-telespettatur Win32 huwa ddisinjat biex juża Windows NT 4.0 APIs.

L-eżekutibbli jinkludi tliet libreriji x86 MediaInfo: 26.10 għal Windows attwali, 21.03 mill-pakkett Windows
XP u 0.7.60 mill-pakkett Windows 95–2000. L-arkitettura ta' librerija waħedha ma tiddeterminax
il-kompatibilità tas-sistema operattiva tagħha. It-telespettatur jipprova l-libreriji miġbura mill-aktar ġodda
għall-eqdem u jieqaf wara l-ewwel mistoqsija ta' tagħbija u verżjoni b'suċċess.

Windows 95 bħalissa mhix runtime appoġġjata.

## Użu

- Fajl > Miftuħ (Ctrl+O) jiftaħ id-djalogu tal-fajl Windows b'għażla multipla. Fuq Windows Vista u aktar tard,
  Iftaħ u Ħlief uża d-Djalogu tal-Oġġett Komuni modern; Windows anzjani jużaw id-djalogu komuni tal-wirt.
- Iddreggja fajl wieħed jew aktar fit-tieqa, fuq l-ikona tal-EXE jew fuq ix-shortcut tiegħu, jew għaddi
  l-mogħdijiet mil-linja tal-kmand. Jekk ma jkunux permessi diversi istanzi, il-fajls jinfetħu fit-tieqa li
  diġà qed taħdem.
- Kull mogħdija sħiħa normalizzata distinta għandha tab waħda. Il-ftuħ mill-ġdid ta' fajl diġà miftuħ jagħżel
  it-tab eżistenti tiegħu mingħajr ma jerġa' jgħabbi jew ibiddel ir-rapport, l-għażla jew il-pożizzjoni
  tal-iscroll tiegħu. Il-paraguni jinjoraw il-każ tal-ittra tal-passaġġ. Ftuħiet ta' fajls multipli
  jipproċessaw il-lista fl-ordni u jħallu l-aħħar fajl ipproċessat b'suċċess attiv, kemm jekk infetaħ ġdid jew
  diġà miftuħ. Meta tgħaddi fuq header tat-tab turi l-mogħdija sħiħa tal-fajl fi tooltip nattiv, inkluż meta
  l-isem tal-fajl murija jitqassar.
- Il-menu tal-Fajl jelenka t-tmien fajls l-aktar reċentement mgħobbija direttament fuq Ħruġ, bejn
  is-separaturi. L-entrati juru biss numru u isem tal-fajl. L-għażla ta' dħul tiftaħ it-triq sħiħa maħżuna
  tagħha jew tagħżel it-tab eżistenti tagħha; ftuħ mill-ġdid b'suċċess jimxiha fil-quċċata mingħajr duplikati.
  L-għażla ta' fajl mhux disponibbli tistaqsi jekk tneħħix l-entrata tal-fajls reċenti tagħha. Jintużaw
  l-ikona tal-mistoqsija nattiva u l-buttuni Yes/No. Iva hija l-inadempjenza u tneħħi d-dħul mill-menu u
  r-reġistru; Nru iżommha. Il-pront jinkludi t-triq sħiħa.
- Ir-rota tal-maws fuq headers tat-tab li jfur tiskrollja l-istrixxa tal-header tab waħda għal kull messaġġ
  mingħajr ma tbiddel l-għażla jew il-fokus.
- Ctrl+Tab u Ctrl+Shift+Tab swiċċ tabs; Ctrl+W jagħlaq it-tab attiva. Meta tikklikkja n-nofs header tat-tab
  tagħlaq dik it-tab filwaqt li tippreserva kwalunkwe tab attiva oħra. File > Agħlaq Kollha tagħlaq kull tab,
  inklużi rapporti fil-kju. File > Ħruġ (Alt+F4) jagħlaq l-applikazzjoni.
- Il-menu tal-kuntest tal-intestatura ta’ tab jinkludi Agħlaq it-tab. Attiva Agħlaq it-tabs b’ikklikkjar
  doppju fil-Preferenzi biex tagħlaq tab billi tikklikkja darbtejn fuq l-intestatura tagħha. L-għażla
  hija mitfija b’mod predefinit u tinżamm.
- Ikklikkjar doppju fit-test tar-rapport jagħżel kelma. Tliet klikks jagħżlu linja loġika. It-tkaxkir
  jestendi l-għażla b’kliem jew linji.
- Ctrl+A jagħżel ir-rapport; Ctrl+C tikkopjaha.
- Editja > Sib (Ctrl+F) ifittex fit-tab tar-rapport attiva jew fiż-żona tat-test ta’ Għajnuna jew Dwar,
  skont liema tieqa għandha l-fokus. It-tieqa tat-tiftix iżżomm l-aħħar sors magħżul waqt li għandha
  l-fokus. F3 jirrepeti t-tfittxija; Shift+F3 jaqleb id-direzzjoni tagħha. Meta jintlaħaq tarf tat-test,
  it-tfittxija tkompli mit-tarf l-ieħor. Għażliet > Kebbeb il-kliem japplika biss għat-tab attiva;
  il-marka ssegwi t-tab magħżula. It-tieqa tat-tfittxija tista’ tiġi minimizzata u jinbidel il-wisa’
  tagħha; il-pożizzjoni u l-għażla Dejjem fuq nett jinżammu. Sa 30 test tat-tfittxija bl-għażliet
  tagħhom jinżammu biss sakemm tingħalaq l-applikazzjoni. L-għażliet tal-bidu u tat-tmiem japplikaw
  għal-linji loġiċi. L-espressjonijiet regolari jużaw is-sintassi ta’ PCRE2. Il-kmandi l-oħra fil-menu
  Editja japplikaw għat-tab tar-rapport attiva. Enter jibda t-tfittxija; Shift+Enter jaqleb
  id-direzzjoni magħżula. “Iddistingwi ittri kbar u żgħar” tiddistingwi bejn ittri kbar u żgħar; “Fittex
  lura” tfittex lejn il-bidu tat-test. Meta tagħżel entrata mill-istorja, jerġgħu jiġu applikati l-ħames
  għażliet tat-tfittxija, inkluż l-istat tal-modalità tal-espressjonijiet regolari; “Dejjem fuq nett”
  hija indipendenti. “Espressjoni regolari” tiddiżattiva “Il-linja tibda bi” u “Il-linja tispiċċa bi”.
  Meta ż-żewġ għażliet tat-truf tal-linja jkunu attivi, biżżejjed qbil f’tarf wieħed. “Kebbeb il-kliem”
  tbiddel biss il-wiri.
- Settings > Preferenzi (Ctrl+G) jiftaħ djalogu tal-preferenzi wieħed għal mogħdijiet MediaInfo u curl, font
  tar-rapport, antialiasing tat-tipa, lingwa tal-interface u lingwa tar-rapport. Mogħdija DLL vojta
  tippermetti skoperta awtomatika.
- Il-buttuna tat-tipa turi l-familja, id-daqs tal-punt u l-istil u tiftaħ id-djalogu tat-tipa standard
  Windows. Default jirrestawra Consolas, jew Courier New jekk Consolas ma jkunx disponibbli; il-buttuna
  Default hija diżattivata filwaqt li l-default hija magħżula. Il-fonts magħżula mill-utent jinżammu mingħajr
  sostituzzjoni bil-kodiċi tal-applikazzjoni.
- Għażliet antialiasing tat-tipa huma ClearType meta appoġġjati, GDI u Xejn. L-għażla inizjali hija
  ClearType meta appoġġjata, inkella GDI. Is-settings tat-tipa japplikaw għat-tabs tar-rapporti,
  għall-esportazzjoni tagħhom bħala stampi u għall-istampar tar-rapporti. Għajnuna u Dwar iżommu t-tipi
  tat-test tagħhom stess.
- Għajnuna tiftaħ tieqa separata bla mudell bid-dħul tagħha stess u l-buttuna timminimizza tat-taskbar. Dwar
  huwa dialog modali; l-intestatura tal-prodott tagħha telenka t-tliet verżjonijiet DLL inkorporati.

Fajl > Issettjar tal-Paġna… jiftaħ l-għażliet tal-karta, l-orjentazzjoni u l-marġini għas-sessjoni
attwali. Stampa… (Ctrl+P) jiftaħ id-djalogu tal-istampar tas-sistema; Windows 11 juri previżjoni,
filwaqt li Windows 10 u verżjonijiet eqdem iżommu d-djalogu klassiku. Ctrl+P jistampa t-tab attiva
tat-tieqa ewlenija jew iż-żona tat-test ta’ Għajnuna jew Dwar, skont liema tieqa għandha l-fokus.
Ir-rapporti jużaw it-tipa magħżula għar-rapport, Għajnuna tuża t-tipa tad-djalogi tas-sistema u Dwar
juża t-tipa taż-żona tat-test tiegħu. Jekk ma hemmx tabs miftuħa iżda Għajnuna hija miftuħa, Issettjar
tal-Paġna… u Stampa… jibqgħu disponibbli; Stampa… jistampa l-għajnuna. Għajnuna tuża d-djalogu
tal-istampar tat-tieqa ewlenija; Ctrl+P ieħor f’Għajnuna jġib l-istess djalogu fuq quddiem. Il-linji
twal jitqassmu u t-test jinqasam f’paġni. L-istampar isir fl-isfond.

Iftaħ folder… jiftaħ il-fajls li jinsabu direttament fil-folder magħżul, kull wieħed fit-tab tiegħu.
Is-subfolders mhumiex inklużi. Iftaħ u Iftaħ folder jużaw l-istess folder magħżul l-aħħar. L-esportazzjoni
tiftakar il-folder tagħha, Dokumenti b’mod predefinit.

Il-modalità avvanzata turi oqsma addizzjonali fir-rapport.

Analiżi sħiħa jeżamina l-fajl kollu u jista’ jieħu aktar żmien. Dawn l-għażliet tar-rapport u Livell ta’
traċċar huma separati għal kull tab; bidla taġġorna biss it-tab attiva. L-aħħar kombinazzjoni magħżula
manwalment tiġi ssejvjata għal tabs ġodda u għall-ftuħ tal-applikazzjoni li jmiss. Rapport korrispondenti
fil-cache jerġa’ jintuża sakemm il-fajl ma jkunx inbidel.

Formati magħrufa, Codecs magħrufa u Parametri magħrufa jinfetħu fit-tabs tar-rapport tagħhom.

Id-daqs inizjali tat-tieqa u l-post jintgħażlu minn Windows. It-tqegħid tat-tieqa ssejvjat qabel jegħleb dawk
in-nuqqasijiet fuq tnedijiet aktar tard.

In-naħa tax-xellug tal-istrixxa tal-istatus turi l-mogħdijiet tal-fajls u l-progress tat-tagħbija; in-naħa
tal-lemin turi l-verżjoni ta’ MediaInfo.dll mgħobbija. Mogħdijiet twal jitqassru b’punti ta’ sospensjoni skont
l-ispazju disponibbli.

## Oħloq Fajl tal-Intestatura

Il-menu Għodod huwa r-raba’ fil-bar tal-menus. Il-kmand Oħloq Fajl tal-Intestatura… jiftaħ fajl tad-dħul
wieħed indipendentement mit-tabs tar-rapport u jikkopja l-ewwel 524288 byte tiegħu (512 KiB). Fajl iqsar jiġi
kkupjat kollu; fajl vojt jipproduċi fajl tal-ħruġ vojt. Dan huwa qari binarju ordinarju tal-fajl, mingħajr
analiżi ta’ MediaInfo u mingħajr il-ħtieġa ta’ MediaInfo.dll. L-għodda ma tbiddilx it-tabs tar-rapport jew
il-lista tal-fajls reċenti tal-programm.

Wara l-qari, id-djalogu Issejvja bħala jiftaħ fil-fowlder tal-fajl tad-dħul u jipproponi video.mp4.header għal
video.mp4: .header jiżdied mal-isem oriġinali sħiħ. Tista’ tibdel kemm l-isem kif ukoll il-fowlder
tad-destinazzjoni. Jekk tikkanċella kwalunkwe wieħed mid-djalogi, ma jinkiteb ebda fajl tal-ħruġ. Biex
jinbidel fajl tad-destinazzjoni eżistenti hemm bżonn konferma. Il-fajl tad-dħul jibqa’ l-istess; jekk
l-issejvjar ifalli, il-fajl tad-destinazzjoni preċedenti jibqa’ l-istess. Għall-ftuħ u l-issejvjar jintużaw
l-aktar djalogi tas-sistema moderni disponibbli f’dik il-verżjoni tal-Windows.

Meta tibda l-applikazzjoni, l-għodda tieħu l-istess fowlder inizjali bħal Fajl > Iftaħ. Jekk ma jkun hemm ebda
fowlder issejvjat, Windows jagħżel il-post inizjali. Wara li jintgħażel fajl tad-dħul, l-għodda tiftakar
il-fowlder tagħha biss sakemm tingħalaq l-applikazzjoni, anki jekk tikkanċella Issejvja bħala. Ma tbiddilx
il-fowlders ta’ Iftaħ u Esporta u ma tissejvjax il-fowlder tagħha fis-settings tal-applikazzjoni. Kull djalogu
Issejvja bħala jibda fil-fowlder tal-fajl tad-dħul magħżul bħalissa, irrispettivament mid-destinazzjoni
preċedenti.

## Skoperta tal-librerija

L-ewwel tiġi ppruvata mogħdija manwali salvata. Jekk ma tistax titgħabba, l-iskoperta awtomatika tipprova:

1. MediaInfo.dll ħdejn l-eżekutibbli, imbagħad f'kull direttorju ġenitur sa l-għerq tas-sehem drive jew UNC.
2. ProgramFiles, ProgramFiles(x86) u ProgramW6432.
3. LOCALAPPDATA u APPDATA.

Taħt dawn l-għeruq ta' installazzjoni, kontrolli ta' skoperta MediaInfo, MediaArea\MediaInfo, MediaArea,
MediaArea.net\MediaInfo, Programs\MediaInfo, Programs\MediaArea\MediaInfo. Postijiet li ma jinqrawx u DLLs
inkompatibbli jinqabżu. Ma tiskennjax id-diska b'mod rikorsiv.

Jekk ma jinstab l-ebda DLL estern kompatibbli, it-telespettatur jipprova l-verżjonijiet inkorporati f'din
l-ordni: 26.10, 21.03, 0.7.60. Huwa estratti u jittestja verżjoni waħda kull darba. Ladarba verżjoni titgħabba
b'suċċess, verżjonijiet eqdem la jiġu estratti u lanqas ittestjati. Tqassam MediaInfo.exe waħdu huwa
biżżejjed; DLL estern kompatibbli dejjem jieħu prijorità u jista' jiġi aġġornat b'mod indipendenti.

Bidla tal-librerija manwali falluta żżomm il-librerija li kienet diġà mgħobbija.

## Esportazzjoni tar-rapporti

Il-formati Save As huma ordnati TXT, BMP, GIF, JPEG, PNG, TIFF u WebP. Encoders mhux appoġġjati jitħallew
barra kemm mid-djalogi moderni kif ukoll mill-wirt.

TXT joffri ANSI, UTF-8, UTF-8 b’BOM, UTF-16 BE b’BOM u UTF-16 LE b’BOM. It-tieni għażla, UTF-8 mingħajr BOM,
hija dik predefinita. It-test sħiħ tar-rapport u t-truf tal-linji oriġinali jinżammu.

BMP, PNG u TIFF jippreservaw il-kuluri kollha mogħtija; GIF89a jippreserva l-paletta mogħtija eżatta meta
l-immaġni jkollha l-aktar 256 kuluri. L-esportazzjoni dejjem tikteb il-format magħżul jew tirrapporta żball;
qatt ma jissostitwixxi format ieħor.

## Lingwi tal-interface u tar-rapport

Il-preferenzi (Settings > Preferenzi, Ctrl+G) fihom il-mogħdijiet tal-libreriji, il-font tar-rapport,
l-antialiasing u l-lingwi. L-interfaċċa għandha 36 varjant u inizjalment issegwi Windows. Ir-rapporti dejjem
jużaw l-Ingliż oriġinali tal-librerija b’mod predefinit, indipendentement minn Windows u l-interfaċċa. Għażla
manwali biss tibdlu: Ingliż, 37 traduzzjoni jew tabella CSV MediaInfo personalizzata.

OK jew Applika jikkonferma l-bidliet; Ikkanċella jwarrab dawk pendenti. Il-preferenzi jissettjaw il-limitu
tat-tul tal-isem tat-tab (80 b’mod predefinit) u jħassru l-lista tal-fajls riċenti. Ismijiet twal iżommu
l-bidu, it-tmiem u l-estensjoni b’ellissi fin-nofs.

B’mod awtomatiku hija permessa istanza waħda biss u tnedijiet sussegwenti jibagħtu l-fajls lit-tieqa miftuħa.
Fil-preferenzi tista’ tippermetti diversi istanzi. B’diversi twieqi, l-ewwel tieqa ta’ kull formola biss
tirrestawra l-pożizzjoni ssejvjata; it-twieqi ta’ wara jirrestawraw biss id-daqs.

Il-bidla tal-interface biss tħalli t-test tar-rapporti miftuħa mhux mibdul. Bidla fil-lingwa tar-rapport
applikata manwalment terġa' tgħabbi r-rapporti tagħhom filwaqt li tippreserva l-ordni tat-tab u l-ordni MRU.

## libcurl

Kontrolli awtomatiċi ta' skoperta curl ħdejn il-MediaInfo DLL magħżula, imbagħad il-executable/ancestor
kondiviżi, Fajls tal-Programm u postijiet ta' installazzjoni tal-utent. Jekk ma jinstab l-ebda curl estern
kompatibbli, il-verżjoni inkorporata kurrenti jew XP li tqabbel tiġi estratta fil-cache ċċekkjata għal kull
utent. L-eqdem MediaInfo 0.7.60 jevita l-iskoperta, l-estrazzjoni u t-tagħbija għal curl għal kollox. curl
invalidu magħżul espliċitament jirrifjuta l-bidla tal-preferenza; curl awtomatiku fakultattiv nieqes ma
jipprevjenix rapporti ordinarji tal-fajl lokali.

## Ismijiet tal-fajls u fajls riċenti

L-ismijiet tal-fajls MRU jitqassru biss meta jkunu itwal minn unitajiet tal-kodiċi 80 UTF-16. Elipsi tan-nofs
tippreserva l-bidu, it-tmiem tal-isem tal-fajl qabel l-estensjoni tiegħu u l-estensjoni finali sħiħa;
mogħdijiet u rapporti sħaħ jibqgħu l-istess. It-titoli tat-tab jużaw l-istess algoritmu b'limitu default
konfigurabbli ta' 80.

Fajls riċenti > Ċar immedjatament ineħħi kemm il-menu MRU ħajjin kif ukoll il-mogħdijiet ssejvjati tiegħu
filwaqt li jħalli t-tabs miftuħa kollha intatti. Ma japplikax jew jivvalida preferenzi pendenti u ma
jippermettix Applika. Ikkanċella jew Escape jippreserva l-istorja mneħħija filwaqt li jarmi l-editjar
pendenti. Clear huwa diżattivat kull meta l-lista tkun vojta, u l-istat tagħha jiġi aggornat meta rapporti
ġodda jimtlew il-lista. Ħsara fil-kitba tar-reġistru tiġi rrappurtata immedjatament. L-applikazzjoni ta'
limitu ġdid tal-isem tat-tab taġġorna kull tab miftuħa mingħajr ma terġa' tgħabbi r-rapport tal-midja tagħha.

## Liċenzja u distribuzzjoni mill-ġdid

It-telespettatur huwa liċenzjat taħt il-Liċenzja MIT fi license.txt.

MediaInfo huwa komponent ta' parti terza. L-uniku avviż ta' distribuzzjoni miżmum huwa root license.txt,
kodifikat bħala UTF-8 b'CRLF u li jinkludi t-telespettatur, il-libreriji, il-komponenti inkorporati
statikament, l-ikona u t-tabelli tat-traduzzjoni uffiċjali.

Dan il-prodott juża l-librerija MediaInfo, Copyright (c) 2002-2026 MediaArea.net SARL.

- MediaInfo: <https://mediaarea.net/MediaInfo>
- Liċenzja: <https://mediaarea.net/en/MediaInfo/License>
- Windows downloads: <https://mediaarea.net/en/MediaInfo/Download/Windows>

## Dipendenzi

### Fajls

| Riżorsa | Arkitettura | Verżjoni rrappurtata mill-komponent | SHA-256 |
| --- | --- | --- | --- |
| Resources/lib/26.10/MediaInfo.dll | x86 | 26.10 | E73027A1577084135425AA013D46C8B2985AD142CCF04F1ADB301B9A9CFB78F8 |
| Resources/lib/21.03/MediaInfo.dll | x86 | 21.03 | EBBF1C371702F3DC39CA23D619C47EDF97E66A95AEABE725284F1402D8F3E58A |
| Resources/lib/0.7.60/MediaInfo.dll | x86 | 0.7.60 | A26C07BCC25FA01A40E6888D02EABD59AA8DB2ABF6F5195481228D3A91D04441 |
| Resources/lib/26.10/libcurl.dll | x86 | 8.11.0-DEV, Schannel, zlib 1.3.1 | DCF136C84F3A4FBEAE2B317FE36D7F11225B56FBA3343AF4BBA8706B3F46F334 |
| Resources/lib/21.03/libcurl.dll | x86 | 7.47.1, WinSSL, zlib 1.2.8 | 21025CAC8089F1E570EE083D8CFD6311C2C51E97094A9FCD8C7A0B544C22CB48 |
| Resources/lib/libwebp.dll | x86 | 1.1.0 | 9986023BB6FF5510A157919F0CD958A94800EC6A1D981F3403A9648BEDFEE575 |

Il-mogħdijiet fit-tabella huma relattivi għad-direttorju tal-proġett MediaInfo.

Il-librerija attwali tirrapporta verżjoni ta' żvilupp; is-sors eżatt tiegħu commit ma jistax jiġi rkuprat minn
dik is-sekwenza tal-verżjoni. L-avviż ta' akkumpanjament tiegħu juża t-test tal-awtur u permess upstream
8.11.0, li t-termini tal-liċenzja tiegħu huma preżenti wkoll fis-serje ta' żvilupp.

### Komponenti inkorporati

| Komponent | Evidenza u skop | Avviż |
| --- | --- | --- |
| MediaInfoLib | Verżjonijiet attwali u esportazzjonijiet Unicode meħtieġa; binarji fornuti mhux mibdula | Copyright oriġinali speċifiċi għall-verżjoni, kundizzjonijiet ta’ distribuzzjoni mill-ġdid u ċaħda ta’ responsabbiltà |
| ZenLib | Referenzi tal-proġetti statiċi u ZenLib RTTI inkorporati fit-tliet DLLs; reviżjonijiet konnessi eżatti mhux fornuti | Avviż zlib-style ZenLib |
| zlib | Kordi tal-verżjoni inflate/deflate inkorporati: 1.3.2 f'MediaInfo 26.10, 1.2.11 f'21.03, 1.2.7 f'0.7.60; curl tirrapporta wkoll 1.3.1 u 1.2.8 | Avviżi zlib oriġinali għall-ħames verżjonijiet kollha |
| TinyXML-2 | Tqabbil ta' miri tas-sors moderni u RTTI binarju; inklużi fil-proġett tal-legat, iżda mhux identifikati b'mod indipendenti fil-binarju tal-legat imqaxxar | Avviż oriġinali stil Lee Thomason zlib miżmuma |
| Brian Gladman AES | Inkluż fiż-żewġ miri moderni tal-librerija upstream, b'avviżi tas-sors permissivi li jaqblu | 1998–2013 avviż ta' ridistribuzzjoni u ċaħda |
| Brian Gladman SHA-1/SHA-2 | Iż-żewġ miri moderni; SHA-256 u SHA-512 tabelli kostanti preżenti fiż-żewġ binarji moderni | 1998–2010 avviż ta' ridistribuzzjoni u ċaħda |
| Brian Gladman HMAC | Kemm il-miri moderni kif ukoll il-kodiċi tal-qarrej curl/S3 tagħhom | Avviż oriġinali bi tliet kundizzjonijiet, inkluż il-paragrafu tal-liċenzja alternattiva tiegħu |
| MD5 | Miri tas-sors moderni; Colin Plumb implimentazzjoni tiddikjara espliċitament dominju pubbliku | Attribuzzjoni miżmuma |
| Base64 | Markus Ewald header fit-tliet siġar tas-sors korrispondenti, li jikkredita Bob Withers | L-attribuzzjoni tal-awtur oriġinali miżmuma; kwalifika hawn taħt |
| fmt | 26.10 mira u fmt v11 format_error RTTI fil-binarju | Avviż oriġinali MIT, inkluża eċċezzjoni fakultattiva |
| tfsxml | 26.10 mira tas-sors | Avviż oriġinali MediaArea MIT |
| Android JNI interface | JNI_OnLoad huwa attwalment esportat kemm minn DLLs moderni; l-header JNI inkluż huwa minn AOSP | AOSP awtur u Liċenzja Apache kompluta 2.0 |
| libcurl | Forniti x86 binarji; esportazzjonijiet tal-verżjoni attwali; użat dinamikament minn MediaInfo modern | Avviżi curl oriġinali għal 8.11.0 u 7.47.1 |
| Traduzzjonijiet uffiċjali tar-rapporti | Is-sorsi kollha 38 mhux modifikati CSV mid-direttorju tal-lingwa MediaInfo v26.10; 37 tabelli mhux bl-Ingliż huma inkorporati, filwaqt li l-Ingliż juża DLL defaults | L-istess avviż tal-proġett BSD-2-Clause miżmum fl-avviż magħqud |
| ikona MediaInfo | Ikona uffiċjali b'ħafna immaġini mhux modifikata, reviżjoni tas-sors f057dd3649bc8692a83863b67770e22c9b9dd81a | Avviż oriġinali BSD-2-Clause u attribuzzjoni |
| libwebp | WebPEncodeLosslessBGRA, WebPFree; 1.1.0; x86 | BSD-3-Clause; PATENTS |

Il-miri tas-sors li jaqblu jistabbilixxu l-inklużjoni f'dawk il-konfigurazzjonijiet tal-bini upstream; ma
jipprovawx li kull funzjoni tgħix ottimizzazzjoni fil-binarji tal-bejjiegħ. Ma ssir l-ebda talba ta' verżjoni
eżatta għal dipendenzi li r-reviżjoni tagħhom mhix irreġistrata f'dawk il-binarji.

### Komponenti fakultattivi u libreriji tas-sistema

- Il-proġetti tal-librerija Windows jippermettu libcurl runtime-loaded għal MediaInfo 26.10 u 21.03. MediaInfo
  0.7.60 inbniet b'MEDIAINFO_LIBCURL_NO; binarju tagħha fih ukoll id-dijanjostika ta' appoġġ għal persuni
  b'diżabilità. It-telespettatur qatt ma jiskopri, estratti jew jgħabbi curl għal dik il-verżjoni miġbura.
- libmms hija diżattivata fit-tliet Windows DLLs fornuti, kif ikkonfermat mill-messaġġi inkorporati tagħhom
  ta' appoġġ għal persuni b'diżabilità. Mhux imqassam mill-ġdid.
- Qt u wxWidgets jappartjenu għal GUI builds fakultattivi. L-ebda waħda hija inkluża f'dan it-telespettatur
  jew f'dawn id-dipendenzi DLL. L-entrati ġeneriċi tagħhom tneħħew mil-liċenzja murija.
- Graphviz huwa ganċ runtime fakultattiv fil-kodiċi upstream modern. L-ebda Graphviz DLL huwa mqassam
  mill-ġdid.
- L-ebda plugin FFmpeg ma huwa mqassam mill-ġdid.
- Il-MediaInfo DLLs jimporta direttament biss KERNEL32.dll. Dan ma jfissirx li l-runtime u l-kodiċi helper
  konnessi statikament tagħhom huma assenti.
- curl kurrenti jimporta direttament WS2_32.dll, bcrypt.dll, ADVAPI32.dll, CRYPT32.dll u KERNEL32.dll. XP curl
  jimporta direttament WS2_32.dll, WLDAP32.dll, ADVAPI32.dll u KERNEL32.dll. Dawn huma Windows komponenti.
  Id-disponibbiltà tagħhom hija ċċekkjata mill-loader Windows.
- Curl jirrapporta Windows Schannel/WinSSL, mhux OpenSSL build. Id-dipendenza addizzjonali tal-kompressjoni
  rrappurtata tagħha hija inkluża b'mod statiku zlib. L-ebda esterna addizzjonali mhux Windows DLL ma tidher
  fit-tabella ta' importazzjoni diretta tagħha.
- It-telespettatur innifsu m'għandu l-ebda dipendenza fuq ir-runtime C/C++. Il-DLLs fornuti ta' parti terza
  fihom il-porzjonijiet tar-runtime kkompilati tagħhom stess. Il-Windows bini juża għodda Microsoft; m'hemm
  l-ebda evidenza li teħtieġ l-entrati ġeneriċi tal-inventarju libstdc++ jew libc++.
- JPEG juża sistema dinamikament mgħobbija GDI+. Il-C# pakkjatur tar-riżorsi u PowerShell huma għodod tal-bini
  u mhumiex dipendenzi tar-runtime.

Spezzjoni ordinarja tal-fajl lokali ma teħtieġx server MediaArea jew database tal-format imniżżel mill-bogħod.
libcurl jintuża minn MediaInfo għal URL inputs u referenzi potenzjalment remoti f'formati tal-midja
appoġġjati. L-għaqda ma żżidx kmand tal-ftuħ URL separat għal dan it-telespettatur.

### Ħażna tal-liċenzja u limitazzjonijiet

L-uniku avviż ta' distribuzzjoni miżmuma huwa [license.txt](../license.txt) , kodifikat bħala UTF-8 b'CRLF.
Il-klawżoli ta' ridistribuzzjoni BSD, curl, zlib, MIT u Apache ċċekkjati ma jeħtiġux fajl ta' avviż separat
fiżikament ħdejn kull DLL; l-avviż magħqud jakkumpanjahom fil-materjali eżekutibbli u tad-distribuzzjoni.

Il-pakkett MediaInfo 0.7.60 arkivjat juża l-liċenzja speċifika għall-verżjoni tiegħu stess u jinkludi t-test
GNU Library GPL l-antik. It-termini tiegħu jiddistingwu espressament distribuzzjoni mill-ġdid binarja mhux
modifikata minn verżjonijiet modifikati; linking dinamiku minn dan it-telespettatur ma jimmodifikax il-DLL
fornut. Il-kundizzjonijiet oriġinali tiegħu u t-test tal-liċenzja li jakkumpanjawha jinżammu. It-telespettatur
jibqa' MIT-liċenzjat.

Attribuzzjoni upstream waħda teħtieġ kwalifika: l-intestatura Markus Ewald Base64 m'għandha l-ebda permess
espliċitu jew dikjarazzjoni tal-liċenzja. MediaArea jiddeskrivi l-implimentazzjoni Bob Withers Base64 bħala
dominju pubbliku fid-dokumentazzjoni MediaConch relatata tagħha, iżda dan ma jistabbilixxix b'mod indipendenti
għotja ta' liċenzja għal kull bidla Ewald. L-ebda għotja ta' liċenzja ma ġiet ivvintata għal dik
l-intestatura. Konferma sħiħa tal-bejjiegħ ta' dik il-provenjenza, ir-reviżjonijiet eżatti tal-ZenLib u
l-iżvilupp curl commit ma kinitx disponibbli fil-binarji fornuti. Dawn il-punti jipprevjenu li dan
l-inventarju jiġi ttrattat bħala SBOM komplut u ċċertifikat b'mod indipendenti.

### Sorsi primarji

- [MediaInfo termini ta' ridistribuzzjoni](https://mediaarea.net/en/MediaInfo/License)
- 
  [MediaInfo 26.10 mira tal-librerija](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Project/MSVC2022/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 21.03 mira tal-librerija](https://github.com/MediaArea/MediaInfoLib/blob/v21.03/Project/MSVC2015/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 0.7.60 mira tal-librerija](https://github.com/MediaArea/MediaInfoLib/blob/v0.7.60/Project/MSVC2005/Library/MediaInfoLib.vcproj)
- 
  [Runtime curl loader](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Source/MediaInfo/Reader/Reader_libcurl.cpp)
- 
  [Sorsi helper miġbura u l-avviżi tagħhom](https://github.com/MediaArea/MediaInfoLib/tree/v26.10/Source/ThirdParty)
- [ZenLib avviż](https://github.com/MediaArea/ZenLib/blob/master/License.txt)
- [zlib avviżi tas-sors](https://github.com/madler/zlib/blob/v1.3.2/zlib.h)
- [curl 8.11.0 avviż](https://github.com/curl/curl/blob/curl-8_11_0/COPYING)
- [curl 7.47.1 avviż](https://github.com/curl/curl/blob/curl-7_47_1/COPYING)
- [Liċenzja Apache 2.0](https://www.apache.org/licenses/LICENSE-2.0)
- [MediaArea Base64 deskrizzjoni](https://github.com/MediaArea/MediaConch/blob/master/README.md)

It-tabelli tar-rapporti ġejjin minn
<https://github.com/MediaArea/MediaInfo/tree/v26.10/Source/Resource/Plugin/Language> . Il-proġett ta' tqabbil
LICENSE huwa <https://github.com/MediaArea/MediaInfo/blob/v26.10/LICENSE> .

- [libwebp 1.1.0 COPYING](https://github.com/webmproject/libwebp/blob/v1.1.0/COPYING)
- [libwebp 1.1.0 PATENTS](https://github.com/webmproject/libwebp/blob/v1.1.0/PATENTS)
