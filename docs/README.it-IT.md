# MediaInfo Viewer

[Čeština](README.cs-CZ.md) | [English (US)](../README.md) | [English (UK)](README.en-GB.md) | [English (Australia)](README.en-AU.md) | [Deutsch](README.de-DE.md) | [Français](README.fr-FR.md) | [Español](README.es-ES.md) | **Italiano** | [Português](README.pt-PT.md) | [Polski](README.pl-PL.md) | [Slovenčina](README.sk-SK.md) | [Dansk](README.da-DK.md) | [Suomi](README.fi-FI.md) | [Íslenska](README.is-IS.md) | [Norsk (bokmål)](README.nb-NO.md) | [Svenska](README.sv-SE.md) | [Türkçe](README.tr-TR.md) | [Eesti](README.et-EE.md) | [Gaeilge](README.ga-IE.md) | [Lietuvių](README.lt-LT.md) | [Latviešu](README.lv-LV.md) | [Magyar](README.hu-HU.md) | [Malti](README.mt-MT.md) | [Nederlands](README.nl-NL.md) | [Română](README.ro-RO.md) | [Ελληνικά](README.el-GR.md) | [Bosanski](README.bs-Latn-BA.md) | [Hrvatski](README.hr-HR.md) | [Slovenščina](README.sl-SI.md) | [Crnogorski](README.cnr-Latn-ME.md) | [Беларуская](README.be-BY.md) | [Български](README.bg-BG.md) | [Македонски](README.mk-MK.md) | [Српски](README.sr-Cyrl-RS.md) | [Українська](README.uk-UA.md) | [Русский](README.ru-RU.md)

Visualizzatore nativo Windows x86 dei rapporti MediaInfo.dll. Ogni file dispone di una scheda in sola lettura.

