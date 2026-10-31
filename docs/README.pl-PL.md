# MediaInfo Viewer

[Čeština](README.cs-CZ.md) | [English (US)](../README.md) | [English (UK)](README.en-GB.md) | [English (Australia)](README.en-AU.md) | [Deutsch](README.de-DE.md) | [Français](README.fr-FR.md) | [Español](README.es-ES.md) | [Italiano](README.it-IT.md) | [Português](README.pt-PT.md) | **Polski** | [Slovenčina](README.sk-SK.md) | [Dansk](README.da-DK.md) | [Suomi](README.fi-FI.md) | [Íslenska](README.is-IS.md) | [Norsk (bokmål)](README.nb-NO.md) | [Svenska](README.sv-SE.md) | [Türkçe](README.tr-TR.md) | [Eesti](README.et-EE.md) | [Gaeilge](README.ga-IE.md) | [Lietuvių](README.lt-LT.md) | [Latviešu](README.lv-LV.md) | [Magyar](README.hu-HU.md) | [Malti](README.mt-MT.md) | [Nederlands](README.nl-NL.md) | [Română](README.ro-RO.md) | [Ελληνικά](README.el-GR.md) | [Bosanski](README.bs-Latn-BA.md) | [Hrvatski](README.hr-HR.md) | [Slovenščina](README.sl-SI.md) | [Crnogorski](README.cnr-Latn-ME.md) | [Беларуская](README.be-BY.md) | [Български](README.bg-BG.md) | [Македонски](README.mk-MK.md) | [Српски](README.sr-Cyrl-RS.md) | [Українська](README.uk-UA.md) | [Русский](README.ru-RU.md)

Natywna przeglądarka raportów MediaInfo.dll dla Windows x86. Każdy plik ma własną kartę tylko do odczytu.

