# MediaInfo Viewer

[Čeština](README.cs-CZ.md) | [English (US)](../README.md) | [English (UK)](README.en-GB.md) | [English (Australia)](README.en-AU.md) | **Deutsch** | [Français](README.fr-FR.md) | [Español](README.es-ES.md) | [Italiano](README.it-IT.md) | [Português](README.pt-PT.md) | [Polski](README.pl-PL.md) | [Slovenčina](README.sk-SK.md) | [Dansk](README.da-DK.md) | [Suomi](README.fi-FI.md) | [Íslenska](README.is-IS.md) | [Norsk (bokmål)](README.nb-NO.md) | [Svenska](README.sv-SE.md) | [Türkçe](README.tr-TR.md) | [Eesti](README.et-EE.md) | [Gaeilge](README.ga-IE.md) | [Lietuvių](README.lt-LT.md) | [Latviešu](README.lv-LV.md) | [Magyar](README.hu-HU.md) | [Malti](README.mt-MT.md) | [Nederlands](README.nl-NL.md) | [Română](README.ro-RO.md) | [Ελληνικά](README.el-GR.md) | [Bosanski](README.bs-Latn-BA.md) | [Hrvatski](README.hr-HR.md) | [Slovenščina](README.sl-SI.md) | [Crnogorski](README.cnr-Latn-ME.md) | [Беларуская](README.be-BY.md) | [Български](README.bg-BG.md) | [Македонски](README.mk-MK.md) | [Српски](README.sr-Cyrl-RS.md) | [Українська](README.uk-UA.md) | [Русский](README.ru-RU.md)

Nativer x86-Windows-Betrachter für Berichte von MediaInfo.dll. Jede Datei erhält einen eigenen
schreibgeschützten Tab.