[Compilazione e compatibilità](#compilazione) | [Verifica delle dipendenze](#dipendenze) | [Licenza](../license.txt)

## Compilazione

Apri MediaInfo.sln in Visual Studio 2015 con il set di strumenti Visual C++ v140 installato. Scegli Release | Win32 e crea la soluzione. L'unica piattaforma applicativa è Win32 (x86).

[PCRE2 10.49](https://github.com/PCRE2Project/pcre2/tree/pcre2-10.49) — UTF-16, collegamento statico,
BSD-3-Clause. [Codice sorgente](../MediaInfo/PCRE2/).
[license.txt](../license.txt).
PCRE2 è integrata nell’eseguibile e non richiede una DLL separata né un’installazione aggiuntiva.

Uscite:

- Release\MediaInfo.exe
- Debug\MediaInfo.exe

Il visualizzatore non collega il runtime C o C++ e non necessita di un MSVC ridistribuibile. L'MediaInfo.dll
selezionato può avere le proprie dipendenze.

L'edificio richiede Windows PowerShell e .NET Framework. Questi sono solo requisiti di costruzione;
l'eseguibile nativo non richiede né PowerShell né .NET.

### Pacchetto di distribuzione

Dopo aver creato Release, esegui
`powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\PackageRelease.ps1` . Lo script crea
`MediaInfo-<version>-win32.zip` nella directory della soluzione, utilizzando la versione del file in quattro
parti dell'eseguibile. L'archivio contiene `MediaInfo.exe` e il `license.txt` combinato direttamente alla
radice.

## Compatibilità

Il visualizzatore Win32 è progettato per utilizzare Windows NT 4.0 APIs.

L'eseguibile include tre librerie x86 MediaInfo: 26.10 per l'attuale Windows, 21.03 dal pacchetto Windows XP e
0.7.60 dal pacchetto Windows 95–2000. L'architettura di una libreria da sola non determina la sua
compatibilità con il sistema operativo. Il visualizzatore prova le librerie in bundle dalla più recente alla
più vecchia e si ferma dopo il primo caricamento riuscito e la query sulla versione.

Windows 95 non è attualmente un runtime supportato.

## Utilizzo

- File > Apri (Ctrl+O) apre la finestra di dialogo file Windows con selezione multipla. Su Windows Vista e
  versioni successive, Apri e Salva utilizzano la moderna finestra di dialogo Elementi comuni; il vecchio
  Windows utilizza le finestre di dialogo comuni legacy.
- Trascinare uno o più file nella finestra, sull’icona dell’EXE o sul relativo collegamento, oppure passare i
  percorsi dalla riga di comando. Se non sono consentite più istanze, i file si aprono nella finestra già in
  esecuzione.
- Ogni percorso completo normalizzato distinto ha una scheda. La riapertura di un file già aperto seleziona la
  scheda esistente senza ricaricare o modificare il rapporto, la selezione o la posizione di scorrimento. I
  confronti ignorano le lettere maiuscole e minuscole del percorso. Le aperture di più file elaborano l'elenco
  in ordine e lasciano attivo l'ultimo file elaborato correttamente, sia esso appena aperto o già aperto.
  Passando il mouse sopra l'intestazione di una scheda viene visualizzato il percorso completo del file in una
  descrizione comando nativa, anche quando il nome file visualizzato viene abbreviato.
- Il menu File elenca gli otto file caricati più di recente direttamente sopra Esci, tra separatori. Le voci
  mostrano solo un numero e un nome file. La selezione di una voce apre il percorso completo memorizzato o
  seleziona la scheda esistente; la riapertura riuscita lo sposta in alto senza duplicati. Selezionando un
  file non disponibile viene chiesto se rimuovere la voce dei file recenti. Vengono utilizzati l'icona della
  domanda nativa e i pulsanti Yes/No. Sì è l'impostazione predefinita e rimuove la voce dal menu e dal
  registro; Non lo conserva. La richiesta include il percorso completo.
- La rotellina del mouse sulle intestazioni delle schede straripanti fa scorrere la striscia di intestazione
  di una scheda per messaggio senza modificare la selezione o il focus.
- Ctrl+Tab e Ctrl+Maiusc+Tab cambiano scheda; Ctrl+W chiude la scheda attiva. Facendo clic con il tasto
  centrale sull'intestazione di una scheda si chiude la scheda preservando qualsiasi altra scheda attiva. File
  > Chiudi tutto chiude tutte le schede, compresi i report in coda. File > Esci (Alt+F4) chiude
  l'applicazione.
- Fare doppio clic per selezionare una parola. Il triplo clic seleziona una linea logica. Il trascinamento
  estende la selezione di parole o linee.
- Ctrl+A seleziona il resoconto; Ctrl+C lo copia.
- Modifica > Trova (Ctrl+F) cerca nella scheda attiva. F3 ripete la ricerca; Maiusc+F3 ne inverte la
  direzione. Alle estremità del testo, la ricerca riprende dall’estremità opposta. Opzioni > A capo automatico
  riguarda solo la scheda attiva; il segno di spunta segue la scheda selezionata. La finestra di ricerca può
  essere ridotta a icona e ridimensionata orizzontalmente; la posizione e l’opzione Sempre in primo piano
  vengono memorizzate. Fino a 30 ricerche e le relative opzioni vengono conservate solo fino alla chiusura
  dell’applicazione. Le opzioni di inizio e fine si riferiscono alle righe logiche. Le espressioni regolari
  usano la sintassi PCRE2. Tutti i comandi di Modifica riguardano solo la scheda attiva. Invio avvia la
  ricerca; Maiusc+Invio inverte la direzione scelta. «Maiuscole/minuscole» distingue le lettere maiuscole
  dalle minuscole; «Cerca all’indietro» cerca verso l’inizio del testo. La scelta di una voce della cronologia
  ripristina tutte e cinque le opzioni di ricerca, compreso lo stato del modo per le espressioni regolari;
  «Sempre in primo piano» è indipendente. «Espressione regolare» disattiva «La riga inizia con» e «La riga
  termina con». Se entrambe le opzioni di inizio e fine riga sono attive, è sufficiente una corrispondenza a
  una delle estremità. «A capo automatico» modifica solo la visualizzazione.
- Opzioni > Preferenze (Ctrl+G) apre un'unica finestra di dialogo delle preferenze per percorsi MediaInfo e
  curl, carattere del report, antialiasing dei caratteri, lingua dell'interfaccia e lingua del report. Un
  percorso DLL vuoto consente il rilevamento automatico.
- Il pulsante del carattere visualizza la famiglia, la dimensione in punti e lo stile e apre la finestra di
  dialogo del carattere standard Windows. Ripristina l'impostazione predefinita Consolas o Courier New se
  Consolas non è disponibile; il pulsante Predefinito è disabilitato mentre è selezionata l'impostazione
  predefinita. I caratteri selezionati dall'utente vengono conservati senza sostituzione con il codice
  dell'applicazione.
- Le scelte di antialiasing dei caratteri sono ClearType se supportato, GDI e Nessuno. La scelta iniziale è
  ClearType quando supportato, altrimenti GDI. Le impostazioni dei caratteri influiscono solo sui resoconti
  dei media e sulle relative esportazioni di immagini.
- File > Esporta (Ctrl+E) apre la finestra di dialogo Windows Salva con nome ed esporta l'intero report attivo
  in TXT, BMP, GIF, JPEG, PNG, TIFF o WebP, incluso il testo all'esterno dell'area visibile.
- La Guida apre una finestra non modale separata con la propria voce sulla barra delle applicazioni e il
  pulsante di riduzione a icona. Informazioni su è una finestra di dialogo modale; l'intestazione del prodotto
  elenca tutte e tre le versioni DLL integrate.

Stampa… (Ctrl+P) apre la finestra di sistema per scegliere la stampante e stampa l’intera scheda attiva senza
anteprima. Viene usato il carattere del report; le righe lunghe vanno a capo e il testo viene suddiviso in
pagine. La stampa avviene in background.

Apri cartella… apre i file contenuti direttamente nella cartella selezionata, ciascuno nella propria scheda.
Le sottocartelle non sono incluse. Apri e Apri cartella condividono l’ultima cartella selezionata.
L’esportazione ricorda una cartella separata, Documenti per impostazione predefinita.

La modalità avanzata mostra campi aggiuntivi nel rapporto.

Analisi completa esamina l'intero file e può richiedere più tempo. Queste opzioni del rapporto e Livello di
traccia appartengono a ciascuna scheda; una modifica aggiorna solo la scheda attiva. L'ultima combinazione
scelta manualmente viene salvata per le nuove schede e per l’avvio successivo. Un rapporto memorizzato nella
cache corrispondente viene riutilizzato finché il file rimane invariato.

Formati conosciuti, Codec conosciuti e Parametri conosciuti si aprono nelle proprie schede del report.

La dimensione e la posizione iniziali della finestra vengono selezionate da Windows. Il posizionamento delle
finestre salvato in precedenza sovrascrive quelle predefinite agli avvii successivi.

La parte sinistra della barra di stato mostra i percorsi dei file e l’avanzamento del caricamento; la parte
destra mostra la versione di MediaInfo.dll caricata. I percorsi lunghi vengono abbreviati con puntini di
sospensione in base allo spazio disponibile.

## Crea intestazione file

Il menu Strumenti è il quarto nella barra dei menu. Il suo comando Crea intestazione file… apre un file di
origine indipendentemente dalle schede dei rapporti e ne copia i primi 524288 byte (512 KiB). Un file più
breve viene copiato per intero; un file vuoto produce un output vuoto. Si tratta di una normale lettura di
file binari, senza analisi MediaInfo né necessità di MediaInfo.dll. Lo strumento lascia invariate le schede
dei rapporti e l'elenco dei file recenti del visualizzatore.

Dopo la lettura, la finestra di dialogo Salva con nome si avvia nella cartella del file di origine e
suggerisce video.mp4.header per video.mp4: .header viene aggiunto al nome originale completo. È possibile
modificare sia il nome che la cartella di destinazione. L'annullamento di una delle finestre di dialogo non
scrive alcun output. La sostituzione di una destinazione esistente richiede conferma. Il file di origine
rimane invariata; un salvataggio fallito conserva la destinazione precedente. Per aprire e salvare vengono
usate le finestre di dialogo di sistema più moderne disponibili nella versione di Windows in uso.

All'avvio dell'applicazione, lo strumento prende la cartella di input iniziale da File > Apri. Se non è stata
salvata alcuna cartella, Windows sceglie la posizione iniziale. Dopo aver selezionato un file di input, lo
strumento ricorda la propria cartella solo fino alla chiusura dell'applicazione, anche se Salva con nome viene
annullato. Non modifica le cartelle utilizzate da Apri e Esporta né salva la propria cartella nelle
impostazioni dell'applicazione. Ogni finestra di dialogo Salva con nome inizia nella cartella del file di
input attualmente selezionato, indipendentemente dalla destinazione di salvataggio precedente.

## Ricerca delle librerie

Viene provato prima un percorso manuale salvato. Se non può essere caricato, il rilevamento automatico tenta:

1. MediaInfo.dll accanto all'eseguibile, quindi in ciascuna directory principale fino all'unità o alla
   condivisione root UNC.
2. ProgramFiles, ProgramFiles(x86) e ProgramW6432.
3. LOCALAPPDATA e APPDATA.

In queste radici di installazione, il rilevamento controlla MediaInfo, MediaArea\MediaInfo, MediaArea,
MediaArea.net\MediaInfo, Programs\MediaInfo, Programs\MediaArea\MediaInfo. Le posizioni illeggibili e DLLs
incompatibili vengono saltate. Non esegue la scansione ricorsiva del disco.

Se non viene trovato alcun DLL esterno compatibile, lo spettatore prova le versioni integrate in questo
ordine: 26.10, 21.03, 0.7.60. Estrae e testa una versione alla volta. Una volta caricata correttamente una
versione, le versioni precedenti non vengono né estratte né testate. La sola distribuzione del MediaInfo.exe è
sufficiente; un DLL esterno compatibile ha sempre la priorità e può essere aggiornato indipendentemente.

Una modifica manuale della libreria non riuscita conserva la libreria già caricata.

## Esportazione dei report

I formati Salva con nome sono ordinati TXT, BMP, GIF, JPEG, PNG, TIFF e WebP. I codificatori non supportati
vengono omessi dalle finestre di dialogo sia moderne che legacy.

TXT offre ANSI, UTF-8, UTF-8 con BOM, UTF-16 BE con BOM e UTF-16 LE con BOM. La seconda voce, UTF-8 senza BOM,
è quella predefinita. Il testo completo del report e le interruzioni di riga originali vengono preservati.

BMP, PNG e TIFF preservano tutti i colori renderizzati; GIF89a preserva l'esatta tavolozza renderizzata quando
l'immagine ha al massimo 256 colori. L'esportazione scrive sempre il formato selezionato o segnala un errore;
non sostituisce mai un altro formato.

Le immagini contengono il report completo nel carattere del report selezionato, con testo nero su sfondo
bianco. Non contengono il menu dell'applicazione, le intestazioni delle schede, la barra di stato, la
selezione o il cursore. Il rendering è indipendente dalla posizione di scorrimento della casella di testo.

Per evitare di troncare automaticamente i report o di esaurire lo spazio degli indirizzi sui computer più
vecchi, una singola immagine è limitata a 16.384 pixel di larghezza, 32.767 pixel di altezza e 256 MiB di
memoria bitmap non compressa. Seleziona un carattere più piccolo se un rapporto supera questi limiti.

`Google WebP (*.webp)` è l’ultimo formato e salva il report senza perdita.

WebP: 16383 × 16383 px.

## Lingue dell’interfaccia e dei report

Le preferenze (Opzioni > Preferenze, Ctrl+G) contengono percorsi delle librerie, carattere del rapporto,
antialiasing e lingue. L’interfaccia ha 36 varianti e inizialmente segue Windows. I rapporti usano sempre
l’inglese originale della libreria, indipendentemente da Windows e dall’interfaccia. Solo una scelta manuale
cambia la lingua: inglese, 37 traduzioni o una tabella CSV MediaInfo personalizzata.

OK o Applica conferma le modifiche; Annulla scarta quelle in sospeso. Le preferenze consentono di limitare i
nomi delle schede (80 predefinito) e cancellare l’elenco dei file recenti. I nomi lunghi conservano inizio,
fine ed estensione con puntini di sospensione al centro.

Per impostazione predefinita è consentita una sola istanza e gli avvii successivi inviano i file alla finestra
aperta. Nelle preferenze è possibile consentire più istanze. Con più finestre, solo la prima di ciascun modulo
ripristina la posizione salvata; le successive ripristinano solo le dimensioni.

La modifica solo dell'interfaccia lascia invariato il testo dei report aperti. Una modifica della lingua del
report applicata manualmente ricarica i report mantenendo l'ordine di tabulazione e l'ordine MRU.

## libcurl

Verifiche automatiche di rilevamento dell'curl accanto all'MediaInfo DLL selezionato, quindi
all'executable/ancestor condiviso, ai file di programma e ai percorsi di installazione dell'utente. Se non
viene trovato alcun curl esterno compatibile, la versione corrente o XP incorporata corrispondente viene
estratta nella cache verificata per utente. Il più vecchio MediaInfo 0.7.60 ignora completamente il
rilevamento, l'estrazione e il caricamento di curl. Un curl non valido selezionato esplicitamente rifiuta la
modifica della preferenza; la mancanza del curl automatico opzionale non impedisce i normali rapporti sui file
locali.

## Nomi dei file e file recenti

I nomi dei file MRU vengono abbreviati solo quando sono più lunghi di 80 UTF-16 unità di codice. I puntini di
sospensione centrali conservano l'inizio, la fine del nome del file prima della sua estensione e l'estensione
finale completa; i percorsi completi e i resoconti rimangono invariati. I sottotitoli delle schede utilizzano
lo stesso algoritmo con un limite predefinito configurabile di 80.

File recenti > Cancella cancella immediatamente sia il menu live MRU che i percorsi salvati, lasciando intatte
tutte le schede aperte. Non applica né convalida le preferenze in sospeso e non abilita Applica. Annulla o
Esci preserva la cronologia cancellata scartando le modifiche in sospeso. Cancella è disabilitato ogni volta
che l'elenco è vuoto e il suo stato viene aggiornato quando nuovi report popolano l'elenco. Un errore di
scrittura del registro viene segnalato immediatamente. L'applicazione di un nuovo limite per il nome della
scheda aggiorna ogni scheda aperta senza ricaricare il relativo rapporto multimediale.

## Licenza e redistribuzione

Il visualizzatore è concesso in licenza con la licenza MIT in license.txt.

MediaInfo è un componente di terze parti. L'unico avviso di distribuzione mantenuto è root license.txt,
codificato come UTF-8 con CRLF e include il visualizzatore, le librerie, i componenti incorporati
staticamente, l'icona e le tabelle di traduzione ufficiali.

Questo prodotto utilizza la libreria MediaInfo, Copyright (c) 2002-2026 MediaArea.net SARL.

- MediaInfo: <https://mediaarea.net/MediaInfo>
- Licenza: <https://mediaarea.net/en/MediaInfo/License>
- Windows download: <https://mediaarea.net/en/MediaInfo/Download/Windows>

## Dipendenze

### File

| Risorsa | Architettura | Versione riportata dal componente | SHA-256 |
| --- | --- | --- | --- |
| Resources/lib/26.10/MediaInfo.dll | x86 | 26.10 | E73027A1577084135425AA013D46C8B2985AD142CCF04F1ADB301B9A9CFB78F8 |
| Resources/lib/21.03/MediaInfo.dll | x86 | 21.03 | EBBF1C371702F3DC39CA23D619C47EDF97E66A95AEABE725284F1402D8F3E58A |
| Resources/lib/0.7.60/MediaInfo.dll | x86 | 0.7.60 | A26C07BCC25FA01A40E6888D02EABD59AA8DB2ABF6F5195481228D3A91D04441 |
| Resources/lib/26.10/libcurl.dll | x86 | 8.11.0-DEV, Schannel, zlib 1.3.1 | DCF136C84F3A4FBEAE2B317FE36D7F11225B56FBA3343AF4BBA8706B3F46F334 |
| Resources/lib/21.03/libcurl.dll | x86 | 7.47.1, WinSSL, zlib 1.2.8 | 21025CAC8089F1E570EE083D8CFD6311C2C51E97094A9FCD8C7A0B544C22CB48 |
| Resources/lib/libwebp.dll | x86 | 1.1.0 | 9986023BB6FF5510A157919F0CD958A94800EC6A1D981F3403A9648BEDFEE575 |

I percorsi nella tabella sono relativi alla directory del progetto MediaInfo.

La libreria attuale riporta una versione in sviluppo; la sua esatta fonte commit non può essere recuperata da
quella stringa di versione. L'avviso di accompagnamento utilizza il testo originale di copyright e
autorizzazione 8.11.0, i cui termini di licenza sono presenti anche nella serie di sviluppo.

### Componenti incorporati

| Componente | Prove e portata | Avviso |
| --- | --- | --- |
| MediaInfoLib | Versioni attuali ed esportazioni Unicode richieste; binari forniti invariati | Copyright originale specifico della versione, condizioni di ridistribuzione e clausola di esclusione della responsabilità |
| ZenLib | Riferimenti al progetto statico e ZenLib RTTI incorporati in tutti e tre i DLLs; revisioni collegate esatte non fornite | Avviso in stile zlib ZenLib |
| zlib | Stringhe della versione inflate/deflate incorporate: 1.3.2 in MediaInfo 26.10, 1.2.11 in 21.03, 1.2.7 in 0.7.60; curl riporta inoltre 1.3.1 e 1.2.8 | Avvisi originali zlib per tutte e cinque le versioni |
| TinyXML-2 | Corrispondenza di target di origine moderni e binario RTTI; incluso nel progetto legacy, ma non identificato in modo indipendente nel file binario legacy rimosso | Avviso originale in stile Lee Thomason zlib mantenuto |
| Brian Gladman AES | Incluso in entrambi gli obiettivi della libreria upstream moderna, con avvisi di origine permissivi corrispondenti | 1998–2013 avviso di ridistribuzione e liberatoria |
| Brian Gladman SHA-1/SHA-2 | Entrambi gli obiettivi moderni; Tabelle costanti SHA-256 e SHA-512 presenti in entrambi i binari moderni | 1998–2010 avviso di ridistribuzione e liberatoria |
| Brian Gladman HMAC | Entrambi i target moderni e il loro codice lettore curl/S3 | Avviso originale relativo alle tre condizioni, compreso il paragrafo sulla licenza alternativa |
| MD5 | Obiettivi di origine moderni; L'implementazione Colin Plumb dichiara esplicitamente il dominio pubblico | Attribuzione mantenuta |
| Base64 | Intestazione Markus Ewald in tutti e tre gli alberi di origine corrispondenti, accreditando Bob Withers | Mantenuta l'attribuzione della paternità originale; qualificazione di seguito |
| fmt | 26.10 target e fmt v11 format_error RTTI nel binario | Avviso MIT originale, inclusa l'eccezione facoltativa |
| tfsxml | 26.10 destinazione di origine | Avviso originale MediaArea MIT |
| Interfaccia Android JNI | JNI_OnLoad viene effettivamente esportato sia dal moderno DLLs; l'intestazione JNI inclusa proviene da AOSP | AOSP copyright e licenza Apache completa 2.0 |
| libcurl | Binari x86 forniti; esportazioni della versione attuale; utilizzato dinamicamente dal moderno MediaInfo | Avvisi originali curl per 8.11.0 e 7.47.1 |
| Traduzioni ufficiali dei report | Tutti i sorgenti 38 non modificati CSV dalla directory della lingua MediaInfo v26.10; Sono incorporate tabelle 37 non inglesi, mentre l'inglese utilizza le impostazioni predefinite DLL | Stesso progetto BSD-2-Clause avviso mantenuto nel bando combinato |
| icona MediaInfo | Icona multi-immagine ufficiale non modificata, revisione sorgente f057dd3649bc8692a83863b67770e22c9b9dd81a | Avviso e attribuzione BSD-2-Clause originale |
| libwebp | WebPEncodeLosslessBGRA, WebPFree; 1.1.0; x86 | BSD-3-Clause; PATENTS |

Gli obiettivi di origine corrispondenti stabiliscono l'inclusione in tali configurazioni di build upstream;
non dimostrano che ogni funzione sopravviva all'ottimizzazione nei binari del fornitore. Non viene fatta
alcuna dichiarazione sulla versione esatta per le dipendenze la cui revisione non è registrata in tali file
binari.

### Componenti opzionali e librerie di sistema

- I progetti di libreria Windows abilitano libcurl caricato in runtime per MediaInfo 26.10 e 21.03. MediaInfo
  0.7.60 è stato costruito con MEDIAINFO_LIBCURL_NO; il suo file binario contiene anche la diagnostica del
  supporto disabilitato. Lo spettatore non scopre, estrae o carica mai curl per quella versione in bundle.
- libmms è disabilitato in tutti e tre i Windows DLLs forniti, come confermato dai messaggi di supporto
  disabilitati incorporati. Non è ridistribuito.
- Qt e wxWidgets appartengono a build GUI opzionali. Nessuno dei due è incluso in questo visualizzatore o in
  queste dipendenze DLL. Le loro voci generiche sono state rimosse dalla licenza visualizzata.
- Graphviz è un hook di runtime opzionale nel moderno codice upstream. No Graphviz DLL viene ridistribuito.
- Nessun plugin FFmpeg viene ridistribuito.
- MediaInfo DLLs importa direttamente solo KERNEL32.dll. Ciò non significa che il loro runtime e il codice
  helper collegati staticamente siano assenti.
- L'attuale curl importa direttamente WS2_32.dll, bcrypt.dll, ADVAPI32.dll, CRYPT32.dll e KERNEL32.dll. XP
  curl importa direttamente WS2_32.dll, WLDAP32.dll, ADVAPI32.dll e KERNEL32.dll. Questi sono componenti
  Windows. La loro disponibilità viene verificata dal caricatore Windows.
- Curl riporta Windows Schannel/WinSSL, non una build OpenSSL. La sua dipendenza di compressione aggiuntiva
  segnalata è inclusa staticamente zlib. Nessun ulteriore esterno nonWindows DLL appare nella sua tabella di
  importazione diretta.
- Il visualizzatore stesso non ha alcuna dipendenza dal runtime C/C++. Il DLLs di terze parti fornito contiene
  le proprie porzioni di runtime compilate. Le build Windows utilizzano gli strumenti Microsoft; non esistono
  prove che richiedano voci di inventario generiche libstdc++ o libc++.
- JPEG utilizza il sistema caricato dinamicamente GDI+. C# Resource Packer e PowerShell sono strumenti di
  compilazione e non sono dipendenze di runtime.

La normale ispezione dei file locali non richiede un server MediaArea o un database di formati scaricati in
remoto. libcurl viene utilizzato da MediaInfo per input URL e potenzialmente riferimenti remoti nei formati
multimediali supportati. Il raggruppamento non aggiunge un comando di apertura URL separato a questo
visualizzatore.

### Archiviazione e limitazioni della licenza

L'unico avviso di distribuzione mantenuto è [license.txt](../license.txt) , codificato come UTF-8 con CRLF. Le
clausole di ridistribuzione BSD, curl, zlib, MIT e Apache selezionate non richiedono un file di avviso
separato fisicamente accanto a ciascun DLL; l'avviso combinato li accompagna nei materiali eseguibili e di
distribuzione.

Il pacchetto MediaInfo 0.7.60 archiviato utilizza la propria licenza specifica della versione e include il
vecchio testo GNU Library GPL. I suoi termini distinguono espressamente la ridistribuzione binaria non
modificata dalle versioni modificate; il collegamento dinamico da parte di questo visualizzatore non modifica
il file DLL fornito. Le sue condizioni originali e il testo della licenza di accompagnamento vengono
mantenuti. Il visualizzatore mantiene la licenza MIT.

Un'attribuzione a monte richiede una qualificazione: l'intestazione Markus Ewald Base64 non ha
un'autorizzazione esplicita o una dichiarazione di licenza. MediaArea descrive l'implementazione Bob Withers
Base64 come di pubblico dominio nella relativa documentazione MediaConch, ma ciò non stabilisce in modo
indipendente una concessione di licenza per ogni modifica di Ewald. Non è stata inventata alcuna concessione
di licenza per quell'intestazione. Una conferma completa del fornitore di tale provenienza, le esatte
revisioni dell'ZenLib e lo sviluppo dell'curl commit non erano disponibili nei file binari forniti. Questi
punti impediscono di trattare questo inventario come un SBOM completo e certificato in modo indipendente.

### Fonti primarie

- [MediaInfo termini di ridistribuzione](https://mediaarea.net/en/MediaInfo/License)
- 
  [destinazione della libreria MediaInfo 26.10](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Project/MSVC2022/Library/MediaInfoLib.vcxproj)
- 
  [destinazione della libreria MediaInfo 21.03](https://github.com/MediaArea/MediaInfoLib/blob/v21.03/Project/MSVC2015/Library/MediaInfoLib.vcxproj)
- 
  [destinazione della libreria MediaInfo 0.7.60](https://github.com/MediaArea/MediaInfoLib/blob/v0.7.60/Project/MSVC2005/Library/MediaInfoLib.vcproj)
- 
  [Caricatore runtime curl](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Source/MediaInfo/Reader/Reader_libcurl.cpp)
- 
  [Fonti di supporto in bundle e relativi avvisi](https://github.com/MediaArea/MediaInfoLib/tree/v26.10/Source/ThirdParty)
- [ZenLib avviso](https://github.com/MediaArea/ZenLib/blob/master/License.txt)
- [zlib avvisi sulla fonte](https://github.com/madler/zlib/blob/v1.3.2/zlib.h)
- [curl 8.11.0 avviso](https://github.com/curl/curl/blob/curl-8_11_0/COPYING)
- [curl 7.47.1 avviso](https://github.com/curl/curl/blob/curl-7_47_1/COPYING)
- [Licenza Apache 2.0](https://www.apache.org/licenses/LICENSE-2.0)
- [MediaArea Base64 descrizione](https://github.com/MediaArea/MediaConch/blob/master/README.md)

Le tabelle del report provengono da
<https://github.com/MediaArea/MediaInfo/tree/v26.10/Source/Resource/Plugin/Language> . Il progetto
corrispondente LICENSE è <https://github.com/MediaArea/MediaInfo/blob/v26.10/LICENSE> .

- [libwebp 1.1.0 COPYING](https://github.com/webmproject/libwebp/blob/v1.1.0/COPYING)
- [libwebp 1.1.0 PATENTS](https://github.com/webmproject/libwebp/blob/v1.1.0/PATENTS)
