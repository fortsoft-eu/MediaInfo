# MediaInfo Viewer

[Čeština](README.cs-CZ.md) | [English (US)](../README.md) | [English (UK)](README.en-GB.md) | [English (Australia)](README.en-AU.md) | [Deutsch](README.de-DE.md) | [Français](README.fr-FR.md) | [Español](README.es-ES.md) | [Italiano](README.it-IT.md) | [Português](README.pt-PT.md) | [Polski](README.pl-PL.md) | [Slovenčina](README.sk-SK.md) | [Dansk](README.da-DK.md) | [Suomi](README.fi-FI.md) | [Íslenska](README.is-IS.md) | [Norsk (bokmål)](README.nb-NO.md) | [Svenska](README.sv-SE.md) | [Türkçe](README.tr-TR.md) | [Eesti](README.et-EE.md) | [Gaeilge](README.ga-IE.md) | [Lietuvių](README.lt-LT.md) | [Latviešu](README.lv-LV.md) | [Magyar](README.hu-HU.md) | [Malti](README.mt-MT.md) | [Nederlands](README.nl-NL.md) | [Română](README.ro-RO.md) | [Ελληνικά](README.el-GR.md) | **Bosanski** | [Hrvatski](README.hr-HR.md) | [Slovenščina](README.sl-SI.md) | [Crnogorski](README.cnr-Latn-ME.md) | [Беларуская](README.be-BY.md) | [Български](README.bg-BG.md) | [Македонски](README.mk-MK.md) | [Српски](README.sr-Cyrl-RS.md) | [Українська](README.uk-UA.md) | [Русский](README.ru-RU.md)

Izvorni Windows x86 preglednik izvještaja MediaInfo.dll. Svaka datoteka ima vlastitu karticu samo za čitanje.

