# MediaInfo Viewer

[Čeština](README.cs-CZ.md) | [English (US)](../README.md) | [English (UK)](README.en-GB.md) | [English (Australia)](README.en-AU.md) | [Deutsch](README.de-DE.md) | [Français](README.fr-FR.md) | [Español](README.es-ES.md) | [Italiano](README.it-IT.md) | [Português](README.pt-PT.md) | [Polski](README.pl-PL.md) | [Slovenčina](README.sk-SK.md) | [Dansk](README.da-DK.md) | [Suomi](README.fi-FI.md) | [Íslenska](README.is-IS.md) | [Norsk (bokmål)](README.nb-NO.md) | [Svenska](README.sv-SE.md) | [Türkçe](README.tr-TR.md) | [Eesti](README.et-EE.md) | [Gaeilge](README.ga-IE.md) | [Lietuvių](README.lt-LT.md) | [Latviešu](README.lv-LV.md) | [Magyar](README.hu-HU.md) | [Malti](README.mt-MT.md) | [Nederlands](README.nl-NL.md) | [Română](README.ro-RO.md) | [Ελληνικά](README.el-GR.md) | [Bosanski](README.bs-Latn-BA.md) | **Hrvatski** | [Slovenščina](README.sl-SI.md) | [Crnogorski](README.cnr-Latn-ME.md) | [Беларуская](README.be-BY.md) | [Български](README.bg-BG.md) | [Македонски](README.mk-MK.md) | [Српски](README.sr-Cyrl-RS.md) | [Українська](README.uk-UA.md) | [Русский](README.ru-RU.md)

Izvorni Windows x86 preglednik izvješća MediaInfo.dll. Svaka datoteka ima vlastitu karticu samo za čitanje.