[Budowanie i zgodność](#kompilacja) | [Audyt zależności](#zależności) | [Licencja](../license.txt)

## Kompilacja

Otwórz MediaInfo.sln w Visual Studio 2015 z zainstalowanym zestawem narzędzi Visual C++ v140. Wybierz Release | Win32 i zbuduj rozwiązanie. Jedyną platformą aplikacji jest Win32 (x86).

Wyjścia:

- Release\MediaInfo.exe
- Debug\MediaInfo.exe

Przeglądarka nie łączy środowiska wykonawczego C ani C++ i nie potrzebuje redystrybucji MSVC. Wybrany
MediaInfo.dll może mieć własne zależności.

Budynek wymaga Windows PowerShell i .NET Framework. Są to wyłącznie wymagania dotyczące kompilacji; natywny
plik wykonywalny nie wymaga ani PowerShell, ani .NET.

### Pakiet dystrybucyjny

Po zbudowaniu Release uruchom `powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\PackageRelease.ps1` .
Skrypt tworzy `MediaInfo-<version>-win32.zip` w katalogu rozwiązania, używając czteroczęściowej wersji pliku
wykonywalnego. Archiwum zawiera `MediaInfo.exe` i połączone `license.txt` bezpośrednio w katalogu głównym.

## Zgodność

Przeglądarka Win32 jest przeznaczona do obsługi Windows NT 4.0 APIs.

Plik wykonywalny zawiera trzy biblioteki x86 MediaInfo: 26.10 dla bieżącego Windows, 21.03 z pakietu Windows
XP i 0.7.60 z pakietu Windows 95–2000. Sama architektura biblioteki nie określa jej zgodności z systemem
operacyjnym. Przeglądarka wypróbowuje dołączone biblioteki od najnowszej do najstarszej i zatrzymuje się po
pierwszym pomyślnym załadowaniu i zapytaniu o wersję.

Windows 95 nie jest obecnie obsługiwanym środowiskiem wykonawczym.

## Użytkowanie

- Plik > Otwórz (Ctrl+O) otwiera okno dialogowe pliku Windows z możliwością wielokrotnego wyboru. W Windows
  Vista i nowszych opcjach Otwórz i Zapisz używaj nowoczesnego okna dialogowego Common Item; starsze Windows
  używają starszych, wspólnych okien dialogowych.
- Przeciągnij co najmniej jeden plik do okna, na ikonę EXE lub jego skrót albo podaj ścieżki w wierszu
  polecenia. Jeśli wiele instancji jest wyłączone, pliki otworzą się w już uruchomionym oknie.
- Każda odrębna znormalizowana pełna ścieżka ma jedną kartę. Ponowne otwarcie już otwartego pliku powoduje
  wybranie istniejącej karty bez ponownego ładowania lub zmiany jego raportu, wyboru lub pozycji przewijania.
  Porównania ignorują wielkość liter ścieżki. Otwarcia wielu plików przetwarzają listę w kolejności i
  pozostawiają aktywny ostatni pomyślnie przetworzony plik, niezależnie od tego, czy jest on nowo otwarty, czy
  już otwarty. Najechanie kursorem na nagłówek karty powoduje wyświetlenie pełnej ścieżki pliku w natywnej
  podpowiedzi, także wtedy, gdy wyświetlana nazwa pliku jest skrócona.
- Menu Plik zawiera listę ośmiu ostatnio załadowanych plików bezpośrednio nad Wyjściem, pomiędzy separatorami.
  Wpisy pokazują tylko liczbę i nazwę pliku. Wybranie wpisu otwiera jego zapisaną pełną ścieżkę lub wybiera
  istniejącą kartę; pomyślne ponowne otwarcie przenosi go na górę bez duplikatów. Po wybraniu niedostępnego
  pliku pojawia się pytanie, czy usunąć wpis dotyczący ostatnich plików. Używana jest natywna ikona pytania i
  przyciski Yes/No. Tak jest ustawieniem domyślnym i usuwa wpis z menu i rejestru; Nie, zachowuje. Monit
  zawiera pełną ścieżkę.
- Kółko myszy nad przepełnionymi nagłówkami kart przewija pasek nagłówka o jedną kartę na wiadomość bez zmiany
  zaznaczenia lub fokusu.
- Ctrl+Tab i Ctrl+Shift+Tab przełączniki zakładek; Ctrl+W zamyka aktywną kartę. Kliknięcie środkowym
  przyciskiem nagłówka karty zamyka tę kartę, zachowując inne aktywne karty. Plik > Zamknij wszystko zamyka
  każdą kartę, łącznie z raportami umieszczonymi w kolejce. Plik > Wyjdź (Alt+F4) zamyka aplikację.
- Podwójne kliknięcie zaznacza słowo. Potrójne kliknięcie wybiera linię logiczną. Przeciąganie rozszerza
  zaznaczenie o słowa lub linie.
- Ctrl+A wybiera raport; Ctrl+C kopiuje to.
- Ustawienia > Preferencje (Ctrl+G) otwiera pojedyncze okno dialogowe preferencji dla ścieżek MediaInfo i
  curl, czcionki raportu, wygładzania czcionek, języka interfejsu i języka raportów. Pusta ścieżka DLL
  umożliwia automatyczne wykrywanie.
- Przycisk czcionki wyświetla rodzinę, rozmiar czcionki i styl oraz otwiera standardowe okno dialogowe
  czcionki Windows. Domyślnie przywraca Consolas lub Courier New, jeśli Consolas jest niedostępne; przycisk
  Domyślne jest wyłączony, gdy wybrane jest ustawienie domyślne. Czcionki wybrane przez użytkownika są
  zachowywane bez zastępowania przez kod aplikacji.
- Opcje wygładzania czcionek to ClearType, jeśli jest obsługiwane, GDI i Brak. Początkowy wybór to ClearType,
  jeśli jest obsługiwany, w przeciwnym razie GDI. Ustawienia czcionek wpływają tylko na raporty multimedialne
  i eksport ich obrazów.
- Plik > Eksportuj (Ctrl+E) otwiera okno dialogowe Windows Zapisz jako i eksportuje cały aktywny raport do
  TXT, BMP, GIF, JPEG, PNG, TIFF lub WebP, łącznie z tekstem poza widocznym obszarem.
- Pomoc otwiera oddzielne, niemodalne okno z własnym wpisem na pasku zadań i przyciskiem minimalizacji.
  Informacje to modalne okno dialogowe; w nagłówku produktu znajdują się wszystkie trzy osadzone wersje DLL.

Drukuj… (Ctrl+P) otwiera systemowe okno wyboru drukarki i drukuje całą aktywną kartę bez podglądu. Używana
jest czcionka raportu; długie wiersze są zawijane, a tekst dzielony na strony. Drukowanie odbywa się w tle.

Otwórz folder… otwiera pliki znajdujące się bezpośrednio w wybranym folderze, każdy na osobnej karcie.
Podfoldery nie są uwzględniane. Otwórz i Otwórz folder korzystają wspólnie z ostatnio wybranego folderu.
Eksport zapamiętuje osobny folder, domyślnie Dokumenty.

Tryb zaawansowany pokazuje dodatkowe pola raportu.

Pełna analiza sprawdza cały plik, co może potrwać dłużej. Te opcje raportu i Poziom śledzenia należą do każdej
karty; zmiana odświeża tylko aktywną kartę. Ostatnia ręcznie wybrana kombinacja jest zapisywana dla nowych
kart i następnego uruchomienia. Pasujący raport z pamięci podręcznej jest ponownie używany, dopóki plik
pozostaje niezmieniony.

Znane formaty, Znane kodeki i Znane parametry otwierają się na osobnych kartach raportu.

Początkowy rozmiar i położenie okna są wybierane przez Windows. Wcześniej zapisane rozmieszczenie okien
zastępuje ustawienia domyślne przy późniejszych uruchomieniach.

Lewa część paska stanu pokazuje ścieżki plików i postęp ładowania, a prawa wersję załadowanej biblioteki
MediaInfo.dll. Długie ścieżki są skracane wielokropkiem stosownie do dostępnego miejsca.

## Utwórz plik nagłówka

Menu Narzędzia jest trzecim menu na pasku menu. Polecenie Utwórz plik nagłówka… otwiera jeden plik źródłowy
niezależnie od kart raportów i kopiuje jego pierwsze 524288 bajtów (512 KiB). Krótszy plik jest kopiowany w
całości; pusty plik generuje puste dane wyjściowe. Jest to zwykły odczyt pliku binarnego, bez analizy
MediaInfo ani konieczności używania MediaInfo.dll. Narzędzie pozostawia karty raportów i listę ostatnich
plików przeglądarki bez zmian.

Po przeczytaniu w folderze pliku źródłowego otworzy się okno dialogowe Zapisz jako, które zaproponuje nazwę
video.mp4.header dla video.mp4: .header jest dołączany do pełnej oryginalnej nazwy. Można zmienić zarówno
nazwę, jak i folder docelowy. Anulowanie któregokolwiek okna dialogowego nie powoduje zapisywania danych
wyjściowych. Zastąpienie istniejącego miejsca docelowego wymaga potwierdzenia. Plik źródłowy pozostaje
niezmienione; nieudane zapisanie powoduje zachowanie poprzedniego miejsca docelowego. Do otwierania i
zapisywania używane są najnowsze systemowe okna dialogowe dostępne w danej wersji systemu Windows.

Podczas uruchamiania aplikacji narzędzie pobiera początkowy folder wejściowy z Plik > Otwórz. Jeśli żaden
folder nie został zapisany, system Windows wybiera początkową lokalizację. Po wybraniu pliku wejściowego
narzędzie zapamiętuje swój własny folder tylko do momentu zakończenia działania aplikacji, nawet jeśli opcja
Zapisz jako została anulowana. Nie zmienia folderów używanych przez Otwórz i Eksportuj ani nie zapisuje
własnego folderu w ustawieniach aplikacji. Każde okno dialogowe Zapisz jako rozpoczyna się w folderze
aktualnie wybranego pliku wejściowego, niezależnie od miejsca docelowego poprzedniego zapisu.

## Wyszukiwanie bibliotek

Najpierw wypróbowywana jest zapisana ścieżka ręczna. Jeśli nie można go załadować, automatyczne wykrywanie
próbuje:

1. MediaInfo.dll obok pliku wykonywalnego, następnie w każdym katalogu nadrzędnym aż do katalogu głównego
   dysku lub UNC udziału.
2. ProgramFiles, ProgramFiles(x86) i ProgramW6432.
3. LOCALAPPDATA i APPDATA.

W tych katalogach głównych instalacji wykrywanie sprawdza MediaInfo, MediaArea\MediaInfo, MediaArea,
MediaArea.net\MediaInfo, Programs\MediaInfo, Programs\MediaArea\MediaInfo. Pomijane są nieczytelne lokalizacje
i niezgodne DLLs. Nie skanuje rekurencyjnie dysku.

Jeśli nie zostanie znaleziony żaden kompatybilny zewnętrzny DLL, przeglądarka wypróbuje osadzone wersje w
następującej kolejności: 26.10, 21.03, 0.7.60. Wyodrębnia i testuje jedną wersję na raz. Po pomyślnym
załadowaniu wersji starsze wersje nie są wyodrębniane ani testowane. Samo rozpowszechnianie MediaInfo.exe jest
wystarczające; kompatybilny zewnętrzny DLL zawsze ma pierwszeństwo i może być aktualizowany niezależnie.

Nieudana ręczna zmiana biblioteki powoduje zachowanie biblioteki, która została już załadowana.

## Eksport raportów

Formaty Zapisz jako są uporządkowane w kolejności TXT, BMP, GIF, JPEG, PNG, TIFF i WebP. Nieobsługiwane kodery
są pomijane zarówno w nowoczesnych, jak i starszych oknach dialogowych.

TXT oferuje ANSI, UTF-8, UTF-8 z BOM, UTF-16 BE z BOM i UTF-16 LE z BOM. Domyślna jest druga pozycja, UTF-8
bez BOM. Pełny tekst raportu i jego oryginalne zakończenia wierszy są zachowane.

BMP, PNG i TIFF zachowują wszystkie renderowane kolory; GIF89a zachowuje dokładnie renderowaną paletę, gdy
obraz ma co najwyżej 256 kolorów. Eksport zawsze zapisuje wybrany format lub zgłasza błąd; nigdy nie zastępuje
innego formatu.

Obrazy zawierają pełny raport w wybranej czcionce raportu, z czarnym tekstem na białym tle. Nie zawierają menu
aplikacji, nagłówków zakładek, paska stanu, zaznaczenia ani karetki. Renderowanie jest niezależne od pozycji
przewijania pola tekstowego.

Aby uniknąć cichego obcinania raportów lub wyczerpania przestrzeni adresowej na starszych komputerach,
pojedynczy obraz jest ograniczony do 16 384 szerokości pikseli, 32 767 wysokości pikseli i 256 MiB
nieskompresowanej pamięci bitmapowej. Jeśli raport przekracza te limity, wybierz mniejszą czcionkę.

`Google WebP (*.webp)` jest ostatnim formatem i zapisuje raport bezstratnie.

WebP: 16383 × 16383 px.

## Języki interfejsu i raportów

Preferencje (Ustawienia > Preferencje, Ctrl+G) zawierają ścieżki bibliotek, czcionkę raportu, wygładzanie i
języki. Interfejs ma 36 wariantów i początkowo korzysta z języka Windows. Raporty zawsze domyślnie używają
oryginalnego angielskiego biblioteki, niezależnie od Windows i interfejsu. Zmienia to wyłącznie ręczny wybór:
angielski, 37 tłumaczeń lub własna tabela CSV MediaInfo.

OK lub Zastosuj zatwierdza zmiany; Anuluj odrzuca oczekujące zmiany. Preferencje pozwalają ustawić limit
długości nazwy karty (domyślnie 80 znaków) i wyczyścić listę ostatnich plików. Długie nazwy zachowują
początek, koniec i rozszerzenie, z wielokropkiem pośrodku.

Domyślnie dozwolona jest tylko jedna instancja, a kolejne uruchomienia przekazują pliki do otwartego okna. W
ustawieniach można zezwolić na wiele instancji. Przy wielu oknach tylko pierwsze okno każdego formularza
przywraca zapisaną pozycję; następne przywracają jedynie rozmiar.

Zmiana samego interfejsu pozostawia tekst otwartych raportów bez zmian. Ręcznie zastosowana zmiana języka
raportów powoduje ponowne załadowanie raportów, zachowując kolejność tabulacji i kolejność MRU.

## libcurl

Automatyczne wykrywanie curl sprawdza obok wybranych MediaInfo DLL, następnie współdzielonych
executable/ancestor, plików programów i lokalizacji instalacji użytkownika. Jeśli nie zostanie znaleziony
żaden kompatybilny zewnętrzny curl, pasująca osadzona wersja bieżąca lub XP zostanie wyodrębniona do
sprawdzanej pamięci podręcznej poszczególnych użytkowników. Najstarszy MediaInfo 0.7.60 całkowicie omija
wykrywanie, wyodrębnianie i ładowanie curl. Wyraźnie wybrany nieprawidłowy curl odrzuca zmianę preferencji;
brak opcjonalnego automatycznego curl nie uniemożliwia zwykłych raportów w pliku lokalnym.

## Nazwy plików i ostatnio używane pliki

Nazwy plików MRU są skracane tylko wtedy, gdy są dłuższe niż 80 UTF-16 jednostek kodu. Środkowy elipsa
zachowuje początek, koniec nazwy pliku przed jego rozszerzeniem oraz całe końcowe rozszerzenie; pełne ścieżki
i raporty pozostają niezmienione. Podpisy zakładek korzystają z tego samego algorytmu z konfigurowalnym
domyślnym limitem wynoszącym 80.

Ostatnie pliki > Wyczyść natychmiast czyści zarówno aktywne menu MRU, jak i zapisane w nim ścieżki,
pozostawiając wszystkie otwarte karty nienaruszone. Nie stosuje ani nie sprawdza oczekujących preferencji i
nie umożliwia zastosowania. Anuluj lub Escape zachowuje wyczyszczoną historię, odrzucając oczekujące zmiany.
Opcja Clear jest wyłączona, gdy lista jest pusta, a jej stan jest odświeżany, gdy na liście pojawiają się nowe
raporty. Błąd zapisu do rejestru jest natychmiast zgłaszany. Zastosowanie nowego limitu nazw kart aktualizuje
każdą otwartą kartę bez ponownego ładowania jej raportu o multimediach.

## Licencja i redystrybucja

Przeglądarka jest objęta licencją MIT Licencja w license.txt.

MediaInfo to komponent innej firmy. Jedyną utrzymywaną informacją o dystrybucji jest root license.txt,
zakodowany jako UTF-8 z CRLF i obejmujący przeglądarkę, biblioteki, statycznie wbudowane komponenty, ikonę i
oficjalne tabele tłumaczeń.

Ten produkt korzysta z biblioteki MediaInfo, Copyright (c) 2002-2026 MediaArea.net SARL.

- MediaInfo: <https://mediaarea.net/MediaInfo>
- Licencja: <https://mediaarea.net/en/MediaInfo/License>
- Windows pliki do pobrania: <https://mediaarea.net/en/MediaInfo/Download/Windows>

## Zależności

### Pliki

| Ratunek | Architektura | Wersja zgłoszona przez komponent | SHA-256 |
| --- | --- | --- | --- |
| Resources/lib/26.10/MediaInfo.dll | x86 | 26.10 | E73027A1577084135425AA013D46C8B2985AD142CCF04F1ADB301B9A9CFB78F8 |
| Resources/lib/21.03/MediaInfo.dll | x86 | 21.03 | EBBF1C371702F3DC39CA23D619C47EDF97E66A95AEABE725284F1402D8F3E58A |
| Resources/lib/0.7.60/MediaInfo.dll | x86 | 0.7.60 | A26C07BCC25FA01A40E6888D02EABD59AA8DB2ABF6F5195481228D3A91D04441 |
| Resources/lib/26.10/libcurl.dll | x86 | 8.11.0-DEV, Schannel, zlib 1.3.1 | DCF136C84F3A4FBEAE2B317FE36D7F11225B56FBA3343AF4BBA8706B3F46F334 |
| Resources/lib/21.03/libcurl.dll | x86 | 7.47.1, WinSSL, zlib 1.2.8 | 21025CAC8089F1E570EE083D8CFD6311C2C51E97094A9FCD8C7A0B544C22CB48 |
| Resources/lib/libwebp.dll | x86 | 1.1.0 | 9986023BB6FF5510A157919F0CD958A94800EC6A1D981F3403A9648BEDFEE575 |

Ścieżki w tabeli są względne wobec katalogu projektu MediaInfo.

Obecna biblioteka zgłasza wersję rozwojową; jego dokładnego źródła commit nie można odzyskać z ciągu tej
wersji. Załączona informacja wykorzystuje tekst dotyczący praw autorskich i zezwoleń firmy 8.11.0, których
warunki licencyjne są również obecne w serii rozwojowej.

### Wbudowane komponenty

| Część | Dowody i zakres | Ogłoszenie |
| --- | --- | --- |
| MediaInfoLib | Aktualne wersje i wymagane eksporty Unicode; niezmienione dostarczone pliki binarne | Oryginalne prawa autorskie specyficzne dla wersji, warunki redystrybucji i zastrzeżenie |
| ZenLib | Statyczne odniesienia do projektów i osadzone ZenLib RTTI we wszystkich trzech DLLs; dokładne powiązane wersje nie zostały dostarczone | Powiadomienie w stylu zlib ZenLib |
| zlib | Wbudowane ciągi wersji inflate/deflate: 1.3.2 w MediaInfo 26.10, 1.2.11 w 21.03, 1.2.7 w 0.7.60; curl dodatkowo raportuje 1.3.1 i 1.2.8 | Oryginalne uwagi zlib dla wszystkich pięciu wersji |
| TinyXML-2 | Dopasowywanie nowoczesnych celów źródłowych i plików binarnych RTTI; uwzględnione w starszym projekcie, ale nie zidentyfikowane niezależnie w usuniętym starszym pliku binarnym | Zachowano oryginalną notatkę w stylu Lee Thomason zlib |
| Brian Gladman AES | Zawarte w obu nowoczesnych obiektach docelowych bibliotek nadrzędnych, z pasującymi informacjami o źródle zezwalającym | 1998–2013 powiadomienie o redystrybucji i zastrzeżenie |
| Brian Gladman SHA-1/SHA-2 | Oba nowoczesne cele; Tabele stałych SHA-256 i SHA-512 obecne w obu nowoczesnych plikach binarnych | 1998–2010 powiadomienie o redystrybucji i zastrzeżenie |
| Brian Gladman HMAC | Zarówno współczesne cele, jak i ich kod czytnika curl/S3 | Oryginalne powiadomienie zawierające trzy warunki, w tym akapit dotyczący licencji alternatywnej |
| MD5 | Nowoczesne cele źródłowe; Implementacja Colin Plumb wyraźnie stwierdza domenę publiczną | Uznanie autorstwa zachowane |
| Base64 | Nagłówek Markus Ewald we wszystkich trzech odpowiednich drzewach źródłowych, przypisując Bob Withers | Zachowano oryginalne uznanie autorstwa; kwalifikacja poniżej |
| fmt | 26.10 cel i fmt v11 format_error RTTI w formacie binarnym | Oryginalne powiadomienie MIT, zawierające opcjonalny wyjątek |
| tfsxml | 26.10 cel źródłowy | Oryginał zawiadomienia MediaArea MIT |
| Interfejs Androida JNI | JNI_OnLoad jest faktycznie eksportowany zarówno przez nowoczesne DLLs; dołączony nagłówek JNI pochodzi z AOSP | AOSP prawa autorskie i pełna licencja Apache 2.0 |
| libcurl | Dostarczone pliki binarne x86; eksport wersji rzeczywistej; dynamicznie używany przez współczesne MediaInfo | Oryginalne powiadomienia curl dla 8.11.0 i 7.47.1 |
| Oficjalne tłumaczenia raportów | Wszystkie 38 niezmodyfikowane źródła CSV z katalogu językowego MediaInfo v26.10; Osadzone są tabele 37 w języku innym niż angielski, podczas gdy w języku angielskim używane są ustawienia domyślne DLL | Powiadomienie o tym samym projekcie BSD-2-Clause zachowane w połączonym powiadomieniu |
| Ikona MediaInfo | Niezmodyfikowana oficjalna ikona wielu obrazów, wersja źródłowa f057dd3649bc8692a83863b67770e22c9b9dd81a | Oryginalna uwaga i przypisanie BSD-2-Clause |
| libwebp | WebPEncodeLosslessBGRA, WebPFree; 1.1.0; x86 | BSD-3-Clause; PATENTS |

Pasujące cele źródłowe ustanawiają włączenie do tych konfiguracji kompilacji nadrzędnej; nie dowodzą, że każda
funkcja przetrwa optymalizację w plikach binarnych dostawcy. Nie ma roszczeń dotyczących dokładnej wersji
zależności, których wersja nie jest zapisana w tych plikach binarnych.

### Opcjonalne komponenty i biblioteki systemowe

- Projekty bibliotek Windows umożliwiają załadowanie w czasie wykonywania libcurl dla MediaInfo 26.10 i 21.03.
  MediaInfo 0.7.60 został zbudowany z MEDIAINFO_LIBCURL_NO; jego plik binarny zawiera również diagnostykę
  wyłączonej obsługi. Przeglądarka nigdy nie odkrywa, nie wyodrębnia ani nie ładuje curl dla tej wersji
  dołączonej.
- libmms jest wyłączony we wszystkich trzech dostarczonych Windows DLLs, co potwierdzają wbudowane komunikaty
  o obsłudze osób niepełnosprawnych. Nie jest redystrybuowany.
- Qt i wxWidgets należą do opcjonalnych kompilacji GUI. Żadne z nich nie jest uwzględnione w tej przeglądarce
  ani w tych zależnościach DLL. Ich ogólne wpisy zostały usunięte z wyświetlanej licencji.
- Graphviz to opcjonalny element wykonawczy w nowoczesnym kodzie nadrzędnym. Żadne Graphviz DLL nie jest
  redystrybuowane.
- Żadna wtyczka FFmpeg nie jest redystrybuowana.
- MediaInfo DLLs bezpośrednio importuje tylko KERNEL32.dll. Nie oznacza to, że nie ma ich statycznie
  połączonego środowiska wykonawczego i kodu pomocniczego.
- Obecny curl bezpośrednio importuje WS2_32.dll, bcrypt.dll, ADVAPI32.dll, CRYPT32.dll i KERNEL32.dll. XP curl
  bezpośrednio importuje WS2_32.dll, WLDAP32.dll, ADVAPI32.dll i KERNEL32.dll. Są to komponenty Windows. Ich
  dostępność sprawdza moduł ładujący Windows.
- Raporty Curl Windows Schannel/WinSSL, a nie kompilacja OpenSSL. Zgłaszana przez niego dodatkowa zależność od
  kompresji jest statycznie uwzględniona zlib. W tabeli importu bezpośredniego nie pojawiają się żadne
  dodatkowe zewnętrzne dane inne niż Windows DLL.
- Sama przeglądarka nie jest zależna od środowiska wykonawczego C/C++. Dostarczone DLLs strony trzeciej
  zawierają własne skompilowane fragmenty środowiska wykonawczego. Kompilacje Windows wykorzystują narzędzia
  Microsoft; nie ma dowodów wymagających ogólnych wpisów inwentarza libstdc++ lub libc++.
- JPEG korzysta z dynamicznie ładowanego systemu GDI+. Paker zasobów C# i PowerShell są narzędziami do
  kompilacji i nie są zależnościami środowiska wykonawczego.

Zwykła inspekcja plików lokalnych nie wymaga serwera MediaArea ani zdalnie pobieranej bazy danych w formacie.
libcurl jest używany przez MediaInfo dla danych wejściowych URL i potencjalnie zdalnych odniesień w
obsługiwanych formatach multimediów. Pakowanie nie powoduje dodania osobnego polecenia otwierającego URL do
tej przeglądarki.

### Przechowywanie licencji i ograniczenia

Jedynym utrzymywanym powiadomieniem o dystrybucji jest [license.txt](../license.txt) , zakodowany jako UTF-8 z
CRLF. Sprawdzone klauzule redystrybucyjne BSD, curl, zlib, MIT i Apache nie wymagają fizycznego oddzielnego
pliku powiadomień obok każdego DLL; połączone powiadomienie towarzyszy im w materiałach wykonywalnych i
dystrybucyjnych.

Zarchiwizowany pakiet MediaInfo 0.7.60 korzysta z własnej licencji specyficznej dla wersji i zawiera stary
tekst GNU Library GPL. Jego warunki wyraźnie odróżniają niezmodyfikowaną redystrybucję binarną od wersji
zmodyfikowanych; dynamiczne łączenie przez tę przeglądarkę nie modyfikuje dostarczonego DLL. Oryginalne
warunki i towarzyszący im tekst licencji zostają zachowane. Przeglądarka posiada licencję MIT.

Jedno z przypisań wymaga kwalifikacji: nagłówek Markus Ewald Base64 nie zawiera wyraźnego pozwolenia ani
oświadczenia licencyjnego. MediaArea opisuje implementację Bob Withers Base64 jako domenę publiczną w
powiązanej dokumentacji MediaConch, ale nie określa to niezależnie udzielenia licencji dla każdej zmiany
Ewalda. Dla tego nagłówka nie wymyślono żadnego udzielenia licencji. Pełne potwierdzenie dostawcy dotyczące
tego pochodzenia, dokładnych wersji ZenLib i rozwoju curl commit nie było dostępne w dostarczonych plikach
binarnych. Punkty te uniemożliwiają traktowanie tego inwentarza jako kompletnego, niezależnie certyfikowanego
SBOM.

### Źródła pierwotne

- [MediaInfo warunki redystrybucji](https://mediaarea.net/en/MediaInfo/License)
- 
  [MediaInfo 26.10 cel biblioteki](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Project/MSVC2022/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 21.03 cel biblioteki](https://github.com/MediaArea/MediaInfoLib/blob/v21.03/Project/MSVC2015/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 0.7.60 cel biblioteki](https://github.com/MediaArea/MediaInfoLib/blob/v0.7.60/Project/MSVC2005/Library/MediaInfoLib.vcproj)
- 
  [Środowisko wykonawcze curl modułu ładującego](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Source/MediaInfo/Reader/Reader_libcurl.cpp)
- 
  [Dołączone źródła pomocy i ich powiadomienia](https://github.com/MediaArea/MediaInfoLib/tree/v26.10/Source/ThirdParty)
- [ZenLib powiadomienie](https://github.com/MediaArea/ZenLib/blob/master/License.txt)
- [zlib uwagi o źródle](https://github.com/madler/zlib/blob/v1.3.2/zlib.h)
- [curl 8.11.0 powiadomienie](https://github.com/curl/curl/blob/curl-8_11_0/COPYING)
- [curl 7.47.1 powiadomienie](https://github.com/curl/curl/blob/curl-7_47_1/COPYING)
- [Licencja Apache 2.0](https://www.apache.org/licenses/LICENSE-2.0)
- [MediaArea Base64 opis](https://github.com/MediaArea/MediaConch/blob/master/README.md)

Tabele raportów pochodzą z
<https://github.com/MediaArea/MediaInfo/tree/v26.10/Source/Resource/Plugin/Language> . Pasujący projekt
LICENSE to <https://github.com/MediaArea/MediaInfo/blob/v26.10/LICENSE> .

- [libwebp 1.1.0 COPYING](https://github.com/webmproject/libwebp/blob/v1.1.0/COPYING)
- [libwebp 1.1.0 PATENTS](https://github.com/webmproject/libwebp/blob/v1.1.0/PATENTS)