[Build und Kompatibilität](#erstellen-der-anwendung) | [Prüfung der Abhängigkeiten](#abhängigkeiten) | [Lizenz](../license.txt)

## Erstellen der Anwendung

Öffnen Sie MediaInfo.sln in Visual Studio 2015 mit installiertem Visual C++ v140-Toolset. Wählen Sie Release | Win32 und erstellen Sie die Lösung. Die einzige Anwendungsplattform ist Win32 (x86).

[PCRE2 10.49](https://github.com/PCRE2Project/pcre2/tree/pcre2-10.49) — UTF-16, statisch eingebunden,
BSD-3-Clause. [Quellcode](../MediaInfo/PCRE2/).
[license.txt](../license.txt).
PCRE2 ist in die EXE eingebunden und erfordert weder eine separate DLL noch eine zusätzliche Installation.

Ausgänge:

- Release\MediaInfo.exe
- Debug\MediaInfo.exe

Der Viewer verknüpft die C- oder C++-Laufzeitumgebung nicht und benötigt kein MSVC-Redistributable. Der
ausgewählte MediaInfo.dll kann seine eigenen Abhängigkeiten haben.

Für den Bau sind Windows PowerShell und .NET Framework erforderlich. Die native ausführbare Datei erfordert
weder PowerShell noch .NET.

### Distributionspaket

Führen Sie nach dem Erstellen von Release
`powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\PackageRelease.ps1` aus. Das Skript erstellt
`MediaInfo-<version>-win32.zip` im Lösungsverzeichnis und verwendet dabei die vierteilige Dateiversion der
ausführbaren Datei. Das Archiv enthält `MediaInfo.exe` und das kombinierte `license.txt` direkt im
Stammverzeichnis.

## Kompatibilität

Der Win32-Viewer ist für die Verwendung von Windows NT 4.0 APIs konzipiert.

Die ausführbare Datei enthält drei x86 MediaInfo-Bibliotheken: 26.10 für das aktuelle Windows, 21.03 aus dem
Paket Windows XP und 0.7.60 aus dem Paket Windows 95–2000. Die Architektur einer Bibliothek allein bestimmt
nicht ihre Betriebssystemkompatibilität. Der Viewer durchsucht die gebündelten Bibliotheken von der neuesten
zur ältesten und stoppt nach der ersten erfolgreichen Lade- und Versionsabfrage.

Windows 95 ist derzeit keine unterstützte Laufzeit.

## Verwendung

- Datei > Öffnen (Strg+O) öffnet den Dateidialog Windows mit Mehrfachauswahl. Auf Windows Vista und höher
  verwenden Sie beim Öffnen und Speichern das moderne Dialogfeld „Allgemeines Element“. Ältere Windows
  verwenden die alten allgemeinen Dialoge.
- Ziehen Sie eine oder mehrere Dateien auf das Fenster, das EXE-Symbol oder dessen Verknüpfung, oder übergeben
  Sie die Pfade in der Befehlszeile. Wenn mehrere Instanzen nicht erlaubt sind, werden die Dateien im bereits
  geöffneten Fenster angezeigt.
- Jeder eindeutige normalisierte vollständige Pfad verfügt über eine Registerkarte. Beim erneuten Öffnen einer
  bereits geöffneten Datei wird die vorhandene Registerkarte ausgewählt, ohne dass der Bericht, die Auswahl
  oder die Bildlaufposition neu geladen oder geändert werden müssen. Bei Vergleichen wird die
  Groß-/Kleinschreibung von Pfadbuchstaben ignoriert. Beim Öffnen mehrerer Dateien wird die Liste der Reihe
  nach verarbeitet und die zuletzt erfolgreich verarbeitete Datei bleibt aktiv, unabhängig davon, ob sie neu
  geöffnet oder bereits geöffnet ist. Wenn Sie mit der Maus über die Kopfzeile einer Registerkarte fahren,
  wird der vollständige Dateipfad in einer nativen QuickInfo angezeigt, auch wenn der angezeigte Dateiname
  gekürzt ist.
- Das Menü „Datei“ listet die acht zuletzt geladenen Dateien direkt über „Beenden“ zwischen Trennzeichen auf.
  Einträge zeigen nur eine Nummer und einen Dateinamen. Wenn Sie einen Eintrag auswählen, wird dessen
  gespeicherter vollständiger Pfad geöffnet oder die vorhandene Registerkarte ausgewählt. Durch erfolgreiches
  erneutes Öffnen wird es ohne Duplikate nach oben verschoben. Wenn Sie eine nicht verfügbare Datei auswählen,
  werden Sie gefragt, ob deren Eintrag „Zuletzt verwendete Dateien“ entfernt werden soll. Es werden das native
  Fragesymbol und die Schaltflächen Yes/No verwendet. „Ja“ ist die Standardeinstellung und entfernt den
  Eintrag aus dem Menü und der Registrierung. Nein, behält es. Die Eingabeaufforderung enthält den
  vollständigen Pfad.
- Das Mausrad über überfüllten Tab-Headern scrollt den Header-Streifen um einen Tab pro Nachricht, ohne die
  Auswahl oder den Fokus zu ändern.
- Strg+Tab und Strg+Umschalt+Tab wechseln die Registerkarten; Strg+W schließt die aktive Registerkarte. Wenn
  Sie mit der mittleren Maustaste auf eine Registerkartenüberschrift klicken, wird diese Registerkarte
  geschlossen, während alle anderen aktiven Registerkarten erhalten bleiben. „Datei“ > „Alle schließen“
  schließt alle Registerkarten, einschließlich der in der Warteschlange befindlichen Berichte. Datei > Beenden
  (Alt+F4) schließt die Anwendung.
- Das Kontextmenü eines Tabreiters enthält Tab schließen. Aktivieren Sie Tabs per Doppelklick schließen
  in den Voreinstellungen, um einen Tab durch Doppelklick auf seinen Reiter zu schließen. Die Option ist
  anfangs deaktiviert und wird gespeichert.
- Ein Doppelklick im Berichtstext wählt ein Wort aus. Ein Dreifachklick wählt eine logische Zeile aus.
  Ziehen erweitert die Auswahl um Wörter oder Zeilen.
- Strg+A wählt den Bericht aus; Strg+C kopiert es.
- Bearbeiten > Suchen (Strg+F) durchsucht je nach Fensterfokus den aktiven Berichtstab oder den
  Textbereich in Hilfe oder Info. Solange das Suchfenster den Fokus hat, behält es die zuletzt gewählte
  Quelle bei. F3 wiederholt die Suche; Umschalt+F3 kehrt die Suchrichtung um. Am Textende wird die Suche
  am anderen Ende fortgesetzt. Optionen > Zeilenumbruch gilt nur für den aktiven Tab; das Häkchen
  richtet sich nach dem ausgewählten Tab. Das Suchfenster lässt sich minimieren und in der Breite
  verändern; seine Position und die Einstellung Immer im Vordergrund werden gespeichert. Bis zu 30
  Suchtexte mit ihren Optionen bleiben nur bis zum Beenden der Anwendung erhalten. Zeile beginnt mit und
  Zeile endet mit beziehen sich auf logische Zeilen. Reguläre Ausdrücke verwenden die PCRE2-Syntax. Die
  übrigen Befehle im Menü Bearbeiten betreffen den aktiven Berichtstab. Eingabe startet die Suche;
  Umschalt+Eingabe kehrt die gewählte Richtung um. „Groß-/Kleinschreibung beachten“ unterscheidet Groß-
  und Kleinbuchstaben; „Rückwärts suchen“ sucht zum Textanfang hin. Ein Eintrag aus dem Verlauf stellt
  alle fünf Suchoptionen wieder her und schaltet gegebenenfalls den Regexmodus aus; „Immer im
  Vordergrund“ ist unabhängig davon. „Regulärer Ausdruck“ deaktiviert „Zeile beginnt mit“ und „Zeile
  endet mit“. Sind beide Zeilenrandoptionen aktiv, genügt ein Treffer an einem Rand. „Zeilenumbruch“
  ändert nur die Darstellung.
- Optionen > Voreinstellungen (Strg+G) öffnet einen einzelnen Voreinstellungsdialog für MediaInfo- und
  curl-Pfade, Berichtsschriftart, Schriftarten-Antialiasing, Schnittstellensprache und Berichtssprache. Ein
  leerer DLL-Pfad ermöglicht die automatische Erkennung.
- Die Schriftart-Schaltfläche zeigt die Familie, die Punktgröße und den Stil an und öffnet das
  Standarddialogfeld für die Schriftart Windows. Standardmäßig wird Consolas oder Courier New
  wiederhergestellt, wenn Consolas nicht verfügbar ist. Die Schaltfläche „Standard“ ist deaktiviert, solange
  die Standardeinstellung ausgewählt ist. Vom Benutzer ausgewählte Schriftarten bleiben erhalten, ohne durch
  Anwendungscode ersetzt zu werden.
- Die Auswahlmöglichkeiten für Schriftarten-Antialiasing sind ClearType, sofern unterstützt, GDI und
  Keine. Die erste Wahl ist ClearType, sofern unterstützt, andernfalls GDI. Schrifteinstellungen gelten
  für Berichtstabs, deren Bildexporte und den Berichtsdruck. Hilfe und Info behalten ihre eigenen
  Textschriften.
- Die Hilfe öffnet ein separates nicht modales Fenster mit einem eigenen Taskleisteneintrag und einer
  Schaltfläche zum Minimieren. About ist ein modaler Dialog; Im Produktheader sind alle drei eingebetteten
  DLL-Versionen aufgeführt.

Datei > Seite einrichten… öffnet die Einstellungen für Papier, Ausrichtung und Ränder für die aktuelle
Sitzung. Drucken… (Strg+P) öffnet den Systemdruckdialog; Windows 11 bietet eine Vorschau, Windows 10 und
ältere Versionen behalten den klassischen Dialog. Strg+P druckt je nach Fensterfokus den aktiven Tab des
Hauptfensters oder den Textbereich in Hilfe oder Info. Berichte verwenden die gewählte Berichtsschrift,
Hilfe die Systemdialogschrift und Info die Schrift seines Textbereichs. Sind keine Tabs geöffnet, aber
die Hilfe ist offen, bleiben Seite einrichten… und Drucken… verfügbar; Drucken… druckt die Hilfe. Die
Hilfe verwendet den Druckdialog des Hauptfensters; erneutes Strg+P in der Hilfe holt ihn in den
Vordergrund. Lange Zeilen werden umgebrochen und der Text auf Seiten verteilt. Der Druck läuft im
Hintergrund.

Ordner öffnen… öffnet die Dateien direkt im ausgewählten Ordner jeweils in einer eigenen Registerkarte.
Unterordner werden nicht einbezogen. Öffnen und Ordner öffnen verwenden gemeinsam den zuletzt ausgewählten
Ordner. Export merkt sich einen eigenen Ordner; standardmäßig ist dies Dokumente.

Der erweiterte Modus zeigt zusätzliche Berichtsfelder an.

Vollständige Analyse untersucht die gesamte Datei und kann länger dauern. Diese Berichtsoptionen und
Trace-Stufe gehören zu jeder Registerkarte; eine Änderung aktualisiert nur die aktive Registerkarte. Die
zuletzt manuell gewählte Kombination wird für neue Registerkarten und den nächsten Start gespeichert. Ein
übereinstimmender zwischengespeicherter Bericht wird wiederverwendet, solange die Datei unverändert bleibt.

Bekannte Formate, Bekannte Codecs und Bekannte Parameter öffnen sich in eigenen Berichtsregisterkarten.

Die anfängliche Fenstergröße und -position werden von Windows ausgewählt. Die zuvor gespeicherte
Fensterplatzierung überschreibt diese Standardeinstellungen bei späteren Starts.

Links in der Statusleiste werden Dateipfade und der Ladefortschritt angezeigt, rechts die Version der
geladenen MediaInfo.dll. Lange Pfade werden passend zum verfügbaren Platz mit Auslassungspunkten gekürzt.

## Header-Datei erstellen

Das Menü Extras ist der vierte Eintrag in der Menüleiste. Sein Befehl Header-Datei erstellen… öffnet eine
Quelldatei unabhängig von den Berichtsregisterkarten und kopiert deren erste 524288 Bytes (512 KiB). Eine
kürzere Datei wird vollständig kopiert; eine leere Datei erzeugt eine leere Ausgabe. Dabei handelt es sich um
das normale Lesen von Binärdateien ohne MediaInfo-Analyse und ohne MediaInfo.dll. Das Tool lässt die
Berichtsregisterkarten und die Liste der zuletzt verwendeten Dateien des Viewers unverändert.

Nach dem Lesen startet der Dialog „Speichern unter“ im Ordner der Quelldatei und schlägt video.mp4.header für
video.mp4 vor: .header wird an den vollständigen Originalnamen angehängt. Sie können sowohl den Namen als auch
den Zielordner ändern. Wenn Sie einen der beiden Dialoge abbrechen, wird keine Ausgabe geschrieben. Das
Ersetzen eines vorhandenen Ziels erfordert eine Bestätigung. Die Quelldatei bleibt unverändert; bei einer
fehlgeschlagenen Speicherung bleibt das vorherige Ziel erhalten. Zum Öffnen und Speichern werden die
modernsten Systemdialoge verwendet, die auf dieser Windows-Version verfügbar sind.

Beim Start der Anwendung übernimmt das Tool seinen anfänglichen Eingabeordner von Datei > Öffnen. Wenn kein
Ordner gespeichert wurde, wählt Windows den ursprünglichen Speicherort. Nachdem eine Eingabedatei ausgewählt
wurde, merkt sich das Tool seinen eigenen Ordner nur, bis die Anwendung beendet wird, auch wenn „Speichern
unter“ abgebrochen wird. Es ändert weder die von Öffnen und Exportieren verwendeten Ordner, noch speichert es
seinen eigenen Ordner in den Anwendungseinstellungen. Jeder Dialog „Speichern unter“ startet im Ordner der
aktuell ausgewählten Eingabedatei, unabhängig vom vorherigen Speicherort.

## Bibliothekssuche

Zuerst wird ein gespeicherter manueller Pfad ausprobiert. Wenn es nicht geladen werden kann, versucht die
automatische Erkennung Folgendes:

1. MediaInfo.dll neben der ausführbaren Datei, dann in jedem übergeordneten Verzeichnis bis zum Laufwerk oder
   UNC Stammverzeichnis der Freigabe.
2. ProgramFiles, ProgramFiles(x86) und ProgramW6432.
3. LOCALAPPDATA und APPDATA.

Unter diesen Installationsstämmen prüft die Erkennung MediaInfo, MediaArea\MediaInfo, MediaArea,
MediaArea.net\MediaInfo, Programs\MediaInfo, Programs\MediaArea\MediaInfo. Nicht lesbare Speicherorte und
inkompatible DLLs werden übersprungen. Die Festplatte wird nicht rekursiv gescannt.

Wenn kein kompatibler externer DLL gefunden wird, probiert der Viewer die eingebetteten Versionen in dieser
Reihenfolge aus: 26.10, 21.03, 0.7.60. Es extrahiert und testet jeweils eine Version. Sobald eine Version
erfolgreich geladen wurde, werden ältere Versionen weder extrahiert noch getestet. Es reicht aus,
MediaInfo.exe allein zu verteilen; Ein kompatibler externer DLL hat immer Vorrang und kann unabhängig
aktualisiert werden.

Bei einer fehlgeschlagenen manuellen Bibliotheksänderung bleibt die bereits geladene Bibliothek erhalten.

## Exportieren von Berichten

Die Formate „Speichern unter“ haben die Reihenfolge TXT, BMP, GIF, JPEG, PNG, TIFF und WebP. Nicht
unterstützte Encoder werden sowohl in modernen als auch in älteren Dialogen weggelassen.

TXT bietet ANSI, UTF-8, UTF-8 mit BOM, UTF-16 BE mit BOM und UTF-16 LE mit BOM. Standard ist der zweite
Eintrag, UTF-8 ohne BOM. Der vollständige Berichtstext und seine ursprünglichen Zeilenumbrüche bleiben
erhalten.

BMP, PNG und TIFF behalten alle gerenderten Farben bei; GIF89a behält die exakte gerenderte Palette bei, wenn
das Bild höchstens 256 Farben hat. es ersetzt niemals ein anderes Format.

## Sprachen der Oberfläche und der Berichte

Die Voreinstellungen (Optionen > Voreinstellungen, Strg+G) enthalten Bibliothekspfade, Berichtsschrift,
Kantenglättung und Sprachen. Die Oberfläche bietet 36 Varianten und richtet sich zunächst nach Windows.
Berichte verwenden stets das ursprüngliche Englisch der Bibliothek, unabhängig von Windows und Oberfläche. Nur
die manuelle Berichtssprachwahl ändert dies: Englisch, 37 Übersetzungen oder eine eigene
MediaInfo-CSV-Tabelle.

OK oder Übernehmen bestätigt Änderungen; Abbrechen verwirft ausstehende Änderungen. Die Voreinstellungen
enthalten die Tabnamenlänge (Standard 80) und das Löschen der Liste zuletzt verwendeter Dateien. Lange Namen
behalten Anfang, Ende und Erweiterung mit Auslassungszeichen in der Mitte.

Standardmäßig ist nur eine Instanz erlaubt; weitere Starts übergeben Dateien an das offene Fenster. In den
Voreinstellungen lassen sich mehrere Instanzen zulassen. Bei mehreren Fenstern wird die gespeicherte Position
nur für das erste Fenster jedes Formulars wiederhergestellt; weitere Fenster übernehmen nur die Größe.

Wenn Sie nur die Benutzeroberfläche ändern, bleibt der Text geöffneter Berichte unverändert. Durch eine
manuell vorgenommene Änderung der Berichtssprache werden die Berichte neu geladen, wobei die Tab-Reihenfolge
und die MRU-Reihenfolge beibehalten werden.

## libcurl

Automatische curl-Erkennungsprüfungen neben den ausgewählten MediaInfo DLL, dann den freigegebenen
executable/ancestor, Programmdateien und Benutzerinstallationsspeicherorten. Wenn kein kompatibler externer
curl gefunden wird, wird die passende eingebettete aktuelle oder XP-Version in den überprüften
benutzerspezifischen Cache extrahiert. Der älteste MediaInfo 0.7.60 umgeht die Erkennung, Extraktion und das
Laden von curl vollständig. Ein explizit ausgewählter ungültiger curl lehnt die Präferenzänderung ab; Das
Fehlen des optionalen automatischen curl verhindert nicht normale lokale Dateiberichte.

## Dateinamen und zuletzt verwendete Dateien

MRU Dateinamen werden nur gekürzt, wenn sie länger als 80 UTF-16 Codeeinheiten sind. Ein mittleres
Auslassungszeichen bewahrt den Anfang, das Ende des Dateinamens vor seiner Erweiterung und die vollständige
Enderweiterung; Die vollständigen Pfade und Berichte bleiben unverändert. Tab-Beschriftungen verwenden
denselben Algorithmus mit einem konfigurierbaren Standardlimit von 80.

Zuletzt verwendete Dateien > Löschen löscht sofort sowohl das Live-Menü MRU als auch seine gespeicherten
Pfade, während alle geöffneten Registerkarten intakt bleiben. Ausstehende Einstellungen werden nicht
angewendet oder validiert und „Anwenden“ wird nicht aktiviert. Mit „Abbrechen“ oder „Escape“ bleibt der
gelöschte Verlauf erhalten, während ausstehende Änderungen verworfen werden. „Löschen“ ist deaktiviert, wenn
die Liste leer ist, und ihr Status wird aktualisiert, wenn neue Berichte die Liste füllen. Ein
Registrierungsschreibfehler wird sofort gemeldet. Durch Anwenden einer neuen Tab-Namensbeschränkung wird jeder
geöffnete Tab aktualisiert, ohne dass der Medienbericht neu geladen werden muss.

## Lizenz und Weiterverbreitung

Der Viewer ist unter der MIT-Lizenz in license.txt lizenziert.

MediaInfo ist eine Komponente eines Drittanbieters. Der einzige gepflegte Verteilungshinweis ist Root
license.txt, codiert als UTF-8 mit CRLF und enthält den Viewer, Bibliotheken, statisch integrierte
Komponenten, Symbole und offizielle Übersetzungstabellen.

Dieses Produkt verwendet die Bibliothek MediaInfo, Copyright (c) 2002-2026 MediaArea.net SARL.

- MediaInfo: <https://mediaarea.net/MediaInfo>
- Lizenz: <https://mediaarea.net/en/MediaInfo/License>
- Windows Downloads: <https://mediaarea.net/en/MediaInfo/Download/Windows>

## Abhängigkeiten

### Dateien

| Ressource | Architektur | Von der Komponente gemeldete Version | SHA-256 |
| --- | --- | --- | --- |
| Resources/lib/26.10/MediaInfo.dll | x86 | 26.10 | E73027A1577084135425AA013D46C8B2985AD142CCF04F1ADB301B9A9CFB78F8 |
| Resources/lib/21.03/MediaInfo.dll | x86 | 21.03 | EBBF1C371702F3DC39CA23D619C47EDF97E66A95AEABE725284F1402D8F3E58A |
| Resources/lib/0.7.60/MediaInfo.dll | x86 | 0.7.60 | A26C07BCC25FA01A40E6888D02EABD59AA8DB2ABF6F5195481228D3A91D04441 |
| Resources/lib/26.10/libcurl.dll | x86 | 8.11.0-DEV, Schannel, zlib 1.3.1 | DCF136C84F3A4FBEAE2B317FE36D7F11225B56FBA3343AF4BBA8706B3F46F334 |
| Resources/lib/21.03/libcurl.dll | x86 | 7.47.1, WinSSL, zlib 1.2.8 | 21025CAC8089F1E570EE083D8CFD6311C2C51E97094A9FCD8C7A0B544C22CB48 |
| Resources/lib/libwebp.dll | x86 | 1.1.0 | 9986023BB6FF5510A157919F0CD958A94800EC6A1D981F3403A9648BEDFEE575 |

Die Pfade in der Tabelle beziehen sich auf das MediaInfo-Projektverzeichnis.

Die aktuelle Bibliothek meldet eine Entwicklungsversion; Die genaue Quelle commit kann aus dieser
Versionszeichenfolge nicht wiederhergestellt werden. Der Begleithinweis verwendet den Urheber- und
Erlaubnistext des Originalautors 8.11.0, dessen Lizenzbedingungen auch in der Entwicklungsreihe enthalten
sind.

### Enthaltene Komponenten

| Komponente | Beweise und Umfang | Beachten |
| --- | --- | --- |
| MediaInfoLib | Aktuelle Versionen und erforderliche Unicode-Exporte; unverändert bereitgestellte Binärdateien | Versionsspezifisches Original-Copyright, Weiterverbreitungsbedingungen und Haftungsausschluss |
| ZenLib | Statische Projektreferenzen und eingebettete ZenLib RTTI in allen drei DLLs; genaue verlinkte Revisionen nicht angegeben | Hinweis im zlib-Stil ZenLib |
| zlib | Eingebettete inflate/deflate-Versionszeichenfolgen: 1.3.2 in MediaInfo 26.10, 1.2.11 in 21.03, 1.2.7 in 0.7.60; curl meldet zusätzlich 1.3.1 und 1.2.8 | Originale zlib-Mitteilungen für alle fünf Versionen |
| TinyXML-2 | Passende moderne Quellziele und binäre RTTI; im Legacy-Projekt enthalten, aber nicht unabhängig in der entfernten Legacy-Binärdatei identifiziert | Ursprünglicher Hinweis im Stil von Lee Thomason zlib beibehalten |
| Brian Gladman AES | In beiden modernen Upstream-Bibliothekszielen enthalten, mit entsprechenden freizügigen Quellenhinweisen | 1998–2013 Weiterverbreitungsmitteilung und Haftungsausschluss |
| Brian Gladman SHA-1/SHA-2 | Beides moderne Ziele; Die Konstantentabellen SHA-256 und SHA-512 sind in beiden modernen Binärdateien vorhanden | 1998–2010 Weiterverbreitungsmitteilung und Haftungsausschluss |
| Brian Gladman HMAC | Sowohl moderne Ziele als auch ihr curl/S3-Lesercode | Ursprüngliche Drei-Bedingungs-Mitteilung, einschließlich des Absatzes zur alternativen Lizenz |
| MD5 | Moderne Quellziele; Die Colin Plumb-Implementierung gibt ausdrücklich die öffentliche Domain an | Namensnennung bleibt erhalten |
| Base64 | Markus Ewald-Header in allen drei entsprechenden Quellbäumen mit Angabe von Bob Withers | Ursprüngliche Urheberangabe bleibt erhalten; Qualifikation unten |
| fmt | 26.10 Ziel und fmt v11 format_error RTTI in der Binärdatei | Ursprüngliche MIT-Mitteilung, einschließlich optionaler Ausnahme |
| tfsxml | 26.10 Quellziel | Ursprüngliche Mitteilung vom MediaArea MIT |
| Android JNI-Schnittstelle | JNI_OnLoad wird tatsächlich von beiden modernen DLLs exportiert; Der enthaltene JNI-Header stammt von AOSP | AOSP Copyright und vollständige Apache-Lizenz 2.0 |
| libcurl | Mitgelieferte x86-Binärdateien; aktuelle Versionsexporte; dynamisch verwendet von modernen MediaInfo | Ursprüngliche curl-Mitteilungen für 8.11.0 und 7.47.1 |
| Offizielle Berichtsübersetzungen | Alle 38 unveränderten CSV-Quellen aus dem Sprachverzeichnis MediaInfo v26.10; 37 nicht-englische Tabellen sind eingebettet, während für Englisch die DLL-Standardwerte verwendet werden | Dieselbe Projekt-BSD-2-Clause-Bekanntmachung wurde in der kombinierten Bekanntmachung beibehalten |
| MediaInfo-Symbol | Unverändertes offizielles Multibild-Symbol, Quellrevision f057dd3649bc8692a83863b67770e22c9b9dd81a | Ursprünglicher Hinweis und Namensnennung von BSD-2-Clause |
| libwebp | WebPEncodeLosslessBGRA, WebPFree; 1.1.0; x86 | BSD-3-Clause; PATENTS |

Die passenden Quellziele stellen die Einbindung in diese Upstream-Build-Konfigurationen her; Sie beweisen
nicht, dass jede Funktion die Optimierung in den Binärdateien des Anbieters übersteht. Für Abhängigkeiten,
deren Revision nicht in diesen Binärdateien aufgezeichnet ist, wird kein Anspruch auf eine genaue Version
erhoben.

### Optionale Komponenten und Systembibliotheken

- Die Windows-Bibliotheksprojekte ermöglichen zur Laufzeit geladenes libcurl für MediaInfo 26.10 und 21.03.
  MediaInfo 0.7.60 wurde mit MEDIAINFO_LIBCURL_NO erstellt; Seine Binärdatei enthält auch die
  Disabled-Support-Diagnose. Der Betrachter entdeckt, extrahiert oder lädt niemals curl für diese gebündelte
  Version.
- libmms ist in allen drei bereitgestellten Windows DLLs deaktiviert, wie durch die eingebetteten Meldungen
  zur deaktivierten Unterstützung bestätigt. Es wird nicht weiterverteilt.
- Qt und wxWidgets gehören zu optionalen GUI-Builds. Weder ist in diesem Viewer noch in diesen
  DLL-Abhängigkeiten enthalten. Ihre generischen Einträge wurden aus der angezeigten Lizenz entfernt.
- Graphviz ist ein optionaler Laufzeit-Hook in modernem Upstream-Code. Kein Graphviz DLL wird neu verteilt.
- Es wird kein FFmpeg-Plugin weitergegeben.
- Die MediaInfo DLLs importieren direkt nur KERNEL32.dll. Dies bedeutet nicht, dass ihr statisch verknüpfter
  Laufzeit- und Hilfscode fehlt.
- Der aktuelle curl importiert direkt WS2_32.dll, bcrypt.dll, ADVAPI32.dll, CRYPT32.dll und KERNEL32.dll. XP
  curl importiert direkt WS2_32.dll, WLDAP32.dll, ADVAPI32.dll und KERNEL32.dll. Dies sind
  Windows-Komponenten. Ihre Verfügbarkeit wird vom Windows-Loader überprüft.
- Curl meldet Windows Schannel/WinSSL, keinen OpenSSL-Build. Die gemeldete zusätzliche
  Komprimierungsabhängigkeit ist statisch enthalten zlib. In der Direktimporttabelle erscheint kein
  zusätzlicher externer Nicht-Windows DLL.
- Der Viewer selbst hat keine C/C++-Laufzeitabhängigkeit. Die bereitgestellten DLLs von Drittanbietern
  enthalten ihre eigenen kompilierten Laufzeitteile. Die Windows-Builds verwenden Microsoft-Tools. Es gibt
  keine Hinweise darauf, dass die generischen Inventareinträge libstdc++ oder libc++ erforderlich sind.
- JPEG verwendet das dynamisch geladene System GDI+. Der Ressourcenpacker C# und PowerShell sind Build-Tools
  und keine Laufzeitabhängigkeiten.

Für die normale Inspektion lokaler Dateien ist weder ein MediaArea-Server noch eine remote heruntergeladene
Formatdatenbank erforderlich. libcurl wird von MediaInfo für URL-Eingaben und potenzielle Remote-Referenzen in
unterstützten Medienformaten verwendet. Durch die Bündelung wird diesem Viewer kein separater Befehl zum
Öffnen von URL hinzugefügt.

### Lizenzspeicherung und Einschränkungen

Die einzige gepflegte Verteilungsmitteilung ist [license.txt](../license.txt) , kodiert als UTF-8 mit CRLF.
Die überprüften BSD-, curl-, zlib-, MIT- und Apache-Umverteilungsklauseln erfordern keine separate
Benachrichtigungsdatei physisch neben jedem DLL; Die gemeinsame Bekanntmachung liegt ihnen in den Ausführungs-
und Vertriebsmaterialien bei.

Das archivierte Paket MediaInfo 0.7.60 verwendet seine eigene versionspezifische Lizenz und enthält den alten
GNU Library GPL-Text. Seine Bedingungen unterscheiden ausdrücklich die unveränderte binäre Umverteilung von
modifizierten Versionen; Durch die dynamische Verknüpfung durch diesen Viewer wird der bereitgestellte DLL
nicht geändert. Die Originalbedingungen und der zugehörige Lizenztext bleiben erhalten. Der Viewer bleibt
MIT-lizenziert.

Eine Upstream-Zuordnung muss qualifiziert werden: Der Header Markus Ewald Base64 hat keine explizite Erlaubnis
oder Lizenzerklärung. MediaArea beschreibt die Bob Withers Base64-Implementierung in der zugehörigen
MediaConch-Dokumentation als Public Domain, aber das begründet nicht unabhängig eine Lizenzgewährung für jede
Ewald-Änderung. Für diesen Header wurde keine Lizenzgewährung erfunden. Eine vollständige
Herstellerbestätigung dieser Herkunft, der genauen ZenLib-Revisionen und der curl-Entwicklung commit war in
den bereitgestellten Binärdateien nicht verfügbar. Diese Punkte verhindern die Behandlung dieses Inventars als
vollständiges, unabhängig zertifiziertes SBOM.

### Primärquellen

- [MediaInfo Umverteilungsbedingungen](https://mediaarea.net/en/MediaInfo/License)
- 
  [MediaInfo 26.10 Bibliotheksziel](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Project/MSVC2022/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 21.03 Bibliotheksziel](https://github.com/MediaArea/MediaInfoLib/blob/v21.03/Project/MSVC2015/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 0.7.60 Bibliotheksziel](https://github.com/MediaArea/MediaInfoLib/blob/v0.7.60/Project/MSVC2005/Library/MediaInfoLib.vcproj)
- 
  [Laufzeit-curl-Loader](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Source/MediaInfo/Reader/Reader_libcurl.cpp)
- 
  [Gebündelte Hilfsquellen und ihre Hinweise](https://github.com/MediaArea/MediaInfoLib/tree/v26.10/Source/ThirdParty)
- [ZenLib Hinweis](https://github.com/MediaArea/ZenLib/blob/master/License.txt)
- [zlib Quellenhinweise](https://github.com/madler/zlib/blob/v1.3.2/zlib.h)
- [curl 8.11.0 Hinweis](https://github.com/curl/curl/blob/curl-8_11_0/COPYING)
- [curl 7.47.1 Hinweis](https://github.com/curl/curl/blob/curl-7_47_1/COPYING)
- [Apache-Lizenz 2.0](https://www.apache.org/licenses/LICENSE-2.0)
- [MediaArea Base64 Beschreibung](https://github.com/MediaArea/MediaConch/blob/master/README.md)

Die Berichtstabellen stammen von
<https://github.com/MediaArea/MediaInfo/tree/v26.10/Source/Resource/Plugin/Language> . Das passende Projekt
LICENSE ist <https://github.com/MediaArea/MediaInfo/blob/v26.10/LICENSE> .

- [libwebp 1.1.0 COPYING](https://github.com/webmproject/libwebp/blob/v1.1.0/COPYING)
- [libwebp 1.1.0 PATENTS](https://github.com/webmproject/libwebp/blob/v1.1.0/PATENTS)
