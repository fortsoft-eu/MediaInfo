# MediaInfo Viewer

[Čeština](README.cs-CZ.md) | [English (US)](../README.md) | [English (UK)](README.en-GB.md) | [English (Australia)](README.en-AU.md) | [Deutsch](README.de-DE.md) | [Français](README.fr-FR.md) | [Español](README.es-ES.md) | [Italiano](README.it-IT.md) | [Português](README.pt-PT.md) | [Polski](README.pl-PL.md) | [Slovenčina](README.sk-SK.md) | [Dansk](README.da-DK.md) | **Suomi** | [Íslenska](README.is-IS.md) | [Norsk (bokmål)](README.nb-NO.md) | [Svenska](README.sv-SE.md) | [Türkçe](README.tr-TR.md) | [Eesti](README.et-EE.md) | [Gaeilge](README.ga-IE.md) | [Lietuvių](README.lt-LT.md) | [Latviešu](README.lv-LV.md) | [Magyar](README.hu-HU.md) | [Malti](README.mt-MT.md) | [Nederlands](README.nl-NL.md) | [Română](README.ro-RO.md) | [Ελληνικά](README.el-GR.md) | [Bosanski](README.bs-Latn-BA.md) | [Hrvatski](README.hr-HR.md) | [Slovenščina](README.sl-SI.md) | [Crnogorski](README.cnr-Latn-ME.md) | [Беларуская](README.be-BY.md) | [Български](README.bg-BG.md) | [Македонски](README.mk-MK.md) | [Српски](README.sr-Cyrl-RS.md) | [Українська](README.uk-UA.md) | [Русский](README.ru-RU.md)

Natiivi Windows x86 -katselin MediaInfo.dll-raporteille. Jokaisella tiedostolla on oma vain luku -välilehti.

