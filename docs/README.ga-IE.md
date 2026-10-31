# MediaInfo Viewer

[Čeština](README.cs-CZ.md) | [English (US)](../README.md) | [English (UK)](README.en-GB.md) | [English (Australia)](README.en-AU.md) | [Deutsch](README.de-DE.md) | [Français](README.fr-FR.md) | [Español](README.es-ES.md) | [Italiano](README.it-IT.md) | [Português](README.pt-PT.md) | [Polski](README.pl-PL.md) | [Slovenčina](README.sk-SK.md) | [Dansk](README.da-DK.md) | [Suomi](README.fi-FI.md) | [Íslenska](README.is-IS.md) | [Norsk (bokmål)](README.nb-NO.md) | [Svenska](README.sv-SE.md) | [Türkçe](README.tr-TR.md) | [Eesti](README.et-EE.md) | **Gaeilge** | [Lietuvių](README.lt-LT.md) | [Latviešu](README.lv-LV.md) | [Magyar](README.hu-HU.md) | [Malti](README.mt-MT.md) | [Nederlands](README.nl-NL.md) | [Română](README.ro-RO.md) | [Ελληνικά](README.el-GR.md) | [Bosanski](README.bs-Latn-BA.md) | [Hrvatski](README.hr-HR.md) | [Slovenščina](README.sl-SI.md) | [Crnogorski](README.cnr-Latn-ME.md) | [Беларуская](README.be-BY.md) | [Български](README.bg-BG.md) | [Македонски](README.mk-MK.md) | [Српски](README.sr-Cyrl-RS.md) | [Українська](README.uk-UA.md) | [Русский](README.ru-RU.md)

Amharcán dúchasach Windows x86 do thuairiscí MediaInfo.dll. Tá cluaisín inléite amháin ar leith ag gach
comhad.

