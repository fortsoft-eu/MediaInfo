/**
 * This is open-source software licensed under the terms of the MIT License.
 *
 * Copyright (c) 2026 Petr Červinka - FortSoft <cervinka@fortsoft.eu>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **
 * Last modified for version 1.2.1.7
 */

#include "Localization.h"
#include "ReportLanguageData.inc"

/// Stores the complete interface catalog as static read-only data.
static const LocalizedLanguage localizedLanguages[] = {
    {
        LANG_CS,
        {
            { TXT_LANGUAGE_NAME, L"Čeština" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nWeb: " },
            { TXT_FILE_OPEN_FAILED, L"Nelze otevřít %s. Zkontrolujte cestu a oprávnění." },
            { TXT_BROWSE_DLL, L"Proch&ázet…" },
            { TXT_BROWSE_REPORT, L"Procháze&t…" },
            { TXT_CLOSE, L"&Zavřít" },
            { TXT_CLOSE_TAB, L"&Zavřít\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"Výc&hozí" },
            { TXT_EXPORT, L"&Exportovat…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Soubor" },
            { TXT_REPORT_FONT, L"&Písmo reportu:" },
            { TXT_HELP_MENU, L"&Nápověda" },
            { TXT_HELP, L"&Nápověda\tF1" },
            { TXT_LANGUAGE, L"&Jazyk:" },
            { TXT_OPEN_WEBSITE, L"&Otevřít ve výchozím prohlížeči" },
            { TXT_OPEN, L"&Otevřít…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Možnosti" },
            { TXT_PREFERENCES_MENU, L"&Předvolby…\tCtrl+G" },
            { TXT_ABOUT, L"&O programu" },
            { TXT_ABOUT_TITLE, L"O programu %ls" },
            { TXT_ALL_FILES, L"Všechny soubory" },
            { TXT_FONT_BOLD, L"Tučné" },
            { TXT_FONT_BOLD_ITALIC, L"Tučná kurzíva" },
            { TXT_BROWSE_CURL, L"Procház&et…" },
            { TXT_CANCEL, L"Zrušit" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Nelze načíst MediaInfo.dll (chyba Windows %lu). Použijte 32bitovou DLL kompatibilní s "
                L"touto verzí Windows."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Nelze načíst libcurl.dll (chyba Windows %lu). Vyberte 32bitovou knihovnu kompatibilní s "
                L"touto verzí Windows."
            },
            { TXT_CLOSE_ALL, L"Zavřít &vše" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Kopírovat &adresu" },
            { TXT_COPY_INFORMATION, L"Kopírovat &informace" },
            { TXT_DLL_FILES, L"Dynamické knihovny" },
            { TXT_EXIT, L"&Konec\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Vložené knihovny MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Vložené knihovny libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Exportovat report" },
            { TXT_FONT_ANTIALIASING, L"Vyhlazování pís&ma:" },
            { TXT_GIF_EXPORT_FAILED, L"Export GIF selhal. Přesný výstup GIF vyžaduje nejvýše 256 barev." },
            { TXT_FONT_ITALIC, L"Kurzíva" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED, L"Export JPEG selhal. Je nutný funkční kodér JPEG systému GDI+." },
            { TXT_LICENSE_UNAVAILABLE, L"Licenční prostředek není dostupný." },
            { TXT_MEDIA_FILES, L"Multimediální soubory" },
            { TXT_APPLICATION_DESCRIPTION, L"Prohlížeč informací o médiích" },
            { TXT_HELP_TITLE, L"MediaInfo — Nápověda" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo nemůže inicializovat analýzu souboru." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo nemůže otevřít nebo rozpoznat tento soubor." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"&Cesta k MediaInfo.dll:" },
            { TXT_MEDIALIB_REQUIRED,
                L"MediaInfo.dll není načtena. Vyberte ji v nabídce Možnosti > Předvolby."
            },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll není načtena." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Nelze načíst žádnou kompatibilní externí ani vloženou MediaInfo.dll. Vyberte ji v nabídce "
                L"Možnosti > Předvolby."
            },
            { TXT_ANTIALIASING_NONE, L"Žádné" },
            { TXT_OK, L"OK" },
            { TXT_OPEN_TITLE, L"Otevřít multimediální soubory" },
            { TXT_PLATFORM, L"Cílová platforma:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Předvolby" },
            { TXT_READY, L"Připraven" },
            { TXT_FONT_REGULAR, L"Normální" },
            { TXT_REPORT_LANGUAGE, L"Jazyk &reportu:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Jazykové tabulky reportu" },
            { TXT_SELECT_MEDIALIB, L"Vybrat: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Vybrat: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH,
                L"Vyberte existující multimediální soubor s cestou kratší než MAX_PATH."
            },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Vyberte soubory s cestami kratšími než MAX_PATH." },
            { TXT_SELECT_CURL, L"Vybrat: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Textový dokument ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"Obrázek BMP nelze uložit. Zkontrolujte cíl, volnou paměť a místo na disku."
            },
            { TXT_LIBRARY_WORKER_START_FAILED, L"Proces knihovny nelze spustit (chyba Windows %lu)." },
            { TXT_REPORT_COPY_FAILED, L"Report MediaInfo nelze zkopírovat do paměti." },
            { TXT_VIEWER_CREATE_FAILED, L"Prohlížeč MediaInfo nelze vytvořit." },
            { TXT_MEDIALIB_PATH_INVALID, L"Cesta k MediaInfo.dll je neplatná nebo příliš dlouhá." },
            { TXT_PNG_EXPORT_FAILED,
                L"Obrázek PNG nelze uložit. Zkontrolujte cíl, volnou paměť a místo na disku."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"Obrázek TIFF nelze uložit. Zkontrolujte cíl, volnou paměť a místo na disku."
            },
            { TXT_COPY_URL_FAILED, L"Adresu URL nelze zkopírovat do schránky." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"Prohlížeč Win32 vyžaduje 32bitovou %s. Vyberte knihovnu x86/i386."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Vloženou knihovnu nelze zapsat do AppData, profilu uživatele, Program Files ani dočasné "
                L"složky."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED, L"Dekomprese knihovny nebo kontrola CRC selhala." },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Prostředek vložené knihovny je neplatný." },
            { TXT_CURL_FILENAME_INVALID,
                L"Knihovna se musí jmenovat libcurl.dll, aby ji MediaInfo mohla používat."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Dialog pro výběr souborů nelze otevřít." },
            { TXT_FILE_DIALOG_SELECTION_FAILED,
                L"Z dialogu pro výběr souborů nelze získat vybrané soubory."
            },
            { TXT_RECENT_FILE_MISSING,
                L"Soubor „%s“ již neexistuje.\n\nOdebrat položku ze seznamu posledních souborů?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Soubor již není dostupný:\n\n%s\n\nOdebrat položku ze seznamu posledních souborů?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Informace nelze zkopírovat do schránky." },
            { TXT_CURL_PATH_INVALID, L"Cesta k libcurl.dll je neplatná nebo příliš dlouhá." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Knihovna nevrátila verzi MediaInfo." },
            { TXT_CURL_EXPORTS_MISSING, L"Knihovna neexportuje funkce curl požadované knihovnou MediaInfo." },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"Knihovna neexportuje požadované funkce Unicode knihovny MediaInfo."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Proces knihovny selhal při %s (kód 0x%08lX). Vyberte kompatibilní DLL v nabídce Možnosti "
                L"> Předvolby."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Proces knihovny přestal odpovídat při %s. Vyberte kompatibilní DLL v nabídce Možnosti > "
                L"Předvolby."
            },
            { TXT_PREFERENCES_SAVE_FAILED,
                L"Nastavení bylo použito, ale nepodařilo se je uložit do registru."
            },
            { TXT_REPORT_START_FAILED, L"Pro spuštění reportu není dostatek paměti." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Obrázek reportu nelze vytvořit." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Jazykovou tabulku nelze načíst. Vyberte platný soubor "
                L"MediaInfo CSV v UTF-8 nebo UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"Vlákno reportu nelze spustit." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"Vybraná MediaInfo.dll odmítla jazyk reportu." },
            { TXT_INVALID_WINDOWS_DLL, L"Vybraný soubor není platná knihovna DLL systému Windows." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Vybraný formát obrázku není podporován." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Textový report nelze uložit. Zkontrolujte cíl a volné místo na disku."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Web nelze otevřít ve výchozím prohlížeči." },
            { TXT_TOO_MANY_FILES, L"Bylo vybráno příliš mnoho souborů. Otevírejte menší skupiny." },
            { TXT_LIBRARY_PATH_HINT,
                L"Použijte 32bitové knihovny kompatibilní s vaší verzí Windows. Ponechejte cesty prázdné pro "
                L"automatické vyhledávání. MediaInfoLib v0.7.60 nepoužívá libcurl.dll."
            },
            { TXT_VERSION, L"Verze" },
            { TXT_WEBSITE_TOOLTIP, L"Navštívit web %s" },
            { TXT_WAITING_FOR_REPORT, L"Čeká se na dokončení aktuálního reportu." },
            { TXT_WEBSITE_LABEL, L"Web:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"kopírování reportu MediaInfo" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"Ce&sta k libcurl.dll:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"načítání MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"načítání libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"uvolňování MediaInfo.dll" },
            { TXT_APPLY, L"P&oužít" },
            { TXT_TAB_NAME_LENGTH, L"Délka názvu &karty:" },
            { TXT_TITLE_NAME_LENGTH, L"Délka názvu záhla&ví:" },
            { TXT_RECENT_FILES, L"Poslední soubory:" },
            { TXT_CLEAR_RECENT_FILES, L"Vyma&zat" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"Délka názvu karty musí být mezi 8 a 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"Délka názvu v záhlaví musí být mezi 8 a 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Seznam posledních souborů byl vymazán, ale nepodařilo se jej uložit do registru."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"Zavírat karty &dvojklikem" },
            { TXT_CLOSE_TAB_CONTEXT, L"Zavřít &kartu" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"Povo&lit více instancí" },
            { TXT_INSTANCE_FORWARD_FAILED, L"Soubory se nepodařilo předat spuštěné instanci MediaInfo." },
            { TXT_LOADING, L"Načítání…" },
            { TXT_LOADING_FILE, L"Načítání souboru %s…" },
            { TXT_APPLICATION_HELP,
                L"SOUBORY A KARTY\r\nNativní prohlížeč reportů MediaInfo.dll pro Windows x86. Každý "
                L"soubor má vlastní kartu pouze pro čtení. Soubory otevřete pomocí Ctrl+O nebo "
                L"přetažením. Opakované otevření vybere existující kartu. Ctrl+W nebo prostřední tlačítko "
                L"myši kartu zavře; Zavřít vše zavře všechny karty. Nabídka Soubor uchovává osm "
                L"posledních souborů. Kontextová nabídka záhlaví karty obsahuje příkaz Zavřít kartu. "
                L"Volba Zavírat karty dvojklikem v Předvolbách umožní zavírání dvojklikem na záhlaví. Ve "
                L"výchozím stavu je vypnutá a její nastavení se ukládá. Dvojklik v textu reportu vybere "
                L"slovo. Trojklik vybere logický řádek. Tažení rozšiřuje výběr po slovech nebo "
                L"řádcích.\r\nOtevřít složku… otevře soubory přímo ve vybrané složce, každý ve vlastní "
                L"kartě. Podsložky se neprocházejí.\r\nOtevřít a Otevřít složku sdílejí naposledy "
                L"zvolenou složku. Export si pamatuje vlastní složku, výchozí jsou Dokumenty. Pokročilý "
                L"režim zobrazí další údaje v reportu.\r\nZnámé formáty / Známé kodeky / Známé parametry "
                L"— MediaInfo.dll.\r\nÚplná analýza prozkoumá celý soubor a může trvat déle. Tyto volby "
                L"reportu a Úroveň trasování patří jednotlivým kartám; změna obnoví pouze aktivní kartu. "
                L"Poslední ručně zvolená kombinace se uloží pro nové karty a další spuštění. Již získaný "
                L"report pro stejnou kombinaci se použije znovu, pokud se soubor nezměnil.\r\nÚroveň "
                L"trasování: 0 / 5 / 9 / 10.\r\nSoubor > Vzhled stránky… otevře nastavení papíru, "
                L"orientace a okrajů pro aktuální spuštění aplikace. Tisk… (Ctrl+P) otevře systémový "
                L"tiskový dialog; Windows 11 poskytují náhled, Windows 10 a starší zachovávají klasický "
                L"dialog. Ctrl+P vytiskne aktivní kartu hlavního okna, nebo textovou oblast Nápovědy či O "
                L"programu podle toho, které okno má fokus. Reporty používají zvolené písmo reportu, "
                L"Nápověda systémové dialogové písmo a O programu písmo svého textu. Pokud nejsou "
                L"otevřené žádné karty a Nápověda je otevřená, zůstávají Vzhled stránky… i Tisk… dostupné "
                L"a tiskne se Nápověda. Tisk z Nápovědy používá dialog hlavního okna; další Ctrl+P v "
                L"Nápovědě jej přenese do popředí. Dlouhé řádky se zalomí a text se rozdělí na stránky. "
                L"Tisk probíhá na pozadí.\r\nPřetáhněte jeden nebo více souborů do okna, na ikonu EXE "
                L"nebo jeho zástupce, případně předejte jejich cesty na příkazovém řádku. Pokud nejsou "
                L"povolené další instance, soubory se otevřou v již běžícím okně.\r\nVlevo ve stavovém "
                L"řádku se zobrazuje cesta k souboru a průběh načítání, vpravo verze načtené "
                L"MediaInfo.dll. Dlouhé cesty se podle dostupného místa zkracují výpustkou.\r\n\r\n"
                L"EXPORT\r\nTXT, BMP, GIF, JPEG, PNG, TIFF a WebP se nabízejí podle dostupnosti. Poslední "
                L"složka a formát exportu se pamatují.\r\nTXT nabízí ANSI, UTF-8, UTF-8 s BOM, UTF-16 BE "
                L"s BOM a UTF-16 LE s BOM. Výchozí je druhá položka, UTF-8 bez BOM. Zachovává se celý "
                L"text reportu i jeho původní konce řádků.\r\n\r\nVYTVOŘIT HLAVIČKOVÝ SOUBOR\r\nNabídka "
                L"Nástroje je čtvrtou hlavní nabídkou. Příkaz Vytvořit hlavičkový soubor… otevře jeden "
                L"vstupní soubor nezávisle na kartách reportů a zkopíruje jeho prvních 524288 bajtů (512 "
                L"KiB). Kratší soubor se zkopíruje celý; prázdný soubor vytvoří prázdný výstup. Jde o "
                L"běžné binární čtení souboru bez analýzy MediaInfo; knihovna MediaInfo.dll není potřeba. "
                L"Karty reportů ani seznam posledních souborů se tím nemění.\r\n\r\nPo přečtení se otevře "
                L"dialog Uložit jako ve složce vstupního souboru. Pro video.mp4 nabídne název "
                L"video.mp4.header: .header se připojí za celý původní název včetně přípony. Název i "
                L"cílovou složku můžete změnit. Zrušení kteréhokoli dialogu nic neuloží. Přepsání "
                L"existujícího cílového souboru vyžaduje potvrzení. Vstupní soubor zůstane nezměněný a "
                L"chyba ukládání zachová původní cílový soubor. Pro otevírání i ukládání se používají "
                L"nejmodernější systémové dialogy dostupné v dané verzi Windows.\r\n\r\nPři spuštění "
                L"aplikace převezme nástroj stejnou počáteční složku jako příkaz Soubor > Otevřít. Pokud "
                L"žádná složka není uložená, počáteční umístění určí Windows. Po výběru vstupního souboru "
                L"si nástroj svou složku pamatuje pouze do ukončení aplikace, i když dialog Uložit jako "
                L"zrušíte. Nemění složky příkazů Otevřít a Exportovat a aplikace jeho vlastní cestu "
                L"neukládá do registru. Každý dialog Uložit jako začne ve složce právě vybraného "
                L"vstupního souboru bez ohledu na předchozí cíl ukládání.\r\n\r\nPŘEDVOLBY A JAZYKY\r\n"
                L"Předvolby (Možnosti > Předvolby, Ctrl+G) obsahují cesty ke knihovnám, písmo reportu, "
                L"vyhlazování a jazyky. Rozhraní má 36 variant a zpočátku se řídí Windows. Výchozí report "
                L"je vždy v původní angličtině knihovny, nezávisle na Windows i rozhraní. Změní jej pouze "
                L"ruční volba jazyka reportu: angličtina, 37 překladů nebo vlastní tabulka MediaInfo CSV. "
                L"OK nebo Použít potvrdí změny; Zrušit zahodí rozpracované úpravy. V předvolbách lze "
                L"změnit limit délky názvu karty (výchozí 80 znaků) a vymazat seznam posledních souborů. "
                L"Dlouhé názvy zachovají začátek, konec i příponu s výpustkou uprostřed. Tlačítko Vymazat "
                L"odstraní seznam posledních souborů okamžitě, i když poté zavřete Předvolby tlačítkem "
                L"Zrušit.\r\n\r\nZáhlaví hlavního okna zobrazuje aktivní soubor ve tvaru název souboru — "
                L"MediaInfo. V předvolbách lze samostatně nastavit délku názvu v záhlaví na 8–255 znaků; "
                L"výchozí hodnota je 40. Delší názvy se zkracují stejnou výpustkou uprostřed se zachováním "
                L"přípony. Bez otevřených karet je záhlaví MediaInfo.\r\n\r\nKNIHOVNY A OKNA\r\nEXE obsahuje "
                L"MediaInfo 26.10, 21.03 a 0.7.60. Po "
                L"externích knihovnách je zkouší od nejnovější. Dvě novější verze mají odpovídající "
                L"libcurl; 0.7.60 libcurl nikdy nerozbaluje. Umístění okna se ukládá. Ve výchozím stavu "
                L"je povolena pouze jedna instance a další spuštění předá soubory otevřenému oknu. V "
                L"předvolbách lze povolit více instancí. Při více oknech se uložená pozice obnoví jen "
                L"prvnímu oknu daného typu; další převezmou pouze uloženou velikost.\r\n\r\nÚpravy > "
                L"Najít (Ctrl+F) hledá podle fokusu okna v aktivní kartě hlavního okna, v textové oblasti "
                L"Nápovědy nebo v textové oblasti O programu. Okno hledání si po dobu vlastního fokusu "
                L"ponechá naposledy zvolený zdroj. F3 hledání opakuje, Shift+F3 obrátí jeho směr. Po "
                L"dosažení okraje textu pokračuje hledání na opačném konci. Možnosti > Zalamování řádků "
                L"ovlivňuje jen aktivní kartu; zatržení se mění podle vybrané karty. Formulář hledání lze "
                L"minimalizovat a měnit jeho šířku; pamatuje si polohu a volbu Vždy navrchu. Historie "
                L"uchovává až 30 hledaných textů s jejich volbami pouze do ukončení aplikace. Začíná na a "
                L"Končí na hledají na okrajích logických řádků. Regulární výrazy používají syntaxi PCRE2. "
                L"Ostatní příkazy nabídky Úpravy pracují s aktivní kartou reportu. Enter spustí hledání, "
                L"Shift+Enter obrátí zvolený směr. Volba „Rozlišovat velikost písmen“ rozlišuje velká a "
                L"malá písmena; „Hledat pozpátku“ hledá směrem k začátku textu. Výběr z historie obnoví "
                L"všech pět voleb hledání, včetně uloženého stavu regulárního výrazu; „Vždy navrchu“ je "
                L"nezávislá volba. „Regulární výraz“ vypne volby „Začíná na“ a „Končí na“. Jsou-li obě "
                L"volby okrajů zapnuté, stačí shoda na jednom z nich. „Zalamování řádků“ mění pouze "
                L"zobrazení."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"Obrázek WebP nelze uložit. Zkontrolujte cíl, volnou paměť a místo na disku."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Textový dokument UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Textový dokument UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Textový dokument UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Textový dokument UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Report nelze v tomto kódování uložit bez ztráty znaků. Zvolte jiné kódování textu."
            },
            { TXT_OPEN_FOLDER, L"Otevřít s&ložku…" },
            { TXT_OPEN_FOLDER_TITLE, L"Otevřít složku" },
            { TXT_FOLDER_READ_FAILED, L"Složku nelze přečíst:\n\n%s\n\nChyba Windows %lu." },
            { TXT_ADVANCED_MODE, L"Pok&ročilý režim" },
            { TXT_REPORT_DETAIL_REJECTED,
                L"Vybraná knihovna MediaInfo.dll odmítla nastavení podrobností reportu."
            },
            { TXT_KNOWN_FORMATS, L"Známé &formáty" },
            { TXT_KNOWN_CODECS, L"Známé &kodeky" },
            { TXT_KNOWN_PARAMETERS, L"Známé &parametry" },
            { TXT_KNOWN_FORMATS_TITLE, L"Známé formáty" },
            { TXT_KNOWN_CODECS_TITLE, L"Známé kodeky" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Známé parametry" },
            { TXT_KNOWN_INFO_FAILED, L"Knihovna nevrátila požadované informace." },
            { TXT_FULL_PARSING, L"Úplná &analýza" },
            { TXT_PARSING_REJECTED, L"Vybraná knihovna MediaInfo.dll odmítla nastavení analýzy." },
            { TXT_TRACE_LEVEL_0, L"Úroveň trasování &0" },
            { TXT_TRACE_LEVEL_5, L"Úroveň trasování &5" },
            { TXT_TRACE_LEVEL_9, L"Úroveň trasování &9" },
            { TXT_TRACE_LEVEL_10, L"Úroveň trasování &10" },
            { TXT_PAGE_SETUP, L"Vz&hled stránky…" },
            { TXT_PAGE_SETUP_FAILED, L"Nelze otevřít dialog Vzhled stránky." },
            { TXT_PRINT, L"&Tisk…\tCtrl+P" },
            { TXT_PRINTING, L"Tisk…" },
            { TXT_PRINT_FAILED,
                L"Text se nepodařilo vytisknout. Zkontrolujte tiskárnu, její nastavení a dostupnou paměť."
            },
            { TXT_TOOLS_MENU, L"Nás&troje" },
            { TXT_CREATE_HEADER, L"Vytvořit &hlavičkový soubor…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Vytvořit hlavičkový soubor - Otevřít" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Vytvořit hlavičkový soubor - Uložit jako" },
            { TXT_HEADER_FORMAT, L"Soubor hlavičky (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Hlavičku souboru nelze přečíst:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Soubor hlavičky nelze uložit:\n\n%s" },
            { TXT_COPY, L"&Kopírovat" },
            { TXT_COPY_FILE_NAME, L"Kopírovat ná&zev souboru" },
            { TXT_COPY_FULL_PATH, L"Kopírovat název souboru včetně &cesty" },
            { TXT_LAUNCH_FILE, L"&Spustit soubor" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"Zo&brazit ve složce" },
            { TXT_EDIT_MENU, L"&Úpravy" },
            { TXT_WORD_WRAP, L"&Zalamování řádků" },
            { TXT_WORD_WRAP_FAILED, L"Zalamování řádků nelze změnit." },
            { TXT_COPY_SELECTION, L"&Kopírovat\tCtrl+C" },
            { TXT_SELECT_ALL, L"Vybrat &vše\tCtrl+A" },
            { TXT_FIND_MENU, L"&Najít…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Najít &další\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Najít &předchozí\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Najít" },
            { TXT_FIND_WHAT, L"&Hledat:" },
            { TXT_FIND_NEXT, L"Najít &další" },
            { TXT_FIND_MATCH_CASE, L"Rozlišovat &velikost písmen" },
            { TXT_FIND_BACKWARD, L"Hledat &pozpátku" },
            { TXT_FIND_TOPMOST, L"Vždy navr&chu" },
            { TXT_FIND_STARTS_WITH, L"Začíná &na" },
            { TXT_FIND_ENDS_WITH, L"K&ončí na" },
            { TXT_FIND_REGEX, L"&Regulární výraz" },
            { TXT_FIND_NOT_FOUND, L"Zadaný text nebyl nalezen." },
            { TXT_FIND_FAILED, L"Vyhledávání se nepodařilo dokončit." },
            { TXT_FIND_REGEX_ERROR, L"Chyba regulárního výrazu:\r\n\r\n%s" },
        }
    },
    {
        LANG_EN_US,
        {
            { TXT_LANGUAGE_NAME, L"English (US)" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nWebsite: " },
            { TXT_FILE_OPEN_FAILED, L"%s could not be opened. Check its path and permissions." },
            { TXT_BROWSE_DLL, L"&Browse…" },
            { TXT_BROWSE_REPORT, L"B&rowse…" },
            { TXT_CLOSE, L"&Close" },
            { TXT_CLOSE_TAB, L"&Close\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"&Default" },
            { TXT_EXPORT, L"&Export…\tCtrl+E" },
            { TXT_FILE_MENU, L"&File" },
            { TXT_REPORT_FONT, L"Report &font:" },
            { TXT_HELP_MENU, L"&Help" },
            { TXT_HELP, L"&Help\tF1" },
            { TXT_LANGUAGE, L"&Language:" },
            { TXT_OPEN_WEBSITE, L"&Open in Default Browser" },
            { TXT_OPEN, L"&Open…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Options" },
            { TXT_PREFERENCES_MENU, L"&Preferences…\tCtrl+G" },
            { TXT_ABOUT, L"&About" },
            { TXT_ABOUT_TITLE, L"About %ls" },
            { TXT_ALL_FILES, L"All Files" },
            { TXT_FONT_BOLD, L"Bold" },
            { TXT_FONT_BOLD_ITALIC, L"Bold Italic" },
            { TXT_BROWSE_CURL, L"Bro&wse…" },
            { TXT_CANCEL, L"Cancel" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Cannot load MediaInfo.dll (Windows error %lu). Use a 32-bit DLL compatible with this "
                L"Windows version."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Cannot load libcurl.dll (Windows error %lu). Select a 32-bit library compatible with this "
                L"Windows version."
            },
            { TXT_CLOSE_ALL, L"Close &All" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Copy &URL" },
            { TXT_COPY_INFORMATION, L"Copy &Information" },
            { TXT_DLL_FILES, L"Dynamic-Link Libraries" },
            { TXT_EXIT, L"E&xit\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Embedded MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Embedded libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Export Report" },
            { TXT_FONT_ANTIALIASING, L"Font a&ntialiasing:" },
            { TXT_GIF_EXPORT_FAILED, L"GIF export failed. Exact GIF output requires at most 256 colors." },
            { TXT_FONT_ITALIC, L"Italic" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED, L"JPEG export failed. A working GDI+ JPEG encoder is required." },
            { TXT_LICENSE_UNAVAILABLE, L"License resource unavailable." },
            { TXT_MEDIA_FILES, L"Media Files" },
            { TXT_APPLICATION_DESCRIPTION, L"Media information viewer" },
            { TXT_HELP_TITLE, L"MediaInfo Help" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo could not initialize media analysis." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo could not open or recognize this file." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo Library" },
            { TXT_MEDIALIB_PATH, L"MediaInfo.dll &path:" },
            { TXT_MEDIALIB_REQUIRED, L"MediaInfo.dll is not loaded. Select it in Options > Preferences." },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll not loaded." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"No compatible external or bundled MediaInfo.dll could be loaded. Select a compatible DLL "
                L"in Options > Preferences."
            },
            { TXT_ANTIALIASING_NONE, L"None" },
            { TXT_OK, L"OK" },
            { TXT_OPEN_TITLE, L"Open Media Files" },
            { TXT_PLATFORM, L"Platform:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Preferences" },
            { TXT_READY, L"Ready" },
            { TXT_FONT_REGULAR, L"Regular" },
            { TXT_REPORT_LANGUAGE, L"Repor&t language:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Report Language Tables" },
            { TXT_SELECT_MEDIALIB, L"Select MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Select a Report Language CSV File" },
            { TXT_INVALID_MEDIA_PATH, L"Select an existing media file with a path shorter than MAX_PATH." },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Select files with paths shorter than MAX_PATH." },
            { TXT_SELECT_CURL, L"Select libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Text Document ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"The BMP image could not be saved. Check the destination and available memory and disk "
                L"space."
            },
            { TXT_LIBRARY_WORKER_START_FAILED,
                L"The MediaInfo library worker could not be started (Windows error %lu)."
            },
            { TXT_REPORT_COPY_FAILED, L"The MediaInfo report could not be copied into memory." },
            { TXT_VIEWER_CREATE_FAILED, L"The MediaInfo viewer could not be created." },
            { TXT_MEDIALIB_PATH_INVALID, L"The MediaInfo.dll path is invalid or too long." },
            { TXT_PNG_EXPORT_FAILED,
                L"The PNG image could not be saved. Check the destination and available memory and disk "
                L"space."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"The TIFF image could not be saved. Check the destination and available memory and disk "
                L"space."
            },
            { TXT_COPY_URL_FAILED, L"The URL could not be copied to the clipboard." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"The Win32 viewer requires a 32-bit %s. Select the x86/i386 library."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"The bundled library could not be written to AppData, the user profile, Program Files or "
                L"the temporary directory."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED,
                L"The bundled library failed decompression or CRC verification."
            },
            { TXT_LIBRARY_RESOURCE_INVALID, L"The bundled library resource is invalid." },
            { TXT_CURL_FILENAME_INVALID,
                L"The curl library must be named libcurl.dll so MediaInfo can use it."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"The file dialog could not be opened." },
            { TXT_FILE_DIALOG_SELECTION_FAILED, L"The file dialog could not return the selected files." },
            { TXT_RECENT_FILE_MISSING,
                L"The file \"%s\" no longer exists.\n\nRemove this entry from the recent files list?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"The file is no longer available:\n\n%s\n\nRemove this entry from the recent files list?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"The information could not be copied to the clipboard." },
            { TXT_CURL_PATH_INVALID, L"The libcurl.dll path is invalid or too long." },
            { TXT_MEDIALIB_VERSION_MISSING, L"The library did not return a MediaInfo version." },
            { TXT_CURL_EXPORTS_MISSING,
                L"The library does not export the curl functions required by MediaInfo."
            },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"The library does not export the required Unicode MediaInfo functions."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"The library worker failed during %s (process exit code 0x%08lX). Select a compatible "
                L"MediaInfo.dll in Options > Preferences."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"The library worker stopped responding during %s. Select a compatible MediaInfo.dll in "
                L"Options > Preferences."
            },
            { TXT_PREFERENCES_SAVE_FAILED,
                L"The preferences were applied, but could not be saved in the registry."
            },
            { TXT_REPORT_START_FAILED, L"The report could not be started: insufficient memory." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"The report image could not be created." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"The report language table could not be loaded. Select a "
                L"valid UTF-8 or UTF-16 MediaInfo CSV file." },
            { TXT_REPORT_THREAD_START_FAILED, L"The report thread could not be started." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"The selected MediaInfo.dll rejected the report language." },
            { TXT_INVALID_WINDOWS_DLL, L"The selected file is not a valid Windows DLL." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"The selected image format is not supported." },
            { TXT_TEXT_EXPORT_FAILED,
                L"The text report could not be saved. Check the destination and available disk space."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"The website could not be opened in the default browser." },
            { TXT_TOO_MANY_FILES, L"Too many files were selected. Open them in smaller groups." },
            { TXT_LIBRARY_PATH_HINT,
                L"Use 32-bit libraries compatible with your Windows version. Leave paths empty for automatic "
                L"discovery. MediaInfoLib v0.7.60 does not use libcurl.dll."
            },
            { TXT_VERSION, L"Version" },
            { TXT_WEBSITE_TOOLTIP, L"Visit %s" },
            { TXT_WAITING_FOR_REPORT, L"Waiting for the current report to finish." },
            { TXT_WEBSITE_LABEL, L"Website:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"copying the MediaInfo report" },
            { TXT_CURL_LIBRARY, L"curl library" },
            { TXT_CURL_PATH, L"libc&url.dll path:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"loading MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"loading libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"unloading MediaInfo.dll" },
            { TXT_APPLY, L"&Apply" },
            { TXT_TAB_NAME_LENGTH, L"Tab name len&gth:" },
            { TXT_TITLE_NAME_LENGTH, L"Titl&e length:" },
            { TXT_RECENT_FILES, L"Recent files:" },
            { TXT_CLEAR_RECENT_FILES, L"&Clear" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"The tab name length must be between 8 and 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"The title name length must be between 8 and 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"The recent files list was cleared, but could not be saved in the registry."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"Close tabs on double-clic&k" },
            { TXT_CLOSE_TAB_CONTEXT, L"Close &Tab" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"Allow multiple &instances" },
            { TXT_INSTANCE_FORWARD_FAILED,
                L"The files could not be passed to the running MediaInfo instance."
            },
            { TXT_LOADING, L"Loading…" },
            { TXT_LOADING_FILE, L"Loading file %s…" },
            { TXT_APPLICATION_HELP,
                L"FILES AND TABS\r\nNative x86 Windows viewer for MediaInfo.dll reports. Each file has "
                L"its own read-only tab. Open files with Ctrl+O or drag and drop. Reopening a file "
                L"selects its existing tab. Ctrl+W or middle-click closes a tab; Close All closes every "
                L"tab. The File menu remembers eight recent files. The tab header's context menu includes "
                L"Close Tab. Enable Close tabs on double-click in Preferences to close a tab by "
                L"double-clicking its header. This option is off by default and is saved. Double-click in "
                L"the report text selects a word. Triple-click selects a logical line. Dragging extends "
                L"the selection by words or lines.\r\nOpen Folder… opens files directly in the selected "
                L"folder, each in its own tab. Subfolders are not included.\r\nOpen and Open Folder share "
                L"their last selected folder. Export remembers its own folder, defaulting to Documents. "
                L"Advanced Mode shows additional report fields.\r\nKnown Formats / Known Codecs / Known "
                L"Parameters — MediaInfo.dll.\r\nFull Parsing examines the entire file and can take "
                L"longer. These report options and Trace Level belong to each tab; a change refreshes "
                L"only the active tab. The last manually chosen combination is saved for new tabs and the "
                L"next launch. A matching cached report is reused while the file remains unchanged.\r\n"
                L"Trace Level: 0 / 5 / 9 / 10.\r\nFile > Page Setup… opens paper, orientation and margin "
                L"settings for the current application session. Print… (Ctrl+P) opens the system print "
                L"dialog; Windows 11 provides a preview, while Windows 10 and earlier keep the classic "
                L"dialog. Ctrl+P prints the active tab in the main window, or the text area in Help or "
                L"About, according to which window has focus. Reports use the selected report font, Help "
                L"uses the system dialog font, and About uses its text area's font. If no tabs are open "
                L"and Help is open, Page Setup… and Print… remain available; Print… prints Help. Printing "
                L"from Help uses the main window's dialog; pressing Ctrl+P in Help again brings it to the "
                L"foreground. Long lines wrap and the text is split into pages. Printing runs in the "
                L"background.\r\nDrag one or more files onto the window, the EXE icon or its shortcut, or "
                L"pass their paths on the command line. If multiple instances are disabled, the files "
                L"open in the running window.\r\nThe left status pane shows file paths and loading "
                L"progress; the right pane shows the loaded MediaInfo.dll version. Long paths are "
                L"shortened with an ellipsis to fit the available space.\r\n\r\nEXPORT\r\nTXT, BMP, GIF, "
                L"JPEG, PNG, TIFF and WebP are listed when available. The last export folder and format "
                L"are remembered.\r\nTXT offers ANSI, UTF-8, UTF-8 with BOM, UTF-16 BE with BOM and "
                L"UTF-16 LE with BOM. The second entry, UTF-8 without BOM, is the default. The complete "
                L"report text and its original line endings are preserved.\r\n\r\nCREATE A HEADER FILE\r\n"
                L"Tools is the fourth main menu. Its Create a Header File… command opens one source file "
                L"independently of the report tabs and copies its first 524288 bytes (512 KiB). A shorter "
                L"file is copied in full; an empty file produces an empty output. This is ordinary binary "
                L"file reading, without MediaInfo analysis or a requirement for MediaInfo.dll. The tool "
                L"leaves report tabs and the viewer's recent-files list unchanged.\r\n\r\nAfter reading, "
                L"the Save As dialog starts in the source file's folder and suggests video.mp4.header for "
                L"video.mp4: .header is appended to the complete original name. You can change both the "
                L"name and the destination folder. Canceling either dialog writes no output. Replacing an "
                L"existing destination requires confirmation. The source stays unchanged; a failed save "
                L"preserves the previous destination. Open and Save use the newest native dialogs "
                L"available on the current Windows version.\r\n\r\nAt application startup, the tool takes "
                L"its initial input folder from File > Open. If no folder has been saved, Windows chooses "
                L"the initial location. After an input file is selected, the tool remembers its own "
                L"folder only until the application exits, even if Save As is canceled. It neither "
                L"changes the folders used by Open and Export nor saves its own folder to the application "
                L"settings. Every Save As dialog starts in the folder of the currently selected input "
                L"file, regardless of the previous save destination.\r\n\r\nPREFERENCES AND LANGUAGES\r\n"
                L"Preferences (Options > Preferences, Ctrl+G) contains library paths, report font, "
                L"antialiasing and language choices. The interface has 36 variants and initially follows "
                L"Windows. Reports always default to the library’s original English, independently of "
                L"Windows and the interface. Only a manual report-language choice changes this: English, "
                L"37 translations or a custom MediaInfo CSV table. OK or Apply commits changes; Cancel "
                L"discards pending edits. Preferences sets the tab name limit (80 by default) and clears "
                L"the recent-files list. Long names retain their beginning, ending and extension with a "
                L"middle ellipsis. Clear removes the recent-files list immediately, even if Preferences "
                L"is then canceled.\r\n\r\nThe main window title shows the active file as filename — "
                L"MediaInfo. Preferences sets a separate title name limit of 8–255 characters (40 by "
                L"default). Longer names use the same middle ellipsis and retain the extension. With no open "
                L"tabs, the title is MediaInfo.\r\n\r\nLIBRARIES AND WINDOWS\r\nThe executable embeds "
                L"MediaInfo "
                L"26.10, 21.03 and 0.7.60, tried newest first after external libraries. The two newer "
                L"versions have matching libcurl libraries; 0.7.60 never extracts libcurl. Window "
                L"placement is saved. By default, only one instance is allowed and later launches send "
                L"files to the open window. Preferences can allow multiple instances. With multiple "
                L"windows, only the first window of each window type restores its saved position; later "
                L"windows restore size only.\r\n\r\nEdit > Find (Ctrl+F) searches the active report tab "
                L"or the text area in Help or About, according to which window has focus. The Find window "
                L"retains the last selected source while it has focus. F3 repeats the search; Shift+F3 "
                L"reverses its direction. Searching wraps at the ends of the text. Options > Word Wrap "
                L"affects only the active tab, and its check mark follows the selected tab. The search "
                L"window can be minimized and resized horizontally; its position and Always on Top "
                L"setting are remembered. Up to 30 search texts and their options are retained only until "
                L"the application exits. Starts with and Ends with match the edges of logical lines. "
                L"Regular expressions use PCRE2 syntax. The other Edit menu commands apply to the active "
                L"report tab. Enter searches; Shift+Enter reverses the selected direction. \"Case "
                L"sensitive\" distinguishes uppercase and lowercase; \"Backward\" searches toward the "
                L"start of the text. Choosing a history entry restores all five search options, including "
                L"the saved regular-expression mode; \"Always on top\" is independent. \"Regular "
                L"expression\" disables \"Starts with\" and \"Ends with\". With both line-edge options "
                L"enabled, either edge can match. \"Word Wrap\" changes only the display."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"The WebP image could not be saved. Check the destination and available memory and disk "
                L"space."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Text Document UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Text Document UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Text Document UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Text Document UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"The report cannot be saved in this encoding without losing characters. Choose another text "
                L"encoding."
            },
            { TXT_OPEN_FOLDER, L"Open &Folder…" },
            { TXT_OPEN_FOLDER_TITLE, L"Open Folder" },
            { TXT_FOLDER_READ_FAILED, L"The folder could not be read:\n\n%s\n\nWindows error %lu." },
            { TXT_ADVANCED_MODE, L"&Advanced Mode" },
            { TXT_REPORT_DETAIL_REJECTED, L"The selected MediaInfo.dll rejected the report detail setting." },
            { TXT_KNOWN_FORMATS, L"Known &Formats" },
            { TXT_KNOWN_CODECS, L"Known &Codecs" },
            { TXT_KNOWN_PARAMETERS, L"Known &Parameters" },
            { TXT_KNOWN_FORMATS_TITLE, L"Known Formats" },
            { TXT_KNOWN_CODECS_TITLE, L"Known Codecs" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Known Parameters" },
            { TXT_KNOWN_INFO_FAILED, L"The library did not return the requested information." },
            { TXT_FULL_PARSING, L"&Full Parsing" },
            { TXT_PARSING_REJECTED, L"The selected MediaInfo.dll rejected the parsing setting." },
            { TXT_TRACE_LEVEL_0, L"Trace Level &0" },
            { TXT_TRACE_LEVEL_5, L"Trace Level &5" },
            { TXT_TRACE_LEVEL_9, L"Trace Level &9" },
            { TXT_TRACE_LEVEL_10, L"Trace Level &10" },
            { TXT_PAGE_SETUP, L"Page Set&up…" },
            { TXT_PAGE_SETUP_FAILED, L"The Page Setup dialog could not be opened." },
            { TXT_PRINT, L"&Print…\tCtrl+P" },
            { TXT_PRINTING, L"Printing…" },
            { TXT_PRINT_FAILED,
                L"The text could not be printed. Check the printer, its settings and available memory."
            },
            { TXT_TOOLS_MENU, L"&Tools" },
            { TXT_CREATE_HEADER, L"Create a &Header File…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Create a Header File - Open" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Create a Header File - Save As" },
            { TXT_HEADER_FORMAT, L"Header File (*.header)" },
            { TXT_HEADER_READ_FAILED, L"The file header could not be read:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"The header file could not be saved:\n\n%s" },
            { TXT_COPY, L"&Copy" },
            { TXT_COPY_FILE_NAME, L"Copy File Na&me" },
            { TXT_COPY_FULL_PATH, L"Copy Full Pat&h" },
            { TXT_LAUNCH_FILE, L"&Launch File" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"&Show in Containing Folder" },
            { TXT_EDIT_MENU, L"&Edit" },
            { TXT_WORD_WRAP, L"&Word Wrap" },
            { TXT_WORD_WRAP_FAILED, L"Word wrap could not be changed." },
            { TXT_COPY_SELECTION, L"&Copy\tCtrl+C" },
            { TXT_SELECT_ALL, L"Select &All\tCtrl+A" },
            { TXT_FIND_MENU, L"&Find…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Find &Next\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Find &Previous\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Find" },
            { TXT_FIND_WHAT, L"&Find:" },
            { TXT_FIND_NEXT, L"Fi&nd Next" },
            { TXT_FIND_MATCH_CASE, L"C&ase sensitive" },
            { TXT_FIND_BACKWARD, L"&Backward" },
            { TXT_FIND_TOPMOST, L"Always on &top" },
            { TXT_FIND_STARTS_WITH, L"&Starts with" },
            { TXT_FIND_ENDS_WITH, L"En&ds with" },
            { TXT_FIND_REGEX, L"Regular e&xpression" },
            { TXT_FIND_NOT_FOUND, L"The specified text was not found." },
            { TXT_FIND_FAILED, L"The search could not be completed." },
            { TXT_FIND_REGEX_ERROR, L"Regular expression error:\r\n\r\n%s" },
        }
    },
    {
        LANG_EN_GB,
        {
            { TXT_LANGUAGE_NAME, L"English (UK)" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nWebsite: " },
            { TXT_FILE_OPEN_FAILED, L"%s could not be opened. Check its path and permissions." },
            { TXT_BROWSE_DLL, L"&Browse…" },
            { TXT_BROWSE_REPORT, L"B&rowse…" },
            { TXT_CLOSE, L"&Close" },
            { TXT_CLOSE_TAB, L"&Close\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"&Default" },
            { TXT_EXPORT, L"&Export…\tCtrl+E" },
            { TXT_FILE_MENU, L"&File" },
            { TXT_REPORT_FONT, L"Report &font:" },
            { TXT_HELP_MENU, L"&Help" },
            { TXT_HELP, L"&Help\tF1" },
            { TXT_LANGUAGE, L"&Language:" },
            { TXT_OPEN_WEBSITE, L"&Open in Default Browser" },
            { TXT_OPEN, L"&Open…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Options" },
            { TXT_PREFERENCES_MENU, L"&Preferences…\tCtrl+G" },
            { TXT_ABOUT, L"&About" },
            { TXT_ABOUT_TITLE, L"About %ls" },
            { TXT_ALL_FILES, L"All Files" },
            { TXT_FONT_BOLD, L"Bold" },
            { TXT_FONT_BOLD_ITALIC, L"Bold Italic" },
            { TXT_BROWSE_CURL, L"Bro&wse…" },
            { TXT_CANCEL, L"Cancel" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Cannot load MediaInfo.dll (Windows error %lu). Use a 32-bit DLL compatible with this "
                L"Windows version."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Cannot load libcurl.dll (Windows error %lu). Select a 32-bit library compatible with this "
                L"Windows version."
            },
            { TXT_CLOSE_ALL, L"Close &All" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Copy &URL" },
            { TXT_COPY_INFORMATION, L"Copy &Information" },
            { TXT_DLL_FILES, L"Dynamic-Link Libraries" },
            { TXT_EXIT, L"E&xit\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Embedded MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Embedded libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Export Report" },
            { TXT_FONT_ANTIALIASING, L"Font a&ntialiasing:" },
            { TXT_GIF_EXPORT_FAILED, L"GIF export failed. Exact GIF output requires at most 256 colours." },
            { TXT_FONT_ITALIC, L"Italic" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED, L"JPEG export failed. A working GDI+ JPEG encoder is required." },
            { TXT_LICENSE_UNAVAILABLE, L"Licence resource unavailable." },
            { TXT_MEDIA_FILES, L"Media Files" },
            { TXT_APPLICATION_DESCRIPTION, L"Media information viewer" },
            { TXT_HELP_TITLE, L"MediaInfo Help" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo could not initialise media analysis." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo could not open or recognise this file." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo Library" },
            { TXT_MEDIALIB_PATH, L"MediaInfo.dll &path:" },
            { TXT_MEDIALIB_REQUIRED, L"MediaInfo.dll is not loaded. Select it in Options > Preferences." },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll not loaded." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"No compatible external or bundled MediaInfo.dll could be loaded. Select a compatible DLL "
                L"in Options > Preferences."
            },
            { TXT_ANTIALIASING_NONE, L"None" },
            { TXT_OK, L"OK" },
            { TXT_OPEN_TITLE, L"Open Media Files" },
            { TXT_PLATFORM, L"Platform:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Preferences" },
            { TXT_READY, L"Ready" },
            { TXT_FONT_REGULAR, L"Regular" },
            { TXT_REPORT_LANGUAGE, L"Repor&t language:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Report Language Tables" },
            { TXT_SELECT_MEDIALIB, L"Select MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Select a Report Language CSV File" },
            { TXT_INVALID_MEDIA_PATH, L"Select an existing media file with a path shorter than MAX_PATH." },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Select files with paths shorter than MAX_PATH." },
            { TXT_SELECT_CURL, L"Select libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Text Document ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"The BMP image could not be saved. Check the destination and available memory and disk "
                L"space."
            },
            { TXT_LIBRARY_WORKER_START_FAILED,
                L"The MediaInfo library worker could not be started (Windows error %lu)."
            },
            { TXT_REPORT_COPY_FAILED, L"The MediaInfo report could not be copied into memory." },
            { TXT_VIEWER_CREATE_FAILED, L"The MediaInfo viewer could not be created." },
            { TXT_MEDIALIB_PATH_INVALID, L"The MediaInfo.dll path is invalid or too long." },
            { TXT_PNG_EXPORT_FAILED,
                L"The PNG image could not be saved. Check the destination and available memory and disk "
                L"space."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"The TIFF image could not be saved. Check the destination and available memory and disk "
                L"space."
            },
            { TXT_COPY_URL_FAILED, L"The URL could not be copied to the clipboard." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"The Win32 viewer requires a 32-bit %s. Select the x86/i386 library."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"The bundled library could not be written to AppData, the user profile, Program Files or "
                L"the temporary directory."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED,
                L"The bundled library failed decompression or CRC verification."
            },
            { TXT_LIBRARY_RESOURCE_INVALID, L"The bundled library resource is invalid." },
            { TXT_CURL_FILENAME_INVALID,
                L"The curl library must be named libcurl.dll so MediaInfo can use it."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"The file dialog could not be opened." },
            { TXT_FILE_DIALOG_SELECTION_FAILED, L"The file dialog could not return the selected files." },
            { TXT_RECENT_FILE_MISSING,
                L"The file \"%s\" no longer exists.\n\nRemove this entry from the recent files list?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"The file is no longer available:\n\n%s\n\nRemove this entry from the recent files list?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"The information could not be copied to the clipboard." },
            { TXT_CURL_PATH_INVALID, L"The libcurl.dll path is invalid or too long." },
            { TXT_MEDIALIB_VERSION_MISSING, L"The library did not return a MediaInfo version." },
            { TXT_CURL_EXPORTS_MISSING,
                L"The library does not export the curl functions required by MediaInfo."
            },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"The library does not export the required Unicode MediaInfo functions."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"The library worker failed during %s (process exit code 0x%08lX). Select a compatible "
                L"MediaInfo.dll in Options > Preferences."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"The library worker stopped responding during %s. Select a compatible MediaInfo.dll in "
                L"Options > Preferences."
            },
            { TXT_PREFERENCES_SAVE_FAILED,
                L"The preferences were applied, but could not be saved in the registry."
            },
            { TXT_REPORT_START_FAILED, L"The report could not be started: insufficient memory." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"The report image could not be created." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"The report language table could not be loaded. Select a "
                L"valid UTF-8 or UTF-16 MediaInfo CSV file." },
            { TXT_REPORT_THREAD_START_FAILED, L"The report thread could not be started." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"The selected MediaInfo.dll rejected the report language." },
            { TXT_INVALID_WINDOWS_DLL, L"The selected file is not a valid Windows DLL." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"The selected image format is not supported." },
            { TXT_TEXT_EXPORT_FAILED,
                L"The text report could not be saved. Check the destination and available disk space."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"The website could not be opened in the default browser." },
            { TXT_TOO_MANY_FILES, L"Too many files were selected. Open them in smaller groups." },
            { TXT_LIBRARY_PATH_HINT,
                L"Use 32-bit libraries compatible with your Windows version. Leave paths empty for automatic "
                L"discovery. MediaInfoLib v0.7.60 does not use libcurl.dll."
            },
            { TXT_VERSION, L"Version" },
            { TXT_WEBSITE_TOOLTIP, L"Visit %s" },
            { TXT_WAITING_FOR_REPORT, L"Waiting for the current report to finish." },
            { TXT_WEBSITE_LABEL, L"Website:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"copying the MediaInfo report" },
            { TXT_CURL_LIBRARY, L"curl library" },
            { TXT_CURL_PATH, L"libc&url.dll path:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"loading MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"loading libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"unloading MediaInfo.dll" },
            { TXT_APPLY, L"&Apply" },
            { TXT_TAB_NAME_LENGTH, L"Tab name len&gth:" },
            { TXT_TITLE_NAME_LENGTH, L"Titl&e length:" },
            { TXT_RECENT_FILES, L"Recent files:" },
            { TXT_CLEAR_RECENT_FILES, L"&Clear" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"The tab name length must be between 8 and 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"The title name length must be between 8 and 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"The recent files list was cleared, but could not be saved in the registry."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"Close tabs on double-clic&k" },
            { TXT_CLOSE_TAB_CONTEXT, L"Close &Tab" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"Allow multiple &instances" },
            { TXT_INSTANCE_FORWARD_FAILED,
                L"The files could not be passed to the running MediaInfo instance."
            },
            { TXT_LOADING, L"Loading…" },
            { TXT_LOADING_FILE, L"Loading file %s…" },
            { TXT_APPLICATION_HELP,
                L"FILES AND TABS\r\nNative x86 Windows viewer for MediaInfo.dll reports. Each file has "
                L"its own read-only tab. Open files with Ctrl+O or drag and drop. Reopening a file "
                L"selects its existing tab. Ctrl+W or middle-click closes a tab; Close All closes every "
                L"tab. The File menu remembers eight recent files. The tab header's context menu includes "
                L"Close Tab. Enable Close tabs on double-click in Preferences to close a tab by "
                L"double-clicking its header. This option is off by default and is saved. Double-click in "
                L"the report text selects a word. Triple-click selects a logical line. Dragging extends "
                L"the selection by words or lines.\r\nOpen Folder… opens files directly in the selected "
                L"folder, each in its own tab. Subfolders are not included.\r\nOpen and Open Folder share "
                L"their last selected folder. Export remembers its own folder, defaulting to Documents. "
                L"Advanced Mode shows additional report fields.\r\nKnown Formats / Known Codecs / Known "
                L"Parameters — MediaInfo.dll.\r\nFull Parsing examines the entire file and can take "
                L"longer. These report options and Trace Level belong to each tab; a change refreshes "
                L"only the active tab. The last manually chosen combination is saved for new tabs and the "
                L"next launch. A matching cached report is reused while the file remains unchanged.\r\n"
                L"Trace Level: 0 / 5 / 9 / 10.\r\nFile > Page Setup… opens paper, orientation and margin "
                L"settings for the current application session. Print… (Ctrl+P) opens the system print "
                L"dialog; Windows 11 provides a preview, while Windows 10 and earlier keep the classic "
                L"dialog. Ctrl+P prints the active tab in the main window, or the text area in Help or "
                L"About, according to which window has focus. Reports use the selected report font, Help "
                L"uses the system dialog font, and About uses its text area's font. If no tabs are open "
                L"and Help is open, Page Setup… and Print… remain available; Print… prints Help. Printing "
                L"from Help uses the main window's dialog; pressing Ctrl+P in Help again brings it to the "
                L"foreground. Long lines wrap and the text is split into pages. Printing runs in the "
                L"background.\r\nDrag one or more files onto the window, the EXE icon or its shortcut, or "
                L"pass their paths on the command line. If multiple instances are disabled, the files "
                L"open in the running window.\r\nThe left status pane shows file paths and loading "
                L"progress; the right pane shows the loaded MediaInfo.dll version. Long paths are "
                L"shortened with an ellipsis to fit the available space.\r\n\r\nEXPORT\r\nTXT, BMP, GIF, "
                L"JPEG, PNG, TIFF and WebP are listed when available. The last export folder and format "
                L"are remembered.\r\nTXT offers ANSI, UTF-8, UTF-8 with BOM, UTF-16 BE with BOM and "
                L"UTF-16 LE with BOM. The second entry, UTF-8 without BOM, is the default. The complete "
                L"report text and its original line endings are preserved.\r\n\r\nCREATE A HEADER FILE\r\n"
                L"Tools is the fourth main menu. Its Create a Header File… command opens one source file "
                L"independently of the report tabs and copies its first 524288 bytes (512 KiB). A shorter "
                L"file is copied in full; an empty file produces an empty output. This is ordinary binary "
                L"file reading, without MediaInfo analysis or a requirement for MediaInfo.dll. The tool "
                L"leaves report tabs and the viewer's recent-files list unchanged.\r\n\r\nAfter reading, "
                L"the Save As dialog starts in the source file's folder and suggests video.mp4.header for "
                L"video.mp4: .header is appended to the complete original name. You can change both the "
                L"name and the destination folder. Cancelling either dialog writes no output. Replacing "
                L"an existing destination requires confirmation. The source stays unchanged; a failed "
                L"save preserves the previous destination. Open and Save use the newest native dialogs "
                L"available on the current Windows version.\r\n\r\nAt application startup, the tool takes "
                L"its initial input folder from File > Open. If no folder has been saved, Windows chooses "
                L"the initial location. After an input file is selected, the tool remembers its own "
                L"folder only until the application exits, even if Save As is cancelled. It neither "
                L"changes the folders used by Open and Export nor saves its own folder to the application "
                L"settings. Every Save As dialog starts in the folder of the currently selected input "
                L"file, regardless of the previous save destination.\r\n\r\nPREFERENCES AND LANGUAGES\r\n"
                L"Preferences (Options > Preferences, Ctrl+G) contains library paths, report font, "
                L"antialiasing and language choices. The interface has 36 variants and initially follows "
                L"Windows. Reports always default to the library’s original English, independently of "
                L"Windows and the interface. Only a manual report-language choice changes this: English, "
                L"37 translations or a custom MediaInfo CSV table. OK or Apply commits changes; Cancel "
                L"discards pending edits. Preferences sets the tab name limit (80 by default) and clears "
                L"the recent-files list. Long names retain their beginning, ending and extension with a "
                L"middle ellipsis. Clear removes the recent-files list immediately, even if Preferences "
                L"is then cancelled.\r\n\r\nThe main window title shows the active file as filename — "
                L"MediaInfo. Preferences sets a separate title name limit of 8–255 characters (40 by "
                L"default). Longer names use the same middle ellipsis and retain the extension. With no open "
                L"tabs, the title is MediaInfo.\r\n\r\nLIBRARIES AND WINDOWS\r\nThe executable embeds "
                L"MediaInfo "
                L"26.10, 21.03 and 0.7.60, tried newest first after external libraries. The two newer "
                L"versions have matching libcurl libraries; 0.7.60 never extracts libcurl. Window "
                L"placement is saved. By default, only one instance is allowed and later launches send "
                L"files to the open window. Preferences can allow multiple instances. With multiple "
                L"windows, only the first window of each window type restores its saved position; later "
                L"windows restore size only.\r\n\r\nEdit > Find (Ctrl+F) searches the active report tab "
                L"or the text area in Help or About, according to which window has focus. The Find window "
                L"retains the last selected source while it has focus. F3 repeats the search; Shift+F3 "
                L"reverses its direction. Searching wraps at the ends of the text. Options > Word Wrap "
                L"affects only the active tab, and its check mark follows the selected tab. The search "
                L"window can be minimised and resized horizontally; its position and Always on Top "
                L"setting are remembered. Up to 30 search texts and their options are retained only until "
                L"the application exits. Starts with and Ends with match the edges of logical lines. "
                L"Regular expressions use PCRE2 syntax. The other Edit menu commands apply to the active "
                L"report tab. Enter searches; Shift+Enter reverses the selected direction. \"Case "
                L"sensitive\" distinguishes uppercase and lowercase; \"Backward\" searches toward the "
                L"start of the text. Choosing a history entry restores all five search options, including "
                L"the saved regular-expression mode; \"Always on top\" is independent. \"Regular "
                L"expression\" disables \"Starts with\" and \"Ends with\". With both line-edge options "
                L"enabled, either edge can match. \"Word Wrap\" changes only the display."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"The WebP image could not be saved. Check the destination and available memory and disk "
                L"space."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Text Document UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Text Document UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Text Document UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Text Document UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"The report cannot be saved in this encoding without losing characters. Choose another text "
                L"encoding."
            },
            { TXT_OPEN_FOLDER, L"Open &Folder…" },
            { TXT_OPEN_FOLDER_TITLE, L"Open Folder" },
            { TXT_FOLDER_READ_FAILED, L"The folder could not be read:\n\n%s\n\nWindows error %lu." },
            { TXT_ADVANCED_MODE, L"&Advanced Mode" },
            { TXT_REPORT_DETAIL_REJECTED, L"The selected MediaInfo.dll rejected the report detail setting." },
            { TXT_KNOWN_FORMATS, L"Known &Formats" },
            { TXT_KNOWN_CODECS, L"Known &Codecs" },
            { TXT_KNOWN_PARAMETERS, L"Known &Parameters" },
            { TXT_KNOWN_FORMATS_TITLE, L"Known Formats" },
            { TXT_KNOWN_CODECS_TITLE, L"Known Codecs" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Known Parameters" },
            { TXT_KNOWN_INFO_FAILED, L"The library did not return the requested information." },
            { TXT_FULL_PARSING, L"&Full Parsing" },
            { TXT_PARSING_REJECTED, L"The selected MediaInfo.dll rejected the parsing setting." },
            { TXT_TRACE_LEVEL_0, L"Trace Level &0" },
            { TXT_TRACE_LEVEL_5, L"Trace Level &5" },
            { TXT_TRACE_LEVEL_9, L"Trace Level &9" },
            { TXT_TRACE_LEVEL_10, L"Trace Level &10" },
            { TXT_PAGE_SETUP, L"Page Set&up…" },
            { TXT_PAGE_SETUP_FAILED, L"The Page Setup dialog could not be opened." },
            { TXT_PRINT, L"&Print…\tCtrl+P" },
            { TXT_PRINTING, L"Printing…" },
            { TXT_PRINT_FAILED,
                L"The text could not be printed. Check the printer, its settings and available memory."
            },
            { TXT_TOOLS_MENU, L"&Tools" },
            { TXT_CREATE_HEADER, L"Create a &Header File…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Create a Header File - Open" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Create a Header File - Save As" },
            { TXT_HEADER_FORMAT, L"Header File (*.header)" },
            { TXT_HEADER_READ_FAILED, L"The file header could not be read:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"The header file could not be saved:\n\n%s" },
            { TXT_COPY, L"&Copy" },
            { TXT_COPY_FILE_NAME, L"Copy File Na&me" },
            { TXT_COPY_FULL_PATH, L"Copy Full Pat&h" },
            { TXT_LAUNCH_FILE, L"&Launch File" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"&Show in Containing Folder" },
            { TXT_EDIT_MENU, L"&Edit" },
            { TXT_WORD_WRAP, L"&Word Wrap" },
            { TXT_WORD_WRAP_FAILED, L"Word wrap could not be changed." },
            { TXT_COPY_SELECTION, L"&Copy\tCtrl+C" },
            { TXT_SELECT_ALL, L"Select &All\tCtrl+A" },
            { TXT_FIND_MENU, L"&Find…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Find &Next\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Find &Previous\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Find" },
            { TXT_FIND_WHAT, L"&Find:" },
            { TXT_FIND_NEXT, L"Fi&nd Next" },
            { TXT_FIND_MATCH_CASE, L"C&ase sensitive" },
            { TXT_FIND_BACKWARD, L"&Backward" },
            { TXT_FIND_TOPMOST, L"Always on &top" },
            { TXT_FIND_STARTS_WITH, L"&Starts with" },
            { TXT_FIND_ENDS_WITH, L"En&ds with" },
            { TXT_FIND_REGEX, L"Regular e&xpression" },
            { TXT_FIND_NOT_FOUND, L"The specified text was not found." },
            { TXT_FIND_FAILED, L"The search could not be completed." },
            { TXT_FIND_REGEX_ERROR, L"Regular expression error:\r\n\r\n%s" },
        }
    },
    {
        LANG_EN_AU,
        {
            { TXT_LANGUAGE_NAME, L"English (Australia)" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nWebsite: " },
            { TXT_FILE_OPEN_FAILED, L"%s could not be opened. Check its path and permissions." },
            { TXT_BROWSE_DLL, L"&Browse…" },
            { TXT_BROWSE_REPORT, L"B&rowse…" },
            { TXT_CLOSE, L"&Close" },
            { TXT_CLOSE_TAB, L"&Close\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"&Default" },
            { TXT_EXPORT, L"&Export…\tCtrl+E" },
            { TXT_FILE_MENU, L"&File" },
            { TXT_REPORT_FONT, L"Report &font:" },
            { TXT_HELP_MENU, L"&Help" },
            { TXT_HELP, L"&Help\tF1" },
            { TXT_LANGUAGE, L"&Language:" },
            { TXT_OPEN_WEBSITE, L"&Open in Default Browser" },
            { TXT_OPEN, L"&Open…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Options" },
            { TXT_PREFERENCES_MENU, L"&Preferences…\tCtrl+G" },
            { TXT_ABOUT, L"&About" },
            { TXT_ABOUT_TITLE, L"About %ls" },
            { TXT_ALL_FILES, L"All Files" },
            { TXT_FONT_BOLD, L"Bold" },
            { TXT_FONT_BOLD_ITALIC, L"Bold Italic" },
            { TXT_BROWSE_CURL, L"Bro&wse…" },
            { TXT_CANCEL, L"Cancel" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Cannot load MediaInfo.dll (Windows error %lu). Use a 32-bit DLL compatible with this "
                L"Windows version."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Cannot load libcurl.dll (Windows error %lu). Select a 32-bit library compatible with this "
                L"Windows version."
            },
            { TXT_CLOSE_ALL, L"Close &All" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Copy &URL" },
            { TXT_COPY_INFORMATION, L"Copy &Information" },
            { TXT_DLL_FILES, L"Dynamic-Link Libraries" },
            { TXT_EXIT, L"E&xit\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Embedded MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Embedded libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Export Report" },
            { TXT_FONT_ANTIALIASING, L"Font a&ntialiasing:" },
            { TXT_GIF_EXPORT_FAILED, L"GIF export failed. Exact GIF output requires at most 256 colours." },
            { TXT_FONT_ITALIC, L"Italic" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED, L"JPEG export failed. A working GDI+ JPEG encoder is required." },
            { TXT_LICENSE_UNAVAILABLE, L"Licence resource unavailable." },
            { TXT_MEDIA_FILES, L"Media Files" },
            { TXT_APPLICATION_DESCRIPTION, L"Media information viewer" },
            { TXT_HELP_TITLE, L"MediaInfo Help" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo could not initialise media analysis." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo could not open or recognise this file." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo Library" },
            { TXT_MEDIALIB_PATH, L"MediaInfo.dll &path:" },
            { TXT_MEDIALIB_REQUIRED, L"MediaInfo.dll is not loaded. Select it in Options > Preferences." },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll not loaded." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"No compatible external or bundled MediaInfo.dll could be loaded. Select a compatible DLL "
                L"in Options > Preferences."
            },
            { TXT_ANTIALIASING_NONE, L"None" },
            { TXT_OK, L"OK" },
            { TXT_OPEN_TITLE, L"Open Media Files" },
            { TXT_PLATFORM, L"Platform:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Preferences" },
            { TXT_READY, L"Ready" },
            { TXT_FONT_REGULAR, L"Regular" },
            { TXT_REPORT_LANGUAGE, L"Repor&t language:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Report Language Tables" },
            { TXT_SELECT_MEDIALIB, L"Select MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Select a Report Language CSV File" },
            { TXT_INVALID_MEDIA_PATH, L"Select an existing media file with a path shorter than MAX_PATH." },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Select files with paths shorter than MAX_PATH." },
            { TXT_SELECT_CURL, L"Select libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Text Document ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"The BMP image could not be saved. Check the destination and available memory and disk "
                L"space."
            },
            { TXT_LIBRARY_WORKER_START_FAILED,
                L"The MediaInfo library worker could not be started (Windows error %lu)."
            },
            { TXT_REPORT_COPY_FAILED, L"The MediaInfo report could not be copied into memory." },
            { TXT_VIEWER_CREATE_FAILED, L"The MediaInfo viewer could not be created." },
            { TXT_MEDIALIB_PATH_INVALID, L"The MediaInfo.dll path is invalid or too long." },
            { TXT_PNG_EXPORT_FAILED,
                L"The PNG image could not be saved. Check the destination and available memory and disk "
                L"space."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"The TIFF image could not be saved. Check the destination and available memory and disk "
                L"space."
            },
            { TXT_COPY_URL_FAILED, L"The URL could not be copied to the clipboard." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"The Win32 viewer requires a 32-bit %s. Select the x86/i386 library."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"The bundled library could not be written to AppData, the user profile, Program Files or "
                L"the temporary directory."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED,
                L"The bundled library failed decompression or CRC verification."
            },
            { TXT_LIBRARY_RESOURCE_INVALID, L"The bundled library resource is invalid." },
            { TXT_CURL_FILENAME_INVALID,
                L"The curl library must be named libcurl.dll so MediaInfo can use it."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"The file dialog could not be opened." },
            { TXT_FILE_DIALOG_SELECTION_FAILED, L"The file dialog could not return the selected files." },
            { TXT_RECENT_FILE_MISSING,
                L"The file \"%s\" no longer exists.\n\nRemove this entry from the recent files list?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"The file is no longer available:\n\n%s\n\nRemove this entry from the recent files list?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"The information could not be copied to the clipboard." },
            { TXT_CURL_PATH_INVALID, L"The libcurl.dll path is invalid or too long." },
            { TXT_MEDIALIB_VERSION_MISSING, L"The library did not return a MediaInfo version." },
            { TXT_CURL_EXPORTS_MISSING,
                L"The library does not export the curl functions required by MediaInfo."
            },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"The library does not export the required Unicode MediaInfo functions."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"The library worker failed during %s (process exit code 0x%08lX). Select a compatible "
                L"MediaInfo.dll in Options > Preferences."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"The library worker stopped responding during %s. Select a compatible MediaInfo.dll in "
                L"Options > Preferences."
            },
            { TXT_PREFERENCES_SAVE_FAILED,
                L"The preferences were applied, but could not be saved in the registry."
            },
            { TXT_REPORT_START_FAILED, L"The report could not be started: insufficient memory." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"The report image could not be created." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"The report language table could not be loaded. Select a "
                L"valid UTF-8 or UTF-16 MediaInfo CSV file." },
            { TXT_REPORT_THREAD_START_FAILED, L"The report thread could not be started." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"The selected MediaInfo.dll rejected the report language." },
            { TXT_INVALID_WINDOWS_DLL, L"The selected file is not a valid Windows DLL." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"The selected image format is not supported." },
            { TXT_TEXT_EXPORT_FAILED,
                L"The text report could not be saved. Check the destination and available disk space."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"The website could not be opened in the default browser." },
            { TXT_TOO_MANY_FILES, L"Too many files were selected. Open them in smaller groups." },
            { TXT_LIBRARY_PATH_HINT,
                L"Use 32-bit libraries compatible with your Windows version. Leave paths empty for automatic "
                L"discovery. MediaInfoLib v0.7.60 does not use libcurl.dll."
            },
            { TXT_VERSION, L"Version" },
            { TXT_WEBSITE_TOOLTIP, L"Visit %s" },
            { TXT_WAITING_FOR_REPORT, L"Waiting for the current report to finish." },
            { TXT_WEBSITE_LABEL, L"Website:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"copying the MediaInfo report" },
            { TXT_CURL_LIBRARY, L"curl library" },
            { TXT_CURL_PATH, L"libc&url.dll path:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"loading MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"loading libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"unloading MediaInfo.dll" },
            { TXT_APPLY, L"&Apply" },
            { TXT_TAB_NAME_LENGTH, L"Tab name len&gth:" },
            { TXT_TITLE_NAME_LENGTH, L"Titl&e length:" },
            { TXT_RECENT_FILES, L"Recent files:" },
            { TXT_CLEAR_RECENT_FILES, L"&Clear" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"The tab name length must be between 8 and 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"The title name length must be between 8 and 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"The recent files list was cleared, but could not be saved in the registry."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"Close tabs on double-clic&k" },
            { TXT_CLOSE_TAB_CONTEXT, L"Close &Tab" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"Allow multiple &instances" },
            { TXT_INSTANCE_FORWARD_FAILED,
                L"The files could not be passed to the running MediaInfo instance."
            },
            { TXT_LOADING, L"Loading…" },
            { TXT_LOADING_FILE, L"Loading file %s…" },
            { TXT_APPLICATION_HELP,
                L"FILES AND TABS\r\nNative x86 Windows viewer for MediaInfo.dll reports. Each file has "
                L"its own read-only tab. Open files with Ctrl+O or drag and drop. Reopening a file "
                L"selects its existing tab. Ctrl+W or middle-click closes a tab; Close All closes every "
                L"tab. The File menu remembers eight recent files. The tab header's context menu includes "
                L"Close Tab. Enable Close tabs on double-click in Preferences to close a tab by "
                L"double-clicking its header. This option is off by default and is saved. Double-click in "
                L"the report text selects a word. Triple-click selects a logical line. Dragging extends "
                L"the selection by words or lines.\r\nOpen Folder… opens files directly in the selected "
                L"folder, each in its own tab. Subfolders are not included.\r\nOpen and Open Folder share "
                L"their last selected folder. Export remembers its own folder, defaulting to Documents. "
                L"Advanced Mode shows additional report fields.\r\nKnown Formats / Known Codecs / Known "
                L"Parameters — MediaInfo.dll.\r\nFull Parsing examines the entire file and can take "
                L"longer. These report options and Trace Level belong to each tab; a change refreshes "
                L"only the active tab. The last manually chosen combination is saved for new tabs and the "
                L"next launch. A matching cached report is reused while the file remains unchanged.\r\n"
                L"Trace Level: 0 / 5 / 9 / 10.\r\nFile > Page Setup… opens paper, orientation and margin "
                L"settings for the current application session. Print… (Ctrl+P) opens the system print "
                L"dialog; Windows 11 provides a preview, while Windows 10 and earlier keep the classic "
                L"dialog. Ctrl+P prints the active tab in the main window, or the text area in Help or "
                L"About, according to which window has focus. Reports use the selected report font, Help "
                L"uses the system dialog font, and About uses its text area's font. If no tabs are open "
                L"and Help is open, Page Setup… and Print… remain available; Print… prints Help. Printing "
                L"from Help uses the main window's dialog; pressing Ctrl+P in Help again brings it to the "
                L"foreground. Long lines wrap and the text is split into pages. Printing runs in the "
                L"background.\r\nDrag one or more files onto the window, the EXE icon or its shortcut, or "
                L"pass their paths on the command line. If multiple instances are disabled, the files "
                L"open in the running window.\r\nThe left status pane shows file paths and loading "
                L"progress; the right pane shows the loaded MediaInfo.dll version. Long paths are "
                L"shortened with an ellipsis to fit the available space.\r\n\r\nEXPORT\r\nTXT, BMP, GIF, "
                L"JPEG, PNG, TIFF and WebP are listed when available. The last export folder and format "
                L"are remembered.\r\nTXT offers ANSI, UTF-8, UTF-8 with BOM, UTF-16 BE with BOM and "
                L"UTF-16 LE with BOM. The second entry, UTF-8 without BOM, is the default. The complete "
                L"report text and its original line endings are preserved.\r\n\r\nCREATE A HEADER FILE\r\n"
                L"Tools is the fourth main menu. Its Create a Header File… command opens one source file "
                L"independently of the report tabs and copies its first 524288 bytes (512 KiB). A shorter "
                L"file is copied in full; an empty file produces an empty output. This is ordinary binary "
                L"file reading, without MediaInfo analysis or a requirement for MediaInfo.dll. The tool "
                L"leaves report tabs and the viewer's recent-files list unchanged.\r\n\r\nAfter reading, "
                L"the Save As dialog starts in the source file's folder and suggests video.mp4.header for "
                L"video.mp4: .header is appended to the complete original name. You can change both the "
                L"name and the destination folder. Cancelling either dialog writes no output. Replacing "
                L"an existing destination requires confirmation. The source stays unchanged; a failed "
                L"save preserves the previous destination. Open and Save use the newest native dialogs "
                L"available on the current Windows version.\r\n\r\nAt application startup, the tool takes "
                L"its initial input folder from File > Open. If no folder has been saved, Windows chooses "
                L"the initial location. After an input file is selected, the tool remembers its own "
                L"folder only until the application exits, even if Save As is cancelled. It neither "
                L"changes the folders used by Open and Export nor saves its own folder to the application "
                L"settings. Every Save As dialog starts in the folder of the currently selected input "
                L"file, regardless of the previous save destination.\r\n\r\nPREFERENCES AND LANGUAGES\r\n"
                L"Preferences (Options > Preferences, Ctrl+G) contains library paths, report font, "
                L"antialiasing and language choices. The interface has 36 variants and initially follows "
                L"Windows. Reports always default to the library’s original English, independently of "
                L"Windows and the interface. Only a manual report-language choice changes this: English, "
                L"37 translations or a custom MediaInfo CSV table. OK or Apply commits changes; Cancel "
                L"discards pending edits. Preferences sets the tab name limit (80 by default) and clears "
                L"the recent-files list. Long names retain their beginning, ending and extension with a "
                L"middle ellipsis. Clear removes the recent-files list immediately, even if Preferences "
                L"is then cancelled.\r\n\r\nThe main window title shows the active file as filename — "
                L"MediaInfo. Preferences sets a separate title name limit of 8–255 characters (40 by "
                L"default). Longer names use the same middle ellipsis and retain the extension. With no open "
                L"tabs, the title is MediaInfo.\r\n\r\nLIBRARIES AND WINDOWS\r\nThe executable embeds "
                L"MediaInfo "
                L"26.10, 21.03 and 0.7.60, tried newest first after external libraries. The two newer "
                L"versions have matching libcurl libraries; 0.7.60 never extracts libcurl. Window "
                L"placement is saved. By default, only one instance is allowed and later launches send "
                L"files to the open window. Preferences can allow multiple instances. With multiple "
                L"windows, only the first window of each window type restores its saved position; later "
                L"windows restore size only.\r\n\r\nEdit > Find (Ctrl+F) searches the active report tab "
                L"or the text area in Help or About, according to which window has focus. The Find window "
                L"retains the last selected source while it has focus. F3 repeats the search; Shift+F3 "
                L"reverses its direction. Searching wraps at the ends of the text. Options > Word Wrap "
                L"affects only the active tab, and its check mark follows the selected tab. The search "
                L"window can be minimised and resized horizontally; its position and Always on Top "
                L"setting are remembered. Up to 30 search texts and their options are retained only until "
                L"the application exits. Starts with and Ends with match the edges of logical lines. "
                L"Regular expressions use PCRE2 syntax. The other Edit menu commands apply to the active "
                L"report tab. Enter searches; Shift+Enter reverses the selected direction. \"Case "
                L"sensitive\" distinguishes uppercase and lowercase; \"Backward\" searches toward the "
                L"start of the text. Choosing a history entry restores all five search options, including "
                L"the saved regular-expression mode; \"Always on top\" is independent. \"Regular "
                L"expression\" disables \"Starts with\" and \"Ends with\". With both line-edge options "
                L"enabled, either edge can match. \"Word Wrap\" changes only the display."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"The WebP image could not be saved. Check the destination and available memory and disk "
                L"space."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Text Document UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Text Document UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Text Document UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Text Document UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"The report cannot be saved in this encoding without losing characters. Choose another text "
                L"encoding."
            },
            { TXT_OPEN_FOLDER, L"Open &Folder…" },
            { TXT_OPEN_FOLDER_TITLE, L"Open Folder" },
            { TXT_FOLDER_READ_FAILED, L"The folder could not be read:\n\n%s\n\nWindows error %lu." },
            { TXT_ADVANCED_MODE, L"&Advanced Mode" },
            { TXT_REPORT_DETAIL_REJECTED, L"The selected MediaInfo.dll rejected the report detail setting." },
            { TXT_KNOWN_FORMATS, L"Known &Formats" },
            { TXT_KNOWN_CODECS, L"Known &Codecs" },
            { TXT_KNOWN_PARAMETERS, L"Known &Parameters" },
            { TXT_KNOWN_FORMATS_TITLE, L"Known Formats" },
            { TXT_KNOWN_CODECS_TITLE, L"Known Codecs" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Known Parameters" },
            { TXT_KNOWN_INFO_FAILED, L"The library did not return the requested information." },
            { TXT_FULL_PARSING, L"&Full Parsing" },
            { TXT_PARSING_REJECTED, L"The selected MediaInfo.dll rejected the parsing setting." },
            { TXT_TRACE_LEVEL_0, L"Trace Level &0" },
            { TXT_TRACE_LEVEL_5, L"Trace Level &5" },
            { TXT_TRACE_LEVEL_9, L"Trace Level &9" },
            { TXT_TRACE_LEVEL_10, L"Trace Level &10" },
            { TXT_PAGE_SETUP, L"Page Set&up…" },
            { TXT_PAGE_SETUP_FAILED, L"The Page Setup dialog could not be opened." },
            { TXT_PRINT, L"&Print…\tCtrl+P" },
            { TXT_PRINTING, L"Printing…" },
            { TXT_PRINT_FAILED,
                L"The text could not be printed. Check the printer, its settings and available memory."
            },
            { TXT_TOOLS_MENU, L"&Tools" },
            { TXT_CREATE_HEADER, L"Create a &Header File…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Create a Header File - Open" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Create a Header File - Save As" },
            { TXT_HEADER_FORMAT, L"Header File (*.header)" },
            { TXT_HEADER_READ_FAILED, L"The file header could not be read:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"The header file could not be saved:\n\n%s" },
            { TXT_COPY, L"&Copy" },
            { TXT_COPY_FILE_NAME, L"Copy File Na&me" },
            { TXT_COPY_FULL_PATH, L"Copy Full Pat&h" },
            { TXT_LAUNCH_FILE, L"&Launch File" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"&Show in Containing Folder" },
            { TXT_EDIT_MENU, L"&Edit" },
            { TXT_WORD_WRAP, L"&Word Wrap" },
            { TXT_WORD_WRAP_FAILED, L"Word wrap could not be changed." },
            { TXT_COPY_SELECTION, L"&Copy\tCtrl+C" },
            { TXT_SELECT_ALL, L"Select &All\tCtrl+A" },
            { TXT_FIND_MENU, L"&Find…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Find &Next\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Find &Previous\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Find" },
            { TXT_FIND_WHAT, L"&Find:" },
            { TXT_FIND_NEXT, L"Fi&nd Next" },
            { TXT_FIND_MATCH_CASE, L"C&ase sensitive" },
            { TXT_FIND_BACKWARD, L"&Backward" },
            { TXT_FIND_TOPMOST, L"Always on &top" },
            { TXT_FIND_STARTS_WITH, L"&Starts with" },
            { TXT_FIND_ENDS_WITH, L"En&ds with" },
            { TXT_FIND_REGEX, L"Regular e&xpression" },
            { TXT_FIND_NOT_FOUND, L"The specified text was not found." },
            { TXT_FIND_FAILED, L"The search could not be completed." },
            { TXT_FIND_REGEX_ERROR, L"Regular expression error:\r\n\r\n%s" },
        }
    },
    {
        LANG_DE,
        {
            { TXT_LANGUAGE_NAME, L"Deutsch" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nWebsite: " },
            { TXT_FILE_OPEN_FAILED, L"%s kann nicht geöffnet werden. Prüfen Sie Pfad und Berechtigungen." },
            { TXT_BROWSE_DLL, L"&Durchsuchen…" },
            { TXT_BROWSE_REPORT, L"Durc&hsuchen…" },
            { TXT_CLOSE, L"&Schließen" },
            { TXT_CLOSE_TAB, L"&Schließen\tStrg+W" },
            { TXT_FONT_DEFAULT, L"St&andard" },
            { TXT_EXPORT, L"&Exportieren…\tStrg+E" },
            { TXT_FILE_MENU, L"&Datei" },
            { TXT_REPORT_FONT, L"&Schriftart des Berichts:" },
            { TXT_HELP_MENU, L"&Hilfe" },
            { TXT_HELP, L"&Hilfe\tF1" },
            { TXT_LANGUAGE, L"Sp&rache:" },
            { TXT_OPEN_WEBSITE, L"Im Standardbrowser &öffnen" },
            { TXT_OPEN, L"&Öffnen…\tStrg+O" },
            { TXT_OPTIONS_MENU, L"&Optionen" },
            { TXT_PREFERENCES_MENU, L"&Voreinstellungen…\tStrg+G" },
            { TXT_ABOUT, L"&Info" },
            { TXT_ABOUT_TITLE, L"Info zu %ls" },
            { TXT_ALL_FILES, L"Alle Dateien" },
            { TXT_FONT_BOLD, L"Fett" },
            { TXT_FONT_BOLD_ITALIC, L"Fett + Kursiv" },
            { TXT_BROWSE_CURL, L"Dur&chsuchen…" },
            { TXT_CANCEL, L"Abbrechen" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"MediaInfo.dll kann nicht geladen werden (Windows-Fehler %lu). Verwenden Sie eine mit "
                L"dieser Windows-Version kompatible 32-Bit-DLL."
            },
            { TXT_CURL_LOAD_FAILED,
                L"libcurl.dll kann nicht geladen werden (Windows-Fehler %lu). Wählen Sie eine mit dieser "
                L"Windows-Version kompatible 32-Bit-Bibliothek."
            },
            { TXT_CLOSE_ALL, L"&Alle schließen" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"&URL kopieren" },
            { TXT_COPY_INFORMATION, L"&Informationen kopieren" },
            { TXT_DLL_FILES, L"Dynamische Bibliotheken" },
            { TXT_EXIT, L"&Beenden\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Eingebettete Bibliotheken MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Eingebettete Bibliotheken libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Bericht exportieren" },
            { TXT_FONT_ANTIALIASING, L"Schrift&glättung:" },
            { TXT_GIF_EXPORT_FAILED,
                L"GIF-Export fehlgeschlagen. Verlustfreies GIF erlaubt höchstens 256 Farben."
            },
            { TXT_FONT_ITALIC, L"Kursiv" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED,
                L"JPEG-Export fehlgeschlagen. Ein funktionsfähiger GDI+-JPEG-Encoder ist erforderlich."
            },
            { TXT_LICENSE_UNAVAILABLE, L"Die Lizenzressource ist nicht verfügbar." },
            { TXT_MEDIA_FILES, L"Mediendateien" },
            { TXT_APPLICATION_DESCRIPTION, L"Betrachter für Medieninformationen" },
            { TXT_HELP_TITLE, L"MediaInfo — Hilfe" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo konnte die Medienanalyse nicht initialisieren." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo kann diese Datei nicht öffnen oder erkennen." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"MediaInfo.dll-&Pfad:" },
            { TXT_MEDIALIB_REQUIRED,
                L"MediaInfo.dll ist nicht geladen. Wählen Sie sie unter Optionen > Voreinstellungen."
            },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll ist nicht geladen." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Keine kompatible externe oder eingebettete MediaInfo.dll konnte geladen werden. Wählen "
                L"Sie sie unter Optionen > Voreinstellungen."
            },
            { TXT_ANTIALIASING_NONE, L"Keine" },
            { TXT_OK, L"OK" },
            { TXT_OPEN_TITLE, L"Mediendateien öffnen" },
            { TXT_PLATFORM, L"Zielplattform:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Voreinstellungen" },
            { TXT_READY, L"Bereit" },
            { TXT_FONT_REGULAR, L"Normal" },
            { TXT_REPORT_LANGUAGE, L"&Berichtssprache:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Berichtssprachtabellen" },
            { TXT_SELECT_MEDIALIB, L"Durchsuchen: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Durchsuchen: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH,
                L"Wählen Sie eine vorhandene Mediendatei mit einem Pfad, der kürzer als MAX_PATH ist."
            },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Wählen Sie vorhandene Dateien mit Pfaden kürzer als MAX_PATH." },
            { TXT_SELECT_CURL, L"Durchsuchen: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Textdokument ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"Das BMP-Bild kann nicht gespeichert werden. Prüfen Sie Ziel, freien Speicher und "
                L"Speicherplatz."
            },
            { TXT_LIBRARY_WORKER_START_FAILED,
                L"Der Bibliotheksprozess kann nicht gestartet werden (Windows-Fehler %lu)."
            },
            { TXT_REPORT_COPY_FAILED, L"Der MediaInfo-Bericht kann nicht in den Speicher kopiert werden." },
            { TXT_VIEWER_CREATE_FAILED, L"Der MediaInfo-Betrachter kann nicht erstellt werden." },
            { TXT_MEDIALIB_PATH_INVALID, L"Der Pfad zu MediaInfo.dll ist ungültig oder zu lang." },
            { TXT_PNG_EXPORT_FAILED,
                L"Das PNG-Bild kann nicht gespeichert werden. Prüfen Sie Ziel, freien Speicher und "
                L"Speicherplatz."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"Das TIFF-Bild kann nicht gespeichert werden. Prüfen Sie Ziel, freien Speicher und "
                L"Speicherplatz."
            },
            { TXT_COPY_URL_FAILED, L"Die URL konnte nicht in die Zwischenablage kopiert werden." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"Der Win32-Betrachter benötigt eine 32-Bit-%s. Wählen Sie die x86/i386-Bibliothek."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Die eingebettete Bibliothek kann weder in AppData, Benutzerprofil, Program Files noch im "
                L"temporären Ordner gespeichert werden."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED,
                L"Dekomprimierung oder CRC-Prüfung der Bibliothek fehlgeschlagen."
            },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Die eingebettete Bibliotheksressource ist ungültig." },
            { TXT_CURL_FILENAME_INVALID,
                L"Die Bibliothek muss libcurl.dll heißen, damit MediaInfo sie verwenden kann."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Der Dateidialog konnte nicht geöffnet werden." },
            { TXT_FILE_DIALOG_SELECTION_FAILED,
                L"Die ausgewählten Dateien konnten nicht vom Dateidialog abgerufen werden."
            },
            { TXT_RECENT_FILE_MISSING,
                L"Die Datei „%s“ existiert nicht mehr.\n\nDiesen Eintrag aus der Liste der zuletzt "
                L"verwendeten Dateien entfernen?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Die Datei ist nicht mehr verfügbar:\n\n%s\n\nDiesen Eintrag aus der Liste der zuletzt "
                L"verwendeten Dateien entfernen?"
            },
            { TXT_COPY_INFORMATION_FAILED,
                L"Die Informationen konnten nicht in die Zwischenablage kopiert werden."
            },
            { TXT_CURL_PATH_INVALID, L"Der Pfad zu libcurl.dll ist ungültig oder zu lang." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Die Bibliothek hat keine MediaInfo-Version zurückgegeben." },
            { TXT_CURL_EXPORTS_MISSING,
                L"Die Bibliothek exportiert nicht die von MediaInfo benötigten curl-Funktionen."
            },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"Die Bibliothek exportiert nicht die erforderlichen Unicode-Funktionen von MediaInfo."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Der Bibliotheksprozess ist beim %s fehlgeschlagen (Code 0x%08lX). Wählen Sie eine "
                L"kompatible DLL unter Optionen > Voreinstellungen."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Der Bibliotheksprozess reagiert beim %s nicht mehr. Wählen Sie eine kompatible DLL unter "
                L"Optionen > Voreinstellungen."
            },
            { TXT_PREFERENCES_SAVE_FAILED,
                L"Die Einstellungen wurden angewendet, konnten jedoch nicht in der Registrierung gespeichert "
                L"werden."
            },
            { TXT_REPORT_START_FAILED, L"Nicht genügend Speicher zum Starten des Berichts." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Das Berichtsbild kann nicht erstellt werden." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Die Sprachtabelle kann nicht geladen werden. Wählen Sie "
                L"eine gültige MediaInfo-CSV-Datei in UTF-8 oder UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"Der Berichtsthread kann nicht gestartet werden." },
            { TXT_REPORT_LANGUAGE_REJECTED,
                L"Die ausgewählte MediaInfo.dll hat die Berichtssprache abgelehnt."
            },
            { TXT_INVALID_WINDOWS_DLL, L"Die ausgewählte Datei ist keine gültige Windows-DLL." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Das ausgewählte Bildformat wird nicht unterstützt." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Der Textbericht kann nicht gespeichert werden. Prüfen Sie Ziel und freien Speicherplatz."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Die Website kann nicht im Standardbrowser geöffnet werden." },
            { TXT_TOO_MANY_FILES, L"Zu viele Dateien ausgewählt. Öffnen Sie kleinere Gruppen." },
            { TXT_LIBRARY_PATH_HINT,
                L"Verwenden Sie 32-Bit-Bibliotheken, die mit Ihrer Windows-Version kompatibel sind. Lassen "
                L"Sie die Pfade für die automatische Suche leer. MediaInfoLib v0.7.60 verwendet libcurl.dll "
                L"nicht."
            },
            { TXT_VERSION, L"Version" },
            { TXT_WEBSITE_TOOLTIP, L"Website %s besuchen" },
            { TXT_WAITING_FOR_REPORT, L"Warten auf den Abschluss des aktuellen Berichts." },
            { TXT_WEBSITE_LABEL, L"Website:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"Kopieren des MediaInfo-Berichts" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"libc&url.dll-Pfad:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"Laden von MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"Laden von libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"Entladen von MediaInfo.dll" },
            { TXT_APPLY, L"Über&nehmen" },
            { TXT_TAB_NAME_LENGTH, L"&Tabnamenlänge:" },
            { TXT_TITLE_NAME_LENGTH, L"T&itellänge:" },
            { TXT_RECENT_FILES, L"Zuletzt verwendete Dateien:" },
            { TXT_CLEAR_RECENT_FILES, L"&Löschen" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"Die Tabnamenlänge muss zwischen 8 und 255 liegen." },
            { TXT_TITLE_NAME_LENGTH_INVALID,
                L"Die Namenslänge im Fenstertitel muss zwischen 8 und 255 liegen."
            },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Die Liste zuletzt verwendeter Dateien wurde gelöscht, konnte jedoch nicht in der "
                L"Registrierung gespeichert werden."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"Tabs per D&oppelklick schließen" },
            { TXT_CLOSE_TAB_CONTEXT, L"T&ab schließen" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"Mehr&ere Instanzen zulassen" },
            { TXT_INSTANCE_FORWARD_FAILED,
                L"Die Dateien konnten nicht an die laufende MediaInfo-Instanz übergeben werden."
            },
            { TXT_LOADING, L"Wird geladen…" },
            { TXT_LOADING_FILE, L"Laden der Datei %s…" },
            { TXT_APPLICATION_HELP,
                L"DATEIEN UND REGISTERKARTEN\r\nNativer x86-Windows-Betrachter für Berichte von "
                L"MediaInfo.dll. Jede Datei erhält einen eigenen schreibgeschützten Tab. Dateien mit "
                L"Strg+O oder per Ziehen öffnen. Erneutes Öffnen wählt den vorhandenen Tab. Strg+W oder "
                L"die mittlere Maustaste schließt einen Tab; Alle schließen schließt sämtliche Tabs. Das "
                L"Menü Datei merkt sich acht zuletzt verwendete Dateien. Das Kontextmenü eines Tabreiters "
                L"enthält Tab schließen. Aktivieren Sie Tabs per Doppelklick schließen in den "
                L"Voreinstellungen, um einen Tab durch Doppelklick auf seinen Reiter zu schließen. Die "
                L"Option ist anfangs deaktiviert und wird gespeichert. Ein Doppelklick im Berichtstext "
                L"wählt ein Wort aus. Ein Dreifachklick wählt eine logische Zeile aus. Ziehen erweitert "
                L"die Auswahl um Wörter oder Zeilen.\r\nOrdner öffnen… öffnet die Dateien direkt im "
                L"ausgewählten Ordner jeweils in einer eigenen Registerkarte. Unterordner werden nicht "
                L"einbezogen.\r\nÖffnen und Ordner öffnen verwenden gemeinsam den zuletzt ausgewählten "
                L"Ordner. Export merkt sich einen eigenen Ordner; standardmäßig ist dies Dokumente. Der "
                L"erweiterte Modus zeigt zusätzliche Berichtsfelder an.\r\nBekannte Formate / Bekannte "
                L"Codecs / Bekannte Parameter — MediaInfo.dll.\r\nVollständige Analyse untersucht die "
                L"gesamte Datei und kann länger dauern. Diese Berichtsoptionen und Trace-Stufe gehören zu "
                L"jeder Registerkarte; eine Änderung aktualisiert nur die aktive Registerkarte. Die "
                L"zuletzt manuell gewählte Kombination wird für neue Registerkarten und den nächsten "
                L"Start gespeichert. Ein übereinstimmender zwischengespeicherter Bericht wird "
                L"wiederverwendet, solange die Datei unverändert bleibt.\r\nTrace-Stufe: 0 / 5 / 9 / "
                L"10.\r\nDatei > Seite einrichten… öffnet die Einstellungen für Papier, Ausrichtung und "
                L"Ränder für die aktuelle Sitzung. Drucken… (Strg+P) öffnet den Systemdruckdialog; "
                L"Windows 11 bietet eine Vorschau, Windows 10 und ältere Versionen behalten den "
                L"klassischen Dialog. Strg+P druckt je nach Fensterfokus den aktiven Tab des "
                L"Hauptfensters oder den Textbereich in Hilfe oder Info. Berichte verwenden die gewählte "
                L"Berichtsschrift, Hilfe die Systemdialogschrift und Info die Schrift seines "
                L"Textbereichs. Sind keine Tabs geöffnet, aber die Hilfe ist offen, bleiben Seite "
                L"einrichten… und Drucken… verfügbar; Drucken… druckt die Hilfe. Die Hilfe verwendet den "
                L"Druckdialog des Hauptfensters; erneutes Strg+P in der Hilfe holt ihn in den "
                L"Vordergrund. Lange Zeilen werden umgebrochen und der Text auf Seiten verteilt. Der "
                L"Druck läuft im Hintergrund.\r\nZiehen Sie eine oder mehrere Dateien auf das Fenster, "
                L"das EXE-Symbol oder dessen Verknüpfung, oder übergeben Sie die Pfade in der "
                L"Befehlszeile. Wenn mehrere Instanzen nicht erlaubt sind, werden die Dateien im bereits "
                L"geöffneten Fenster angezeigt.\r\nLinks in der Statusleiste werden Dateipfade und der "
                L"Ladefortschritt angezeigt, rechts die Version der geladenen MediaInfo.dll. Lange Pfade "
                L"werden passend zum verfügbaren Platz mit Auslassungspunkten gekürzt.\r\n\r\nEXPORT\r\n"
                L"TXT, BMP, GIF, JPEG, PNG, TIFF und WebP werden je nach Verfügbarkeit angeboten. "
                L"Exportordner und Format werden gespeichert.\r\nTXT bietet ANSI, UTF-8, UTF-8 mit BOM, "
                L"UTF-16 BE mit BOM und UTF-16 LE mit BOM. Standard ist der zweite Eintrag, UTF-8 ohne "
                L"BOM. Der vollständige Berichtstext und seine ursprünglichen Zeilenumbrüche bleiben "
                L"erhalten.\r\n\r\nHEADER-DATEI ERSTELLEN\r\nDas Menü Extras ist der vierte Eintrag in "
                L"der Menüleiste. Sein Befehl Header-Datei erstellen… öffnet eine Quelldatei unabhängig "
                L"von den Berichtsregisterkarten und kopiert deren erste 524288 Bytes (512 KiB). Eine "
                L"kürzere Datei wird vollständig kopiert; eine leere Datei erzeugt eine leere Ausgabe. "
                L"Dabei handelt es sich um das normale Lesen von Binärdateien ohne MediaInfo-Analyse und "
                L"ohne MediaInfo.dll. Das Tool lässt die Berichtsregisterkarten und die Liste der zuletzt "
                L"verwendeten Dateien des Viewers unverändert.\r\n\r\nNach dem Lesen startet der Dialog "
                L"„Speichern unter“ im Ordner der Quelldatei und schlägt video.mp4.header für video.mp4 "
                L"vor: .header wird an den vollständigen Originalnamen angehängt. Sie können sowohl den "
                L"Namen als auch den Zielordner ändern. Wenn Sie einen der beiden Dialoge abbrechen, wird "
                L"keine Ausgabe geschrieben. Das Ersetzen eines vorhandenen Ziels erfordert eine "
                L"Bestätigung. Die Quelldatei bleibt unverändert; bei einer fehlgeschlagenen Speicherung "
                L"bleibt das vorherige Ziel erhalten. Zum Öffnen und Speichern werden die modernsten "
                L"Systemdialoge verwendet, die auf dieser Windows-Version verfügbar sind.\r\n\r\nBeim "
                L"Start der Anwendung übernimmt das Tool seinen anfänglichen Eingabeordner von Datei > "
                L"Öffnen. Wenn kein Ordner gespeichert wurde, wählt Windows den ursprünglichen "
                L"Speicherort. Nachdem eine Eingabedatei ausgewählt wurde, merkt sich das Tool seinen "
                L"eigenen Ordner nur, bis die Anwendung beendet wird, auch wenn „Speichern unter“ "
                L"abgebrochen wird. Es ändert weder die von Öffnen und Exportieren verwendeten Ordner, "
                L"noch speichert es seinen eigenen Ordner in den Anwendungseinstellungen. Jeder Dialog "
                L"„Speichern unter“ startet im Ordner der aktuell ausgewählten Eingabedatei, unabhängig "
                L"vom vorherigen Speicherort.\r\n\r\nVOREINSTELLUNGEN UND SPRACHEN\r\nDie "
                L"Voreinstellungen (Optionen > Voreinstellungen, Strg+G) enthalten Bibliothekspfade, "
                L"Berichtsschrift, Kantenglättung und Sprachen. Die Oberfläche bietet 36 Varianten und "
                L"richtet sich zunächst nach Windows. Berichte verwenden stets das ursprüngliche Englisch "
                L"der Bibliothek, unabhängig von Windows und Oberfläche. Nur die manuelle "
                L"Berichtssprachwahl ändert dies: Englisch, 37 Übersetzungen oder eine eigene "
                L"MediaInfo-CSV-Tabelle. OK oder Übernehmen bestätigt Änderungen; Abbrechen verwirft "
                L"ausstehende Änderungen. Die Voreinstellungen enthalten die Tabnamenlänge (Standard 80) "
                L"und das Löschen der Liste zuletzt verwendeter Dateien. Lange Namen behalten Anfang, "
                L"Ende und Erweiterung mit Auslassungszeichen in der Mitte. Löschen entfernt die Liste "
                L"zuletzt verwendeter Dateien sofort, auch wenn die Voreinstellungen anschließend mit "
                L"Abbrechen geschlossen werden.\r\n\r\nDer Titel des Hauptfensters zeigt die aktive Datei als"
                L" Dateiname — MediaInfo. In den Voreinstellungen lässt sich die Namenslänge im Fenstertitel "
                L"unabhängig auf 8–255 Zeichen festlegen (Standard: 40). Längere Namen werden wie Tabnamen in"
                L" der Mitte mit einem Auslassungszeichen gekürzt; die Erweiterung bleibt erhalten. Ohne "
                L"offene Tabs lautet der Titel MediaInfo.\r\n\r\nBIBLIOTHEKEN UND "
                L"FENSTER\r\nDie EXE enthält "
                L"MediaInfo 26.10, 21.03 und 0.7.60; nach externen Bibliotheken werden sie beginnend mit "
                L"der neuesten geprüft. Die beiden neueren Versionen besitzen passende "
                L"libcurl-Bibliotheken; 0.7.60 entpackt libcurl niemals. Die Fensterposition wird "
                L"gespeichert. Standardmäßig ist nur eine Instanz erlaubt; weitere Starts übergeben "
                L"Dateien an das offene Fenster. In den Voreinstellungen lassen sich mehrere Instanzen "
                L"zulassen. Bei mehreren Fenstern wird die gespeicherte Position nur für das erste "
                L"Fenster jedes Fenstertyps wiederhergestellt; weitere Fenster übernehmen nur die "
                L"Größe.\r\n\r\nBearbeiten > Suchen (Strg+F) durchsucht je nach Fensterfokus den aktiven "
                L"Berichtstab oder den Textbereich in Hilfe oder Info. Solange das Suchfenster den Fokus "
                L"hat, behält es die zuletzt gewählte Quelle bei. F3 wiederholt die Suche; Umschalt+F3 "
                L"kehrt die Suchrichtung um. Am Textende wird die Suche am anderen Ende fortgesetzt. "
                L"Optionen > Zeilenumbruch gilt nur für den aktiven Tab; das Häkchen richtet sich nach "
                L"dem ausgewählten Tab. Das Suchfenster lässt sich minimieren und in der Breite "
                L"verändern; seine Position und die Einstellung Immer im Vordergrund werden gespeichert. "
                L"Bis zu 30 Suchtexte mit ihren Optionen bleiben nur bis zum Beenden der Anwendung "
                L"erhalten. Zeile beginnt mit und Zeile endet mit beziehen sich auf logische Zeilen. "
                L"Reguläre Ausdrücke verwenden die PCRE2-Syntax. Die übrigen Befehle im Menü Bearbeiten "
                L"betreffen den aktiven Berichtstab. Eingabe startet die Suche; Umschalt+Eingabe kehrt "
                L"die gewählte Richtung um. „Groß-/Kleinschreibung beachten“ unterscheidet Groß- und "
                L"Kleinbuchstaben; „Rückwärts suchen“ sucht zum Textanfang hin. Ein Eintrag aus dem "
                L"Verlauf stellt alle fünf Suchoptionen wieder her und schaltet gegebenenfalls den "
                L"Regexmodus aus; „Immer im Vordergrund“ ist unabhängig davon. „Regulärer Ausdruck“ "
                L"deaktiviert „Zeile beginnt mit“ und „Zeile endet mit“. Sind beide Zeilenrandoptionen "
                L"aktiv, genügt ein Treffer an einem Rand. „Zeilenumbruch“ ändert nur die Darstellung."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"Das WebP-Bild kann nicht gespeichert werden. Prüfen Sie Ziel, freien Speicher und "
                L"Speicherplatz."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Textdokument UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Textdokument UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Textdokument UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Textdokument UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Der Bericht kann in dieser Kodierung nicht ohne Zeichenverlust gespeichert werden. Wählen "
                L"Sie eine andere Textkodierung."
            },
            { TXT_OPEN_FOLDER, L"O&rdner öffnen…" },
            { TXT_OPEN_FOLDER_TITLE, L"Ordner öffnen" },
            { TXT_FOLDER_READ_FAILED,
                L"Der Ordner konnte nicht gelesen werden:\n\n%s\n\nWindows-Fehler %lu."
            },
            { TXT_ADVANCED_MODE, L"&Erweiterter Modus" },
            { TXT_REPORT_DETAIL_REJECTED,
                L"Die ausgewählte MediaInfo.dll hat die Einstellung der Berichtsdetails abgelehnt."
            },
            { TXT_KNOWN_FORMATS, L"Bekannte &Formate" },
            { TXT_KNOWN_CODECS, L"Bekannte &Codecs" },
            { TXT_KNOWN_PARAMETERS, L"Bekannte &Parameter" },
            { TXT_KNOWN_FORMATS_TITLE, L"Bekannte Formate" },
            { TXT_KNOWN_CODECS_TITLE, L"Bekannte Codecs" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Bekannte Parameter" },
            { TXT_KNOWN_INFO_FAILED,
                L"Die Bibliothek hat die angeforderten Informationen nicht zurückgegeben."
            },
            { TXT_FULL_PARSING, L"Vollständige &Analyse" },
            { TXT_PARSING_REJECTED, L"Die ausgewählte MediaInfo.dll hat die Analyseeinstellung abgelehnt." },
            { TXT_TRACE_LEVEL_0, L"Trace-Stufe &0" },
            { TXT_TRACE_LEVEL_5, L"Trace-Stufe &5" },
            { TXT_TRACE_LEVEL_9, L"Trace-Stufe &9" },
            { TXT_TRACE_LEVEL_10, L"Trace-Stufe &10" },
            { TXT_PAGE_SETUP, L"Seite ei&nrichten…" },
            { TXT_PAGE_SETUP_FAILED, L"Die Seiteneinrichtung konnte nicht geöffnet werden." },
            { TXT_PRINT, L"&Drucken…\tStrg+P" },
            { TXT_PRINTING, L"Drucken…" },
            { TXT_PRINT_FAILED,
                L"Der Text konnte nicht gedruckt werden. Prüfen Sie den Drucker, seine Einstellungen und "
                L"den verfügbaren Speicher."
            },
            { TXT_TOOLS_MENU, L"E&xtras" },
            { TXT_CREATE_HEADER, L"&Header-Datei erstellen…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Header-Datei erstellen - Öffnen" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Header-Datei erstellen - Speichern unter" },
            { TXT_HEADER_FORMAT, L"Header-Datei (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Der Dateiheader konnte nicht gelesen werden:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Die Header-Datei konnte nicht gespeichert werden:\n\n%s" },
            { TXT_COPY, L"&Kopieren" },
            { TXT_COPY_FILE_NAME, L"Datei&namen kopieren" },
            { TXT_COPY_FULL_PATH, L"Vollständigen Datei&pfad kopieren" },
            { TXT_LAUNCH_FILE, L"Da&tei starten" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"&In Ordner anzeigen" },
            { TXT_EDIT_MENU, L"&Bearbeiten" },
            { TXT_WORD_WRAP, L"&Zeilenumbruch" },
            { TXT_WORD_WRAP_FAILED, L"Der Zeilenumbruch konnte nicht geändert werden." },
            { TXT_COPY_SELECTION, L"&Kopieren\tStrg+C" },
            { TXT_SELECT_ALL, L"&Alles auswählen\tStrg+A" },
            { TXT_FIND_MENU, L"&Suchen…\tStrg+F" },
            { TXT_FIND_NEXT_MENU, L"&Weitersuchen\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"&Vorheriges suchen\tUmschalt+F3" },
            { TXT_FIND_TITLE, L"%s — Suchen" },
            { TXT_FIND_WHAT, L"Suchen &nach:" },
            { TXT_FIND_NEXT, L"&Weitersuchen" },
            { TXT_FIND_MATCH_CASE, L"Groß-/&Kleinschreibung beachten" },
            { TXT_FIND_BACKWARD, L"&Rückwärts suchen" },
            { TXT_FIND_TOPMOST, L"Immer im &Vordergrund" },
            { TXT_FIND_STARTS_WITH, L"Zeile &beginnt mit" },
            { TXT_FIND_ENDS_WITH, L"Zeile &endet mit" },
            { TXT_FIND_REGEX, L"Regulärer &Ausdruck" },
            { TXT_FIND_NOT_FOUND, L"Der angegebene Text wurde nicht gefunden." },
            { TXT_FIND_FAILED, L"Die Suche konnte nicht abgeschlossen werden." },
            { TXT_FIND_REGEX_ERROR, L"Fehler im regulären Ausdruck:\r\n\r\n%s" },
        }
    },
    {
        LANG_FR,
        {
            { TXT_LANGUAGE_NAME, L"Français" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nSite web : " },
            { TXT_FILE_OPEN_FAILED, L"Impossible d’ouvrir %s. Vérifiez le chemin et les autorisations." },
            { TXT_BROWSE_DLL, L"&Parcourir…" },
            { TXT_BROWSE_REPORT, L"Parcour&ir…" },
            { TXT_CLOSE, L"&Fermer" },
            { TXT_CLOSE_TAB, L"&Fermer\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"Par &défaut" },
            { TXT_EXPORT, L"&Exporter…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Fichier" },
            { TXT_REPORT_FONT, L"P&olice du rapport :" },
            { TXT_HELP_MENU, L"&Aide" },
            { TXT_HELP, L"&Aide\tF1" },
            { TXT_LANGUAGE, L"Lan&gue :" },
            { TXT_OPEN_WEBSITE, L"&Ouvrir dans le navigateur par défaut" },
            { TXT_OPEN, L"&Ouvrir…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"O&ptions" },
            { TXT_PREFERENCES_MENU, L"&Préférences…\tCtrl+G" },
            { TXT_ABOUT, L"À &propos" },
            { TXT_ABOUT_TITLE, L"À propos de %ls" },
            { TXT_ALL_FILES, L"Tous les fichiers" },
            { TXT_FONT_BOLD, L"Gras" },
            { TXT_FONT_BOLD_ITALIC, L"Gras + Italique" },
            { TXT_BROWSE_CURL, L"Pa&rcourir…" },
            { TXT_CANCEL, L"Annuler" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Impossible de charger MediaInfo.dll (erreur Windows %lu). Utilisez une DLL 32 bits "
                L"compatible avec cette version de Windows."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Impossible de charger libcurl.dll (erreur Windows %lu). Sélectionnez une bibliothèque 32 "
                L"bits compatible avec cette version de Windows."
            },
            { TXT_CLOSE_ALL, L"&Tout fermer" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Copier l’&URL" },
            { TXT_COPY_INFORMATION, L"Copier les &informations" },
            { TXT_DLL_FILES, L"Bibliothèques dynamiques" },
            { TXT_EXIT, L"&Quitter\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Bibliothèques intégrées MediaInfo.dll :" },
            { TXT_EMBEDDED_CURL, L"Bibliothèques intégrées libcurl.dll :" },
            { TXT_EXPORT_TITLE, L"Exporter le rapport" },
            { TXT_FONT_ANTIALIASING, L"&Lissage des polices :" },
            { TXT_GIF_EXPORT_FAILED,
                L"Échec de l’export GIF. Un GIF sans perte nécessite au plus 256 couleurs."
            },
            { TXT_FONT_ITALIC, L"Italique" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED,
                L"Échec de l’export JPEG. Un encodeur JPEG GDI+ fonctionnel est nécessaire."
            },
            { TXT_LICENSE_UNAVAILABLE, L"La ressource de licence est indisponible." },
            { TXT_MEDIA_FILES, L"Fichiers multimédias" },
            { TXT_APPLICATION_DESCRIPTION, L"Visionneuse d’informations multimédias" },
            { TXT_HELP_TITLE, L"MediaInfo — Aide" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo n’a pas pu initialiser l’analyse du fichier." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo ne peut pas ouvrir ou reconnaître ce fichier." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"&Chemin de MediaInfo.dll :" },
            { TXT_MEDIALIB_REQUIRED,
                L"MediaInfo.dll n’est pas chargée. Sélectionnez-la dans Options > Préférences."
            },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll n’est pas chargée." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Aucune MediaInfo.dll externe ou intégrée compatible n’a pu être chargée. Sélectionnez-la "
                L"dans Options > Préférences."
            },
            { TXT_ANTIALIASING_NONE, L"Aucun" },
            { TXT_OK, L"OK" },
            { TXT_OPEN_TITLE, L"Ouvrir des fichiers multimédias" },
            { TXT_PLATFORM, L"Plateforme cible :" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Préférences" },
            { TXT_READY, L"Prêt" },
            { TXT_FONT_REGULAR, L"Normal" },
            { TXT_REPORT_LANGUAGE, L"Langue du rappor&t :" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Tables de langue des rapports" },
            { TXT_SELECT_MEDIALIB, L"Parcourir : MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Parcourir : MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH,
                L"Sélectionnez un fichier multimédia existant dont le chemin est plus court que MAX_PATH."
            },
            { TXT_SELECTED_PATHS_TOO_LONG,
                L"Sélectionnez des fichiers existants dont les chemins sont plus courts que MAX_PATH."
            },
            { TXT_SELECT_CURL, L"Parcourir : libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Document texte ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"Impossible d’enregistrer l’image BMP. Vérifiez la destination, la mémoire disponible et "
                L"l’espace disque."
            },
            { TXT_LIBRARY_WORKER_START_FAILED,
                L"Impossible de démarrer le processus de bibliothèque (erreur Windows %lu)."
            },
            { TXT_REPORT_COPY_FAILED, L"Impossible de copier le rapport MediaInfo en mémoire." },
            { TXT_VIEWER_CREATE_FAILED, L"Impossible de créer la visionneuse MediaInfo." },
            { TXT_MEDIALIB_PATH_INVALID, L"Le chemin de MediaInfo.dll est incorrect ou trop long." },
            { TXT_PNG_EXPORT_FAILED,
                L"Impossible d’enregistrer l’image PNG. Vérifiez la destination, la mémoire disponible et "
                L"l’espace disque."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"Impossible d’enregistrer l’image TIFF. Vérifiez la destination, la mémoire disponible et "
                L"l’espace disque."
            },
            { TXT_COPY_URL_FAILED, L"Impossible de copier l’URL dans le presse-papiers." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"La visionneuse Win32 nécessite une %s 32 bits. Sélectionnez la bibliothèque x86/i386."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Impossible d’écrire la bibliothèque intégrée dans AppData, le profil utilisateur, Program "
                L"Files ou le dossier temporaire."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED,
                L"Échec de la décompression ou du contrôle CRC de la bibliothèque."
            },
            { TXT_LIBRARY_RESOURCE_INVALID, L"La ressource de bibliothèque intégrée est incorrecte." },
            { TXT_CURL_FILENAME_INVALID,
                L"La bibliothèque doit s’appeler libcurl.dll pour que MediaInfo puisse l’utiliser."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Impossible d’ouvrir la boîte de dialogue de fichiers." },
            { TXT_FILE_DIALOG_SELECTION_FAILED,
                L"Impossible de récupérer les fichiers sélectionnés dans la boîte de dialogue."
            },
            { TXT_RECENT_FILE_MISSING,
                L"Le fichier « %s » n’existe plus.\n\nRetirer cette entrée de la liste des fichiers récents ?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Le fichier n’est plus disponible :\n\n%s\n\nRetirer cette entrée de la liste des fichiers "
                L"récents ?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Impossible de copier les informations dans le presse-papiers." },
            { TXT_CURL_PATH_INVALID, L"Le chemin de libcurl.dll est incorrect ou trop long." },
            { TXT_MEDIALIB_VERSION_MISSING, L"La bibliothèque n’a pas renvoyé de version MediaInfo." },
            { TXT_CURL_EXPORTS_MISSING,
                L"La bibliothèque n’exporte pas les fonctions curl requises par MediaInfo."
            },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"La bibliothèque n’exporte pas les fonctions Unicode requises de MediaInfo."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Le processus de bibliothèque a échoué pendant %s (code 0x%08lX). Sélectionnez une DLL "
                L"compatible dans Options > Préférences."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Le processus de bibliothèque ne répond plus pendant %s. Sélectionnez une DLL compatible "
                L"dans Options > Préférences."
            },
            { TXT_PREFERENCES_SAVE_FAILED,
                L"Les préférences ont été appliquées, mais n’ont pas pu être enregistrées dans le Registre."
            },
            { TXT_REPORT_START_FAILED, L"Mémoire insuffisante pour démarrer le rapport." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Impossible de créer l’image du rapport." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Impossible de charger la table de langue. Sélectionnez "
                L"un fichier CSV MediaInfo valide en UTF-8 ou UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"Impossible de démarrer le thread du rapport." },
            { TXT_REPORT_LANGUAGE_REJECTED,
                L"La bibliothèque MediaInfo.dll sélectionnée a refusé la langue du rapport."
            },
            { TXT_INVALID_WINDOWS_DLL, L"Le fichier sélectionné n’est pas une DLL Windows valide." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Le format d’image sélectionné n’est pas pris en charge." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Impossible d’enregistrer le rapport texte. Vérifiez la destination et l’espace disque "
                L"disponible."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Impossible d’ouvrir le site dans le navigateur par défaut." },
            { TXT_TOO_MANY_FILES, L"Trop de fichiers sélectionnés. Ouvrez des groupes plus petits." },
            { TXT_LIBRARY_PATH_HINT,
                L"Utilisez des bibliothèques 32 bits compatibles avec votre version de Windows. Laissez les "
                L"chemins vides pour la recherche automatique. MediaInfoLib v0.7.60 n’utilise pas "
                L"libcurl.dll."
            },
            { TXT_VERSION, L"Version" },
            { TXT_WEBSITE_TOOLTIP, L"Visiter le site web %s" },
            { TXT_WAITING_FOR_REPORT, L"En attente de la fin du rapport en cours." },
            { TXT_WEBSITE_LABEL, L"Site web :" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"la copie du rapport MediaInfo" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"Chemin de libc&url.dll :" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"le chargement de MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"le chargement de libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"le déchargement de MediaInfo.dll" },
            { TXT_APPLY, L"&Appliquer" },
            { TXT_TAB_NAME_LENGTH, L"Longueur des &noms d’onglets :" },
            { TXT_TITLE_NAME_LENGTH, L"Long&ueur du titre :" },
            { TXT_RECENT_FILES, L"Fichiers récents :" },
            { TXT_CLEAR_RECENT_FILES, L"&Effacer" },
            { TXT_TAB_NAME_LENGTH_INVALID,
                L"La longueur des noms d’onglets doit être comprise entre 8 et 255."
            },
            { TXT_TITLE_NAME_LENGTH_INVALID,
                L"La longueur du nom dans le titre doit être comprise entre 8 et 255."
            },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"La liste des fichiers récents a été effacée, mais n’a pas pu être enregistrée dans le "
                L"Registre."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"&Fermer les onglets par double-clic" },
            { TXT_CLOSE_TAB_CONTEXT, L"Fermer l’&onglet" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"Autori&ser plusieurs instances" },
            { TXT_INSTANCE_FORWARD_FAILED,
                L"Les fichiers n’ont pas pu être transmis à l’instance de MediaInfo en cours d’exécution."
            },
            { TXT_LOADING, L"Chargement…" },
            { TXT_LOADING_FILE, L"Chargement du fichier %s…" },
            { TXT_APPLICATION_HELP,
                L"FICHIERS ET ONGLETS\r\nVisionneuse Windows x86 native des rapports MediaInfo.dll. "
                L"Chaque fichier dispose de son propre onglet en lecture seule. Ouvrez avec Ctrl+O ou par "
                L"glisser-déposer. Rouvrir un fichier sélectionne son onglet existant. Ctrl+W ou le "
                L"bouton central ferme un onglet ; Tout fermer ferme tous les onglets. Le menu Fichier "
                L"mémorise huit fichiers récents. Le menu contextuel de l’en-tête d’un onglet contient "
                L"Fermer l’onglet. Activez Fermer les onglets par double-clic dans les Préférences pour "
                L"fermer un onglet en double-cliquant sur son en-tête. Cette option est désactivée par "
                L"défaut et son état est enregistré. Un double-clic dans le texte du rapport sélectionne "
                L"un mot. Un triple-clic sélectionne une ligne logique. Le glissement étend la sélection "
                L"par mots ou par lignes.\r\nOuvrir un dossier… ouvre les fichiers directement contenus "
                L"dans le dossier sélectionné, chacun dans son propre onglet. Les sous-dossiers ne sont "
                L"pas inclus.\r\nOuvrir et Ouvrir un dossier partagent le dernier dossier sélectionné. "
                L"L’export mémorise son propre dossier, Documents par défaut. Le mode avancé affiche des "
                L"champs supplémentaires dans le rapport.\r\nFormats connus / Codecs connus / Paramètres "
                L"connus — MediaInfo.dll.\r\nAnalyse complète examine l'intégralité du fichier et peut "
                L"prendre plus de temps. Ces options de rapport et Niveau de trace appartiennent à chaque "
                L"onglet ; une modification actualise uniquement l’onglet actif. La dernière combinaison "
                L"choisie manuellement est enregistrée pour les nouveaux onglets et le prochain "
                L"lancement. Un rapport mis en cache correspondant est réutilisé tant que le fichier "
                L"reste inchangé.\r\nNiveau de trace: 0 / 5 / 9 / 10.\r\nFichier > Mise en page… ouvre "
                L"les réglages du papier, de l’orientation et des marges pour la session en cours. "
                L"Imprimer… (Ctrl+P) ouvre la boîte de dialogue système d’impression ; Windows 11 fournit "
                L"un aperçu, tandis que Windows 10 et les versions antérieures conservent le dialogue "
                L"classique. Ctrl+P imprime l’onglet actif de la fenêtre principale ou la zone de texte "
                L"d’Aide ou d’À propos, selon la fenêtre qui a le focus. Les rapports utilisent la police "
                L"choisie, l’Aide la police système des dialogues et À propos la police de sa zone de "
                L"texte. Si aucun onglet n’est ouvert mais que l’Aide l’est, Mise en page… et Imprimer… "
                L"restent disponibles ; Imprimer… imprime l’Aide. L’Aide utilise le dialogue d’impression "
                L"de la fenêtre principale ; un nouvel appui sur Ctrl+P dans l’Aide le ramène au premier "
                L"plan. Les lignes longues sont renvoyées à la ligne et le texte est réparti en pages. "
                L"L’impression s’effectue en arrière-plan.\r\nDéposez un ou plusieurs fichiers dans la "
                L"fenêtre, sur l’icône de l’EXE ou sur son raccourci, ou transmettez leurs chemins en "
                L"ligne de commande. Si les instances multiples sont désactivées, les fichiers s’ouvrent "
                L"dans la fenêtre déjà active.\r\nLa partie gauche de la barre d’état affiche les chemins "
                L"des fichiers et la progression du chargement ; la partie droite affiche la version de "
                L"MediaInfo.dll chargée. Les chemins trop longs sont abrégés par des points de suspension "
                L"selon l’espace disponible.\r\n\r\nEXPORTATION\r\nTXT, BMP, GIF, JPEG, PNG, TIFF et WebP "
                L"sont proposés selon leur disponibilité. Le dernier dossier et le format d’exportation "
                L"sont mémorisés.\r\nTXT propose ANSI, UTF-8, UTF-8 avec BOM, UTF-16 BE avec BOM et "
                L"UTF-16 LE avec BOM. La deuxième entrée, UTF-8 sans BOM, est sélectionnée par défaut. Le "
                L"texte intégral du rapport et ses fins de ligne d’origine sont conservés.\r\n\r\nCRÉER "
                L"UN FICHIER D’EN-TÊTE\r\nLe menu Outils est le quatrième menu de la barre de menus. Sa "
                L"commande Créer un fichier d’en-tête… ouvre un fichier source indépendamment des onglets "
                L"du rapport et copie ses 524288 premiers octets (512 KiB). Un fichier plus court est "
                L"copié dans son intégralité ; un fichier vide produit une sortie vide. Il s'agit d'une "
                L"lecture de fichier binaire ordinaire, sans analyse MediaInfo ni nécessité de "
                L"MediaInfo.dll. L’outil ne modifie ni les onglets des rapports ni la liste des fichiers "
                L"récents du programme.\r\n\r\nAprès la lecture, la boîte de dialogue Enregistrer sous "
                L"démarre dans le dossier du fichier source et suggère video.mp4.header pour video.mp4 : "
                L".header est ajouté au nom d'origine complet. Vous pouvez modifier à la fois le nom et "
                L"le dossier de destination. L'annulation de l'une ou l'autre boîte de dialogue n'écrit "
                L"aucune sortie. Le remplacement d'une destination existante nécessite une confirmation. "
                L"Le fichier source reste inchangé ; un échec d’enregistrement préserve le fichier de "
                L"destination existant. L’ouverture et l’enregistrement utilisent les boîtes de dialogue "
                L"système les plus récentes disponibles sur cette version de Windows.\r\n\r\nAu démarrage "
                L"de l'application, l'outil prend son dossier d'entrée initial depuis Fichier > Ouvrir. "
                L"Si aucun dossier n'a été enregistré, Windows choisit l'emplacement initial. Une fois "
                L"qu'un fichier d'entrée est sélectionné, l'outil mémorise son propre dossier uniquement "
                L"jusqu'à ce que l'application se ferme, même si la boîte de dialogue Enregistrer sous "
                L"est annulée. Il ne modifie pas les dossiers utilisés par Ouvrir et Exporter et "
                L"n'enregistre pas non plus son propre dossier dans les paramètres de l'application. "
                L"Chaque boîte de dialogue Enregistrer sous démarre dans le dossier du fichier d'entrée "
                L"actuellement sélectionné, quelle que soit la destination de sauvegarde "
                L"précédente.\r\n\r\nPRÉFÉRENCES ET LANGUES\r\nLes préférences (Options > Préférences, "
                L"Ctrl+G) regroupent les chemins des bibliothèques, la police du rapport, le lissage et "
                L"les langues. L’interface possède 36 variantes et suit initialement Windows. Les "
                L"rapports utilisent toujours l’anglais d’origine de la bibliothèque, indépendamment de "
                L"Windows et de l’interface. Seul un choix manuel change leur langue : anglais, 37 "
                L"traductions ou une table CSV MediaInfo personnelle. OK ou Appliquer valide les "
                L"modifications ; Annuler abandonne les modifications en attente. Les préférences "
                L"permettent de limiter les noms d’onglets (80 par défaut) et d’effacer la liste des "
                L"fichiers récents. Les noms longs conservent le début, la fin et l’extension avec des "
                L"points de suspension au milieu. Effacer supprime immédiatement la liste des fichiers "
                L"récents, même si vous fermez ensuite les préférences avec Annuler.\r\n\r\nLe titre de la "
                L"fenêtre principale affiche le fichier actif sous la forme nom du fichier — MediaInfo. Les "
                L"préférences permettent de régler séparément la longueur du nom dans le titre de 8 à 255 "
                L"caractères (40 par défaut). Les noms longs utilisent les mêmes points de suspension au "
                L"milieu et conservent l’extension. Sans onglet ouvert, le titre est "
                L"MediaInfo.\r\n\r\nBIBLIOTHÈQUES "
                L"ET FENÊTRES\r\nL’exécutable contient les bibliothèques MediaInfo 26.10, 21.03 et "
                L"0.7.60. Après les bibliothèques externes, elles sont essayées de la plus récente à la "
                L"plus ancienne. Les deux versions récentes ont leur libcurl ; 0.7.60 ne l’extrait "
                L"jamais. La position de la fenêtre est enregistrée. Par défaut, une seule instance est "
                L"autorisée et les lancements suivants transmettent les fichiers à la fenêtre ouverte. "
                L"Les préférences permettent d’autoriser plusieurs instances. Si plusieurs fenêtres sont "
                L"autorisées, seule la première de chaque type de fenêtre retrouve sa position "
                L"enregistrée ; les suivantes ne reprennent que la taille.\r\n\r\nÉdition > Rechercher "
                L"(Ctrl+F) recherche dans l’onglet de rapport actif ou dans la zone de texte d’Aide ou "
                L"d’À propos, selon la fenêtre qui a le focus. La fenêtre de recherche conserve la "
                L"dernière source sélectionnée tant qu’elle a le focus. F3 répète la recherche ; Maj+F3 "
                L"inverse son sens. Aux extrémités du texte, la recherche reprend à l’autre extrémité. "
                L"Options > Retour automatique à la ligne concerne uniquement l’onglet actif ; la coche "
                L"suit l’onglet sélectionné. La fenêtre de recherche peut être réduite et redimensionnée "
                L"horizontalement ; sa position et l’option Toujours au premier plan sont mémorisées. "
                L"Jusqu’à 30 recherches et leurs options sont conservées uniquement jusqu’à la fermeture "
                L"de l’application. Les options de début et de fin s’appliquent aux lignes logiques. Les "
                L"expressions régulières utilisent la syntaxe PCRE2. Les autres commandes du menu Édition "
                L"concernent l’onglet de rapport actif. Entrée lance la recherche ; Maj+Entrée inverse le "
                L"sens choisi. « Respecter la casse » distingue les majuscules des minuscules ; « "
                L"Rechercher vers l’arrière » recherche vers le début du texte. Choisir une entrée de "
                L"l’historique rétablit les cinq options de recherche, y compris l’état du mode "
                L"d’expression régulière ; « Toujours au premier plan » est indépendante. « Expression "
                L"régulière » désactive « La ligne commence par » et « La ligne se termine par ». Si les "
                L"deux options de début et de fin de ligne sont activées, une correspondance à l’une des "
                L"extrémités suffit. « Retour automatique à la ligne » modifie uniquement l’affichage."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"Impossible d’enregistrer l’image WebP. Vérifiez la destination, la mémoire disponible et "
                L"l’espace disque."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Document texte UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Document texte UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Document texte UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Document texte UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Le rapport ne peut pas être enregistré dans cet encodage sans perte de caractères. "
                L"Choisissez un autre encodage."
            },
            { TXT_OPEN_FOLDER, L"Ouvrir un &dossier…" },
            { TXT_OPEN_FOLDER_TITLE, L"Ouvrir un dossier" },
            { TXT_FOLDER_READ_FAILED, L"Impossible de lire le dossier :\n\n%s\n\nErreur Windows %lu." },
            { TXT_ADVANCED_MODE, L"Mode &avancé" },
            { TXT_REPORT_DETAIL_REJECTED,
                L"La bibliothèque MediaInfo.dll sélectionnée a refusé le niveau de détail du rapport."
            },
            { TXT_KNOWN_FORMATS, L"&Formats connus" },
            { TXT_KNOWN_CODECS, L"&Codecs connus" },
            { TXT_KNOWN_PARAMETERS, L"Paramè&tres connus" },
            { TXT_KNOWN_FORMATS_TITLE, L"Formats connus" },
            { TXT_KNOWN_CODECS_TITLE, L"Codecs connus" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Paramètres connus" },
            { TXT_KNOWN_INFO_FAILED, L"La bibliothèque n’a pas renvoyé les informations demandées." },
            { TXT_FULL_PARSING, L"Analyse &complète" },
            { TXT_PARSING_REJECTED,
                L"La bibliothèque MediaInfo.dll sélectionnée a refusé le réglage de l’analyse."
            },
            { TXT_TRACE_LEVEL_0, L"Niveau de trace &0" },
            { TXT_TRACE_LEVEL_5, L"Niveau de trace &5" },
            { TXT_TRACE_LEVEL_9, L"Niveau de trace &9" },
            { TXT_TRACE_LEVEL_10, L"Niveau de trace &10" },
            { TXT_PAGE_SETUP, L"Mise en &page…" },
            { TXT_PAGE_SETUP_FAILED, L"Impossible d’ouvrir la boîte de dialogue de mise en page." },
            { TXT_PRINT, L"&Imprimer…\tCtrl+P" },
            { TXT_PRINTING, L"Impression…" },
            { TXT_PRINT_FAILED,
                L"Le texte n’a pas pu être imprimé. Vérifiez l’imprimante, ses paramètres et la mémoire "
                L"disponible."
            },
            { TXT_TOOLS_MENU, L"&Outils" },
            { TXT_CREATE_HEADER, L"Cré&er un fichier d’en-tête…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Créer un fichier d’en-tête - Ouvrir" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Créer un fichier d’en-tête - Enregistrer sous" },
            { TXT_HEADER_FORMAT, L"Fichier d’en-tête (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Impossible de lire l’en-tête du fichier :\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Impossible d’enregistrer le fichier d’en-tête :\n\n%s" },
            { TXT_COPY, L"&Copier" },
            { TXT_COPY_FILE_NAME, L"Copier le &nom du fichier" },
            { TXT_COPY_FULL_PATH, L"Copier le c&hemin complet" },
            { TXT_LAUNCH_FILE, L"&Lancer le fichier" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"&Afficher dans le dossier" },
            { TXT_EDIT_MENU, L"É&dition" },
            { TXT_WORD_WRAP, L"&Retour automatique à la ligne" },
            { TXT_WORD_WRAP_FAILED, L"Le retour automatique à la ligne n’a pas pu être modifié." },
            { TXT_COPY_SELECTION, L"&Copier\tCtrl+C" },
            { TXT_SELECT_ALL, L"&Tout sélectionner\tCtrl+A" },
            { TXT_FIND_MENU, L"&Rechercher…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Rechercher le &suivant\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Rechercher le &précédent\tMaj+F3" },
            { TXT_FIND_TITLE, L"%s — Rechercher" },
            { TXT_FIND_WHAT, L"Rec&hercher :" },
            { TXT_FIND_NEXT, L"Rechercher le &suivant" },
            { TXT_FIND_MATCH_CASE, L"Respecter la &casse" },
            { TXT_FIND_BACKWARD, L"Rechercher vers l’&arrière" },
            { TXT_FIND_TOPMOST, L"Toujours au premier &plan" },
            { TXT_FIND_STARTS_WITH, L"La l&igne commence par" },
            { TXT_FIND_ENDS_WITH, L"La ligne se &termine par" },
            { TXT_FIND_REGEX, L"Expression &régulière" },
            { TXT_FIND_NOT_FOUND, L"Le texte spécifié est introuvable." },
            { TXT_FIND_FAILED, L"La recherche n’a pas pu être terminée." },
            { TXT_FIND_REGEX_ERROR, L"Erreur d’expression régulière :\r\n\r\n%s" },
        }
    },
    {
        LANG_ES,
        {
            { TXT_LANGUAGE_NAME, L"Español" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nSitio web: " },
            { TXT_FILE_OPEN_FAILED, L"No se puede abrir %s. Compruebe la ruta y los permisos." },
            { TXT_BROWSE_DLL, L"&Examinar…" },
            { TXT_BROWSE_REPORT, L"Exa&minar…" },
            { TXT_CLOSE, L"&Cerrar" },
            { TXT_CLOSE_TAB, L"&Cerrar\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"&Predeterminada" },
            { TXT_EXPORT, L"&Exportar…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Archivo" },
            { TXT_REPORT_FONT, L"&Fuente del informe:" },
            { TXT_HELP_MENU, L"A&yuda" },
            { TXT_HELP, L"&Ayuda\tF1" },
            { TXT_LANGUAGE, L"&Idioma:" },
            { TXT_OPEN_WEBSITE, L"&Abrir en el navegador predeterminado" },
            { TXT_OPEN, L"&Abrir…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Opciones" },
            { TXT_PREFERENCES_MENU, L"&Preferencias…\tCtrl+G" },
            { TXT_ABOUT, L"A&cerca de" },
            { TXT_ABOUT_TITLE, L"Acerca de %ls" },
            { TXT_ALL_FILES, L"Todos los archivos" },
            { TXT_FONT_BOLD, L"Negrita" },
            { TXT_FONT_BOLD_ITALIC, L"Negrita + Cursiva" },
            { TXT_BROWSE_CURL, L"E&xaminar…" },
            { TXT_CANCEL, L"Cancelar" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"No se puede cargar MediaInfo.dll (error de Windows %lu). Use una DLL de 32 bits compatible "
                L"con esta versión de Windows."
            },
            { TXT_CURL_LOAD_FAILED,
                L"No se puede cargar libcurl.dll (error de Windows %lu). Seleccione una biblioteca de 32 "
                L"bits compatible con esta versión de Windows."
            },
            { TXT_CLOSE_ALL, L"Cerrar &todo" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Copiar &URL" },
            { TXT_COPY_INFORMATION, L"Copiar &información" },
            { TXT_DLL_FILES, L"Bibliotecas dinámicas" },
            { TXT_EXIT, L"&Salir\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Bibliotecas integradas MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Bibliotecas integradas libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Exportar informe" },
            { TXT_FONT_ANTIALIASING, L"&Suavizado de fuente:" },
            { TXT_GIF_EXPORT_FAILED,
                L"Error al exportar GIF. Un GIF sin pérdidas admite como máximo 256 colores."
            },
            { TXT_FONT_ITALIC, L"Cursiva" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED,
                L"Error al exportar JPEG. Se necesita un codificador JPEG de GDI+ que funcione."
            },
            { TXT_LICENSE_UNAVAILABLE, L"El recurso de licencia no está disponible." },
            { TXT_MEDIA_FILES, L"Archivos multimedia" },
            { TXT_APPLICATION_DESCRIPTION, L"Visor de información multimedia" },
            { TXT_HELP_TITLE, L"MediaInfo — Ayuda" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo no pudo inicializar el análisis del archivo." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo no puede abrir o reconocer este archivo." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"&Ruta de MediaInfo.dll:" },
            { TXT_MEDIALIB_REQUIRED,
                L"MediaInfo.dll no está cargada. Selecciónela en Opciones > Preferencias."
            },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll no está cargada." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"No se pudo cargar ninguna MediaInfo.dll externa o integrada compatible. Selecciónela en "
                L"Opciones > Preferencias."
            },
            { TXT_ANTIALIASING_NONE, L"Ninguno" },
            { TXT_OK, L"Aceptar" },
            { TXT_OPEN_TITLE, L"Abrir archivos multimedia" },
            { TXT_PLATFORM, L"Plataforma de destino:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Preferencias" },
            { TXT_READY, L"Listo" },
            { TXT_FONT_REGULAR, L"Normal" },
            { TXT_REPORT_LANGUAGE, L"Idioma &del informe:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Tablas de idioma de los informes" },
            { TXT_SELECT_MEDIALIB, L"Examinar: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Examinar: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH,
                L"Seleccione un archivo multimedia existente con una ruta más corta que MAX_PATH."
            },
            { TXT_SELECTED_PATHS_TOO_LONG,
                L"Seleccione archivos existentes con rutas más cortas que MAX_PATH."
            },
            { TXT_SELECT_CURL, L"Examinar: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Documento de texto ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"No se puede guardar la imagen BMP. Compruebe el destino, la memoria libre y el espacio en "
                L"disco."
            },
            { TXT_LIBRARY_WORKER_START_FAILED,
                L"No se puede iniciar el proceso de biblioteca (error de Windows %lu)."
            },
            { TXT_REPORT_COPY_FAILED, L"No se puede copiar el informe de MediaInfo a la memoria." },
            { TXT_VIEWER_CREATE_FAILED, L"No se puede crear el visor MediaInfo." },
            { TXT_MEDIALIB_PATH_INVALID, L"La ruta de MediaInfo.dll no es válida o es demasiado larga." },
            { TXT_PNG_EXPORT_FAILED,
                L"No se puede guardar la imagen PNG. Compruebe el destino, la memoria libre y el espacio en "
                L"disco."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"No se puede guardar la imagen TIFF. Compruebe el destino, la memoria libre y el espacio en "
                L"disco."
            },
            { TXT_COPY_URL_FAILED, L"No se pudo copiar la URL al portapapeles." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"El visor Win32 necesita una %s de 32 bits. Seleccione la biblioteca x86/i386."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"No se puede escribir la biblioteca integrada en AppData, el perfil de usuario, Program "
                L"Files ni la carpeta temporal."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED,
                L"Error de descompresión o comprobación CRC de la biblioteca."
            },
            { TXT_LIBRARY_RESOURCE_INVALID, L"El recurso de biblioteca integrado no es válido." },
            { TXT_CURL_FILENAME_INVALID,
                L"La biblioteca debe llamarse libcurl.dll para que MediaInfo pueda usarla."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"No se pudo abrir el cuadro de diálogo de archivos." },
            { TXT_FILE_DIALOG_SELECTION_FAILED,
                L"No se pudieron obtener los archivos seleccionados del cuadro de diálogo."
            },
            { TXT_RECENT_FILE_MISSING,
                L"El archivo «%s» ya no existe.\n\n¿Desea quitar esta entrada de la lista de archivos "
                L"recientes?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"El archivo ya no está disponible:\n\n%s\n\n¿Desea quitar esta entrada de la lista de "
                L"archivos recientes?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"No se pudo copiar la información al portapapeles." },
            { TXT_CURL_PATH_INVALID, L"La ruta de libcurl.dll no es válida o es demasiado larga." },
            { TXT_MEDIALIB_VERSION_MISSING, L"La biblioteca no devolvió una versión de MediaInfo." },
            { TXT_CURL_EXPORTS_MISSING,
                L"La biblioteca no exporta las funciones curl que necesita MediaInfo."
            },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"La biblioteca no exporta las funciones Unicode necesarias de MediaInfo."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"El proceso de biblioteca falló durante %s (código 0x%08lX). Seleccione una DLL compatible "
                L"en Opciones > Preferencias."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"El proceso de biblioteca dejó de responder durante %s. Seleccione una DLL compatible en "
                L"Opciones > Preferencias."
            },
            { TXT_PREFERENCES_SAVE_FAILED,
                L"Las preferencias se aplicaron, pero no se pudieron guardar en el Registro."
            },
            { TXT_REPORT_START_FAILED, L"No hay memoria suficiente para iniciar el informe." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"No se puede crear la imagen del informe." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"No se puede cargar la tabla de idioma. Seleccione un CSV "
                L"de MediaInfo válido en UTF-8 o UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"No se puede iniciar el hilo del informe." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"La MediaInfo.dll seleccionada rechazó el idioma del informe." },
            { TXT_INVALID_WINDOWS_DLL, L"El archivo seleccionado no es una DLL válida de Windows." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"El formato de imagen seleccionado no es compatible." },
            { TXT_TEXT_EXPORT_FAILED,
                L"No se puede guardar el informe de texto. Compruebe el destino y el espacio libre en disco."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"No se puede abrir el sitio en el navegador predeterminado." },
            { TXT_TOO_MANY_FILES, L"Se seleccionaron demasiados archivos. Abra grupos más pequeños." },
            { TXT_LIBRARY_PATH_HINT,
                L"Use bibliotecas de 32 bits compatibles con su versión de Windows. Deje las rutas vacías "
                L"para la búsqueda automática. MediaInfoLib v0.7.60 no usa libcurl.dll."
            },
            { TXT_VERSION, L"Versión" },
            { TXT_WEBSITE_TOOLTIP, L"Visitar el sitio web %s" },
            { TXT_WAITING_FOR_REPORT, L"Esperando a que termine el informe actual." },
            { TXT_WEBSITE_LABEL, L"Sitio web:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"la copia del informe de MediaInfo" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"Ruta de libc&url.dll:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"la carga de MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"la carga de libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"la descarga de MediaInfo.dll" },
            { TXT_APPLY, L"&Aplicar" },
            { TXT_TAB_NAME_LENGTH, L"&Longitud del nombre de pestaña:" },
            { TXT_TITLE_NAME_LENGTH, L"L&ongitud del título:" },
            { TXT_RECENT_FILES, L"Archivos recientes:" },
            { TXT_CLEAR_RECENT_FILES, L"&Borrar" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"La longitud del nombre de pestaña debe estar entre 8 y 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID,
                L"La longitud del nombre en el título debe estar entre 8 y 255."
            },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"La lista de archivos recientes se borró, pero no se pudo guardar en el Registro."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"&Cerrar pestañas con doble clic" },
            { TXT_CLOSE_TAB_CONTEXT, L"Cerrar &pestaña" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"Permi&tir varias instancias" },
            { TXT_INSTANCE_FORWARD_FAILED,
                L"No se pudieron enviar los archivos a la instancia de MediaInfo en ejecución."
            },
            { TXT_LOADING, L"Cargando…" },
            { TXT_LOADING_FILE, L"Cargando el archivo %s…" },
            { TXT_APPLICATION_HELP,
                L"ARCHIVOS Y PESTAÑAS\r\nVisor nativo de Windows x86 para informes de MediaInfo.dll. Cada "
                L"archivo tiene su propia pestaña de solo lectura. Abra archivos con Ctrl+O o "
                L"arrastrándolos. Abrir de nuevo selecciona la pestaña existente. Ctrl+W o el botón "
                L"central cierra una pestaña; Cerrar todo cierra todas. El menú Archivo recuerda ocho "
                L"archivos recientes. El menú contextual de la cabecera de una pestaña incluye Cerrar "
                L"pestaña. Active Cerrar pestañas con doble clic en Preferencias para cerrar una pestaña "
                L"haciendo doble clic en su cabecera. La opción está desactivada de forma predeterminada "
                L"y se guarda. Un doble clic en el texto del informe selecciona una palabra. Un triple "
                L"clic selecciona una línea lógica. Arrastrar amplía la selección por palabras o "
                L"líneas.\r\nAbrir carpeta… abre los archivos directamente contenidos en la carpeta "
                L"seleccionada, cada uno en su propia pestaña. No se incluyen las subcarpetas.\r\nAbrir y "
                L"Abrir carpeta comparten la última carpeta seleccionada. La exportación recuerda su "
                L"propia carpeta, Documentos por defecto. El modo avanzado muestra campos adicionales en "
                L"el informe.\r\nFormatos conocidos / Códecs conocidos / Parámetros conocidos — "
                L"MediaInfo.dll.\r\nAnálisis completo examina todo el archivo y puede tardar más. Estas "
                L"opciones de informe y Nivel de traza pertenecen a cada pestaña; un cambio actualiza "
                L"solo la pestaña activa. La última combinación elegida manualmente se guarda para nuevas "
                L"pestañas y el próximo inicio. Un informe almacenado en caché coincidente se reutiliza "
                L"mientras el archivo permanece sin cambios.\r\nNivel de traza: 0 / 5 / 9 / 10.\r\n"
                L"Archivo > Configurar página… abre los ajustes de papel, orientación y márgenes para la "
                L"sesión actual. Imprimir… (Ctrl+P) abre el diálogo de impresión del sistema; Windows 11 "
                L"ofrece una vista previa, mientras que Windows 10 y anteriores conservan el diálogo "
                L"clásico. Ctrl+P imprime la pestaña activa de la ventana principal o el área de texto de "
                L"Ayuda o Acerca de, según la ventana que tenga el foco. Los informes usan la fuente "
                L"elegida, Ayuda la fuente de diálogo del sistema y Acerca de la de su área de texto. Si "
                L"no hay pestañas abiertas pero Ayuda está abierta, Configurar página… e Imprimir… siguen "
                L"disponibles; Imprimir… imprime la Ayuda. Ayuda usa el diálogo de impresión de la "
                L"ventana principal; pulsar Ctrl+P de nuevo en Ayuda lo trae al primer plano. Las líneas "
                L"largas se ajustan y el texto se divide en páginas. La impresión se realiza en segundo "
                L"plano.\r\nArrastre uno o varios archivos a la ventana, al icono del EXE o a su acceso "
                L"directo, o indique sus rutas en la línea de comandos. Si no se permiten varias "
                L"instancias, los archivos se abren en la ventana que ya está en ejecución.\r\nLa parte "
                L"izquierda de la barra de estado muestra las rutas de los archivos y el progreso de "
                L"carga; la derecha muestra la versión de MediaInfo.dll cargada. Las rutas largas se "
                L"abrevian con puntos suspensivos según el espacio disponible.\r\n\r\nEXPORTACIÓN\r\nTXT, "
                L"BMP, GIF, JPEG, PNG, TIFF y WebP aparecen según su disponibilidad. Se recuerdan la "
                L"última carpeta y el formato de exportación.\r\nTXT ofrece ANSI, UTF-8, UTF-8 con BOM, "
                L"UTF-16 BE con BOM y UTF-16 LE con BOM. La segunda opción, UTF-8 sin BOM, es la "
                L"predeterminada. Se conservan el texto completo del informe y sus finales de línea "
                L"originales.\r\n\r\nCREAR ARCHIVO DE ENCABEZADO\r\nEl menú Herramientas es el cuarto de "
                L"la barra de menús. Su comando Crear archivo de encabezado… abre un archivo de origen "
                L"independientemente de las pestañas del informe y copia sus primeros 524288 bytes (512 "
                L"KiB). Un archivo más corto se copia en su totalidad; un archivo vacío produce una "
                L"salida vacía. Esta es una lectura de archivos binarios normal, sin analizar el "
                L"contenido con MediaInfo ni necesitar MediaInfo.dll. La herramienta deja sin cambios las "
                L"pestañas de informes y la lista de archivos recientes del visor.\r\n\r\nDespués de "
                L"leer, el cuadro de diálogo Guardar como comienza en la carpeta del archivo de origen y "
                L"sugiere video.mp4.header para video.mp4: .header se agrega al nombre original completo. "
                L"Puede cambiar tanto el nombre como la carpeta de destino. Cancelar cualquiera de los "
                L"diálogos no escribe ningún resultado. Reemplazar un destino existente requiere "
                L"confirmación. El archivo de origen permanece sin cambios; un guardado fallido conserva "
                L"el destino anterior. Para abrir y guardar se utilizan los cuadros de diálogo del "
                L"sistema más modernos disponibles en esa versión de Windows.\r\n\r\nAl iniciar la "
                L"aplicación, la herramienta toma su carpeta de entrada inicial de Archivo > Abrir. Si no "
                L"se ha guardado ninguna carpeta, Windows elige la ubicación inicial. Después de "
                L"seleccionar un archivo de entrada, la herramienta recuerda su propia carpeta sólo hasta "
                L"que se cierra la aplicación, incluso si se cancela Guardar como. No cambia las carpetas "
                L"utilizadas por Abrir y Exportar ni guarda su propia carpeta en la configuración de la "
                L"aplicación. Cada cuadro de diálogo Guardar como comienza en la carpeta del archivo de "
                L"entrada seleccionado actualmente, independientemente del destino de guardado "
                L"anterior.\r\n\r\nPREFERENCIAS E IDIOMAS\r\nLas preferencias (Opciones > Preferencias, "
                L"Ctrl+G) contienen rutas de bibliotecas, fuente del informe, suavizado e idiomas. La "
                L"interfaz ofrece 36 variantes y sigue inicialmente a Windows. Los informes usan siempre "
                L"el inglés original de la biblioteca, independientemente de Windows y de la interfaz. "
                L"Solo una selección manual cambia su idioma: inglés, 37 traducciones o una tabla CSV de "
                L"MediaInfo propia. Aceptar o Aplicar confirma los cambios; Cancelar descarta los "
                L"pendientes. Las preferencias permiten limitar los nombres de pestaña (80 por defecto) y "
                L"borrar la lista de archivos recientes. Los nombres largos conservan el principio, el "
                L"final y la extensión con puntos suspensivos en medio. Borrar elimina la lista de "
                L"archivos recientes inmediatamente, aunque después cierre las preferencias con "
                L"Cancelar.\r\n\r\nEl título de la ventana principal muestra el archivo activo como nombre de"
                L" archivo — MediaInfo. Las preferencias permiten fijar por separado la longitud del nombre "
                L"en el título entre 8 y 255 caracteres (40 por defecto). Los nombres largos usan los mismos "
                L"puntos suspensivos en el centro y conservan la extensión. Sin pestañas abiertas, el título "
                L"es MediaInfo.\r\n\r\nBIBLIOTECAS Y VENTANAS\r\nEl ejecutable incluye MediaInfo 26.10, 21.03"
                L" "
                L"y 0.7.60, probadas de más reciente a más antigua tras las bibliotecas externas. Las dos "
                L"nuevas tienen su libcurl; 0.7.60 nunca la extrae. Se guarda la posición de la ventana. "
                L"De forma predeterminada, solo se permite una instancia y los siguientes inicios envían "
                L"los archivos a la ventana abierta. En Preferencias se pueden permitir varias "
                L"instancias. Si hay varias ventanas, solo la primera de cada tipo de ventana recupera su "
                L"posición guardada; las siguientes recuperan únicamente el tamaño.\r\n\r\nEdición > "
                L"Buscar (Ctrl+F) busca en la pestaña de informe activa o en el área de texto de Ayuda o "
                L"Acerca de, según la ventana que tenga el foco. La ventana de búsqueda conserva el "
                L"último origen seleccionado mientras tiene el foco. F3 repite la búsqueda; Mayús+F3 "
                L"invierte su dirección. Al llegar a un extremo del texto, la búsqueda continúa desde el "
                L"otro. Opciones > Ajuste de línea solo afecta a la pestaña activa; la marca cambia según "
                L"la pestaña seleccionada. La ventana de búsqueda se puede minimizar y redimensionar "
                L"horizontalmente; se recuerdan su posición y la opción Siempre visible. Se conservan "
                L"hasta 30 búsquedas y sus opciones solo hasta que se cierra la aplicación. Las opciones "
                L"de principio y final se aplican a las líneas lógicas. Las expresiones regulares usan la "
                L"sintaxis de PCRE2. Los demás comandos del menú Edición se aplican a la pestaña de "
                L"informe activa. Entrar inicia la búsqueda; Mayús+Entrar invierte la dirección elegida. "
                L"«Coincidir mayúsculas y minúsculas» distingue mayúsculas y minúsculas; «Buscar hacia "
                L"atrás» busca hacia el principio del texto. Elegir una entrada del historial restaura "
                L"las cinco opciones de búsqueda, incluido el estado del modo de expresión regular; "
                L"«Siempre visible» es independiente. «Expresión regular» desactiva «La línea empieza "
                L"por» y «La línea termina en». Si ambas opciones de extremos de línea están activadas, "
                L"basta con que coincida uno de ellos. «Ajuste de línea» solo cambia la visualización."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"No se puede guardar la imagen WebP. Compruebe el destino, la memoria libre y el espacio en "
                L"disco."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Documento de texto UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Documento de texto UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Documento de texto UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Documento de texto UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"El informe no se puede guardar con esta codificación sin perder caracteres. Elija otra "
                L"codificación."
            },
            { TXT_OPEN_FOLDER, L"Abrir ca&rpeta…" },
            { TXT_OPEN_FOLDER_TITLE, L"Abrir carpeta" },
            { TXT_FOLDER_READ_FAILED, L"No se pudo leer la carpeta:\n\n%s\n\nError de Windows %lu." },
            { TXT_ADVANCED_MODE, L"Modo &avanzado" },
            { TXT_REPORT_DETAIL_REJECTED,
                L"La biblioteca MediaInfo.dll seleccionada rechazó el nivel de detalle del informe."
            },
            { TXT_KNOWN_FORMATS, L"&Formatos conocidos" },
            { TXT_KNOWN_CODECS, L"Có&decs conocidos" },
            { TXT_KNOWN_PARAMETERS, L"&Parámetros conocidos" },
            { TXT_KNOWN_FORMATS_TITLE, L"Formatos conocidos" },
            { TXT_KNOWN_CODECS_TITLE, L"Códecs conocidos" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Parámetros conocidos" },
            { TXT_KNOWN_INFO_FAILED, L"La biblioteca no devolvió la información solicitada." },
            { TXT_FULL_PARSING, L"Análisis &completo" },
            { TXT_PARSING_REJECTED,
                L"La biblioteca MediaInfo.dll seleccionada rechazó la configuración del análisis."
            },
            { TXT_TRACE_LEVEL_0, L"Nivel de traza &0" },
            { TXT_TRACE_LEVEL_5, L"Nivel de traza &5" },
            { TXT_TRACE_LEVEL_9, L"Nivel de traza &9" },
            { TXT_TRACE_LEVEL_10, L"Nivel de traza &10" },
            { TXT_PAGE_SETUP, L"Config&urar página…" },
            { TXT_PAGE_SETUP_FAILED, L"No se pudo abrir la configuración de página." },
            { TXT_PRINT, L"&Imprimir…\tCtrl+P" },
            { TXT_PRINTING, L"Imprimiendo…" },
            { TXT_PRINT_FAILED,
                L"No se pudo imprimir el texto. Compruebe la impresora, su configuración y la memoria "
                L"disponible."
            },
            { TXT_TOOLS_MENU, L"&Herramientas" },
            { TXT_CREATE_HEADER, L"&Crear archivo de encabezado…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Crear archivo de encabezado - Abrir" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Crear archivo de encabezado - Guardar como" },
            { TXT_HEADER_FORMAT, L"Archivo de encabezado (*.header)" },
            { TXT_HEADER_READ_FAILED, L"No se pudo leer el encabezado del archivo:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"No se pudo guardar el archivo de encabezado:\n\n%s" },
            { TXT_COPY, L"&Copiar" },
            { TXT_COPY_FILE_NAME, L"Copiar el &nombre del archivo" },
            { TXT_COPY_FULL_PATH, L"Copiar la &ruta completa" },
            { TXT_LAUNCH_FILE, L"E&jecutar archivo" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"&Mostrar en carpeta" },
            { TXT_EDIT_MENU, L"&Edición" },
            { TXT_WORD_WRAP, L"A&juste de línea" },
            { TXT_WORD_WRAP_FAILED, L"No se pudo cambiar el ajuste de línea." },
            { TXT_COPY_SELECTION, L"&Copiar\tCtrl+C" },
            { TXT_SELECT_ALL, L"Seleccionar &todo\tCtrl+A" },
            { TXT_FIND_MENU, L"&Buscar…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Buscar &siguiente\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Buscar &anterior\tMayús+F3" },
            { TXT_FIND_TITLE, L"%s — Buscar" },
            { TXT_FIND_WHAT, L"Buscar &texto:" },
            { TXT_FIND_NEXT, L"Buscar &siguiente" },
            { TXT_FIND_MATCH_CASE, L"Coincidir &mayúsculas y minúsculas" },
            { TXT_FIND_BACKWARD, L"Buscar hacia &atrás" },
            { TXT_FIND_TOPMOST, L"Siempre &visible" },
            { TXT_FIND_STARTS_WITH, L"La línea &empieza por" },
            { TXT_FIND_ENDS_WITH, L"La &línea termina en" },
            { TXT_FIND_REGEX, L"Expresión &regular" },
            { TXT_FIND_NOT_FOUND, L"No se encontró el texto especificado." },
            { TXT_FIND_FAILED, L"No se pudo completar la búsqueda." },
            { TXT_FIND_REGEX_ERROR, L"Error de expresión regular:\r\n\r\n%s" },
        }
    },
    {
        LANG_IT,
        {
            { TXT_LANGUAGE_NAME, L"Italiano" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nSito web: " },
            { TXT_FILE_OPEN_FAILED, L"Impossibile aprire %s. Verificare percorso e autorizzazioni." },
            { TXT_BROWSE_DLL, L"&Sfoglia…" },
            { TXT_BROWSE_REPORT, L"Sf&oglia…" },
            { TXT_CLOSE, L"&Chiudi" },
            { TXT_CLOSE_TAB, L"&Chiudi\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"P&redefinito" },
            { TXT_EXPORT, L"&Esporta…\tCtrl+E" },
            { TXT_FILE_MENU, L"&File" },
            { TXT_REPORT_FONT, L"&Carattere del rapporto:" },
            { TXT_HELP_MENU, L"&Guida" },
            { TXT_HELP, L"&Guida\tF1" },
            { TXT_LANGUAGE, L"&Lingua:" },
            { TXT_OPEN_WEBSITE, L"&Apri nel browser predefinito" },
            { TXT_OPEN, L"&Apri…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Opzioni" },
            { TXT_PREFERENCES_MENU, L"&Preferenze…\tCtrl+G" },
            { TXT_ABOUT, L"&Informazioni" },
            { TXT_ABOUT_TITLE, L"Informazioni su %ls" },
            { TXT_ALL_FILES, L"Tutti i file" },
            { TXT_FONT_BOLD, L"Grassetto" },
            { TXT_FONT_BOLD_ITALIC, L"Grassetto + Corsivo" },
            { TXT_BROWSE_CURL, L"S&foglia…" },
            { TXT_CANCEL, L"Annulla" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Impossibile caricare MediaInfo.dll (errore Windows %lu). Usare una DLL a 32 bit "
                L"compatibile con questa versione di Windows."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Impossibile caricare libcurl.dll (errore Windows %lu). Selezionare una libreria a 32 bit "
                L"compatibile con questa versione di Windows."
            },
            { TXT_CLOSE_ALL, L"Chiudi &tutto" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Copia &URL" },
            { TXT_COPY_INFORMATION, L"Copia &informazioni" },
            { TXT_DLL_FILES, L"Librerie dinamiche" },
            { TXT_EXIT, L"E&sci\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Librerie incorporate MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Librerie incorporate libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Esporta rapporto" },
            { TXT_FONT_ANTIALIASING, L"A&ntialiasing del carattere:" },
            { TXT_GIF_EXPORT_FAILED,
                L"Esportazione GIF non riuscita. Il GIF senza perdita richiede al massimo 256 colori."
            },
            { TXT_FONT_ITALIC, L"Corsivo" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED,
                L"Esportazione JPEG non riuscita. È necessario un codificatore JPEG GDI+ funzionante."
            },
            { TXT_LICENSE_UNAVAILABLE, L"Risorsa della licenza non disponibile." },
            { TXT_MEDIA_FILES, L"File multimediali" },
            { TXT_APPLICATION_DESCRIPTION, L"Visualizzatore di informazioni multimediali" },
            { TXT_HELP_TITLE, L"MediaInfo — Guida" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo non può inizializzare l’analisi del file." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo non può aprire o riconoscere questo file." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"&Percorso di MediaInfo.dll:" },
            { TXT_MEDIALIB_REQUIRED, L"MediaInfo.dll non è caricata. Selezionarla in Opzioni > Preferenze." },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll non è caricata." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Nessuna MediaInfo.dll esterna o incorporata compatibile può essere caricata. Selezionarla "
                L"in Opzioni > Preferenze."
            },
            { TXT_ANTIALIASING_NONE, L"Nessuno" },
            { TXT_OK, L"OK" },
            { TXT_OPEN_TITLE, L"Apri file multimediali" },
            { TXT_PLATFORM, L"Piattaforma di destinazione:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Preferenze" },
            { TXT_READY, L"Pronto" },
            { TXT_FONT_REGULAR, L"Normale" },
            { TXT_REPORT_LANGUAGE, L"Lin&gua del rapporto:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Tabelle linguistiche dei rapporti" },
            { TXT_SELECT_MEDIALIB, L"Sfoglia: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Sfoglia: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH,
                L"Selezionare un file multimediale esistente con un percorso più breve di MAX_PATH."
            },
            { TXT_SELECTED_PATHS_TOO_LONG,
                L"Selezionare file esistenti con percorsi più brevi di MAX_PATH."
            },
            { TXT_SELECT_CURL, L"Sfoglia: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Documento di testo ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"Impossibile salvare l’immagine BMP. Verificare destinazione, memoria libera e spazio su "
                L"disco."
            },
            { TXT_LIBRARY_WORKER_START_FAILED,
                L"Impossibile avviare il processo della libreria (errore Windows %lu)."
            },
            { TXT_REPORT_COPY_FAILED, L"Impossibile copiare il rapporto MediaInfo in memoria." },
            { TXT_VIEWER_CREATE_FAILED, L"Impossibile creare il visualizzatore MediaInfo." },
            { TXT_MEDIALIB_PATH_INVALID, L"Il percorso di MediaInfo.dll non è valido o è troppo lungo." },
            { TXT_PNG_EXPORT_FAILED,
                L"Impossibile salvare l’immagine PNG. Verificare destinazione, memoria libera e spazio su "
                L"disco."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"Impossibile salvare l’immagine TIFF. Verificare destinazione, memoria libera e spazio su "
                L"disco."
            },
            { TXT_COPY_URL_FAILED, L"Impossibile copiare l’URL negli Appunti." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"Il visualizzatore Win32 richiede una %s a 32 bit. Selezionare la libreria x86/i386."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Impossibile scrivere la libreria incorporata in AppData, nel profilo utente, in Program "
                L"Files o nella cartella temporanea."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED,
                L"Decompressione o verifica CRC della libreria non riuscita."
            },
            { TXT_LIBRARY_RESOURCE_INVALID, L"La risorsa della libreria incorporata non è valida." },
            { TXT_CURL_FILENAME_INVALID,
                L"La libreria deve chiamarsi libcurl.dll affinché MediaInfo possa usarla."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Impossibile aprire la finestra di dialogo dei file." },
            { TXT_FILE_DIALOG_SELECTION_FAILED,
                L"Impossibile ottenere i file selezionati dalla finestra di dialogo."
            },
            { TXT_RECENT_FILE_MISSING,
                L"Il file «%s» non esiste più.\n\nRimuovere questa voce dall’elenco dei file recenti?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Il file non è più disponibile:\n\n%s\n\nRimuovere questa voce dall’elenco dei file "
                L"recenti?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Impossibile copiare le informazioni negli Appunti." },
            { TXT_CURL_PATH_INVALID, L"Il percorso di libcurl.dll non è valido o è troppo lungo." },
            { TXT_MEDIALIB_VERSION_MISSING, L"La libreria non ha restituito una versione MediaInfo." },
            { TXT_CURL_EXPORTS_MISSING, L"La libreria non esporta le funzioni curl richieste da MediaInfo." },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"La libreria non esporta le funzioni Unicode richieste di MediaInfo."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Il processo della libreria è fallito durante %s (codice 0x%08lX). Selezionare una DLL "
                L"compatibile in Opzioni > Preferenze."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Il processo della libreria non risponde durante %s. Selezionare una DLL compatibile in "
                L"Opzioni > Preferenze."
            },
            { TXT_PREFERENCES_SAVE_FAILED,
                L"Le preferenze sono state applicate ma non salvate nel Registro."
            },
            { TXT_REPORT_START_FAILED, L"Memoria insufficiente per avviare il rapporto." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Impossibile creare l’immagine del rapporto." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Impossibile caricare la tabella linguistica. Selezionare "
                L"un CSV MediaInfo valido in UTF-8 o UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"Impossibile avviare il thread del rapporto." },
            { TXT_REPORT_LANGUAGE_REJECTED,
                L"La MediaInfo.dll selezionata ha rifiutato la lingua del rapporto."
            },
            { TXT_INVALID_WINDOWS_DLL, L"Il file selezionato non è una DLL Windows valida." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Il formato immagine selezionato non è supportato." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Impossibile salvare il rapporto testuale. Verificare destinazione e spazio libero su disco."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Impossibile aprire il sito nel browser predefinito." },
            { TXT_TOO_MANY_FILES, L"Troppi file selezionati. Aprire gruppi più piccoli." },
            { TXT_LIBRARY_PATH_HINT,
                L"Usare librerie a 32 bit compatibili con la propria versione di Windows. Lasciare vuoti i "
                L"percorsi per la ricerca automatica. MediaInfoLib v0.7.60 non usa libcurl.dll."
            },
            { TXT_VERSION, L"Versione" },
            { TXT_WEBSITE_TOOLTIP, L"Visita il sito web %s" },
            { TXT_WAITING_FOR_REPORT, L"In attesa del completamento del rapporto corrente." },
            { TXT_WEBSITE_LABEL, L"Sito web:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"la copia del rapporto MediaInfo" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"Percorso di libc&url.dll:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"il caricamento di MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"il caricamento di libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"lo scaricamento di MediaInfo.dll" },
            { TXT_APPLY, L"&Applica" },
            { TXT_TAB_NAME_LENGTH, L"Lunghezza del nome della sc&heda:" },
            { TXT_TITLE_NAME_LENGTH, L"L&unghezza del titolo:" },
            { TXT_RECENT_FILES, L"File recenti:" },
            { TXT_CLEAR_RECENT_FILES, L"Canc&ella" },
            { TXT_TAB_NAME_LENGTH_INVALID,
                L"La lunghezza del nome della scheda deve essere compresa tra 8 e 255."
            },
            { TXT_TITLE_NAME_LENGTH_INVALID,
                L"La lunghezza del nome nel titolo deve essere compresa tra 8 e 255."
            },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"L’elenco dei file recenti è stato cancellato, ma non è stato possibile salvarlo nel "
                L"Registro."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"Chiudi le schede con &doppio clic" },
            { TXT_CLOSE_TAB_CONTEXT, L"Chiudi &scheda" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"Consen&ti più istanze" },
            { TXT_INSTANCE_FORWARD_FAILED,
                L"Impossibile passare i file all’istanza di MediaInfo in esecuzione."
            },
            { TXT_LOADING, L"Caricamento…" },
            { TXT_LOADING_FILE, L"Caricamento del file %s…" },
            { TXT_APPLICATION_HELP,
                L"FILE E SCHEDE\r\nVisualizzatore nativo Windows x86 dei rapporti MediaInfo.dll. Ogni "
                L"file dispone di una scheda in sola lettura. Aprire con Ctrl+O o trascinare i file. "
                L"Riaprire un file seleziona la scheda esistente. Ctrl+W o il pulsante centrale chiude "
                L"una scheda; Chiudi tutto chiude tutte le schede. Il menu File ricorda otto file "
                L"recenti. Il menu contestuale dell’intestazione di una scheda include Chiudi scheda. "
                L"Attivare Chiudi le schede con doppio clic in Preferenze per chiudere una scheda facendo "
                L"doppio clic sulla sua intestazione. L’opzione è disattivata per impostazione "
                L"predefinita e viene salvata. Un doppio clic nel testo del rapporto seleziona una "
                L"parola. Un triplo clic seleziona una riga logica. Il trascinamento estende la selezione "
                L"per parole o righe.\r\nApri cartella… apre i file contenuti direttamente nella cartella "
                L"selezionata, ciascuno nella propria scheda. Le sottocartelle non sono incluse.\r\nApri "
                L"e Apri cartella condividono l’ultima cartella selezionata. L’esportazione ricorda una "
                L"cartella separata, Documenti per impostazione predefinita. La modalità avanzata mostra "
                L"campi aggiuntivi nel rapporto.\r\nFormati conosciuti / Codec conosciuti / Parametri "
                L"conosciuti — MediaInfo.dll.\r\nAnalisi completa esamina l'intero file e può richiedere "
                L"più tempo. Queste opzioni del rapporto e Livello di traccia appartengono a ciascuna "
                L"scheda; una modifica aggiorna solo la scheda attiva. L'ultima combinazione scelta "
                L"manualmente viene salvata per le nuove schede e per l’avvio successivo. Un rapporto "
                L"memorizzato nella cache corrispondente viene riutilizzato finché il file rimane "
                L"invariato.\r\nLivello di traccia: 0 / 5 / 9 / 10.\r\nFile > Imposta pagina… apre le "
                L"impostazioni di carta, orientamento e margini per la sessione corrente. Stampa… "
                L"(Ctrl+P) apre la finestra di stampa del sistema; Windows 11 offre un’anteprima, mentre "
                L"Windows 10 e precedenti mantengono la finestra classica. Ctrl+P stampa la scheda attiva "
                L"della finestra principale o l’area di testo di Guida o Informazioni, in base alla "
                L"finestra con lo stato attivo. I rapporti usano il carattere scelto, la Guida il "
                L"carattere dei dialoghi di sistema e Informazioni quello della propria area di testo. Se "
                L"non ci sono schede aperte ma la Guida è aperta, Imposta pagina… e Stampa… restano "
                L"disponibili; Stampa… stampa la Guida. La Guida usa la finestra di stampa della finestra "
                L"principale; premendo di nuovo Ctrl+P nella Guida, si riporta in primo piano lo stesso "
                L"dialogo di stampa. Le righe lunghe vengono mandate a capo e il testo suddiviso in "
                L"pagine. La stampa avviene in background.\r\nTrascinare uno o più file nella finestra, "
                L"sull’icona dell’EXE o sul relativo collegamento, oppure passare i percorsi dalla riga "
                L"di comando. Se non sono consentite più istanze, i file si aprono nella finestra già in "
                L"esecuzione.\r\nLa parte sinistra della barra di stato mostra i percorsi dei file e "
                L"l’avanzamento del caricamento; la parte destra mostra la versione di MediaInfo.dll "
                L"caricata. I percorsi lunghi vengono abbreviati con puntini di sospensione in base allo "
                L"spazio disponibile.\r\n\r\nESPORTAZIONE\r\nTXT, BMP, GIF, JPEG, PNG, TIFF e WebP sono "
                L"elencati quando disponibili. Cartella e formato dell’ultima esportazione vengono "
                L"ricordati.\r\nTXT offre ANSI, UTF-8, UTF-8 con BOM, UTF-16 BE con BOM e UTF-16 LE con "
                L"BOM. La seconda voce, UTF-8 senza BOM, è quella predefinita. Il testo completo del "
                L"report e le interruzioni di riga originali vengono preservati.\r\n\r\nCREA INTESTAZIONE "
                L"FILE\r\nIl menu Strumenti è il quarto nella barra dei menu. Il suo comando Crea "
                L"intestazione file… apre un file di origine indipendentemente dalle schede dei rapporti "
                L"e ne copia i primi 524288 byte (512 KiB). Un file più breve viene copiato per intero; "
                L"un file vuoto produce un output vuoto. Si tratta di una normale lettura di file binari, "
                L"senza analisi MediaInfo né necessità di MediaInfo.dll. Lo strumento lascia invariate le "
                L"schede dei rapporti e l'elenco dei file recenti del visualizzatore.\r\n\r\nDopo la "
                L"lettura, la finestra di dialogo Salva con nome si avvia nella cartella del file di "
                L"origine e suggerisce video.mp4.header per video.mp4: .header viene aggiunto al nome "
                L"originale completo. È possibile modificare sia il nome che la cartella di destinazione. "
                L"L'annullamento di una delle finestre di dialogo non scrive alcun output. La "
                L"sostituzione di una destinazione esistente richiede conferma. Il file di origine rimane "
                L"invariato; un salvataggio fallito conserva la destinazione precedente. Per aprire e "
                L"salvare vengono usate le finestre di dialogo di sistema più moderne disponibili nella "
                L"versione di Windows in uso.\r\n\r\nAll'avvio dell'applicazione, lo strumento prende la "
                L"cartella di input iniziale da File > Apri. Se non è stata salvata alcuna cartella, "
                L"Windows sceglie la posizione iniziale. Dopo aver selezionato un file di input, lo "
                L"strumento ricorda la propria cartella solo fino alla chiusura dell'applicazione, anche "
                L"se Salva con nome viene annullato. Non modifica le cartelle utilizzate da Apri e "
                L"Esporta né salva la propria cartella nelle impostazioni dell'applicazione. Ogni "
                L"finestra di dialogo Salva con nome inizia nella cartella del file di input attualmente "
                L"selezionato, indipendentemente dalla destinazione di salvataggio precedente.\r\n\r\n"
                L"PREFERENZE E LINGUE\r\nLe preferenze (Opzioni > Preferenze, Ctrl+G) contengono percorsi "
                L"delle librerie, carattere del rapporto, antialiasing e lingue. L’interfaccia ha 36 "
                L"varianti e inizialmente segue Windows. I rapporti usano sempre l’inglese originale "
                L"della libreria, indipendentemente da Windows e dall’interfaccia. Solo una scelta "
                L"manuale cambia la lingua: inglese, 37 traduzioni o una tabella CSV MediaInfo "
                L"personalizzata. OK o Applica conferma le modifiche; Annulla scarta quelle in sospeso. "
                L"Le preferenze consentono di limitare i nomi delle schede (80 predefinito) e cancellare "
                L"l’elenco dei file recenti. I nomi lunghi conservano inizio, fine ed estensione con "
                L"puntini di sospensione al centro. Cancella rimuove subito l’elenco dei file recenti, "
                L"anche se poi si chiudono le preferenze con Annulla.\r\n\r\nIl titolo della finestra "
                L"principale mostra il file attivo come nome del file — MediaInfo. Le preferenze consentono "
                L"di impostare separatamente la lunghezza del nome nel titolo da 8 a 255 caratteri (40 "
                L"predefinito). I nomi più lunghi usano gli stessi puntini di sospensione al centro e "
                L"mantengono l’estensione. Senza schede aperte, il titolo è MediaInfo.\r\n\r\nLIBRERIE E "
                L"FINESTRE\r\n"
                L"L’eseguibile include le librerie MediaInfo 26.10, 21.03 e 0.7.60. Dopo le librerie "
                L"esterne, vengono provate dalla più recente alla più vecchia. Le due versioni più "
                L"recenti hanno la propria libcurl; 0.7.60 non la estrae mai. La posizione della finestra "
                L"viene salvata. Per impostazione predefinita è consentita una sola istanza e gli avvii "
                L"successivi inviano i file alla finestra aperta. Nelle preferenze è possibile consentire "
                L"più istanze. Con più finestre, solo la prima di ciascun tipo di finestra ripristina la "
                L"posizione salvata; le successive ripristinano solo le dimensioni.\r\n\r\nModifica > "
                L"Trova (Ctrl+F) cerca nella scheda di rapporto attiva o nell’area di testo di Guida o "
                L"Informazioni, in base alla finestra con lo stato attivo. La finestra di ricerca "
                L"mantiene l’ultima origine selezionata finché resta attiva. F3 ripete la ricerca; "
                L"Maiusc+F3 ne inverte la direzione. Alle estremità del testo, la ricerca riprende "
                L"dall’estremità opposta. Opzioni > A capo automatico riguarda solo la scheda attiva; il "
                L"segno di spunta segue la scheda selezionata. La finestra di ricerca può essere ridotta "
                L"a icona e ridimensionata orizzontalmente; la posizione e l’opzione Sempre in primo "
                L"piano vengono memorizzate. Fino a 30 ricerche e le relative opzioni vengono conservate "
                L"solo fino alla chiusura dell’applicazione. Le opzioni di inizio e fine si riferiscono "
                L"alle righe logiche. Le espressioni regolari usano la sintassi PCRE2. Gli altri comandi "
                L"del menu Modifica si applicano alla scheda di rapporto attiva. Invio avvia la ricerca; "
                L"Maiusc+Invio inverte la direzione scelta. «Maiuscole/minuscole» distingue le lettere "
                L"maiuscole dalle minuscole; «Cerca all’indietro» cerca verso l’inizio del testo. La "
                L"scelta di una voce della cronologia ripristina tutte e cinque le opzioni di ricerca, "
                L"compreso lo stato del modo per le espressioni regolari; «Sempre in primo piano» è "
                L"indipendente. «Espressione regolare» disattiva «La riga inizia con» e «La riga termina "
                L"con». Se entrambe le opzioni di inizio e fine riga sono attive, è sufficiente una "
                L"corrispondenza a una delle estremità. «A capo automatico» modifica solo la "
                L"visualizzazione."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"Impossibile salvare l’immagine WebP. Verificare destinazione, memoria libera e spazio su "
                L"disco."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Documento di testo UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Documento di testo UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Documento di testo UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Documento di testo UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Il rapporto non può essere salvato con questa codifica senza perdere caratteri. Scegliere "
                L"un’altra codifica."
            },
            { TXT_OPEN_FOLDER, L"Apri ca&rtella…" },
            { TXT_OPEN_FOLDER_TITLE, L"Apri cartella" },
            { TXT_FOLDER_READ_FAILED, L"Impossibile leggere la cartella:\n\n%s\n\nErrore di Windows %lu." },
            { TXT_ADVANCED_MODE, L"Modalità &avanzata" },
            { TXT_REPORT_DETAIL_REJECTED,
                L"La libreria MediaInfo.dll selezionata ha rifiutato il livello di dettaglio del rapporto."
            },
            { TXT_KNOWN_FORMATS, L"&Formati conosciuti" },
            { TXT_KNOWN_CODECS, L"&Codec conosciuti" },
            { TXT_KNOWN_PARAMETERS, L"&Parametri conosciuti" },
            { TXT_KNOWN_FORMATS_TITLE, L"Formati conosciuti" },
            { TXT_KNOWN_CODECS_TITLE, L"Codec conosciuti" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Parametri conosciuti" },
            { TXT_KNOWN_INFO_FAILED, L"La libreria non ha restituito le informazioni richieste." },
            { TXT_FULL_PARSING, L"Analisi &completa" },
            { TXT_PARSING_REJECTED,
                L"La libreria MediaInfo.dll selezionata ha rifiutato l’impostazione dell’analisi."
            },
            { TXT_TRACE_LEVEL_0, L"Livello di traccia &0" },
            { TXT_TRACE_LEVEL_5, L"Livello di traccia &5" },
            { TXT_TRACE_LEVEL_9, L"Livello di traccia &9" },
            { TXT_TRACE_LEVEL_10, L"Livello di traccia &10" },
            { TXT_PAGE_SETUP, L"&Imposta pagina…" },
            { TXT_PAGE_SETUP_FAILED, L"Impossibile aprire l’impostazione della pagina." },
            { TXT_PRINT, L"Stam&pa…\tCtrl+P" },
            { TXT_PRINTING, L"Stampa…" },
            { TXT_PRINT_FAILED,
                L"Impossibile stampare il testo. Controllare la stampante, le sue impostazioni e la "
                L"memoria disponibile."
            },
            { TXT_TOOLS_MENU, L"&Strumenti" },
            { TXT_CREATE_HEADER, L"Crea &intestazione file…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Crea intestazione file - Apri" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Crea intestazione file - Salva con nome" },
            { TXT_HEADER_FORMAT, L"File di intestazione (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Impossibile leggere l’intestazione del file:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Impossibile salvare il file di intestazione:\n\n%s" },
            { TXT_COPY, L"&Copia" },
            { TXT_COPY_FILE_NAME, L"Copia &nome file" },
            { TXT_COPY_FULL_PATH, L"Copia p&ercorso completo" },
            { TXT_LAUNCH_FILE, L"A&vvia file" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"&Mostra nella cartella" },
            { TXT_EDIT_MENU, L"&Modifica" },
            { TXT_WORD_WRAP, L"A cap&o automatico" },
            { TXT_WORD_WRAP_FAILED, L"Impossibile modificare l’a capo automatico." },
            { TXT_COPY_SELECTION, L"&Copia\tCtrl+C" },
            { TXT_SELECT_ALL, L"Seleziona t&utto\tCtrl+A" },
            { TXT_FIND_MENU, L"&Trova…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Trova &successivo\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Trova &precedente\tMaiusc+F3" },
            { TXT_FIND_TITLE, L"%s — Trova" },
            { TXT_FIND_WHAT, L"&Testo da trovare:" },
            { TXT_FIND_NEXT, L"Trova &successivo" },
            { TXT_FIND_MATCH_CASE, L"&Maiuscole/minuscole" },
            { TXT_FIND_BACKWARD, L"Cerca all’&indietro" },
            { TXT_FIND_TOPMOST, L"Sempre in &primo piano" },
            { TXT_FIND_STARTS_WITH, L"&La riga inizia con" },
            { TXT_FIND_ENDS_WITH, L"La riga termin&a con" },
            { TXT_FIND_REGEX, L"Espressione &regolare" },
            { TXT_FIND_NOT_FOUND, L"Il testo specificato non è stato trovato." },
            { TXT_FIND_FAILED, L"Impossibile completare la ricerca." },
            { TXT_FIND_REGEX_ERROR, L"Errore nell’espressione regolare:\r\n\r\n%s" },
        }
    },
    {
        LANG_PT,
        {
            { TXT_LANGUAGE_NAME, L"Português" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nSite: " },
            { TXT_FILE_OPEN_FAILED, L"Não é possível abrir %s. Verifique o caminho e as permissões." },
            { TXT_BROWSE_DLL, L"&Procurar…" },
            { TXT_BROWSE_REPORT, L"Pr&ocurar…" },
            { TXT_CLOSE, L"&Fechar" },
            { TXT_CLOSE_TAB, L"&Fechar\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"Pre&definição" },
            { TXT_EXPORT, L"&Exportar…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Ficheiro" },
            { TXT_REPORT_FONT, L"&Tipo de letra do relatório:" },
            { TXT_HELP_MENU, L"&Ajuda" },
            { TXT_HELP, L"&Ajuda\tF1" },
            { TXT_LANGUAGE, L"&Idioma:" },
            { TXT_OPEN_WEBSITE, L"&Abrir no navegador predefinido" },
            { TXT_OPEN, L"&Abrir…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Opções" },
            { TXT_PREFERENCES_MENU, L"&Preferências…\tCtrl+G" },
            { TXT_ABOUT, L"Ac&erca de" },
            { TXT_ABOUT_TITLE, L"Acerca de %ls" },
            { TXT_ALL_FILES, L"Todos os ficheiros" },
            { TXT_FONT_BOLD, L"Negrito" },
            { TXT_FONT_BOLD_ITALIC, L"Negrito + Itálico" },
            { TXT_BROWSE_CURL, L"P&rocurar…" },
            { TXT_CANCEL, L"Cancelar" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Não é possível carregar MediaInfo.dll (erro do Windows %lu). Utilize uma DLL de 32 bits "
                L"compatível com esta versão do Windows."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Não é possível carregar libcurl.dll (erro do Windows %lu). Selecione uma biblioteca de 32 "
                L"bits compatível com esta versão do Windows."
            },
            { TXT_CLOSE_ALL, L"Fechar &tudo" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Copiar &URL" },
            { TXT_COPY_INFORMATION, L"Copiar &informações" },
            { TXT_DLL_FILES, L"Bibliotecas dinâmicas" },
            { TXT_EXIT, L"&Sair\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Bibliotecas incluídas MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Bibliotecas incluídas libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Exportar relatório" },
            { TXT_FONT_ANTIALIASING, L"&Suavização do tipo de letra:" },
            { TXT_GIF_EXPORT_FAILED,
                L"Falha na exportação GIF. Um GIF sem perdas exige no máximo 256 cores."
            },
            { TXT_FONT_ITALIC, L"Itálico" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED,
                L"Falha na exportação JPEG. É necessário um codificador JPEG GDI+ funcional."
            },
            { TXT_LICENSE_UNAVAILABLE, L"O recurso da licença não está disponível." },
            { TXT_MEDIA_FILES, L"Ficheiros multimédia" },
            { TXT_APPLICATION_DESCRIPTION, L"Visualizador de informações multimédia" },
            { TXT_HELP_TITLE, L"MediaInfo — Ajuda" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"O MediaInfo não conseguiu inicializar a análise do ficheiro." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"O MediaInfo não consegue abrir ou reconhecer este ficheiro." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"&Caminho de MediaInfo.dll:" },
            { TXT_MEDIALIB_REQUIRED,
                L"MediaInfo.dll não está carregada. Selecione-a em Opções > Preferências."
            },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll não está carregada." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Não foi possível carregar uma MediaInfo.dll externa ou incluída compatível. Selecione-a "
                L"em Opções > Preferências."
            },
            { TXT_ANTIALIASING_NONE, L"Nenhuma" },
            { TXT_OK, L"OK" },
            { TXT_OPEN_TITLE, L"Abrir ficheiros multimédia" },
            { TXT_PLATFORM, L"Plataforma de destino:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Preferências" },
            { TXT_READY, L"Pronto" },
            { TXT_FONT_REGULAR, L"Normal" },
            { TXT_REPORT_LANGUAGE, L"Idioma do r&elatório:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Tabelas de idiomas dos relatórios" },
            { TXT_SELECT_MEDIALIB, L"Procurar: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Procurar: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH,
                L"Selecione um ficheiro multimédia existente com um caminho mais curto do que MAX_PATH."
            },
            { TXT_SELECTED_PATHS_TOO_LONG,
                L"Selecione ficheiros existentes com caminhos mais curtos do que MAX_PATH."
            },
            { TXT_SELECT_CURL, L"Procurar: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Documento de texto ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"Não é possível guardar a imagem BMP. Verifique o destino, a memória livre e o espaço em "
                L"disco."
            },
            { TXT_LIBRARY_WORKER_START_FAILED,
                L"Não é possível iniciar o processo da biblioteca (erro do Windows %lu)."
            },
            { TXT_REPORT_COPY_FAILED, L"Não é possível copiar o relatório MediaInfo para a memória." },
            { TXT_VIEWER_CREATE_FAILED, L"Não é possível criar o visualizador MediaInfo." },
            { TXT_MEDIALIB_PATH_INVALID, L"O caminho de MediaInfo.dll é inválido ou demasiado longo." },
            { TXT_PNG_EXPORT_FAILED,
                L"Não é possível guardar a imagem PNG. Verifique o destino, a memória livre e o espaço em "
                L"disco."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"Não é possível guardar a imagem TIFF. Verifique o destino, a memória livre e o espaço em "
                L"disco."
            },
            { TXT_COPY_URL_FAILED, L"Não foi possível copiar o URL para a área de transferência." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"O visualizador Win32 exige uma %s de 32 bits. Selecione a biblioteca x86/i386."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Não é possível gravar a biblioteca incluída em AppData, no perfil do utilizador, em "
                L"Program Files nem na pasta temporária."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED, L"Falha na descompressão ou verificação CRC da biblioteca." },
            { TXT_LIBRARY_RESOURCE_INVALID, L"O recurso da biblioteca incluída é inválido." },
            { TXT_CURL_FILENAME_INVALID,
                L"A biblioteca tem de se chamar libcurl.dll para que o MediaInfo a possa utilizar."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Não foi possível abrir a caixa de diálogo de ficheiros." },
            { TXT_FILE_DIALOG_SELECTION_FAILED,
                L"Não foi possível obter os ficheiros selecionados na caixa de diálogo."
            },
            { TXT_RECENT_FILE_MISSING,
                L"O ficheiro «%s» já não existe.\n\nRemover esta entrada da lista de ficheiros recentes?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"O ficheiro já não está disponível:\n\n%s\n\nRemover esta entrada da lista de ficheiros "
                L"recentes?"
            },
            { TXT_COPY_INFORMATION_FAILED,
                L"Não foi possível copiar as informações para a área de transferência."
            },
            { TXT_CURL_PATH_INVALID, L"O caminho de libcurl.dll é inválido ou demasiado longo." },
            { TXT_MEDIALIB_VERSION_MISSING, L"A biblioteca não devolveu uma versão do MediaInfo." },
            { TXT_CURL_EXPORTS_MISSING,
                L"A biblioteca não exporta as funções curl necessárias ao MediaInfo."
            },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"A biblioteca não exporta as funções Unicode necessárias do MediaInfo."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"O processo da biblioteca falhou durante %s (código 0x%08lX). Selecione uma DLL compatível "
                L"em Opções > Preferências."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"O processo da biblioteca deixou de responder durante %s. Selecione uma DLL compatível em "
                L"Opções > Preferências."
            },
            { TXT_PREFERENCES_SAVE_FAILED,
                L"As preferências foram aplicadas, mas não foi possível guardá-las no Registo."
            },
            { TXT_REPORT_START_FAILED, L"Memória insuficiente para iniciar o relatório." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Não é possível criar a imagem do relatório." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Não é possível carregar a tabela de idioma. Selecione um "
                L"CSV MediaInfo válido em UTF-8 ou UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"Não é possível iniciar a thread do relatório." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"A MediaInfo.dll selecionada rejeitou o idioma do relatório." },
            { TXT_INVALID_WINDOWS_DLL, L"O ficheiro selecionado não é uma DLL Windows válida." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"O formato de imagem selecionado não é suportado." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Não é possível guardar o relatório de texto. Verifique o destino e o espaço livre em disco."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Não é possível abrir o sítio no navegador predefinido." },
            { TXT_TOO_MANY_FILES, L"Foram selecionados demasiados ficheiros. Abra grupos mais pequenos." },
            { TXT_LIBRARY_PATH_HINT,
                L"Utilize bibliotecas de 32 bits compatíveis com a sua versão do Windows. Deixe os caminhos "
                L"vazios para a pesquisa automática. O MediaInfoLib v0.7.60 não utiliza libcurl.dll."
            },
            { TXT_VERSION, L"Versão" },
            { TXT_WEBSITE_TOOLTIP, L"Visitar o site %s" },
            { TXT_WAITING_FOR_REPORT, L"A aguardar o fim do relatório atual." },
            { TXT_WEBSITE_LABEL, L"Site:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"a cópia do relatório MediaInfo" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"Caminho de libc&url.dll:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"o carregamento de MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"o carregamento de libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"o descarregamento de MediaInfo.dll" },
            { TXT_APPLY, L"&Aplicar" },
            { TXT_TAB_NAME_LENGTH, L"Co&mprimento do nome do separador:" },
            { TXT_TITLE_NAME_LENGTH, L"&Comprimento do título:" },
            { TXT_RECENT_FILES, L"Ficheiros recentes:" },
            { TXT_CLEAR_RECENT_FILES, L"&Limpar" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"O comprimento do nome do separador deve estar entre 8 e 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"O comprimento do nome no título deve estar entre 8 e 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"A lista de ficheiros recentes foi limpa, mas não foi possível guardá-la no Registo."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"&Fechar separadores com duplo clique" },
            { TXT_CLOSE_TAB_CONTEXT, L"Fechar &separador" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"Permitir várias i&nstâncias" },
            { TXT_INSTANCE_FORWARD_FAILED,
                L"Não foi possível enviar os ficheiros para a instância do MediaInfo em execução."
            },
            { TXT_LOADING, L"A carregar…" },
            { TXT_LOADING_FILE, L"A carregar o ficheiro %s…" },
            { TXT_APPLICATION_HELP,
                L"FICHEIROS E SEPARADORES\r\nVisualizador nativo para Windows x86 de relatórios "
                L"MediaInfo.dll. Cada ficheiro tem um separador só de leitura. Abra ficheiros com Ctrl+O "
                L"ou arraste-os. Reabrir seleciona o separador existente. Ctrl+W ou o botão central fecha "
                L"um separador; Fechar tudo fecha todos. O menu Ficheiro memoriza oito ficheiros "
                L"recentes. O menu de contexto do cabeçalho de um separador inclui Fechar separador. "
                L"Ative Fechar separadores com duplo clique nas Preferências para fechar um separador com "
                L"um duplo clique no cabeçalho. A opção está desativada por predefinição e é guardada. Um "
                L"duplo clique no texto do relatório seleciona uma palavra. Um triplo clique seleciona "
                L"uma linha lógica. Arrastar expande a seleção por palavras ou linhas.\r\nAbrir pasta… "
                L"abre os ficheiros contidos diretamente na pasta selecionada, cada um no seu próprio "
                L"separador. As subpastas não são incluídas.\r\nAbrir e Abrir pasta partilham a última "
                L"pasta selecionada. A exportação memoriza a sua própria pasta, Documentos por "
                L"predefinição. O modo avançado apresenta campos adicionais no relatório.\r\nFormatos "
                L"conhecidos / Codecs conhecidos / Parâmetros conhecidos — MediaInfo.dll.\r\nAnálise "
                L"completa examina o ficheiro inteiro e pode demorar mais tempo. Estas opções de "
                L"relatório e Nível de rastreio pertencem a cada separador; uma alteração atualiza apenas "
                L"o separador ativo. A última combinação escolhida manualmente é guardada para novos "
                L"separadores e para a próxima execução. Um relatório armazenado em cache correspondente "
                L"é reutilizado enquanto o ficheiro permanece inalterado.\r\nNível de rastreio: 0 / 5 / 9 "
                L"/ 10.\r\nFicheiro > Configurar página… abre as definições de papel, orientação e "
                L"margens para a sessão atual. Imprimir… (Ctrl+P) abre a caixa de diálogo de impressão do "
                L"sistema; o Windows 11 fornece uma pré-visualização, enquanto o Windows 10 e anteriores "
                L"mantêm a caixa de diálogo clássica. Ctrl+P imprime o separador ativo da janela "
                L"principal ou a área de texto de Ajuda ou Acerca de, conforme a janela que tem o foco. "
                L"Os relatórios usam o tipo de letra escolhido, a Ajuda o tipo de letra dos diálogos do "
                L"sistema e Acerca de o da sua área de texto. Se não houver separadores abertos mas a "
                L"Ajuda estiver aberta, Configurar página… e Imprimir… continuam disponíveis; Imprimir… "
                L"imprime a Ajuda. A Ajuda usa a caixa de diálogo de impressão da janela principal; "
                L"premir Ctrl+P novamente na Ajuda volta a colocar a mesma caixa de diálogo em primeiro "
                L"plano. As linhas longas são ajustadas e o texto é dividido em páginas. A impressão "
                L"decorre em segundo plano.\r\nArraste um ou mais ficheiros para a janela, para o ícone "
                L"do EXE ou para o respetivo atalho, ou indique os caminhos na linha de comandos. Se não "
                L"forem permitidas várias instâncias, os ficheiros abrem-se na janela que já está em "
                L"execução.\r\nO lado esquerdo da barra de estado apresenta os caminhos dos ficheiros e o "
                L"progresso do carregamento; o lado direito apresenta a versão da MediaInfo.dll "
                L"carregada. Os caminhos longos são abreviados com reticências de acordo com o espaço "
                L"disponível.\r\n\r\nEXPORTAÇÃO\r\nTXT, BMP, GIF, JPEG, PNG, TIFF e WebP surgem conforme "
                L"a disponibilidade. A última pasta e o formato de exportação são memorizados.\r\nTXT "
                L"oferece ANSI, UTF-8, UTF-8 com BOM, UTF-16 BE com BOM e UTF-16 LE com BOM. A segunda "
                L"opção, UTF-8 sem BOM, é a predefinida. O texto completo do relatório e as quebras de "
                L"linha originais são preservados.\r\n\r\nCRIAR FICHEIRO DE CABEÇALHO\r\nO menu "
                L"Ferramentas é o quarto na barra de menus. O seu comando Criar ficheiro de cabeçalho… "
                L"abre um ficheiro de origem independentemente dos separadores do relatório e copia os "
                L"seus primeiros 524288 bytes (512 KiB). Um ficheiro mais curto é copiado por completo; "
                L"um ficheiro vazio produz uma saída vazia. Esta é uma leitura comum de ficheiro binário, "
                L"sem análise MediaInfo nem necessidade de MediaInfo.dll. A ferramenta deixa inalterados "
                L"os separadores do relatório e a lista de ficheiros recentes do visualizador.\r\n\r\n"
                L"Após a leitura, a caixa de diálogo Guardar como inicia-se na pasta do ficheiro de "
                L"origem e sugere video.mp4.header para video.mp4: .header é anexado ao nome original "
                L"completo. Pode alterar o nome e a pasta de destino. Cancelar qualquer caixa de diálogo "
                L"não grava qualquer saída. A substituição de um destino existente requer confirmação. O "
                L"ficheiro de origem permanece inalterado; uma falha ao guardar preserva o destino "
                L"anterior. Para abrir e guardar são utilizadas as caixas de diálogo do sistema mais "
                L"modernas disponíveis nessa versão do Windows.\r\n\r\nNa inicialização da aplicação, a "
                L"ferramenta obtém a sua pasta de entrada inicial de Ficheiro > Abrir. Se não tiver sido "
                L"guardada nenhuma pasta, o Windows escolhe o local inicial. Depois de um ficheiro de "
                L"entrada ser selecionado, a ferramenta recorda a sua própria pasta apenas até a "
                L"aplicação sair, mesmo que o Guardar como seja cancelado. Não altera as pastas "
                L"utilizadas por Abrir e Exportar nem guarda a sua própria pasta nas definições da "
                L"aplicação. Cada caixa de diálogo Guardar como inicia-se na pasta do ficheiro de entrada "
                L"atualmente selecionado, independentemente do destino de gravação anterior.\r\n\r\n"
                L"PREFERÊNCIAS E IDIOMAS\r\nAs preferências (Opções > Preferências, Ctrl+G) contêm "
                L"caminhos das bibliotecas, tipo de letra do relatório, suavização e idiomas. A interface "
                L"tem 36 variantes e segue inicialmente o Windows. Os relatórios usam sempre o inglês "
                L"original da biblioteca, independentemente do Windows e da interface. Só uma escolha "
                L"manual muda o idioma: inglês, 37 traduções ou uma tabela CSV MediaInfo personalizada. "
                L"OK ou Aplicar confirma as alterações; Cancelar descarta as pendentes. As preferências "
                L"permitem limitar os nomes dos separadores (80 por predefinição) e limpar a lista dos "
                L"ficheiros recentes. Os nomes longos mantêm início, fim e extensão com reticências no "
                L"meio. Limpar remove imediatamente a lista de ficheiros recentes, mesmo que depois feche "
                L"as preferências com Cancelar.\r\n\r\nO título da janela principal mostra o ficheiro ativo "
                L"como nome do ficheiro — MediaInfo. As preferências permitem definir separadamente o "
                L"comprimento do nome no título entre 8 e 255 carateres (40 por predefinição). Os nomes mais "
                L"longos usam as mesmas reticências ao centro e mantêm a extensão. Sem separadores abertos, o"
                L" título é MediaInfo.\r\n\r\nBIBLIOTECAS E JANELAS\r\nO executável inclui "
                L"MediaInfo 26.10, 21.03 e 0.7.60, testadas da mais recente após as bibliotecas externas. "
                L"As duas versões recentes têm a respetiva libcurl; 0.7.60 nunca a extrai. A posição da "
                L"janela é guardada. Por predefinição, só é permitida uma instância e os arranques "
                L"seguintes enviam os ficheiros para a janela aberta. Nas preferências, é possível "
                L"permitir várias instâncias. Com várias janelas, apenas a primeira de cada tipo de "
                L"janela recupera a posição guardada; as seguintes recuperam apenas o tamanho.\r\n\r\n"
                L"Editar > Localizar (Ctrl+F) pesquisa no separador de relatório ativo ou na área de "
                L"texto de Ajuda ou Acerca de, conforme a janela que tem o foco. A janela de pesquisa "
                L"mantém a última origem selecionada enquanto tem o foco. F3 repete a pesquisa; Shift+F3 "
                L"inverte a direção. Ao atingir uma extremidade do texto, a pesquisa continua na outra. "
                L"Opções > Moldar texto afeta apenas o separador ativo; a marca acompanha o separador "
                L"selecionado. A janela de pesquisa pode ser minimizada e redimensionada horizontalmente; "
                L"a posição e a opção Sempre em cima são memorizadas. São guardadas até 30 pesquisas e as "
                L"respetivas opções apenas até a aplicação ser encerrada. As opções de início e fim "
                L"referem-se às linhas lógicas. As expressões regulares utilizam a sintaxe PCRE2. Os "
                L"restantes comandos do menu Editar aplicam-se ao separador de relatório ativo. Enter "
                L"inicia a pesquisa; Shift+Enter inverte a direção escolhida. «Distinguir maiúsculas de "
                L"minúsculas» distingue maiúsculas de minúsculas; «Procurar para trás» pesquisa em "
                L"direção ao início do texto. A escolha de uma entrada do histórico repõe as cinco opções "
                L"de pesquisa, incluindo o estado do modo de expressão regular; «Sempre em cima» é "
                L"independente. «Expressão regular» desativa «A linha começa por» e «A linha termina "
                L"com». Com ambas as opções de início e fim de linha ativas, basta uma correspondência "
                L"numa das extremidades. «Moldar texto» altera apenas a apresentação."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"Não é possível guardar a imagem WebP. Verifique o destino, a memória livre e o espaço em "
                L"disco."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Documento de texto UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Documento de texto UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Documento de texto UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Documento de texto UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"O relatório não pode ser guardado nesta codificação sem perder caracteres. Escolha outra "
                L"codificação."
            },
            { TXT_OPEN_FOLDER, L"Abrir &pasta…" },
            { TXT_OPEN_FOLDER_TITLE, L"Abrir pasta" },
            { TXT_FOLDER_READ_FAILED, L"Não foi possível ler a pasta:\n\n%s\n\nErro do Windows %lu." },
            { TXT_ADVANCED_MODE, L"Modo &avançado" },
            { TXT_REPORT_DETAIL_REJECTED,
                L"A biblioteca MediaInfo.dll selecionada rejeitou o nível de detalhe do relatório."
            },
            { TXT_KNOWN_FORMATS, L"&Formatos conhecidos" },
            { TXT_KNOWN_CODECS, L"&Codecs conhecidos" },
            { TXT_KNOWN_PARAMETERS, L"&Parâmetros conhecidos" },
            { TXT_KNOWN_FORMATS_TITLE, L"Formatos conhecidos" },
            { TXT_KNOWN_CODECS_TITLE, L"Codecs conhecidos" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Parâmetros conhecidos" },
            { TXT_KNOWN_INFO_FAILED, L"A biblioteca não devolveu as informações pedidas." },
            { TXT_FULL_PARSING, L"Análise &completa" },
            { TXT_PARSING_REJECTED,
                L"A biblioteca MediaInfo.dll selecionada rejeitou a definição da análise."
            },
            { TXT_TRACE_LEVEL_0, L"Nível de rastreio &0" },
            { TXT_TRACE_LEVEL_5, L"Nível de rastreio &5" },
            { TXT_TRACE_LEVEL_9, L"Nível de rastreio &9" },
            { TXT_TRACE_LEVEL_10, L"Nível de rastreio &10" },
            { TXT_PAGE_SETUP, L"&Configurar página…" },
            { TXT_PAGE_SETUP_FAILED, L"Não foi possível abrir a configuração da página." },
            { TXT_PRINT, L"&Imprimir…\tCtrl+P" },
            { TXT_PRINTING, L"A imprimir…" },
            { TXT_PRINT_FAILED,
                L"Não foi possível imprimir o texto. Verifique a impressora, as suas definições e a "
                L"memória disponível."
            },
            { TXT_TOOLS_MENU, L"Ferramen&tas" },
            { TXT_CREATE_HEADER, L"&Criar ficheiro de cabeçalho…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Criar ficheiro de cabeçalho - Abrir" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Criar ficheiro de cabeçalho - Guardar como" },
            { TXT_HEADER_FORMAT, L"Ficheiro de cabeçalho (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Não foi possível ler o cabeçalho do ficheiro:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Não foi possível guardar o ficheiro de cabeçalho:\n\n%s" },
            { TXT_COPY, L"&Copiar" },
            { TXT_COPY_FILE_NAME, L"Copiar &nome do ficheiro" },
            { TXT_COPY_FULL_PATH, L"Copiar cam&inho completo" },
            { TXT_LAUNCH_FILE, L"E&xecutar ficheiro" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"&Mostrar na pasta" },
            { TXT_EDIT_MENU, L"&Editar" },
            { TXT_WORD_WRAP, L"&Moldar texto" },
            { TXT_WORD_WRAP_FAILED, L"Não foi possível alterar a moldagem do texto." },
            { TXT_COPY_SELECTION, L"&Copiar\tCtrl+C" },
            { TXT_SELECT_ALL, L"Selecionar t&udo\tCtrl+A" },
            { TXT_FIND_MENU, L"&Localizar…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Localizar &seguinte\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Localizar &anterior\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Localizar" },
            { TXT_FIND_WHAT, L"&Localizar:" },
            { TXT_FIND_NEXT, L"Localizar &seguinte" },
            { TXT_FIND_MATCH_CASE, L"Distinguir &maiúsculas de minúsculas" },
            { TXT_FIND_BACKWARD, L"Procurar para &trás" },
            { TXT_FIND_TOPMOST, L"Sempre em &cima" },
            { TXT_FIND_STARTS_WITH, L"&A linha começa por" },
            { TXT_FIND_ENDS_WITH, L"A li&nha termina com" },
            { TXT_FIND_REGEX, L"Expressão &regular" },
            { TXT_FIND_NOT_FOUND, L"O texto especificado não foi encontrado." },
            { TXT_FIND_FAILED, L"Não foi possível concluir a pesquisa." },
            { TXT_FIND_REGEX_ERROR, L"Erro na expressão regular:\r\n\r\n%s" },
        }
    },
    {
        LANG_PL,
        {
            { TXT_LANGUAGE_NAME, L"Polski" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nWitryna: " },
            { TXT_FILE_OPEN_FAILED, L"Nie można otworzyć %s. Sprawdź ścieżkę i uprawnienia." },
            { TXT_BROWSE_DLL, L"&Przeglądaj…" },
            { TXT_BROWSE_REPORT, L"Przegl&ądaj…" },
            { TXT_CLOSE, L"&Zamknij" },
            { TXT_CLOSE_TAB, L"&Zamknij\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"&Domyślna" },
            { TXT_EXPORT, L"&Eksportuj…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Plik" },
            { TXT_REPORT_FONT, L"&Czcionka raportu:" },
            { TXT_HELP_MENU, L"Po&moc" },
            { TXT_HELP, L"&Pomoc\tF1" },
            { TXT_LANGUAGE, L"&Język:" },
            { TXT_OPEN_WEBSITE, L"&Otwórz w domyślnej przeglądarce" },
            { TXT_OPEN, L"&Otwórz…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Opcje" },
            { TXT_PREFERENCES_MENU, L"&Preferencje…\tCtrl+G" },
            { TXT_ABOUT, L"&O programie" },
            { TXT_ABOUT_TITLE, L"Informacje o %ls" },
            { TXT_ALL_FILES, L"Wszystkie pliki" },
            { TXT_FONT_BOLD, L"Pogrubienie" },
            { TXT_FONT_BOLD_ITALIC, L"Pogrubienie + Kursywa" },
            { TXT_BROWSE_CURL, L"Przeg&lądaj…" },
            { TXT_CANCEL, L"Anuluj" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Nie można załadować MediaInfo.dll (błąd Windows %lu). Użyj 32-bitowej biblioteki DLL "
                L"zgodnej z tą wersją systemu Windows."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Nie można załadować libcurl.dll (błąd Windows %lu). Wybierz 32-bitową bibliotekę zgodną z "
                L"tą wersją systemu Windows."
            },
            { TXT_CLOSE_ALL, L"Zamknij &wszystkie" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Kopiuj &adres URL" },
            { TXT_COPY_INFORMATION, L"Kopiuj &informacje" },
            { TXT_DLL_FILES, L"Biblioteki dynamiczne" },
            { TXT_EXIT, L"Za&kończ\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Dołączone biblioteki MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Dołączone biblioteki libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Eksportuj raport" },
            { TXT_FONT_ANTIALIASING, L"Wy&gładzanie czcionki:" },
            { TXT_GIF_EXPORT_FAILED,
                L"Eksport GIF nie powiódł się. Bezstratny GIF wymaga najwyżej 256 kolorów."
            },
            { TXT_FONT_ITALIC, L"Kursywa" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED,
                L"Eksport JPEG nie powiódł się. Wymagany jest działający koder JPEG GDI+."
            },
            { TXT_LICENSE_UNAVAILABLE, L"Zasób licencji jest niedostępny." },
            { TXT_MEDIA_FILES, L"Pliki multimedialne" },
            { TXT_APPLICATION_DESCRIPTION, L"Przeglądarka informacji o multimediach" },
            { TXT_HELP_TITLE, L"MediaInfo — Pomoc" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo nie może zainicjować analizy pliku." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo nie może otworzyć lub rozpoznać tego pliku." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"&Ścieżka do MediaInfo.dll:" },
            { TXT_MEDIALIB_REQUIRED,
                L"MediaInfo.dll nie jest załadowana. Wybierz ją w Opcje > Preferencje."
            },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll nie jest załadowana." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Nie można załadować zgodnej zewnętrznej ani dołączonej MediaInfo.dll. Wybierz ją w Opcje "
                L"> Preferencje."
            },
            { TXT_ANTIALIASING_NONE, L"Brak" },
            { TXT_OK, L"OK" },
            { TXT_OPEN_TITLE, L"Otwórz pliki multimedialne" },
            { TXT_PLATFORM, L"Platforma docelowa:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Preferencje" },
            { TXT_READY, L"Gotowy" },
            { TXT_FONT_REGULAR, L"Zwykły" },
            { TXT_REPORT_LANGUAGE, L"Język &raportu:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Tabele języków raportów" },
            { TXT_SELECT_MEDIALIB, L"Wybierz: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Wybierz: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH,
                L"Wybierz istniejący plik multimedialny o ścieżce krótszej niż MAX_PATH."
            },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Wybierz istniejące pliki o ścieżkach krótszych niż MAX_PATH." },
            { TXT_SELECT_CURL, L"Wybierz: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Dokument tekstowy ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"Nie można zapisać obrazu BMP. Sprawdź miejsce docelowe, wolną pamięć i miejsce na dysku."
            },
            { TXT_LIBRARY_WORKER_START_FAILED,
                L"Nie można uruchomić procesu biblioteki (błąd Windows %lu)."
            },
            { TXT_REPORT_COPY_FAILED, L"Nie można skopiować raportu MediaInfo do pamięci." },
            { TXT_VIEWER_CREATE_FAILED, L"Nie można utworzyć przeglądarki MediaInfo." },
            { TXT_MEDIALIB_PATH_INVALID, L"Ścieżka do MediaInfo.dll jest nieprawidłowa lub zbyt długa." },
            { TXT_PNG_EXPORT_FAILED,
                L"Nie można zapisać obrazu PNG. Sprawdź miejsce docelowe, wolną pamięć i miejsce na dysku."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"Nie można zapisać obrazu TIFF. Sprawdź miejsce docelowe, wolną pamięć i miejsce na dysku."
            },
            { TXT_COPY_URL_FAILED, L"Nie można skopiować adresu URL do schowka." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"Przeglądarka Win32 wymaga 32-bitowej %s. Wybierz bibliotekę x86/i386."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Nie można zapisać dołączonej biblioteki w AppData, profilu użytkownika, Program Files ani "
                L"katalogu tymczasowym."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED,
                L"Dekompresja biblioteki lub sprawdzenie CRC nie powiodło się."
            },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Zasób dołączonej biblioteki jest nieprawidłowy." },
            { TXT_CURL_FILENAME_INVALID,
                L"Biblioteka musi nazywać się libcurl.dll, aby MediaInfo mogło jej używać."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Nie można otworzyć okna wyboru plików." },
            { TXT_FILE_DIALOG_SELECTION_FAILED, L"Nie można pobrać wybranych plików z okna wyboru." },
            { TXT_RECENT_FILE_MISSING,
                L"Plik „%s” już nie istnieje.\n\nCzy usunąć ten wpis z listy ostatnich plików?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Plik nie jest już dostępny:\n\n%s\n\nCzy usunąć ten wpis z listy ostatnich plików?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Nie można skopiować informacji do schowka." },
            { TXT_CURL_PATH_INVALID, L"Ścieżka do libcurl.dll jest nieprawidłowa lub zbyt długa." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Biblioteka nie zwróciła wersji MediaInfo." },
            { TXT_CURL_EXPORTS_MISSING,
                L"Biblioteka nie eksportuje funkcji curl wymaganych przez MediaInfo."
            },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"Biblioteka nie eksportuje wymaganych funkcji Unicode MediaInfo."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Proces biblioteki uległ awarii podczas %s (kod 0x%08lX). Wybierz zgodną DLL w Opcje > "
                L"Preferencje."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Proces biblioteki przestał odpowiadać podczas %s. Wybierz zgodną DLL w Opcje > "
                L"Preferencje."
            },
            { TXT_PREFERENCES_SAVE_FAILED, L"Preferencje zastosowano, ale nie zapisano ich w rejestrze." },
            { TXT_REPORT_START_FAILED, L"Za mało pamięci, aby uruchomić raport." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Nie można utworzyć obrazu raportu." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Nie można załadować tabeli języka. Wybierz prawidłowy "
                L"plik CSV MediaInfo w UTF-8 lub UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"Nie można uruchomić wątku raportu." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"Wybrana MediaInfo.dll odrzuciła język raportu." },
            { TXT_INVALID_WINDOWS_DLL, L"Wybrany plik nie jest prawidłową biblioteką DLL systemu Windows." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Wybrany format obrazu nie jest obsługiwany." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Nie można zapisać raportu tekstowego. Sprawdź miejsce docelowe i wolne miejsce na dysku."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Nie można otworzyć witryny w domyślnej przeglądarce." },
            { TXT_TOO_MANY_FILES, L"Wybrano za dużo plików. Otwieraj je w mniejszych grupach." },
            { TXT_LIBRARY_PATH_HINT,
                L"Użyj 32-bitowych bibliotek zgodnych z używaną wersją systemu Windows. Pozostaw puste "
                L"ścieżki, aby włączyć automatyczne wyszukiwanie. MediaInfoLib v0.7.60 nie używa libcurl.dll."
            },
            { TXT_VERSION, L"Wersja" },
            { TXT_WEBSITE_TOOLTIP, L"Odwiedź witrynę %s" },
            { TXT_WAITING_FOR_REPORT, L"Oczekiwanie na zakończenie bieżącego raportu." },
            { TXT_WEBSITE_LABEL, L"Witryna:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"kopiowania raportu MediaInfo" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"Ścieżka do libc&url.dll:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"ładowania MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"ładowania libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"zwalniania MediaInfo.dll" },
            { TXT_APPLY, L"Z&astosuj" },
            { TXT_TAB_NAME_LENGTH, L"Długość &nazwy karty:" },
            { TXT_TITLE_NAME_LENGTH, L"Dł&ugość tytułu:" },
            { TXT_RECENT_FILES, L"Ostatnie pliki:" },
            { TXT_CLEAR_RECENT_FILES, L"Wyc&zyść" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"Długość nazwy karty musi wynosić od 8 do 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"Długość nazwy w tytule musi wynosić od 8 do 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Lista ostatnich plików została wyczyszczona, ale nie można było zapisać jej w rejestrze."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"Za&mykaj karty dwuklikiem" },
            { TXT_CLOSE_TAB_CONTEXT, L"Zamknij &kartę" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"Z&ezwalaj na wiele instancji" },
            { TXT_INSTANCE_FORWARD_FAILED,
                L"Nie można przekazać plików do uruchomionej instancji MediaInfo."
            },
            { TXT_LOADING, L"Ładowanie…" },
            { TXT_LOADING_FILE, L"Ładowanie pliku %s…" },
            { TXT_APPLICATION_HELP,
                L"PLIKI I KARTY\r\nNatywna przeglądarka raportów MediaInfo.dll dla Windows x86. Każdy "
                L"plik ma własną kartę tylko do odczytu. Otwieraj pliki przez Ctrl+O lub przeciąganie. "
                L"Ponowne otwarcie wybiera istniejącą kartę. Ctrl+W lub środkowy przycisk zamyka kartę; "
                L"Zamknij wszystkie zamyka wszystkie karty. Menu Plik zapamiętuje osiem ostatnio "
                L"otwieranych plików. Menu kontekstowe nagłówka karty zawiera polecenie Zamknij kartę. W "
                L"Preferencjach włącz Zamykaj karty dwuklikiem, aby zamykać kartę dwukrotnym kliknięciem "
                L"jej nagłówka. Opcja jest domyślnie wyłączona i jej stan jest zapisywany. Dwukrotne "
                L"kliknięcie tekstu raportu zaznacza słowo. Trzykrotne kliknięcie zaznacza wiersz "
                L"logiczny. Przeciąganie rozszerza zaznaczenie o słowa lub wiersze.\r\nOtwórz folder… "
                L"otwiera pliki znajdujące się bezpośrednio w wybranym folderze, każdy na osobnej karcie. "
                L"Podfoldery nie są uwzględniane.\r\nOtwórz i Otwórz folder korzystają wspólnie z "
                L"ostatnio wybranego folderu. Eksport zapamiętuje osobny folder, domyślnie Dokumenty. "
                L"Tryb zaawansowany pokazuje dodatkowe pola raportu.\r\nZnane formaty / Znane kodeki / "
                L"Znane parametry — MediaInfo.dll.\r\nPełna analiza sprawdza cały plik, co może potrwać "
                L"dłużej. Te opcje raportu i Poziom śledzenia należą do każdej karty; zmiana odświeża "
                L"tylko aktywną kartę. Ostatnia ręcznie wybrana kombinacja jest zapisywana dla nowych "
                L"kart i następnego uruchomienia. Pasujący raport z pamięci podręcznej jest ponownie "
                L"używany, dopóki plik pozostaje niezmieniony.\r\nPoziom śledzenia: 0 / 5 / 9 / 10.\r\n"
                L"Plik > Ustawienia strony… otwiera ustawienia papieru, orientacji i marginesów na "
                L"bieżącą sesję. Drukuj… (Ctrl+P) otwiera systemowe okno drukowania; Windows 11 "
                L"udostępnia podgląd, a Windows 10 i starsze zachowują klasyczne okno. Ctrl+P drukuje "
                L"aktywną kartę okna głównego albo pole tekstowe Pomocy lub O programie, zależnie od "
                L"tego, które okno ma fokus. Raporty używają wybranej czcionki raportu, Pomoc systemowej "
                L"czcionki okien dialogowych, a O programie czcionki swojego pola tekstowego. Jeśli nie "
                L"ma otwartych kart, ale Pomoc jest otwarta, Ustawienia strony… i Drukuj… pozostają "
                L"dostępne; Drukuj… drukuje Pomoc. Pomoc używa okna drukowania okna głównego; ponowne "
                L"Ctrl+P w Pomocy przenosi je na pierwszy plan. Długie wiersze są zawijane, a tekst "
                L"dzielony na strony. Drukowanie działa w tle.\r\nPrzeciągnij co najmniej jeden plik do "
                L"okna, na ikonę EXE lub jego skrót albo podaj ścieżki w wierszu polecenia. Jeśli wiele "
                L"instancji jest wyłączone, pliki otworzą się w już uruchomionym oknie.\r\nLewa część "
                L"paska stanu pokazuje ścieżki plików i postęp ładowania, a prawa wersję załadowanej "
                L"biblioteki MediaInfo.dll. Długie ścieżki są skracane wielokropkiem stosownie do "
                L"dostępnego miejsca.\r\n\r\nEKSPORT\r\nTXT, BMP, GIF, JPEG, PNG, TIFF i WebP są dostępne "
                L"zależnie od systemu. Ostatni folder i format eksportu są zapamiętywane.\r\nTXT oferuje "
                L"ANSI, UTF-8, UTF-8 z BOM, UTF-16 BE z BOM i UTF-16 LE z BOM. Domyślna jest druga "
                L"pozycja, UTF-8 bez BOM. Pełny tekst raportu i jego oryginalne zakończenia wierszy są "
                L"zachowane.\r\n\r\nUTWÓRZ PLIK NAGŁÓWKA\r\nMenu Narzędzia jest czwartym menu na pasku "
                L"menu. Polecenie Utwórz plik nagłówka… otwiera jeden plik źródłowy niezależnie od kart "
                L"raportów i kopiuje jego pierwsze 524288 bajtów (512 KiB). Krótszy plik jest kopiowany w "
                L"całości; pusty plik generuje puste dane wyjściowe. Jest to zwykły odczyt pliku "
                L"binarnego, bez analizy MediaInfo ani konieczności używania MediaInfo.dll. Narzędzie "
                L"pozostawia karty raportów i listę ostatnich plików przeglądarki bez zmian.\r\n\r\nPo "
                L"przeczytaniu w folderze pliku źródłowego otworzy się okno dialogowe Zapisz jako, które "
                L"zaproponuje nazwę video.mp4.header dla video.mp4: .header jest dołączany do pełnej "
                L"oryginalnej nazwy. Można zmienić zarówno nazwę, jak i folder docelowy. Anulowanie "
                L"któregokolwiek okna dialogowego nie powoduje zapisywania danych wyjściowych. "
                L"Zastąpienie istniejącego miejsca docelowego wymaga potwierdzenia. Plik źródłowy "
                L"pozostaje niezmieniony; nieudane zapisanie powoduje zachowanie poprzedniego miejsca "
                L"docelowego. Do otwierania i zapisywania używane są najnowsze systemowe okna dialogowe "
                L"dostępne w danej wersji systemu Windows.\r\n\r\nPodczas uruchamiania aplikacji "
                L"narzędzie pobiera początkowy folder wejściowy z Plik > Otwórz. Jeśli żaden folder nie "
                L"został zapisany, system Windows wybiera początkową lokalizację. Po wybraniu pliku "
                L"wejściowego narzędzie zapamiętuje swój własny folder tylko do momentu zakończenia "
                L"działania aplikacji, nawet jeśli opcja Zapisz jako została anulowana. Nie zmienia "
                L"folderów używanych przez Otwórz i Eksportuj ani nie zapisuje własnego folderu w "
                L"ustawieniach aplikacji. Każde okno dialogowe Zapisz jako rozpoczyna się w folderze "
                L"aktualnie wybranego pliku wejściowego, niezależnie od miejsca docelowego poprzedniego "
                L"zapisu.\r\n\r\nPREFERENCJE I JĘZYKI\r\nPreferencje (Opcje > Preferencje, Ctrl+G) "
                L"zawierają ścieżki bibliotek, czcionkę raportu, wygładzanie i języki. Interfejs ma 36 "
                L"wariantów i początkowo korzysta z języka Windows. Raporty zawsze domyślnie używają "
                L"oryginalnego angielskiego biblioteki, niezależnie od Windows i interfejsu. Zmienia to "
                L"wyłącznie ręczny wybór: angielski, 37 tłumaczeń lub własna tabela CSV MediaInfo. OK lub "
                L"Zastosuj zatwierdza zmiany; Anuluj odrzuca oczekujące zmiany. Preferencje pozwalają "
                L"ustawić limit długości nazwy karty (domyślnie 80 znaków) i wyczyścić listę ostatnich "
                L"plików. Długie nazwy zachowują początek, koniec i rozszerzenie, z wielokropkiem "
                L"pośrodku. Wyczyść natychmiast usuwa listę ostatnich plików, nawet jeśli preferencje "
                L"zostaną następnie zamknięte przyciskiem Anuluj.\r\n\r\nTytuł głównego okna pokazuje aktywny"
                L" plik w postaci nazwa pliku — MediaInfo. W preferencjach można osobno ustawić długość nazwy"
                L" w tytule od 8 do 255 znaków (domyślnie 40). Dłuższe nazwy są skracane tym samym "
                L"wielokropkiem pośrodku z zachowaniem rozszerzenia. Gdy nie ma otwartych kart, tytuł to "
                L"MediaInfo.\r\n\r\nBIBLIOTEKI I OKNA\r\nProgram "
                L"zawiera MediaInfo 26.10, 21.03 i 0.7.60, sprawdzane od najnowszej po bibliotekach "
                L"zewnętrznych. Dwie nowsze wersje mają odpowiednią libcurl; 0.7.60 nigdy jej nie "
                L"rozpakowuje. Położenie okna jest zapisywane. Domyślnie dozwolona jest tylko jedna "
                L"instancja, a kolejne uruchomienia przekazują pliki do otwartego okna. W ustawieniach "
                L"można zezwolić na wiele instancji. Przy wielu oknach tylko pierwsze okno każdego typu "
                L"przywraca zapisaną pozycję; następne przywracają jedynie rozmiar.\r\n\r\nEdycja > "
                L"Znajdź (Ctrl+F) przeszukuje aktywną kartę raportu albo pole tekstowe Pomocy lub O "
                L"programie, zależnie od tego, które okno ma fokus. Okno wyszukiwania zachowuje ostatnio "
                L"wybrane źródło, dopóki ma fokus. F3 powtarza wyszukiwanie, a Shift+F3 odwraca jego "
                L"kierunek. Po dotarciu do końca tekstu wyszukiwanie jest kontynuowane od drugiego końca. "
                L"Opcje > Zawijanie wierszy dotyczy tylko aktywnej karty; zaznaczenie odpowiada wybranej "
                L"karcie. Okno wyszukiwania można zminimalizować i zmieniać jego szerokość; położenie "
                L"oraz ustawienie Zawsze na wierzchu są zapamiętywane. Do 30 wyszukiwanych tekstów z "
                L"opcjami pozostaje w pamięci tylko do zamknięcia aplikacji. Opcje początku i końca "
                L"dotyczą logicznych wierszy. Wyrażenia regularne używają składni PCRE2. Pozostałe "
                L"polecenia menu Edycja dotyczą aktywnej karty raportu. Enter uruchamia wyszukiwanie, a "
                L"Shift+Enter odwraca wybrany kierunek. „Uwzględnij wielkość liter” rozróżnia wielkie i "
                L"małe litery; „Szukaj wstecz” wyszukuje w kierunku początku tekstu. Wybranie wpisu "
                L"historii przywraca wszystkie pięć opcji wyszukiwania, w tym stan trybu wyrażeń "
                L"regularnych; „Zawsze na wierzchu” jest niezależne. „Wyrażenie regularne” wyłącza opcje "
                L"„Wiersz zaczyna się od” i „Wiersz kończy się na”. Gdy obie opcje krańców wiersza są "
                L"włączone, wystarczy dopasowanie na jednym z nich. „Zawijanie wierszy” zmienia tylko "
                L"sposób wyświetlania."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"Nie można zapisać obrazu WebP. Sprawdź miejsce docelowe, wolną pamięć i miejsce na dysku."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Dokument tekstowy UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Dokument tekstowy UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Dokument tekstowy UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Dokument tekstowy UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Nie można zapisać raportu w tym kodowaniu bez utraty znaków. Wybierz inne kodowanie tekstu."
            },
            { TXT_OPEN_FOLDER, L"Otwórz &folder…" },
            { TXT_OPEN_FOLDER_TITLE, L"Otwórz folder" },
            { TXT_FOLDER_READ_FAILED, L"Nie można odczytać folderu:\n\n%s\n\nBłąd systemu Windows %lu." },
            { TXT_ADVANCED_MODE, L"Tryb &zaawansowany" },
            { TXT_REPORT_DETAIL_REJECTED,
                L"Wybrana biblioteka MediaInfo.dll odrzuciła ustawienie szczegółowości raportu."
            },
            { TXT_KNOWN_FORMATS, L"Znane &formaty" },
            { TXT_KNOWN_CODECS, L"Znane &kodeki" },
            { TXT_KNOWN_PARAMETERS, L"Znane para&metry" },
            { TXT_KNOWN_FORMATS_TITLE, L"Znane formaty" },
            { TXT_KNOWN_CODECS_TITLE, L"Znane kodeki" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Znane parametry" },
            { TXT_KNOWN_INFO_FAILED, L"Biblioteka nie zwróciła żądanych informacji." },
            { TXT_FULL_PARSING, L"Pełna &analiza" },
            { TXT_PARSING_REJECTED, L"Wybrana biblioteka MediaInfo.dll odrzuciła ustawienie analizy." },
            { TXT_TRACE_LEVEL_0, L"Poziom śledzenia &0" },
            { TXT_TRACE_LEVEL_5, L"Poziom śledzenia &5" },
            { TXT_TRACE_LEVEL_9, L"Poziom śledzenia &9" },
            { TXT_TRACE_LEVEL_10, L"Poziom śledzenia &10" },
            { TXT_PAGE_SETUP, L"Ustawienia &strony…" },
            { TXT_PAGE_SETUP_FAILED, L"Nie można otworzyć ustawień strony." },
            { TXT_PRINT, L"&Drukuj…\tCtrl+P" },
            { TXT_PRINTING, L"Drukowanie…" },
            { TXT_PRINT_FAILED,
                L"Nie można wydrukować tekstu. Sprawdź drukarkę, jej ustawienia i dostępną pamięć."
            },
            { TXT_TOOLS_MENU, L"&Narzędzia" },
            { TXT_CREATE_HEADER, L"Utwórz plik &nagłówka…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Utwórz plik nagłówka - Otwórz" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Utwórz plik nagłówka - Zapisz jako" },
            { TXT_HEADER_FORMAT, L"Plik nagłówka (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Nie można odczytać nagłówka pliku:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Nie można zapisać pliku nagłówka:\n\n%s" },
            { TXT_COPY, L"&Kopiuj" },
            { TXT_COPY_FILE_NAME, L"Kopiuj n&azwę pliku" },
            { TXT_COPY_FULL_PATH, L"Kopiuj pełną &ścieżkę" },
            { TXT_LAUNCH_FILE, L"&Uruchom plik" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"&Pokaż w folderze" },
            { TXT_EDIT_MENU, L"&Edycja" },
            { TXT_WORD_WRAP, L"Za&wijanie wierszy" },
            { TXT_WORD_WRAP_FAILED, L"Nie można zmienić zawijania wierszy." },
            { TXT_COPY_SELECTION, L"&Kopiuj\tCtrl+C" },
            { TXT_SELECT_ALL, L"Zaznacz &wszystko\tCtrl+A" },
            { TXT_FIND_MENU, L"&Znajdź…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Znajdź &następny\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Znajdź &poprzedni\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Znajdź" },
            { TXT_FIND_WHAT, L"Znajdź &tekst:" },
            { TXT_FIND_NEXT, L"Znajdź &następny" },
            { TXT_FIND_MATCH_CASE, L"Uwzględnij &wielkość liter" },
            { TXT_FIND_BACKWARD, L"Szukaj w&stecz" },
            { TXT_FIND_TOPMOST, L"Z&awsze na wierzchu" },
            { TXT_FIND_STARTS_WITH, L"Wiersz zaczyna się &od" },
            { TXT_FIND_ENDS_WITH, L"Wiersz &kończy się na" },
            { TXT_FIND_REGEX, L"Wyrażenie &regularne" },
            { TXT_FIND_NOT_FOUND, L"Nie znaleziono podanego tekstu." },
            { TXT_FIND_FAILED, L"Nie można ukończyć wyszukiwania." },
            { TXT_FIND_REGEX_ERROR, L"Błąd wyrażenia regularnego:\r\n\r\n%s" },
        }
    },
    {
        LANG_SK,
        {
            { TXT_LANGUAGE_NAME, L"Slovenčina" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nWeb: " },
            { TXT_FILE_OPEN_FAILED, L"Nemožno otvoriť %s. Skontrolujte cestu a oprávnenia." },
            { TXT_BROWSE_DLL, L"Prehľadá&vať…" },
            { TXT_BROWSE_REPORT, L"Pre&hľadávať…" },
            { TXT_CLOSE, L"&Zavrieť" },
            { TXT_CLOSE_TAB, L"&Zavrieť\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"Pre&dvolené" },
            { TXT_EXPORT, L"&Exportovať…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Súbor" },
            { TXT_REPORT_FONT, L"&Písmo reportu:" },
            { TXT_HELP_MENU, L"&Pomoc" },
            { TXT_HELP, L"&Pomoc\tF1" },
            { TXT_LANGUAGE, L"&Jazyk:" },
            { TXT_OPEN_WEBSITE, L"&Otvoriť v predvolenom prehliadači" },
            { TXT_OPEN, L"&Otvoriť…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Možnosti" },
            { TXT_PREFERENCES_MENU, L"&Predvoľby…\tCtrl+G" },
            { TXT_ABOUT, L"&O programe" },
            { TXT_ABOUT_TITLE, L"O programe %ls" },
            { TXT_ALL_FILES, L"Všetky súbory" },
            { TXT_FONT_BOLD, L"Tučné" },
            { TXT_FONT_BOLD_ITALIC, L"Tučná kurzíva" },
            { TXT_BROWSE_CURL, L"Pr&ehľadávať…" },
            { TXT_CANCEL, L"Zrušiť" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Nemožno načítať MediaInfo.dll (chyba Windows %lu). Použite 32-bitovú DLL kompatibilnú s "
                L"touto verziou Windows."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Nemožno načítať libcurl.dll (chyba Windows %lu). Vyberte 32-bitovú knižnicu kompatibilnú s "
                L"touto verziou Windows."
            },
            { TXT_CLOSE_ALL, L"Zavrieť &všetko" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Kopírovať &adresu" },
            { TXT_COPY_INFORMATION, L"Kopírovať &informácie" },
            { TXT_DLL_FILES, L"Dynamické knižnice" },
            { TXT_EXIT, L"&Koniec\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Vložené knižnice MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Vložené knižnice libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Exportovať report" },
            { TXT_FONT_ANTIALIASING, L"Vyhladzovanie pís&ma:" },
            { TXT_GIF_EXPORT_FAILED, L"Export GIF zlyhal. Presný výstup GIF vyžaduje najviac 256 farieb." },
            { TXT_FONT_ITALIC, L"Kurzíva" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED, L"Export JPEG zlyhal. Vyžaduje sa funkčný kodér JPEG systému GDI+." },
            { TXT_LICENSE_UNAVAILABLE, L"Licenčný prostriedok nie je dostupný." },
            { TXT_MEDIA_FILES, L"Multimediálne súbory" },
            { TXT_APPLICATION_DESCRIPTION, L"Prehliadač informácií o médiách" },
            { TXT_HELP_TITLE, L"MediaInfo — Pomoc" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo nemôže inicializovať analýzu súboru." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo nemôže otvoriť alebo rozpoznať tento súbor." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"&Cesta k MediaInfo.dll:" },
            { TXT_MEDIALIB_REQUIRED,
                L"MediaInfo.dll nie je načítaná. Vyberte ju v ponuke Možnosti > Predvoľby."
            },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll nie je načítaná." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Nemožno načítať kompatibilnú externú ani vloženú MediaInfo.dll. Vyberte ju v ponuke "
                L"Možnosti > Predvoľby."
            },
            { TXT_ANTIALIASING_NONE, L"Žiadne" },
            { TXT_OK, L"OK" },
            { TXT_OPEN_TITLE, L"Otvoriť multimediálne súbory" },
            { TXT_PLATFORM, L"Cieľová platforma:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Predvoľby" },
            { TXT_READY, L"Pripravený" },
            { TXT_FONT_REGULAR, L"Normálne" },
            { TXT_REPORT_LANGUAGE, L"Jazyk &reportu:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Jazykové tabuľky reportu" },
            { TXT_SELECT_MEDIALIB, L"Vybrať: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Vybrať: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH,
                L"Vyberte existujúci multimediálny súbor s cestou kratšou než MAX_PATH."
            },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Vyberte súbory s cestami kratšími než MAX_PATH." },
            { TXT_SELECT_CURL, L"Vybrať: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Textový dokument ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"Obrázok BMP nemožno uložiť. Skontrolujte cieľ, voľnú pamäť a miesto na disku."
            },
            { TXT_LIBRARY_WORKER_START_FAILED, L"Proces knižnice nemožno spustiť (chyba Windows %lu)." },
            { TXT_REPORT_COPY_FAILED, L"Report MediaInfo nemožno skopírovať do pamäte." },
            { TXT_VIEWER_CREATE_FAILED, L"Prehliadač MediaInfo nemožno vytvoriť." },
            { TXT_MEDIALIB_PATH_INVALID, L"Cesta k MediaInfo.dll je neplatná alebo príliš dlhá." },
            { TXT_PNG_EXPORT_FAILED,
                L"Obrázok PNG nemožno uložiť. Skontrolujte cieľ, voľnú pamäť a miesto na disku."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"Obrázok TIFF nemožno uložiť. Skontrolujte cieľ, voľnú pamäť a miesto na disku."
            },
            { TXT_COPY_URL_FAILED, L"Adresu URL nemožno skopírovať do schránky." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"Prehliadač Win32 vyžaduje 32-bitovú %s. Vyberte knižnicu x86/i386."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Vloženú knižnicu nemožno zapísať do AppData, profilu používateľa, Program Files ani "
                L"dočasného priečinka."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED, L"Dekompresia knižnice alebo kontrola CRC zlyhala." },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Prostriedok vloženej knižnice je neplatný." },
            { TXT_CURL_FILENAME_INVALID,
                L"Knižnica sa musí volať libcurl.dll, aby ju MediaInfo mohla používať."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Dialóg na výber súborov nemožno otvoriť." },
            { TXT_FILE_DIALOG_SELECTION_FAILED,
                L"Z dialógu na výber súborov nemožno získať vybrané súbory."
            },
            { TXT_RECENT_FILE_MISSING,
                L"Súbor „%s“ už neexistuje.\n\nOdstrániť položku zo zoznamu posledných súborov?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Súbor už nie je dostupný:\n\n%s\n\nOdstrániť položku zo zoznamu posledných súborov?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Informácie nemožno skopírovať do schránky." },
            { TXT_CURL_PATH_INVALID, L"Cesta k libcurl.dll je neplatná alebo príliš dlhá." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Knižnica nevrátila verziu MediaInfo." },
            { TXT_CURL_EXPORTS_MISSING,
                L"Knižnica neexportuje funkcie curl požadované knižnicou MediaInfo."
            },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"Knižnica neexportuje požadované funkcie Unicode knižnice MediaInfo."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Proces knižnice zlyhal pri %s (kód 0x%08lX). Vyberte kompatibilnú DLL v ponuke Možnosti > "
                L"Predvoľby."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Proces knižnice prestal odpovedať pri %s. Vyberte kompatibilnú DLL v ponuke Možnosti > "
                L"Predvoľby."
            },
            { TXT_PREFERENCES_SAVE_FAILED,
                L"Nastavenia sa použili, ale nepodarilo sa ich uložiť do registra."
            },
            { TXT_REPORT_START_FAILED, L"Na spustenie reportu nie je dostatok pamäte." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Obrázok reportu nemožno vytvoriť." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Jazykovú tabuľku nemožno načítať. Vyberte platný súbor "
                L"MediaInfo CSV v UTF-8 alebo UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"Vlákno reportu nemožno spustiť." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"Vybraná MediaInfo.dll odmietla jazyk reportu." },
            { TXT_INVALID_WINDOWS_DLL, L"Vybraný súbor nie je platná knižnica DLL systému Windows." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Vybraný formát obrázka nie je podporovaný." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Textový report nemožno uložiť. Skontrolujte cieľ a voľné miesto na disku."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Web nemožno otvoriť v predvolenom prehliadači." },
            { TXT_TOO_MANY_FILES, L"Bolo vybraných príliš veľa súborov. Otvárajte menšie skupiny." },
            { TXT_LIBRARY_PATH_HINT,
                L"Použite 32-bitové knižnice kompatibilné s vašou verziou Windows. Ponechajte cesty prázdne "
                L"pre automatické vyhľadávanie. MediaInfoLib v0.7.60 nepoužíva libcurl.dll."
            },
            { TXT_VERSION, L"Verzia" },
            { TXT_WEBSITE_TOOLTIP, L"Navštíviť web %s" },
            { TXT_WAITING_FOR_REPORT, L"Čaká sa na dokončenie aktuálneho reportu." },
            { TXT_WEBSITE_LABEL, L"Web:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"kopírovaní reportu MediaInfo" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"Ce&sta k libcurl.dll:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"načítavaní MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"načítavaní libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"uvoľňovaní MediaInfo.dll" },
            { TXT_APPLY, L"P&oužiť" },
            { TXT_TAB_NAME_LENGTH, L"Dĺžka názvu &karty:" },
            { TXT_TITLE_NAME_LENGTH, L"Dĺžka &názvu záhlavia:" },
            { TXT_RECENT_FILES, L"Posledné súbory:" },
            { TXT_CLEAR_RECENT_FILES, L"Vyma&zať" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"Dĺžka názvu karty musí byť medzi 8 a 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"Dĺžka názvu v záhlaví musí byť medzi 8 a 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Zoznam posledných súborov bol vymazaný, ale nepodarilo sa ho uložiť do registra."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"Z&atvárať karty dvojklikom" },
            { TXT_CLOSE_TAB_CONTEXT, L"Zavrieť &kartu" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"Povo&liť viac inštancií" },
            { TXT_INSTANCE_FORWARD_FAILED, L"Súbory sa nepodarilo odovzdať spustenej inštancii MediaInfo." },
            { TXT_LOADING, L"Načítavanie…" },
            { TXT_LOADING_FILE, L"Načítavanie súboru %s…" },
            { TXT_APPLICATION_HELP,
                L"SÚBORY A KARTY\r\nNatívny prehliadač reportov MediaInfo.dll pre Windows x86. Každý "
                L"súbor má vlastnú kartu iba na čítanie. Súbory otvorte cez Ctrl+O alebo potiahnutím. "
                L"Opätovné otvorenie vyberie existujúcu kartu. Ctrl+W alebo prostredné tlačidlo myši "
                L"kartu zavrie; Zavrieť všetko zavrie všetky karty. Ponuka Súbor uchováva osem posledných "
                L"súborov. Kontextová ponuka záhlavia karty obsahuje príkaz Zavrieť kartu. Voľba Zatvárať "
                L"karty dvojklikom v Predvoľbách umožní zatváranie dvojklikom na záhlavie. Predvolene je "
                L"vypnutá a jej nastavenie sa ukladá. Dvojklik v texte reportu vyberie slovo. Trojklik "
                L"vyberie logický riadok. Ťahanie rozširuje výber po slovách alebo riadkoch.\r\nOtvoriť "
                L"priečinok… otvorí súbory priamo vo vybranom priečinku, každý na vlastnej karte. "
                L"Podpriečinky sa neprechádzajú.\r\nOtvoriť a Otvoriť priečinok zdieľajú naposledy "
                L"vybraný priečinok. Export si pamätá vlastný priečinok, predvolené sú Dokumenty. "
                L"Pokročilý režim zobrazí ďalšie údaje v reporte.\r\nZnáme formáty / Známe kodeky / Známe "
                L"parametre — MediaInfo.dll.\r\nÚplná analýza preskúma celý súbor a môže trvať dlhšie. "
                L"Tieto voľby reportu a Úroveň trasovania patria jednotlivým kartám; zmena obnoví iba "
                L"aktívnu kartu. Posledná ručne zvolená kombinácia sa uloží pre nové karty a ďalšie "
                L"spustenie. Už získaný report pre rovnakú kombináciu sa použije znova, ak sa súbor "
                L"nezmenil.\r\nÚroveň trasovania: 0 / 5 / 9 / 10.\r\nSúbor > Vzhľad strany… otvorí "
                L"nastavenia papiera, orientácie a okrajov pre aktuálne spustenie aplikácie. Tlačiť… "
                L"(Ctrl+P) otvorí systémový tlačový dialóg; Windows 11 poskytuje náhľad, Windows 10 a "
                L"staršie zachovávajú klasický dialóg. Ctrl+P vytlačí aktívnu kartu hlavného okna alebo "
                L"textovú oblasť Pomoci či O programe podľa toho, ktoré okno má fokus. Reporty používajú "
                L"zvolené písmo reportu, Pomoc systémové dialógové písmo a O programe písmo svojej "
                L"textovej oblasti. Ak nie sú otvorené žiadne karty a Pomoc je otvorená, Vzhľad strany… "
                L"aj Tlačiť… zostávajú dostupné; Tlačiť… vytlačí Pomoc. Pomoc používa tlačový dialóg "
                L"hlavného okna; ďalšie Ctrl+P v Pomoci ho prenesie do popredia. Dlhé riadky sa zalomia a "
                L"text sa rozdelí na strany. Tlač prebieha na pozadí.\r\nPresuňte jeden alebo viac "
                L"súborov do okna, na ikonu EXE alebo jeho zástupcu, prípadne odovzdajte ich cesty v "
                L"príkazovom riadku. Ak nie je povolených viac inštancií, súbory sa otvoria v už "
                L"spustenom okne.\r\nVľavo v stavovom riadku sa zobrazuje cesta k súboru a priebeh "
                L"načítavania, vpravo verzia načítanej MediaInfo.dll. Dlhé cesty sa podľa dostupného "
                L"miesta skracujú výpustkou.\r\n\r\nEXPORT\r\nTXT, BMP, GIF, JPEG, PNG, TIFF a WebP sa "
                L"ponúkajú podľa dostupnosti. Posledný priečinok a formát exportu sa pamätajú.\r\nTXT "
                L"ponúka ANSI, UTF-8, UTF-8 s BOM, UTF-16 BE s BOM a UTF-16 LE s BOM. Predvolená je druhá "
                L"položka, UTF-8 bez BOM. Zachováva sa celý text reportu aj jeho pôvodné konce "
                L"riadkov.\r\n\r\nVYTVORIŤ SÚBOR HLAVIČKY\r\nPonuka Nástroje je štvrtou hlavnou ponukou. "
                L"Príkaz Vytvoriť súbor hlavičky… otvorí jeden vstupný súbor nezávisle od kariet reportov "
                L"a skopíruje jeho prvých 524288 bajtov (512 KiB). Kratší súbor sa skopíruje celý; "
                L"prázdny súbor vytvorí prázdny výstup. Ide o bežné binárne čítanie súboru bez analýzy "
                L"MediaInfo; knižnica MediaInfo.dll nie je potrebná. Karty reportov ani zoznam posledných "
                L"súborov sa tým nemenia.\r\n\r\nPo prečítaní sa otvorí dialógové okno Uložiť ako v "
                L"priečinku vstupného súboru. Pre video.mp4 ponúkne názov video.mp4.header: .header sa "
                L"pripojí za celý pôvodný názov vrátane prípony. Názov aj cieľový priečinok môžete "
                L"zmeniť. Zrušenie ktoréhokoľvek dialógového okna nič neuloží. Prepísanie existujúceho "
                L"cieľového súboru vyžaduje potvrdenie. Vstupný súbor zostane nezmenený a chyba ukladania "
                L"zachová pôvodný cieľový súbor. Na otváranie aj ukladanie sa používajú najmodernejšie "
                L"systémové dialógové okná dostupné v danej verzii Windows.\r\n\r\nPri spustení aplikácie "
                L"prevezme nástroj rovnaký počiatočný priečinok ako príkaz Súbor > Otvoriť. Ak žiadny "
                L"priečinok nie je uložený, počiatočné umiestnenie určí Windows. Po výbere vstupného "
                L"súboru si nástroj svoj priečinok pamätá iba do ukončenia aplikácie, aj keď dialógové "
                L"okno Uložiť ako zrušíte. Nemení priečinky príkazov Otvoriť a Exportovať a aplikácia "
                L"jeho vlastnú cestu neukladá do registra. Každé dialógové okno Uložiť ako začne v "
                L"priečinku práve vybraného vstupného súboru bez ohľadu na predchádzajúci cieľ "
                L"ukladania.\r\n\r\nPREDVOĽBY A JAZYKY\r\nPredvoľby (Možnosti > Predvoľby, Ctrl+G) "
                L"obsahujú cesty ku knižniciam, písmo reportu, vyhladzovanie a jazyky. Rozhranie má 36 "
                L"variantov a spočiatku sa riadi Windows. Reporty sú vždy predvolene v pôvodnej "
                L"angličtine knižnice, nezávisle od Windows a rozhrania. Zmení to iba ručná voľba: "
                L"angličtina, 37 prekladov alebo vlastná tabuľka MediaInfo CSV. OK alebo Použiť potvrdí "
                L"zmeny; Zrušiť zahodí rozpracované úpravy. Predvoľby umožňujú zmeniť limit dĺžky názvu "
                L"karty (predvolene 80 znakov) a vymazať zoznam posledných súborov. Dlhé názvy zachovajú "
                L"začiatok, koniec aj príponu s výpustkou uprostred. Tlačidlo Vymazať odstráni zoznam "
                L"posledných súborov okamžite, aj keď potom zatvoríte Predvoľby tlačidlom "
                L"Zrušiť.\r\n\r\nZáhlavie hlavného okna zobrazuje aktívny súbor v tvare názov súboru — "
                L"MediaInfo. V predvoľbách možno samostatne nastaviť dĺžku názvu v záhlaví na 8–255 znakov; "
                L"predvolená hodnota je 40. Dlhšie názvy sa skracujú rovnakou výpustkou uprostred so "
                L"zachovaním prípony. Bez otvorených kariet je záhlavie MediaInfo.\r\n\r\n"
                L"KNIŽNICE A OKNÁ\r\nEXE obsahuje knižnice MediaInfo 26.10, 21.03 a 0.7.60. Po externých "
                L"knižniciach sa skúšajú od najnovšej verzie. Dve novšie verzie majú príslušnú libcurl; "
                L"0.7.60 ju nikdy nerozbaľuje. Poloha okna sa ukladá. Predvolene je povolená iba jedna "
                L"inštancia a ďalšie spustenie odovzdá súbory otvorenému oknu. V Predvoľbách možno "
                L"povoliť viac inštancií. Pri viacerých oknách sa uložená poloha obnoví len prvému oknu "
                L"daného typu; ďalšie prevezmú iba uloženú veľkosť.\r\n\r\nÚpravy > Hľadať (Ctrl+F) hľadá "
                L"podľa fokusu okna v aktívnej karte hlavného okna, v textovej oblasti Pomoci alebo v "
                L"textovej oblasti O programe. Okno hľadania si počas vlastného fokusu ponechá naposledy "
                L"zvolený zdroj. F3 hľadanie opakuje, Shift+F3 obráti jeho smer. Po dosiahnutí okraja "
                L"textu pokračuje hľadanie na opačnom konci. Možnosti > Zalamovanie riadkov ovplyvňuje "
                L"iba aktívnu kartu; začiarknutie sa mení podľa vybratej karty. Formulár hľadania možno "
                L"minimalizovať a meniť jeho šírku; pamätá si polohu a voľbu Vždy navrchu. História "
                L"uchováva najviac 30 hľadaných textov s ich voľbami iba do ukončenia aplikácie. Začína "
                L"na a Končí na hľadajú na okrajoch logických riadkov. Regulárne výrazy používajú syntax "
                L"PCRE2. Ostatné príkazy ponuky Úpravy sa vzťahujú na aktívnu kartu reportu. Enter spustí "
                L"hľadanie, Shift+Enter obráti zvolený smer. Voľba „Rozlišovať veľké a malé písmená“ "
                L"rozlišuje veľké a malé písmená; „Hľadať dozadu“ hľadá smerom k začiatku textu. Výber z "
                L"histórie obnoví všetkých päť volieb hľadania vrátane uloženého stavu regulárneho "
                L"výrazu; „Vždy navrchu“ je nezávislá voľba. „Regulárny výraz“ vypne voľby „Začína na“ a "
                L"„Končí na“. Ak sú zapnuté obe voľby okrajov riadka, stačí zhoda na jednom z nich. "
                L"„Zalamovanie riadkov“ mení iba zobrazenie."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"Obrázok WebP nemožno uložiť. Skontrolujte cieľ, voľnú pamäť a miesto na disku."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Textový dokument UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Textový dokument UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Textový dokument UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Textový dokument UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Report nemožno v tomto kódovaní uložiť bez straty znakov. Vyberte iné kódovanie textu."
            },
            { TXT_OPEN_FOLDER, L"Otvoriť p&riečinok…" },
            { TXT_OPEN_FOLDER_TITLE, L"Otvoriť priečinok" },
            { TXT_FOLDER_READ_FAILED, L"Priečinok sa nedá prečítať:\n\n%s\n\nChyba systému Windows %lu." },
            { TXT_ADVANCED_MODE, L"Pok&ročilý režim" },
            { TXT_REPORT_DETAIL_REJECTED,
                L"Vybraná knižnica MediaInfo.dll odmietla nastavenie podrobností reportu."
            },
            { TXT_KNOWN_FORMATS, L"Známe &formáty" },
            { TXT_KNOWN_CODECS, L"Známe &kodeky" },
            { TXT_KNOWN_PARAMETERS, L"Známe pa&rametre" },
            { TXT_KNOWN_FORMATS_TITLE, L"Známe formáty" },
            { TXT_KNOWN_CODECS_TITLE, L"Známe kodeky" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Známe parametre" },
            { TXT_KNOWN_INFO_FAILED, L"Knižnica nevrátila požadované informácie." },
            { TXT_FULL_PARSING, L"Úplná &analýza" },
            { TXT_PARSING_REJECTED, L"Vybraná knižnica MediaInfo.dll odmietla nastavenie analýzy." },
            { TXT_TRACE_LEVEL_0, L"Úroveň trasovania &0" },
            { TXT_TRACE_LEVEL_5, L"Úroveň trasovania &5" },
            { TXT_TRACE_LEVEL_9, L"Úroveň trasovania &9" },
            { TXT_TRACE_LEVEL_10, L"Úroveň trasovania &10" },
            { TXT_PAGE_SETUP, L"Vz&hľad strany…" },
            { TXT_PAGE_SETUP_FAILED, L"Vzhľad strany sa nepodarilo otvoriť." },
            { TXT_PRINT, L"&Tlačiť…\tCtrl+P" },
            { TXT_PRINTING, L"Tlač…" },
            { TXT_PRINT_FAILED,
                L"Text sa nepodarilo vytlačiť. Skontrolujte tlačiareň, jej nastavenia a dostupnú pamäť."
            },
            { TXT_TOOLS_MENU, L"Nás&troje" },
            { TXT_CREATE_HEADER, L"Vytvoriť súbor &hlavičky…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Vytvoriť súbor hlavičky - Otvoriť" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Vytvoriť súbor hlavičky - Uložiť ako" },
            { TXT_HEADER_FORMAT, L"Súbor hlavičky (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Hlavičku súboru sa nepodarilo prečítať:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Súbor hlavičky sa nepodarilo uložiť:\n\n%s" },
            { TXT_COPY, L"&Kopírovať" },
            { TXT_COPY_FILE_NAME, L"Kopírovať ná&zov súboru" },
            { TXT_COPY_FULL_PATH, L"Kopírovať úplnú &cestu" },
            { TXT_LAUNCH_FILE, L"&Spustiť súbor" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"Zo&braziť v priečinku" },
            { TXT_EDIT_MENU, L"&Úpravy" },
            { TXT_WORD_WRAP, L"&Zalamovanie riadkov" },
            { TXT_WORD_WRAP_FAILED, L"Zalamovanie riadkov sa nepodarilo zmeniť." },
            { TXT_COPY_SELECTION, L"&Kopírovať\tCtrl+C" },
            { TXT_SELECT_ALL, L"Vybrať &všetko\tCtrl+A" },
            { TXT_FIND_MENU, L"&Hľadať…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Hľadať ď&alej\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Hľadať &predchádzajúce\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Hľadať" },
            { TXT_FIND_WHAT, L"&Hľadať:" },
            { TXT_FIND_NEXT, L"Hľadať ď&alej" },
            { TXT_FIND_MATCH_CASE, L"Rozlišovať &veľké a malé písmená" },
            { TXT_FIND_BACKWARD, L"Hľadať &dozadu" },
            { TXT_FIND_TOPMOST, L"Vždy navr&chu" },
            { TXT_FIND_STARTS_WITH, L"Začína &na" },
            { TXT_FIND_ENDS_WITH, L"&Končí na" },
            { TXT_FIND_REGEX, L"&Regulárny výraz" },
            { TXT_FIND_NOT_FOUND, L"Zadaný text sa nenašiel." },
            { TXT_FIND_FAILED, L"Vyhľadávanie sa nepodarilo dokončiť." },
            { TXT_FIND_REGEX_ERROR, L"Chyba regulárneho výrazu:\r\n\r\n%s" },
        }
    },
    {
        LANG_DA,
        {
            { TXT_LANGUAGE_NAME, L"Dansk" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nWebsted: " },
            { TXT_FILE_OPEN_FAILED, L"Kan ikke åbne %s. Kontrollér sti og rettigheder." },
            { TXT_BROWSE_DLL, L"&Gennemse…" },
            { TXT_BROWSE_REPORT, L"Ge&nnemse…" },
            { TXT_CLOSE, L"&Luk" },
            { TXT_CLOSE_TAB, L"&Luk\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"Stan&dard" },
            { TXT_EXPORT, L"&Eksportér…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Filer" },
            { TXT_REPORT_FONT, L"Rapportskrift&type:" },
            { TXT_HELP_MENU, L"&Hjælp" },
            { TXT_HELP, L"&Hjælp\tF1" },
            { TXT_LANGUAGE, L"S&prog:" },
            { TXT_OPEN_WEBSITE, L"&Åbn i standardbrowseren" },
            { TXT_OPEN, L"&Åbn…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Indstillinger" },
            { TXT_PREFERENCES_MENU, L"&Præferencer…\tCtrl+G" },
            { TXT_ABOUT, L"&Om" },
            { TXT_ABOUT_TITLE, L"Om %ls" },
            { TXT_ALL_FILES, L"Alle filer" },
            { TXT_FONT_BOLD, L"Fed" },
            { TXT_FONT_BOLD_ITALIC, L"Fed + Kursiv" },
            { TXT_BROWSE_CURL, L"G&ennemse…" },
            { TXT_CANCEL, L"Annuller" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Kan ikke indlæse MediaInfo.dll (Windows-fejl %lu). Brug en 32-bit-DLL, der er kompatibel "
                L"med denne Windows-version."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Kan ikke indlæse libcurl.dll (Windows-fejl %lu). Vælg et 32-bit-bibliotek, der er "
                L"kompatibelt med denne Windows-version."
            },
            { TXT_CLOSE_ALL, L"Luk &alle" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Kopiér &URL" },
            { TXT_COPY_INFORMATION, L"Kopiér &oplysninger" },
            { TXT_DLL_FILES, L"Dynamiske biblioteker" },
            { TXT_EXIT, L"A&fslut\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Indlejrede biblioteker MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Indlejrede biblioteker libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Eksportér rapport" },
            { TXT_FONT_ANTIALIASING, L"Skri&ftudjævning:" },
            { TXT_GIF_EXPORT_FAILED, L"GIF-eksport mislykkedes. Tabsfri GIF kræver højst 256 farver." },
            { TXT_FONT_ITALIC, L"Kursiv" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED, L"JPEG-eksport mislykkedes. En fungerende GDI+-JPEG-koder kræves." },
            { TXT_LICENSE_UNAVAILABLE, L"Licensressourcen er ikke tilgængelig." },
            { TXT_MEDIA_FILES, L"Mediefiler" },
            { TXT_APPLICATION_DESCRIPTION, L"Visning af medieoplysninger" },
            { TXT_HELP_TITLE, L"MediaInfo — Hjælp" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo kunne ikke initialisere analysen af filen." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo kan ikke åbne eller genkende denne fil." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"&Sti til MediaInfo.dll:" },
            { TXT_MEDIALIB_REQUIRED,
                L"MediaInfo.dll er ikke indlæst. Vælg den under Indstillinger > Præferencer."
            },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll er ikke indlæst." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Ingen kompatibel ekstern eller indlejret MediaInfo.dll kunne indlæses. Vælg den under "
                L"Indstillinger > Præferencer."
            },
            { TXT_ANTIALIASING_NONE, L"Ingen" },
            { TXT_OK, L"OK" },
            { TXT_OPEN_TITLE, L"Åbn mediefiler" },
            { TXT_PLATFORM, L"Målplatform:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Præferencer" },
            { TXT_READY, L"Klar" },
            { TXT_FONT_REGULAR, L"Normal" },
            { TXT_REPORT_LANGUAGE, L"&Rapportsprog:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Rapportsprogtabeller" },
            { TXT_SELECT_MEDIALIB, L"Gennemse: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Gennemse: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH,
                L"Vælg en eksisterende mediefil med en sti, der er kortere end MAX_PATH."
            },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Vælg eksisterende filer med stier kortere end MAX_PATH." },
            { TXT_SELECT_CURL, L"Gennemse: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Tekstdokument ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"BMP-billedet kan ikke gemmes. Kontrollér destination, ledig hukommelse og diskplads."
            },
            { TXT_LIBRARY_WORKER_START_FAILED, L"Biblioteksprocessen kan ikke startes (Windows-fejl %lu)." },
            { TXT_REPORT_COPY_FAILED, L"MediaInfo-rapporten kan ikke kopieres til hukommelsen." },
            { TXT_VIEWER_CREATE_FAILED, L"MediaInfo-viseren kan ikke oprettes." },
            { TXT_MEDIALIB_PATH_INVALID, L"Stien til MediaInfo.dll er ugyldig eller for lang." },
            { TXT_PNG_EXPORT_FAILED,
                L"PNG-billedet kan ikke gemmes. Kontrollér destination, ledig hukommelse og diskplads."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"TIFF-billedet kan ikke gemmes. Kontrollér destination, ledig hukommelse og diskplads."
            },
            { TXT_COPY_URL_FAILED, L"URL-adressen kunne ikke kopieres til udklipsholderen." },
            { TXT_LIBRARY_REQUIRES_X86, L"Win32-viseren kræver en 32-bit-%s. Vælg x86/i386-biblioteket." },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Det indlejrede bibliotek kan ikke skrives til AppData, brugerprofilen, Program Files eller "
                L"den midlertidige mappe."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED,
                L"Bibliotekets dekomprimering eller CRC-kontrol mislykkedes."
            },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Den indlejrede biblioteksressource er ugyldig." },
            { TXT_CURL_FILENAME_INVALID, L"Biblioteket skal hedde libcurl.dll, så MediaInfo kan bruge det." },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Fildialogen kunne ikke åbnes." },
            { TXT_FILE_DIALOG_SELECTION_FAILED, L"De valgte filer kunne ikke hentes fra fildialogen." },
            { TXT_RECENT_FILE_MISSING,
                L"Filen »%s« findes ikke længere.\n\nVil du fjerne denne post fra listen over seneste filer?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Filen er ikke længere tilgængelig:\n\n%s\n\nVil du fjerne denne post fra listen over "
                L"seneste filer?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Oplysningerne kunne ikke kopieres til udklipsholderen." },
            { TXT_CURL_PATH_INVALID, L"Stien til libcurl.dll er ugyldig eller for lang." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Biblioteket returnerede ingen MediaInfo-version." },
            { TXT_CURL_EXPORTS_MISSING,
                L"Biblioteket eksporterer ikke de curl-funktioner, som MediaInfo kræver."
            },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"Biblioteket eksporterer ikke de nødvendige Unicode-funktioner til MediaInfo."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Biblioteksprocessen fejlede under %s (kode 0x%08lX). Vælg en kompatibel DLL under "
                L"Indstillinger > Præferencer."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Biblioteksprocessen svarer ikke under %s. Vælg en kompatibel DLL under Indstillinger > "
                L"Præferencer."
            },
            { TXT_PREFERENCES_SAVE_FAILED,
                L"Indstillingerne blev anvendt, men kunne ikke gemmes i registreringsdatabasen."
            },
            { TXT_REPORT_START_FAILED, L"Ikke nok hukommelse til at starte rapporten." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Rapportbilledet kan ikke oprettes." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Sprogtabellen kan ikke indlæses. Vælg en gyldig "
                L"MediaInfo-CSV-fil i UTF-8 eller UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"Rapporttråden kan ikke startes." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"Den valgte MediaInfo.dll afviste rapportsproget." },
            { TXT_INVALID_WINDOWS_DLL, L"Den valgte fil er ikke en gyldig Windows-DLL." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Det valgte billedformat understøttes ikke." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Tekstrapporten kan ikke gemmes. Kontrollér destination og ledig diskplads."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Webstedet kan ikke åbnes i standardbrowseren." },
            { TXT_TOO_MANY_FILES, L"Der er valgt for mange filer. Åbn mindre grupper." },
            { TXT_LIBRARY_PATH_HINT,
                L"Brug 32-bit-biblioteker, der er kompatible med din Windows-version. Lad stierne være tomme "
                L"for automatisk søgning. MediaInfoLib v0.7.60 bruger ikke libcurl.dll."
            },
            { TXT_VERSION, L"Version" },
            { TXT_WEBSITE_TOOLTIP, L"Besøg webstedet %s" },
            { TXT_WAITING_FOR_REPORT, L"Venter på, at den aktuelle rapport afsluttes." },
            { TXT_WEBSITE_LABEL, L"Websted:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"kopiering af MediaInfo-rapporten" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"Sti til libc&url.dll:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"indlæsning af MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"indlæsning af libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"frigivelse af MediaInfo.dll" },
            { TXT_APPLY, L"&Anvend" },
            { TXT_TAB_NAME_LENGTH, L"&Længde på fanenavn:" },
            { TXT_TITLE_NAME_LENGTH, L"Titell&ængde:" },
            { TXT_RECENT_FILES, L"Seneste filer:" },
            { TXT_CLEAR_RECENT_FILES, L"R&yd" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"Fanenavnets længde skal være mellem 8 og 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"Navnets længde i titlen skal være mellem 8 og 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Listen over seneste filer blev ryddet, men kunne ikke gemmes i registreringsdatabasen."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"Lu&k faner ved dobbeltklik" },
            { TXT_CLOSE_TAB_CONTEXT, L"Luk &fane" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"T&illad flere instanser" },
            { TXT_INSTANCE_FORWARD_FAILED, L"Filerne kunne ikke sendes til den kørende MediaInfo-instans." },
            { TXT_LOADING, L"Indlæser…" },
            { TXT_LOADING_FILE, L"Indlæser filen %s…" },
            { TXT_APPLICATION_HELP,
                L"FILER OG FANER\r\nWindows x86-fremviser til MediaInfo.dll-rapporter. Hver fil har sin "
                L"egen skrivebeskyttede fane. Åbn filer med Ctrl+O eller træk og slip. Genåbning vælger "
                L"den eksisterende fane. Ctrl+W eller den midterste museknap lukker en fane; Luk alle "
                L"lukker samtlige faner. Menuen Filer husker de otte seneste filer. Fanens kontekstmenu "
                L"indeholder Luk fane. Aktivér Luk faner ved dobbeltklik i Præferencer for at lukke en "
                L"fane ved at dobbeltklikke på dens overskrift. Indstillingen er som standard slået fra "
                L"og gemmes. Dobbeltklik i rapportteksten markerer et ord. Tredobbeltklik markerer en "
                L"logisk linje. Træk udvider markeringen med ord eller linjer.\r\nÅbn mappe… åbner "
                L"filerne direkte i den valgte mappe, hver på sin egen fane. Undermapper medtages "
                L"ikke.\r\nÅbn og Åbn mappe deler den sidst valgte mappe. Eksport husker sin egen mappe, "
                L"som standard Dokumenter. Avanceret tilstand viser flere felter i rapporten.\r\nKendte "
                L"formater / Kendte codecs / Kendte parametre — MediaInfo.dll.\r\nFuld analyse undersøger "
                L"hele filen og kan tage længere tid. Disse rapportmuligheder og Sporingsniveau hører til "
                L"hver fane; en ændring opdaterer kun den aktive fane. Den sidst manuelt valgte "
                L"kombination gemmes til nye faner og næste start. En matchende cachelagret rapport "
                L"genbruges, så længe filen forbliver uændret.\r\nSporingsniveau: 0 / 5 / 9 / 10.\r\n"
                L"Filer > Sideopsætning… åbner indstillinger for papir, retning og margener for den "
                L"aktuelle session. Udskriv… (Ctrl+P) åbner systemets udskriftsdialog; Windows 11 viser "
                L"en forhåndsvisning, mens Windows 10 og ældre beholder den klassiske dialog. Ctrl+P "
                L"udskriver den aktive fane i hovedvinduet eller tekstfeltet i Hjælp eller Om, alt efter "
                L"hvilket vindue der har fokus. Rapporter bruger den valgte rapportskrifttype, Hjælp "
                L"bruger systemets dialogskrifttype, og Om bruger skrifttypen i sit tekstfelt. Hvis ingen "
                L"faner er åbne, men Hjælp er åben, er Sideopsætning… og Udskriv… stadig tilgængelige; "
                L"Udskriv… udskriver Hjælp. Hjælp bruger hovedvinduets udskriftsdialog; endnu et Ctrl+P i "
                L"Hjælp bringer den frem. Lange linjer ombrydes, og teksten opdeles i sider. Udskrivning "
                L"foregår i baggrunden.\r\nTræk en eller flere filer til vinduet, EXE-ikonet eller dets "
                L"genvej, eller angiv stierne på kommandolinjen. Hvis flere instanser ikke er tilladt, "
                L"åbnes filerne i det vindue, der allerede kører.\r\nVenstre side af statuslinjen viser "
                L"filstier og indlæsningsforløb; højre side viser versionen af den indlæste "
                L"MediaInfo.dll. Lange stier forkortes med udeladelsesprikker, så de passer til den "
                L"tilgængelige plads.\r\n\r\nEKSPORT\r\nTXT, BMP, GIF, JPEG, PNG, TIFF og WebP vises, når "
                L"de er tilgængelige. Seneste eksportmappe og format huskes.\r\nTXT tilbyder ANSI, UTF-8, "
                L"UTF-8 med BOM, UTF-16 BE med BOM og UTF-16 LE med BOM. Den anden mulighed, UTF-8 uden "
                L"BOM, er standard. Hele rapportteksten og dens oprindelige linjeskift bevares.\r\n\r\n"
                L"OPRET EN HEADER-FIL\r\nMenuen Værktøjer er den fjerde på menulinjen. Dens Opret en "
                L"header-fil…-kommando åbner én kildefil uafhængigt af rapportfanerne og kopierer dens "
                L"første 524288 bytes (512 KiB). En kortere fil kopieres i sin helhed; en tom fil "
                L"producerer et tomt output. Dette er almindelig binær fillæsning uden MediaInfo-analyse "
                L"eller et krav om MediaInfo.dll. Værktøjet efterlader rapportfaner og programmets liste "
                L"over seneste filer uændret.\r\n\r\nEfter læsning starter Gem som-dialogen i kildefilens "
                L"mappe og foreslår video.mp4.header for video.mp4: .header føjes til det komplette "
                L"originalnavn. Du kan ændre både navnet og destinationsmappen. Annullering af en af "
                L"dialogboksene skriver ikke noget output. Udskiftning af en eksisterende destination "
                L"kræver bekræftelse. Kilden forbliver uændret; en mislykket lagring bevarer den forrige "
                L"destination. Åbning og lagring bruger de nyeste systemdialogbokse, der er tilgængelige "
                L"i denne version af Windows.\r\n\r\nVed applikationsstart tager værktøjet sin indledende "
                L"inputmappe fra Filer > Åbn. Hvis ingen mappe er blevet gemt, vælger Windows den "
                L"oprindelige placering. Når en inputfil er valgt, husker værktøjet kun sin egen mappe, "
                L"indtil programmet afsluttes, selvom Gem som annulleres. Det ændrer hverken mapperne "
                L"brugt af Åbn og Eksportér eller gemmer sin egen mappe i applikationsindstillingerne. "
                L"Hver Gem som-dialog starter i mappen med den aktuelt valgte inputfil, uanset den "
                L"tidligere gemte destination.\r\n\r\nPRÆFERENCER OG SPROG\r\nPræferencer (Indstillinger "
                L"> Præferencer, Ctrl+G) indeholder biblioteksstier, rapportskrifttype, udjævning og "
                L"sprog. Grænsefladen har 36 varianter og følger først Windows. Rapporter bruger altid "
                L"bibliotekets oprindelige engelsk som standard, uafhængigt af Windows og grænsefladen. "
                L"Kun et manuelt valg ændrer rapportsproget: engelsk, 37 oversættelser eller en egen "
                L"MediaInfo-CSV-tabel. OK eller Anvend bekræfter ændringer; Annuller forkaster ventende "
                L"ændringer. Præferencer angiver grænsen for fanenavne (80 som standard) og rydder listen "
                L"over seneste filer. Lange navne bevarer begyndelsen, slutningen og filtypen med "
                L"udeladelsesprikker i midten. Ryd fjerner listen over seneste filer med det samme, "
                L"selvom præferencerne derefter lukkes med Annuller.\r\n\r\nHovedvinduets titel viser den "
                L"aktive fil som filnavn — MediaInfo. I indstillingerne kan navnets længde i titlen "
                L"indstilles særskilt til 8–255 tegn (40 som standard). Længere navne forkortes med de samme "
                L"udeladelsesprikker i midten, og filtypen bevares. Uden åbne faner er titlen "
                L"MediaInfo.\r\n\r\nBIBLIOTEKER OG VINDUER\r\n"
                L"Programmet indeholder MediaInfo 26.10, 21.03 og 0.7.60, der prøves fra den nyeste "
                L"version efter eksterne biblioteker. De to nyere versioner har passende libcurl; 0.7.60 "
                L"pakker aldrig libcurl ud. Vinduesplaceringen gemmes. Som standard tillades kun én "
                L"instans, og senere starter sender filer til det åbne vindue. Flere instanser kan "
                L"tillades i præferencerne. Ved flere vinduer gendannes den gemte placering kun for det "
                L"første vindue af hver vinduestype; senere vinduer gendanner kun størrelsen.\r\n\r\n"
                L"Rediger > Søg (Ctrl+F) søger i den aktive rapportfane eller i tekstfeltet i Hjælp eller "
                L"Om, alt efter hvilket vindue der har fokus. Søgevinduet beholder den senest valgte "
                L"kilde, mens det selv har fokus. F3 gentager søgningen; Skift+F3 vender retningen. Ved "
                L"tekstens ender fortsætter søgningen fra den modsatte ende. Indstillinger > "
                L"Tekstombrydning gælder kun den aktive fane; markeringen følger den valgte fane. "
                L"Søgevinduet kan minimeres og ændres i bredden; placeringen og indstillingen Altid "
                L"øverst huskes. Op til 30 søgetekster med deres indstillinger gemmes kun, indtil "
                L"programmet lukkes. Indstillingerne for start og slutning gælder logiske linjer. "
                L"Regulære udtryk bruger PCRE2-syntaks. De øvrige kommandoer i menuen Rediger gælder den "
                L"aktive rapportfane. Enter starter søgningen; Skift+Enter vender den valgte retning. "
                L"„Forskel på store og små bogstaver“ skelner mellem store og små bogstaver; „Søg bagud“ "
                L"søger mod tekstens begyndelse. Valg af en historikpost gendanner alle fem "
                L"søgeindstillinger, herunder tilstanden for regulære udtryk; „Altid øverst“ er "
                L"uafhængig. „Regulært udtryk“ deaktiverer „Linjen starter med“ og „Linjen slutter med“. "
                L"Er begge indstillinger for linjens ender slået til, er et match ved én ende nok. "
                L"„Tekstombrydning“ ændrer kun visningen."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"WebP-billedet kan ikke gemmes. Kontrollér destination, ledig hukommelse og diskplads."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Tekstdokument UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Tekstdokument UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Tekstdokument UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Tekstdokument UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Rapporten kan ikke gemmes med denne kodning uden tab af tegn. Vælg en anden tekstkodning."
            },
            { TXT_OPEN_FOLDER, L"Åbn &mappe…" },
            { TXT_OPEN_FOLDER_TITLE, L"Åbn mappe" },
            { TXT_FOLDER_READ_FAILED, L"Mappen kunne ikke læses:\n\n%s\n\nWindows-fejl %lu." },
            { TXT_ADVANCED_MODE, L"&Avanceret tilstand" },
            { TXT_REPORT_DETAIL_REJECTED,
                L"Den valgte MediaInfo.dll afviste indstillingen for rapportdetaljer."
            },
            { TXT_KNOWN_FORMATS, L"Kendte &formater" },
            { TXT_KNOWN_CODECS, L"Kendte &codecs" },
            { TXT_KNOWN_PARAMETERS, L"Kendte &parametre" },
            { TXT_KNOWN_FORMATS_TITLE, L"Kendte formater" },
            { TXT_KNOWN_CODECS_TITLE, L"Kendte codecs" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Kendte parametre" },
            { TXT_KNOWN_INFO_FAILED, L"Biblioteket returnerede ikke de ønskede oplysninger." },
            { TXT_FULL_PARSING, L"&Fuld analyse" },
            { TXT_PARSING_REJECTED, L"Den valgte MediaInfo.dll afviste analyseindstillingen." },
            { TXT_TRACE_LEVEL_0, L"Sporingsniveau &0" },
            { TXT_TRACE_LEVEL_5, L"Sporingsniveau &5" },
            { TXT_TRACE_LEVEL_9, L"Sporingsniveau &9" },
            { TXT_TRACE_LEVEL_10, L"Sporingsniveau &10" },
            { TXT_PAGE_SETUP, L"&Sideopsætning…" },
            { TXT_PAGE_SETUP_FAILED, L"Sideopsætningen kunne ikke åbnes." },
            { TXT_PRINT, L"&Udskriv…\tCtrl+P" },
            { TXT_PRINTING, L"Udskriver…" },
            { TXT_PRINT_FAILED,
                L"Teksten kunne ikke udskrives. Kontroller printeren, dens indstillinger og den "
                L"tilgængelige hukommelse."
            },
            { TXT_TOOLS_MENU, L"&Værktøjer" },
            { TXT_CREATE_HEADER, L"Opret en &header-fil…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Opret en header-fil - Åbn" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Opret en header-fil - Gem som" },
            { TXT_HEADER_FORMAT, L"Headerfil (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Filens header kunne ikke læses:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Headerfilen kunne ikke gemmes:\n\n%s" },
            { TXT_COPY, L"&Kopiér" },
            { TXT_COPY_FILE_NAME, L"Kopiér f&ilnavn" },
            { TXT_COPY_FULL_PATH, L"K&opiér fuld sti" },
            { TXT_LAUNCH_FILE, L"S&tart fil" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"&Vis i mappe" },
            { TXT_EDIT_MENU, L"&Rediger" },
            { TXT_WORD_WRAP, L"&Tekstombrydning" },
            { TXT_WORD_WRAP_FAILED, L"Tekstombrydning kunne ikke ændres." },
            { TXT_COPY_SELECTION, L"&Kopiér\tCtrl+C" },
            { TXT_SELECT_ALL, L"Markér &alt\tCtrl+A" },
            { TXT_FIND_MENU, L"&Søg…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Søg &næste\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Søg &forrige\tSkift+F3" },
            { TXT_FIND_TITLE, L"%s — Søg" },
            { TXT_FIND_WHAT, L"Søg &efter:" },
            { TXT_FIND_NEXT, L"Søg &næste" },
            { TXT_FIND_MATCH_CASE, L"Forskel på store og små &bogstaver" },
            { TXT_FIND_BACKWARD, L"Søg b&agud" },
            { TXT_FIND_TOPMOST, L"Altid &øverst" },
            { TXT_FIND_STARTS_WITH, L"Linjen &starter med" },
            { TXT_FIND_ENDS_WITH, L"Linjen sl&utter med" },
            { TXT_FIND_REGEX, L"&Regulært udtryk" },
            { TXT_FIND_NOT_FOUND, L"Den angivne tekst blev ikke fundet." },
            { TXT_FIND_FAILED, L"Søgningen kunne ikke fuldføres." },
            { TXT_FIND_REGEX_ERROR, L"Fejl i regulært udtryk:\r\n\r\n%s" },
        }
    },
    {
        LANG_FI,
        {
            { TXT_LANGUAGE_NAME, L"Suomi" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nVerkkosivusto: " },
            { TXT_FILE_OPEN_FAILED, L"Tiedostoa %s ei voi avata. Tarkista polku ja käyttöoikeudet." },
            { TXT_BROWSE_DLL, L"&Selaa…" },
            { TXT_BROWSE_REPORT, L"Se&laa…" },
            { TXT_CLOSE, L"&Sulje" },
            { TXT_CLOSE_TAB, L"&Sulje\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"&Oletus" },
            { TXT_EXPORT, L"&Vie…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Tiedosto" },
            { TXT_REPORT_FONT, L"Raportin &fontti:" },
            { TXT_HELP_MENU, L"&Ohje" },
            { TXT_HELP, L"&Ohje\tF1" },
            { TXT_LANGUAGE, L"&Kieli:" },
            { TXT_OPEN_WEBSITE, L"&Avaa oletusselaimessa" },
            { TXT_OPEN, L"&Avaa…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Asetukset" },
            { TXT_PREFERENCES_MENU, L"&Asetukset…\tCtrl+G" },
            { TXT_ABOUT, L"&Tietoja" },
            { TXT_ABOUT_TITLE, L"Tietoja ohjelmasta %ls" },
            { TXT_ALL_FILES, L"Kaikki tiedostot" },
            { TXT_FONT_BOLD, L"Lihavoitu" },
            { TXT_FONT_BOLD_ITALIC, L"Lihavoitu + Kursivoitu" },
            { TXT_BROWSE_CURL, L"S&elaa…" },
            { TXT_CANCEL, L"Peruuta" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"MediaInfo.dll ei lataudu (Windows-virhe %lu). Käytä tämän Windows-version kanssa "
                L"yhteensopivaa 32-bittistä DLL-kirjastoa."
            },
            { TXT_CURL_LOAD_FAILED,
                L"libcurl.dll ei lataudu (Windows-virhe %lu). Valitse tämän Windows-version kanssa "
                L"yhteensopiva 32-bittinen kirjasto."
            },
            { TXT_CLOSE_ALL, L"Sulje &kaikki" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Kopioi &URL" },
            { TXT_COPY_INFORMATION, L"Kopioi &tiedot" },
            { TXT_DLL_FILES, L"Dynaamiset kirjastot" },
            { TXT_EXIT, L"&Lopeta\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Upotetut kirjastot MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Upotetut kirjastot libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Vie raportti" },
            { TXT_FONT_ANTIALIASING, L"Fontin peh&mennys:" },
            { TXT_GIF_EXPORT_FAILED, L"GIF-vienti epäonnistui. Häviötön GIF sallii enintään 256 väriä." },
            { TXT_FONT_ITALIC, L"Kursivoitu" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED, L"JPEG-vienti epäonnistui. Tarvitaan toimiva GDI+-JPEG-kooderi." },
            { TXT_LICENSE_UNAVAILABLE, L"Lisenssiresurssi ei ole käytettävissä." },
            { TXT_MEDIA_FILES, L"Mediatiedostot" },
            { TXT_APPLICATION_DESCRIPTION, L"Mediatietojen katseluohjelma" },
            { TXT_HELP_TITLE, L"MediaInfo — Ohje" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo ei voinut alustaa tiedoston analysointia." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo ei voi avata tai tunnistaa tiedostoa." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"MediaInfo.dll-kirjaston &polku:" },
            { TXT_MEDIALIB_REQUIRED,
                L"MediaInfo.dll ei ole ladattu. Valitse se kohdasta Asetukset > Asetukset."
            },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll ei ole ladattu." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Yhteensopivaa ulkoista tai sisällytettyä MediaInfo.dll-kirjastoa ei voitu ladata. Valitse "
                L"se kohdasta Asetukset > Asetukset."
            },
            { TXT_ANTIALIASING_NONE, L"Ei mitään" },
            { TXT_OK, L"OK" },
            { TXT_OPEN_TITLE, L"Avaa mediatiedostoja" },
            { TXT_PLATFORM, L"Kohdealusta:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Asetukset" },
            { TXT_READY, L"Valmis" },
            { TXT_FONT_REGULAR, L"Normaali" },
            { TXT_REPORT_LANGUAGE, L"&Raportin kieli:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Raporttien kielitaulukot" },
            { TXT_SELECT_MEDIALIB, L"Selaa: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Selaa: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH,
                L"Valitse olemassa oleva mediatiedosto, jonka polku on lyhyempi kuin MAX_PATH."
            },
            { TXT_SELECTED_PATHS_TOO_LONG,
                L"Valitse olemassa olevia tiedostoja, joiden polut ovat lyhyempiä kuin MAX_PATH."
            },
            { TXT_SELECT_CURL, L"Selaa: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Tekstiasiakirja ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"BMP-kuvaa ei voi tallentaa. Tarkista kohde, vapaa muisti ja levytila."
            },
            { TXT_LIBRARY_WORKER_START_FAILED, L"Kirjastoprosessia ei voi käynnistää (Windows-virhe %lu)." },
            { TXT_REPORT_COPY_FAILED, L"MediaInfo-raporttia ei voi kopioida muistiin." },
            { TXT_VIEWER_CREATE_FAILED, L"MediaInfo-katseluohjelmaa ei voi luoda." },
            { TXT_MEDIALIB_PATH_INVALID, L"MediaInfo.dll-polku on virheellinen tai liian pitkä." },
            { TXT_PNG_EXPORT_FAILED,
                L"PNG-kuvaa ei voi tallentaa. Tarkista kohde, vapaa muisti ja levytila."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"TIFF-kuvaa ei voi tallentaa. Tarkista kohde, vapaa muisti ja levytila."
            },
            { TXT_COPY_URL_FAILED, L"URL-osoitetta ei voitu kopioida leikepöydälle." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"Win32-katseluohjelma vaatii 32-bittisen %s-kirjaston. Valitse x86/i386-kirjasto."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Sisällytettyä kirjastoa ei voi kirjoittaa AppDataan, käyttäjäprofiiliin, Program Filesiin "
                L"eikä tilapäiskansioon."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED, L"Kirjaston purkaminen tai CRC-tarkistus epäonnistui." },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Sisällytetyn kirjaston resurssi on virheellinen." },
            { TXT_CURL_FILENAME_INVALID,
                L"Kirjaston nimen on oltava libcurl.dll, jotta MediaInfo voi käyttää sitä."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Tiedostovalintaikkunaa ei voitu avata." },
            { TXT_FILE_DIALOG_SELECTION_FAILED,
                L"Valittuja tiedostoja ei voitu hakea tiedostovalintaikkunasta."
            },
            { TXT_RECENT_FILE_MISSING,
                L"Tiedostoa ”%s” ei enää ole.\n\nPoistetaanko tämä merkintä viimeksi käytettyjen tiedostojen "
                L"luettelosta?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Tiedosto ei ole enää käytettävissä:\n\n%s\n\nPoistetaanko tämä merkintä viimeksi "
                L"käytettyjen tiedostojen luettelosta?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Tietoja ei voitu kopioida leikepöydälle." },
            { TXT_CURL_PATH_INVALID, L"libcurl.dll-polku on virheellinen tai liian pitkä." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Kirjasto ei palauttanut MediaInfo-versiota." },
            { TXT_CURL_EXPORTS_MISSING, L"Kirjasto ei vie MediaInfon tarvitsemia curl-funktioita." },
            { TXT_MEDIALIB_EXPORTS_MISSING, L"Kirjasto ei vie vaadittuja MediaInfon Unicode-funktioita." },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Kirjastoprosessi epäonnistui kohdassa %s (koodi 0x%08lX). Valitse yhteensopiva DLL "
                L"kohdasta Asetukset > Asetukset."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Kirjastoprosessi lakkasi vastaamasta kohdassa %s. Valitse yhteensopiva DLL kohdasta "
                L"Asetukset > Asetukset."
            },
            { TXT_PREFERENCES_SAVE_FAILED,
                L"Asetukset otettiin käyttöön, mutta rekisteriin tallennus epäonnistui."
            },
            { TXT_REPORT_START_FAILED, L"Muisti ei riitä raportin käynnistämiseen." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Raportin kuvaa ei voi luoda." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Kielitaulukkoa ei voi ladata. Valitse kelvollinen UTF-8- "
                L"tai UTF-16-muotoinen MediaInfo-CSV-tiedosto." },
            { TXT_REPORT_THREAD_START_FAILED, L"Raporttisäiettä ei voi käynnistää." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"Valittu MediaInfo.dll hylkäsi raportin kielen." },
            { TXT_INVALID_WINDOWS_DLL, L"Valittu tiedosto ei ole kelvollinen Windows-DLL." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Valittua kuvamuotoa ei tueta." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Tekstiraporttia ei voi tallentaa. Tarkista kohde ja vapaa levytila."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Sivustoa ei voi avata oletusselaimessa." },
            { TXT_TOO_MANY_FILES, L"Valittuja tiedostoja on liikaa. Avaa pienempiä ryhmiä." },
            { TXT_LIBRARY_PATH_HINT,
                L"Käytä tämän Windowsin kanssa yhteensopivia 32-bittisiä DLL-kirjastoja. Tyhjät polut "
                L"ottavat haun käyttöön. MediaInfoLib v0.7.60 ei käytä libcurl.dll-kirjastoa."
            },
            { TXT_VERSION, L"Versio" },
            { TXT_WEBSITE_TOOLTIP, L"Käy verkkosivustolla %s" },
            { TXT_WAITING_FOR_REPORT, L"Odotetaan nykyisen raportin valmistumista." },
            { TXT_WEBSITE_LABEL, L"Verkkosivusto:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"MediaInfo-raportin kopiointi" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"libc&url.dll-kirjaston polku:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"MediaInfo.dll-kirjaston lataaminen" },
            { TXT_CURL_LOAD_OPERATION, L"libcurl.dll-kirjaston lataaminen" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"MediaInfo.dll-kirjaston vapauttaminen" },
            { TXT_APPLY, L"Kä&ytä" },
            { TXT_TAB_NAME_LENGTH, L"Välilehden nimen p&ituus:" },
            { TXT_TITLE_NAME_LENGTH, L"Otsiko&n pituus:" },
            { TXT_RECENT_FILES, L"Viimeisimmät tiedostot:" },
            { TXT_CLEAR_RECENT_FILES, L"&Tyhjennä" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"Välilehden nimen pituuden on oltava 8–255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"Otsikossa olevan nimen pituuden on oltava 8–255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Viimeisimpien tiedostojen luettelo tyhjennettiin, mutta sitä ei voitu tallentaa "
                L"rekisteriin."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"Sul&je välilehdet kaksoisnapsautuksella" },
            { TXT_CLOSE_TAB_CONTEXT, L"Sulje &välilehti" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"S&alli useita esiintymiä" },
            { TXT_INSTANCE_FORWARD_FAILED,
                L"Tiedostoja ei voitu välittää käynnissä olevalle MediaInfo-esiintymälle."
            },
            { TXT_LOADING, L"Ladataan…" },
            { TXT_LOADING_FILE, L"Ladataan tiedostoa %s…" },
            { TXT_APPLICATION_HELP,
                L"TIEDOSTOT JA VÄLILEHDET\r\nNatiivi Windows x86 -katselin MediaInfo.dll-raporteille. "
                L"Jokaisella tiedostolla on oma vain luku -välilehti. Avaa Ctrl+O:lla tai vetämällä "
                L"tiedostot ikkunaan. Uudelleenavaus valitsee olemassa olevan välilehden. Ctrl+W tai "
                L"hiiren keskipainike sulkee välilehden; Sulje kaikki sulkee kaikki. Tiedosto-valikko "
                L"muistaa kahdeksan viimeisintä tiedostoa. Välilehden otsikon pikavalikossa on Sulje "
                L"välilehti. Ota asetuksissa käyttöön Sulje välilehdet kaksoisnapsautuksella, jos haluat "
                L"sulkea välilehden kaksoisnapsauttamalla sen otsikkoa. Asetus on oletuksena pois "
                L"käytöstä, ja se tallennetaan. Kaksoisnapsautus raporttitekstissä valitsee sanan. "
                L"Kolmoisnapsautus valitsee loogisen rivin. Vetäminen laajentaa valintaa sanoittain tai "
                L"riveittäin.\r\nAvaa kansio… avaa valitussa kansiossa suoraan olevat tiedostot kukin "
                L"omalle välilehdelleen. Alikansioita ei sisällytetä.\r\nAvaa ja Avaa kansio käyttävät "
                L"yhteistä viimeksi valittua kansiota. Vienti muistaa erillisen kansion, joka on "
                L"oletuksena Tiedostot. Edistynyt tila näyttää raportissa lisää kenttiä.\r\nTunnetut "
                L"muodot / Tunnetut koodekit / Tunnetut parametrit — MediaInfo.dll.\r\nTäydellinen "
                L"analyysi tutkii koko tiedoston ja voi kestää kauemmin. Nämä raporttivaihtoehdot ja "
                L"Jäljitystaso kuuluvat jokaiseen välilehteen; muutos päivittää vain aktiivisen "
                L"välilehden. Viimeisin manuaalisesti valittu yhdistelmä tallennetaan uusia välilehtiä ja "
                L"seuraavaa käynnistystä varten. Vastaavaa välimuistissa olevaa raporttia käytetään "
                L"uudelleen, kun tiedosto pysyy muuttumattomana.\r\nJäljitystaso: 0 / 5 / 9 / 10.\r\n"
                L"Tiedosto > Sivun asetukset… avaa istunnon paperi-, suunta- ja reunusasetukset. Tulosta… "
                L"(Ctrl+P) avaa järjestelmän tulostusikkunan; Windows 11 näyttää esikatselun, kun taas "
                L"Windows 10 ja vanhemmat käyttävät perinteistä ikkunaa. Ctrl+P tulostaa pääikkunan "
                L"aktiivisen välilehden tai Ohje- tai Tietoja-ikkunan tekstialueen sen mukaan, missä "
                L"ikkunassa kohdistus on. Raportit käyttävät valittua raporttifonttia, Ohje järjestelmän "
                L"valintaikkunafonttia ja Tietoja oman tekstialueensa fonttia. Jos välilehtiä ei ole auki "
                L"mutta Ohje on auki, Sivun asetukset… ja Tulosta… ovat edelleen käytettävissä; Tulosta… "
                L"tulostaa ohjeen. Ohje käyttää pääikkunan tulostusikkunaa; uusi Ctrl+P ohjeessa tuo "
                L"saman ikkunan etualalle. Pitkät rivit rivitetään ja teksti jaetaan sivuille. Tulostus "
                L"tapahtuu taustalla.\r\nVedä yksi tai useampi tiedosto ikkunaan, EXE-kuvakkeen tai sen "
                L"pikakuvakkeen päälle tai anna polut komentorivillä. Jos useita esiintymiä ei sallita, "
                L"tiedostot avataan jo käynnissä olevassa ikkunassa.\r\nTilarivin vasen osa näyttää "
                L"tiedostopolut ja latauksen etenemisen, oikea osa ladatun MediaInfo.dll-kirjaston "
                L"version. Pitkät polut lyhennetään kolmella pisteellä käytettävissä olevan tilan "
                L"mukaan.\r\n\r\nVIENTI\r\nTXT, BMP, GIF, JPEG, PNG, TIFF ja WebP näkyvät saatavuuden "
                L"mukaan. Viimeisin vientikansio ja muoto muistetaan.\r\nTXT tarjoaa muodot ANSI, UTF-8, "
                L"UTF-8 ja BOM, UTF-16 BE ja BOM sekä UTF-16 LE ja BOM. Oletus on toinen vaihtoehto, "
                L"UTF-8 ilman BOM-merkkiä. Koko raporttiteksti ja sen alkuperäiset rivinvaihdot "
                L"säilytetään.\r\n\r\nLUO OTSAKETIEDOSTO\r\nTyökalut on valikkorivin neljäs valikko. Sen "
                L"Luo otsaketiedosto…-komento avaa yhden lähdetiedoston raporttivälilehdistä riippumatta "
                L"ja kopioi sen ensimmäiset 524288 tavua (512 KiB). Lyhyempi tiedosto kopioidaan "
                L"kokonaan; tyhjä tiedosto tuottaa tyhjän tulosteen. Tämä on tavallista "
                L"binaaritiedostojen lukemista ilman MediaInfo-analyysiä tai MediaInfo.dll-vaatimusta. "
                L"Työkalu jättää raporttivälilehdet ja katseluohjelman viimeisimmät tiedostot "
                L"ennalleen.\r\n\r\nLukemisen jälkeen Tallenna nimellä -valintaikkuna avautuu "
                L"lähdetiedoston kansioon ja ehdottaa tiedostolle video.mp4 nimeä video.mp4.header: "
                L".header lisätään koko alkuperäiseen nimeen. Voit muuttaa sekä nimeä että kohdekansiota. "
                L"Kumman tahansa valintaikkunan peruuttaminen ei kirjoita tulostiedostoa. Olemassa olevan "
                L"kohdetiedoston korvaaminen vaatii vahvistuksen. Lähdetiedosto pysyy ennallaan, ja "
                L"epäonnistunut tallennus säilyttää aiemman kohdetiedoston. Avaamiseen ja tallentamiseen "
                L"käytetään uusimpia kyseisessä Windows-versiossa saatavilla olevia järjestelmän "
                L"valintaikkunoita.\r\n\r\nSovelluksen käynnistyessä työkalu ottaa alkuperäisen "
                L"syöttökansionsa osoitteesta Tiedosto > Avaa. Jos yhtään kansiota ei ole tallennettu, "
                L"Windows valitsee alkuperäisen sijainnin. Kun syöttötiedosto on valittu, työkalu muistaa "
                L"oman kansion vain, kunnes sovellus sulkeutuu, vaikka Tallenna nimellä -toiminto "
                L"peruutetaan. Se ei muuta komentojen Avaa ja Vie käyttämiä kansioita eikä tallenna omaa "
                L"kansiotaan sovellusasetuksiin. Jokainen Tallenna nimellä -valintaikkuna alkaa valitun "
                L"syöttötiedoston kansiosta edellisestä tallennuskohteesta riippumatta.\r\n\r\nASETUKSET "
                L"JA KIELET\r\nAsetukset (Asetukset > Asetukset, Ctrl+G) sisältävät kirjastopolut, "
                L"raportin fontin, pehmennyksen ja kielet. Käyttöliittymässä on 36 vaihtoehtoa, ja aluksi "
                L"se seuraa Windowsia. Raportit käyttävät aina oletuksena kirjaston alkuperäistä "
                L"englantia Windowsista ja käyttöliittymästä riippumatta. Kieli vaihtuu vain käsin "
                L"valitsemalla: englanti, 37 käännöstä tai oma MediaInfo-CSV-taulukko. OK tai Käytä "
                L"vahvistaa muutokset; Peruuta hylkää odottavat muutokset. Asetuksissa voi rajoittaa "
                L"välilehtien nimien pituutta (oletus 80 merkkiä) ja tyhjentää viimeisimpien tiedostojen "
                L"luettelon. Pitkissä nimissä säilyvät alku, loppu ja tiedostopääte, ja keskellä on kolme "
                L"pistettä. Tyhjennä poistaa viimeisimpien tiedostojen luettelon heti, vaikka asetukset "
                L"suljettaisiin sen jälkeen Peruuta-painikkeella.\r\n\r\nPääikkunan otsikko näyttää "
                L"aktiivisen tiedoston muodossa tiedostonimi — MediaInfo. Asetuksissa otsikossa olevan nimen "
                L"pituudeksi voi valita erikseen 8–255 merkkiä (oletus 40). Pidemmät nimet lyhennetään "
                L"samalla keskelle lisättävällä kolmella pisteellä, ja tiedostotunniste säilytetään. Kun "
                L"välilehtiä ei ole auki, otsikko on MediaInfo.\r\n\r\nKIRJASTOT JA "
                L"IKKUNAT\r\nOhjelma "
                L"sisältää MediaInfo-versiot 26.10, 21.03 ja 0.7.60, joita kokeillaan uusimmasta "
                L"ulkoisten kirjastojen jälkeen. Kahdella uudemmalla on sopiva libcurl; 0.7.60 ei koskaan "
                L"pura sitä. Ikkunan sijainti tallennetaan. Oletuksena sallitaan vain yksi esiintymä, ja "
                L"myöhemmät käynnistykset lähettävät tiedostot avoimeen ikkunaan. Asetuksissa voi sallia "
                L"useita esiintymiä. Kun ikkunoita on useita, vain kunkin ikkunatyypin ensimmäinen ikkuna "
                L"palauttaa tallennetun sijaintinsa; myöhemmät ikkunat palauttavat vain koon.\r\n\r\n"
                L"Muokkaa > Etsi (Ctrl+F) hakee aktiivisesta raporttivälilehdestä tai Ohje- tai "
                L"Tietoja-ikkunan tekstialueelta sen mukaan, missä ikkunassa kohdistus on. Hakuikkuna "
                L"säilyttää viimeksi valitun lähteen, kun kohdistus on siinä. F3 toistaa haun ja "
                L"Vaihto+F3 vaihtaa hakusuunnan. Tekstin päässä haku jatkuu toisesta päästä. Asetukset > "
                L"Automaattinen rivitys koskee vain aktiivista välilehteä; valintamerkki seuraa valittua "
                L"välilehteä. Hakuikkunan voi pienentää ja sen leveyttä muuttaa; sijainti ja Aina "
                L"päällimmäisenä -asetus muistetaan. Enintään 30 hakutekstiä asetuksineen säilytetään "
                L"vain sovelluksen sulkemiseen asti. Rivin alku- ja loppuehdot koskevat loogisia rivejä. "
                L"Säännölliset lausekkeet käyttävät PCRE2-syntaksia. Muut Muokkaa-valikon komennot "
                L"koskevat aktiivista raporttivälilehteä. Enter käynnistää haun; Vaihto+Enter kääntää "
                L"valitun suunnan. ”Sama kirjainkoko” erottaa isot ja pienet kirjaimet; ”Etsi taaksepäin” "
                L"hakee kohti tekstin alkua. Historiakohteen valinta palauttaa kaikki viisi hakuasetusta, "
                L"myös säännöllisten lausekkeiden tilan; ”Aina päällimmäisenä” on erillinen asetus. "
                L"”Säännöllinen lauseke” poistaa käytöstä asetukset ”Rivi alkaa” ja ”Rivi päättyy”. Kun "
                L"molemmat rivin reunaehdot ovat käytössä, osuma kummassa tahansa reunassa riittää. "
                L"”Automaattinen rivitys” muuttaa vain näyttötapaa."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"WebP-kuvaa ei voi tallentaa. Tarkista kohde, vapaa muisti ja levytila."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Tekstiasiakirja UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Tekstiasiakirja UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Tekstiasiakirja UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Tekstiasiakirja UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Raporttia ei voi tallentaa tällä koodauksella menettämättä merkkejä. Valitse toinen "
                L"tekstikoodaus."
            },
            { TXT_OPEN_FOLDER, L"Avaa ka&nsio…" },
            { TXT_OPEN_FOLDER_TITLE, L"Avaa kansio" },
            { TXT_FOLDER_READ_FAILED, L"Kansiota ei voitu lukea:\n\n%s\n\nWindows-virhe %lu." },
            { TXT_ADVANCED_MODE, L"&Edistynyt tila" },
            { TXT_REPORT_DETAIL_REJECTED,
                L"Valittu MediaInfo.dll hylkäsi raportin yksityiskohtaisuuden asetuksen."
            },
            { TXT_KNOWN_FORMATS, L"Tunnetut &muodot" },
            { TXT_KNOWN_CODECS, L"Tunnetut &koodekit" },
            { TXT_KNOWN_PARAMETERS, L"Tunnetut &parametrit" },
            { TXT_KNOWN_FORMATS_TITLE, L"Tunnetut muodot" },
            { TXT_KNOWN_CODECS_TITLE, L"Tunnetut koodekit" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Tunnetut parametrit" },
            { TXT_KNOWN_INFO_FAILED, L"Kirjasto ei palauttanut pyydettyjä tietoja." },
            { TXT_FULL_PARSING, L"&Täydellinen analyysi" },
            { TXT_PARSING_REJECTED, L"Valittu MediaInfo.dll hylkäsi analyysin asetuksen." },
            { TXT_TRACE_LEVEL_0, L"Jäljitystaso &0" },
            { TXT_TRACE_LEVEL_5, L"Jäljitystaso &5" },
            { TXT_TRACE_LEVEL_9, L"Jäljitystaso &9" },
            { TXT_TRACE_LEVEL_10, L"Jäljitystaso &10" },
            { TXT_PAGE_SETUP, L"Siv&un asetukset…" },
            { TXT_PAGE_SETUP_FAILED, L"Sivun asetuksia ei voitu avata." },
            { TXT_PRINT, L"&Tulosta…\tCtrl+P" },
            { TXT_PRINTING, L"Tulostetaan…" },
            { TXT_PRINT_FAILED,
                L"Tekstiä ei voitu tulostaa. Tarkista tulostin, sen asetukset ja vapaa muisti."
            },
            { TXT_TOOLS_MENU, L"T&yökalut" },
            { TXT_CREATE_HEADER, L"Lu&o otsaketiedosto…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Luo otsaketiedosto - Avaa" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Luo otsaketiedosto - Tallenna nimellä" },
            { TXT_HEADER_FORMAT, L"Otsaketiedosto (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Tiedoston otsaketta ei voitu lukea:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Otsaketiedostoa ei voitu tallentaa:\n\n%s" },
            { TXT_COPY, L"&Kopioi" },
            { TXT_COPY_FILE_NAME, L"Kopioi tiedoston &nimi" },
            { TXT_COPY_FULL_PATH, L"Kopioi koko tiedosto&polku" },
            { TXT_LAUNCH_FILE, L"Kä&ynnistä tiedosto" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"Näytä kans&iossa" },
            { TXT_EDIT_MENU, L"&Muokkaa" },
            { TXT_WORD_WRAP, L"A&utomaattinen rivitys" },
            { TXT_WORD_WRAP_FAILED, L"Automaattista rivitystä ei voitu muuttaa." },
            { TXT_COPY_SELECTION, L"&Kopioi\tCtrl+C" },
            { TXT_SELECT_ALL, L"Valitse k&aikki\tCtrl+A" },
            { TXT_FIND_MENU, L"&Etsi…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Etsi &seuraava\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Etsi e&dellinen\tVaihto+F3" },
            { TXT_FIND_TITLE, L"%s — Etsi" },
            { TXT_FIND_WHAT, L"Etsittävä &teksti:" },
            { TXT_FIND_NEXT, L"&Etsi seuraava" },
            { TXT_FIND_MATCH_CASE, L"Sama kirjain&koko" },
            { TXT_FIND_BACKWARD, L"Etsi t&aaksepäin" },
            { TXT_FIND_TOPMOST, L"Aina &päällimmäisenä" },
            { TXT_FIND_STARTS_WITH, L"Rivi a&lkaa" },
            { TXT_FIND_ENDS_WITH, L"Rivi p&äättyy" },
            { TXT_FIND_REGEX, L"Säänn&öllinen lauseke" },
            { TXT_FIND_NOT_FOUND, L"Määritettyä tekstiä ei löytynyt." },
            { TXT_FIND_FAILED, L"Hakua ei voitu suorittaa loppuun." },
            { TXT_FIND_REGEX_ERROR, L"Virhe säännöllisessä lausekkeessa:\r\n\r\n%s" },
        }
    },
    {
        LANG_IS,
        {
            { TXT_LANGUAGE_NAME, L"Íslenska" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nVefsvæði: " },
            { TXT_FILE_OPEN_FAILED, L"Ekki er hægt að opna %s. Athugaðu slóð og heimildir." },
            { TXT_BROWSE_DLL, L"&Fletta…" },
            { TXT_BROWSE_REPORT, L"Flett&a…" },
            { TXT_CLOSE, L"&Loka" },
            { TXT_CLOSE_TAB, L"&Loka\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"S&jálfgefið" },
            { TXT_EXPORT, L"&Flytja út…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Skrá" },
            { TXT_REPORT_FONT, L"&Letur skýrslu:" },
            { TXT_HELP_MENU, L"&Hjálp" },
            { TXT_HELP, L"&Hjálp\tF1" },
            { TXT_LANGUAGE, L"&Tungumál:" },
            { TXT_OPEN_WEBSITE, L"&Opna í sjálfgefnum vafra" },
            { TXT_OPEN, L"&Opna…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"V&alkostir" },
            { TXT_PREFERENCES_MENU, L"&Kjörstillingar…\tCtrl+G" },
            { TXT_ABOUT, L"&Um" },
            { TXT_ABOUT_TITLE, L"Um %ls" },
            { TXT_ALL_FILES, L"Allar skrár" },
            { TXT_FONT_BOLD, L"Feitletrað" },
            { TXT_FONT_BOLD_ITALIC, L"Feitletrað + Skáletrað" },
            { TXT_BROWSE_CURL, L"Fl&etta…" },
            { TXT_CANCEL, L"Hætta við" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Ekki er hægt að hlaða MediaInfo.dll (Windows-villa %lu). Notaðu 32 bita DLL-safn sem er "
                L"samhæft þessari útgáfu af Windows."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Ekki er hægt að hlaða libcurl.dll (Windows-villa %lu). Veldu 32 bita safn sem er samhæft "
                L"þessari útgáfu af Windows."
            },
            { TXT_CLOSE_ALL, L"Loka &öllu" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Afrita &vefslóð" },
            { TXT_COPY_INFORMATION, L"Afrita &upplýsingar" },
            { TXT_DLL_FILES, L"Kvik söfn" },
            { TXT_EXIT, L"&Hætta\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Innbyggð söfn MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Innbyggð söfn libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Flytja út skýrslu" },
            { TXT_FONT_ANTIALIASING, L"Leturj&öfnun:" },
            { TXT_GIF_EXPORT_FAILED, L"GIF-útflutningur mistókst. Taplaust GIF leyfir mest 256 liti." },
            { TXT_FONT_ITALIC, L"Skáletrað" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED,
                L"JPEG-útflutningur mistókst. Virkur GDI+ JPEG-kóðari er nauðsynlegur."
            },
            { TXT_LICENSE_UNAVAILABLE, L"Leyfisgögnin eru ekki tiltæk." },
            { TXT_MEDIA_FILES, L"Miðlaskrár" },
            { TXT_APPLICATION_DESCRIPTION, L"Skoðari fyrir miðlaupplýsingar" },
            { TXT_HELP_TITLE, L"MediaInfo — Hjálp" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo gat ekki frumstillt greiningu skrárinnar." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo getur ekki opnað eða greint þessa skrá." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"&Slóð að MediaInfo.dll:" },
            { TXT_MEDIALIB_REQUIRED,
                L"MediaInfo.dll er ekki hlaðið. Veldu það í Valkostir > Kjörstillingar."
            },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll er ekki hlaðið." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Ekki tókst að hlaða samhæft ytra eða innbyggt MediaInfo.dll. Veldu það í Valkostir > "
                L"Kjörstillingar."
            },
            { TXT_ANTIALIASING_NONE, L"Engin" },
            { TXT_OK, L"Í lagi" },
            { TXT_OPEN_TITLE, L"Opna miðlaskrár" },
            { TXT_PLATFORM, L"Markvettvangur:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Kjörstillingar" },
            { TXT_READY, L"Tilbúið" },
            { TXT_FONT_REGULAR, L"Venjulegt" },
            { TXT_REPORT_LANGUAGE, L"Tungu&mál skýrslu:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Tungumálatöflur skýrslna" },
            { TXT_SELECT_MEDIALIB, L"Velja: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Velja: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH,
                L"Veldu fyrirliggjandi miðlaskrá með slóð sem er styttri en MAX_PATH."
            },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Veldu fyrirliggjandi skrár með slóðum styttri en MAX_PATH." },
            { TXT_SELECT_CURL, L"Velja: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Textaskjal ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"Ekki er hægt að vista BMP-myndina. Athugaðu áfangastað, laust minni og diskpláss."
            },
            { TXT_LIBRARY_WORKER_START_FAILED, L"Ekki er hægt að ræsa safnferlið (Windows-villa %lu)." },
            { TXT_REPORT_COPY_FAILED, L"Ekki er hægt að afrita MediaInfo-skýrsluna í minni." },
            { TXT_VIEWER_CREATE_FAILED, L"Ekki er hægt að búa til MediaInfo-skoðarann." },
            { TXT_MEDIALIB_PATH_INVALID, L"Slóðin að MediaInfo.dll er ógild eða of löng." },
            { TXT_PNG_EXPORT_FAILED,
                L"Ekki er hægt að vista PNG-myndina. Athugaðu áfangastað, laust minni og diskpláss."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"Ekki er hægt að vista TIFF-myndina. Athugaðu áfangastað, laust minni og diskpláss."
            },
            { TXT_COPY_URL_FAILED, L"Ekki tókst að afrita vefslóðina á klippispjaldið." },
            { TXT_LIBRARY_REQUIRES_X86, L"Win32-skoðarinn krefst 32 bita %s. Veldu x86/i386-safnið." },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Ekki er hægt að skrifa innbyggða safnið í AppData, notandasniðið, Program Files eða "
                L"tímabundnu möppuna."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED, L"Afþjöppun eða CRC-prófun safnsins mistókst." },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Tilfang innbyggða safnsins er ógilt." },
            { TXT_CURL_FILENAME_INVALID,
                L"Safnið verður að heita libcurl.dll svo MediaInfo geti notað það."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Ekki tókst að opna skráargluggann." },
            { TXT_FILE_DIALOG_SELECTION_FAILED, L"Ekki tókst að sækja valdar skrár úr skráarglugganum." },
            { TXT_RECENT_FILE_MISSING,
                L"Skráin „%s“ er ekki lengur til.\n\nViltu fjarlægja þessa færslu af lista nýlegra skráa?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Skráin er ekki lengur tiltæk:\n\n%s\n\nViltu fjarlægja þessa færslu af lista nýlegra "
                L"skráa?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Ekki tókst að afrita upplýsingarnar á klippispjaldið." },
            { TXT_CURL_PATH_INVALID, L"Slóðin að libcurl.dll er ógild eða of löng." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Safnið skilaði ekki MediaInfo-útgáfu." },
            { TXT_CURL_EXPORTS_MISSING, L"Safnið flytur ekki út curl-aðgerðirnar sem MediaInfo þarfnast." },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"Safnið flytur ekki út nauðsynlegar Unicode-aðgerðir MediaInfo."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Safnferlið mistókst við %s (kóði 0x%08lX). Veldu samhæft DLL-safn í Valkostir > "
                L"Kjörstillingar."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Safnferlið hætti að svara við %s. Veldu samhæft DLL-safn í Valkostir > Kjörstillingar."
            },
            { TXT_PREFERENCES_SAVE_FAILED, L"Stillingarnar voru virkjaðar en ekki vistaðar í skrásetningu." },
            { TXT_REPORT_START_FAILED, L"Ekki er nægt minni til að ræsa skýrsluna." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Ekki er hægt að búa til mynd skýrslunnar." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Ekki er hægt að hlaða tungumálatöflunni. Veldu gilda "
                L"MediaInfo CSV-skrá í UTF-8 eða UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"Ekki er hægt að ræsa skýrsluþráðinn." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"Valið MediaInfo.dll hafnaði tungumáli skýrslunnar." },
            { TXT_INVALID_WINDOWS_DLL, L"Valin skrá er ekki gilt Windows DLL-safn." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Valið myndsnið er ekki stutt." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Ekki er hægt að vista textaskýrsluna. Athugaðu áfangastað og laust diskpláss."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Ekki er hægt að opna vefsvæðið í sjálfgefnum vafra." },
            { TXT_TOO_MANY_FILES, L"Of margar skrár voru valdar. Opnaðu smærri hópa." },
            { TXT_LIBRARY_PATH_HINT,
                L"Notaðu 32 bita söfn sem eru samhæf þinni útgáfu af Windows. Hafðu slóðirnar auðar fyrir "
                L"sjálfvirka leit. MediaInfoLib v0.7.60 notar ekki libcurl.dll."
            },
            { TXT_VERSION, L"Útgáfa" },
            { TXT_WEBSITE_TOOLTIP, L"Heimsækja vefsvæði %s" },
            { TXT_WAITING_FOR_REPORT, L"Beðið eftir að núverandi skýrslu ljúki." },
            { TXT_WEBSITE_LABEL, L"Vefsvæði:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"afritun MediaInfo-skýrslunnar" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"Slóð að libc&url.dll:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"hleðslu MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"hleðslu libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"afhleðslu MediaInfo.dll" },
            { TXT_APPLY, L"&Nota" },
            { TXT_TAB_NAME_LENGTH, L"Lengd fli&paheitis:" },
            { TXT_TITLE_NAME_LENGTH, L"Len&gd titils:" },
            { TXT_RECENT_FILES, L"Nýlegar skrár:" },
            { TXT_CLEAR_RECENT_FILES, L"&Hreinsa" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"Lengd flipaheitis verður að vera á bilinu 8 til 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"Lengd nafns í titli verður að vera á bilinu 8 til 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Listinn yfir nýlegar skrár var hreinsaður en ekki var hægt að vista hann í skrásetningunni."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"L&oka flipum með tvísmelli" },
            { TXT_CLOSE_TAB_CONTEXT, L"Loka &flipa" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"Le&yfa mörg tilvik" },
            { TXT_INSTANCE_FORWARD_FAILED,
                L"Ekki tókst að senda skrárnar til MediaInfo-tilviksins sem er í gangi."
            },
            { TXT_LOADING, L"Hleð…" },
            { TXT_LOADING_FILE, L"Hleð skrá %s…" },
            { TXT_APPLICATION_HELP,
                L"SKRÁR OG FLIPAR\r\nWindows x86-skoðari fyrir MediaInfo.dll-skýrslur. Hver skrá hefur "
                L"sinn eigin skrifvarða flipa. Opnaðu skrár með Ctrl+O eða dragðu þær inn. Enduropnun "
                L"velur flipann sem fyrir er. Ctrl+W eða miðjuhnappur músarinnar lokar flipa; Loka öllu "
                L"lokar öllum flipum. Skráarvalmyndin geymir átta nýlegar skrár. Samhengisvalmynd "
                L"flipaheitis inniheldur Loka flipa. Virkjaðu Loka flipum með tvísmelli í Kjörstillingum "
                L"til að loka flipa með því að tvísmella á heiti hans. Valið er sjálfgefið óvirkt og er "
                L"vistað. Tvísmellur í skýrslutexta velur orð. Þrír smellir velja röklega línu. Dráttur "
                L"stækkar valið eftir orðum eða línum.\r\nOpna möppu… opnar skrár sem eru beint í valinni "
                L"möppu, hverja á sínum flipa. Undirmöppur eru ekki teknar með.\r\nOpna og Opna möppu "
                L"nota sömu möppuna og síðast var valin. Útflutningur man sína eigin möppu, sjálfgefið "
                L"Skjöl. Ítarleg stilling sýnir fleiri reiti í skýrslunni.\r\nÞekkt snið / Þekktir "
                L"kóðarar / Þekktir stikar — MediaInfo.dll.\r\nFull greining skoðar alla skrána og getur "
                L"tekið lengri tíma. Þessir skýrsluvalkostir og Rakningarstig tilheyra hverjum flipa; "
                L"breyting endurnýjar aðeins virka flipann. Síðasta handvirkt valin samsetning er vistuð "
                L"fyrir nýja flipa og næstu ræsingu. Samsvarandi skýrsla í skyndiminni er endurnotuð á "
                L"meðan skráin er óbreytt.\r\nRakningarstig: 0 / 5 / 9 / 10.\r\nSkrá > Síðuuppsetning… "
                L"opnar stillingar fyrir pappír, stefnu og spássíur fyrir núverandi keyrslu. Prenta… "
                L"(Ctrl+P) opnar prentglugga kerfisins; Windows 11 sýnir forskoðun en Windows 10 og eldri "
                L"útgáfur nota hefðbundna gluggann. Ctrl+P prentar virka flipann í aðalglugganum eða "
                L"textasvæðið í Hjálp eða Um, eftir því hvaða gluggi hefur fókus. Skýrslur nota valið "
                L"skýrsluletur, Hjálp notar letur kerfisglugga og Um notar letur eigin textasvæðis. Ef "
                L"engir flipar eru opnir en Hjálp er opin eru Síðuuppsetning… og Prenta… áfram tiltæk; "
                L"Prenta… prentar hjálpina. Hjálp notar prentglugga aðalgluggans; Ctrl+P aftur í Hjálp "
                L"færir sama glugga fremst. Langar línur brotna og textanum er skipt á síður. Prentun fer "
                L"fram í bakgrunni.\r\nDragðu eina eða fleiri skrár í gluggann, á EXE-táknið eða "
                L"flýtileið þess, eða gefðu slóðirnar upp á skipanalínunni. Ef mörg tilvik eru ekki leyfð "
                L"opnast skrárnar í glugganum sem er þegar í gangi.\r\nVinstra megin á stöðustikunni "
                L"birtast skráarslóðir og framvinda hleðslu; hægra megin birtist útgáfa þess "
                L"MediaInfo.dll sem er hlaðið. Langar slóðir eru styttar með úrfellingarpunktum eftir því "
                L"plássi sem er tiltækt.\r\n\r\nÚTFLUTNINGUR\r\nTXT, BMP, GIF, JPEG, PNG, TIFF og WebP "
                L"birtast þegar þau eru tiltæk. Síðasta útflutningsmappa og snið eru vistuð.\r\nTXT býður "
                L"ANSI, UTF-8, UTF-8 með BOM, UTF-16 BE með BOM og UTF-16 LE með BOM. Annar valkosturinn, "
                L"UTF-8 án BOM, er sjálfgefinn. Allur texti skýrslunnar og upprunaleg línuskipti "
                L"varðveitast.\r\n\r\nBÚA TIL HAUSASKRÁ\r\nValmyndin Verkfæri er fjórða valmyndin á "
                L"valmyndastikunni. Búa til hausaskrá… skipunin hennar opnar eina frumskrá óháð "
                L"skýrsluflipa og afritar fyrstu 524288 bæti (512 KiB). Styttri skrá er afrituð í heild; "
                L"tóm skrá framleiðir tómt úttak. Þetta er venjulegur lestur tvíundargagna úr skrá, án "
                L"MediaInfo greiningar eða kröfu um MediaInfo.dll. Tólið breytir hvorki skýrsluflipum né "
                L"lista forritsins yfir nýlegar skrár.\r\n\r\nEftir lestur hefst Vista sem valmyndin í "
                L"upprunaskrármöppunni og stingur upp á video.mp4.header fyrir video.mp4: .header er bætt "
                L"við allt upprunalega nafnið. Þú getur breytt bæði nafninu og áfangamöppunni. Ef hætt er "
                L"við annan hvorn gluggann skrifar ekkert úttak. Til að skipta út núverandi áfangastað "
                L"þarf staðfestingu. Upprunaskráin helst óbreytt; misheppnuð vistun varðveitir fyrri "
                L"áfangastað. Við opnun og vistun eru notaðir nýjustu kerfisgluggar sem eru tiltækir í "
                L"viðkomandi útgáfu Windows.\r\n\r\nVið ræsingu forritsins tekur tólið upphaflega "
                L"inntaksmöppuna frá Skrá > Opna. Ef engin mappa hefur verið vistuð velur Windows "
                L"upphafsstaðsetninguna. Eftir að inntaksskrá er valin man tólið aðeins sína eigin möppu "
                L"þar til forritið hættir, jafnvel þó að hætt sé við Vista sem. Það breytir hvorki "
                L"möppunum sem Opna og Flytja út eru notaðar né vistar sína eigin möppu í "
                L"forritastillingunum. Sérhver vista sem gluggi byrjar í möppunni í inntaksskránni sem nú "
                L"er valin, óháð fyrri vistunarstaðnum.\r\n\r\nKJÖRSTILLINGAR OG TUNGUMÁL\r\n"
                L"Kjörstillingar (Valkostir > Kjörstillingar, Ctrl+G) innihalda slóðir safna, letur "
                L"skýrslu, leturjöfnun og tungumál. Viðmótið hefur 36 útgáfur og fylgir Windows í "
                L"upphafi. Skýrslur nota alltaf upprunalega ensku safnsins sjálfgefið, óháð Windows og "
                L"viðmóti. Aðeins handvirkt val breytir því: enska, 37 þýðingar eða eigin MediaInfo "
                L"CSV-tafla. Í lagi eða Nota staðfestir breytingar; Hætta við hendir óstaðfestum "
                L"breytingum. Kjörstillingar leyfa hámarkslengd flipaheita (sjálfgefið 80) og hreinsun "
                L"listans yfir nýlegar skrár. Löng heiti halda upphafi, enda og skráarendingu með "
                L"úrfellingarmerki í miðju. Hreinsa fjarlægir listann yfir nýlegar skrár strax, jafnvel "
                L"þótt kjörstillingunum sé síðan lokað með Hætta við.\r\n\r\nTitill aðalgluggans sýnir virku "
                L"skrána á forminu skráarheiti — MediaInfo. Í kjörstillingum má stilla lengd nafns í titli "
                L"sérstaklega á 8–255 stafi (sjálfgefið 40). Lengri nöfn eru stytt með sömu "
                L"úrfellingarpunktum í miðjunni og skráarendingin helst. Þegar engir flipar eru opnir er "
                L"titillinn MediaInfo.\r\n\r\nSÖFN OG GLUGGAR\r\nForritið "
                L"inniheldur MediaInfo 26.10, 21.03 og 0.7.60, prófuð frá nýjustu útgáfu á eftir ytri "
                L"söfnum. Nýrri útgáfurnar tvær hafa viðeigandi libcurl; 0.7.60 afþjappar því aldrei. "
                L"Staðsetning gluggans er vistuð. Sjálfgefið er aðeins eitt tilvik leyft og síðari "
                L"ræsingar senda skrár til opna gluggans. Í stillingum má leyfa mörg tilvik. Ef fleiri "
                L"gluggar eru leyfðir endurheimtir aðeins fyrsti gluggi hverrar gluggategundar vistaða "
                L"staðsetningu; síðari gluggar endurheimta aðeins stærðina.\r\n\r\nBreyta > Finna "
                L"(Ctrl+F) leitar í virka skýrsluflipanum eða textasvæðinu í Hjálp eða Um, eftir því "
                L"hvaða gluggi hefur fókus. Leitarglugginn heldur síðast valda upprunanum meðan hann "
                L"hefur fókus. F3 endurtekur leitina og Shift+F3 snýr leitarstefnunni við. Við enda "
                L"textans heldur leitin áfram frá hinum endanum. Valkostir > Línuskipting gildir aðeins "
                L"fyrir virkan flipa; gátmerkið fylgir völdum flipa. Hægt er að lágmarka leitargluggann "
                L"og breyta breidd hans; staðsetning og stillingin Alltaf efst eru vistaðar. Allt að 30 "
                L"leitartextar og stillingar þeirra eru aðeins geymd þar til forritinu er lokað. Upphafs- "
                L"og endaskilyrði eiga við röklegar línur. Reglulegar segðir nota PCRE2-málskipan. Aðrar "
                L"skipanir í valmyndinni Breyta eiga við virka skýrsluflipann. Enter ræsir leit; "
                L"Shift+Enter snýr valinni stefnu við. „Greina á milli há- og lágstafa“ greinir á milli "
                L"há- og lágstafa; „Leita afturábak“ leitar að upphafi textans. Val á færslu úr "
                L"leitarsögunni endurheimtir alla fimm leitarvalkostina, þar á meðal stillingu reglulegra "
                L"segða; „Alltaf efst“ er óháður valkostur. „Regluleg segð“ gerir „Lína byrjar á“ og "
                L"„Lína endar á“ óvirka. Ef báðir valkostir fyrir enda línu eru virkir nægir samsvörun "
                L"við annan endann. „Línuskipting“ breytir aðeins birtingunni."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"Ekki er hægt að vista WebP-myndina. Athugaðu áfangastað, laust minni og diskpláss."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Textaskjal UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Textaskjal UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Textaskjal UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Textaskjal UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Ekki er hægt að vista skýrsluna með þessari stafakóðun án þess að tapa stöfum. Veldu aðra "
                L"stafakóðun."
            },
            { TXT_OPEN_FOLDER, L"Opna &möppu…" },
            { TXT_OPEN_FOLDER_TITLE, L"Opna möppu" },
            { TXT_FOLDER_READ_FAILED, L"Ekki tókst að lesa möppuna:\n\n%s\n\nWindows-villa %lu." },
            { TXT_ADVANCED_MODE, L"&Ítarleg stilling" },
            { TXT_REPORT_DETAIL_REJECTED,
                L"Valið MediaInfo.dll hafnaði stillingu fyrir ítarleika skýrslunnar."
            },
            { TXT_KNOWN_FORMATS, L"Þekkt &snið" },
            { TXT_KNOWN_CODECS, L"Þekktir &kóðarar" },
            { TXT_KNOWN_PARAMETERS, L"Þekktir s&tikar" },
            { TXT_KNOWN_FORMATS_TITLE, L"Þekkt snið" },
            { TXT_KNOWN_CODECS_TITLE, L"Þekktir kóðarar" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Þekktir stikar" },
            { TXT_KNOWN_INFO_FAILED, L"Safnið skilaði ekki umbeðnum upplýsingum." },
            { TXT_FULL_PARSING, L"&Full greining" },
            { TXT_PARSING_REJECTED, L"Valið MediaInfo.dll hafnaði greiningarstillingunni." },
            { TXT_TRACE_LEVEL_0, L"Rakningarstig &0" },
            { TXT_TRACE_LEVEL_5, L"Rakningarstig &5" },
            { TXT_TRACE_LEVEL_9, L"Rakningarstig &9" },
            { TXT_TRACE_LEVEL_10, L"Rakningarstig &10" },
            { TXT_PAGE_SETUP, L"&Síðuuppsetning…" },
            { TXT_PAGE_SETUP_FAILED, L"Ekki tókst að opna síðuuppsetningu." },
            { TXT_PRINT, L"&Prenta…\tCtrl+P" },
            { TXT_PRINTING, L"Prentar…" },
            { TXT_PRINT_FAILED,
                L"Ekki tókst að prenta textann. Athugaðu prentarann, stillingar hans og laust minni."
            },
            { TXT_TOOLS_MENU, L"&Verkfæri" },
            { TXT_CREATE_HEADER, L"Búa til &hausaskrá…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Búa til hausaskrá - Opna" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Búa til hausaskrá - Vista sem" },
            { TXT_HEADER_FORMAT, L"Hausaskrá (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Ekki tókst að lesa haus skrárinnar:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Ekki tókst að vista hausaskrána:\n\n%s" },
            { TXT_COPY, L"&Afrita" },
            { TXT_COPY_FILE_NAME, L"Afr&ita skráarheiti" },
            { TXT_COPY_FULL_PATH, L"Afrita alla &slóðina" },
            { TXT_LAUNCH_FILE, L"&Ræsa skrá" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"Sý&na í möppu" },
            { TXT_EDIT_MENU, L"&Breyta" },
            { TXT_WORD_WRAP, L"&Línuskipting" },
            { TXT_WORD_WRAP_FAILED, L"Ekki tókst að breyta línuskiptingu." },
            { TXT_COPY_SELECTION, L"&Afrita\tCtrl+C" },
            { TXT_SELECT_ALL, L"Velja a&llt\tCtrl+A" },
            { TXT_FIND_MENU, L"&Finna…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Finna &næsta\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Finna f&yrra\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Finna" },
            { TXT_FIND_WHAT, L"Leit&a að:" },
            { TXT_FIND_NEXT, L"Finna &næsta" },
            { TXT_FIND_MATCH_CASE, L"Greina á milli há- og lág&stafa" },
            { TXT_FIND_BACKWARD, L"Leita a&fturábak" },
            { TXT_FIND_TOPMOST, L"Alltaf &efst" },
            { TXT_FIND_STARTS_WITH, L"Lína &byrjar á" },
            { TXT_FIND_ENDS_WITH, L"Lína en&dar á" },
            { TXT_FIND_REGEX, L"&Regluleg segð" },
            { TXT_FIND_NOT_FOUND, L"Tilgreindur texti fannst ekki." },
            { TXT_FIND_FAILED, L"Ekki tókst að ljúka leitinni." },
            { TXT_FIND_REGEX_ERROR, L"Villa í reglulegri segð:\r\n\r\n%s" },
        }
    },
    {
        LANG_NB,
        {
            { TXT_LANGUAGE_NAME, L"Norsk (bokmål)" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nNettsted: " },
            { TXT_FILE_OPEN_FAILED, L"Kan ikke åpne %s. Kontroller bane og tillatelser." },
            { TXT_BROWSE_DLL, L"Bla &gjennom…" },
            { TXT_BROWSE_REPORT, L"Bla g&jennom…" },
            { TXT_CLOSE, L"&Lukk" },
            { TXT_CLOSE_TAB, L"&Lukk\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"Stan&dard" },
            { TXT_EXPORT, L"&Eksporter…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Fil" },
            { TXT_REPORT_FONT, L"Rapports&krifttype:" },
            { TXT_HELP_MENU, L"&Hjelp" },
            { TXT_HELP, L"&Hjelp\tF1" },
            { TXT_LANGUAGE, L"S&pråk:" },
            { TXT_OPEN_WEBSITE, L"&Åpne i standardnettleseren" },
            { TXT_OPEN, L"&Åpne…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Alternativer" },
            { TXT_PREFERENCES_MENU, L"&Preferanser…\tCtrl+G" },
            { TXT_ABOUT, L"&Om" },
            { TXT_ABOUT_TITLE, L"Om %ls" },
            { TXT_ALL_FILES, L"Alle filer" },
            { TXT_FONT_BOLD, L"Fet" },
            { TXT_FONT_BOLD_ITALIC, L"Fet + Kursiv" },
            { TXT_BROWSE_CURL, L"B&la gjennom…" },
            { TXT_CANCEL, L"Avbryt" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Kan ikke laste MediaInfo.dll (Windows-feil %lu). Bruk en 32-biters DLL som er kompatibel "
                L"med denne Windows-versjonen."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Kan ikke laste libcurl.dll (Windows-feil %lu). Velg et 32-biters bibliotek som er "
                L"kompatibelt med denne Windows-versjonen."
            },
            { TXT_CLOSE_ALL, L"Lukk &alle" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Kopier &URL" },
            { TXT_COPY_INFORMATION, L"Kopier &informasjon" },
            { TXT_DLL_FILES, L"Dynamiske biblioteker" },
            { TXT_EXIT, L"A&vslutt\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Innebygde biblioteker MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Innebygde biblioteker libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Eksporter rapport" },
            { TXT_FONT_ANTIALIASING, L"Skriftu&tjevning:" },
            { TXT_GIF_EXPORT_FAILED, L"GIF-eksport mislyktes. Tapsfri GIF krever høyst 256 farger." },
            { TXT_FONT_ITALIC, L"Kursiv" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED, L"JPEG-eksport mislyktes. En fungerende GDI+-JPEG-koder kreves." },
            { TXT_LICENSE_UNAVAILABLE, L"Lisensressursen er utilgjengelig." },
            { TXT_MEDIA_FILES, L"Mediefiler" },
            { TXT_APPLICATION_DESCRIPTION, L"Viser for medieinformasjon" },
            { TXT_HELP_TITLE, L"MediaInfo — Hjelp" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo kunne ikke initialisere filanalysen." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo kan ikke åpne eller gjenkjenne denne filen." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"&Sti til MediaInfo.dll:" },
            { TXT_MEDIALIB_REQUIRED,
                L"MediaInfo.dll er ikke lastet. Velg den under Alternativer > Preferanser."
            },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll er ikke lastet." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Ingen kompatibel ekstern eller innebygd MediaInfo.dll kunne lastes. Velg den under "
                L"Alternativer > Preferanser."
            },
            { TXT_ANTIALIASING_NONE, L"Ingen" },
            { TXT_OK, L"OK" },
            { TXT_OPEN_TITLE, L"Åpne mediefiler" },
            { TXT_PLATFORM, L"Målplattform:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Preferanser" },
            { TXT_READY, L"Klar" },
            { TXT_FONT_REGULAR, L"Vanlig" },
            { TXT_REPORT_LANGUAGE, L"&Rapportspråk:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Rapportspråktabeller" },
            { TXT_SELECT_MEDIALIB, L"Bla gjennom: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Bla gjennom: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH,
                L"Velg en eksisterende mediefil med en bane som er kortere enn MAX_PATH."
            },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Velg eksisterende filer med baner kortere enn MAX_PATH." },
            { TXT_SELECT_CURL, L"Bla gjennom: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Tekstdokument ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"BMP-bildet kan ikke lagres. Kontroller mål, ledig minne og diskplass."
            },
            { TXT_LIBRARY_WORKER_START_FAILED, L"Bibliotekprosessen kan ikke startes (Windows-feil %lu)." },
            { TXT_REPORT_COPY_FAILED, L"MediaInfo-rapporten kan ikke kopieres til minnet." },
            { TXT_VIEWER_CREATE_FAILED, L"MediaInfo-viseren kan ikke opprettes." },
            { TXT_MEDIALIB_PATH_INVALID, L"Banen til MediaInfo.dll er ugyldig eller for lang." },
            { TXT_PNG_EXPORT_FAILED,
                L"PNG-bildet kan ikke lagres. Kontroller mål, ledig minne og diskplass."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"TIFF-bildet kan ikke lagres. Kontroller mål, ledig minne og diskplass."
            },
            { TXT_COPY_URL_FAILED, L"URL-adressen kunne ikke kopieres til utklippstavlen." },
            { TXT_LIBRARY_REQUIRES_X86, L"Win32-viseren krever en 32-biters %s. Velg x86/i386-biblioteket." },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Det innebygde biblioteket kan ikke skrives til AppData, brukerprofilen, Program Files "
                L"eller den midlertidige mappen."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED, L"Bibliotekets utpakking eller CRC-kontroll mislyktes." },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Ressursen for det innebygde biblioteket er ugyldig." },
            { TXT_CURL_FILENAME_INVALID,
                L"Biblioteket må hete libcurl.dll for at MediaInfo skal kunne bruke det."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Fildialogen kunne ikke åpnes." },
            { TXT_FILE_DIALOG_SELECTION_FAILED, L"De valgte filene kunne ikke hentes fra fildialogen." },
            { TXT_RECENT_FILE_MISSING,
                L"Filen «%s» finnes ikke lenger.\n\nVil du fjerne denne oppføringen fra listen over nylige "
                L"filer?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Filen er ikke lenger tilgjengelig:\n\n%s\n\nVil du fjerne denne oppføringen fra listen "
                L"over nylige filer?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Informasjonen kunne ikke kopieres til utklippstavlen." },
            { TXT_CURL_PATH_INVALID, L"Banen til libcurl.dll er ugyldig eller for lang." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Biblioteket returnerte ingen MediaInfo-versjon." },
            { TXT_CURL_EXPORTS_MISSING,
                L"Biblioteket eksporterer ikke curl-funksjonene som MediaInfo krever."
            },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"Biblioteket eksporterer ikke de nødvendige Unicode-funksjonene for MediaInfo."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Bibliotekprosessen feilet under %s (kode 0x%08lX). Velg en kompatibel DLL under "
                L"Alternativer > Preferanser."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Bibliotekprosessen sluttet å svare under %s. Velg en kompatibel DLL under Alternativer > "
                L"Preferanser."
            },
            { TXT_PREFERENCES_SAVE_FAILED, L"Innstillingene ble brukt, men kunne ikke lagres i registeret." },
            { TXT_REPORT_START_FAILED, L"Ikke nok minne til å starte rapporten." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Rapportbildet kan ikke opprettes." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Språktabellen kan ikke lastes. Velg en gyldig "
                L"MediaInfo-CSV-fil i UTF-8 eller UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"Rapporttråden kan ikke startes." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"Den valgte MediaInfo.dll avviste rapportspråket." },
            { TXT_INVALID_WINDOWS_DLL, L"Den valgte filen er ikke en gyldig Windows-DLL." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Det valgte bildeformatet støttes ikke." },
            { TXT_TEXT_EXPORT_FAILED, L"Tekstrapporten kan ikke lagres. Kontroller mål og ledig diskplass." },
            { TXT_WEBSITE_OPEN_FAILED, L"Nettstedet kan ikke åpnes i standardnettleseren." },
            { TXT_TOO_MANY_FILES, L"For mange filer er valgt. Åpne mindre grupper." },
            { TXT_LIBRARY_PATH_HINT,
                L"Bruk 32-biters biblioteker som er kompatible med Windows-versjonen din. La banene være "
                L"tomme for automatisk søk. MediaInfoLib v0.7.60 bruker ikke libcurl.dll."
            },
            { TXT_VERSION, L"Versjon" },
            { TXT_WEBSITE_TOOLTIP, L"Besøk nettstedet %s" },
            { TXT_WAITING_FOR_REPORT, L"Venter på at den gjeldende rapporten skal fullføres." },
            { TXT_WEBSITE_LABEL, L"Nettsted:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"kopiering av MediaInfo-rapporten" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"Sti til libc&url.dll:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"lasting av MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"lasting av libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"frigjøring av MediaInfo.dll" },
            { TXT_APPLY, L"&Bruk" },
            { TXT_TAB_NAME_LENGTH, L"Lengde på &fanenavn:" },
            { TXT_TITLE_NAME_LENGTH, L"Titt&ellengde:" },
            { TXT_RECENT_FILES, L"Nylige filer:" },
            { TXT_CLEAR_RECENT_FILES, L"Tø&m" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"Fanenavnets lengde må være mellom 8 og 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"Navnets lengde i tittelen må være mellom 8 og 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Listen over nylige filer ble tømt, men kunne ikke lagres i registeret."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"Lukk f&aner med dobbeltklikk" },
            { TXT_CLOSE_TAB_CONTEXT, L"Lukk &fane" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"T&illat flere forekomster" },
            { TXT_INSTANCE_FORWARD_FAILED,
                L"Filene kunne ikke sendes til den kjørende MediaInfo-forekomsten."
            },
            { TXT_LOADING, L"Laster…" },
            { TXT_LOADING_FILE, L"Laster filen %s…" },
            { TXT_APPLICATION_HELP,
                L"FILER OG FANER\r\nWindows x86-viser for MediaInfo.dll-rapporter. Hver fil har sin egen "
                L"skrivebeskyttede fane. Åpne med Ctrl+O eller dra og slipp. Ny åpning velger den "
                L"eksisterende fanen. Ctrl+W eller den midterste museknappen lukker en fane; Lukk alle "
                L"lukker samtlige faner. Fil-menyen husker de åtte sist brukte filene. Kontekstmenyen til "
                L"en faneoverskrift inneholder Lukk fane. Slå på Lukk faner med dobbeltklikk i "
                L"Preferanser for å lukke en fane ved å dobbeltklikke på overskriften. Valget er som "
                L"standard av og lagres. Dobbeltklikk i rapportteksten velger et ord. Trippelklikk velger "
                L"en logisk linje. Dra for å utvide utvalget med ord eller linjer.\r\nÅpne mappe… åpner "
                L"filene direkte i den valgte mappen, hver i sin egen fane. Undermapper tas ikke med.\r\n"
                L"Åpne og Åpne mappe deler den sist valgte mappen. Eksport husker sin egen mappe, som "
                L"standard Dokumenter. Avansert modus viser flere felt i rapporten.\r\nKjente formater / "
                L"Kjente kodeker / Kjente parametere — MediaInfo.dll.\r\nFull analyse undersøker hele "
                L"filen og kan ta lengre tid. Disse rapportalternativene og Sporingsnivå tilhører hver "
                L"fane; en endring oppdaterer bare den aktive fanen. Den siste manuelt valgte "
                L"kombinasjonen lagres for nye faner og neste oppstart. En samsvarende bufret rapport "
                L"gjenbrukes så lenge filen forblir uendret.\r\nSporingsnivå: 0 / 5 / 9 / 10.\r\nFil > "
                L"Utskriftsformat… åpner innstillinger for papir, retning og marger for denne økten. "
                L"Skriv ut… (Ctrl+P) åpner systemets utskriftsdialog; Windows 11 viser en "
                L"forhåndsvisning, mens Windows 10 og eldre beholder den klassiske dialogen. Ctrl+P "
                L"skriver ut den aktive fanen i hovedvinduet eller tekstfeltet i Hjelp eller Om, avhengig "
                L"av hvilket vindu som har fokus. Rapporter bruker den valgte rapportskriften, Hjelp "
                L"bruker systemets dialogskrift, og Om bruker skriften i sitt tekstfelt. Hvis ingen faner "
                L"er åpne, men Hjelp er åpen, er Utskriftsformat… og Skriv ut… fortsatt tilgjengelige; "
                L"Skriv ut… skriver ut Hjelp. Hjelp bruker hovedvinduets utskriftsdialog; Ctrl+P på nytt "
                L"i Hjelp henter den samme dialogen frem. Lange linjer brytes og teksten deles i sider. "
                L"Utskrift foregår i bakgrunnen.\r\nDra én eller flere filer til vinduet, EXE-ikonet "
                L"eller snarveien, eller oppgi banene på kommandolinjen. Hvis flere forekomster ikke er "
                L"tillatt, åpnes filene i vinduet som allerede kjører.\r\nVenstre side av statuslinjen "
                L"viser filbaner og innlastingsfremdrift; høyre side viser versjonen av den innlastede "
                L"MediaInfo.dll. Lange baner forkortes med utelatelsesprikker etter tilgjengelig "
                L"plass.\r\n\r\nEKSPORT\r\nTXT, BMP, GIF, JPEG, PNG, TIFF og WebP vises når de er "
                L"tilgjengelige. Siste eksportmappe og format huskes.\r\nTXT tilbyr ANSI, UTF-8, UTF-8 "
                L"med BOM, UTF-16 BE med BOM og UTF-16 LE med BOM. Det andre alternativet, UTF-8 uten "
                L"BOM, er standard. Hele rapportteksten og de opprinnelige linjeskiftene bevares.\r\n\r\n"
                L"OPPRETT EN HEADERFIL\r\nMenyen Verktøy er den fjerde på menylinjen. Dens Opprett en "
                L"headerfil…-kommando åpner én kildefil uavhengig av rapportfanene og kopierer de første "
                L"524288 byte (512 KiB). En kortere fil kopieres i sin helhet; en tom fil produserer en "
                L"tom utdatafil. Dette er vanlig binær fillesing, uten MediaInfo-analyse eller krav om "
                L"MediaInfo.dll. Verktøyet lar rapportfaner og programmets liste over siste filer være "
                L"uendret.\r\n\r\nEtter lesing starter dialogboksen Lagre som i kildefilens mappe og "
                L"foreslår video.mp4.header for video.mp4: .header legges til hele originalnavnet. Du kan "
                L"endre både navnet og målmappen. Hvis du avbryter en av dialogboksene, skrives ingen "
                L"utdata. Å erstatte en eksisterende destinasjon krever bekreftelse. Kilden forblir "
                L"uendret; en mislykket lagring bevarer den forrige destinasjonen. Åpning og lagring "
                L"bruker de nyeste systemdialogboksene som er tilgjengelige i denne "
                L"Windows-versjonen.\r\n\r\nVed oppstart av applikasjonen henter verktøyet den første "
                L"inndatamappen fra Fil > Åpne. Hvis ingen mappe er lagret, velger Windows den "
                L"opprinnelige plasseringen. Etter at en inndatafil er valgt, husker verktøyet sin egen "
                L"mappe bare til programmet avsluttes, selv om Lagre som avbrytes. Det endrer verken "
                L"mappene som brukes av Åpne og Eksporter eller lagrer sin egen mappe i "
                L"applikasjonsinnstillingene. Hver Lagre som-dialog starter i mappen til den valgte "
                L"inndatafilen, uavhengig av forrige lagringsmål.\r\n\r\nPREFERANSER OG SPRÅK\r\n"
                L"Preferanser (Alternativer > Preferanser, Ctrl+G) inneholder bibliotekstier, "
                L"rapportskrift, utjevning og språk. Grensesnittet har 36 varianter og følger først "
                L"Windows. Rapporter bruker alltid bibliotekets opprinnelige engelsk som standard, "
                L"uavhengig av Windows og grensesnittet. Bare et manuelt valg endrer rapportspråket: "
                L"engelsk, 37 oversettelser eller en egen MediaInfo-CSV-tabell. OK eller Bruk bekrefter "
                L"endringer; Avbryt forkaster ventende endringer. Preferanser angir grensen for fanenavn "
                L"(80 som standard) og tømmer listen over nylige filer. Lange navn beholder begynnelsen, "
                L"slutten og filtypen med utelatelsesprikker i midten. Tøm fjerner listen over nylige "
                L"filer med en gang, selv om preferansene deretter lukkes med Avbryt.\r\n\r\nHovedvinduets "
                L"tittel viser den aktive filen som filnavn — MediaInfo. I innstillingene kan navnets lengde "
                L"i tittelen angis separat til 8–255 tegn (40 som standard). Lengre navn forkortes med de "
                L"samme utelatelsesprikkene i midten, og filtypen beholdes. Uten åpne faner er tittelen "
                L"MediaInfo.\r\n\r\nBIBLIOTEKER "
                L"OG VINDUER\r\nProgrammet inneholder MediaInfo 26.10, 21.03 og 0.7.60, som prøves fra "
                L"den nyeste versjonen etter eksterne biblioteker. De to nyere versjonene har passende "
                L"libcurl; 0.7.60 pakker aldri ut libcurl. Vindusplasseringen lagres. Som standard "
                L"tillates bare én forekomst, og senere oppstarter sender filer til det åpne vinduet. "
                L"Flere forekomster kan tillates i preferansene. Ved flere vinduer gjenopprettes lagret "
                L"plassering bare for det første vinduet av hver vindustype; senere vinduer gjenoppretter "
                L"bare størrelsen.\r\n\r\nRediger > Søk (Ctrl+F) søker i den aktive rapportfanen eller "
                L"tekstfeltet i Hjelp eller Om, avhengig av hvilket vindu som har fokus. Søkevinduet "
                L"beholder den sist valgte kilden mens det selv har fokus. F3 gjentar søket; Skift+F3 "
                L"snur retningen. Ved tekstens ender fortsetter søket fra motsatt ende. Alternativer > "
                L"Tekstbryting gjelder bare den aktive fanen; haken følger den valgte fanen. Søkevinduet "
                L"kan minimeres og endres i bredden; plasseringen og innstillingen Alltid øverst huskes. "
                L"Opptil 30 søketekster med innstillingene deres beholdes bare til programmet avsluttes. "
                L"Valgene for begynnelse og slutt gjelder logiske linjer. Regulære uttrykk bruker "
                L"PCRE2-syntaks. De øvrige kommandoene i Rediger-menyen gjelder den aktive rapportfanen. "
                L"Enter starter søket; Skift+Enter snur den valgte retningen. «Skill mellom store og små "
                L"bokstaver» skiller mellom store og små bokstaver; «Søk bakover» søker mot begynnelsen "
                L"av teksten. Valg av en historikkoppføring gjenoppretter alle fem søkevalg, inkludert "
                L"innstillingen for regulære uttrykk; «Alltid øverst» er uavhengig. «Regulært uttrykk» "
                L"deaktiverer «Linjen starter med» og «Linjen slutter med». Når begge valgene for linjens "
                L"ender er aktivert, holder det med et treff ved én ende. «Tekstbryting» endrer bare "
                L"visningen."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"WebP-bildet kan ikke lagres. Kontroller mål, ledig minne og diskplass."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Tekstdokument UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Tekstdokument UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Tekstdokument UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Tekstdokument UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Rapporten kan ikke lagres med denne kodingen uten tap av tegn. Velg en annen tekstkoding."
            },
            { TXT_OPEN_FOLDER, L"Åpne &mappe…" },
            { TXT_OPEN_FOLDER_TITLE, L"Åpne mappe" },
            { TXT_FOLDER_READ_FAILED, L"Mappen kunne ikke leses:\n\n%s\n\nWindows-feil %lu." },
            { TXT_ADVANCED_MODE, L"&Avansert modus" },
            { TXT_REPORT_DETAIL_REJECTED,
                L"Den valgte MediaInfo.dll avviste innstillingen for rapportdetaljer."
            },
            { TXT_KNOWN_FORMATS, L"Kjente &formater" },
            { TXT_KNOWN_CODECS, L"Kjente &kodeker" },
            { TXT_KNOWN_PARAMETERS, L"Kjente &parametere" },
            { TXT_KNOWN_FORMATS_TITLE, L"Kjente formater" },
            { TXT_KNOWN_CODECS_TITLE, L"Kjente kodeker" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Kjente parametere" },
            { TXT_KNOWN_INFO_FAILED, L"Biblioteket returnerte ikke de forespurte opplysningene." },
            { TXT_FULL_PARSING, L"&Full analyse" },
            { TXT_PARSING_REJECTED, L"Den valgte MediaInfo.dll avviste analyseinnstillingen." },
            { TXT_TRACE_LEVEL_0, L"Sporingsnivå &0" },
            { TXT_TRACE_LEVEL_5, L"Sporingsnivå &5" },
            { TXT_TRACE_LEVEL_9, L"Sporingsnivå &9" },
            { TXT_TRACE_LEVEL_10, L"Sporingsnivå &10" },
            { TXT_PAGE_SETUP, L"&Utskriftsformat…" },
            { TXT_PAGE_SETUP_FAILED, L"Utskriftsformatet kunne ikke åpnes." },
            { TXT_PRINT, L"&Skriv ut…\tCtrl+P" },
            { TXT_PRINTING, L"Skriver ut…" },
            { TXT_PRINT_FAILED,
                L"Teksten kunne ikke skrives ut. Kontroller skriveren, innstillingene og tilgjengelig "
                L"minne."
            },
            { TXT_TOOLS_MENU, L"&Verktøy" },
            { TXT_CREATE_HEADER, L"Opprett en &headerfil…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Opprett en headerfil - Åpne" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Opprett en headerfil - Lagre som" },
            { TXT_HEADER_FORMAT, L"Headerfil (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Filhodet kunne ikke leses:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Headerfilen kunne ikke lagres:\n\n%s" },
            { TXT_COPY, L"&Kopier" },
            { TXT_COPY_FILE_NAME, L"Kopier fi&lnavn" },
            { TXT_COPY_FULL_PATH, L"Kopier fullstendig fil&bane" },
            { TXT_LAUNCH_FILE, L"S&tart fil" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"V&is i mappe" },
            { TXT_EDIT_MENU, L"&Rediger" },
            { TXT_WORD_WRAP, L"&Tekstbryting" },
            { TXT_WORD_WRAP_FAILED, L"Tekstbryting kunne ikke endres." },
            { TXT_COPY_SELECTION, L"&Kopier\tCtrl+C" },
            { TXT_SELECT_ALL, L"Merk &alt\tCtrl+A" },
            { TXT_FIND_MENU, L"&Søk…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Søk &neste\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Søk &forrige\tSkift+F3" },
            { TXT_FIND_TITLE, L"%s — Søk" },
            { TXT_FIND_WHAT, L"Søk &etter:" },
            { TXT_FIND_NEXT, L"Søk &neste" },
            { TXT_FIND_MATCH_CASE, L"Skill mellom store og små &bokstaver" },
            { TXT_FIND_BACKWARD, L"Søk b&akover" },
            { TXT_FIND_TOPMOST, L"Alltid &øverst" },
            { TXT_FIND_STARTS_WITH, L"Linjen &starter med" },
            { TXT_FIND_ENDS_WITH, L"Linjen sl&utter med" },
            { TXT_FIND_REGEX, L"&Regulært uttrykk" },
            { TXT_FIND_NOT_FOUND, L"Den angitte teksten ble ikke funnet." },
            { TXT_FIND_FAILED, L"Søket kunne ikke fullføres." },
            { TXT_FIND_REGEX_ERROR, L"Feil i regulært uttrykk:\r\n\r\n%s" },
        }
    },
    {
        LANG_SV,
        {
            { TXT_LANGUAGE_NAME, L"Svenska" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nWebbplats: " },
            { TXT_FILE_OPEN_FAILED, L"Kan inte öppna %s. Kontrollera sökväg och behörigheter." },
            { TXT_BROWSE_DLL, L"&Bläddra…" },
            { TXT_BROWSE_REPORT, L"Bl&äddra…" },
            { TXT_CLOSE, L"&Stäng" },
            { TXT_CLOSE_TAB, L"&Stäng\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"Stan&dard" },
            { TXT_EXPORT, L"&Exportera…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Arkiv" },
            { TXT_REPORT_FONT, L"Rapport&teckensnitt:" },
            { TXT_HELP_MENU, L"&Hjälp" },
            { TXT_HELP, L"&Hjälp\tF1" },
            { TXT_LANGUAGE, L"S&pråk:" },
            { TXT_OPEN_WEBSITE, L"&Öppna i standardwebbläsaren" },
            { TXT_OPEN, L"&Öppna…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"A&lternativ" },
            { TXT_PREFERENCES_MENU, L"&Preferenser…\tCtrl+G" },
            { TXT_ABOUT, L"&Om" },
            { TXT_ABOUT_TITLE, L"Om %ls" },
            { TXT_ALL_FILES, L"Alla filer" },
            { TXT_FONT_BOLD, L"Fet" },
            { TXT_FONT_BOLD_ITALIC, L"Fet + Kursiv" },
            { TXT_BROWSE_CURL, L"B&läddra…" },
            { TXT_CANCEL, L"Avbryt" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Kan inte läsa in MediaInfo.dll (Windows-fel %lu). Använd en 32-bitars DLL som är "
                L"kompatibel med den här Windows-versionen."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Kan inte läsa in libcurl.dll (Windows-fel %lu). Välj ett 32-bitars bibliotek som är "
                L"kompatibelt med den här Windows-versionen."
            },
            { TXT_CLOSE_ALL, L"Stäng &alla" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Kopiera &URL" },
            { TXT_COPY_INFORMATION, L"Kopiera &information" },
            { TXT_DLL_FILES, L"Dynamiska bibliotek" },
            { TXT_EXIT, L"A&vsluta\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Inbäddade bibliotek MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Inbäddade bibliotek libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Exportera rapport" },
            { TXT_FONT_ANTIALIASING, L"Teckensnittsut&jämning:" },
            { TXT_GIF_EXPORT_FAILED, L"GIF-export misslyckades. Förlustfri GIF kräver högst 256 färger." },
            { TXT_FONT_ITALIC, L"Kursiv" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED, L"JPEG-export misslyckades. En fungerande GDI+-JPEG-kodare krävs." },
            { TXT_LICENSE_UNAVAILABLE, L"Licensresursen är inte tillgänglig." },
            { TXT_MEDIA_FILES, L"Mediefiler" },
            { TXT_APPLICATION_DESCRIPTION, L"Visare för medieinformation" },
            { TXT_HELP_TITLE, L"MediaInfo — Hjälp" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo kunde inte initiera filanalysen." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo kan inte öppna eller identifiera den här filen." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"&Sökväg till MediaInfo.dll:" },
            { TXT_MEDIALIB_REQUIRED,
                L"MediaInfo.dll är inte inläst. Välj den under Alternativ > Preferenser."
            },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll är inte inläst." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Ingen kompatibel extern eller inbäddad MediaInfo.dll kunde läsas in. Välj den under "
                L"Alternativ > Preferenser."
            },
            { TXT_ANTIALIASING_NONE, L"Ingen" },
            { TXT_OK, L"OK" },
            { TXT_OPEN_TITLE, L"Öppna mediefiler" },
            { TXT_PLATFORM, L"Målplattform:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Preferenser" },
            { TXT_READY, L"Redo" },
            { TXT_FONT_REGULAR, L"Normal" },
            { TXT_REPORT_LANGUAGE, L"&Rapportspråk:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Rapportspråktabeller" },
            { TXT_SELECT_MEDIALIB, L"Bläddra: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Bläddra: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH,
                L"Välj en befintlig mediefil med en sökväg som är kortare än MAX_PATH."
            },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Välj befintliga filer med sökvägar kortare än MAX_PATH." },
            { TXT_SELECT_CURL, L"Bläddra: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Textdokument ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"BMP-bilden kan inte sparas. Kontrollera mål, ledigt minne och diskutrymme."
            },
            { TXT_LIBRARY_WORKER_START_FAILED, L"Biblioteksprocessen kan inte startas (Windows-fel %lu)." },
            { TXT_REPORT_COPY_FAILED, L"MediaInfo-rapporten kan inte kopieras till minnet." },
            { TXT_VIEWER_CREATE_FAILED, L"MediaInfo-visaren kan inte skapas." },
            { TXT_MEDIALIB_PATH_INVALID, L"Sökvägen till MediaInfo.dll är ogiltig eller för lång." },
            { TXT_PNG_EXPORT_FAILED,
                L"PNG-bilden kan inte sparas. Kontrollera mål, ledigt minne och diskutrymme."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"TIFF-bilden kan inte sparas. Kontrollera mål, ledigt minne och diskutrymme."
            },
            { TXT_COPY_URL_FAILED, L"URL-adressen kunde inte kopieras till Urklipp." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"Win32-visaren kräver en 32-bitars %s. Välj biblioteket för x86/i386."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Det inbäddade biblioteket kan inte skrivas till AppData, användarprofilen, Program Files "
                L"eller den tillfälliga mappen."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED,
                L"Bibliotekets dekomprimering eller CRC-kontroll misslyckades."
            },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Den inbäddade biblioteksresursen är ogiltig." },
            { TXT_CURL_FILENAME_INVALID,
                L"Biblioteket måste heta libcurl.dll för att MediaInfo ska kunna använda det."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Fildialogrutan kunde inte öppnas." },
            { TXT_FILE_DIALOG_SELECTION_FAILED, L"De valda filerna kunde inte hämtas från fildialogrutan." },
            { TXT_RECENT_FILE_MISSING,
                L"Filen ”%s” finns inte längre.\n\nVill du ta bort den här posten från listan över senaste "
                L"filer?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Filen är inte längre tillgänglig:\n\n%s\n\nVill du ta bort den här posten från listan "
                L"över senaste filer?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Informationen kunde inte kopieras till Urklipp." },
            { TXT_CURL_PATH_INVALID, L"Sökvägen till libcurl.dll är ogiltig eller för lång." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Biblioteket returnerade ingen MediaInfo-version." },
            { TXT_CURL_EXPORTS_MISSING,
                L"Biblioteket exporterar inte de curl-funktioner som MediaInfo kräver."
            },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"Biblioteket exporterar inte de Unicode-funktioner som MediaInfo kräver."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Biblioteksprocessen misslyckades under %s (kod 0x%08lX). Välj en kompatibel DLL under "
                L"Alternativ > Preferenser."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Biblioteksprocessen slutade svara under %s. Välj en kompatibel DLL under Alternativ > "
                L"Preferenser."
            },
            { TXT_PREFERENCES_SAVE_FAILED,
                L"Inställningarna tillämpades men kunde inte sparas i registret."
            },
            { TXT_REPORT_START_FAILED, L"Otillräckligt minne för att starta rapporten." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Rapportbilden kan inte skapas." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Språktabellen kan inte läsas in. Välj en giltig "
                L"MediaInfo-CSV-fil i UTF-8 eller UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"Rapporttråden kan inte startas." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"Vald MediaInfo.dll avvisade rapportspråket." },
            { TXT_INVALID_WINDOWS_DLL, L"Den valda filen är inte en giltig Windows-DLL." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Det valda bildformatet stöds inte." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Textrapporten kan inte sparas. Kontrollera mål och ledigt diskutrymme."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Webbplatsen kan inte öppnas i standardwebbläsaren." },
            { TXT_TOO_MANY_FILES, L"För många filer valdes. Öppna mindre grupper." },
            { TXT_LIBRARY_PATH_HINT,
                L"Använd 32-bitars bibliotek som är kompatibla med din Windows-version. Lämna sökvägarna "
                L"tomma för automatisk sökning. MediaInfoLib v0.7.60 använder inte libcurl.dll."
            },
            { TXT_VERSION, L"Version" },
            { TXT_WEBSITE_TOOLTIP, L"Besök webbplatsen %s" },
            { TXT_WAITING_FOR_REPORT, L"Väntar på att den aktuella rapporten ska slutföras." },
            { TXT_WEBSITE_LABEL, L"Webbplats:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"kopiering av MediaInfo-rapporten" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"Sökväg till libc&url.dll:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"inläsning av MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"inläsning av libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"frigöring av MediaInfo.dll" },
            { TXT_APPLY, L"&Verkställ" },
            { TXT_TAB_NAME_LENGTH, L"Fliknamnets lä&ngd:" },
            { TXT_TITLE_NAME_LENGTH, L"&Fönstertitelns längd:" },
            { TXT_RECENT_FILES, L"Senaste filer:" },
            { TXT_CLEAR_RECENT_FILES, L"R&ensa" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"Fliknamnets längd måste vara mellan 8 och 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"Namnets längd i titeln måste vara mellan 8 och 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Listan över senaste filer rensades, men kunde inte sparas i registret."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"Stän&g flikar med dubbelklick" },
            { TXT_CLOSE_TAB_CONTEXT, L"Stäng &flik" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"T&illåt flera instanser" },
            { TXT_INSTANCE_FORWARD_FAILED,
                L"Filerna kunde inte skickas till den körande MediaInfo-instansen."
            },
            { TXT_LOADING, L"Läser in…" },
            { TXT_LOADING_FILE, L"Läser in filen %s…" },
            { TXT_APPLICATION_HELP,
                L"FILER OCH FLIKAR\r\nWindows x86-visare för rapporter från MediaInfo.dll. Varje fil har "
                L"en egen skrivskyddad flik. Öppna med Ctrl+O eller dra och släpp. Att öppna igen väljer "
                L"den befintliga fliken. Ctrl+W eller den mittersta musknappen stänger en flik; Stäng "
                L"alla stänger samtliga flikar. Arkiv-menyn minns de åtta senaste filerna. Flikrubrikens "
                L"snabbmeny innehåller Stäng flik. Aktivera Stäng flikar med dubbelklick i Preferenser "
                L"för att stänga en flik genom att dubbelklicka på dess rubrik. Alternativet är avstängt "
                L"från början och sparas. Dubbelklick i rapporttexten markerar ett ord. Trippelklick "
                L"markerar en logisk rad. Dra för att utöka markeringen med ord eller rader.\r\nÖppna "
                L"mapp… öppnar filerna direkt i den valda mappen, var och en på en egen flik. Undermappar "
                L"tas inte med.\r\nÖppna och Öppna mapp delar den senast valda mappen. Export kommer ihåg "
                L"en egen mapp, som standard Dokument. Avancerat läge visar fler fält i rapporten.\r\n"
                L"Kända format / Kända kodekar / Kända parametrar — MediaInfo.dll.\r\nFullständig analys "
                L"undersöker hela filen och kan ta längre tid. Dessa rapportalternativ och Spårningsnivå "
                L"tillhör varje flik; en ändring uppdaterar endast den aktiva fliken. Den senast manuellt "
                L"valda kombinationen sparas för nya flikar och nästa start. En matchande cachad rapport "
                L"återanvänds så länge filen förblir oförändrad.\r\nSpårningsnivå: 0 / 5 / 9 / 10.\r\n"
                L"Arkiv > Utskriftsformat… öppnar inställningar för papper, orientering och marginaler "
                L"för den aktuella sessionen. Skriv ut… (Ctrl+P) öppnar systemets utskriftsdialog; "
                L"Windows 11 visar en förhandsgranskning, medan Windows 10 och äldre behåller den "
                L"klassiska dialogen. Ctrl+P skriver ut den aktiva fliken i huvudfönstret eller "
                L"textområdet i Hjälp eller Om, beroende på vilket fönster som har fokus. Rapporter "
                L"använder det valda rapportteckensnittet, Hjälp systemets dialogteckensnitt och Om "
                L"textområdets eget teckensnitt. Om inga flikar är öppna men hjälpfönstret är öppet är "
                L"Utskriftsformat… och Skriv ut… fortfarande tillgängliga; Skriv ut… skriver ut hjälpen. "
                L"Hjälp använder huvudfönstrets utskriftsdialog; ytterligare Ctrl+P i Hjälp för samma "
                L"dialog till förgrunden. Långa rader radbryts och texten delas upp på sidor. Utskrift "
                L"sker i bakgrunden.\r\nDra en eller flera filer till fönstret, EXE-ikonen eller dess "
                L"genväg, eller ange sökvägarna på kommandoraden. Om flera instanser inte är tillåtna "
                L"öppnas filerna i det fönster som redan körs.\r\nVänster del av statusfältet visar "
                L"filsökvägar och inläsningsförlopp; höger del visar versionen av den inlästa "
                L"MediaInfo.dll. Långa sökvägar förkortas med uteslutningstecken efter det tillgängliga "
                L"utrymmet.\r\n\r\nEXPORT\r\nTXT, BMP, GIF, JPEG, PNG, TIFF och WebP visas när de är "
                L"tillgängliga. Senaste exportmapp och format sparas.\r\nTXT erbjuder ANSI, UTF-8, UTF-8 "
                L"med BOM, UTF-16 BE med BOM och UTF-16 LE med BOM. Det andra alternativet, UTF-8 utan "
                L"BOM, är standard. Hela rapporttexten och dess ursprungliga radslut bevaras.\r\n\r\n"
                L"SKAPA EN HEADER-FIL\r\nMenyn Verktyg är den fjärde på menyraden. Dess Skapa en "
                L"header-fil…-kommando öppnar en källfil oberoende av rapportflikarna och kopierar dess "
                L"första 524288 byte (512 KiB). En kortare fil kopieras i sin helhet; en tom fil ger en "
                L"tom utdatafil. Detta är vanlig binär filläsning, utan MediaInfo-analys eller krav på "
                L"MediaInfo.dll. Verktyget lämnar rapportflikar och programmets lista över senaste filer "
                L"oförändrade.\r\n\r\nEfter läsning startar dialogrutan Spara som i källfilens mapp och "
                L"föreslår video.mp4.header för video.mp4: .header läggs till det fullständiga "
                L"originalnamnet. Du kan ändra både namnet och målmappen. Om du avbryter någon av "
                L"dialogrutorna skrivs ingen utdata. Att ersätta en befintlig destination kräver "
                L"bekräftelse. Källan förblir oförändrad; en misslyckad lagring bevarar den tidigare "
                L"destinationen. Öppning och sparande använder de senaste systemdialogrutorna som finns i "
                L"den aktuella Windows-versionen.\r\n\r\nVid programstart hämtar verktyget sin initiala "
                L"inmatningsmapp från Arkiv > Öppna. Om ingen mapp har sparats väljer Windows den "
                L"ursprungliga platsen. När en indatafil har valts kommer verktyget bara ihåg sin egen "
                L"mapp tills programmet avslutas, även om Spara som avbryts. Det ändrar varken mapparna "
                L"som används av Öppna och Exportera eller sparar sin egen mapp i programinställningarna. "
                L"Varje Spara som-dialogruta startar i mappen för den för närvarande valda indatafilen, "
                L"oavsett den tidigare sparade destinationen.\r\n\r\nPREFERENSER OCH SPRÅK\r\nPreferenser "
                L"(Alternativ > Preferenser, Ctrl+G) innehåller bibliotekssökvägar, rapportteckensnitt, "
                L"utjämning och språk. Gränssnittet har 36 varianter och följer först Windows. Rapporter "
                L"använder alltid bibliotekets ursprungliga engelska som standard, oberoende av Windows "
                L"och gränssnittet. Endast ett manuellt val ändrar rapportspråket: engelska, 37 "
                L"översättningar eller en egen MediaInfo-CSV-tabell. OK eller Verkställ bekräftar "
                L"ändringar; Avbryt förkastar väntande ändringar. Preferenser anger gränsen för fliknamn "
                L"(80 som standard) och rensar listan över senaste filer. Långa namn behåller början, "
                L"slutet och filändelsen med uteslutningstecken i mitten. Rensa tar bort listan över "
                L"senaste filer omedelbart, även om preferenserna därefter stängs med "
                L"Avbryt.\r\n\r\nHuvudfönstrets titel visar den aktiva filen som filnamn — MediaInfo. I "
                L"inställningarna kan namnets längd i titeln anges separat till 8–255 tecken (40 som "
                L"standard). Längre namn förkortas med samma uteslutningstecken i mitten, och filändelsen "
                L"behålls. Utan öppna flikar är titeln MediaInfo.\r\n\r\n"
                L"BIBLIOTEK OCH FÖNSTER\r\nProgrammet innehåller MediaInfo 26.10, 21.03 och 0.7.60, som "
                L"provas från den nyaste versionen efter externa bibliotek. De två nyare versionerna har "
                L"passande libcurl; 0.7.60 packar aldrig upp libcurl. Fönsterplaceringen sparas. Som "
                L"standard tillåts bara en instans och senare starter skickar filer till det öppna "
                L"fönstret. Flera instanser kan tillåtas i preferenserna. Med flera fönster återställs "
                L"den sparade positionen bara för det första fönstret av varje fönstertyp; senare fönster "
                L"återställer bara storleken.\r\n\r\nRedigera > Sök (Ctrl+F) söker i den aktiva "
                L"rapportfliken eller i textområdet i Hjälp eller Om, beroende på vilket fönster som har "
                L"fokus. Sökfönstret behåller den senast valda källan medan det självt har fokus. F3 "
                L"upprepar sökningen; Skift+F3 vänder riktningen. Vid textens ändar fortsätter sökningen "
                L"från motsatt ände. Alternativ > Automatiskt radbyte gäller bara den aktiva fliken; "
                L"bocken följer den valda fliken. Sökfönstret kan minimeras och ändras i bredd; "
                L"positionen och inställningen Alltid överst sparas. Upp till 30 söktexter med sina "
                L"alternativ behålls bara tills programmet avslutas. Alternativen för början och slutet "
                L"gäller logiska rader. Reguljära uttryck använder PCRE2-syntax. Övriga kommandon i menyn "
                L"Redigera gäller den aktiva rapportfliken. Enter startar sökningen; Skift+Enter vänder "
                L"den valda riktningen. ”Matcha gemener och versaler” skiljer mellan gemener och "
                L"versaler; ”Sök bakåt” söker mot textens början. Ett val i historiken återställer alla "
                L"fem sökalternativen, inklusive inställningen för reguljära uttryck; ”Alltid överst” är "
                L"oberoende. ”Reguljärt uttryck” inaktiverar ”Raden börjar med” och ”Raden slutar med”. "
                L"Om båda alternativen för radens ändar är aktiverade räcker en träff vid endera änden. "
                L"”Automatiskt radbyte” ändrar bara visningen."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"WebP-bilden kan inte sparas. Kontrollera mål, ledigt minne och diskutrymme."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Textdokument UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Textdokument UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Textdokument UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Textdokument UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Rapporten kan inte sparas med den här kodningen utan att tecken går förlorade. Välj en "
                L"annan textkodning."
            },
            { TXT_OPEN_FOLDER, L"Öppna &mapp…" },
            { TXT_OPEN_FOLDER_TITLE, L"Öppna mapp" },
            { TXT_FOLDER_READ_FAILED, L"Det gick inte att läsa mappen:\n\n%s\n\nWindows-fel %lu." },
            { TXT_ADVANCED_MODE, L"&Avancerat läge" },
            { TXT_REPORT_DETAIL_REJECTED, L"Vald MediaInfo.dll avvisade inställningen för rapportdetaljer." },
            { TXT_KNOWN_FORMATS, L"Kända &format" },
            { TXT_KNOWN_CODECS, L"Kända &kodekar" },
            { TXT_KNOWN_PARAMETERS, L"Kända &parametrar" },
            { TXT_KNOWN_FORMATS_TITLE, L"Kända format" },
            { TXT_KNOWN_CODECS_TITLE, L"Kända kodekar" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Kända parametrar" },
            { TXT_KNOWN_INFO_FAILED, L"Biblioteket returnerade inte den begärda informationen." },
            { TXT_FULL_PARSING, L"&Fullständig analys" },
            { TXT_PARSING_REJECTED, L"Vald MediaInfo.dll avvisade analysinställningen." },
            { TXT_TRACE_LEVEL_0, L"Spårningsnivå &0" },
            { TXT_TRACE_LEVEL_5, L"Spårningsnivå &5" },
            { TXT_TRACE_LEVEL_9, L"Spårningsnivå &9" },
            { TXT_TRACE_LEVEL_10, L"Spårningsnivå &10" },
            { TXT_PAGE_SETUP, L"Uts&kriftsformat…" },
            { TXT_PAGE_SETUP_FAILED, L"Utskriftsformatet kunde inte öppnas." },
            { TXT_PRINT, L"Skriv &ut…\tCtrl+P" },
            { TXT_PRINTING, L"Skriver ut…" },
            { TXT_PRINT_FAILED,
                L"Texten kunde inte skrivas ut. Kontrollera skrivaren, dess inställningar och "
                L"tillgängligt minne."
            },
            { TXT_TOOLS_MENU, L"&Verktyg" },
            { TXT_CREATE_HEADER, L"Skapa en &header-fil…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Skapa en header-fil - Öppna" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Skapa en header-fil - Spara som" },
            { TXT_HEADER_FORMAT, L"Headerfil (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Filens huvud kunde inte läsas:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Headerfilen kunde inte sparas:\n\n%s" },
            { TXT_COPY, L"&Kopiera" },
            { TXT_COPY_FILE_NAME, L"Kopiera fi&lnamn" },
            { TXT_COPY_FULL_PATH, L"Kopiera fullständig sök&väg" },
            { TXT_LAUNCH_FILE, L"S&tarta fil" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"V&isa i mapp" },
            { TXT_EDIT_MENU, L"&Redigera" },
            { TXT_WORD_WRAP, L"A&utomatiskt radbyte" },
            { TXT_WORD_WRAP_FAILED, L"Automatiskt radbyte kunde inte ändras." },
            { TXT_COPY_SELECTION, L"&Kopiera\tCtrl+C" },
            { TXT_SELECT_ALL, L"Markera &allt\tCtrl+A" },
            { TXT_FIND_MENU, L"&Sök…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Sök &nästa\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Sök &föregående\tSkift+F3" },
            { TXT_FIND_TITLE, L"%s — Sök" },
            { TXT_FIND_WHAT, L"Sök &efter:" },
            { TXT_FIND_NEXT, L"Sök &nästa" },
            { TXT_FIND_MATCH_CASE, L"&Matcha gemener och versaler" },
            { TXT_FIND_BACKWARD, L"Sök &bakåt" },
            { TXT_FIND_TOPMOST, L"Alltid &överst" },
            { TXT_FIND_STARTS_WITH, L"&Raden börjar med" },
            { TXT_FIND_ENDS_WITH, L"Raden s&lutar med" },
            { TXT_FIND_REGEX, L"Re&guljärt uttryck" },
            { TXT_FIND_NOT_FOUND, L"Den angivna texten hittades inte." },
            { TXT_FIND_FAILED, L"Sökningen kunde inte slutföras." },
            { TXT_FIND_REGEX_ERROR, L"Fel i reguljärt uttryck:\r\n\r\n%s" },
        }
    },
    {
        LANG_TR,
        {
            { TXT_LANGUAGE_NAME, L"Türkçe" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nWeb sitesi: " },
            { TXT_FILE_OPEN_FAILED, L"%s açılamıyor. Yolu ve izinleri denetleyin." },
            { TXT_BROWSE_DLL, L"&Gözat…" },
            { TXT_BROWSE_REPORT, L"Göz&at…" },
            { TXT_CLOSE, L"&Kapat" },
            { TXT_CLOSE_TAB, L"&Kapat\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"&Varsayılan" },
            { TXT_EXPORT, L"&Dışa aktar…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Dosya" },
            { TXT_REPORT_FONT, L"Rapor ya&zı tipi:" },
            { TXT_HELP_MENU, L"&Yardım" },
            { TXT_HELP, L"&Yardım\tF1" },
            { TXT_LANGUAGE, L"&Dil:" },
            { TXT_OPEN_WEBSITE, L"Varsayılan tarayıcıda &aç" },
            { TXT_OPEN, L"&Aç…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Seçenekler" },
            { TXT_PREFERENCES_MENU, L"&Tercihler…\tCtrl+G" },
            { TXT_ABOUT, L"&Hakkında" },
            { TXT_ABOUT_TITLE, L"%ls Hakkında" },
            { TXT_ALL_FILES, L"Tüm dosyalar" },
            { TXT_FONT_BOLD, L"Kalın" },
            { TXT_FONT_BOLD_ITALIC, L"Kalın + İtalik" },
            { TXT_BROWSE_CURL, L"G&özat…" },
            { TXT_CANCEL, L"İptal" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"MediaInfo.dll yüklenemiyor (Windows hatası %lu). Bu Windows sürümüyle uyumlu bir 32 bit "
                L"DLL kullanın."
            },
            { TXT_CURL_LOAD_FAILED,
                L"libcurl.dll yüklenemiyor (Windows hatası %lu). Bu Windows sürümüyle uyumlu bir 32 bit "
                L"kitaplık seçin."
            },
            { TXT_CLOSE_ALL, L"&Tümünü kapat" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"&URL'yi kopyala" },
            { TXT_COPY_INFORMATION, L"&Bilgileri kopyala" },
            { TXT_DLL_FILES, L"Dinamik kitaplıklar" },
            { TXT_EXIT, L"&Çıkış\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Gömülü kitaplıklar MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Gömülü kitaplıklar libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Raporu dışa aktar" },
            { TXT_FONT_ANTIALIASING, L"Yazı tipi &kenar yumuşatma:" },
            { TXT_GIF_EXPORT_FAILED,
                L"GIF dışa aktarımı başarısız. Kayıpsız GIF en fazla 256 renk gerektirir."
            },
            { TXT_FONT_ITALIC, L"İtalik" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED,
                L"JPEG dışa aktarımı başarısız. Çalışan bir GDI+ JPEG kodlayıcısı gerekir."
            },
            { TXT_LICENSE_UNAVAILABLE, L"Lisans kaynağı kullanılamıyor." },
            { TXT_MEDIA_FILES, L"Medya dosyaları" },
            { TXT_APPLICATION_DESCRIPTION, L"Medya bilgisi görüntüleyicisi" },
            { TXT_HELP_TITLE, L"MediaInfo — Yardım" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo dosya analizini başlatamadı." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo bu dosyayı açamıyor veya tanıyamıyor." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"MediaInfo.dll &yolu:" },
            { TXT_MEDIALIB_REQUIRED, L"MediaInfo.dll yüklenmedi. Seçenekler > Tercihler bölümünden seçin." },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll yüklenmedi." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Uyumlu haricî veya gömülü MediaInfo.dll yüklenemedi. Seçenekler > Tercihler bölümünden "
                L"seçin."
            },
            { TXT_ANTIALIASING_NONE, L"Yok" },
            { TXT_OK, L"Tamam" },
            { TXT_OPEN_TITLE, L"Medya dosyalarını aç" },
            { TXT_PLATFORM, L"Hedef platform:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Tercihler" },
            { TXT_READY, L"Hazır" },
            { TXT_FONT_REGULAR, L"Normal" },
            { TXT_REPORT_LANGUAGE, L"&Rapor dili:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Rapor dili tabloları" },
            { TXT_SELECT_MEDIALIB, L"Gözat: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Gözat: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH, L"Yolu MAX_PATH sınırından kısa olan mevcut bir medya dosyası seçin." },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Yolları MAX_PATH sınırından kısa olan mevcut dosyaları seçin." },
            { TXT_SELECT_CURL, L"Gözat: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Metin belgesi ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"BMP görüntüsü kaydedilemiyor. Hedefi, boş belleği ve disk alanını denetleyin."
            },
            { TXT_LIBRARY_WORKER_START_FAILED, L"Kitaplık işlemi başlatılamıyor (Windows hatası %lu)." },
            { TXT_REPORT_COPY_FAILED, L"MediaInfo raporu belleğe kopyalanamıyor." },
            { TXT_VIEWER_CREATE_FAILED, L"MediaInfo görüntüleyicisi oluşturulamıyor." },
            { TXT_MEDIALIB_PATH_INVALID, L"MediaInfo.dll yolu geçersiz veya çok uzun." },
            { TXT_PNG_EXPORT_FAILED,
                L"PNG görüntüsü kaydedilemiyor. Hedefi, boş belleği ve disk alanını denetleyin."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"TIFF görüntüsü kaydedilemiyor. Hedefi, boş belleği ve disk alanını denetleyin."
            },
            { TXT_COPY_URL_FAILED, L"URL panoya kopyalanamadı." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"Win32 görüntüleyici 32 bit %s gerektirir. x86/i386 kitaplığını seçin."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Gömülü kitaplık AppData, kullanıcı profili, Program Files veya geçici klasöre yazılamıyor."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED, L"Kitaplığın açılması veya CRC denetimi başarısız." },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Gömülü kitaplık kaynağı geçersiz." },
            { TXT_CURL_FILENAME_INVALID,
                L"MediaInfo tarafından kullanılabilmesi için kitaplığın adı libcurl.dll olmalıdır."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Dosya iletişim kutusu açılamadı." },
            { TXT_FILE_DIALOG_SELECTION_FAILED, L"Seçilen dosyalar dosya iletişim kutusundan alınamadı." },
            { TXT_RECENT_FILE_MISSING,
                L"“%s” dosyası artık mevcut değil.\n\nBu öğe son dosyalar listesinden kaldırılsın mı?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Dosya artık kullanılamıyor:\n\n%s\n\nBu öğe son dosyalar listesinden kaldırılsın mı?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Bilgiler panoya kopyalanamadı." },
            { TXT_CURL_PATH_INVALID, L"libcurl.dll yolu geçersiz veya çok uzun." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Kitaplık MediaInfo sürümünü döndürmedi." },
            { TXT_CURL_EXPORTS_MISSING,
                L"Kitaplık, MediaInfo’nun gerektirdiği curl işlevlerini dışa aktarmıyor."
            },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"Kitaplık, gerekli MediaInfo Unicode işlevlerini dışa aktarmıyor."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Kitaplık işlemi %s sırasında başarısız oldu (kod 0x%08lX). Seçenekler > Tercihler "
                L"bölümünden uyumlu bir DLL seçin."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Kitaplık işlemi %s sırasında yanıt vermeyi durdurdu. Seçenekler > Tercihler bölümünden "
                L"uyumlu bir DLL seçin."
            },
            { TXT_PREFERENCES_SAVE_FAILED, L"Tercihler uygulandı ancak kayıt defterine kaydedilemedi." },
            { TXT_REPORT_START_FAILED, L"Raporu başlatmak için yeterli bellek yok." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Rapor görüntüsü oluşturulamıyor." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Dil tablosu yüklenemiyor. Geçerli bir UTF-8 veya UTF-16 "
                L"MediaInfo CSV dosyası seçin." },
            { TXT_REPORT_THREAD_START_FAILED, L"Rapor iş parçacığı başlatılamıyor." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"Seçili MediaInfo.dll rapor dilini reddetti." },
            { TXT_INVALID_WINDOWS_DLL, L"Seçili dosya geçerli bir Windows DLL dosyası değil." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Seçili görüntü biçimi desteklenmiyor." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Metin raporu kaydedilemiyor. Hedefi ve boş disk alanını denetleyin."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Web sitesi varsayılan tarayıcıda açılamıyor." },
            { TXT_TOO_MANY_FILES, L"Çok fazla dosya seçildi. Daha küçük gruplar açın." },
            { TXT_LIBRARY_PATH_HINT,
                L"Windows sürümünüzle uyumlu 32 bit kitaplıklar kullanın. Otomatik arama için yolları boş "
                L"bırakın. MediaInfoLib v0.7.60 libcurl.dll kullanmaz."
            },
            { TXT_VERSION, L"Sürüm" },
            { TXT_WEBSITE_TOOLTIP, L"%s web sitesini ziyaret et" },
            { TXT_WAITING_FOR_REPORT, L"Geçerli raporun tamamlanması bekleniyor." },
            { TXT_WEBSITE_LABEL, L"Web sitesi:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"MediaInfo raporunun kopyalanması" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"libc&url.dll yolu:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"MediaInfo.dll dosyasının yüklenmesi" },
            { TXT_CURL_LOAD_OPERATION, L"libcurl.dll dosyasının yüklenmesi" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"MediaInfo.dll dosyasının serbest bırakılması" },
            { TXT_APPLY, L"Uygu&la" },
            { TXT_TAB_NAME_LENGTH, L"&Sekme adı uzunluğu:" },
            { TXT_TITLE_NAME_LENGTH, L"&Başlık uzunluğu:" },
            { TXT_RECENT_FILES, L"Son dosyalar:" },
            { TXT_CLEAR_RECENT_FILES, L"&Temizle" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"Sekme adı uzunluğu 8 ile 255 arasında olmalıdır." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"Başlıktaki adın uzunluğu 8 ile 255 arasında olmalıdır." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Son dosyalar listesi temizlendi ancak kayıt defterine kaydedilemedi."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"S&ekmeleri çift tıklamayla kapat" },
            { TXT_CLOSE_TAB_CONTEXT, L"&Sekmeyi kapat" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"Birde&n fazla örneğe izin ver" },
            { TXT_INSTANCE_FORWARD_FAILED, L"Dosyalar çalışan MediaInfo örneğine aktarılamadı." },
            { TXT_LOADING, L"Yükleniyor…" },
            { TXT_LOADING_FILE, L"Dosya yükleniyor: %s…" },
            { TXT_APPLICATION_HELP,
                L"DOSYALAR VE SEKMELER\r\nMediaInfo.dll raporları için yerel Windows x86 görüntüleyicisi. "
                L"Her dosyanın salt okunur bir sekmesi vardır. Ctrl+O ile veya sürükleyip bırakarak açın. "
                L"Yeniden açmak mevcut sekmeyi seçer. Ctrl+W veya farenin orta düğmesi sekmeyi kapatır; "
                L"Tümünü kapat bütün sekmeleri kapatır. Dosya menüsü son sekiz dosyayı hatırlar. Sekme "
                L"başlığının bağlam menüsünde Sekmeyi kapat bulunur. Başlığına çift tıklayarak sekmeyi "
                L"kapatmak için Tercihler'de Sekmeleri çift tıklamayla kapat seçeneğini etkinleştirin. "
                L"Seçenek varsayılan olarak kapalıdır ve kaydedilir. Rapor metnine çift tıklamak bir "
                L"sözcüğü seçer. Üç kez tıklamak mantıksal bir satırı seçer. Sürüklemek seçimi sözcükler "
                L"veya satırlar halinde genişletir.\r\nKlasör aç… seçili klasörün doğrudan içindeki "
                L"dosyaları, her biri kendi sekmesinde olacak şekilde açar. Alt klasörler dahil "
                L"edilmez.\r\nAç ve Klasör aç, son seçilen klasörü paylaşır. Dışa aktarma kendi klasörünü "
                L"hatırlar; varsayılan klasör Belgeler’dir. Gelişmiş mod, raporda ek alanlar gösterir.\r\n"
                L"Bilinen biçimler / Bilinen kodekler / Bilinen parametreler — MediaInfo.dll.\r\nTam "
                L"Ayrıştırma dosyanın tamamını inceler ve daha uzun sürebilir. Bu rapor seçenekleri ve "
                L"İzleme Düzeyi her sekmeye aittir; bir değişiklik yalnızca etkin sekmeyi yeniler. Manuel "
                L"olarak seçilen son kombinasyon, yeni sekmeler ve bir sonraki başlatma için kaydedilir. "
                L"Eşleşen önbelleğe alınmış bir rapor, dosya değişmeden kaldığı sürece yeniden "
                L"kullanılır.\r\nİzleme Düzeyi: 0 / 5 / 9 / 10.\r\nDosya > Sayfa Yapısı… geçerli oturum "
                L"için kâğıt, yön ve kenar boşluğu ayarlarını açar. Yazdır… (Ctrl+P) sistem yazdırma "
                L"iletişim kutusunu açar; Windows 11 önizleme sunar, Windows 10 ve önceki sürümler klasik "
                L"iletişim kutusunu korur. Ctrl+P, odağın bulunduğu pencereye göre ana penceredeki etkin "
                L"sekmeyi veya Yardım ya da Hakkında penceresinin metin alanını yazdırır. Raporlar "
                L"seçilen rapor yazı tipini, Yardım sistem iletişim kutusu yazı tipini, Hakkında ise "
                L"kendi metin alanının yazı tipini kullanır. Hiçbir sekme açık değilken Yardım açıksa "
                L"Sayfa Yapısı… ve Yazdır… kullanılabilir kalır; Yazdır… Yardım'ı yazdırır. Yardım, ana "
                L"pencerenin yazdırma iletişim kutusunu kullanır; Yardım'da tekrar Ctrl+P'ye basmak aynı "
                L"iletişim kutusunu öne getirir. Uzun satırlar kaydırılır ve metin sayfalara bölünür. "
                L"Yazdırma arka planda yapılır.\r\nBir veya daha fazla dosyayı pencereye, EXE simgesine "
                L"veya kısayoluna sürükleyin ya da yollarını komut satırında belirtin. Birden çok örneğe "
                L"izin verilmiyorsa dosyalar zaten açık olan pencerede açılır.\r\nDurum çubuğunun sol "
                L"tarafı dosya yollarını ve yükleme ilerlemesini, sağ tarafı ise yüklenen MediaInfo.dll "
                L"sürümünü gösterir. Uzun yollar kullanılabilir alana göre üç noktayla kısaltılır.\r\n\r\n"
                L"DIŞA AKTARMA\r\nTXT, BMP, GIF, JPEG, PNG, TIFF ve WebP kullanılabildiklerinde "
                L"listelenir. Son dışa aktarma klasörü ve biçimi hatırlanır.\r\nTXT; ANSI, UTF-8, BOM "
                L"içeren UTF-8, BOM içeren UTF-16 BE ve BOM içeren UTF-16 LE seçeneklerini sunar. İkinci "
                L"seçenek olan BOM içermeyen UTF-8 varsayılandır. Raporun tam metni ve özgün satır "
                L"sonları korunur.\r\n\r\nÜST BİLGİ DOSYASI OLUŞTUR\r\nAraçlar menüsü, menü çubuğundaki "
                L"dördüncü menüdür. Üst bilgi dosyası oluştur… komutu, rapor sekmelerinden bağımsız "
                L"olarak bir kaynak dosyayı açar ve ilk 524288 baytını (512 KiB) kopyalar. Daha kısa bir "
                L"dosya tam olarak kopyalanır; boş bir dosya boş bir çıktı üretir. Bu, MediaInfo analizi "
                L"veya MediaInfo.dll gereksinimi olmadan sıradan bir ikili dosya okumasıdır. Araç, rapor "
                L"sekmelerini ve görüntüleyicinin son dosyalar listesini değiştirmeden bırakır.\r\n\r\n"
                L"Okuduktan sonra, kaynak dosyanın klasöründe Farklı Kaydet iletişim kutusu başlar ve "
                L"video.mp4 için video.mp4.header'ı önerir: .header orijinal adın tamamına eklenir. Hem "
                L"adı hem de hedef klasörü değiştirebilirsiniz. Her iki iletişim kutusunun iptal edilmesi "
                L"hiçbir çıktı yazmaz. Mevcut bir hedefi değiştirmek onay gerektirir. Kaynak değişmeden "
                L"kalır; başarısız bir kaydetme önceki hedefi korur. Açma ve kaydetme işlemlerinde "
                L"kullanılan Windows sürümünde mevcut olan en yeni sistem iletişim kutuları "
                L"kullanılır.\r\n\r\nUygulama başlatıldığında araç, ilk giriş klasörünü Dosya > Aç "
                L"konumundan alır. Hiçbir klasör kaydedilmemişse Windows başlangıç konumunu seçer. Bir "
                L"giriş dosyası seçildikten sonra araç, Farklı Kaydet iptal edilse bile yalnızca "
                L"uygulamadan çıkana kadar kendi klasörünü hatırlar. Aç ve Dışa aktar tarafından "
                L"kullanılan klasörleri değiştirmez ve kendi klasörünü uygulama ayarlarına kaydetmez. Her "
                L"Farklı Kaydet iletişim kutusu, önceki kaydetme hedefine bakılmaksızın, o anda seçili "
                L"olan giriş dosyasının klasöründe başlar.\r\n\r\nTERCİHLER VE DİLLER\r\nTercihler "
                L"(Seçenekler > Tercihler, Ctrl+G), kitaplık yollarını, rapor yazı tipini, yumuşatmayı ve "
                L"dilleri içerir. Arayüzün 36 seçeneği vardır ve başlangıçta Windows’u izler. Raporların "
                L"varsayılan dili, Windows ve arayüzden bağımsız olarak her zaman kitaplığın özgün "
                L"İngilizcesidir. Bunu yalnızca elle yapılan rapor dili seçimi değiştirir: İngilizce, 37 "
                L"çeviri veya özel MediaInfo CSV tablosu. Tamam veya Uygula değişiklikleri onaylar; İptal "
                L"bekleyen değişiklikleri atar. Tercihler, sekme adı sınırını (varsayılan 80) ayarlar ve "
                L"son dosyalar listesini temizler. Uzun adlar başlangıcı, sonu ve uzantıyı korur; ortada "
                L"üç nokta bulunur. Temizle, Tercihler daha sonra İptal ile kapatılsa bile son dosyalar "
                L"listesini hemen siler.\r\n\r\nAna pencere başlığı etkin dosyayı dosya adı — MediaInfo "
                L"biçiminde gösterir. Tercihlerde başlıktaki adın uzunluğu bağımsız olarak 8–255 karakter "
                L"arasında ayarlanabilir (varsayılan 40). Uzun adlar aynı orta üç noktayla kısaltılır ve "
                L"uzantı korunur. Açık sekme yoksa başlık MediaInfo olur.\r\n\r\nKİTAPLIKLAR VE "
                L"PENCERELER\r\nProgram, MediaInfo 26.10, "
                L"21.03 ve 0.7.60 kitaplıklarını içerir. Dış kitaplıklardan sonra bunlar en yeni sürümden "
                L"eskiye doğru denenir. İki yeni sürümün uygun libcurl kitaplıkları vardır; 0.7.60 "
                L"libcurl’ü asla çıkartmaz. Pencere konumu kaydedilir. Varsayılan olarak yalnızca tek "
                L"örneğe izin verilir ve sonraki başlatmalar dosyaları açık pencereye gönderir. "
                L"Tercihlerde birden fazla örneğe izin verilebilir. Birden fazla pencere olduğunda, her "
                L"pencere türünün yalnızca ilk penceresi kayıtlı konumunu geri yükler; sonraki pencereler "
                L"yalnızca boyutu geri yükler.\r\n\r\nDüzenle > Bul (Ctrl+F), odağın bulunduğu pencereye "
                L"göre etkin rapor sekmesinde veya Yardım ya da Hakkında penceresinin metin alanında "
                L"arar. Arama penceresi, odak kendisindeyken son seçilen kaynağı korur. F3 aramayı "
                L"yineler; Shift+F3 yönünü tersine çevirir. Metnin sonuna ulaşıldığında arama diğer uçtan "
                L"devam eder. Seçenekler > Sözcük Kaydır yalnızca etkin sekmeyi etkiler; onay işareti "
                L"seçili sekmeye göre değişir. Arama penceresi simge durumuna küçültülebilir ve yatay "
                L"olarak boyutlandırılabilir; konumu ile Her zaman üstte ayarı hatırlanır. En fazla 30 "
                L"arama metni ve seçenekleri yalnızca uygulama kapatılana kadar saklanır. Başlangıç ve "
                L"bitiş seçenekleri mantıksal satırları esas alır. Düzenli ifadeler PCRE2 sözdizimini "
                L"kullanır. Düzenle menüsündeki diğer komutlar etkin rapor sekmesine uygulanır. Enter "
                L"aramayı başlatır; Shift+Enter seçilen yönü tersine çevirir. “Büyük/küçük harf eşleştir” "
                L"büyük ve küçük harfleri ayırt eder; “Geriye doğru ara” metnin başına doğru arar. "
                L"Geçmişten bir öğe seçmek, düzenli ifade modunun durumu da dahil beş arama seçeneğinin "
                L"tümünü geri yükler; “Her zaman üstte” bağımsızdır. “Düzenli ifade”, “Satır şu ifadeyle "
                L"başlar” ve “Satır şu ifadeyle biter” seçeneklerini devre dışı bırakır. Her iki satır "
                L"ucu seçeneği de açıksa uçlardan birinde eşleşme olması yeterlidir. “Sözcük Kaydır” "
                L"yalnızca görünümü değiştirir."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"WebP görüntüsü kaydedilemiyor. Hedefi, boş belleği ve disk alanını denetleyin."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Metin belgesi UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Metin belgesi UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Metin belgesi UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Metin belgesi UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Rapor, karakter kaybı olmadan bu kodlamayla kaydedilemez. Başka bir metin kodlaması seçin."
            },
            { TXT_OPEN_FOLDER, L"Klasö&r aç…" },
            { TXT_OPEN_FOLDER_TITLE, L"Klasör aç" },
            { TXT_FOLDER_READ_FAILED, L"Klasör okunamadı:\n\n%s\n\nWindows hatası %lu." },
            { TXT_ADVANCED_MODE, L"&Gelişmiş Mod" },
            { TXT_REPORT_DETAIL_REJECTED, L"Seçilen MediaInfo.dll, rapor ayrıntı ayarını reddetti." },
            { TXT_KNOWN_FORMATS, L"Bilinen &biçimler" },
            { TXT_KNOWN_CODECS, L"Bilinen &kodekler" },
            { TXT_KNOWN_PARAMETERS, L"Bilinen &parametreler" },
            { TXT_KNOWN_FORMATS_TITLE, L"Bilinen biçimler" },
            { TXT_KNOWN_CODECS_TITLE, L"Bilinen kodekler" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Bilinen parametreler" },
            { TXT_KNOWN_INFO_FAILED, L"Kitaplık istenen bilgileri döndürmedi." },
            { TXT_FULL_PARSING, L"Tam &Ayrıştırma" },
            { TXT_PARSING_REJECTED, L"Seçilen MediaInfo.dll, ayrıştırma ayarını reddetti." },
            { TXT_TRACE_LEVEL_0, L"İzleme Düzeyi &0" },
            { TXT_TRACE_LEVEL_5, L"İzleme Düzeyi &5" },
            { TXT_TRACE_LEVEL_9, L"İzleme Düzeyi &9" },
            { TXT_TRACE_LEVEL_10, L"İzleme Düzeyi &10" },
            { TXT_PAGE_SETUP, L"&Sayfa Yapısı…" },
            { TXT_PAGE_SETUP_FAILED, L"Sayfa yapısı açılamadı." },
            { TXT_PRINT, L"&Yazdır…\tCtrl+P" },
            { TXT_PRINTING, L"Yazdırılıyor…" },
            { TXT_PRINT_FAILED,
                L"Metin yazdırılamadı. Yazıcıyı, ayarlarını ve kullanılabilir belleği denetleyin."
            },
            { TXT_TOOLS_MENU, L"Ara&çlar" },
            { TXT_CREATE_HEADER, L"&Üst bilgi dosyası oluştur…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Üst bilgi dosyası oluştur - Aç" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Üst bilgi dosyası oluştur - Farklı Kaydet" },
            { TXT_HEADER_FORMAT, L"Üst bilgi dosyası (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Dosyanın üst bilgisi okunamadı:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Üst bilgi dosyası kaydedilemedi:\n\n%s" },
            { TXT_COPY, L"&Kopyala" },
            { TXT_COPY_FILE_NAME, L"Dosya &adını kopyala" },
            { TXT_COPY_FULL_PATH, L"Tam dosya &yolunu kopyala" },
            { TXT_LAUNCH_FILE, L"D&osyayı başlat" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"K&lasörde göster" },
            { TXT_EDIT_MENU, L"Dü&zenle" },
            { TXT_WORD_WRAP, L"&Sözcük Kaydır" },
            { TXT_WORD_WRAP_FAILED, L"Sözcük kaydırma değiştirilemedi." },
            { TXT_COPY_SELECTION, L"&Kopyala\tCtrl+C" },
            { TXT_SELECT_ALL, L"Tü&münü Seç\tCtrl+A" },
            { TXT_FIND_MENU, L"&Bul…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"&Sonrakini Bul\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"&Öncekini Bul\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Bul" },
            { TXT_FIND_WHAT, L"Aranan &metin:" },
            { TXT_FIND_NEXT, L"&Sonrakini Bul" },
            { TXT_FIND_MATCH_CASE, L"Büyük/küçük &harf eşleştir" },
            { TXT_FIND_BACKWARD, L"&Geriye doğru ara" },
            { TXT_FIND_TOPMOST, L"Her zaman &üstte" },
            { TXT_FIND_STARTS_WITH, L"Satır şu ifadeyle &başlar" },
            { TXT_FIND_ENDS_WITH, L"Sa&tır şu ifadeyle biter" },
            { TXT_FIND_REGEX, L"Dü&zenli ifade" },
            { TXT_FIND_NOT_FOUND, L"Belirtilen metin bulunamadı." },
            { TXT_FIND_FAILED, L"Arama tamamlanamadı." },
            { TXT_FIND_REGEX_ERROR, L"Düzenli ifade hatası:\r\n\r\n%s" },
        }
    },
    {
        LANG_ET,
        {
            { TXT_LANGUAGE_NAME, L"Eesti" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nVeebisait: " },
            { TXT_FILE_OPEN_FAILED, L"Faili %s ei saa avada. Kontrollige teed ja õigusi." },
            { TXT_BROWSE_DLL, L"&Sirvi…" },
            { TXT_BROWSE_REPORT, L"Si&rvi…" },
            { TXT_CLOSE, L"&Sule" },
            { TXT_CLOSE_TAB, L"&Sule\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"&Vaikesäte" },
            { TXT_EXPORT, L"&Ekspordi…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Fail" },
            { TXT_REPORT_FONT, L"Aruande &font:" },
            { TXT_HELP_MENU, L"&Spikker" },
            { TXT_HELP, L"&Spikker\tF1" },
            { TXT_LANGUAGE, L"&Keel:" },
            { TXT_OPEN_WEBSITE, L"&Ava vaikebrauseris" },
            { TXT_OPEN, L"&Ava…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"S&uvandid" },
            { TXT_PREFERENCES_MENU, L"&Eelistused…\tCtrl+G" },
            { TXT_ABOUT, L"&Teave" },
            { TXT_ABOUT_TITLE, L"Teave %ls kohta" },
            { TXT_ALL_FILES, L"Kõik failid" },
            { TXT_FONT_BOLD, L"Paks" },
            { TXT_FONT_BOLD_ITALIC, L"Paks + Kursiiv" },
            { TXT_BROWSE_CURL, L"S&irvi…" },
            { TXT_CANCEL, L"Loobu" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"MediaInfo.dll-i ei saa laadida (Windowsi tõrge %lu). Kasutage selle Windowsi versiooniga "
                L"ühilduvat 32-bitist DLL-i."
            },
            { TXT_CURL_LOAD_FAILED,
                L"libcurl.dll-i ei saa laadida (Windowsi tõrge %lu). Valige selle Windowsi versiooniga "
                L"ühilduv 32-bitine teek."
            },
            { TXT_CLOSE_ALL, L"Sule &kõik" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Kopeeri a&dress" },
            { TXT_COPY_INFORMATION, L"Kopeeri &teave" },
            { TXT_DLL_FILES, L"Dünaamilised teegid" },
            { TXT_EXIT, L"&Välju\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Kaasatud teegid MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Kaasatud teegid libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Ekspordi aruanne" },
            { TXT_FONT_ANTIALIASING, L"F&ondi silumine:" },
            { TXT_GIF_EXPORT_FAILED, L"GIF-i eksport nurjus. Kadudeta GIF lubab kuni 256 värvi." },
            { TXT_FONT_ITALIC, L"Kursiiv" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED, L"JPEG eksport nurjus. Vaja on töötavat GDI+ JPEG-kooderit." },
            { TXT_LICENSE_UNAVAILABLE, L"Litsentsiressurss pole saadaval." },
            { TXT_MEDIA_FILES, L"Meediafailid" },
            { TXT_APPLICATION_DESCRIPTION, L"Meediateabe vaatur" },
            { TXT_HELP_TITLE, L"MediaInfo — Spikker" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo ei saanud faili analüüsi lähtestada." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo ei saa faili avada ega tuvastada." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"MediaInfo.dll-i &tee:" },
            { TXT_MEDIALIB_REQUIRED,
                L"MediaInfo.dll pole laaditud. Valige see menüüst Suvandid > Eelistused."
            },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll pole laaditud." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Ühilduvat välist ega kaasatud MediaInfo.dll-i ei saa laadida. Valige see menüüst Suvandid "
                L"> Eelistused."
            },
            { TXT_ANTIALIASING_NONE, L"Puudub" },
            { TXT_OK, L"OK" },
            { TXT_OPEN_TITLE, L"Ava meediafailid" },
            { TXT_PLATFORM, L"Sihtplatvorm:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Eelistused" },
            { TXT_READY, L"Valmis" },
            { TXT_FONT_REGULAR, L"Tavaline" },
            { TXT_REPORT_LANGUAGE, L"&Aruande keel:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Aruannete keeletabelid" },
            { TXT_SELECT_MEDIALIB, L"Sirvi: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Sirvi: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH, L"Valige olemasolev meediafail, mille tee on lühem kui MAX_PATH." },
            { TXT_SELECTED_PATHS_TOO_LONG,
                L"Valige olemasolevad failid, mille teed on lühemad kui MAX_PATH."
            },
            { TXT_SELECT_CURL, L"Sirvi: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Tekstidokument ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"BMP-pilti ei saa salvestada. Kontrollige sihtkohta, vaba mälu ja kettaruumi."
            },
            { TXT_LIBRARY_WORKER_START_FAILED, L"Teegi protsessi ei saa käivitada (Windowsi tõrge %lu)." },
            { TXT_REPORT_COPY_FAILED, L"MediaInfo aruannet ei saa mällu kopeerida." },
            { TXT_VIEWER_CREATE_FAILED, L"MediaInfo vaaturit ei saa luua." },
            { TXT_MEDIALIB_PATH_INVALID, L"MediaInfo.dll-i tee on vigane või liiga pikk." },
            { TXT_PNG_EXPORT_FAILED,
                L"PNG-pilti ei saa salvestada. Kontrollige sihtkohta, vaba mälu ja kettaruumi."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"TIFF-pilti ei saa salvestada. Kontrollige sihtkohta, vaba mälu ja kettaruumi."
            },
            { TXT_COPY_URL_FAILED, L"URL-i ei saanud lõikelauale kopeerida." },
            { TXT_LIBRARY_REQUIRES_X86, L"Win32 vaatur nõuab 32-bitist %s-i. Valige x86/i386 teek." },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Kaasatud teeki ei saa kirjutada AppDatasse, kasutajaprofiili, Program Filesi ega ajutisse "
                L"kausta."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED, L"Teegi lahtipakkimine või CRC-kontroll nurjus." },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Kaasatud teegi ressurss on vigane." },
            { TXT_CURL_FILENAME_INVALID,
                L"Teegi nimi peab olema libcurl.dll, et MediaInfo saaks seda kasutada."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Failidialoogi ei saanud avada." },
            { TXT_FILE_DIALOG_SELECTION_FAILED, L"Valitud faile ei saanud failidialoogist hankida." },
            { TXT_RECENT_FILE_MISSING,
                L"Faili „%s” pole enam olemas.\n\nKas eemaldada see kirje viimaste failide loendist?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Fail pole enam saadaval:\n\n%s\n\nKas eemaldada see kirje viimaste failide loendist?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Teavet ei saanud lõikelauale kopeerida." },
            { TXT_CURL_PATH_INVALID, L"libcurl.dll-i tee on vigane või liiga pikk." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Teek ei tagastanud MediaInfo versiooni." },
            { TXT_CURL_EXPORTS_MISSING, L"Teek ei ekspordi MediaInfo jaoks nõutavaid curl-funktsioone." },
            { TXT_MEDIALIB_EXPORTS_MISSING, L"Teek ei ekspordi nõutavaid MediaInfo Unicode’i funktsioone." },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Teegi protsess nurjus %s (kood 0x%08lX). Valige ühilduv DLL menüüst Suvandid > Eelistused."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Teegi protsess lakkas vastamast %s. Valige ühilduv DLL menüüst Suvandid > Eelistused."
            },
            { TXT_PREFERENCES_SAVE_FAILED, L"Sätted rakendati, kuid registrisse salvestamine nurjus." },
            { TXT_REPORT_START_FAILED, L"Aruande käivitamiseks pole piisavalt mälu." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Aruande pilti ei saa luua." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Keeletabelit ei saa laadida. Valige kehtiv UTF-8 või "
                L"UTF-16 MediaInfo CSV-fail." },
            { TXT_REPORT_THREAD_START_FAILED, L"Aruande lõime ei saa käivitada." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"Valitud MediaInfo.dll lükkas aruande keele tagasi." },
            { TXT_INVALID_WINDOWS_DLL, L"Valitud fail pole kehtiv Windowsi DLL." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Valitud pildivorming pole toetatud." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Tekstiaruannet ei saa salvestada. Kontrollige sihtkohta ja vaba kettaruumi."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Veebisaiti ei saa vaikebrauseris avada." },
            { TXT_TOO_MANY_FILES, L"Valiti liiga palju faile. Avage väiksemad rühmad." },
            { TXT_LIBRARY_PATH_HINT,
                L"Kasutage selle Windowsiga ühilduvaid 32-bitiseid DLL-e. Tühjad teed lubavad otsingu. "
                L"MediaInfoLib v0.7.60 ei kasuta libcurl.dll-i."
            },
            { TXT_VERSION, L"Versioon" },
            { TXT_WEBSITE_TOOLTIP, L"Ava veebisait %s" },
            { TXT_WAITING_FOR_REPORT, L"Oodatakse praeguse aruande valmimist." },
            { TXT_WEBSITE_LABEL, L"Veebisait:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"MediaInfo aruande kopeerimisel" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"libc&url.dll-i tee:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"MediaInfo.dll-i laadimisel" },
            { TXT_CURL_LOAD_OPERATION, L"libcurl.dll-i laadimisel" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"MediaInfo.dll-i vabastamisel" },
            { TXT_APPLY, L"Rak&enda" },
            { TXT_TAB_NAME_LENGTH, L"Vahekaardi nime &pikkus:" },
            { TXT_TITLE_NAME_LENGTH, L"Pealkir&ja pikkus:" },
            { TXT_RECENT_FILES, L"Hiljutised failid:" },
            { TXT_CLEAR_RECENT_FILES, L"Tü&hjenda" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"Vahekaardi nime pikkus peab olema 8 kuni 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"Pealkirjas oleva nime pikkus peab olema 8 kuni 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Hiljutiste failide loend tühjendati, kuid seda ei saanud registrisse salvestada."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"Sule vahelehe&d topeltklõpsuga" },
            { TXT_CLOSE_TAB_CONTEXT, L"Sule &vaheleht" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"&Luba mitu eksemplari" },
            { TXT_INSTANCE_FORWARD_FAILED, L"Faile ei saanud töötavale MediaInfo eksemplarile edastada." },
            { TXT_LOADING, L"Laadimine…" },
            { TXT_LOADING_FILE, L"Faili laadimine: %s…" },
            { TXT_APPLICATION_HELP,
                L"FAILID JA VAHEKAARDID\r\nWindows x86 omarakendus MediaInfo.dll-i aruannete vaatamiseks. "
                L"Igal failil on oma kirjutuskaitstud vahekaart. Avage Ctrl+O abil või lohistage failid "
                L"aknasse. Uuesti avamine valib olemasoleva vahekaardi. Ctrl+W või keskmine hiirenupp "
                L"sulgeb vahekaardi; Sule kõik sulgeb kõik. Failimenüü mäletab kaheksat viimast faili. "
                L"Vahekaardi päise kontekstimenüüs on käsk Sule vaheleht. Lülitage Eelistustes sisse Sule "
                L"vahelehed topeltklõpsuga, et sulgeda vahekaart selle päisel topeltklõpsates. See valik "
                L"on vaikimisi välja lülitatud ja salvestatakse. Topeltklõps aruande tekstis valib sõna. "
                L"Kolmikklõps valib loogilise rea. Lohistamine laiendab valikut sõnade või ridade "
                L"kaupa.\r\nAva kaust… avab otse valitud kaustas olevad failid, igaüks oma vahekaardil. "
                L"Alamkaustu ei kaasata.\r\nAva ja Ava kaust jagavad viimati valitud kausta. Eksport "
                L"jätab meelde oma kausta, vaikimisi Dokumendid. Täpsem režiim kuvab aruandes "
                L"lisavälju.\r\nTeadaolevad vormingud / Teadaolevad koodekid / Teadaolevad parameetrid — "
                L"MediaInfo.dll.\r\nTäielik analüüs uurib kogu faili ja võib võtta kauem aega. Need "
                L"aruande valikud ja Jälitustase kuuluvad igale vahelehele; muudatus värskendab ainult "
                L"aktiivset vahekaarti. Viimane käsitsi valitud kombinatsioon salvestatakse uute "
                L"vahekaartide ja järgmise käivitamise jaoks. Sobivat vahemällu salvestatud aruannet "
                L"kasutatakse uuesti, kuni fail jääb muutumatuks.\r\nJälitustase: 0 / 5 / 9 / 10.\r\nFail "
                L"> Lehekülje häälestus… avab selle seansi paberi, suuna ja veeriste sätted. Prindi… "
                L"(Ctrl+P) avab süsteemi prindidialoogi; Windows 11 kuvab eelvaate, Windows 10 ja vanemad "
                L"kasutavad klassikalist dialoogi. Ctrl+P prindib olenevalt fookuses olevast aknast "
                L"peaakna aktiivse vahekaardi või Spikri või Teabe teksti. Aruanded kasutavad valitud "
                L"aruandefonti, Spikker süsteemi dialoogifonti ja Teave oma tekstiala fonti. Kui "
                L"vahekaarte pole avatud, kuid Spikker on avatud, jäävad Lehekülje häälestus… ja Prindi… "
                L"kasutatavaks; Prindi… prindib spikri. Spikker kasutab peaakna prindidialoogi; uus "
                L"Ctrl+P Spikris toob sama dialoogi esiplaanile. Pikad read murtakse ja tekst jaotatakse "
                L"lehekülgedeks. Printimine toimub taustal.\r\nLohistage üks või mitu faili aknasse, EXE "
                L"ikoonile või selle otseteele või andke failiteed käsureal. Kui mitu eksemplari pole "
                L"lubatud, avatakse failid juba töötavas aknas.\r\nOlekuriba vasakul pool kuvatakse "
                L"failiteed ja laadimise edenemine, paremal laaditud MediaInfo.dll versioon. Pikad teed "
                L"lühendatakse vastavalt vabale ruumile mõttepunktidega.\r\n\r\nEKSPORT\r\nTXT, BMP, GIF, "
                L"JPEG, PNG, TIFF ja WebP kuvatakse saadavuse järgi. Viimane ekspordikaust ja vorming "
                L"jäetakse meelde.\r\nTXT pakub vorminguid ANSI, UTF-8, BOM-iga UTF-8, BOM-iga UTF-16 BE "
                L"ja BOM-iga UTF-16 LE. Vaikimisi on valitud teine kirje, BOM-ita UTF-8. Aruande kogu "
                L"tekst ja algsed reavahetused säilivad.\r\n\r\nLOO PÄISEFAIL\r\nTööriistad on menüüriba "
                L"neljas menüü. Selle käsk Loo päisefail… avab aruande vahekaartidest sõltumatult ühe "
                L"lähtefaili ja kopeerib selle esimesed 524288 baiti (512 KiB). Lühem fail kopeeritakse "
                L"täielikult; tühi fail annab tühja väljundi. See on tavaline binaarfailide lugemine, "
                L"ilma MediaInfo analüüsita või MediaInfo.dll-i nõudeta. Tööriist jätab aruannete "
                L"vahelehed ja programmi viimaste failide loendi muutmata.\r\n\r\nPärast lugemist algab "
                L"lähtefaili kaustas dialoog Salvesta nimega ja pakub video.mp4 jaoks video.mp4.header: "
                L".header lisatakse kogu algsele nimele. Saate muuta nii nime kui ka sihtkausta. Kummagi "
                L"dialoogi tühistamine ei kirjuta väljundit. Olemasoleva sihtkoha asendamine nõuab "
                L"kinnitust. Allikas jääb muutumatuks; ebaõnnestunud salvestamine säilitab eelmise "
                L"sihtkoha. Avamiseks ja salvestamiseks kasutatakse uusimaid selles Windowsi versioonis "
                L"saadaolevaid süsteemidialooge.\r\n\r\nRakenduse käivitamisel võtab tööriist algse "
                L"sisendkausta Fail > Ava. Kui ühtegi kausta pole salvestatud, valib Windows algse "
                L"asukoha. Pärast sisendfaili valimist jätab tööriist oma kausta meelde ainult kuni "
                L"rakenduse sulgemiseni, isegi kui Salvesta nimega on tühistatud. See ei muuda Ava ja "
                L"Ekspordi kasutatavaid kaustu ega salvesta oma kausta rakenduse seadetesse. Iga Salvesta "
                L"nimega dialoog algab parajasti valitud sisendfaili kaustast, olenemata eelmisest "
                L"salvestussihtkohast.\r\n\r\nEELISTUSED JA KEELED\r\nEelistused (Suvandid > Eelistused, "
                L"Ctrl+G) sisaldavad teekide asukohti, aruande fonti, silumist ja keeli. Liidesel on 36 "
                L"varianti ning alguses järgib see Windowsi. Aruanded kasutavad vaikimisi alati teegi "
                L"algset inglise keelt, sõltumata Windowsist ja liidesest. Seda muudab ainult käsitsi "
                L"valitud aruande keel: inglise keel, 37 tõlget või oma MediaInfo CSV-tabel. OK või "
                L"Rakenda kinnitab muudatused; Loobu tühistab ootel muudatused. Eelistustes saab määrata "
                L"vahekaardi nime piirangu (vaikimisi 80) ja tühjendada hiljutiste failide loendi. Pikad "
                L"nimed säilitavad alguse, lõpu ja laiendi, keskel on mõttepunktid. Tühjenda eemaldab "
                L"hiljutiste failide loendi kohe, isegi kui eelistused suletakse seejärel nupuga "
                L"Loobu.\r\n\r\nPeaakna pealkiri näitab aktiivset faili kujul failinimi — MediaInfo. "
                L"Eelistustes saab pealkirjas oleva nime pikkuseks eraldi määrata 8–255 märki (vaikimisi 40)."
                L" Pikemad nimed lühendatakse sama mõttepunktimärgiga keskel, säilitades faililaiendi. Kui "
                L"avatud vahekaarte pole, on pealkiri MediaInfo.\r\n\r\nTEEGID JA AKNAD\r\nProgramm sisaldab "
                L"MediaInfo versioone 26.10, 21.03 ja "
                L"0.7.60, mida proovitakse uusimast pärast väliseid teeke. Kahel uuemal on sobiv libcurl; "
                L"0.7.60 ei paki seda kunagi lahti. Akna asukoht salvestatakse. Vaikimisi on lubatud "
                L"ainult üks eksemplar ja järgmised käivitused saadavad failid avatud aknasse. "
                L"Eelistustes saab lubada mitu eksemplari. Mitme akna korral taastab salvestatud asukoha "
                L"ainult iga aknatüübi esimene aken; järgmised aknad taastavad ainult suuruse.\r\n\r\n"
                L"Redigeeri > Otsi (Ctrl+F) otsib olenevalt fookuses olevast aknast aktiivselt aruande "
                L"vahekaardilt või Spikri või Teabe tekstialalt. Otsinguaken säilitab viimati valitud "
                L"allika, kuni fookus on selles. F3 kordab otsingut ja Shift+F3 pöörab otsingu suuna "
                L"ümber. Teksti lõppu jõudes jätkub otsing teisest otsast. Suvandid > Reamurdmine kehtib "
                L"ainult aktiivsel vahekaardil; märge vastab valitud vahekaardile. Otsinguakna saab "
                L"minimeerida ja selle laiust muuta; asukoht ning valik Alati pealmine jäetakse meelde. "
                L"Kuni 30 otsinguteksti koos valikutega säilitatakse ainult rakenduse sulgemiseni. Alguse "
                L"ja lõpu valikud kehtivad loogiliste ridade kohta. Regulaaravaldised kasutavad PCRE2 "
                L"süntaksit. Menüü Redigeeri ülejäänud käsud rakenduvad aktiivsele aruande vahekaardile. "
                L"Enter käivitab otsingu; Shift+Enter pöörab valitud suuna ümber. „Tõstutundlik“ eristab "
                L"suur- ja väiketähti; „Otsi tagasisuunas“ otsib teksti alguse suunas. Ajalookirje "
                L"valimine taastab kõik viis otsinguvalikut, sealhulgas regulaaravaldise režiimi oleku; "
                L"„Alati pealmine“ on sõltumatu. „Regulaaravaldis“ keelab valikud „Rida algab“ ja „Rida "
                L"lõpeb“. Kui mõlemad reapiiri valikud on lubatud, piisab vastest ühes piiris. "
                L"„Reamurdmine“ muudab ainult kuvamist."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"WebP-pilti ei saa salvestada. Kontrollige sihtkohta, vaba mälu ja kettaruumi."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Tekstidokument UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Tekstidokument UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Tekstidokument UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Tekstidokument UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Aruannet ei saa selle kodeeringuga salvestada ilma märke kaotamata. Valige teine "
                L"tekstikodeering."
            },
            { TXT_OPEN_FOLDER, L"Ava ka&ust…" },
            { TXT_OPEN_FOLDER_TITLE, L"Ava kaust" },
            { TXT_FOLDER_READ_FAILED, L"Kausta ei saanud lugeda:\n\n%s\n\nWindowsi tõrge %lu." },
            { TXT_ADVANCED_MODE, L"&Täpsem režiim" },
            { TXT_REPORT_DETAIL_REJECTED, L"Valitud MediaInfo.dll lükkas aruande üksikasjade sätte tagasi." },
            { TXT_KNOWN_FORMATS, L"Teadaolevad &vormingud" },
            { TXT_KNOWN_CODECS, L"Teadaolevad &koodekid" },
            { TXT_KNOWN_PARAMETERS, L"Teadaolevad &parameetrid" },
            { TXT_KNOWN_FORMATS_TITLE, L"Teadaolevad vormingud" },
            { TXT_KNOWN_CODECS_TITLE, L"Teadaolevad koodekid" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Teadaolevad parameetrid" },
            { TXT_KNOWN_INFO_FAILED, L"Teek ei tagastanud soovitud teavet." },
            { TXT_FULL_PARSING, L"Täielik ana&lüüs" },
            { TXT_PARSING_REJECTED, L"Valitud MediaInfo.dll lükkas analüüsi sätte tagasi." },
            { TXT_TRACE_LEVEL_0, L"Jälitustase &0" },
            { TXT_TRACE_LEVEL_5, L"Jälitustase &5" },
            { TXT_TRACE_LEVEL_9, L"Jälitustase &9" },
            { TXT_TRACE_LEVEL_10, L"Jälitustase &10" },
            { TXT_PAGE_SETUP, L"&Lehekülje häälestus…" },
            { TXT_PAGE_SETUP_FAILED, L"Lehekülje häälestust ei saanud avada." },
            { TXT_PRINT, L"&Prindi…\tCtrl+P" },
            { TXT_PRINTING, L"Printimine…" },
            { TXT_PRINT_FAILED,
                L"Teksti ei saanud printida. Kontrollige printerit, selle sätteid ja vaba mälu."
            },
            { TXT_TOOLS_MENU, L"Töö&riistad" },
            { TXT_CREATE_HEADER, L"Loo &päisefail…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Loo päisefail - Ava" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Loo päisefail - Salvesta nimega" },
            { TXT_HEADER_FORMAT, L"Päisefail (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Faili päist ei saanud lugeda:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Päisefaili ei saanud salvestada:\n\n%s" },
            { TXT_COPY, L"&Kopeeri" },
            { TXT_COPY_FILE_NAME, L"Kopeeri faili &nimi" },
            { TXT_COPY_FULL_PATH, L"Kopeeri täielik faili&tee" },
            { TXT_LAUNCH_FILE, L"Kä&ivita fail" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"N&äita kaustas" },
            { TXT_EDIT_MENU, L"R&edigeeri" },
            { TXT_WORD_WRAP, L"&Reamurdmine" },
            { TXT_WORD_WRAP_FAILED, L"Reamurdmist ei saanud muuta." },
            { TXT_COPY_SELECTION, L"&Kopeeri\tCtrl+C" },
            { TXT_SELECT_ALL, L"Val&i kõik\tCtrl+A" },
            { TXT_FIND_MENU, L"&Otsi…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Otsi &järgmist\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Otsi &eelmist\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Otsi" },
            { TXT_FIND_WHAT, L"Otsitav &tekst:" },
            { TXT_FIND_NEXT, L"Otsi &järgmist" },
            { TXT_FIND_MATCH_CASE, L"T&õstutundlik" },
            { TXT_FIND_BACKWARD, L"Otsi t&agasisuunas" },
            { TXT_FIND_TOPMOST, L"Alati &pealmine" },
            { TXT_FIND_STARTS_WITH, L"&Rida algab" },
            { TXT_FIND_ENDS_WITH, L"Rida &lõpeb" },
            { TXT_FIND_REGEX, L"Re&gulaaravaldis" },
            { TXT_FIND_NOT_FOUND, L"Määratud teksti ei leitud." },
            { TXT_FIND_FAILED, L"Otsingut ei saanud lõpule viia." },
            { TXT_FIND_REGEX_ERROR, L"Regulaaravaldise viga:\r\n\r\n%s" },
        }
    },
    {
        LANG_GA,
        {
            { TXT_LANGUAGE_NAME, L"Gaeilge" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nSuíomh gréasáin: " },
            { TXT_FILE_OPEN_FAILED, L"Ní féidir %s a oscailt. Seiceáil an chonair agus na ceadanna." },
            { TXT_BROWSE_DLL, L"&Brabhsáil…" },
            { TXT_BROWSE_REPORT, L"Brab&hsáil…" },
            { TXT_CLOSE, L"&Dún" },
            { TXT_CLOSE_TAB, L"&Dún\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"Réa&mhshocrú" },
            { TXT_EXPORT, L"&Easpórtáil…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Comhad" },
            { TXT_REPORT_FONT, L"C&ló na tuairisce:" },
            { TXT_HELP_MENU, L"Ca&bhair" },
            { TXT_HELP, L"&Cabhair\tF1" },
            { TXT_LANGUAGE, L"&Teanga:" },
            { TXT_OPEN_WEBSITE, L"&Oscail sa bhrabhsálaí réamhshocraithe" },
            { TXT_OPEN, L"&Oscail…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Roghanna" },
            { TXT_PREFERENCES_MENU, L"&Roghanna…\tCtrl+G" },
            { TXT_ABOUT, L"&Maidir leis" },
            { TXT_ABOUT_TITLE, L"Maidir le %ls" },
            { TXT_ALL_FILES, L"Gach comhad" },
            { TXT_FONT_BOLD, L"Trom" },
            { TXT_FONT_BOLD_ITALIC, L"Trom + Iodálach" },
            { TXT_BROWSE_CURL, L"B&rabhsáil…" },
            { TXT_CANCEL, L"Cealaigh" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Ní féidir MediaInfo.dll a lódáil (earráid Windows %lu). Úsáid DLL 32 giotán atá "
                L"comhoiriúnach leis an leagan seo de Windows."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Ní féidir libcurl.dll a lódáil (earráid Windows %lu). Roghnaigh leabharlann 32 giotán atá "
                L"comhoiriúnach leis an leagan seo de Windows."
            },
            { TXT_CLOSE_ALL, L"Dún &uile" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Cóipeáil an &seoladh" },
            { TXT_COPY_INFORMATION, L"Cóipeáil an &fhaisnéis" },
            { TXT_DLL_FILES, L"Leabharlanna dinimiciúla" },
            { TXT_EXIT, L"&Scoir\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Leabharlanna leabaithe MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Leabharlanna leabaithe libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Easpórtáil tuairisc" },
            { TXT_FONT_ANTIALIASING, L"&Frithailiasáil cló:" },
            { TXT_GIF_EXPORT_FAILED,
                L"Theip ar easpórtáil GIF. Éilíonn GIF gan chaillteanas 256 dath ar a mhéad."
            },
            { TXT_FONT_ITALIC, L"Iodálach" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED,
                L"Theip ar easpórtáil JPEG. Tá ionchódóir JPEG GDI+ feidhmiúil de dhíth."
            },
            { TXT_LICENSE_UNAVAILABLE, L"Níl an acmhainn cheadúnais ar fáil." },
            { TXT_MEDIA_FILES, L"Comhaid mheán" },
            { TXT_APPLICATION_DESCRIPTION, L"Amharcán faisnéise meán" },
            { TXT_HELP_TITLE, L"MediaInfo — Cabhair" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"Níorbh fhéidir le MediaInfo anailís an chomhaid a thúsú." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"Ní féidir le MediaInfo an comhad seo a oscailt ná a aithint." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"&Conair chuig MediaInfo.dll:" },
            { TXT_MEDIALIB_REQUIRED, L"Níl MediaInfo.dll lódáilte. Roghnaigh é faoi Roghanna > Roghanna." },
            { TXT_MEDIALIB_NOT_LOADED, L"Níl MediaInfo.dll lódáilte." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Níorbh fhéidir MediaInfo.dll comhoiriúnach seachtrach nó leabaithe a lódáil. Roghnaigh é "
                L"faoi Roghanna > Roghanna."
            },
            { TXT_ANTIALIASING_NONE, L"Gan frithailiasáil" },
            { TXT_OK, L"OK" },
            { TXT_OPEN_TITLE, L"Oscail comhaid mheán" },
            { TXT_PLATFORM, L"Sprioc-ardán:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Roghanna" },
            { TXT_READY, L"Réidh" },
            { TXT_FONT_REGULAR, L"Gnáth" },
            { TXT_REPORT_LANGUAGE, L"Tea&nga na tuairisce:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Táblaí teanga tuairiscí" },
            { TXT_SELECT_MEDIALIB, L"Brabhsáil: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Brabhsáil: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH,
                L"Roghnaigh comhad meán atá ann cheana le conair níos giorra ná MAX_PATH."
            },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Roghnaigh comhaid atá ann le conairí níos giorra ná MAX_PATH." },
            { TXT_SELECT_CURL, L"Brabhsáil: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Doiciméad téacs ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"Ní féidir an íomhá BMP a shábháil. Seiceáil an ceann scríbe, an chuimhne shaor agus an "
                L"spás diosca."
            },
            { TXT_LIBRARY_WORKER_START_FAILED,
                L"Ní féidir próiseas na leabharlainne a thosú (earráid Windows %lu)."
            },
            { TXT_REPORT_COPY_FAILED, L"Ní féidir tuairisc MediaInfo a chóipeáil go cuimhne." },
            { TXT_VIEWER_CREATE_FAILED, L"Ní féidir an t-amharcán MediaInfo a chruthú." },
            { TXT_MEDIALIB_PATH_INVALID, L"Tá conair MediaInfo.dll neamhbhailí nó rófhada." },
            { TXT_PNG_EXPORT_FAILED,
                L"Ní féidir an íomhá PNG a shábháil. Seiceáil an ceann scríbe, an chuimhne shaor agus an "
                L"spás diosca."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"Ní féidir an íomhá TIFF a shábháil. Seiceáil an ceann scríbe, an chuimhne shaor agus an "
                L"spás diosca."
            },
            { TXT_COPY_URL_FAILED, L"Níorbh fhéidir an URL a chóipeáil go dtí an ghearrthaisce." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"Tá %s 32 giotán de dhíth ar an amharcán Win32. Roghnaigh leabharlann x86/i386."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Ní féidir an leabharlann leabaithe a scríobh in AppData, sa phróifíl úsáideora, in Program "
                L"Files ná san fhillteán sealadach."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED,
                L"Theip ar dhí-chomhbhrú nó ar sheiceáil CRC na leabharlainne."
            },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Tá acmhainn na leabharlainne leabaithe neamhbhailí." },
            { TXT_CURL_FILENAME_INVALID,
                L"Caithfear libcurl.dll a thabhairt ar an leabharlann ionas gur féidir le MediaInfo í a "
                L"úsáid."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Níorbh fhéidir an dialóg comhad a oscailt." },
            { TXT_FILE_DIALOG_SELECTION_FAILED,
                L"Níorbh fhéidir na comhaid roghnaithe a fháil ón dialóg comhad."
            },
            { TXT_RECENT_FILE_MISSING,
                L"Níl an comhad “%s” ann a thuilleadh.\n\nAn bhfuil fonn ort an iontráil seo a bhaint den "
                L"liosta comhad le déanaí?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Níl an comhad ar fáil a thuilleadh:\n\n%s\n\nAn bhfuil fonn ort an iontráil seo a bhaint "
                L"den liosta comhad le déanaí?"
            },
            { TXT_COPY_INFORMATION_FAILED,
                L"Níorbh fhéidir an fhaisnéis a chóipeáil go dtí an ghearrthaisce."
            },
            { TXT_CURL_PATH_INVALID, L"Tá conair libcurl.dll neamhbhailí nó rófhada." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Níor chuir an leabharlann leagan MediaInfo ar ais." },
            { TXT_CURL_EXPORTS_MISSING,
                L"Ní easpórtálann an leabharlann na feidhmeanna curl a theastaíonn ó MediaInfo."
            },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"Ní easpórtálann an leabharlann na feidhmeanna Unicode riachtanacha de chuid MediaInfo."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Theip ar phróiseas na leabharlainne ag an gcéim seo: %s (cód 0x%08lX). Roghnaigh DLL "
                L"comhoiriúnach faoi Roghanna > Roghanna."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Ní fhreagraíonn próiseas na leabharlainne ag an gcéim seo: %s. Roghnaigh DLL "
                L"comhoiriúnach faoi Roghanna > Roghanna."
            },
            { TXT_PREFERENCES_SAVE_FAILED,
                L"Cuireadh na socruithe i bhfeidhm ach níor sábháladh sa chlárlann iad."
            },
            { TXT_REPORT_START_FAILED, L"Níl dóthain cuimhne ann chun an tuairisc a thosú." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Ní féidir íomhá na tuairisce a chruthú." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Ní féidir an tábla teanga a lódáil. Roghnaigh comhad "
                L"bailí MediaInfo CSV in UTF-8 nó UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"Ní féidir snáithe na tuairisce a thosú." },
            { TXT_REPORT_LANGUAGE_REJECTED,
                L"Dhiúltaigh an MediaInfo.dll roghnaithe do theanga na tuairisce."
            },
            { TXT_INVALID_WINDOWS_DLL, L"Ní DLL bailí Windows é an comhad roghnaithe." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Ní thacaítear leis an bhformáid íomhá roghnaithe." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Ní féidir an tuairisc téacs a shábháil. Seiceáil an ceann scríbe agus an spás saor diosca."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Ní féidir an suíomh a oscailt sa bhrabhsálaí réamhshocraithe." },
            { TXT_TOO_MANY_FILES, L"Roghnaíodh an iomarca comhad. Oscail grúpaí níos lú." },
            { TXT_LIBRARY_PATH_HINT,
                L"Úsáid leabharlanna 32 giotán atá comhoiriúnach le do leagan de Windows. Fág na conairí "
                L"folamh don chuardach uathoibríoch. Ní úsáideann MediaInfoLib v0.7.60 libcurl.dll."
            },
            { TXT_VERSION, L"Leagan" },
            { TXT_WEBSITE_TOOLTIP, L"Oscail an suíomh gréasáin %s" },
            { TXT_WAITING_FOR_REPORT, L"Ag fanacht le deireadh na tuairisce reatha." },
            { TXT_WEBSITE_LABEL, L"Suíomh gréasáin:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"tuairisc MediaInfo á cóipeáil" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"Conair chuig libc&url.dll:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"MediaInfo.dll á lódáil" },
            { TXT_CURL_LOAD_OPERATION, L"libcurl.dll á lódáil" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"MediaInfo.dll á dhílódáil" },
            { TXT_APPLY, L"Cuir &i bhfeidhm" },
            { TXT_TAB_NAME_LENGTH, L"F&ad ainm an chluaisín:" },
            { TXT_TITLE_NAME_LENGTH, L"Fad an t&eidil:" },
            { TXT_RECENT_FILES, L"Comhaid le déanaí:" },
            { TXT_CLEAR_RECENT_FILES, L"&Glan" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"Caithfidh fad ainm an chluaisín a bheith idir 8 agus 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"Caithfidh fad an ainm sa teideal a bheith idir 8 agus 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Glanadh liosta na gcomhad le déanaí, ach níorbh fhéidir é a shábháil sa chlárlann."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"Dún cluaisíní le &déchliceáil" },
            { TXT_CLOSE_TAB_CONTEXT, L"Dún an &cluaisín" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"Ceadaigh &áscanna iolracha" },
            { TXT_INSTANCE_FORWARD_FAILED,
                L"Níorbh fhéidir na comhaid a chur ar aghaidh chuig an ásc de MediaInfo atá ar siúl."
            },
            { TXT_LOADING, L"Á lódáil…" },
            { TXT_LOADING_FILE, L"Comhad á lódáil: %s…" },
            { TXT_APPLICATION_HELP,
                L"COMHAID AGUS CLUAISÍNÍ\r\nAmharcán dúchasach Windows x86 do thuairiscí MediaInfo.dll. "
                L"Tá cluaisín inléite amháin ar leith ag gach comhad. Oscail le Ctrl+O nó tarraing agus "
                L"scaoil. Roghnaíonn athoscailt an cluaisín atá ann cheana. Dúnann Ctrl+W nó cnaipe láir "
                L"na luiche cluaisín; dúnann Dún uile gach cluaisín. Cuimhníonn an roghchlár Comhad ar "
                L"ocht gcomhad le déanaí. Tá Dún an cluaisín i roghchlár comhthéacs cheanntásc an "
                L"chluaisín. Cumasaigh Dún cluaisíní le déchliceáil i Roghanna chun cluaisín a dhúnadh "
                L"trí dhéchliceáil ar a cheanntásc. Tá an rogha múchta de réir réamhshocraithe agus "
                L"sábháiltear í. Roghnaíonn déchliceáil sa téacs tuairisce focal. Roghnaíonn trí "
                L"chliceáil líne loighciúil. Leathnaíonn tarraingt an roghnú de réir focal nó línte.\r\n"
                L"Osclaíonn Oscail fillteán… na comhaid atá go díreach san fhillteán roghnaithe, gach "
                L"ceann ina chluaisín féin. Ní chuirtear fofhillteáin san áireamh.\r\nÚsáideann Oscail "
                L"agus Oscail fillteán an fillteán céanna a roghnaíodh go deireanach. Cuimhníonn "
                L"easpórtáil ar a fillteán féin, Doiciméid de réir réamhshocraithe. Taispeánann an "
                L"tArdmhód réimsí breise sa tuairisc.\r\nFormáidí aitheanta / Cóidecanna aitheanta / "
                L"Paraiméadair aitheanta — MediaInfo.dll.\r\nScrúdaíonn Anailís iomlán an comhad iomlán "
                L"agus féadfaidh sé níos faide a ghlacadh. Baineann na roghanna tuairisce seo agus "
                L"Leibhéal rianaithe le gach cluaisín; ní athnuachann athrú ach an cluaisín gníomhach. "
                L"Déantar an teaglaim dheireanach a roghnaíodh de láimh a shábháil le haghaidh cluaisíní "
                L"nua agus an chéad seoladh eile. Déantar tuairisc chomhoiriúnach i dtaisce a athúsáid "
                L"fad is a fhanann an comhad gan athrú.\r\nLeibhéal rianaithe: 0 / 5 / 9 / 10.\r\n"
                L"Osclaíonn Comhad > Socrú Leathanaigh… socruithe páipéir, treoshuímh agus imeall don "
                L"seisiún reatha. Osclaíonn Priontáil… (Ctrl+P) dialóg phriontála an chórais; "
                L"soláthraíonn Windows 11 réamhamharc, agus coimeádann Windows 10 agus leaganacha níos "
                L"sine an dialóg chlasaiceach. Priontálann Ctrl+P cluaisín gníomhach na príomhfhuinneoige "
                L"nó réimse téacs Cabhair nó Maidir leis, de réir na fuinneoige a bhfuil an fócas aici. "
                L"Úsáideann tuairiscí an cló tuairisce roghnaithe, Cabhair cló dialóige an chórais agus "
                L"Maidir leis cló a réimse téacs féin. Mura bhfuil cluaisíní ar oscailt ach go bhfuil "
                L"Cabhair ar oscailt, fanann Socrú Leathanaigh… agus Priontáil… ar fáil; priontálann "
                L"Priontáil… an chabhair. Úsáideann Cabhair dialóg phriontála na príomhfhuinneoige; "
                L"tugann Ctrl+P arís i gCabhair an dialóg chéanna chun tosaigh. Timfhilltear línte fada "
                L"agus roinntear an téacs ina leathanaigh. Déantar an phriontáil sa chúlra.\r\nTarraing "
                L"comhad amháin nó níos mó isteach san fhuinneog, ar dheilbhín an EXE nó ar a aicearra, "
                L"nó tabhair na conairí ar líne na n-orduithe. Mura gceadaítear níos mó ná ásc amháin, "
                L"osclaítear na comhaid san fhuinneog atá ag rith cheana.\r\nTaispeántar conairí comhad "
                L"agus dul chun cinn an luchtaithe ar thaobh clé an bharra stádais, agus leagan an "
                L"MediaInfo.dll atá luchtaithe ar dheis. Giorraítear conairí fada le comhartha focalbhá "
                L"de réir an spáis atá ar fáil.\r\n\r\nEASPÓRTÁIL\r\nTXT, BMP, GIF, JPEG, PNG, TIFF agus "
                L"WebP nuair atá siad ar fáil. Cuimhnítear ar an bhfillteán agus ar an bhformáid "
                L"easpórtála deireanach.\r\nCuireann TXT ANSI, UTF-8, UTF-8 le BOM, UTF-16 BE le BOM agus "
                L"UTF-16 LE le BOM ar fáil. Is é an dara rogha, UTF-8 gan BOM, an réamhshocrú. "
                L"Caomhnaítear téacs iomlán na tuairisce agus a chríocha líne bunaidh.\r\n\r\nCRUTHAIGH "
                L"COMHAD CEANNTÁISC\r\nIs é Uirlisí an ceathrú roghchlár ar an mbarra roghchláir. "
                L"Osclaíonn an t-ordú Cruthaigh Comhad Ceanntáisc… comhad foinse amháin go neamhspleách "
                L"ar na cluaisíní tuairisce agus cóipeann sé a chéad 524288 beart (512 KiB). Déantar "
                L"comhad níos giorra a chóipeáil ina iomláine; táirgeann comhad folamh aschur folamh. Is "
                L"gnáthléamh comhaid dhénártha é seo, gan anailís MediaInfo ná gá le MediaInfo.dll. "
                L"Fágann an uirlis cluaisíní tuairisce agus liosta na gcomhad is déanaí gan athrú.\r\n\r\n"
                L"Tar éis é a léamh, tosaíonn an dialóg Sábháil Mar i bhfillteán an chomhaid foinse agus "
                L"molann sé video.mp4.header le haghaidh video.mp4: tá .header i gceangal leis an ainm "
                L"bunaidh iomlán. Is féidir leat an t-ainm agus an fillteán ceann scríbe a athrú. Ní "
                L"scríobhtar aon aschur má chuirtear ceachtar den dá dialóg ar ceal. Teastaíonn deimhniú "
                L"chun ceann scríbe a athsholáthar. Fanann an fhoinse gan athrú; caomhnaíonn sábháil "
                L"theip an ceann scríbe roimhe sin. Úsáidtear na dialóga córais is nuaí atá ar fáil sa "
                L"leagan sin de Windows chun comhaid a oscailt agus a shábháil.\r\n\r\nNuair a thosaíonn "
                L"an feidhmchlár, úsáideann an uirlis an fillteán tosaigh céanna le Comhad > Oscail. Mura "
                L"bhfuil fillteán sábháilte, roghnaíonn Windows an suíomh tosaigh. Tar éis comhad "
                L"ionchuir a roghnú, cuimhníonn an uirlis ar a fillteán féin go dtí go ndúntar an "
                L"feidhmchlár, fiú má chuirtear Sábháil Mar ar ceal. Ní athraíonn sí fillteáin Oscail ná "
                L"Easpórtáil agus ní shábhálann sí a fillteán féin i socruithe an fheidhmchláir. "
                L"Osclaítear gach dialóg Sábháil Mar i bhfillteán an chomhaid ionchuir reatha, beag beann "
                L"ar an gceann scríbe sábhála roimhe seo.\r\n\r\nROGHANNA AGUS TEANGACHA\r\nTá conairí "
                L"leabharlainne, cló na tuairisce, frithailiasáil agus teangacha i Roghanna (Roghanna > "
                L"Roghanna, Ctrl+G). Tá 36 leagan den chomhéadan ann agus leanann sé Windows ar dtús. "
                L"Úsáideann tuairiscí bun-Bhéarla na leabharlainne i gcónaí mar réamhshocrú, neamhspleách "
                L"ar Windows agus ar an gcomhéadan. Ní athraíonn é sin ach rogha láimhe: Béarla, 37 "
                L"aistriúchán nó tábla CSV MediaInfo saincheaptha. Deimhníonn OK nó Cuir i bhfeidhm na "
                L"hathruithe; caitheann Cealaigh na hathruithe ar feitheamh amach. Sna Roghanna, is "
                L"féidir teorainn a chur le fad ainm an chluaisín (80 de réir réamhshocraithe) agus "
                L"liosta na gcomhad le déanaí a ghlanadh. Coinnítear tús, deireadh agus iarmhír "
                L"ainmneacha fada le comhartha focalbhá sa lár. Baineann Glan liosta na gcomhad le déanaí "
                L"láithreach, fiú má dhúntar Roghanna le Cealaigh ina dhiaidh sin.\r\n\r\nTaispeánann teideal"
                L" na príomhfhuinneoige an comhad gníomhach san fhoirm ainm comhaid — MediaInfo. Sna "
                L"sainroghanna is féidir fad an ainm sa teideal a shocrú ar leithligh idir 8 agus 255 "
                L"carachtar (40 de réir réamhshocraithe). Giorraítear ainmneacha níos faide leis an "
                L"gcomhartha céanna trí phonc sa lár agus coinnítear an iarmhír. Mura bhfuil cluaisín ar "
                L"oscailt, is é MediaInfo an teideal.\r\n\r\nLEABHARLANNA "
                L"AGUS FUINNEOGA\r\nTá MediaInfo 26.10, 21.03 agus 0.7.60 sa chlár, á dtriail ón gceann "
                L"is nuaí tar éis leabharlanna seachtracha. Tá libcurl oiriúnach ag an dá leagan is nuaí; "
                L"ní bhaineann 0.7.60 libcurl amach riamh. Sábháiltear suíomh na fuinneoige. De réir "
                L"réamhshocraithe, ní cheadaítear ach ásc amháin agus seolann seoltaí eile na comhaid "
                L"chuig an bhfuinneog oscailte. Is féidir áscanna iolracha a cheadú sna socruithe. Má tá "
                L"roinnt fuinneog ann, ní athchóirítear an suíomh sábháilte ach don chéad fhuinneog de "
                L"gach cineál fuinneoige; ní athchóirítear ach an méid do na fuinneoga eile.\r\n\r\n"
                L"Déanann Eagar > Aimsigh (Ctrl+F) cuardach sa chluaisín tuairisce gníomhach nó i réimse "
                L"téacs Cabhair nó Maidir leis, de réir na fuinneoige a bhfuil an fócas aici. Coinníonn "
                L"an fhuinneog chuardaigh an fhoinse dheireanach a roghnaíodh agus an fócas aici. F3 an "
                L"cuardach arís agus aisiompaíonn Shift+F3 an treo. Ag ceann an téacs, leanann an "
                L"cuardach ón gceann eile. Ní bhaineann Roghanna > Timfhilleadh Focal ach leis an "
                L"gcluaisín gníomhach; leanann an tic an cluaisín roghnaithe. Is féidir an fhuinneog "
                L"chuardaigh a íoslaghdú agus a leithead a athrú; coinnítear a suíomh agus an socrú Ar "
                L"barr i gcónaí. Ní choinnítear suas le 30 téacs cuardaigh agus a gcuid roghanna ach go "
                L"dtí go ndúntar an feidhmchlár. Baineann na roghanna tosaigh agus deiridh le línte "
                L"loighciúla. Úsáideann sloinn rialta comhréir PCRE2. Baineann na horduithe eile sa "
                L"roghchlár Eagar leis an gcluaisín tuairisce gníomhach. Tosaíonn Enter cuardach; "
                L"aisiompaíonn Shift+Enter an treo roghnaithe. Déanann “Meaitseáil an cás” idirdhealú "
                L"idir cás uachtair agus cás íochtair; cuardaíonn “Cuardaigh ar gcúl” i dtreo thús an "
                L"téacs. Athbhunaíonn roghnú iontrála staire na cúig rogha cuardaigh uile, lena "
                L"n-áirítear staid mhód na slonn rialta; tá “Ar barr i gcónaí” neamhspleách. "
                L"Díchumasaíonn “Slonn rialta” na roghanna “Tosaíonn an líne le” agus “Críochnaíonn an "
                L"líne le”. Má tá an dá rogha imill líne cumasaithe, is leor meaitseáil ag ceachtar "
                L"imeall. Ní athraíonn “Timfhilleadh Focal” ach an taispeáint."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"Ní féidir an íomhá WebP a shábháil. Seiceáil an ceann scríbe, an chuimhne shaor agus an "
                L"spás diosca."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Doiciméad téacs UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Doiciméad téacs UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Doiciméad téacs UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Doiciméad téacs UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Ní féidir an tuairisc a shábháil sa chódú seo gan carachtair a chailleadh. Roghnaigh códú "
                L"téacs eile."
            },
            { TXT_OPEN_FOLDER, L"Oscail &fillteán…" },
            { TXT_OPEN_FOLDER_TITLE, L"Oscail fillteán" },
            { TXT_FOLDER_READ_FAILED, L"Níorbh fhéidir an fillteán a léamh:\n\n%s\n\nEarráid Windows %lu." },
            { TXT_ADVANCED_MODE, L"&Ardmhód" },
            { TXT_REPORT_DETAIL_REJECTED,
                L"Dhiúltaigh an MediaInfo.dll roghnaithe do shocrú sonraí na tuairisce."
            },
            { TXT_KNOWN_FORMATS, L"&Formáidí aitheanta" },
            { TXT_KNOWN_CODECS, L"Cóid&ecanna aitheanta" },
            { TXT_KNOWN_PARAMETERS, L"&Paraiméadair aitheanta" },
            { TXT_KNOWN_FORMATS_TITLE, L"Formáidí aitheanta" },
            { TXT_KNOWN_CODECS_TITLE, L"Cóidecanna aitheanta" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Paraiméadair aitheanta" },
            { TXT_KNOWN_INFO_FAILED, L"Níor sheol an leabharlann an fhaisnéis iarrtha ar ais." },
            { TXT_FULL_PARSING, L"Anailís io&mlán" },
            { TXT_PARSING_REJECTED, L"Dhiúltaigh an MediaInfo.dll roghnaithe don socrú anailíse." },
            { TXT_TRACE_LEVEL_0, L"Leibhéal rianaithe &0" },
            { TXT_TRACE_LEVEL_5, L"Leibhéal rianaithe &5" },
            { TXT_TRACE_LEVEL_9, L"Leibhéal rianaithe &9" },
            { TXT_TRACE_LEVEL_10, L"Leibhéal rianaithe &10" },
            { TXT_PAGE_SETUP, L"So&crú Leathanaigh…" },
            { TXT_PAGE_SETUP_FAILED, L"Níorbh fhéidir socrú an leathanaigh a oscailt." },
            { TXT_PRINT, L"&Priontáil…\tCtrl+P" },
            { TXT_PRINTING, L"Á phriontáil…" },
            { TXT_PRINT_FAILED,
                L"Níorbh fhéidir an téacs a phriontáil. Seiceáil an printéir, a shocruithe agus an "
                L"chuimhne atá ar fáil."
            },
            { TXT_TOOLS_MENU, L"&Uirlisí" },
            { TXT_CREATE_HEADER, L"&Cruthaigh Comhad Ceanntáisc…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Cruthaigh Comhad Ceanntáisc - Oscail" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Cruthaigh Comhad Ceanntáisc - Sábháil Mar" },
            { TXT_HEADER_FORMAT, L"Comhad Ceanntáisc (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Níorbh fhéidir ceanntásc an chomhaid a léamh:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Níorbh fhéidir an comhad ceanntáisc a shábháil:\n\n%s" },
            { TXT_COPY, L"&Cóipeáil" },
            { TXT_COPY_FILE_NAME, L"Có&ipeáil ainm an chomhaid" },
            { TXT_COPY_FULL_PATH, L"Cóipeáil an chonair i&omlán" },
            { TXT_LAUNCH_FILE, L"Seo&l an comhad" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"&Taispeáin san fhillteán" },
            { TXT_EDIT_MENU, L"&Eagar" },
            { TXT_WORD_WRAP, L"&Timfhilleadh Focal" },
            { TXT_WORD_WRAP_FAILED, L"Níorbh fhéidir timfhilleadh focal a athrú." },
            { TXT_COPY_SELECTION, L"&Cóipeáil\tCtrl+C" },
            { TXT_SELECT_ALL, L"Roghnaigh &Uile\tCtrl+A" },
            { TXT_FIND_MENU, L"&Aimsigh…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Aimsigh an Chéad Cheann &Eile\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Aimsigh an Ceann &Roimhe Seo\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Aimsigh" },
            { TXT_FIND_WHAT, L"Téacs le &haimsiú:" },
            { TXT_FIND_NEXT, L"Aimsigh an &Chéad Cheann Eile" },
            { TXT_FIND_MATCH_CASE, L"Meaitseáil an cá&s" },
            { TXT_FIND_BACKWARD, L"Cuardaigh ar &gcúl" },
            { TXT_FIND_TOPMOST, L"Ar &barr i gcónaí" },
            { TXT_FIND_STARTS_WITH, L"&Tosaíonn an líne le" },
            { TXT_FIND_ENDS_WITH, L"Críochnaíonn an líne &le" },
            { TXT_FIND_REGEX, L"Slonn &rialta" },
            { TXT_FIND_NOT_FOUND, L"Níor aimsíodh an téacs sonraithe." },
            { TXT_FIND_FAILED, L"Níorbh fhéidir an cuardach a chríochnú." },
            { TXT_FIND_REGEX_ERROR, L"Earráid sa slonn rialta:\r\n\r\n%s" },
        }
    },
    {
        LANG_LT,
        {
            { TXT_LANGUAGE_NAME, L"Lietuvių" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nSvetainė: " },
            { TXT_FILE_OPEN_FAILED, L"Nepavyko atidaryti %s. Patikrinkite kelią ir teises." },
            { TXT_BROWSE_DLL, L"&Naršyti…" },
            { TXT_BROWSE_REPORT, L"Na&ršyti…" },
            { TXT_CLOSE, L"&Uždaryti" },
            { TXT_CLOSE_TAB, L"&Uždaryti\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"Nu&matytasis" },
            { TXT_EXPORT, L"&Eksportuoti…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Failas" },
            { TXT_REPORT_FONT, L"Ataskaitos &šriftas:" },
            { TXT_HELP_MENU, L"&Žinynas" },
            { TXT_HELP, L"&Žinynas\tF1" },
            { TXT_LANGUAGE, L"Ka&lba:" },
            { TXT_OPEN_WEBSITE, L"&Atidaryti numatytojoje naršyklėje" },
            { TXT_OPEN, L"&Atidaryti…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Parinktys" },
            { TXT_PREFERENCES_MENU, L"&Nuostatos…\tCtrl+G" },
            { TXT_ABOUT, L"&Apie" },
            { TXT_ABOUT_TITLE, L"Apie %ls" },
            { TXT_ALL_FILES, L"Visi failai" },
            { TXT_FONT_BOLD, L"Paryškintasis" },
            { TXT_FONT_BOLD_ITALIC, L"Paryškintasis + Kursyvas" },
            { TXT_BROWSE_CURL, L"N&aršyti…" },
            { TXT_CANCEL, L"Atšaukti" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Nepavyko įkelti MediaInfo.dll (Windows klaida %lu). Naudokite su šia Windows versija "
                L"suderinamą 32 bitų DLL."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Nepavyko įkelti libcurl.dll (Windows klaida %lu). Pasirinkite su šia Windows versija "
                L"suderinamą 32 bitų biblioteką."
            },
            { TXT_CLOSE_ALL, L"Uždaryti &viską" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Kopijuoti a&dresą" },
            { TXT_COPY_INFORMATION, L"Kopijuoti &informaciją" },
            { TXT_DLL_FILES, L"Dinaminės bibliotekos" },
            { TXT_EXIT, L"&Išeiti\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Įterptos bibliotekos MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Įterptos bibliotekos libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Eksportuoti ataskaitą" },
            { TXT_FONT_ANTIALIASING, L"Šrifto &glodinimas:" },
            { TXT_GIF_EXPORT_FAILED, L"GIF eksportas nepavyko. GIF be nuostolių leidžia iki 256 spalvų." },
            { TXT_FONT_ITALIC, L"Kursyvas" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED,
                L"JPEG eksportas nepavyko. Reikalinga veikianti GDI+ JPEG kodavimo priemonė."
            },
            { TXT_LICENSE_UNAVAILABLE, L"Licencijos išteklius nepasiekiamas." },
            { TXT_MEDIA_FILES, L"Medijos failai" },
            { TXT_APPLICATION_DESCRIPTION, L"Medijos informacijos peržiūros programa" },
            { TXT_HELP_TITLE, L"MediaInfo — Žinynas" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo nepavyko inicijuoti failo analizės." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo negali atidaryti ar atpažinti šio failo." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"MediaInfo.dll &kelias:" },
            { TXT_MEDIALIB_REQUIRED, L"MediaInfo.dll neįkelta. Pasirinkite ją per Parinktys > Nuostatos." },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll neįkelta." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Nepavyko įkelti suderinamos išorinės ar įterptos MediaInfo.dll. Pasirinkite ją per "
                L"Parinktys > Nuostatos."
            },
            { TXT_ANTIALIASING_NONE, L"Nėra" },
            { TXT_OK, L"Gerai" },
            { TXT_OPEN_TITLE, L"Atidaryti medijos failus" },
            { TXT_PLATFORM, L"Tikslinė platforma:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Nuostatos" },
            { TXT_READY, L"Parengta" },
            { TXT_FONT_REGULAR, L"Įprastas" },
            { TXT_REPORT_LANGUAGE, L"A&taskaitos kalba:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Ataskaitų kalbų lentelės" },
            { TXT_SELECT_MEDIALIB, L"Naršyti: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Naršyti: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH,
                L"Pasirinkite esamą medijos failą, kurio kelias trumpesnis nei MAX_PATH."
            },
            { TXT_SELECTED_PATHS_TOO_LONG,
                L"Pasirinkite esamus failus, kurių keliai trumpesni nei MAX_PATH."
            },
            { TXT_SELECT_CURL, L"Naršyti: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Tekstinis dokumentas ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"Nepavyko įrašyti BMP vaizdo. Patikrinkite paskirties vietą, laisvą atmintį ir disko vietą."
            },
            { TXT_LIBRARY_WORKER_START_FAILED,
                L"Bibliotekos proceso paleisti nepavyko (Windows klaida %lu)."
            },
            { TXT_REPORT_COPY_FAILED, L"Nepavyko nukopijuoti MediaInfo ataskaitos į atmintį." },
            { TXT_VIEWER_CREATE_FAILED, L"Nepavyko sukurti MediaInfo peržiūros programos." },
            { TXT_MEDIALIB_PATH_INVALID, L"MediaInfo.dll kelias netinkamas arba per ilgas." },
            { TXT_PNG_EXPORT_FAILED,
                L"Nepavyko įrašyti PNG vaizdo. Patikrinkite paskirties vietą, laisvą atmintį ir disko vietą."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"Nepavyko įrašyti TIFF vaizdo. Patikrinkite paskirties vietą, laisvą atmintį ir disko vietą."
            },
            { TXT_COPY_URL_FAILED, L"Nepavyko nukopijuoti URL į iškarpinę." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"Win32 peržiūros programai reikia 32 bitų %s. Pasirinkite x86/i386 biblioteką."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Nepavyko įrašyti įterptos bibliotekos į AppData, naudotojo profilį, Program Files ar "
                L"laikinąjį aplanką."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED, L"Bibliotekos išskleidimas arba CRC patikra nepavyko." },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Įterptos bibliotekos išteklius netinkamas." },
            { TXT_CURL_FILENAME_INVALID,
                L"Biblioteka turi vadintis libcurl.dll, kad MediaInfo galėtų ją naudoti."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Nepavyko atidaryti failų dialogo." },
            { TXT_FILE_DIALOG_SELECTION_FAILED, L"Nepavyko gauti pasirinktų failų iš failų dialogo." },
            { TXT_RECENT_FILE_MISSING,
                L"Failo „%s“ nebėra.\n\nAr pašalinti šį įrašą iš paskiausių failų sąrašo?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Failas nebepasiekiamas:\n\n%s\n\nAr pašalinti šį įrašą iš paskiausių failų sąrašo?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Nepavyko nukopijuoti informacijos į iškarpinę." },
            { TXT_CURL_PATH_INVALID, L"libcurl.dll kelias netinkamas arba per ilgas." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Biblioteka nepateikė MediaInfo versijos." },
            { TXT_CURL_EXPORTS_MISSING, L"Biblioteka neeksportuoja MediaInfo reikalingų curl funkcijų." },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"Biblioteka neeksportuoja reikalingų MediaInfo Unicode funkcijų."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Bibliotekos procesas nutrūko vykdant %s (kodas 0x%08lX). Pasirinkite suderinamą DLL per "
                L"Parinktys > Nuostatos."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Bibliotekos procesas nebeatsako vykdant %s. Pasirinkite suderinamą DLL per Parinktys > "
                L"Nuostatos."
            },
            { TXT_PREFERENCES_SAVE_FAILED, L"Nuostatos pritaikytos, bet jų nepavyko įrašyti į registrą." },
            { TXT_REPORT_START_FAILED, L"Ataskaitai paleisti nepakanka atminties." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Nepavyko sukurti ataskaitos vaizdo." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Nepavyko įkelti kalbos lentelės. Pasirinkite tinkamą "
                L"UTF-8 arba UTF-16 MediaInfo CSV failą." },
            { TXT_REPORT_THREAD_START_FAILED, L"Nepavyko paleisti ataskaitos gijos." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"Pasirinkta MediaInfo.dll atmetė ataskaitos kalbą." },
            { TXT_INVALID_WINDOWS_DLL, L"Pasirinktas failas nėra tinkama Windows DLL." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Pasirinktas vaizdo formatas nepalaikomas." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Nepavyko įrašyti tekstinės ataskaitos. Patikrinkite paskirties vietą ir laisvą disko vietą."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Nepavyko atidaryti svetainės numatytojoje naršyklėje." },
            { TXT_TOO_MANY_FILES, L"Pasirinkta per daug failų. Atverkite mažesnėmis grupėmis." },
            { TXT_LIBRARY_PATH_HINT,
                L"Naudokite su savo Windows versija suderinamas 32 bitų bibliotekas. Palikite kelius "
                L"tuščius, kad būtų ieškoma automatiškai. MediaInfoLib v0.7.60 nenaudoja libcurl.dll."
            },
            { TXT_VERSION, L"Versija" },
            { TXT_WEBSITE_TOOLTIP, L"Atidaryti svetainę %s" },
            { TXT_WAITING_FOR_REPORT, L"Laukiama dabartinės ataskaitos pabaigos." },
            { TXT_WEBSITE_LABEL, L"Svetainė:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"MediaInfo ataskaitos kopijavimą" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"libc&url.dll kelias:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"MediaInfo.dll įkėlimą" },
            { TXT_CURL_LOAD_OPERATION, L"libcurl.dll įkėlimą" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"MediaInfo.dll atlaisvinimą" },
            { TXT_APPLY, L"Taik&yti" },
            { TXT_TAB_NAME_LENGTH, L"Skirtuko pavadinimo &ilgis:" },
            { TXT_TITLE_NAME_LENGTH, L"Antraštė&s ilgis:" },
            { TXT_RECENT_FILES, L"Paskutiniai failai:" },
            { TXT_CLEAR_RECENT_FILES, L"Iš&valyti" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"Skirtuko pavadinimo ilgis turi būti nuo 8 iki 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"Pavadinimo ilgis antraštėje turi būti nuo 8 iki 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Paskutinių failų sąrašas išvalytas, bet jo nepavyko įrašyti į registrą."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"Uždaryti skirtukus &dukart spustelėjus" },
            { TXT_CLOSE_TAB_CONTEXT, L"Uždaryti &skirtuką" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"L&eisti kelis egzempliorius" },
            { TXT_INSTANCE_FORWARD_FAILED, L"Nepavyko perduoti failų veikiančiam MediaInfo egzemplioriui." },
            { TXT_LOADING, L"Įkeliama…" },
            { TXT_LOADING_FILE, L"Įkeliamas failas %s…" },
            { TXT_APPLICATION_HELP,
                L"FAILAI IR SKIRTUKAI\r\nSavoji Windows x86 peržiūros programa MediaInfo.dll ataskaitoms. "
                L"Kiekvienas failas turi atskirą tik skaitomą skirtuką. Atverkite naudodami Ctrl+O arba "
                L"vilkdami. Atvėrus pakartotinai pasirenkamas esamas skirtukas. Ctrl+W arba vidurinis "
                L"pelės mygtukas užveria skirtuką; Uždaryti viską užveria visas. Failo meniu įsimena "
                L"aštuonis paskutinius failus. Skirtuko antraštės kontekstiniame meniu yra Uždaryti "
                L"skirtuką. Nuostatose įjunkite Uždaryti skirtukus dukart spustelėjus, jei norite "
                L"uždaryti skirtuką dukart spustelėdami jo antraštę. Parinktis iš pradžių išjungta, jos "
                L"būsena įrašoma. Dukart spustelėjus ataskaitos tekstą pasirenkamas žodis. Triskart "
                L"spustelėjus pasirenkama loginė eilutė. Velkant žymėjimas plečiamas žodžiais arba "
                L"eilutėmis.\r\nAtidaryti aplanką… atveria tiesiogiai pasirinktame aplanke esančius "
                L"failus, kiekvieną atskirame skirtuke. Poaplankiai neįtraukiami.\r\nAtidaryti ir "
                L"Atidaryti aplanką naudoja bendrą paskutinį pasirinktą aplanką. Eksportas įsimena "
                L"atskirą aplanką, numatytasis yra Dokumentai. Išplėstinis režimas rodo papildomus "
                L"ataskaitos laukus.\r\nŽinomi formatai / Žinomi kodekai / Žinomi parametrai — "
                L"MediaInfo.dll.\r\nIšsami analizė patikrina visą failą ir gali užtrukti ilgiau. Šios "
                L"ataskaitos parinktys ir Sekimo lygis priklauso kiekvienam skirtukui; pakeitimas "
                L"atnaujina tik aktyvų skirtuką. Paskutinis rankiniu būdu pasirinktas derinys išsaugomas "
                L"naujiems skirtukams ir kitam paleidimui. Atitinkama talpykloje saugoma ataskaita "
                L"naudojama pakartotinai, kol failas lieka nepakitęs.\r\nSekimo lygis: 0 / 5 / 9 / 10.\r\n"
                L"Failas > Puslapio sąranka… atveria dabartinio seanso popieriaus, padėties ir paraščių "
                L"nuostatas. Spausdinti… (Ctrl+P) atveria sistemos spausdinimo dialogą; Windows 11 rodo "
                L"peržiūrą, o Windows 10 ir senesnės versijos palieka įprastą dialogą. Ctrl+P spausdina "
                L"pagrindinio lango aktyvų skirtuką arba Žinyno ar Apie teksto sritį, atsižvelgiant į "
                L"tai, kuris langas aktyvus. Ataskaitos naudoja pasirinktą ataskaitos šriftą, Žinynas "
                L"sistemos dialogų šriftą, o Apie savo teksto srities šriftą. Jei nėra atvertų skirtukų, "
                L"bet Žinynas atvertas, Puslapio sąranka… ir Spausdinti… lieka pasiekiami; Spausdinti… "
                L"spausdina žinyną. Žinynas naudoja pagrindinio lango spausdinimo dialogą; dar kartą "
                L"paspaudus Ctrl+P Žinyne tas pats dialogas iškeliamas į priekį. Ilgos eilutės keliamos, "
                L"o tekstas padalijamas į puslapius. Spausdinama fone.\r\nVilkite vieną ar kelis failus į "
                L"langą, ant EXE piktogramos ar jos nuorodos arba perduokite jų kelius komandinėje "
                L"eilutėje. Jei keli egzemplioriai neleidžiami, failai atidaromi jau veikiančiame "
                L"lange.\r\nKairėje būsenos juostos pusėje rodomi failų keliai ir įkėlimo eiga, dešinėje "
                L"– įkeltos MediaInfo.dll versija. Ilgi keliai trumpinami daugtaškiu pagal turimą "
                L"vietą.\r\n\r\nEKSPORTAS\r\nTXT, BMP, GIF, JPEG, PNG, TIFF ir WebP rodomi pagal "
                L"prieinamumą. Įsimenamas paskutinis eksporto aplankas ir formatas.\r\nTXT siūlo ANSI, "
                L"UTF-8, UTF-8 su BOM, UTF-16 BE su BOM ir UTF-16 LE su BOM. Numatytasis yra antrasis "
                L"įrašas, UTF-8 be BOM. Išsaugomas visas ataskaitos tekstas ir originalios eilučių "
                L"pabaigos.\r\n\r\nSUKURTI ANTRAŠTĖS FAILĄ\r\nĮrankiai yra ketvirtasis meniu juostos "
                L"meniu. Jo komanda Sukurti antraštės failą… atidaro vieną šaltinio failą nepriklausomai "
                L"nuo ataskaitos skirtukų ir nukopijuoja pirmuosius 524288 baitus (512 KiB). Trumpesnis "
                L"failas nukopijuojamas visas; tuščias failas sukuria tuščią išvestį. Tai įprastas "
                L"dvejetainių failų skaitymas be MediaInfo analizės arba MediaInfo.dll reikalavimo. "
                L"Įrankis nepakeičia ataskaitų skirtukų ir peržiūros priemonės naujausių failų "
                L"sąrašo.\r\n\r\nPerskaičius, šaltinio failo aplanke prasideda dialogo langas Įrašyti "
                L"kaip ir siūlomas video.mp4.header, skirtas video.mp4: .header pridedamas prie viso "
                L"pradinio pavadinimo. Galite pakeisti pavadinimą ir paskirties aplanką. Atšaukus bet "
                L"kurį dialogo langą, išvestis nebus rašoma. Norint pakeisti esamą paskirties vietą, "
                L"reikia patvirtinimo. Šaltinis lieka nepakitęs; nepavykęs išsaugojimas išsaugo ankstesnę "
                L"paskirties vietą. Atidarant ir įrašant naudojami naujausi toje Windows versijoje "
                L"prieinami sistemos dialogo langai.\r\n\r\nPaleidus programą, įrankis paima pradinį "
                L"įvesties aplanką iš Failas > Atidaryti. Jei nebuvo išsaugotas joks aplankas, Windows "
                L"pasirenka pradinę vietą. Pasirinkus įvesties failą, įrankis atsimena savo aplanką tik "
                L"tol, kol programa išjungiama, net jei atšaukta Įrašyti kaip. Jis nekeičia Atidaryti ir "
                L"Eksportuoti naudojamų aplankų ir neišsaugo savo aplanko programos nustatymuose. "
                L"Kiekvienas dialogo langas Įrašyti kaip prasideda šiuo metu pasirinkto įvesties failo "
                L"aplanke, neatsižvelgiant į ankstesnę įrašymo vietą.\r\n\r\nNUOSTATOS IR KALBOS\r\n"
                L"Nuostatose (Parinktys > Nuostatos, Ctrl+G) yra bibliotekų keliai, ataskaitos šriftas, "
                L"glodinimas ir kalbos. Sąsaja turi 36 variantus ir iš pradžių laikosi Windows kalbos. "
                L"Ataskaitoms visada numatyta originali bibliotekos anglų kalba, nepriklausomai nuo "
                L"Windows ir sąsajos. Tai pakeičia tik rankinis pasirinkimas: anglų kalba, 37 vertimai "
                L"arba savas MediaInfo CSV žodynas. Gerai arba Taikyti patvirtina pakeitimus; Atšaukti "
                L"atmeta laukiančius pakeitimus. Nuostatose galima riboti skirtukų pavadinimus (numatyta "
                L"80) ir išvalyti paskutinių failų sąrašą. Ilgi pavadinimai išlaiko pradžią, pabaigą ir "
                L"plėtinį, o viduryje įterpiamas daugtaškis. Išvalyti iš karto pašalina paskutinių failų "
                L"sąrašą, net jei nuostatos vėliau uždaromos mygtuku Atšaukti.\r\n\r\nPagrindinio lango "
                L"antraštėje aktyvus failas rodomas formatu failo pavadinimas — MediaInfo. Nuostatose galima "
                L"atskirai nustatyti pavadinimo ilgį antraštėje nuo 8 iki 255 simbolių (numatyta 40). Ilgesni"
                L" pavadinimai trumpinami tuo pačiu daugtaškiu viduryje, išsaugant plėtinį. Kai nėra atvertų "
                L"skirtukų, antraštė yra MediaInfo.\r\n\r\nBIBLIOTEKOS IR "
                L"LANGAI\r\nProgramoje yra MediaInfo 26.10, 21.03 ir 0.7.60, tikrinamos nuo naujausios po "
                L"išorinių bibliotekų. Dvi naujesnės turi atitinkamas libcurl bibliotekas; 0.7.60 libcurl "
                L"niekada neišpakuoja. Lango padėtis išsaugoma. Pagal numatytąsias nuostatas leidžiamas "
                L"tik vienas egzempliorius, o vėlesni paleidimai perduoda failus atvertam langui. "
                L"Nuostatose galima leisti kelis egzempliorius. Kai langų yra keli, išsaugota vieta "
                L"atkuriama tik pirmajam kiekvieno lango tipo langui; kiti langai atkuria tik "
                L"dydį.\r\n\r\nRedaguoti > Rasti (Ctrl+F) ieško aktyviame ataskaitos skirtuke arba Žinyno "
                L"ar Apie teksto srityje, atsižvelgiant į tai, kuris langas aktyvus. Paieškos langas "
                L"išlaiko paskutinį pasirinktą šaltinį, kol pats yra aktyvus. F3 kartoja paiešką, o "
                L"Shift+F3 pakeičia jos kryptį. Pasiekus teksto galą, paieška tęsiama nuo kito galo. "
                L"Parinktys > Teksto eilučių kėlimas taikomas tik aktyviam skirtukui; varnelė atitinka "
                L"pasirinktą skirtuką. Paieškos langą galima sumažinti ir keisti jo plotį; jo vieta ir "
                L"parinktis Visada viršuje įsimenamos. Iki 30 paieškos tekstų su parinktimis saugoma tik "
                L"iki programos uždarymo. Pradžios ir pabaigos parinktys taikomos loginėms eilutėms. "
                L"Reguliarieji reiškiniai naudoja PCRE2 sintaksę. Kitos meniu Redaguoti komandos taikomos "
                L"aktyviam ataskaitos skirtukui. Enter pradeda paiešką; Shift+Enter apverčia pasirinktą "
                L"kryptį. „Skirti didžiąsias ir mažąsias raides“ skiria didžiąsias ir mažąsias raides; "
                L"„Ieškoti atgal“ ieško teksto pradžios link. Pasirinkus istorijos įrašą atkuriamos visos "
                L"penkios paieškos parinktys, įskaitant reguliariųjų reiškinių režimo būseną; „Visada "
                L"viršuje“ yra nepriklausoma. „Reguliarusis reiškinys“ išjungia „Eilutė prasideda“ ir "
                L"„Eilutė baigiasi“. Įjungus abi eilutės kraštų parinktis, pakanka atitikmens viename "
                L"krašte. „Teksto eilučių kėlimas“ keičia tik rodymą."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"Nepavyko įrašyti WebP vaizdo. Patikrinkite paskirties vietą, laisvą atmintį ir disko vietą."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Tekstinis dokumentas UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Tekstinis dokumentas UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Tekstinis dokumentas UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Tekstinis dokumentas UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Ataskaitos negalima išsaugoti šia koduote neprarandant simbolių. Pasirinkite kitą teksto "
                L"koduotę."
            },
            { TXT_OPEN_FOLDER, L"Atidaryti a&planką…" },
            { TXT_OPEN_FOLDER_TITLE, L"Atidaryti aplanką" },
            { TXT_FOLDER_READ_FAILED, L"Nepavyko perskaityti aplanko:\n\n%s\n\n„Windows“ klaida %lu." },
            { TXT_ADVANCED_MODE, L"&Išplėstinis režimas" },
            { TXT_REPORT_DETAIL_REJECTED, L"Pasirinkta MediaInfo.dll atmetė ataskaitos detalumo nuostatą." },
            { TXT_KNOWN_FORMATS, L"Žinomi &formatai" },
            { TXT_KNOWN_CODECS, L"Žinomi &kodekai" },
            { TXT_KNOWN_PARAMETERS, L"Žinomi &parametrai" },
            { TXT_KNOWN_FORMATS_TITLE, L"Žinomi formatai" },
            { TXT_KNOWN_CODECS_TITLE, L"Žinomi kodekai" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Žinomi parametrai" },
            { TXT_KNOWN_INFO_FAILED, L"Biblioteka negrąžino prašomos informacijos." },
            { TXT_FULL_PARSING, L"Išsami ana&lizė" },
            { TXT_PARSING_REJECTED, L"Pasirinkta MediaInfo.dll atmetė analizės nuostatą." },
            { TXT_TRACE_LEVEL_0, L"Sekimo lygis &0" },
            { TXT_TRACE_LEVEL_5, L"Sekimo lygis &5" },
            { TXT_TRACE_LEVEL_9, L"Sekimo lygis &9" },
            { TXT_TRACE_LEVEL_10, L"Sekimo lygis &10" },
            { TXT_PAGE_SETUP, L"Puslapi&o sąranka…" },
            { TXT_PAGE_SETUP_FAILED, L"Nepavyko atidaryti puslapio sąrankos." },
            { TXT_PRINT, L"&Spausdinti…\tCtrl+P" },
            { TXT_PRINTING, L"Spausdinama…" },
            { TXT_PRINT_FAILED,
                L"Nepavyko išspausdinti teksto. Patikrinkite spausdintuvą, jo nuostatas ir laisvą atmintį."
            },
            { TXT_TOOLS_MENU, L"Įra&nkiai" },
            { TXT_CREATE_HEADER, L"Sukurti &antraštės failą…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Sukurti antraštės failą - Atidaryti" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Sukurti antraštės failą - Įrašyti kaip" },
            { TXT_HEADER_FORMAT, L"Antraštės failas (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Nepavyko perskaityti failo antraštės:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Nepavyko įrašyti antraštės failo:\n\n%s" },
            { TXT_COPY, L"&Kopijuoti" },
            { TXT_COPY_FILE_NAME, L"Kopijuoti failo var&dą" },
            { TXT_COPY_FULL_PATH, L"Kopijuoti visą k&elią" },
            { TXT_LAUNCH_FILE, L"Pa&leisti failą" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"&Rodyti aplanke" },
            { TXT_EDIT_MENU, L"&Redaguoti" },
            { TXT_WORD_WRAP, L"Teksto eilučių &kėlimas" },
            { TXT_WORD_WRAP_FAILED, L"Nepavyko pakeisti teksto eilučių kėlimo." },
            { TXT_COPY_SELECTION, L"&Kopijuoti\tCtrl+C" },
            { TXT_SELECT_ALL, L"Pažymėti &viską\tCtrl+A" },
            { TXT_FIND_MENU, L"&Rasti…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Rasti ki&tą\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Rasti &ankstesnį\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Rasti" },
            { TXT_FIND_WHAT, L"Rasti &tekstą:" },
            { TXT_FIND_NEXT, L"Rasti &kitą" },
            { TXT_FIND_MATCH_CASE, L"Skirti didžiąsias ir &mažąsias raides" },
            { TXT_FIND_BACKWARD, L"Ieškoti &atgal" },
            { TXT_FIND_TOPMOST, L"Visada &viršuje" },
            { TXT_FIND_STARTS_WITH, L"Eilutė &prasideda" },
            { TXT_FIND_ENDS_WITH, L"Eilutė &baigiasi" },
            { TXT_FIND_REGEX, L"&Reguliarusis reiškinys" },
            { TXT_FIND_NOT_FOUND, L"Nurodytas tekstas nerastas." },
            { TXT_FIND_FAILED, L"Nepavyko užbaigti paieškos." },
            { TXT_FIND_REGEX_ERROR, L"Reguliariojo reiškinio klaida:\r\n\r\n%s" },
        }
    },
    {
        LANG_LV,
        {
            { TXT_LANGUAGE_NAME, L"Latviešu" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nTīmekļa vietne: " },
            { TXT_FILE_OPEN_FAILED, L"Nevar atvērt %s. Pārbaudiet ceļu un piekļuves tiesības." },
            { TXT_BROWSE_DLL, L"&Pārlūkot…" },
            { TXT_BROWSE_REPORT, L"Pār&lūkot…" },
            { TXT_CLOSE, L"Ai&zvērt" },
            { TXT_CLOSE_TAB, L"Ai&zvērt\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"&Noklusējums" },
            { TXT_EXPORT, L"&Eksportēt…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Fails" },
            { TXT_REPORT_FONT, L"Pārskata &fonts:" },
            { TXT_HELP_MENU, L"&Palīdzība" },
            { TXT_HELP, L"&Palīdzība\tF1" },
            { TXT_LANGUAGE, L"&Valoda:" },
            { TXT_OPEN_WEBSITE, L"&Atvērt noklusējuma pārlūkprogrammā" },
            { TXT_OPEN, L"&Atvērt…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Opcijas" },
            { TXT_PREFERENCES_MENU, L"&Iestatījumi…\tCtrl+G" },
            { TXT_ABOUT, L"Pa&r programmu" },
            { TXT_ABOUT_TITLE, L"Par programmu %ls" },
            { TXT_ALL_FILES, L"Visi faili" },
            { TXT_FONT_BOLD, L"Treknraksts" },
            { TXT_FONT_BOLD_ITALIC, L"Treknraksts + Slīpraksts" },
            { TXT_BROWSE_CURL, L"P&ārlūkot…" },
            { TXT_CANCEL, L"Atcelt" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Nevar ielādēt MediaInfo.dll (Windows kļūda %lu). Izmantojiet 32 bitu DLL, kas ir saderīga "
                L"ar šo Windows versiju."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Nevar ielādēt libcurl.dll (Windows kļūda %lu). Atlasiet 32 bitu bibliotēku, kas ir "
                L"saderīga ar šo Windows versiju."
            },
            { TXT_CLOSE_ALL, L"Aizvērt &visu" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Kopēt ad&resi" },
            { TXT_COPY_INFORMATION, L"Kopēt &informāciju" },
            { TXT_DLL_FILES, L"Dinamiskās bibliotēkas" },
            { TXT_EXIT, L"&Iziet\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Iegultās bibliotēkas MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Iegultās bibliotēkas libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Eksportēt pārskatu" },
            { TXT_FONT_ANTIALIASING, L"Fonta no&gludināšana:" },
            { TXT_GIF_EXPORT_FAILED,
                L"GIF eksports neizdevās. Bezzudumu GIF pieļauj ne vairāk kā 256 krāsas."
            },
            { TXT_FONT_ITALIC, L"Slīpraksts" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED,
                L"JPEG eksports neizdevās. Nepieciešams darbspējīgs GDI+ JPEG kodētājs."
            },
            { TXT_LICENSE_UNAVAILABLE, L"Licences resurss nav pieejams." },
            { TXT_MEDIA_FILES, L"Multivides faili" },
            { TXT_APPLICATION_DESCRIPTION, L"Multivides informācijas skatītājs" },
            { TXT_HELP_TITLE, L"MediaInfo — Palīdzība" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo nevarēja inicializēt faila analīzi." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo nevar atvērt vai atpazīt šo failu." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"MediaInfo.dll &ceļš:" },
            { TXT_MEDIALIB_REQUIRED,
                L"MediaInfo.dll nav ielādēta. Atlasiet to sadaļā Opcijas > Iestatījumi."
            },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll nav ielādēta." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Nevar ielādēt saderīgu ārējo vai iegulto MediaInfo.dll. Atlasiet to sadaļā Opcijas > "
                L"Iestatījumi."
            },
            { TXT_ANTIALIASING_NONE, L"Nav" },
            { TXT_OK, L"Labi" },
            { TXT_OPEN_TITLE, L"Atvērt multivides failus" },
            { TXT_PLATFORM, L"Mērķa platforma:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Iestatījumi" },
            { TXT_READY, L"Gatavs" },
            { TXT_FONT_REGULAR, L"Parasts" },
            { TXT_REPORT_LANGUAGE, L"Pā&rskata valoda:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Pārskatu valodu tabulas" },
            { TXT_SELECT_MEDIALIB, L"Pārlūkot: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Pārlūkot: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH, L"Atlasiet esošu multivides failu ar ceļu, kas īsāks par MAX_PATH." },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Atlasiet esošus failus ar ceļiem, kas īsāki par MAX_PATH." },
            { TXT_SELECT_CURL, L"Pārlūkot: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Teksta dokuments ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"Nevar saglabāt BMP attēlu. Pārbaudiet mērķi, brīvo atmiņu un vietu diskā."
            },
            { TXT_LIBRARY_WORKER_START_FAILED, L"Nevar palaist bibliotēkas procesu (Windows kļūda %lu)." },
            { TXT_REPORT_COPY_FAILED, L"Nevar kopēt MediaInfo pārskatu atmiņā." },
            { TXT_VIEWER_CREATE_FAILED, L"Nevar izveidot MediaInfo skatītāju." },
            { TXT_MEDIALIB_PATH_INVALID, L"MediaInfo.dll ceļš nav derīgs vai ir pārāk garš." },
            { TXT_PNG_EXPORT_FAILED,
                L"Nevar saglabāt PNG attēlu. Pārbaudiet mērķi, brīvo atmiņu un vietu diskā."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"Nevar saglabāt TIFF attēlu. Pārbaudiet mērķi, brīvo atmiņu un vietu diskā."
            },
            { TXT_COPY_URL_FAILED, L"Neizdevās kopēt URL starpliktuvē." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"Win32 skatītājam nepieciešama 32 bitu %s. Atlasiet x86/i386 bibliotēku."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Iegulto bibliotēku nevar ierakstīt AppData, lietotāja profilā, Program Files vai pagaidu "
                L"mapē."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED, L"Bibliotēkas atspiešana vai CRC pārbaude neizdevās." },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Iegultās bibliotēkas resurss nav derīgs." },
            { TXT_CURL_FILENAME_INVALID,
                L"Bibliotēkai jābūt nosauktai libcurl.dll, lai MediaInfo varētu to izmantot."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Neizdevās atvērt failu dialogu." },
            { TXT_FILE_DIALOG_SELECTION_FAILED, L"Neizdevās iegūt failu dialogā atlasītos failus." },
            { TXT_RECENT_FILE_MISSING,
                L"Fails “%s” vairs nepastāv.\n\nVai noņemt šo ierakstu no neseno failu saraksta?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Fails vairs nav pieejams:\n\n%s\n\nVai noņemt šo ierakstu no neseno failu saraksta?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Neizdevās kopēt informāciju starpliktuvē." },
            { TXT_CURL_PATH_INVALID, L"libcurl.dll ceļš nav derīgs vai ir pārāk garš." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Bibliotēka neatgrieza MediaInfo versiju." },
            { TXT_CURL_EXPORTS_MISSING, L"Bibliotēka neeksportē MediaInfo nepieciešamās curl funkcijas." },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"Bibliotēka neeksportē nepieciešamās MediaInfo Unicode funkcijas."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Bibliotēkas process neizdevās %s (kods 0x%08lX). Atlasiet saderīgu DLL sadaļā Opcijas > "
                L"Iestatījumi."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Bibliotēkas process pārstāja atbildēt %s. Atlasiet saderīgu DLL sadaļā Opcijas > "
                L"Iestatījumi."
            },
            { TXT_PREFERENCES_SAVE_FAILED,
                L"Iestatījumi tika lietoti, bet tos neizdevās saglabāt reģistrā."
            },
            { TXT_REPORT_START_FAILED, L"Nepietiek atmiņas pārskata palaišanai." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Nevar izveidot pārskata attēlu." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Nevar ielādēt valodas tabulu. Atlasiet derīgu UTF-8 vai "
                L"UTF-16 MediaInfo CSV failu." },
            { TXT_REPORT_THREAD_START_FAILED, L"Nevar palaist pārskata pavedienu." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"Atlasītā MediaInfo.dll noraidīja pārskata valodu." },
            { TXT_INVALID_WINDOWS_DLL, L"Atlasītais fails nav derīga Windows DLL." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Atlasītais attēla formāts netiek atbalstīts." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Nevar saglabāt teksta pārskatu. Pārbaudiet mērķi un brīvo vietu diskā."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Nevar atvērt vietni noklusējuma pārlūkā." },
            { TXT_TOO_MANY_FILES, L"Atlasīts pārāk daudz failu. Atveriet mazākas grupas." },
            { TXT_LIBRARY_PATH_HINT,
                L"Izmantojiet 32 bitu bibliotēkas, kas ir saderīgas ar jūsu Windows versiju. Atstājiet ceļus "
                L"tukšus automātiskai meklēšanai. MediaInfoLib v0.7.60 neizmanto libcurl.dll."
            },
            { TXT_VERSION, L"Versija" },
            { TXT_WEBSITE_TOOLTIP, L"Atvērt tīmekļa vietni %s" },
            { TXT_WAITING_FOR_REPORT, L"Gaida pašreizējā pārskata pabeigšanu." },
            { TXT_WEBSITE_LABEL, L"Tīmekļa vietne:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"MediaInfo pārskata kopēšanas laikā" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"libc&url.dll ceļš:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"MediaInfo.dll ielādes laikā" },
            { TXT_CURL_LOAD_OPERATION, L"libcurl.dll ielādes laikā" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"MediaInfo.dll atbrīvošanas laikā" },
            { TXT_APPLY, L"L&ietot" },
            { TXT_TAB_NAME_LENGTH, L"Cilnes nosauku&ma garums:" },
            { TXT_TITLE_NAME_LENGTH, L"Vir&sraksta garums:" },
            { TXT_RECENT_FILES, L"Nesenie faili:" },
            { TXT_CLEAR_RECENT_FILES, L"No&tīrīt" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"Cilnes nosaukuma garumam jābūt no 8 līdz 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"Nosaukuma garumam virsrakstā jābūt no 8 līdz 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Neseno failu saraksts tika notīrīts, bet to neizdevās saglabāt reģistrā."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"Aizvērt cilnes ar &dubultklikšķi" },
            { TXT_CLOSE_TAB_CONTEXT, L"&Aizvērt cilni" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"&Atļaut vairākas instances" },
            { TXT_INSTANCE_FORWARD_FAILED, L"Failus neizdevās nodot palaistajai MediaInfo instancei." },
            { TXT_LOADING, L"Notiek ielāde…" },
            { TXT_LOADING_FILE, L"Notiek faila ielāde: %s…" },
            { TXT_APPLICATION_HELP,
                L"FAILI UN CILNES\r\nVietējais Windows x86 skatītājs MediaInfo.dll pārskatiem. Katram "
                L"failam ir sava tikai lasāma cilne. Atveriet ar Ctrl+O vai ievelciet failus logā. "
                L"Atkārtota atvēršana atlasa esošo cilni. Ctrl+W vai peles vidējā poga aizver cilni; "
                L"Aizvērt visu aizver visas. Faila izvēlne atceras astoņus nesenos failus. Cilnes "
                L"galvenes kontekstizvēlnē ir Aizvērt cilni. Iestatījumos ieslēdziet Aizvērt cilnes ar "
                L"dubultklikšķi, lai aizvērtu cilni ar dubultklikšķi uz tās galvenes. Šī opcija pēc "
                L"noklusējuma ir izslēgta un tiek saglabāta. Dubultklikšķis pārskata tekstā atlasa vārdu. "
                L"Trīskāršs klikšķis atlasa loģisku rindu. Vilkšana paplašina atlasi pa vārdiem vai "
                L"rindām.\r\nAtvērt mapi… atver failus, kas atrodas tieši atlasītajā mapē, katru savā "
                L"cilnē. Apakšmapes netiek iekļautas.\r\nAtvērt un Atvērt mapi koplieto pēdējo atlasīto "
                L"mapi. Eksports atceras atsevišķu mapi, pēc noklusējuma Dokumenti. Paplašinātais režīms "
                L"pārskatā parāda papildu laukus.\r\nZināmie formāti / Zināmie kodeki / Zināmie parametri "
                L"— MediaInfo.dll.\r\nPilna analīze pārbauda visu failu un var aizņemt ilgāku laiku. Šīs "
                L"pārskata opcijas un Trasēšanas līmenis pieder katrai cilnei; izmaiņas atsvaidzina tikai "
                L"aktīvo cilni. Pēdējā manuāli izvēlētā kombinācija tiek saglabāta jaunām cilnēm un "
                L"nākamajai palaišanai. Atbilstošs kešatmiņā saglabātais pārskats tiek atkārtoti "
                L"izmantots, kamēr fails paliek nemainīgs.\r\nTrasēšanas līmenis: 0 / 5 / 9 / 10.\r\n"
                L"Fails > Lappuses iestatīšana… atver papīra, orientācijas un piemaļu iestatījumus "
                L"pašreizējai sesijai. Drukāt… (Ctrl+P) atver sistēmas drukāšanas dialogu; Windows 11 "
                L"nodrošina priekšskatījumu, bet Windows 10 un vecākas versijas saglabā klasisko dialogu. "
                L"Ctrl+P drukā galvenā loga aktīvo cilni vai Palīdzības vai Par programmu teksta apgabalu "
                L"atkarībā no tā, kuram logam ir fokuss. Pārskati izmanto izvēlēto pārskata fontu, "
                L"Palīdzība sistēmas dialogu fontu, bet Par programmu sava teksta apgabala fontu. Ja nav "
                L"atvērtu ciļņu, bet Palīdzība ir atvērta, Lappuses iestatīšana… un Drukāt… paliek "
                L"pieejamas; Drukāt… drukā Palīdzību. Palīdzība izmanto galvenā loga drukāšanas dialogu; "
                L"atkārtots Ctrl+P Palīdzībā izvirza to pašu dialogu priekšplānā. Garās rindas tiek "
                L"aplauztas, un teksts sadalīts lappusēs. Drukāšana notiek fonā.\r\nVelciet vienu vai "
                L"vairākus failus uz logu, EXE ikonu vai tās saīsni vai norādiet to ceļus komandrindā. Ja "
                L"vairākas instances nav atļautas, faili tiek atvērti jau palaistajā logā.\r\nStatusa "
                L"joslas kreisajā pusē redzami failu ceļi un ielādes norise, bet labajā – ielādētās "
                L"MediaInfo.dll versija. Gari ceļi tiek saīsināti ar daudzpunkti atbilstoši pieejamajai "
                L"vietai.\r\n\r\nEKSPORTĒŠANA\r\nTXT, BMP, GIF, JPEG, PNG, TIFF un WebP tiek piedāvāti "
                L"atbilstoši pieejamībai. Tiek atcerēta pēdējā eksporta mape un formāts.\r\nTXT piedāvā "
                L"ANSI, UTF-8, UTF-8 ar BOM, UTF-16 BE ar BOM un UTF-16 LE ar BOM. Noklusējums ir otrais "
                L"ieraksts, UTF-8 bez BOM. Tiek saglabāts pilns pārskata teksts un tā sākotnējās rindu "
                L"beigas.\r\n\r\nIZVEIDOT GALVENES FAILU\r\nRīki ir ceturtā izvēlne izvēļņu joslā. Tā "
                L"komanda Izveidot galvenes failu… atver vienu avota failu neatkarīgi no pārskatu cilnēm "
                L"un kopē tā pirmos 524288 baitus (512 KiB). Īsāks fails tiek kopēts pilnībā; tukšs fails "
                L"rada tukšu izvadi. Tā ir parasta bināro failu lasīšana bez MediaInfo analīzes vai "
                L"MediaInfo.dll prasības. Rīks nemaina pārskatu cilnes vai programmas neseno failu "
                L"sarakstu.\r\n\r\nPēc izlasīšanas avota faila mapē sākas dialoglodziņš Saglabāt kā un "
                L"piedāvā video.mp4.header priekš video.mp4: .header tiek pievienots visam oriģinālajam "
                L"nosaukumam. Varat mainīt gan nosaukumu, gan mērķa mapi. Atceļot jebkuru no "
                L"dialoglodziņiem, izvades fails netiek ierakstīts. Esoša galamērķa aizstāšanai "
                L"nepieciešams apstiprinājums. Avots paliek nemainīgs; neveiksmīga saglabāšana saglabā "
                L"iepriekšējo galamērķi. Atvēršanai un saglabāšanai tiek izmantoti jaunākie attiecīgajā "
                L"Windows versijā pieejamie sistēmas dialoglodziņi.\r\n\r\nLietojumprogrammas startēšanas "
                L"laikā rīks iegūst sākotnējo ievades mapi no Fails > Atvērt. Ja mape nav saglabāta, "
                L"sistēma Windows izvēlas sākotnējo atrašanās vietu. Pēc ievades faila atlasīšanas rīks "
                L"atceras savu mapi tikai līdz lietojumprogrammas iziešanai, pat ja ir atcelta opcija "
                L"Saglabāt kā. Tas nemaina mapes, ko izmanto Atvērt un Eksportēt, un nesaglabā savu mapi "
                L"lietojumprogrammas iestatījumos. Katrs dialoglodziņš Saglabāt kā sākas pašlaik atlasītā "
                L"ievades faila mapē neatkarīgi no iepriekšējā saglabāšanas mērķa.\r\n\r\nIESTATĪJUMI UN "
                L"VALODAS\r\nIestatījumi (Opcijas > Iestatījumi, Ctrl+G) ietver bibliotēku ceļus, "
                L"pārskata fontu, fonta nogludināšanu un valodas. Saskarnei ir 36 varianti, un sākotnēji "
                L"tā seko Windows valodai. Pārskati vienmēr pēc noklusējuma izmanto bibliotēkas sākotnējo "
                L"angļu valodu neatkarīgi no Windows un saskarnes. To maina tikai manuāla izvēle: angļu "
                L"valoda, 37 tulkojumi vai sava MediaInfo CSV tabula. Labi vai Lietot apstiprina "
                L"izmaiņas; Atcelt atmet gaidošās izmaiņas. Iestatījumos var noteikt cilnes nosaukuma "
                L"ierobežojumu (noklusēti 80) un notīrīt neseno failu sarakstu. Gari nosaukumi saglabā "
                L"sākumu, beigas un paplašinājumu ar daudzpunkti vidū. Notīrīt uzreiz noņem neseno failu "
                L"sarakstu, pat ja iestatījumi pēc tam tiek aizvērti ar Atcelt.\r\n\r\nGalvenā loga "
                L"virsraksts rāda aktīvo failu formā faila nosaukums — MediaInfo. Iestatījumos nosaukuma "
                L"garumu virsrakstā var iestatīt atsevišķi no 8 līdz 255 rakstzīmēm (noklusējums 40). Garāki "
                L"nosaukumi tiek saīsināti ar to pašu daudzpunkti vidū, saglabājot paplašinājumu. Ja nav "
                L"atvērtu cilņu, virsraksts ir MediaInfo.\r\n\r\nBIBLIOTĒKAS UN "
                L"LOGI\r\nProgramma ietver MediaInfo 26.10, 21.03 un 0.7.60, ko mēģina no jaunākās pēc "
                L"ārējām bibliotēkām. Divām jaunākajām ir atbilstoša libcurl; 0.7.60 to nekad neizpako. "
                L"Loga novietojums tiek saglabāts. Pēc noklusējuma ir atļauta tikai viena instance, un "
                L"turpmākās palaišanas nodod failus atvērtajam logam. Iestatījumos var atļaut vairākas "
                L"instances. Ja ir vairāki logi, saglabātā pozīcija tiek atjaunota tikai katra loga tipa "
                L"pirmajam logam; pārējiem logiem tiek atjaunots tikai izmērs.\r\n\r\nRediģēt > Atrast "
                L"(Ctrl+F) meklē aktīvajā pārskata cilnē vai Palīdzības vai Par programmu teksta apgabalā "
                L"atkarībā no tā, kuram logam ir fokuss. Meklēšanas logs saglabā pēdējo izvēlēto avotu, "
                L"kamēr tam ir fokuss. F3 atkārto meklēšanu, bet Shift+F3 maina tās virzienu. Sasniedzot "
                L"teksta malu, meklēšana turpinās no otras malas. Opcijas > Teksta aplaušana attiecas "
                L"tikai uz aktīvo cilni; atzīme mainās atbilstoši atlasītajai cilnei. Meklēšanas logu var "
                L"minimizēt un mainīt tā platumu; tiek atcerēta atrašanās vieta un opcija Vienmēr "
                L"virspusē. Līdz 30 meklēšanas tekstiem ar opcijām tiek saglabāti tikai līdz lietotnes "
                L"aizvēršanai. Sākuma un beigu opcijas attiecas uz loģiskajām rindām. Regulārās "
                L"izteiksmes izmanto PCRE2 sintaksi. Pārējās izvēlnes Rediģēt komandas attiecas uz aktīvo "
                L"pārskata cilni. Enter sāk meklēšanu; Shift+Enter apgriež izvēlēto virzienu. “Atšķirt "
                L"lielos un mazos burtus” atšķir lielos un mazos burtus; “Meklēt atpakaļ” meklē teksta "
                L"sākuma virzienā. Vēstures ieraksta izvēle atjauno visas piecas meklēšanas opcijas, "
                L"tostarp regulārās izteiksmes režīma stāvokli; “Vienmēr virspusē” ir neatkarīga opcija. "
                L"“Regulārā izteiksme” atspējo “Rinda sākas ar” un “Rinda beidzas ar”. Ja abas rindas "
                L"malu opcijas ir ieslēgtas, pietiek ar atbilstību vienā malā. “Teksta aplaušana” maina "
                L"tikai attēlojumu."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"Nevar saglabāt WebP attēlu. Pārbaudiet mērķi, brīvo atmiņu un vietu diskā."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Teksta dokuments UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Teksta dokuments UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Teksta dokuments UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Teksta dokuments UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Pārskatu nevar saglabāt šajā kodējumā, nezaudējot rakstzīmes. Izvēlieties citu teksta "
                L"kodējumu."
            },
            { TXT_OPEN_FOLDER, L"Atvērt &mapi…" },
            { TXT_OPEN_FOLDER_TITLE, L"Atvērt mapi" },
            { TXT_FOLDER_READ_FAILED, L"Mapi nevarēja nolasīt:\n\n%s\n\nWindows kļūda %lu." },
            { TXT_ADVANCED_MODE, L"&Paplašinātais režīms" },
            { TXT_REPORT_DETAIL_REJECTED,
                L"Atlasītā MediaInfo.dll noraidīja pārskata detalizācijas iestatījumu."
            },
            { TXT_KNOWN_FORMATS, L"Zināmie &formāti" },
            { TXT_KNOWN_CODECS, L"Zināmie &kodeki" },
            { TXT_KNOWN_PARAMETERS, L"Zināmie para&metri" },
            { TXT_KNOWN_FORMATS_TITLE, L"Zināmie formāti" },
            { TXT_KNOWN_CODECS_TITLE, L"Zināmie kodeki" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Zināmie parametri" },
            { TXT_KNOWN_INFO_FAILED, L"Bibliotēka neatgrieza pieprasīto informāciju." },
            { TXT_FULL_PARSING, L"Pilna ana&līze" },
            { TXT_PARSING_REJECTED, L"Atlasītā MediaInfo.dll noraidīja analīzes iestatījumu." },
            { TXT_TRACE_LEVEL_0, L"Trasēšanas līmenis &0" },
            { TXT_TRACE_LEVEL_5, L"Trasēšanas līmenis &5" },
            { TXT_TRACE_LEVEL_9, L"Trasēšanas līmenis &9" },
            { TXT_TRACE_LEVEL_10, L"Trasēšanas līmenis &10" },
            { TXT_PAGE_SETUP, L"&Lappuses iestatīšana…" },
            { TXT_PAGE_SETUP_FAILED, L"Neizdevās atvērt lappuses iestatījumus." },
            { TXT_PRINT, L"&Drukāt…\tCtrl+P" },
            { TXT_PRINTING, L"Drukāšana…" },
            { TXT_PRINT_FAILED,
                L"Tekstu nevarēja izdrukāt. Pārbaudiet printeri, tā iestatījumus un pieejamo atmiņu."
            },
            { TXT_TOOLS_MENU, L"&Rīki" },
            { TXT_CREATE_HEADER, L"Izveidot &galvenes failu…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Izveidot galvenes failu - Atvērt" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Izveidot galvenes failu - Saglabāt kā" },
            { TXT_HEADER_FORMAT, L"Galvenes fails (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Neizdevās nolasīt faila galveni:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Neizdevās saglabāt galvenes failu:\n\n%s" },
            { TXT_COPY, L"&Kopēt" },
            { TXT_COPY_FILE_NAME, L"Kopēt faila n&osaukumu" },
            { TXT_COPY_FULL_PATH, L"Kopēt pilnu &ceļu" },
            { TXT_LAUNCH_FILE, L"&Palaist failu" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"&Rādīt mapē" },
            { TXT_EDIT_MENU, L"R&ediģēt" },
            { TXT_WORD_WRAP, L"&Teksta aplaušana" },
            { TXT_WORD_WRAP_FAILED, L"Neizdevās mainīt teksta aplaušanu." },
            { TXT_COPY_SELECTION, L"&Kopēt\tCtrl+C" },
            { TXT_SELECT_ALL, L"Atlasīt &visu\tCtrl+A" },
            { TXT_FIND_MENU, L"&Atrast…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Atrast &nākamo\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Atrast &iepriekšējo\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Atrast" },
            { TXT_FIND_WHAT, L"Meklējamais &teksts:" },
            { TXT_FIND_NEXT, L"Atrast &nākamo" },
            { TXT_FIND_MATCH_CASE, L"Atšķirt lielos un &mazos burtus" },
            { TXT_FIND_BACKWARD, L"Meklēt &atpakaļ" },
            { TXT_FIND_TOPMOST, L"Vienmēr &virspusē" },
            { TXT_FIND_STARTS_WITH, L"Rinda &sākas ar" },
            { TXT_FIND_ENDS_WITH, L"Rinda &beidzas ar" },
            { TXT_FIND_REGEX, L"&Regulārā izteiksme" },
            { TXT_FIND_NOT_FOUND, L"Norādītais teksts netika atrasts." },
            { TXT_FIND_FAILED, L"Meklēšanu neizdevās pabeigt." },
            { TXT_FIND_REGEX_ERROR, L"Regulārās izteiksmes kļūda:\r\n\r\n%s" },
        }
    },
    {
        LANG_HU,
        {
            { TXT_LANGUAGE_NAME, L"Magyar" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nWebhely: " },
            { TXT_FILE_OPEN_FAILED,
                L"A(z) %s nem nyitható meg. Ellenőrizze az elérési utat és a jogosultságokat."
            },
            { TXT_BROWSE_DLL, L"&Tallózás…" },
            { TXT_BROWSE_REPORT, L"Tall&ózás…" },
            { TXT_CLOSE, L"&Bezárás" },
            { TXT_CLOSE_TAB, L"&Bezárás\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"A&lapértelmezett" },
            { TXT_EXPORT, L"&Exportálás…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Fájl" },
            { TXT_REPORT_FONT, L"Jelentés &betűtípusa:" },
            { TXT_HELP_MENU, L"&Súgó" },
            { TXT_HELP, L"&Súgó\tF1" },
            { TXT_LANGUAGE, L"&Nyelv:" },
            { TXT_OPEN_WEBSITE, L"&Megnyitás az alapértelmezett böngészőben" },
            { TXT_OPEN, L"&Megnyitás…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Beállítások" },
            { TXT_PREFERENCES_MENU, L"&Beállítások…\tCtrl+G" },
            { TXT_ABOUT, L"&Névjegy" },
            { TXT_ABOUT_TITLE, L"A(z) %ls névjegye" },
            { TXT_ALL_FILES, L"Minden fájl" },
            { TXT_FONT_BOLD, L"Félkövér" },
            { TXT_FONT_BOLD_ITALIC, L"Félkövér + Dőlt" },
            { TXT_BROWSE_CURL, L"T&allózás…" },
            { TXT_CANCEL, L"Mégse" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"A MediaInfo.dll nem tölthető be (Windows-hiba: %lu). Használjon ezzel a Windows-verzióval "
                L"kompatibilis 32 bites DLL-t."
            },
            { TXT_CURL_LOAD_FAILED,
                L"A libcurl.dll nem tölthető be (Windows-hiba: %lu). Válasszon ezzel a Windows-verzióval "
                L"kompatibilis 32 bites könyvtárat."
            },
            { TXT_CLOSE_ALL, L"&Összes bezárása" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"&Cím másolása" },
            { TXT_COPY_INFORMATION, L"&Információ másolása" },
            { TXT_DLL_FILES, L"Dinamikus könyvtárak" },
            { TXT_EXIT, L"&Kilépés\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Beágyazott könyvtárak MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Beágyazott könyvtárak libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Jelentés exportálása" },
            { TXT_FONT_ANTIALIASING, L"Betűtípus él&simítása:" },
            { TXT_GIF_EXPORT_FAILED,
                L"A GIF-export sikertelen. A veszteségmentes GIF legfeljebb 256 színt enged."
            },
            { TXT_FONT_ITALIC, L"Dőlt" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED, L"A JPEG-export sikertelen. Működő GDI+ JPEG-kódoló szükséges." },
            { TXT_LICENSE_UNAVAILABLE, L"A licenc erőforrása nem érhető el." },
            { TXT_MEDIA_FILES, L"Médiafájlok" },
            { TXT_APPLICATION_DESCRIPTION, L"Médiainformáció-megjelenítő" },
            { TXT_HELP_TITLE, L"MediaInfo — Súgó" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"A MediaInfo nem tudta inicializálni a fájl elemzését." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"A MediaInfo nem tudja megnyitni vagy felismerni a fájlt." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"MediaInfo.dll &elérési útja:" },
            { TXT_MEDIALIB_REQUIRED,
                L"A MediaInfo.dll nincs betöltve. Válassza ki a Beállítások > Beállítások alatt."
            },
            { TXT_MEDIALIB_NOT_LOADED, L"A MediaInfo.dll nincs betöltve." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Nem tölthető be kompatibilis külső vagy beágyazott MediaInfo.dll. Válassza ki a "
                L"Beállítások > Beállítások alatt."
            },
            { TXT_ANTIALIASING_NONE, L"Nincs" },
            { TXT_OK, L"OK" },
            { TXT_OPEN_TITLE, L"Médiafájlok megnyitása" },
            { TXT_PLATFORM, L"Célplatform:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Beállítások" },
            { TXT_READY, L"Kész" },
            { TXT_FONT_REGULAR, L"Normál" },
            { TXT_REPORT_LANGUAGE, L"&Jelentés nyelve:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Jelentésnyelvi táblázatok" },
            { TXT_SELECT_MEDIALIB, L"Tallózás: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Tallózás: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH, L"Válasszon létező médiafájlt MAX_PATH-nál rövidebb elérési úttal." },
            { TXT_SELECTED_PATHS_TOO_LONG,
                L"Válasszon létező fájlokat MAX_PATH-nál rövidebb elérési úttal."
            },
            { TXT_SELECT_CURL, L"Tallózás: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Szöveges dokumentum ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"A BMP-kép nem menthető. Ellenőrizze a célt, a szabad memóriát és a lemezterületet."
            },
            { TXT_LIBRARY_WORKER_START_FAILED,
                L"A könyvtár folyamata nem indítható el (Windows-hiba: %lu)."
            },
            { TXT_REPORT_COPY_FAILED, L"A MediaInfo-jelentés nem másolható a memóriába." },
            { TXT_VIEWER_CREATE_FAILED, L"A MediaInfo-megjelenítő nem hozható létre." },
            { TXT_MEDIALIB_PATH_INVALID, L"A MediaInfo.dll elérési útja érvénytelen vagy túl hosszú." },
            { TXT_PNG_EXPORT_FAILED,
                L"A PNG-kép nem menthető. Ellenőrizze a célt, a szabad memóriát és a lemezterületet."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"A TIFF-kép nem menthető. Ellenőrizze a célt, a szabad memóriát és a lemezterületet."
            },
            { TXT_COPY_URL_FAILED, L"Az URL nem másolható a vágólapra." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"A Win32-megjelenítőhöz 32 bites %s szükséges. Válassza az x86/i386-könyvtárat."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"A beágyazott könyvtár nem írható az AppData, a felhasználói profil, a Program Files vagy "
                L"az ideiglenes mappa alá."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED,
                L"A könyvtár kicsomagolása vagy CRC-ellenőrzése sikertelen."
            },
            { TXT_LIBRARY_RESOURCE_INVALID, L"A beágyazott könyvtár erőforrása érvénytelen." },
            { TXT_CURL_FILENAME_INVALID,
                L"A könyvtár neve libcurl.dll kell legyen, hogy a MediaInfo használhassa."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"A fájlválasztó párbeszédpanel nem nyitható meg." },
            { TXT_FILE_DIALOG_SELECTION_FAILED,
                L"A kiválasztott fájlok nem kérhetők le a fájlválasztó párbeszédpaneltől."
            },
            { TXT_RECENT_FILE_MISSING,
                L"A(z) „%s” fájl már nem létezik.\n\nEltávolítja ezt a bejegyzést a legutóbbi fájlok "
                L"listájából?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"A fájl már nem érhető el:\n\n%s\n\nEltávolítja ezt a bejegyzést a legutóbbi fájlok "
                L"listájából?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Az információ nem másolható a vágólapra." },
            { TXT_CURL_PATH_INVALID, L"A libcurl.dll elérési útja érvénytelen vagy túl hosszú." },
            { TXT_MEDIALIB_VERSION_MISSING, L"A könyvtár nem adott vissza MediaInfo-verziót." },
            { TXT_CURL_EXPORTS_MISSING,
                L"A könyvtár nem exportálja a MediaInfo által igényelt curl-függvényeket."
            },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"A könyvtár nem exportálja a szükséges MediaInfo Unicode-függvényeket."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"A könyvtár folyamata hibát jelzett ennél: %s (kód: 0x%08lX). Válasszon kompatibilis DLL-t "
                L"a Beállítások > Beállítások alatt."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"A könyvtár folyamata nem válaszol ennél: %s. Válasszon kompatibilis DLL-t a Beállítások > "
                L"Beállítások alatt."
            },
            { TXT_PREFERENCES_SAVE_FAILED,
                L"A beállítások érvénybe léptek, de nem menthetők a rendszerleíró adatbázisba."
            },
            { TXT_REPORT_START_FAILED, L"Nincs elegendő memória a jelentés indításához." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"A jelentés képe nem hozható létre." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"A nyelvi táblázat nem tölthető be. Válasszon érvényes "
                L"UTF-8 vagy UTF-16 MediaInfo CSV-fájlt." },
            { TXT_REPORT_THREAD_START_FAILED, L"A jelentés szála nem indítható el." },
            { TXT_REPORT_LANGUAGE_REJECTED,
                L"A kiválasztott MediaInfo.dll elutasította a jelentés nyelvét."
            },
            { TXT_INVALID_WINDOWS_DLL, L"A kiválasztott fájl nem érvényes Windows DLL." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"A kiválasztott képformátum nem támogatott." },
            { TXT_TEXT_EXPORT_FAILED,
                L"A szöveges jelentés nem menthető. Ellenőrizze a célt és a szabad lemezterületet."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"A webhely nem nyitható meg az alapértelmezett böngészőben." },
            { TXT_TOO_MANY_FILES, L"Túl sok fájlt választott ki. Nyisson meg kisebb csoportokat." },
            { TXT_LIBRARY_PATH_HINT,
                L"Használjon a Windows-verziójával kompatibilis 32 bites könyvtárakat. Az automatikus "
                L"kereséshez hagyja üresen az elérési utakat. A MediaInfoLib v0.7.60 nem használ "
                L"libcurl.dll-könyvtárat."
            },
            { TXT_VERSION, L"Verzió" },
            { TXT_WEBSITE_TOOLTIP, L"Webhely megnyitása: %s" },
            { TXT_WAITING_FOR_REPORT, L"Várakozás az aktuális jelentés befejezésére." },
            { TXT_WEBSITE_LABEL, L"Webhely:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"a MediaInfo-jelentés másolása" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"libc&url.dll elérési útja:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"a MediaInfo.dll betöltése" },
            { TXT_CURL_LOAD_OPERATION, L"a libcurl.dll betöltése" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"a MediaInfo.dll felszabadítása" },
            { TXT_APPLY, L"Al&kalmaz" },
            { TXT_TAB_NAME_LENGTH, L"Lapnév &hossza:" },
            { TXT_TITLE_NAME_LENGTH, L"&Címhossz:" },
            { TXT_RECENT_FILES, L"Legutóbbi fájlok:" },
            { TXT_CLEAR_RECENT_FILES, L"Tö&rlés" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"A lapnév hosszának 8 és 255 között kell lennie." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"A címsorban lévő név hosszának 8 és 255 között kell lennie." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"A legutóbbi fájlok listája törölve lett, de nem sikerült menteni a rendszerleíró "
                L"adatbázisba."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"Lapok bezárása &dupla kattintással" },
            { TXT_CLOSE_TAB_CONTEXT, L"&Lap bezárása" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"Több &példány engedélyezése" },
            { TXT_INSTANCE_FORWARD_FAILED, L"A fájlokat nem sikerült átadni a futó MediaInfo-példánynak." },
            { TXT_LOADING, L"Betöltés…" },
            { TXT_LOADING_FILE, L"Fájl betöltése: %s…" },
            { TXT_APPLICATION_HELP,
                L"FÁJLOK ÉS LAPOK\r\nNatív Windows x86 megjelenítő a MediaInfo.dll jelentéseihez. Minden "
                L"fájlnak saját, csak olvasható lapja van. Megnyitás: Ctrl+O vagy húzza a fájlokat az "
                L"ablakra. Az ismételt megnyitás a meglévő lapot választja ki. Ctrl+W vagy a középső "
                L"egérgomb bezár egy lapot; az Összes bezárása mindet bezárja. A Fájl menü nyolc "
                L"legutóbbi fájlt jegyez meg. A lap fejlécének helyi menüjében megtalálható a Lap "
                L"bezárása parancs. A Beállításokban engedélyezze a Lapok bezárása dupla kattintással "
                L"lehetőséget, ha a fejlécére duplán kattintva szeretné bezárni a lapot. A beállítás "
                L"alapértelmezésben ki van kapcsolva, és az állapota mentődik. A jelentés szövegében a "
                L"dupla kattintás egy szót jelöl ki. A tripla kattintás egy logikai sort jelöl ki. A "
                L"húzás szavanként vagy soronként bővíti a kijelölést.\r\nA Mappa megnyitása… a "
                L"kiválasztott mappában közvetlenül található fájlokat külön-külön lapon nyitja meg. Az "
                L"almappák nem szerepelnek benne.\r\nA Megnyitás és a Mappa megnyitása közösen használja "
                L"az utoljára kiválasztott mappát. Az exportálás külön mappát jegyez meg, "
                L"alapértelmezésben a Dokumentumokat. A Haladó mód további mezőket jelenít meg a "
                L"jelentésben.\r\nIsmert formátumok / Ismert kodekek / Ismert paraméterek — "
                L"MediaInfo.dll.\r\nTeljes elemzés megvizsgálja a teljes fájlt, és tovább tarthat. Ezek a "
                L"jelentésbeállítások és a Nyomkövetési szint az egyes lapokhoz tartoznak; a módosítás "
                L"csak az aktív lapot frissíti. Az utoljára manuálisan kiválasztott kombináció mentésre "
                L"kerül az új lapokhoz és a következő indításhoz. A megfelelő gyorsítótárazott jelentést "
                L"a rendszer újra felhasználja, amíg a fájl változatlan marad.\r\nNyomkövetési szint: 0 / "
                L"5 / 9 / 10.\r\nA Fájl > Oldalbeállítás… az aktuális munkamenet papír-, tájolás- és "
                L"margóbeállításait nyitja meg. A Nyomtatás… (Ctrl+P) a rendszer nyomtatási "
                L"párbeszédpanelét nyitja meg; Windows 11 alatt előnézet is elérhető, Windows 10 és "
                L"régebbi rendszereken a hagyományos panel marad. A Ctrl+P a fókuszban lévő ablaktól "
                L"függően a főablak aktív lapját, a Súgó vagy a Névjegy szövegmezőjét nyomtatja. A "
                L"jelentések a választott jelentésbetűtípust, a Súgó a rendszer "
                L"párbeszédpanel-betűtípusát, a Névjegy pedig saját szövegmezőjének betűtípusát "
                L"használja. Ha nincs nyitott lap, de a Súgó nyitva van, az Oldalbeállítás… és a "
                L"Nyomtatás… továbbra is elérhető, és a Súgó nyomtatható. A Súgó a főablak nyomtatási "
                L"panelét használja; az ismételt Ctrl+P a Súgóban ugyanezt a panelt hozza előtérbe. A "
                L"hosszú sorok tördelődnek, a szöveg oldalakra oszlik. A nyomtatás a háttérben "
                L"történik.\r\nHúzzon egy vagy több fájlt az ablakra, az EXE ikonjára vagy "
                L"parancsikonjára, vagy adja meg az elérési útjukat a parancssorban. Ha több példány nem "
                L"engedélyezett, a fájlok a már futó ablakban nyílnak meg.\r\nAz állapotsor bal oldala a "
                L"fájlok elérési útját és a betöltés állapotát, a jobb oldala a betöltött MediaInfo.dll "
                L"verzióját mutatja. A hosszú elérési utak a rendelkezésre álló helyhez igazodva három "
                L"ponttal rövidülnek.\r\n\r\nEXPORTÁLÁS\r\nTXT, BMP, GIF, JPEG, PNG, TIFF és WebP az "
                L"elérhetőség szerint jelenik meg. Az utolsó exportmappa és formátum megmarad.\r\nA TXT "
                L"az ANSI, UTF-8, UTF-8 BOM-mal, UTF-16 BE BOM-mal és UTF-16 LE BOM-mal lehetőségeket "
                L"kínálja. Az alapértelmezett a második elem, az UTF-8 BOM nélkül. A jelentés teljes "
                L"szövege és eredeti sorvégei megmaradnak.\r\n\r\nFEJLÉCFÁJL LÉTREHOZÁSA\r\nAz Eszközök a "
                L"menüsor negyedik menüje. A Fejlécfájl létrehozása… parancsa egy forrásfájlt nyit meg a "
                L"jelentéslapoktól függetlenül, és átmásolja annak első 524288 bájtját (512 KiB). A "
                L"rövidebb fájlt teljes egészében másolja; egy üres fájl üres kimenetet ad. Ez egy "
                L"közönséges bináris fájlolvasás, MediaInfo elemzés vagy MediaInfo.dll követelmény "
                L"nélkül. Az eszköz változatlanul hagyja a jelentéslapokat és a megtekintő legutóbbi "
                L"fájlok listáját.\r\n\r\nAz olvasás után a Mentés másként párbeszédablak elindul a "
                L"forrásfájl mappájában, és a video.mp4.header fájlt javasolja a video.mp4 számára: a "
                L".header hozzá van fűzve a teljes eredeti névhez. Módosíthatja a nevet és a célmappát "
                L"is. Bármelyik párbeszédpanel megszakítása nem ír ki kimenetet. Meglévő célhely cseréje "
                L"megerősítést igényel. A forrás változatlan marad; a sikertelen mentés megőrzi az előző "
                L"célt. A megnyitás és a mentés az adott Windows-verzióban elérhető legkorszerűbb "
                L"rendszer-párbeszédpaneleket használja.\r\n\r\nAz alkalmazás indításakor az eszköz a "
                L"kezdeti beviteli mappát a Fájl > Megnyitás mappából veszi. Ha még nincs mentett mappa, "
                L"a Windows kiválasztja a kezdeti helyet. A bemeneti fájl kiválasztása után az eszköz "
                L"csak a saját mappájára emlékszik az alkalmazás kilépéséig, még akkor is, ha megszakítja "
                L"a Mentés másként párbeszédpanelt. Nem módosítja a Megnyitás és Exportálás által "
                L"használt mappákat, és nem menti el saját mappáját az alkalmazás beállításaihoz. Minden "
                L"Mentés másként párbeszédablak az aktuálisan kiválasztott beviteli fájl mappájában "
                L"kezdődik, függetlenül az előző mentési céltól.\r\n\r\nBEÁLLÍTÁSOK ÉS NYELVEK\r\nA "
                L"Beállítások (Beállítások > Beállítások, Ctrl+G) tartalmazza a könyvtárak útvonalát, a "
                L"jelentés betűtípusát, az élsimítást és a nyelveket. A felületnek 36 változata van, "
                L"kezdetben a Windowst követi. A jelentések alapértelmezése mindig a könyvtár eredeti "
                L"angol nyelve, a Windowstól és a felülettől függetlenül. Csak a kézi választás "
                L"változtatja meg: angol, 37 fordítás vagy saját MediaInfo CSV-tábla. Az OK vagy az "
                L"Alkalmaz véglegesíti a módosításokat; a Mégse elveti a függő módosításokat. A "
                L"Beállításokban korlátozható a lapnév hossza (alapérték 80), és törölhető a legutóbbi "
                L"fájlok listája. A hosszú nevek eleje, vége és kiterjesztése megmarad, középen három "
                L"ponttal. A Törlés azonnal eltávolítja a legutóbbi fájlok listáját, akkor is, ha a "
                L"Beállításokat ezután a Mégse gombbal zárja be.\r\n\r\nA főablak címsora az aktív fájlt "
                L"fájlnév — MediaInfo alakban mutatja. A beállításokban a címsorban lévő név hossza külön "
                L"állítható 8–255 karakterre (alapértelmezés: 40). A hosszabb nevek ugyanazzal a középre "
                L"helyezett három ponttal rövidülnek, a kiterjesztés megmarad. Ha nincs nyitott lap, a cím "
                L"MediaInfo.\r\n\r\nKÖNYVTÁRAK ÉS ABLAKOK\r\nAz EXE "
                L"MediaInfo 26.10, 21.03 és 0.7.60 változatokat tartalmaz; a külső könyvtárak után a "
                L"legújabbtól próbálja őket. A két újabbhoz megfelelő libcurl tartozik; a 0.7.60 soha nem "
                L"bontja ki. Az ablak helyzete megmarad. Alapértelmezés szerint csak egy példány "
                L"engedélyezett, és a későbbi indítások átadják a fájlokat a nyitott ablaknak. A "
                L"beállításokban több példány is engedélyezhető. Több ablak esetén csak az egyes "
                L"ablaktípusok első ablaka állítja vissza a mentett pozíciót; a továbbiak csak a "
                L"méretet.\r\n\r\nA Szerkesztés > Keresés (Ctrl+F) a fókuszban lévő ablaktól függően az "
                L"aktív jelentéslapon, a Súgó vagy a Névjegy szövegmezőjében keres. A keresőablak "
                L"megtartja az utoljára kiválasztott forrást, amíg nála van a fókusz. F3 megismétli a "
                L"keresést, a Shift+F3 pedig megfordítja az irányát. A szöveg végéhez érve a keresés a "
                L"másik végéről folytatódik. A Beállítások > Sortörés csak az aktív lapra érvényes; a "
                L"jelölés a kiválasztott lapot követi. A keresőablak kis méretre állítható és "
                L"vízszintesen átméretezhető; a helyzete és a Mindig felül beállítás megmarad. Legfeljebb "
                L"30 keresési szöveg és beállításaik csak az alkalmazás bezárásáig maradnak meg. A sor "
                L"elejére és végére vonatkozó beállítások logikai sorokra érvényesek. A reguláris "
                L"kifejezések PCRE2-szintaxist használnak. A Szerkesztés menü többi parancsa az aktív "
                L"jelentéslapra vonatkozik. Az Enter elindítja a keresést; a Shift+Enter megfordítja a "
                L"kiválasztott irányt. A „Kis- és nagybetűk megkülönböztetése” megkülönbözteti a kis- és "
                L"nagybetűket; a „Keresés visszafelé” a szöveg eleje felé keres. Egy előzmény "
                L"kiválasztása visszaállítja mind az öt keresési beállítást, beleértve a reguláris "
                L"kifejezések módjának állapotát is; a „Mindig felül” ettől független. A „Reguláris "
                L"kifejezés” letiltja a „Sor elején” és „Sor végén” beállításokat. Ha mindkét sorhatárra "
                L"vonatkozó feltétel be van kapcsolva, bármelyik sorhatáron elég az egyezés. A „Sortörés” "
                L"csak a megjelenítést módosítja."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"A WebP-kép nem menthető. Ellenőrizze a célt, a szabad memóriát és a lemezterületet."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Szöveges dokumentum UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Szöveges dokumentum UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Szöveges dokumentum UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Szöveges dokumentum UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"A jelentés nem menthető ezzel a kódolással karaktervesztés nélkül. Válasszon másik "
                L"szövegkódolást."
            },
            { TXT_OPEN_FOLDER, L"Ma&ppa megnyitása…" },
            { TXT_OPEN_FOLDER_TITLE, L"Mappa megnyitása" },
            { TXT_FOLDER_READ_FAILED, L"A mappa nem olvasható:\n\n%s\n\nWindows-hiba: %lu." },
            { TXT_ADVANCED_MODE, L"&Haladó mód" },
            { TXT_REPORT_DETAIL_REJECTED,
                L"A kiválasztott MediaInfo.dll elutasította a jelentés részletességi beállítását."
            },
            { TXT_KNOWN_FORMATS, L"Ismert &formátumok" },
            { TXT_KNOWN_CODECS, L"Ismert &kodekek" },
            { TXT_KNOWN_PARAMETERS, L"Ismert &paraméterek" },
            { TXT_KNOWN_FORMATS_TITLE, L"Ismert formátumok" },
            { TXT_KNOWN_CODECS_TITLE, L"Ismert kodekek" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Ismert paraméterek" },
            { TXT_KNOWN_INFO_FAILED, L"A könyvtár nem adta vissza a kért információkat." },
            { TXT_FULL_PARSING, L"&Teljes elemzés" },
            { TXT_PARSING_REJECTED, L"A kiválasztott MediaInfo.dll elutasította az elemzési beállítást." },
            { TXT_TRACE_LEVEL_0, L"Nyomkövetési szint &0" },
            { TXT_TRACE_LEVEL_5, L"Nyomkövetési szint &5" },
            { TXT_TRACE_LEVEL_9, L"Nyomkövetési szint &9" },
            { TXT_TRACE_LEVEL_10, L"Nyomkövetési szint &10" },
            { TXT_PAGE_SETUP, L"&Oldalbeállítás…" },
            { TXT_PAGE_SETUP_FAILED, L"Az oldalbeállítás nem nyitható meg." },
            { TXT_PRINT, L"&Nyomtatás…\tCtrl+P" },
            { TXT_PRINTING, L"Nyomtatás…" },
            { TXT_PRINT_FAILED,
                L"A szöveg nem nyomtatható. Ellenőrizze a nyomtatót, annak beállításait és a "
                L"rendelkezésre álló memóriát."
            },
            { TXT_TOOLS_MENU, L"&Eszközök" },
            { TXT_CREATE_HEADER, L"&Fejlécfájl létrehozása…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Fejlécfájl létrehozása - Megnyitás" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Fejlécfájl létrehozása - Mentés másként" },
            { TXT_HEADER_FORMAT, L"Fejlécfájl (*.header)" },
            { TXT_HEADER_READ_FAILED, L"A fájl fejléce nem olvasható:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"A fejlécfájl nem menthető:\n\n%s" },
            { TXT_COPY, L"&Másolás" },
            { TXT_COPY_FILE_NAME, L"Fájl&név másolása" },
            { TXT_COPY_FULL_PATH, L"Teljes elérési &út másolása" },
            { TXT_LAUNCH_FILE, L"&Fájl indítása" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"Me&gjelenítés mappában" },
            { TXT_EDIT_MENU, L"S&zerkesztés" },
            { TXT_WORD_WRAP, L"&Sortörés" },
            { TXT_WORD_WRAP_FAILED, L"A sortörést nem sikerült módosítani." },
            { TXT_COPY_SELECTION, L"&Másolás\tCtrl+C" },
            { TXT_SELECT_ALL, L"&Az összes kijelölése\tCtrl+A" },
            { TXT_FIND_MENU, L"&Keresés…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Kö&vetkező keresése\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"&Előző keresése\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Keresés" },
            { TXT_FIND_WHAT, L"Keresendő &szöveg:" },
            { TXT_FIND_NEXT, L"Kö&vetkező keresése" },
            { TXT_FIND_MATCH_CASE, L"Kis- és &nagybetűk megkülönböztetése" },
            { TXT_FIND_BACKWARD, L"Keresés v&isszafelé" },
            { TXT_FIND_TOPMOST, L"Mindig &felül" },
            { TXT_FIND_STARTS_WITH, L"Sor &elején" },
            { TXT_FIND_ENDS_WITH, L"Sor vé&gén" },
            { TXT_FIND_REGEX, L"&Reguláris kifejezés" },
            { TXT_FIND_NOT_FOUND, L"A megadott szöveg nem található." },
            { TXT_FIND_FAILED, L"A keresést nem sikerült befejezni." },
            { TXT_FIND_REGEX_ERROR, L"Hiba a reguláris kifejezésben:\r\n\r\n%s" },
        }
    },
    {
        LANG_MT,
        {
            { TXT_LANGUAGE_NAME, L"Malti" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nSit web: " },
            { TXT_FILE_OPEN_FAILED, L"Ma jistax jinfetaħ %s. Iċċekkja l-mogħdija u l-permessi." },
            { TXT_BROWSE_DLL, L"&Ibbrawżja…" },
            { TXT_BROWSE_REPORT, L"Ibbra&wżja…" },
            { TXT_CLOSE, L"&Agħlaq" },
            { TXT_CLOSE_TAB, L"&Agħlaq\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"Pre&definit" },
            { TXT_EXPORT, L"&Esporta…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Fajl" },
            { TXT_REPORT_FONT, L"&Font tar-rapport:" },
            { TXT_HELP_MENU, L"&Għajnuna" },
            { TXT_HELP, L"&Għajnuna\tF1" },
            { TXT_LANGUAGE, L"&Lingwa:" },
            { TXT_OPEN_WEBSITE, L"&Iftaħ fil-brawżer predefinit" },
            { TXT_OPEN, L"&Iftaħ…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"G&ħażliet" },
            { TXT_PREFERENCES_MENU, L"&Preferenzi…\tCtrl+G" },
            { TXT_ABOUT, L"&Dwar" },
            { TXT_ABOUT_TITLE, L"Dwar %ls" },
            { TXT_ALL_FILES, L"Il-fajls kollha" },
            { TXT_FONT_BOLD, L"Grassett" },
            { TXT_FONT_BOLD_ITALIC, L"Grassett + Korsiv" },
            { TXT_BROWSE_CURL, L"I&bbrawżja…" },
            { TXT_CANCEL, L"Ikkanċella" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Ma tistax titgħabba MediaInfo.dll (żball ta’ Windows %lu). Uża DLL ta’ 32 bit kompatibbli "
                L"ma’ din il-verżjoni ta’ Windows."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Ma tistax titgħabba libcurl.dll (żball ta’ Windows %lu). Agħżel librerija ta’ 32 bit "
                L"kompatibbli ma’ din il-verżjoni ta’ Windows."
            },
            { TXT_CLOSE_ALL, L"Agħlaq &kollox" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Ikkopja l-i&ndirizz" },
            { TXT_COPY_INFORMATION, L"Ikkopja l-in&formazzjoni" },
            { TXT_DLL_FILES, L"Libreriji dinamiċi" },
            { TXT_EXIT, L"&Oħroġ\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Libreriji inkorporati MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Libreriji inkorporati libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Esporta rapport" },
            { TXT_FONT_ANTIALIASING, L"A&nti-aliasing tal-font:" },
            { TXT_GIF_EXPORT_FAILED,
                L"L-esportazzjoni GIF falliet. GIF mingħajr telf jeħtieġ mhux aktar minn 256 kulur."
            },
            { TXT_FONT_ITALIC, L"Korsiv" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED,
                L"L-esportazzjoni JPEG falliet. Jeħtieġ kodifikatur JPEG GDI+ li jaħdem."
            },
            { TXT_LICENSE_UNAVAILABLE, L"Ir-riżorsa tal-liċenzja mhijiex disponibbli." },
            { TXT_MEDIA_FILES, L"Fajls tal-midja" },
            { TXT_APPLICATION_DESCRIPTION, L"Viżwalizzatur tal-informazzjoni tal-midja" },
            { TXT_HELP_TITLE, L"MediaInfo — Għajnuna" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo ma setax jinizjalizza l-analiżi tal-fajl." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo ma jistax jiftaħ jew jagħraf dan il-fajl." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"&Mogħdija ta’ MediaInfo.dll:" },
            { TXT_MEDIALIB_REQUIRED,
                L"MediaInfo.dll mhijiex mgħobbija. Agħżilha minn Għażliet > Preferenzi."
            },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll mhijiex mgħobbija." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Ma setgħetx titgħabba MediaInfo.dll esterna jew inkorporata kompatibbli. Agħżilha minn "
                L"Għażliet > Preferenzi."
            },
            { TXT_ANTIALIASING_NONE, L"Xejn" },
            { TXT_OK, L"OK" },
            { TXT_OPEN_TITLE, L"Iftaħ fajls tal-midja" },
            { TXT_PLATFORM, L"Pjattaforma fil-mira:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Preferenzi" },
            { TXT_READY, L"Lest" },
            { TXT_FONT_REGULAR, L"Normali" },
            { TXT_REPORT_LANGUAGE, L"Lingwa tar-&rapport:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Tabelli tal-lingwa tar-rapporti" },
            { TXT_SELECT_MEDIALIB, L"Ibbrawżja: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Ibbrawżja: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH, L"Agħżel fajl tal-midja eżistenti b’mogħdija iqsar minn MAX_PATH." },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Agħżel fajls eżistenti b’mogħdijiet iqsar minn MAX_PATH." },
            { TXT_SELECT_CURL, L"Ibbrawżja: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Dokument testwali ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"L-immaġni BMP ma tistax tiġi ssejvjata. Iċċekkja d-destinazzjoni, il-memorja ħielsa u "
                L"l-ispazju fuq id-diska."
            },
            { TXT_LIBRARY_WORKER_START_FAILED,
                L"Il-proċess tal-librerija ma jistax jinbeda (żball ta’ Windows %lu)."
            },
            { TXT_REPORT_COPY_FAILED, L"Ir-rapport MediaInfo ma jistax jiġi kkupjat fil-memorja." },
            { TXT_VIEWER_CREATE_FAILED, L"Il-viżwalizzatur MediaInfo ma jistax jinħoloq." },
            { TXT_MEDIALIB_PATH_INVALID,
                L"Il-mogħdija ta’ MediaInfo.dll mhijiex valida jew hija twila wisq."
            },
            { TXT_PNG_EXPORT_FAILED,
                L"L-immaġni PNG ma tistax tiġi ssejvjata. Iċċekkja d-destinazzjoni, il-memorja ħielsa u "
                L"l-ispazju fuq id-diska."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"L-immaġni TIFF ma tistax tiġi ssejvjata. Iċċekkja d-destinazzjoni, il-memorja ħielsa u "
                L"l-ispazju fuq id-diska."
            },
            { TXT_COPY_URL_FAILED, L"Il-URL ma setax jiġi kkupjat fil-clipboard." },
            { TXT_LIBRARY_REQUIRES_X86, L"Il-viżwalizzatur Win32 jeħtieġ %s ta’ 32 bit. Agħżel "
                L"il-librerija x86/i386." },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Il-librerija inkorporata ma tistax tinkiteb f’AppData, fil-profil tal-utent, f’Program "
                L"Files jew fil-fowlder temporanju."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED,
                L"Id-dekompressjoni jew il-verifika CRC tal-librerija falliet."
            },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Ir-riżorsa tal-librerija inkorporata mhijiex valida." },
            { TXT_CURL_FILENAME_INVALID,
                L"Il-librerija trid tissejjaħ libcurl.dll biex MediaInfo jkun jista’ jużaha."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Id-djalogu tal-fajls ma setax jinfetaħ." },
            { TXT_FILE_DIALOG_SELECTION_FAILED,
                L"Il-fajls magħżula ma setgħux jinkisbu mid-djalogu tal-fajls."
            },
            { TXT_RECENT_FILE_MISSING,
                L"Il-fajl “%s” m’għadux jeżisti.\n\nTrid tneħħi din l-entrata mil-lista tal-fajls riċenti?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Il-fajl m’għadux disponibbli:\n\n%s\n\nTrid tneħħi din l-entrata mil-lista tal-fajls "
                L"riċenti?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"L-informazzjoni ma setgħetx tiġi kkupjata fil-clipboard." },
            { TXT_CURL_PATH_INVALID, L"Il-mogħdija ta’ libcurl.dll mhijiex valida jew hija twila wisq." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Il-librerija ma rritornatx verżjoni ta’ MediaInfo." },
            { TXT_CURL_EXPORTS_MISSING,
                L"Il-librerija ma tesportax il-funzjonijiet curl meħtieġa minn MediaInfo."
            },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"Il-librerija ma tesportax il-funzjonijiet Unicode meħtieġa ta’ MediaInfo."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Il-proċess tal-librerija falla waqt %s (kodiċi 0x%08lX). Agħżel DLL kompatibbli minn "
                L"Għażliet > Preferenzi."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Il-proċess tal-librerija ma jirrispondix waqt %s. Agħżel DLL kompatibbli minn Għażliet > "
                L"Preferenzi."
            },
            { TXT_PREFERENCES_SAVE_FAILED,
                L"Il-preferenzi ġew applikati iżda ma ġewx issejvjati fir-reġistru."
            },
            { TXT_REPORT_START_FAILED, L"M’hemmx memorja biżżejjed biex jinbeda r-rapport." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"L-immaġni tar-rapport ma tistax tinħoloq." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"It-tabella tal-lingwa ma tistax titgħabba. Agħżel fajl "
                L"MediaInfo CSV validu f’UTF-8 jew UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"Il-ħajta tar-rapport ma tistax tinbeda." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"Il-MediaInfo.dll magħżula rrifjutat il-lingwa tar-rapport." },
            { TXT_INVALID_WINDOWS_DLL, L"Il-fajl magħżul mhuwiex DLL valida ta’ Windows." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Il-format tal-immaġni magħżul mhuwiex appoġġjat." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Ir-rapport testwali ma jistax jiġi ssejvjat. Iċċekkja d-destinazzjoni u l-ispazju ħieles "
                L"fuq id-diska."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Is-sit ma jistax jinfetaħ fil-brawżer predefinit." },
            { TXT_TOO_MANY_FILES, L"Intgħażlu wisq fajls. Iftaħ gruppi iżgħar." },
            { TXT_LIBRARY_PATH_HINT,
                L"Uża libreriji ta’ 32 bit kompatibbli mal-verżjoni tiegħek ta’ Windows. Ħalli l-mogħdijiet "
                L"vojta għat-tiftix awtomatiku. MediaInfoLib v0.7.60 ma jużax libcurl.dll."
            },
            { TXT_VERSION, L"Verżjoni" },
            { TXT_WEBSITE_TOOLTIP, L"Iftaħ is-sit web %s" },
            { TXT_WAITING_FOR_REPORT, L"Qed jistenna li jispiċċa r-rapport attwali." },
            { TXT_WEBSITE_LABEL, L"Sit web:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"l-ikkupjar tar-rapport MediaInfo" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"Mogħdija ta’ libc&url.dll:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"it-tagħbija ta’ MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"it-tagħbija ta’ libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"il-ħatt ta’ MediaInfo.dll" },
            { TXT_APPLY, L"&Applika" },
            { TXT_TAB_NAME_LENGTH, L"&Tul tal-isem tat-tab:" },
            { TXT_TITLE_NAME_LENGTH, L"T&ul tat-titlu:" },
            { TXT_RECENT_FILES, L"Fajls riċenti:" },
            { TXT_CLEAR_RECENT_FILES, L"&Ħassar" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"It-tul tal-isem tat-tab irid ikun bejn 8 u 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"It-tul tal-isem fit-titlu jrid ikun bejn 8 u 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Il-lista tal-fajls riċenti tħassret, iżda ma setgħetx tiġi ssejvjata fir-reġistru."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"A&għlaq it-tabs b’ikklikkjar doppju" },
            { TXT_CLOSE_TAB_CONTEXT, L"Agħlaq it-&tab" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"I&ppermetti diversi istanzi" },
            { TXT_INSTANCE_FORWARD_FAILED,
                L"Ma setgħux jintbagħtu l-fajls lill-istanza ta’ MediaInfo li qed taħdem."
            },
            { TXT_LOADING, L"Qed jitgħabba…" },
            { TXT_LOADING_FILE, L"Qed jitgħabba l-fajl %s…" },
            { TXT_APPLICATION_HELP,
                L"FAJLS U TABS\r\nViżwalizzatur nattiv ta’ Windows x86 għar-rapporti ta’ MediaInfo.dll. "
                L"Kull fajl għandu tab tiegħu għall-qari biss. Iftaħ b’Ctrl+O jew iddreggja l-fajls "
                L"fit-tieqa. Il-ftuħ mill-ġdid jagħżel it-tab eżistenti. B’Ctrl+W jew bil-buttuna "
                L"tan-nofs tal-maws tista’ tagħlaq tab; Agħlaq kollox jagħlaq it-tabs kollha. Il-menu "
                L"Fajl jiftakar tmien fajls riċenti. Il-menu tal-kuntest tal-intestatura ta’ tab jinkludi "
                L"Agħlaq it-tab. Attiva Agħlaq it-tabs b’ikklikkjar doppju fil-Preferenzi biex tagħlaq "
                L"tab billi tikklikkja darbtejn fuq l-intestatura tagħha. L-għażla hija mitfija b’mod "
                L"predefinit u tinżamm. Ikklikkjar doppju fit-test tar-rapport jagħżel kelma. Tliet "
                L"klikks jagħżlu linja loġika. It-tkaxkir jestendi l-għażla b’kliem jew linji.\r\nIftaħ "
                L"fowlder… jiftaħ il-fajls li jinsabu direttament fil-fowlder magħżul, kull wieħed "
                L"fit-tab tiegħu. Is-subfowlders mhumiex inklużi.\r\nIftaħ u Iftaħ fowlder jużaw l-istess "
                L"fowlder magħżul l-aħħar. L-esportazzjoni tiftakar il-fowlder tagħha, Dokumenti b’mod "
                L"predefinit. Il-modalità avvanzata turi oqsma addizzjonali fir-rapport.\r\nFormati "
                L"magħrufa / Codecs magħrufa / Parametri magħrufa — MediaInfo.dll.\r\nAnaliżi sħiħa "
                L"teżamina l-fajl kollu u tista’ tieħu aktar żmien. Dawn l-għażliet tar-rapport u Livell "
                L"ta’ traċċar huma separati għal kull tab; bidla taġġorna biss it-tab attiva. L-aħħar "
                L"kombinazzjoni magħżula manwalment tiġi ssejvjata għal tabs ġodda u għall-ftuħ "
                L"tal-applikazzjoni li jmiss. Rapport korrispondenti fil-cache jerġa’ jintuża sakemm "
                L"il-fajl ma jkunx inbidel.\r\nLivell ta’ traċċar: 0 / 5 / 9 / 10.\r\nFajl > Issettjar "
                L"tal-Paġna… jiftaħ l-għażliet tal-karta, l-orjentazzjoni u l-marġini għas-sessjoni "
                L"attwali. Stampa… (Ctrl+P) jiftaħ id-djalogu tal-istampar tas-sistema; Windows 11 juri "
                L"previżjoni, filwaqt li Windows 10 u verżjonijiet eqdem iżommu d-djalogu klassiku. "
                L"Ctrl+P jistampa t-tab attiva tat-tieqa ewlenija jew iż-żona tat-test ta’ Għajnuna jew "
                L"Dwar, skont liema tieqa għandha l-fokus. Ir-rapporti jużaw it-tipa magħżula "
                L"għar-rapport, Għajnuna tuża t-tipa tad-djalogi tas-sistema u Dwar juża t-tipa taż-żona "
                L"tat-test tiegħu. Jekk ma hemmx tabs miftuħa iżda Għajnuna hija miftuħa, Issettjar "
                L"tal-Paġna… u Stampa… jibqgħu disponibbli; Stampa… jistampa l-għajnuna. Għajnuna tuża "
                L"d-djalogu tal-istampar tat-tieqa ewlenija; Ctrl+P ieħor f’Għajnuna jġib l-istess "
                L"djalogu fuq quddiem. Il-linji twal jitqassmu u t-test jinqasam f’paġni. L-istampar isir "
                L"fl-isfond.\r\nIddreggja fajl wieħed jew aktar fit-tieqa, fuq l-ikona tal-EXE jew fuq "
                L"ix-shortcut tiegħu, jew għaddi l-mogħdijiet mil-linja tal-kmand. Jekk ma jkunux "
                L"permessi diversi istanzi, il-fajls jinfetħu fit-tieqa li diġà qed taħdem.\r\nIn-naħa "
                L"tax-xellug tal-istrixxa tal-istatus turi l-mogħdijiet tal-fajls u l-progress "
                L"tat-tagħbija; in-naħa tal-lemin turi l-verżjoni ta’ MediaInfo.dll mgħobbija. Mogħdijiet "
                L"twal jitqassru b’punti ta’ sospensjoni skont l-ispazju disponibbli.\r\n\r\n"
                L"ESPORTAZZJONI\r\nTXT, BMP, GIF, JPEG, PNG, TIFF u WebP jidhru meta jkunu disponibbli. "
                L"L-aħħar fowlder u format tal-esportazzjoni jinżammu.\r\nTXT joffri ANSI, UTF-8, UTF-8 "
                L"b’BOM, UTF-16 BE b’BOM u UTF-16 LE b’BOM. It-tieni għażla, UTF-8 mingħajr BOM, hija dik "
                L"predefinita. It-test sħiħ tar-rapport u t-truf tal-linji oriġinali jinżammu.\r\n\r\n"
                L"OĦLOQ FAJL TAL-INTESTATURA\r\nIl-menu Għodod huwa r-raba’ fil-bar tal-menus. Il-kmand "
                L"Oħloq Fajl tal-Intestatura… jiftaħ fajl tad-dħul wieħed indipendentement mit-tabs "
                L"tar-rapport u jikkopja l-ewwel 524288 byte tiegħu (512 KiB). Fajl iqsar jiġi kkupjat "
                L"kollu; fajl vojt jipproduċi fajl tal-ħruġ vojt. Dan huwa qari binarju ordinarju "
                L"tal-fajl, mingħajr analiżi ta’ MediaInfo u mingħajr il-ħtieġa ta’ MediaInfo.dll. "
                L"L-għodda ma tbiddilx it-tabs tar-rapport jew il-lista tal-fajls reċenti "
                L"tal-programm.\r\n\r\nWara l-qari, id-djalogu Issejvja bħala jiftaħ fil-fowlder tal-fajl "
                L"tad-dħul u jipproponi video.mp4.header għal video.mp4: .header jiżdied mal-isem "
                L"oriġinali sħiħ. Tista’ tibdel kemm l-isem kif ukoll il-fowlder tad-destinazzjoni. Jekk "
                L"tikkanċella kwalunkwe wieħed mid-djalogi, ma jinkiteb ebda fajl tal-ħruġ. Biex jinbidel "
                L"fajl tad-destinazzjoni eżistenti hemm bżonn konferma. Il-fajl tad-dħul jibqa’ l-istess; "
                L"jekk l-issejvjar ifalli, il-fajl tad-destinazzjoni preċedenti jibqa’ l-istess. "
                L"Għall-ftuħ u l-issejvjar jintużaw l-aktar djalogi tas-sistema moderni disponibbli f’dik "
                L"il-verżjoni tal-Windows.\r\n\r\nMeta tibda l-applikazzjoni, l-għodda tieħu l-istess "
                L"fowlder inizjali bħal Fajl > Iftaħ. Jekk ma jkun hemm ebda fowlder issejvjat, Windows "
                L"jagħżel il-post inizjali. Wara li jintgħażel fajl tad-dħul, l-għodda tiftakar "
                L"il-fowlder tagħha biss sakemm tingħalaq l-applikazzjoni, anki jekk tikkanċella Issejvja "
                L"bħala. Ma tbiddilx il-fowlders ta’ Iftaħ u Esporta u ma tissejvjax il-fowlder tagħha "
                L"fl-issettjar tal-applikazzjoni. Kull djalogu Issejvja bħala jibda fil-fowlder tal-fajl "
                L"tad-dħul magħżul bħalissa, irrispettivament mid-destinazzjoni preċedenti.\r\n\r\n"
                L"PREFERENZI U LINGWI\r\nIl-preferenzi (Għażliet > Preferenzi, Ctrl+G) fihom "
                L"il-mogħdijiet tal-libreriji, il-font tar-rapport, l-antialiasing u l-lingwi. "
                L"L-interfaċċa għandha 36 varjant u inizjalment issegwi Windows. Ir-rapporti dejjem jużaw "
                L"l-Ingliż oriġinali tal-librerija b’mod predefinit, indipendentement minn Windows u "
                L"l-interfaċċa. Għażla manwali biss tibdlu: Ingliż, 37 traduzzjoni jew tabella CSV "
                L"MediaInfo personalizzata. OK jew Applika jikkonferma l-bidliet; Ikkanċella jwarrab dawk "
                L"pendenti. Il-preferenzi jissettjaw il-limitu tat-tul tal-isem tat-tab (80 b’mod "
                L"predefinit) u jħassru l-lista tal-fajls riċenti. Ismijiet twal iżommu l-bidu, it-tmiem "
                L"u l-estensjoni b’ellissi fin-nofs. Ħassar ineħħi l-lista tal-fajls riċenti "
                L"immedjatament, anki jekk imbagħad tagħlaq il-preferenzi b’Ikkanċella.\r\n\r\nIt-titlu "
                L"tat-tieqa prinċipali juri l-fajl attiv fil-forma isem tal-fajl — MediaInfo. Fil-preferenzi "
                L"tista’ tissettja separatament it-tul tal-isem fit-titlu minn 8 sa 255 karattru (40 b’mod "
                L"predefinit). Ismijiet itwal jitqassru bl-istess tliet tikek fin-nofs u jżommu l-estensjoni."
                L" Mingħajr tabs miftuħin, it-titlu huwa MediaInfo.\r\n\r\nLIBRERIJI "
                L"U TWIEQI\r\nIl-programm jinkludi MediaInfo 26.10, 21.03 u 0.7.60, li jiġu ppruvati "
                L"mill-aktar ġdida wara l-libreriji esterni. Iż-żewġ verżjonijiet ġodda għandhom libcurl "
                L"adattata; 0.7.60 qatt ma toħroġ libcurl. Il-pożizzjoni tat-tieqa tinżamm. B’mod "
                L"awtomatiku hija permessa istanza waħda biss u tnedijiet sussegwenti jibagħtu l-fajls "
                L"lit-tieqa miftuħa. Fil-preferenzi tista’ tippermetti diversi istanzi. B’diversi twieqi, "
                L"l-ewwel tieqa ta’ kull tip ta’ tieqa biss tirrestawra l-pożizzjoni ssejvjata; it-twieqi "
                L"ta’ wara jirrestawraw biss id-daqs.\r\n\r\nEditja > Sib (Ctrl+F) ifittex fit-tab "
                L"tar-rapport attiva jew fiż-żona tat-test ta’ Għajnuna jew Dwar, skont liema tieqa "
                L"għandha l-fokus. It-tieqa tat-tiftix iżżomm l-aħħar sors magħżul waqt li għandha "
                L"l-fokus. F3 jirrepeti t-tfittxija; Shift+F3 jaqleb id-direzzjoni tagħha. Meta jintlaħaq "
                L"tarf tat-test, it-tfittxija tkompli mit-tarf l-ieħor. Għażliet > Kebbeb il-kliem "
                L"japplika biss għat-tab attiva; il-marka ssegwi t-tab magħżula. It-tieqa tat-tfittxija "
                L"tista’ tiġi minimizzata u jinbidel il-wisa’ tagħha; il-pożizzjoni u l-għażla Dejjem fuq "
                L"nett jinżammu. Sa 30 test tat-tfittxija bl-għażliet tagħhom jinżammu biss sakemm "
                L"tingħalaq l-applikazzjoni. L-għażliet tal-bidu u tat-tmiem japplikaw għal-linji loġiċi. "
                L"L-espressjonijiet regolari jużaw is-sintassi ta’ PCRE2. Il-kmandi l-oħra fil-menu "
                L"Editja japplikaw għat-tab tar-rapport attiva. Enter jibda t-tfittxija; Shift+Enter "
                L"jaqleb id-direzzjoni magħżula. “Iddistingwi ittri kbar u żgħar” tiddistingwi bejn ittri "
                L"kbar u żgħar; “Fittex lura” tfittex lejn il-bidu tat-test. Meta tagħżel entrata "
                L"mill-istorja, jerġgħu jiġu applikati l-ħames għażliet tat-tfittxija, inkluż l-istat "
                L"tal-modalità tal-espressjonijiet regolari; “Dejjem fuq nett” hija indipendenti. "
                L"“Espressjoni regolari” tiddiżattiva “Il-linja tibda bi” u “Il-linja tispiċċa bi”. Meta "
                L"ż-żewġ għażliet tat-truf tal-linja jkunu attivi, biżżejjed qbil f’tarf wieħed. “Kebbeb "
                L"il-kliem” tbiddel biss il-wiri."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"L-immaġni WebP ma tistax tiġi ssejvjata. Iċċekkja d-destinazzjoni, il-memorja ħielsa u "
                L"l-ispazju fuq id-diska."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Dokument testwali UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Dokument testwali UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Dokument testwali UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Dokument testwali UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Ir-rapport ma jistax jiġi ssejvjat b’din il-kodifikazzjoni mingħajr telf ta’ karattri. "
                L"Agħżel kodifikazzjoni oħra."
            },
            { TXT_OPEN_FOLDER, L"Iftaħ &fowlder…" },
            { TXT_OPEN_FOLDER_TITLE, L"Iftaħ fowlder" },
            { TXT_FOLDER_READ_FAILED, L"Il-fowlder ma setax jinqara:\n\n%s\n\nŻball tal-Windows %lu." },
            { TXT_ADVANCED_MODE, L"Modalità &avvanzata" },
            { TXT_REPORT_DETAIL_REJECTED,
                L"Il-MediaInfo.dll magħżula rrifjutat l-issettjar tad-dettall tar-rapport."
            },
            { TXT_KNOWN_FORMATS, L"&Formati magħrufa" },
            { TXT_KNOWN_CODECS, L"&Codecs magħrufa" },
            { TXT_KNOWN_PARAMETERS, L"&Parametri magħrufa" },
            { TXT_KNOWN_FORMATS_TITLE, L"Formati magħrufa" },
            { TXT_KNOWN_CODECS_TITLE, L"Codecs magħrufa" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Parametri magħrufa" },
            { TXT_KNOWN_INFO_FAILED, L"Il-librerija ma tatx l-informazzjoni mitluba." },
            { TXT_FULL_PARSING, L"Analiżi &sħiħa" },
            { TXT_PARSING_REJECTED, L"Il-MediaInfo.dll magħżula rrifjutat l-issettjar tal-analiżi." },
            { TXT_TRACE_LEVEL_0, L"Livell ta’ traċċar &0" },
            { TXT_TRACE_LEVEL_5, L"Livell ta’ traċċar &5" },
            { TXT_TRACE_LEVEL_9, L"Livell ta’ traċċar &9" },
            { TXT_TRACE_LEVEL_10, L"Livell ta’ traċċar &10" },
            { TXT_PAGE_SETUP, L"Issettjar tal-&Paġna…" },
            { TXT_PAGE_SETUP_FAILED, L"Ma setax jinfetaħ l-issettjar tal-paġna." },
            { TXT_PRINT, L"&Stampa…\tCtrl+P" },
            { TXT_PRINTING, L"Qed jistampa…" },
            { TXT_PRINT_FAILED,
                L"It-test ma setax jiġi stampat. Iċċekkja l-printer, l-issettjar tiegħu u l-memorja "
                L"disponibbli."
            },
            { TXT_TOOLS_MENU, L"Għ&odod" },
            { TXT_CREATE_HEADER, L"Oħloq Fajl tal-&Intestatura…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Oħloq Fajl tal-Intestatura - Iftaħ" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Oħloq Fajl tal-Intestatura - Issejvja bħala" },
            { TXT_HEADER_FORMAT, L"Fajl tal-Intestatura (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Ma setgħetx tinqara l-intestatura tal-fajl:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Ma setax jiġi ssejvjat il-fajl tal-intestatura:\n\n%s" },
            { TXT_COPY, L"&Ikkopja" },
            { TXT_COPY_FILE_NAME, L"Ikkopja &isem il-fajl" },
            { TXT_COPY_FULL_PATH, L"Ikkopja l-&mogħdija sħiħa" },
            { TXT_LAUNCH_FILE, L"&Niedi l-fajl" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"&Uri fil-fowlder" },
            { TXT_EDIT_MENU, L"&Editja" },
            { TXT_WORD_WRAP, L"&Kebbeb il-kliem" },
            { TXT_WORD_WRAP_FAILED, L"It-tgeżwir tal-kliem ma setax jinbidel." },
            { TXT_COPY_SELECTION, L"I&kkopja\tCtrl+C" },
            { TXT_SELECT_ALL, L"&Agħżel kollox\tCtrl+A" },
            { TXT_FIND_MENU, L"&Sib…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Sib li &jmiss\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Sib ta' &qabel\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Sib" },
            { TXT_FIND_WHAT, L"Test biex &issib:" },
            { TXT_FIND_NEXT, L"Sib li &jmiss" },
            { TXT_FIND_MATCH_CASE, L"Iddistingwi ittri kbar u &żgħar" },
            { TXT_FIND_BACKWARD, L"Fittex &lura" },
            { TXT_FIND_TOPMOST, L"Dejjem fuq &nett" },
            { TXT_FIND_STARTS_WITH, L"Il-linja &tibda bi" },
            { TXT_FIND_ENDS_WITH, L"Il-linja tispiċċa &bi" },
            { TXT_FIND_REGEX, L"Espressjoni &regolari" },
            { TXT_FIND_NOT_FOUND, L"It-test speċifikat ma nstabx." },
            { TXT_FIND_FAILED, L"It-tfittxija ma setgħetx titlesta." },
            { TXT_FIND_REGEX_ERROR, L"Żball fl-espressjoni regolari:\r\n\r\n%s" },
        }
    },
    {
        LANG_NL,
        {
            { TXT_LANGUAGE_NAME, L"Nederlands" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nWebsite: " },
            { TXT_FILE_OPEN_FAILED, L"Kan %s niet openen. Controleer het pad en de machtigingen." },
            { TXT_BROWSE_DLL, L"&Bladeren…" },
            { TXT_BROWSE_REPORT, L"Bla&deren…" },
            { TXT_CLOSE, L"&Sluiten" },
            { TXT_CLOSE_TAB, L"&Sluiten\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"&Standaard" },
            { TXT_EXPORT, L"&Exporteren…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Bestand" },
            { TXT_REPORT_FONT, L"Rapportletter&type:" },
            { TXT_HELP_MENU, L"&Help" },
            { TXT_HELP, L"&Help\tF1" },
            { TXT_LANGUAGE, L"T&aal:" },
            { TXT_OPEN_WEBSITE, L"&Openen in standaardbrowser" },
            { TXT_OPEN, L"&Openen…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Opties" },
            { TXT_PREFERENCES_MENU, L"&Voorkeuren…\tCtrl+G" },
            { TXT_ABOUT, L"&Info" },
            { TXT_ABOUT_TITLE, L"Info over %ls" },
            { TXT_ALL_FILES, L"Alle bestanden" },
            { TXT_FONT_BOLD, L"Vet" },
            { TXT_FONT_BOLD_ITALIC, L"Vet + Cursief" },
            { TXT_BROWSE_CURL, L"B&laderen…" },
            { TXT_CANCEL, L"Annuleren" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Kan MediaInfo.dll niet laden (Windows-fout %lu). Gebruik een 32-bits DLL die compatibel is "
                L"met deze Windows-versie."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Kan libcurl.dll niet laden (Windows-fout %lu). Kies een 32-bits bibliotheek die compatibel "
                L"is met deze Windows-versie."
            },
            { TXT_CLOSE_ALL, L"A&lles sluiten" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"&Adres kopiëren" },
            { TXT_COPY_INFORMATION, L"&Informatie kopiëren" },
            { TXT_DLL_FILES, L"Dynamische bibliotheken" },
            { TXT_EXIT, L"&Afsluiten\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Ingesloten bibliotheken MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Ingesloten bibliotheken libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Rapport exporteren" },
            { TXT_FONT_ANTIALIASING, L"Lettertype&vereffening:" },
            { TXT_GIF_EXPORT_FAILED,
                L"GIF-export mislukt. GIF zonder verlies vereist maximaal 256 kleuren."
            },
            { TXT_FONT_ITALIC, L"Cursief" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED, L"JPEG-export mislukt. Een werkende GDI+-JPEG-encoder is vereist." },
            { TXT_LICENSE_UNAVAILABLE, L"De licentiebron is niet beschikbaar." },
            { TXT_MEDIA_FILES, L"Mediabestanden" },
            { TXT_APPLICATION_DESCRIPTION, L"Viewer voor media-informatie" },
            { TXT_HELP_TITLE, L"MediaInfo — Help" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo kon de bestandsanalyse niet initialiseren." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo kan dit bestand niet openen of herkennen." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"MediaInfo.dll-&pad:" },
            { TXT_MEDIALIB_REQUIRED,
                L"MediaInfo.dll is niet geladen. Selecteer deze via Opties > Voorkeuren."
            },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll is niet geladen." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Geen compatibele externe of ingesloten MediaInfo.dll kon worden geladen. Selecteer deze "
                L"via Opties > Voorkeuren."
            },
            { TXT_ANTIALIASING_NONE, L"Geen" },
            { TXT_OK, L"OK" },
            { TXT_OPEN_TITLE, L"Mediabestanden openen" },
            { TXT_PLATFORM, L"Doelplatform:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Voorkeuren" },
            { TXT_READY, L"Gereed" },
            { TXT_FONT_REGULAR, L"Normaal" },
            { TXT_REPORT_LANGUAGE, L"&Rapporttaal:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Rapporttaaltabellen" },
            { TXT_SELECT_MEDIALIB, L"Bladeren: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Bladeren: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH,
                L"Selecteer een bestaand mediabestand met een pad dat korter is dan MAX_PATH."
            },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Selecteer bestaande bestanden met paden korter dan MAX_PATH." },
            { TXT_SELECT_CURL, L"Bladeren: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Tekstdocument ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"Kan de BMP-afbeelding niet opslaan. Controleer doel, vrij geheugen en schijfruimte."
            },
            { TXT_LIBRARY_WORKER_START_FAILED,
                L"Kan het bibliotheekproces niet starten (Windows-fout %lu)."
            },
            { TXT_REPORT_COPY_FAILED, L"Kan het MediaInfo-rapport niet naar het geheugen kopiëren." },
            { TXT_VIEWER_CREATE_FAILED, L"Kan de MediaInfo-viewer niet maken." },
            { TXT_MEDIALIB_PATH_INVALID, L"Het pad naar MediaInfo.dll is ongeldig of te lang." },
            { TXT_PNG_EXPORT_FAILED,
                L"Kan de PNG-afbeelding niet opslaan. Controleer doel, vrij geheugen en schijfruimte."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"Kan de TIFF-afbeelding niet opslaan. Controleer doel, vrij geheugen en schijfruimte."
            },
            { TXT_COPY_URL_FAILED, L"De URL kon niet naar het klembord worden gekopieerd." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"De Win32-viewer vereist een 32-bits %s. Selecteer de x86/i386-bibliotheek."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Kan de ingesloten bibliotheek niet schrijven naar AppData, het gebruikersprofiel, Program "
                L"Files of de tijdelijke map."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED,
                L"Decompressie of CRC-controle van de bibliotheek is mislukt."
            },
            { TXT_LIBRARY_RESOURCE_INVALID, L"De ingesloten bibliotheekbron is ongeldig." },
            { TXT_CURL_FILENAME_INVALID,
                L"De bibliotheek moet libcurl.dll heten zodat MediaInfo deze kan gebruiken."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Het bestandsdialoogvenster kon niet worden geopend." },
            { TXT_FILE_DIALOG_SELECTION_FAILED,
                L"De geselecteerde bestanden konden niet uit het bestandsdialoogvenster worden opgehaald."
            },
            { TXT_RECENT_FILE_MISSING,
                L"Het bestand ‘%s’ bestaat niet meer.\n\nWilt u deze vermelding uit de lijst met recente "
                L"bestanden verwijderen?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Het bestand is niet meer beschikbaar:\n\n%s\n\nWilt u deze vermelding uit de lijst met "
                L"recente bestanden verwijderen?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"De informatie kon niet naar het klembord worden gekopieerd." },
            { TXT_CURL_PATH_INVALID, L"Het pad naar libcurl.dll is ongeldig of te lang." },
            { TXT_MEDIALIB_VERSION_MISSING, L"De bibliotheek heeft geen MediaInfo-versie teruggegeven." },
            { TXT_CURL_EXPORTS_MISSING,
                L"De bibliotheek exporteert niet de curl-functies die MediaInfo vereist."
            },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"De bibliotheek exporteert niet de vereiste Unicode-functies van MediaInfo."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Het bibliotheekproces is mislukt tijdens %s (code 0x%08lX). Selecteer een compatibele DLL "
                L"via Opties > Voorkeuren."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Het bibliotheekproces reageert niet meer tijdens %s. Selecteer een compatibele DLL via "
                L"Opties > Voorkeuren."
            },
            { TXT_PREFERENCES_SAVE_FAILED,
                L"De voorkeuren zijn toegepast, maar konden niet in het register worden opgeslagen."
            },
            { TXT_REPORT_START_FAILED, L"Onvoldoende geheugen om het rapport te starten." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Kan de rapportafbeelding niet maken." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Kan de taaltabel niet laden. Selecteer een geldig "
                L"MediaInfo-CSV-bestand in UTF-8 of UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"Kan de rapportthread niet starten." },
            { TXT_REPORT_LANGUAGE_REJECTED,
                L"De geselecteerde MediaInfo.dll heeft de rapporttaal geweigerd."
            },
            { TXT_INVALID_WINDOWS_DLL, L"Het geselecteerde bestand is geen geldige Windows-DLL." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"De geselecteerde afbeeldingsindeling wordt niet ondersteund." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Kan het tekstrapport niet opslaan. Controleer doel en vrije schijfruimte."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Kan de website niet in de standaardbrowser openen." },
            { TXT_TOO_MANY_FILES, L"Te veel bestanden geselecteerd. Open kleinere groepen." },
            { TXT_LIBRARY_PATH_HINT,
                L"Gebruik compatibele 32-bits DLL's voor deze Windows-versie. Lege paden schakelen zoeken "
                L"in. MediaInfoLib v0.7.60 gebruikt geen libcurl.dll."
            },
            { TXT_VERSION, L"Versie" },
            { TXT_WEBSITE_TOOLTIP, L"Website %s openen" },
            { TXT_WAITING_FOR_REPORT, L"Wachten op het voltooien van het huidige rapport." },
            { TXT_WEBSITE_LABEL, L"Website:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"het kopiëren van het MediaInfo-rapport" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"libc&url.dll-pad:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"het laden van MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"het laden van libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"het vrijgeven van MediaInfo.dll" },
            { TXT_APPLY, L"T&oepassen" },
            { TXT_TAB_NAME_LENGTH, L"Lengte van tab&naam:" },
            { TXT_TITLE_NAME_LENGTH, L"Titellen&gte:" },
            { TXT_RECENT_FILES, L"Recente bestanden:" },
            { TXT_CLEAR_RECENT_FILES, L"&Wissen" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"De lengte van de tabnaam moet tussen 8 en 255 liggen." },
            { TXT_TITLE_NAME_LENGTH_INVALID,
                L"De lengte van de naam in de titel moet tussen 8 en 255 liggen."
            },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"De lijst met recente bestanden is gewist, maar kon niet in het register worden opgeslagen."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"Tabbladen slu&iten met dubbelklikken" },
            { TXT_CLOSE_TAB_CONTEXT, L"&Tabblad sluiten" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"M&eerdere exemplaren toestaan" },
            { TXT_INSTANCE_FORWARD_FAILED,
                L"De bestanden konden niet worden doorgegeven aan het actieve exemplaar van MediaInfo."
            },
            { TXT_LOADING, L"Laden…" },
            { TXT_LOADING_FILE, L"Laden van bestand %s…" },
            { TXT_APPLICATION_HELP,
                L"BESTANDEN EN TABBLADEN\r\nNative Windows x86-viewer voor MediaInfo.dll-rapporten. Elk "
                L"bestand krijgt een eigen tabblad dat alleen kan worden gelezen. Open met Ctrl+O of "
                L"sleep bestanden naar het venster. Opnieuw openen selecteert het bestaande tabblad. "
                L"Ctrl+W of de middelste muisknop sluit een tabblad; Alles sluiten sluit alle tabbladen. "
                L"Het menu Bestand onthoudt acht recente bestanden. Het snelmenu van een tabbladkop bevat "
                L"Tabblad sluiten. Schakel Tabbladen sluiten met dubbelklikken in bij Voorkeuren om een "
                L"tabblad te sluiten door op de kop te dubbelklikken. Deze optie staat standaard uit en "
                L"wordt opgeslagen. Dubbelklikken in de rapporttekst selecteert een woord. Driemaal "
                L"klikken selecteert een logische regel. Slepen breidt de selectie uit met woorden of "
                L"regels.\r\nMap openen… opent de bestanden die zich direct in de geselecteerde map "
                L"bevinden, elk op een eigen tabblad. Submappen worden niet meegenomen.\r\nOpenen en Map "
                L"openen delen de laatst geselecteerde map. Export onthoudt een eigen map, standaard "
                L"Documenten. De geavanceerde modus toont extra velden in het rapport.\r\nBekende "
                L"bestandsindelingen / Bekende codecs / Bekende parameters — MediaInfo.dll.\r\nVolledige "
                L"analyse onderzoekt het hele bestand en kan langer duren. Deze rapportopties en "
                L"Traceringsniveau horen bij elk tabblad; een wijziging vernieuwt alleen het actieve "
                L"tabblad. De laatste handmatig gekozen combinatie wordt bewaard voor nieuwe tabbladen en "
                L"de volgende start. Een overeenkomend in de cache opgeslagen rapport wordt hergebruikt "
                L"zolang het bestand ongewijzigd blijft.\r\nTraceringsniveau: 0 / 5 / 9 / 10.\r\nBestand "
                L"> Pagina-instelling… opent de instellingen voor papier, afdrukstand en marges voor de "
                L"huidige sessie. Afdrukken… (Ctrl+P) opent het afdrukvenster van het systeem; Windows 11 "
                L"toont een afdrukvoorbeeld, terwijl Windows 10 en ouder het klassieke venster behouden. "
                L"Ctrl+P drukt het actieve tabblad van het hoofdvenster of het tekstvak in Help of Info "
                L"af, afhankelijk van welk venster de focus heeft. Rapporten gebruiken het gekozen "
                L"rapportlettertype, Help het systeemlettertype voor dialoogvensters en Info het "
                L"lettertype van het eigen tekstvak. Als er geen tabbladen open zijn maar Help wel open "
                L"is, blijven Pagina-instelling… en Afdrukken… beschikbaar; Afdrukken… drukt Help af. "
                L"Help gebruikt het afdrukvenster van het hoofdvenster; opnieuw Ctrl+P in Help brengt "
                L"hetzelfde venster naar de voorgrond. Lange regels worden afgebroken en de tekst wordt "
                L"over pagina’s verdeeld. Afdrukken gebeurt op de achtergrond.\r\nSleep een of meer "
                L"bestanden naar het venster, het EXE-pictogram of de snelkoppeling, of geef de paden op "
                L"via de opdrachtregel. Als meerdere exemplaren niet zijn toegestaan, worden de bestanden "
                L"in het al geopende venster geopend.\r\nLinks op de statusbalk staan bestandspaden en de "
                L"voortgang van het laden; rechts staat de versie van de geladen MediaInfo.dll. Lange "
                L"paden worden met een weglatingsteken ingekort tot de beschikbare ruimte.\r\n\r\n"
                L"EXPORTEREN\r\nTXT, BMP, GIF, JPEG, PNG, TIFF en WebP verschijnen als ze beschikbaar "
                L"zijn. De laatste exportmap en het formaat worden onthouden.\r\nTXT biedt ANSI, UTF-8, "
                L"UTF-8 met BOM, UTF-16 BE met BOM en UTF-16 LE met BOM. De tweede optie, UTF-8 zonder "
                L"BOM, is de standaard. De volledige rapporttekst en de oorspronkelijke regeleinden "
                L"blijven behouden.\r\n\r\nHEADERBESTAND MAKEN\r\nHet menu Extra is het vierde menu op de "
                L"menubalk. De opdracht Headerbestand maken… opent één bronbestand, onafhankelijk van de "
                L"rapporttabbladen, en kopieert de eerste 524288 bytes (512 KiB). Een korter bestand "
                L"wordt volledig gekopieerd; een leeg bestand produceert een lege uitvoer. Dit is het "
                L"gewone lezen van binaire bestanden, zonder MediaInfo-analyse of een vereiste voor "
                L"MediaInfo.dll. De tool laat rapporttabbladen en de lijst met recente bestanden van het "
                L"programma ongewijzigd.\r\n\r\nNa het lezen start het dialoogvenster Opslaan als in de "
                L"map van het bronbestand en wordt video.mp4.header voor video.mp4 voorgesteld: .header "
                L"wordt toegevoegd aan de volledige originele naam. U kunt zowel de naam als de doelmap "
                L"wijzigen. Als u een van beide dialoogvensters annuleert, wordt er geen uitvoer "
                L"geschreven. Voor het vervangen van een bestaande bestemming is bevestiging vereist. De "
                L"bron blijft ongewijzigd; bij een mislukte opslag blijft de vorige bestemming behouden. "
                L"Voor openen en opslaan worden de modernste systeemdialoogvensters gebruikt die in die "
                L"Windows-versie beschikbaar zijn.\r\n\r\nBij het opstarten van de toepassing haalt het "
                L"hulpprogramma de oorspronkelijke invoermap van Bestand > Openen. Als er geen map is "
                L"opgeslagen, kiest Windows de oorspronkelijke locatie. Nadat een invoerbestand is "
                L"geselecteerd, onthoudt het hulpprogramma zijn eigen map alleen totdat de toepassing "
                L"wordt afgesloten, zelfs als Opslaan als wordt geannuleerd. Het verandert noch de mappen "
                L"die worden gebruikt door Openen en Exporteren, noch slaat het zijn eigen map op in de "
                L"applicatie-instellingen. Elk dialoogvenster Opslaan als begint in de map van het "
                L"momenteel geselecteerde invoerbestand, ongeacht de vorige opslagbestemming.\r\n\r\n"
                L"VOORKEUREN EN TALEN\r\nVoorkeuren (Opties > Voorkeuren, Ctrl+G) bevatten "
                L"bibliotheekpaden, rapportlettertype, anti-aliasing en talen. De interface heeft 36 "
                L"varianten en volgt aanvankelijk Windows. Rapporten gebruiken standaard altijd het "
                L"oorspronkelijke Engels van de bibliotheek, onafhankelijk van Windows en de interface. "
                L"Alleen een handmatige keuze wijzigt de rapporttaal: Engels, 37 vertalingen of een eigen "
                L"MediaInfo-CSV-tabel. OK of Toepassen bevestigt wijzigingen; Annuleren verwerpt "
                L"openstaande wijzigingen. Voorkeuren stellen de limiet voor tabnamen in (standaard 80) "
                L"en wissen de lijst met recente bestanden. Lange namen behouden begin, einde en extensie "
                L"met een weglatingsteken in het midden. Wissen verwijdert de lijst met recente bestanden "
                L"onmiddellijk, ook als de voorkeuren daarna met Annuleren worden gesloten.\r\n\r\nDe titel "
                L"van het hoofdvenster toont het actieve bestand als bestandsnaam — MediaInfo. In de "
                L"voorkeuren kan de naamlengte in de titel afzonderlijk worden ingesteld op 8–255 tekens "
                L"(standaard 40). Langere namen worden met hetzelfde weglatingsteken in het midden ingekort "
                L"en behouden de extensie. Zonder geopende tabbladen is de titel MediaInfo.\r\n\r\n"
                L"BIBLIOTHEKEN EN VENSTERS\r\nDe EXE bevat de bibliotheken MediaInfo 26.10, 21.03 en "
                L"0.7.60. Na de externe bibliotheken worden deze van de nieuwste naar de oudste "
                L"geprobeerd. De twee nieuwere versies hebben bijpassende libcurl-bibliotheken; 0.7.60 "
                L"pakt libcurl nooit uit. De vensterpositie wordt opgeslagen. Standaard is slechts één "
                L"exemplaar toegestaan en worden bestanden bij opnieuw starten naar het open venster "
                L"gestuurd. In de voorkeuren kunnen meerdere exemplaren worden toegestaan. Bij meerdere "
                L"vensters herstelt alleen het eerste venster van elk venstertype de opgeslagen positie; "
                L"latere vensters herstellen alleen de grootte.\r\n\r\nBewerken > Zoeken (Ctrl+F) zoekt "
                L"in het actieve rapporttabblad of het tekstvak in Help of Info, afhankelijk van welk "
                L"venster de focus heeft. Het zoekvenster behoudt de laatst gekozen bron zolang het zelf "
                L"de focus heeft. F3 herhaalt de zoekopdracht; Shift+F3 keert de richting om. Aan het "
                L"einde van de tekst gaat het zoeken verder vanaf het andere uiteinde. Opties > "
                L"Automatische terugloop geldt alleen voor het actieve tabblad; het vinkje volgt het "
                L"geselecteerde tabblad. Het zoekvenster kan worden geminimaliseerd en in de breedte "
                L"worden aangepast; de positie en de instelling Altijd bovenop worden onthouden. Maximaal "
                L"30 zoekteksten met hun opties blijven alleen bewaard totdat de toepassing wordt "
                L"afgesloten. De begin- en eindopties gelden voor logische regels. Reguliere expressies "
                L"gebruiken PCRE2-syntaxis. De overige opdrachten in het menu Bewerken gelden voor het "
                L"actieve rapporttabblad. Enter start het zoeken; Shift+Enter keert de gekozen richting "
                L"om. \"Hoofdlettergevoelig\" maakt onderscheid tussen hoofdletters en kleine letters; "
                L"\"Achteruit zoeken\" zoekt naar het begin van de tekst. Een keuze uit de geschiedenis "
                L"herstelt alle vijf zoekopties, ook de stand van de modus voor reguliere expressies; "
                L"\"Altijd bovenop\" staat hier los van. \"Reguliere expressie\" schakelt \"Regel begint "
                L"met\" en \"Regel eindigt op\" uit. Als beide opties voor de regeluiteinden aanstaan, "
                L"volstaat een overeenkomst aan één uiteinde. \"Automatische terugloop\" verandert alleen "
                L"de weergave."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"Kan de WebP-afbeelding niet opslaan. Controleer doel, vrij geheugen en schijfruimte."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Tekstdocument UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Tekstdocument UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Tekstdocument UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Tekstdocument UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Het rapport kan niet zonder tekenverlies in deze codering worden opgeslagen. Kies een "
                L"andere tekstcodering."
            },
            { TXT_OPEN_FOLDER, L"&Map openen…" },
            { TXT_OPEN_FOLDER_TITLE, L"Map openen" },
            { TXT_FOLDER_READ_FAILED, L"De map kan niet worden gelezen:\n\n%s\n\nWindows-fout %lu." },
            { TXT_ADVANCED_MODE, L"&Geavanceerde modus" },
            { TXT_REPORT_DETAIL_REJECTED,
                L"De geselecteerde MediaInfo.dll heeft het detailniveau van het rapport geweigerd."
            },
            { TXT_KNOWN_FORMATS, L"Bekende &bestandsindelingen" },
            { TXT_KNOWN_CODECS, L"Bekende &codecs" },
            { TXT_KNOWN_PARAMETERS, L"Bekende &parameters" },
            { TXT_KNOWN_FORMATS_TITLE, L"Bekende bestandsindelingen" },
            { TXT_KNOWN_CODECS_TITLE, L"Bekende codecs" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Bekende parameters" },
            { TXT_KNOWN_INFO_FAILED, L"De bibliotheek heeft de gevraagde informatie niet teruggegeven." },
            { TXT_FULL_PARSING, L"Volledige &analyse" },
            { TXT_PARSING_REJECTED,
                L"De geselecteerde MediaInfo.dll heeft de analyse-instelling geweigerd."
            },
            { TXT_TRACE_LEVEL_0, L"Traceringsniveau &0" },
            { TXT_TRACE_LEVEL_5, L"Traceringsniveau &5" },
            { TXT_TRACE_LEVEL_9, L"Traceringsniveau &9" },
            { TXT_TRACE_LEVEL_10, L"Traceringsniveau &10" },
            { TXT_PAGE_SETUP, L"Pagina-&instelling…" },
            { TXT_PAGE_SETUP_FAILED, L"De pagina-instelling kon niet worden geopend." },
            { TXT_PRINT, L"Af&drukken…\tCtrl+P" },
            { TXT_PRINTING, L"Afdrukken…" },
            { TXT_PRINT_FAILED,
                L"De tekst kan niet worden afgedrukt. Controleer de printer, de instellingen en het "
                L"beschikbare geheugen."
            },
            { TXT_TOOLS_MENU, L"E&xtra" },
            { TXT_CREATE_HEADER, L"&Headerbestand maken…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Headerbestand maken - Openen" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Headerbestand maken - Opslaan als" },
            { TXT_HEADER_FORMAT, L"Headerbestand (*.header)" },
            { TXT_HEADER_READ_FAILED, L"De bestandsheader kon niet worden gelezen:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Het headerbestand kon niet worden opgeslagen:\n\n%s" },
            { TXT_COPY, L"&Kopiëren" },
            { TXT_COPY_FILE_NAME, L"Bestands&naam kopiëren" },
            { TXT_COPY_FULL_PATH, L"Volledig bestands&pad kopiëren" },
            { TXT_LAUNCH_FILE, L"&Bestand starten" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"&Weergeven in map" },
            { TXT_EDIT_MENU, L"Be&werken" },
            { TXT_WORD_WRAP, L"A&utomatische terugloop" },
            { TXT_WORD_WRAP_FAILED, L"Automatische terugloop kon niet worden gewijzigd." },
            { TXT_COPY_SELECTION, L"&Kopiëren\tCtrl+C" },
            { TXT_SELECT_ALL, L"&Alles selecteren\tCtrl+A" },
            { TXT_FIND_MENU, L"&Zoeken…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"&Volgende zoeken\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Vo&rige zoeken\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Zoeken" },
            { TXT_FIND_WHAT, L"Zoeken &naar:" },
            { TXT_FIND_NEXT, L"&Volgende zoeken" },
            { TXT_FIND_MATCH_CASE, L"&Hoofdlettergevoelig" },
            { TXT_FIND_BACKWARD, L"&Achteruit zoeken" },
            { TXT_FIND_TOPMOST, L"Altijd &bovenop" },
            { TXT_FIND_STARTS_WITH, L"Regel be&gint met" },
            { TXT_FIND_ENDS_WITH, L"Regel &eindigt op" },
            { TXT_FIND_REGEX, L"&Reguliere expressie" },
            { TXT_FIND_NOT_FOUND, L"De opgegeven tekst is niet gevonden." },
            { TXT_FIND_FAILED, L"De zoekopdracht kon niet worden voltooid." },
            { TXT_FIND_REGEX_ERROR, L"Fout in reguliere expressie:\r\n\r\n%s" },
        }
    },
    {
        LANG_RO,
        {
            { TXT_LANGUAGE_NAME, L"Română" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nSite web: " },
            { TXT_FILE_OPEN_FAILED, L"Nu se poate deschide %s. Verificați calea și permisiunile." },
            { TXT_BROWSE_DLL, L"&Răsfoire…" },
            { TXT_BROWSE_REPORT, L"Ră&sfoire…" },
            { TXT_CLOSE, L"&Închidere" },
            { TXT_CLOSE_TAB, L"&Închidere\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"&Implicit" },
            { TXT_EXPORT, L"&Exportă…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Fișier" },
            { TXT_REPORT_FONT, L"&Fontul raportului:" },
            { TXT_HELP_MENU, L"&Ajutor" },
            { TXT_HELP, L"&Ajutor\tF1" },
            { TXT_LANGUAGE, L"&Limbă:" },
            { TXT_OPEN_WEBSITE, L"&Deschidere în browserul implicit" },
            { TXT_OPEN, L"&Deschide…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Opțiuni" },
            { TXT_PREFERENCES_MENU, L"&Preferințe…\tCtrl+G" },
            { TXT_ABOUT, L"&Despre" },
            { TXT_ABOUT_TITLE, L"Despre %ls" },
            { TXT_ALL_FILES, L"Toate fișierele" },
            { TXT_FONT_BOLD, L"Aldin" },
            { TXT_FONT_BOLD_ITALIC, L"Aldin + Cursiv" },
            { TXT_BROWSE_CURL, L"R&ăsfoire…" },
            { TXT_CANCEL, L"Anulare" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Nu se poate încărca MediaInfo.dll (eroare Windows %lu). Folosiți un DLL pe 32 de biți "
                L"compatibil cu această versiune de Windows."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Nu se poate încărca libcurl.dll (eroare Windows %lu). Selectați o bibliotecă pe 32 de biți "
                L"compatibilă cu această versiune de Windows."
            },
            { TXT_CLOSE_ALL, L"Închide &tot" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Copiere &adresă" },
            { TXT_COPY_INFORMATION, L"Copiere &informații" },
            { TXT_DLL_FILES, L"Biblioteci dinamice" },
            { TXT_EXIT, L"Ieși&re\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Biblioteci încorporate MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Biblioteci încorporate libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Exportă raportul" },
            { TXT_FONT_ANTIALIASING, L"&Netezire font:" },
            { TXT_GIF_EXPORT_FAILED,
                L"Exportul GIF a eșuat. GIF fără pierderi necesită cel mult 256 de culori."
            },
            { TXT_FONT_ITALIC, L"Cursiv" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED,
                L"Exportul JPEG a eșuat. Este necesar un codificator JPEG GDI+ funcțional."
            },
            { TXT_LICENSE_UNAVAILABLE, L"Resursa licenței nu este disponibilă." },
            { TXT_MEDIA_FILES, L"Fișiere multimedia" },
            { TXT_APPLICATION_DESCRIPTION, L"Vizualizator de informații multimedia" },
            { TXT_HELP_TITLE, L"MediaInfo — Ajutor" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo nu a putut inițializa analiza fișierului." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo nu poate deschide sau recunoaște acest fișier." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"&Cale către MediaInfo.dll:" },
            { TXT_MEDIALIB_REQUIRED,
                L"MediaInfo.dll nu este încărcat. Selectați-l în Opțiuni > Preferințe."
            },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll nu este încărcat." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Nu s-a putut încărca un MediaInfo.dll extern sau încorporat compatibil. Selectați-l în "
                L"Opțiuni > Preferințe."
            },
            { TXT_ANTIALIASING_NONE, L"Fără" },
            { TXT_OK, L"OK" },
            { TXT_OPEN_TITLE, L"Deschide fișiere multimedia" },
            { TXT_PLATFORM, L"Platformă țintă:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Preferințe" },
            { TXT_READY, L"Pregătit" },
            { TXT_FONT_REGULAR, L"Normal" },
            { TXT_REPORT_LANGUAGE, L"Li&mba raportului:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Tabele de limbă pentru rapoarte" },
            { TXT_SELECT_MEDIALIB, L"Răsfoire: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Răsfoire: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH,
                L"Selectați un fișier multimedia existent cu o cale mai scurtă decât MAX_PATH."
            },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Selectați fișiere existente cu căi mai scurte decât MAX_PATH." },
            { TXT_SELECT_CURL, L"Răsfoire: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Document text ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"Imaginea BMP nu poate fi salvată. Verificați destinația, memoria liberă și spațiul pe disc."
            },
            { TXT_LIBRARY_WORKER_START_FAILED,
                L"Procesul bibliotecii nu poate fi pornit (eroare Windows %lu)."
            },
            { TXT_REPORT_COPY_FAILED, L"Raportul MediaInfo nu poate fi copiat în memorie." },
            { TXT_VIEWER_CREATE_FAILED, L"Vizualizatorul MediaInfo nu poate fi creat." },
            { TXT_MEDIALIB_PATH_INVALID, L"Calea către MediaInfo.dll este nevalidă sau prea lungă." },
            { TXT_PNG_EXPORT_FAILED,
                L"Imaginea PNG nu poate fi salvată. Verificați destinația, memoria liberă și spațiul pe disc."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"Imaginea TIFF nu poate fi salvată. Verificați destinația, memoria liberă și spațiul pe "
                L"disc."
            },
            { TXT_COPY_URL_FAILED, L"URL-ul nu a putut fi copiat în clipboard." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"Vizualizatorul Win32 necesită un %s pe 32 de biți. Selectați biblioteca x86/i386."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Biblioteca încorporată nu poate fi scrisă în AppData, profilul utilizatorului, Program "
                L"Files sau dosarul temporar."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED, L"Decomprimarea sau verificarea CRC a bibliotecii a eșuat." },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Resursa bibliotecii încorporate este nevalidă." },
            { TXT_CURL_FILENAME_INVALID,
                L"Biblioteca trebuie să se numească libcurl.dll pentru a putea fi folosită de MediaInfo."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Dialogul pentru fișiere nu a putut fi deschis." },
            { TXT_FILE_DIALOG_SELECTION_FAILED,
                L"Fișierele selectate nu au putut fi obținute din dialogul pentru fișiere."
            },
            { TXT_RECENT_FILE_MISSING,
                L"Fișierul „%s” nu mai există.\n\nDoriți să eliminați această intrare din lista fișierelor "
                L"recente?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Fișierul nu mai este disponibil:\n\n%s\n\nDoriți să eliminați această intrare din lista "
                L"fișierelor recente?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Informațiile nu au putut fi copiate în clipboard." },
            { TXT_CURL_PATH_INVALID, L"Calea către libcurl.dll este nevalidă sau prea lungă." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Biblioteca nu a returnat o versiune MediaInfo." },
            { TXT_CURL_EXPORTS_MISSING, L"Biblioteca nu exportă funcțiile curl necesare pentru MediaInfo." },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"Biblioteca nu exportă funcțiile Unicode necesare ale MediaInfo."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Procesul bibliotecii a eșuat în timpul %s (cod 0x%08lX). Selectați un DLL compatibil în "
                L"Opțiuni > Preferințe."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Procesul bibliotecii nu mai răspunde în timpul %s. Selectați un DLL compatibil în Opțiuni "
                L"> Preferințe."
            },
            { TXT_PREFERENCES_SAVE_FAILED,
                L"Preferințele au fost aplicate, dar nu au putut fi salvate în registru."
            },
            { TXT_REPORT_START_FAILED, L"Memorie insuficientă pentru pornirea raportului." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Imaginea raportului nu poate fi creată." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Tabelul de limbă nu poate fi încărcat. Selectați un CSV "
                L"MediaInfo valid în UTF-8 sau UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"Firul raportului nu poate fi pornit." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"MediaInfo.dll selectat a respins limba raportului." },
            { TXT_INVALID_WINDOWS_DLL, L"Fișierul selectat nu este un DLL Windows valid." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Formatul de imagine selectat nu este acceptat." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Raportul text nu poate fi salvat. Verificați destinația și spațiul liber pe disc."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Site-ul nu poate fi deschis în browserul implicit." },
            { TXT_TOO_MANY_FILES, L"Au fost selectate prea multe fișiere. Deschideți grupuri mai mici." },
            { TXT_LIBRARY_PATH_HINT,
                L"Folosiți biblioteci pe 32 de biți compatibile cu versiunea dvs. de Windows. Lăsați căile "
                L"goale pentru căutarea automată. MediaInfoLib v0.7.60 nu folosește libcurl.dll."
            },
            { TXT_VERSION, L"Versiune" },
            { TXT_WEBSITE_TOOLTIP, L"Deschidere site web %s" },
            { TXT_WAITING_FOR_REPORT, L"Se așteaptă finalizarea raportului curent." },
            { TXT_WEBSITE_LABEL, L"Site web:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"copierii raportului MediaInfo" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"Cale către libc&url.dll:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"încărcării MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"încărcării libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"descărcării MediaInfo.dll" },
            { TXT_APPLY, L"Se a&plică" },
            { TXT_TAB_NAME_LENGTH, L"Lun&gime nume filă:" },
            { TXT_TITLE_NAME_LENGTH, L"L&ungime titlu:" },
            { TXT_RECENT_FILES, L"Fișiere recente:" },
            { TXT_CLEAR_RECENT_FILES, L"Ș&terge" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"Lungimea numelui filei trebuie să fie între 8 și 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"Lungimea numelui din titlu trebuie să fie între 8 și 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Lista fișierelor recente a fost ștearsă, dar nu a putut fi salvată în registru."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"Închide filele prin &dublu clic" },
            { TXT_CLOSE_TAB_CONTEXT, L"Închide &fila" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"P&ermite mai multe instanțe" },
            { TXT_INSTANCE_FORWARD_FAILED,
                L"Fișierele nu au putut fi transmise instanței MediaInfo care rulează."
            },
            { TXT_LOADING, L"Se încarcă…" },
            { TXT_LOADING_FILE, L"Se încarcă fișierul %s…" },
            { TXT_APPLICATION_HELP,
                L"FIȘIERE ȘI FILE\r\nVizualizator nativ Windows x86 pentru rapoarte MediaInfo.dll. "
                L"Fiecare fișier are propria filă doar pentru citire. Deschideți cu Ctrl+O sau prin "
                L"glisare. Redeschiderea selectează fila existentă. Ctrl+W sau butonul din mijloc al "
                L"mouse-ului închide o filă; Închide tot închide toate filele. Meniul Fișier reține opt "
                L"fișiere recente. Meniul contextual al antetului unei file include Închide fila. "
                L"Activați Închide filele prin dublu clic în Preferințe pentru a închide o filă prin "
                L"dublu clic pe antetul ei. Opțiunea este dezactivată implicit și se salvează. Un dublu "
                L"clic în textul raportului selectează un cuvânt. Un triplu clic selectează o linie "
                L"logică. Tragerea extinde selecția pe cuvinte sau linii.\r\nDeschide folderul… deschide "
                L"fișierele aflate direct în folderul selectat, fiecare în propria filă. Subfolderele nu "
                L"sunt incluse.\r\nDeschide și Deschide folderul folosesc același ultim folder selectat. "
                L"Exportul reține un folder separat, implicit Documente. Modul avansat afișează câmpuri "
                L"suplimentare în raport.\r\nFormate cunoscute / Codecuri cunoscute / Parametri cunoscuți "
                L"— MediaInfo.dll.\r\nAnaliză completă examinează întregul fișier și poate dura mai mult. "
                L"Aceste opțiuni de raport și Nivel de trasare aparțin fiecărei file; o modificare "
                L"reîmprospătează numai fila activă. Ultima combinație aleasă manual este salvată pentru "
                L"noi file și pentru următoarea pornire. Un raport în cache care se potrivește este "
                L"reutilizat în timp ce fișierul rămâne neschimbat.\r\nNivel de trasare: 0 / 5 / 9 / "
                L"10.\r\nFișier > Configurare pagină… deschide setările pentru hârtie, orientare și "
                L"margini ale sesiunii curente. Imprimare… (Ctrl+P) deschide dialogul de imprimare al "
                L"sistemului; Windows 11 oferă o previzualizare, iar Windows 10 și versiunile mai vechi "
                L"păstrează dialogul clasic. Ctrl+P imprimă fila activă din fereastra principală sau zona "
                L"de text din Ajutor ori Despre, în funcție de fereastra care are focalizarea. Rapoartele "
                L"folosesc fontul de raport ales, Ajutor fontul dialogurilor de sistem, iar Despre fontul "
                L"propriei zone de text. Dacă nu sunt file deschise, dar Ajutor este deschis, Configurare "
                L"pagină… și Imprimare… rămân disponibile; Imprimare… imprimă Ajutorul. Ajutor folosește "
                L"dialogul de imprimare al ferestrei principale; un nou Ctrl+P în Ajutor aduce același "
                L"dialog în prim-plan. Liniile lungi se încadrează, iar textul se împarte în pagini. "
                L"Imprimarea se face în fundal.\r\nGlisați unul sau mai multe fișiere în fereastră, pe "
                L"pictograma EXE sau pe comanda sa rapidă, ori transmiteți căile în linia de comandă. "
                L"Dacă nu sunt permise mai multe instanțe, fișierele se deschid în fereastra care rulează "
                L"deja.\r\nPartea stângă a barei de stare afișează căile fișierelor și progresul "
                L"încărcării, iar partea dreaptă afișează versiunea MediaInfo.dll încărcată. Căile lungi "
                L"sunt prescurtate cu puncte de suspensie în funcție de spațiul disponibil.\r\n\r\n"
                L"EXPORT\r\nTXT, BMP, GIF, JPEG, PNG, TIFF și WebP apar când sunt disponibile. Ultimul "
                L"dosar și format de export sunt memorate.\r\nTXT oferă ANSI, UTF-8, UTF-8 cu BOM, UTF-16 "
                L"BE cu BOM și UTF-16 LE cu BOM. A doua opțiune, UTF-8 fără BOM, este cea implicită. Se "
                L"păstrează întregul text al raportului și sfârșiturile de linie originale.\r\n\r\n"
                L"CREEAZĂ UN FIȘIER ANTET\r\nMeniul Instrumente este al patrulea din bara de meniu. "
                L"Comanda sa Creează un fișier antet… deschide un fișier sursă independent de filele de "
                L"raport și îi copiază primii 524288 de octeți (512 KiB). Un fișier mai scurt este copiat "
                L"integral; un fișier gol produce o ieșire goală. Aceasta este o citire binară obișnuită "
                L"a unui fișier, fără analiză MediaInfo sau o cerință pentru MediaInfo.dll. Instrumentul "
                L"lasă neschimbate filele de raport și lista de fișiere recente a "
                L"vizualizatorului.\r\n\r\nDupă citire, dialogul Salvare ca începe în folderul fișierului "
                L"sursă și sugerează video.mp4.header pentru video.mp4: .header este atașat la numele "
                L"original complet. Puteți schimba atât numele, cât și folderul de destinație. Anularea "
                L"fiecărei casete de dialog nu va scrie nicio ieșire. Înlocuirea unei destinații "
                L"existente necesită confirmare. Sursa rămâne neschimbată; o salvare eșuată păstrează "
                L"destinația anterioară. Pentru deschidere și salvare sunt folosite cele mai moderne "
                L"casete de dialog de sistem disponibile în versiunea respectivă de Windows.\r\n\r\nLa "
                L"pornirea aplicației, instrumentul își ia folderul de intrare inițial din Fișier > "
                L"Deschide. Dacă nu a fost salvat niciun folder, Windows alege locația inițială. După ce "
                L"este selectat un fișier de intrare, instrumentul își amintește propriul folder numai "
                L"până când aplicația iese, chiar dacă Salvare ca este anulată. Nu modifică folderele "
                L"folosite de Deschide și Exportă și nici nu își salvează propriul folder în setările "
                L"aplicației. Fiecare dialog Salvare ca începe în folderul fișierului de intrare selectat "
                L"curent, indiferent de destinația anterioară de salvare.\r\n\r\nPREFERINȚE ȘI LIMBI\r\n"
                L"Preferințele (Opțiuni > Preferințe, Ctrl+G) conțin căile bibliotecilor, fontul "
                L"raportului, netezirea și limbile. Interfața are 36 de variante și urmează inițial "
                L"Windows. Rapoartele folosesc întotdeauna implicit engleza originală a bibliotecii, "
                L"independent de Windows și interfață. Doar o alegere manuală schimbă limba: engleză, 37 "
                L"de traduceri sau un tabel CSV MediaInfo propriu. OK sau Se aplică confirmă "
                L"modificările; Anulare le abandonează pe cele în așteptare. Preferințele stabilesc "
                L"limita numelor filelor (implicit 80) și șterg lista fișierelor recente. Numele lungi "
                L"păstrează începutul, sfârșitul și extensia, cu puncte de suspensie la mijloc. Șterge "
                L"elimină imediat lista fișierelor recente, chiar dacă preferințele sunt apoi închise cu "
                L"Anulare.\r\n\r\nTitlul ferestrei principale afișează fișierul activ în forma nume fișier — "
                L"MediaInfo. Preferințele permit setarea separată a lungimii numelui din titlu între 8 și 255"
                L" de caractere (implicit 40). Numele mai lungi sunt scurtate cu aceleași puncte de suspensie"
                L" la mijloc, păstrând extensia. Fără file deschise, titlul este MediaInfo.\r\n\r\nBIBLIOTECI"
                L" ȘI FERESTRE\r\nProgramul include MediaInfo 26.10, 21.03 și "
                L"0.7.60, încercate de la cea mai nouă după bibliotecile externe. Cele două versiuni mai "
                L"noi au libcurl corespunzătoare; 0.7.60 nu extrage niciodată libcurl. Poziția ferestrei "
                L"este salvată. În mod implicit este permisă o singură instanță, iar pornirile ulterioare "
                L"trimit fișierele la fereastra deschisă. Preferințele permit activarea mai multor "
                L"instanțe. Cu mai multe ferestre, doar prima fereastră a fiecărui tip de fereastră "
                L"restabilește poziția salvată; celelalte restabilesc doar dimensiunea.\r\n\r\nEditare > "
                L"Găsire (Ctrl+F) caută în fila de raport activă sau în zona de text din Ajutor ori "
                L"Despre, în funcție de fereastra care are focalizarea. Fereastra de căutare păstrează "
                L"ultima sursă selectată cât timp are focalizarea. F3 repetă căutarea; Shift+F3 îi "
                L"inversează direcția. La capătul textului, căutarea continuă din celălalt capăt. Opțiuni "
                L"> Încadrare cuvinte se aplică numai filei active; bifa corespunde filei selectate. "
                L"Fereastra de căutare poate fi minimizată și redimensionată orizontal; poziția și "
                L"opțiunea Întotdeauna deasupra sunt memorate. Până la 30 de texte căutate și opțiunile "
                L"lor sunt păstrate numai până la închiderea aplicației. Opțiunile de început și sfârșit "
                L"se aplică liniilor logice. Expresiile regulate folosesc sintaxa PCRE2. Celelalte "
                L"comenzi din meniul Editare se aplică filei de raport active. Enter pornește căutarea; "
                L"Shift+Enter inversează direcția aleasă. „Potrivire litere mari și mici” deosebește "
                L"literele mari de cele mici; „Căutare înapoi” caută spre începutul textului. Alegerea "
                L"unei intrări din istoric restabilește toate cele cinci opțiuni de căutare, inclusiv "
                L"starea modului de expresii regulate; „Întotdeauna deasupra” este independentă. "
                L"„Expresie regulată” dezactivează „Linia începe cu” și „Linia se termină cu”. Dacă "
                L"ambele opțiuni pentru capetele liniei sunt active, este suficientă o potrivire la "
                L"oricare capăt. „Încadrare cuvinte” schimbă numai afișarea."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"Imaginea WebP nu poate fi salvată. Verificați destinația, memoria liberă și spațiul pe "
                L"disc."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Document text UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Document text UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Document text UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Document text UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Raportul nu poate fi salvat cu această codificare fără pierderi de caractere. Alegeți altă "
                L"codificare."
            },
            { TXT_OPEN_FOLDER, L"Deschide &folderul…" },
            { TXT_OPEN_FOLDER_TITLE, L"Deschide folderul" },
            { TXT_FOLDER_READ_FAILED, L"Folderul nu a putut fi citit:\n\n%s\n\nEroare Windows %lu." },
            { TXT_ADVANCED_MODE, L"Mod &avansat" },
            { TXT_REPORT_DETAIL_REJECTED,
                L"Biblioteca MediaInfo.dll selectată a respins nivelul de detaliu al raportului."
            },
            { TXT_KNOWN_FORMATS, L"&Formate cunoscute" },
            { TXT_KNOWN_CODECS, L"&Codecuri cunoscute" },
            { TXT_KNOWN_PARAMETERS, L"&Parametri cunoscuți" },
            { TXT_KNOWN_FORMATS_TITLE, L"Formate cunoscute" },
            { TXT_KNOWN_CODECS_TITLE, L"Codecuri cunoscute" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Parametri cunoscuți" },
            { TXT_KNOWN_INFO_FAILED, L"Biblioteca nu a returnat informațiile solicitate." },
            { TXT_FULL_PARSING, L"Analiză &completă" },
            { TXT_PARSING_REJECTED, L"Biblioteca MediaInfo.dll selectată a respins setarea analizei." },
            { TXT_TRACE_LEVEL_0, L"Nivel de trasare &0" },
            { TXT_TRACE_LEVEL_5, L"Nivel de trasare &5" },
            { TXT_TRACE_LEVEL_9, L"Nivel de trasare &9" },
            { TXT_TRACE_LEVEL_10, L"Nivel de trasare &10" },
            { TXT_PAGE_SETUP, L"Configurare &pagină…" },
            { TXT_PAGE_SETUP_FAILED, L"Configurarea paginii nu a putut fi deschisă." },
            { TXT_PRINT, L"&Imprimare…\tCtrl+P" },
            { TXT_PRINTING, L"Se imprimă…" },
            { TXT_PRINT_FAILED,
                L"Textul nu a putut fi imprimat. Verificați imprimanta, setările ei și memoria "
                L"disponibilă."
            },
            { TXT_TOOLS_MENU, L"&Instrumente" },
            { TXT_CREATE_HEADER, L"Cree&ază un fișier antet…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Creează un fișier antet - Deschide" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Creează un fișier antet - Salvare ca" },
            { TXT_HEADER_FORMAT, L"Fișier antet (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Antetul fișierului nu a putut fi citit:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Fișierul antet nu a putut fi salvat:\n\n%s" },
            { TXT_COPY, L"&Copiere" },
            { TXT_COPY_FILE_NAME, L"Copiază &numele fișierului" },
            { TXT_COPY_FULL_PATH, L"Copiază cal&ea completă" },
            { TXT_LAUNCH_FILE, L"&Lansează fișierul" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"&Afișează în folder" },
            { TXT_EDIT_MENU, L"&Editare" },
            { TXT_WORD_WRAP, L"Î&ncadrare cuvinte" },
            { TXT_WORD_WRAP_FAILED, L"Încadrarea cuvintelor nu a putut fi schimbată." },
            { TXT_COPY_SELECTION, L"&Copiere\tCtrl+C" },
            { TXT_SELECT_ALL, L"Selectare &totală\tCtrl+A" },
            { TXT_FIND_MENU, L"&Găsire…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Găsire &următor\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Găsire &anterior\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Găsire" },
            { TXT_FIND_WHAT, L"Text de &găsit:" },
            { TXT_FIND_NEXT, L"Găsire &următor" },
            { TXT_FIND_MATCH_CASE, L"&Potrivire litere mari și mici" },
            { TXT_FIND_BACKWARD, L"Căutare î&napoi" },
            { TXT_FIND_TOPMOST, L"Întotdeauna &deasupra" },
            { TXT_FIND_STARTS_WITH, L"Linia începe &cu" },
            { TXT_FIND_ENDS_WITH, L"Linia se &termină cu" },
            { TXT_FIND_REGEX, L"Expresie &regulată" },
            { TXT_FIND_NOT_FOUND, L"Textul specificat nu a fost găsit." },
            { TXT_FIND_FAILED, L"Căutarea nu a putut fi finalizată." },
            { TXT_FIND_REGEX_ERROR, L"Eroare în expresia regulată:\r\n\r\n%s" },
        }
    },
    {
        LANG_EL,
        {
            { TXT_LANGUAGE_NAME, L"Ελληνικά" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nΤοποθεσία web: " },
            { TXT_FILE_OPEN_FAILED, L"Αδυναμία ανοίγματος του %s. Ελέγξτε τη διαδρομή και τα δικαιώματα." },
            { TXT_BROWSE_DLL, L"&Αναζήτηση…" },
            { TXT_BROWSE_REPORT, L"Ανα&ζήτηση…" },
            { TXT_CLOSE, L"&Κλείσιμο" },
            { TXT_CLOSE_TAB, L"&Κλείσιμο\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"&Προεπιλογή" },
            { TXT_EXPORT, L"&Εξαγωγή…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Αρχείο" },
            { TXT_REPORT_FONT, L"&Γραμματοσειρά αναφοράς:" },
            { TXT_HELP_MENU, L"&Βοήθεια" },
            { TXT_HELP, L"&Βοήθεια\tF1" },
            { TXT_LANGUAGE, L"Γ&λώσσα:" },
            { TXT_OPEN_WEBSITE, L"&Άνοιγμα στο προεπιλεγμένο πρόγραμμα περιήγησης" },
            { TXT_OPEN, L"&Άνοιγμα…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"Ε&πιλογές" },
            { TXT_PREFERENCES_MENU, L"&Προτιμήσεις…\tCtrl+G" },
            { TXT_ABOUT, L"&Πληροφορίες" },
            { TXT_ABOUT_TITLE, L"Πληροφορίες για το %ls" },
            { TXT_ALL_FILES, L"Όλα τα αρχεία" },
            { TXT_FONT_BOLD, L"Έντονα" },
            { TXT_FONT_BOLD_ITALIC, L"Έντονα + Πλάγια" },
            { TXT_BROWSE_CURL, L"Α&ναζήτηση…" },
            { TXT_CANCEL, L"Άκυρο" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Αδυναμία φόρτωσης του MediaInfo.dll (σφάλμα Windows %lu). Χρησιμοποιήστε DLL 32 bit "
                L"συμβατή με αυτήν την έκδοση των Windows."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Αδυναμία φόρτωσης του libcurl.dll (σφάλμα Windows %lu). Επιλέξτε βιβλιοθήκη 32 bit συμβατή "
                L"με αυτήν την έκδοση των Windows."
            },
            { TXT_CLOSE_ALL, L"Κλείσιμο ό&λων" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Αντιγραφή &διεύθυνσης" },
            { TXT_COPY_INFORMATION, L"Αντιγραφή &πληροφοριών" },
            { TXT_DLL_FILES, L"Δυναμικές βιβλιοθήκες" },
            { TXT_EXIT, L"Έ&ξοδος\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Ενσωματωμένες βιβλιοθήκες MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Ενσωματωμένες βιβλιοθήκες libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Εξαγωγή αναφοράς" },
            { TXT_FONT_ANTIALIASING, L"Ε&ξομάλυνση γραμματοσειράς:" },
            { TXT_GIF_EXPORT_FAILED,
                L"Η εξαγωγή GIF απέτυχε. Το GIF χωρίς απώλειες επιτρέπει έως 256 χρώματα."
            },
            { TXT_FONT_ITALIC, L"Πλάγια" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED,
                L"Η εξαγωγή JPEG απέτυχε. Απαιτείται λειτουργικός κωδικοποιητής JPEG του GDI+."
            },
            { TXT_LICENSE_UNAVAILABLE, L"Ο πόρος άδειας χρήσης δεν είναι διαθέσιμος." },
            { TXT_MEDIA_FILES, L"Αρχεία πολυμέσων" },
            { TXT_APPLICATION_DESCRIPTION, L"Προβολή πληροφοριών πολυμέσων" },
            { TXT_HELP_TITLE, L"MediaInfo — Βοήθεια" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"Το MediaInfo δεν μπόρεσε να αρχικοποιήσει την ανάλυση του "
                L"αρχείου." },
            { TXT_MEDIA_FILE_UNRECOGNIZED,
                L"Το MediaInfo δεν μπορεί να ανοίξει ή να αναγνωρίσει αυτό το αρχείο."
            },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"&Διαδρομή MediaInfo.dll:" },
            { TXT_MEDIALIB_REQUIRED,
                L"Το MediaInfo.dll δεν έχει φορτωθεί. Επιλέξτε το από Επιλογές > Προτιμήσεις."
            },
            { TXT_MEDIALIB_NOT_LOADED, L"Το MediaInfo.dll δεν έχει φορτωθεί." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Δεν φορτώθηκε συμβατό εξωτερικό ή ενσωματωμένο MediaInfo.dll. Επιλέξτε το από Επιλογές > "
                L"Προτιμήσεις."
            },
            { TXT_ANTIALIASING_NONE, L"Καμία" },
            { TXT_OK, L"OK" },
            { TXT_OPEN_TITLE, L"Άνοιγμα αρχείων πολυμέσων" },
            { TXT_PLATFORM, L"Πλατφόρμα προορισμού:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Προτιμήσεις" },
            { TXT_READY, L"Έτοιμο" },
            { TXT_FONT_REGULAR, L"Κανονικό" },
            { TXT_REPORT_LANGUAGE, L"Γλώσσα αναφο&ράς:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Πίνακες γλώσσας αναφορών" },
            { TXT_SELECT_MEDIALIB, L"Αναζήτηση: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Αναζήτηση: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH,
                L"Επιλέξτε ένα υπάρχον αρχείο πολυμέσων με διαδρομή μικρότερη από MAX_PATH."
            },
            { TXT_SELECTED_PATHS_TOO_LONG,
                L"Επιλέξτε υπάρχοντα αρχεία με διαδρομές μικρότερες από MAX_PATH."
            },
            { TXT_SELECT_CURL, L"Αναζήτηση: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Έγγραφο κειμένου ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"Αδυναμία αποθήκευσης της εικόνας BMP. Ελέγξτε προορισμό, ελεύθερη μνήμη και χώρο δίσκου."
            },
            { TXT_LIBRARY_WORKER_START_FAILED,
                L"Αδυναμία εκκίνησης της διεργασίας βιβλιοθήκης (σφάλμα Windows %lu)."
            },
            { TXT_REPORT_COPY_FAILED, L"Αδυναμία αντιγραφής της αναφοράς MediaInfo στη μνήμη." },
            { TXT_VIEWER_CREATE_FAILED, L"Αδυναμία δημιουργίας του προγράμματος προβολής MediaInfo." },
            { TXT_MEDIALIB_PATH_INVALID, L"Η διαδρομή του MediaInfo.dll είναι άκυρη ή πολύ μεγάλη." },
            { TXT_PNG_EXPORT_FAILED,
                L"Αδυναμία αποθήκευσης της εικόνας PNG. Ελέγξτε προορισμό, ελεύθερη μνήμη και χώρο δίσκου."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"Αδυναμία αποθήκευσης της εικόνας TIFF. Ελέγξτε προορισμό, ελεύθερη μνήμη και χώρο δίσκου."
            },
            { TXT_COPY_URL_FAILED, L"Δεν ήταν δυνατή η αντιγραφή του URL στο πρόχειρο." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"Η προβολή Win32 απαιτεί %s 32 bit. Επιλέξτε τη βιβλιοθήκη x86/i386."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Αδυναμία εγγραφής της ενσωματωμένης βιβλιοθήκης στο AppData, στο προφίλ χρήστη, στο "
                L"Program Files ή στον προσωρινό φάκελο."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED, L"Η αποσυμπίεση ή ο έλεγχος CRC της βιβλιοθήκης απέτυχε." },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Ο πόρος της ενσωματωμένης βιβλιοθήκης είναι άκυρος." },
            { TXT_CURL_FILENAME_INVALID,
                L"Η βιβλιοθήκη πρέπει να ονομάζεται libcurl.dll για να χρησιμοποιηθεί από το MediaInfo."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Δεν ήταν δυνατό το άνοιγμα του παραθύρου διαλόγου αρχείων." },
            { TXT_FILE_DIALOG_SELECTION_FAILED,
                L"Δεν ήταν δυνατή η λήψη των επιλεγμένων αρχείων από το παράθυρο διαλόγου."
            },
            { TXT_RECENT_FILE_MISSING,
                L"Το αρχείο «%s» δεν υπάρχει πλέον.\n\nΝα αφαιρεθεί αυτή η καταχώρηση από τη λίστα πρόσφατων "
                L"αρχείων;"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Το αρχείο δεν είναι πλέον διαθέσιμο:\n\n%s\n\nΝα αφαιρεθεί αυτή η καταχώρηση από τη λίστα "
                L"πρόσφατων αρχείων;"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Δεν ήταν δυνατή η αντιγραφή των πληροφοριών στο πρόχειρο." },
            { TXT_CURL_PATH_INVALID, L"Η διαδρομή του libcurl.dll είναι άκυρη ή πολύ μεγάλη." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Η βιβλιοθήκη δεν επέστρεψε έκδοση MediaInfo." },
            { TXT_CURL_EXPORTS_MISSING,
                L"Η βιβλιοθήκη δεν εξάγει τις συναρτήσεις curl που απαιτεί το MediaInfo."
            },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"Η βιβλιοθήκη δεν εξάγει τις απαιτούμενες συναρτήσεις Unicode του MediaInfo."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Η διεργασία βιβλιοθήκης απέτυχε κατά %s (κωδικός 0x%08lX). Επιλέξτε συμβατή DLL από "
                L"Επιλογές > Προτιμήσεις."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Η διεργασία βιβλιοθήκης δεν αποκρίνεται κατά %s. Επιλέξτε συμβατή DLL από Επιλογές > "
                L"Προτιμήσεις."
            },
            { TXT_PREFERENCES_SAVE_FAILED,
                L"Οι προτιμήσεις εφαρμόστηκαν, αλλά δεν αποθηκεύτηκαν στο Μητρώο."
            },
            { TXT_REPORT_START_FAILED, L"Δεν υπάρχει αρκετή μνήμη για την εκκίνηση της αναφοράς." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Αδυναμία δημιουργίας εικόνας της αναφοράς." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Αδυναμία φόρτωσης πίνακα γλώσσας. Επιλέξτε έγκυρο αρχείο "
                L"CSV MediaInfo σε UTF-8 ή UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"Αδυναμία εκκίνησης του νήματος αναφοράς." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"Το επιλεγμένο MediaInfo.dll απέρριψε τη γλώσσα αναφοράς." },
            { TXT_INVALID_WINDOWS_DLL, L"Το επιλεγμένο αρχείο δεν είναι έγκυρη DLL των Windows." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Η επιλεγμένη μορφή εικόνας δεν υποστηρίζεται." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Αδυναμία αποθήκευσης αναφοράς κειμένου. Ελέγξτε προορισμό και ελεύθερο χώρο δίσκου."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Αδυναμία ανοίγματος του ιστοτόπου στον προεπιλεγμένο περιηγητή." },
            { TXT_TOO_MANY_FILES, L"Επιλέχθηκαν πάρα πολλά αρχεία. Ανοίξτε μικρότερες ομάδες." },
            { TXT_LIBRARY_PATH_HINT,
                L"Χρησιμοποιήστε βιβλιοθήκες 32 bit συμβατές με την έκδοση των Windows σας. Αφήστε κενές τις "
                L"διαδρομές για αυτόματη αναζήτηση. Το MediaInfoLib v0.7.60 δεν χρησιμοποιεί libcurl.dll."
            },
            { TXT_VERSION, L"Έκδοση" },
            { TXT_WEBSITE_TOOLTIP, L"Άνοιγμα τοποθεσίας web %s" },
            { TXT_WAITING_FOR_REPORT, L"Αναμονή ολοκλήρωσης της τρέχουσας αναφοράς." },
            { TXT_WEBSITE_LABEL, L"Τοποθεσία web:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"την αντιγραφή της αναφοράς MediaInfo" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"Διαδρο&μή libcurl.dll:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"τη φόρτωση του MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"τη φόρτωση του libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"την αποδέσμευση του MediaInfo.dll" },
            { TXT_APPLY, L"&Εφαρμογή" },
            { TXT_TAB_NAME_LENGTH, L"Μήκος ονόματος &καρτέλας:" },
            { TXT_TITLE_NAME_LENGTH, L"&Μήκος τίτλου:" },
            { TXT_RECENT_FILES, L"Πρόσφατα αρχεία:" },
            { TXT_CLEAR_RECENT_FILES, L"Εκκα&θάριση" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"Το μήκος ονόματος καρτέλας πρέπει να είναι από 8 έως 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"Το μήκος ονόματος στον τίτλο πρέπει να είναι από 8 έως 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Η λίστα πρόσφατων αρχείων εκκαθαρίστηκε, αλλά δεν ήταν δυνατή η αποθήκευσή της στο Μητρώο."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"Κλεί&σιμο καρτελών με διπλό κλικ" },
            { TXT_CLOSE_TAB_CONTEXT, L"Κλείσιμο &καρτέλας" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"Να επ&ιτρέπονται πολλές παρουσίες" },
            { TXT_INSTANCE_FORWARD_FAILED,
                L"Δεν ήταν δυνατή η μεταβίβαση των αρχείων στην εκτελούμενη παρουσία του MediaInfo."
            },
            { TXT_LOADING, L"Φόρτωση…" },
            { TXT_LOADING_FILE, L"Φόρτωση αρχείου %s…" },
            { TXT_APPLICATION_HELP,
                L"ΑΡΧΕΙΑ ΚΑΙ ΚΑΡΤΕΛΕΣ\r\nΕγγενής προβολή αναφορών MediaInfo.dll για Windows x86. Κάθε "
                L"αρχείο έχει δική του καρτέλα μόνο για ανάγνωση. Ανοίξτε με Ctrl+O ή μεταφορά και "
                L"απόθεση. Το νέο άνοιγμα επιλέγει την υπάρχουσα καρτέλα. Ctrl+W ή το μεσαίο πλήκτρο του "
                L"ποντικιού κλείνει καρτέλα· Κλείσιμο όλων κλείνει όλες. Το μενού Αρχείο θυμάται οκτώ "
                L"πρόσφατα αρχεία. Το μενού περιβάλλοντος της κεφαλίδας μιας καρτέλας περιλαμβάνει το "
                L"Κλείσιμο καρτέλας. Ενεργοποιήστε το Κλείσιμο καρτελών με διπλό κλικ στις Προτιμήσεις "
                L"για να κλείνετε μια καρτέλα με διπλό κλικ στην κεφαλίδα της. Η επιλογή είναι αρχικά "
                L"απενεργοποιημένη και αποθηκεύεται. Διπλό κλικ στο κείμενο της αναφοράς επιλέγει μια "
                L"λέξη. Τριπλό κλικ επιλέγει μια λογική γραμμή. Το σύρσιμο επεκτείνει την επιλογή κατά "
                L"λέξεις ή γραμμές.\r\nΤο Άνοιγμα φακέλου… ανοίγει τα αρχεία που βρίσκονται απευθείας "
                L"στον επιλεγμένο φάκελο, το καθένα στη δική του καρτέλα. Οι υποφάκελοι δεν "
                L"περιλαμβάνονται.\r\nΤο Άνοιγμα και το Άνοιγμα φακέλου μοιράζονται τον τελευταίο "
                L"επιλεγμένο φάκελο. Η εξαγωγή θυμάται ξεχωριστό φάκελο, από προεπιλογή Έγγραφα. Η "
                L"Σύνθετη λειτουργία εμφανίζει επιπλέον πεδία στην αναφορά.\r\nΓνωστές μορφές / Γνωστοί "
                L"κωδικοποιητές / Γνωστές παράμετροι — MediaInfo.dll.\r\nΗ Πλήρης ανάλυση εξετάζει "
                L"ολόκληρο το αρχείο και μπορεί να διαρκέσει περισσότερο. Αυτές οι επιλογές αναφοράς και "
                L"το Επίπεδο ιχνηλάτησης ανήκουν σε κάθε καρτέλα. Μια αλλαγή ανανεώνει μόνο την ενεργή "
                L"καρτέλα. Ο τελευταίος συνδυασμός που επιλέχθηκε με μη αυτόματο τρόπο αποθηκεύεται για "
                L"νέες καρτέλες και την επόμενη εκκίνηση. Μια αντίστοιχη αναφορά από την προσωρινή μνήμη "
                L"χρησιμοποιείται ξανά όσο το αρχείο παραμένει αμετάβλητο.\r\nΕπίπεδο ιχνηλάτησης: 0 / 5 "
                L"/ 9 / 10.\r\nΗ επιλογή Αρχείο > Διαμόρφωση σελίδας… ανοίγει τις ρυθμίσεις χαρτιού, "
                L"προσανατολισμού και περιθωρίων για την τρέχουσα περίοδο λειτουργίας. Η εντολή Εκτύπωση… "
                L"(Ctrl+P) ανοίγει το παράθυρο εκτύπωσης του συστήματος· τα Windows 11 παρέχουν "
                L"προεπισκόπηση, ενώ τα Windows 10 και παλαιότερα διατηρούν το κλασικό παράθυρο. Το "
                L"Ctrl+P εκτυπώνει την ενεργή καρτέλα του κύριου παραθύρου ή την περιοχή κειμένου της "
                L"Βοήθειας ή των Πληροφοριών, ανάλογα με το παράθυρο που έχει την εστίαση. Οι αναφορές "
                L"χρησιμοποιούν την επιλεγμένη γραμματοσειρά αναφοράς, η Βοήθεια τη γραμματοσειρά "
                L"διαλόγων του συστήματος και οι Πληροφορίες τη δική τους γραμματοσειρά κειμένου. Αν δεν "
                L"υπάρχουν ανοιχτές καρτέλες αλλά η Βοήθεια είναι ανοιχτή, τα Διαμόρφωση σελίδας… και "
                L"Εκτύπωση… παραμένουν διαθέσιμα· η Εκτύπωση… εκτυπώνει τη Βοήθεια. Η Βοήθεια "
                L"χρησιμοποιεί το παράθυρο εκτύπωσης του κύριου παραθύρου· νέο Ctrl+P στη Βοήθεια φέρνει "
                L"το ίδιο παράθυρο στο προσκήνιο. Οι μεγάλες γραμμές αναδιπλώνονται και το κείμενο "
                L"χωρίζεται σε σελίδες. Η εκτύπωση γίνεται στο παρασκήνιο.\r\nΣύρετε ένα ή περισσότερα "
                L"αρχεία στο παράθυρο, στο εικονίδιο του EXE ή στη συντόμευσή του, ή δώστε τις διαδρομές "
                L"τους στη γραμμή εντολών. Αν δεν επιτρέπονται πολλές παρουσίες, τα αρχεία ανοίγουν στο "
                L"παράθυρο που εκτελείται ήδη.\r\nΤο αριστερό τμήμα της γραμμής κατάστασης δείχνει τις "
                L"διαδρομές αρχείων και την πρόοδο φόρτωσης, ενώ το δεξιό δείχνει την έκδοση της "
                L"φορτωμένης MediaInfo.dll. Οι μεγάλες διαδρομές συντομεύονται με αποσιωπητικά ανάλογα με "
                L"τον διαθέσιμο χώρο.\r\n\r\nΕΞΑΓΩΓΗ\r\nTXT, BMP, GIF, JPEG, PNG, TIFF και WebP "
                L"εμφανίζονται όταν διατίθενται. Ο τελευταίος φάκελος και η μορφή εξαγωγής "
                L"αποθηκεύονται.\r\nΤο TXT προσφέρει ANSI, UTF-8, UTF-8 με BOM, UTF-16 BE με BOM και "
                L"UTF-16 LE με BOM. Προεπιλεγμένη είναι η δεύτερη επιλογή, UTF-8 χωρίς BOM. Διατηρούνται "
                L"ολόκληρο το κείμενο της αναφοράς και οι αρχικές αλλαγές γραμμής.\r\n\r\nΔΗΜΙΟΥΡΓΗΣΤΕ "
                L"ΑΡΧΕΙΟ ΚΕΦΑΛΙΔΑΣ\r\nΤο μενού Εργαλεία είναι το τέταρτο στη γραμμή μενού. Η εντολή "
                L"Δημιουργήστε αρχείο κεφαλίδας… ανοίγει ένα αρχείο πηγής ανεξάρτητα από τις καρτέλες "
                L"αναφοράς και αντιγράφει τα πρώτα 524288 byte (512 KiB). Ένα μικρότερο αρχείο "
                L"αντιγράφεται πλήρως. Ένα κενό αρχείο παράγει ένα κενό αποτέλεσμα. Πρόκειται για "
                L"συνηθισμένη ανάγνωση δυαδικού αρχείου, χωρίς ανάλυση MediaInfo ή απαίτηση για το "
                L"MediaInfo.dll. Το εργαλείο αφήνει αμετάβλητες τις καρτέλες αναφορών και τη λίστα "
                L"πρόσφατων αρχείων του προγράμματος.\r\n\r\nΜετά την ανάγνωση ανοίγει το παράθυρο "
                L"διαλόγου Αποθήκευση ως στον φάκελο του αρχείου εισόδου. Για το video.mp4 προτείνεται το "
                L"όνομα video.mp4.header: το .header προστίθεται στο πλήρες αρχικό όνομα, μαζί με την "
                L"επέκταση. Μπορείτε να αλλάξετε τόσο το όνομα όσο και τον φάκελο προορισμού. Η ακύρωση "
                L"οποιουδήποτε από τα δύο παράθυρα διαλόγου δεν δημιουργεί αρχείο εξόδου. Η αντικατάσταση "
                L"υπάρχοντος αρχείου προορισμού απαιτεί επιβεβαίωση. Το αρχείο εισόδου παραμένει "
                L"αμετάβλητο και μια αποτυχημένη αποθήκευση διατηρεί το προηγούμενο αρχείο προορισμού. "
                L"Για το άνοιγμα και την αποθήκευση χρησιμοποιούνται τα πιο σύγχρονα παράθυρα διαλόγου "
                L"συστήματος που διατίθενται στη συγκεκριμένη έκδοση των Windows.\r\n\r\nΚατά την "
                L"εκκίνηση της εφαρμογής, το εργαλείο παίρνει τον αρχικό φάκελο εισαγωγής από το Αρχείο > "
                L"Άνοιγμα. Εάν δεν έχει αποθηκευτεί κανένας φάκελος, τα Windows επιλέγουν την αρχική "
                L"θέση. Αφού επιλεγεί ένα αρχείο εισόδου, το εργαλείο θυμάται τον δικό του φάκελο μόνο "
                L"μέχρι να βγει η εφαρμογή, ακόμα κι αν η Αποθήκευση ως ακυρωθεί. Δεν αλλάζει τους "
                L"φακέλους που χρησιμοποιούνται από τα Άνοιγμα και Εξαγωγή ούτε αποθηκεύει τον δικό του "
                L"φάκελο στις ρυθμίσεις της εφαρμογής. Κάθε διάλογος Αποθήκευση ως ξεκινά στο φάκελο του "
                L"τρέχοντος επιλεγμένου αρχείου εισόδου, ανεξάρτητα από τον προηγούμενο προορισμό "
                L"αποθήκευσης.\r\n\r\nΠΡΟΤΙΜΗΣΕΙΣ ΚΑΙ ΓΛΩΣΣΕΣ\r\nΟι Προτιμήσεις (Επιλογές > Προτιμήσεις, "
                L"Ctrl+G) περιέχουν διαδρομές βιβλιοθηκών, γραμματοσειρά αναφοράς, εξομάλυνση και "
                L"γλώσσες. Η διεπαφή έχει 36 παραλλαγές και αρχικά ακολουθεί τα Windows. Οι αναφορές "
                L"χρησιμοποιούν πάντα εξ ορισμού τα αρχικά αγγλικά της βιβλιοθήκης, ανεξάρτητα από "
                L"Windows και διεπαφή. Μόνο χειροκίνητη επιλογή αλλάζει τη γλώσσα: αγγλικά, 37 "
                L"μεταφράσεις ή προσαρμοσμένος πίνακας CSV MediaInfo. Το OK ή η Εφαρμογή επιβεβαιώνει τις "
                L"αλλαγές· το Άκυρο απορρίπτει τις εκκρεμείς αλλαγές. Στις Προτιμήσεις ορίζεται το όριο "
                L"ονόματος καρτέλας (προεπιλογή 80) και εκκαθαρίζεται η λίστα πρόσφατων αρχείων. Τα "
                L"μεγάλα ονόματα διατηρούν αρχή, τέλος και επέκταση με αποσιωπητικά στη μέση. Η "
                L"Εκκαθάριση αφαιρεί αμέσως τη λίστα πρόσφατων αρχείων, ακόμη και αν οι Προτιμήσεις "
                L"κλείσουν στη συνέχεια με Άκυρο.\r\n\r\nΟ τίτλος του κύριου παραθύρου εμφανίζει το ενεργό "
                L"αρχείο ως όνομα αρχείου — MediaInfo. Στις προτιμήσεις μπορείτε να ορίσετε χωριστά το μήκος "
                L"του ονόματος στον τίτλο από 8 έως 255 χαρακτήρες (προεπιλογή 40). Τα μεγαλύτερα ονόματα "
                L"συντομεύονται με τα ίδια αποσιωπητικά στη μέση και διατηρούν την επέκταση. Χωρίς ανοιχτές "
                L"καρτέλες, ο τίτλος είναι MediaInfo.\r\n\r\nΒΙΒΛΙΟΘΗΚΕΣ ΚΑΙ ΠΑΡΑΘΥΡΑ\r\nΤο πρόγραμμα"
                L" "
                L"περιλαμβάνει MediaInfo 26.10, 21.03 και 0.7.60, που δοκιμάζονται από τη νεότερη μετά "
                L"τις εξωτερικές βιβλιοθήκες. Οι δύο νεότερες έχουν αντίστοιχη libcurl· η 0.7.60 δεν την "
                L"αποσυμπιέζει ποτέ. Η θέση του παραθύρου αποθηκεύεται. Από προεπιλογή επιτρέπεται μόνο "
                L"μία παρουσία και οι επόμενες εκκινήσεις στέλνουν τα αρχεία στο ανοιχτό παράθυρο. Στις "
                L"προτιμήσεις μπορούν να επιτραπούν πολλές παρουσίες. Με πολλά παράθυρα, μόνο το πρώτο "
                L"παράθυρο κάθε τύπου παραθύρου επαναφέρει την αποθηκευμένη θέση· τα επόμενα επαναφέρουν "
                L"μόνο το μέγεθος.\r\n\r\nΗ εντολή Επεξεργασία > Εύρεση (Ctrl+F) αναζητά στην ενεργή "
                L"καρτέλα αναφοράς ή στην περιοχή κειμένου της Βοήθειας ή των Πληροφοριών, ανάλογα με το "
                L"παράθυρο που έχει την εστίαση. Το παράθυρο αναζήτησης διατηρεί την τελευταία επιλεγμένη "
                L"πηγή όσο έχει την εστίαση. F3 επαναλαμβάνει την αναζήτηση, ενώ το Shift+F3 αντιστρέφει "
                L"την κατεύθυνσή της. Στο τέλος του κειμένου, η αναζήτηση συνεχίζεται από το άλλο άκρο. Η "
                L"επιλογή Επιλογές > Αναδίπλωση λέξεων αφορά μόνο την ενεργή καρτέλα· η ένδειξη επιλογής "
                L"ακολουθεί την επιλεγμένη καρτέλα. Το παράθυρο αναζήτησης μπορεί να ελαχιστοποιηθεί και "
                L"να αλλάξει πλάτος· η θέση του και η επιλογή Πάντα σε πρώτο πλάνο αποθηκεύονται. Έως 30 "
                L"κείμενα αναζήτησης και οι επιλογές τους διατηρούνται μόνο μέχρι το κλείσιμο της "
                L"εφαρμογής. Οι επιλογές αρχής και τέλους αφορούν λογικές γραμμές. Οι κανονικές εκφράσεις "
                L"χρησιμοποιούν τη σύνταξη PCRE2. Οι υπόλοιπες εντολές του μενού Επεξεργασία αφορούν την "
                L"ενεργή καρτέλα αναφοράς. Το Enter ξεκινά την αναζήτηση· το Shift+Enter αντιστρέφει την "
                L"επιλεγμένη κατεύθυνση. Η επιλογή «Διάκριση πεζών-κεφαλαίων» ξεχωρίζει πεζά και "
                L"κεφαλαία· η «Αναζήτηση προς τα πίσω» αναζητά προς την αρχή του κειμένου. Η επιλογή μιας "
                L"εγγραφής ιστορικού επαναφέρει και τις πέντε επιλογές αναζήτησης, συμπεριλαμβανομένης "
                L"της κατάστασης των κανονικών εκφράσεων· η «Πάντα σε πρώτο πλάνο» είναι ανεξάρτητη. Η "
                L"«Κανονική έκφραση» απενεργοποιεί τις «Η γραμμή αρχίζει από» και «Η γραμμή τελειώνει "
                L"σε». Όταν είναι ενεργές και οι δύο επιλογές άκρων γραμμής, αρκεί αντιστοιχία σε ένα "
                L"άκρο. Η «Αναδίπλωση λέξεων» αλλάζει μόνο την εμφάνιση."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"Αδυναμία αποθήκευσης της εικόνας WebP. Ελέγξτε προορισμό, ελεύθερη μνήμη και χώρο δίσκου."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Έγγραφο κειμένου UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Έγγραφο κειμένου UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Έγγραφο κειμένου UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Έγγραφο κειμένου UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Η αναφορά δεν μπορεί να αποθηκευτεί με αυτήν την κωδικοποίηση χωρίς απώλεια χαρακτήρων. "
                L"Επιλέξτε άλλη κωδικοποίηση."
            },
            { TXT_OPEN_FOLDER, L"Άνοιγμα &φακέλου…" },
            { TXT_OPEN_FOLDER_TITLE, L"Άνοιγμα φακέλου" },
            { TXT_FOLDER_READ_FAILED,
                L"Δεν ήταν δυνατή η ανάγνωση του φακέλου:\n\n%s\n\nΣφάλμα των Windows %lu."
            },
            { TXT_ADVANCED_MODE, L"&Σύνθετη λειτουργία" },
            { TXT_REPORT_DETAIL_REJECTED,
                L"Η επιλεγμένη MediaInfo.dll απέρριψε τη ρύθμιση λεπτομερειών της αναφοράς."
            },
            { TXT_KNOWN_FORMATS, L"Γνωστές &μορφές" },
            { TXT_KNOWN_CODECS, L"Γνωστοί &κωδικοποιητές" },
            { TXT_KNOWN_PARAMETERS, L"Γνωστές πα&ράμετροι" },
            { TXT_KNOWN_FORMATS_TITLE, L"Γνωστές μορφές" },
            { TXT_KNOWN_CODECS_TITLE, L"Γνωστοί κωδικοποιητές" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Γνωστές παράμετροι" },
            { TXT_KNOWN_INFO_FAILED, L"Η βιβλιοθήκη δεν επέστρεψε τις ζητούμενες πληροφορίες." },
            { TXT_FULL_PARSING, L"Πλήρης &ανάλυση" },
            { TXT_PARSING_REJECTED, L"Η επιλεγμένη MediaInfo.dll απέρριψε τη ρύθμιση ανάλυσης." },
            { TXT_TRACE_LEVEL_0, L"Επίπεδο ιχνηλάτησης &0" },
            { TXT_TRACE_LEVEL_5, L"Επίπεδο ιχνηλάτησης &5" },
            { TXT_TRACE_LEVEL_9, L"Επίπεδο ιχνηλάτησης &9" },
            { TXT_TRACE_LEVEL_10, L"Επίπεδο ιχνηλάτησης &10" },
            { TXT_PAGE_SETUP, L"Διαμόρφωση &σελίδας…" },
            { TXT_PAGE_SETUP_FAILED, L"Δεν ήταν δυνατό το άνοιγμα της διαμόρφωσης σελίδας." },
            { TXT_PRINT, L"Εκ&τύπωση…\tCtrl+P" },
            { TXT_PRINTING, L"Εκτύπωση…" },
            { TXT_PRINT_FAILED,
                L"Δεν ήταν δυνατή η εκτύπωση του κειμένου. Ελέγξτε τον εκτυπωτή, τις ρυθμίσεις και τη "
                L"διαθέσιμη μνήμη."
            },
            { TXT_TOOLS_MENU, L"&Εργαλεία" },
            { TXT_CREATE_HEADER, L"Δημιουργήστε αρχείο &κεφαλίδας…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Δημιουργήστε αρχείο κεφαλίδας - Άνοιγμα" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Δημιουργήστε αρχείο κεφαλίδας - Αποθήκευση ως" },
            { TXT_HEADER_FORMAT, L"Αρχείο κεφαλίδας (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Δεν ήταν δυνατή η ανάγνωση της κεφαλίδας του αρχείου:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Δεν ήταν δυνατή η αποθήκευση του αρχείου κεφαλίδας:\n\n%s" },
            { TXT_COPY, L"&Αντιγραφή" },
            { TXT_COPY_FILE_NAME, L"Αντιγραφή &ονόματος αρχείου" },
            { TXT_COPY_FULL_PATH, L"Αντιγραφή πλήρους &διαδρομής" },
            { TXT_LAUNCH_FILE, L"Εκκί&νηση αρχείου" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"Ε&μφάνιση σε φάκελο" },
            { TXT_EDIT_MENU, L"Επε&ξεργασία" },
            { TXT_WORD_WRAP, L"Α&ναδίπλωση λέξεων" },
            { TXT_WORD_WRAP_FAILED, L"Δεν ήταν δυνατή η αλλαγή της αναδίπλωσης λέξεων." },
            { TXT_COPY_SELECTION, L"&Αντιγραφή\tCtrl+C" },
            { TXT_SELECT_ALL, L"Επιλογή ό&λων\tCtrl+A" },
            { TXT_FIND_MENU, L"&Εύρεση…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Εύρεση επό&μενου\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Εύρεση &προηγούμενου\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Εύρεση" },
            { TXT_FIND_WHAT, L"Εύ&ρεση:" },
            { TXT_FIND_NEXT, L"Εύρεση επό&μενου" },
            { TXT_FIND_MATCH_CASE, L"&Διάκριση πεζών-κεφαλαίων" },
            { TXT_FIND_BACKWARD, L"Αναζήτηση προς τα &πίσω" },
            { TXT_FIND_TOPMOST, L"Πάντα σε πρώτο π&λάνο" },
            { TXT_FIND_STARTS_WITH, L"Η γραμμή &αρχίζει από" },
            { TXT_FIND_ENDS_WITH, L"Η γραμμή τελειώνει &σε" },
            { TXT_FIND_REGEX, L"Κανονική έκ&φραση" },
            { TXT_FIND_NOT_FOUND, L"Το καθορισμένο κείμενο δεν βρέθηκε." },
            { TXT_FIND_FAILED, L"Δεν ήταν δυνατή η ολοκλήρωση της αναζήτησης." },
            { TXT_FIND_REGEX_ERROR, L"Σφάλμα κανονικής έκφρασης:\r\n\r\n%s" },
        }
    },
    {
        LANG_BS,
        {
            { TXT_LANGUAGE_NAME, L"Bosanski" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nWeb-mjesto: " },
            { TXT_FILE_OPEN_FAILED, L"Nije moguće otvoriti %s. Provjerite putanju i dozvole." },
            { TXT_BROWSE_DLL, L"P&regledaj…" },
            { TXT_BROWSE_REPORT, L"Preg&ledaj…" },
            { TXT_CLOSE, L"&Zatvori" },
            { TXT_CLOSE_TAB, L"&Zatvori\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"Po&drazumijevano" },
            { TXT_EXPORT, L"&Izvezi…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Datoteka" },
            { TXT_REPORT_FONT, L"&Font izvještaja:" },
            { TXT_HELP_MENU, L"&Pomoć" },
            { TXT_HELP, L"&Pomoć\tF1" },
            { TXT_LANGUAGE, L"&Jezik:" },
            { TXT_OPEN_WEBSITE, L"&Otvori u podrazumijevanom pregledniku" },
            { TXT_OPEN, L"&Otvori…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Opcije" },
            { TXT_PREFERENCES_MENU, L"&Postavke…\tCtrl+G" },
            { TXT_ABOUT, L"&O programu" },
            { TXT_ABOUT_TITLE, L"O programu %ls" },
            { TXT_ALL_FILES, L"Sve datoteke" },
            { TXT_FONT_BOLD, L"Podebljano" },
            { TXT_FONT_BOLD_ITALIC, L"Podebljano + Kurziv" },
            { TXT_BROWSE_CURL, L"Pr&egledaj…" },
            { TXT_CANCEL, L"Otkaži" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Nije moguće učitati MediaInfo.dll (greška sistema Windows %lu). Koristite 32-bitnu DLL "
                L"kompatibilnu s ovom verzijom sistema Windows."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Nije moguće učitati libcurl.dll (greška sistema Windows %lu). Izaberite 32-bitnu "
                L"biblioteku kompatibilnu s ovom verzijom sistema Windows."
            },
            { TXT_CLOSE_ALL, L"Zatvori &sve" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Kopiraj &adresu" },
            { TXT_COPY_INFORMATION, L"Kopiraj &informacije" },
            { TXT_DLL_FILES, L"Dinamičke biblioteke" },
            { TXT_EXIT, L"Iz&laz\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Ugrađene biblioteke MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Ugrađene biblioteke libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Izvezi izvještaj" },
            { TXT_FONT_ANTIALIASING, L"Iz&glađivanje fonta:" },
            { TXT_GIF_EXPORT_FAILED, L"Izvoz GIF nije uspio. GIF bez gubitaka zahtijeva najviše 256 boja." },
            { TXT_FONT_ITALIC, L"Kurziv" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED, L"Izvoz JPEG nije uspio. Potreban je ispravan GDI+ JPEG koder." },
            { TXT_LICENSE_UNAVAILABLE, L"Resurs licence nije dostupan." },
            { TXT_MEDIA_FILES, L"Medijske datoteke" },
            { TXT_APPLICATION_DESCRIPTION, L"Preglednik informacija o medijima" },
            { TXT_HELP_TITLE, L"MediaInfo — Pomoć" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo nije mogao inicijalizirati analizu datoteke." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo ne može otvoriti ili prepoznati ovu datoteku." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"&Putanja do MediaInfo.dll:" },
            { TXT_MEDIALIB_REQUIRED, L"MediaInfo.dll nije učitana. Izaberite je u Opcije > Postavke." },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll nije učitana." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Nije moguće učitati kompatibilnu vanjsku ili ugrađenu MediaInfo.dll. Izaberite je u "
                L"Opcije > Postavke."
            },
            { TXT_ANTIALIASING_NONE, L"Nema" },
            { TXT_OK, L"U redu" },
            { TXT_OPEN_TITLE, L"Otvori medijske datoteke" },
            { TXT_PLATFORM, L"Ciljna platforma:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Postavke" },
            { TXT_READY, L"Spreman" },
            { TXT_FONT_REGULAR, L"Obično" },
            { TXT_REPORT_LANGUAGE, L"Jezik &izvještaja:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Jezičke tabele izvještaja" },
            { TXT_SELECT_MEDIALIB, L"Pregledaj: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Pregledaj: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH,
                L"Izaberite postojeću medijsku datoteku s putanjom kraćom od MAX_PATH."
            },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Izaberite postojeće datoteke s putanjama kraćim od MAX_PATH." },
            { TXT_SELECT_CURL, L"Pregledaj: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Tekstualni dokument ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"Nije moguće sačuvati BMP sliku. Provjerite odredište, slobodnu memoriju i prostor na disku."
            },
            { TXT_LIBRARY_WORKER_START_FAILED,
                L"Nije moguće pokrenuti proces biblioteke (greška Windows %lu)."
            },
            { TXT_REPORT_COPY_FAILED, L"Nije moguće kopirati izvještaj MediaInfo u memoriju." },
            { TXT_VIEWER_CREATE_FAILED, L"Nije moguće napraviti preglednik MediaInfo." },
            { TXT_MEDIALIB_PATH_INVALID, L"Putanja do MediaInfo.dll nije ispravna ili je preduga." },
            { TXT_PNG_EXPORT_FAILED,
                L"Nije moguće sačuvati PNG sliku. Provjerite odredište, slobodnu memoriju i prostor na disku."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"Nije moguće sačuvati TIFF sliku. Provjerite odredište, slobodnu memoriju i prostor na "
                L"disku."
            },
            { TXT_COPY_URL_FAILED, L"Nije moguće kopirati URL u međuspremnik." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"Preglednik Win32 zahtijeva 32-bitnu %s. Izaberite biblioteku x86/i386."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Ugrađenu biblioteku nije moguće upisati u AppData, korisnički profil, Program Files ili "
                L"privremenu fasciklu."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED, L"Raspakivanje biblioteke ili CRC provjera nije uspjela." },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Resurs ugrađene biblioteke nije ispravan." },
            { TXT_CURL_FILENAME_INVALID,
                L"Biblioteka se mora zvati libcurl.dll da bi je MediaInfo mogla koristiti."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Nije moguće otvoriti dijalog za datoteke." },
            { TXT_FILE_DIALOG_SELECTION_FAILED,
                L"Nije moguće dobiti izabrane datoteke iz dijaloga za datoteke."
            },
            { TXT_RECENT_FILE_MISSING,
                L"Datoteka „%s“ više ne postoji.\n\nŽelite li ukloniti ovu stavku s popisa nedavnih datoteka?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Datoteka više nije dostupna:\n\n%s\n\nŽelite li ukloniti ovu stavku s popisa nedavnih "
                L"datoteka?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Nije moguće kopirati informacije u međuspremnik." },
            { TXT_CURL_PATH_INVALID, L"Putanja do libcurl.dll nije ispravna ili je preduga." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Biblioteka nije vratila verziju MediaInfo." },
            { TXT_CURL_EXPORTS_MISSING, L"Biblioteka ne izvozi funkcije curl potrebne za MediaInfo." },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"Biblioteka ne izvozi potrebne Unicode funkcije biblioteke MediaInfo."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Proces biblioteke nije uspio tokom %s (kod 0x%08lX). Izaberite kompatibilnu DLL u Opcije "
                L"> Postavke."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Proces biblioteke ne odgovara tokom %s. Izaberite kompatibilnu DLL u Opcije > Postavke."
            },
            { TXT_PREFERENCES_SAVE_FAILED, L"Postavke su primijenjene, ali nisu sačuvane u registru." },
            { TXT_REPORT_START_FAILED, L"Nema dovoljno memorije za pokretanje izvještaja." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Nije moguće napraviti sliku izvještaja." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Nije moguće učitati jezičku tabelu. Izaberite ispravan "
                L"MediaInfo CSV u UTF-8 ili UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"Nije moguće pokrenuti nit izvještaja." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"Izabrana MediaInfo.dll odbila je jezik izvještaja." },
            { TXT_INVALID_WINDOWS_DLL, L"Izabrana datoteka nije ispravna Windows DLL." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Izabrani format slike nije podržan." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Nije moguće sačuvati tekstualni izvještaj. Provjerite odredište i slobodan prostor na "
                L"disku."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Nije moguće otvoriti stranicu u podrazumijevanom pregledniku." },
            { TXT_TOO_MANY_FILES, L"Izabrano je previše datoteka. Otvarajte manje grupe." },
            { TXT_LIBRARY_PATH_HINT,
                L"Koristite 32-bitne biblioteke kompatibilne s vašom verzijom sistema Windows. Ostavite "
                L"putanje prazne za automatsku pretragu. MediaInfoLib v0.7.60 ne koristi libcurl.dll."
            },
            { TXT_VERSION, L"Verzija" },
            { TXT_WEBSITE_TOOLTIP, L"Posjeti web-mjesto %s" },
            { TXT_WAITING_FOR_REPORT, L"Čekanje završetka trenutnog izvještaja." },
            { TXT_WEBSITE_LABEL, L"Web-mjesto:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"kopiranja izvještaja MediaInfo" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"Putanja do libc&url.dll:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"učitavanja MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"učitavanja libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"oslobađanja MediaInfo.dll" },
            { TXT_APPLY, L"Primije&ni" },
            { TXT_TAB_NAME_LENGTH, L"Dužina naziva &kartice:" },
            { TXT_TITLE_NAME_LENGTH, L"D&užina naslova:" },
            { TXT_RECENT_FILES, L"Nedavne datoteke:" },
            { TXT_CLEAR_RECENT_FILES, L"&Očisti" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"Dužina naziva kartice mora biti između 8 i 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"Dužina naziva u naslovu mora biti između 8 i 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Lista nedavnih datoteka je očišćena, ali nije sačuvana u registru."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"Z&atvaraj kartice dvoklikom" },
            { TXT_CLOSE_TAB_CONTEXT, L"&Zatvori karticu" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"Do&zvoli više instanci" },
            { TXT_INSTANCE_FORWARD_FAILED,
                L"Datoteke nije bilo moguće proslijediti pokrenutoj instanci programa MediaInfo."
            },
            { TXT_LOADING, L"Učitavanje…" },
            { TXT_LOADING_FILE, L"Učitavanje datoteke %s…" },
            { TXT_APPLICATION_HELP,
                L"DATOTEKE I KARTICE\r\nIzvorni Windows x86 preglednik izvještaja MediaInfo.dll. Svaka "
                L"datoteka ima vlastitu karticu samo za čitanje. Otvorite pomoću Ctrl+O ili prevlačenjem. "
                L"Ponovno otvaranje bira postojeću karticu. Ctrl+W ili srednje dugme miša zatvara "
                L"karticu; Zatvori sve zatvara sve kartice. Meni Datoteka pamti osam nedavnih datoteka. "
                L"Kontekstni meni zaglavlja kartice sadrži Zatvori karticu. U Postavkama uključite "
                L"Zatvaraj kartice dvoklikom da biste zatvorili karticu dvoklikom na njeno zaglavlje. "
                L"Opcija je početno isključena i njeno stanje se čuva. Dvoklik u tekstu izvještaja "
                L"odabire riječ. Trostruki klik odabire logički red. Povlačenje proširuje odabir po "
                L"riječima ili redovima.\r\nOtvori fasciklu… otvara datoteke koje su neposredno u "
                L"izabranoj fascikli, svaku na zasebnoj kartici. Podfascikle nisu uključene.\r\nOtvori i "
                L"Otvori fasciklu dijele posljednju izabranu fasciklu. Izvoz pamti zasebnu fasciklu, "
                L"zadano Dokumenti. Napredni način rada prikazuje dodatna polja izvještaja.\r\nPoznati "
                L"formati / Poznati kodeci / Poznati parametri — MediaInfo.dll.\r\nPotpuna analiza "
                L"ispituje cijelu datoteku i može potrajati duže. Ove opcije izvještaja i Nivo praćenja "
                L"pripadaju svakoj kartici; promjena osvježava samo aktivnu karticu. Posljednja ručno "
                L"odabrana kombinacija se čuva za nove kartice i sljedeće pokretanje. Odgovarajući "
                L"keširani izvještaj se ponovo koristi dok datoteka ostaje nepromijenjena.\r\nNivo "
                L"praćenja: 0 / 5 / 9 / 10.\r\nDatoteka > Podešavanje stranice… otvara postavke papira, "
                L"orijentacije i margina za trenutnu sesiju. Štampaj… (Ctrl+P) otvara sistemski dijalog "
                L"štampanja; Windows 11 pruža pregled, dok Windows 10 i stariji zadržavaju klasični "
                L"dijalog. Ctrl+P štampa aktivnu karticu glavnog prozora ili tekstualno polje prozora "
                L"Pomoć ili O programu, zavisno od toga koji prozor ima fokus. Izvještaji koriste "
                L"odabrani font izvještaja, Pomoć sistemski font dijaloga, a O programu font svog "
                L"tekstualnog polja. Ako nema otvorenih kartica, a Pomoć je otvorena, Podešavanje "
                L"stranice… i Štampaj… ostaju dostupni; Štampaj… štampa pomoć. Pomoć koristi dijalog "
                L"štampanja glavnog prozora; ponovni Ctrl+P u Pomoći dovodi isti dijalog u prvi plan. "
                L"Dugi redovi se prelamaju, a tekst dijeli na stranice. Štampanje se odvija u "
                L"pozadini.\r\nPrevucite jednu ili više datoteka u prozor, na ikonu EXE datoteke ili "
                L"njenu prečicu, ili proslijedite njihove putanje preko komandne linije. Ako više "
                L"instanci nije dozvoljeno, datoteke se otvaraju u već pokrenutom prozoru.\r\nLijeva "
                L"strana statusne trake prikazuje putanje datoteka i tok učitavanja, a desna verziju "
                L"učitane MediaInfo.dll biblioteke. Duge putanje skraćuju se trotačkom prema dostupnom "
                L"prostoru.\r\n\r\nIZVOZ\r\nTXT, BMP, GIF, JPEG, PNG, TIFF i WebP prikazuju se kada su "
                L"dostupni. Posljednja fascikla i format izvoza se pamte.\r\nTXT nudi ANSI, UTF-8, UTF-8 "
                L"s BOM-om, UTF-16 BE s BOM-om i UTF-16 LE s BOM-om. Podrazumijevana je druga stavka, "
                L"UTF-8 bez BOM-a. Čuvaju se cijeli tekst izvještaja i izvorni završeci redova.\r\n\r\n"
                L"NAPRAVI DATOTEKU ZAGLAVLJA\r\nMeni Alati je četvrti na traci menija. Njegova komanda "
                L"Napravi datoteku zaglavlja… otvara jednu izvornu datoteku nezavisno od kartica "
                L"izvještaja i kopira njenih prvih 524288 bajtova (512 KiB). Kraća datoteka se kopira u "
                L"potpunosti; prazna datoteka proizvodi prazan izlaz. Ovo je obično čitanje binarnih "
                L"datoteka, bez MediaInfo analize ili zahtjeva za MediaInfo.dll. Alat ostavlja kartice "
                L"izvještaja i listu nedavnih datoteka programa nepromijenjene.\r\n\r\nNakon čitanja, "
                L"dijalog Sačuvaj kao počinje u fascikli izvorne datoteke i predlaže video.mp4.header za "
                L"video.mp4: .header se dodaje kompletnom originalnom imenu. Možete promijeniti i naziv i "
                L"odredišnu fasciklu. Otkazivanje bilo kojeg dijaloga ne upisuje izlaz. Zamjena "
                L"postojećeg odredišta zahtijeva potvrdu. Izvor ostaje nepromijenjen; neuspješno čuvanje "
                L"čuva prethodnu destinaciju. Otvaranje i čuvanje koriste najnovije sistemske dijaloge "
                L"dostupne u toj verziji Windowsa.\r\n\r\nPrilikom pokretanja aplikacije, alat preuzima "
                L"svoju početnu ulaznu fasciklu iz Datoteka > Otvori. Ako nijedna fascikla nije sačuvana, "
                L"Windows bira početnu lokaciju. Nakon odabira ulazne datoteke, alat pamti svoju fasciklu "
                L"samo dok se aplikacija ne zatvori, čak i ako je Sačuvaj kao otkazano. Ne mijenja "
                L"fascikle koje koriste Otvori i Izvezi niti čuva svoju fasciklu u postavkama aplikacije. "
                L"Svaki dijalog Sačuvaj kao počinje u fascikli trenutno odabrane ulazne datoteke, bez "
                L"obzira na prethodno odredište za čuvanje.\r\n\r\nPOSTAVKE I JEZICI\r\nPostavke (Opcije "
                L"> Postavke, Ctrl+G) sadrže putanje biblioteka, font izvještaja, izglađivanje i jezike. "
                L"Sučelje ima 36 varijanti i početno prati Windows. Izvještaji uvijek podrazumijevano "
                L"koriste izvorni engleski biblioteke, nezavisno od Windowsa i sučelja. To mijenja samo "
                L"ručni izbor jezika: engleski, 37 prijevoda ili vlastita MediaInfo CSV tabela. U redu "
                L"ili Primijeni potvrđuje promjene; Otkaži odbacuje nepotvrđene promjene. Postavke "
                L"određuju granicu naziva kartice (podrazumijevano 80) i brišu listu nedavnih datoteka. "
                L"Dugi nazivi zadržavaju početak, kraj i nastavak s trotačkom u sredini. Očisti odmah "
                L"uklanja listu nedavnih datoteka, čak i ako zatim zatvorite Postavke dugmetom "
                L"Otkaži.\r\n\r\nNaslov glavnog prozora prikazuje aktivnu datoteku u obliku naziv datoteke — "
                L"MediaInfo. U postavkama se dužina naziva u naslovu može zasebno postaviti na 8–255 znakova "
                L"(zadano 40). Duži nazivi skraćuju se istom trotačkom u sredini, uz očuvanje nastavka. Bez "
                L"otvorenih kartica naslov je MediaInfo.\r\n\r\nBIBLIOTEKE I PROZORI\r\nProgram sadrži "
                L"MediaInfo 26.10, 21.03 i 0.7.60, "
                L"koje se pokušavaju od najnovije nakon vanjskih biblioteka. Dvije novije verzije imaju "
                L"odgovarajući libcurl; 0.7.60 ga nikada ne raspakuje. Položaj prozora se čuva. "
                L"Podrazumijevano je dozvoljena samo jedna instanca, a naredna pokretanja šalju datoteke "
                L"otvorenom prozoru. U postavkama se može dozvoliti više instanci. Kada postoji više "
                L"prozora, samo prvi prozor svakog tipa prozora vraća sačuvani položaj; ostali vraćaju "
                L"samo veličinu.\r\n\r\nUređivanje > Pronađi (Ctrl+F) pretražuje aktivnu karticu "
                L"izvještaja ili tekstualno polje prozora Pomoć ili O programu, zavisno od toga koji "
                L"prozor ima fokus. Prozor pretrage zadržava posljednji odabrani izvor dok ima fokus. F3 "
                L"ponavlja pretragu, a Shift+F3 mijenja njen smjer. Na kraju teksta pretraga se nastavlja "
                L"s drugog kraja. Opcije > Prelamanje redova važi samo za aktivnu karticu; oznaka prati "
                L"odabranu karticu. Prozor pretrage može se minimizirati i mijenjati mu se širina; "
                L"položaj i opcija Uvijek na vrhu se pamte. Do 30 tekstova pretrage s njihovim opcijama "
                L"čuva se samo do zatvaranja aplikacije. Opcije početka i kraja odnose se na logičke "
                L"redove. Regularni izrazi koriste PCRE2 sintaksu. Ostale komande menija Uređivanje "
                L"odnose se na aktivnu karticu izvještaja. Enter pokreće pretragu, a Shift+Enter obrće "
                L"odabrani smjer. „Razlikuj velika i mala slova“ razlikuje velika i mala slova; „Traži "
                L"unazad“ traži prema početku teksta. Izbor stavke historije vraća svih pet opcija "
                L"pretrage, uključujući stanje režima regularnih izraza; „Uvijek na vrhu“ je nezavisna "
                L"opcija. „Regularni izraz“ onemogućava „Red počinje sa“ i „Red završava sa“. Kada su "
                L"uključene obje opcije krajeva reda, dovoljno je poklapanje na jednom kraju. „Prelamanje "
                L"redova“ mijenja samo prikaz."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"Nije moguće sačuvati WebP sliku. Provjerite odredište, slobodnu memoriju i prostor na "
                L"disku."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Tekstualni dokument UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Tekstualni dokument UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Tekstualni dokument UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Tekstualni dokument UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Izvještaj se ne može sačuvati u ovom kodiranju bez gubitka znakova. Odaberite drugo "
                L"kodiranje teksta."
            },
            { TXT_OPEN_FOLDER, L"Otvori &fasciklu…" },
            { TXT_OPEN_FOLDER_TITLE, L"Otvori fasciklu" },
            { TXT_FOLDER_READ_FAILED, L"Fascikla se ne može pročitati:\n\n%s\n\nGreška Windowsa %lu." },
            { TXT_ADVANCED_MODE, L"&Napredni način rada" },
            { TXT_REPORT_DETAIL_REJECTED, L"Izabrana MediaInfo.dll odbila je postavku detalja izvještaja." },
            { TXT_KNOWN_FORMATS, L"Poznati &formati" },
            { TXT_KNOWN_CODECS, L"Poznati &kodeci" },
            { TXT_KNOWN_PARAMETERS, L"Poznati p&arametri" },
            { TXT_KNOWN_FORMATS_TITLE, L"Poznati formati" },
            { TXT_KNOWN_CODECS_TITLE, L"Poznati kodeci" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Poznati parametri" },
            { TXT_KNOWN_INFO_FAILED, L"Biblioteka nije vratila tražene informacije." },
            { TXT_FULL_PARSING, L"Potpuna &analiza" },
            { TXT_PARSING_REJECTED, L"Izabrana MediaInfo.dll odbila je postavku analize." },
            { TXT_TRACE_LEVEL_0, L"Nivo praćenja &0" },
            { TXT_TRACE_LEVEL_5, L"Nivo praćenja &5" },
            { TXT_TRACE_LEVEL_9, L"Nivo praćenja &9" },
            { TXT_TRACE_LEVEL_10, L"Nivo praćenja &10" },
            { TXT_PAGE_SETUP, L"&Podešavanje stranice…" },
            { TXT_PAGE_SETUP_FAILED, L"Nije moguće otvoriti podešavanje stranice." },
            { TXT_PRINT, L"Š&tampaj…\tCtrl+P" },
            { TXT_PRINTING, L"Štampanje…" },
            { TXT_PRINT_FAILED,
                L"Tekst se ne može odštampati. Provjerite štampač, njegove postavke i dostupnu memoriju."
            },
            { TXT_TOOLS_MENU, L"&Alati" },
            { TXT_CREATE_HEADER, L"Napravi datoteku &zaglavlja…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Napravi datoteku zaglavlja - Otvori" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Napravi datoteku zaglavlja - Sačuvaj kao" },
            { TXT_HEADER_FORMAT, L"Datoteka zaglavlja (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Nije moguće pročitati zaglavlje datoteke:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Nije moguće sačuvati datoteku zaglavlja:\n\n%s" },
            { TXT_COPY, L"&Kopiraj" },
            { TXT_COPY_FILE_NAME, L"Kopiraj &naziv datoteke" },
            { TXT_COPY_FULL_PATH, L"Kopiraj punu p&utanju" },
            { TXT_LAUNCH_FILE, L"Po&kreni datoteku" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"P&rikaži u fascikli" },
            { TXT_EDIT_MENU, L"&Uređivanje" },
            { TXT_WORD_WRAP, L"P&relamanje redova" },
            { TXT_WORD_WRAP_FAILED, L"Prelamanje redova nije moguće promijeniti." },
            { TXT_COPY_SELECTION, L"&Kopiraj\tCtrl+C" },
            { TXT_SELECT_ALL, L"Odaberi &sve\tCtrl+A" },
            { TXT_FIND_MENU, L"&Pronađi…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Pronađi s&ljedeće\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Pronađi preth&odno\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Pronađi" },
            { TXT_FIND_WHAT, L"&Traži:" },
            { TXT_FIND_NEXT, L"Pronađi s&ljedeće" },
            { TXT_FIND_MATCH_CASE, L"Razlikuj velika i &mala slova" },
            { TXT_FIND_BACKWARD, L"Traži &unazad" },
            { TXT_FIND_TOPMOST, L"Uvijek na &vrhu" },
            { TXT_FIND_STARTS_WITH, L"Red počinje &sa" },
            { TXT_FIND_ENDS_WITH, L"Red završava s&a" },
            { TXT_FIND_REGEX, L"&Regularni izraz" },
            { TXT_FIND_NOT_FOUND, L"Navedeni tekst nije pronađen." },
            { TXT_FIND_FAILED, L"Pretragu nije moguće dovršiti." },
            { TXT_FIND_REGEX_ERROR, L"Greška u regularnom izrazu:\r\n\r\n%s" },
        }
    },
    {
        LANG_HR,
        {
            { TXT_LANGUAGE_NAME, L"Hrvatski" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nWeb-mjesto: " },
            { TXT_FILE_OPEN_FAILED, L"Nije moguće otvoriti %s. Provjerite putanju i dozvole." },
            { TXT_BROWSE_DLL, L"P&regledaj…" },
            { TXT_BROWSE_REPORT, L"Preg&ledaj…" },
            { TXT_CLOSE, L"&Zatvori" },
            { TXT_CLOSE_TAB, L"&Zatvori\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"Za&dano" },
            { TXT_EXPORT, L"&Izvezi…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Datoteka" },
            { TXT_REPORT_FONT, L"&Font izvješća:" },
            { TXT_HELP_MENU, L"&Pomoć" },
            { TXT_HELP, L"&Pomoć\tF1" },
            { TXT_LANGUAGE, L"&Jezik:" },
            { TXT_OPEN_WEBSITE, L"&Otvori u zadanom pregledniku" },
            { TXT_OPEN, L"&Otvori…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Mogućnosti" },
            { TXT_PREFERENCES_MENU, L"&Postavke…\tCtrl+G" },
            { TXT_ABOUT, L"&O programu" },
            { TXT_ABOUT_TITLE, L"O programu %ls" },
            { TXT_ALL_FILES, L"Sve datoteke" },
            { TXT_FONT_BOLD, L"Podebljano" },
            { TXT_FONT_BOLD_ITALIC, L"Podebljano + Kurziv" },
            { TXT_BROWSE_CURL, L"Pr&egledaj…" },
            { TXT_CANCEL, L"Odustani" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Nije moguće učitati MediaInfo.dll (pogreška sustava Windows %lu). Koristite 32-bitnu DLL "
                L"kompatibilnu s ovom verzijom sustava Windows."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Nije moguće učitati libcurl.dll (pogreška sustava Windows %lu). Odaberite 32-bitnu "
                L"knjižnicu kompatibilnu s ovom verzijom sustava Windows."
            },
            { TXT_CLOSE_ALL, L"Zatvori &sve" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Kopiraj &adresu" },
            { TXT_COPY_INFORMATION, L"Kopiraj &informacije" },
            { TXT_DLL_FILES, L"Dinamičke knjižnice" },
            { TXT_EXIT, L"Iz&laz\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Ugrađene knjižnice MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Ugrađene knjižnice libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Izvezi izvješće" },
            { TXT_FONT_ANTIALIASING, L"Iz&glađivanje fonta:" },
            { TXT_GIF_EXPORT_FAILED, L"Izvoz GIF nije uspio. GIF bez gubitaka zahtijeva najviše 256 boja." },
            { TXT_FONT_ITALIC, L"Kurziv" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED, L"Izvoz JPEG nije uspio. Potreban je ispravan GDI+ JPEG koder." },
            { TXT_LICENSE_UNAVAILABLE, L"Resurs licence nije dostupan." },
            { TXT_MEDIA_FILES, L"Medijske datoteke" },
            { TXT_APPLICATION_DESCRIPTION, L"Preglednik informacija o medijima" },
            { TXT_HELP_TITLE, L"MediaInfo — Pomoć" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo nije mogao inicijalizirati analizu datoteke." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo ne može otvoriti ili prepoznati ovu datoteku." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"&Putanja do MediaInfo.dll:" },
            { TXT_MEDIALIB_REQUIRED, L"MediaInfo.dll nije učitana. Odaberite je u Mogućnosti > Postavke." },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll nije učitana." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Nije moguće učitati kompatibilnu vanjsku ili ugrađenu MediaInfo.dll. Odaberite je u "
                L"Mogućnosti > Postavke."
            },
            { TXT_ANTIALIASING_NONE, L"Nema" },
            { TXT_OK, L"U redu" },
            { TXT_OPEN_TITLE, L"Otvori medijske datoteke" },
            { TXT_PLATFORM, L"Ciljna platforma:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Postavke" },
            { TXT_READY, L"Spreman" },
            { TXT_FONT_REGULAR, L"Obično" },
            { TXT_REPORT_LANGUAGE, L"Jezik &izvješća:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Jezične tablice izvješća" },
            { TXT_SELECT_MEDIALIB, L"Pregledaj: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Pregledaj: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH,
                L"Odaberite postojeću medijsku datoteku s putanjom kraćom od MAX_PATH."
            },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Odaberite postojeće datoteke s putanjama kraćim od MAX_PATH." },
            { TXT_SELECT_CURL, L"Pregledaj: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Tekstni dokument ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"Nije moguće spremiti BMP sliku. Provjerite odredište, slobodnu memoriju i prostor na disku."
            },
            { TXT_LIBRARY_WORKER_START_FAILED,
                L"Nije moguće pokrenuti proces knjižnice (pogreška Windows %lu)."
            },
            { TXT_REPORT_COPY_FAILED, L"Nije moguće kopirati izvješće MediaInfo u memoriju." },
            { TXT_VIEWER_CREATE_FAILED, L"Nije moguće napraviti preglednik MediaInfo." },
            { TXT_MEDIALIB_PATH_INVALID, L"Putanja do MediaInfo.dll nije ispravna ili je preduga." },
            { TXT_PNG_EXPORT_FAILED,
                L"Nije moguće spremiti PNG sliku. Provjerite odredište, slobodnu memoriju i prostor na disku."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"Nije moguće spremiti TIFF sliku. Provjerite odredište, slobodnu memoriju i prostor na "
                L"disku."
            },
            { TXT_COPY_URL_FAILED, L"Nije moguće kopirati URL u međuspremnik." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"Preglednik Win32 zahtijeva 32-bitnu %s. Odaberite knjižnicu x86/i386."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Ugrađenu knjižnicu nije moguće upisati u AppData, korisnički profil, Program Files ili "
                L"privremenu mapu."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED, L"Raspakiravanje knjižnice ili CRC provjera nije uspjela." },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Resurs ugrađene knjižnice nije ispravan." },
            { TXT_CURL_FILENAME_INVALID,
                L"Knjižnica se mora zvati libcurl.dll da bi je MediaInfo mogla koristiti."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Nije moguće otvoriti dijaloški okvir za datoteke." },
            { TXT_FILE_DIALOG_SELECTION_FAILED,
                L"Nije moguće dohvatiti odabrane datoteke iz dijaloškog okvira."
            },
            { TXT_RECENT_FILE_MISSING,
                L"Datoteka „%s“ više ne postoji.\n\nŽelite li ukloniti ovu stavku s popisa nedavnih datoteka?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Datoteka više nije dostupna:\n\n%s\n\nŽelite li ukloniti ovu stavku s popisa nedavnih "
                L"datoteka?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Nije moguće kopirati informacije u međuspremnik." },
            { TXT_CURL_PATH_INVALID, L"Putanja do libcurl.dll nije ispravna ili je preduga." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Knjižnica nije vratila verziju MediaInfo." },
            { TXT_CURL_EXPORTS_MISSING, L"Knjižnica ne izvozi funkcije curl potrebne za MediaInfo." },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"Knjižnica ne izvozi potrebne Unicode funkcije knjižnice MediaInfo."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Proces knjižnice nije uspio tijekom %s (kod 0x%08lX). Odaberite kompatibilnu DLL u "
                L"Mogućnosti > Postavke."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Proces knjižnice ne odgovara tijekom %s. Odaberite kompatibilnu DLL u Mogućnosti > "
                L"Postavke."
            },
            { TXT_PREFERENCES_SAVE_FAILED, L"Postavke su primijenjene, ali nisu spremljene u registru." },
            { TXT_REPORT_START_FAILED, L"Nema dovoljno memorije za pokretanje izvješća." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Nije moguće napraviti sliku izvješća." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Nije moguće učitati jezičnu tablicu. Odaberite ispravan "
                L"MediaInfo CSV u UTF-8 ili UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"Nije moguće pokrenuti nit izvješća." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"Odabrana MediaInfo.dll odbila je jezik izvješća." },
            { TXT_INVALID_WINDOWS_DLL, L"Odabrana datoteka nije ispravna Windows DLL." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Odabrani format slike nije podržan." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Nije moguće spremiti tekstualno izvješće. Provjerite odredište i slobodan prostor na disku."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Nije moguće otvoriti stranicu u zadanom pregledniku." },
            { TXT_TOO_MANY_FILES, L"Odabrano je previše datoteka. Otvarajte manje grupe." },
            { TXT_LIBRARY_PATH_HINT,
                L"Koristite 32-bitne knjižnice kompatibilne s vašom verzijom sustava Windows. Ostavite "
                L"putanje prazne za automatsko pretraživanje. MediaInfoLib v0.7.60 ne koristi libcurl.dll."
            },
            { TXT_VERSION, L"Verzija" },
            { TXT_WEBSITE_TOOLTIP, L"Posjeti web-mjesto %s" },
            { TXT_WAITING_FOR_REPORT, L"Čekanje završetka trenutnog izvješća." },
            { TXT_WEBSITE_LABEL, L"Web-mjesto:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"kopiranja izvješća MediaInfo" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"Putanja do libc&url.dll:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"učitavanja MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"učitavanja libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"oslobađanja MediaInfo.dll" },
            { TXT_APPLY, L"Primije&ni" },
            { TXT_TAB_NAME_LENGTH, L"Duljina naziva &kartice:" },
            { TXT_TITLE_NAME_LENGTH, L"D&uljina naslova:" },
            { TXT_RECENT_FILES, L"Nedavne datoteke:" },
            { TXT_CLEAR_RECENT_FILES, L"&Očisti" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"Duljina naziva kartice mora biti između 8 i 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"Duljina naziva u naslovu mora biti između 8 i 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Popis nedavnih datoteka je očišćen, ali nije spremljen u registru."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"&Zatvaraj kartice dvoklikom" },
            { TXT_CLOSE_TAB_CONTEXT, L"&Zatvori karticu" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"Dopu&sti više instanci" },
            { TXT_INSTANCE_FORWARD_FAILED,
                L"Datoteke nije bilo moguće proslijediti pokrenutoj instanci programa MediaInfo."
            },
            { TXT_LOADING, L"Učitavanje…" },
            { TXT_LOADING_FILE, L"Učitavanje datoteke %s…" },
            { TXT_APPLICATION_HELP,
                L"DATOTEKE I KARTICE\r\nIzvorni Windows x86 preglednik izvješća MediaInfo.dll. Svaka "
                L"datoteka ima vlastitu karticu samo za čitanje. Otvorite pomoću Ctrl+O ili povlačenjem. "
                L"Ponovno otvaranje odabire postojeću karticu. Ctrl+W ili srednja tipka miša zatvara "
                L"karticu; Zatvori sve zatvara sve kartice. Izbornik Datoteka pamti osam nedavnih "
                L"datoteka. Kontekstni izbornik zaglavlja kartice sadrži Zatvori karticu. U Postavkama "
                L"uključite Zatvaraj kartice dvoklikom da biste zatvorili karticu dvoklikom na njezino "
                L"zaglavlje. Mogućnost je početno isključena i njezino se stanje sprema. Dvoklik u tekstu "
                L"izvješća odabire riječ. Trostruki klik odabire logički redak. Povlačenje proširuje "
                L"odabir po riječima ili retcima.\r\nOtvori mapu… otvara datoteke koje se nalaze izravno "
                L"u odabranoj mapi, svaku na zasebnoj kartici. Podmape nisu uključene.\r\nOtvori i Otvori "
                L"mapu dijele posljednju odabranu mapu. Izvoz pamti zasebnu mapu, zadano Dokumenti. "
                L"Napredni način rada prikazuje dodatna polja izvješća.\r\nPoznati formati / Poznati "
                L"kodeci / Poznati parametri — MediaInfo.dll.\r\nPotpuna analiza ispituje cijelu datoteku "
                L"i može trajati duže. Ove opcije izvješća i Razina praćenja pripadaju svakoj kartici; "
                L"promjena osvježava samo aktivnu karticu. Posljednja ručno odabrana kombinacija sprema "
                L"se za nove kartice i sljedeće pokretanje. Podudarno predmemorirano izvješće ponovno se "
                L"koristi dok datoteka ostaje nepromijenjena.\r\nRazina praćenja: 0 / 5 / 9 / 10.\r\n"
                L"Datoteka > Postavljanje stranice… otvara postavke papira, usmjerenja i margina za "
                L"trenutačnu sesiju. Ispis… (Ctrl+P) otvara sistemski dijaloški okvir ispisa; Windows 11 "
                L"pruža pretpregled, dok Windows 10 i stariji zadržavaju klasični dijaloški okvir. Ctrl+P "
                L"ispisuje aktivnu karticu glavnog prozora ili tekstno polje prozora Pomoć ili O "
                L"programu, ovisno o tome koji prozor ima fokus. Izvješća rabe odabrani font izvješća, "
                L"Pomoć sistemski font dijaloških okvira, a O programu font svojeg tekstnog polja. Ako "
                L"nema otvorenih kartica, a Pomoć je otvorena, Postavljanje stranice… i Ispis… ostaju "
                L"dostupni; Ispis… ispisuje pomoć. Pomoć rabi dijaloški okvir ispisa glavnog prozora; "
                L"ponovni Ctrl+P u Pomoći dovodi isti okvir u prvi plan. Dugi se retci prelamaju, a tekst "
                L"dijeli na stranice. Ispis se odvija u pozadini.\r\nPovucite jednu ili više datoteka u "
                L"prozor, na ikonu EXE datoteke ili njezin prečac ili predajte njihove putanje putem "
                L"naredbenog retka. Ako više instanci nije dopušteno, datoteke se otvaraju u već "
                L"pokrenutom prozoru.\r\nLijeva strana trake stanja prikazuje putanje datoteka i tijek "
                L"učitavanja, a desna verziju učitane knjižnice MediaInfo.dll. Duge putanje skraćuju se "
                L"trotočkom prema dostupnom prostoru.\r\n\r\nIZVOZ\r\nTXT, BMP, GIF, JPEG, PNG, TIFF i "
                L"WebP prikazuju se kada su dostupni. Posljednja mapa i oblik izvoza se pamte.\r\nTXT "
                L"nudi ANSI, UTF-8, UTF-8 s BOM-om, UTF-16 BE s BOM-om i UTF-16 LE s BOM-om. Zadana je "
                L"druga stavka, UTF-8 bez BOM-a. Čuvaju se cijeli tekst izvješća i izvorni završeci "
                L"redaka.\r\n\r\nKREIRATI ZAGLAVNU DATOTEKU\r\nIzbornik Alati je četvrti na traci "
                L"izbornika. Njegova naredba Kreirati zaglavnu datoteku… otvara jednu izvornu datoteku "
                L"neovisno o karticama izvješća i kopira njenih prvih 524288 bajtova (512 KiB). Kraća "
                L"datoteka kopira se u cijelosti; prazna datoteka daje prazan izlaz. Ovo je obično "
                L"čitanje binarne datoteke, bez MediaInfo analize ili zahtjeva za MediaInfo.dll. Alat "
                L"ostavlja nepromijenjene kartice izvješća i preglednikov popis nedavnih datoteka.\r\n\r\n"
                L"Nakon čitanja, dijaloški okvir Spremi kao pokreće se u mapi izvorne datoteke i predlaže "
                L"video.mp4.header za video.mp4: .header se dodaje cijelom izvornom nazivu. Možete "
                L"promijeniti i naziv i odredišnu mapu. Otkazivanje bilo kojeg dijaloškog okvira ne "
                L"zapisuje izlaznu datoteku. Zamjena postojećeg odredišta zahtijeva potvrdu. Izvor ostaje "
                L"nepromijenjen; neuspješno spremanje čuva prethodno odredište. Za otvaranje i spremanje "
                L"koriste se najnoviji sistemski dijaloški okviri dostupni u toj verziji sustava "
                L"Windows.\r\n\r\nPrilikom pokretanja aplikacije, alat preuzima početnu ulaznu mapu iz "
                L"Datoteka > Otvori. Ako mapa nije spremljena, Windows odabire početnu lokaciju. Nakon "
                L"odabira ulazne datoteke, alat pamti vlastitu mapu samo dok se aplikacija ne zatvori, "
                L"čak i ako se Spremi kao otkaže. Ne mijenja mape koje koriste Otvori i Izvezi niti "
                L"sprema vlastitu mapu u postavke aplikacije. Svaki dijaloški okvir Spremi kao počinje u "
                L"mapi trenutno odabrane ulazne datoteke, bez obzira na prethodno odredište "
                L"spremanja.\r\n\r\nPOSTAVKE I JEZICI\r\nPostavke (Mogućnosti > Postavke, Ctrl+G) sadrže "
                L"putanje knjižnica, font izvješća, izglađivanje i jezike. Sučelje ima 36 inačica i "
                L"početno prati Windows. Izvješća uvijek zadano koriste izvorni engleski knjižnice, "
                L"neovisno o Windowsu i sučelju. To mijenja samo ručni odabir jezika: engleski, 37 "
                L"prijevoda ili vlastita MediaInfo CSV tablica. U redu ili Primijeni potvrđuje promjene; "
                L"Odustani odbacuje nepotvrđene promjene. Postavke određuju ograničenje naziva kartice "
                L"(zadano 80) i brišu popis nedavnih datoteka. Dugi nazivi zadržavaju početak, kraj i "
                L"nastavak s trotočkom u sredini. Očisti odmah uklanja popis nedavnih datoteka, čak i ako "
                L"zatim zatvorite Postavke tipkom Odustani.\r\n\r\nNaslov glavnog prozora prikazuje aktivnu "
                L"datoteku u obliku naziv datoteke — MediaInfo. U postavkama se duljina naziva u naslovu može"
                L" zasebno postaviti na 8–255 znakova (zadano 40). Dulji nazivi skraćuju se istom trotočkom u"
                L" sredini, uz očuvanje nastavka. Bez otvorenih kartica naslov je MediaInfo.\r\n\r\nKNJIŽNICE"
                L" I PROZORI\r\nProgram sadrži "
                L"MediaInfo 26.10, 21.03 i 0.7.60, koje se isprobavaju od najnovije nakon vanjskih "
                L"knjižnica. Dvije novije inačice imaju odgovarajući libcurl; 0.7.60 ga nikada ne "
                L"raspakirava. Položaj prozora se sprema. Prema zadanim postavkama dopuštena je samo "
                L"jedna instanca, a sljedeća pokretanja šalju datoteke otvorenom prozoru. U postavkama se "
                L"može dopustiti više instanci. Kada postoji više prozora, samo prvi prozor svakog tipa "
                L"prozora vraća spremljeni položaj; ostali vraćaju samo veličinu.\r\n\r\nUređivanje > "
                L"Pronađi (Ctrl+F) pretražuje aktivnu karticu izvješća ili tekstno polje prozora Pomoć "
                L"ili O programu, ovisno o tome koji prozor ima fokus. Prozor pretraživanja zadržava "
                L"posljednji odabrani izvor dok ima fokus. F3 ponavlja pretraživanje, a Shift+F3 mijenja "
                L"njegov smjer. Na kraju teksta pretraživanje se nastavlja s drugog kraja. Mogućnosti > "
                L"Prelamanje redaka vrijedi samo za aktivnu karticu; oznaka prati odabranu karticu. "
                L"Prozor pretraživanja može se minimizirati i mijenjati mu se širina; položaj i mogućnost "
                L"Uvijek na vrhu pamte se. Do 30 tekstova pretraživanja s njihovim mogućnostima čuva se "
                L"samo do zatvaranja aplikacije. Mogućnosti početka i kraja odnose se na logičke retke. "
                L"Regularni izrazi koriste sintaksu PCRE2. Ostale naredbe izbornika Uređivanje odnose se "
                L"na aktivnu karticu izvješća. Enter pokreće pretraživanje, a Shift+Enter obrće odabrani "
                L"smjer. „Razlikuj velika i mala slova“ razlikuje velika i mala slova; „Traži unatrag“ "
                L"pretražuje prema početku teksta. Odabir stavke povijesti vraća svih pet mogućnosti "
                L"pretraživanja, uključujući postavku regularnih izraza; „Uvijek na vrhu“ neovisna je "
                L"mogućnost. „Regularni izraz“ onemogućuje „Redak počinje s“ i „Redak završava s“. Kada "
                L"su uključene obje mogućnosti krajeva retka, dovoljno je podudaranje na jednom kraju. "
                L"„Prelamanje redaka“ mijenja samo prikaz."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"Nije moguće spremiti WebP sliku. Provjerite odredište, slobodnu memoriju i prostor na "
                L"disku."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Tekstni dokument UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Tekstni dokument UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Tekstni dokument UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Tekstni dokument UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Izvješće se ne može spremiti u ovom kodiranju bez gubitka znakova. Odaberite drugo "
                L"kodiranje teksta."
            },
            { TXT_OPEN_FOLDER, L"Otvori &mapu…" },
            { TXT_OPEN_FOLDER_TITLE, L"Otvori mapu" },
            { TXT_FOLDER_READ_FAILED, L"Mapu nije moguće pročitati:\n\n%s\n\nPogreška sustava Windows %lu." },
            { TXT_ADVANCED_MODE, L"&Napredni način rada" },
            { TXT_REPORT_DETAIL_REJECTED, L"Odabrana MediaInfo.dll odbila je postavku detalja izvješća." },
            { TXT_KNOWN_FORMATS, L"Poznati &formati" },
            { TXT_KNOWN_CODECS, L"Poznati &kodeci" },
            { TXT_KNOWN_PARAMETERS, L"Poznati p&arametri" },
            { TXT_KNOWN_FORMATS_TITLE, L"Poznati formati" },
            { TXT_KNOWN_CODECS_TITLE, L"Poznati kodeci" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Poznati parametri" },
            { TXT_KNOWN_INFO_FAILED, L"Knjižnica nije vratila tražene informacije." },
            { TXT_FULL_PARSING, L"Potpuna &analiza" },
            { TXT_PARSING_REJECTED, L"Odabrana MediaInfo.dll odbila je postavku analize." },
            { TXT_TRACE_LEVEL_0, L"Razina praćenja &0" },
            { TXT_TRACE_LEVEL_5, L"Razina praćenja &5" },
            { TXT_TRACE_LEVEL_9, L"Razina praćenja &9" },
            { TXT_TRACE_LEVEL_10, L"Razina praćenja &10" },
            { TXT_PAGE_SETUP, L"Pos&tavljanje stranice…" },
            { TXT_PAGE_SETUP_FAILED, L"Nije moguće otvoriti postavljanje stranice." },
            { TXT_PRINT, L"Is&pis…\tCtrl+P" },
            { TXT_PRINTING, L"Ispis…" },
            { TXT_PRINT_FAILED,
                L"Tekst nije moguće ispisati. Provjerite pisač, njegove postavke i dostupnu memoriju."
            },
            { TXT_TOOLS_MENU, L"&Alati" },
            { TXT_CREATE_HEADER, L"Kreirati &zaglavnu datoteku…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Kreirati zaglavnu datoteku - Otvori" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Kreirati zaglavnu datoteku - Spremi kao" },
            { TXT_HEADER_FORMAT, L"Datoteka zaglavlja (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Nije moguće pročitati zaglavlje datoteke:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Nije moguće spremiti datoteku zaglavlja:\n\n%s" },
            { TXT_COPY, L"&Kopiraj" },
            { TXT_COPY_FILE_NAME, L"Kopiraj &naziv datoteke" },
            { TXT_COPY_FULL_PATH, L"Kopiraj punu p&utanju" },
            { TXT_LAUNCH_FILE, L"Po&kreni datoteku" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"P&rikaži u mapi" },
            { TXT_EDIT_MENU, L"&Uređivanje" },
            { TXT_WORD_WRAP, L"P&relamanje redaka" },
            { TXT_WORD_WRAP_FAILED, L"Prelamanje redaka nije moguće promijeniti." },
            { TXT_COPY_SELECTION, L"&Kopiraj\tCtrl+C" },
            { TXT_SELECT_ALL, L"Odaberi &sve\tCtrl+A" },
            { TXT_FIND_MENU, L"&Pronađi…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Pronađi s&ljedeće\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Pronađi preth&odno\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Pronađi" },
            { TXT_FIND_WHAT, L"&Traži:" },
            { TXT_FIND_NEXT, L"Pronađi s&ljedeće" },
            { TXT_FIND_MATCH_CASE, L"Razlikuj velika i &mala slova" },
            { TXT_FIND_BACKWARD, L"Traži &unatrag" },
            { TXT_FIND_TOPMOST, L"Uvijek na &vrhu" },
            { TXT_FIND_STARTS_WITH, L"Redak počinje &s" },
            { TXT_FIND_ENDS_WITH, L"Redak završav&a s" },
            { TXT_FIND_REGEX, L"&Regularni izraz" },
            { TXT_FIND_NOT_FOUND, L"Navedeni tekst nije pronađen." },
            { TXT_FIND_FAILED, L"Pretraživanje nije moguće dovršiti." },
            { TXT_FIND_REGEX_ERROR, L"Pogreška u regularnom izrazu:\r\n\r\n%s" },
        }
    },
    {
        LANG_SL,
        {
            { TXT_LANGUAGE_NAME, L"Slovenščina" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nSpletno mesto: " },
            { TXT_FILE_OPEN_FAILED, L"Datoteke %s ni mogoče odpreti. Preverite pot in dovoljenja." },
            { TXT_BROWSE_DLL, L"Pre&brskaj…" },
            { TXT_BROWSE_REPORT, L"Prebr&skaj…" },
            { TXT_CLOSE, L"&Zapri" },
            { TXT_CLOSE_TAB, L"&Zapri\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"Pri&vzeto" },
            { TXT_EXPORT, L"&Izvozi…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Datoteka" },
            { TXT_REPORT_FONT, L"P&isava poročila:" },
            { TXT_HELP_MENU, L"&Pomoč" },
            { TXT_HELP, L"&Pomoč\tF1" },
            { TXT_LANGUAGE, L"&Jezik:" },
            { TXT_OPEN_WEBSITE, L"&Odpri v privzetem brskalniku" },
            { TXT_OPEN, L"&Odpri…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Možnosti" },
            { TXT_PREFERENCES_MENU, L"&Nastavitve…\tCtrl+G" },
            { TXT_ABOUT, L"&O programu" },
            { TXT_ABOUT_TITLE, L"O programu %ls" },
            { TXT_ALL_FILES, L"Vse datoteke" },
            { TXT_FONT_BOLD, L"Krepko" },
            { TXT_FONT_BOLD_ITALIC, L"Krepko + Ležeče" },
            { TXT_BROWSE_CURL, L"P&rebrskaj…" },
            { TXT_CANCEL, L"Prekliči" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"MediaInfo.dll ni mogoče naložiti (napaka Windows %lu). Uporabite 32-bitno DLL, združljivo "
                L"s to različico sistema Windows."
            },
            { TXT_CURL_LOAD_FAILED,
                L"libcurl.dll ni mogoče naložiti (napaka Windows %lu). Izberite 32-bitno knjižnico, "
                L"združljivo s to različico sistema Windows."
            },
            { TXT_CLOSE_ALL, L"Zapri &vse" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Kopiraj &naslov" },
            { TXT_COPY_INFORMATION, L"Kopiraj &podatke" },
            { TXT_DLL_FILES, L"Dinamične knjižnice" },
            { TXT_EXIT, L"Iz&hod\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Vgrajene knjižnice MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Vgrajene knjižnice libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Izvozi poročilo" },
            { TXT_FONT_ANTIALIASING, L"&Glajenje pisave:" },
            { TXT_GIF_EXPORT_FAILED, L"Izvoz GIF ni uspel. GIF brez izgub zahteva največ 256 barv." },
            { TXT_FONT_ITALIC, L"Ležeče" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED, L"Izvoz JPEG ni uspel. Potreben je delujoč kodirnik JPEG GDI+." },
            { TXT_LICENSE_UNAVAILABLE, L"Licenčni vir ni na voljo." },
            { TXT_MEDIA_FILES, L"Predstavnostne datoteke" },
            { TXT_APPLICATION_DESCRIPTION, L"Pregledovalnik informacij o predstavnosti" },
            { TXT_HELP_TITLE, L"MediaInfo — Pomoč" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo ni mogel inicializirati analize datoteke." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo ne more odpreti ali prepoznati te datoteke." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"&Pot do MediaInfo.dll:" },
            { TXT_MEDIALIB_REQUIRED, L"MediaInfo.dll ni naložena. Izberite jo v Možnosti > Nastavitve." },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll ni naložena." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Združljive zunanje ali vgrajene MediaInfo.dll ni mogoče naložiti. Izberite jo v Možnosti "
                L"> Nastavitve."
            },
            { TXT_ANTIALIASING_NONE, L"Brez" },
            { TXT_OK, L"V redu" },
            { TXT_OPEN_TITLE, L"Odpri predstavnostne datoteke" },
            { TXT_PLATFORM, L"Ciljna platforma:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Nastavitve" },
            { TXT_READY, L"Pripravljen" },
            { TXT_FONT_REGULAR, L"Navadno" },
            { TXT_REPORT_LANGUAGE, L"Jezik p&oročila:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Jezikovne tabele poročil" },
            { TXT_SELECT_MEDIALIB, L"Prebrskaj: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Prebrskaj: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH,
                L"Izberite obstoječo predstavnostno datoteko s potjo, krajšo od MAX_PATH."
            },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Izberite obstoječe datoteke s potmi, krajšimi od MAX_PATH." },
            { TXT_SELECT_CURL, L"Prebrskaj: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Besedilni dokument ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"Slike BMP ni mogoče shraniti. Preverite cilj, prosti pomnilnik in prostor na disku."
            },
            { TXT_LIBRARY_WORKER_START_FAILED, L"Procesa knjižnice ni mogoče zagnati (napaka Windows %lu)." },
            { TXT_REPORT_COPY_FAILED, L"Poročila MediaInfo ni mogoče kopirati v pomnilnik." },
            { TXT_VIEWER_CREATE_FAILED, L"Pregledovalnika MediaInfo ni mogoče ustvariti." },
            { TXT_MEDIALIB_PATH_INVALID, L"Pot do MediaInfo.dll je neveljavna ali predolga." },
            { TXT_PNG_EXPORT_FAILED,
                L"Slike PNG ni mogoče shraniti. Preverite cilj, prosti pomnilnik in prostor na disku."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"Slike TIFF ni mogoče shraniti. Preverite cilj, prosti pomnilnik in prostor na disku."
            },
            { TXT_COPY_URL_FAILED, L"URL-ja ni bilo mogoče kopirati v odložišče." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"Pregledovalnik Win32 zahteva 32-bitno %s. Izberite knjižnico x86/i386."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Vgrajene knjižnice ni mogoče zapisati v AppData, uporabniški profil, Program Files ali "
                L"začasno mapo."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED, L"Razširjanje knjižnice ali preverjanje CRC ni uspelo." },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Vir vgrajene knjižnice je neveljaven." },
            { TXT_CURL_FILENAME_INVALID,
                L"Knjižnica se mora imenovati libcurl.dll, da jo MediaInfo lahko uporablja."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Pogovornega okna za datoteke ni bilo mogoče odpreti." },
            { TXT_FILE_DIALOG_SELECTION_FAILED,
                L"Izbranih datotek ni bilo mogoče pridobiti iz pogovornega okna."
            },
            { TXT_RECENT_FILE_MISSING,
                L"Datoteka »%s« ne obstaja več.\n\nAli želite odstraniti ta vnos s seznama nedavnih datotek?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Datoteka ni več na voljo:\n\n%s\n\nAli želite odstraniti ta vnos s seznama nedavnih "
                L"datotek?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Podatkov ni bilo mogoče kopirati v odložišče." },
            { TXT_CURL_PATH_INVALID, L"Pot do libcurl.dll je neveljavna ali predolga." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Knjižnica ni vrnila različice MediaInfo." },
            { TXT_CURL_EXPORTS_MISSING, L"Knjižnica ne izvaža funkcij curl, ki jih potrebuje MediaInfo." },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"Knjižnica ne izvaža zahtevanih funkcij Unicode knjižnice MediaInfo."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Proces knjižnice je odpovedal med %s (koda 0x%08lX). Izberite združljivo DLL v Možnosti > "
                L"Nastavitve."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Proces knjižnice se ne odziva med %s. Izberite združljivo DLL v Možnosti > Nastavitve."
            },
            { TXT_PREFERENCES_SAVE_FAILED, L"Nastavitve so uveljavljene, vendar niso shranjene v register." },
            { TXT_REPORT_START_FAILED, L"Za zagon poročila ni dovolj pomnilnika." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Slike poročila ni mogoče ustvariti." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Jezikovne tabele ni mogoče naložiti. Izberite veljavno "
                L"datoteko MediaInfo CSV v UTF-8 ali UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"Niti poročila ni mogoče zagnati." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"Izbrana MediaInfo.dll je zavrnila jezik poročila." },
            { TXT_INVALID_WINDOWS_DLL, L"Izbrana datoteka ni veljavna Windows DLL." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Izbrana oblika slike ni podprta." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Besedilnega poročila ni mogoče shraniti. Preverite cilj in prosti prostor na disku."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Spletnega mesta ni mogoče odpreti v privzetem brskalniku." },
            { TXT_TOO_MANY_FILES, L"Izbranih je preveč datotek. Odpirajte manjše skupine." },
            { TXT_LIBRARY_PATH_HINT,
                L"Uporabite 32-bitne knjižnice, združljive z vašo različico sistema Windows. Poti pustite "
                L"prazne za samodejno iskanje. MediaInfoLib v0.7.60 ne uporablja libcurl.dll."
            },
            { TXT_VERSION, L"Različica" },
            { TXT_WEBSITE_TOOLTIP, L"Obišči spletno mesto %s" },
            { TXT_WAITING_FOR_REPORT, L"Čakanje na dokončanje trenutnega poročila." },
            { TXT_WEBSITE_LABEL, L"Spletno mesto:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"kopiranjem poročila MediaInfo" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"Pot do libc&url.dll:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"nalaganjem MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"nalaganjem libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"sproščanjem MediaInfo.dll" },
            { TXT_APPLY, L"Upor&abi" },
            { TXT_TAB_NAME_LENGTH, L"&Dolžina imena zavihka:" },
            { TXT_TITLE_NAME_LENGTH, L"Dolži&na naslova:" },
            { TXT_RECENT_FILES, L"Nedavne datoteke:" },
            { TXT_CLEAR_RECENT_FILES, L"Po&čisti" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"Dolžina imena zavihka mora biti med 8 in 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"Dolžina imena v naslovu mora biti med 8 in 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Seznam nedavnih datotek je bil počiščen, vendar ga ni bilo mogoče shraniti v register."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"&Zapri zavihke z dvoklikom" },
            { TXT_CLOSE_TAB_CONTEXT, L"Zapri &zavihek" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"Dovo&li več primerkov" },
            { TXT_INSTANCE_FORWARD_FAILED,
                L"Datotek ni bilo mogoče posredovati zagnanemu primerku programa MediaInfo."
            },
            { TXT_LOADING, L"Nalaganje…" },
            { TXT_LOADING_FILE, L"Nalaganje datoteke %s…" },
            { TXT_APPLICATION_HELP,
                L"DATOTEKE IN ZAVIHKI\r\nIzvorni pregledovalnik Windows x86 za poročila MediaInfo.dll. "
                L"Vsaka datoteka ima svoj zavihek samo za branje. Odprite s Ctrl+O ali povlecite datoteke "
                L"v okno. Ponovno odpiranje izbere obstoječi zavihek. Ctrl+W ali srednji gumb miške zapre "
                L"zavihek; Zapri vse zapre vse zavihke. Meni Datoteka si zapomni osem nedavnih datotek. "
                L"Priročni meni glave zavihka vsebuje Zapri zavihek. V Nastavitvah omogočite Zapri "
                L"zavihke z dvoklikom, da zavihek zaprete z dvoklikom na njegovo glavo. Možnost je "
                L"privzeto izklopljena in se shrani. Dvoklik v besedilu poročila izbere besedo. Trojni "
                L"klik izbere logično vrstico. Vlečenje razširi izbor po besedah ali vrsticah.\r\nOdpri "
                L"mapo… odpre datoteke neposredno v izbrani mapi, vsako na svojem zavihku. Podmape niso "
                L"vključene.\r\nOdpri in Odpri mapo si delita nazadnje izbrano mapo. Izvoz si zapomni "
                L"ločeno mapo, privzeto Dokumenti. Napredni način prikaže dodatna polja poročila.\r\n"
                L"Znani formati / Znani kodeki / Znani parametri — MediaInfo.dll.\r\nPopolna analiza "
                L"pregleda celotno datoteko in lahko traja dlje. Te možnosti poročila in Raven sledenja "
                L"pripadajo vsakemu zavihku; sprememba osveži samo aktivni zavihek. Zadnja ročno izbrana "
                L"kombinacija se shrani za nove zavihke in naslednji zagon. Ujemajoče se predpomnjeno "
                L"poročilo se ponovno uporabi, dokler datoteka ostane nespremenjena.\r\nRaven sledenja: 0 "
                L"/ 5 / 9 / 10.\r\nDatoteka > Priprava strani… odpre nastavitve papirja, usmerjenosti in "
                L"robov za trenutno sejo. Natisni… (Ctrl+P) odpre sistemsko pogovorno okno za tiskanje; "
                L"Windows 11 ponuja predogled, Windows 10 in starejši pa ohranijo klasično okno. Ctrl+P "
                L"natisne aktivni zavihek glavnega okna ali besedilno polje okna Pomoč ali O programu, "
                L"odvisno od tega, katero okno ima fokus. Poročila uporabljajo izbrano pisavo poročila, "
                L"Pomoč sistemsko pisavo pogovornih oken, O programu pa pisavo svojega besedilnega polja. "
                L"Če ni odprtih zavihkov, Pomoč pa je odprta, Priprava strani… in Natisni… ostaneta na "
                L"voljo; Natisni… natisne pomoč. Pomoč uporablja pogovorno okno za tiskanje glavnega "
                L"okna; ponovni Ctrl+P v Pomoči postavi isto okno v ospredje. Dolge vrstice se prelomijo, "
                L"besedilo pa razdeli na strani. Tiskanje poteka v ozadju.\r\nPovlecite eno ali več "
                L"datotek v okno, na ikono EXE ali njeno bližnjico ali pa podajte njihove poti v ukazni "
                L"vrstici. Če več primerkov ni dovoljenih, se datoteke odprejo v že delujočem oknu.\r\n"
                L"Levi del vrstice stanja prikazuje poti datotek in potek nalaganja, desni pa različico "
                L"naložene knjižnice MediaInfo.dll. Dolge poti se skrajšajo s tropičjem glede na "
                L"razpoložljivi prostor.\r\n\r\nIZVOZ\r\nTXT, BMP, GIF, JPEG, PNG, TIFF in WebP se "
                L"prikažejo, ko so na voljo. Zadnja izvozna mapa in oblika se shranita.\r\nTXT ponuja "
                L"ANSI, UTF-8, UTF-8 z BOM, UTF-16 BE z BOM in UTF-16 LE z BOM. Privzeta je druga "
                L"možnost, UTF-8 brez BOM. Ohranijo se celotno besedilo poročila in izvirni konci "
                L"vrstic.\r\n\r\nUSTVARI DATOTEKO GLAVE\r\nMeni Orodja je četrti v menijski vrstici. "
                L"Njegov ukaz Ustvari datoteko glave… odpre eno izvorno datoteko neodvisno od zavihkov "
                L"poročila in kopira njenih prvih 524288 bajtov (512 KiB). Krajša datoteka se kopira v "
                L"celoti; prazna datoteka ustvari prazen rezultat. To je običajno branje binarne "
                L"datoteke, brez analize MediaInfo ali zahteve za MediaInfo.dll. Orodje pusti "
                L"nespremenjene zavihke poročila in pregledovalnikov seznam nedavnih datotek.\r\n\r\nPo "
                L"branju se v mapi izvorne datoteke odpre pogovorno okno Shrani kot in predlaga "
                L"video.mp4.header za video.mp4: .header se doda celotnemu izvirnemu imenu. Spremenite "
                L"lahko ime in ciljno mapo. Preklic katerega koli pogovornega okna ne zapiše nobenega "
                L"rezultata. Zamenjava obstoječe destinacije zahteva potrditev. Vir ostane nespremenjen; "
                L"neuspelo shranjevanje ohrani prejšnji cilj. Odpiranje in shranjevanje uporabljata "
                L"najnovejša sistemska pogovorna okna, ki so na voljo v tej različici sistema "
                L"Windows.\r\n\r\nOb zagonu aplikacije orodje vzame prvotno vnosno mapo iz Datoteka > "
                L"Odpri. Če ni shranjena nobena mapa, Windows izbere začetno lokacijo. Ko je vhodna "
                L"datoteka izbrana, si orodje zapomni lastno mapo samo, dokler se aplikacija ne zapre, "
                L"tudi če je možnost Shrani kot preklicana. Ne spremeni niti map, ki jih uporabljata "
                L"Odpri in Izvozi, niti ne shrani lastne mape v nastavitve aplikacije. Vsako pogovorno "
                L"okno Shrani kot se začne v mapi trenutno izbrane vhodne datoteke, ne glede na prejšnji "
                L"cilj shranjevanja.\r\n\r\nNASTAVITVE IN JEZIKI\r\nNastavitve (Možnosti > Nastavitve, "
                L"Ctrl+G) vsebujejo poti knjižnic, pisavo poročila, glajenje in jezike. Vmesnik ima 36 "
                L"različic in sprva sledi Windowsu. Poročila vedno privzeto uporabljajo izvirno "
                L"angleščino knjižnice, neodvisno od Windowsa in vmesnika. To spremeni samo ročna izbira "
                L"jezika: angleščina, 37 prevodov ali lastna tabela MediaInfo CSV. V redu ali Uporabi "
                L"potrdi spremembe; Prekliči zavrže čakajoče spremembe. Nastavitve določijo omejitev "
                L"imena zavihka (privzeto 80) in počistijo seznam nedavnih datotek. Dolga imena ohranijo "
                L"začetek, konec in pripono s tropičjem na sredini. Počisti takoj odstrani seznam "
                L"nedavnih datotek, tudi če nastavitve nato zaprete s Prekliči.\r\n\r\nNaslov glavnega okna "
                L"prikazuje dejavno datoteko v obliki ime datoteke — MediaInfo. V nastavitvah lahko dolžino "
                L"imena v naslovu ločeno nastavite na 8–255 znakov (privzeto 40). Daljša imena se skrajšajo z"
                L" istim tropičjem na sredini, končnica pa se ohrani. Brez odprtih zavihkov je naslov "
                L"MediaInfo.\r\n\r\nKNJIŽNICE IN "
                L"OKNA\r\nProgram vsebuje MediaInfo 26.10, 21.03 in 0.7.60, ki jih po zunanjih knjižnicah "
                L"preizkuša od najnovejše. Novejši različici imata ustrezni libcurl; 0.7.60 ga nikoli ne "
                L"razširi. Položaj okna se shrani. Privzeto je dovoljen samo en primerek, poznejši zagoni "
                L"pa pošljejo datoteke odprtemu oknu. V nastavitvah lahko dovolite več primerkov. Pri več "
                L"oknih le prvo okno vsake vrste okna obnovi shranjeni položaj; poznejša okna obnovijo "
                L"samo velikost.\r\n\r\nUredi > Najdi (Ctrl+F) išče po aktivnem zavihku poročila ali "
                L"besedilnem polju okna Pomoč ali O programu, odvisno od tega, katero okno ima fokus. "
                L"Iskalno okno ohrani nazadnje izbrani vir, dokler ima fokus. F3 ponovi iskanje, Shift+F3 "
                L"pa obrne njegovo smer. Na koncu besedila se iskanje nadaljuje z drugega konca. Možnosti "
                L"> Prelom vrstic velja le za aktivni zavihek; kljukica sledi izbranemu zavihku. Iskalno "
                L"okno je mogoče minimizirati in mu spreminjati širino; položaj in možnost Vedno na vrhu "
                L"se shranita. Do 30 iskalnih besedil z možnostmi se hrani le do zaprtja programa. "
                L"Možnosti začetka in konca veljata za logične vrstice. Regularni izrazi uporabljajo "
                L"sintakso PCRE2. Drugi ukazi menija Uredi veljajo za aktivni zavihek poročila. Enter "
                L"začne iskanje, Shift+Enter pa obrne izbrano smer. »Razlikuj velike in male črke« "
                L"razlikuje velike in male črke; »Išči nazaj« išče proti začetku besedila. Izbira vnosa "
                L"iz zgodovine obnovi vseh pet možnosti iskanja, vključno s stanjem regularnih izrazov; "
                L"»Vedno na vrhu« je neodvisna možnost. »Regularni izraz« onemogoči »Vrstica se začne z« "
                L"in »Vrstica se konča z«. Če sta vključeni obe možnosti robov vrstice, zadostuje "
                L"ujemanje na enem robu. »Prelom vrstic« spremeni samo prikaz."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"Slike WebP ni mogoče shraniti. Preverite cilj, prosti pomnilnik in prostor na disku."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Besedilni dokument UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Besedilni dokument UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Besedilni dokument UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Besedilni dokument UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Poročila ni mogoče shraniti s tem kodiranjem brez izgube znakov. Izberite drugo kodiranje "
                L"besedila."
            },
            { TXT_OPEN_FOLDER, L"Odpri &mapo…" },
            { TXT_OPEN_FOLDER_TITLE, L"Odpri mapo" },
            { TXT_FOLDER_READ_FAILED, L"Mape ni mogoče prebrati:\n\n%s\n\nNapaka sistema Windows %lu." },
            { TXT_ADVANCED_MODE, L"N&apredni način" },
            { TXT_REPORT_DETAIL_REJECTED,
                L"Izbrana MediaInfo.dll je zavrnila nastavitev podrobnosti poročila."
            },
            { TXT_KNOWN_FORMATS, L"Znani &formati" },
            { TXT_KNOWN_CODECS, L"Znani &kodeki" },
            { TXT_KNOWN_PARAMETERS, L"Znani p&arametri" },
            { TXT_KNOWN_FORMATS_TITLE, L"Znani formati" },
            { TXT_KNOWN_CODECS_TITLE, L"Znani kodeki" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Znani parametri" },
            { TXT_KNOWN_INFO_FAILED, L"Knjižnica ni vrnila zahtevanih informacij." },
            { TXT_FULL_PARSING, L"&Popolna analiza" },
            { TXT_PARSING_REJECTED, L"Izbrana MediaInfo.dll je zavrnila nastavitev analize." },
            { TXT_TRACE_LEVEL_0, L"Raven sledenja &0" },
            { TXT_TRACE_LEVEL_5, L"Raven sledenja &5" },
            { TXT_TRACE_LEVEL_9, L"Raven sledenja &9" },
            { TXT_TRACE_LEVEL_10, L"Raven sledenja &10" },
            { TXT_PAGE_SETUP, L"Priprava &strani…" },
            { TXT_PAGE_SETUP_FAILED, L"Priprave strani ni bilo mogoče odpreti." },
            { TXT_PRINT, L"Na&tisni…\tCtrl+P" },
            { TXT_PRINTING, L"Tiskanje…" },
            { TXT_PRINT_FAILED,
                L"Besedila ni bilo mogoče natisniti. Preverite tiskalnik, njegove nastavitve in "
                L"razpoložljivi pomnilnik."
            },
            { TXT_TOOLS_MENU, L"&Orodja" },
            { TXT_CREATE_HEADER, L"Ustvari datoteko &glave…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Ustvari datoteko glave - Odpri" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Ustvari datoteko glave - Shrani kot" },
            { TXT_HEADER_FORMAT, L"Datoteka glave (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Glave datoteke ni bilo mogoče prebrati:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Datoteke glave ni bilo mogoče shraniti:\n\n%s" },
            { TXT_COPY, L"&Kopiraj" },
            { TXT_COPY_FILE_NAME, L"Kopiraj &ime datoteke" },
            { TXT_COPY_FULL_PATH, L"Kopiraj celotno p&ot" },
            { TXT_LAUNCH_FILE, L"Z&aženi datoteko" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"P&rikaži v mapi" },
            { TXT_EDIT_MENU, L"&Uredi" },
            { TXT_WORD_WRAP, L"P&relom vrstic" },
            { TXT_WORD_WRAP_FAILED, L"Preloma vrstic ni bilo mogoče spremeniti." },
            { TXT_COPY_SELECTION, L"&Kopiraj\tCtrl+C" },
            { TXT_SELECT_ALL, L"Izberi &vse\tCtrl+A" },
            { TXT_FIND_MENU, L"&Najdi…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Najdi na&slednje\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Najdi &prejšnje\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Najdi" },
            { TXT_FIND_WHAT, L"&Išči:" },
            { TXT_FIND_NEXT, L"Najdi na&slednje" },
            { TXT_FIND_MATCH_CASE, L"Razlikuj velike in &male črke" },
            { TXT_FIND_BACKWARD, L"Išči n&azaj" },
            { TXT_FIND_TOPMOST, L"Vedno na &vrhu" },
            { TXT_FIND_STARTS_WITH, L"Vrstica se za&čne z" },
            { TXT_FIND_ENDS_WITH, L"Vrstica se &konča z" },
            { TXT_FIND_REGEX, L"&Regularni izraz" },
            { TXT_FIND_NOT_FOUND, L"Navedenega besedila ni bilo mogoče najti." },
            { TXT_FIND_FAILED, L"Iskanja ni bilo mogoče dokončati." },
            { TXT_FIND_REGEX_ERROR, L"Napaka v regularnem izrazu:\r\n\r\n%s" },
        }
    },
    {
        LANG_CNR,
        {
            { TXT_LANGUAGE_NAME, L"Crnogorski" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nVeb-sajt: " },
            { TXT_FILE_OPEN_FAILED, L"Nije moguće otvoriti %s. Provjerite putanju i dozvole." },
            { TXT_BROWSE_DLL, L"P&regledaj…" },
            { TXT_BROWSE_REPORT, L"Preg&ledaj…" },
            { TXT_CLOSE, L"&Zatvori" },
            { TXT_CLOSE_TAB, L"&Zatvori\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"Po&drazumijevano" },
            { TXT_EXPORT, L"&Izvezi…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Datoteka" },
            { TXT_REPORT_FONT, L"&Font izvještaja:" },
            { TXT_HELP_MENU, L"&Pomoć" },
            { TXT_HELP, L"&Pomoć\tF1" },
            { TXT_LANGUAGE, L"&Jezik:" },
            { TXT_OPEN_WEBSITE, L"&Otvori u podrazumijevanom pregledaču" },
            { TXT_OPEN, L"&Otvori…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Opcije" },
            { TXT_PREFERENCES_MENU, L"&Podešavanja…\tCtrl+G" },
            { TXT_ABOUT, L"&O programu" },
            { TXT_ABOUT_TITLE, L"O programu %ls" },
            { TXT_ALL_FILES, L"Sve datoteke" },
            { TXT_FONT_BOLD, L"Podebljano" },
            { TXT_FONT_BOLD_ITALIC, L"Podebljano + Kurziv" },
            { TXT_BROWSE_CURL, L"Pr&egledaj…" },
            { TXT_CANCEL, L"Otkaži" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Nije moguće učitati MediaInfo.dll (greška sistema Windows %lu). Koristite 32-bitnu DLL "
                L"kompatibilnu s ovom verzijom sistema Windows."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Nije moguće učitati libcurl.dll (greška sistema Windows %lu). Izaberite 32-bitnu "
                L"biblioteku kompatibilnu s ovom verzijom sistema Windows."
            },
            { TXT_CLOSE_ALL, L"Zatvori &sve" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Kopiraj &adresu" },
            { TXT_COPY_INFORMATION, L"Kopiraj &podatke" },
            { TXT_DLL_FILES, L"Dinamičke biblioteke" },
            { TXT_EXIT, L"Iz&laz\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Ugrađene biblioteke MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Ugrađene biblioteke libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Izvezi izvještaj" },
            { TXT_FONT_ANTIALIASING, L"U&mekšavanje fonta:" },
            { TXT_GIF_EXPORT_FAILED, L"Izvoz GIF nije uspio. GIF bez gubitaka zahtijeva najviše 256 boja." },
            { TXT_FONT_ITALIC, L"Kurziv" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED, L"Izvoz JPEG nije uspio. Potreban je ispravan GDI+ JPEG koder." },
            { TXT_LICENSE_UNAVAILABLE, L"Resurs licence nije dostupan." },
            { TXT_MEDIA_FILES, L"Medijske datoteke" },
            { TXT_APPLICATION_DESCRIPTION, L"Pregledač informacija o medijima" },
            { TXT_HELP_TITLE, L"MediaInfo — Pomoć" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo nije mogao inicijalizovati analizu datoteke." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo ne može otvoriti ili prepoznati ovu datoteku." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"&Putanja do MediaInfo.dll:" },
            { TXT_MEDIALIB_REQUIRED, L"MediaInfo.dll nije učitana. Izaberite je u Opcije > Podešavanja." },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll nije učitana." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Nije moguće učitati kompatibilnu spoljašnju ili ugrađenu MediaInfo.dll. Izaberite je u "
                L"Opcije > Podešavanja."
            },
            { TXT_ANTIALIASING_NONE, L"Nema" },
            { TXT_OK, L"U redu" },
            { TXT_OPEN_TITLE, L"Otvori medijske datoteke" },
            { TXT_PLATFORM, L"Ciljna platforma:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Podešavanja" },
            { TXT_READY, L"Spreman" },
            { TXT_FONT_REGULAR, L"Obično" },
            { TXT_REPORT_LANGUAGE, L"Jezik &izvještaja:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Jezičke tabele izvještaja" },
            { TXT_SELECT_MEDIALIB, L"Pregledaj: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Pregledaj: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH,
                L"Izaberite postojeću medijsku datoteku s putanjom kraćom od MAX_PATH."
            },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Izaberite postojeće datoteke s putanjama kraćim od MAX_PATH." },
            { TXT_SELECT_CURL, L"Pregledaj: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Tekstualni dokument ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"Nije moguće sačuvati BMP sliku. Provjerite odredište, slobodnu memoriju i prostor na disku."
            },
            { TXT_LIBRARY_WORKER_START_FAILED,
                L"Nije moguće pokrenuti proces biblioteke (greška Windows %lu)."
            },
            { TXT_REPORT_COPY_FAILED, L"Nije moguće kopirati izvještaj MediaInfo u memoriju." },
            { TXT_VIEWER_CREATE_FAILED, L"Nije moguće napraviti pregledač MediaInfo." },
            { TXT_MEDIALIB_PATH_INVALID, L"Putanja do MediaInfo.dll nije ispravna ili je preduga." },
            { TXT_PNG_EXPORT_FAILED,
                L"Nije moguće sačuvati PNG sliku. Provjerite odredište, slobodnu memoriju i prostor na disku."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"Nije moguće sačuvati TIFF sliku. Provjerite odredište, slobodnu memoriju i prostor na "
                L"disku."
            },
            { TXT_COPY_URL_FAILED, L"Nije moguće kopirati URL u međuspremnik." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"Pregledač Win32 zahtijeva 32-bitnu %s. Izaberite biblioteku x86/i386."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Ugrađenu biblioteku nije moguće upisati u AppData, korisnički profil, Program Files ili "
                L"privremenu fasciklu."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED, L"Raspakivanje biblioteke ili CRC provjera nije uspjela." },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Resurs ugrađene biblioteke nije ispravan." },
            { TXT_CURL_FILENAME_INVALID,
                L"Biblioteka se mora zvati libcurl.dll da bi je MediaInfo mogla koristiti."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Nije moguće otvoriti dijalog za datoteke." },
            { TXT_FILE_DIALOG_SELECTION_FAILED,
                L"Nije moguće dobiti izabrane datoteke iz dijaloga za datoteke."
            },
            { TXT_RECENT_FILE_MISSING,
                L"Datoteka „%s“ više ne postoji.\n\nŽelite li ukloniti ovu stavku sa spiska nedavnih "
                L"datoteka?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Datoteka više nije dostupna:\n\n%s\n\nŽelite li ukloniti ovu stavku sa spiska nedavnih "
                L"datoteka?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Nije moguće kopirati podatke u međuspremnik." },
            { TXT_CURL_PATH_INVALID, L"Putanja do libcurl.dll nije ispravna ili je preduga." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Biblioteka nije vratila verziju MediaInfo." },
            { TXT_CURL_EXPORTS_MISSING, L"Biblioteka ne izvozi funkcije curl potrebne za MediaInfo." },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"Biblioteka ne izvozi potrebne Unicode funkcije biblioteke MediaInfo."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Proces biblioteke nije uspio tokom %s (kod 0x%08lX). Izaberite kompatibilnu DLL u Opcije "
                L"> Podešavanja."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Proces biblioteke ne odgovara tokom %s. Izaberite kompatibilnu DLL u Opcije > Podešavanja."
            },
            { TXT_PREFERENCES_SAVE_FAILED, L"Podešavanja su primijenjena, ali nisu sačuvana u registru." },
            { TXT_REPORT_START_FAILED, L"Nema dovoljno memorije za pokretanje izvještaja." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Nije moguće napraviti sliku izvještaja." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Nije moguće učitati jezičku tabelu. Izaberite ispravan "
                L"MediaInfo CSV u UTF-8 ili UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"Nije moguće pokrenuti nit izvještaja." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"Izabrana MediaInfo.dll odbila je jezik izvještaja." },
            { TXT_INVALID_WINDOWS_DLL, L"Izabrana datoteka nije ispravna Windows DLL." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Izabrani format slike nije podržan." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Nije moguće sačuvati tekstualni izvještaj. Provjerite odredište i slobodan prostor na "
                L"disku."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Nije moguće otvoriti stranicu u podrazumijevanom pregledaču." },
            { TXT_TOO_MANY_FILES, L"Izabrano je previše datoteka. Otvarajte manje grupe." },
            { TXT_LIBRARY_PATH_HINT,
                L"Koristite 32-bitne biblioteke kompatibilne s vašom verzijom sistema Windows. Ostavite "
                L"putanje prazne za automatsku pretragu. MediaInfoLib v0.7.60 ne koristi libcurl.dll."
            },
            { TXT_VERSION, L"Verzija" },
            { TXT_WEBSITE_TOOLTIP, L"Otvori veb-sajt %s" },
            { TXT_WAITING_FOR_REPORT, L"Čekanje završetka trenutnog izvještaja." },
            { TXT_WEBSITE_LABEL, L"Veb-sajt:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"kopiranja izvještaja MediaInfo" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"Putanja do libc&url.dll:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"učitavanja MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"učitavanja libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"oslobađanja MediaInfo.dll" },
            { TXT_APPLY, L"Primije&ni" },
            { TXT_TAB_NAME_LENGTH, L"Dužina naziva &kartice:" },
            { TXT_TITLE_NAME_LENGTH, L"D&užina naslova:" },
            { TXT_RECENT_FILES, L"Nedavne datoteke:" },
            { TXT_CLEAR_RECENT_FILES, L"&Očisti" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"Dužina naziva kartice mora biti između 8 i 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"Dužina naziva u naslovu mora biti između 8 i 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Lista nedavnih datoteka je očišćena, ali nije sačuvana u registru."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"Z&atvaraj kartice dvoklikom" },
            { TXT_CLOSE_TAB_CONTEXT, L"&Zatvori karticu" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"Do&zvoli više instanci" },
            { TXT_INSTANCE_FORWARD_FAILED,
                L"Datoteke nije bilo moguće proslijediti pokrenutoj instanci programa MediaInfo."
            },
            { TXT_LOADING, L"Učitavanje…" },
            { TXT_LOADING_FILE, L"Učitavanje datoteke %s…" },
            { TXT_APPLICATION_HELP,
                L"DATOTEKE I KARTICE\r\nIzvorni Windows x86 pregledač izvještaja MediaInfo.dll. Svaka "
                L"datoteka ima svoju karticu samo za čitanje. Otvorite pomoću Ctrl+O ili prevlačenjem. "
                L"Ponovno otvaranje bira postojeću karticu. Ctrl+W ili srednje dugme miša zatvara "
                L"karticu; Zatvori sve zatvara sve kartice. Meni Datoteka pamti osam nedavnih datoteka. "
                L"Kontekstni meni zaglavlja kartice sadrži Zatvori karticu. U Podešavanjima uključite "
                L"Zatvaraj kartice dvoklikom da biste zatvorili karticu dvoklikom na njeno zaglavlje. "
                L"Opcija je početno isključena i njeno stanje se čuva. Dvoklik u tekstu izvještaja bira "
                L"riječ. Trostruki klik bira logički red. Povlačenje proširuje izbor po riječima ili "
                L"redovima.\r\nOtvori fasciklu… otvara datoteke koje su neposredno u izabranoj fascikli, "
                L"svaku na zasebnoj kartici. Podfascikle nijesu uključene.\r\nOtvori i Otvori fasciklu "
                L"dijele posljednju izabranu fasciklu. Izvoz pamti zasebnu fasciklu, podrazumijevano "
                L"Dokumenti. Napredni režim prikazuje dodatna polja izvještaja.\r\nPoznati formati / "
                L"Poznati kodeci / Poznati parametri — MediaInfo.dll.\r\nPotpuna analiza ispituje cijelu "
                L"datoteku i može potrajati duže. Ove opcije izvještaja i Nivo praćenja pripadaju svakoj "
                L"kartici; promjena osvježava samo aktivnu karticu. Posljednja ručno izabrana kombinacija "
                L"čuva se za nove kartice i sljedeće pokretanje. Odgovarajući izvještaj iz keš memorije "
                L"ponovo se koristi dok datoteka ostaje nepromijenjena.\r\nNivo praćenja: 0 / 5 / 9 / "
                L"10.\r\nDatoteka > Podešavanje stranice… otvara podešavanja papira, orijentacije i "
                L"margina za tekuću sesiju. Štampaj… (Ctrl+P) otvara sistemski dijalog štampanja; Windows "
                L"11 pruža pregled, dok Windows 10 i stariji zadržavaju klasični dijalog. Ctrl+P štampa "
                L"aktivnu karticu glavnog prozora ili tekstualno polje prozora Pomoć ili O programu, "
                L"zavisno od toga koji prozor ima fokus. Izvještaji koriste izabrani font izvještaja, "
                L"Pomoć sistemski font dijaloga, a O programu font svog tekstualnog polja. Ako nema "
                L"otvorenih kartica, a Pomoć je otvorena, Podešavanje stranice… i Štampaj… ostaju "
                L"dostupni; Štampaj… štampa pomoć. Pomoć koristi dijalog štampanja glavnog prozora; "
                L"ponovni Ctrl+P u Pomoći dovodi isti dijalog u prvi plan. Dugi redovi se prelamaju, a "
                L"tekst dijeli na stranice. Štampanje se odvija u pozadini.\r\nPrevucite jednu ili više "
                L"datoteka u prozor, na ikonu EXE datoteke ili njenu prečicu ili proslijedite njihove "
                L"putanje preko komandne linije. Ako više instanci nije dozvoljeno, datoteke se otvaraju "
                L"u već pokrenutom prozoru.\r\nLijeva strana statusne trake prikazuje putanje datoteka i "
                L"tok učitavanja, a desna verziju učitane biblioteke MediaInfo.dll. Duge putanje skraćuju "
                L"se trotačkom prema dostupnom prostoru.\r\n\r\nIZVOZ\r\nTXT, BMP, GIF, JPEG, PNG, TIFF i "
                L"WebP prikazuju se kada su dostupni. Posljednja fascikla i format izvoza se pamte.\r\n"
                L"TXT nudi ANSI, UTF-8, UTF-8 s BOM-om, UTF-16 BE s BOM-om i UTF-16 LE s BOM-om. "
                L"Podrazumijevana je druga stavka, UTF-8 bez BOM-a. Čuvaju se cijeli tekst izvještaja i "
                L"izvorni završeci redova.\r\n\r\nNAPRAVI DATOTEKU ZAGLAVLJA\r\nMeni Alati je četvrti na "
                L"traci menija. Komanda Napravi datoteku zaglavlja… otvara jednu ulaznu datoteku "
                L"nezavisno od kartica izvještaja i kopira njenih prvih 524288 bajtova (512 KiB). Kraća "
                L"datoteka se kopira u cjelini; prazna datoteka daje praznu izlaznu datoteku. To je "
                L"obično binarno čitanje datoteke, bez analize pomoću MediaInfo i bez potrebe za "
                L"MediaInfo.dll. Kartice izvještaja i spisak nedavnih datoteka ostaju "
                L"nepromijenjeni.\r\n\r\nNakon čitanja otvara se dijalog Sačuvaj kao u fascikli ulazne "
                L"datoteke. Za video.mp4 nudi naziv video.mp4.header: .header se dodaje na cijeli izvorni "
                L"naziv, uključujući nastavak. Možete promijeniti naziv i odredišnu fasciklu. Otkazivanje "
                L"bilo kog dijaloga ne upisuje izlaznu datoteku. Zamjena postojeće odredišne datoteke "
                L"zahtijeva potvrdu. Ulazna datoteka se ne mijenja, a neuspješno čuvanje zadržava "
                L"prethodnu odredišnu datoteku. Otvaranje i čuvanje koriste najnovije sistemske dijaloge "
                L"dostupne u toj verziji Windowsa.\r\n\r\nPri pokretanju aplikacije alat preuzima istu "
                L"početnu fasciklu kao Datoteka > Otvori. Ako fascikla nije sačuvana, Windows bira "
                L"početnu lokaciju. Poslije izbora ulazne datoteke alat pamti sopstvenu fasciklu samo do "
                L"zatvaranja aplikacije, čak i ako otkažete Sačuvaj kao. Ne mijenja fascikle komandi "
                L"Otvori i Izvezi niti čuva svoju fasciklu u podešavanjima aplikacije. Svaki dijalog "
                L"Sačuvaj kao počinje u fascikli trenutno izabrane ulazne datoteke, bez obzira na "
                L"prethodno odredište čuvanja.\r\n\r\nPODEŠAVANJA I JEZICI\r\nPodešavanja (Opcije > "
                L"Podešavanja, Ctrl+G) sadrže putanje biblioteka, font izvještaja, umekšavanje i jezike. "
                L"Interfejs ima 36 varijanti i početno prati Windows. Izvještaji uvijek podrazumijevano "
                L"koriste izvorni engleski biblioteke, nezavisno od Windowsa i interfejsa. To mijenja "
                L"samo ručni izbor jezika: engleski, 37 prevoda ili sopstvena MediaInfo CSV tabela. U "
                L"redu ili Primijeni potvrđuje promjene; Otkaži odbacuje nepotvrđene promjene. "
                L"Podešavanja određuju granicu naziva kartice (podrazumijevano 80) i brišu listu nedavnih "
                L"datoteka. Dugi nazivi zadržavaju početak, kraj i ekstenziju s trotačkom u sredini. "
                L"Očisti odmah uklanja listu nedavnih datoteka, čak i ako zatim zatvorite Podešavanja "
                L"dugmetom Otkaži.\r\n\r\nNaslov glavnog prozora prikazuje aktivnu datoteku u obliku naziv "
                L"datoteke — MediaInfo. U podešavanjima se dužina naziva u naslovu može zasebno postaviti na "
                L"8–255 znakova (podrazumijevano 40). Duži nazivi skraćuju se istom trotačkom u sredini, uz "
                L"očuvanje nastavka. Bez otvorenih kartica naslov je MediaInfo.\r\n\r\nBIBLIOTEKE I "
                L"PROZORI\r\nProgram sadrži MediaInfo 26.10, 21.03 i "
                L"0.7.60, koje se pokušavaju od najnovije nakon spoljnih biblioteka. Dvije novije verzije "
                L"imaju odgovarajući libcurl; 0.7.60 ga nikada ne raspakuje. Položaj prozora se čuva. "
                L"Podrazumijevano je dozvoljena samo jedna instanca, a naredna pokretanja šalju datoteke "
                L"otvorenom prozoru. U podešavanjima se može dozvoliti više instanci. Kada postoji više "
                L"prozora, samo prvi prozor svakog tipa prozora vraća sačuvani položaj; ostali vraćaju "
                L"samo veličinu.\r\n\r\nUređivanje > Pronađi (Ctrl+F) pretražuje aktivnu karticu "
                L"izvještaja ili tekstualno polje prozora Pomoć ili O programu, zavisno od toga koji "
                L"prozor ima fokus. Prozor pretrage zadržava posljednji izabrani izvor dok ima fokus. F3 "
                L"ponavlja pretragu, a Shift+F3 mijenja njen smjer. Na kraju teksta pretraga se nastavlja "
                L"s drugog kraja. Opcije > Prelamanje redova važi samo za aktivnu karticu; oznaka prati "
                L"izabranu karticu. Prozor pretrage može se minimizirati i mijenjati mu se širina; "
                L"položaj i opcija Uvijek na vrhu se pamte. Do 30 tekstova pretrage s njihovim opcijama "
                L"čuva se samo do zatvaranja aplikacije. Opcije početka i kraja odnose se na logičke "
                L"redove. Regularni izrazi koriste PCRE2 sintaksu. Ostale komande menija Uređivanje "
                L"odnose se na aktivnu karticu izvještaja. Enter pokreće pretragu, a Shift+Enter obrće "
                L"izabrani smjer. „Razlikuj velika i mala slova“ razlikuje velika i mala slova; „Traži "
                L"unazad“ traži prema početku teksta. Izbor stavke istorije vraća svih pet opcija "
                L"pretrage, uključujući stanje režima regularnih izraza; „Uvijek na vrhu“ je nezavisna "
                L"opcija. „Regularni izraz“ onemogućava „Red počinje sa“ i „Red se završava sa“. Kada su "
                L"uključene obje opcije krajeva reda, dovoljno je poklapanje na jednom kraju. „Prelamanje "
                L"redova“ mijenja samo prikaz."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"Nije moguće sačuvati WebP sliku. Provjerite odredište, slobodnu memoriju i prostor na "
                L"disku."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Tekstualni dokument UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Tekstualni dokument UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Tekstualni dokument UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Tekstualni dokument UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Izvještaj se ne može sačuvati u ovom kodiranju bez gubitka znakova. Izaberite drugo "
                L"kodiranje teksta."
            },
            { TXT_OPEN_FOLDER, L"Otvori &fasciklu…" },
            { TXT_OPEN_FOLDER_TITLE, L"Otvori fasciklu" },
            { TXT_FOLDER_READ_FAILED, L"Fascikla se ne može pročitati:\n\n%s\n\nGreška Windowsa %lu." },
            { TXT_ADVANCED_MODE, L"&Napredni režim" },
            { TXT_REPORT_DETAIL_REJECTED,
                L"Izabrana MediaInfo.dll odbila je podešavanje detalja izvještaja."
            },
            { TXT_KNOWN_FORMATS, L"Poznati &formati" },
            { TXT_KNOWN_CODECS, L"Poznati &kodeci" },
            { TXT_KNOWN_PARAMETERS, L"Poznati p&arametri" },
            { TXT_KNOWN_FORMATS_TITLE, L"Poznati formati" },
            { TXT_KNOWN_CODECS_TITLE, L"Poznati kodeci" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Poznati parametri" },
            { TXT_KNOWN_INFO_FAILED, L"Biblioteka nije vratila tražene informacije." },
            { TXT_FULL_PARSING, L"Potpuna &analiza" },
            { TXT_PARSING_REJECTED, L"Izabrana MediaInfo.dll odbila je podešavanje analize." },
            { TXT_TRACE_LEVEL_0, L"Nivo praćenja &0" },
            { TXT_TRACE_LEVEL_5, L"Nivo praćenja &5" },
            { TXT_TRACE_LEVEL_9, L"Nivo praćenja &9" },
            { TXT_TRACE_LEVEL_10, L"Nivo praćenja &10" },
            { TXT_PAGE_SETUP, L"&Podešavanje stranice…" },
            { TXT_PAGE_SETUP_FAILED, L"Nije moguće otvoriti podešavanje stranice." },
            { TXT_PRINT, L"Š&tampaj…\tCtrl+P" },
            { TXT_PRINTING, L"Štampanje…" },
            { TXT_PRINT_FAILED,
                L"Tekst se ne može odštampati. Provjerite štampač, njegova podešavanja i dostupnu "
                L"memoriju."
            },
            { TXT_TOOLS_MENU, L"&Alati" },
            { TXT_CREATE_HEADER, L"Napravi datoteku &zaglavlja…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Napravi datoteku zaglavlja - Otvori" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Napravi datoteku zaglavlja - Sačuvaj kao" },
            { TXT_HEADER_FORMAT, L"Datoteka zaglavlja (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Nije moguće pročitati zaglavlje datoteke:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Nije moguće sačuvati datoteku zaglavlja:\n\n%s" },
            { TXT_COPY, L"&Kopiraj" },
            { TXT_COPY_FILE_NAME, L"Kopiraj &naziv datoteke" },
            { TXT_COPY_FULL_PATH, L"Kopiraj punu p&utanju" },
            { TXT_LAUNCH_FILE, L"Po&kreni datoteku" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"P&rikaži u fascikli" },
            { TXT_EDIT_MENU, L"&Uređivanje" },
            { TXT_WORD_WRAP, L"P&relamanje redova" },
            { TXT_WORD_WRAP_FAILED, L"Prelamanje redova nije moguće promijeniti." },
            { TXT_COPY_SELECTION, L"&Kopiraj\tCtrl+C" },
            { TXT_SELECT_ALL, L"Izaberi &sve\tCtrl+A" },
            { TXT_FIND_MENU, L"&Pronađi…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Pronađi s&ljedeće\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Pronađi preth&odno\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Pronađi" },
            { TXT_FIND_WHAT, L"&Traži:" },
            { TXT_FIND_NEXT, L"Pronađi s&ljedeće" },
            { TXT_FIND_MATCH_CASE, L"Razlikuj velika i &mala slova" },
            { TXT_FIND_BACKWARD, L"Traži &unazad" },
            { TXT_FIND_TOPMOST, L"Uvijek na &vrhu" },
            { TXT_FIND_STARTS_WITH, L"Red počinje &sa" },
            { TXT_FIND_ENDS_WITH, L"Red se završava s&a" },
            { TXT_FIND_REGEX, L"&Regularni izraz" },
            { TXT_FIND_NOT_FOUND, L"Navedeni tekst nije pronađen." },
            { TXT_FIND_FAILED, L"Pretragu nije moguće dovršiti." },
            { TXT_FIND_REGEX_ERROR, L"Greška u regularnom izrazu:\r\n\r\n%s" },
        }
    },
    {
        LANG_BE,
        {
            { TXT_LANGUAGE_NAME, L"Беларуская" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nВэб-сайт: " },
            { TXT_FILE_OPEN_FAILED, L"Немагчыма адкрыць %s. Праверце шлях і дазволы." },
            { TXT_BROWSE_DLL, L"&Агляд…" },
            { TXT_BROWSE_REPORT, L"Аг&ляд…" },
            { TXT_CLOSE, L"&Закрыць" },
            { TXT_CLOSE_TAB, L"&Закрыць\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"&Прадвызначаны" },
            { TXT_EXPORT, L"&Экспартаваць…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Файл" },
            { TXT_REPORT_FONT, L"Ш&рыфт справаздачы:" },
            { TXT_HELP_MENU, L"&Даведка" },
            { TXT_HELP, L"&Даведка\tF1" },
            { TXT_LANGUAGE, L"&Мова:" },
            { TXT_OPEN_WEBSITE, L"&Адкрыць у прадвызначаным браўзеры" },
            { TXT_OPEN, L"&Адкрыць…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"П&араметры" },
            { TXT_PREFERENCES_MENU, L"&Налады…\tCtrl+G" },
            { TXT_ABOUT, L"&Пра праграму" },
            { TXT_ABOUT_TITLE, L"Пра праграму %ls" },
            { TXT_ALL_FILES, L"Усе файлы" },
            { TXT_FONT_BOLD, L"Паўтлусты" },
            { TXT_FONT_BOLD_ITALIC, L"Паўтлусты + Курсіў" },
            { TXT_BROWSE_CURL, L"А&гляд…" },
            { TXT_CANCEL, L"Скасаваць" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Немагчыма загрузіць MediaInfo.dll (памылка Windows %lu). Выкарыстайце 32-бітную DLL, "
                L"сумяшчальную з гэтай версіяй Windows."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Немагчыма загрузіць libcurl.dll (памылка Windows %lu). Выберыце 32-бітную бібліятэку, "
                L"сумяшчальную з гэтай версіяй Windows."
            },
            { TXT_CLOSE_ALL, L"Закрыць &усё" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Капіяваць ад&рас" },
            { TXT_COPY_INFORMATION, L"Капіяваць &звесткі" },
            { TXT_DLL_FILES, L"Дынамічныя бібліятэкі" },
            { TXT_EXIT, L"&Выйсці\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Убудаваныя бібліятэкі MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Убудаваныя бібліятэкі libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Экспартаваць справаздачу" },
            { TXT_FONT_ANTIALIASING, L"&Згладжванне шрыфту:" },
            { TXT_GIF_EXPORT_FAILED,
                L"Экспарт GIF не ўдаўся. GIF без страт патрабуе не больш за 256 колераў."
            },
            { TXT_FONT_ITALIC, L"Курсіў" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED, L"Экспарт JPEG не ўдаўся. Патрэбны працоўны кадавальнік JPEG GDI+." },
            { TXT_LICENSE_UNAVAILABLE, L"Рэсурс ліцэнзіі недаступны." },
            { TXT_MEDIA_FILES, L"Медыяфайлы" },
            { TXT_APPLICATION_DESCRIPTION, L"Прагляд інфармацыі пра медыя" },
            { TXT_HELP_TITLE, L"MediaInfo — Даведка" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo не змагла ініцыялізаваць аналіз файла." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo не можа адкрыць або распазнаць гэты файл." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"&Шлях да MediaInfo.dll:" },
            { TXT_MEDIALIB_REQUIRED, L"MediaInfo.dll не загружана. Выберыце яе ў Параметры > Налады." },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll не загружана." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Не ўдалося загрузіць сумяшчальную знешнюю або ўбудаваную MediaInfo.dll. Выберыце яе ў "
                L"Параметры > Налады."
            },
            { TXT_ANTIALIASING_NONE, L"Няма" },
            { TXT_OK, L"OK" },
            { TXT_OPEN_TITLE, L"Адкрыць медыяфайлы" },
            { TXT_PLATFORM, L"Мэтавая платформа:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Налады" },
            { TXT_READY, L"Гатовы" },
            { TXT_FONT_REGULAR, L"Звычайны" },
            { TXT_REPORT_LANGUAGE, L"Мова &справаздачы:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Моўныя табліцы справаздач" },
            { TXT_SELECT_MEDIALIB, L"Агляд: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Агляд: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH, L"Выберыце існы медыяфайл са шляхам, карацейшым за MAX_PATH." },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Выберыце існыя файлы са шляхамі карацейшымі за MAX_PATH." },
            { TXT_SELECT_CURL, L"Агляд: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Тэкставы дакумент ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"Немагчыма захаваць выяву BMP. Праверце месца прызначэння, свабодную памяць і месца на "
                L"дыску."
            },
            { TXT_LIBRARY_WORKER_START_FAILED,
                L"Немагчыма запусціць працэс бібліятэкі (памылка Windows %lu)."
            },
            { TXT_REPORT_COPY_FAILED, L"Немагчыма скапіяваць справаздачу MediaInfo ў памяць." },
            { TXT_VIEWER_CREATE_FAILED, L"Немагчыма стварыць праграму прагляду MediaInfo." },
            { TXT_MEDIALIB_PATH_INVALID, L"Шлях да MediaInfo.dll няправільны або занадта доўгі." },
            { TXT_PNG_EXPORT_FAILED,
                L"Немагчыма захаваць выяву PNG. Праверце месца прызначэння, свабодную памяць і месца на "
                L"дыску."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"Немагчыма захаваць выяву TIFF. Праверце месца прызначэння, свабодную памяць і месца на "
                L"дыску."
            },
            { TXT_COPY_URL_FAILED, L"Не ўдалося скапіяваць URL у буфер абмену." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"Праглядальнік Win32 патрабуе 32-бітную %s. Выберыце бібліятэку x86/i386."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Немагчыма запісаць убудаваную бібліятэку ў AppData, профіль карыстальніка, Program Files "
                L"або часовую папку."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED, L"Распакоўванне бібліятэкі або праверка CRC не ўдаліся." },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Рэсурс убудаванай бібліятэкі няправільны." },
            { TXT_CURL_FILENAME_INVALID,
                L"Бібліятэка павінна называцца libcurl.dll, каб MediaInfo магла яе выкарыстоўваць."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Не ўдалося адкрыць дыялог выбару файлаў." },
            { TXT_FILE_DIALOG_SELECTION_FAILED,
                L"Не ўдалося атрымаць выбраныя файлы з дыялогу выбару файлаў."
            },
            { TXT_RECENT_FILE_MISSING,
                L"Файл «%s» больш не існуе.\n\nВыдаліць гэты запіс са спіса апошніх файлаў?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Файл больш недаступны:\n\n%s\n\nВыдаліць гэты запіс са спіса апошніх файлаў?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Не ўдалося скапіяваць звесткі ў буфер абмену." },
            { TXT_CURL_PATH_INVALID, L"Шлях да libcurl.dll няправільны або занадта доўгі." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Бібліятэка не вярнула версію MediaInfo." },
            { TXT_CURL_EXPORTS_MISSING, L"Бібліятэка не экспартуе функцыі curl, патрэбныя MediaInfo." },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"Бібліятэка не экспартуе патрэбныя функцыі Unicode бібліятэкі MediaInfo."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Працэс бібліятэкі завяршыўся памылкай падчас %s (код 0x%08lX). Выберыце сумяшчальную DLL "
                L"у Параметры > Налады."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Працэс бібліятэкі не адказвае падчас %s. Выберыце сумяшчальную DLL у Параметры > Налады."
            },
            { TXT_PREFERENCES_SAVE_FAILED, L"Налады ўжытыя, але іх не ўдалося захаваць у рэестр." },
            { TXT_REPORT_START_FAILED, L"Недастаткова памяці для запуску справаздачы." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Немагчыма стварыць выяву справаздачы." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Немагчыма загрузіць моўную табліцу. Выберыце правільны "
                L"файл MediaInfo CSV у UTF-8 або UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"Немагчыма запусціць паток справаздачы." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"Выбраная MediaInfo.dll адхіліла мову справаздачы." },
            { TXT_INVALID_WINDOWS_DLL, L"Выбраны файл не з’яўляецца правільнай DLL Windows." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Выбраны фармат выявы не падтрымліваецца." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Немагчыма захаваць тэкставую справаздачу. Праверце месца прызначэння і свабоднае месца на "
                L"дыску."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Немагчыма адкрыць сайт у прадвызначаным браўзеры." },
            { TXT_TOO_MANY_FILES, L"Выбрана занадта шмат файлаў. Адкрывайце меншыя групы." },
            { TXT_LIBRARY_PATH_HINT,
                L"Выкарыстайце 32-бітныя бібліятэкі, сумяшчальныя з вашай версіяй Windows. Пакіньце шляхі "
                L"пустымі для аўтаматычнага пошуку. MediaInfoLib v0.7.60 не выкарыстоўвае libcurl.dll."
            },
            { TXT_VERSION, L"Версія" },
            { TXT_WEBSITE_TOOLTIP, L"Адкрыць вэб-сайт %s" },
            { TXT_WAITING_FOR_REPORT, L"Чаканне завяршэння бягучай справаздачы." },
            { TXT_WEBSITE_LABEL, L"Вэб-сайт:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"капіявання справаздачы MediaInfo" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"Шлях &да libcurl.dll:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"загрузкі MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"загрузкі libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"выгрузкі MediaInfo.dll" },
            { TXT_APPLY, L"&Ужыць" },
            { TXT_TAB_NAME_LENGTH, L"Да&ўжыня назвы ўкладкі:" },
            { TXT_TITLE_NAME_LENGTH, L"&Даўжыня загалоўка:" },
            { TXT_RECENT_FILES, L"Апошнія файлы:" },
            { TXT_CLEAR_RECENT_FILES, L"А&чысціць" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"Даўжыня назвы ўкладкі павінна быць ад 8 да 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"Даўжыня назвы ў загалоўку павінна быць ад 8 да 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Спіс апошніх файлаў быў ачышчаны, але яго не ўдалося захаваць у рэестры."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"За&крываць укладкі падвойнай пстрычкай" },
            { TXT_CLOSE_TAB_CONTEXT, L"Закрыць &укладку" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"Даз&валяць некалькі асобнікаў" },
            { TXT_INSTANCE_FORWARD_FAILED, L"Не ўдалося перадаць файлы запушчанаму асобніку MediaInfo." },
            { TXT_LOADING, L"Загрузка…" },
            { TXT_LOADING_FILE, L"Загрузка файла %s…" },
            { TXT_APPLICATION_HELP,
                L"ФАЙЛЫ І ЎКЛАДКІ\r\nНатыўны праглядальнік справаздач MediaInfo.dll для Windows x86. "
                L"Кожны файл мае асобную ўкладку толькі для чытання. Адкрывайце праз Ctrl+O або "
                L"перацягваннем. Паўторнае адкрыццё выбірае існую ўкладку. Ctrl+W або сярэдняя кнопка "
                L"мышы закрывае ўкладку; Закрыць усё закрывае ўсе. Меню Файл памятае восем апошніх "
                L"файлаў. Кантэкстнае меню загалоўка ўкладкі змяшчае Закрыць укладку. У Наладах уключыце "
                L"Закрываць укладкі падвойнай пстрычкай, каб закрываць укладку падвойнай пстрычкай па яе "
                L"загалоўку. Параметр па змаўчанні выключаны і захоўваецца. Падвойная пстрычка ў тэксце "
                L"справаздачы вылучае слова. Трайная пстрычка вылучае лагічны радок. Перацягванне пашырае "
                L"вылучэнне па словах або радках.\r\nАдкрыць папку… адкрывае файлы непасрэдна ў выбранай "
                L"папцы, кожны ва ўласнай укладцы. Укладзеныя папкі не ўключаюцца.\r\nАдкрыць і Адкрыць "
                L"папку выкарыстоўваюць агульную апошнюю выбраную папку. Экспарт запамінае асобную папку, "
                L"прадвызначана Дакументы. Пашыраны рэжым паказвае дадатковыя палі справаздачы.\r\n"
                L"Вядомыя фарматы / Вядомыя кодэкі / Вядомыя параметры — MediaInfo.dll.\r\nПоўны аналіз "
                L"правярае ўвесь файл і можа заняць больш часу. Гэтыя параметры справаздачы і Узровень "
                L"трасіроўкі належаць кожнай укладцы; змяненне абнаўляе толькі актыўную ўкладку. Апошняя "
                L"абраная ўручную камбінацыя захоўваецца для новых укладак і наступнага запуску. "
                L"Адпаведная кэшаваная справаздача выкарыстоўваецца паўторна, пакуль файл застаецца "
                L"нязменным.\r\nУзровень трасіроўкі: 0 / 5 / 9 / 10.\r\nФайл > Параметры старонкі… "
                L"адкрывае налады паперы, арыентацыі і палёў для бягучага сеанса. Друк… (Ctrl+P) адкрывае "
                L"сістэмны дыялог друку; Windows 11 дае папярэдні прагляд, а Windows 10 і старэйшыя "
                L"захоўваюць класічны дыялог. Ctrl+P друкуе актыўную ўкладку галоўнага акна або тэкставае "
                L"поле Даведкі ці Пра праграму ў залежнасці ад таго, якое акно мае фокус. Справаздачы "
                L"выкарыстоўваюць выбраны шрыфт справаздачы, Даведка сістэмны шрыфт дыялогаў, а Пра "
                L"праграму шрыфт свайго тэкставага поля. Калі ўкладкі не адкрытыя, але Даведка адкрытая, "
                L"Параметры старонкі… і Друк… застаюцца даступнымі; Друк… друкуе даведку. Даведка "
                L"выкарыстоўвае дыялог друку галоўнага акна; паўторны Ctrl+P у Даведцы выводзіць той жа "
                L"дыялог на пярэдні план. Доўгія радкі пераносяцца, а тэкст дзеліцца на старонкі. Друк "
                L"выконваецца ў фоне.\r\nПерацягніце адзін або некалькі файлаў у акно, на значок EXE або "
                L"яго ярлык ці перадайце іх шляхі ў камандным радку. Калі некалькі асобнікаў не "
                L"дазволеныя, файлы адкрываюцца ва ўжо запушчаным акне.\r\nЗлева ў радку стану "
                L"паказваюцца шляхі файлаў і ход загрузкі, справа — версія загружанай MediaInfo.dll. "
                L"Доўгія шляхі скарачаюцца шматкроп’ем з улікам даступнага месца.\r\n\r\nЭКСПАРТ\r\nTXT, "
                L"BMP, GIF, JPEG, PNG, TIFF і WebP паказваюцца паводле даступнасці. Апошняя папка і "
                L"фармат экспарту захоўваюцца.\r\nTXT прапануе ANSI, UTF-8, UTF-8 з BOM, UTF-16 BE з BOM "
                L"і UTF-16 LE з BOM. Па змаўчанні выбраны другі варыянт, UTF-8 без BOM. Захоўваюцца ўвесь "
                L"тэкст справаздачы і зыходныя канцы радкоў.\r\n\r\nСТВАРЫЦЬ ЗАГАЛОВАК\r\nМеню "
                L"Інструменты — чацвёртае ў радку меню. Яго каманда Стварыць загаловак… адкрывае адзін "
                L"зыходны файл незалежна ад укладак справаздачы і капіюе яго першыя 524288 байт (512 "
                L"KiB). Больш кароткі файл капіюецца цалкам; пусты файл стварае пусты вынік. Гэта "
                L"звычайнае чытанне бінарнага файла без аналізу MediaInfo або патрабавання MediaInfo.dll. "
                L"Інструмент пакідае нязменнымі ўкладкі справаздач і спіс апошніх файлаў праграмы "
                L"прагляду.\r\n\r\nПасля прачытання ў папцы зыходнага файла адкрыецца дыялогавае акно "
                L"\"Захаваць як\", якое прапануе video.mp4.header для video.mp4: .header дадаецца да "
                L"поўнай зыходнай назвы. Вы можаце змяніць як назву, так і папку прызначэння. Скасаванне "
                L"любога дыялогу не прыводзіць да вываду. Замена існуючага прызначэння патрабуе "
                L"пацверджання. Уваходны файл застаецца нязменным; няўдалае захаванне захоўвае папярэдні "
                L"пункт прызначэння. Для адкрыцця і захавання выкарыстоўваюцца найноўшыя сістэмныя "
                L"дыялогавыя вокны, даступныя ў гэтай версіі Windows.\r\n\r\nПры запуску праграмы "
                L"інструмент бярэ пачатковую папку ўводу з Файл > Адкрыць. Калі папка не была захавана, "
                L"Windows выбірае першапачатковае размяшчэнне. Пасля выбару ўваходнага файла інструмент "
                L"запамінае ўласную папку толькі да выхаду з праграмы, нават калі каманда \"Захаваць як\" "
                L"адменена. Ён не змяняе папкі, якія выкарыстоўваюцца Адкрыць і Экспартаваць, і не "
                L"захоўвае ўласную папку ў наладах прыкладання. Кожнае дыялогавае акно «Захаваць як» "
                L"пачынаецца ў папцы выбранага ўваходнага файла, незалежна ад папярэдняга месца "
                L"захавання.\r\n\r\nНАЛАДЫ І МОВЫ\r\nНалады (Параметры > Налады, Ctrl+G) змяшчаюць шляхі "
                L"бібліятэк, шрыфт справаздачы, згладжванне і мовы. Інтэрфейс мае 36 варыянтаў і спачатку "
                L"адпавядае Windows. Справаздачы заўсёды па змоўчанні выкарыстоўваюць зыходную англійскую "
                L"бібліятэкі, незалежна ад Windows і інтэрфейсу. Гэта змяняе толькі ручны выбар: "
                L"англійская, 37 перакладаў або ўласная табліца MediaInfo CSV. OK або Ужыць пацвярджае "
                L"змены; Скасаваць адкідае непацверджаныя змены. У наладах задаецца мяжа назвы ўкладкі "
                L"(па змоўчанні 80) і ачышчаецца спіс апошніх файлаў. Доўгія назвы захоўваюць пачатак, "
                L"канец і пашырэнне са шматкроп’ем пасярэдзіне. Ачысціць адразу выдаляе спіс апошніх "
                L"файлаў, нават калі пасля гэтага закрыць налады кнопкай Скасаваць.\r\n\r\nЗагаловак "
                L"галоўнага акна паказвае актыўны файл у выглядзе назва файла — MediaInfo. У наладах можна "
                L"асобна задаць даўжыню назвы ў загалоўку ад 8 да 255 сімвалаў (прадвызначана 40). Доўгія "
                L"назвы скарачаюцца тым жа шматкроп’ем пасярэдзіне з захаваннем пашырэння. Без адкрытых "
                L"укладак загаловак — MediaInfo.\r\n\r\nБІБЛІЯТЭКІ І "
                L"ВОКНЫ\r\nПраграма змяшчае MediaInfo 26.10, 21.03 і 0.7.60, якія правяраюцца ад "
                L"найноўшай пасля знешніх бібліятэк. Дзве навейшыя версіі маюць адпаведную libcurl; "
                L"0.7.60 ніколі яе не распакоўвае. Становішча акна захоўваецца. Паводле прадвызначэння "
                L"дазволены толькі адзін асобнік, а наступныя запускі перадаюць файлы адкрытаму акну. У "
                L"наладах можна дазволіць некалькі асобнікаў. Пры некалькіх вокнах толькі першае акно "
                L"кожнага тыпу акна аднаўляе захаванае становішча; астатнія аднаўляюць толькі "
                L"памер.\r\n\r\nПраўка > Знайсці (Ctrl+F) шукае ў актыўнай укладцы справаздачы або "
                L"тэкставым полі Даведкі ці Пра праграму ў залежнасці ад таго, якое акно мае фокус. Акно "
                L"пошуку захоўвае апошнюю выбраную крыніцу, пакуль само мае фокус. F3 паўтарае пошук, а "
                L"Shift+F3 змяняе яго кірунак. На мяжы тэксту пошук працягваецца з супрацьлеглага канца. "
                L"Параметры > Перанос радкоў дзейнічае толькі ў актыўнай укладцы; адзнака адпавядае "
                L"выбранай укладцы. Акно пошуку можна згарнуць і змяняць яго шырыню; пазіцыя і налада "
                L"Заўсёды зверху захоўваюцца. Да 30 пошукавых тэкстаў з іх параметрамі захоўваюцца толькі "
                L"да закрыцця праграмы. Параметры пачатку і канца тычацца лагічных радкоў. Рэгулярныя "
                L"выразы выкарыстоўваюць сінтаксіс PCRE2. Астатнія каманды меню Праўка дзейнічаюць у "
                L"актыўнай укладцы справаздачы. Enter запускае пошук, а Shift+Enter змяняе выбраны "
                L"кірунак на супрацьлеглы. «Улічваць рэгістр» адрознівае вялікія і малыя літары; «Шукаць "
                L"назад» шукае ў бок пачатку тэксту. Выбар запісу гісторыі аднаўляе ўсе пяць параметраў "
                L"пошуку, у тым ліку стан рэжыму рэгулярных выразаў; «Заўсёды зверху» — незалежны "
                L"параметр. «Рэгулярны выраз» выключае «Радок пачынаецца з» і «Радок сканчаецца на». Калі "
                L"ўключаны абодва параметры краёў радка, дастаткова супадзення на адным краі. «Перанос "
                L"радкоў» змяняе толькі адлюстраванне."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"Немагчыма захаваць выяву WebP. Праверце месца прызначэння, свабодную памяць і месца на "
                L"дыску."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Тэкставы дакумент UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Тэкставы дакумент UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Тэкставы дакумент UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Тэкставы дакумент UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Справаздачу нельга захаваць у гэтай кадзіроўцы без страты сімвалаў. Выберыце іншую "
                L"кадзіроўку тэксту."
            },
            { TXT_OPEN_FOLDER, L"Адкрыць &папку…" },
            { TXT_OPEN_FOLDER_TITLE, L"Адкрыць папку" },
            { TXT_FOLDER_READ_FAILED, L"Не ўдалося прачытаць папку:\n\n%s\n\nПамылка Windows %lu." },
            { TXT_ADVANCED_MODE, L"&Пашыраны рэжым" },
            { TXT_REPORT_DETAIL_REJECTED,
                L"Выбраная MediaInfo.dll адхіліла наладу падрабязнасці справаздачы."
            },
            { TXT_KNOWN_FORMATS, L"Вядомыя &фарматы" },
            { TXT_KNOWN_CODECS, L"Вядомыя &кодэкі" },
            { TXT_KNOWN_PARAMETERS, L"Вядомыя па&раметры" },
            { TXT_KNOWN_FORMATS_TITLE, L"Вядомыя фарматы" },
            { TXT_KNOWN_CODECS_TITLE, L"Вядомыя кодэкі" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Вядомыя параметры" },
            { TXT_KNOWN_INFO_FAILED, L"Бібліятэка не вярнула запытаныя звесткі." },
            { TXT_FULL_PARSING, L"Поўны &аналіз" },
            { TXT_PARSING_REJECTED, L"Выбраная MediaInfo.dll адхіліла наладу аналізу." },
            { TXT_TRACE_LEVEL_0, L"Узровень трасіроўкі &0" },
            { TXT_TRACE_LEVEL_5, L"Узровень трасіроўкі &5" },
            { TXT_TRACE_LEVEL_9, L"Узровень трасіроўкі &9" },
            { TXT_TRACE_LEVEL_10, L"Узровень трасіроўкі &10" },
            { TXT_PAGE_SETUP, L"Па&раметры старонкі…" },
            { TXT_PAGE_SETUP_FAILED, L"Не ўдалося адкрыць параметры старонкі." },
            { TXT_PRINT, L"&Друк…\tCtrl+P" },
            { TXT_PRINTING, L"Друк…" },
            { TXT_PRINT_FAILED,
                L"Не ўдалося надрукаваць тэкст. Праверце прынтар, яго налады і даступную памяць."
            },
            { TXT_TOOLS_MENU, L"&Інструменты" },
            { TXT_CREATE_HEADER, L"Стварыць &загаловак…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Стварыць загаловак - Адкрыць" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Стварыць загаловак - Захаваць як" },
            { TXT_HEADER_FORMAT, L"Файл загалоўка (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Не ўдалося прачытаць загаловак файла:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Не ўдалося захаваць файл загалоўка:\n\n%s" },
            { TXT_COPY, L"&Капіяваць" },
            { TXT_COPY_FILE_NAME, L"Капіяваць &імя файла" },
            { TXT_COPY_FULL_PATH, L"Капіяваць поўны &шлях" },
            { TXT_LAUNCH_FILE, L"Запу&сціць файл" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"Па&казаць у папцы" },
            { TXT_EDIT_MENU, L"&Праўка" },
            { TXT_WORD_WRAP, L"П&еранос радкоў" },
            { TXT_WORD_WRAP_FAILED, L"Не ўдалося змяніць перанос радкоў." },
            { TXT_COPY_SELECTION, L"&Капіяваць\tCtrl+C" },
            { TXT_SELECT_ALL, L"Выбраць &усё\tCtrl+A" },
            { TXT_FIND_MENU, L"&Знайсці…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Знайсці &далей\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Знайсці &папярэдняе\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Знайсці" },
            { TXT_FIND_WHAT, L"&Шукаць:" },
            { TXT_FIND_NEXT, L"Знайсці &далей" },
            { TXT_FIND_MATCH_CASE, L"Улічваць &рэгістр" },
            { TXT_FIND_BACKWARD, L"Шукаць &назад" },
            { TXT_FIND_TOPMOST, L"З&аўсёды зверху" },
            { TXT_FIND_STARTS_WITH, L"Радок &пачынаецца з" },
            { TXT_FIND_ENDS_WITH, L"Радок скан&чаецца на" },
            { TXT_FIND_REGEX, L"Рэгулярны &выраз" },
            { TXT_FIND_NOT_FOUND, L"Зададзены тэкст не знойдзены." },
            { TXT_FIND_FAILED, L"Не ўдалося завяршыць пошук." },
            { TXT_FIND_REGEX_ERROR, L"Памылка рэгулярнага выразу:\r\n\r\n%s" },
        }
    },
    {
        LANG_BG,
        {
            { TXT_LANGUAGE_NAME, L"Български" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nУебсайт: " },
            { TXT_FILE_OPEN_FAILED, L"Не може да се отвори %s. Проверете пътя и разрешенията." },
            { TXT_BROWSE_DLL, L"П&реглед…" },
            { TXT_BROWSE_REPORT, L"Пре&глед…" },
            { TXT_CLOSE, L"&Затвори" },
            { TXT_CLOSE_TAB, L"&Затвори\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"По п&одразбиране" },
            { TXT_EXPORT, L"&Експортирай…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Файл" },
            { TXT_REPORT_FONT, L"&Шрифт на отчета:" },
            { TXT_HELP_MENU, L"&Помощ" },
            { TXT_HELP, L"&Помощ\tF1" },
            { TXT_LANGUAGE, L"Е&зик:" },
            { TXT_OPEN_WEBSITE, L"&Отвори в браузъра по подразбиране" },
            { TXT_OPEN, L"&Отвори…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Опции" },
            { TXT_PREFERENCES_MENU, L"&Предпочитания…\tCtrl+G" },
            { TXT_ABOUT, L"&За програмата" },
            { TXT_ABOUT_TITLE, L"За програмата %ls" },
            { TXT_ALL_FILES, L"Всички файлове" },
            { TXT_FONT_BOLD, L"Получер" },
            { TXT_FONT_BOLD_ITALIC, L"Получер + Курсив" },
            { TXT_BROWSE_CURL, L"Пр&еглед…" },
            { TXT_CANCEL, L"Отказ" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Не може да се зареди MediaInfo.dll (грешка на Windows %lu). Използвайте 32-битова DLL, "
                L"съвместима с тази версия на Windows."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Не може да се зареди libcurl.dll (грешка на Windows %lu). Изберете 32-битова библиотека, "
                L"съвместима с тази версия на Windows."
            },
            { TXT_CLOSE_ALL, L"Затвори &всички" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Копирай &адреса" },
            { TXT_COPY_INFORMATION, L"Копирай &информацията" },
            { TXT_DLL_FILES, L"Динамични библиотеки" },
            { TXT_EXIT, L"&Изход\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Вградени библиотеки MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Вградени библиотеки libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Експортирай отчет" },
            { TXT_FONT_ANTIALIASING, L"&Изглаждане на шрифта:" },
            { TXT_GIF_EXPORT_FAILED,
                L"Експортирането в GIF е неуспешно. GIF без загуби изисква най-много 256 цвята."
            },
            { TXT_FONT_ITALIC, L"Курсив" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED,
                L"Експортирането в JPEG е неуспешно. Необходим е работещ JPEG кодер на GDI+."
            },
            { TXT_LICENSE_UNAVAILABLE, L"Ресурсът на лиценза не е достъпен." },
            { TXT_MEDIA_FILES, L"Мултимедийни файлове" },
            { TXT_APPLICATION_DESCRIPTION, L"Програма за преглед на мултимедийна информация" },
            { TXT_HELP_TITLE, L"MediaInfo — Помощ" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo не можа да инициализира анализа на файла." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo не може да отвори или разпознае този файл." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"&Път до MediaInfo.dll:" },
            { TXT_MEDIALIB_REQUIRED, L"MediaInfo.dll не е заредена. Изберете я от Опции > Предпочитания." },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll не е заредена." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Не може да се зареди съвместима външна или вградена MediaInfo.dll. Изберете я от Опции > "
                L"Предпочитания."
            },
            { TXT_ANTIALIASING_NONE, L"Няма" },
            { TXT_OK, L"OK" },
            { TXT_OPEN_TITLE, L"Отвори мултимедийни файлове" },
            { TXT_PLATFORM, L"Целева платформа:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Предпочитания" },
            { TXT_READY, L"Готов" },
            { TXT_FONT_REGULAR, L"Обикновен" },
            { TXT_REPORT_LANGUAGE, L"Език на о&тчета:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Езикови таблици за отчети" },
            { TXT_SELECT_MEDIALIB, L"Преглед: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Преглед: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH, L"Изберете съществуващ мултимедиен файл с път, по-къс от MAX_PATH." },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Изберете съществуващи файлове с пътища, по-къси от MAX_PATH." },
            { TXT_SELECT_CURL, L"Преглед: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Текстов документ ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"BMP изображението не може да се запише. Проверете целта, свободната памет и мястото на "
                L"диска."
            },
            { TXT_LIBRARY_WORKER_START_FAILED,
                L"Процесът на библиотеката не може да се стартира (грешка на Windows %lu)."
            },
            { TXT_REPORT_COPY_FAILED, L"Отчетът на MediaInfo не може да се копира в паметта." },
            { TXT_VIEWER_CREATE_FAILED, L"Прозорецът на MediaInfo не може да се създаде." },
            { TXT_MEDIALIB_PATH_INVALID, L"Пътят до MediaInfo.dll е невалиден или твърде дълъг." },
            { TXT_PNG_EXPORT_FAILED,
                L"PNG изображението не може да се запише. Проверете целта, свободната памет и мястото на "
                L"диска."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"TIFF изображението не може да се запише. Проверете целта, свободната памет и мястото на "
                L"диска."
            },
            { TXT_COPY_URL_FAILED, L"URL адресът не можа да се копира в клипборда." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"Програмата за преглед Win32 изисква 32-битова %s. Изберете библиотеката x86/i386."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Вградената библиотека не може да се запише в AppData, потребителския профил, Program Files "
                L"или временната папка."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED,
                L"Разархивирането или CRC проверката на библиотеката е неуспешно."
            },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Ресурсът на вградената библиотека е невалиден." },
            { TXT_CURL_FILENAME_INVALID,
                L"Библиотеката трябва да се казва libcurl.dll, за да я използва MediaInfo."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Диалоговият прозорец за файлове не можа да се отвори." },
            { TXT_FILE_DIALOG_SELECTION_FAILED,
                L"Избраните файлове не можаха да се получат от диалоговия прозорец."
            },
            { TXT_RECENT_FILE_MISSING,
                L"Файлът „%s“ вече не съществува.\n\nДа бъде ли премахнат този запис от списъка с последни "
                L"файлове?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Файлът вече не е достъпен:\n\n%s\n\nДа бъде ли премахнат този запис от списъка с последни "
                L"файлове?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Информацията не можа да се копира в клипборда." },
            { TXT_CURL_PATH_INVALID, L"Пътят до libcurl.dll е невалиден или твърде дълъг." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Библиотеката не върна версия на MediaInfo." },
            { TXT_CURL_EXPORTS_MISSING,
                L"Библиотеката не експортира функциите curl, необходими за MediaInfo."
            },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"Библиотеката не експортира необходимите Unicode функции на MediaInfo."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Процесът на библиотеката се провали при %s (код 0x%08lX). Изберете съвместима DLL от "
                L"Опции > Предпочитания."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Процесът на библиотеката не отговаря при %s. Изберете съвместима DLL от Опции > "
                L"Предпочитания."
            },
            { TXT_PREFERENCES_SAVE_FAILED, L"Настройките са приложени, но не са записани в регистъра." },
            { TXT_REPORT_START_FAILED, L"Недостатъчна памет за стартиране на отчета." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Изображението на отчета не може да се създаде." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Езиковата таблица не може да се зареди. Изберете валиден "
                L"MediaInfo CSV файл в UTF-8 или UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"Нишката на отчета не може да се стартира." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"Избраната MediaInfo.dll отхвърли езика на отчета." },
            { TXT_INVALID_WINDOWS_DLL, L"Избраният файл не е валидна Windows DLL." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Избраният формат на изображение не се поддържа." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Текстовият отчет не може да се запише. Проверете целта и свободното място на диска."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Сайтът не може да се отвори в браузъра по подразбиране." },
            { TXT_TOO_MANY_FILES, L"Избрани са твърде много файлове. Отваряйте по-малки групи." },
            { TXT_LIBRARY_PATH_HINT,
                L"Използвайте 32-битови библиотеки, съвместими с вашата версия на Windows. Оставете пътищата "
                L"празни за автоматично търсене. MediaInfoLib v0.7.60 не използва libcurl.dll."
            },
            { TXT_VERSION, L"Версия" },
            { TXT_WEBSITE_TOOLTIP, L"Отвори уебсайта %s" },
            { TXT_WAITING_FOR_REPORT, L"Изчакване на завършването на текущия отчет." },
            { TXT_WEBSITE_LABEL, L"Уебсайт:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"копиране на отчета MediaInfo" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"Път &до libcurl.dll:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"зареждане на MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"зареждане на libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"освобождаване на MediaInfo.dll" },
            { TXT_APPLY, L"При&ложи" },
            { TXT_TAB_NAME_LENGTH, L"Дъл&жина на името на раздела:" },
            { TXT_TITLE_NAME_LENGTH, L"&Дължина на заглавието:" },
            { TXT_RECENT_FILES, L"Скорошни файлове:" },
            { TXT_CLEAR_RECENT_FILES, L"Из&чисти" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"Дължината на името на раздела трябва да бъде от 8 до 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"Дължината на името в заглавието трябва да бъде от 8 до 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Списъкът с последни файлове е изчистен, но не можа да се запише в регистъра."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"Зат&варяне на разделите с двойно щракване" },
            { TXT_CLOSE_TAB_CONTEXT, L"Затвори &раздела" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"Р&азрешаване на няколко екземпляра" },
            { TXT_INSTANCE_FORWARD_FAILED,
                L"Файловете не можаха да бъдат предадени на работещия екземпляр на MediaInfo."
            },
            { TXT_LOADING, L"Зареждане…" },
            { TXT_LOADING_FILE, L"Зареждане на файла %s…" },
            { TXT_APPLICATION_HELP,
                L"ФАЙЛОВЕ И РАЗДЕЛИ\r\nПрограма за Windows x86 за преглед на отчети от MediaInfo.dll. "
                L"Всеки файл има отделен раздел само за четене. Отваряйте с Ctrl+O или чрез плъзгане. "
                L"Повторното отваряне избира съществуващия раздел. Ctrl+W или средният бутон на мишката "
                L"затваря раздел; Затвори всички затваря всички. Менюто Файл помни осем скорошни файла. "
                L"Контекстното меню на заглавката на раздел съдържа Затвори раздела. В Предпочитания "
                L"включете Затваряне на разделите с двойно щракване, за да затваряте раздел с двойно "
                L"щракване върху заглавката му. Опцията е изключена по подразбиране и се запазва. Двойно "
                L"щракване в текста на отчета избира дума. Тройно щракване избира логически ред. "
                L"Плъзгането разширява избора по думи или редове.\r\nОтвори папка… отваря файловете "
                L"непосредствено в избраната папка, всеки в собствен раздел. Подпапките не се "
                L"включват.\r\nОтвори и Отвори папка споделят последната избрана папка. Експортът запомня "
                L"отделна папка, по подразбиране Документи. Разширеният режим показва допълнителни полета "
                L"в отчета.\r\nИзвестни формати / Известни кодеци / Известни параметри — "
                L"MediaInfo.dll.\r\nПълен анализ проверява целия файл и може да отнеме повече време. Тези "
                L"опции за отчет и Ниво на проследяване принадлежат на всеки раздел; промяната опреснява "
                L"само активния раздел. Последната ръчно избрана комбинация се запазва за нови раздели и "
                L"следващото стартиране. Съвпадащият кеширан отчет се използва повторно, докато файлът "
                L"остава непроменен.\r\nНиво на проследяване: 0 / 5 / 9 / 10.\r\nФайл > Настройка на "
                L"страницата… отваря настройките за хартия, ориентация и полета за текущата сесия. Печат… "
                L"(Ctrl+P) отваря системния диалог за печат; Windows 11 предоставя визуализация, а "
                L"Windows 10 и по-старите запазват класическия диалог. Ctrl+P отпечатва активния раздел "
                L"на главния прозорец или текстовото поле на Помощ или За програмата според това кой "
                L"прозорец има фокуса. Отчетите използват избрания шрифт на отчета, Помощ системния шрифт "
                L"за диалози, а За програмата шрифта на своето текстово поле. Ако няма отворени раздели, "
                L"но Помощ е отворена, Настройка на страницата… и Печат… остават достъпни; Печат… "
                L"отпечатва помощта. Помощ използва диалога за печат на главния прозорец; повторно Ctrl+P "
                L"в Помощ извежда същия диалог на преден план. Дългите редове се пренасят, а текстът се "
                L"разделя на страници. Печатът се изпълнява във фонов режим.\r\nПлъзнете един или повече "
                L"файлове в прозореца, върху иконата на EXE или неговия пряк път или подайте пътищата им "
                L"от командния ред. Ако не са разрешени няколко екземпляра, файловете се отварят във вече "
                L"работещия прозорец.\r\nЛявата част на лентата на състоянието показва пътищата до "
                L"файловете и хода на зареждането, а дясната — версията на заредената MediaInfo.dll. "
                L"Дългите пътища се съкращават с многоточие според наличното място.\r\n\r\n"
                L"ЕКСПОРТИРАНЕ\r\nTXT, BMP, GIF, JPEG, PNG, TIFF и WebP се показват според наличността. "
                L"Последната папка и формат за експорт се запомнят.\r\nTXT предлага ANSI, UTF-8, UTF-8 с "
                L"BOM, UTF-16 BE с BOM и UTF-16 LE с BOM. По подразбиране е избрана втората опция, UTF-8 "
                L"без BOM. Запазват се целият текст на отчета и оригиналните краища на редовете.\r\n\r\n"
                L"ХЕДЪР ФАЙЛ\r\nМенюто Инструменти е четвъртото в лентата с менюта. Неговата команда "
                L"Хедър файл… отваря един входен файл независимо от разделите на отчета и копира първите "
                L"му 524288 байта (512 KiB). По-къс файл се копира изцяло; празен файл произвежда празен "
                L"изход. Това е обикновено четене на двоичен файл, без анализ на MediaInfo или изискване "
                L"за MediaInfo.dll. Инструментът оставя разделите на отчета и списъка с последните "
                L"файлове на програмата непроменени.\r\n\r\nСлед прочитане диалоговият прозорец Запиши "
                L"като започва в папката на входния файл и предлага video.mp4.header за video.mp4: "
                L".header се добавя към пълното оригинално име. Можете да промените както името, така и "
                L"целевата папка. Анулирането на който и да е диалогов прозорец не води до изход. "
                L"Замяната на съществуваща дестинация изисква потвърждение. Входният файл остава "
                L"непроменен; неуспешно запазване запазва предишната дестинация. За отваряне и записване "
                L"се използват най-новите системни диалогови прозорци, налични в съответната версия на "
                L"Windows.\r\n\r\nПри стартиране на приложението инструментът взема първоначалната си "
                L"входна папка от Файл > Отвори. Ако няма запазена папка, Windows избира първоначалното "
                L"местоположение. След като бъде избран входен файл, инструментът запомня собствената си "
                L"папка само докато приложението излезе, дори ако Запиши като е отменено. Нито променя "
                L"папките, използвани от Отвори и Експортирай, нито запазва собствената си папка в "
                L"настройките на приложението. Всеки диалогов прозорец Запиши като започва в папката на "
                L"текущо избрания входен файл, независимо от предишната дестинация за запис.\r\n\r\n"
                L"ПРЕДПОЧИТАНИЯ И ЕЗИЦИ\r\nПредпочитанията (Опции > Предпочитания, Ctrl+G) съдържат "
                L"пътища до библиотеки, шрифт на отчета, изглаждане и езици. Интерфейсът има 36 варианта "
                L"и първоначално следва Windows. Отчетите винаги използват по подразбиране оригиналния "
                L"английски на библиотеката, независимо от Windows и интерфейса. Това се променя само "
                L"ръчно: английски, 37 превода или собствена таблица MediaInfo CSV. OK или Приложи "
                L"потвърждава промените; Отказ отхвърля чакащите промени. Предпочитанията задават "
                L"ограничението за името на раздела (по подразбиране 80) и изчистват списъка със скорошни "
                L"файлове. Дългите имена запазват началото, края и разширението с многоточие по средата. "
                L"Изчисти премахва списъка с последни файлове веднага, дори ако след това затворите "
                L"предпочитанията с Отказ.\r\n\r\nЗаглавието на главния прозорец показва активния файл във "
                L"вида име на файл — MediaInfo. В предпочитанията дължината на името в заглавието може да се "
                L"зададе отделно от 8 до 255 знака (по подразбиране 40). По-дългите имена се съкращават със "
                L"същото многоточие в средата, като разширението се запазва. Без отворени раздели заглавието "
                L"е MediaInfo.\r\n\r\nБИБЛИОТЕКИ И ПРОЗОРЦИ\r\nПрограмата включва MediaInfo "
                L"26.10, 21.03 и 0.7.60, изпробвани от най-новата след външните библиотеки. Двете по-нови "
                L"версии имат подходящ libcurl; 0.7.60 никога не го разархивира. Положението на прозореца "
                L"се запазва. По подразбиране е разрешен само един екземпляр, а следващите стартирания "
                L"изпращат файловете към отворения прозорец. В предпочитанията може да се разрешат "
                L"няколко екземпляра. При няколко прозореца само първият прозорец на всеки тип прозорец "
                L"възстановява запазената позиция; останалите възстановяват само размера.\r\n\r\n"
                L"Редактиране > Намери (Ctrl+F) търси в активния раздел на отчета или текстовото поле на "
                L"Помощ или За програмата според това кой прозорец има фокуса. Прозорецът за търсене "
                L"запазва последния избран източник, докато самият той има фокуса. F3 повтаря търсенето, "
                L"а Shift+F3 обръща посоката му. При достигане на края на текста търсенето продължава от "
                L"другия край. Опции > Пренасяне на нов ред засяга само активния раздел; отметката следва "
                L"избрания раздел. Прозорецът за търсене може да се минимизира и да се променя ширината "
                L"му; позицията и настройката Винаги отгоре се запомнят. До 30 текста за търсене с "
                L"техните опции се пазят само до затварянето на приложението. Опциите за начало и край се "
                L"отнасят за логически редове. Регулярните изрази използват синтаксиса на PCRE2. "
                L"Останалите команди в менюто Редактиране се отнасят за активния раздел на отчета. Enter "
                L"стартира търсенето, а Shift+Enter обръща избраната посока. „Различавай главни и малки "
                L"букви“ различава главни и малки букви; „Търси назад“ търси към началото на текста. "
                L"Избирането на запис от историята възстановява всичките пет опции за търсене, "
                L"включително състоянието на режима за регулярни изрази; „Винаги отгоре“ е независима "
                L"опция. „Регулярен израз“ изключва „Редът започва с“ и „Редът завършва с“. Когато и "
                L"двете опции за краищата на реда са включени, е достатъчно съвпадение на единия край. "
                L"„Пренасяне на нов ред“ променя само показването."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"WebP изображението не може да се запише. Проверете целта, свободната памет и мястото на "
                L"диска."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Текстов документ UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Текстов документ UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Текстов документ UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Текстов документ UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Отчетът не може да се запише с тази кодировка без загуба на знаци. Изберете друга текстова "
                L"кодировка."
            },
            { TXT_OPEN_FOLDER, L"Отвори &папка…" },
            { TXT_OPEN_FOLDER_TITLE, L"Отвори папка" },
            { TXT_FOLDER_READ_FAILED, L"Папката не може да бъде прочетена:\n\n%s\n\nГрешка на Windows %lu." },
            { TXT_ADVANCED_MODE, L"&Разширен режим" },
            { TXT_REPORT_DETAIL_REJECTED,
                L"Избраната MediaInfo.dll отхвърли настройката за подробности на отчета."
            },
            { TXT_KNOWN_FORMATS, L"Известни &формати" },
            { TXT_KNOWN_CODECS, L"Известни &кодеци" },
            { TXT_KNOWN_PARAMETERS, L"Известни п&араметри" },
            { TXT_KNOWN_FORMATS_TITLE, L"Известни формати" },
            { TXT_KNOWN_CODECS_TITLE, L"Известни кодеци" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Известни параметри" },
            { TXT_KNOWN_INFO_FAILED, L"Библиотеката не върна заявената информация." },
            { TXT_FULL_PARSING, L"Пълен &анализ" },
            { TXT_PARSING_REJECTED, L"Избраната MediaInfo.dll отхвърли настройката за анализ." },
            { TXT_TRACE_LEVEL_0, L"Ниво на проследяване &0" },
            { TXT_TRACE_LEVEL_5, L"Ниво на проследяване &5" },
            { TXT_TRACE_LEVEL_9, L"Ниво на проследяване &9" },
            { TXT_TRACE_LEVEL_10, L"Ниво на проследяване &10" },
            { TXT_PAGE_SETUP, L"&Настройка на страницата…" },
            { TXT_PAGE_SETUP_FAILED, L"Настройката на страницата не може да бъде отворена." },
            { TXT_PRINT, L"Пе&чат…\tCtrl+P" },
            { TXT_PRINTING, L"Печат…" },
            { TXT_PRINT_FAILED,
                L"Текстът не може да бъде отпечатан. Проверете принтера, настройките му и наличната памет."
            },
            { TXT_TOOLS_MENU, L"&Инструменти" },
            { TXT_CREATE_HEADER, L"&Хедър файл…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Хедър файл - Отвори" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Хедър файл - Запиши като" },
            { TXT_HEADER_FORMAT, L"Файл със заглавна част (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Заглавната част на файла не може да бъде прочетена:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Файлът със заглавна част не може да бъде записан:\n\n%s" },
            { TXT_COPY, L"&Копирай" },
            { TXT_COPY_FILE_NAME, L"Копирай &името на файла" },
            { TXT_COPY_FULL_PATH, L"Копирай пълния п&ът" },
            { TXT_LAUNCH_FILE, L"&Стартирай файла" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"По&кажи в папката" },
            { TXT_EDIT_MENU, L"&Редактиране" },
            { TXT_WORD_WRAP, L"Пр&енасяне на нов ред" },
            { TXT_WORD_WRAP_FAILED, L"Пренасянето на нов ред не може да бъде променено." },
            { TXT_COPY_SELECTION, L"&Копирай\tCtrl+C" },
            { TXT_SELECT_ALL, L"Избери &всичко\tCtrl+A" },
            { TXT_FIND_MENU, L"&Намери…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Намери &следващ\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Намери &предишен\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Намиране" },
            { TXT_FIND_WHAT, L"&Търси:" },
            { TXT_FIND_NEXT, L"Намери &следващ" },
            { TXT_FIND_MATCH_CASE, L"Различавай &главни и малки букви" },
            { TXT_FIND_BACKWARD, L"Търси &назад" },
            { TXT_FIND_TOPMOST, L"Винаги &отгоре" },
            { TXT_FIND_STARTS_WITH, L"Редът за&почва с" },
            { TXT_FIND_ENDS_WITH, L"Редът за&вършва с" },
            { TXT_FIND_REGEX, L"&Регулярен израз" },
            { TXT_FIND_NOT_FOUND, L"Указаният текст не е намерен." },
            { TXT_FIND_FAILED, L"Търсенето не можа да бъде завършено." },
            { TXT_FIND_REGEX_ERROR, L"Грешка в регулярния израз:\r\n\r\n%s" },
        }
    },
    {
        LANG_MK,
        {
            { TXT_LANGUAGE_NAME, L"Македонски" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nВеб-страница: " },
            { TXT_FILE_OPEN_FAILED, L"Не може да се отвори %s. Проверете ги патеката и дозволите." },
            { TXT_BROWSE_DLL, L"П&регледај…" },
            { TXT_BROWSE_REPORT, L"Пре&гледај…" },
            { TXT_CLOSE, L"&Затвори" },
            { TXT_CLOSE_TAB, L"&Затвори\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"&Стандардно" },
            { TXT_EXPORT, L"&Извези…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Датотека" },
            { TXT_REPORT_FONT, L"&Фонт на извештајот:" },
            { TXT_HELP_MENU, L"&Помош" },
            { TXT_HELP, L"&Помош\tF1" },
            { TXT_LANGUAGE, L"&Јазик:" },
            { TXT_OPEN_WEBSITE, L"&Отвори во стандардниот прелистувач" },
            { TXT_OPEN, L"&Отвори…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Опции" },
            { TXT_PREFERENCES_MENU, L"&Претпочитувања…\tCtrl+G" },
            { TXT_ABOUT, L"&За програмата" },
            { TXT_ABOUT_TITLE, L"За програмата %ls" },
            { TXT_ALL_FILES, L"Сите датотеки" },
            { TXT_FONT_BOLD, L"Задебелено" },
            { TXT_FONT_BOLD_ITALIC, L"Задебелено + Курзив" },
            { TXT_BROWSE_CURL, L"Пр&егледај…" },
            { TXT_CANCEL, L"Откажи" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Не може да се вчита MediaInfo.dll (грешка на Windows %lu). Користете 32-битна DLL "
                L"компатибилна со оваа верзија на Windows."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Не може да се вчита libcurl.dll (грешка на Windows %lu). Изберете 32-битна библиотека "
                L"компатибилна со оваа верзија на Windows."
            },
            { TXT_CLOSE_ALL, L"Затвори ги &сите" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Копирај ја &адресата" },
            { TXT_COPY_INFORMATION, L"Копирај ги &информациите" },
            { TXT_DLL_FILES, L"Динамички библиотеки" },
            { TXT_EXIT, L"Из&лез\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Вградени библиотеки MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Вградени библиотеки libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Извези извештај" },
            { TXT_FONT_ANTIALIASING, L"Из&мазнување на фонтот:" },
            { TXT_GIF_EXPORT_FAILED, L"Извозот во GIF не успеа. GIF без загуби бара најмногу 256 бои." },
            { TXT_FONT_ITALIC, L"Курзив" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED, L"Извозот во JPEG не успеа. Потребен е функционален GDI+ JPEG кодер." },
            { TXT_LICENSE_UNAVAILABLE, L"Ресурсот за лиценцата не е достапен." },
            { TXT_MEDIA_FILES, L"Медиумски датотеки" },
            { TXT_APPLICATION_DESCRIPTION, L"Прегледувач на медиумски информации" },
            { TXT_HELP_TITLE, L"MediaInfo — Помош" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo не можеше да ја иницијализира анализата на "
                L"датотеката." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo не може да ја отвори или препознае датотеката." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"&Патека до MediaInfo.dll:" },
            { TXT_MEDIALIB_REQUIRED, L"MediaInfo.dll не е вчитана. Изберете ја во Опции > Претпочитувања." },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll не е вчитана." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Не може да се вчита компатибилна надворешна или вградена MediaInfo.dll. Изберете ја во "
                L"Опции > Претпочитувања."
            },
            { TXT_ANTIALIASING_NONE, L"Нема" },
            { TXT_OK, L"Во ред" },
            { TXT_OPEN_TITLE, L"Отвори медиумски датотеки" },
            { TXT_PLATFORM, L"Целна платформа:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Претпочитувања" },
            { TXT_READY, L"Подготвен" },
            { TXT_FONT_REGULAR, L"Обично" },
            { TXT_REPORT_LANGUAGE, L"Јазик на &извештајот:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Јазични табели за извештаи" },
            { TXT_SELECT_MEDIALIB, L"Прегледај: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Прегледај: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH,
                L"Изберете постојна медиумска датотека со патека пократка од MAX_PATH."
            },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Изберете постојни датотеки со патеки пократки од MAX_PATH." },
            { TXT_SELECT_CURL, L"Прегледај: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Текстуален документ ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"BMP сликата не може да се зачува. Проверете ги целта, слободната меморија и просторот на "
                L"дискот."
            },
            { TXT_LIBRARY_WORKER_START_FAILED,
                L"Процесот на библиотеката не може да се стартува (грешка на Windows %lu)."
            },
            { TXT_REPORT_COPY_FAILED, L"Извештајот MediaInfo не може да се копира во меморијата." },
            { TXT_VIEWER_CREATE_FAILED, L"Прегледувачот MediaInfo не може да се создаде." },
            { TXT_MEDIALIB_PATH_INVALID, L"Патеката до MediaInfo.dll е неважечка или предолга." },
            { TXT_PNG_EXPORT_FAILED,
                L"PNG сликата не може да се зачува. Проверете ги целта, слободната меморија и просторот на "
                L"дискот."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"TIFF сликата не може да се зачува. Проверете ги целта, слободната меморија и просторот на "
                L"дискот."
            },
            { TXT_COPY_URL_FAILED, L"URL-адресата не можеше да се копира во таблата со исечоци." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"Прегледувачот Win32 бара 32-битна %s. Изберете ја библиотеката x86/i386."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Вградената библиотека не може да се запише во AppData, корисничкиот профил, Program Files "
                L"или привремената папка."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED,
                L"Распакувањето или CRC проверката на библиотеката не успеа."
            },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Ресурсот на вградената библиотека е неважечки." },
            { TXT_CURL_FILENAME_INVALID,
                L"Библиотеката мора да се вика libcurl.dll за да ја користи MediaInfo."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Дијалогот за датотеки не можеше да се отвори." },
            { TXT_FILE_DIALOG_SELECTION_FAILED,
                L"Избраните датотеки не можеа да се добијат од дијалогот за датотеки."
            },
            { TXT_RECENT_FILE_MISSING,
                L"Датотеката „%s“ веќе не постои.\n\nДа се отстрани оваа ставка од списокот на неодамнешни "
                L"датотеки?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Датотеката веќе не е достапна:\n\n%s\n\nДа се отстрани оваа ставка од списокот на "
                L"неодамнешни датотеки?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Информациите не можеа да се копираат во таблата со исечоци." },
            { TXT_CURL_PATH_INVALID, L"Патеката до libcurl.dll е неважечка или предолга." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Библиотеката не врати верзија на MediaInfo." },
            { TXT_CURL_EXPORTS_MISSING,
                L"Библиотеката не ги извезува функциите curl потребни за MediaInfo."
            },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"Библиотеката не ги извезува потребните Unicode функции на MediaInfo."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Процесот на библиотеката не успеа при %s (код 0x%08lX). Изберете компатибилна DLL во "
                L"Опции > Претпочитувања."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Процесот на библиотеката не одговара при %s. Изберете компатибилна DLL во Опции > "
                L"Претпочитувања."
            },
            { TXT_PREFERENCES_SAVE_FAILED, L"Поставките се применети, но не се зачувани во регистарот." },
            { TXT_REPORT_START_FAILED, L"Нема доволно меморија за стартување на извештајот." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Сликата на извештајот не може да се создаде." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Јазичната табела не може да се вчита. Изберете важечка "
                L"MediaInfo CSV датотека во UTF-8 или UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"Нишката на извештајот не може да се стартува." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"Избраната MediaInfo.dll го одби јазикот на извештајот." },
            { TXT_INVALID_WINDOWS_DLL, L"Избраната датотека не е важечка Windows DLL." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Избраниот формат на слика не е поддржан." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Текстуалниот извештај не може да се зачува. Проверете ги целта и слободниот простор на "
                L"дискот."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Веб-страницата не може да се отвори во стандардниот прелистувач." },
            { TXT_TOO_MANY_FILES, L"Избрани се премногу датотеки. Отворајте помали групи." },
            { TXT_LIBRARY_PATH_HINT,
                L"Користете 32-битни библиотеки компатибилни со вашата верзија на Windows. Оставете ги "
                L"патеките празни за автоматско пребарување. MediaInfoLib v0.7.60 не користи libcurl.dll."
            },
            { TXT_VERSION, L"Верзија" },
            { TXT_WEBSITE_TOOLTIP, L"Отвори ја веб-страницата %s" },
            { TXT_WAITING_FOR_REPORT, L"Се чека завршувањето на тековниот извештај." },
            { TXT_WEBSITE_LABEL, L"Веб-страница:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"копирање на извештајот MediaInfo" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"Патека &до libcurl.dll:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"вчитување на MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"вчитување на libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"ослободување на MediaInfo.dll" },
            { TXT_APPLY, L"Приме&ни" },
            { TXT_TAB_NAME_LENGTH, L"До&лжина на името на картичката:" },
            { TXT_TITLE_NAME_LENGTH, L"&Должина на насловот:" },
            { TXT_RECENT_FILES, L"Неодамнешни датотеки:" },
            { TXT_CLEAR_RECENT_FILES, L"Ис&чисти" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"Должината на името на картичката мора да биде од 8 до 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"Должината на името во насловот мора да биде од 8 до 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Списокот на неодамнешни датотеки е исчистен, но не можеше да се зачува во регистарот."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"&Затворај картички со двоен клик" },
            { TXT_CLOSE_TAB_CONTEXT, L"Затвори &картичка" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"Д&озволи повеќе инстанци" },
            { TXT_INSTANCE_FORWARD_FAILED,
                L"Датотеките не можеа да се предадат на активната инстанца на MediaInfo."
            },
            { TXT_LOADING, L"Се вчитува…" },
            { TXT_LOADING_FILE, L"Се вчитува датотеката %s…" },
            { TXT_APPLICATION_HELP,
                L"ДАТОТЕКИ И КАРТИЧКИ\r\nИзворен Windows x86 прегледувач за извештаи од MediaInfo.dll. "
                L"Секоја датотека има своја картичка само за читање. Отворете со Ctrl+O или со влечење. "
                L"Повторното отворање ја избира постојната картичка. Ctrl+W или средното копче на "
                L"глувчето затвора картичка; Затвори ги сите ги затвора сите. Менито Датотека памети осум "
                L"неодамнешни датотеки. Контекстното мени на заглавието на картичката содржи Затвори "
                L"картичка. Во Претпочитувања вклучете Затворај картички со двоен клик за да затворате "
                L"картичка со двоен клик на нејзиното заглавие. Опцијата е стандардно исклучена и се "
                L"зачувува. Двоен клик во текстот на извештајот избира збор. Троен клик избира логички "
                L"ред. Влечењето го проширува изборот по зборови или редови.\r\nОтвори папка… ги отвора "
                L"датотеките непосредно во избраната папка, секоја во сопствена картичка. Потпапките не "
                L"се вклучени.\r\nОтвори и Отвори папка ја делат последната избрана папка. Извозот памети "
                L"посебна папка, стандардно Документи. Напредниот режим прикажува дополнителни полиња во "
                L"извештајот.\r\nПознати формати / Познати кодеци / Познати параметри — MediaInfo.dll.\r\n"
                L"Целосна анализа ја испитува целата датотека и може да потрае подолго. Овие опции за "
                L"извештај и Ниво на следење припаѓаат на секоја картичка; промената ја освежува само "
                L"активната картичка. Последната рачно избрана комбинација е зачувана за нови картички и "
                L"следното стартување. Соодветниот кеширан извештај повторно се користи додека датотеката "
                L"останува непроменета.\r\nНиво на следење: 0 / 5 / 9 / 10.\r\nДатотека > Поставување на "
                L"страницата… ги отвора поставките за хартија, ориентација и маргини за тековната сесија. "
                L"Печати… (Ctrl+P) го отвора системскиот дијалог за печатење; Windows 11 нуди преглед "
                L"пред печатење, а Windows 10 и постарите го задржуваат класичниот дијалог. Ctrl+P ја "
                L"печати активната картичка на главниот прозорец или текстуалното поле во Помош или За "
                L"програмата, зависно од тоа кој прозорец е во фокус. Извештаите го користат избраниот "
                L"фонт за извештаи, Помош системскиот фонт за дијалози, а За програмата фонтот на своето "
                L"текстуално поле. Ако нема отворени картички, но Помош е отворена, Поставување на "
                L"страницата… и Печати… остануваат достапни; Печати… ја печати помошта. Помош го користи "
                L"дијалогот за печатење на главниот прозорец; повторно Ctrl+P во Помош го носи истиот "
                L"дијалог во преден план. Долгите редови се пренесуваат, а текстот се дели на страници. "
                L"Печатењето се извршува во заднина.\r\nПовлечете една или повеќе датотеки во прозорецот, "
                L"врз иконата на EXE или неговата кратенка или задајте ги патеките преку командната "
                L"линија. Ако не се дозволени повеќе инстанци, датотеките се отвораат во веќе отворениот "
                L"прозорец.\r\nЛевиот дел од статусната лента ги прикажува патеките до датотеките и текот "
                L"на вчитувањето, а десниот верзијата на вчитаната MediaInfo.dll. Долгите патеки се "
                L"скратуваат со три точки според достапниот простор.\r\n\r\nИЗВОЗ\r\nTXT, BMP, GIF, JPEG, "
                L"PNG, TIFF и WebP се прикажуваат кога се достапни. Се паметат последната папка и формат "
                L"за извоз.\r\nTXT нуди ANSI, UTF-8, UTF-8 со BOM, UTF-16 BE со BOM и UTF-16 LE со BOM. "
                L"Стандардно е избрана втората ставка, UTF-8 без BOM. Се зачувуваат целиот текст на "
                L"извештајот и изворните краеви на редовите.\r\n\r\nСОЗДАЈ ДАТОТЕКА СО ЗАГЛАВИЕ\r\nМенито "
                L"Алатки е четврто на лентата со менија. Неговата команда Создај датотека со заглавие… "
                L"отвора една изворна датотека независно од картичките за извештај и ги копира првите "
                L"524288 бајти (512 KiB). Пократка датотека се копира во целост; празна датотека "
                L"произведува празен излез. Ова е обично читање на бинарни датотеки, без анализа на "
                L"MediaInfo или барање за MediaInfo.dll. Алатката ги остава непроменети картичките за "
                L"извештаи и списокот со неодамнешни датотеки на програмата.\r\n\r\nПо читањето, "
                L"дијалогот Зачувај како започнува во папката на изворната датотека и предлага "
                L"video.mp4.header за video.mp4: .header се додава на целосното оригинално име. Можете да "
                L"ги промените и името и одредишната папка. Откажувањето на било кој дијалог не запишува "
                L"излез. Замена на постоечка дестинација бара потврда. Изворот останува непроменет; "
                L"неуспешно зачувување ја зачувува претходната дестинација. За отворање и зачувување се "
                L"користат најновите системски дијалози достапни во таа верзија на Windows.\r\n\r\nПри "
                L"стартување на апликацијата, алатката ја зема својата почетна папка за внесување од "
                L"Датотека > Отвори. Ако ниедна папка не е зачувана, Windows ја избира почетната "
                L"локација. Откако ќе се избере влезна датотека, алатката ја памети сопствената папка "
                L"само додека апликацијата не излезе, дури и ако Зачувај како е откажана. Ниту ги менува "
                L"папките што ги користат Отвори и Извези ниту ја зачувува сопствената папка во "
                L"поставките на апликацијата. Секој дијалог Зачувај како започнува во папката на "
                L"моментално избраната влезна датотека, без оглед на претходната дестинација за "
                L"зачувување.\r\n\r\nПРЕТПОЧИТУВАЊА И ЈАЗИЦИ\r\nПретпочитувањата (Опции > Претпочитувања, "
                L"Ctrl+G) содржат патеки до библиотеки, фонт на извештајот, измазнување и јазици. "
                L"Интерфејсот има 36 варијанти и првично го следи Windows. Извештаите секогаш стандардно "
                L"го користат изворниот англиски на библиотеката, независно од Windows и интерфејсот. Тоа "
                L"се менува само рачно: англиски, 37 преводи или сопствена MediaInfo CSV табела. Во ред "
                L"или Примени ги потврдува промените; Откажи ги отфрла непотврдените промени. "
                L"Претпочитувањата го одредуваат ограничувањето на должината на името на картичката "
                L"(стандардно 80 знаци) и го чистат списокот на неодамнешни датотеки. Долгите имиња ги "
                L"задржуваат почетокот, крајот и наставката со три точки во средината. Исчисти веднаш го "
                L"отстранува списокот на неодамнешни датотеки, дури и ако потоа ги затворите "
                L"претпочитувањата со Откажи.\r\n\r\nНасловот на главниот прозорец ја прикажува активната "
                L"датотека во облик име на датотека — MediaInfo. Во поставките должината на името во насловот"
                L" може одделно да се постави на 8–255 знаци (стандардно 40). Подолгите имиња се скратуваат "
                L"со истите три точки во средината, со зачувување на наставката. Без отворени картички, "
                L"насловот е MediaInfo.\r\n\r\nБИБЛИОТЕКИ И ПРОЗОРЦИ\r\nПрограмата содржи MediaInfo "
                L"26.10, 21.03 и 0.7.60, испробани од најновата по надворешните библиотеки. Двете понови "
                L"верзии имаат соодветна libcurl; 0.7.60 никогаш не ја отпакува. Положбата на прозорецот "
                L"се зачувува. Стандардно е дозволена само една инстанца, а следните стартувања ги "
                L"испраќаат датотеките до отворениот прозорец. Во претпочитувањата може да се дозволат "
                L"повеќе инстанци. Кога има повеќе прозорци, само првиот прозорец од секој тип прозорец "
                L"ја враќа зачуваната положба; останатите ја враќаат само големината.\r\n\r\nУреди > "
                L"Најди (Ctrl+F) пребарува во активната картичка на извештајот или текстуалното поле во "
                L"Помош или За програмата, зависно од тоа кој прозорец е во фокус. Прозорецот за "
                L"пребарување го задржува последниот избран извор додека самиот е во фокус. F3 го "
                L"повторува пребарувањето, а Shift+F3 ја менува неговата насока. На крајот на текстот "
                L"пребарувањето продолжува од другиот крај. Опции > Пренесување редови важи само за "
                L"активната картичка; ознаката ја следи избраната картичка. Прозорецот за пребарување "
                L"може да се минимизира и да му се менува ширината; положбата и опцијата Секогаш на врвот "
                L"се паметат. До 30 текстови за пребарување со нивните опции се чуваат само до "
                L"затворањето на апликацијата. Опциите за почеток и крај важат за логичките редови. "
                L"Регуларните изрази користат синтакса на PCRE2. Другите команди во менито Уреди важат за "
                L"активната картичка на извештајот. Enter го започнува пребарувањето, а Shift+Enter ја "
                L"превртува избраната насока. „Разликувај големи и мали букви“ разликува големи и мали "
                L"букви; „Барај наназад“ пребарува кон почетокот на текстот. Изборот на запис од "
                L"историјата ги враќа сите пет опции за пребарување, вклучувајќи ја состојбата на режимот "
                L"за регуларни изрази; „Секогаш на врвот“ е независна опција. „Регуларен израз“ ги "
                L"исклучува „Редот почнува со“ и „Редот завршува со“. Кога се вклучени двете опции за "
                L"краевите на редот, доволно е совпаѓање на едниот крај. „Пренесување редови“ го менува "
                L"само приказот."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"WebP сликата не може да се зачува. Проверете ги целта, слободната меморија и просторот на "
                L"дискот."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Текстуален документ UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Текстуален документ UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Текстуален документ UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Текстуален документ UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Извештајот не може да се зачува со ова кодирање без губење знаци. Изберете друго кодирање "
                L"на текстот."
            },
            { TXT_OPEN_FOLDER, L"Отвори &папка…" },
            { TXT_OPEN_FOLDER_TITLE, L"Отвори папка" },
            { TXT_FOLDER_READ_FAILED, L"Папката не може да се прочита:\n\n%s\n\nГрешка на Windows %lu." },
            { TXT_ADVANCED_MODE, L"&Напреден режим" },
            { TXT_REPORT_DETAIL_REJECTED,
                L"Избраната MediaInfo.dll ја одби поставката за деталност на извештајот."
            },
            { TXT_KNOWN_FORMATS, L"Познати &формати" },
            { TXT_KNOWN_CODECS, L"Познати &кодеци" },
            { TXT_KNOWN_PARAMETERS, L"Познати п&араметри" },
            { TXT_KNOWN_FORMATS_TITLE, L"Познати формати" },
            { TXT_KNOWN_CODECS_TITLE, L"Познати кодеци" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Познати параметри" },
            { TXT_KNOWN_INFO_FAILED, L"Библиотеката не ги врати бараните информации." },
            { TXT_FULL_PARSING, L"&Целосна анализа" },
            { TXT_PARSING_REJECTED, L"Избраната MediaInfo.dll ја одби поставката за анализа." },
            { TXT_TRACE_LEVEL_0, L"Ниво на следење &0" },
            { TXT_TRACE_LEVEL_5, L"Ниво на следење &5" },
            { TXT_TRACE_LEVEL_9, L"Ниво на следење &9" },
            { TXT_TRACE_LEVEL_10, L"Ниво на следење &10" },
            { TXT_PAGE_SETUP, L"Пост&авување на страницата…" },
            { TXT_PAGE_SETUP_FAILED, L"Не може да се отвори поставувањето на страницата." },
            { TXT_PRINT, L"Пе&чати…\tCtrl+P" },
            { TXT_PRINTING, L"Печатење…" },
            { TXT_PRINT_FAILED,
                L"Текстот не може да се отпечати. Проверете го печатачот, неговите поставки и достапната "
                L"меморија."
            },
            { TXT_TOOLS_MENU, L"&Алатки" },
            { TXT_CREATE_HEADER, L"Со&здај датотека со заглавие…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Создај датотека со заглавие - Отвори" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Создај датотека со заглавие - Зачувај како" },
            { TXT_HEADER_FORMAT, L"Датотека со заглавие (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Не може да се прочита заглавието на датотеката:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Не може да се зачува датотеката со заглавие:\n\n%s" },
            { TXT_COPY, L"&Копирај" },
            { TXT_COPY_FILE_NAME, L"Копирај го &името на датотеката" },
            { TXT_COPY_FULL_PATH, L"Копирај ја целосната п&атека" },
            { TXT_LAUNCH_FILE, L"С&тартувај датотека" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"П&рикажи во папката" },
            { TXT_EDIT_MENU, L"&Уреди" },
            { TXT_WORD_WRAP, L"П&ренесување редови" },
            { TXT_WORD_WRAP_FAILED, L"Пренесувањето редови не може да се промени." },
            { TXT_COPY_SELECTION, L"&Копирај\tCtrl+C" },
            { TXT_SELECT_ALL, L"Избери &сè\tCtrl+A" },
            { TXT_FIND_MENU, L"&Најди…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Најди сл&едно\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Најди &претходно\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Најди" },
            { TXT_FIND_WHAT, L"&Барај:" },
            { TXT_FIND_NEXT, L"Најди &следно" },
            { TXT_FIND_MATCH_CASE, L"Разликувај големи и &мали букви" },
            { TXT_FIND_BACKWARD, L"Барај на&назад" },
            { TXT_FIND_TOPMOST, L"Секогаш на &врвот" },
            { TXT_FIND_STARTS_WITH, L"Редот &почнува со" },
            { TXT_FIND_ENDS_WITH, L"Редот завршув&а со" },
            { TXT_FIND_REGEX, L"&Регуларен израз" },
            { TXT_FIND_NOT_FOUND, L"Наведениот текст не е пронајден." },
            { TXT_FIND_FAILED, L"Пребарувањето не може да се доврши." },
            { TXT_FIND_REGEX_ERROR, L"Грешка во регуларниот израз:\r\n\r\n%s" },
        }
    },
    {
        LANG_SR,
        {
            { TXT_LANGUAGE_NAME, L"Српски" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nВеб-сајт: " },
            { TXT_FILE_OPEN_FAILED, L"Није могуће отворити %s. Проверите путању и дозволе." },
            { TXT_BROWSE_DLL, L"П&регледај…" },
            { TXT_BROWSE_REPORT, L"Пре&гледај…" },
            { TXT_CLOSE, L"&Затвори" },
            { TXT_CLOSE_TAB, L"&Затвори\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"Подра&зумевано" },
            { TXT_EXPORT, L"&Извези…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Датотека" },
            { TXT_REPORT_FONT, L"&Фонт извештаја:" },
            { TXT_HELP_MENU, L"&Помоћ" },
            { TXT_HELP, L"&Помоћ\tF1" },
            { TXT_LANGUAGE, L"&Језик:" },
            { TXT_OPEN_WEBSITE, L"&Отвори у подразумеваном прегледачу" },
            { TXT_OPEN, L"&Отвори…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Опције" },
            { TXT_PREFERENCES_MENU, L"&Подешавања…\tCtrl+G" },
            { TXT_ABOUT, L"&О програму" },
            { TXT_ABOUT_TITLE, L"О програму %ls" },
            { TXT_ALL_FILES, L"Све датотеке" },
            { TXT_FONT_BOLD, L"Подебљано" },
            { TXT_FONT_BOLD_ITALIC, L"Подебљано + Курзив" },
            { TXT_BROWSE_CURL, L"Пр&егледај…" },
            { TXT_CANCEL, L"Откажи" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Није могуће учитати MediaInfo.dll (грешка система Windows %lu). Користите 32-битну DLL "
                L"компатибилну с овом верзијом система Windows."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Није могуће учитати libcurl.dll (грешка система Windows %lu). Изаберите 32-битну "
                L"библиотеку компатибилну с овом верзијом система Windows."
            },
            { TXT_CLOSE_ALL, L"Затвори &све" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Копирај &адресу" },
            { TXT_COPY_INFORMATION, L"Копирај &податке" },
            { TXT_DLL_FILES, L"Динамичке библиотеке" },
            { TXT_EXIT, L"Из&лаз\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Уграђене библиотеке MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Уграђене библиотеке libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Извези извештај" },
            { TXT_FONT_ANTIALIASING, L"У&мекшавање фонта:" },
            { TXT_GIF_EXPORT_FAILED, L"Извоз GIF није успео. GIF без губитака захтева највише 256 боја." },
            { TXT_FONT_ITALIC, L"Курзив" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED, L"Извоз JPEG није успео. Потребан је исправан GDI+ JPEG кодер." },
            { TXT_LICENSE_UNAVAILABLE, L"Ресурс лиценце није доступан." },
            { TXT_MEDIA_FILES, L"Медијске датотеке" },
            { TXT_APPLICATION_DESCRIPTION, L"Прегледач информација о медијима" },
            { TXT_HELP_TITLE, L"MediaInfo — Помоћ" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo није могао да иницијализује анализу датотеке." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo не може отворити или препознати ову датотеку." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"&Путања до MediaInfo.dll:" },
            { TXT_MEDIALIB_REQUIRED, L"MediaInfo.dll није учитана. Изаберите је у Опције > Подешавања." },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll није учитана." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Није могуће учитати компатибилну спољашњу или уграђену MediaInfo.dll. Изаберите је у "
                L"Опције > Подешавања."
            },
            { TXT_ANTIALIASING_NONE, L"Нема" },
            { TXT_OK, L"У реду" },
            { TXT_OPEN_TITLE, L"Отвори медијске датотеке" },
            { TXT_PLATFORM, L"Циљна платформа:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Подешавања" },
            { TXT_READY, L"Спреман" },
            { TXT_FONT_REGULAR, L"Обично" },
            { TXT_REPORT_LANGUAGE, L"Језик &извештаја:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Језичке табеле извештаја" },
            { TXT_SELECT_MEDIALIB, L"Прегледај: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Прегледај: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH,
                L"Изаберите постојећу медијску датотеку с путањом краћом од MAX_PATH."
            },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Изаберите постојеће датотеке с путањама краћим од MAX_PATH." },
            { TXT_SELECT_CURL, L"Прегледај: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Текстуални документ ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"Није могуће сачувати BMP слику. Проверите одредиште, слободну меморију и простор на диску."
            },
            { TXT_LIBRARY_WORKER_START_FAILED,
                L"Није могуће покренути процес библиотеке (грешка Windows %lu)."
            },
            { TXT_REPORT_COPY_FAILED, L"Није могуће копирати извештај MediaInfo у меморију." },
            { TXT_VIEWER_CREATE_FAILED, L"Није могуће направити прегледач MediaInfo." },
            { TXT_MEDIALIB_PATH_INVALID, L"Путања до MediaInfo.dll није исправна или је предуга." },
            { TXT_PNG_EXPORT_FAILED,
                L"Није могуће сачувати PNG слику. Проверите одредиште, слободну меморију и простор на диску."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"Није могуће сачувати TIFF слику. Проверите одредиште, слободну меморију и простор на диску."
            },
            { TXT_COPY_URL_FAILED, L"Није могуће копирати URL у оставу." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"Прегледач Win32 захтева 32-битну %s. Изаберите библиотеку x86/i386."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Уграђену библиотеку није могуће уписати у AppData, кориснички профил, Program Files или "
                L"привремену фасциклу."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED, L"Распакивање библиотеке или CRC провера није успела." },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Ресурс уграђене библиотеке није исправан." },
            { TXT_CURL_FILENAME_INVALID,
                L"Библиотека се мора звати libcurl.dll да би је MediaInfo могла користити."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Није могуће отворити дијалог за датотеке." },
            { TXT_FILE_DIALOG_SELECTION_FAILED,
                L"Није могуће добити изабране датотеке из дијалога за датотеке."
            },
            { TXT_RECENT_FILE_MISSING,
                L"Датотека „%s“ више не постоји.\n\nУклонити ову ставку са списка недавних датотека?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Датотека више није доступна:\n\n%s\n\nУклонити ову ставку са списка недавних датотека?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Није могуће копирати податке у оставу." },
            { TXT_CURL_PATH_INVALID, L"Путања до libcurl.dll није исправна или је предуга." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Библиотека није вратила верзију MediaInfo." },
            { TXT_CURL_EXPORTS_MISSING, L"Библиотека не извози функције curl потребне за MediaInfo." },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"Библиотека не извози потребне Unicode функције библиотеке MediaInfo."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Процес библиотеке није успео током %s (код 0x%08lX). Изаберите компатибилну DLL у Опције "
                L"> Подешавања."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Процес библиотеке не одговара током %s. Изаберите компатибилну DLL у Опције > Подешавања."
            },
            { TXT_PREFERENCES_SAVE_FAILED, L"Подешавања су примењена, али нису сачувана у регистру." },
            { TXT_REPORT_START_FAILED, L"Нема довољно меморије за покретање извештаја." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Није могуће направити слику извештаја." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Није могуће учитати језичку табелу. Изаберите исправан "
                L"MediaInfo CSV у UTF-8 или UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"Није могуће покренути нит извештаја." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"Изабрана MediaInfo.dll одбила је језик извештаја." },
            { TXT_INVALID_WINDOWS_DLL, L"Изабрана датотека није исправна Windows DLL." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Изабрани формат слике није подржан." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Није могуће сачувати текстуални извештај. Проверите одредиште и слободан простор на диску."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Није могуће отворити страницу у подразумеваном прегледачу." },
            { TXT_TOO_MANY_FILES, L"Изабрано је превише датотека. Отварајте мање групе." },
            { TXT_LIBRARY_PATH_HINT,
                L"Користите 32-битне библиотеке компатибилне с вашом верзијом система Windows. Оставите "
                L"путање празне за аутоматску претрагу. MediaInfoLib v0.7.60 не користи libcurl.dll."
            },
            { TXT_VERSION, L"Верзија" },
            { TXT_WEBSITE_TOOLTIP, L"Отвори веб-сајт %s" },
            { TXT_WAITING_FOR_REPORT, L"Чекање завршетка тренутног извештаја." },
            { TXT_WEBSITE_LABEL, L"Веб-сајт:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"копирања извештаја MediaInfo" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"Путања &до libcurl.dll:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"учитавања MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"учитавања libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"ослобађања MediaInfo.dll" },
            { TXT_APPLY, L"Приме&ни" },
            { TXT_TAB_NAME_LENGTH, L"Ду&жина назива картице:" },
            { TXT_TITLE_NAME_LENGTH, L"&Дужина наслова:" },
            { TXT_RECENT_FILES, L"Недавне датотеке:" },
            { TXT_CLEAR_RECENT_FILES, L"&Очисти" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"Дужина назива картице мора бити између 8 и 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"Дужина назива у наслову мора бити између 8 и 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Листа недавних датотека је очишћена, али није сачувана у регистру."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"З&атварај картице двокликом" },
            { TXT_CLOSE_TAB_CONTEXT, L"&Затвори картицу" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"Доз&воли више инстанци" },
            { TXT_INSTANCE_FORWARD_FAILED,
                L"Датотеке није било могуће проследити покренутој инстанци програма MediaInfo."
            },
            { TXT_LOADING, L"Учитавање…" },
            { TXT_LOADING_FILE, L"Учитавање датотеке %s…" },
            { TXT_APPLICATION_HELP,
                L"ДАТОТЕКЕ И КАРТИЦЕ\r\nИзворни Windows x86 прегледач извештаја MediaInfo.dll. Свака "
                L"датотека има своју картицу само за читање. Отворите помоћу Ctrl+O или превлачењем. "
                L"Поновно отварање бира постојећу картицу. Ctrl+W или средње дугме миша затвара картицу; "
                L"Затвори све затвара све картице. Мени Датотека памти осам недавних датотека. Контекстни "
                L"мени заглавља картице садржи Затвори картицу. У Подешавањима укључите Затварај картице "
                L"двокликом да бисте затворили картицу двокликом на њено заглавље. Опција је "
                L"подразумевано искључена и њено стање се чува. Двоклик у тексту извештаја бира реч. "
                L"Троструки клик бира логички ред. Превлачење проширује избор по речима или редовима.\r\n"
                L"Отвори фасциклу… отвара датотеке које су непосредно у изабраној фасцикли, сваку на "
                L"засебној картици. Потфасцикле нису укључене.\r\nОтвори и Отвори фасциклу деле последњу "
                L"изабрану фасциклу. Извоз памти посебну фасциклу, подразумевано Документи. Напредни "
                L"режим приказује додатна поља извештаја.\r\nПознати формати / Познати кодеци / Познати "
                L"параметри — MediaInfo.dll.\r\nПотпуна анализа испитује целу датотеку и може потрајати "
                L"дуже. Ове опције извештаја и Ниво праћења припадају свакој картици; промена освежава "
                L"само активну картицу. Последња ручно одабрана комбинација се чува за нове картице и "
                L"следеће покретање. Подударни кеширани извештај се поново користи док датотека остаје "
                L"непромењена.\r\nНиво праћења: 0 / 5 / 9 / 10.\r\nДатотека > Подешавање странице… отвара "
                L"подешавања папира, оријентације и маргина за текућу сесију. Штампај… (Ctrl+P) отвара "
                L"системски дијалог штампања; Windows 11 пружа преглед, док Windows 10 и старији "
                L"задржавају класични дијалог. Ctrl+P штампа активну картицу главног прозора или "
                L"текстуално поље прозора Помоћ или О програму, зависно од тога који прозор има фокус. "
                L"Извештаји користе изабрани фонт извештаја, Помоћ системски фонт дијалога, а О програму "
                L"фонт свог текстуалног поља. Ако нема отворених картица, а Помоћ је отворена, Подешавање "
                L"странице… и Штампај… остају доступни; Штампај… штампа помоћ. Помоћ користи дијалог "
                L"штампања главног прозора; поновни Ctrl+P у Помоћи доводи исти дијалог у први план. Дуги "
                L"редови се преламају, а текст дели на странице. Штампање се одвија у позадини.\r\n"
                L"Превуците једну или више датотека у прозор, на икону EXE датотеке или њену пречицу или "
                L"проследите њихове путање преко командне линије. Ако више инстанци није дозвољено, "
                L"датотеке се отварају у већ покренутом прозору.\r\nЛева страна статусне траке приказује "
                L"путање датотека и ток учитавања, а десна верзију учитане библиотеке MediaInfo.dll. Дуге "
                L"путање скраћују се тротачком према доступном простору.\r\n\r\nИЗВОЗ\r\nTXT, BMP, GIF, "
                L"JPEG, PNG, TIFF и WebP приказују се када су доступни. Последња фасцикла и формат извоза "
                L"се памте.\r\nTXT нуди ANSI, UTF-8, UTF-8 са BOM-ом, UTF-16 BE са BOM-ом и UTF-16 LE са "
                L"BOM-ом. Подразумевана је друга ставка, UTF-8 без BOM-а. Чувају се цео текст извештаја и "
                L"изворни завршеци редова.\r\n\r\nНАПРАВИ ДАТОТЕКУ ЗАГЛАВЉА\r\nМени Алатке је четврти на "
                L"траци менија. Команда Направи датотеку заглавља… отвара једну улазну датотеку независно "
                L"од картица извештаја и копира њених првих 524288 бајтова (512 KiB). Краћа датотека се "
                L"копира у целини; празна датотека даје празну излазну датотеку. То је обично бинарно "
                L"читање датотеке, без анализе помоћу MediaInfo и без потребе за MediaInfo.dll. Картице "
                L"извештаја и списак недавних датотека остају непромењени.\r\n\r\nНакон читања отвара се "
                L"дијалог Сачувај као у фасцикли улазне датотеке. За video.mp4 нуди назив "
                L"video.mp4.header: .header се додаје на цео изворни назив, укључујући наставак. Можете "
                L"променити назив и одредишну фасциклу. Отказивање било ког дијалога не уписује излазну "
                L"датотеку. Замена постојеће одредишне датотеке захтева потврду. Улазна датотека се не "
                L"мења, а неуспело чување задржава претходну одредишну датотеку. Отварање и чување "
                L"користе најновије системске дијалоге доступне у тој верзији Windows-а.\r\n\r\nПри "
                L"покретању апликације алат преузима исту почетну фасциклу као Датотека > Отвори. Ако "
                L"фасцикла није сачувана, Windows бира почетну локацију. После избора улазне датотеке "
                L"алат памти сопствену фасциклу само до затварања апликације, чак и ако откажете Сачувај "
                L"као. Не мења фасцикле команди Отвори и Извези нити чува своју фасциклу у подешавањима "
                L"апликације. Сваки дијалог Сачувај као почиње у фасцикли тренутно изабране улазне "
                L"датотеке, без обзира на претходно одредиште чувања.\r\n\r\nПОДЕШАВАЊА И ЈЕЗИЦИ\r\n"
                L"Подешавања (Опције > Подешавања, Ctrl+G) садрже путање библиотека, фонт извештаја, "
                L"умекшавање и језике. Интерфејс има 36 варијанти и почетно прати Windows. Извештаји увек "
                L"подразумевано користе изворни енглески библиотеке, независно од Windows-а и интерфејса. "
                L"То мења само ручни избор језика: енглески, 37 превода или сопствена MediaInfo CSV "
                L"табела. У реду или Примени потврђује промене; Откажи одбацује непотврђене промене. "
                L"Подешавања одређују ограничење назива картице (подразумевано 80) и бришу листу недавних "
                L"датотека. Дуги називи задржавају почетак, крај и наставак с тротачком у средини. Очисти "
                L"одмах уклања листу недавних датотека, чак и ако затим затворите Подешавања дугметом "
                L"Откажи.\r\n\r\nНаслов главног прозора приказује активну датотеку у облику назив датотеке — "
                L"MediaInfo. У подешавањима се дужина назива у наслову може засебно поставити на 8–255 "
                L"знакова (подразумијевано 40). Дужи називи скраћују се истом тротачком у средини, уз очување"
                L" наставка. Без отворених картица наслов је MediaInfo.\r\n\r\nБИБЛИОТЕКЕ И "
                L"ПРОЗОРИ\r\nПрограм садржи MediaInfo 26.10, 21.03 и 0.7.60, "
                L"које се покушавају од најновије након спољних библиотека. Две новије верзије имају "
                L"одговарајући libcurl; 0.7.60 га никада не распакује. Положај прозора се чува. "
                L"Подразумевано је дозвољена само једна инстанца, а наредна покретања шаљу датотеке "
                L"отвореном прозору. У подешавањима се може дозволити више инстанци. Када постоји више "
                L"прозора, само први прозор сваког типа прозора враћа сачувани положај; остали враћају "
                L"само величину.\r\n\r\nУређивање > Пронађи (Ctrl+F) претражује активну картицу извештаја "
                L"или текстуално поље прозора Помоћ или О програму, зависно од тога који прозор има "
                L"фокус. Прозор претраге задржава последњи изабрани извор док има фокус. F3 понавља "
                L"претрагу, а Shift+F3 мења њен смер. На крају текста претрага се наставља с другог "
                L"краја. Опције > Преламање редова важи само за активну картицу; ознака прати изабрану "
                L"картицу. Прозор претраге може се умањити и мењати му се ширина; положај и опција Увек "
                L"на врху се памте. До 30 текстова претраге с њиховим опцијама чува се само до затварања "
                L"апликације. Опције почетка и краја односе се на логичке редове. Регуларни изрази "
                L"користе синтаксу PCRE2. Остале команде менија Уређивање односе се на активну картицу "
                L"извештаја. Enter покреће претрагу, а Shift+Enter обрће изабрани смер. „Разликуј велика "
                L"и мала слова“ разликује велика и мала слова; „Тражи уназад“ тражи према почетку текста. "
                L"Избор ставке историје враћа свих пет опција претраге, укључујући стање режима "
                L"регуларних израза; „Увек на врху“ је независна опција. „Регуларни израз“ онемогућава "
                L"„Ред почиње са“ и „Ред се завршава са“. Када су укључене обе опције крајева реда, "
                L"довољно је поклапање на једном крају. „Преламање редова“ мења само приказ."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"Није могуће сачувати WebP слику. Проверите одредиште, слободну меморију и простор на диску."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Текстуални документ UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Текстуални документ UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Текстуални документ UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Текстуални документ UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Извештај се не може сачувати у овом кодирању без губитка знакова. Изаберите друго кодирање "
                L"текста."
            },
            { TXT_OPEN_FOLDER, L"Отвори &фасциклу…" },
            { TXT_OPEN_FOLDER_TITLE, L"Отвори фасциклу" },
            { TXT_FOLDER_READ_FAILED,
                L"Фасцикла не може да се прочита:\n\n%s\n\nГрешка оперативног система Windows %lu."
            },
            { TXT_ADVANCED_MODE, L"&Напредни режим" },
            { TXT_REPORT_DETAIL_REJECTED, L"Изабрана MediaInfo.dll одбила је подешавање детаља извештаја." },
            { TXT_KNOWN_FORMATS, L"Познати &формати" },
            { TXT_KNOWN_CODECS, L"Познати &кодеци" },
            { TXT_KNOWN_PARAMETERS, L"Познати п&араметри" },
            { TXT_KNOWN_FORMATS_TITLE, L"Познати формати" },
            { TXT_KNOWN_CODECS_TITLE, L"Познати кодеци" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Познати параметри" },
            { TXT_KNOWN_INFO_FAILED, L"Библиотека није вратила тражене информације." },
            { TXT_FULL_PARSING, L"Потпуна &анализа" },
            { TXT_PARSING_REJECTED, L"Изабрана MediaInfo.dll одбила је подешавање анализе." },
            { TXT_TRACE_LEVEL_0, L"Ниво праћења &0" },
            { TXT_TRACE_LEVEL_5, L"Ниво праћења &5" },
            { TXT_TRACE_LEVEL_9, L"Ниво праћења &9" },
            { TXT_TRACE_LEVEL_10, L"Ниво праћења &10" },
            { TXT_PAGE_SETUP, L"&Подешавање странице…" },
            { TXT_PAGE_SETUP_FAILED, L"Није могуће отворити подешавање странице." },
            { TXT_PRINT, L"Ш&тампај…\tCtrl+P" },
            { TXT_PRINTING, L"Штампање…" },
            { TXT_PRINT_FAILED,
                L"Текст не може да се одштампа. Проверите штампач, његова подешавања и доступну меморију."
            },
            { TXT_TOOLS_MENU, L"&Алатке" },
            { TXT_CREATE_HEADER, L"Направи датотеку &заглавља…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Направи датотеку заглавља - Отвори" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Направи датотеку заглавља - Сачувај као" },
            { TXT_HEADER_FORMAT, L"Датотека заглавља (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Није могуће прочитати заглавље датотеке:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Није могуће сачувати датотеку заглавља:\n\n%s" },
            { TXT_COPY, L"&Копирај" },
            { TXT_COPY_FILE_NAME, L"Копирај &назив датотеке" },
            { TXT_COPY_FULL_PATH, L"Копирај пуну п&утању" },
            { TXT_LAUNCH_FILE, L"По&крени датотеку" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"П&рикажи у фасцикли" },
            { TXT_EDIT_MENU, L"&Уређивање" },
            { TXT_WORD_WRAP, L"П&реламање редова" },
            { TXT_WORD_WRAP_FAILED, L"Преламање редова није могуће променити." },
            { TXT_COPY_SELECTION, L"&Копирај\tCtrl+C" },
            { TXT_SELECT_ALL, L"Изабери &све\tCtrl+A" },
            { TXT_FIND_MENU, L"&Пронађи…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Пронађи с&ледеће\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Пронађи прет&ходно\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Пронађи" },
            { TXT_FIND_WHAT, L"&Тражи:" },
            { TXT_FIND_NEXT, L"Пронађи с&ледеће" },
            { TXT_FIND_MATCH_CASE, L"Разликуј велика и &мала слова" },
            { TXT_FIND_BACKWARD, L"Тражи &уназад" },
            { TXT_FIND_TOPMOST, L"Увек на &врху" },
            { TXT_FIND_STARTS_WITH, L"Ред &почиње са" },
            { TXT_FIND_ENDS_WITH, L"Ред се завршава с&а" },
            { TXT_FIND_REGEX, L"&Регуларни израз" },
            { TXT_FIND_NOT_FOUND, L"Наведени текст није пронађен." },
            { TXT_FIND_FAILED, L"Претрагу није могуће довршити." },
            { TXT_FIND_REGEX_ERROR, L"Грешка у регуларном изразу:\r\n\r\n%s" },
        }
    },
    {
        LANG_UK,
        {
            { TXT_LANGUAGE_NAME, L"Українська" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nВебсайт: " },
            { TXT_FILE_OPEN_FAILED, L"Не вдається відкрити %s. Перевірте шлях і дозволи." },
            { TXT_BROWSE_DLL, L"&Огляд…" },
            { TXT_BROWSE_REPORT, L"Огл&яд…" },
            { TXT_CLOSE, L"&Закрити" },
            { TXT_CLOSE_TAB, L"&Закрити\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"За &замовчуванням" },
            { TXT_EXPORT, L"&Експортувати…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Файл" },
            { TXT_REPORT_FONT, L"Ш&рифт звіту:" },
            { TXT_HELP_MENU, L"&Довідка" },
            { TXT_HELP, L"&Довідка\tF1" },
            { TXT_LANGUAGE, L"&Мова:" },
            { TXT_OPEN_WEBSITE, L"&Відкрити в типовому браузері" },
            { TXT_OPEN, L"&Відкрити…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"&Параметри" },
            { TXT_PREFERENCES_MENU, L"&Налаштування…\tCtrl+G" },
            { TXT_ABOUT, L"&Про програму" },
            { TXT_ABOUT_TITLE, L"Про програму %ls" },
            { TXT_ALL_FILES, L"Усі файли" },
            { TXT_FONT_BOLD, L"Напівжирний" },
            { TXT_FONT_BOLD_ITALIC, L"Напівжирний + Курсив" },
            { TXT_BROWSE_CURL, L"О&гляд…" },
            { TXT_CANCEL, L"Скасувати" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Не вдається завантажити MediaInfo.dll (помилка Windows %lu). Використайте 32-бітну DLL, "
                L"сумісну з цією версією Windows."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Не вдається завантажити libcurl.dll (помилка Windows %lu). Виберіть 32-бітну бібліотеку, "
                L"сумісну з цією версією Windows."
            },
            { TXT_CLOSE_ALL, L"Закрити в&се" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Копіювати &адресу" },
            { TXT_COPY_INFORMATION, L"Копіювати ві&домості" },
            { TXT_DLL_FILES, L"Динамічні бібліотеки" },
            { TXT_EXIT, L"В&ийти\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Вбудовані бібліотеки MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Вбудовані бібліотеки libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Експортувати звіт" },
            { TXT_FONT_ANTIALIASING, L"Зг&ладжування шрифту:" },
            { TXT_GIF_EXPORT_FAILED,
                L"Експорт GIF не вдався. GIF без втрат потребує щонайбільше 256 кольорів."
            },
            { TXT_FONT_ITALIC, L"Курсив" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED, L"Експорт JPEG не вдався. Потрібен справний кодер JPEG GDI+." },
            { TXT_LICENSE_UNAVAILABLE, L"Ресурс ліцензії недоступний." },
            { TXT_MEDIA_FILES, L"Медіафайли" },
            { TXT_APPLICATION_DESCRIPTION, L"Переглядач інформації про медіа" },
            { TXT_HELP_TITLE, L"MediaInfo — Довідка" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo не вдалося ініціалізувати аналіз файлу." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo не може відкрити або розпізнати цей файл." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"&Шлях до MediaInfo.dll:" },
            { TXT_MEDIALIB_REQUIRED,
                L"MediaInfo.dll не завантажено. Виберіть її в Параметри > Налаштування."
            },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll не завантажено." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Не вдалося завантажити сумісну зовнішню чи вбудовану MediaInfo.dll. Виберіть її в "
                L"Параметри > Налаштування."
            },
            { TXT_ANTIALIASING_NONE, L"Немає" },
            { TXT_OK, L"Гаразд" },
            { TXT_OPEN_TITLE, L"Відкрити медіафайли" },
            { TXT_PLATFORM, L"Цільова платформа:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Налаштування" },
            { TXT_READY, L"Готовий" },
            { TXT_FONT_REGULAR, L"Звичайний" },
            { TXT_REPORT_LANGUAGE, L"Мова з&віту:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Мовні таблиці звітів" },
            { TXT_SELECT_MEDIALIB, L"Огляд: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Огляд: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH, L"Виберіть наявний медіафайл зі шляхом, коротшим за MAX_PATH." },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Виберіть наявні файли зі шляхами, коротшими за MAX_PATH." },
            { TXT_SELECT_CURL, L"Огляд: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Текстовий документ ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"Не вдається зберегти зображення BMP. Перевірте папку призначення, вільну пам’ять і місце "
                L"на диску."
            },
            { TXT_LIBRARY_WORKER_START_FAILED,
                L"Не вдається запустити процес бібліотеки (помилка Windows %lu)."
            },
            { TXT_REPORT_COPY_FAILED, L"Не вдається скопіювати звіт MediaInfo в пам’ять." },
            { TXT_VIEWER_CREATE_FAILED, L"Не вдається створити переглядач MediaInfo." },
            { TXT_MEDIALIB_PATH_INVALID, L"Шлях до MediaInfo.dll неправильний або надто довгий." },
            { TXT_PNG_EXPORT_FAILED,
                L"Не вдається зберегти зображення PNG. Перевірте папку призначення, вільну пам’ять і місце "
                L"на диску."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"Не вдається зберегти зображення TIFF. Перевірте папку призначення, вільну пам’ять і місце "
                L"на диску."
            },
            { TXT_COPY_URL_FAILED, L"Не вдалося скопіювати URL у буфер обміну." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"Переглядач Win32 потребує 32-бітної %s. Виберіть бібліотеку x86/i386."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Не вдається записати вбудовану бібліотеку в AppData, профіль користувача, Program Files чи "
                L"тимчасову папку."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED, L"Розпакування бібліотеки або перевірка CRC не вдалася." },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Ресурс вбудованої бібліотеки неправильний." },
            { TXT_CURL_FILENAME_INVALID,
                L"Бібліотека має називатися libcurl.dll, щоб MediaInfo могла її використовувати."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Не вдалося відкрити діалог вибору файлів." },
            { TXT_FILE_DIALOG_SELECTION_FAILED,
                L"Не вдалося отримати вибрані файли з діалогу вибору файлів."
            },
            { TXT_RECENT_FILE_MISSING,
                L"Файл «%s» більше не існує.\n\nВилучити цей запис зі списку нещодавніх файлів?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Файл більше недоступний:\n\n%s\n\nВилучити цей запис зі списку нещодавніх файлів?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Не вдалося скопіювати відомості в буфер обміну." },
            { TXT_CURL_PATH_INVALID, L"Шлях до libcurl.dll неправильний або надто довгий." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Бібліотека не повернула версію MediaInfo." },
            { TXT_CURL_EXPORTS_MISSING, L"Бібліотека не експортує функції curl, потрібні MediaInfo." },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"Бібліотека не експортує потрібні функції Unicode бібліотеки MediaInfo."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Процес бібліотеки завершився помилкою під час %s (код 0x%08lX). Виберіть сумісну DLL у "
                L"Параметри > Налаштування."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Процес бібліотеки не відповідає під час %s. Виберіть сумісну DLL у Параметри > "
                L"Налаштування."
            },
            { TXT_PREFERENCES_SAVE_FAILED, L"Налаштування застосовано, але не збережено в реєстрі." },
            { TXT_REPORT_START_FAILED, L"Недостатньо пам’яті для запуску звіту." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Не вдається створити зображення звіту." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Не вдається завантажити мовну таблицю. Виберіть дійсний "
                L"файл MediaInfo CSV у UTF-8 або UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"Не вдається запустити потік звіту." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"Вибрана MediaInfo.dll відхилила мову звіту." },
            { TXT_INVALID_WINDOWS_DLL, L"Вибраний файл не є дійсною DLL Windows." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Вибраний формат зображення не підтримується." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Не вдається зберегти текстовий звіт. Перевірте папку призначення та вільне місце на диску."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Не вдається відкрити сайт у типовому браузері." },
            { TXT_TOO_MANY_FILES, L"Вибрано забагато файлів. Відкривайте менші групи." },
            { TXT_LIBRARY_PATH_HINT,
                L"Використайте 32-бітні бібліотеки, сумісні з вашою версією Windows. Для автоматичного "
                L"пошуку залиште шляхи порожніми. MediaInfoLib v0.7.60 не використовує libcurl.dll."
            },
            { TXT_VERSION, L"Версія" },
            { TXT_WEBSITE_TOOLTIP, L"Відкрити вебсайт %s" },
            { TXT_WAITING_FOR_REPORT, L"Очікування завершення поточного звіту." },
            { TXT_WEBSITE_LABEL, L"Вебсайт:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"копіювання звіту MediaInfo" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"Шлях &до libcurl.dll:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"завантаження MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"завантаження libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"вивантаження MediaInfo.dll" },
            { TXT_APPLY, L"З&астосувати" },
            { TXT_TAB_NAME_LENGTH, L"Довжи&на назви вкладки:" },
            { TXT_TITLE_NAME_LENGTH, L"&Довжина заголовка:" },
            { TXT_RECENT_FILES, L"Останні файли:" },
            { TXT_CLEAR_RECENT_FILES, L"О&чистити" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"Довжина назви вкладки має бути від 8 до 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"Довжина назви в заголовку має бути від 8 до 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Список останніх файлів очищено, але його не вдалося зберегти в реєстрі."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"Закривати вкладки &подвійним клацанням" },
            { TXT_CLOSE_TAB_CONTEXT, L"Закрити &вкладку" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"Дозвол&ити кілька екземплярів" },
            { TXT_INSTANCE_FORWARD_FAILED, L"Не вдалося передати файли запущеному екземпляру MediaInfo." },
            { TXT_LOADING, L"Завантаження…" },
            { TXT_LOADING_FILE, L"Завантаження файлу %s…" },
            { TXT_APPLICATION_HELP,
                L"ФАЙЛИ ТА ВКЛАДКИ\r\nНативний переглядач звітів MediaInfo.dll для Windows x86. Кожен "
                L"файл має власну вкладку лише для читання. Відкривайте через Ctrl+O або перетягуванням. "
                L"Повторне відкриття вибирає наявну вкладку. Ctrl+W або середня кнопка миші закриває "
                L"вкладку; Закрити все закриває всі. Меню Файл пам’ятає вісім останніх файлів. Контекстне "
                L"меню заголовка вкладки містить Закрити вкладку. У Налаштуваннях увімкніть Закривати "
                L"вкладки подвійним клацанням, щоб закривати вкладку подвійним клацанням її заголовка. "
                L"Типово параметр вимкнений, його стан зберігається. Подвійне клацання тексту звіту "
                L"виділяє слово. Потрійне клацання виділяє логічний рядок. Перетягування розширює "
                L"виділення за словами або рядками.\r\nВідкрити папку… відкриває файли безпосередньо у "
                L"вибраній папці, кожен на окремій вкладці. Вкладені папки не включаються.\r\nВідкрити та "
                L"Відкрити папку використовують спільну останню вибрану папку. Експорт запам’ятовує "
                L"окрему папку, типово Документи. Розширений режим показує додаткові поля звіту.\r\n"
                L"Відомі формати / Відомі кодеки / Відомі параметри — MediaInfo.dll.\r\nПовний аналіз "
                L"перевіряє весь файл і може зайняти більше часу. Ці параметри звіту та Рівень трасування "
                L"належать кожній вкладці; зміна оновлює лише активну вкладку. Остання вибрана вручну "
                L"комбінація зберігається для нових вкладок і наступного запуску. Відповідний кешований "
                L"звіт повторно використовується, доки файл залишається незмінним.\r\nРівень трасування: "
                L"0 / 5 / 9 / 10.\r\nФайл > Параметри сторінки… відкриває налаштування паперу, орієнтації "
                L"та полів для поточного сеансу. Друк… (Ctrl+P) відкриває системне вікно друку; Windows "
                L"11 надає попередній перегляд, а Windows 10 і старіші зберігають класичне вікно. Ctrl+P "
                L"друкує активну вкладку головного вікна або текстове поле Довідки чи Про програму "
                L"залежно від того, яке вікно має фокус. Звіти використовують вибраний шрифт звіту, "
                L"Довідка системний шрифт діалогів, а Про програму шрифт свого текстового поля. Якщо "
                L"вкладок не відкрито, але Довідка відкрита, Параметри сторінки… і Друк… залишаються "
                L"доступними; Друк… друкує довідку. Довідка використовує вікно друку головного вікна; "
                L"повторне Ctrl+P у Довідці виводить те саме вікно на передній план. Довгі рядки "
                L"переносяться, а текст ділиться на сторінки. Друк виконується у фоні.\r\nПеретягніть "
                L"один або кілька файлів у вікно, на піктограму EXE чи його ярлик або передайте їхні "
                L"шляхи в командному рядку. Якщо кілька примірників не дозволено, файли відкриються у вже "
                L"запущеному вікні.\r\nЛіворуч у рядку стану показано шляхи до файлів і перебіг "
                L"завантаження, праворуч — версію завантаженої MediaInfo.dll. Довгі шляхи скорочуються "
                L"трьома крапками відповідно до доступного місця.\r\n\r\nЕКСПОРТ\r\nTXT, BMP, GIF, JPEG, "
                L"PNG, TIFF і WebP пропонуються залежно від доступності. Остання тека та формат експорту "
                L"зберігаються.\r\nTXT пропонує ANSI, UTF-8, UTF-8 із BOM, UTF-16 BE із BOM і UTF-16 LE "
                L"із BOM. Типово вибрано другий варіант, UTF-8 без BOM. Зберігаються весь текст звіту та "
                L"початкові закінчення рядків.\r\n\r\nСТВОРИТИ ФАЙЛ ЗАГОЛОВКУ\r\nМеню Інструменти — "
                L"четверте в рядку меню. Його команда Створити файл заголовку… відкриває один вхідний "
                L"файл незалежно від вкладок звіту та копіює його перші 524288 байт (512 KiB). Коротший "
                L"файл копіюється повністю; порожній файл створює порожній вихід. Це звичайне читання "
                L"двійкового файлу без аналізу MediaInfo або вимоги для MediaInfo.dll. Інструмент залишає "
                L"без змін вкладки звіту та список останніх файлів засобу перегляду.\r\n\r\nПісля "
                L"прочитання в папці вхідного файлу відкривається діалогове вікно «Зберегти як», яке "
                L"пропонує video.mp4.header для video.mp4: .header додається до повної оригінальної "
                L"назви. Ви можете змінити назву та папку призначення. Скасування будь-якого діалогового "
                L"вікна не призводить до запису результатів. Для заміни існуючого призначення потрібне "
                L"підтвердження. Вхідний файл залишається незмінним; невдале збереження зберігає "
                L"попередній пункт призначення. Для відкриття та збереження використовуються найсучасніші "
                L"системні діалогові вікна, доступні в цій версії Windows.\r\n\r\nПід час запуску "
                L"програми інструмент бере початкову папку введення з Файл > Відкрити. Якщо папка не була "
                L"збережена, Windows вибирає початкове розташування. Після вибору вхідного файлу "
                L"інструмент запам’ятовує його власну папку лише до завершення роботи програми, навіть "
                L"якщо функцію «Зберегти як» скасовано. Він не змінює папки, які використовуються "
                L"Відкрити і Експортувати, і не зберігає власну папку в налаштуваннях програми. Кожне "
                L"діалогове вікно «Зберегти як» починається в папці поточного вибраного вхідного файлу, "
                L"незалежно від попереднього місця збереження.\r\n\r\nНАЛАШТУВАННЯ ТА МОВИ\r\n"
                L"Налаштування (Параметри > Налаштування, Ctrl+G) містять шляхи бібліотек, шрифт звіту, "
                L"згладжування та мови. Інтерфейс має 36 варіантів і спочатку відповідає Windows. Звіти "
                L"завжди типово використовують початкову англійську бібліотеки, незалежно від Windows та "
                L"інтерфейсу. Це змінює лише ручний вибір: англійська, 37 перекладів або власна таблиця "
                L"MediaInfo CSV. Гаразд або Застосувати підтверджує зміни; Скасувати відкидає "
                L"непідтверджені зміни. Налаштування задають обмеження назви вкладки (типово 80) й "
                L"очищують список останніх файлів. Довгі назви зберігають початок, кінець і розширення з "
                L"трикрапкою посередині. Очистити негайно видаляє список останніх файлів, навіть якщо "
                L"потім закрити налаштування кнопкою Скасувати.\r\n\r\nЗаголовок головного вікна показує "
                L"активний файл у вигляді назва файлу — MediaInfo. У налаштуваннях можна окремо задати "
                L"довжину назви в заголовку від 8 до 255 символів (типово 40). Довші назви скорочуються тією "
                L"самою трикрапкою посередині зі збереженням розширення. Без відкритих вкладок заголовок — "
                L"MediaInfo.\r\n\r\nБІБЛІОТЕКИ ТА ВІКНА\r\nПрограма "
                L"містить MediaInfo 26.10, 21.03 та 0.7.60, які перевіряються від найновішої після "
                L"зовнішніх бібліотек. Дві новіші версії мають відповідну libcurl; 0.7.60 ніколи її не "
                L"розпаковує. Положення вікна зберігається. За замовчуванням дозволено лише один "
                L"екземпляр, а наступні запуски передають файли відкритому вікну. У налаштуваннях можна "
                L"дозволити кілька екземплярів. За наявності кількох вікон лише перше вікно кожного типу "
                L"вікна відновлює збережене розташування; решта відновлюють лише розмір.\r\n\r\n"
                L"Редагування > Знайти (Ctrl+F) шукає в активній вкладці звіту або текстовому полі "
                L"Довідки чи Про програму залежно від того, яке вікно має фокус. Вікно пошуку зберігає "
                L"останнє вибране джерело, доки саме має фокус. F3 повторює пошук, а Shift+F3 змінює його "
                L"напрямок. На межі тексту пошук продовжується з протилежного кінця. Параметри > "
                L"Перенесення слів діє лише в активній вкладці; позначка відповідає вибраній вкладці. "
                L"Вікно пошуку можна згорнути та змінювати його ширину; положення і налаштування Завжди "
                L"зверху зберігаються. До 30 пошукових текстів із параметрами зберігаються лише до "
                L"закриття програми. Параметри початку та кінця стосуються логічних рядків. Регулярні "
                L"вирази використовують синтаксис PCRE2. Інші команди меню Редагування стосуються "
                L"активної вкладки звіту. Enter запускає пошук, а Shift+Enter змінює вибраний напрямок на "
                L"протилежний. «Враховувати регістр» розрізняє великі й малі літери; «Шукати назад» шукає "
                L"в напрямку початку тексту. Вибір запису історії відновлює всі п’ять параметрів пошуку, "
                L"зокрема стан режиму регулярних виразів; «Завжди зверху» — незалежний параметр. "
                L"«Регулярний вираз» вимикає «Рядок починається з» і «Рядок закінчується на». Якщо "
                L"ввімкнено обидва параметри країв рядка, достатньо збігу на одному краї. «Перенесення "
                L"слів» змінює лише відображення."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"Не вдається зберегти зображення WebP. Перевірте папку призначення, вільну пам’ять і місце "
                L"на диску."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Текстовий документ UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Текстовий документ UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Текстовий документ UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Текстовий документ UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Звіт неможливо зберегти в цьому кодуванні без втрати символів. Виберіть інше кодування "
                L"тексту."
            },
            { TXT_OPEN_FOLDER, L"Відкрити &папку…" },
            { TXT_OPEN_FOLDER_TITLE, L"Відкрити папку" },
            { TXT_FOLDER_READ_FAILED, L"Не вдалося прочитати папку:\n\n%s\n\nПомилка Windows %lu." },
            { TXT_ADVANCED_MODE, L"&Розширений режим" },
            { TXT_REPORT_DETAIL_REJECTED, L"Вибрана MediaInfo.dll відхилила налаштування подробиць звіту." },
            { TXT_KNOWN_FORMATS, L"Відомі &формати" },
            { TXT_KNOWN_CODECS, L"Відомі &кодеки" },
            { TXT_KNOWN_PARAMETERS, L"Відомі п&араметри" },
            { TXT_KNOWN_FORMATS_TITLE, L"Відомі формати" },
            { TXT_KNOWN_CODECS_TITLE, L"Відомі кодеки" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Відомі параметри" },
            { TXT_KNOWN_INFO_FAILED, L"Бібліотека не повернула запитані відомості." },
            { TXT_FULL_PARSING, L"&Повний аналіз" },
            { TXT_PARSING_REJECTED, L"Вибрана MediaInfo.dll відхилила налаштування аналізу." },
            { TXT_TRACE_LEVEL_0, L"Рівень трасування &0" },
            { TXT_TRACE_LEVEL_5, L"Рівень трасування &5" },
            { TXT_TRACE_LEVEL_9, L"Рівень трасування &9" },
            { TXT_TRACE_LEVEL_10, L"Рівень трасування &10" },
            { TXT_PAGE_SETUP, L"Па&раметри сторінки…" },
            { TXT_PAGE_SETUP_FAILED, L"Не вдалося відкрити параметри сторінки." },
            { TXT_PRINT, L"&Друк…\tCtrl+P" },
            { TXT_PRINTING, L"Друк…" },
            { TXT_PRINT_FAILED,
                L"Не вдалося надрукувати текст. Перевірте принтер, його налаштування та доступну пам’ять."
            },
            { TXT_TOOLS_MENU, L"&Інструменти" },
            { TXT_CREATE_HEADER, L"Створити файл &заголовку…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Створити файл заголовку - Відкрити" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Створити файл заголовку - Зберегти як" },
            { TXT_HEADER_FORMAT, L"Файл заголовка (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Не вдалося прочитати заголовок файлу:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Не вдалося зберегти файл заголовка:\n\n%s" },
            { TXT_COPY, L"&Копіювати" },
            { TXT_COPY_FILE_NAME, L"Копіювати &ім’я файлу" },
            { TXT_COPY_FULL_PATH, L"Копіювати повний &шлях" },
            { TXT_LAUNCH_FILE, L"З&апустити файл" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"П&оказати в папці" },
            { TXT_EDIT_MENU, L"&Редагування" },
            { TXT_WORD_WRAP, L"П&еренесення слів" },
            { TXT_WORD_WRAP_FAILED, L"Не вдалося змінити перенесення слів." },
            { TXT_COPY_SELECTION, L"&Копіювати\tCtrl+C" },
            { TXT_SELECT_ALL, L"Виділити &все\tCtrl+A" },
            { TXT_FIND_MENU, L"&Знайти…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Знайти &далі\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Знайти &попереднє\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Пошук" },
            { TXT_FIND_WHAT, L"&Шукати:" },
            { TXT_FIND_NEXT, L"Знайти &далі" },
            { TXT_FIND_MATCH_CASE, L"Враховувати &регістр" },
            { TXT_FIND_BACKWARD, L"Шукати &назад" },
            { TXT_FIND_TOPMOST, L"З&авжди зверху" },
            { TXT_FIND_STARTS_WITH, L"Рядок &починається з" },
            { TXT_FIND_ENDS_WITH, L"Рядок за&кінчується на" },
            { TXT_FIND_REGEX, L"Регулярний &вираз" },
            { TXT_FIND_NOT_FOUND, L"Зазначений текст не знайдено." },
            { TXT_FIND_FAILED, L"Не вдалося завершити пошук." },
            { TXT_FIND_REGEX_ERROR, L"Помилка регулярного виразу:\r\n\r\n%s" },
        }
    },
    {
        LANG_RU,
        {
            { TXT_LANGUAGE_NAME, L"Русский" },
            { TXT_ABOUT_WEBSITE_APPEND, L"\r\nВеб-сайт: " },
            { TXT_FILE_OPEN_FAILED, L"Не удаётся открыть %s. Проверьте путь и разрешения." },
            { TXT_BROWSE_DLL, L"&Обзор…" },
            { TXT_BROWSE_REPORT, L"Обзо&р…" },
            { TXT_CLOSE, L"&Закрыть" },
            { TXT_CLOSE_TAB, L"&Закрыть\tCtrl+W" },
            { TXT_FONT_DEFAULT, L"По &умолчанию" },
            { TXT_EXPORT, L"&Экспортировать…\tCtrl+E" },
            { TXT_FILE_MENU, L"&Файл" },
            { TXT_REPORT_FONT, L"&Шрифт отчёта:" },
            { TXT_HELP_MENU, L"&Справка" },
            { TXT_HELP, L"&Справка\tF1" },
            { TXT_LANGUAGE, L"&Язык:" },
            { TXT_OPEN_WEBSITE, L"&Открыть в браузере по умолчанию" },
            { TXT_OPEN, L"&Открыть…\tCtrl+O" },
            { TXT_OPTIONS_MENU, L"П&араметры" },
            { TXT_PREFERENCES_MENU, L"&Настройки…\tCtrl+G" },
            { TXT_ABOUT, L"&О программе" },
            { TXT_ABOUT_TITLE, L"О программе %ls" },
            { TXT_ALL_FILES, L"Все файлы" },
            { TXT_FONT_BOLD, L"Полужирный" },
            { TXT_FONT_BOLD_ITALIC, L"Полужирный + Курсив" },
            { TXT_BROWSE_CURL, L"Об&зор…" },
            { TXT_CANCEL, L"Отмена" },
            { TXT_MEDIALIB_LOAD_FAILED,
                L"Не удаётся загрузить MediaInfo.dll (ошибка Windows %lu). Используйте 32-битную DLL, "
                L"совместимую с этой версией Windows."
            },
            { TXT_CURL_LOAD_FAILED,
                L"Не удаётся загрузить libcurl.dll (ошибка Windows %lu). Выберите 32-битную библиотеку, "
                L"совместимую с этой версией Windows."
            },
            { TXT_CLOSE_ALL, L"Закрыть &всё" },
            { TXT_GIF_FORMAT, L"CompuServe GIF 89a (*.gif)" },
            { TXT_COPY_URL, L"Копировать &адрес" },
            { TXT_COPY_INFORMATION, L"Копировать &сведения" },
            { TXT_DLL_FILES, L"Динамические библиотеки" },
            { TXT_EXIT, L"Вы&ход\tAlt+F4" },
            { TXT_EMBEDDED_MEDIALIB, L"Встроенные библиотеки MediaInfo.dll:" },
            { TXT_EMBEDDED_CURL, L"Встроенные библиотеки libcurl.dll:" },
            { TXT_EXPORT_TITLE, L"Экспортировать отчёт" },
            { TXT_FONT_ANTIALIASING, L"&Сглаживание шрифта:" },
            { TXT_GIF_EXPORT_FAILED, L"Экспорт GIF не удался. GIF без потерь требует не более 256 цветов." },
            { TXT_FONT_ITALIC, L"Курсив" },
            { TXT_JPEG_FORMAT, L"JPEG File Interchange Format (*.jpg)" },
            { TXT_JPEG_EXPORT_FAILED, L"Экспорт JPEG не удался. Требуется работающий кодировщик JPEG GDI+." },
            { TXT_LICENSE_UNAVAILABLE, L"Ресурс лицензии недоступен." },
            { TXT_MEDIA_FILES, L"Медиафайлы" },
            { TXT_APPLICATION_DESCRIPTION, L"Просмотр информации о медиа" },
            { TXT_HELP_TITLE, L"MediaInfo — Справка" },
            { TXT_MEDIA_FILE_HANDLE_FAILED, L"MediaInfo не удалось инициализировать анализ файла." },
            { TXT_MEDIA_FILE_UNRECOGNIZED, L"MediaInfo не может открыть или распознать этот файл." },
            { TXT_CSV_FORMAT, L"Comma Separated Values (*.csv)" },
            { TXT_MEDIALIB_TITLE, L"MediaInfo.dll" },
            { TXT_MEDIALIB_PATH, L"&Путь к библиотеке MediaInfo.dll:" },
            { TXT_MEDIALIB_REQUIRED, L"MediaInfo.dll не загружена. Выберите её в Параметры > Настройки." },
            { TXT_MEDIALIB_NOT_LOADED, L"MediaInfo.dll не загружена." },
            { TXT_NO_COMPATIBLE_MEDIALIB,
                L"Не удалось загрузить совместимую внешнюю или встроенную MediaInfo.dll. Выберите её в "
                L"Параметры > Настройки."
            },
            { TXT_ANTIALIASING_NONE, L"Нет" },
            { TXT_OK, L"ОК" },
            { TXT_OPEN_TITLE, L"Открыть медиафайлы" },
            { TXT_PLATFORM, L"Целевая платформа:" },
            { TXT_PNG_FORMAT, L"Portable Network Graphics PNG (*.png)" },
            { TXT_PREFERENCES_TITLE, L"Настройки" },
            { TXT_READY, L"Готов" },
            { TXT_FONT_REGULAR, L"Обычный" },
            { TXT_REPORT_LANGUAGE, L"Язык о&тчёта:" },
            { TXT_REPORT_LANGUAGE_TABLES, L"Языковые таблицы отчётов" },
            { TXT_SELECT_MEDIALIB, L"Обзор: MediaInfo.dll" },
            { TXT_SELECT_REPORT_LANGUAGE, L"Обзор: MediaInfo CSV" },
            { TXT_INVALID_MEDIA_PATH, L"Выберите существующий медиафайл с путём короче MAX_PATH." },
            { TXT_SELECTED_PATHS_TOO_LONG, L"Выберите существующие файлы с путями короче MAX_PATH." },
            { TXT_SELECT_CURL, L"Обзор: libcurl.dll" },
            { TXT_TIFF_FORMAT, L"Tagged Image File Format TIFF (*.tif)" },
            { TXT_TEXT_FORMAT, L"Текстовый документ ANSI (*.txt)" },
            { TXT_BMP_EXPORT_FAILED,
                L"Не удаётся сохранить изображение BMP. Проверьте папку назначения, свободную память и место "
                L"на диске."
            },
            { TXT_LIBRARY_WORKER_START_FAILED,
                L"Не удаётся запустить процесс библиотеки (ошибка Windows %lu)."
            },
            { TXT_REPORT_COPY_FAILED, L"Не удаётся скопировать отчёт MediaInfo в память." },
            { TXT_VIEWER_CREATE_FAILED, L"Не удаётся создать просмотрщик MediaInfo." },
            { TXT_MEDIALIB_PATH_INVALID, L"Путь к MediaInfo.dll неверен или слишком длинный." },
            { TXT_PNG_EXPORT_FAILED,
                L"Не удаётся сохранить изображение PNG. Проверьте папку назначения, свободную память и место "
                L"на диске."
            },
            { TXT_TIFF_EXPORT_FAILED,
                L"Не удаётся сохранить изображение TIFF. Проверьте папку назначения, свободную память и "
                L"место на диске."
            },
            { TXT_COPY_URL_FAILED, L"Не удалось скопировать URL в буфер обмена." },
            { TXT_LIBRARY_REQUIRES_X86,
                L"Просмотрщику Win32 требуется 32-битная %s. Выберите библиотеку x86/i386."
            },
            { TXT_LIBRARY_EXTRACTION_FAILED,
                L"Не удаётся записать встроенную библиотеку в AppData, профиль пользователя, Program Files "
                L"или временную папку."
            },
            { TXT_LIBRARY_DECOMPRESSION_FAILED, L"Распаковка библиотеки или проверка CRC не удалась." },
            { TXT_LIBRARY_RESOURCE_INVALID, L"Ресурс встроенной библиотеки недействителен." },
            { TXT_CURL_FILENAME_INVALID,
                L"Библиотека должна называться libcurl.dll, чтобы MediaInfo могла её использовать."
            },
            { TXT_FILE_DIALOG_OPEN_FAILED, L"Не удалось открыть диалог выбора файлов." },
            { TXT_FILE_DIALOG_SELECTION_FAILED,
                L"Не удалось получить выбранные файлы из диалога выбора файлов."
            },
            { TXT_RECENT_FILE_MISSING,
                L"Файл «%s» больше не существует.\n\nУдалить эту запись из списка последних файлов?"
            },
            { TXT_RECENT_FILE_UNAVAILABLE,
                L"Файл больше недоступен:\n\n%s\n\nУдалить эту запись из списка последних файлов?"
            },
            { TXT_COPY_INFORMATION_FAILED, L"Не удалось скопировать сведения в буфер обмена." },
            { TXT_CURL_PATH_INVALID, L"Путь к libcurl.dll неверен или слишком длинный." },
            { TXT_MEDIALIB_VERSION_MISSING, L"Библиотека не вернула версию MediaInfo." },
            { TXT_CURL_EXPORTS_MISSING, L"Библиотека не экспортирует функции curl, необходимые MediaInfo." },
            { TXT_MEDIALIB_EXPORTS_MISSING,
                L"Библиотека не экспортирует необходимые функции Unicode библиотеки MediaInfo."
            },
            { TXT_LIBRARY_WORKER_FAILED,
                L"Процесс библиотеки завершился ошибкой при %s (код 0x%08lX). Выберите совместимую DLL в "
                L"Параметры > Настройки."
            },
            { TXT_LIBRARY_WORKER_TIMEOUT,
                L"Процесс библиотеки не отвечает при %s. Выберите совместимую DLL в Параметры > Настройки."
            },
            { TXT_PREFERENCES_SAVE_FAILED, L"Настройки применены, но не сохранены в реестре." },
            { TXT_REPORT_START_FAILED, L"Недостаточно памяти для запуска отчёта." },
            { TXT_REPORT_IMAGE_CREATE_FAILED, L"Не удаётся создать изображение отчёта." },
            { TXT_REPORT_LANGUAGE_LOAD_FAILED, L"Не удаётся загрузить языковую таблицу. Выберите "
                L"допустимый файл MediaInfo CSV в UTF-8 или UTF-16." },
            { TXT_REPORT_THREAD_START_FAILED, L"Не удаётся запустить поток отчёта." },
            { TXT_REPORT_LANGUAGE_REJECTED, L"Выбранная MediaInfo.dll отклонила язык отчёта." },
            { TXT_INVALID_WINDOWS_DLL, L"Выбранный файл не является допустимой DLL Windows." },
            { TXT_IMAGE_FORMAT_UNSUPPORTED, L"Выбранный формат изображения не поддерживается." },
            { TXT_TEXT_EXPORT_FAILED,
                L"Не удаётся сохранить текстовый отчёт. Проверьте папку назначения и свободное место на "
                L"диске."
            },
            { TXT_WEBSITE_OPEN_FAILED, L"Не удаётся открыть сайт в браузере по умолчанию." },
            { TXT_TOO_MANY_FILES, L"Выбрано слишком много файлов. Открывайте меньшие группы." },
            { TXT_LIBRARY_PATH_HINT,
                L"Используйте 32-битные библиотеки, совместимые с вашей версией Windows. Для автоматического "
                L"поиска оставьте пути пустыми. MediaInfoLib v0.7.60 не использует libcurl.dll."
            },
            { TXT_VERSION, L"Версия" },
            { TXT_WEBSITE_TOOLTIP, L"Открыть веб-сайт %s" },
            { TXT_WAITING_FOR_REPORT, L"Ожидание завершения текущего отчёта." },
            { TXT_WEBSITE_LABEL, L"Веб-сайт:" },
            { TXT_BMP_FORMAT, L"Windows Bitmap BMP (*.bmp)" },
            { TXT_REPORT_COPY_OPERATION, L"копировании отчёта MediaInfo" },
            { TXT_CURL_LIBRARY, L"libcurl.dll" },
            { TXT_CURL_PATH, L"Путь к ли&блиотеке libcurl.dll:" },
            { TXT_MEDIALIB_LOAD_OPERATION, L"загрузке MediaInfo.dll" },
            { TXT_CURL_LOAD_OPERATION, L"загрузке libcurl.dll" },
            { TXT_MEDIALIB_UNLOAD_OPERATION, L"выгрузке MediaInfo.dll" },
            { TXT_APPLY, L"Пр&именить" },
            { TXT_TAB_NAME_LENGTH, L"&Длина названия вкладки:" },
            { TXT_TITLE_NAME_LENGTH, L"Д&лина заголовка:" },
            { TXT_RECENT_FILES, L"Последние файлы:" },
            { TXT_CLEAR_RECENT_FILES, L"О&чистить" },
            { TXT_TAB_NAME_LENGTH_INVALID, L"Длина названия вкладки должна быть от 8 до 255." },
            { TXT_TITLE_NAME_LENGTH_INVALID, L"Длина названия в заголовке должна быть от 8 до 255." },
            { TXT_RECENT_FILES_SAVE_FAILED,
                L"Список последних файлов очищен, но его не удалось сохранить в реестре."
            },
            { TXT_CLOSE_TABS_ON_DOUBLE_CLICK, L"За&крывать вкладки двойным щелчком" },
            { TXT_CLOSE_TAB_CONTEXT, L"Закрыть &вкладку" },
            { TXT_ALLOW_MULTIPLE_INSTANCES, L"Р&азрешать несколько экземпляров" },
            { TXT_INSTANCE_FORWARD_FAILED, L"Не удалось передать файлы работающему экземпляру MediaInfo." },
            { TXT_LOADING, L"Загрузка…" },
            { TXT_LOADING_FILE, L"Загрузка файла %s…" },
            { TXT_APPLICATION_HELP,
                L"ФАЙЛЫ И ВКЛАДКИ\r\nНативный просмотрщик отчётов MediaInfo.dll для Windows x86. У "
                L"каждого файла своя вкладка только для чтения. Открывайте через Ctrl+O или "
                L"перетаскиванием. Повторное открытие выбирает существующую вкладку. Ctrl+W или средняя "
                L"кнопка мыши закрывает вкладку; Закрыть всё закрывает все. Меню Файл помнит восемь "
                L"последних файлов. Контекстное меню заголовка вкладки содержит Закрыть вкладку. В "
                L"Настройках включите Закрывать вкладки двойным щелчком, чтобы закрывать вкладку двойным "
                L"щелчком по её заголовку. По умолчанию параметр выключен, его состояние сохраняется. "
                L"Двойной щелчок в тексте отчёта выделяет слово. Тройной щелчок выделяет логическую "
                L"строку. Перетаскивание расширяет выделение по словам или строкам.\r\nОткрыть папку… "
                L"открывает файлы непосредственно в выбранной папке, каждый на отдельной вкладке. "
                L"Вложенные папки не включаются.\r\nОткрыть и Открыть папку используют общую последнюю "
                L"выбранную папку. Экспорт запоминает отдельную папку, по умолчанию Документы. "
                L"Расширенный режим показывает дополнительные поля отчёта.\r\nИзвестные форматы / "
                L"Известные кодеки / Известные параметры — MediaInfo.dll.\r\nПолный анализ проверяет весь "
                L"файл и может занять больше времени. Эти параметры отчета и Уровень трассировки "
                L"относятся к каждой вкладке; изменение обновляет только активную вкладку. Последняя "
                L"выбранная вручную комбинация сохраняется для новых вкладок и следующего запуска. "
                L"Соответствующий кэшированный отчет используется повторно, пока файл остается "
                L"неизменным.\r\nУровень трассировки: 0 / 5 / 9 / 10.\r\nФайл > Параметры страницы… "
                L"открывает настройки бумаги, ориентации и полей для текущего сеанса. Печать… (Ctrl+P) "
                L"открывает системное окно печати; Windows 11 предоставляет предварительный просмотр, а "
                L"Windows 10 и более ранние версии сохраняют классическое окно. Ctrl+P печатает активную "
                L"вкладку главного окна или текстовое поле Справки либо О программе в зависимости от "
                L"того, какое окно имеет фокус. Отчёты используют выбранный шрифт отчёта, Справка "
                L"системный шрифт диалогов, а О программе шрифт своего текстового поля. Если вкладок нет, "
                L"но Справка открыта, Параметры страницы… и Печать… остаются доступны; Печать… печатает "
                L"справку. Справка использует окно печати главного окна; повторное Ctrl+P в Справке "
                L"выводит то же окно на передний план. Длинные строки переносятся, а текст разбивается на "
                L"страницы. Печать выполняется в фоне.\r\nПеретащите один или несколько файлов в окно, на "
                L"значок EXE или его ярлык либо передайте их пути в командной строке. Если несколько "
                L"экземпляров не разрешены, файлы откроются в уже запущенном окне.\r\nСлева в строке "
                L"состояния отображаются пути к файлам и ход загрузки, справа — версия загруженной "
                L"MediaInfo.dll. Длинные пути сокращаются многоточием с учётом доступного места.\r\n\r\n"
                L"ЭКСПОРТ\r\nTXT, BMP, GIF, JPEG, PNG, TIFF и WebP предлагаются по доступности. Последняя "
                L"папка и формат экспорта запоминаются.\r\nTXT предлагает ANSI, UTF-8, UTF-8 с BOM, "
                L"UTF-16 BE с BOM и UTF-16 LE с BOM. По умолчанию выбран второй вариант, UTF-8 без BOM. "
                L"Сохраняются полный текст отчёта и исходные окончания строк.\r\n\r\nСОЗДАТЬ ЗАГОЛОВОК\r\n"
                L"Меню Инструменты — четвёртое в строке меню. Его команда Создать заголовок… открывает "
                L"один исходный файл независимо от вкладок отчета и копирует его первые 524288 байт (512 "
                L"KiB). Более короткий файл копируется полностью; пустой файл производит пустой вывод. "
                L"Это обычное чтение двоичного файла без анализа MediaInfo или требования к "
                L"MediaInfo.dll. Инструмент оставляет вкладки отчетов и список последних файлов средства "
                L"просмотра без изменений.\r\n\r\nПосле прочтения в папке исходного файла открывается "
                L"диалоговое окно «Сохранить как», в котором предлагается video.mp4.header для video.mp4: "
                L".header добавляется к полному исходному имени. Вы можете изменить как имя, так и папку "
                L"назначения. Отмена любого диалога не приводит к выводу данных. Замена существующего "
                L"пункта назначения требует подтверждения. Источник остается неизменным; неудачное "
                L"сохранение сохраняет предыдущий пункт назначения. Для открытия и сохранения "
                L"используются самые современные системные диалоговые окна, доступные в данной версии "
                L"Windows.\r\n\r\nПри запуске приложения инструмент берет исходную входную папку из Файл "
                L"> Открыть. Если ни одна папка не была сохранена, Windows выбирает исходное "
                L"местоположение. После выбора входного файла инструмент запоминает собственную папку "
                L"только до выхода из приложения, даже если команда «Сохранить как» отменена. Он не "
                L"изменяет папки, используемые Открыть и Экспортировать, и не сохраняет свою собственную "
                L"папку в настройках приложения. Каждое диалоговое окно «Сохранить как» начинается в "
                L"папке текущего выбранного входного файла, независимо от предыдущего места "
                L"сохранения.\r\n\r\nНАСТРОЙКИ И ЯЗЫКИ\r\nНастройки (Параметры > Настройки, Ctrl+G) "
                L"содержат пути библиотек, шрифт отчёта, сглаживание и языки. Интерфейс имеет 36 "
                L"вариантов и изначально следует Windows. Отчёты всегда по умолчанию используют исходный "
                L"английский библиотеки, независимо от Windows и интерфейса. Это меняет только ручной "
                L"выбор: английский, 37 переводов или собственная таблица MediaInfo CSV. ОК или Применить "
                L"подтверждает изменения; Отмена отбрасывает неподтверждённые изменения. Настройки задают "
                L"ограничение названия вкладки (по умолчанию 80) и очищают список последних файлов. "
                L"Длинные названия сохраняют начало, конец и расширение с многоточием посередине. "
                L"Очистить сразу удаляет список последних файлов, даже если затем закрыть настройки "
                L"кнопкой Отмена.\r\n\r\nЗаголовок главного окна показывает активный файл в виде имя файла — "
                L"MediaInfo. В настройках можно отдельно задать длину названия в заголовке от 8 до 255 "
                L"символов (по умолчанию 40). Длинные названия сокращаются тем же многоточием посередине с "
                L"сохранением расширения. Без открытых вкладок заголовок — MediaInfo.\r\n\r\nБИБЛИОТЕКИ И "
                L"ОКНА\r\nПрограмма содержит MediaInfo 26.10, 21.03 и "
                L"0.7.60, проверяемые от новейшей после внешних библиотек. У двух новых версий есть "
                L"соответствующая libcurl; 0.7.60 никогда её не распаковывает. Положение окна "
                L"сохраняется. По умолчанию разрешён только один экземпляр, а последующие запуски "
                L"передают файлы открытому окну. В настройках можно разрешить несколько экземпляров. При "
                L"нескольких окнах только первое окно каждого типа окна восстанавливает сохранённое "
                L"положение; остальные восстанавливают только размер.\r\n\r\nПравка > Найти (Ctrl+F) ищет "
                L"в активной вкладке отчёта или текстовом поле Справки либо О программе в зависимости от "
                L"того, какое окно имеет фокус. Окно поиска сохраняет последний выбранный источник, пока "
                L"само имеет фокус. F3 повторяет поиск, а Shift+F3 меняет его направление. На границе "
                L"текста поиск продолжается с противоположного конца. Параметры > Перенос по словам "
                L"действует только в активной вкладке; флажок соответствует выбранной вкладке. Окно "
                L"поиска можно свернуть и изменять его ширину; положение и настройка Поверх остальных "
                L"окон сохраняются. До 30 поисковых текстов с параметрами хранятся только до закрытия "
                L"приложения. Параметры начала и конца относятся к логическим строкам. Регулярные "
                L"выражения используют синтаксис PCRE2. Остальные команды меню Правка относятся к "
                L"активной вкладке отчёта. Enter запускает поиск, а Shift+Enter меняет выбранное "
                L"направление на противоположное. «Учитывать регистр» различает прописные и строчные "
                L"буквы; «Искать назад» ищет в сторону начала текста. Выбор записи истории "
                L"восстанавливает все пять параметров поиска, включая состояние режима регулярных "
                L"выражений; «Поверх остальных окон» — независимый параметр. «Регулярное выражение» "
                L"отключает «Строка начинается с» и «Строка заканчивается на». Если включены оба "
                L"параметра краёв строки, достаточно совпадения на одном краю. «Перенос по словам» меняет "
                L"только отображение."
            },
            { TXT_WEBP_FORMAT, L"Google WebP (*.webp)" },
            { TXT_WEBP_EXPORT_FAILED,
                L"Не удаётся сохранить изображение WebP. Проверьте папку назначения, свободную память и "
                L"место "
                L"на диске."
            },
            { TXT_TEXT_UTF8_FORMAT, L"Текстовый документ UTF-8 (*.txt)" },
            { TXT_TEXT_UTF8_BOM_FORMAT, L"Текстовый документ UTF-8 BOM (*.txt)" },
            { TXT_TEXT_UTF16_BE_FORMAT, L"Текстовый документ UTF-16 BE BOM (*.txt)" },
            { TXT_TEXT_UTF16_LE_FORMAT, L"Текстовый документ UTF-16 LE BOM (*.txt)" },
            { TXT_TEXT_ENCODING_FAILED,
                L"Отчёт нельзя сохранить в этой кодировке без потери символов. Выберите другую кодировку "
                L"текста."
            },
            { TXT_OPEN_FOLDER, L"Открыть &папку…" },
            { TXT_OPEN_FOLDER_TITLE, L"Открыть папку" },
            { TXT_FOLDER_READ_FAILED, L"Не удалось прочитать папку:\n\n%s\n\nОшибка Windows %lu." },
            { TXT_ADVANCED_MODE, L"&Расширенный режим" },
            { TXT_REPORT_DETAIL_REJECTED,
                L"Выбранная MediaInfo.dll отклонила настройку подробностей отчёта."
            },
            { TXT_KNOWN_FORMATS, L"Известные &форматы" },
            { TXT_KNOWN_CODECS, L"Известные &кодеки" },
            { TXT_KNOWN_PARAMETERS, L"Известные &параметры" },
            { TXT_KNOWN_FORMATS_TITLE, L"Известные форматы" },
            { TXT_KNOWN_CODECS_TITLE, L"Известные кодеки" },
            { TXT_KNOWN_PARAMETERS_TITLE, L"Известные параметры" },
            { TXT_KNOWN_INFO_FAILED, L"Библиотека не вернула запрошенную информацию." },
            { TXT_FULL_PARSING, L"&Полный анализ" },
            { TXT_PARSING_REJECTED, L"Выбранная MediaInfo.dll отклонила настройку анализа." },
            { TXT_TRACE_LEVEL_0, L"Уровень трассировки &0" },
            { TXT_TRACE_LEVEL_5, L"Уровень трассировки &5" },
            { TXT_TRACE_LEVEL_9, L"Уровень трассировки &9" },
            { TXT_TRACE_LEVEL_10, L"Уровень трассировки &10" },
            { TXT_PAGE_SETUP, L"Параметры &страницы…" },
            { TXT_PAGE_SETUP_FAILED, L"Не удалось открыть параметры страницы." },
            { TXT_PRINT, L"Пе&чать…\tCtrl+P" },
            { TXT_PRINTING, L"Печать…" },
            { TXT_PRINT_FAILED,
                L"Не удалось напечатать текст. Проверьте принтер, его настройки и доступную память."
            },
            { TXT_TOOLS_MENU, L"&Инструменты" },
            { TXT_CREATE_HEADER, L"Со&здать заголовок…" },
            { TXT_CREATE_HEADER_OPEN_TITLE, L"Создать заголовок - Открыть" },
            { TXT_CREATE_HEADER_SAVE_TITLE, L"Создать заголовок - Сохранить как" },
            { TXT_HEADER_FORMAT, L"Файл заголовка (*.header)" },
            { TXT_HEADER_READ_FAILED, L"Не удалось прочитать заголовок файла:\n\n%s" },
            { TXT_HEADER_SAVE_FAILED, L"Не удалось сохранить файл заголовка:\n\n%s" },
            { TXT_COPY, L"&Копировать" },
            { TXT_COPY_FILE_NAME, L"Копировать &имя файла" },
            { TXT_COPY_FULL_PATH, L"Копировать полный п&уть" },
            { TXT_LAUNCH_FILE, L"З&апустить файл" },
            { TXT_SHOW_IN_CONTAINING_FOLDER, L"По&казать в папке" },
            { TXT_EDIT_MENU, L"&Правка" },
            { TXT_WORD_WRAP, L"П&еренос по словам" },
            { TXT_WORD_WRAP_FAILED, L"Не удалось изменить перенос по словам." },
            { TXT_COPY_SELECTION, L"&Копировать\tCtrl+C" },
            { TXT_SELECT_ALL, L"Выделить &всё\tCtrl+A" },
            { TXT_FIND_MENU, L"&Найти…\tCtrl+F" },
            { TXT_FIND_NEXT_MENU, L"Найти &далее\tF3" },
            { TXT_FIND_PREVIOUS_MENU, L"Найти &предыдущее\tShift+F3" },
            { TXT_FIND_TITLE, L"%s — Поиск" },
            { TXT_FIND_WHAT, L"Най&ти:" },
            { TXT_FIND_NEXT, L"Найти &далее" },
            { TXT_FIND_MATCH_CASE, L"Учитывать &регистр" },
            { TXT_FIND_BACKWARD, L"Искать н&азад" },
            { TXT_FIND_TOPMOST, L"Поверх &остальных окон" },
            { TXT_FIND_STARTS_WITH, L"Строка &начинается с" },
            { TXT_FIND_ENDS_WITH, L"Строка закан&чивается на" },
            { TXT_FIND_REGEX, L"Регулярное &выражение" },
            { TXT_FIND_NOT_FOUND, L"Указанный текст не найден." },
            { TXT_FIND_FAILED, L"Не удалось завершить поиск." },
            { TXT_FIND_REGEX_ERROR, L"Ошибка регулярного выражения:\r\n\r\n%s" },
        }
    },
};

static_assert(sizeof(localizedLanguages) / sizeof(localizedLanguages[0]) == LANG_COUNT,
    "Every application language must define its translations.");

/// Returns the immutable translation for a supported language and named text key.
const wchar_t* GetLocalizedText(AppLanguage language, TextId id) {
    return localizedLanguages[language].texts[id].text;
}

/// Returns the complete Help text for the active interface language.
const wchar_t* LocalizedHelpText() {
    return GetLocalizedText(static_cast<AppLanguage>(GetApplicationLanguage()), TXT_APPLICATION_HELP);
}

/// Returns the number of original-English and official translated report-language choices.
int ReportLanguageCount() {
    return static_cast<int>(sizeof(reportLanguages) / sizeof(reportLanguages[0]));
}

/// Returns a report-language display name by index.
const wchar_t* ReportLanguageName(int index) {
    return index >= 0 && index < ReportLanguageCount() ? reportLanguages[index].name : L"";
}

/// Returns the report-language table code, using an empty code for original English.
const wchar_t* ReportLanguageCode(int index) {
    return index >= 0 && index < ReportLanguageCount() ? reportLanguages[index].code : L"";
}

/// Finds an official report-language choice by its independent table code.
int ReportLanguageIndex(const wchar_t* selection) {
    for (int index = 0; index < ReportLanguageCount(); ++index) {
        if (!lstrcmpiW(selection, reportLanguages[index].code)) {
            return index;
        }
    }
    return -1;
}

/// Loads an embedded or custom UTF-8 or UTF-16 report translation table into an owned Unicode buffer.
wchar_t* LoadReportLanguage(const wchar_t* selection, wchar_t* error, int capacity) {
    wchar_t* text = nullptr;
    int index = ReportLanguageIndex(selection);
    if (index >= 0 && reportLanguages[index].resource) {
        HMODULE module = GetModuleHandleW(nullptr);
        HRSRC resource = FindResourceW(module, MAKEINTRESOURCEW(reportLanguages[index].resource), RT_RCDATA);
        HGLOBAL loaded = resource ? LoadResource(module, resource) : nullptr;
        const wchar_t* source = loaded ? static_cast<const wchar_t*>(LockResource(loaded)) : nullptr;
        DWORD bytes = resource ? SizeofResource(module, resource) : 0;
        if (source && bytes >= sizeof(wchar_t) && !(bytes % sizeof(wchar_t))) {
            text = static_cast<wchar_t*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY,
                bytes + sizeof(wchar_t)));
            if (text) {
                if (*source == 0xFEFF) {
                    ++source;
                    bytes -= sizeof(wchar_t);
                }
                CopyMemory(text, source, bytes);
            }
        }
    } else if (index < 0) {
        HANDLE file = CreateFileW(selection, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING,
            FILE_ATTRIBUTE_NORMAL, nullptr);
        if (file != INVALID_HANDLE_VALUE) {
            DWORD high = 0;
            DWORD size = GetFileSize(file, &high);
            BYTE* bytes = size && !high && size <= 4 * 1024 * 1024
                ? static_cast<BYTE*>(HeapAlloc(GetProcessHeap(), 0, size))
                : nullptr;
            DWORD received = 0;
            if (bytes && ReadFile(file, bytes, size, &received, nullptr) && received == size) {
                if (size >= 2 && bytes[0] == 0xFF && bytes[1] == 0xFE && !(size % 2)) {
                    text = static_cast<wchar_t*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, size));
                    if (text) {
                        CopyMemory(text, bytes + 2, size - 2);
                    }
                } else if (size >= 2 && bytes[0] == 0xFE && bytes[1] == 0xFF && !(size % 2)) {
                    text = static_cast<wchar_t*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, size));
                    if (text) {
                        for (DWORD position = 2; position < size; position += 2) {
                            text[position / 2 - 1] =
                                static_cast<wchar_t>(bytes[position] << 8 | bytes[position + 1]);
                        }
                    }
                } else {
                    DWORD skip = size >= 3 && bytes[0] == 0xEF && bytes[1] == 0xBB && bytes[2] == 0xBF
                        ? 3
                        : 0;
                    int length = MultiByteToWideChar(CP_UTF8, 0, reinterpret_cast<const char*>(bytes + skip),
                        size - skip, nullptr, 0);
                    text = length
                        ? static_cast<wchar_t*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY,
                            (length + 1) * sizeof(wchar_t)))
                        : nullptr;
                    if (text && !MultiByteToWideChar(CP_UTF8, 0, reinterpret_cast<const char*>(bytes + skip),
                        size - skip, text, length)) {
                        HeapFree(GetProcessHeap(), 0, text);
                        text = nullptr;
                    }
                }
            }
            if (bytes) {
                HeapFree(GetProcessHeap(), 0, bytes);
            }
            CloseHandle(file);
        }
    }
    bool separator = false;
    if (text) {
        for (const wchar_t* cursor = text; *cursor; ++cursor) {
            if (*cursor == L';') {
                separator = true;
                break;
            }
        }
    }
    if (!separator) {
        if (text) {
            HeapFree(GetProcessHeap(), 0, text);
        }
        lstrcpynW(error, T(TXT_REPORT_LANGUAGE_LOAD_FAILED), capacity);
        return nullptr;
    }
    return text;
}
