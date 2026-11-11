# MediaInfo Viewer

[Čeština](README.cs-CZ.md) | [English (US)](../README.md) | [English (UK)](README.en-GB.md) | [English (Australia)](README.en-AU.md) | [Deutsch](README.de-DE.md) | [Français](README.fr-FR.md) | [Español](README.es-ES.md) | [Italiano](README.it-IT.md) | [Português](README.pt-PT.md) | [Polski](README.pl-PL.md) | [Slovenčina](README.sk-SK.md) | [Dansk](README.da-DK.md) | [Suomi](README.fi-FI.md) | [Íslenska](README.is-IS.md) | [Norsk (bokmål)](README.nb-NO.md) | [Svenska](README.sv-SE.md) | [Türkçe](README.tr-TR.md) | [Eesti](README.et-EE.md) | [Gaeilge](README.ga-IE.md) | [Lietuvių](README.lt-LT.md) | [Latviešu](README.lv-LV.md) | [Magyar](README.hu-HU.md) | [Malti](README.mt-MT.md) | [Nederlands](README.nl-NL.md) | **Română** | [Ελληνικά](README.el-GR.md) | [Bosanski](README.bs-Latn-BA.md) | [Hrvatski](README.hr-HR.md) | [Slovenščina](README.sl-SI.md) | [Crnogorski](README.cnr-Latn-ME.md) | [Беларуская](README.be-BY.md) | [Български](README.bg-BG.md) | [Македонски](README.mk-MK.md) | [Српски](README.sr-Cyrl-RS.md) | [Українська](README.uk-UA.md) | [Русский](README.ru-RU.md)

Vizualizator nativ Windows x86 pentru rapoarte MediaInfo.dll. Fiecare fișier are propria filă doar pentru
citire.