[Tógáil agus comhoiriúnacht](#tiomsú) | [Iniúchadh spleáchas](#spleáchais) | [Ceadúnas](../license.txt)

## Tiomsú

Oscail MediaInfo.sln in Visual Studio 2015 agus an tacar uirlisí Visual C++ v140 suiteáilte. Roghnaigh Release | Win32 agus tóg an réiteach. Is é an t-aon ardán iarratais ná Win32 (x86).

Aschuir:

- Release\MediaInfo.exe
- Debug\MediaInfo.exe

Ní nascann an t-amharcóir an t-am rite C nó C++ agus níl gá le MSVC in-athdháilte. Is féidir a spleáchais féin
a bheith ag an MediaInfo.dll roghnaithe.

Teastaíonn Windows PowerShell agus .NET Framework le tógáil. Is riachtanais tógála amháin iad seo; níl
PowerShell ná .NET ag teastáil ón inrite dúchais.

### Pacáiste dáileacháin

Tar éis Release a thógáil, rith `powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\PackageRelease.ps1`
. Cruthaíonn an script `MediaInfo-<version>-win32.zip` san eolaire réitigh, ag baint úsáide as leagan comhaid
ceithre chuid an inrite. Tá `MediaInfo.exe` sa chartlann agus an `license.txt` comhcheangailte go díreach ag a
fréamh.

## Comhoiriúnacht

Tá an t-amharcóir Win32 deartha chun Windows NT 4.0 APIs a úsáid.

Áirítear leis an inrite trí leabharlann x86 MediaInfo: 26.10 don Windows reatha, 21.03 ón bpacáiste Windows XP
agus 0.7.60 ón bpacáiste Windows 95–2000. Ní chinneann ailtireacht leabharlainne amháin comhoiriúnacht an
chórais oibriúcháin. Déanann an breathnóir iarracht na leabharlanna cuachta ón gceann is nua go dtí an duine
is sine agus stopann sé tar éis an chéad cheist maidir le hualach agus leagan rathúil.

Ní am rite tacaithe é Windows 95 faoi láthair.

## Úsáid

- Osclaíonn Comhad > Oscail (Ctrl+O) an dialóg comhad Windows le rogha iolrach. Ar Windows Vista agus níos
  déanaí, Oscail agus Sábháil úsáid an Dialóg Míreanna Coitianta nua-aimseartha; níos sine Windows bain úsáid
  as na dialóga comónta oidhreachta.
- Tarraing comhad amháin nó níos mó isteach san fhuinneog, ar dheilbhín an EXE nó ar a aicearra, nó tabhair na
  conairí ar líne na n-orduithe. Mura gceadaítear níos mó ná ásc amháin, osclaítear na comhaid san fhuinneog
  atá ag rith cheana.
- Tá cluaisín amháin ag gach cosán iomlán normalaithe ar leith. Má athosclaítear comhad atá oscailte cheana
  féin, roghnaíonn sé an cluaisín atá ann cheana féin gan a thuarascáil, a roghnú nó a shuíomh scrollaigh a
  athlódáil nó a athrú. Déanann comparáidí neamhaird ar chás litreacha cosáin. Próiseálann oscailtí ilchomhaid
  an liosta in ord agus fágtar an comhad deireanach a próiseáladh go rathúil gníomhach, bíodh sé nua-oscailte
  nó oscailte cheana féin. Nuair a théann tú os cionn ceanntásc táb, taispeántar conair iomlán an chomhaid i
  leid uirlisí dúchais, lena n-áirítear nuair a ghiorraítear ainm an chomhaid atá ar taispeáint.
- Liostaíonn an roghchlár Comhad na hocht gcomhad is déanaí a lódaíodh díreach os cionn an Scoir, idir
  deighilteoirí. Ní thaispeánann iontrálacha ach uimhir agus ainm comhaid. Má roghnaítear iontráil osclaíonn
  sé a chonair iomlán stóráilte nó roghnaíonn sé an cluaisín atá ann cheana; bogann athoscailt rathúil é go
  dtí an barr gan dúbailt. Nuair a roghnaítear comhad nach bhfuil ar fáil, fiafraítear cibé an mbainfear a
  iontráil i gcomhaid le déanaí. Úsáidtear íocón na ceiste dúchais agus na cnaipí Yes/No. Is ea an réamhshocrú
  agus baintear an iontráil ón roghchlár agus ón gclár; Ní choinníonn aon duine é. Áirítear leis an leid an
  cosán iomlán.
- Scrollaíonn roth na luiche thar cheanntásca cluaisíní cur thar maoil an stiall ceanntásc táb amháin in
  aghaidh an teachtaireachta gan roghnú ná fócas a athrú.
- lasc cluaisíní Ctrl+Tab agus Ctrl+Shift+Tab; Dúnann Ctrl+W an cluaisín gníomhach. Dúnann lárchliceáil ar
  cheanntásc cluaisín an cluaisín sin agus aon chluaisín gníomhach eile á chaomhnú. Comhad > Dún Gach Dúnann
  gach cluaisín, lena n-áirítear tuarascálacha ciúáilte. Dúnann Comhad > Scoir (Alt+F4) an feidhmchlár.
- Roghnaíonn dhá chliceáil focal. Roghnaíonn trí chliceáil líne loighciúil. Leathnaíonn tarraingt an rogha trí
  fhocail nó línte.
- roghnaíonn Ctrl+A an tuairisc; Déanann Ctrl+C cóipeáil air.
- Socruithe > Sainroghanna (Ctrl+G) osclaíonn dialóg roghanna amháin le haghaidh cosáin MediaInfo agus curl,
  cló tuairisce, frith-ailiasú cló, teanga comhéadain agus teanga tuairisce. Ligeann cosán folamh DLL
  fionnachtain uathoibríoch.
- Taispeánann an cnaipe cló an teaghlach, méid an phointe agus an stíl agus osclaíonn sé an dialóg chló
  caighdeánach Windows. Athshocróidh an réamhshocrú Consolas, nó Courier New mura bhfuil Consolas ar fáil; tá
  an cnaipe réamhshocraithe díchumasaithe agus an réamhshocrú roghnaithe. Coinnítear clónna a roghnaíonn
  úsáideoirí gan cód feidhmchláir a chur ina n-ionad.
- Is iad ClearType roghanna frithaliasaithe cló nuair a fhaigheann siad tacaíocht, GDI agus Dada. Is é
  ClearType an rogha tosaigh nuair a thacaítear leis, nó GDI. Ní bhíonn tionchar ag socruithe cló ach ar
  thuairiscí meán agus ar a n-onnmhairí íomhá.
- Comhad > Osclaíonn Easpórtáil (Ctrl+E) an dialóg Save As Windows agus easpórtálann sé an tuairisc ghníomhach
  iomlán chuig TXT, BMP, GIF, JPEG, PNG, TIFF nó WebP, lena n-áirítear téacs lasmuigh den limistéar
  infheicthe.
- Osclaíonn Help fuinneog ar leith gan mhodh lena hiontráil tascbharra féin agus an cnaipe íoslaghdaithe.
  Maidir le dialóg mhodhúil; liostaíonn ceanntásc an táirge na trí leagan leabaithe DLL ar fad.

Osclaíonn Priontáil… (Ctrl+P) dialóg printéara an chórais agus priontálann sé an cluaisín gníomhach iomlán gan
réamhamharc. Úsáidtear cló na tuairisce; filltear línte fada agus roinntear an téacs ina leathanaigh. Ritheann
priontáil sa chúlra.

Osclaíonn Oscail fillteán… na comhaid atá go díreach san fhillteán roghnaithe, gach ceann ina chluaisín féin.
Ní chuirtear fofhillteáin san áireamh. Úsáideann Oscail agus Oscail fillteán an fillteán céanna a roghnaíodh
go deireanach. Cuimhníonn easpórtáil ar a fillteán féin, Doiciméid de réir réamhshocraithe.

Taispeánann an tArdmhód réimsí breise sa tuairisc.

Scrúdaíonn Anailís iomlán an comhad iomlán agus féadfaidh sé níos faide a ghlacadh. Baineann na roghanna
tuairisce seo agus Leibhéal rianaithe le gach cluaisín; ní athnuachann athrú ach an cluaisín gníomhach.
Déantar an teaglaim dheireanach a roghnaíodh de láimh a shábháil le haghaidh cluaisíní nua agus an chéad
seoladh eile. Déantar tuairisc chomhoiriúnach i dtaisce a athúsáid fad is a fhanann an comhad gan athrú.

Osclaítear Formáidí aitheanta, Cóidecanna aitheanta agus Paraiméadair aitheanta ina gcluaisíní tuairisce féin.

Roghnaíonn Windows méid na fuinneoige tosaigh agus an suíomh. Sáraíonn socrúchán fuinneoige a sábháladh roimhe
seo na mainneachtainí sin ar sheoltaí níos déanaí.

Taispeántar conairí comhad agus dul chun cinn an luchtaithe ar thaobh clé an bharra stádais, agus leagan an
MediaInfo.dll atá luchtaithe ar dheis. Giorraítear conairí fada le comhartha focalbhá de réir an spáis atá ar
fáil.

## Cruthaigh Comhad Ceanntáisc

Is é Uirlisí an tríú roghchlár ar an mbarra roghchláir. Osclaíonn an t-ordú Cruthaigh Comhad Ceanntáisc…
comhad foinse amháin go neamhspleách ar na cluaisíní tuairisce agus cóipeann sé a chéad 524288 beart (512
KiB). Déantar comhad níos giorra a chóipeáil ina iomláine; táirgeann comhad folamh aschur folamh. Is
gnáthléamh comhaid dhénártha é seo, gan anailís MediaInfo ná gá le MediaInfo.dll. Fágann an uirlis cluaisíní
tuairisce agus liosta na gcomhad is déanaí gan athrú.

Tar éis é a léamh, tosaíonn an dialóg Sábháil Mar i bhfillteán an chomhaid foinse agus molann sé
video.mp4.header le haghaidh video.mp4: tá .header i gceangal leis an ainm bunaidh iomlán. Is féidir leat an
t-ainm agus an fillteán ceann scríbe a athrú. Ní scríobhtar aon aschur má chuirtear ceachtar den dá dialóg ar
ceal. Teastaíonn deimhniú chun ceann scríbe a athsholáthar. Fanann an fhoinse gan athrú; caomhnaíonn sábháil
theip an ceann scríbe roimhe sin. Úsáidtear na dialóga córais is nuaí atá ar fáil sa leagan sin de Windows
chun comhaid a oscailt agus a shábháil.

Nuair a thosaíonn an feidhmchlár, úsáideann an uirlis an fillteán tosaigh céanna le Comhad > Oscail. Mura
bhfuil fillteán sábháilte, roghnaíonn Windows an suíomh tosaigh. Tar éis comhad ionchuir a roghnú, cuimhníonn
an uirlis ar a fillteán féin go dtí go ndúntar an feidhmchlár, fiú má chuirtear Sábháil Mar ar ceal. Ní
athraíonn sí fillteáin Oscail ná Easpórtáil agus ní shábhálann sí a fillteán féin i socruithe an
fheidhmchláir. Osclaítear gach dialóg Sábháil Mar i bhfillteán an chomhaid ionchuir reatha, beag beann ar an
gceann scríbe sábhála roimhe seo.

## Cuardach leabharlann

Baintear triail as conair láimhe shábháilte ar dtús. Mura féidir é a lódáil, déanann fionnachtain uathoibríoch
iarracht:

1. MediaInfo.dll in aice leis an inrite, ansin i ngach eolaire tuismitheoirí suas go dtí an tiomántán nó UNC
   root root.
2. ProgramFiles, ProgramFiles(x86) agus ProgramW6432.
3. LOCALAPPDATA agus APPDATA.

Faoi na fréamhacha suiteála seo, seiceálacha fionnachtana MediaInfo, MediaArea\MediaInfo, MediaArea,
MediaArea.net\MediaInfo, Programs\MediaInfo, Programs\MediaArea\MediaInfo. Ní dhéantar suíomhanna nach féidir
a léamh agus DLLs nach bhfuil comhoiriúnach. Ní dhéanann sé scanadh athchúrsach ar an diosca.

Mura bhfaightear DLL seachtrach comhoiriúnach, déanann an t-amharcóir iarracht na leaganacha leabaithe san ord
seo: 26.10, 21.03, 0.7.60. Déanann sé sleachta agus triail leagan amháin ag an am. Chomh luath agus a lódálann
leagan go rathúil, ní bhaintear ná ní thástáiltear leaganacha níos sine. Is leor MediaInfo.exe a dháileadh ina
aonar; bíonn tosaíocht i gcónaí ag DLL seachtrach comhoiriúnach agus is féidir é a nuashonrú go neamhspleách.

Coinnítear an leabharlann a bhí luchtaithe cheana féin mar gheall ar athrú láimhe ar theip air.

## Easpórtáil tuairiscí

Ordaítear na formáidí Sábháil Mar TXT, BMP, GIF, JPEG, PNG, TIFF agus WebP. Fágtar ionchódóirí nach dtacaítear
leo ar lár as dialóga nua-aimseartha agus oidhreachta araon.

Cuireann TXT ANSI, UTF-8, UTF-8 le BOM, UTF-16 BE le BOM agus UTF-16 LE le BOM ar fáil. Is é an dara rogha,
UTF-8 gan BOM, an réamhshocrú. Caomhnaítear téacs iomlán na tuairisce agus a chríocha líne bunaidh.

caomhnaíonn BMP, PNG agus TIFF gach dath rindreáilte; Caomhnaíonn GIF89a an pailéad rindreáilte cruinn nuair a
bhíonn dathanna 256 ar a mhéad san íomhá. Scríobhann Easpórtáil an fhormáid roghnaithe i gcónaí nó
tuairiscíonn sé earráid; ní ionadaíonn sé formáid eile riamh.

Tá an tuairisc iomlán sna híomhánna sa chló tuairisce roghnaithe, agus téacs dubh ar chúlra bán. Níl roghchlár
na bhfeidhmchlár, ceanntásca cluaisíní, barra stádais, roghnúcháin nó cúramaí iontu. Tá an rindreáil
neamhspleách ar shuíomh scrollaigh an bhosca téacs.

Chun tuairiscí ciúine a ghearradh nó an spás seoltaí ar ríomhairí níos sine a sheachaint, tá íomhá amháin
teoranta do 16,384 picteilín ar leithead, 32,767 picteilín ar airde agus 256 MiB de chuimhne léarscáile
neamh-chomhbhrúite. Roghnaigh cló níos lú má sháraíonn tuairisc na teorainneacha sin.

Is é `Google WebP (*.webp)` an fhormáid dheireanach agus sábhálann sé an tuairisc gan chaillteanas.

WebP: 16383 × 16383 px.

## Teangacha an chomhéadain agus na dtuairiscí

Tá conairí leabharlainne, cló na tuairisce, frithailiasáil agus teangacha i Roghanna (Socruithe > Roghanna,
Ctrl+G). Tá 36 leagan den chomhéadan ann agus leanann sé Windows ar dtús. Úsáideann tuairiscí bun-Bhéarla na
leabharlainne i gcónaí mar réamhshocrú, neamhspleách ar Windows agus ar an gcomhéadan. Ní athraíonn é sin ach
rogha láimhe: Béarla, 37 aistriúchán nó tábla CSV MediaInfo saincheaptha.

Deimhníonn OK nó Cuir i bhfeidhm na hathruithe; caitheann Cealaigh na hathruithe ar feitheamh amach. Sna
Roghanna, is féidir teorainn a chur le fad ainm an chluaisín (80 de réir réamhshocraithe) agus liosta na
gcomhad le déanaí a ghlanadh. Coinnítear tús, deireadh agus iarmhír ainmneacha fada le comhartha focalbhá sa
lár.

De réir réamhshocraithe, ní cheadaítear ach ásc amháin agus seolann seoltaí eile na comhaid chuig an
bhfuinneog oscailte. Is féidir áscanna iolracha a cheadú sna socruithe. Má tá roinnt fuinneog ann, ní
athchóirítear an suíomh sábháilte ach don chéad fhuinneog de gach foirm; ní athchóirítear ach an méid do na
fuinneoga eile.

Mura n-athraítear ach an comhéadan fágtar téacs na dtuarascálacha oscailte gan athrú. Déanann athrú teanga
tuairisce a chuirtear i bhfeidhm de láimh a gcuid tuarascálacha a athlódáil agus ord cluaisíní agus ord MRU á
gcaomhnú.

## libcurl

Seiceálann fionnachtain uathoibríoch curl in aice leis an MediaInfo DLL roghnaithe, ansin an
executable/ancestor roinnte, Comhaid Cláir agus láithreacha suiteála an úsáideora. Mura bhfaightear curl
seachtrach comhoiriúnach, baintear an sruth leabaithe meaitseála nó an leagan XP isteach sa taisce seiceála in
aghaidh an úsáideora. Seachnaíonn an MediaInfo 0.7.60 is sine curl fionnachtain, eastóscadh agus luchtú go
hiomlán. Diúltaíonn curl neamhbhailí a roghnaíodh go sainráite don athrú sainrogha; ní chuireann sé seo cosc
ar ghnáththuairiscí comhaid logánta in easnamh uathoibríoch roghnach curl.

## Ainmneacha comhad agus comhaid le déanaí

MRU ní ghiorrú comhadainmneacha ach amháin nuair atá níos faide ná 80 UTF-16 aonad cóid. Caomhnaíonn
lár-éilips tús, deireadh ainm an chomhaid roimh a shíneadh agus an síneadh deiridh iomlán; tá cosáin iomlána
agus tuairiscí gan athrú. Úsáideann fotheidil na gcluaisíní an t-algartam céanna le teorainn réamhshocraithe
inroghnaithe de 80.

Comhaid le déanaí > Glanann Clear láithreach an roghchlár beo MRU agus a cosáin shábháilte agus fágtar gach
cluaisín oscailte slán. Ní chuireann sé i bhfeidhm ná ní bhailíochtaíonn sé roghanna atá ar feitheamh agus ní
chumasaíonn sé Iarratas a dhéanamh. Caomhnaíonn Cealaigh nó Éalú an stair glanta fad is atá athruithe ar
feitheamh á gcur i leataobh. Tá Clear díchumasaithe aon uair a bhíonn an liosta folamh, agus déantar a staid a
athnuachan nuair a bhíonn an liosta i dtuairiscí nua. Tuairiscítear teip i scríobh na clárlainne láithreach.
Nuair a chuirtear teorainn ainm cluaisín nua i bhfeidhm, nuashonraítear gach cluaisín oscailte gan a thuairisc
meán a athlódáil.

## Ceadúnas agus athdháileadh

Tá an breathnóir ceadúnaithe faoin gCeadúnas MIT in license.txt.

Is comhpháirt tríú páirtí é MediaInfo. Is é an t-aon fhógra dáileacháin atá á chothabháil ná fréamh
license.txt, ionchódaithe mar UTF-8 le CRLF agus lena n-áirítear an breathnóir, leabharlanna, comhpháirteanna
atá corpraithe go statach, deilbhíní agus táblaí aistriúcháin oifigiúil.

Úsáideann an táirge seo an leabharlann MediaInfo, Cóipcheart (c) 2002-2026 MediaArea.net SARL.

- MediaInfo: <https://mediaarea.net/MediaInfo>
- Ceadúnas: <https://mediaarea.net/en/MediaInfo/License>
- Windows íosluchtú: <https://mediaarea.net/en/MediaInfo/Download/Windows>

## Spleáchais

### Comhaid

| Acmhainn | Ailtireacht | Leagan a thuairiscigh an chomhpháirt | SHA-256 |
| --- | --- | --- | --- |
| Resources/lib/26.10/MediaInfo.dll | x86 | 26.10 | E73027A1577084135425AA013D46C8B2985AD142CCF04F1ADB301B9A9CFB78F8 |
| Resources/lib/21.03/MediaInfo.dll | x86 | 21.03 | EBBF1C371702F3DC39CA23D619C47EDF97E66A95AEABE725284F1402D8F3E58A |
| Resources/lib/0.7.60/MediaInfo.dll | x86 | 0.7.60 | A26C07BCC25FA01A40E6888D02EABD59AA8DB2ABF6F5195481228D3A91D04441 |
| Resources/lib/26.10/libcurl.dll | x86 | 8.11.0-DEV, Schannel, zlib 1.3.1 | DCF136C84F3A4FBEAE2B317FE36D7F11225B56FBA3343AF4BBA8706B3F46F334 |
| Resources/lib/21.03/libcurl.dll | x86 | 7.47.1, WinSSL, zlib 1.2.8 | 21025CAC8089F1E570EE083D8CFD6311C2C51E97094A9FCD8C7A0B544C22CB48 |
| Resources/lib/libwebp.dll | x86 | 1.1.0 | 9986023BB6FF5510A157919F0CD958A94800EC6A1D981F3403A9648BEDFEE575 |

Tá na cosáin sa tábla coibhneasta le heolaire tionscadail MediaInfo.

Tuairiscíonn an leabharlann reatha leagan forbartha; ní féidir a fhoinse cruinn commit a aisghabháil ón
teaghrán leagain sin. Úsáideann an fógra a ghabhann leis seo an téacs cóipchirt agus ceada réamhtheachtacha
8.11.0, a bhfuil téarmaí an cheadúnais i láthair sa tsraith forbartha freisin.

### Comhpháirteanna ionchorpraithe

| Comhpháirt | Fianaise agus scóip | Fógra |
| --- | --- | --- |
| MediaInfoLib | Leaganacha iarbhír agus onnmhairí Unicode riachtanacha; dénártha soláthraithe gan athrú | Bunchóipcheart leagan-shonrach, coinníollacha athdháilte agus séanadh |
| ZenLib | Tagairtí tionscadail statacha agus ZenLib RTTI leabaithe i ngach ceann de na trí DLLs; níor soláthraíodh leasuithe nasctha beachta | zlib-stíl ZenLib fógra |
| zlib | Teaghráin leagain inflate/deflate leabaithe: 1.3.2 in MediaInfo 26.10, 1.2.11 in 21.03, 1.2.7 in 0.7.60; Tuairiscíonn curl freisin 1.3.1 agus 1.2.8 | Bunfhógraí zlib do na cúig leagan ar fad |
| TinyXML-2 | Spriocanna foinse nua-aimseartha a mheaitseáil agus RTTI dénártha; san áireamh sa tionscadal oidhreachta, ach nach bhfuil aitheanta go neamhspleách sa dénártha oidhreacht stripped | Bunfhógra Lee Thomason zlib coinnithe |
| Brian Gladman AES | Áirithe sa dá sprioc leabharlainne in aghaidh an tsrutha nua-aimseartha, le fógraí foinse ceadaithe a mheaitseáil | 1998–2013 fógra athdháilte agus séanadh |
| Brian Gladman SHA-1/SHA-2 | An dá sprioc nua-aimseartha; Tá táblaí tairiseacha SHA-256 agus SHA-512 i láthair sa dá dhénártha nua-aimseartha | 1998–2010 fógra athdháilte agus séanadh |
| Brian Gladman HMAC | An dá sprioc nua-aimseartha agus a gcód léitheora curl/S3 | Fógra bunaidh trí choinníoll, lena n-áirítear a mhír um cheadúnas malartach |
| MD5 | Spriocanna foinse nua-aimseartha; Luann cur i bhfeidhm Colin Plumb go sainráite san fhearann poiblí | Coinníodh an chion |
| Base64 | Markus Ewald ceanntásc sna trí chrann foinse chomhfhreagracha, ag creidiúnú Bob Withers | Coinníodh sannadh an údair bhunaidh; cáilíocht thíos |
| fmt | sprioc 26.10 agus fmt v11 format_error RTTI sa dénártha | Fógra bunaidh MIT, lena n-áirítear eisceacht roghnach |
| tfsxml | 26.10 sprioc foinse | Fógra bunaidh MediaArea MIT |
| Android JNI comhéadan | onnmhairítear JNI_OnLoad iarbhír ag an dá DLLs nua-aimseartha; tá an ceanntásc JNI san áireamh ó AOSP | AOSP cóipcheart agus comhlánaigh Ceadúnas Apache 2.0 |
| libcurl | Soláthraíodh x86 dénártha; onnmhairí leagan iarbhír; in úsáid go dinimiciúil ag MediaInfo nua-aimseartha | Bunfhógraí curl do 8.11.0 agus 7.47.1 |
| Aistriúcháin oifigiúla tuairiscí | Gach foinse 38 neamhmhodhnaithe CSV ón eolaire teangacha MediaInfo v26.10; Tá táblaí neamh-Bhéarla leabaithe 37, agus úsáideann an Béarla DLL réamhshocraithe | Tionscadal céanna BSD-2-Clause fógra coinnithe san fhógra comhcheangailte |
| MediaInfo deilbhín | Deilbhín oifigiúil ilíomhánna neamhathraithe, athbhreithniú foinse f057dd3649bc8692a83863b67770e22c9b9dd81a | Bunfhógra BSD-2-Clause agus sannadh |
| libwebp | WebPEncodeLosslessBGRA, WebPFree; 1.1.0; x86 | BSD-3-Clause; PATENTS |

Bunaíonn na spriocanna foinse comhoiriúnaithe cuimsiú sna cumraíochtaí tógála réamhtheachtacha sin; ní
chruthaíonn siad go maireann gach feidhm leas iomlán a bhaint sna dénártha díoltóirí. Ní dhéantar aon éileamh
ar leagan cruinn maidir le cleithiúnaithe nach bhfuil a n-athbhreithniú taifeadta sna dénártha trádála sin.

### Comhpháirteanna roghnacha agus leabharlanna córais

- Cumasaíonn na tionscadail leabharlainne Windows libcurl atá luchtaithe ag am rite le haghaidh MediaInfo
  26.10 agus 21.03. Tógadh MediaInfo 0.7.60 le MEDIAINFO_LIBCURL_NO; ina dhénártha tá an diagnóisic le
  tacaíocht do dhaoine faoi mhíchumas. Ní fhaigheann an breathnóir amach, ní bhaintear as nó ní lódálann sé
  curl don leagan cuachta sin.
- Tá libmms díchumasaithe i ngach ceann de na trí Windows DLLs arna soláthar, mar atá deimhnithe ag a
  dteachtaireachtaí leabaithe tacaíochta do dhaoine faoi mhíchumas. Ní dhéantar é a athdháileadh.
- Baineann Qt agus wxWidgets le foirgnimh roghnacha GUI. Ní chuirtear san áireamh ach an oiread san amharcóir
  seo ná sna spleáchais DLL seo. Baineadh a n-iontrálacha cineálacha den cheadúnas ar taispeáint.
- Is duán ama rite roghnach é Graphviz i gcód in aghaidh an tsrutha nua-aimseartha. Ní athdháiltear Graphviz
  DLL.
- Níl aon bhreiseán FFmpeg athdháilte.
- Ní allmhairíonn an MediaInfo DLLs ach KERNEL32.dll. Ní chiallaíonn sé seo go bhfuil a n-am rite atá nasctha
  go statach agus a gcód cúntóra as láthair.
- Allmhairíonn curl reatha WS2_32.dll, bcrypt.dll, ADVAPI32.dll, CRYPT32.dll agus KERNEL32.dll go díreach.
  Allmhairíonn XP curl WS2_32.dll, WLDAP32.dll, ADVAPI32.dll agus KERNEL32.dll go díreach. Is comhpháirteanna
  Windows iad seo. Seiceálann an lódóir Windows a infhaighteacht.
- Tuairiscíonn Curl Windows Schannel/WinSSL, ní tógáil OpenSSL. Tá a spleáchas comhbhrú breise tuairiscithe
  san áireamh go statach zlib. Níl aon bhreise seachtrach neamh-Windows DLL le feiceáil ina tábla um
  allmhairiú díreach.
- Níl aon C/C++ spleáchas ar am rite ag an amharcóir féin. Tá a gcuid ama rite tiomsaithe féin sa tríú páirtí
  DLLs. Úsáideann na foirgnimh Windows uirlisí Microsoft; níl aon fhianaise ann a éilíonn na hiontrálacha
  fardail cineálach libstdc++ nó libc++.
- Úsáideann JPEG córas luchtaithe go dinimiciúil GDI+. Is uirlisí tógála iad an pacálaí acmhainne C# agus
  PowerShell agus ní spleáchais am rite iad.

Ní bhíonn freastalaí MediaArea ná bunachar sonraí formáide cianda íoslódáilte ag teastáil ó ghnáth-iniúchadh
comhad áitiúil. Úsáideann libcurl MediaInfo le haghaidh ionchuir URL agus tagairtí a d’fhéadfadh a bheith
cianda i bhformáidí meán tacaithe. Ní chuireann sé ordú oscailt URL ar leith leis an amharcán seo nuair a
chuachta é.

### Stóráil ceadúnais agus teorainneacha

Is é [license.txt](../license.txt) an t-aon fhógra dáileacháin arna chothabháil, agus é ionchódaithe mar UTF-8
le CRLF. Ní éilíonn na clásail athdháilte seiceála BSD, curl, zlib, MIT agus Apache comhad fógra ar leith go
fisiciúil in aice le gach DLL; bíonn an fógra comhcheangailte in éineacht leo sna hábhair inrite agus
dáileacháin.

Úsáideann an pacáiste cartlainne MediaInfo 0.7.60 a cheadúnas leagan-shonrach féin agus áirítear leis an
seantéacs GNU Library GPL. Déanann a théarmaí idirdhealú sainráite idir athdháileadh dénártha neamhmhodhnaithe
agus leaganacha modhnaithe; ní athraítear an DLL a sholáthrófar trí nascadh dinimiciúil a dhéanann an
t-amharcóir seo. Coinnítear na bunchoinníollacha agus an téacs ceadúnais a ghabhann leis. Fanann an breathnóir
MIT-cheadúnaithe.

Teastaíonn cáilíocht as sannadh réamhtheachtach amháin: níl cead sainráite ná ráiteas ceadúnais ag an
gceanntásc Markus Ewald Base64. Déanann MediaArea cur síos ar chur i bhfeidhm Bob Withers Base64 mar
fhorfheidhmiú poiblí ina dhoiciméadú MediaConch gaolmhar, ach ní bhunaíonn sé sin go neamhspleách deontas
ceadúnais do gach athrú Ewald. Níl aon deontas ceadúnais ceaptha don cheannteideal sin. Ní raibh deimhniú
iomlán an díoltóra ar an mbunáit sin, na hathbhreithnithe cruinne ZenLib agus an fhorbairt curl commit ar fáil
sna dénártha soláthraithe. Cuireann na pointí seo cosc ar an bhfardal seo a chóireáil mar SBOM iomlán,
deimhnithe go neamhspleách.

### Príomhfhoinsí

- [MediaInfo téarmaí athdháilte](https://mediaarea.net/en/MediaInfo/License)
- 
  [MediaInfo 26.10 sprioc leabharlainne](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Project/MSVC2022/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 21.03 sprioc leabharlainne](https://github.com/MediaArea/MediaInfoLib/blob/v21.03/Project/MSVC2015/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 0.7.60 sprioc leabharlainne](https://github.com/MediaArea/MediaInfoLib/blob/v0.7.60/Project/MSVC2005/Library/MediaInfoLib.vcproj)
- 
  [Am rite curl lódóir](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Source/MediaInfo/Reader/Reader_libcurl.cpp)
- 
  [Foinsí cúntóra cuachta agus a bhfógraí](https://github.com/MediaArea/MediaInfoLib/tree/v26.10/Source/ThirdParty)
- [ZenLib fógra](https://github.com/MediaArea/ZenLib/blob/master/License.txt)
- [zlib fógraí foinse](https://github.com/madler/zlib/blob/v1.3.2/zlib.h)
- [curl 8.11.0 fógra](https://github.com/curl/curl/blob/curl-8_11_0/COPYING)
- [curl 7.47.1 fógra](https://github.com/curl/curl/blob/curl-7_47_1/COPYING)
- [Ceadúnas Apache 2.0](https://www.apache.org/licenses/LICENSE-2.0)
- [MediaArea Base64 tuairisc](https://github.com/MediaArea/MediaConch/blob/master/README.md)

Tagann na táblaí tuairisce ó
<https://github.com/MediaArea/MediaInfo/tree/v26.10/Source/Resource/Plugin/Language> . Is é
<https://github.com/MediaArea/MediaInfo/blob/v26.10/LICENSE> an tionscadal meaitseála LICENSE.

- [libwebp 1.1.0 COPYING](https://github.com/webmproject/libwebp/blob/v1.1.0/COPYING)
- [libwebp 1.1.0 PATENTS](https://github.com/webmproject/libwebp/blob/v1.1.0/PATENTS)