[Izgradnja i kompatibilnost](#prevođenje) | [Provjera ovisnosti](#ovisnosti) | [Licenca](../license.txt)

## Prevođenje

Otvorite MediaInfo.sln u Visual Studio 2015 s instaliranim skupom alata Visual C++ v140. Odaberite Release | Win32 i izradite rješenje. Jedina aplikacijska platforma je Win32 (x86).

[PCRE2 10.49](https://github.com/PCRE2Project/pcre2/tree/pcre2-10.49) — UTF-16, statički povezano,
BSD-3-Clause. [Izvorni kod](../MediaInfo/PCRE2/).
[license.txt](../license.txt).
PCRE2 je ugrađena u EXE i ne zahtijeva zasebnu DLL datoteku ni dodatnu instalaciju.

Izlazi:

- Release\MediaInfo.exe
- Debug\MediaInfo.exe

Preglednik ne povezuje C ili C++ runtime i ne treba MSVC mogućnost redistribucije. Odabrani MediaInfo.dll može
imati vlastite ovisnosti.

Za izgradnju su potrebni Windows PowerShell i .NET Framework. Ovo su samo zahtjevi za izgradnju; izvorna
izvršna datoteka ne zahtijeva ni PowerShell ni .NET.

### Distribucijski paket

Nakon izgradnje Release, pokrenite
`powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\PackageRelease.ps1` . Skripta stvara
`MediaInfo-<version>-win32.zip` u direktoriju rješenja, koristeći verziju izvršne datoteke od četiri dijela.
Arhiva sadrži `MediaInfo.exe` i kombinirani `license.txt` izravno u svom korijenu.

## Kompatibilnost

Preglednik Win32 dizajniran je za korištenje Windows NT 4.0 APIs.

Izvršna datoteka uključuje tri biblioteke x86 MediaInfo: 26.10 za trenutni Windows, 21.03 iz paketa Windows XP
i 0.7.60 iz paketa Windows 95–2000. Sama arhitektura knjižnice ne određuje njezinu kompatibilnost s
operativnim sustavom. Preglednik isprobava biblioteke u paketu od najnovije do najstarije i zaustavlja se
nakon prvog uspješnog učitavanja i upita za verziju.

Windows 95 trenutno nije podržano runtime.

## Upotreba

- Datoteka > Otvori (Ctrl+O) otvara dijaloški okvir datoteke Windows s višestrukim odabirom. Na Windows Vista
  i novijim, Otvori i Spremi koriste moderni dijaloški okvir za zajedničke stavke; stariji Windows koriste
  naslijeđene zajedničke dijaloge.
- Povucite jednu ili više datoteka u prozor, na ikonu EXE datoteke ili njezin prečac ili predajte njihove
  putanje putem naredbenog retka. Ako više instanci nije dopušteno, datoteke se otvaraju u već pokrenutom
  prozoru.
- Svaka posebna normalizirana puna staza ima jednu karticu. Ponovno otvaranje već otvorene datoteke odabire
  njezinu postojeću karticu bez ponovnog učitavanja ili mijenjanja izvješća, odabira ili položaja pomicanja.
  Usporedbe zanemaruju velika i mala slova puta. Otvaranje više datoteka obrađuje popis redom i ostavlja
  aktivnom posljednju uspješno obrađenu datoteku, bilo da je tek otvorena ili već otvorena. Postavljanje
  pokazivača iznad zaglavlja kartice prikazuje cijeli put datoteke u izvornom opisu alata, uključujući i kada
  je prikazani naziv datoteke skraćen.
- Izbornik Datoteka navodi osam posljednjih učitanih datoteka neposredno iznad Izlaz, između separatora. Unosi
  prikazuju samo broj i naziv datoteke. Odabirom unosa otvara se njegova pohranjena puna putanja ili odabire
  postojeća kartica; uspješno ponovno otvaranje pomiče ga na vrh bez duplikata. Odabirom nedostupne datoteke
  postavlja se pitanje treba li ukloniti unos nedavnih datoteka. Koriste se izvorna ikona pitanja i gumbi
  Yes/No. Da je zadana postavka i uklanja unos iz izbornika i registra; Ne zadržava ga. Upit uključuje puni
  put.
- Kotačić miša preko prepunih zaglavlja kartica pomiče traku zaglavlja jednu karticu po poruci bez promjene
  odabira ili fokusa.
- Ctrl+Tab i Ctrl+Shift+Tab mijenjanje kartica; Ctrl+W zatvara aktivnu karticu. Srednjim pritiskom na
  zaglavlje kartice zatvara se ta kartica dok se zadržavaju sve druge aktivne kartice. Datoteka > Zatvori sve
  zatvara sve kartice, uključujući izvješća u čekanju. File > Exit (Alt+F4) zatvara aplikaciju.
- Dupli klik odabire riječ. Trostruki klik odabire logičnu liniju. Povlačenjem se odabir proširuje riječima
  ili retcima.
- Ctrl+A odabire izvješće; Ctrl+C ga kopira.
- Uređivanje > Pronađi (Ctrl+F) pretražuje aktivnu karticu. F3 ponavlja pretraživanje, a Shift+F3 mijenja
  njegov smjer. Na kraju teksta pretraživanje se nastavlja s drugog kraja. Mogućnosti > Prelamanje redaka
  vrijedi samo za aktivnu karticu; oznaka prati odabranu karticu. Prozor pretraživanja može se minimizirati i
  mijenjati mu se širina; položaj i mogućnost Uvijek na vrhu pamte se. Do 30 tekstova pretraživanja s njihovim
  mogućnostima čuva se samo do zatvaranja aplikacije. Mogućnosti početka i kraja odnose se na logičke retke.
  Regularni izrazi koriste sintaksu PCRE2. Sve naredbe izbornika Uređivanje odnose se samo na aktivnu karticu.
  Enter pokreće pretraživanje, a Shift+Enter obrće odabrani smjer. „Razlikuj velika i mala slova“ razlikuje
  velika i mala slova; „Traži unatrag“ pretražuje prema početku teksta. Odabir stavke povijesti vraća svih pet
  mogućnosti pretraživanja, uključujući postavku regularnih izraza; „Uvijek na vrhu“ neovisna je mogućnost.
  „Regularni izraz“ onemogućuje „Redak počinje s“ i „Redak završava s“. Kada su uključene obje mogućnosti
  krajeva retka, dovoljno je podudaranje na jednom kraju. „Prelamanje redaka“ mijenja samo prikaz.
- Mogućnosti > Postavke (Ctrl+G) otvara jedan dijaloški okvir postavki za staze MediaInfo i curl, font
  izvješća, antialiasing fonta, jezik sučelja i jezik izvješća. Prazna staza DLL omogućuje automatsko
  otkrivanje.
- Gumb fonta prikazuje obitelj, veličinu i stil fonta i otvara standardni dijaloški okvir Windows fonta.
  Zadana vrijednost vraća Consolas ili Courier New ako Consolas nije dostupan; gumb Zadano je onemogućen dok
  je odabrano zadano. Fontovi koje je odabrao korisnik zadržavaju se bez zamjene kodom aplikacije.
- Izbori antialiasinga fonta su ClearType kada je podržano, GDI i Ništa. Početni izbor je ClearType kada je
  podržan, inače GDI. Postavke fonta utječu samo na medijska izvješća i njihov izvoz slika.
- Datoteka > Izvoz (Ctrl+E) otvara dijaloški okvir Windows Spremi kao i izvozi cijelo aktivno izvješće u TXT,
  BMP, GIF, JPEG, PNG, TIFF ili WebP, uključujući tekst izvan vidljivog područja.
- Pomoć otvara zaseban nemodalni prozor s vlastitim unosom programske trake i gumbom za minimiziranje. O je
  modalni dijalog; njegovo zaglavlje proizvoda navodi sve tri ugrađene verzije DLL.

Ispis… (Ctrl+P) otvara sistemski dijalog za odabir pisača i ispisuje cijelu aktivnu karticu bez pretpregleda.
Koristi se font izvješća; dugi se redci prelamaju, a tekst dijeli na stranice. Ispis se odvija u pozadini.

Otvori mapu… otvara datoteke koje se nalaze izravno u odabranoj mapi, svaku na zasebnoj kartici. Podmape nisu
uključene. Otvori i Otvori mapu dijele posljednju odabranu mapu. Izvoz pamti zasebnu mapu, zadano Dokumenti.

Napredni način rada prikazuje dodatna polja izvješća.

Potpuna analiza ispituje cijelu datoteku i može trajati duže. Ove opcije izvješća i Razina praćenja pripadaju
svakoj kartici; promjena osvježava samo aktivnu karticu. Posljednja ručno odabrana kombinacija sprema se za
nove kartice i sljedeće pokretanje. Podudarno predmemorirano izvješće ponovno se koristi dok datoteka ostaje
nepromijenjena.

Poznati formati, Poznati kodeci i Poznati parametri otvaraju se na zasebnim karticama izvješća.

Početnu veličinu i lokaciju prozora odabire Windows. Prethodno spremljeni položaj prozora poništava te zadane
postavke pri kasnijim pokretanjima.

Lijeva strana trake stanja prikazuje putanje datoteka i tijek učitavanja, a desna verziju učitane biblioteke
MediaInfo.dll. Duge putanje skraćuju se trotočkom prema dostupnom prostoru.

## Kreirati zaglavnu datoteku

Izbornik Alati je četvrti na traci izbornika. Njegova naredba Kreirati zaglavnu datoteku… otvara jednu izvornu
datoteku neovisno o karticama izvješća i kopira njenih prvih 524288 bajtova (512 KiB). Kraća datoteka kopira
se u cijelosti; prazna datoteka daje prazan izlaz. Ovo je obično čitanje binarne datoteke, bez MediaInfo
analize ili zahtjeva za MediaInfo.dll. Alat ostavlja nepromijenjene kartice izvješća i preglednikov popis
nedavnih datoteka.

Nakon čitanja, dijaloški okvir Spremi kao pokreće se u mapi izvorne datoteke i predlaže video.mp4.header za
video.mp4: .header se dodaje cijelom izvornom nazivu. Možete promijeniti i naziv i odredišnu mapu. Otkazivanje
bilo kojeg dijaloškog okvira ne zapisuje izlaznu datoteku. Zamjena postojećeg odredišta zahtijeva potvrdu.
Izvor ostaje nepromijenjen; neuspješno spremanje čuva prethodno odredište. Za otvaranje i spremanje koriste se
najnoviji sistemski dijaloški okviri dostupni u toj verziji sustava Windows.

Prilikom pokretanja aplikacije, alat preuzima početnu ulaznu mapu iz Datoteka > Otvori. Ako mapa nije
spremljena, Windows odabire početnu lokaciju. Nakon odabira ulazne datoteke, alat pamti vlastitu mapu samo dok
se aplikacija ne zatvori, čak i ako se Spremi kao otkaže. Ne mijenja mape koje koriste Otvori i Izvezi niti
sprema vlastitu mapu u postavke aplikacije. Svaki dijaloški okvir Spremi kao počinje u mapi trenutno odabrane
ulazne datoteke, bez obzira na prethodno odredište spremanja.

## Pronalaženje biblioteka

Prvo se isprobava spremljeni ručni put. Ako se ne može učitati, automatsko otkrivanje pokušava:

1. MediaInfo.dll pored izvršne datoteke, zatim u svakom nadređenom direktoriju do pogona ili UNC korijenskog
   dijeljenja.
2. ProgramFiles, ProgramFiles(x86) i ProgramW6432.
3. LOCALAPPDATA i APPDATA.

Ispod ovih instalacijskih korijena, otkrivanje provjerava MediaInfo, MediaArea\MediaInfo, MediaArea,
MediaArea.net\MediaInfo, Programs\MediaInfo, Programs\MediaArea\MediaInfo. Nečitljive lokacije i
nekompatibilni DLLs su preskočeni. Ne skenira rekurzivno disk.

Ako nije pronađen kompatibilni vanjski DLL, preglednik isprobava ugrađene verzije ovim redoslijedom: 26.10,
21.03, 0.7.60. Ekstrahira i testira jednu po jednu verziju. Nakon što se verzija uspješno učita, starije
verzije se ne izdvajaju niti testiraju. Dovoljna je samo distribucija MediaInfo.exe; kompatibilni vanjski DLL
uvijek ima prioritet i može se neovisno ažurirati.

Neuspjela ručna promjena biblioteke zadržava biblioteku koja je već učitana.

## Izvoz izvješća

Formati Spremi kao poredani su TXT, BMP, GIF, JPEG, PNG, TIFF i WebP. Nepodržani koderi izostavljeni su iz
modernih i naslijeđenih dijaloških okvira.

TXT nudi ANSI, UTF-8, UTF-8 s BOM-om, UTF-16 BE s BOM-om i UTF-16 LE s BOM-om. Zadana je druga stavka, UTF-8
bez BOM-a. Čuvaju se cijeli tekst izvješća i izvorni završeci redaka.

BMP, PNG i TIFF čuvaju sve prikazane boje; GIF89a čuva točno prikazanu paletu kada slika ima najviše 256 boja.
Izvoz uvijek zapisuje odabrani format ili javlja pogrešku; nikada ne zamjenjuje drugi format.

Slike sadrže cijelo izvješće u odabranom fontu izvješća, s crnim tekstom na bijeloj pozadini. Ne sadrže
izbornik aplikacije, zaglavlja kartica, statusnu traku, odabir ili umetanje. Iscrtavanje je neovisno o
položaju pomicanja tekstualnog okvira.

Kako bi se izbjeglo tiho skraćivanje izvješća ili iscrpljivanje adresnog prostora na starijim računalima,
jedna slika je ograničena na 16.384 piksela širine, 32.767 piksela visine i 256 MiB nekomprimirane bitmap
memorije. Odaberite manji font ako izvješće premašuje ta ograničenja.

`Google WebP (*.webp)` posljednji je format i sprema izvješće bez gubitaka.

WebP: 16383 × 16383 px.

## Jezici sučelja i izvješća

Postavke (Mogućnosti > Postavke, Ctrl+G) sadrže putanje knjižnica, font izvješća, izglađivanje i jezike.
Sučelje ima 36 inačica i početno prati Windows. Izvješća uvijek zadano koriste izvorni engleski knjižnice,
neovisno o Windowsu i sučelju. To mijenja samo ručni odabir jezika: engleski, 37 prijevoda ili vlastita
MediaInfo CSV tablica.

U redu ili Primijeni potvrđuje promjene; Odustani odbacuje nepotvrđene promjene. Postavke određuju ograničenje
naziva kartice (zadano 80) i brišu popis nedavnih datoteka. Dugi nazivi zadržavaju početak, kraj i nastavak s
trotočkom u sredini.

Prema zadanim postavkama dopuštena je samo jedna instanca, a sljedeća pokretanja šalju datoteke otvorenom
prozoru. U postavkama se može dopustiti više instanci. Kada postoji više prozora, samo prvi prozor svakog
obrasca vraća spremljeni položaj; ostali vraćaju samo veličinu.

Promjenom samo sučelja tekst otvorenih izvješća ostaje nepromijenjen. Ručno primijenjena promjena jezika
izvješća ponovno učitava njihova izvješća uz očuvanje redoslijeda kartica i redoslijeda MRU.

## libcurl

Automatske provjere otkrivanja curl pored odabranih MediaInfo DLL, zatim dijeljenih executable/ancestor,
programskih datoteka i korisničkih instalacijskih lokacija. Ako se ne pronađe kompatibilni vanjski curl,
odgovarajuća ugrađena trenutna ili XP verzija ekstrahira se u provjerenu predmemoriju po korisniku. Najstariji
MediaInfo 0.7.60 u potpunosti zaobilazi curl otkrivanje, izdvajanje i učitavanje. Eksplicitno odabrani
nevažeći curl odbija promjenu preference; nedostatak izbornog automatskog curl ne sprječava obična izvješća
lokalne datoteke.

## Nazivi datoteka i nedavne datoteke

Nazivi datoteka MRU skraćuju se samo ako su dulji od 80 UTF-16 kodnih jedinica. Srednja elipsa čuva početak,
kraj naziva datoteke prije njenog proširenja i potpuno konačno proširenje; puni putovi i izvješća ostaju
nepromijenjeni. Opisi kartica koriste isti algoritam sa konfigurabilnim zadanim ograničenjem od 80.

Nedavne datoteke > Očisti odmah briše i živi MRU izbornik i njegove spremljene staze dok sve otvorene kartice
ostavlja netaknutima. Ne primjenjuje niti potvrđuje postavke na čekanju i ne omogućuje Primijeni. Cancel ili
Escape čuva izbrisanu povijest dok odbacuje izmjene na čekanju. Brisanje je onemogućeno svaki put kada je
popis prazan, a njegovo se stanje osvježava kada nova izvješća popune popis. Odmah se prijavljuje neuspjeh
pisanja u registar. Primjenom novog ograničenja naziva kartice ažurira se svaka otvorena kartica bez ponovnog
učitavanja njezinog medijskog izvješća.

## Licenca i redistribucija

Preglednik je licenciran pod licencom MIT u license.txt.

MediaInfo je komponenta treće strane. Jedina održavana obavijest o distribuciji je root license.txt, kodiran
kao UTF-8 s CRLF i uključuje preglednik, biblioteke, statički ugrađene komponente, ikonu i službene tablice
prijevoda.

Ovaj proizvod koristi biblioteku MediaInfo, Autorska prava (c) 2002-2026 MediaArea.net SARL.

- MediaInfo: <https://mediaarea.net/MediaInfo>
- Licenca: <https://mediaarea.net/en/MediaInfo/License>
- Windows preuzimanja: <https://mediaarea.net/en/MediaInfo/Download/Windows>

## Ovisnosti

### Datoteke

| Resurs | Arhitektura | Verzija koju je prijavila komponenta | SHA-256 |
| --- | --- | --- | --- |
| Resources/lib/26.10/MediaInfo.dll | x86 | 26.10 | E73027A1577084135425AA013D46C8B2985AD142CCF04F1ADB301B9A9CFB78F8 |
| Resources/lib/21.03/MediaInfo.dll | x86 | 21.03 | EBBF1C371702F3DC39CA23D619C47EDF97E66A95AEABE725284F1402D8F3E58A |
| Resources/lib/0.7.60/MediaInfo.dll | x86 | 0.7.60 | A26C07BCC25FA01A40E6888D02EABD59AA8DB2ABF6F5195481228D3A91D04441 |
| Resources/lib/26.10/libcurl.dll | x86 | 8.11.0-DEV, Schannel, zlib 1.3.1 | DCF136C84F3A4FBEAE2B317FE36D7F11225B56FBA3343AF4BBA8706B3F46F334 |
| Resources/lib/21.03/libcurl.dll | x86 | 7.47.1, WinSSL, zlib 1.2.8 | 21025CAC8089F1E570EE083D8CFD6311C2C51E97094A9FCD8C7A0B544C22CB48 |
| Resources/lib/libwebp.dll | x86 | 1.1.0 | 9986023BB6FF5510A157919F0CD958A94800EC6A1D981F3403A9648BEDFEE575 |

Putanje u tablici relativne su u odnosu na direktorij projekta MediaInfo.

Trenutna knjižnica izvješćuje o razvojnoj verziji; njegov točan izvor commit ne može se povratiti iz tog niza
verzije. Njegova popratna obavijest koristi prethodni 8.11.0 tekst autorskih prava i dopuštenja, čiji su
licencni uvjeti također prisutni u razvojnoj seriji.

### Ugrađene komponente

| komponenta | Dokazi i opseg | Obavijest |
| --- | --- | --- |
| MediaInfoLib | Stvarne verzije i potrebni Unicode izvozi; nepromijenjene isporučene binarne datoteke | Izvorna autorska prava specifična za verziju, uvjeti redistribucije i odricanje od odgovornosti |
| ZenLib | Statičke reference projekta i ugrađeni ZenLib RTTI u sva tri DLLs; točne povezane revizije nisu navedene | Obavijest u stilu zlib ZenLib |
| zlib | Ugrađeni nizovi inflate/deflate verzije: 1.3.2 u MediaInfo 26.10, 1.2.11 u 21.03, 1.2.7 u 0.7.60; curl dodatno izvješćuje 1.3.1 i 1.2.8 | Izvorne zlib obavijesti za svih pet verzija |
| TinyXML-2 | Usklađivanje modernih ciljeva izvora i binarnih RTTI; uključeni u naslijeđeni projekt, ali nisu neovisno identificirani u ogoljenoj naslijeđenoj binarnici | Izvorna obavijest u stilu Lee Thomason zlib zadržana |
| Brian Gladman AES | Uključeno u obje suvremene upstream bibliotečke ciljeve, s odgovarajućim dopuštenim obavijestima o izvoru | 1998–2013 obavijest o ponovnoj distribuciji i odricanje od odgovornosti |
| Brian Gladman SHA-1/SHA-2 | Obje moderne mete; SHA-256 i SHA-512 konstantne tablice prisutne u obje moderne binarne datoteke | 1998–2010 obavijest o ponovnoj distribuciji i odricanje od odgovornosti |
| Brian Gladman HMAC | Obje moderne mete i njihov kod čitača curl/S3 | Izvorna obavijest s tri uvjeta, uključujući paragraf alternativne licence |
| MD5 | Suvremeni izvorni ciljevi; Implementacija Colin Plumb eksplicitno navodi javnu domenu | Atribucija zadržana |
| Base64 | Markus Ewald zaglavlje u sva tri odgovarajuća izvorna stabla, pripisujući Bob Withers | Izvorno pripisivanje autorstva zadržano; kvalifikacija u nastavku |
| fmt | 26.10 cilj i fmt v11 format_error RTTI u binarnom obliku | Izvorna MIT obavijest, uključujući neobveznu iznimku |
| tfsxml | 26.10 izvorni cilj | Izvorna MediaArea MIT obavijest |
| Android JNI sučelje | JNI_OnLoad zapravo izvoze oba moderna DLLs; uključeno JNI zaglavlje je iz AOSP | AOSP autorsko pravo i potpuna Apache licenca 2.0 |
| libcurl | Isporučene x86 binarne datoteke; izvoz stvarne verzije; dinamički koristi moderni MediaInfo | Izvorne curl obavijesti za 8.11.0 i 7.47.1 |
| Službeni prijevodi izvješća | Svi 38 neizmijenjeni CSV izvori iz jezičnog imenika MediaInfo v26.10; 37 neengleske tablice su ugrađene, dok engleski koristi zadane DLL | Obavijest o istom projektu BSD-2-Clause zadržana je u kombiniranoj obavijesti |
| MediaInfo ikona | Nemodificirana službena ikona s više slika, revizija izvora f057dd3649bc8692a83863b67770e22c9b9dd81a | Izvorna BSD-2-Clause obavijest i atribucija |
| libwebp | WebPEncodeLosslessBGRA, WebPFree; 1.1.0; x86 | BSD-3-Clause; PATENTS |

Odgovarajući izvorni ciljevi uspostavljaju uključenost u te uzvodne konfiguracije izgradnje; oni ne dokazuju
da svaka funkcija preživljava optimizaciju u binarnim datotekama dobavljača. Ne zahtijeva se točna verzija za
ovisnosti čija revizija nije zabilježena u tim binarnim datotekama.

### Izborne komponente i sistemske biblioteke

- Projekti knjižnice Windows omogućuju libcurl s učitavanjem vremena izvođenja za MediaInfo 26.10 i 21.03.
  MediaInfo 0.7.60 izgrađen je s MEDIAINFO_LIBCURL_NO; njegova binarna datoteka također sadrži dijagnostiku
  onemogućene podrške. Gledatelj nikada ne otkriva, izdvaja ili učitava curl za tu verziju paketa.
- libmms je onemogućen u sva tri isporučena Windows DLLs, što potvrđuju njihove ugrađene poruke o onemogućenoj
  podršci. Ne raspodjeljuje se.
- Qt i wxWidgets pripadaju izbornim verzijama GUI. Nijedno nije uključeno u ovaj preglednik ili u ove DLL
  ovisnosti. Njihovi generički unosi uklonjeni su iz prikazane licence.
- Graphviz je izborna kuka za vrijeme izvođenja u modernom uzvodnom kodu. Nijedan Graphviz DLL nije
  redistribuiran.
- Nijedan FFmpeg dodatak se ne distribuira dalje.
- MediaInfo DLLs izravno uvozi samo KERNEL32.dll. To ne znači da njihovo statički povezano vrijeme izvođenja i
  pomoćni kod nedostaju.
- Trenutačni curl izravno uvozi WS2_32.dll, bcrypt.dll, ADVAPI32.dll, CRYPT32.dll i KERNEL32.dll. XP curl
  izravno uvozi WS2_32.dll, WLDAP32.dll, ADVAPI32.dll i KERNEL32.dll. Ovo su komponente Windows. Njihovu
  dostupnost provjerava učitavač Windows.
- Curl izvješćuje Windows Schannel/WinSSL, a ne OpenSSL međugradnju. Njegova prijavljena dodatna ovisnost o
  kompresiji statički je uključena zlib. Nikakav dodatni vanjski ne-Windows DLL ne pojavljuje se u njegovoj
  tablici izravnog uvoza.
- Sam preglednik nema ovisnost o vremenu izvođenja C/C++. Isporučeni DLLs treće strane sadrži vlastite
  kompajlirane dijelove vremena izvođenja. Windows međugradnje koriste Microsoftove alate; nema dokaza koji
  zahtijevaju generičke libstdc++ ili libc++ unose inventara.
- JPEG koristi dinamički učitani sustav GDI+. Paker resursa C# i PowerShell alati su za izgradnju i nisu
  ovisnosti o vremenu izvođenja.

Uobičajena inspekcija lokalne datoteke ne zahtijeva MediaArea poslužitelj ili daljinski preuzet format baze
podataka. libcurl koristi MediaInfo za URL ulaze i potencijalno udaljene reference u podržanim medijskim
formatima. Spajanjem u paket ne dodaje se zasebna naredba za otvaranje URL ovom pregledniku.

### Pohranjivanje licence i ograničenja

Jedina održavana obavijest o distribuciji je [license.txt](../license.txt) , kodirana kao UTF-8 s CRLF.
Označene klauzule o redistribuciji BSD, curl, zlib, MIT i Apache ne zahtijevaju posebnu datoteku obavijesti
fizički pored svakog DLL; kombinirana obavijest prati ih u izvršnim i distribucijskim materijalima.

Arhivirani paket MediaInfo 0.7.60 koristi vlastitu licencu specifičnu za verziju i uključuje stari tekst GNU
Library GPL. Njegovi uvjeti izričito razlikuju nemodificiranu binarnu redistribuciju od modificiranih verzija;
dinamičko povezivanje ovog preglednika ne mijenja isporučeni DLL. Njegovi izvorni uvjeti i popratni tekst
licence su zadržani. Gledatelj ostaje s licencom MIT.

Jedna uzvodna atribucija zahtijeva kvalifikaciju: zaglavlje Markus Ewald Base64 nema eksplicitnu dozvolu ili
izjavu o licenci. MediaArea opisuje implementaciju Bob Withers Base64 kao javnu domenu u svojoj povezanoj
MediaConch dokumentaciji, ali to ne uspostavlja neovisno dodjelu licence za svaku Ewald promjenu. Za to
zaglavlje nije izmišljeno dodjeljivanje licence. Potpuna potvrda dobavljača tog porijekla, točnih ZenLib
revizija i curl razvoja commit nije bila dostupna u isporučenim binarnim datotekama. Ove točke sprječavaju
tretiranje ovog inventara kao potpunog, neovisno certificiranog SBOM.

### Primarni izvori

- [MediaInfo uvjeti redistribucije](https://mediaarea.net/en/MediaInfo/License)
- 
  [MediaInfo 26.10 cilj knjižnice](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Project/MSVC2022/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 21.03 cilj knjižnice](https://github.com/MediaArea/MediaInfoLib/blob/v21.03/Project/MSVC2015/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 0.7.60 cilj knjižnice](https://github.com/MediaArea/MediaInfoLib/blob/v0.7.60/Project/MSVC2005/Library/MediaInfoLib.vcproj)
- 
  [Runtime curl loader](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Source/MediaInfo/Reader/Reader_libcurl.cpp)
- 
  [Skupni pomoćni izvori i njihove obavijesti](https://github.com/MediaArea/MediaInfoLib/tree/v26.10/Source/ThirdParty)
- [ZenLib obavijest](https://github.com/MediaArea/ZenLib/blob/master/License.txt)
- [zlib izvorne obavijesti](https://github.com/madler/zlib/blob/v1.3.2/zlib.h)
- [curl 8.11.0 obavijest](https://github.com/curl/curl/blob/curl-8_11_0/COPYING)
- [curl 7.47.1 obavijest](https://github.com/curl/curl/blob/curl-7_47_1/COPYING)
- [Apache licenca 2.0](https://www.apache.org/licenses/LICENSE-2.0)
- [MediaArea Base64 opis](https://github.com/MediaArea/MediaConch/blob/master/README.md)

Tablice izvješća potječu iz
<https://github.com/MediaArea/MediaInfo/tree/v26.10/Source/Resource/Plugin/Language> . Odgovarajući projekt
LICENSE je <https://github.com/MediaArea/MediaInfo/blob/v26.10/LICENSE> .

- [libwebp 1.1.0 COPYING](https://github.com/webmproject/libwebp/blob/v1.1.0/COPYING)
- [libwebp 1.1.0 PATENTS](https://github.com/webmproject/libwebp/blob/v1.1.0/PATENTS)