[Compilare și compatibilitate](#compilare) | [Auditul dependențelor](#dependențe) | [Licență](../license.txt)

## Compilare

Deschideți MediaInfo.sln în Visual Studio 2015 cu setul de instrumente Visual C++ v140 instalat. Alegeți Release | Win32 și construiți soluția. Singura platformă de aplicație este Win32 (x86).

[PCRE2 10.49](https://github.com/PCRE2Project/pcre2/tree/pcre2-10.49) — UTF-16, legat static, BSD-3-Clause.
[license.txt](../license.txt). [Cod sursă](../MediaInfo/PCRE2/).
PCRE2 este inclusă în executabil și nu necesită un DLL separat sau o instalare suplimentară.

Ieșiri:

- Release\MediaInfo.exe
- Debug\MediaInfo.exe

Vizualizatorul nu conectează runtime-ul C sau C++ și nu are nevoie de un MSVC redistribuibil. MediaInfo.dll
selectat poate avea propriile sale dependențe.

Construirea necesită Windows PowerShell și .NET Framework. Acestea sunt doar cerințe de construcție;
executabilul nativ nu necesită nici PowerShell nici .NET.

### Pachet de distribuție

După construirea Release, rulați
`powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\PackageRelease.ps1` . Scriptul creează
`MediaInfo-<version>-win32.zip` în directorul soluției, folosind versiunea fișierului executabil în patru
părți. Arhiva conține `MediaInfo.exe` și `license.txt` combinate direct la rădăcină.

## Compatibilitate

Vizualizatorul Win32 este conceput pentru a utiliza Windows NT 4.0 APIs.

Executabilul include trei biblioteci x86 MediaInfo: 26.10 pentru Windows curent, 21.03 din pachetul Windows XP
și 0.7.60 din pachetul Windows 95–2000. Arhitectura unei biblioteci singură nu determină compatibilitatea sa
cu sistemul de operare. Vizualizatorul încearcă bibliotecile grupate de la cea mai nouă la cea mai veche și se
oprește după prima interogare de încărcare și versiune cu succes.

Windows 95 nu este în prezent un timp de rulare acceptat.

## Utilizare

- Fișier > Deschidere (Ctrl+O) deschide dialogul fișierului Windows cu selecție multiplă. Pe Windows Vista și
  mai târziu, Deschidere și Salvare utilizează Dialogul Element comun modern; mai vechi Windows folosesc
  dialogurile comune vechi.
- Glisați unul sau mai multe fișiere în fereastră, pe pictograma EXE sau pe comanda sa rapidă, ori transmiteți
  căile în linia de comandă. Dacă nu sunt permise mai multe instanțe, fișierele se deschid în fereastra care
  rulează deja.
- Fiecare cale completă normalizată distinctă are o filă. Redeschiderea unui fișier deja deschis selectează
  fila existentă fără a-i reîncărca sau modifica poziția raportului, selecției sau derulării acestuia.
  Comparațiile ignoră literele de cale. Deschiderile cu mai multe fișiere procesează lista în ordine și lasă
  activ ultimul fișier procesat cu succes, indiferent dacă este nou deschis sau deja deschis. Trecând cu
  mouse-ul peste antetul unei file, se afișează calea completă a fișierului într-un sfat explicativ nativ,
  inclusiv atunci când numele fișierului afișat este scurtat.
- Meniul Fișier listează cele mai recent opt fișiere încărcate direct deasupra Ieșire, între separatori.
  Intrările arată doar un număr și un nume de fișier. Selectarea unei intrări deschide calea completă stocată
  sau selectează fila existentă; redeschiderea cu succes o mută în partea de sus fără duplicate. Selectarea
  unui fișier indisponibil vă întreabă dacă să eliminați intrarea de fișiere recente. Sunt folosite pictograma
  întrebare nativă și butoanele Yes/No. Da este implicit și elimină intrarea din meniu și din registru; Nu o
  reține. Promptul include calea completă.
- Rotița mouse-ului deasupra antetelor de filă care depășesc derulează banda de antet o filă per mesaj fără a
  schimba selecția sau focalizarea.
- Ctrl+Tab și Ctrl+Shift+Tab comută filele; Ctrl+W închide fila activă. Făcând clic din mijloc pe un antet de
  filă, se închide acea filă, păstrând orice altă filă activă. Fișier > Închidere totul închide fiecare filă,
  inclusiv rapoartele aflate în coadă. Fișier > Ieșire (Alt+F4) închide aplicația.
- Meniul contextual al antetului unei file include Închide fila. Activați Închide filele prin dublu clic
  în Preferințe pentru a închide o filă prin dublu clic pe antetul ei. Opțiunea este dezactivată
  implicit și se salvează.
- Un dublu clic în textul raportului selectează un cuvânt. Un triplu clic selectează o linie logică.
  Tragerea extinde selecția pe cuvinte sau linii.
- Ctrl+A selectează raportul; Ctrl+C îl copiază.
- Editare > Găsire (Ctrl+F) caută în fila de raport activă sau în zona de text din Ajutor ori Despre, în
  funcție de fereastra care are focalizarea. Fereastra de căutare păstrează ultima sursă selectată cât
  timp are focalizarea. F3 repetă căutarea; Shift+F3 îi inversează direcția. La capătul textului,
  căutarea continuă din celălalt capăt. Opțiuni > Încadrare cuvinte se aplică numai filei active; bifa
  corespunde filei selectate. Fereastra de căutare poate fi minimizată și redimensionată orizontal;
  poziția și opțiunea Întotdeauna deasupra sunt memorate. Până la 30 de texte căutate și opțiunile lor
  sunt păstrate numai până la închiderea aplicației. Opțiunile de început și sfârșit se aplică liniilor
  logice. Expresiile regulate folosesc sintaxa PCRE2. Celelalte comenzi din meniul Editare se aplică
  filei de raport active. Enter pornește căutarea; Shift+Enter inversează direcția aleasă. „Potrivire
  litere mari și mici” deosebește literele mari de cele mici; „Căutare înapoi” caută spre începutul
  textului. Alegerea unei intrări din istoric restabilește toate cele cinci opțiuni de căutare, inclusiv
  starea modului de expresii regulate; „Întotdeauna deasupra” este independentă. „Expresie regulată”
  dezactivează „Linia începe cu” și „Linia se termină cu”. Dacă ambele opțiuni pentru capetele liniei
  sunt active, este suficientă o potrivire la oricare capăt. „Încadrare cuvinte” schimbă numai afișarea.
- Opțiuni > Preferințe (Ctrl+G) deschide un dialog unic de preferințe pentru căile MediaInfo și curl, fontul
  raportului, antialiasing font, limba interfeței și limba raportului. O cale goală DLL permite descoperirea
  automată.
- Butonul pentru font afișează familia, dimensiunea punctului și stilul și deschide dialogul standard pentru
  font Windows. Restabilește implicit Consolas sau Courier New dacă Consolas nu este disponibil; butonul
  Implicit este dezactivat în timp ce este selectat implicit. Fonturile selectate de utilizator sunt păstrate
  fără a fi înlocuite cu codul aplicației.
- Opțiunile de antialiasing pentru font sunt ClearType atunci când sunt acceptate, GDI și Niciunul.
  Alegerea inițială este ClearType când este acceptată, în caz contrar GDI. Setările fontului se aplică
  filelor de rapoarte, exporturilor acestora ca imagini și imprimării rapoartelor. Ajutor și Despre își
  păstrează propriile fonturi de text.
- Ajutor deschide o fereastră separată, fără model, cu propria sa intrare în bara de activități și butonul de
  minimizare. Despre este un dialog modal; antetul produsului său listează toate cele trei versiuni DLL
  încorporate.

Fișier > Configurare pagină… deschide setările pentru hârtie, orientare și margini ale sesiunii curente.
Imprimare… (Ctrl+P) deschide dialogul de imprimare al sistemului; Windows 11 oferă o previzualizare, iar
Windows 10 și versiunile mai vechi păstrează dialogul clasic. Ctrl+P imprimă fila activă din fereastra
principală sau zona de text din Ajutor ori Despre, în funcție de fereastra care are focalizarea.
Rapoartele folosesc fontul de raport ales, Ajutor fontul dialogurilor de sistem, iar Despre fontul
propriei zone de text. Dacă nu sunt file deschise, dar Ajutor este deschis, Configurare pagină… și
Imprimare… rămân disponibile; Imprimare… imprimă Ajutorul. Ajutor folosește dialogul de imprimare al
ferestrei principale; un nou Ctrl+P în Ajutor aduce același dialog în prim-plan. Liniile lungi se
încadrează, iar textul se împarte în pagini. Imprimarea se face în fundal.

Deschide folderul… deschide fișierele aflate direct în folderul selectat, fiecare în propria filă.
Subfolderele nu sunt incluse. Deschide și Deschide folderul folosesc același ultim folder selectat. Exportul
reține un folder separat, implicit Documente.

Modul avansat afișează câmpuri suplimentare în raport.

Analiză completă examinează întregul fișier și poate dura mai mult. Aceste opțiuni de raport și Nivel de
trasare aparțin fiecărei file; o modificare reîmprospătează numai fila activă. Ultima combinație aleasă manual
este salvată pentru noi file și pentru următoarea pornire. Un raport în cache care se potrivește este
reutilizat în timp ce fișierul rămâne neschimbat.

Formate cunoscute, Codecuri cunoscute și Parametri cunoscuți se deschid în propriile file de raport.

Dimensiunea și locația inițială a ferestrei sunt selectate de Windows. Poziția ferestrelor salvate anterior
înlocuiește aceste valori implicite la lansările ulterioare.

Partea stângă a barei de stare afișează căile fișierelor și progresul încărcării, iar partea dreaptă afișează
versiunea MediaInfo.dll încărcată. Căile lungi sunt prescurtate cu puncte de suspensie în funcție de spațiul
disponibil.

## Creează un fișier antet

Meniul Instrumente este al patrulea din bara de meniu. Comanda sa Creează un fișier antet… deschide un fișier
sursă independent de filele de raport și îi copiază primii 524288 de octeți (512 KiB). Un fișier mai scurt
este copiat integral; un fișier gol produce o ieșire goală. Aceasta este o citire binară obișnuită a unui
fișier, fără analiză MediaInfo sau o cerință pentru MediaInfo.dll. Instrumentul lasă neschimbate filele de
raport și lista de fișiere recente a vizualizatorului.

După citire, dialogul Salvare ca începe în folderul fișierului sursă și sugerează video.mp4.header pentru
video.mp4: .header este atașat la numele original complet. Puteți schimba atât numele, cât și folderul de
destinație. Anularea fiecărei casete de dialog nu va scrie nicio ieșire. Înlocuirea unei destinații existente
necesită confirmare. Sursa rămâne neschimbată; o salvare eșuată păstrează destinația anterioară. Pentru
deschidere și salvare sunt folosite cele mai moderne casete de dialog de sistem disponibile în versiunea
respectivă de Windows.

La pornirea aplicației, instrumentul își ia folderul de intrare inițial din Fișier > Deschide. Dacă nu a fost
salvat niciun folder, Windows alege locația inițială. După ce este selectat un fișier de intrare, instrumentul
își amintește propriul folder numai până când aplicația iese, chiar dacă Salvare ca este anulată. Nu modifică
folderele folosite de Deschide și Exportă și nici nu își salvează propriul folder în setările aplicației.
Fiecare dialog Salvare ca începe în folderul fișierului de intrare selectat curent, indiferent de destinația
anterioară de salvare.

## Căutarea bibliotecilor

Se încearcă mai întâi o cale manuală salvată. Dacă nu poate fi încărcat, descoperirea automată încearcă:

1. MediaInfo.dll lângă executabil, apoi în fiecare director părinte până la unitate sau rădăcină partajată
   UNC.
2. ProgramFiles, ProgramFiles(x86) și ProgramW6432.
3. LOCALAPPDATA și APPDATA.

Sub aceste rădăcini de instalare, descoperirea verifică MediaInfo, MediaArea\MediaInfo, MediaArea,
MediaArea.net\MediaInfo, Programs\MediaInfo, Programs\MediaArea\MediaInfo. Locațiile care nu pot fi citite și
DLLs incompatibile sunt omise. Nu scanează recursiv discul.

Dacă nu se găsește niciun DLL extern compatibil, vizualizatorul încearcă versiunile încorporate în această
ordine: 26.10, 21.03, 0.7.60. Extrage și testează câte o versiune la un moment dat. Odată ce o versiune se
încarcă cu succes, versiunile mai vechi nu sunt nici extrase, nici testate. Numai distribuirea MediaInfo.exe
este suficientă; un DLL extern compatibil are întotdeauna prioritate și poate fi actualizat independent.

O modificare manuală eșuată a bibliotecii păstrează biblioteca care a fost deja încărcată.

## Exportul raportului

Formatele Salvare ca sunt ordonate TXT, BMP, GIF, JPEG, PNG, TIFF și WebP. Codificatoarele neacceptate sunt
omise atât din dialogurile moderne, cât și din cele vechi.

TXT oferă ANSI, UTF-8, UTF-8 cu BOM, UTF-16 BE cu BOM și UTF-16 LE cu BOM. A doua opțiune, UTF-8 fără BOM,
este cea implicită. Se păstrează întregul text al raportului și sfârșiturile de linie originale.

BMP, PNG și TIFF păstrează toate culorile redate; GIF89a păstrează paleta redată exactă atunci când imaginea
are cel mult 256 culori. Export scrie întotdeauna formatul selectat sau raportează o eroare; nu înlocuiește
niciodată un alt format.

## Limbi de interfață și rapoarte

Preferințele (Opțiuni > Preferințe, Ctrl+G) conțin căile bibliotecilor, fontul raportului, netezirea și
limbile. Interfața are 36 de variante și urmează inițial Windows. Rapoartele folosesc întotdeauna implicit
engleza originală a bibliotecii, independent de Windows și interfață. Doar o alegere manuală schimbă limba:
engleză, 37 de traduceri sau un tabel CSV MediaInfo propriu.

OK sau Se aplică confirmă modificările; Anulare le abandonează pe cele în așteptare. Preferințele stabilesc
limita numelor filelor (implicit 80) și șterg lista fișierelor recente. Numele lungi păstrează începutul,
sfârșitul și extensia, cu puncte de suspensie la mijloc.

Titlul ferestrei principale afișează fișierul activ în forma nume fișier — MediaInfo. Preferințele permit
setarea separată a lungimii numelui din titlu între 8 și 255 de caractere (implicit 40). Numele mai lungi
sunt scurtate cu aceleași puncte de suspensie la mijloc, păstrând extensia. Fără file deschise, titlul
este MediaInfo.

În mod implicit este permisă o singură instanță, iar pornirile ulterioare trimit fișierele la fereastra
deschisă. Preferințele permit activarea mai multor instanțe. Cu mai multe ferestre, doar prima fereastră a
fiecărui formular restabilește poziția salvată; celelalte restabilesc doar dimensiunea.

Schimbarea numai a interfeței lasă textul rapoartelor deschise neschimbat. O modificare a limbii raportului
aplicată manual le reîncarcă rapoartele, păstrând ordinea filelor și ordinea MRU.

## libcurl

Verificări automate de descoperire curl lângă MediaInfo DLL selectate, apoi executable/ancestor partajate,
fișierele program și locațiile de instalare ale utilizatorului. Dacă nu se găsește niciun curl extern
compatibil, versiunea curentă sau XP încorporată corespunzătoare este extrasă în memoria cache verificată per
utilizator. Cel mai vechi MediaInfo 0.7.60 ocolește în întregime descoperirea, extragerea și încărcarea curl.
Un curl invalid selectat în mod explicit respinge modificarea preferințelor; lipsa opțională automată curl nu
împiedică rapoartele obișnuite ale fișierelor locale.

## Nume de fișiere și fișiere recente

Numele fișierelor MRU sunt scurtate numai atunci când sunt mai mari decât unitățile de cod 80 UTF-16. O elipsă
din mijloc păstrează începutul, sfârșitul numelui fișierului înainte de extensia sa și extensia finală
completă; căile și rapoartele complete rămân neschimbate. Subtitrările filelor folosesc același algoritm cu o
limită prestabilită configurabilă de 80.

Fișiere recente > Ștergeți șterge imediat atât meniul MRU live, cât și căile salvate, lăsând intacte toate
filele deschise. Nu aplică sau validează preferințele în așteptare și nu activează Aplicare. Anulare sau
Escape păstrează istoricul șters în timp ce elimină editările în așteptare. Ștergerea este dezactivată ori de
câte ori lista este goală, iar starea acesteia este reîmprospătată când noi rapoarte populează lista. Un eșec
de scriere în registry este raportat imediat. Aplicarea unei noi limite de nume de filă actualizează fiecare
filă deschisă fără a reîncărca raportul său media.

## Licență și redistribuire

Vizionatorul este licențiat sub Licența MIT în license.txt.

MediaInfo este o componentă terță parte. Singura notificare de distribuție menținută este rădăcina
license.txt, codificată ca UTF-8 cu CRLF și care include vizualizatorul, bibliotecile, componentele
încorporate static, pictograma și tabelele oficiale de traducere.

Acest produs folosește biblioteca MediaInfo, Copyright (c) 2002-2026 MediaArea.net SARL.

- MediaInfo: <https://mediaarea.net/MediaInfo>
- Licență: <https://mediaarea.net/en/MediaInfo/License>
- Windows descărcări: <https://mediaarea.net/en/MediaInfo/Download/Windows>

## Dependențe

### Fișiere

| Resursă | Arhitectură | Versiunea raportată de componentă | SHA-256 |
| --- | --- | --- | --- |
| Resources/lib/26.10/MediaInfo.dll | x86 | 26.10 | E73027A1577084135425AA013D46C8B2985AD142CCF04F1ADB301B9A9CFB78F8 |
| Resources/lib/21.03/MediaInfo.dll | x86 | 21.03 | EBBF1C371702F3DC39CA23D619C47EDF97E66A95AEABE725284F1402D8F3E58A |
| Resources/lib/0.7.60/MediaInfo.dll | x86 | 0.7.60 | A26C07BCC25FA01A40E6888D02EABD59AA8DB2ABF6F5195481228D3A91D04441 |
| Resources/lib/26.10/libcurl.dll | x86 | 8.11.0-DEV, Schannel, zlib 1.3.1 | DCF136C84F3A4FBEAE2B317FE36D7F11225B56FBA3343AF4BBA8706B3F46F334 |
| Resources/lib/21.03/libcurl.dll | x86 | 7.47.1, WinSSL, zlib 1.2.8 | 21025CAC8089F1E570EE083D8CFD6311C2C51E97094A9FCD8C7A0B544C22CB48 |
| Resources/lib/libwebp.dll | x86 | 1.1.0 | 9986023BB6FF5510A157919F0CD958A94800EC6A1D981F3403A9648BEDFEE575 |

Căile din tabel sunt relative la directorul proiectului MediaInfo.

Biblioteca actuală raportează o versiune de dezvoltare; sursa sa exactă commit nu poate fi recuperată din acel
șir de versiune. Notificarea de însoțire folosește textul de autorizare și drepturi de autor 8.11.0 din
amonte, ai cărui termeni de licență sunt prezenți și în seria de dezvoltare.

### Componente încorporate

| Componentă | Dovezi și întindere | Observa |
| --- | --- | --- |
| MediaInfoLib | Versiuni reale și exporturi Unicode necesare; binare furnizate neschimbate | Drepturi de autor originale specifice versiunii, condiții de redistribuire și declinare a răspunderii |
| ZenLib | Referințe statice de proiect și ZenLib RTTI încorporate în toate cele trei DLLs; revizuirile legate exact nu sunt furnizate | zlib-stil ZenLib notificare |
| zlib | Șiruri de versiuni inflate/deflate încorporate: 1.3.2 în MediaInfo 26.10, 1.2.11 în 21.03, 1.2.7 în 0.7.60; curl raportează suplimentar 1.3.1 și 1.2.8 | Notificări originale zlib pentru toate cele cinci versiuni |
| TinyXML-2 | Potrivirea țintelor sursă moderne și RTTI binar; incluse în proiectul moștenit, dar nu identificate în mod independent în binarul moștenit eliminat | Anunțul original în stil Lee Thomason zlib păstrat |
| Brian Gladman AES | Inclus în ambele ținte moderne de bibliotecă din amonte, cu notificări de sursă permisive | 1998–2013 notificare de redistribuire și declinare a răspunderii |
| Brian Gladman SHA-1/SHA-2 | Ambele tinte moderne; Tabelele constante SHA-256 și SHA-512 prezente în ambele binare moderne | 1998–2010 notificare de redistribuire și declinare a răspunderii |
| Brian Gladman HMAC | Atât țintele moderne, cât și codul lor de citire curl/S3 | Notificarea originală cu trei condiții, inclusiv paragraful său privind licența alternativă |
| MD5 | Ținte sursă moderne; Implementarea Colin Plumb afirmă în mod explicit domeniul public | Atribuirea păstrată |
| Base64 | Antetul Markus Ewald în toți cei trei arbori sursă corespunzători, creditând Bob Withers | Atribuirea originalului de autor păstrată; calificarea de mai jos |
| fmt | 26.10 țintă și fmt v11 format_error RTTI în binar | Notificare originală MIT, inclusiv excepție opțională |
| tfsxml | 26.10 sursă țintă | Aviz original MediaArea MIT |
| Interfață Android JNI | JNI_OnLoad este de fapt exportat atât de DLLs modern; antetul JNI inclus este de la AOSP | AOSP drepturi de autor și licență Apache completă 2.0 |
| libcurl | Binare furnizate x86; exporturi de versiuni reale; folosit dinamic de MediaInfo modern | Notificări originale curl pentru 8.11.0 și 7.47.1 |
| Traduceri oficiale ale rapoartelor | Toate sursele 38 nemodificate CSV din directorul de limbă MediaInfo v26.10; 37 tabelele non-engleze sunt încorporate, în timp ce limba engleză folosește valorile implicite DLL | Același anunț de proiect BSD-2-Clause reținut în notificarea combinată |
| pictograma MediaInfo | Pictogramă oficială nemodificată cu mai multe imagini, versiunea sursă f057dd3649bc8692a83863b67770e22c9b9dd81a | Anunț și atribuire BSD-2-Clause originale |
| libwebp | WebPEncodeLosslessBGRA, WebPFree; 1.1.0; x86 | BSD-3-Clause; PATENTS |

Țintele sursă potrivite stabilesc includerea în acele configurații de construcție din amonte; nu demonstrează
că fiecare funcție supraviețuiește optimizării în binarele furnizorului. Nu se face nicio revendicare exactă a
versiunii pentru dependențele a căror revizuire nu este înregistrată în acele binare.

### Componente opționale și biblioteci de sistem

- Proiectele de bibliotecă Windows permit libcurl încărcat în timp de execuție pentru MediaInfo 26.10 și
  21.03. MediaInfo 0.7.60 a fost construit cu MEDIAINFO_LIBCURL_NO; binarul său conține și diagnosticul de
  asistență pentru dezactivați. Vizionatorul nu descoperă, extrage sau încarcă niciodată curl pentru acea
  versiune în pachet.
- libmms este dezactivat în toate cele trei Windows DLLs furnizate, după cum este confirmat de mesajele de
  asistență dezactivate încorporate. Nu este redistribuit.
- Qt și wxWidgets aparțin versiunilor opționale GUI. Niciunul nu este inclus în acest vizualizator sau în
  aceste dependențe DLL. Intrările lor generice au fost eliminate din licența afișată.
- Graphviz este un cârlig de rulare opțional în codul modern în amonte. Nu Graphviz DLL nu este redistribuit.
- Niciun plugin FFmpeg nu este redistribuit.
- MediaInfo DLLs importă direct numai KERNEL32.dll. Acest lucru nu înseamnă că runtimele lor legate static și
  codul de ajutor sunt absente.
- curl curent importă direct WS2_32.dll, bcrypt.dll, ADVAPI32.dll, CRYPT32.dll și KERNEL32.dll. XP curl
  importă direct WS2_32.dll, WLDAP32.dll, ADVAPI32.dll și KERNEL32.dll. Acestea sunt componente Windows.
  Disponibilitatea lor este verificată de încărcătorul Windows.
- Curl raportează Windows Schannel/WinSSL, nu o build OpenSSL. Dependența suplimentară de compresie raportată
  este inclusă static zlib. Nu apare niciun alt extern non-Windows DLL în tabelul său de import direct.
- Vizualizatorul în sine nu are nicio dependență de rulare C/C++. DLLs terță parte furnizate conțin propriile
  lor porțiuni de rulare compilate. Compilările Windows folosesc instrumente Microsoft; nu există dovezi care
  să solicite intrările de inventar generice libstdc++ sau libc++.
- JPEG utilizează sistemul încărcat dinamic GDI+. C# Resource Packer și PowerShell sunt instrumente de
  compilare și nu sunt dependențe de rulare.

Inspecția obișnuită a fișierelor locale nu necesită un server MediaArea sau o bază de date în format
descărcată de la distanță. libcurl este folosit de MediaInfo pentru intrări URL și referințe potențial la
distanță în formatele media acceptate. Gruparea nu adaugă o comandă separată de deschidere URL la acest
vizualizator.

### Stocarea licenței și limitări

Singura notificare de distribuire menținută este [license.txt](../license.txt) , codificată ca UTF-8 cu CRLF.
Clauzele de redistribuire BSD, curl, zlib, MIT și Apache verificate nu necesită fizic un fișier de notificare
separat lângă fiecare DLL; avizul combinat le însoțește în materialele executabile și de distribuție.

Pachetul arhivat MediaInfo 0.7.60 folosește propria licență specifică versiunii și include vechiul text GNU
Library GPL. Termenii săi disting în mod expres redistribuirea binară nemodificată de versiunile modificate;
legarea dinamică de către acest vizualizator nu modifică DLL furnizat. Condițiile sale originale și textul
licenței însoțitoare sunt păstrate. Vizionatorul rămâne licențiat MIT.

O atribuire în amonte necesită calificare: antetul Markus Ewald Base64 nu are permisiunea explicită sau
declarația de licență. MediaArea descrie implementarea Bob Withers Base64 ca domeniu public în documentația
MediaConch aferentă, dar aceasta nu stabilește în mod independent o acordare de licență pentru fiecare
modificare Ewald. Nu a fost inventat nicio acordare de licență pentru acel antet. O confirmare completă a
furnizorului a acelei proveniențe, revizuirile exacte ZenLib și dezvoltarea curl commit nu a fost disponibilă
în binarele furnizate. Aceste puncte împiedică tratarea acestui inventar ca pe un SBOM complet, certificat
independent.

### Surse primare

- [MediaInfo termeni de redistribuire](https://mediaarea.net/en/MediaInfo/License)
- 
  [MediaInfo 26.10 bibliotecă țintă](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Project/MSVC2022/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 21.03 bibliotecă țintă](https://github.com/MediaArea/MediaInfoLib/blob/v21.03/Project/MSVC2015/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 0.7.60 bibliotecă țintă](https://github.com/MediaArea/MediaInfoLib/blob/v0.7.60/Project/MSVC2005/Library/MediaInfoLib.vcproj)
- 
  [Runtime curl încărcător](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Source/MediaInfo/Reader/Reader_libcurl.cpp)
- 
  [Surse de ajutor grupate și notificările acestora](https://github.com/MediaArea/MediaInfoLib/tree/v26.10/Source/ThirdParty)
- [ZenLib notificare](https://github.com/MediaArea/ZenLib/blob/master/License.txt)
- [zlib notificări sursă](https://github.com/madler/zlib/blob/v1.3.2/zlib.h)
- [curl 8.11.0 notificare](https://github.com/curl/curl/blob/curl-8_11_0/COPYING)
- [curl 7.47.1 notificare](https://github.com/curl/curl/blob/curl-7_47_1/COPYING)
- [Licență Apache 2.0](https://www.apache.org/licenses/LICENSE-2.0)
- [MediaArea Base64 descriere](https://github.com/MediaArea/MediaConch/blob/master/README.md)

Tabelele de raport provin de la
<https://github.com/MediaArea/MediaInfo/tree/v26.10/Source/Resource/Plugin/Language> . Proiectul potrivit
LICENSE este <https://github.com/MediaArea/MediaInfo/blob/v26.10/LICENSE> .

- [libwebp 1.1.0 COPYING](https://github.com/webmproject/libwebp/blob/v1.1.0/COPYING)
- [libwebp 1.1.0 PATENTS](https://github.com/webmproject/libwebp/blob/v1.1.0/PATENTS)