[Izgradnja i kompatibilnost](#kompajliranje) | [Provjera zavisnosti](#zavisnosti) | [Licenca](../license.txt)

## Kompajliranje

Otvorite MediaInfo.sln u Visual Studio 2015 sa instaliranim skupom alata Visual C++ v140. Odaberite Release | Win32 i izgraditi rješenje. Jedina aplikacijska platforma je Win32 (x86).

[PCRE2 10.49](https://github.com/PCRE2Project/pcre2/tree/pcre2-10.49) — UTF-16, statički povezano,
BSD-3-Clause. [Izvorni kod](../MediaInfo/PCRE2/).
[license.txt](../license.txt).
PCRE2 je ugrađena u EXE i ne zahtijeva zasebnu DLL datoteku ni dodatnu instalaciju.

Izlazi:

- Release\MediaInfo.exe
- Debug\MediaInfo.exe

Pregledač ne povezuje C ili C++ vrijeme izvođenja i ne treba mu MSVC redistributivni. Odabrani MediaInfo.dll
može imati svoje zavisnosti.

Za izgradnju su potrebni Windows PowerShell i .NET Framework. Ovo su samo zahtjevi za izgradnju; izvorni
izvršni fajl ne zahtijeva ni PowerShell ni .NET.

### Distribucijski paket

Nakon izgradnje Release, pokrenite
`powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\PackageRelease.ps1` . Skripta kreira
`MediaInfo-<version>-win32.zip` u direktoriju rješenja, koristeći verziju izvršne datoteke od četiri dijela.
Arhiva sadrži `MediaInfo.exe` i kombinovani `license.txt` direktno u svom korijenu.

## Kompatibilnost

Preglednik Win32 je dizajniran da koristi Windows NT 4.0 APIs.

Izvršni program uključuje tri x86 MediaInfo biblioteke: 26.10 za trenutni Windows, 21.03 iz Windows XP paketa
i 0.7.60 iz Windows 95–2000 paketa. Arhitektura biblioteke sama po sebi ne određuje njenu kompatibilnost sa
operativnim sistemom. Pregledač isprobava povezane biblioteke od najnovije do najstarije i zaustavlja se nakon
prvog uspješnog upita za učitavanje i verziju.

Windows 95 trenutno nije podržano vrijeme izvođenja.

## Upotreba

- Datoteka > Otvori (Ctrl+O) otvara dijalog datoteke Windows sa višestrukim odabirom. Na Windows Vista i
  novijim verzijama, Otvorite i sačuvajte koristite moderni dijalog Common Item; stariji Windows koriste
  naslijeđe uobičajene dijaloge.
- Prevucite jednu ili više datoteka u prozor, na ikonu EXE datoteke ili njenu prečicu, ili proslijedite
  njihove putanje preko komandne linije. Ako više instanci nije dozvoljeno, datoteke se otvaraju u već
  pokrenutom prozoru.
- Svaka različita normalizirana puna putanja ima jednu karticu. Ponovnim otvaranjem već otvorene datoteke
  odabire se njena postojeća kartica bez ponovnog učitavanja ili promjene izvještaja, odabira ili položaja
  pomicanja. Poređenja zanemaruju velika i mala slova putanje. Otvaranja više datoteka obrađuju listu po redu
  i ostavljaju posljednju uspješno obrađenu datoteku aktivnom, bilo da je novootvorena ili već otvorena.
  Prelazak miša iznad zaglavlja kartice prikazuje punu putanju datoteke u izvornom opisu alata, uključujući i
  kada se prikazano ime datoteke skraćuje.
- Meni Datoteka navodi osam nedavno učitanih datoteka direktno iznad Exit-a, između separatora. Unosi
  prikazuju samo broj i naziv datoteke. Odabir unosa otvara njegovu pohranjenu punu putanju ili odabire
  postojeću karticu; uspješno ponovno otvaranje pomiče ga na vrh bez duplikata. Odabirom nedostupne datoteke
  postavlja se pitanje da li da se ukloni njen unos nedavnih datoteka. Koriste se izvorna ikona pitanja i
  Yes/No dugmad. Da je podrazumevano i uklanja unos iz menija i registra; Ne zadržava ga. Prompt uključuje
  punu putanju.
- Točkić miša koji preplavljuje zaglavlja kartica skroluje traku zaglavlja jednu karticu po poruci bez
  promjene odabira ili fokusa.
- Ctrl+Tab i Ctrl+Shift+Tab menjaju kartice; Ctrl+W zatvara aktivnu karticu. Srednjim klikom na zaglavlje
  kartice zatvara se ta kartica uz očuvanje bilo koje druge aktivne kartice. Datoteka > Zatvori sve zatvara
  sve kartice, uključujući izvještaje u redu čekanja. Datoteka > Izlaz (Alt+F4) zatvara aplikaciju.
- Dvostruki klik odabire riječ. Trostruki klik odabire logičku liniju. Prevlačenjem se proširuje izbor
  riječima ili linijama.
- Ctrl+A bira izvještaj; Ctrl+C kopira.
- Uređivanje > Pronađi (Ctrl+F) pretražuje aktivnu karticu. F3 ponavlja pretragu, a Shift+F3 mijenja njen
  smjer. Na kraju teksta pretraga se nastavlja s drugog kraja. Opcije > Prelamanje redova važi samo za aktivnu
  karticu; oznaka prati odabranu karticu. Prozor pretrage može se minimizirati i mijenjati mu se širina;
  položaj i opcija Uvijek na vrhu se pamte. Do 30 tekstova pretrage s njihovim opcijama čuva se samo do
  zatvaranja aplikacije. Opcije početka i kraja odnose se na logičke redove. Regularni izrazi koriste PCRE2
  sintaksu. Sve komande menija Uređivanje odnose se samo na aktivnu karticu. Enter pokreće pretragu, a
  Shift+Enter obrće odabrani smjer. „Razlikuj velika i mala slova“ razlikuje velika i mala slova; „Traži
  unazad“ traži prema početku teksta. Izbor stavke historije vraća svih pet opcija pretrage, uključujući
  stanje režima regularnih izraza; „Uvijek na vrhu“ je nezavisna opcija. „Regularni izraz“ onemogućava „Red
  počinje sa“ i „Red završava sa“. Kada su uključene obje opcije krajeva reda, dovoljno je poklapanje na
  jednom kraju. „Prelamanje redova“ mijenja samo prikaz.
- Opcije > Preference (Ctrl+G) otvara jedan dijalog postavki za MediaInfo i curl putanje, font izvještaja,
  antialiasing fonta, jezik interfejsa i jezik izvještaja. Prazna staza DLL omogućava automatsko otkrivanje.
- Dugme fonta prikazuje porodicu, veličinu tačke i stil i otvara standardni dijalog Windows fonta. Zadano
  vraća Consolas, ili Courier New ako Consolas nije dostupan; dugme Podrazumevano je onemogućeno dok je
  izabrano podrazumevano. Fontovi koje odabere korisnik zadržavaju se bez zamjene kodom aplikacije.
- Izbor antialiasinga fonta su ClearType kada je podržano, GDI i Ništa. Početni izbor je ClearType kada je
  podržan, u suprotnom GDI. Postavke fonta utiču samo na medijske izvještaje i njihove izvoze slika.
- Datoteka > Izvoz (Ctrl+E) otvara dijalog Windows Sačuvaj kao i izvozi cijeli aktivni izvještaj u TXT, BMP,
  GIF, JPEG, PNG, TIFF ili WebP, uključujući tekst izvan vidljivog područja.
- Pomoć otvara poseban prozor bez režima sa sopstvenim unosom na traci zadataka i dugmetom za minimiziranje.
  About je modalni dijalog; njegovo zaglavlje proizvoda navodi sve tri ugrađene DLL verzije.

Štampaj… (Ctrl+P) otvara sistemski dijalog za izbor štampača i štampa cijelu aktivnu karticu bez pregleda.
Koristi se font izvještaja; dugi redovi se prelamaju, a tekst dijeli na stranice. Štampanje se odvija u
pozadini.

Otvori fasciklu… otvara datoteke koje su neposredno u izabranoj fascikli, svaku na zasebnoj kartici.
Podfascikle nisu uključene. Otvori i Otvori fasciklu dijele posljednju izabranu fasciklu. Izvoz pamti zasebnu
fasciklu, zadano Dokumenti.

Napredni način rada prikazuje dodatna polja izvještaja.

Potpuna analiza ispituje cijelu datoteku i može potrajati duže. Ove opcije izvještaja i Nivo praćenja
pripadaju svakoj kartici; promjena osvježava samo aktivnu karticu. Posljednja ručno odabrana kombinacija se
čuva za nove kartice i sljedeće pokretanje. Odgovarajući keširani izvještaj se ponovo koristi dok datoteka
ostaje nepromijenjena.

Poznati formati, Poznati kodeci i Poznati parametri otvaraju se u vlastitim karticama izvještaja.

Početnu veličinu prozora i lokaciju bira Windows. Prethodno sačuvani položaj prozora poništava te zadane
postavke pri kasnijim pokretanjima.

Lijeva strana statusne trake prikazuje putanje datoteka i tok učitavanja, a desna verziju učitane
MediaInfo.dll biblioteke. Duge putanje skraćuju se trotačkom prema dostupnom prostoru.

## Napravi datoteku zaglavlja

Meni Alati je četvrti na traci menija. Njegova komanda Napravi datoteku zaglavlja… otvara jednu izvornu
datoteku nezavisno od kartica izvještaja i kopira njenih prvih 524288 bajtova (512 KiB). Kraća datoteka se
kopira u potpunosti; prazna datoteka proizvodi prazan izlaz. Ovo je obično čitanje binarnih datoteka, bez
MediaInfo analize ili zahtjeva za MediaInfo.dll. Alat ostavlja kartice izvještaja i listu nedavnih datoteka
programa nepromijenjene.

Nakon čitanja, dijalog Sačuvaj kao počinje u fascikli izvorne datoteke i predlaže video.mp4.header za
video.mp4: .header se dodaje kompletnom originalnom imenu. Možete promijeniti i naziv i odredišnu fasciklu.
Otkazivanje bilo kojeg dijaloga ne upisuje izlaz. Zamjena postojećeg odredišta zahtijeva potvrdu. Izvor ostaje
nepromijenjen; neuspješno čuvanje čuva prethodnu destinaciju. Otvaranje i čuvanje koriste najnovije sistemske
dijaloge dostupne u toj verziji Windowsa.

Prilikom pokretanja aplikacije, alat preuzima svoj početnu ulaznu fasciklu iz Datoteka > Otvori. Ako nijedna
fascikla nije sačuvan, Windows bira početnu lokaciju. Nakon odabira ulazne datoteke, alat pamti svoju fasciklu
samo dok se aplikacija ne zatvori, čak i ako je Sačuvaj kao otkazano. Ne mijenja fascikle koje koriste Otvori
i Izvezi niti čuva svoju fasciklu u postavkama aplikacije. Svaki dijalog Sačuvaj kao počinje u fascikli
trenutno odabrane ulazne datoteke, bez obzira na prethodno odredište za čuvanje.

## Pronalaženje biblioteka

Prvo se pokušava sačuvati ručni put. Ako se ne može učitati, automatsko otkrivanje pokušava:

1. MediaInfo.dll pored izvršne datoteke, zatim u svakom roditeljskom direktoriju do pogona ili UNC dijeljenog
   korijena.
2. ProgramFiles, ProgramFiles(x86) i ProgramW6432.
3. LOCALAPPDATA i APPDATA.

Pod ovim korijenima instalacije, otkrivanje provjerava MediaInfo, MediaArea\MediaInfo, MediaArea,
MediaArea.net\MediaInfo, Programs\MediaInfo, Programs\MediaArea\MediaInfo. Nečitke lokacije i nekompatibilni
DLLs se preskaču. Ne skenira disk rekurzivno.

Ako nije pronađen nijedan kompatibilan eksterni DLL, pregledač pokušava ugrađene verzije ovim redoslijedom:
26.10, 21.03, 0.7.60. Ekstrahira i testira jednu po jednu verziju. Jednom kada se verzija uspješno učita,
starije verzije se ne izdvajaju niti testiraju. Dovoljna je samo distribucija MediaInfo.exe; kompatibilni
eksterni DLL uvijek ima prioritet i može se ažurirati nezavisno.

Neuspješna ručna promjena biblioteke zadržava biblioteku koja je već bila učitana.

## Izvoz izvještaja

Formati Sačuvaj kao su poređani TXT, BMP, GIF, JPEG, PNG, TIFF i WebP. Nepodržani koderi su izostavljeni iz
modernih i starih dijaloga.

TXT nudi ANSI, UTF-8, UTF-8 s BOM-om, UTF-16 BE s BOM-om i UTF-16 LE s BOM-om. Podrazumijevana je druga
stavka, UTF-8 bez BOM-a. Čuvaju se cijeli tekst izvještaja i izvorni završeci redova.

BMP, PNG i TIFF čuvaju sve prikazane boje; GIF89a čuva tačno prikazanu paletu kada slika ima najviše 256 boja.
Izvoz uvijek upisuje odabrani format ili prijavljuje grešku; nikada ne zamjenjuje drugi format.

Slike sadrže cijeli izvještaj u odabranom fontu izvještaja, s crnim tekstom na bijeloj pozadini. Ne sadrže
meni aplikacije, zaglavlja kartica, statusnu traku, izbor ili kursor. Renderiranje je nezavisno od položaja
pomicanja tekstualnog okvira.

Kako bi se izbjeglo tiho skraćivanje izvještaja ili iscrpljivanje adresnog prostora na starijim računarima,
jedna slika je ograničena na 16.384 piksela širine, 32.767 visine piksela i 256 MiB nekomprimirane bitmap
memorije. Odaberite manji font ako izvještaj prelazi ta ograničenja.

`Google WebP (*.webp)` je posljednji format i čuva izvještaj bez gubitaka.

WebP: 16383 × 16383 px.

## Jezici interfejsa i izvještaja

Postavke (Opcije > Postavke, Ctrl+G) sadrže putanje biblioteka, font izvještaja, izglađivanje i jezike.
Sučelje ima 36 varijanti i početno prati Windows. Izvještaji uvijek podrazumijevano koriste izvorni engleski
biblioteke, nezavisno od Windowsa i sučelja. To mijenja samo ručni izbor jezika: engleski, 37 prijevoda ili
vlastita MediaInfo CSV tabela.

U redu ili Primijeni potvrđuje promjene; Otkaži odbacuje nepotvrđene promjene. Postavke određuju granicu
naziva kartice (podrazumijevano 80) i brišu listu nedavnih datoteka. Dugi nazivi zadržavaju početak, kraj i
nastavak s trotačkom u sredini.

Podrazumijevano je dozvoljena samo jedna instanca, a naredna pokretanja šalju datoteke otvorenom prozoru. U
postavkama se može dozvoliti više instanci. Kada postoji više prozora, samo prvi prozor svakog obrasca vraća
sačuvani položaj; ostali vraćaju samo veličinu.

Promjenom samo interfejsa tekst otvorenih izvještaja ostaje nepromijenjen. Ručno primijenjena promjena jezika
izvještaja ponovo učitava njihove izvještaje uz očuvanje redoslijeda kartica i MRU reda.

## libcurl

Automatske provjere otkrivanja curl pored odabranih MediaInfo DLL, zatim zajedničkih executable/ancestor,
programskih datoteka i lokacija za instalaciju korisnika. Ako nije pronađen kompatibilan eksterni curl,
odgovarajuća ugrađena trenutna ili XP verzija se izdvaja u provjerenu keš memoriju po korisniku. Najstariji
MediaInfo 0.7.60 u potpunosti zaobilazi curl otkrivanje, ekstrakciju i učitavanje. Eksplicitno odabran
nevažeći curl odbija promjenu preferencije; nedostatak opcionog automatskog curl ne sprečava obične izveštaje
o lokalnim datotekama.

## Nazivi datoteka i lista nedavnih datoteka

MRU imena datoteka se skraćuju samo ako su duža od 80 UTF-16 kodnih jedinica. Srednja elipsa čuva početak,
kraj imena datoteke prije njegove ekstenzije i kompletnu konačnu ekstenziju; puni putevi i izvještaji ostaju
nepromijenjeni. Naslovi kartica koriste isti algoritam sa podesivim zadanim ograničenjem od 80.

Nedavni fajlovi > Obriši odmah briše i živi MRU meni i njegove sačuvane putanje, a sve otvorene kartice
ostavlja netaknute. Ne primjenjuje niti potvrđuje željene postavke i ne omogućava Primijeni. Cancel or Escape
čuva izbrisanu historiju dok odbacuje izmjene na čekanju. Brisanje je onemogućeno kad god je lista prazna, a
njegovo stanje se osvježava kada novi izvještaji popune listu. Odmah se prijavljuje greška u pisanju registra.
Primjena novog ograničenja naziva kartice ažurira svaku otvorenu karticu bez ponovnog učitavanja medijskog
izvještaja.

## Licenciranje i redistribucija

Pregledač je licenciran pod MIT licencom u license.txt.

MediaInfo je komponenta treće strane. Jedino obavještenje o održavanoj distribuciji je root license.txt,
kodirano kao UTF-8 sa CRLF i uključuje preglednik, biblioteke, statički ugrađene komponente, ikone i zvanične
tablice prijevoda.

Ovaj proizvod koristi biblioteku MediaInfo, Copyright (c) 2002-2026 MediaArea.net SARL.

- MediaInfo: <https://mediaarea.net/MediaInfo>
- Licenca: <https://mediaarea.net/en/MediaInfo/License>
- Windows preuzimanja: <https://mediaarea.net/en/MediaInfo/Download/Windows>

## Zavisnosti

### Datoteke

| Resurs | Arhitektura | Verzija koju je prijavila komponenta | SHA-256 |
| --- | --- | --- | --- |
| Resources/lib/26.10/MediaInfo.dll | x86 | 26.10 | E73027A1577084135425AA013D46C8B2985AD142CCF04F1ADB301B9A9CFB78F8 |
| Resources/lib/21.03/MediaInfo.dll | x86 | 21.03 | EBBF1C371702F3DC39CA23D619C47EDF97E66A95AEABE725284F1402D8F3E58A |
| Resources/lib/0.7.60/MediaInfo.dll | x86 | 0.7.60 | A26C07BCC25FA01A40E6888D02EABD59AA8DB2ABF6F5195481228D3A91D04441 |
| Resources/lib/26.10/libcurl.dll | x86 | 8.11.0-DEV, Schannel, zlib 1.3.1 | DCF136C84F3A4FBEAE2B317FE36D7F11225B56FBA3343AF4BBA8706B3F46F334 |
| Resources/lib/21.03/libcurl.dll | x86 | 7.47.1, WinSSL, zlib 1.2.8 | 21025CAC8089F1E570EE083D8CFD6311C2C51E97094A9FCD8C7A0B544C22CB48 |
| Resources/lib/libwebp.dll | x86 | 1.1.0 | 9986023BB6FF5510A157919F0CD958A94800EC6A1D981F3403A9648BEDFEE575 |

Putanje u tabeli su relativne u odnosu na direktorij projekta MediaInfo.

Trenutna biblioteka prijavljuje razvojnu verziju; njegov tačan izvor commit ne može se oporaviti iz tog niza
verzije. Njegovo prateće obavještenje koristi gornji 8.11.0 tekst o autorskim pravima i dozvolama, čiji su
uslovi licence također prisutni u razvojnoj seriji.

### Ugrađene komponente

| Komponenta | Dokazi i obim | Napomena |
| --- | --- | --- |
| MediaInfoLib | Stvarne verzije i potrebni Unicode izvozi; nepromijenjene isporučene binarne datoteke | Originalna autorska prava za određenu verziju, uslovi redistribucije i odricanje od odgovornosti |
| ZenLib | Statičke reference projekta i ugrađeni ZenLib RTTI u sva tri DLLs; nisu dostavljene tačne povezane revizije | Obavijest u zlib stilu ZenLib |
| zlib | Ugrađeni nizovi verzije inflate/deflate: 1.3.2 u MediaInfo 26.10, 1.2.11 u 21.03, 1.2.7 u 0.7.60; curl dodatno prijavljuje 1.3.1 i 1.2.8 | Originalna zlib obavještenja za svih pet verzija |
| TinyXML-2 | Usklađivanje modernih izvornih ciljeva i binarnog RTTI; uključeno u naslijeđeni projekt, ali nije nezavisno identificirano u lišenoj naslijeđenoj binarnoj verziji | Originalna napomena u stilu Lee Thomason zlib je zadržana |
| Brian Gladman AES | Uključeno u oba cilja moderne biblioteke uzvodno, s odgovarajućim dopuštenim izvornim obavijestima | 1998–2013 obavještenje o redistribuciji i odricanje od odgovornosti |
| Brian Gladman SHA-1/SHA-2 | Obe moderne mete; SHA-256 i SHA-512 konstantne tablice prisutne u obje moderne binarne datoteke | 1998–2010 obavještenje o redistribuciji i odricanje od odgovornosti |
| Brian Gladman HMAC | I moderne mete i njihov curl/S3 kod za čitanje | Originalno obaveštenje o tri uslova, uključujući njegov paragraf o alternativnoj licenci |
| MD5 | Moderni izvorni ciljevi; Colin Plumb implementacija eksplicitno navodi javno vlasništvo | Atribucija je zadržana |
| Base64 | Markus Ewald zaglavlje u sva tri odgovarajuća stabla izvora, pripisuje Bob Withers | Originalna atribucija autorstva zadržana; kvalifikacija ispod |
| fmt | 26.10 cilj i fmt v11 format_error RTTI u binarnom | Originalno MIT obavještenje, uključujući neobavezni izuzetak |
| tfsxml | 26.10 izvorni cilj | Originalno MediaArea MIT obavještenje |
| Android JNI interfejs | JNI_OnLoad zapravo izvoze oba moderna DLLs; uključeno JNI zaglavlje je iz AOSP | AOSP autorska prava i kompletna Apache licenca 2.0 |
| libcurl | Isporučene x86 binarne datoteke; stvarni izvoz verzija; dinamički koristi moderni MediaInfo | Originalna curl obavještenja za 8.11.0 i 7.47.1 |
| Zvanični prevodi izvještaja | Svi 38 neizmijenjeni CSV izvori iz MediaInfo v26.10 jezičkog direktorija; 37 tabele koje nisu na engleskom su ugrađene, dok engleski koristi DLL zadane postavke | Obavještenje o istom projektu BSD-2-Clause zadržano u kombinovanom obavještenju |
| MediaInfo ikona | Nepromijenjena zvanična ikona sa više slika, revizija izvora f057dd3649bc8692a83863b67770e22c9b9dd81a | Originalno BSD-2-Clause obavještenje i atribucija |
| libwebp | WebPEncodeLosslessBGRA, WebPFree; 1.1.0; x86 | BSD-3-Clause; PATENTS |

Podudarni izvorni ciljevi uspostavljaju uključivanje u te konfiguracije uzvodne izgradnje; oni ne dokazuju da
svaka funkcija preživljava optimizaciju u binarnim datotekama dobavljača. Za ovisnosti čija revizija nije
zabilježena u tim binarnim datotekama ne postoji zahtjev za točnu verziju.

### Opcione komponente i sistemske biblioteke

- Bibliotečki projekti Windows omogućavaju libcurl učitano tokom izvođenja za MediaInfo 26.10 i 21.03.
  MediaInfo 0.7.60 je izgrađen sa MEDIAINFO_LIBCURL_NO; njegova binarna datoteka također sadrži dijagnostiku
  podrške za onesposobljene. Pregledač nikada ne otkriva, izdvaja ili učitava curl za tu verziju u paketu.
- libmms je onemogućen u sva tri isporučena Windows DLLs, što potvrđuju njihove ugrađene poruke podrške za
  onesposobljene. Ne distribuira se.
- Qt i wxWidgets pripadaju opcionim GUI buildovima. Nijedno nije uključeno u ovaj preglednik ili u ove DLL
  zavisnosti. Njihovi generički unosi su uklonjeni iz prikazane licence.
- Graphviz je opciona zakačiva za vrijeme izvođenja u modernom uzvodnom kodu. Nema Graphviz DLL se
  redistribuira.
- Nijedan FFmpeg dodatak nije redistribuiran.
- MediaInfo DLLs direktno uvozi samo KERNEL32.dll. To ne znači da njihov statički povezan runtime i pomoćni
  kod nedostaju.
- Trenutni curl direktno uvozi WS2_32.dll, bcrypt.dll, ADVAPI32.dll, CRYPT32.dll i KERNEL32.dll. XP curl
  direktno uvozi WS2_32.dll, WLDAP32.dll, ADVAPI32.dll i KERNEL32.dll. Ovo su Windows komponente. Njihovu
  dostupnost provjerava Windows loader.
- Curl prijavljuje Windows Schannel/WinSSL, a ne OpenSSL build. Njegova prijavljena dodatna ovisnost o
  kompresiji je statički uključena zlib. Nema dodatnih eksternih ne-Windows DLL u njegovoj tabeli direktnog
  uvoza.
- Sam preglednik nema C/C++ ovisnost o vremenu izvođenja. Isporučeni DLLs treće strane sadrže njihove vlastite
  kompajlirane dijelove vremena izvođenja. Windows verzije koriste Microsoft alate; nema dokaza koji
  zahtijevaju generičke libstdc++ ili libc++ unose inventara.
- JPEG koristi dinamički učitani sistem GDI+. Paker resursa C# i PowerShell su alati za izgradnju i nisu
  ovisnosti o vremenu izvođenja.

Uobičajena inspekcija lokalnih datoteka ne zahtijeva MediaArea server ili bazu podataka formata preuzetu na
daljinu. libcurl koristi MediaInfo za URL ulaze i potencijalno udaljene reference u podržanim medijskim
formatima. Spajanjem ne dodaje se posebna URL naredba za otvaranje ovom pregledniku.

### Čuvanje licenci i ograničenja

Jedina održavana obavijest o distribuciji je [license.txt](../license.txt) , kodirana kao UTF-8 sa CRLF.
Provjerene klauzule o redistribuciji BSD, curl, zlib, MIT i Apache ne zahtijevaju posebnu datoteku obavijesti
fizički pored svake DLL; kombinovano obaveštenje ih prati u izvršnom i distribucionom materijalu.

Arhivirani MediaInfo 0.7.60 paket koristi vlastitu licencu specifičnu za verziju i uključuje stari GNU Library
GPL tekst. Njegovi uslovi izričito razlikuju nemodifikovanu binarnu redistribuciju od modifikovanih verzija;
dinamičko povezivanje od strane ovog preglednika ne mijenja isporučeni DLL. Njegovi originalni uslovi i
prateći tekst licence se zadržavaju. Gledalac ostaje MIT-licenciran.

Za jednu uzvodnu atribuciju potrebna je kvalifikacija: zaglavlje Markus Ewald Base64 nema eksplicitnu dozvolu
ili izjavu o licenci. MediaArea opisuje implementaciju Bob Withers Base64 kao javnu domenu u svojoj povezanoj
MediaConch dokumentaciji, ali to ne utvrđuje nezavisno dodjelu licence za svaku Ewaldovu promjenu. Za to
zaglavlje nije izmišljena licenca. Potpuna potvrda dobavljača te provenijencije, tačne ZenLib revizije i curl
razvoj commit nije bila dostupna u isporučenim binarnim datotekama. Ove tačke sprečavaju tretiranje ovog
inventara kao kompletnog, nezavisno certificiranog SBOM.

### Primarni izvori

- [MediaInfo uslovi redistribucije](https://mediaarea.net/en/MediaInfo/License)
- 
  [MediaInfo 26.10 cilj biblioteke](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Project/MSVC2022/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 21.03 cilj biblioteke](https://github.com/MediaArea/MediaInfoLib/blob/v21.03/Project/MSVC2015/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 0.7.60 cilj biblioteke](https://github.com/MediaArea/MediaInfoLib/blob/v0.7.60/Project/MSVC2005/Library/MediaInfoLib.vcproj)
- 
  [Runtime curl loader](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Source/MediaInfo/Reader/Reader_libcurl.cpp)
- 
  [Ukupni izvori pomoćnika i njihove obavijesti](https://github.com/MediaArea/MediaInfoLib/tree/v26.10/Source/ThirdParty)
- [ZenLib obavijest](https://github.com/MediaArea/ZenLib/blob/master/License.txt)
- [zlib izvorne obavijesti](https://github.com/madler/zlib/blob/v1.3.2/zlib.h)
- [curl 8.11.0 obavijest](https://github.com/curl/curl/blob/curl-8_11_0/COPYING)
- [curl 7.47.1 obavijest](https://github.com/curl/curl/blob/curl-7_47_1/COPYING)
- [Apache licenca 2.0](https://www.apache.org/licenses/LICENSE-2.0)
- [MediaArea Base64 opis](https://github.com/MediaArea/MediaConch/blob/master/README.md)

Tabele izvještaja dolaze iz
<https://github.com/MediaArea/MediaInfo/tree/v26.10/Source/Resource/Plugin/Language> . Odgovarajući projekat
LICENSE je <https://github.com/MediaArea/MediaInfo/blob/v26.10/LICENSE> .

- [libwebp 1.1.0 COPYING](https://github.com/webmproject/libwebp/blob/v1.1.0/COPYING)
- [libwebp 1.1.0 PATENTS](https://github.com/webmproject/libwebp/blob/v1.1.0/PATENTS)