[Kääntäminen ja yhteensopivuus](#kääntäminen) | [Riippuvuuksien tarkastus](#riippuvuudet) | [Lisenssi](../license.txt)

## Kääntäminen

Avaa MediaInfo.sln kansiossa Visual Studio 2015, kun työkalusarja on asennettu Visual C++ v140. Valitse Release | Win32 ja rakentaa ratkaisu. Ainoa sovellusalusta on Win32 (x86).

[PCRE2 10.49](https://github.com/PCRE2Project/pcre2/tree/pcre2-10.49) — UTF-16, staattisesti linkitetty,
BSD-3-Clause. [Lähdekoodi](../MediaInfo/PCRE2/).
[license.txt](../license.txt).
PCRE2 on sisällytetty EXE-tiedostoon, eikä se vaadi erillistä DLL-tiedostoa tai asennusta.

Lähdöt:

- Release\MediaInfo.exe
- Debug\MediaInfo.exe

Katselija ei linkitä C- tai C++-ajoaikaa eikä tarvitse MSVC uudelleenjaettavaa. Valitulla MediaInfo.dll:lla
voi olla omat riippuvuutensa.

Rakennus vaatii Windows PowerShell ja .NET Framework. Nämä ovat vain rakennusvaatimuksia; natiivi suoritettava
tiedosto ei vaadi PowerShell eikä .NET.

### Jakelupaketti

Kun olet rakentanut Release, suorita
`powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\PackageRelease.ps1` . Skripti luo
ratkaisuhakemistoon `MediaInfo-<version>-win32.zip` käyttämällä suoritettavan tiedoston neliosaista versiota.
Arkisto sisältää `MediaInfo.exe` ja yhdistetyn `license.txt` suoraan juurensa.

## Yhteensopivuus

Win32-katseluohjelma on suunniteltu käyttämään Windows NT 4.0 APIs.

Suoritettava tiedosto sisältää kolme x86 MediaInfo -kirjastoa: 26.10 nykyiselle Windows, 21.03 paketista
Windows XP ja 0.7.60 paketista Windows 95–2000. Kirjaston arkkitehtuuri ei yksin määritä sen
käyttöjärjestelmän yhteensopivuutta. Katseluohjelma kokeilee niputettuja kirjastoja uusimmasta vanhimpaan ja
pysähtyy ensimmäisen onnistuneen latauksen ja versiokyselyn jälkeen.

Windows 95 ei ole tällä hetkellä tuettu suoritusaika.

## Käyttö

- Tiedosto > Avaa (Ctrl+O) avaa Windows-tiedostoikkunan, jossa on useita valintoja. Windows Vista:ssa ja
  uudemmissa Avaa ja Tallenna käytä nykyaikaista Common Item Dialogia; vanhemmat Windows käyttävät vanhoja
  yleisiä valintaikkunoita.
- Vedä yksi tai useampi tiedosto ikkunaan, EXE-kuvakkeen tai sen pikakuvakkeen päälle tai anna polut
  komentorivillä. Jos useita esiintymiä ei sallita, tiedostot avataan jo käynnissä olevassa ikkunassa.
- Jokaisella erillisellä normalisoidulla täydellä polulla on yksi välilehti. Jo avoimen tiedoston avaaminen
  uudelleen valitsee sen olemassa olevan välilehden lataamatta uudelleen tai muuttamatta sen raporttia,
  valintaa tai vierityskohtaa. Vertailut jättävät huomioimatta polun kirjainkoon. Useiden tiedostojen avaukset
  käsittelevät luetteloa järjestyksessä ja jättävät viimeksi onnistuneesti käsitellyn tiedoston aktiiviseksi,
  olipa se vasta avattu vai jo auki. Vie hiiri välilehden otsikon päälle näyttää koko tiedostopolun
  alkuperäisessä työkaluvihjeessä, myös silloin, kun näytettävää tiedostonimeä lyhennetään.
- Tiedosto-valikossa on kahdeksan viimeksi ladattua tiedostoa suoraan Lopeta yläpuolella erottimien välissä.
  Merkinnöissä näkyy vain numero ja tiedostonimi. Tiedon valitseminen avaa sen tallennetun täyden polun tai
  valitsee sen olemassa olevan välilehden; onnistunut uudelleen avaaminen siirtää sen alkuun ilman
  kaksoiskappaleita. Kun valitset tiedoston, joka ei ole käytettävissä, kysytään, poistetaanko sen
  viimeisimmät tiedostot. Käytetään alkuperäistä kysymyskuvaketta ja Yes/No painikkeita. Kyllä on oletusarvo
  ja poistaa merkinnän valikosta ja rekisteristä; Ei säilytä sitä. Kehote sisältää koko polun.
- Hiiren rulla ylivuoto välilehtien otsikoiden yli vierittää otsikkonauhaa yhden välilehden viestiä kohden
  muuttamatta valintaa tai kohdistusta.
- Ctrl+Tab ja Ctrl+Vaihto+Tab vaihtaa välilehtiä; Ctrl+W sulkee aktiivisen välilehden. Välilehden otsikon
  keskinapsauttaminen sulkee välilehden ja säilyttää muut aktiiviset välilehdet. Tiedosto > Sulje kaikki
  sulkee kaikki välilehdet, mukaan lukien jonossa olevat raportit. Tiedosto > Lopeta (Alt+F4) sulkee
  sovelluksen.
- Välilehden otsikon pikavalikossa on Sulje välilehti. Ota asetuksissa käyttöön Sulje välilehdet
  kaksoisnapsautuksella, jos haluat sulkea välilehden kaksoisnapsauttamalla sen otsikkoa. Asetus on
  oletuksena pois käytöstä, ja se tallennetaan.
- Kaksoisnapsautus raporttitekstissä valitsee sanan. Kolmoisnapsautus valitsee loogisen rivin. Vetäminen
  laajentaa valintaa sanoittain tai riveittäin.
- Ctrl+A valitsee raportin; Ctrl+C kopioi sen.
- Muokkaa > Etsi (Ctrl+F) hakee aktiivisesta raporttivälilehdestä tai Ohje- tai Tietoja-ikkunan
  tekstialueelta sen mukaan, missä ikkunassa kohdistus on. Hakuikkuna säilyttää viimeksi valitun
  lähteen, kun kohdistus on siinä. F3 toistaa haun ja Vaihto+F3 vaihtaa hakusuunnan. Tekstin päässä haku
  jatkuu toisesta päästä. Asetukset > Automaattinen rivitys koskee vain aktiivista välilehteä;
  valintamerkki seuraa valittua välilehteä. Hakuikkunan voi pienentää ja sen leveyttä muuttaa; sijainti
  ja Aina päällimmäisenä -asetus muistetaan. Enintään 30 hakutekstiä asetuksineen säilytetään vain
  sovelluksen sulkemiseen asti. Rivin alku- ja loppuehdot koskevat loogisia rivejä. Säännölliset
  lausekkeet käyttävät PCRE2-syntaksia. Muut Muokkaa-valikon komennot koskevat aktiivista
  raporttivälilehteä. Enter käynnistää haun; Vaihto+Enter kääntää valitun suunnan. ”Sama kirjainkoko”
  erottaa isot ja pienet kirjaimet; ”Etsi taaksepäin” hakee kohti tekstin alkua. Historiakohteen valinta
  palauttaa kaikki viisi hakuasetusta, myös säännöllisten lausekkeiden tilan; ”Aina päällimmäisenä” on
  erillinen asetus. ”Säännöllinen lauseke” poistaa käytöstä asetukset ”Rivi alkaa” ja ”Rivi päättyy”.
  Kun molemmat rivin reunaehdot ovat käytössä, osuma kummassa tahansa reunassa riittää. ”Automaattinen
  rivitys” muuttaa vain näyttötapaa.
- Asetukset > Asetukset (Ctrl+G) avaa yhden asetusikkunan MediaInfo- ja curl-poluille, raportin fontille,
  fontin antialiasolle, käyttöliittymäkielelle ja raportin kielelle. Tyhjä DLL polku mahdollistaa
  automaattisen etsinnän.
- Fonttipainike näyttää perheen, pistekoon ja tyylin ja avaa standardin Windows fontin valintaikkunan.
  Oletusarvo palauttaa Consolas tai Courier New, jos Consolas ei ole käytettävissä; Oletus-painike ei ole
  käytössä, kun oletusasetus on valittuna. Käyttäjän valitsemat kirjasimet säilytetään ilman korvausta
  sovelluskoodilla.
- Fontin antialiasointivaihtoehdot ovat ClearType, kun niitä tuetaan, GDI ja Ei mitään. Alkuvalinta on
  ClearType, kun sitä tuetaan, muuten GDI. Fonttiasetukset koskevat raporttivälilehtiä, niiden
  kuvavientiä ja raporttien tulostusta. Ohje ja Tietoja säilyttävät omat tekstifonttinsa.
- Ohje avaa erillisen mallittoman ikkunan, jossa on oma tehtäväpalkin merkintä ja pienennyspainike. Tietoja on
  modaalinen dialogi; sen tuoteotsikossa luetellaan kaikki kolme upotettua DLL-versiota.

Tiedosto > Sivun asetukset… avaa istunnon paperi-, suunta- ja reunusasetukset. Tulosta… (Ctrl+P) avaa
järjestelmän tulostusikkunan; Windows 11 näyttää esikatselun, kun taas Windows 10 ja vanhemmat käyttävät
perinteistä ikkunaa. Ctrl+P tulostaa pääikkunan aktiivisen välilehden tai Ohje- tai Tietoja-ikkunan
tekstialueen sen mukaan, missä ikkunassa kohdistus on. Raportit käyttävät valittua raporttifonttia, Ohje
järjestelmän valintaikkunafonttia ja Tietoja oman tekstialueensa fonttia. Jos välilehtiä ei ole auki
mutta Ohje on auki, Sivun asetukset… ja Tulosta… ovat edelleen käytettävissä; Tulosta… tulostaa ohjeen.
Ohje käyttää pääikkunan tulostusikkunaa; uusi Ctrl+P ohjeessa tuo saman ikkunan etualalle. Pitkät rivit
rivitetään ja teksti jaetaan sivuille. Tulostus tapahtuu taustalla.

Avaa kansio… avaa valitussa kansiossa suoraan olevat tiedostot kukin omalle välilehdelleen. Alikansioita ei
sisällytetä. Avaa ja Avaa kansio käyttävät yhteistä viimeksi valittua kansiota. Vienti muistaa erillisen
kansion, joka on oletuksena Tiedostot.

Edistynyt tila näyttää raportissa lisää kenttiä.

Täydellinen analyysi tutkii koko tiedoston ja voi kestää kauemmin. Nämä raporttivaihtoehdot ja Jäljitystaso
kuuluvat jokaiseen välilehteen; muutos päivittää vain aktiivisen välilehden. Viimeisin manuaalisesti valittu
yhdistelmä tallennetaan uusia välilehtiä ja seuraavaa käynnistystä varten. Vastaavaa välimuistissa olevaa
raporttia käytetään uudelleen, kun tiedosto pysyy muuttumattomana.

Tunnetut muodot, Tunnetut koodekit ja Tunnetut parametrit avautuvat omille raporttivälilehdilleen.

Alkuperäisen ikkunan koon ja sijainnin valitsee Windows. Aiemmin tallennettu ikkunan sijoitus ohittaa nämä
oletusasetukset myöhemmissä käynnistyksissä.

Tilarivin vasen osa näyttää tiedostopolut ja latauksen etenemisen, oikea osa ladatun MediaInfo.dll-kirjaston
version. Pitkät polut lyhennetään kolmella pisteellä käytettävissä olevan tilan mukaan.

## Luo otsaketiedosto

Työkalut on valikkorivin neljäs valikko. Sen Luo otsaketiedosto…-komento avaa yhden lähdetiedoston
raporttivälilehdistä riippumatta ja kopioi sen ensimmäiset 524288 tavua (512 KiB). Lyhyempi tiedosto
kopioidaan kokonaan; tyhjä tiedosto tuottaa tyhjän tulosteen. Tämä on tavallista binaaritiedostojen lukemista
ilman MediaInfo-analyysiä tai MediaInfo.dll-vaatimusta. Työkalu jättää raporttivälilehdet ja katseluohjelman
viimeisimmät tiedostot ennalleen.

Lukemisen jälkeen Tallenna nimellä -valintaikkuna avautuu lähdetiedoston kansioon ja ehdottaa tiedostolle
video.mp4 nimeä video.mp4.header: .header lisätään koko alkuperäiseen nimeen. Voit muuttaa sekä nimeä että
kohdekansiota. Kumman tahansa valintaikkunan peruuttaminen ei kirjoita tulostiedostoa. Olemassa olevan
kohdetiedoston korvaaminen vaatii vahvistuksen. Lähdetiedosto pysyy ennallaan, ja epäonnistunut tallennus
säilyttää aiemman kohdetiedoston. Avaamiseen ja tallentamiseen käytetään uusimpia kyseisessä Windows-versiossa
saatavilla olevia järjestelmän valintaikkunoita.

Sovelluksen käynnistyessä työkalu ottaa alkuperäisen syöttökansionsa osoitteesta Tiedosto > Avaa. Jos yhtään
kansiota ei ole tallennettu, Windows valitsee alkuperäisen sijainnin. Kun syöttötiedosto on valittu, työkalu
muistaa oman kansion vain, kunnes sovellus sulkeutuu, vaikka Tallenna nimellä -toiminto peruutetaan. Se ei
muuta komentojen Avaa ja Vie käyttämiä kansioita eikä tallenna omaa kansiotaan sovellusasetuksiin. Jokainen
Tallenna nimellä -valintaikkuna alkaa valitun syöttötiedoston kansiosta edellisestä tallennuskohteesta
riippumatta.

## Kirjastojen etsintä

Ensin kokeillaan tallennettua manuaalista polkua. Jos sitä ei voi ladata, automaattinen etsintä yrittää:

1. MediaInfo.dll suoritettavan tiedoston vieressä, sitten kussakin ylähakemistossa asemaan asti tai UNC jaa
   juuri.
2. ProgramFiles, ProgramFiles(x86) ja ProgramW6432.
3. LOCALAPPDATA ja APPDATA.

Näiden asennusjuurien alla etsintätarkistukset MediaInfo, MediaArea\MediaInfo, MediaArea,
MediaArea.net\MediaInfo, Programs\MediaInfo, Programs\MediaArea\MediaInfo. Lukemattomat sijainnit ja
yhteensopimattomat DLLs ohitetaan. Se ei tarkista levyä rekursiivisesti.

Jos yhteensopivaa ulkoista DLL ei löydy, katseluohjelma yrittää upotettuja versioita tässä järjestyksessä:
26.10, 21.03, 0.7.60. Se purkaa ja testaa yhden version kerrallaan. Kun versio latautuu onnistuneesti,
vanhempia versioita ei pureta eikä testata. Pelkästään MediaInfo.exe:n jakaminen riittää; yhteensopiva
ulkoinen DLL on aina etusijalla, ja se voidaan päivittää itsenäisesti.

Epäonnistunut manuaalinen kirjastomuutos säilyttää jo ladatun kirjaston.

## Raportin vienti

Tallenna nimellä -muodot ovat järjestyksessä TXT, BMP, GIF, JPEG, PNG, TIFF ja WebP. Ei-tuetut enkooderit on
jätetty pois sekä nykyaikaisista että vanhoista valintaikkunoista.

TXT tarjoaa muodot ANSI, UTF-8, UTF-8 ja BOM, UTF-16 BE ja BOM sekä UTF-16 LE ja BOM. Oletus on toinen
vaihtoehto, UTF-8 ilman BOM-merkkiä. Koko raporttiteksti ja sen alkuperäiset rivinvaihdot säilytetään.

BMP, PNG ja TIFF säilyttävät kaikki renderoidut värit; GIF89a säilyttää tarkan renderoidun paletin, kun
kuvassa on enintään 256 väriä. Vienti kirjoittaa aina valitun muodon tai ilmoittaa virheestä; se ei koskaan
korvaa toista muotoa.

## Käyttöliittymän ja raporttien kielet

Asetukset (Asetukset > Asetukset, Ctrl+G) sisältävät kirjastopolut, raportin fontin, pehmennyksen ja kielet.
Käyttöliittymässä on 36 vaihtoehtoa, ja aluksi se seuraa Windowsia. Raportit käyttävät aina oletuksena
kirjaston alkuperäistä englantia Windowsista ja käyttöliittymästä riippumatta. Kieli vaihtuu vain käsin
valitsemalla: englanti, 37 käännöstä tai oma MediaInfo-CSV-taulukko.

OK tai Käytä vahvistaa muutokset; Peruuta hylkää odottavat muutokset. Asetuksissa voi rajoittaa välilehtien
nimien pituutta (oletus 80 merkkiä) ja tyhjentää viimeisimpien tiedostojen luettelon. Pitkissä nimissä
säilyvät alku, loppu ja tiedostopääte, ja keskellä on kolme pistettä.

Oletuksena sallitaan vain yksi esiintymä, ja myöhemmät käynnistykset lähettävät tiedostot avoimeen ikkunaan.
Asetuksissa voi sallia useita esiintymiä. Kun ikkunoita on useita, vain kunkin lomakkeen ensimmäinen ikkuna
palauttaa tallennetun sijaintinsa; myöhemmät ikkunat palauttavat vain koon.

Vain käyttöliittymän muuttaminen jättää avoimien raporttien tekstit ennalleen. Manuaalisesti tehty
raporttikielen muutos lataa raportit uudelleen säilyttäen samalla välilehtien järjestyksen ja
MRU-järjestyksen.

## libcurl

Automaattiset curl-etsintätarkistukset valitun MediaInfo DLL, sitten jaetun executable/ancestor,
ohjelmatiedostojen ja käyttäjien asennuspaikkojen vieressä. Jos yhteensopivaa ulkoista curl-laitetta ei löydy,
vastaava upotettu nykyinen tai XP-versio puretaan tarkistettuun käyttäjäkohtaiseen välimuistiin. Vanhin
MediaInfo 0.7.60 ohittaa curl löytämisen, purkamisen ja lataamisen kokonaan. Eksplisiittisesti valittu
virheellinen curl hylkää asetusmuutoksen; puuttuu valinnainen automaattinen curl ei estä tavallisia
paikallisia raportteja.

## Tiedostonimet ja viimeksi käytetyt tiedostot

MRU tiedostonimet lyhennetään vain, jos ne ovat pitkiä kuin 80 UTF-16 koodiyksikköä. Keskimmäinen ellipsi
säilyttää tiedostonimen alun, lopun ennen sen päätettä ja täydellisen lopullisen tunnisteen. täydelliset polut
ja raportit pysyvät ennallaan.

Viimeisimmät tiedostot > Tyhjennä tyhjentää välittömästi sekä reaaliaikaisen MRU-valikon että sen tallennetut
polut jättäen kaikki avoimet välilehdet ennalleen. Se ei ota käyttöön tai vahvista odottavia asetuksia, eikä
ota käyttöön Käytä. Peruuta tai Escape säilyttää tyhjennetyn historian ja hylkää odottavat muokkaukset.
Tyhjennä on pois käytöstä aina, kun luettelo on tyhjä, ja sen tila päivitetään, kun luetteloon tulee uusia
raportteja. Rekisterin kirjoitusvirheestä ilmoitetaan välittömästi. Uuden välilehden nimirajoituksen
käyttöönotto päivittää jokaisen avoimen välilehden lataamatta sen mediaraporttia uudelleen.

## Lisenssi ja jakelu

Katsojalla on lisenssi MIT -lisenssillä license.txt.

MediaInfo on kolmannen osapuolen komponentti. Ainoa ylläpidetty jakeluilmoitus on root license.txt, joka on
koodattu muodossa UTF-8 ja CRLF ja joka sisältää katseluohjelman, kirjastot, staattisesti sisällytetyt
komponentit, kuvakkeen ja viralliset käännöstaulukot.

Tämä tuote käyttää MediaInfo-kirjastoa, tekijänoikeus (c) 2002-2026 MediaArea.net SARL.

- MediaInfo: <https://mediaarea.net/MediaInfo>
- Lisenssi: <https://mediaarea.net/en/MediaInfo/License>
- Windows latausta: <https://mediaarea.net/en/MediaInfo/Download/Windows>

## Riippuvuudet

### Tiedostot

| Resurssi | Arkkitehtuuri | Komponentin ilmoittama versio | SHA-256 |
| --- | --- | --- | --- |
| Resources/lib/26.10/MediaInfo.dll | x86 | 26.10 | E73027A1577084135425AA013D46C8B2985AD142CCF04F1ADB301B9A9CFB78F8 |
| Resources/lib/21.03/MediaInfo.dll | x86 | 21.03 | EBBF1C371702F3DC39CA23D619C47EDF97E66A95AEABE725284F1402D8F3E58A |
| Resources/lib/0.7.60/MediaInfo.dll | x86 | 0.7.60 | A26C07BCC25FA01A40E6888D02EABD59AA8DB2ABF6F5195481228D3A91D04441 |
| Resources/lib/26.10/libcurl.dll | x86 | 8.11.0-DEV, Schannel, zlib 1.3.1 | DCF136C84F3A4FBEAE2B317FE36D7F11225B56FBA3343AF4BBA8706B3F46F334 |
| Resources/lib/21.03/libcurl.dll | x86 | 7.47.1, WinSSL, zlib 1.2.8 | 21025CAC8089F1E570EE083D8CFD6311C2C51E97094A9FCD8C7A0B544C22CB48 |
| Resources/lib/libwebp.dll | x86 | 1.1.0 | 9986023BB6FF5510A157919F0CD958A94800EC6A1D981F3403A9648BEDFEE575 |

Taulukon polut ovat suhteessa MediaInfo-projektihakemistoon.

Nykyinen kirjasto raportoi kehitysversion; sen tarkkaa lähdettä commit ei voida palauttaa kyseisestä
versiomerkkijonosta. Sen oheisessa ilmoituksessa käytetään alkupään 8.11.0 tekijänoikeus- ja lupatekstiä,
jonka lisenssiehdot ovat mukana myös kehityssarjassa.

### Sisällytetyt komponentit

| Komponentti | Todisteet ja laajuus | Huomaa |
| --- | --- | --- |
| MediaInfoLib | Todelliset versiot ja vaaditut Unicode-vientit; muuttumattomina toimitetut binaarit | Versiokohtainen alkuperäinen tekijänoikeus, jakeluehdot ja vastuuvapauslauseke |
| ZenLib | Staattiset projektiviittaukset ja upotettu ZenLib RTTI kaikkiin kolmeen DLLs; tarkkoja linkitettyjä versioita ei toimitettu | zlib-tyylinen ZenLib huomautus |
| zlib | Upotetut inflate/deflate-versiot: 1.3.2 MediaInfo 26.10, 1.2.11 21.03, 1.2.7 0.7.60; curl raportoi lisäksi 1.3.1 ja 1.2.8 | Alkuperäiset zlib-ilmoitukset kaikille viidelle versiolle |
| TinyXML-2 | Vastaavat nykyaikaiset lähdekohteet ja binääri RTTI; sisältyvät vanhaan projektiin, mutta niitä ei tunnisteta itsenäisesti poistetussa legacy-binaarissa | Alkuperäinen Lee Thomason zlib-tyylinen huomautus säilytetty |
| Brian Gladman AES | Sisältyy molempiin nykyaikaisiin alkupään kirjastokohteisiin, ja niissä on vastaavat sallivat lähdeilmoitukset | 1998–2013 uudelleenjakoilmoitus ja vastuuvapauslauseke |
| Brian Gladman SHA-1/SHA-2 | Molemmat modernit kohteet; SHA-256 ja SHA-512 vakiotaulukot ovat läsnä molemmissa nykyaikaisissa binäärimuodoissa | 1998–2010 uudelleenjakoilmoitus ja vastuuvapauslauseke |
| Brian Gladman HMAC | Sekä nykyaikaiset kohteet että niiden curl/S3 lukijakoodi | Alkuperäinen kolmen ehdon ilmoitus, mukaan lukien sen vaihtoehtoista lisenssiä koskeva kohta |
| MD5 | Nykyaikaiset lähdekohteet; Colin Plumb-toteutus ilmoittaa nimenomaisesti julkisen käyttöoikeuden | Attribuutio säilytetty |
| Base64 | Markus Ewald otsikko kaikissa kolmessa vastaavassa lähdepuussa, hyvitetään Bob Withers | Alkuperäinen tekijän merkintä säilytetty; pätevyys alla |
| fmt | 26.10 kohde ja fmt v11 format_error RTTI binäärimuodossa | Alkuperäinen MIT-ilmoitus, mukaan lukien valinnainen poikkeus |
| tfsxml | 26.10 lähdekohde | Alkuperäinen MediaArea MIT ilmoitus |
| Android JNI käyttöliittymä | JNI_OnLoad on itse asiassa vienyt molemmat nykyaikaiset DLLs; mukana tuleva JNI-otsikko on lähteestä AOSP | AOSP tekijänoikeus ja täydellinen Apache-lisenssi 2.0 |
| libcurl | Mukana x86 binäärit; todellinen versio vienti; moderni MediaInfo käyttää dynaamisesti | Alkuperäiset curl ilmoitukset kohteille 8.11.0 ja 7.47.1 |
| Viralliset raporttikäännökset | Kaikki 38 muokkaamattomat CSV lähteet MediaInfo v26.10 -kielihakemistosta; 37 ei-englanninkieliset taulukot on upotettu, kun taas englanti käyttää DLL oletusasetuksia | Sama projektin BSD-2-Clause ilmoitus säilytettiin yhdistetyssä ilmoituksessa |
| MediaInfo -kuvake | Muokkaamaton virallinen monikuvakuvake, lähdeversio f057dd3649bc8692a83863b67770e22c9b9dd81a | Alkuperäinen BSD-2-Clause-ilmoitus ja merkintä |
| libwebp | WebPEncodeLosslessBGRA, WebPFree; 1.1.0; x86 | BSD-3-Clause; PATENTS |

Vastaavat lähdekohteet muodostavat sisällyttämisen näihin alkupään koontikokoonpanoihin; ne eivät todista,
että jokainen funktio selviää optimoinnista toimittajan binäärissä. Täsmällistä versiota ei vaadita
riippuvuuksille, joiden versiota ei ole tallennettu näihin binääriin.

### Valinnaiset komponentit ja järjestelmäkirjastot

- Windows-kirjastoprojektit mahdollistavat ajonaikaisesti ladatun libcurl:n MediaInfo 26.10:lle ja 21.03:lle.
  MediaInfo 0.7.60 rakennettiin MEDIAINFO_LIBCURL_NO:lla; sen binaari sisältää myös estetty-tuen
  diagnostiikan. Katsoja ei koskaan löydä, pura tai lataa curl-tiedostoa kyseiselle niputettuun versioon.
- libmms on poistettu käytöstä kaikissa kolmessa toimitetussa Windows DLLs:ssa, mikä vahvistetaan niiden
  upotetuissa estettyjen tukiviestien avulla. Sitä ei jaeta uudelleen.
- Qt ja wxWidgets kuuluvat valinnaisiin GUI koontiversioihin. Kumpikaan ei sisälly tähän katseluohjelmaan tai
  näihin DLL-riippuvuuksiin. Niiden yleiset merkinnät poistettiin näytetystä lisenssistä.
- Graphviz on valinnainen ajonaikainen koukku nykyaikaisessa ylävirran koodissa. Ei Graphviz DLL jaeta
  uudelleen.
- Mitään FFmpeg-laajennusta ei jaeta uudelleen.
- MediaInfo DLLs tuo suoraan vain KERNEL32.dll. Tämä ei tarkoita, että niiden staattisesti linkitetty
  suoritusaika ja apukoodi puuttuvat.
- Nykyinen curl tuo suoraan WS2_32.dll, bcrypt.dll, ADVAPI32.dll, CRYPT32.dll ja KERNEL32.dll. XP curl tuo
  suoraan WS2_32.dll, WLDAP32.dll, ADVAPI32.dll ja KERNEL32.dll. Nämä ovat Windows komponentteja.
  Windows-lataaja tarkistaa niiden saatavuuden.
- Curl raportoi Windows Schannel/WinSSL, ei OpenSSL koontiversiota. Sen ilmoitettu ylimääräinen
  pakkausriippuvuus sisältyy staattisesti zlib. Sen suoratuontitaulukossa ei näy muita ulkoisia ei-Windows
  DLL.
- Itse katseluohjelmalla ei ole C/C++ ajonaikaista riippuvuutta. Mukana toimitettu kolmannen osapuolen DLLs
  sisältää omat käännetyt ajonaikaiset osansa. Windows-koontiversiot käyttävät Microsoftin työkaluja; ei ole
  näyttöä, joka vaatisi yleisiä libstdc++ tai libc++ inventaariomerkintöjä.
- JPEG käyttää dynaamisesti ladattua järjestelmää GDI+. C#-resurssien pakkaaja ja PowerShell ovat
  rakennustyökaluja, eivätkä ne ole ajonaikaisia riippuvuuksia.

Tavallinen paikallisten tiedostojen tarkastus ei vaadi MediaArea-palvelinta tai etäladattavaa tietokantaa.
MediaInfo käyttää libcurl URL-tuloihin ja mahdollisesti etäviittauksiin tuetuissa mediamuodoissa. Sen
niputtaminen ei lisää erillistä URL-avauskomentoa tähän katseluohjelmaan.

### Lisenssien säilyttäminen ja rajoitukset

Ainoa ylläpidetty jakeluilmoitus on [license.txt](../license.txt) , koodattu UTF-8 ja CRLF. Tarkistetut BSD,
curl, zlib, MIT ja Apache-uudelleenjakolausekkeet eivät vaadi erillistä ilmoitustiedostoa fyysisesti kunkin
DLL:n viereen; yhdistetty ilmoitus on niiden mukana suoritus- ja jakelumateriaaleissa.

Arkistoitu paketti MediaInfo 0.7.60 käyttää omaa versiokohtaista lisenssiään ja sisältää vanhan GNU Library
GPL-tekstin. Sen ehdot erottavat nimenomaisesti muuntamattoman binaarisen uudelleenjakelun modifioiduista
versioista; tämän katseluohjelman dynaaminen linkitys ei muuta toimitettua DLL. Sen alkuperäiset ehdot ja
mukana oleva lisenssiteksti säilytetään. Katsoja pysyy MIT-lisensoituna.

Yksi alkupään attribuutio vaatii kelpuutuksen: Markus Ewald Base64-otsikolla ei ole nimenomaista lupaa tai
lisenssilauseketta. MediaArea kuvaa Bob Withers Base64 -toteutuksen julkisena MediaConch-dokumentaatiossaan,
mutta se ei määritä itsenäisesti lisenssin myöntämistä jokaiselle Ewald-muutokselle. Tälle otsikolle ei ole
keksitty lupaa. Täydellistä toimittajan vahvistusta alkuperästä, tarkat ZenLib-versiot ja curl-kehitys commit
eivät olleet saatavilla toimitetuissa binäärimuodoissa. Nämä kohdat estävät tämän inventaarion käsittelemisen
täydellisenä, itsenäisesti sertifioituna SBOM.

### Ensisijaiset lähteet

- [MediaInfo uudelleenjakoehdot](https://mediaarea.net/en/MediaInfo/License)
- 
  [MediaInfo 26.10 kirjaston kohde](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Project/MSVC2022/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 21.03 kirjaston kohde](https://github.com/MediaArea/MediaInfoLib/blob/v21.03/Project/MSVC2015/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 0.7.60 kirjaston kohde](https://github.com/MediaArea/MediaInfoLib/blob/v0.7.60/Project/MSVC2005/Library/MediaInfoLib.vcproj)
- 
  [Runtime curl loader](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Source/MediaInfo/Reader/Reader_libcurl.cpp)
- 
  [Mukana olevat apulähteet ja niiden ilmoitukset](https://github.com/MediaArea/MediaInfoLib/tree/v26.10/Source/ThirdParty)
- [ZenLib huomautus](https://github.com/MediaArea/ZenLib/blob/master/License.txt)
- [zlib lähdeilmoitukset](https://github.com/madler/zlib/blob/v1.3.2/zlib.h)
- [curl 8.11.0 huomautus](https://github.com/curl/curl/blob/curl-8_11_0/COPYING)
- [curl 7.47.1 huomautus](https://github.com/curl/curl/blob/curl-7_47_1/COPYING)
- [Apache-lisenssi 2.0](https://www.apache.org/licenses/LICENSE-2.0)
- [MediaArea Base64 kuvaus](https://github.com/MediaArea/MediaConch/blob/master/README.md)

Raporttitaulukot ovat peräisin osoitteesta
<https://github.com/MediaArea/MediaInfo/tree/v26.10/Source/Resource/Plugin/Language> . Vastaava projekti
LICENSE on <https://github.com/MediaArea/MediaInfo/blob/v26.10/LICENSE> .

- [libwebp 1.1.0 COPYING](https://github.com/webmproject/libwebp/blob/v1.1.0/COPYING)
- [libwebp 1.1.0 PATENTS](https://github.com/webmproject/libwebp/blob/v1.1.0/PATENTS)
